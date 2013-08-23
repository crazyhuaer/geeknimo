// version1Dlg.h : header file
//

#if !defined(AFX_VERSION1DLG_H__F68E9123_97B2_47FB_8E0A_BE18323C76A9__INCLUDED_)
#define AFX_VERSION1DLG_H__F68E9123_97B2_47FB_8E0A_BE18323C76A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AlexfStaticHistogram.h"

/////////////////////////////////////////////////////////////////////////////
// CVersion1Dlg dialog

class CVersion1Dlg : public CDialog
{
// Construction
public:
	CVersion1Dlg(CWnd* pParent = NULL);	// standard constructor

public:
	//CAlexfStaticHistogram m_AlexfStaticHistogram;
	CAlexfStaticHistogram   m_AlexfStaticHistogram_Test;

// Dialog Data
	//{{AFX_DATA(CVersion1Dlg)
	enum { IDD = IDD_VERSION1_DIALOG };
	CAlexfStaticHistogram	m_AlexfStaticHistogram;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVersion1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVersion1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonExit();
	afx_msg void OnButtonOrigin();
	afx_msg void OnButtonLeft();
	afx_msg void OnButtonRight();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VERSION1DLG_H__F68E9123_97B2_47FB_8E0A_BE18323C76A9__INCLUDED_)
