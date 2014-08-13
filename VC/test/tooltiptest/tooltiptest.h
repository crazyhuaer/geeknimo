// tooltiptest.h : main header file for the TOOLTIPTEST application
//

#if !defined(AFX_TOOLTIPTEST_H__603AC5E7_E4F6_4322_939A_0754A82A1FE3__INCLUDED_)
#define AFX_TOOLTIPTEST_H__603AC5E7_E4F6_4322_939A_0754A82A1FE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTooltiptestApp:
// See tooltiptest.cpp for the implementation of this class
//

class CTooltiptestApp : public CWinApp
{
public:
	CTooltiptestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTooltiptestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTooltiptestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLTIPTEST_H__603AC5E7_E4F6_4322_939A_0754A82A1FE3__INCLUDED_)
