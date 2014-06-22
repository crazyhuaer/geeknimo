// version.h : main header file for the VERSION application
//

#if !defined(AFX_VERSION_H__54EDFF8A_2FFF_4EB6_850A_B238B088B660__INCLUDED_)
#define AFX_VERSION_H__54EDFF8A_2FFF_4EB6_850A_B238B088B660__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVersionApp:
// See version.cpp for the implementation of this class
//

class CVersionApp : public CWinApp
{
public:
	CVersionApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVersionApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVersionApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VERSION_H__54EDFF8A_2FFF_4EB6_850A_B238B088B660__INCLUDED_)
