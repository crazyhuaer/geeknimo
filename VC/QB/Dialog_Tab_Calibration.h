#if !defined(AFX_DIALOG_TAB_CALIBRATION_H__9EE337C6_40A6_4582_9B02_B9E55614277E__INCLUDED_)
#define AFX_DIALOG_TAB_CALIBRATION_H__9EE337C6_40A6_4582_9B02_B9E55614277E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_Tab_Calibration.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_Calibration dialog

class CDialog_Tab_Calibration : public CDialog
{
// Construction
public:
	CDialog_Tab_Calibration(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_Tab_Calibration)
	enum { IDD = IDD_TAB_CALIBRATION };
	CStatic	m_Static_Sn_Version;
	CStatic	m_Static_Hw_Version;
	CStatic	m_Static_Hw_Sn;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_Tab_Calibration)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_Tab_Calibration)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_TAB_CALIBRATION_H__9EE337C6_40A6_4582_9B02_B9E55614277E__INCLUDED_)
