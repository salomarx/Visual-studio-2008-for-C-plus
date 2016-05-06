// StockSet.h : Implementation of the CStockSet class



// CStockSet implementation

// code generated on 24 November 2005, 16:39

#include "stdafx.h"
#include "StockSet.h"
IMPLEMENT_DYNAMIC(CStockSet, CRecordset)

CStockSet::CStockSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ProductID = 0;
	m_ProductName = L"";
	m_SupplierID = 0;
	m_CategoryID = 0;
	m_QuantityPerUnit = L"";
	m_UnitPrice = 0.0;
	m_UnitsInStock = 0;
	m_UnitsOnOrder = 0;
	m_ReorderLevel = 0;
	m_Discontinued = FALSE;
	m_nFields = 10;
	m_nDefaultType = snapshot;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CStockSet::GetDefaultConnect()
{
	return _T("DSN=Northwind;DBQ=D:\\Beginning Visual C++ 2005\\Model Access DB\\Northwind.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CStockSet::GetDefaultSQL()
{
	return _T("[Products]");
}

void CStockSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ProductID]"), m_ProductID);
	RFX_Text(pFX, _T("[ProductName]"), m_ProductName);
	RFX_Long(pFX, _T("[SupplierID]"), m_SupplierID);
	RFX_Long(pFX, _T("[CategoryID]"), m_CategoryID);
	RFX_Text(pFX, _T("[QuantityPerUnit]"), m_QuantityPerUnit);
	RFX_Double(pFX, _T("[UnitPrice]"), m_UnitPrice);
	RFX_Int(pFX, _T("[UnitsInStock]"), m_UnitsInStock);
	RFX_Int(pFX, _T("[UnitsOnOrder]"), m_UnitsOnOrder);
	RFX_Int(pFX, _T("[ReorderLevel]"), m_ReorderLevel);
	RFX_Bool(pFX, _T("[Discontinued]"), m_Discontinued);
}
/////////////////////////////////////////////////////////////////////////////
// CStockSet diagnostics

#ifdef _DEBUG
void CStockSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStockSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


