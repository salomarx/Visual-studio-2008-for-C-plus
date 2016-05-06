#include "stdafx.h"
#include "DBSimpleUpdate.h"            // Main header file for the application
#include "CustomerView.h"
#include "CustomerSet.h"
#include "viewconstants.h"
#include "MainFrm.h"
#include "DBSimpleUpdateDoc.h"         
#include "EmployeeSet.h"

// Constructor
CCustomerView::CCustomerView()
  : CRecordView(CCustomerView::IDD),
   m_pSet(NULL)
   , m_OrderDate(0)
   , m_RequiredDate(0)
   , m_NewOrderID(0)
   , m_EmployeeID(NO_EMPLOYEE_ID)
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
  DDX_Control(pDX, IDC_EMPLOYEENAME, m_EmployeeCtrl);
}

CRecordset* CCustomerView::OnGetRecordset()
{
  if(m_pSet == NULL)                   // If we don't have the recordset address
  {
    m_pSet = new CCustomerSet(NULL);   // create a new one

    // Sort records by company name
    m_pSet->m_strSort = _T("[CompanyName]");

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

  CEmployeeSet* pEmployeeSet = &static_cast<CDBSimpleUpdateDoc*>(GetDocument())->m_EmployeeSet;
  if(!pEmployeeSet->IsOpen())
    pEmployeeSet->Open();

  // First entry is not a name
  int listIndex = m_EmployeeCtrl.AddString(_T("Choose a name"));
  m_EmployeeCtrl.SetItemData(listIndex, NO_EMPLOYEE_ID);
  if(pEmployeeSet->IsBOF())
  {
    AfxMessageBox(_T("Employees recordset is empty"));
    EndWaitCursor();
    return;
  }
  
  pEmployeeSet->MoveFirst();

  // Insert names and IDs in the list box
  while(!pEmployeeSet->IsEOF())
  {
    listIndex = m_EmployeeCtrl.AddString(
      pEmployeeSet->m_FirstName + _T(" ") + pEmployeeSet->m_LastName);

    m_EmployeeCtrl.SetItemData(listIndex,
                     static_cast<DWORD_PTR>(pEmployeeSet->m_EmployeeID));
    pEmployeeSet->MoveNext();
  }
  m_EmployeeID = NO_EMPLOYEE_ID;
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
  ON_LBN_SELCHANGE(IDC_EMPLOYEENAME, &CCustomerView::OnSelchangeEmployeename)
END_MESSAGE_MAP()

void CCustomerView::OnSelectproducts()
{
  // Verify that an employee name has been selected
  if(m_EmployeeID == NO_EMPLOYEE_ID)
  {
    AfxMessageBox(_T("You must select an employee name."));
    return;
  }

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
  pDoc-> m_Order.m_EmployeeID = m_EmployeeID;


  // Set up order field values from CCustomerView dialog input
  pDoc-> m_Order.m_OrderID = m_NewOrderID;            // Generated new ID
  pDoc-> m_Order.m_OrderDate = m_OrderDate;           // From order date control
  pDoc-> m_Order.m_RequiredDate = m_RequiredDate;     // From required date control

  // Reset Employee Names list box
  m_EmployeeCtrl.SetTopIndex(0);                      // Move to first item
  m_EmployeeID = NO_EMPLOYEE_ID;                      // Reset ID to no selection

  static_cast<CMainFrame*>(GetParentFrame())->SelectView(SELECT_PRODUCT);
}

void CCustomerView::OnCancel()
{
  // Reset Employee Names list box
  m_EmployeeCtrl.SetTopIndex(0);                    // Move to first item
  m_EmployeeID = NO_EMPLOYEE_ID;                    // Reset ID to no selection

  static_cast<CMainFrame*>(GetParentFrame())->SelectView(ORDER_DETAILS);
}

void CCustomerView::SetNewOrderID(void)
{
  // Get a new order ID from the COrderSet object in the document
  m_NewOrderID = static_cast<CDBSimpleUpdateDoc*>
                                  (GetDocument())->m_OrderSet.CreateNewOrderID();
  UpdateData(FALSE);                              // Transfer data to controls
}

void CCustomerView::OnSelchangeEmployeename()
{
  m_EmployeeID = static_cast<long>(m_EmployeeCtrl.GetItemData(m_EmployeeCtrl.GetCurSel()));
}
