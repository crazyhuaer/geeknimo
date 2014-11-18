// modifyip.h : main header file for the MODIFYIP application
//

#if !defined(AFX_MODIFYIP_H__1A6275B3_C1DD_4F02_955A_430A264BDEDC__INCLUDED_)
#define AFX_MODIFYIP_H__1A6275B3_C1DD_4F02_955A_430A264BDEDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CModifyipApp:
// See modifyip.cpp for the implementation of this class
//

class CModifyipApp : public CWinApp
{
public:
	CModifyipApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModifyipApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CModifyipApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODIFYIP_H__1A6275B3_C1DD_4F02_955A_430A264BDEDC__INCLUDED_)
