#if !defined(AFX_DIALOG_MAIN_H__C149CB7E_9934_44FA_837F_7718E2B21072__INCLUDED_)
#define AFX_DIALOG_MAIN_H__C149CB7E_9934_44FA_837F_7718E2B21072__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_Main.h : header file
//
//#include "MyCom.h"
#include "Comm.h"
#include "SmsTraffic.h"

/////////////////////////////////////////////////////////////////////////////
// CDialog_Main dialog

class CDialog_Main : public CDialog
{
// Construction
public:
	CDialog_Main(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_Main)
	enum { IDD = DIALOG_MAIN_PAGE };
	CEdit	m_Period_Send;
	CButton	m_Start_Send;
	CEdit	m_Data_Url;
	CComboBox	m_Com_Number;
	CButton	m_test_gprs;
	CButton	m_Open_MSCOMM;
	CRichEditCtrl	m_Status_Information;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_Main)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_Main)
	afx_msg void OnOnOffTc35();
	afx_msg void OnTestGprs();
	afx_msg void OnStartSend();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKillfocusPeriodSend();
	afx_msg void OnSetfocusPeriodSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// MSCOMM Class
	BOOL	m_Status_Timer;
	BOOL	m_MSCOMM_Open;
	CSmsTraffic* m_pSmsTraffic;
	char	m_Status_Enter;

	void	SendTheMessage(CString	strSmsc,CString	strNumber,CString strContent);
	CString* SplitString(CString str, char split, int& iSubStrs);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_MAIN_H__C149CB7E_9934_44FA_837F_7718E2B21072__INCLUDED_)
