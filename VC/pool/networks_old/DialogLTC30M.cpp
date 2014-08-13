// DialogLTC30M.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "DialogLTC30M.h"
#include <shlwapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogLTC30M dialog


CDialogLTC30M::CDialogLTC30M(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogLTC30M::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogLTC30M)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialogLTC30M::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogLTC30M)
	DDX_Control(pDX, IDC_LIST_LTC30M, m_List_LTC30M);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogLTC30M, CDialog)
	//{{AFX_MSG_MAP(CDialogLTC30M)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_LTC30M, OnDblclkListLtc30m)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogLTC30M message handlers

void CDialogLTC30M::OnDblclkListLtc30m(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	int listIndex;  
	CString command;
	
	POSITION pos=m_List_LTC30M.GetFirstSelectedItemPosition(); 
	if(pos==NULL) 
		return; 
	
	listIndex=(int)m_List_LTC30M.GetNextSelectedItem(pos); 
	
	CString strIP=m_List_LTC30M.GetItemText(listIndex,0);
	
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
