// CCustomerView implementation
#include "stdafx.h"
#include "resource.h"
#include "CustomerView.h"
#include "ProductSet.h"
#include "OrderSet.h"
#include "CustomerSet.h"
#include "DBSampleDoc.h"
#include "OurConstants.h"
#include "MainFrm.h"
#include "CustomerSet.h"

IMPLEMENT_DYNCREATE(CCustomerView, CRecordView)

CCustomerView::CCustomerView(): CRecordView(CCustomerView::IDD), m_pSet(NULL)
{
}

CCustomerSet* CCustomerView::GetRecordset()
  {
    ASSERT(m_pSet != NULL);
    return m_pSet;
  }

  CRecordset* CCustomerView::OnGetRecordset()
  {
    return m_pSet;
  }

  // COrderView diagnostics

#ifdef _DEBUG
void CCustomerView::AssertValid() const
{
  CRecordView::AssertValid();
}

void CCustomerView::Dump(CDumpContext& dc) const
{
  CRecordView::Dump(dc);
}
#endif //_DEBUG
BEGIN_MESSAGE_MAP(CCustomerView, CRecordView)
  ON_BN_CLICKED(IDC_ORDERS, &CCustomerView::OnOrders)
  ON_BN_CLICKED(IDC_PRODUCTS, &CCustomerView::OnProducts)
END_MESSAGE_MAP()

void CCustomerView::OnOrders()
{
  static_cast<CMainFrame*>(GetParentFrame())->SelectView(ORDER_VIEW);
}

void CCustomerView::OnProducts()
{
  static_cast<CMainFrame*>(GetParentFrame())->SelectView(PRODUCT_VIEW);
}

void CCustomerView::OnInitialUpdate()
{
     BeginWaitCursor();

   CDBSampleDoc* pDoc = static_cast<CDBSampleDoc*>(GetDocument());
   m_pSet = &pDoc->m_CustomerSet;      // Initialize the recordset pointer

   // Set the DB for the customer recordset
   m_pSet->m_pDatabase = pDoc->m_DBSampleSet.m_pDatabase;

   // Set the current customer ID as the filter parameter value
   m_pSet->m_CustomerIDparam = pDoc->m_OrderSet.m_OrdersCustomerID;
   m_pSet->m_strFilter ="CustomerID = ?";    // Filter on CustomerID field

   CRecordView::OnInitialUpdate();
   if (m_pSet->IsOpen())
   {
      CString strTitle = m_pSet->m_pDatabase->GetDatabaseName();
      CString strTable = m_pSet->GetTableName();
      if (!strTable.IsEmpty())
         strTitle += _T(":") + strTable;
      GetDocument()->SetTitle(strTitle);
   }
   EndWaitCursor();
}

void CCustomerView::OnActivateView(BOOL bActivate,
                                   CView* pActivateView, CView* pDeactiveView)
{
     if(bActivate)
   {
      if(!m_pSet->IsOpen())
         return;
      CDBSampleDoc* pDoc = static_cast<CDBSampleDoc*>(GetDocument());

      // Set current customer ID as parameter
      m_pSet->m_CustomerIDparam = pDoc->m_OrderSet.m_OrdersCustomerID;
      m_pSet->Requery();               // Get data from the DB
      CRecordView::OnInitialUpdate();  // Redraw the dialog

      // Check for empty recordset
      if(m_pSet->IsEOF())
         AfxMessageBox(L"No customer details for the current customer ID");

      CString strTitle = _T("Table Name:");
      CString strTable = m_pSet->GetTableName();
      if (!strTable.IsEmpty())
         strTitle += strTable;
      else
         strTitle += _T("Multiple Tables");
      pDoc->SetTitle(strTitle);
   }
   CRecordView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

void CCustomerView::DoDataExchange(CDataExchange* pDX)
{
  CRecordView::DoDataExchange(pDX);
  DDX_FieldText(pDX, IDC_ADDRESS,
                            m_pSet->m_Address, m_pSet);
  DDX_FieldText(pDX, IDC_CITY,
                            m_pSet->m_City, m_pSet);
  DDX_FieldText(pDX, IDC_COMPANYNAME,
                            m_pSet->m_CompanyName, m_pSet);
  DDX_FieldText(pDX, IDC_PHONE,
                            m_pSet->m_Phone, m_pSet);
  DDX_FieldText(pDX, IDC_CUSTOMERID,
                            m_pSet->m_CustomerID, m_pSet);
}
