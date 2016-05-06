// Stores the data for a new order
#pragma once

class COrder
{
public:
  // Data members same as fields in COrderSet
  long m_OrderID;
  CString m_CustomerID;
  long m_EmployeeID;
  CTime m_OrderDate;
  CTime m_RequiredDate;
  long m_ShipVia;
  double m_Freight;
  CString m_ShipName;
  CString m_ShipAddress;
  CString m_ShipCity;
  CString m_ShipRegion;
  CString m_ShipPostalCode;
  CString m_ShipCountry;

  // Default constructor
  COrder():
      m_OrderID(0),                  // Will be set by CCustomerView object
      m_EmployeeID(1),               // Arbitrary employee ID assigned
      m_ShipVia(3),                  // Arbitrary shipping company
      m_CustomerID(_T("")),     m_Freight(0.0),       m_ShipName(_T("")),
      m_ShipAddress(_T("")),    m_ShipCity(_T("")),   m_ShipRegion(_T("")),
      m_ShipPostalCode(_T("")), m_ShipCountry(_T(""))
  {
    SYSTEMTIME Now;
    GetLocalTime(&Now);                        // Get current time
    m_OrderDate = m_RequiredDate = CTime(Now); // Set time as today
  }
};
