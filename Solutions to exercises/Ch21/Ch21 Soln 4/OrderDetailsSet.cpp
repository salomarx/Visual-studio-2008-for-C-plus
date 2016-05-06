// OrderDetailsSet.cpp : implementation of the COrderDetailsSet class
//

#include "stdafx.h"
#include "DBSimpleUpdate.h"
#include "OrderDetailsSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COrderDetailsSet implementation

// code generated on 8 October 2005, 20:05

IMPLEMENT_DYNAMIC(COrderDetailsSet, CRecordset)

COrderDetailsSet::COrderDetailsSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_OrderID = 0;
	m_ProductID = 0;
	m_UnitPrice = 0.0;
	m_Quantity = 0;
	m_Discount = 0.0;
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString COrderDetailsSet::GetDefaultConnect()
{
	return _T("DSN=Northwind;DBQ=D:\\Beginning Visual C++ 2005\\Model Access DB\\Northwind.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString COrderDetailsSet::GetDefaultSQL()
{
	return _T("[Order Details]");
}

void COrderDetailsSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[OrderID]"), m_OrderID);
	RFX_Long(pFX, _T("[ProductID]"), m_ProductID);
	RFX_Double(pFX, _T("[UnitPrice]"), m_UnitPrice);
	RFX_Int(pFX, _T("[Quantity]"), m_Quantity);
	RFX_Single(pFX, _T("[Discount]"), m_Discount);

}
/////////////////////////////////////////////////////////////////////////////
// COrderDetailsSet diagnostics

#ifdef _DEBUG
void COrderDetailsSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void COrderDetailsSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

