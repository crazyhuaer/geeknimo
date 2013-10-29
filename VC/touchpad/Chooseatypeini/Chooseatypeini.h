// Chooseatypeini.h : main header file for the CHOOSEATYPEINI application
//

#if !defined(AFX_CHOOSEATYPEINI_H__F66D9C1F_D15A_4CF4_805A_388B15ACF70B__INCLUDED_)
#define AFX_CHOOSEATYPEINI_H__F66D9C1F_D15A_4CF4_805A_388B15ACF70B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CChooseatypeiniApp:
// See Chooseatypeini.cpp for the implementation of this class
//

class CChooseatypeiniApp : public CWinApp
{
public:
	CChooseatypeiniApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChooseatypeiniApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CChooseatypeiniApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOOSEATYPEINI_H__F66D9C1F_D15A_4CF4_805A_388B15ACF70B__INCLUDED_)
