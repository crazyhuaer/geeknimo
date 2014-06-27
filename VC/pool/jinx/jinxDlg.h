// jinxDlg.h : header file
//

#if !defined(AFX_JINXDLG_H__A4C027CD_78A1_49B6_AD10_244BE2AB4F51__INCLUDED_)
#define AFX_JINXDLG_H__A4C027CD_78A1_49B6_AD10_244BE2AB4F51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CJinxDlg dialog

class CJinxDlg : public CDialog
{
// Construction
public:
	CJinxDlg(CWnd* pParent = NULL);	// standard constructor
	int MyPing(CString szDestHost);
// Dialog Data
	//{{AFX_DATA(CJinxDlg)
	enum { IDD = IDD_JINX_DIALOG };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJinxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CJinxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JINXDLG_H__A4C027CD_78A1_49B6_AD10_244BE2AB4F51__INCLUDED_)
