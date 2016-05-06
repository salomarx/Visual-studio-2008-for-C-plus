// CustomerSet.h : Implementation of the CCustomerSet class



// CCustomerSet implementation

// code generated on 9 October 2005, 12:29

#include "stdafx.h"
#include "CustomerSet.h"
IMPLEMENT_DYNAMIC(CCustomerSet, CRecordset)

CCustomerSet::CCustomerSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_CustomerID = L"";
	m_CompanyName = L"";
	m_ContactName = L"";
	m_ContactTitle = L"";
	m_Address = L"";
	m_City = L"";
	m_Region = L"";
	m_PostalCode = L"";
	m_Country = L"";
	m_Phone = L"";
	m_Fax = L"";
	m_nFields = 11;
	m_nDefaultType = snapshot;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CCustomerSet::GetDefaultConnect()
{
	return _T("DSN=Northwind;DBQ=D:\\Beginning Visual C++ 2005\\Model Access DB\\Northwind.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CCustomerSet::GetDefaultSQL()
{
	return _T("[Customers]");
}

void CCustomerSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Text(pFX, _T("[CustomerID]"), m_CustomerID);
	RFX_Text(pFX, _T("[CompanyName]"), m_CompanyName);
	RFX_Text(pFX, _T("[ContactName]"), m_ContactName);
	RFX_Text(pFX, _T("[ContactTitle]"), m_ContactTitle);
	RFX_Text(pFX, _T("[Address]"), m_Address);
	RFX_Text(pFX, _T("[City]"), m_City);
	RFX_Text(pFX, _T("[Region]"), m_Region);
	RFX_Text(pFX, _T("[PostalCode]"), m_PostalCode);
	RFX_Text(pFX, _T("[Country]"), m_Country);
	RFX_Text(pFX, _T("[Phone]"), m_Phone);
	RFX_Text(pFX, _T("[Fax]"), m_Fax);

}
/////////////////////////////////////////////////////////////////////////////
// CCustomerSet diagnostics

#ifdef _DEBUG
void CCustomerSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCustomerSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


