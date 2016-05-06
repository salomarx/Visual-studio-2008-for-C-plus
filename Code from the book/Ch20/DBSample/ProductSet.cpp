// ProductSet.cpp : implementation of the CProductSet class
//

#include "stdafx.h"
#include "DBSample.h"
#include "ProductSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProductSet implementation

// code generated on 18 September 2007, 14:51

IMPLEMENT_DYNAMIC(CProductSet, CRecordset)

CProductSet::CProductSet(CDatabase* pdb)
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
// #error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CProductSet::GetDefaultConnect()
{
	return _T("DSN=Northwind;DBQ=C:\\Model Access DB\\Northwind.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CProductSet::GetDefaultSQL()
{
	return _T("[Products]");
}

void CProductSet::DoFieldExchange(CFieldExchange* pFX)
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
// CProductSet diagnostics

#ifdef _DEBUG
void CProductSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CProductSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

