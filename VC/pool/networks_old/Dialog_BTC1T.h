#if !defined(AFX_DIALOG_BTC1T_H__4F3172AB_8445_4A65_BEDD_56C22ABD63AA__INCLUDED_)
#define AFX_DIALOG_BTC1T_H__4F3172AB_8445_4A65_BEDD_56C22ABD63AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_BTC1T.h : header file
//
#include "MyListCtrl1.h"
#include <shlwapi.h>
/////////////////////////////////////////////////////////////////////////////
// CDialog_BTC1T dialog

class CDialog_BTC1T : public CDialog
{
// Construction
public:
	CDialog_BTC1T(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_BTC1T)
	enum { IDD = IDD_DIALOG_BTC1T };
	MyListCtrl1	m_List_BTC1T;
	//}}AFX_DATA
public:
	int m_line;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_BTC1T)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_BTC1T)
	afx_msg void OnDblclkListBtc1t(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_BTC1T_H__4F3172AB_8445_4A65_BEDD_56C22ABD63AA__INCLUDED_)
