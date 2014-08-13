#if !defined(AFX_LTC30M_H__1D6AF7C4_875B_413A_8988_533C93753A0E__INCLUDED_)
#define AFX_LTC30M_H__1D6AF7C4_875B_413A_8988_533C93753A0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LTC30M.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// LTC30M dialog

class LTC30M : public CDialog
{
// Construction
public:
	LTC30M(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LTC30M)
	enum { IDD = IDD_DIALOG_LTC30M };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LTC30M)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LTC30M)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LTC30M_H__1D6AF7C4_875B_413A_8988_533C93753A0E__INCLUDED_)
