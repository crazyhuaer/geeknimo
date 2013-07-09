// Dialog_Tab_TEST.cpp : implementation file
//

#include "stdafx.h"
#include "QB.h"
#include "Dialog_Tab_TEST.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_TEST dialog


CDialog_Tab_Test::CDialog_Tab_Test(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Tab_Test::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_Tab_TEST)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialog_Tab_Test::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_Tab_TEST)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_Tab_Test, CDialog)
	//{{AFX_MSG_MAP(CDialog_Tab_Test)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_TEST message handlers
