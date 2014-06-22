// dialog_usb_testDlg.h : header file
//

#if !defined(AFX_DIALOG_USB_TESTDLG_H__D7F3E00F_C053_46DC_BF1B_33A555D5896B__INCLUDED_)
#define AFX_DIALOG_USB_TESTDLG_H__D7F3E00F_C053_46DC_BF1B_33A555D5896B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "libusb.h"
/////////////////////////////////////////////////////////////////////////////
// CDialog_usb_testDlg dialog

class CDialog_usb_testDlg : public CDialog
{
// Construction
public:
	CDialog_usb_testDlg(CWnd* pParent = NULL);	// standard constructor

public:
	libusb_device **devs;

// Dialog Data
	//{{AFX_DATA(CDialog_usb_testDlg)
	enum { IDD = IDD_DIALOG_USB_TEST_DIALOG };
	CRichEditCtrl	m_cRichEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_usb_testDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDialog_usb_testDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonDetect();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_USB_TESTDLG_H__D7F3E00F_C053_46DC_BF1B_33A555D5896B__INCLUDED_)
