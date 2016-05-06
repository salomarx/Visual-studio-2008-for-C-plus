// ProductView.h : interface of the CProductView class
//


#pragma once

class CProductSet;

class CProductView : public CRecordView
{
protected: // create from serialization only
	CProductView();
	DECLARE_DYNCREATE(CProductView)

public:
	enum{ IDD = IDD_DBSAMPLE_FORM };
	CProductSet* m_pSet;

// Attributes
public:
	CDBSampleDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CProductView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnOrders();
protected:
  virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
};

#ifndef _DEBUG  // debug version in ProductView.cpp
inline CDBSampleDoc* CProductView::GetDocument() const
   { return reinterpret_cast<CDBSampleDoc*>(m_pDocument); }
#endif

