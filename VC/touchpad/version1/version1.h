// version1.h : main header file for the VERSION1 application
//

#if !defined(AFX_VERSION1_H__C2D19812_DD2F_4A57_AB8A_92B25B7FBC12__INCLUDED_)
#define AFX_VERSION1_H__C2D19812_DD2F_4A57_AB8A_92B25B7FBC12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVersion1App:
// See version1.cpp for the implementation of this class
//

class CVersion1App : public CWinApp
{
public:
	CVersion1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVersion1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVersion1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VERSION1_H__C2D19812_DD2F_4A57_AB8A_92B25B7FBC12__INCLUDED_)
