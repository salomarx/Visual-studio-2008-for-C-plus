// OrderDetailsView.h : interface of the COrderDetailsView class
//


#pragma once
#include "afxwin.h"

class COrderDetailsSet;

class COrderDetailsView : public CRecordView
{
protected: // create from serialization only
	COrderDetailsView();
	DECLARE_DYNCREATE(COrderDetailsView)

public:
	enum{ IDD = IDD_DBSIMPLEUPDATE_FORM };
	COrderDetailsSet* m_pSet;
  enum Mode {READ_ONLY, UPDATE};       // Application modes
  Mode m_Mode;                         // Records the current mode

// Attributes
public:
	CDBSimpleUpdateDoc* GetDocument() const;

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
	virtual ~COrderDetailsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnEditorder();
public:
  afx_msg void OnCancel();
public:
  // Control variable for discount edit control
  CEdit m_DiscountCtrl;
public:
  // Control variable for quantity edit control
  CEdit m_QuantityCtrl;
public:
  afx_msg void OnUpdateRecordFirst(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateRecordPrev(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateRecordNext(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateRecordLast(CCmdUI *pCmdUI);
public:
  // Control variable for Cancel button
  CButton m_CancelEditCtrl;
public:
  // Control variable for Edit Order button
  CButton m_EditOrderCtrl;
public:
  afx_msg void OnNeworder();
public:
  CButton m_NewOrderCtrl;
};

#ifndef _DEBUG  // debug version in OrderDetailsView.cpp
inline CDBSimpleUpdateDoc* COrderDetailsView::GetDocument() const
   { return reinterpret_cast<CDBSimpleUpdateDoc*>(m_pDocument); }
#endif

