// OrderDetailsSet.h: interface of the COrderDetailsSet class
//


#pragma once

// code generated on 8 October 2005, 20:05

class COrderDetailsSet : public CRecordset
{
public:
	COrderDetailsSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(COrderDetailsSet)

// Field/Param Data

// The string types below (if present) reflect the actual data type of the
// database field - CStringA for ANSI datatypes and CStringW for Unicode
// datatypes. This is to prevent the ODBC driver from performing potentially
// unnecessary conversions.  If you wish, you may change these members to
// CString types and the ODBC driver will perform all necessary conversions.
// (Note: You must use an ODBC driver version that is version 3.5 or greater
// to support both Unicode and these conversions).

	long	m_OrderID;	//Same as Order ID in Orders table.
	long	m_ProductID;	//Same as Product ID in Products table.
	double	m_UnitPrice;
	int	m_Quantity;
	float	m_Discount;

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

