// SkView.h : main header file for the SkView application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSkViewApp:
// See SkView.cpp for the implementation of this class
//

class CSkViewApp : public CWinApp
{
public:
	CSkViewApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSkViewApp theApp;