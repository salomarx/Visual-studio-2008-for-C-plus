// ShippersSet.h : Implementation of the CShippersSet class



// CShippersSet implementation

// code generated on 29 November 2005, 19:14

#include "stdafx.h"
#include "ShippersSet.h"
IMPLEMENT_DYNAMIC(CShippersSet, CRecordset)

CShippersSet::CShippersSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ShipperID = 0;
	m_CompanyName = L"";
	m_Phone = L"";
	m_nFields = 3;
	m_nDefaultType = snapshot;
  m_strSort = _T("CompanyName");
}

//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CShippersSet::GetDefaultConnect()
{
	return _T("DSN=Northwind;DBQ=D:\\Beginning Visual C++ 2005\\Model Access DB\\Northwind.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CShippersSet::GetDefaultSQL()
{
	return _T("[Shippers]");
}

void CShippersSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ShipperID]"), m_ShipperID);
	RFX_Text(pFX, _T("[CompanyName]"), m_CompanyName);
	RFX_Text(pFX, _T("[Phone]"), m_Phone);

}
/////////////////////////////////////////////////////////////////////////////
// CShippersSet diagnostics

#ifdef _DEBUG
void CShippersSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CShippersSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


