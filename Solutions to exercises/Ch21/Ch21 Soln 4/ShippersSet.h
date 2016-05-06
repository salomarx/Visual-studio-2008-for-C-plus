// ShippersSet.h : Declaration of the CShippersSet

#pragma once

// code generated on 29 November 2005, 19:14

class CShippersSet : public CRecordset
{
public:
	CShippersSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CShippersSet)

// Field/Param Data

// The string types below (if present) reflect the actual data type of the
// database field - CStringA for ANSI datatypes and CStringW for Unicode
// datatypes. This is to prevent the ODBC driver from performing potentially
// unnecessary conversions.  If you wish, you may change these members to
// CString types and the ODBC driver will perform all necessary conversions.
// (Note: You must use an ODBC driver version that is version 3.5 or greater
// to support both Unicode and these conversions).

	long	m_ShipperID;	//Number automatically assigned to new shipper.
	CString	m_CompanyName;	//Name of shipping company.
	CString	m_Phone;	//Phone number includes country code or area code.

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


