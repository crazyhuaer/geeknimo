// ReadandWrite.h : main header file for the READANDWRITE application
//

#if !defined(AFX_READANDWRITE_H__2CC8007D_F023_4F1F_A784_A570EB67D0B5__INCLUDED_)
#define AFX_READANDWRITE_H__2CC8007D_F023_4F1F_A784_A570EB67D0B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReadandWriteApp:
// See ReadandWrite.cpp for the implementation of this class
//

class CReadandWriteApp : public CWinApp
{
public:
	CReadandWriteApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadandWriteApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReadandWriteApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READANDWRITE_H__2CC8007D_F023_4F1F_A784_A570EB67D0B5__INCLUDED_)
