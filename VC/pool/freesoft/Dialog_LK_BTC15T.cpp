// Dialog_LK_BTC15T.cpp : implementation file
//

#include "stdafx.h"
#include "freesoft.h"
#include "Dialog_LK_BTC15T.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_LK_BTC15T dialog


CDialog_LK_BTC15T::CDialog_LK_BTC15T(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_LK_BTC15T::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_LK_BTC15T)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialog_LK_BTC15T::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_LK_BTC15T)
	DDX_Control(pDX, IDC_LIST_LK_BTC15T, m_cList_LK_BTC15T);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_LK_BTC15T, CDialog)
	//{{AFX_MSG_MAP(CDialog_LK_BTC15T)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_LK_BTC15T message handlers
