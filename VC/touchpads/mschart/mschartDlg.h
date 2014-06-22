// mschartDlg.h : header file
//

#if !defined(AFX_MSCHARTDLG_H__68CCFE93_18B6_4761_BF89_F7A78AAC7D99__INCLUDED_)
#define AFX_MSCHARTDLG_H__68CCFE93_18B6_4761_BF89_F7A78AAC7D99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMschartDlg dialog

class CMschartDlg : public CDialog
{
// Construction
public:
	CMschartDlg(CWnd* pParent = NULL);	// standard constructor

public:
	

private:
	void DrawHistogram(int count[],int control,int num);

// Dialog Data
	//{{AFX_DATA(CMschartDlg)
	enum { IDD = IDD_MSCHART_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMschartDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMschartDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonExit();
	afx_msg void OnButtonOriginal();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSCHARTDLG_H__68CCFE93_18B6_4761_BF89_F7A78AAC7D99__INCLUDED_)
