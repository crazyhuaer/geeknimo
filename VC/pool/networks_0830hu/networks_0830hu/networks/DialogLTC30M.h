#if !defined(AFX_DIALOGLTC30M_H__154FFAD4_C103_4438_B648_EE49CAD3A1BC__INCLUDED_)
#define AFX_DIALOGLTC30M_H__154FFAD4_C103_4438_B648_EE49CAD3A1BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogLTC30M.h : header file
//
#include "MyListCtrl1.h"
/////////////////////////////////////////////////////////////////////////////
// CDialogLTC30M dialog

class CDialogLTC30M : public CDialog
{
// Construction
public:
	CDialogLTC30M(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogLTC30M)
	enum { IDD = IDD_DIALOG_LTC30M };
	MyListCtrl1	m_List_LTC30M;
	//}}AFX_DATA
public:
	int m_line;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogLTC30M)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogLTC30M)
	afx_msg void OnDblclkListLtc30m(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGLTC30M_H__154FFAD4_C103_4438_B648_EE49CAD3A1BC__INCLUDED_)
