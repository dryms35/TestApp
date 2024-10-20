
// TestApp.Mfc.h : main header file for the TestApp.Mfc application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTestAppMfcApp:
// See TestApp.Mfc.cpp for the implementation of this class
//

class CTestAppMfcApp : public CWinAppEx
{
public:
	CTestAppMfcApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	afx_msg void OnAppTest();
	DECLARE_MESSAGE_MAP()
};

extern CTestAppMfcApp theApp;
