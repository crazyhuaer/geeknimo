// modifyipDlg.h : header file
//

#if !defined(AFX_MODIFYIPDLG_H__993DD171_5363_43A3_B7B9_9FB67E0FBEEA__INCLUDED_)
#define AFX_MODIFYIPDLG_H__993DD171_5363_43A3_B7B9_9FB67E0FBEEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CModifyipDlg dialog

class CModifyipDlg : public CDialog
{
// Construction
public:
	CModifyipDlg(CWnd* pParent = NULL);	// standard constructor

// Member Data
	CString strCmdPath;
	CString strIpTarget;
	CString strIpNetmask,strIpGateway,strIpDns;
	CString	strIpStart,strIpEnd;
	unsigned char m_chIpStart[4],m_chIpEnd[4];

	CWinThread* m_thread;
// Member function


// Thead function
	static UINT  funTheadPing(LPVOID param);
	static UINT  funTheadModifyIp(LPVOID param);

// Dialog Data
	//{{AFX_DATA(CModifyipDlg)
	enum { IDD = IDD_MODIFYIP_DIALOG };
	CButton	m_btnCreateIpPool;
	CButton	m_btnModifyIp;
	CButton	m_btnPing;
	CIPAddressCtrl	m_coIpAddressNetMask;
	CIPAddressCtrl	m_coIpaddressDns;
	CIPAddressCtrl	m_coIpAddressGateway;
	CRichEditCtrl	m_coMessage;
	CListCtrl	m_coListIpPool;
	CIPAddressCtrl	m_coIpAddressIpPool2;
	CIPAddressCtrl	m_coIpAddressIpPool1;
	CIPAddressCtrl	m_coIpAddressTarget;
	CString	m_MessageBox;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModifyipDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CModifyipDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonCreateIppool();
	afx_msg void OnButtonPing();
	afx_msg void OnButtonModifyip();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODIFYIPDLG_H__993DD171_5363_43A3_B7B9_9FB67E0FBEEA__INCLUDED_)
