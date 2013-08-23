// Dialog_Tab_Test.cpp : implementation file
//

#include "stdafx.h"
#include "QB.h"
#include "Dialog_Tab_Test.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_Test dialog


CDialog_Tab_Test::CDialog_Tab_Test(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Tab_Test::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_Tab_Test)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialog_Tab_Test::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_Tab_Test)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_Tab_Test, CDialog)
	//{{AFX_MSG_MAP(CDialog_Tab_Test)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_Test message handlers

void CDialog_Tab_Test::OnButton1() 
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("Heelo");
}
