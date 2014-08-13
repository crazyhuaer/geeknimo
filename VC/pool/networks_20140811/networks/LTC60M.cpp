// LTC60M.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "LTC60M.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LTC60M dialog


LTC60M::LTC60M(CWnd* pParent /*=NULL*/)
	: CDialog(LTC60M::IDD, pParent)
{
	//{{AFX_DATA_INIT(LTC60M)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void LTC60M::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LTC60M)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LTC60M, CDialog)
	//{{AFX_MSG_MAP(LTC60M)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LTC60M message handlers
