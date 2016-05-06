// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "DBSimpleUpdate.h"
#include "ViewConstants.h"
#include "CustomerView.h"
#include "ProductView.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame construction/destruction

CMainFrame::CMainFrame() : m_CurrentViewID(ORDER_DETAILS)
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// Enables switching between views. The argument specifies the new view
void CMainFrame::SelectView(ViewID viewID)
{
   CView* pOldActiveView = GetActiveView();     // Get current view

   // Get pointer to new view if it exists
   // if it doesn't the pointer will be null
   CView* pNewActiveView = static_cast<CView*>(GetDlgItem(viewID));

   // If this is first time around for the new view, the new view 
   // won't exist, so we must create it
   // The Order Details view is always created first so we don't need
   // to provide for creating that.
   if (pNewActiveView == NULL)
   {
      switch(viewID)
      {
         case NEW_ORDER:               // Create view to add new order
            pNewActiveView = new CCustomerView;
            break;
         case SELECT_PRODUCT:          // Create view to add product to order
            pNewActiveView = new CProductView;
            break;
          default:
            AfxMessageBox(_T("Invalid View ID"));
            return;
      }

      // Switching the views
      // Obtain the current view context to apply to the new view
      CCreateContext context;
      context.m_pCurrentDoc = pOldActiveView->GetDocument();
      pNewActiveView->Create(NULL, NULL, 0L, CFrameWnd::rectDefault,
                                                  this, viewID, &context);
      pNewActiveView->OnInitialUpdate();
   }
   SetActiveView(pNewActiveView);                 // Activate the new view
   if(viewID==NEW_ORDER)
   {
     static_cast<CCustomerView*>(pNewActiveView)->SetNewOrderID();
     static_cast<CCustomerView*>(pNewActiveView)->OnMove(ID_RECORD_FIRST);
   }
   else if(viewID == SELECT_PRODUCT)
     static_cast<CProductView*>(pNewActiveView)->InitializeView(); 

   pOldActiveView->ShowWindow(SW_HIDE);           // Hide the old view
   pNewActiveView->ShowWindow(SW_SHOW);           // Show the new view
   pOldActiveView->SetDlgCtrlID(m_CurrentViewID); // Set the old view ID
   pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
   m_CurrentViewID = viewID;                      // Save the new view ID
   RecalcLayout();
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame message handlers



