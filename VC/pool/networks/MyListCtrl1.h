#if !defined(AFX_MYLISTCTRL1_H__C54D4E01_6CFA_4D8A_9736_68E14E720F04__INCLUDED_)
#define AFX_MYLISTCTRL1_H__C54D4E01_6CFA_4D8A_9736_68E14E720F04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyListCtrl1.h : header file
//
#include <afxtempl.h>
/////////////////////////////////////////////////////////////////////////////
// MyListCtrl1 window

class MyListCtrl1 : public CListCtrl
{
	// Construction
public:
	MyListCtrl1();
	
	// Attributes
public:
	CMap<DWORD, DWORD&, COLORREF, COLORREF&> MapItemColor;
	void SetItemColor(DWORD iItem, COLORREF color);
	bool IsColumnVisible(int nCol);
	int GetFirstVisibleColumn();
	BOOL ShowColumn(int nCol, bool bShow);
	BOOL SetColumnWidthAuto(int nCol = -1, bool includeHeader = false);
	// Operations
public:
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MyListCtrl1)
public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL
	
	// Implementation
public:
	virtual ~MyListCtrl1();
	
	// Generated message map functions
protected:
	//{{AFX_MSG(MyListCtrl1)
	// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	struct ColumnState
	{
		ColumnState()
			:m_Visible(false)
			,m_OrgWidth(0)
			,m_OrgPosition(-1)
		{}
		bool m_Visible;
		int  m_OrgWidth;	// Width it had before being hidden
		int  m_OrgPosition;	// Position it had before being hidden
	};
	CArray<ColumnState, ColumnState&>	m_ColumnStates;
	int GetColumnStateCount();
	void InsertColumnState(int nCol, bool bVisible, int nOrgWidth = 0);
	void DeleteColumnState(int nCol);
	ColumnState& GetColumnState(int nCol);
	DECLARE_MESSAGE_MAP()
		
		virtual afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual afx_msg LRESULT OnDeleteColumn(WPARAM wParam, LPARAM lParam);
	virtual afx_msg LRESULT OnInsertColumn(WPARAM wParam, LPARAM lParam);
	virtual afx_msg LRESULT OnSetColumnWidth(WPARAM wParam, LPARAM lParam);
	virtual afx_msg BOOL OnHeaderBeginResize(UINT id, NMHDR* pNmhdr, LRESULT* pResult);
	virtual afx_msg BOOL OnHeaderEndDrag(UINT id, NMHDR* pNmhdr, LRESULT* pResult);
	virtual afx_msg BOOL OnHeaderDividerDblClick(UINT, NMHDR* pNMHDR, LRESULT* pResult);
	virtual afx_msg void OnContextMenu(CWnd*, CPoint point);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	
	virtual void PreSubclassWindow();
	
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(MyListCtrl1)
	// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
		DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLISTCTRL1_H__C54D4E01_6CFA_4D8A_9736_68E14E720F04__INCLUDED_)
