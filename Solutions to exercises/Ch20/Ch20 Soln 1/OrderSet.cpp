// OrderSet.h : Implementation of the COrderSet class



// COrderSet implementation

// code generated on 13 October 2005, 12:51

#include "stdafx.h"
#include "OrderSet.h"
IMPLEMENT_DYNAMIC(COrderSet, CRecordset)

COrderSet::COrderSet(CDatabase* pdb)
	: CRecordset(pdb)
  , m_ProductIDparam(0)
{
	m_OrderDetailsOrderID = 0;
	m_OrderDetailsProductID = 0;
	//m_OrderDetailsUnitPrice = 0.0;
	m_OrderDetailsQuantity = 0;
	//m_OrderDetailsDiscount = 0.0;
	m_OrdersOrderID = 0;
	m_OrdersCustomerID = L"";
	//m_OrdersEmployeeID = 0;
	//m_OrdersOrderDate;
	//m_OrdersRequiredDate;
	//m_OrdersShippedDate;
	//m_OrdersShipVia = 0;
	//m_OrdersFreight = 0.0;
	//m_OrdersShipName = L"";
	//m_OrdersShipAddress = L"";
	//m_OrdersShipCity = L"";
	//m_OrdersShipRegion = L"";
	//m_OrdersShipPostalCode = L"";
	//m_OrdersShipCountry = L"";
	//m_nFields = 19;
	m_nFields = 5;
   m_ProductIDparam = 0L;    // Set initial parameter value
   m_nParams = 1;            // Set number of parameters
	m_nDefaultType = snapshot;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString COrderSet::GetDefaultConnect()
{
	return _T("DSN=Northwind;DBQ=D:\\Beginning Visual C++ 2005\\Model Access DB\\Northwind.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString COrderSet::GetDefaultSQL()
{
	return _T("[Order Details],[Orders]");
}

void COrderSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[Order Details].[OrderID]"), m_OrderDetailsOrderID);
	RFX_Long(pFX, _T("[Order Details].[ProductID]"), m_OrderDetailsProductID);
	//RFX_Double(pFX, _T("[Order Details].[UnitPrice]"), m_OrderDetailsUnitPrice);
	RFX_Int(pFX, _T("[Order Details].[Quantity]"), m_OrderDetailsQuantity);
	//RFX_Single(pFX, _T("[Order Details].[Discount]"), m_OrderDetailsDiscount);
	RFX_Long(pFX, _T("[Orders].[OrderID]"), m_OrdersOrderID);
	RFX_Text(pFX, _T("[Orders].[CustomerID]"), m_OrdersCustomerID);
	//RFX_Long(pFX, _T("[Orders].[EmployeeID]"), m_OrdersEmployeeID);
	//RFX_Date(pFX, _T("[Orders].[OrderDate]"), m_OrdersOrderDate);
	//RFX_Date(pFX, _T("[Orders].[RequiredDate]"), m_OrdersRequiredDate);
	//RFX_Date(pFX, _T("[Orders].[ShippedDate]"), m_OrdersShippedDate);
	//RFX_Long(pFX, _T("[Orders].[ShipVia]"), m_OrdersShipVia);
	//RFX_Double(pFX, _T("[Orders].[Freight]"), m_OrdersFreight);
	//RFX_Text(pFX, _T("[Orders].[ShipName]"), m_OrdersShipName);
	//RFX_Text(pFX, _T("[Orders].[ShipAddress]"), m_OrdersShipAddress);
	//RFX_Text(pFX, _T("[Orders].[ShipCity]"), m_OrdersShipCity);
	//RFX_Text(pFX, _T("[Orders].[ShipRegion]"), m_OrdersShipRegion);
	//RFX_Text(pFX, _T("[Orders].[ShipPostalCode]"), m_OrdersShipPostalCode);
	//RFX_Text(pFX, _T("[Orders].[ShipCountry]"), m_OrdersShipCountry);
   // Set the field type as parameter
   pFX->SetFieldType(CFieldExchange::param);
   RFX_Long(pFX,_T("ProductIDParam"), m_ProductIDparam);
}
/////////////////////////////////////////////////////////////////////////////
// COrderSet diagnostics

#ifdef _DEBUG
void COrderSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void COrderSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


