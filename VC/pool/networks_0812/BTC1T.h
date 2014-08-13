#if !defined(AFX_BTC1T_H__BCA14A66_940A_4650_97D7_4A6407F241AE__INCLUDED_)
#define AFX_BTC1T_H__BCA14A66_940A_4650_97D7_4A6407F241AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BTC1T.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BTC1T dialog

class BTC1T : public CDialog
{
// Construction
public:
	BTC1T(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(BTC1T)
	enum { IDD = IDD_DIALOG_BTC1T };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BTC1T)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BTC1T)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BTC1T_H__BCA14A66_940A_4650_97D7_4A6407F241AE__INCLUDED_)
