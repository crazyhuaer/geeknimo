// Dialog_LKBTC1T.cpp : implementation file
//

#include "stdafx.h"
#include "freesoft.h"
#include "Dialog_LKBTC1T.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_LKBTC1T dialog


CDialog_LKBTC1T::CDialog_LKBTC1T(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_LKBTC1T::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_LKBTC1T)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialog_LKBTC1T::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_LKBTC1T)
	DDX_Control(pDX, IDC_LIST_LK_BTC1T, m_cList_LK_BTC1T);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_LKBTC1T, CDialog)
	//{{AFX_MSG_MAP(CDialog_LKBTC1T)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
