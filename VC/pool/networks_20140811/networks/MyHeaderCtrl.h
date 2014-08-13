#if !defined(AFX_MYHEADERCTRL_H__9D344746_BD1C_48A5_9930_1E21F84ED18E__INCLUDED_)
#define AFX_MYHEADERCTRL_H__9D344746_BD1C_48A5_9930_1E21F84ED18E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyHeaderCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MyHeaderCtrl window

class MyHeaderCtrl : public CHeaderCtrl
{
// Construction
public:
	MyHeaderCtrl();

// Attributes
public:

// Operations
public:

// Overrides
public:
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MyHeaderCtrl)
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~MyHeaderCtrl();
	void SetSortArrow( const int iColumn, const BOOL bAscending );

	// Generated message map functions
protected:
	void DrawItem( LPDRAWITEMSTRUCT lpDrawItemStruct );
	int m_iSortColumn;
	BOOL m_bSortAscending;
	//{{AFX_MSG(MyHeaderCtrl)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYHEADERCTRL_H__9D344746_BD1C_48A5_9930_1E21F84ED18E__INCLUDED_)
