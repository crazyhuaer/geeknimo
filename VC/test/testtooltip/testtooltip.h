// testtooltip.h : main header file for the TESTTOOLTIP application
//

#if !defined(AFX_TESTTOOLTIP_H__5C5BA052_C1EB_4FD1_AB2D_DF0480AC3686__INCLUDED_)
#define AFX_TESTTOOLTIP_H__5C5BA052_C1EB_4FD1_AB2D_DF0480AC3686__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTesttooltipApp:
// See testtooltip.cpp for the implementation of this class
//

class CTesttooltipApp : public CWinApp
{
public:
	CTesttooltipApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTesttooltipApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTesttooltipApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTTOOLTIP_H__5C5BA052_C1EB_4FD1_AB2D_DF0480AC3686__INCLUDED_)
