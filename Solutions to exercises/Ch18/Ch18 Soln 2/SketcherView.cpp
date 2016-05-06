// SketcherView.cpp : implementation of the CSketcherView class
//

#include "stdafx.h"
#include "Sketcher.h"

#include "SketcherDoc.h"
#include "Elements.h"
#include "SketcherView.h"
#include "ChildFrm.h"
#include "ScaleDialog.h"
#include "TextDialog.h"
#include "PrintData.h"
#include <cmath>

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
  ON_COMMAND(ID_VIEW_SCALE, &CSketcherView::OnViewScale)
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
,m_Scale(1)
{
   SetScrollSizes(MM_TEXT, CSize(0,0));     // Set arbitrary scrollers
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
  pInfo->m_lpUserData = new CPrintData;     // Create a print data object 
  CSketcherDoc* pDoc = GetDocument();       // Get a document pointer

  // Get the whole document area
  CRect DocExtent = pDoc->GetDocExtent();

  // Save the reference point for the whole document
  ((CPrintData*)(pInfo->m_lpUserData))->m_DocRefPoint =
                                 CPoint(DocExtent.left, DocExtent.bottom);

  // Get the name of the document file and save it
  ((CPrintData*)(pInfo->m_lpUserData))->m_DocTitle = pDoc->GetTitle();

  // Calculate how many printed page widths of 600 units are required
  // to accommodate the width of the document
  ((CPrintData*)(pInfo->m_lpUserData))->m_nWidths =
          static_cast<UINT>(ceil((static_cast<double>(DocExtent.Width()))/600.0));

  // Calculate how many printed page lengths of 900 units are required
  // to accommodate the document length
  ((CPrintData*)(pInfo->m_lpUserData))->m_nLengths =
         static_cast<UINT>(ceil((static_cast<double>(DocExtent.Height()))/900.0));

  // Set the first page number as 1 and
  // set the last page number as the total number of pages
  pInfo->SetMinPage(1);
  pInfo->SetMaxPage((static_cast<CPrintData*>(pInfo->m_lpUserData))->m_nWidths *
                    (static_cast<CPrintData*>(pInfo->m_lpUserData))->m_nLengths);

   return DoPreparePrinting(pInfo);
}

void CSketcherView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSketcherView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
   // Delete our print data object
   delete static_cast<CPrintData*>(pInfo->m_lpUserData);
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
  CClientDC aDC(this);           // Create a device context
  OnPrepareDC(&aDC);             // Get origin adjusted
  aDC.DPtoLP(&point);            // convert point to Logical
  // In moving mode, so drop the element
  if(m_MoveMode)
  {
    m_MoveMode = FALSE;                // Kill move mode
    m_pSelected = 0;                   // De-select element
    GetDocument()->UpdateAllViews(0);  // Redraw all the views
    GetDocument()->SetModifiedFlag();  // Set the modified flag
  }
  else
  {
    CSketcherDoc* pDoc = GetDocument();// Get a document pointer
    if(pDoc->GetElementType() == TEXT)
    {
      CTextDialog aDlg;
      if(aDlg.DoModal() == IDOK)
      {
        // Exit OK so create a text element 
        CFont aFont;
        aFont.CreatePointFont(100, _T(""));
        CFont* pOldFont = aDC.SelectObject(&aFont);

        CSketcherDoc* pDoc = GetDocument();
        CSize TextExtent = aDC.GetTextExtent(aDlg.m_TextString);

        // Get bottom right of text rectangle - MM_LOENGLISH
        CPoint BottomRt(point.x+TextExtent.cx, point.y-TextExtent.cy);
        CText* pTextElement = new CText(point, BottomRt,
                              aDlg.m_TextString, pDoc->GetElementColor());

        // Add the element to the document
        pDoc->AddElement(pTextElement);

        // Get all views updated
        pDoc->UpdateAllViews(0,0,pTextElement);

        aDC.SelectObject(pOldFont);
      }
       return;
     }

     m_FirstPoint = point;             // Record the cursor position
     SetCapture();                     // Capture subsequent mouse messages
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
                                       pDoc->GetElementColor(), pDoc->GetPenWidth());

      case CIRCLE:
         return new CCircle(m_FirstPoint, m_SecondPoint,
                                       pDoc->GetElementColor(), pDoc->GetPenWidth());

      case CURVE:
         return new CCurve(m_FirstPoint, m_SecondPoint, 
                                       pDoc->GetElementColor(), pDoc->GetPenWidth());
      case LINE:
         return new CLine(m_FirstPoint, m_SecondPoint,
                                       pDoc->GetElementColor(), pDoc->GetPenWidth());

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
  ResetScrollSizes();                  // Set up the scrollbars
  CScrollView::OnInitialUpdate();
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
  CSize Distance = point - m_CursorPos;   // Get move distance
  m_CursorPos = point;          // Set current point as 1st for next time

  // If there is an element, selected, move it
  if(m_pSelected)
  {
    // If the element is text use this method...
    if(m_pSelected->IsKindOf(RUNTIME_CLASS(CText)))
    {
      CRect OldRect=m_pSelected->GetBoundRect(); // Get old bound rect
      m_pSelected->Move(Distance);               // Move the element
      CRect NewRect=m_pSelected->GetBoundRect(); // Get new bound rect
      OldRect.UnionRect(&OldRect,&NewRect);      // Combine the bound rects
      aDC.LPtoDP(OldRect);                       // Convert to client coords
      OldRect.NormalizeRect();                   // Normalize combined area
      InvalidateRect(&OldRect);                  // Invalidate combined area
      UpdateWindow();                            // Redraw immediately
      m_pSelected->Draw(&aDC,m_pSelected);  // Draw highlighted

      return;
    }

    // ...otherwise, use this method
    aDC.SetROP2(R2_NOTXORPEN);
    m_pSelected->Draw(&aDC,m_pSelected);    // Draw the element to erase it
    m_pSelected->Move(Distance);            // Now move the element
    m_pSelected->Draw(&aDC,m_pSelected);    // Draw the moved element
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

void CSketcherView::OnViewScale()
{
  CScaleDialog aDlg;                   // Create a dialog object
  aDlg.m_Scale = m_Scale;              // Pass the view scale to the dialog
  if(aDlg.DoModal() == IDOK)
  {
    m_Scale = 1 + aDlg.m_Scale;        // Get the new scale

    // Get the frame that wraps this view
    CChildFrame* childFrame = static_cast<CChildFrame*>(GetParentFrame());

    // Build the message string
    CString StatusMsg("View Scale:");
    StatusMsg += static_cast<char>('1' + m_Scale - 1);
    // Set the status bar  
    childFrame->m_StatusBar.GetStatusBarCtrl().SetText(StatusMsg, 0, 0);
 
    ResetScrollSizes();                // Adjust scrolling to the new scale
    InvalidateRect(0);                 // Invalidate the whole window 
  }
}

void CSketcherView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
  // TODO: Add your specialized code here and/or call the base class
  int Scale = m_Scale;                 // Store the scale locally
  if(pDC->IsPrinting())
    Scale = 1;                         // If we are printing, set scale to 1

  CScrollView::OnPrepareDC(pDC, pInfo);
  CSketcherDoc* pDoc = GetDocument();
  pDC->SetMapMode(MM_ANISOTROPIC);     // Set the map mode
  CSize DocSize = pDoc->GetDocSize();  // Get the document size

  // y extent must be negative because we want MM_LOENGLISH
  DocSize.cy = -DocSize.cy;            // Change sign of y
  pDC->SetWindowExt(DocSize);          // Now set the window extent

  // Get the number of pixels per inch in x and y
  int xLogPixels = pDC->GetDeviceCaps(LOGPIXELSX);
  int yLogPixels = pDC->GetDeviceCaps(LOGPIXELSY);

  // Calculate the viewport extent in x and y
  long xExtent = static_cast<long>(DocSize.cx)*m_Scale*xLogPixels/100L;
  long yExtent = static_cast<long>(DocSize.cy)*m_Scale*yLogPixels/100L;

  pDC->SetViewportExt(static_cast<int>(xExtent),
                      static_cast<int>(-yExtent)); // Set viewport extent
}

void CSketcherView::ResetScrollSizes(void)
{
  CClientDC aDC(this);
  OnPrepareDC(&aDC);                             // Set up the device context
  CSize DocSize = GetDocument()->GetDocSize();   // Get the document size
  aDC.LPtoDP(&DocSize);                          // Get the size in pixels
  SetScrollSizes(MM_TEXT, DocSize);              // Set up the scrollbars
}

void CSketcherView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
  // Output the document file name
  pDC->SetTextAlign(TA_CENTER);        // Center the following text
  pDC->TextOut(pInfo->m_rectDraw.right/2, -20,
              (static_cast<CPrintData*>(pInfo->m_lpUserData))->m_DocTitle);
  pDC->SetTextAlign(TA_LEFT);          // Left justify text

  // Calculate the origin point for the current page
  int xOrg = (static_cast<CPrintData*>(pInfo->m_lpUserData))->m_DocRefPoint.x +
                 600*((pInfo->m_nCurPage - 1)%
                     ((static_cast<CPrintData*>(pInfo->m_lpUserData))->m_nWidths));

  int yOrg = (static_cast<CPrintData*>(pInfo->m_lpUserData))->m_DocRefPoint.y -
                 900*((pInfo->m_nCurPage - 1)/
                     ((static_cast<CPrintData*>(pInfo->m_lpUserData))->m_nWidths));

  // Calculate offsets to center drawing area on page as positive values
  int xOffset = (pInfo->m_rectDraw.right - 600)/2;
  int yOffset = -(pInfo->m_rectDraw.bottom + 900)/2;

  // Change window origin to correspond to current page & save old origin
  CPoint OldOrg = pDC->SetWindowOrg(xOrg-xOffset, yOrg+yOffset);

  // Define a clip rectangle the size of the printed area
  pDC->IntersectClipRect(xOrg,yOrg,xOrg+600,yOrg-900);

  OnDraw(pDC);                         // Draw the whole document
  pDC->SelectClipRgn(NULL);            // Remove the clip rectangle
  pDC->SetWindowOrg(OldOrg);           // Restore old window origin
}
