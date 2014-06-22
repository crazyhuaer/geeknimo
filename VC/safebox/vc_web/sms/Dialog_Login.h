#if !defined(AFX_DIALOG_LOGIN_H__2A9319E8_C4F0_440F_AD2A_2E960B4B9FE1__INCLUDED_)
#define AFX_DIALOG_LOGIN_H__2A9319E8_C4F0_440F_AD2A_2E960B4B9FE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_Login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_Login dialog

class CDialog_Login : public CDialog
{
// Construction
public:
	CDialog_Login(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_Login)
	enum { IDD = IDD_DIALOG_LOGIN };
	CEdit	m_Server_Url;
	CEdit	m_login_password;
	CEdit	m_login_username;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_Login)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_Login)
	afx_msg void OnLoginOn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	CString	m_strUsername;
	CString m_strPassword;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_LOGIN_H__2A9319E8_C4F0_440F_AD2A_2E960B4B9FE1__INCLUDED_)
