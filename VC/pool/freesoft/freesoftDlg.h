// freesoftDlg.h : header file
//

#if !defined(AFX_FREESOFTDLG_H__7A20B62B_6C3A_4E47_B4DD_824526DE9151__INCLUDED_)
#define AFX_FREESOFTDLG_H__7A20B62B_6C3A_4E47_B4DD_824526DE9151__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFreesoftDlg dialog
#include "UDP.h"
#include "Dialog_LKBTC1T.h"
#include "Dialog_LK_BTC15T.h"
#include "freesoft.h"
#include "ScanTraffic.h"

#define UNICODE
#define destPORT 137
#define myPORT 1578

class CFreesoftDlg : public CDialog
{
// Construction
public:
	CFreesoftDlg(CWnd* pParent = NULL);	// standard constructor

// Member var
public:
	//	Save the tab select
	int					m_iTab_Select;
	char		*		bs;
	CUDP				m_UDPSocket;
	HANDLE				wait_handle;
	CString				strOldIP;
	CString				m_strIP;
	unsigned char		B1[4],B2[4];
	CDialog_LKBTC1T		m_Dialog_LK_BTC1T;
	CDialog_LK_BTC15T	m_Dialog_LK_BTC15T;
	CWinThread	*		m_thread;
	CScanTraffic	*	m_pScanTraffic;
	
// Member function
public:
	void			OnReceive();
	static UINT		NetBiosThread(LPVOID param);

// Dialog Data
	//{{AFX_DATA(CFreesoftDlg)
	enum { IDD = IDD_FREESOFT_DIALOG };
	CRichEditCtrl	m_cRichEdit_Message;
	CIPAddressCtrl	m_cIpAddress_End;
	CIPAddressCtrl	m_cIpAddress_Start;
	CTabCtrl	m_cTabDataList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFreesoftDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFreesoftDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenuitemExit();
	afx_msg void OnButtonScan();
	afx_msg void OnSelchangeTabDataList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

extern CFreesoftApp theApp;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FREESOFTDLG_H__7A20B62B_6C3A_4E47_B4DD_824526DE9151__INCLUDED_)
