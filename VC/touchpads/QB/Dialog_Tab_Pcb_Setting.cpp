// Dialog_Tab_Pcb_Setting.cpp : implementation file
//

#include "stdafx.h"
#include "QB.h"
#include "Dialog_Tab_Pcb_Setting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_Pcb_Setting dialog


CDialog_Tab_Pcb_Setting::CDialog_Tab_Pcb_Setting(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Tab_Pcb_Setting::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_Tab_Pcb_Setting)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialog_Tab_Pcb_Setting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_Tab_Pcb_Setting)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_Tab_Pcb_Setting, CDialog)
	//{{AFX_MSG_MAP(CDialog_Tab_Pcb_Setting)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_Pcb_Setting message handlers
