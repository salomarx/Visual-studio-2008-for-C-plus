// CStockView implementation
#include "stdafx.h"
#include "resource.h"
#include "OurConstants.h"
#include "Mainfrm.h"
#include "StockView.h"
#include "StockSet.h"
#include "DBSampleDoc.h"

IMPLEMENT_DYNCREATE(CStockView, CRecordView)

CStockView::CStockView(): CRecordView(CStockView::IDD), m_pSet(NULL)
{
}

CStockSet* CStockView::GetRecordset()
  {
    ASSERT(m_pSet != NULL);
    return m_pSet;
  }

  CRecordset* CStockView::OnGetRecordset()
  {
    return m_pSet;
  }

void CStockView::DoDataExchange(CDataExchange* pDX)
{
  CRecordView::DoDataExchange(pDX);
   DDX_FieldText(pDX, IDC_STOCKNAME, m_pSet->m_ProductName, m_pSet);
   DDX_FieldText(pDX, IDC_STOCKID, m_pSet->m_ProductID, m_pSet);
   DDX_FieldText(pDX, IDC_STOCKUNITPRICE, m_pSet->m_UnitPrice, m_pSet);
   DDX_FieldText(pDX, IDC_STOCKUNITSINSTOCK, m_pSet->m_UnitsInStock, m_pSet);
   DDX_FieldText(pDX, IDC_STOCKREORDERLEVEL, m_pSet->m_ReorderLevel, m_pSet);
}

  // COrderView diagnostics

#ifdef _DEBUG
void CStockView::AssertValid() const
{
  CRecordView::AssertValid();
}

void CStockView::Dump(CDumpContext& dc) const
{
  CRecordView::Dump(dc);
}
#endif //_DEBUG
BEGIN_MESSAGE_MAP(CStockView, CRecordView)
  ON_BN_CLICKED(IDC_STOCKPRODUCTS, &CStockView::OnProducts)
END_MESSAGE_MAP()

void CStockView::OnProducts()
{
  static_cast<CMainFrame*>(GetParentFrame())->SelectView(PRODUCT_VIEW);
}

void CStockView::OnInitialUpdate()
{

  BeginWaitCursor();

  CDBSampleDoc* pDoc = static_cast<CDBSampleDoc*>(GetDocument());
	m_pSet = &(pDoc->m_StockSet);

  // Set the database for the recordset
  m_pSet->m_pDatabase = pDoc->m_DBSampleSet.m_pDatabase;
  CRecordView::OnInitialUpdate();
  if(m_pSet->IsOpen())
  {
    CString strTitle = m_pSet->m_pDatabase->GetDatabaseName();
    CString strTable = m_pSet->GetTableName();
    if(!strTable.IsEmpty())
      strTitle += _T(":") + strTable;
    GetDocument()->SetTitle(strTitle);
   }

  EndWaitCursor();
}
