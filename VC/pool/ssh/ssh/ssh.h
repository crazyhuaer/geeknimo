// ssh.h : main header file for the SSH application
//

#if !defined(AFX_SSH_H__6BE08928_EBDE_40CB_8E6C_879355C68455__INCLUDED_)
#define AFX_SSH_H__6BE08928_EBDE_40CB_8E6C_879355C68455__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSshApp:
// See ssh.cpp for the implementation of this class
//

class CSshApp : public CWinApp
{
public:
	CSshApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSshApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSshApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSH_H__6BE08928_EBDE_40CB_8E6C_879355C68455__INCLUDED_)
