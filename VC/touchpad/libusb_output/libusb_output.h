// libusb_output.h : main header file for the LIBUSB_OUTPUT application
//

#if !defined(AFX_LIBUSB_OUTPUT_H__BE3BC4B3_769A_44DA_97F2_0EE784884949__INCLUDED_)
#define AFX_LIBUSB_OUTPUT_H__BE3BC4B3_769A_44DA_97F2_0EE784884949__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLibusb_outputApp:
// See libusb_output.cpp for the implementation of this class
//

class CLibusb_outputApp : public CWinApp
{
public:
	CLibusb_outputApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibusb_outputApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLibusb_outputApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBUSB_OUTPUT_H__BE3BC4B3_769A_44DA_97F2_0EE784884949__INCLUDED_)
