// tooltiptestDlg.h : header file
//

#if !defined(AFX_TOOLTIPTESTDLG_H__F6AD7020_34EA_42E4_B2B2_7B861562825B__INCLUDED_)
#define AFX_TOOLTIPTESTDLG_H__F6AD7020_34EA_42E4_B2B2_7B861562825B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTooltiptestDlg dialog

class CTooltiptestDlg : public CDialog
{
// Construction
public:
	CTooltiptestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTooltiptestDlg)
	enum { IDD = IDD_TOOLTIPTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTooltiptestDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CToolTipCtrl m_tt; 
	// Generated message map functions
	//{{AFX_MSG(CTooltiptestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLTIPTESTDLG_H__F6AD7020_34EA_42E4_B2B2_7B861562825B__INCLUDED_)
