// UnknowType.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "UnknowType.h"
#include <shlwapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UnknowType dialog


UnknowType::UnknowType(CWnd* pParent /*=NULL*/)
	: CDialog(UnknowType::IDD, pParent)
{
	//{{AFX_DATA_INIT(UnknowType)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void UnknowType::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UnknowType)
	DDX_Control(pDX, IDC_LIST_UNKNOWTYPE, m_List_UnknowType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UnknowType, CDialog)
	//{{AFX_MSG_MAP(UnknowType)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_UNKNOWTYPE, OnDblclkListUnknowtype)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UnknowType message handlers

void UnknowType::OnDblclkListUnknowtype(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int listIndex;  
	CString command;
	
	POSITION pos=m_List_UnknowType.GetFirstSelectedItemPosition(); 
	if(pos==NULL) 
		return; 
	
	listIndex=(int)m_List_UnknowType.GetNextSelectedItem(pos); 
	
	CString strIP=m_List_UnknowType.GetItemText(listIndex,0);
	
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
