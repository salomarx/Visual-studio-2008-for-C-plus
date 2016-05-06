// OrderDetailsView.cpp : implementation of the COrderDetailsView class
//

#include "stdafx.h"
#include "DBSimpleUpdate.h"

#include "OrderDetailsSet.h"
#include "DBSimpleUpdateDoc.h"
#include "OrderDetailsView.h"
#include "viewconstants.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COrderDetailsView

IMPLEMENT_DYNCREATE(COrderDetailsView, CRecordView)

BEGIN_MESSAGE_MAP(COrderDetailsView, CRecordView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
  ON_BN_CLICKED(IDC_EDITORDER, &COrderDetailsView::OnEditorder)
  ON_BN_CLICKED(IDC_CANCEL, &COrderDetailsView::OnCancel)
  ON_UPDATE_COMMAND_UI(ID_RECORD_FIRST, &COrderDetailsView::OnUpdateRecordFirst)
  ON_UPDATE_COMMAND_UI(ID_RECORD_PREV, &COrderDetailsView::OnUpdateRecordPrev)
  ON_UPDATE_COMMAND_UI(ID_RECORD_NEXT, &COrderDetailsView::OnUpdateRecordNext)
  ON_UPDATE_COMMAND_UI(ID_RECORD_LAST, &COrderDetailsView::OnUpdateRecordLast)
  ON_BN_CLICKED(IDC_NEWORDER, &COrderDetailsView::OnNeworder)
END_MESSAGE_MAP()

// COrderDetailsView construction/destruction

COrderDetailsView::COrderDetailsView()
	: CRecordView(COrderDetailsView::IDD)
  , m_Mode(READ_ONLY)
{
	m_pSet = NULL;
	// TODO: add construction code here

}

COrderDetailsView::~COrderDetailsView()
{
}

void COrderDetailsView::DoDataExchange(CDataExchange* pDX)
{
  CRecordView::DoDataExchange(pDX);
  DDX_FieldText(pDX, IDC_ORDERID, m_pSet->m_OrderID, m_pSet);
  DDX_FieldText(pDX, IDC_PRODUCTID, m_pSet->m_ProductID, m_pSet);
  DDX_FieldText(pDX, IDC_UNITPRICE, m_pSet->m_UnitPrice, m_pSet);
  DDX_FieldText(pDX, IDC_QUANTITY, m_pSet->m_Quantity, m_pSet);
  DDX_FieldText(pDX, IDC_DISCOUNT, m_pSet->m_Discount, m_pSet);
  DDX_Control(pDX, IDC_DISCOUNT, m_DiscountCtrl);
  DDX_Control(pDX, IDC_QUANTITY, m_QuantityCtrl);
  DDX_Control(pDX, IDC_CANCEL, m_CancelEditCtrl);
  DDX_Control(pDX, IDC_EDITORDER, m_EditOrderCtrl);
  DDX_Control(pDX, IDC_NEWORDER, m_NewOrderCtrl);
}

BOOL COrderDetailsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void COrderDetailsView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DBSimpleUpdateSet;
	CRecordView::OnInitialUpdate();

}


// COrderDetailsView printing

BOOL COrderDetailsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COrderDetailsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COrderDetailsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// COrderDetailsView diagnostics

#ifdef _DEBUG
void COrderDetailsView::AssertValid() const
{
	CRecordView::AssertValid();
}

void COrderDetailsView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDBSimpleUpdateDoc* COrderDetailsView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBSimpleUpdateDoc)));
	return (CDBSimpleUpdateDoc*)m_pDocument;
}
#endif //_DEBUG


// COrderDetailsView database support
CRecordset* COrderDetailsView::OnGetRecordset()
{
	return m_pSet;
}



// COrderDetailsView message handlers

void COrderDetailsView::OnEditorder()
{
  if(m_pSet->CanUpdate())
  {
    try
    {
      if(m_Mode == UPDATE)
      { // When button was clicked we were in update
        // Disable input to edit controls
        m_QuantityCtrl.SetReadOnly(); 
        m_DiscountCtrl.SetReadOnly();

        // Change the Update button text to Edit Order   
        m_EditOrderCtrl.SetWindowText(_T("Edit Order"));

        // Make the Cancel button invisible
        m_CancelEditCtrl.ShowWindow(SW_HIDE);

        // Show the new order button
        m_NewOrderCtrl.ShowWindow(SW_SHOW);             

        // Complete the update
        m_pSet->Update();                                       
        m_Mode = READ_ONLY;            // Change to read-only mode
      }
      else
      { // When button was clicked we were in read-only mode

        // Enable input to edit controls
        m_QuantityCtrl.SetReadOnly(FALSE); 
        m_DiscountCtrl.SetReadOnly(FALSE);

        // Change the Edit Order button text to Update
        m_EditOrderCtrl.SetWindowText(_T("Update"));

        // Hide the new order button
        m_NewOrderCtrl.ShowWindow(SW_HIDE);             

        // Make the Cancel button visible
        m_CancelEditCtrl.ShowWindow(SW_SHOW);

        // Start the update
        m_pSet->Edit();                                         

        m_Mode = UPDATE;               // Switch to update mode
      }
    }
    catch(CException* pEx)
    {
      pEx->ReportError();              // Display the error message
    }
  }
  else
    AfxMessageBox(_T("Recordset is not updatable."));
}

void COrderDetailsView::OnCancel()
{
  m_pSet->CancelUpdate();                   // Cancel the update operation
  m_EditOrderCtrl.SetWindowText(_T("Edit"));// Switch button text
  m_CancelEditCtrl.ShowWindow(SW_HIDE);     // Hide the Cancel button
  m_NewOrderCtrl.ShowWindow(SW_SHOW);       // Show the New Order button
  m_QuantityCtrl.SetReadOnly(TRUE);         // Set state of quantity edit control
  m_DiscountCtrl.SetReadOnly(TRUE);         // Set state of discount edit control
  m_Mode = READ_ONLY;                       // Switch the mode
}

void COrderDetailsView::OnUpdateRecordFirst(CCmdUI *pCmdUI)
{
  // Disable item if m_Mode is UPDATE 
  // Enable item if m_Mode is READ_ONLY and it's not the 1st record
  pCmdUI->Enable((m_Mode == READ_ONLY) && !IsOnFirstRecord());
}

void COrderDetailsView::OnUpdateRecordPrev(CCmdUI *pCmdUI)
{
  // Disable item if m_Mode is UPDATE 
  // Enable item if m_Mode is READ_ONLY and it's not the 1st record
  pCmdUI->Enable((m_Mode == READ_ONLY) && !IsOnFirstRecord());
}

void COrderDetailsView::OnUpdateRecordNext(CCmdUI *pCmdUI)
{
  // Disable item if m_Mode is UPDATE 
  // Enable item if m_Mode is READ_ONLY and it's not the 1st record
  pCmdUI->Enable((m_Mode == READ_ONLY) && !IsOnLastRecord());
}

void COrderDetailsView::OnUpdateRecordLast(CCmdUI *pCmdUI)
{
  // Disable item if m_Mode is UPDATE 
  // Enable item if m_Mode is READ_ONLY and it's not the 1st record
  pCmdUI->Enable((m_Mode == READ_ONLY) && !IsOnLastRecord());
}

void COrderDetailsView::OnNeworder()
{
  static_cast<CMainFrame*>(GetParentFrame())->SelectView(NEW_ORDER);
}
