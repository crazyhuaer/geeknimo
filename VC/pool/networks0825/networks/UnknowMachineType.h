#if !defined(AFX_UNKNOWMACHINETYPE_H__A41F1EED_DA19_435D_AC75_DE7FA62ECA05__INCLUDED_)
#define AFX_UNKNOWMACHINETYPE_H__A41F1EED_DA19_435D_AC75_DE7FA62ECA05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UnknowMachineType.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// UnknowMachineType dialog

class UnknowMachineType : public CDialog
{
// Construction
public:
	UnknowMachineType(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(UnknowMachineType)
	enum { IDD = IDD_DIALOG_UNKNOWTYPE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(UnknowMachineType)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(UnknowMachineType)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UNKNOWMACHINETYPE_H__A41F1EED_DA19_435D_AC75_DE7FA62ECA05__INCLUDED_)
