// SkViewView.cpp : implementation of the CSkViewView class
//

#include "stdafx.h"
#include "DllImports.h"
#include "SkView.h"

#include "SkViewDoc.h"
#include "SkViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSkViewView

IMPLEMENT_DYNCREATE(CSkViewView, CView)

BEGIN_MESSAGE_MAP(CSkViewView, CView)
END_MESSAGE_MAP()

// CSkViewView construction/destruction

CSkViewView::CSkViewView()
{
	// TODO: add construction code here

}

CSkViewView::~CSkViewView()
{
}

BOOL CSkViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSkViewView drawing

void CSkViewView::OnDraw(CDC* pDC)
{
	CSkViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

  POSITION aPos = pDoc->GetListHeadPosition();
  CElement* pElement = 0;
  while(aPos)
  {
    pElement = pDoc->GetNext(aPos);
    if(pDC->RectVisible(pElement->GetBoundRect()))
      pElement->Draw(pDC);
  }
}


// CSkViewView diagnostics

#ifdef _DEBUG
void CSkViewView::AssertValid() const
{
	CView::AssertValid();
}

void CSkViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSkViewDoc* CSkViewView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSkViewDoc)));
	return (CSkViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CSkViewView message handlers

void CSkViewView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
  // TODO: Add your specialized code here and/or call the base class

  CView::OnPrepareDC(pDC, pInfo);
  CSkViewDoc* pDoc = GetDocument();
  pDC->SetMapMode(MM_ANISOTROPIC);

  CSize DocSize = pDoc->GetDocExtent().Size();
  DocSize.cy = -DocSize.cy;
  pDC->SetWindowExt(DocSize);

  CRect WinRect;
  GetWindowRect(&WinRect);

  double xScale = (static_cast<double>(WinRect.right - WinRect.left))/
                                    (DocSize.cx);
  double yScale = -(static_cast<double>(WinRect.bottom - WinRect.top))/
                                    (DocSize.cy);
  double scale = xScale<yScale ? xScale : yScale; // Choose smaller scale factor
  long xExtent = static_cast<long>(DocSize.cx*scale);
  long yExtent = static_cast<long>(DocSize.cy*scale);

  pDC->SetViewportExt(static_cast<int>(xExtent), static_cast<int>(-yExtent));
}
