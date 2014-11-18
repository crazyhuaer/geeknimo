#if !defined(AFX_DIALOG_LKBTC1T_H__FD278EC2_C891_4F1D_A369_F42673E2243B__INCLUDED_)
#define AFX_DIALOG_LKBTC1T_H__FD278EC2_C891_4F1D_A369_F42673E2243B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_LKBTC1T.h : header file
//
#include "MyListCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CDialog_LKBTC1T dialog

class CDialog_LKBTC1T : public CDialog
{
// Construction
public:
	CDialog_LKBTC1T(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_LKBTC1T)
	enum { IDD = IDD_DIALOG_LKBTC1T };
	CMyListCtrl	m_cList_LK_BTC1T;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_LKBTC1T)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_LKBTC1T)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_LKBTC1T_H__FD278EC2_C891_4F1D_A369_F42673E2243B__INCLUDED_)
