// 20131113_testlibusbwin32Dlg.h : header file
//

#if !defined(AFX_20131113_TESTLIBUSBWIN32DLG_H__ACFAAE62_914F_4629_9598_18636F9043C8__INCLUDED_)
#define AFX_20131113_TESTLIBUSBWIN32DLG_H__ACFAAE62_914F_4629_9598_18636F9043C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy20131113_testlibusbwin32Dlg dialog

class CMy20131113_testlibusbwin32Dlg : public CDialog
{
// Construction
public:
	CMy20131113_testlibusbwin32Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy20131113_testlibusbwin32Dlg)
	enum { IDD = IDD_MY20131113_TESTLIBUSBWIN32_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy20131113_testlibusbwin32Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy20131113_testlibusbwin32Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_20131113_TESTLIBUSBWIN32DLG_H__ACFAAE62_914F_4629_9598_18636F9043C8__INCLUDED_)
