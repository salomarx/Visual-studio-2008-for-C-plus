#include "stdafx.h"
#include "DBSimpleUpdate.h"            // Main header file for the application
#include "CustomerView.h"
#include "CustomerSet.h"
#include "MainFrm.h"
#include "DBSimpleUpdateDoc.h"         

// Constructor
CCustomerView::CCustomerView()
  : CRecordView(CCustomerView::IDD),
   m_pSet(NULL)
   , m_OrderDate(0)
   , m_RequiredDate(0)
   , m_NewOrderID(0)
{
}

CCustomerView::~CCustomerView()
{
  if (m_pSet)
    delete m_pSet;
}

// CCustomerView diagnostics

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

void CCustomerView::DoDataExchange(CDataExchange* pDX)
{
  // TODO: Add your specialized code here and/or call the base class

  CRecordView::DoDataExchange(pDX);
  DDX_DateTimeCtrl(pDX, IDC_ORDERDATE, m_OrderDate);
  DDX_DateTimeCtrl(pDX, IDC_REQUIREDDATE, m_RequiredDate);
  DDX_FieldText(pDX, IDC_COMPANYNAME, m_pSet->m_CompanyName, m_pSet);
  DDX_Text(pDX, IDC_NEWORDERID, m_NewOrderID);
}

CRecordset* CCustomerView::OnGetRecordset()
{
  if(m_pSet == NULL)                   // If we don't have the recordset address
  {
    m_pSet = new CCustomerSet(NULL);   // create a new one
     m_pSet->Open();                    // and open it
  }
   return m_pSet;                       // Return the recordset address
}

void CCustomerView::OnInitialUpdate()
{
  BeginWaitCursor();
  GetRecordset();
  CRecordView::OnInitialUpdate();
  if (m_pSet->IsOpen())
  {
    CString strTitle = m_pSet->m_pDatabase->GetDatabaseName();
    CString strTable = m_pSet->GetTableName();
    if(!strTable.IsEmpty())
      strTitle += _T(":") + strTable;
  GetDocument()->SetTitle(strTitle);
  }
  EndWaitCursor();

  // Initialize time values  
  SYSTEMTIME Now;
  GetLocalTime(&Now);                            // Get current time
  m_OrderDate = m_RequiredDate = CTime(Now);     // Set time as today
}

CCustomerSet* CCustomerView::GetRecordset()
{
  return static_cast<CCustomerSet*>(OnGetRecordset());
}
BEGIN_MESSAGE_MAP(CCustomerView, CRecordView)
  ON_BN_CLICKED(IDC_SELECTPRODUCTS, &CCustomerView::OnSelectproducts)
  ON_BN_CLICKED(IDC_CANCEL, &CCustomerView::OnCancel)
END_MESSAGE_MAP()

void CCustomerView::OnSelectproducts()
{
  // Get a pointer to the document  
  CDBSimpleUpdateDoc* pDoc = static_cast<CDBSimpleUpdateDoc*>(GetDocument());

  // Set up order field values from CCustomerSet object  
  pDoc->m_Order.m_CustomerID = m_pSet->m_CustomerID;
  pDoc->m_Order.m_ShipAddress = m_pSet->m_Address;
  pDoc-> m_Order.m_ShipCity = m_pSet->m_City;
  pDoc-> m_Order.m_ShipCountry = m_pSet->m_Country;
  pDoc-> m_Order.m_ShipName = m_pSet->m_CompanyName;
  pDoc-> m_Order.m_ShipPostalCode = m_pSet->m_PostalCode;
  pDoc-> m_Order.m_ShipRegion = m_pSet->m_Region;


  // Set up order field values from CCustomerView dialog input
  pDoc-> m_Order.m_OrderID = m_NewOrderID;            // Generated new ID
  pDoc-> m_Order.m_OrderDate = m_OrderDate;           // From order date control
  pDoc-> m_Order.m_RequiredDate = m_RequiredDate;     // From required date control

  static_cast<CMainFrame*>(GetParentFrame())->SelectView(SELECT_PRODUCT);
}

void CCustomerView::OnCancel()
{
  static_cast<CMainFrame*>(GetParentFrame())->SelectView(ORDER_DETAILS);
}

void CCustomerView::SetNewOrderID(void)
{
  // Get a new order ID from the COrderSet object in the document
  m_NewOrderID = static_cast<CDBSimpleUpdateDoc*>
                                  (GetDocument())->m_OrderSet.CreateNewOrderID();
  UpdateData(FALSE);                              // Transfer data to controls
}
