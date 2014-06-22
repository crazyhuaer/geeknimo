// mschart.h : main header file for the MSCHART application
//

#if !defined(AFX_MSCHART_H__527061B3_FD07_4F1F_B1DE_FC85E0039C38__INCLUDED_)
#define AFX_MSCHART_H__527061B3_FD07_4F1F_B1DE_FC85E0039C38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMschartApp:
// See mschart.cpp for the implementation of this class
//

class CMschartApp : public CWinApp
{
public:
	CMschartApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMschartApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMschartApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSCHART_H__527061B3_FD07_4F1F_B1DE_FC85E0039C38__INCLUDED_)
