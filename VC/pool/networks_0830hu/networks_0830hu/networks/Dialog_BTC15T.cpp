// Dialog_BTC15T.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "Dialog_BTC15T.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_BTC15T dialog


CDialog_BTC15T::CDialog_BTC15T(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_BTC15T::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_BTC15T)
	//}}AFX_DATA_INIT
}


void CDialog_BTC15T::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_BTC15T)
	DDX_Control(pDX, IDC_LIST_BTC15T, m_List_BTC15T);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_BTC15T, CDialog)
	//{{AFX_MSG_MAP(CDialog_BTC15T)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_BTC15T, OnDblclkListBtc15t)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_BTC15T message handlers

void CDialog_BTC15T::OnDblclkListBtc15t(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int listIndex;  
	CString command;
	
	POSITION pos=m_List_BTC15T.GetFirstSelectedItemPosition(); 
	if(pos==NULL) 
		return; 
	
	listIndex=(int)m_List_BTC15T.GetNextSelectedItem(pos); 
	
	CString strIP=m_List_BTC15T.GetItemText(listIndex,0);
	
	char userName[MAX_PATH];
	CString sUsername;
	DWORD size=MAX_PATH;
	::GetUserName(userName,&size);
	sUsername.Format("%s",userName);
	
	CString url = "C:\\Users\\lenovo\\AppData\\Roaming\\360se6\\Application\\360se.exe";
	url.Replace("lenovo", sUsername);
	
	if (PathFileExists(url))
		ShellExecute(NULL,"open",url,strIP,"",SW_SHOWNORMAL);
	else
		ShellExecute(NULL,"open","IEXPLORE.EXE",strIP,"",SW_SHOWNORMAL);
	*pResult = 0;
}
