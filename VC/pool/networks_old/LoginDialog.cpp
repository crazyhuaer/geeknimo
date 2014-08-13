// LoginDialog.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "LoginDialog.h"
#include "md5_password.h"
#include "networksDlg.h"
#include "sqlite3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog dialog

extern CNetworksDlg *pDlg;

CLoginDialog::CLoginDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDialog::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(CLoginDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLoginDialog::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void CLoginDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDialog)
	DDX_Control(pDX, IDC_USERNAME, m_username);
	DDX_Control(pDX, IDC_PASSWORD, m_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDialog, CDialog)
	//{{AFX_MSG_MAP(CLoginDialog)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, OnButtonLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CLoginDialog, CDialog)
	//{{AFX_DISPATCH_MAP(CLoginDialog)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ILoginDialog to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {122402C4-9929-4227-8371-DC1A042573DB}
static const IID IID_ILoginDialog =
{ 0x122402c4, 0x9929, 0x4227, { 0x83, 0x71, 0xdc, 0x1a, 0x4, 0x25, 0x73, 0xdb } };

BEGIN_INTERFACE_MAP(CLoginDialog, CDialog)
	INTERFACE_PART(CLoginDialog, IID_ILoginDialog, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog message handlers

struct userInfo
{
	char username[64];
	char password[64];
};

int _sql_callback(void * notused, int argc, char ** argv, char ** szColName)
{	   
	memcpy(reinterpret_cast<userInfo*>(notused)->username, argv[0], 32);
	memcpy(reinterpret_cast<userInfo*>(notused)->password, argv[1], 32);
	return 0;
}

void CLoginDialog::OnButtonLogin() 
{
	// TODO: Add your control notification handler code here
	CString	strUserName,strPassword;	
	m_username.GetWindowText(strUserName);
	m_password.GetWindowText(strPassword);
	
	char* User_userword_Char=strUserName.GetBuffer(strUserName.GetLength());
	strUserName=MDString(User_userword_Char);
	char* User_Password_Char=strPassword.GetBuffer(strPassword.GetLength());
	strPassword = MDString(User_Password_Char);

	char * pErrMsg = 0;  
    int ret = 0;  
    sqlite3 * db = 0;
	userInfo info;
	memset(&info, 0, sizeof(struct userInfo));
    ret = sqlite3_open("./user.db", &db);  
    if ( ret != SQLITE_OK )  
    {  
        AfxMessageBox(sqlite3_errmsg(db));  
        exit(1);  
    } 

	//lkpool.admin 18d86ccba6c49512154e5abfe51eaa06 lkpool.8573  d8c993d0e022c4849ac0c27db27ecf69
	//lkpool 5efb93a618588266af575fb8a381d60f lkpool.007 ccf82797241106ef5cbb8c28f2edd63d
	//ret = sqlite3_exec(db, "SELECT * FROM login WHERE username=\'"+strUserName+"\';",_sql_callback,&info,&pErrMsg); 
	if (strUserName == "5efb93a618588266af575fb8a381d60f")
	{
		ret = sqlite3_exec(db, "SELECT * FROM login WHERE username='5efb93a618588266af575fb8a381d60f';",_sql_callback,&info,&pErrMsg); 
		if (strcmp(info.password,strPassword))
		{
			AfxMessageBox("用户名或密码错误");
			return;
		}

		((CNetworksApp*)AfxGetApp())->isAdmin = FALSE;
		((CNetworksApp*)AfxGetApp())->usrname =strUserName;

		CNetworksDlg* pNetWorkDlg = new CNetworksDlg;
		pNetWorkDlg->Create(IDD_NETWORKS_DIALOG,this); 
		pNetWorkDlg->ShowWindow(SW_SHOW); 
		pNetWorkDlg->CenterWindow();
		this->ShowWindow(SW_HIDE);
	}
	else if(strUserName == "18d86ccba6c49512154e5abfe51eaa06")//admins
	{
		ret = sqlite3_exec(db, "SELECT * FROM login WHERE username='18d86ccba6c49512154e5abfe51eaa06';",_sql_callback,&info,&pErrMsg); 
		if (strcmp(info.password,strPassword))
		{
			AfxMessageBox("用户名或密码错误");
			return;
		}
		CNetworksDlg* pDlg = new CNetworksDlg;
		((CNetworksApp*)AfxGetApp())->isAdmin = TRUE;
		((CNetworksApp*)AfxGetApp())->usrname =strUserName;
		pDlg->Create(IDD_NETWORKS_DIALOG,this); 
		pDlg->ShowWindow(SW_SHOW); 
		pDlg->CenterWindow();
		this->ShowWindow(SW_HIDE);
	}
	else
	{
		AfxMessageBox("用户名或密码错误!");
	}

	sqlite3_close(db);  
    db = 0; 
}

BOOL CLoginDialog::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	// TODO: Add your specialized code here and/or call the base class
	if((pMsg->message == WM_KEYDOWN)&&(pMsg->wParam == VK_RETURN))  
    {  
        //return false;  
		OnButtonLogin();
		return FALSE;
    }   
	
	return CDialog::PreTranslateMessage(pMsg);
}
