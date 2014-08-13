// menu.h : main header file for the MENU application
//

#if !defined(AFX_MENU_H__F4862014_F64A_46CA_94D6_74870BE3C225__INCLUDED_)
#define AFX_MENU_H__F4862014_F64A_46CA_94D6_74870BE3C225__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMenuApp:
// See menu.cpp for the implementation of this class
//

class CMenuApp : public CWinApp
{
public:
	CMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMenuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENU_H__F4862014_F64A_46CA_94D6_74870BE3C225__INCLUDED_)
