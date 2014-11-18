#if !defined(AFX_DIALOG_BTC15T_H__572CD767_5B13_4066_B775_954CF54D9E05__INCLUDED_)
#define AFX_DIALOG_BTC15T_H__572CD767_5B13_4066_B775_954CF54D9E05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_BTC15T.h : header file
//
#include "MyListCtrl1.h"
#include <shlwapi.h>
/////////////////////////////////////////////////////////////////////////////
// CDialog_BTC15T dialog

class CDialog_BTC15T : public CDialog
{
// Construction
public:
	CDialog_BTC15T(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_BTC15T)
	enum { IDD = IDD_DIALOG_BTC15T };
	MyListCtrl1	m_List_BTC15T;
	//}}AFX_DATA

public:
	int m_line;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_BTC15T)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_BTC15T)
	afx_msg void OnDblclkListBtc15t(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_BTC15T_H__572CD767_5B13_4066_B775_954CF54D9E05__INCLUDED_)
