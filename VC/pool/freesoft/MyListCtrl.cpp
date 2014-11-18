// MyListCtrl1.cpp : implementation file
//

#include "stdafx.h"
#include "freesoft.h"
#include "MyListCtrl.h"
#include "MyHeaderCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define  ID_LIST_PRINT 200
#define  ID_LIST_SAVE  201
#define  ID_LIST_DELETE 202
#define	 ID_LIST_DELETEALL 203

LPCTSTR g_pszSection = _T("ListCtrls");


struct ItemData
{
public:
	ItemData() : arrpsz( NULL ), dwData( NULL ),crText ( NULL ),crBak (NULL) {}
	
	LPTSTR* arrpsz;
	DWORD dwData;
	//color
	COLORREF * crText;
	COLORREF * crBak;
	
	
private:
	// ban copying.
	ItemData( const ItemData& );
	ItemData& operator=( const ItemData& );
};



/////////////////////////////////////////////////////////////////////////////
// MyListCtrl1

CMyListCtrl::CMyListCtrl(): 
m_bSortAscending(TRUE), 
m_iNumColumns(0),
m_iSortColumn(-1)
{
	EnableAutomation();
	crWindow              = ::GetSysColor(COLOR_WINDOW);
	crWindowText          = ::GetSysColor(COLOR_WINDOWFRAME);
	crHighLight     = ::GetSysColor(COLOR_HIGHLIGHT);
	crHighLightText = ::GetSysColor(COLOR_HIGHLIGHTTEXT);
}

CMyListCtrl::~CMyListCtrl()
{
}

BEGIN_MESSAGE_MAP(CMyListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CMyListCtrl)
	// NOTE - the ClassWizard will add and remove mapping macros here.
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnCustomDraw)
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnColumnClick)
	ON_MESSAGE(LVM_DELETECOLUMN, OnDeleteColumn)
	ON_MESSAGE(LVM_INSERTCOLUMN, OnInsertColumn)
	ON_MESSAGE(LVM_SETCOLUMNWIDTH, OnSetColumnWidth)
	ON_NOTIFY_EX(HDN_BEGINTRACKA, 0, OnHeaderBeginResize)
	ON_NOTIFY_EX(HDN_BEGINTRACKW, 0, OnHeaderBeginResize)
	ON_NOTIFY_EX(HDN_ENDDRAG, 0, OnHeaderEndDrag)
	ON_NOTIFY_EX(HDN_DIVIDERDBLCLICKA, 0, OnHeaderDividerDblClick)
	ON_NOTIFY_EX(HDN_DIVIDERDBLCLICKW, 0, OnHeaderDividerDblClick)
	ON_WM_CONTEXTMENU()	// OnContextMenu
	ON_WM_KEYDOWN()		// OnKeyDown
	ON_WM_DESTROY()
	ON_WM_RBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_SYSCOLORCHANGE()
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMyListCtrl, CListCtrl)
	//{{AFX_DISPATCH_MAP(CMyListCtrl)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IMyListCtrl1 to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {8F2F7E74-ED71-4219-B5C8-C309D03ADE54}
static const IID IID_IMyListCtrl1 =
{ 0x8f2f7e74, 0xed71, 0x4219, { 0xb5, 0xc8, 0xc3, 0x9, 0xd0, 0x3a, 0xde, 0x54 } };

BEGIN_INTERFACE_MAP(CMyListCtrl, CListCtrl)
	INTERFACE_PART(CMyListCtrl, IID_IMyListCtrl1, Dispatch)
END_INTERFACE_MAP()

int CALLBACK  ListCompare(LPARAM lParam0, LPARAM lParam1, LPARAM lParam)
{
	CMyListCtrl *pList = (CMyListCtrl*)lParam;
    LVFINDINFO stFindInfo;
    int iFindItem;
    CString str0;
    CString str1;
	int CompRet = 0;
    stFindInfo.flags = LVFI_PARAM;
    stFindInfo.lParam = lParam0;	
    iFindItem = pList->FindItem(&stFindInfo);
    str0 = pList->GetItemText(iFindItem, pList->m_iSortColumn);
	
    stFindInfo.flags = LVFI_PARAM;
    stFindInfo.lParam = lParam1;
    iFindItem = pList->FindItem(&stFindInfo);
    str1 = pList->GetItemText(iFindItem, pList->m_iSortColumn);

	HDITEM headerItem;
	headerItem.mask = HDI_TEXT;
	TCHAR pBuf[256];
	headerItem.pszText = pBuf;
	headerItem.cchTextMax = 256;
	CHeaderCtrl* pHeaderCtrl = pList->GetHeaderCtrl();
	pHeaderCtrl->GetItem(pList->m_iSortColumn, &headerItem);

	CString tmp = headerItem.pszText;
	//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage(tmp);
	UINT nType = (UINT)(headerItem.lParam);

	if (!strcmp("BA1", tmp)||  !strcmp("BA2", tmp)|| !strcmp("BA3", tmp)||!strcmp("BA4", tmp)||  \
		!strcmp("SUM", tmp) || !strcmp("BA10-TEMP", tmp) || !strcmp("BA11-TEMP", tmp)|| !strcmp("BA12-TEMP", tmp)  \
		|| !strcmp("BA13-TEMP",tmp))
	{
	    if (strcmp(str0, str1) == 0)
			CompRet = 0;
		else if(atoi(str0) - atoi(str1) > 0.001)
			CompRet = 1;
		else
			CompRet = -1;
	}
	else if(!strcmp("RUN-TIME", tmp))//解析时间成整形然后排序
	{
	
		str0.Replace("day","");
		str0.Replace("days","");
		str0.Remove('h');
		str0.Remove('m');
		str0.Remove('s');
	
		str1.Replace("day","");
		str1.Replace("days","");
		str1.Remove('h');
		str1.Remove('m');
		str1.Remove('s');

		if (atoi(str0) - atoi(str1) == 0)
			CompRet = 0;
		else if(atoi(str0) - atoi(str1) > 0.001)
			CompRet = 1;
		else
			CompRet = -1;
		
	}
	else
		return 0;
	//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage(str0 + " and " + str1);

	if(pList->m_bSortAscending)
		return CompRet;
	else
		return CompRet * -1;

	return 0;
}

int CMyListCtrl::GetFirstVisibleColumn()
{
	int nColCount = GetHeaderCtrl()->GetItemCount();
	for(int i = 0; i < nColCount; ++i)
	{
		int nCol = GetHeaderCtrl()->OrderToIndex(i);
		if (IsColumnVisible(nCol))
		{
			return nCol;
		}
	}
	return -1;
}

BOOL CMyListCtrl::ShowColumn(int nCol, bool bShow)
{
	SetRedraw(FALSE);

	ColumnState& columnState = GetColumnState(nCol);

	int nColCount = GetHeaderCtrl()->GetItemCount();
	int* pOrderArray = new int[nColCount];
	VERIFY( GetColumnOrderArray(pOrderArray, nColCount) );
	if (bShow)
	{
		// Restore the position of the column
		int nCurIndex = -1;
		for(int i = 0; i < nColCount ; ++i)
		{
			if (pOrderArray[i]==nCol)
				nCurIndex = i;
			else
			if (nCurIndex!=-1)
			{
				// We want to move it to the original position,
				// and after the last hidden column
				if ( (i <= columnState.m_OrgPosition)
				  || !IsColumnVisible(pOrderArray[i])
				   )
				{
					pOrderArray[nCurIndex] = pOrderArray[i];
					pOrderArray[i] = nCol;
					nCurIndex = i;
				}
			}
		}
	}
	else
	{
		// Move the column to the front of the display order list
		int nCurIndex(-1);
		for(int i = nColCount-1; i >=0 ; --i)
		{
			if (pOrderArray[i]==nCol)
			{
				// Backup the current position of the column
				columnState.m_OrgPosition = i;
				nCurIndex = i;
			}
			else
			if (nCurIndex!=-1)
			{
				pOrderArray[nCurIndex] = pOrderArray[i];
				pOrderArray[i] = nCol;
				nCurIndex = i;
			}
		}
	}

	VERIFY( SetColumnOrderArray(nColCount, pOrderArray) );
	delete [] pOrderArray;

	if (bShow)
	{
		// Restore the column width
		columnState.m_Visible = true;
		VERIFY( SetColumnWidth(nCol, columnState.m_OrgWidth) );
	}
	else
	{
		// Backup the column width
		int orgWidth = GetColumnWidth(nCol);
		VERIFY( SetColumnWidth(nCol, 0) );
		columnState.m_Visible = false;
		columnState.m_OrgWidth = orgWidth;
	}
	SetRedraw(TRUE);
	Invalidate(FALSE);
	return TRUE;
}

BOOL CMyListCtrl::SetColumnWidthAuto(int nCol, bool includeHeader)
{
	if (nCol == -1)
	{
		for(int i = 0; i < GetHeaderCtrl()->GetItemCount() ; ++i)
		{
			SetColumnWidthAuto(i, includeHeader);
		}
		return TRUE;
	}
	else
	{
		if (includeHeader)
			return SetColumnWidth(nCol, LVSCW_AUTOSIZE_USEHEADER);
		else
			return SetColumnWidth(nCol, LVSCW_AUTOSIZE);
	}
}

CMyListCtrl::ColumnState& CMyListCtrl::GetColumnState(int nCol)
{
	VERIFY( nCol >=0 && nCol < m_ColumnStates.GetSize() );
	return m_ColumnStates[nCol];
}

bool CMyListCtrl::IsColumnVisible(int nCol)
{
	return GetColumnState(nCol).m_Visible;
}

int CMyListCtrl::GetColumnStateCount()
{
	return m_ColumnStates.GetSize();
}

void CMyListCtrl::InsertColumnState(int nCol, bool bVisible, int nOrgWidth)
{
	VERIFY( nCol >=0 && nCol <= m_ColumnStates.GetSize() );

	ColumnState columnState;
	columnState.m_OrgWidth = nOrgWidth;
	columnState.m_Visible = bVisible;

	if (nCol == m_ColumnStates.GetSize())
	{
		// Append column picker to the end of the array
		m_ColumnStates.Add(columnState);
	}
	else
	{
		// Insert column in the middle of the array
		//CArray<ColumnState, ColumnState&> newArray;
		//for(int i=0 ; i < m_ColumnStates.GetSize(); ++i)
		//{
		//	if (i == nCol)
		//		newArray.Add(columnState);
		//	newArray.Add(m_ColumnStates[i]);
		//}
		//m_ColumnStates = newArray;
		m_ColumnStates.InsertAt(nCol, columnState, 1);
	}
}

void CMyListCtrl::DeleteColumnState(int nCol)
{
	VERIFY( nCol >=0 && nCol < m_ColumnStates.GetSize() );
	m_ColumnStates.RemoveAt(nCol);
}

void CMyListCtrl::OnContextMenu(CWnd* pWnd, CPoint point)
{
	if (point.x==-1 && point.y==-1)
	{
		// OBS! point is initialized to (-1,-1) if using SHIFT+F10 or VK_APPS
	}
	else
	{
		CPoint pt = point;
		ScreenToClient(&pt);

		CRect headerRect;
		GetHeaderCtrl()->GetClientRect(&headerRect);
		if (headerRect.PtInRect(pt))
		{
			// Show context-menu with the option to show hide columns
			CMenu menu;
			if (menu.CreatePopupMenu())
			{
				for( int i = GetColumnStateCount()-1 ; i >= 0; --i)
				{
					UINT uFlags = MF_BYPOSITION | MF_STRING;

					// Put check-box on context-menu
					if (IsColumnVisible(i))
						uFlags |= MF_CHECKED;
					else
						uFlags |= MF_UNCHECKED;

					// Retrieve column-title
					LVCOLUMN lvc = {0};
					lvc.mask = LVCF_TEXT;
					TCHAR sColText[256];
					lvc.pszText = sColText;
					lvc.cchTextMax = sizeof(sColText)-1;
					VERIFY( GetColumn(i, &lvc) );

					menu.InsertMenu(0, uFlags, i, lvc.pszText);
				}

				menu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this, 0);
			}
		}
	}
}

// Handle context-menu event for showing / hiding columns
BOOL CMyListCtrl::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (HIWORD(wParam) == 0)
	{
		int nCol = LOWORD(wParam);
		ShowColumn(nCol, !IsColumnVisible(nCol));
	}
	return TRUE;
}

void CMyListCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch(nChar)
	{
		case VK_ADD:	// CTRL + NumPlus (Auto size all columns)
		{
			if (GetKeyState(VK_CONTROL) < 0)
			{
				// Special handling to avoid showing "hidden" columns
				SetColumnWidthAuto(-1);
				return;
			}
		} break;
	}
	CListCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CMyListCtrl::OnHeaderBeginResize(UINT, NMHDR* pNMHDR, LRESULT* pResult)
{
	// Check that column is allowed to be resized
	NMHEADER* pNMH = (NMHEADER*)pNMHDR;
	int nCol = (int)pNMH->iItem;
	if (!IsColumnVisible(nCol))
	{
		*pResult = TRUE;	// Block resize
		return TRUE;		// Block event
	}
	return FALSE;
}

LRESULT CMyListCtrl::OnSetColumnWidth(WPARAM wParam, LPARAM lParam)
{
	// Check that column is allowed to be resized
	int nCol = (int)wParam;
	if (!IsColumnVisible(nCol))
	{
		return FALSE;
	}
	// Let the CListCtrl handle the event
	return DefWindowProc(LVM_SETCOLUMNWIDTH, wParam, lParam);
}

BOOL CMyListCtrl::OnHeaderEndDrag(UINT, NMHDR* pNMHDR, LRESULT* pResult)
{
	NMHEADER* pNMH = (NMHEADER*)pNMHDR;
	if (pNMH->pitem->mask & HDI_ORDER)
	{
		// Correct iOrder so it is just after the last hidden column
		int nColCount = GetHeaderCtrl()->GetItemCount();
		int* pOrderArray = new int[nColCount];
		VERIFY( GetColumnOrderArray(pOrderArray, nColCount) );

		for(int i = 0; i < nColCount ; ++i)
		{
			if (IsColumnVisible(pOrderArray[i]))
			{
                pNMH->pitem->iOrder = max(pNMH->pitem->iOrder,i);
				break;
			}
		}
		delete [] pOrderArray;
	}
	return FALSE;
}

BOOL CMyListCtrl::OnHeaderDividerDblClick(UINT, NMHDR* pNMHDR, LRESULT* pResult)
{
	NMHEADER* pNMH = (NMHEADER*)pNMHDR;
	SetColumnWidthAuto(pNMH->iItem);
	return TRUE;	// Don't let parent handle the event
}

LRESULT CMyListCtrl::OnDeleteColumn(WPARAM wParam, LPARAM lParam)
{
	// Let the CListCtrl handle the event
	LRESULT lRet = DefWindowProc(LVM_DELETECOLUMN, wParam, lParam);
	if (lRet == FALSE)
		return FALSE;

	// Book keeping of columns
	DeleteColumnState((int)wParam);
	return lRet;
}

LRESULT CMyListCtrl::OnInsertColumn(WPARAM wParam, LPARAM lParam)
{
	// Let the CListCtrl handle the event
	LRESULT lRet = DefWindowProc(LVM_INSERTCOLUMN, wParam, lParam);
	if (lRet == -1)
		return -1;

	int nCol = (int)lRet;

	// Book keeping of columns
	if (GetColumnStateCount() < GetHeaderCtrl()->GetItemCount())
		InsertColumnState((int)nCol, true);	// Insert as visible

	return lRet;
}

namespace {
	LRESULT EnableWindowTheme(HWND hwnd, LPCWSTR classList, LPCWSTR subApp, LPCWSTR idlist)
	{
		HMODULE hinstDll;
		HRESULT (__stdcall *pSetWindowTheme)(HWND hwnd, LPCWSTR pszSubAppName, LPCWSTR pszSubIdList);
		HANDLE (__stdcall *pOpenThemeData)(HWND hwnd, LPCWSTR pszClassList);
		HRESULT (__stdcall *pCloseThemeData)(HANDLE hTheme);

		hinstDll = ::LoadLibrary("UxTheme.dll");
		if (hinstDll)
		{
			(FARPROC&)pOpenThemeData = ::GetProcAddress(hinstDll, TEXT("OpenThemeData"));
			(FARPROC&)pCloseThemeData = ::GetProcAddress(hinstDll, TEXT("CloseThemeData"));
			(FARPROC&)pSetWindowTheme = ::GetProcAddress(hinstDll, TEXT("SetWindowTheme"));
			::FreeLibrary(hinstDll);
			if (pSetWindowTheme && pOpenThemeData && pCloseThemeData)
			{
				HANDLE theme = pOpenThemeData(hwnd,classList);
				if (theme!=NULL)
				{
					VERIFY(pCloseThemeData(theme)==S_OK);
					return pSetWindowTheme(hwnd, subApp, idlist);
				}
			}
		}
		return S_FALSE;
	}
}

/*
void CMyListCtrl::PreSubclassWindow()
{
	CListCtrl::PreSubclassWindow();

	// Focus retangle is not painted properly without double-buffering
#if (_WIN32_WINNT >= 0x501)
	SetExtendedStyle(LVS_EX_DOUBLEBUFFER | GetExtendedStyle());
#endif
	SetExtendedStyle(GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	SetExtendedStyle(GetExtendedStyle() | LVS_EX_HEADERDRAGDROP);
	SetExtendedStyle(GetExtendedStyle() | LVS_EX_GRIDLINES);

	// Enable Vista-look if possible
	EnableWindowTheme(GetSafeHwnd(), L"ListView", L"Explorer", NULL);
}
*/
void CMyListCtrl::PreSubclassWindow()
{
	// the list control must have the report style.
	ASSERT( GetStyle() & LVS_REPORT );

	CListCtrl::PreSubclassWindow();
	VERIFY( m_ctlHeader.SubclassWindow( GetHeaderCtrl()->GetSafeHwnd() ) );
}


BOOL CMyListCtrl::SetHeadings( UINT uiStringID )
{
	CString strHeadings;
	VERIFY( strHeadings.LoadString( uiStringID ) );
	return SetHeadings( strHeadings );
}


// the heading text is in the format column 1 text,column 1 width;column 2 text,column 3 width;etc.
BOOL CMyListCtrl::SetHeadings( const CString& strHeadings )
{
	int iStart = 0;

	for( ;; )
	{
		const int iComma = strHeadings.Find( _T(','), iStart );

		if( iComma == -1 )
			break;

		const CString strHeading = strHeadings.Mid( iStart, iComma - iStart );

		iStart = iComma + 1;

		int iSemiColon = strHeadings.Find( _T(';'), iStart );

		if( iSemiColon == -1 )
			iSemiColon = strHeadings.GetLength();

		const int iWidth = atoi( strHeadings.Mid( iStart, iSemiColon - iStart ) );
		
		iStart = iSemiColon + 1;

		if( InsertColumn( m_iNumColumns++, strHeading, LVCFMT_LEFT, iWidth ) == -1 )
			return FALSE;
	}

	return TRUE;
}


int CMyListCtrl::AddItem( LPCTSTR pszText, ... )
{
	const int iIndex = InsertItem( GetItemCount(), pszText );
	LPTSTR* arrpsz = new LPTSTR[ m_iNumColumns ];
	COLORREF * clrText = new COLORREF[ m_iNumColumns ];
	COLORREF * clrBak= new COLORREF[ m_iNumColumns ];

	arrpsz[ 0 ] = new TCHAR[ lstrlen( pszText ) + 1 ];
	clrText[ 0 ] = crWindowText;
	clrBak[ 0 ] = crWindow;
	(void)lstrcpy( arrpsz[ 0 ], pszText );
	
 	va_list list;
	va_start( list, pszText );

	//insert sub item  and set subitem data
	for( int iColumn = 1; iColumn < m_iNumColumns; iColumn++ )
	{
		pszText = va_arg( list, LPCTSTR );
		ASSERT_VALID_STRING( pszText );
		VERIFY( CListCtrl::SetItem( iIndex, iColumn, LVIF_TEXT, pszText, 0, 0, 0, 0 ) );

		arrpsz[ iColumn ] = new TCHAR[ lstrlen( pszText ) + 1 ];
		clrText[ iColumn ] = crWindowText;
		clrBak[ iColumn ] = crWindow;
		(void)lstrcpy( arrpsz[ iColumn ], pszText );
	}

	va_end( list );

	VERIFY( SetArray( iIndex, arrpsz,clrText,clrBak ) );

	return iIndex;
}


void CMyListCtrl::FreeItemMemory( const int iItem )
{
	ItemData* pid = reinterpret_cast<ItemData*>( CListCtrl::GetItemData( iItem ) );



	LPTSTR* arrpsz = pid->arrpsz;

	for( int i = 0; i < m_iNumColumns; i++ )
	{
		delete[] arrpsz[ i ];	
	}
	delete[] pid->crText;
	delete[] pid->crBak;
	delete[] arrpsz;
	delete pid;
	

	VERIFY( CListCtrl::SetItemData( iItem, NULL ) );
}


BOOL CMyListCtrl::DeleteItem( int iItem )
{
	FreeItemMemory( iItem );
	return CListCtrl::DeleteItem( iItem );
}


BOOL CMyListCtrl::DeleteAllItems()
{
	for( int iItem = 0; iItem < GetItemCount(); iItem ++ )
		FreeItemMemory( iItem );

	return CListCtrl::DeleteAllItems();
}


bool IsNumber( LPCTSTR pszText )
{
	ASSERT_VALID_STRING( pszText );

	for( int i = 0; i < lstrlen( pszText ); i++ )
		if( !_istdigit( pszText[ i ] ) )
			return false;

	return true;
}


int NumberCompare( LPCTSTR pszNumber1, LPCTSTR pszNumber2 )
{
	ASSERT_VALID_STRING( pszNumber1 );
	ASSERT_VALID_STRING( pszNumber2 );

	const int iNumber1 = atoi( pszNumber1 );
	const int iNumber2 = atoi( pszNumber2 );

	if( iNumber1 < iNumber2 )
		return -1;
	
	if( iNumber1 > iNumber2 )
		return 1;

	return 0;
}


bool IsDate( LPCTSTR pszText )
{
	ASSERT_VALID_STRING( pszText );

	// format should be 99/99/9999.

	if( lstrlen( pszText ) != 10 )
		return false;

	return _istdigit( pszText[ 0 ] )
		&& _istdigit( pszText[ 1 ] )
		&& pszText[ 2 ] == _T('/')
		&& _istdigit( pszText[ 3 ] )
		&& _istdigit( pszText[ 4 ] )
		&& pszText[ 5 ] == _T('/')
		&& _istdigit( pszText[ 6 ] )
		&& _istdigit( pszText[ 7 ] )
		&& _istdigit( pszText[ 8 ] )
		&& _istdigit( pszText[ 9 ] );
}


int DateCompare( const CString& strDate1, const CString& strDate2 )
{
	const int iYear1 = atoi( strDate1.Mid( 6, 4 ) );
	const int iYear2 = atoi( strDate2.Mid( 6, 4 ) );

	if( iYear1 < iYear2 )
		return -1;

	if( iYear1 > iYear2 )
		return 1;

	const int iMonth1 = atoi( strDate1.Mid( 3, 2 ) );
	const int iMonth2 = atoi( strDate2.Mid( 3, 2 ) );

	if( iMonth1 < iMonth2 )
		return -1;

	if( iMonth1 > iMonth2 )
		return 1;

	const int iDay1 = atoi( strDate1.Mid( 0, 2 ) );
	const int iDay2 = atoi( strDate2.Mid( 0, 2 ) );

	if( iDay1 < iDay2 )
		return -1;

	if( iDay1 > iDay2 )
		return 1;

	return 0;
}


int CALLBACK CMyListCtrl::CompareFunction( LPARAM lParam1, LPARAM lParam2, LPARAM lParamData )
{
	CMyListCtrl* pListCtrl = reinterpret_cast<CMyListCtrl*>( lParamData );
	ASSERT( pListCtrl->IsKindOf( RUNTIME_CLASS( CListCtrl ) ) );

	ItemData* pid1 = reinterpret_cast<ItemData*>( lParam1 );
	ItemData* pid2 = reinterpret_cast<ItemData*>( lParam2 );

	ASSERT( pid1 );
	ASSERT( pid2 );


		LPCTSTR pszText1 = pid1->arrpsz[ pListCtrl->m_iSortColumn ];
		LPCTSTR pszText2 = pid2->arrpsz[ pListCtrl->m_iSortColumn ];


	ASSERT_VALID_STRING( pszText1 );
	ASSERT_VALID_STRING( pszText2 );

	if( IsNumber( pszText1 ) )
		return pListCtrl->m_bSortAscending ? NumberCompare( pszText1, pszText2 ) : NumberCompare( pszText2, pszText1 );
	else if( IsDate( pszText1 ) )
		return pListCtrl->m_bSortAscending ? DateCompare( pszText1, pszText2 ) : DateCompare( pszText2, pszText1 );
	else
		// text.
		return pListCtrl->m_bSortAscending ? lstrcmp( pszText1, pszText2 ) : lstrcmp( pszText2, pszText1 );
}


void CMyListCtrl::OnColumnClick( NMHDR* pNMHDR, LRESULT* pResult )
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	const int iColumn = pNMListView->iSubItem;

	// if it's a second click on the same column then reverse the sort order,
	// otherwise sort the new column in ascending order.
	Sort( iColumn, iColumn == m_iSortColumn ? !m_bSortAscending : TRUE );

	*pResult = 0;
}


void CMyListCtrl::Sort( int iColumn, BOOL bAscending )
{
	m_iSortColumn = iColumn;
	m_bSortAscending = bAscending;

	// show the appropriate arrow in the header control.
	m_ctlHeader.SetSortArrow( m_iSortColumn, m_bSortAscending );

	VERIFY( SortItems( ListCompare, reinterpret_cast<DWORD>( this ) ) );
}


void CMyListCtrl::LoadColumnInfo()
{
	// you must call this after setting the column headings.
	ASSERT( m_iNumColumns > 0 );

	CString strKey;
	strKey.Format( _T("%d"), GetDlgCtrlID() );

	UINT nBytes = 0;
	BYTE* buf = NULL;
	if( AfxGetApp()->GetProfileBinary( g_pszSection, strKey, &buf, &nBytes ) )
	{
		if( nBytes > 0 )
		{
			CMemFile memFile( buf, nBytes );
			CArchive ar( &memFile, CArchive::load );
			m_ctlHeader.Serialize( ar );
			ar.Close();

			m_ctlHeader.Invalidate();
		}

		delete[] buf;
	}
}


void CMyListCtrl::SaveColumnInfo()
{
	ASSERT( m_iNumColumns > 0 );

	CString strKey;
	strKey.Format( _T("%d"), GetDlgCtrlID() );

	CMemFile memFile;

	CArchive ar( &memFile, CArchive::store );
	m_ctlHeader.Serialize( ar );
	ar.Close();

	DWORD dwLen = memFile.GetLength();
	BYTE* buf = memFile.Detach();	

	VERIFY( AfxGetApp()->WriteProfileBinary( g_pszSection, strKey, buf, dwLen ) );

	free( buf );
}


void CMyListCtrl::OnDestroy() 
{
	for( int iItem = 0; iItem < GetItemCount(); iItem ++ )
		FreeItemMemory( iItem );

	CListCtrl::OnDestroy();
}


BOOL CMyListCtrl::SetItemText( int nItem, int nSubItem, LPCTSTR lpszText )
{
	if( !CListCtrl::SetItemText( nItem, nSubItem, lpszText ) )
		return FALSE;

	LPTSTR* arrpsz = GetTextArray( nItem );
	LPTSTR pszText = arrpsz[ nSubItem ];
	delete[] pszText;
	pszText = new TCHAR[ lstrlen( lpszText ) + 1 ];
	(void)lstrcpy( pszText, lpszText );
	arrpsz[ nSubItem ] = pszText;

	return TRUE;
}


BOOL CMyListCtrl::SetItemData( int nItem, DWORD dwData )
{

		//if( nItem >= GetItemCount() )
		//	return FALSE;
	
		//ItemData* pid = reinterpret_cast<ItemData*>( CListCtrl::GetItemData( nItem ) );
		//ASSERT( pid );
		//pid->dwData = dwData;
	
		//return TRUE;

	CListCtrl::SetItemData( nItem,  dwData);
	return TRUE;
	
}


DWORD CMyListCtrl::GetItemData( int nItem ) const
{

		ASSERT( nItem < GetItemCount() );
	
		ItemData* pid = reinterpret_cast<ItemData*>( CListCtrl::GetItemData( nItem ) );
		ASSERT( pid );
		return pid->dwData;
	
}


BOOL CMyListCtrl::SetArray( int iItem, LPTSTR* arrpsz,COLORREF * clrText,COLORREF * clrBak )
{
	ASSERT( CListCtrl::GetItemData( iItem ) == NULL );
	ItemData* pid = new ItemData;
	pid->arrpsz = arrpsz;
	pid->crText = clrText;
	pid->crBak = clrBak;
	return CListCtrl::SetItemData( iItem, reinterpret_cast<DWORD>( pid ) );//set item data /
}


LPTSTR* CMyListCtrl::GetTextArray( int iItem ) const
{
	ASSERT( iItem < GetItemCount() );

	ItemData* pid = reinterpret_cast<ItemData*>( CListCtrl::GetItemData( iItem ) );
	return pid->arrpsz;
}


void CMyListCtrl::OnPaint() 
{
	Default();
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CListCtrl::OnPaint() for painting messages
}

void CMyListCtrl::OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult)
{
	//draw each item.set txt color,bkcolor....
	NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>(pNMHDR);
	
	// Take the default processing unless we set this to something else below.
	*pResult = CDRF_DODEFAULT;
	
	// First thing - check the draw stage. If it's the control's prepaint
	// stage, then tell Windows we want messages for every item.
	
	if (pLVCD->nmcd.dwDrawStage == CDDS_PREPAINT)
	{
		*pResult = CDRF_NOTIFYITEMDRAW;
	}
	else if (pLVCD->nmcd.dwDrawStage == CDDS_ITEMPREPAINT)
	{
		// This is the notification message for an item.  We'll request
		// notifications before each subitem's prepaint stage.
		
		*pResult = CDRF_NOTIFYSUBITEMDRAW;
	}
	else if (pLVCD->nmcd.dwDrawStage == (CDDS_ITEMPREPAINT | CDDS_SUBITEM))
	{
		// This is the prepaint stage for a subitem. Here's where we set the
		// item's text and background colors. Our return value will tell
		// Windows to draw the subitem itself, but it will use the new colors
		// we set here.
		
		int nItem = static_cast<int> (pLVCD->nmcd.dwItemSpec);
		int nSubItem = pLVCD->iSubItem;
		
		ItemData *pXLCD = (ItemData *) pLVCD->nmcd.lItemlParam;
		ASSERT(pXLCD);
		
		COLORREF crText  = crWindowText;
		COLORREF crBkgnd = crWindow;
		
		
		if (pXLCD){
			crText  = (pXLCD->crText)[nSubItem];
			crBkgnd = (pXLCD->crBak)[nSubItem];
		}
								
		
		
		// store the colors back in the NMLVCUSTOMDRAW struct
		pLVCD->clrText = crText;
		pLVCD->clrTextBk = crBkgnd;
		
		CDC* pDC = CDC::FromHandle(pLVCD->nmcd.hdc);
		CRect rect;
		GetSubItemRect(nItem, nSubItem, LVIR_BOUNDS, rect);
		rect.left += 1;
		if (GetItemState(nItem, LVIS_SELECTED))
			DrawText(nItem, nSubItem, pDC, crHighLightText, crHighLight , rect);
		else
			DrawText(nItem, nSubItem, pDC, crText, crBkgnd, rect);
				
		*pResult = CDRF_SKIPDEFAULT;	// We've painted everything.
	}
}


int CMyListCtrl::AddItemColor(LPCTSTR pszText, COLORREF crText, COLORREF crBak)
{
	//insert item at the last
	const int iIndex = InsertItem( GetItemCount(), pszText );
	ItemData *m_pSortItemData=new ItemData[GetColumns()];

	//m_pSortItemData[0].crText=crText;
	//m_pSortItemData[0].crBak=crBak;

	
	SetItemData(iIndex,(DWORD) m_pSortItemData);

	//no sort function
	
	return iIndex;


}

int CMyListCtrl::GetColumns()
{
	return m_ctlHeader.GetItemCount();
}

BOOL CMyListCtrl::GetSubItemRect(int nItem, int nSubItem, int nArea, CRect &rect)
{
	ASSERT(nItem >= 0);
	ASSERT(nItem < GetItemCount());
	if ((nItem < 0) || nItem >= GetItemCount())
		return FALSE;
	ASSERT(nSubItem >= 0);
	ASSERT(nSubItem < GetColumns());
	if ((nSubItem < 0) || nSubItem >= GetColumns())
		return FALSE;
	
	BOOL bRC = CListCtrl::GetSubItemRect(nItem, nSubItem, nArea, rect);
	
	// if nSubItem == 0, the rect returned by CListCtrl::GetSubItemRect
	// is the entire row, so use left edge of second subitem
	
	if (nSubItem == 0)
	{
		if (GetColumns() > 1)
		{
			CRect rect1;
			bRC = GetSubItemRect(nItem, 1, LVIR_BOUNDS, rect1);
			rect.right = rect1.left;
		}
	}
	
	return bRC;

}


void CMyListCtrl::DrawText(int nItem, int nSubItem, CDC *pDC, COLORREF crText, COLORREF crBkgnd, CRect &rect)
{
	ASSERT(pDC);
	
//	GetDrawColors(nItem, nSubItem, crText, crBkgnd);
	
	pDC->FillSolidRect(&rect, crBkgnd);
	
	CString str;
	str = GetItemText(nItem, nSubItem);
	
	if (!str.IsEmpty())
	{
		// get text justification
		HDITEM hditem;
		hditem.mask = HDI_FORMAT;
		m_ctlHeader.GetItem(nSubItem, &hditem);
		int nFmt = hditem.fmt & HDF_JUSTIFYMASK;
		UINT nFormat = DT_VCENTER | DT_SINGLELINE;
		if (nFmt == HDF_CENTER)
			nFormat |= DT_CENTER;
		else if (nFmt == HDF_LEFT)
			nFormat |= DT_LEFT;
		else
			nFormat |= DT_RIGHT;
		
		
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(crText);
		pDC->SetBkColor(crBkgnd);
		pDC->DrawText(str, &rect, nFormat);
	
	}

}

void CMyListCtrl::OnSysColorChange() 
{
	CListCtrl::OnSysColorChange();
	
	// TODO: Add your message handler code here
	crWindow              = ::GetSysColor(COLOR_WINDOW);
	crWindowText          = ::GetSysColor(COLOR_WINDOWTEXT);
	crHighLight     = ::GetSysColor(COLOR_HIGHLIGHT);
	crHighLightText = ::GetSysColor(COLOR_HIGHLIGHTTEXT);	
}

void CMyListCtrl::SetItemColor(int nItem, int nSubItem, COLORREF clrText, COLORREF clrBkgnd)
{
	ASSERT(nItem >= 0);
	ASSERT(nItem < GetItemCount());
	if ((nItem < 0) || nItem >= GetItemCount())
		return ;
	ASSERT(nSubItem >= 0);
	ASSERT(nSubItem < GetColumns());
	if ((nSubItem < 0) || nSubItem >= GetColumns())
		return ;
		
	if (nItem < 0)
		return ;	
	
	ItemData *pid = (ItemData *) CListCtrl::GetItemData(nItem);
	if (pid)
	{
		(pid->crText)[nSubItem]		 = (clrText == -1) ? crWindowText : clrText;
		(pid->crBak)[nSubItem]		 = (clrBkgnd == -1) ? crWindow : clrBkgnd;
	}
	
	UpdateSubItem(nItem, nSubItem);	
}


void CMyListCtrl::UpdateSubItem(int nItem, int nSubItem)
{
	ASSERT(nItem >= 0);
	ASSERT(nItem < GetItemCount());
	if ((nItem < 0) || nItem >= GetItemCount())
		return;
	ASSERT(nSubItem >= 0);
	ASSERT(nSubItem < GetColumns());
	if ((nSubItem < 0) || nSubItem >= GetColumns())
		return;
	
	CRect rect;
	if (nSubItem == -1)
	{
		GetItemRect(nItem, &rect, LVIR_BOUNDS);
	}
	else
	{
		GetSubItemRect(nItem, nSubItem, LVIR_BOUNDS, rect);
	}
	
	InvalidateRect(&rect);
	UpdateWindow();				
}

void CMyListCtrl::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult)
{
	AfxMessageBox("hhh");
	*pResult = 0;
}
