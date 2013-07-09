// Dialog_Tab_Calibration.cpp : implementation file
//

#include "stdafx.h"
#include "QB.h"
#include "Dialog_Tab_Calibration.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_Calibration dialog


CDialog_Tab_Calibration::CDialog_Tab_Calibration(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Tab_Calibration::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_Tab_Calibration)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialog_Tab_Calibration::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_Tab_Calibration)
	DDX_Control(pDX, IDC_STATIC_SN_VERSION, m_Static_Sn_Version);
	DDX_Control(pDX, IDC_STATIC_HW_VERSION, m_Static_Hw_Version);
	DDX_Control(pDX, IDC_STATIC_HW_SN, m_Static_Hw_Sn);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_Tab_Calibration, CDialog)
	//{{AFX_MSG_MAP(CDialog_Tab_Calibration)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_Tab_Calibration message handlers
