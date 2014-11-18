// SZLTC30M.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "SZLTC30M.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SZLTC30M dialog


SZLTC30M::SZLTC30M(CWnd* pParent /*=NULL*/)
	: CDialog(SZLTC30M::IDD, pParent)
{
	//{{AFX_DATA_INIT(SZLTC30M)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void SZLTC30M::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SZLTC30M)
	DDX_Control(pDX, IDC_LIST_SZLTC30M, m_List_szLTC30M);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SZLTC30M, CDialog)
	//{{AFX_MSG_MAP(SZLTC30M)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SZLTC30M message handlers
