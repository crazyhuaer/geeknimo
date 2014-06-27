// networksDlg.h : header file
//

#if !defined(AFX_NETWORKSDLG_H__E23ABBC3_B70A_4155_8DD7_5A5DC04121BC__INCLUDED_)
#define AFX_NETWORKSDLG_H__E23ABBC3_B70A_4155_8DD7_5A5DC04121BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UDP.h"

/////////////////////////////////////////////////////////////////////////////
// CNetworksDlg dialog

class CNetworksDlg : public CDialog
{
// Construction
public:
	CNetworksDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNetworksDlg)
	enum { IDD = IDD_NETWORKS_DIALOG };
	CButton	m_Button_Fresh;
	CStatic	m_SoftStatus;
	CSpinButtonCtrl	m_SpinTimeOut;
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetworksDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNetworksDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonRefresh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	bool bExit;
	CWinThread* m_thread;
	CUDP m_UDPSocket;
	char *bs;
	HANDLE wait_handle;
	CString strOldIP;
	int		m_line;
	int		m_curLine;

public:
	USHORT	checksum(USHORT *buffer, int size);
	CString	FindBA(CString *strHtmlData);
	CString	FindSummary(CString *strHtmlData);
	CString FindPoolStatus(CString *strHtmlData,int curline);
	void	OnReceive();
	int		LkMachine_GetStatus(CString iDestAddr,int Output,int line);

	static UINT  NbtstatThread(LPVOID param);
	static UINT  GetStatusThread(LPVOID param);
};

// 
// ICMP header 
// 
typedef struct _ihdr { 
	BYTE i_type; 
	BYTE i_code; /* type sub code */ 
	USHORT i_cksum; 
	USHORT i_id; 
	USHORT i_seq; 
	/* This is not the std header, but we reserve space for time */ 
	ULONG timestamp; 
}IcmpHeader;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETWORKSDLG_H__E23ABBC3_B70A_4155_8DD7_5A5DC04121BC__INCLUDED_)
