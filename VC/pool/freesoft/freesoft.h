// freesoft.h : main header file for the FREESOFT application
//

#if !defined(AFX_FREESOFT_H__CB6D052D_972F_4F4A_901F_771173C1A5A8__INCLUDED_)
#define AFX_FREESOFT_H__CB6D052D_972F_4F4A_901F_771173C1A5A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFreesoftApp:
// See freesoft.cpp for the implementation of this class
//

class CFreesoftApp : public CWinApp
{
public:
	CFreesoftApp();

public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFreesoftApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFreesoftApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FREESOFT_H__CB6D052D_972F_4F4A_901F_771173C1A5A8__INCLUDED_)
