// networksDlg.h : header file
//

#if !defined(AFX_NETWORKSDLG_H__E23ABBC3_B70A_4155_8DD7_5A5DC04121BC__INCLUDED_)
#define AFX_NETWORKSDLG_H__E23ABBC3_B70A_4155_8DD7_5A5DC04121BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UDP.h"
#include <afxtempl.h>
#include "MyListCtrl1.h"
#include "InitFile.h"
#include "DialogLTC60M.h"
#include "DialogLTC30M.h"
#include "Dialog_BTC1T.h"
#include "UnknowType.h"
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
	CButton	m_machine_type_know;
	CTabCtrl	m_MainTab;
	CComboBox	m_combo_fre;
	CComboBox	m_coinType;
	CButton	m_single_update;
	CComboBox	m_ComboBox_diff;
	CButton	m_user_check3;
	CButton	m_user_check2;
	CButton	m_user_check1;
	CButton	m_Check3;
	CButton	m_Check2;
	CButton	m_Check1;
	CStatic	m_Single;
	CButton	m_multi_reboot;
	CButton	m_sing_reboot;
	MyListCtrl1	m_ListCtrl;
	CStatic	m_Multi;
	CButton	m_Button_Fresh;
	CButton	m_bFresh;
	CListBox	m_ListBox;
	CEdit	m_PasswordEdit3;
	CEdit	m_PasswordEdit2;
	CEdit	m_PasswordEdit1;
	CEdit	m_UsernameEdit3;
	CEdit	m_UsernameEdit2;
	CEdit	m_UsernameEdit1;
	CEdit	m_PoolUrlEdit3;
	CEdit	m_PoolUrlEdit2;
	CEdit	m_PoolUrlEdit1;
	CIPAddressCtrl	m_IPStop;
	CIPAddressCtrl	m_IPStart;
	CStatic	m_SoftStatus;
	CSpinButtonCtrl	m_SpinTimeOut;
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
	afx_msg void OnRefresh();
	afx_msg void OnSingleUpdate();
	afx_msg void OnSingleReboot();
	afx_msg void OnMutipleReboot();
	afx_msg void OnClose();
	afx_msg void OnMenuitem32771();
	afx_msg void OnMenuitemEng();
	afx_msg void OnMenuitemCN();
	afx_msg void OnButtonStop();
	afx_msg void OnButtonSuspend();
	afx_msg void OnMenuitemModifyPassword();
	afx_msg void OnDblclkListIpStatus(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeComboCoinType();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	bool bExit;
	bool bRef;
	CWinThread* m_thread;
	CUDP m_UDPSocket;
	char *bs;
	HANDLE wait_handle;
	CString strOldIP;
	int		m_line;
	int		m_curLine;
	CString m_strIP;

	CInitFile m_IniFile;

	CDialog_BTC1T m_BTC1T;
	CDialogLTC30M m_LTC30M;
	CDialogLTC60M m_LTC60M;
	UnknowType m_UnknowType;
	

	CString		m_poolInfo[13];
	CString		m_section;

	//MyListCtrl1 m_MyListctrl; 
	CMap<DWORD , DWORD& , COLORREF , COLORREF&> MapItemColor;
public:
	void	OnReceive();
	USHORT	checksum(USHORT *buffer, int size);
	void sshSrv(CString command, CString hostname, int port);


	CString	FindBA(CString *strHtmlData);
	void	WriteINI();
	CString	FindSummary(CString *strHtmlData);
	CString FindTemp(CString strHtmlData,int curline);
	CString FindRunTime(CString *strHtmlData,int curline);
	CString FindPoolStatus(CString *strHtmlData,int curline);
	int		LkMachine_GetStatus(CString iDestAddr,int Output,int line);
	int		MachineType(CString ipAddr,CString *strHtmlData);
	void	MultiLkMachine_GetStatus(CString iDestAddr, int ret, CString strHTML);

	static UINT  NbtstatThread(LPVOID param);
	static UINT  GetStatusThread(LPVOID param);
	static UINT  ModifyOnerecordThread(LPVOID param);
	static UINT  SingleRebootThread(LPVOID param);
	static UINT  MultiRebootThread(LPVOID param);

	void countMachine();
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
