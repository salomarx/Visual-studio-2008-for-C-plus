#include "stdafx.h"
#include "DBSimpleUpdate.h"
#include "ProductView.h"
#include "ProductSet.h"
#include "viewconstants.h"
#include "MainFrm.h"
#include "DBSimpleUpdateDoc.h"

CProductView::CProductView()
  : CRecordView(CProductView::IDD),
    m_pSet(NULL)
    , m_OrderID(0)
    , m_CustomerName(_T(""))
    , m_Quantity(0)
    , m_Discount(0)
    , m_OrderAdded(false)
    , m_TotalValue(0.0)
{
}

CProductView::~CProductView()
{
  if (m_pSet)
    delete m_pSet;
}

void CProductView::DoDataExchange(CDataExchange* pDX)
{
  // TODO: Add your specialized code here and/or call the base class

  CRecordView::DoDataExchange(pDX);
  DDX_FieldText(pDX, IDC_PRODUCTNAME, m_pSet->m_ProductName, m_pSet);
  DDX_Text(pDX, IDC_NEWORDERID, m_OrderID);
  DDX_Text(pDX, IDC_CUSTOMERNAME, m_CustomerName);
  DDX_Text(pDX, IDC_ORDERQUANTITY, m_Quantity);
  DDX_Text(pDX, IDC_ORDERSDISCOUNT, m_Discount);
  DDX_Text(pDX, IDC_TOTALVALUE, m_TotalValue);
}

void CProductView::OnInitialUpdate()
{
  CRecordView::OnInitialUpdate();

  // TODO: Add your specialized code here and/or call the base class
}

CRecordset* CProductView::OnGetRecordset()
{
  if(m_pSet == NULL)                   // If there is no recordset
  {
    m_pSet = new CProductSet(NULL);    // create one
    m_pSet->Open();                    // then open it
  }
  return m_pSet;                       // Return the address of the recordset
}

CProductSet* CProductView::GetRecordset()
{
  return static_cast<CProductSet*>(OnGetRecordset());
}

#ifdef _DEBUG
void CProductView::AssertValid() const
{
  CRecordView::AssertValid();
}

void CProductView::Dump(CDumpContext& dc) const
{
  CRecordView::Dump(dc);
}
#endif //_DEBUG
BEGIN_MESSAGE_MAP(CProductView, CRecordView)
  ON_BN_CLICKED(IDC_SELECTPRODUCT, &CProductView::OnSelectproduct)
  ON_BN_CLICKED(IDC_DONE, &CProductView::OnDone)
END_MESSAGE_MAP()

void CProductView::OnSelectproduct()
{
  UpdateData(TRUE);                              // Transfer data from controls

  // Get a pointer to the document  
  CDBSimpleUpdateDoc* pDoc = static_cast<CDBSimpleUpdateDoc*>(GetDocument()); 

  if(!m_OrderAdded)                              // If order not added
    m_OrderAdded = pDoc->AddOrder();             // then try to add it
  if(m_OrderAdded)
  {
     pDoc->AddOrderDetails(m_pSet->m_ProductID,
                           m_pSet->m_UnitPrice,
                           m_Quantity,
                           m_Discount);
    // Accumulating the total order value
    // Add unit price to total value
    m_TotalValue += m_Quantity*m_pSet->m_UnitPrice*(1.0-m_Discount);


    // Now reset the values in the quantity and discount controls
    m_Quantity = 1;
    m_Discount = 0;
    UpdateData(FALSE);                           // Transfer data to controls
  }
}

void CProductView::InitializeView(void)
{
  // Get a pointer to the document  
  CDBSimpleUpdateDoc* pDoc = static_cast<CDBSimpleUpdateDoc*>(GetDocument());

  m_OrderID = pDoc->m_Order.m_OrderID;
  m_CustomerName = pDoc->m_Order.m_ShipName;
  m_Quantity = 1;                                // Must order at least 1
  m_Discount = 0;                                // No default discount
  m_OrderAdded = false;                          // Order not added initially
  m_TotalValue = 0.0;                            // Reset total value
  UpdateData(FALSE);                             // Transfer data to controls
}

void CProductView::OnDone()
{
  static_cast<CMainFrame*>(GetParentFrame())->SelectView(ORDER_DETAILS);
}

