// windows_api_usb.h : main header file for the WINDOWS_API_USB application
//

#if !defined(AFX_WINDOWS_API_USB_H__1D9483AC_8B89_4542_A30A_1DBEE62DA95D__INCLUDED_)
#define AFX_WINDOWS_API_USB_H__1D9483AC_8B89_4542_A30A_1DBEE62DA95D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWindows_api_usbApp:
// See windows_api_usb.cpp for the implementation of this class
//

class CWindows_api_usbApp : public CWinApp
{
public:
	CWindows_api_usbApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWindows_api_usbApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWindows_api_usbApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDOWS_API_USB_H__1D9483AC_8B89_4542_A30A_1DBEE62DA95D__INCLUDED_)
