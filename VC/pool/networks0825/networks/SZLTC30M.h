#if !defined(AFX_SZLTC30M_H__655595CE_4E05_4C81_96EC_A37CEDCF32C6__INCLUDED_)
#define AFX_SZLTC30M_H__655595CE_4E05_4C81_96EC_A37CEDCF32C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SZLTC30M.h : header file
//
#include "MyListCtrl1.h"

/////////////////////////////////////////////////////////////////////////////
// SZLTC30M dialog

class SZLTC30M : public CDialog
{
// Construction
public:
	SZLTC30M(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SZLTC30M)
	enum { IDD = IDD_DIALOG_SZLTC30M };
	MyListCtrl1	m_List_szLTC30M;
	//}}AFX_DATA
public:
	int m_line;
	void OnDblclkListLtc30m(NMHDR* pNMHDR, LRESULT* pResult);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SZLTC30M)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SZLTC30M)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SZLTC30M_H__655595CE_4E05_4C81_96EC_A37CEDCF32C6__INCLUDED_)
