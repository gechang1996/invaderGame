
// Project1.h : main header file for the Project1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


/** CProject1App:
 * See Project1.cpp for the implementation of this class */
class CProject1App : public CWinApp
{
private:
	/** GDI startup input
	 * /return  */

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	
	/// gdi plus token pointer
	ULONG_PTR gdiplusToken;
public:
	CProject1App() noexcept;


// Overrides
public:
	
	/** \cond
	 * Init instance
	 * /returns bool false of true */
	virtual BOOL InitInstance();
	
	/** Exit instance
	 * /returns CWinApp::ExitInstance()  */
	virtual int ExitInstance();

	/** \endcond */

	// Implementation

public:
	/// Info
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProject1App theApp;
