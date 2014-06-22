// libusb_win8Dlg.h : header file
//

#if !defined(AFX_LIBUSB_WIN8DLG_H__657FF506_8F84_43C9_B816_0D1A68CB077A__INCLUDED_)
#define AFX_LIBUSB_WIN8DLG_H__657FF506_8F84_43C9_B816_0D1A68CB077A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLibusb_win8Dlg dialog

class CLibusb_win8Dlg : public CDialog
{
// Construction
public:
	CLibusb_win8Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLibusb_win8Dlg)
	enum { IDD = IDD_LIBUSB_WIN8_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibusb_win8Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLibusb_win8Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBUSB_WIN8DLG_H__657FF506_8F84_43C9_B816_0D1A68CB077A__INCLUDED_)
