#if !defined(AFX_MYLISTCTRL1_H__C54D4E01_6CFA_4D8A_9736_68E14E720F04__INCLUDED_)
#define AFX_MYLISTCTRL1_H__C54D4E01_6CFA_4D8A_9736_68E14E720F04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyListCtrl1.h : header file
//
#include <afxtempl.h>
#include "MyHeaderCtrl.h"

#ifdef _DEBUG
#define ASSERT_VALID_STRING( str ) ASSERT( !IsBadStringPtr( str, 0xfffff ) )
#else	//	_DEBUG
#define ASSERT_VALID_STRING( str ) ( (void)0 )
#endif	//	_DEBUG
/////////////////////////////////////////////////////////////////////////////
// MyListCtrl1 window

class MyListCtrl1 : public CListCtrl
{
	// Construction
public:
	MyListCtrl1();
	
	// Attributes
public:
	int m_iNumColumns;
	int m_iSortColumn;
	BOOL m_bSortAscending;
	bool IsColumnVisible(int nCol);
	int GetFirstVisibleColumn();
	BOOL ShowColumn(int nCol, bool bShow);
	BOOL SetColumnWidthAuto(int nCol = -1, bool includeHeader = false);
	
	// Operations
public:
	BOOL SetHeadings( UINT uiStringID );
	BOOL SetHeadings( const CString& strHeadings );
	
	int AddItem( LPCTSTR pszText, ... );
	BOOL DeleteItem( int iItem );
	BOOL DeleteAllItems();
	void LoadColumnInfo();
	void SaveColumnInfo();
	BOOL SetItemText( int nItem, int nSubItem, LPCTSTR lpszText );
	void Sort( int iColumn, BOOL bAscending );
	BOOL SetItemData(int nItem, DWORD dwData);
	DWORD GetItemData(int nItem) const;

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MyListCtrl1)
public:
	//virtual void OnFinalRelease();
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL
	
	// Implementation
public:
	virtual ~MyListCtrl1();
	void SetItemColor(int nItem, int nSubItem, COLORREF clrText, COLORREF clrBkgnd);
	void DrawText(int nItem, int nSubItem, CDC *pDC, COLORREF crText, COLORREF crBkgnd, CRect &rect);
	BOOL GetSubItemRect(int nItem, int nSubItem, int nArea, CRect& rect);
	int GetColumns();
	int AddItemColor(LPCTSTR pszText,COLORREF crText,COLORREF crBak);
	
	// Generated message map functions


protected:
	//{{AFX_MSG(MyListCtrl1)
	// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnColumnclickList(NMHDR* pNMHDR, LRESULT* pResult);
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

	//virtual void PreSubclassWindow();

	void UpdateSubItem(int nItem, int nSubItem);
	static int CALLBACK CompareFunction( LPARAM lParam1, LPARAM lParam2, LPARAM lParamData );
	void FreeItemMemory( const int iItem );
	BOOL SetArray( int iItem, LPTSTR* arrpsz ,COLORREF * clrText,COLORREF * clrBak);
	LPTSTR* GetTextArray( int iItem ) const;
		
	MyHeaderCtrl m_ctlHeader;
	
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(MyListCtrl1)
	// NOTE - the ClassWizard will add and remove member functions here.
	virtual afx_msg void OnColumnClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg void OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult);	
	afx_msg void OnSysColorChange();

	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	private:
	COLORREF crWindowText,crWindow,crHighLight,crHighLightText;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLISTCTRL1_H__C54D4E01_6CFA_4D8A_9736_68E14E720F04__INCLUDED_)
