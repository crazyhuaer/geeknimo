// QBDlg.h : header file
//

#if !defined(AFX_QBDLG_H__4B247E9A_F03A_4623_9671_AF0F6A31EB95__INCLUDED_)
#define AFX_QBDLG_H__4B247E9A_F03A_4623_9671_AF0F6A31EB95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CQBDlg dialog

#include "Dialog_Tab_TEST.h"
#include "Dialog_Tab_Help.h"
#include "Dialog_Tab_Calibration.h"
#include "Dialog_Tab_Pcb_Setting.h"

class CQBDlg : public CDialog
{
// Construction
public:
	CQBDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CQBDlg)
	enum { IDD = IDD_QB_DIALOG };
	CComboBox	m_ScreenType;
	CTabCtrl	m_MainTabControl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQBDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CQBDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	int	intLoginUser;
	CDialog_Tab_Help m_MainTabControl_Help;
	CDialog_Tab_Test m_MainTabControl_Test;
	CDialog_Tab_Pcb_Setting m_MainTabControl_Pcb_Setting;
	CDialog_Tab_Calibration m_MainTabControl_Calibration;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QBDLG_H__4B247E9A_F03A_4623_9671_AF0F6A31EB95__INCLUDED_)
