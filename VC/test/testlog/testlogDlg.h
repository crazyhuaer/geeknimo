// testlogDlg.h : header file
//

#if !defined(AFX_TESTLOGDLG_H__6111E4C3_8F94_4A74_84F4_9E657AB5D470__INCLUDED_)
#define AFX_TESTLOGDLG_H__6111E4C3_8F94_4A74_84F4_9E657AB5D470__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestlogDlg dialog

class CTestlogDlg : public CDialog
{
// Construction
public:
	CTestlogDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestlogDlg)
	enum { IDD = IDD_TESTLOG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestlogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestlogDlg)
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

#endif // !defined(AFX_TESTLOGDLG_H__6111E4C3_8F94_4A74_84F4_9E657AB5D470__INCLUDED_)
