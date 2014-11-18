// ModifyPassowrd.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "ModifyPassowrd.h"
#include "md5_password.h"
#include "sqlite3.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModifyPassowrd dialog


CModifyPassowrd::CModifyPassowrd(CWnd* pParent /*=NULL*/)
	: CDialog(CModifyPassowrd::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(CModifyPassowrd)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CModifyPassowrd::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void CModifyPassowrd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModifyPassowrd)
	DDX_Control(pDX, IDC_EDIT2, m_newPassword2);
	DDX_Control(pDX, IDC_EDIT1, m_newPassword1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CModifyPassowrd, CDialog)
	//{{AFX_MSG_MAP(CModifyPassowrd)
	ON_BN_CLICKED(IDC_ModifyPassword, OnModifyPassword)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CModifyPassowrd, CDialog)
	//{{AFX_DISPATCH_MAP(CModifyPassowrd)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IModifyPassowrd to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {07D65272-5811-4688-95B1-E1C3F3AC19AE}
static const IID IID_IModifyPassowrd =
{ 0x7d65272, 0x5811, 0x4688, { 0x95, 0xb1, 0xe1, 0xc3, 0xf3, 0xac, 0x19, 0xae } };

BEGIN_INTERFACE_MAP(CModifyPassowrd, CDialog)
	INTERFACE_PART(CModifyPassowrd, IID_IModifyPassowrd, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModifyPassowrd message handlers

void CModifyPassowrd::OnModifyPassword()
{
	// TODO: Add your control notification handler code here
	CString password1, password2;
	m_newPassword1.GetWindowText(password1);
	m_newPassword2.GetWindowText(password2);
	if (password1 == "" || password2 == "")
	{
		AfxMessageBox("密码不能为空");
		return;
	}

	char* set_password1=password1.GetBuffer(password1.GetLength());
	password1=MDString(set_password1);
	char* set_password2=password2.GetBuffer(password2.GetLength());
	password2 = MDString(set_password2);
	if (password1 != password2)
	{
		AfxMessageBox("两次输入密码不相同，请重新输入");
		return;
	}

	char * pErrMsg = 0;  
    int ret = 0;  
    sqlite3 * db = 0;
    ret = sqlite3_open("./user.db", &db);  
    if ( ret != SQLITE_OK )  
    {  
        AfxMessageBox(sqlite3_errmsg(db));  
        exit(1);  
    } 
	ret = sqlite3_exec(db, "UPDATE login SET password=\'"+password2+"\' WHERE username=\'"+((CNetworksApp*)AfxGetApp())->usrname+"\';",NULL,NULL,&pErrMsg); 
	sqlite3_close(db);  
    db = 0; 
	AfxMessageBox("密码修改成功");
	OnCancel();
}

BOOL CModifyPassowrd::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	// TODO: Add your specialized code here and/or call the base class
	if((pMsg->message == WM_KEYDOWN)&&(pMsg->wParam == VK_RETURN))  
    {  
        //return false;  
		OnModifyPassword();
		return FALSE;
    }   
	
	return CDialog::PreTranslateMessage(pMsg);
}
