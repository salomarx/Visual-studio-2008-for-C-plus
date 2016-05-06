#include "stdafx.h"
#include "DBSample.h"
#include "OrderView.h"
#include "OrderSet.h" 
#include "DBSampleDoc.h"
#include "OurConstants.h"
#include "MainFrm.h"

IMPLEMENT_DYNCREATE(COrderView, CRecordView)

COrderView::COrderView()
  : CRecordView(COrderView::IDD), m_pSet(NULL)
{
}

// COrderView diagnostics

#ifdef _DEBUG
void COrderView::AssertValid() const
{
  CRecordView::AssertValid();
}

void COrderView::Dump(CDumpContext& dc) const
{
  CRecordView::Dump(dc);
}
#endif //_DEBUG

void COrderView::DoDataExchange(CDataExchange* pDX)
{
  CRecordView::DoDataExchange(pDX);
  DDX_FieldText(pDX, IDC_ORDERDETAILS_ORDERID,
                            m_pSet->m_OrderDetailsOrderID, m_pSet);
  DDX_FieldText(pDX, IDC_ORDERS_CUSTOMERID,
                            m_pSet->m_OrdersCustomerID, m_pSet);
  DDX_FieldText(pDX, IDC_ORDERDETAILS_PRODUCTID,
                            m_pSet->m_OrderDetailsProductID, m_pSet);
  DDX_FieldText(pDX, IDC_ORDERDETAILS_QUANTITY,
                            m_pSet->m_OrderDetailsQuantity, m_pSet);
}

COrderSet* COrderView::GetRecordset()
{
  ASSERT(m_pSet != NULL);
  return m_pSet;
}

CRecordset* COrderView::OnGetRecordset()
{
  return m_pSet;
}

void COrderView::OnInitialUpdate()
{
  BeginWaitCursor();
  CDBSampleDoc* pDoc = static_cast<CDBSampleDoc*>(GetDocument());  
   m_pSet = &pDoc->m_OrderSet;           // Get a pointer to the recordset

   // Use the DB that is open for products recordset
   m_pSet->m_pDatabase = pDoc->m_DBSampleSet.m_pDatabase;

   // Set the current product ID as parameter
   m_pSet->m_ProductIDparam = pDoc->m_DBSampleSet.m_ProductID;

   // Set the filter as product ID field
   m_pSet->m_strFilter =
     "[ProductID] = ? AND [Orders].[OrderID] = [Order Details].[OrderID]";

   CRecordView::OnInitialUpdate();
   EndWaitCursor();
}
BEGIN_MESSAGE_MAP(COrderView, CRecordView)
  ON_BN_CLICKED(IDC_PRODUCTS, &COrderView::OnProducts)
  ON_BN_CLICKED(IDC_CUSTOMER, &COrderView::OnCustomer)
END_MESSAGE_MAP()

void COrderView::OnProducts()
{
  static_cast<CMainFrame*>(GetParentFrame())->SelectView(PRODUCT_VIEW);
}

void COrderView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
  if(bActivate)
  {
    // Get a pointer to the document
    CDBSampleDoc* pDoc = GetDocument();

    // Get a pointer to the frame window
    CMainFrame* pMFrame = static_cast<CMainFrame*>(GetParentFrame());

    // If the last view was the product view, we must re-query
    // the recordset with the product ID from the product recordset
    if(pMFrame->m_CurrentViewID==PRODUCT_VIEW)
    {
      if(!m_pSet->IsOpen())       // Make sure the recordset is open
        return;
      // Set current product ID as parameter
      m_pSet->m_ProductIDparam = pDoc->m_DBSampleSet.m_ProductID;
      m_pSet->Requery();          // Get data from the DB

      // If we are past the EOF there are no records
      if(m_pSet->IsEOF())
        AfxMessageBox(L"No orders for the current product ID");
    }

    // Set the window caption
    CString strTitle = _T("Table Name: ");
    CString strTable = m_pSet->GetTableName();
    if(!strTable.IsEmpty())
      strTitle += strTable;
    else
      strTitle += _T("Orders - Multiple Tables");
    pDoc->SetTitle(strTitle);
    CRecordView::OnInitialUpdate();       // Update values in dialog
  }

  CRecordView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

void COrderView::OnCustomer()
{
  static_cast<CMainFrame*>(GetParentFrame())->SelectView(CUSTOMER_VIEW);
}
