// ChooseatypeiniDlg.h : header file
//

#if !defined(AFX_CHOOSEATYPEINIDLG_H__D93087B6_9E06_4911_8226_402BD382E7DA__INCLUDED_)
#define AFX_CHOOSEATYPEINIDLG_H__D93087B6_9E06_4911_8226_402BD382E7DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChooseatypeiniDlg dialog
#include "InitFile.h"

class CChooseatypeiniDlg : public CDialog
{
// Construction
public:
	CChooseatypeiniDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChooseatypeiniDlg)
	enum { IDD = IDD_CHOOSEATYPEINI_DIALOG };
	CComboBox	m_Screen_Type;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChooseatypeiniDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

public:
	CString mSection;
	CString FConfigFileName;

	CInitFile mInitFile;
	int		mTypeCount;

	int		m_nlength;
	CString	m_strname;
	float	m_fwidth;


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChooseatypeiniDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReadButton();
	afx_msg void OnWriteButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOOSEATYPEINIDLG_H__D93087B6_9E06_4911_8226_402BD382E7DA__INCLUDED_)
