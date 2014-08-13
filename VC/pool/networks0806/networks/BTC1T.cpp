// BTC1T.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "BTC1T.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BTC1T dialog


BTC1T::BTC1T(CWnd* pParent /*=NULL*/)
	: CDialog(BTC1T::IDD, pParent)
{
	//{{AFX_DATA_INIT(BTC1T)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void BTC1T::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BTC1T)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BTC1T, CDialog)
	//{{AFX_MSG_MAP(BTC1T)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BTC1T message handlers
