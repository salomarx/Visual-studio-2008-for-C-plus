// DBSimpleUpdateDoc.cpp : implementation of the CDBSimpleUpdateDoc class
//

#include "stdafx.h"
#include "DBSimpleUpdate.h"

#include "OrderDetailsSet.h"
#include "DBSimpleUpdateDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDBSimpleUpdateDoc

IMPLEMENT_DYNCREATE(CDBSimpleUpdateDoc, CDocument)

BEGIN_MESSAGE_MAP(CDBSimpleUpdateDoc, CDocument)
END_MESSAGE_MAP()


// CDBSimpleUpdateDoc construction/destruction

CDBSimpleUpdateDoc::CDBSimpleUpdateDoc()
{
	// TODO: add one-time construction code here

}

CDBSimpleUpdateDoc::~CDBSimpleUpdateDoc()
{
}

BOOL CDBSimpleUpdateDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CDBSimpleUpdateDoc diagnostics

#ifdef _DEBUG
void CDBSimpleUpdateDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDBSimpleUpdateDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDBSimpleUpdateDoc commands

bool CDBSimpleUpdateDoc::AddOrder(void)
{
  try
  {
    if(!m_OrderSet.IsOpen())                     // If recordset is not open
        m_OrderSet.Open();                       // open it

      if(m_OrderSet.CanAppend())                 // If we can add a record
      {                                          // then add it
        m_OrderSet.AddNew();                     // Start adding new record
        m_OrderSet.m_CustomerID = m_Order.m_CustomerID;
        m_OrderSet.m_EmployeeID = m_Order.m_EmployeeID;
        m_OrderSet.m_Freight = m_Order.m_Freight;
        m_OrderSet.m_OrderDate = m_Order.m_OrderDate;
        m_OrderSet.m_OrderID = m_Order.m_OrderID;
        m_OrderSet.m_RequiredDate = m_Order.m_RequiredDate;
        m_OrderSet.m_ShipAddress = m_Order.m_ShipAddress;
        m_OrderSet.m_ShipName = m_Order.m_ShipName;
        m_OrderSet.m_ShipPostalCode = m_Order.m_ShipPostalCode;
        m_OrderSet.m_ShipRegion = m_Order.m_ShipRegion;
        m_OrderSet.m_ShipVia = m_Order.m_ShipVia;

        // No value for the Shipped Date field
        m_OrderSet.SetFieldNull(&m_OrderSet.m_ShippedDate);

        m_OrderSet.Update();                     // Complete adding new record
        return true;                             // Return success
      }
      else
        AfxMessageBox(_T("Cannot append to Orders table"));
  }
  catch(CException* pEx)                         // Catch any exceptions
  {
    pEx->ReportError();                          // Display the error message
  }
  return false;                                  // Here we have failed
}

void CDBSimpleUpdateDoc::AddOrderDetails(long ID, double price, int quantity, float discount)
{
  try
  {
    if(!m_DBSimpleUpdateSet.IsOpen())              // If recordset is not open
      m_DBSimpleUpdateSet.Open();                  // open it

    m_DBSimpleUpdateSet.AddNew();                  // Start adding new record

    // Set Product Details recordset data member values 
    m_DBSimpleUpdateSet.m_OrderID = m_Order.m_OrderID;
    m_DBSimpleUpdateSet.m_Quantity = quantity; 
    m_DBSimpleUpdateSet.m_Discount = discount;
    m_DBSimpleUpdateSet.m_ProductID = ID;
    m_DBSimpleUpdateSet.m_UnitPrice = price;
    m_DBSimpleUpdateSet.Update();                  // Complete adding new record
  }
  catch(CException* pEx)                         // Catch any exceptions
  {
    pEx->ReportError();                          // Display the error message
  }
}
