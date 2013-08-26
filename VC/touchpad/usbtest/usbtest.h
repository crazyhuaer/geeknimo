// usbtest.h : main header file for the USBTEST application
//

#if !defined(AFX_USBTEST_H__D6EB7B54_E829_4AB1_8A86_887007AE6A2E__INCLUDED_)
#define AFX_USBTEST_H__D6EB7B54_E829_4AB1_8A86_887007AE6A2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUsbtestApp:
// See usbtest.cpp for the implementation of this class
//

class CUsbtestApp : public CWinApp
{
public:
	CUsbtestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUsbtestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUsbtestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USBTEST_H__D6EB7B54_E829_4AB1_8A86_887007AE6A2E__INCLUDED_)
