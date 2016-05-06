// DBSampleDoc.h : interface of the CDBSampleDoc class
//


#pragma once
#include "ProductSet.h"
#include "orderset.h"
#include "customerset.h"
#include "StockSet.h"


class CDBSampleDoc : public CDocument
{
protected: // create from serialization only
	CDBSampleDoc();
	DECLARE_DYNCREATE(CDBSampleDoc)

// Attributes
public:
	CProductSet m_DBSampleSet;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();

// Implementation
public:
	virtual ~CDBSampleDoc();
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
  CCustomerSet m_CustomerSet;
public:
   CStockSet m_StockSet;
};


