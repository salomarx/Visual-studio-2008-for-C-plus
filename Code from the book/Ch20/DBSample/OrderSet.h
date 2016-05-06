// OrderSet.h : Declaration of the COrderSet

#pragma once

// code generated on 18 September 2007, 16:02

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

	long	m_OrderDetailsOrderID;	//Same as Order ID in Orders table.
	long	m_OrderDetailsProductID;	//Same as Product ID in Products table.
	//double	m_OrderDetailsUnitPrice;
	int	m_OrderDetailsQuantity;
	//float	m_OrderDetailsDiscount;
	long	m_OrdersOrderID;	//Unique order number.
	CString	m_OrdersCustomerID;	//Same entry as in Customers table.
	//long	m_OrdersEmployeeID;	//Same entry as in Employees table.
	//CTime	m_OrdersOrderDate;
	//CTime	m_OrdersRequiredDate;
	//CTime	m_OrdersShippedDate;
	//long	m_OrdersShipVia;	//Same as Shipper ID in Shippers table.
	//double	m_OrdersFreight;
	//CStringW	m_OrdersShipName;	//Name of person or company to receive the shipment.
	//CStringW	m_OrdersShipAddress;	//Street address only -- no post-office box allowed.
	//CStringW	m_OrdersShipCity;
	//CStringW	m_OrdersShipRegion;	//State or province.
	//CStringW	m_OrdersShipPostalCode;
	//CStringW	m_OrdersShipCountry;

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

  long m_ProductIDparam;
};


