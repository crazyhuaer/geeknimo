// QB.h : main header file for the QB application
//

#if !defined(AFX_QB_H__ECA97A8B_EFAF_451B_B0AE_F1EDF4B4A657__INCLUDED_)
#define AFX_QB_H__ECA97A8B_EFAF_451B_B0AE_F1EDF4B4A657__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CQBApp:
// See QB.cpp for the implementation of this class
//

class CQBApp : public CWinApp
{
public:
	CQBApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQBApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CQBApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QB_H__ECA97A8B_EFAF_451B_B0AE_F1EDF4B4A657__INCLUDED_)
