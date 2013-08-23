#if !defined(AFX_DIALOG_TAB_TEST_H__3D213E22_17AB_42D5_8B77_E5A971ED36E4__INCLUDED_)
#define AFX_DIALOG_TAB_TEST_H__3D213E22_17AB_42D5_8B77_E5A971ED36E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_Tab_Test.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_Test dialog

class CDialog_Tab_Test : public CDialog
{
// Construction
public:
	CDialog_Tab_Test(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_Tab_Test)
	enum { IDD = IDD_TAB_TEST };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_Tab_Test)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_Tab_Test)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_TAB_TEST_H__3D213E22_17AB_42D5_8B77_E5A971ED36E4__INCLUDED_)
