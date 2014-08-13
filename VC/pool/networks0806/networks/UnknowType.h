#if !defined(AFX_UNKNOWTYPE_H__D85E2CE3_5F0E_4F09_A248_7D0398E018BD__INCLUDED_)
#define AFX_UNKNOWTYPE_H__D85E2CE3_5F0E_4F09_A248_7D0398E018BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UnknowType.h : header file
//
#include "MyListCtrl1.h"
/////////////////////////////////////////////////////////////////////////////
// UnknowType dialog

class UnknowType : public CDialog
{
// Construction
public:
	UnknowType(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(UnknowType)
	enum { IDD = IDD_DIALOG_UNKNOWTYPE };
	MyListCtrl1	m_List_UnknowType;
	//}}AFX_DATA

public:
	int m_line;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(UnknowType)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(UnknowType)
	afx_msg void OnDblclkListUnknowtype(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UNKNOWTYPE_H__D85E2CE3_5F0E_4F09_A248_7D0398E018BD__INCLUDED_)
