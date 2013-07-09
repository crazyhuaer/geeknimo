#if !defined(AFX_DIALOG_TAB_HELP_H__2E8DEC49_4495_4D50_8438_3E3D3F9C6883__INCLUDED_)
#define AFX_DIALOG_TAB_HELP_H__2E8DEC49_4495_4D50_8438_3E3D3F9C6883__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_Tab_Help.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_Help dialog

class CDialog_Tab_Help : public CDialog
{
// Construction
public:
	CDialog_Tab_Help(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_Tab_Help)
	enum { IDD = IDD_TAB_HELP };
	CEdit	m_UserPassword;
	CEdit	m_UserName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_Tab_Help)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_Tab_Help)
	afx_msg void OnLogin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_TAB_HELP_H__2E8DEC49_4495_4D50_8438_3E3D3F9C6883__INCLUDED_)
