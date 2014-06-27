// networks.h : main header file for the NETWORKS application
//

#if !defined(AFX_NETWORKS_H__6FFA0169_B682_4D71_B1D5_97D342A661B3__INCLUDED_)
#define AFX_NETWORKS_H__6FFA0169_B682_4D71_B1D5_97D342A661B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "log.h"
/////////////////////////////////////////////////////////////////////////////
// CNetworksApp:
// See networks.cpp for the implementation of this class
//

class CNetworksApp : public CWinApp
{
public:
	CNetworksApp();
	CLog m_Log;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetworksApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNetworksApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETWORKS_H__6FFA0169_B682_4D71_B1D5_97D342A661B3__INCLUDED_)
