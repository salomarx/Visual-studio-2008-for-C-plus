// DBSimpleUpdate.h : main header file for the DBSimpleUpdate application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDBSimpleUpdateApp:
// See DBSimpleUpdate.cpp for the implementation of this class
//

class CDBSimpleUpdateApp : public CWinApp
{
public:
	CDBSimpleUpdateApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDBSimpleUpdateApp theApp;