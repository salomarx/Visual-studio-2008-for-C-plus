// DBSimpleUpdateDoc.h : interface of the CDBSimpleUpdateDoc class
//


#pragma once
#include "OrderDetailsSet.h"
#include "orderset.h"
#include "order.h"


class CDBSimpleUpdateDoc : public CDocument
{
protected: // create from serialization only
	CDBSimpleUpdateDoc();
	DECLARE_DYNCREATE(CDBSimpleUpdateDoc)

// Attributes
public:
	COrderDetailsSet m_DBSimpleUpdateSet;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();

// Implementation
public:
	virtual ~CDBSimpleUpdateDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
  COrderSet m_OrderSet;
public:
  bool AddOrder(void);
public:
  void AddOrderDetails(long ID, double price, int quantity, float discount);
public:
  COrder m_Order;
};


