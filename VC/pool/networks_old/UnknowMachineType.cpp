// UnknowMachineType.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "UnknowMachineType.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UnknowMachineType dialog


UnknowMachineType::UnknowMachineType(CWnd* pParent /*=NULL*/)
	: CDialog(UnknowMachineType::IDD, pParent)
{
	//{{AFX_DATA_INIT(UnknowMachineType)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void UnknowMachineType::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UnknowMachineType)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UnknowMachineType, CDialog)
	//{{AFX_MSG_MAP(UnknowMachineType)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UnknowMachineType message handlers
