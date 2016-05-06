// OrderSet.h : Implementation of the COrderSet class



// COrderSet implementation

// code generated on 9 October 2005, 19:24

#include "stdafx.h"
#include "OrderSet.h"
IMPLEMENT_DYNAMIC(COrderSet, CRecordset)

COrderSet::COrderSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_OrderID = 0;
	m_CustomerID = L"";
	m_EmployeeID = 0;
	m_OrderDate;
	m_RequiredDate;
	m_ShippedDate;
	m_ShipVia = 0;
	m_Freight = 0.0;
	m_ShipName = L"";
	m_ShipAddress = L"";
	m_ShipCity = L"";
	m_ShipRegion = L"";
	m_ShipPostalCode = L"";
	m_ShipCountry = L"";
	m_nFields = 14;
	m_nDefaultType = dynaset;
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
	return _T("[Orders]");
}

void COrderSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[OrderID]"), m_OrderID);
	RFX_Text(pFX, _T("[CustomerID]"), m_CustomerID);
	RFX_Long(pFX, _T("[EmployeeID]"), m_EmployeeID);
	RFX_Date(pFX, _T("[OrderDate]"), m_OrderDate);
	RFX_Date(pFX, _T("[RequiredDate]"), m_RequiredDate);
	RFX_Date(pFX, _T("[ShippedDate]"), m_ShippedDate);
	RFX_Long(pFX, _T("[ShipVia]"), m_ShipVia);
	RFX_Double(pFX, _T("[Freight]"), m_Freight);
	RFX_Text(pFX, _T("[ShipName]"), m_ShipName);
	RFX_Text(pFX, _T("[ShipAddress]"), m_ShipAddress);
	RFX_Text(pFX, _T("[ShipCity]"), m_ShipCity);
	RFX_Text(pFX, _T("[ShipRegion]"), m_ShipRegion);
	RFX_Text(pFX, _T("[ShipPostalCode]"), m_ShipPostalCode);
	RFX_Text(pFX, _T("[ShipCountry]"), m_ShipCountry);

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



long COrderSet::CreateNewOrderID(void)
{
  if(!IsOpen())
    Open(CRecordset::dynaset);

  // Check for no records in recordset  
  long newOrderID = 0;
  if(!(IsBOF() && IsEOF()))
  {                                         // We have records
    MoveFirst();                            // so go to the first
    while(!IsEOF())                         // Compare with all the others
    {
      // Save order ID if its larger
      if(newOrderID < m_OrderID)
          newOrderID = m_OrderID;

      MoveNext();                           // Go to next record
    }
  }
  return ++newOrderID;
}
