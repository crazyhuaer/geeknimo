#if !defined(AFX_MODIFYPASSOWRD_H__338EDFD6_7A0B_4676_9C4A_45A8FB4FC3FC__INCLUDED_)
#define AFX_MODIFYPASSOWRD_H__338EDFD6_7A0B_4676_9C4A_45A8FB4FC3FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ModifyPassowrd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CModifyPassowrd dialog

class CModifyPassowrd : public CDialog
{
// Construction
public:
	CModifyPassowrd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CModifyPassowrd)
	enum { IDD = IDD_ADMIN_REGISTER };
	CEdit	m_newPassword2;
	CEdit	m_newPassword1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModifyPassowrd)
	public:
	virtual void OnFinalRelease();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CModifyPassowrd)
	afx_msg void OnModifyPassword();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CModifyPassowrd)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODIFYPASSOWRD_H__338EDFD6_7A0B_4676_9C4A_45A8FB4FC3FC__INCLUDED_)
