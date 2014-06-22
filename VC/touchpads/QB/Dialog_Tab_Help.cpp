// Dialog_Tab_Help.cpp : implementation file
//

#include "stdafx.h"
#include "QB.h"
#include "QBDlg.h"
#include "Dialog_Tab_Help.h"
#include "Dialog_Tab_Calibration.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_Help dialog


CDialog_Tab_Help::CDialog_Tab_Help(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Tab_Help::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_Tab_Help)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialog_Tab_Help::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_Tab_Help)
	DDX_Control(pDX, IDC_USER_PASSWORD, m_UserPassword);
	DDX_Control(pDX, IDC_USER_NAME, m_UserName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_Tab_Help, CDialog)
	//{{AFX_MSG_MAP(CDialog_Tab_Help)
	ON_BN_CLICKED(IDC_LOGIN, OnLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_Help message handlers
void CDialog_Tab_Help::OnLogin() 
{
	// TODO: Add your control notification handler code here
	CString UserName,UserPassword;

	CTabCtrl *pDlg = (CTabCtrl *)GetParent();
	CQBDlg *pQbDlg = (CQBDlg *)this->GetParent()->GetParent();

	m_UserName.GetWindowText(UserName);
	m_UserPassword.GetWindowText(UserPassword);

	if ((UserName == "user" && UserPassword == "user"))
	{
		if (!pQbDlg->intLoginUser)
		{
			TC_ITEM TabCtrlItem;
			TabCtrlItem.mask = TCIF_TEXT;
			TabCtrlItem.pszText = "(校准)Calibration";
			pDlg->InsertItem( 1, &TabCtrlItem );
			
			//pDlg->SetCurSel(1);	
			
			//this->ShowWindow(false);
			//pQbDlg->m_MainTabControl_Calibration.ShowWindow(true);
			pQbDlg->intLoginUser = 1;
		}
		else
		{
			//AfxMessageBox("您已经登录了");
		}

	} 
	else if(UserPassword == "98765")
	{
		if (pQbDlg->intLoginUser == 0)
		{
			//AfxMessageBox("弹出工厂模式");
			
			TC_ITEM TabCtrlItem;
			TabCtrlItem.mask = TCIF_TEXT;
			TabCtrlItem.pszText = "(校准)Calibration";
			pDlg->InsertItem( 1, &TabCtrlItem );
			
			TabCtrlItem.pszText = "(设置)PCB_Setting";
			pDlg->InsertItem( 2, &TabCtrlItem );

			TabCtrlItem.pszText = "(测试)Test";
			pDlg->InsertItem( 3, &TabCtrlItem );

			pDlg->SetCurSel(0);	
			
			//this->ShowWindow(false);
			//pQbDlg->m_MainTabControl_Calibration.ShowWindow(true);
			pQbDlg->intLoginUser = 2;
		}
		else if (pQbDlg->intLoginUser == 1)
		{
			TC_ITEM TabCtrlItem;
			TabCtrlItem.mask = TCIF_TEXT;
			
			TabCtrlItem.pszText = "(设置)PCB_Setting";
			pDlg->InsertItem( 2, &TabCtrlItem );
			
			TabCtrlItem.pszText = "(测试)Test";
			pDlg->InsertItem( 3, &TabCtrlItem );
			
			pDlg->SetCurSel(0);	
			
			//this->ShowWindow(false);
			//pQbDlg->m_MainTabControl_Calibration.ShowWindow(true);
			pQbDlg->intLoginUser = 2;
		}
		else
		{
			//AfxMessageBox("您已经登录了");
		}

	}
	else	;

#if 0
	//CQBDlg *dlg = (CQBDlg *)AfxGetApp()->m_pMainWnd;
	CQBDlg *dlg = (CQBDlg *)this->GetParent()->GetParent();
	this->ShowWindow(false);
	dlg->m_MainTabControl_Calibration.ShowWindow(true);
#endif


}

BOOL CDialog_Tab_Help::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE)  return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) 
	{
		CDialog_Tab_Help::OnLogin();
		return TRUE;
	}
	else 
    return CDialog::PreTranslateMessage(pMsg);
}
