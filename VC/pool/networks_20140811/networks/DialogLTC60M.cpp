// DialogLTC60M.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "DialogLTC60M.h"
#include <shlwapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogLTC60M dialog


CDialogLTC60M::CDialogLTC60M(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogLTC60M::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogLTC60M)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialogLTC60M::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogLTC60M)
	DDX_Control(pDX, IDC_LIST_LTC60M, m_List_LTC60M);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogLTC60M, CDialog)
	//{{AFX_MSG_MAP(CDialogLTC60M)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_LTC60M, OnDblclkListLtc60m)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogLTC60M message handlers

void CDialogLTC60M::OnDblclkListLtc60m(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	int listIndex;  
	CString command;
	
	POSITION pos=m_List_LTC60M.GetFirstSelectedItemPosition(); 
	if(pos==NULL) 
		return; 
	
	listIndex=(int)m_List_LTC60M.GetNextSelectedItem(pos); 
	
	CString strIP=m_List_LTC60M.GetItemText(listIndex,0);
	
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
