// OrderSet.h : Declaration of the COrderSet

#pragma once

// code generated on 9 October 2005, 19:24

class COrderSet : public CRecordset
{
public:
	COrderSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(COrderSet)

// Field/Param Data

// The string types below (if present) reflect the actual data type of the
// database field - CStringA for ANSI datatypes and CStringW for Unicode
// datatypes. This is to prevent the ODBC driver from performing potentially
// unnecessary conversions.  If you wish, you may change these members to
// CString types and the ODBC driver will perform all necessary conversions.
// (Note: You must use an ODBC driver version that is version 3.5 or greater
// to support both Unicode and these conversions).

	long	m_OrderID;	//Unique order number.
	CString	m_CustomerID;	//Same entry as in Customers table.
	long	m_EmployeeID;	//Same entry as in Employees table.
	CTime	m_OrderDate;
	CTime	m_RequiredDate;
	CTime	m_ShippedDate;
	long	m_ShipVia;	//Same as Shipper ID in Shippers table.
	double	m_Freight;
	CString	m_ShipName;	//Name of person or company to receive the shipment.
	CString	m_ShipAddress;	//Street address only -- no post-office box allowed.
	CString	m_ShipCity;
	CString	m_ShipRegion;	//State or province.
	CString	m_ShipPostalCode;
	CString	m_ShipCountry;

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

public:
  long CreateNewOrderID(void);
};


