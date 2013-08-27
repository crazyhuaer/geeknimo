// libusb_outputDlg.h : header file
//

#if !defined(AFX_LIBUSB_OUTPUTDLG_H__ED3E6671_4A92_44EC_A953_F54B96339B04__INCLUDED_)
#define AFX_LIBUSB_OUTPUTDLG_H__ED3E6671_4A92_44EC_A953_F54B96339B04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "libusb.h"
/////////////////////////////////////////////////////////////////////////////
// CLibusb_outputDlg dialog

class CLibusb_outputDlg : public CDialog
{
// Construction
public:
	CLibusb_outputDlg(CWnd* pParent = NULL);	// standard constructor

public:
	libusb_device **devs;

// Dialog Data
	//{{AFX_DATA(CLibusb_outputDlg)
	enum { IDD = IDD_LIBUSB_OUTPUT_DIALOG };
	CRichEditCtrl	m_cRichEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibusb_outputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLibusb_outputDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonDetect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBUSB_OUTPUTDLG_H__ED3E6671_4A92_44EC_A953_F54B96339B04__INCLUDED_)
