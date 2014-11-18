#if !defined(AFX_LTC60M_H__9D7F6D9A_F522_41C6_AE63_C4CE370D3718__INCLUDED_)
#define AFX_LTC60M_H__9D7F6D9A_F522_41C6_AE63_C4CE370D3718__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LTC60M.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// LTC60M dialog

class LTC60M : public CDialog
{
// Construction
public:
	LTC60M(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LTC60M)
	enum { IDD = IDD_DIALOG_LTC60M };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LTC60M)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LTC60M)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LTC60M_H__9D7F6D9A_F522_41C6_AE63_C4CE370D3718__INCLUDED_)
