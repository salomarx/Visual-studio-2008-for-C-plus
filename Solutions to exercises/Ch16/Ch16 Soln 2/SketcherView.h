// SketcherView.h : interface of the CSketcherView class
//


#pragma once
class CElement;              // Forward class declaration
//#include "atltypes.h"


class CSketcherView : public CScrollView
{
protected: // create from serialization only
	CSketcherView();
	DECLARE_DYNCREATE(CSketcherView)

// Attributes
public:
	CSketcherDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CSketcherView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
public:
  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
public:
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);
protected:
  // First point recorded for an element
  CPoint m_FirstPoint;
  CPoint m_SecondPoint;
  // Pointer to a temporary element
  CElement* m_pTempElement;
  CElement* m_pSelected;         // Currently selected element
  BOOL m_MoveMode;               // Move element flag
  CPoint m_CursorPos;            // Cursor position
  CPoint m_FirstPos;             // Original position in a move

  void MoveElement(CClientDC& aDC, CPoint& point);  // Move an element
  // Create a new element on the heap
  CElement* CreateElement(void);
  virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
public:
  virtual void OnInitialUpdate();
public:
  afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
public:
  afx_msg void OnElementMove();
public:
  afx_msg void OnElementDelete();
public:
  afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
public:
  afx_msg void OnElementSendtoback();
};

#ifndef _DEBUG  // debug version in SketcherView.cpp
inline CSketcherDoc* CSketcherView::GetDocument() const
   { return reinterpret_cast<CSketcherDoc*>(m_pDocument); }
#endif

