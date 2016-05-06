// CustomerSet.h : Declaration of the CCustomerSet

#pragma once

// code generated on 9 October 2005, 12:29

class CCustomerSet : public CRecordset
{
public:
	CCustomerSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCustomerSet)

// Field/Param Data

// The string types below (if present) reflect the actual data type of the
// database field - CStringA for ANSI datatypes and CStringW for Unicode
// datatypes. This is to prevent the ODBC driver from performing potentially
// unnecessary conversions.  If you wish, you may change these members to
// CString types and the ODBC driver will perform all necessary conversions.
// (Note: You must use an ODBC driver version that is version 3.5 or greater
// to support both Unicode and these conversions).

	CString	m_CustomerID;	//Unique five-character code based on customer name.
	CString	m_CompanyName;
	CString	m_ContactName;
	CString	m_ContactTitle;
	CString	m_Address;	//Street or post-office box.
	CString	m_City;
	CString	m_Region;	//State or province.
	CString	m_PostalCode;
	CString	m_Country;
	CString	m_Phone;	//Phone number includes country code or area code.
	CString	m_Fax;	//Phone number includes country code or area code.

// Overrides
	// Wizard generated virtual function overrides
	public:
	virtual CString GetDefaultConnect();	// Default connection string

	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


