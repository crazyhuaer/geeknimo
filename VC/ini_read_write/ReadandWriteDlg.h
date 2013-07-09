// ReadandWriteDlg.h : header file
//

#if !defined(AFX_READANDWRITEDLG_H__BBFD986A_E697_457B_AF3B_5C0B41F96C86__INCLUDED_)
#define AFX_READANDWRITEDLG_H__BBFD986A_E697_457B_AF3B_5C0B41F96C86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReadandWriteDlg dialog

#include "InitFile.h"

class CReadandWriteDlg : public CDialog
{
// Construction
public:
	CString section;
	CString filename;
	CReadandWriteDlg(CWnd* pParent = NULL);	// standard constructor
	CInitFile initfile;

// Dialog Data
	//{{AFX_DATA(CReadandWriteDlg)
	enum { IDD = IDD_READANDWRITE_DIALOG };
	int		m_nlength;
	CString	m_strname;
	float	m_fwidth;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadandWriteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReadandWriteDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReadini();
	afx_msg void OnWriteini();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READANDWRITEDLG_H__BBFD986A_E697_457B_AF3B_5C0B41F96C86__INCLUDED_)
