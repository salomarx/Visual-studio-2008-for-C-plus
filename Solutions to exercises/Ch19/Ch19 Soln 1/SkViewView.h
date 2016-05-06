// SkViewView.h : interface of the CSkViewView class
//


#pragma once


class CSkViewView : public CView
{
protected: // create from serialization only
	CSkViewView();
	DECLARE_DYNCREATE(CSkViewView)

// Attributes
public:
	CSkViewDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CSkViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
  virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
};

#ifndef _DEBUG  // debug version in SkViewView.cpp
inline CSkViewDoc* CSkViewView::GetDocument() const
   { return reinterpret_cast<CSkViewDoc*>(m_pDocument); }
#endif

