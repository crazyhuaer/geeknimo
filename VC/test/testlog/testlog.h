// testlog.h : main header file for the TESTLOG application
//

#if !defined(AFX_TESTLOG_H__2949AB12_5831_4BA3_B4BA_1A1AB9A0914A__INCLUDED_)
#define AFX_TESTLOG_H__2949AB12_5831_4BA3_B4BA_1A1AB9A0914A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "Log.h"
/////////////////////////////////////////////////////////////////////////////
// CTestlogApp:
// See testlog.cpp for the implementation of this class
//

class CTestlogApp : public CWinApp
{
public:
	CTestlogApp();
	CLog m_Log;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestlogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestlogApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTLOG_H__2949AB12_5831_4BA3_B4BA_1A1AB9A0914A__INCLUDED_)
