// ChildFrm.cpp : implementation of the CChildFrame class
//
#include "stdafx.h"
#include "Sketcher.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
  ON_WM_CREATE()
END_MESSAGE_MAP()


// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying the CREATESTRUCT cs
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}


// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG


// CChildFrame message handlers

int CChildFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
  if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
    return -1;

  // Create the status bar
  m_StatusBar.Create(this);

  // Work out the width of the text we want to display
  CRect textRect;
  CClientDC aDC(&m_StatusBar);
  aDC.SelectObject(m_StatusBar.GetFont());
  aDC.DrawText(_T("View Scale:99"), -1, textRect, DT_SINGLELINE|DT_CALCRECT);

  // Setup a part big enough to take the text
  int width = textRect.Width();
  m_StatusBar.GetStatusBarCtrl().SetParts(1, &width);

  // Initialize the text for the status bar
  m_StatusBar.GetStatusBarCtrl().SetText(_T("View Scale:1"), 0, 0);

  return 0;
}
