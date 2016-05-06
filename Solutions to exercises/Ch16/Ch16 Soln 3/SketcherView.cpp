// SketcherView.cpp : implementation of the CSketcherView class
//

#include "stdafx.h"
#include "Sketcher.h"

#include "SketcherDoc.h"
#include "Elements.h"
#include "SketcherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSketcherView

IMPLEMENT_DYNCREATE(CSketcherView, CScrollView)

BEGIN_MESSAGE_MAP(CSketcherView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
  ON_WM_LBUTTONUP()
  ON_WM_LBUTTONDOWN()
  ON_WM_MOUSEMOVE()
  ON_WM_CONTEXTMENU()
  ON_COMMAND(ID_ELEMENT_MOVE, &CSketcherView::OnElementMove)
  ON_COMMAND(ID_ELEMENT_DELETE, &CSketcherView::OnElementDelete)
  ON_WM_RBUTTONDOWN()
  ON_COMMAND(ID_ELEMENT_SENDTOBACK, &CSketcherView::OnElementSendtoback)
END_MESSAGE_MAP()

// CSketcherView construction/destruction

CSketcherView::CSketcherView()
: m_FirstPoint(0,0)
, m_SecondPoint(0,0)
, m_pTempElement(NULL)
, m_pSelected(NULL)
, m_MoveMode(FALSE)
, m_CursorPos(CPoint(0,0))
, m_FirstPos(CPoint(0,0))
{
	// TODO: add construction code here

}

CSketcherView::~CSketcherView()
{
}

BOOL CSketcherView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSketcherView drawing

void CSketcherView::OnDraw(CDC* pDC)
{
  CSketcherDoc* pDoc = GetDocument();
  ASSERT_VALID(pDoc);
  if(!pDoc)
    return;

  POSITION aPos = pDoc->GetListHeadPosition();
  CElement* pElement = 0;              // Store for an element pointer
  while(aPos)                          // Loop while aPos is not null
  {
    pElement = pDoc->GetNext(aPos);    // Get the current element pointer
    // If the element is visible...
    if(pDC->RectVisible(pElement->GetBoundRect()))
      pElement->Draw(pDC, m_pSelected);// ...draw it
  }
}

// CSketcherView printing

BOOL CSketcherView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSketcherView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSketcherView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSketcherView diagnostics

#ifdef _DEBUG
void CSketcherView::AssertValid() const
{
	CView::AssertValid();
}

void CSketcherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSketcherDoc* CSketcherView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSketcherDoc)));
	return (CSketcherDoc*)m_pDocument;
}
#endif //_DEBUG


// CSketcherView message handlers

void CSketcherView::OnLButtonUp(UINT nFlags, CPoint point)
{
   if(this == GetCapture())
      ReleaseCapture();                // Stop capturing mouse messages

   // If there is an element, add it to the document
   if(m_pTempElement)
   {
      GetDocument()->AddElement(m_pTempElement);
      GetDocument()->UpdateAllViews(0,0,m_pTempElement);  // Tell all the views
      m_pTempElement = 0;              // Reset the element pointer
   }
}

void CSketcherView::OnLButtonDown(UINT nFlags, CPoint point)
{
  CClientDC aDC(this);                 // Create a device context
  OnPrepareDC(&aDC);                   // Get origin adjusted
  aDC.DPtoLP(&point);                  // convert point to Logical

  if(m_MoveMode)
  {
    // In moving mode, so drop the element
    m_MoveMode = FALSE;                // Kill move mode
    m_pSelected = 0;                   // De-select the element
    GetDocument()->UpdateAllViews(0);  // Redraw all the views
  }
  else
  {
    m_FirstPoint = point;              // Record the cursor position
    SetCapture();                      // Capture subsequent mouse messages
  }
}

void CSketcherView::OnMouseMove(UINT nFlags, CPoint point)
{
  // Define a Device Context object for the view
  CClientDC aDC(this);                // DC is for this view
  OnPrepareDC(&aDC);                  // Get origin adjusted

    // If we are in move mode, move the selected element and return
  if(m_MoveMode)
  {
    aDC.DPtoLP(&point);                // Convert to logical coordinatess
    MoveElement(aDC, point);           // Move the element
    return;
  }

  aDC.SetROP2(R2_NOTXORPEN);          // Set the drawing mode
  if((nFlags&MK_LBUTTON)  && (this==GetCapture()))
  {
    aDC.DPtoLP(&point);              // convert point to Logical
    m_SecondPoint = point;           // Save the current cursor position

    if(m_pTempElement)
    {
      if(CURVE == GetDocument()->GetElementType())   // Is it a curve?
      {  // We are drawing a curve
         // so add a segment to the existing curve
         static_cast<CCurve*>(m_pTempElement)->AddSegment(m_SecondPoint);  
         m_pTempElement->Draw(&aDC);   // Now draw it
         return;                       // We are done
      }

      aDC.SetROP2(R2_NOTXORPEN);       // Set drawing mode
      // Redraw the old element so it disappears from the view
      m_pTempElement->Draw(&aDC);
      delete m_pTempElement;           // Delete the old element
      m_pTempElement = 0;              // Reset the pointer to 0
    }

    // Create a temporary element of the type and color that
    // is recorded in the document object, and draw it
    m_pTempElement = CreateElement();  // Create a new element
    m_pTempElement->Draw(&aDC);        // Draw the element
  }
  else
  { // We are not drawing an element so do highlighting...
    CSketcherDoc* pDoc=GetDocument();  // Get a pointer to the document
    CElement* pElement = 0;            // Store an element pointer
    CRect aRect(0,0,0,0);              // Store a rectangle
    POSITION aPos = pDoc->GetListHeadPosition();  // Get first element posn
    CElement* pOldSelection = m_pSelected;        // Save old selected element
    m_pSelected = 0;
    while(aPos)                        // Iterate through the list
    {
      pElement = pDoc->GetNext(aPos);
      aRect = pElement->GetBoundRect();
      aDC.LPtoDP(aRect);
      aRect.NormalizeRect();

      // Select the first element that appears under the cursor
      if(aRect.PtInRect(point))
      {
        m_pSelected = pElement;
        break;
      }
    }
    if(m_pSelected == pOldSelection)   // If new selection is same as old       
      return;                          // we are done

    // Unhighlight old selection if there is one
    if(pOldSelection != 0)             // Verify there is one
    {
      aRect = pOldSelection->GetBoundRect();
      aDC.LPtoDP(aRect);               // Convert to device coords
      aRect.NormalizeRect();           // Normalize
      InvalidateRect(aRect, FALSE);    // Invalidate area
    }

    // Highlight new selection if there is one
    if(m_pSelected != 0)               // Verify there is one
    {
      aRect = m_pSelected->GetBoundRect();
      aDC.LPtoDP(aRect);               // Convert to device coords
      aRect.NormalizeRect();           // Normalize
      InvalidateRect(aRect, FALSE);    // Invalidate area
    }
  }
}

// Create a new element on the heap
CElement* CSketcherView::CreateElement(void)
{
   // Get a pointer to the document for this view
   CSketcherDoc* pDoc = GetDocument();
   ASSERT_VALID(pDoc);                 // Verify the pointer is good

   // Now select the element using the type stored in the document
   switch(pDoc->GetElementType())
   {
      case RECTANGLE:
         return new CRectangle(m_FirstPoint, m_SecondPoint,
                                             pDoc->GetElementColor());

      case CIRCLE:
         return new CCircle(m_FirstPoint, m_SecondPoint,
                                          pDoc->GetElementColor());

      case CURVE:
         return new CCurve(m_FirstPoint, m_SecondPoint, pDoc->GetElementColor());
      case LINE:
         return new CLine(m_FirstPoint, m_SecondPoint,
                                        pDoc->GetElementColor());

      default:
         // Something's gone wrong
         AfxMessageBox(_T("Bad Element code"), MB_OK);
         AfxAbort();
         return NULL;
   }
}

void CSketcherView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
   // Invalidate the area corresponding to the element pointed to
   // if there is one, otherwise invalidate the whole client area 
   if(pHint)
   {
      CClientDC aDC(this);            // Create a device context
      OnPrepareDC(&aDC);              // Get origin adjusted

      // Get the enclosing rectangle and convert to client coordinates
      CRect aRect=((CElement*)pHint)->GetBoundRect();
      aDC.LPtoDP(aRect);
      aRect.NormalizeRect();
      InvalidateRect(aRect);          // Get the area redrawn
   }
   else
      InvalidateRect(0);              // Invalidate the client area
}

void CSketcherView::OnInitialUpdate()
{
  CScrollView::OnInitialUpdate();

   // Define document size as 30x30ins in MM_LOENGLISH
   CSize DocSize(3000,3000);

   // Set mapping mode and document size.
   SetScrollSizes(MM_LOENGLISH, DocSize);
}

void CSketcherView::OnContextMenu(CWnd* pWnd, CPoint point)
{
   CMenu menu;
   menu.LoadMenu(IDR_CURSOR_MENU);

   // Set check marks if it's the no element menu
   if(m_pSelected == 0)
   {
      // Check color menu items
      COLORREF Color = GetDocument()->GetElementColor();
      menu.CheckMenuItem(ID_COLOR_BLACK,
                     (BLACK==Color?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
      menu.CheckMenuItem(ID_COLOR_RED,
                       (RED==Color?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
      menu.CheckMenuItem(ID_COLOR_GREEN,
                     (GREEN==Color?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
      menu.CheckMenuItem(ID_COLOR_BLUE,
                      (BLUE==Color?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);

      // Check element menu items
      unsigned int ElementType = GetDocument()->GetElementType();
      menu.CheckMenuItem(ID_ELEMENT_LINE,
                (LINE==ElementType?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
      menu.CheckMenuItem(ID_ELEMENT_RECTANGLE,
           (RECTANGLE==ElementType?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
      menu.CheckMenuItem(ID_ELEMENT_CIRCLE,
              (CIRCLE==ElementType?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
      menu.CheckMenuItem(ID_ELEMENT_CURVE,
               (CURVE==ElementType?MF_CHECKED:MF_UNCHECKED)|MF_BYCOMMAND);
   }
   CMenu* pPopup = menu.GetSubMenu(m_pSelected == 0 ? 1 : 0);
   ASSERT(pPopup != NULL);
   pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}

void CSketcherView::OnElementMove()
{
   CClientDC aDC(this);
   OnPrepareDC(&aDC);              // Set up the device context
   GetCursorPos(&m_CursorPos);     // Get cursor position in screen coords
   ScreenToClient(&m_CursorPos);   // Convert to client coords
   aDC.DPtoLP(&m_CursorPos);       // Convert to logical
   m_FirstPos = m_CursorPos;       // Remember first position
   m_MoveMode = TRUE;              // Start move mode
}

void CSketcherView::OnElementDelete()
{
  if(m_pSelected)
  {
    CSketcherDoc* pDoc = GetDocument();// Get the document pointer
    pDoc->DeleteElement(m_pSelected);  // Delete the element
    pDoc->UpdateAllViews(0);           // Redraw all the views
    m_pSelected = 0;                   // Reset selected element ptr
  }
}

void CSketcherView::MoveElement(CClientDC& aDC, CPoint& point)
{
  CSize Distance = point - m_CursorPos;  // Get move distance
  m_CursorPos = point;                   // Set current point as 1st for next time

  // If there is an element, selected, move it
  if(m_pSelected)
  {
    aDC.SetROP2(R2_NOTXORPEN);
    m_pSelected->Draw(&aDC,m_pSelected); // Draw the element to erase it
    m_pSelected->Move(Distance);         // Now move the element
    m_pSelected->Draw(&aDC,m_pSelected); // Draw the moved element
  }
}

void CSketcherView::OnRButtonDown(UINT nFlags, CPoint point)
{
   if(m_MoveMode)
   {
     // In moving mode, so drop element back in original position
     CClientDC aDC(this);
     OnPrepareDC(&aDC);                // Get origin adjusted
     MoveElement(aDC, m_FirstPos);     // Move element to orig position
     m_MoveMode = FALSE;               // Kill move mode
     m_pSelected = 0;                  // De-select element
     GetDocument()->UpdateAllViews(0); // Redraw all the views
     return;                           // We are done
  }

  //CScrollView::OnRButtonDown(nFlags, point);
}

void CSketcherView::OnElementSendtoback()
{
  GetDocument()->SendToBack(m_pSelected);   // Move element in list
}
