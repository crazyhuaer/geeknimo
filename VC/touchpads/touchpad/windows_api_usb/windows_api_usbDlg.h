// windows_api_usbDlg.h : header file
//

#if !defined(AFX_WINDOWS_API_USBDLG_H__DC2C80EE_B365_4448_BE87_48B7D0BE493A__INCLUDED_)
#define AFX_WINDOWS_API_USBDLG_H__DC2C80EE_B365_4448_BE87_48B7D0BE493A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWindows_api_usbDlg dialog

class CWindows_api_usbDlg : public CDialog
{
// Construction
public:
	CWindows_api_usbDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWindows_api_usbDlg)
	enum { IDD = IDD_WINDOWS_API_USB_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWindows_api_usbDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWindows_api_usbDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDOWS_API_USBDLG_H__DC2C80EE_B365_4448_BE87_48B7D0BE493A__INCLUDED_)
