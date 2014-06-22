// dialog_usb_test.h : main header file for the DIALOG_USB_TEST application
//

#if !defined(AFX_DIALOG_USB_TEST_H__307180F2_0636_4055_9DD2_13FC45BA3BF3__INCLUDED_)
#define AFX_DIALOG_USB_TEST_H__307180F2_0636_4055_9DD2_13FC45BA3BF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDialog_usb_testApp:
// See dialog_usb_test.cpp for the implementation of this class
//

class CDialog_usb_testApp : public CWinApp
{
public:
	CDialog_usb_testApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_usb_testApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDialog_usb_testApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_USB_TEST_H__307180F2_0636_4055_9DD2_13FC45BA3BF3__INCLUDED_)
