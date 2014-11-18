// SZLTC30M.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "SZLTC30M.h"
#include <shlwapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SZLTC30M dialog


SZLTC30M::SZLTC30M(CWnd* pParent /*=NULL*/)
	: CDialog(SZLTC30M::IDD, pParent)
{
	//{{AFX_DATA_INIT(SZLTC30M)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void SZLTC30M::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SZLTC30M)
	DDX_Control(pDX, IDC_LIST_SZLTC30M, m_List_szLTC30M);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SZLTC30M, CDialog)
	//{{AFX_MSG_MAP(SZLTC30M)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SZLTC30M message handlers

void SZLTC30M::OnDblclkListLtc30m(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	int listIndex;  
	CString command;
	
	POSITION pos=m_List_szLTC30M.GetFirstSelectedItemPosition(); 
	if(pos==NULL) 
		return; 
	
	listIndex=(int)m_List_szLTC30M.GetNextSelectedItem(pos); 
	
	CString strIP=m_List_szLTC30M.GetItemText(listIndex,0);
	
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
