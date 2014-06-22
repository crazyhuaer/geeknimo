// 20131113_testlibusbwin32.h : main header file for the 20131113_TESTLIBUSBWIN32 application
//

#if !defined(AFX_20131113_TESTLIBUSBWIN32_H__5B758ABE_4F51_469F_AE64_E0FF5017EB4D__INCLUDED_)
#define AFX_20131113_TESTLIBUSBWIN32_H__5B758ABE_4F51_469F_AE64_E0FF5017EB4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy20131113_testlibusbwin32App:
// See 20131113_testlibusbwin32.cpp for the implementation of this class
//

class CMy20131113_testlibusbwin32App : public CWinApp
{
public:
	CMy20131113_testlibusbwin32App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy20131113_testlibusbwin32App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy20131113_testlibusbwin32App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_20131113_TESTLIBUSBWIN32_H__5B758ABE_4F51_469F_AE64_E0FF5017EB4D__INCLUDED_)
