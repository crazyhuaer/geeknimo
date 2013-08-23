// FullScreenTouchPad.h : main header file for the FULLSCREENTOUCHPAD application
//

#if !defined(AFX_FULLSCREENTOUCHPAD_H__0139434B_347D_4AB5_8B60_4A5119A55447__INCLUDED_)
#define AFX_FULLSCREENTOUCHPAD_H__0139434B_347D_4AB5_8B60_4A5119A55447__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFullScreenTouchPadApp:
// See FullScreenTouchPad.cpp for the implementation of this class
//

class CFullScreenTouchPadApp : public CWinApp
{
public:
	CFullScreenTouchPadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFullScreenTouchPadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFullScreenTouchPadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FULLSCREENTOUCHPAD_H__0139434B_347D_4AB5_8B60_4A5119A55447__INCLUDED_)
