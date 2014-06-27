// Dialog_Login.cpp : implementation file
//

#include "stdafx.h"
#include "sms.h"
#include "Dialog_Main.h"
#include "Dialog_Login.h"
#include "smsDlg.h"
#include "md5_password.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_Login dialog


CDialog_Login::CDialog_Login(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Login::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_Login)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialog_Login::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_Login)
	DDX_Control(pDX, IDC_SERVER_URL, m_Server_Url);
	DDX_Control(pDX, IDC_LOGIN_PASSWORD, m_login_password);
	DDX_Control(pDX, IDC_LOGIN_USERNAME, m_login_username);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_Login, CDialog)
	//{{AFX_MSG_MAP(CDialog_Login)
	ON_BN_CLICKED(IDC_LOGIN_ON, OnLoginOn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_Login message handlers
/************************************************************************/
/*
	User:	Topseten.
	Time:	2014-06-01 14:28

	This function:
	Connect the server(example:http://localhost or http://example.com)
	The var strRequestURL is used to save it.
	The var strRequestData is used to save data what u want to get/post.
	case 100:
		prove you can connect and login to get some useful data.
	case other:
		code is u defined which is server back.

	ps: the password is used to md5 by MDString.
*/
/************************************************************************/
void CDialog_Login::OnLoginOn() 
{
	// TODO: Add your control notification handler code here
	//add log to app
	extern CSmsApp theApp;
	theApp.m_Log.LogMessage("程序开始运行");

	CInternetSession m_session;
	CString strData;
	TCHAR	ch;
	CString	strRequestURL,strRequestData;
	
	CString	strUserName,strPassword;

	m_login_username.GetWindowText(strUserName);
	m_login_password.GetWindowText(strPassword);

	char* User_Password_Char=strPassword.GetBuffer(strPassword.GetLength());
	strPassword = MDString(User_Password_Char);

	//strRequestURL = "http://192.168.1.200/projecttest/phone/index.php";
	//strRequestURL = "http://localhost/project/sms/login.php";
	m_Server_Url.GetWindowText(strRequestURL);
	strRequestURL.TrimLeft(); 
	strRequestURL.TrimRight();
	if (strRequestURL == "")
	{
		AfxMessageBox("请按照格式输入服务器地址");
		theApp.m_Log.LogMessage("没有输入服务器地址");
	}
	else if (strRequestURL.Left(7) == "http://" )
	{
		strRequestData = "?username="+strUserName+"&password="+strPassword;
		
		theApp.m_Log.LogMessage("开始连接服务器，连接登陆的url网址为:"+strRequestURL);
		
		CHttpFile *pFile = (CHttpFile *) m_session.OpenURL(strRequestURL+strRequestData, 1, 
			INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
		
		while (pFile->Read(&ch, sizeof(TCHAR)))
		{
			strData += ch;
		}
		
		switch (atoi(strData))
		{
		case 100:
			{
				//AfxMessageBox("登陆成功");
				// Get the SmsDlg window
				CTabCtrl *pDlg = (CTabCtrl *)GetParent();
				CSmsDlg *pSmsDlg = (CSmsDlg *)this->GetParent()->GetParent();
				
				// Save the username and password;
				m_login_username.GetWindowText(m_strUsername);
				m_login_password.GetWindowText(m_strPassword);
				
				theApp.m_Log.LogMessage("登陆成功,登陆的用户名为:"+m_strUsername);
				
				if (pSmsDlg->m_bLogin_Status == FALSE)
				{
					TC_ITEM TabCtrlItem;
					TabCtrlItem.mask = TCIF_TEXT;
					
					// Set the TAB.
					TabCtrlItem.pszText = "短信发送";
					pDlg->InsertItem(1, &TabCtrlItem );
					pSmsDlg->m_Main_Tab.ShowWindow(true);
					pSmsDlg->m_Login_Tab.ShowWindow(false);
					
					// Init the main page
					pSmsDlg->m_Main_Tab.m_Com_Number.SetCurSel(0);
					pSmsDlg->m_Main_Tab.m_MSCOMM_Open = false;
					pSmsDlg->m_Main_Tab.m_pSmsTraffic = new CSmsTraffic;
					pSmsDlg->m_Main_Tab.m_Status_Timer = FALSE;
					pSmsDlg->m_Main_Tab.m_Period_Send.SetWindowText("60");
					
					pSmsDlg->m_Main_Tab.m_Status_Information.SetWindowText("");
					pSmsDlg->m_Main_Tab.m_Status_Enter = 0x00;
					pSmsDlg->m_Main_Tab.m_test_gprs.EnableWindow(FALSE);
					pSmsDlg->m_Main_Tab.m_Start_Send.EnableWindow(FALSE);
					
					pSmsDlg->m_Main_Tab.m_Status_Information.PostMessage(WM_VSCROLL, SB_BOTTOM, 0);	
					pDlg->SetCurSel(1);	
					pSmsDlg->m_bLogin_Status = TRUE;
				} 
				else
				{
					AfxMessageBox("你已经登录过");
					theApp.m_Log.LogMessage(m_strUsername+" 再次登录");
				}
			}
			
			break;
			
		case 101:
			{
				AfxMessageBox("帐号或者密码错误");
				theApp.m_Log.LogMessage(m_strUsername+" 帐号或者密码错误");
			}
			break;
			
		case 102:
			{
				
			}
			break;
			
		case 120:
			{
				AfxMessageBox("亲,你似乎没有发送密码哦");
				theApp.m_Log.LogMessage(m_strUsername+"亲,你似乎没有发送密码哦");
			}
			break;
			
		default:
			{
				
			}
		}
		
		//AfxMessageBox(strData);
		// Kill.
		pFile->Close();
		delete	pFile;
	} 
	else
	{
		AfxMessageBox("请使用http协议");
		theApp.m_Log.LogMessage("输入的协议不正确");
	}
}

/************************************************************************/
/* 
	User:Topseten
	Time:2014-06-01 14:30

	This function is used to avoid key,such as Enter and ESC to quit the application.
	And Enter can login.
*/
/************************************************************************/
BOOL CDialog_Login::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE)  return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) 
	{
		CDialog_Login::OnLoginOn();
		return TRUE;
	}
	else 
    return CDialog::PreTranslateMessage(pMsg);
}
