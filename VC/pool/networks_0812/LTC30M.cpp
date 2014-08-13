// LTC30M.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "LTC30M.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LTC30M dialog


LTC30M::LTC30M(CWnd* pParent /*=NULL*/)
	: CDialog(LTC30M::IDD, pParent)
{
	//{{AFX_DATA_INIT(LTC30M)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void LTC30M::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LTC30M)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LTC30M, CDialog)
	//{{AFX_MSG_MAP(LTC30M)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LTC30M message handlers
