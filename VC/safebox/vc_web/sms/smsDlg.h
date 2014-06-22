// smsDlg.h : header file
//

#if !defined(AFX_SMSDLG_H__A199B80E_124F_4CE1_A4D2_C71D3382E162__INCLUDED_)
#define AFX_SMSDLG_H__A199B80E_124F_4CE1_A4D2_C71D3382E162__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSmsDlg dialog
#include "Dialog_Login.h"
#include "Dialog_Main.h"

class CSmsDlg : public CDialog
{
// Construction
public:
	CSmsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSmsDlg)
	enum { IDD = IDD_SMS_DIALOG };
	CTabCtrl	m_MainTabControl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSmsDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSmsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTabAll(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	CDialog_Login	m_Login_Tab;
	CDialog_Main	m_Main_Tab;
	BOOL			m_bLogin_Status;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMSDLG_H__A199B80E_124F_4CE1_A4D2_C71D3382E162__INCLUDED_)
