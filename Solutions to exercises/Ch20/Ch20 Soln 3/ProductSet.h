// DBSampleSet.h: interface of the CProductSet class
//


#pragma once

// code generated on 13 October 2005, 12:21

class CProductSet : public CRecordset
{
public:
	CProductSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CProductSet)

// Field/Param Data

// The string types below (if present) reflect the actual data type of the
// database field - CStringA for ANSI datatypes and CStringW for Unicode
// datatypes. This is to prevent the ODBC driver from performing potentially
// unnecessary conversions.  If you wish, you may change these members to
// CString types and the ODBC driver will perform all necessary conversions.
// (Note: You must use an ODBC driver version that is version 3.5 or greater
// to support both Unicode and these conversions).

	long	m_ProductID;	//Number automatically assigned to new product.
	CString	m_ProductName;
	long	m_SupplierID;	//Same entry as in Suppliers table.
	long	m_CategoryID;	//Same entry as in Categories table.
	CString	m_QuantityPerUnit;	//(e.g., 24-count case, 1-liter bottle).
	double	m_UnitPrice;
	int	m_UnitsInStock;
	int	m_UnitsOnOrder;
	int	m_ReorderLevel;	//Minimum units to maintain in stock.
	BOOL	m_Discontinued;	//Yes means item is no longer available.

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

