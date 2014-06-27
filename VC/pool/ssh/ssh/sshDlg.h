// sshDlg.h : header file
//
#include "UDP.h"

#if !defined(AFX_SSHDLG_H__037D6BB1_57E0_45AD_B2BC_FE4C45839D79__INCLUDED_)
#define AFX_SSHDLG_H__037D6BB1_57E0_45AD_B2BC_FE4C45839D79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSshDlg dialog

class CSshDlg : public CDialog
{
// Construction
public:
	CSshDlg(CWnd* pParent = NULL);	// standard constructor
	void OnReceive();
	CUDP m_UDPSocket;
	CString	m_strIP;
	void sshSrv(CString command, CString hostname, int port);
// Dialog Data
	//{{AFX_DATA(CSshDlg)
	enum { IDD = IDD_SSH_DIALOG };
	CEdit	m_passwordEdit2;
	CEdit	m_passwordEdit3;
	CEdit	m_usernameEdit3;
	CEdit	m_usernameEdit2;
	CEdit	m_passwordEdit1;
	CEdit	m_usernameEdit1;
	CEdit	m_poolUrlEdit3;
	CEdit	m_poolUrlEdit2;
	CEdit	m_poolUrlEdit1;
	CListBox	m_ListBox;
	CIPAddressCtrl	m_IPEdit2;
	CIPAddressCtrl	m_IPEdit1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSshDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSshDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSHDLG_H__037D6BB1_57E0_45AD_B2BC_FE4C45839D79__INCLUDED_)
