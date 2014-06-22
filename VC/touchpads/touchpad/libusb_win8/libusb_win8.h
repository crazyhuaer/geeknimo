// libusb_win8.h : main header file for the LIBUSB_WIN8 application
//

#if !defined(AFX_LIBUSB_WIN8_H__E6B52B9A_ED40_4BD7_8765_CC658CD1DB55__INCLUDED_)
#define AFX_LIBUSB_WIN8_H__E6B52B9A_ED40_4BD7_8765_CC658CD1DB55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLibusb_win8App:
// See libusb_win8.cpp for the implementation of this class
//

class CLibusb_win8App : public CWinApp
{
public:
	CLibusb_win8App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibusb_win8App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLibusb_win8App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBUSB_WIN8_H__E6B52B9A_ED40_4BD7_8765_CC658CD1DB55__INCLUDED_)
