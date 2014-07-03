// testhello.h : main header file for the TESTHELLO application
//

#if !defined(AFX_TESTHELLO_H__13946B68_7B92_4A79_BCFB_544D52C1B2AB__INCLUDED_)
#define AFX_TESTHELLO_H__13946B68_7B92_4A79_BCFB_544D52C1B2AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTesthelloApp:
// See testhello.cpp for the implementation of this class
//

class CTesthelloApp : public CWinApp
{
public:
	CTesthelloApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTesthelloApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTesthelloApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTHELLO_H__13946B68_7B92_4A79_BCFB_544D52C1B2AB__INCLUDED_)
