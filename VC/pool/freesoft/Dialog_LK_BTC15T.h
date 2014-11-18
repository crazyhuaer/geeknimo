#if !defined(AFX_DIALOG_LK_BTC15T_H__29FA329B_7EF5_4C85_A0A1_B67D7C2BAE89__INCLUDED_)
#define AFX_DIALOG_LK_BTC15T_H__29FA329B_7EF5_4C85_A0A1_B67D7C2BAE89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_LK_BTC15T.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_LK_BTC15T dialog
#include "MyListCtrl.h"

class CDialog_LK_BTC15T : public CDialog
{
// Construction
public:
	CDialog_LK_BTC15T(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_LK_BTC15T)
	enum { IDD = IDD_DIALOG_LKBTC15T };
	CMyListCtrl	m_cList_LK_BTC15T;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_LK_BTC15T)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_LK_BTC15T)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_LK_BTC15T_H__29FA329B_7EF5_4C85_A0A1_B67D7C2BAE89__INCLUDED_)
