// versionDlg.h : header file
//

#if !defined(AFX_VERSIONDLG_H__F87C3CD4_5CD4_4F58_AA2D_1369C2FF594D__INCLUDED_)
#define AFX_VERSIONDLG_H__F87C3CD4_5CD4_4F58_AA2D_1369C2FF594D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AlexfStaticHistogram.h"

/////////////////////////////////////////////////////////////////////////////
// CVersionDlg dialog

class CVersionDlg : public CDialog
{
// Construction
public:
	CVersionDlg(CWnd* pParent = NULL);	// standard constructor

public:
	int	Button_ID_Increase;
	int Histogram_ID_Increase;
	int Static_ID_Increase;
	CAlexfStaticHistogram   m_AlexfStaticHistogram[5];

// Dialog Data
	//{{AFX_DATA(CVersionDlg)
	enum { IDD = IDD_VERSION_DIALOG };
	CButton					m_ScanOrigin;
	CButton					m_ScanLeft;
	CButton					m_ScanRight;
	CButton					m_Exit;
	CStatic					m_PcbInfo;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVersionDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVersionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	afx_msg void OnScanOrigin();
	afx_msg void OnScanLeft();
	afx_msg void OnScanRight();
	afx_msg void OnExit();
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VERSIONDLG_H__F87C3CD4_5CD4_4F58_AA2D_1369C2FF594D__INCLUDED_)
