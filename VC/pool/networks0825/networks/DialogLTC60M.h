#if !defined(AFX_DIALOGLTC60M_H__B94EAA5A_5C9D_422A_900C_D820CD23E2B6__INCLUDED_)
#define AFX_DIALOGLTC60M_H__B94EAA5A_5C9D_422A_900C_D820CD23E2B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogLTC60M.h : header file
//
#include "MyListCtrl1.h"
/////////////////////////////////////////////////////////////////////////////
// CDialogLTC60M dialog

class CDialogLTC60M : public CDialog
{
// Construction
public:
	CDialogLTC60M(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogLTC60M)
	enum { IDD = IDD_DIALOG_LTC60M };
	MyListCtrl1	m_List_LTC60M;
	//}}AFX_DATA
public:
	int m_line;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogLTC60M)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogLTC60M)
	afx_msg void OnDblclkListLtc60m(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGLTC60M_H__B94EAA5A_5C9D_422A_900C_D820CD23E2B6__INCLUDED_)
