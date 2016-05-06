// EmployeeSet.h : Implementation of the CEmployeeSet class



// CEmployeeSet implementation

// code generated on 29 November 2005, 14:36

#include "stdafx.h"
#include "EmployeeSet.h"
IMPLEMENT_DYNAMIC(CEmployeeSet, CRecordset)

CEmployeeSet::CEmployeeSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_EmployeeID = 0;
	m_LastName = L"";
	m_FirstName = L"";
	m_nFields = 3;
	m_nDefaultType = snapshot;
  m_strSort = _T("LastName, FirstName");
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CEmployeeSet::GetDefaultConnect()
{
	return _T("DSN=Northwind;DBQ=D:\\Beginning Visual C++ 2005\\Model Access DB\\Northwind.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CEmployeeSet::GetDefaultSQL()
{
	return _T("[Employees]");
}

void CEmployeeSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[EmployeeID]"), m_EmployeeID);
	RFX_Text(pFX, _T("[LastName]"), m_LastName);
	RFX_Text(pFX, _T("[FirstName]"), m_FirstName);
}
/////////////////////////////////////////////////////////////////////////////
// CEmployeeSet diagnostics

#ifdef _DEBUG
void CEmployeeSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEmployeeSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


