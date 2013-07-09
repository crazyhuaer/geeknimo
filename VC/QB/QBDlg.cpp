// QBDlg.cpp : implementation file
//

#include "stdafx.h"
#include "QB.h"
#include "QBDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQBDlg dialog

CQBDlg::CQBDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQBDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQBDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQBDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQBDlg)
	DDX_Control(pDX, IDC_SCREEN_TYPE, m_ScreenType);
	DDX_Control(pDX, IDC_TAB_MAIN, m_MainTabControl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CQBDlg, CDialog)
	//{{AFX_MSG_MAP(CQBDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, OnSelchangeTabMain)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQBDlg message handlers

BOOL CQBDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	// Initialization data
	
	intLoginUser = 0;

	TC_ITEM TabCtrlItem;
	TabCtrlItem.mask = TCIF_TEXT;
	TabCtrlItem.pszText = "(пео╒)Help";
	m_MainTabControl.InsertItem( 0, &TabCtrlItem );

	// Set Help and Calibration the postion IDC_TAB_MAIN
	m_MainTabControl_Test.Create(IDD_TAB_TEST,GetDlgItem(IDC_TAB_MAIN));
	m_MainTabControl_Help.Create(IDD_TAB_HELP,GetDlgItem(IDC_TAB_MAIN)); 
	m_MainTabControl_Calibration.Create(IDD_TAB_CALIBRATION,GetDlgItem(IDC_TAB_MAIN));  
	m_MainTabControl_Pcb_Setting.Create(IDD_TAB_PCB_SETTING,GetDlgItem(IDC_TAB_MAIN)); 

	// Get the IDC_TAB_MAIN window sizes.
	CRect rs; 
	m_MainTabControl.GetClientRect(&rs); 

	rs.top+=19; 
	//rs.bottom-=60; 
	//rs.left+=1; 
	//rs.right-=2; 
	
	// Move Help and Calibration dialogs to rs.
	m_MainTabControl_Help.MoveWindow(&rs); 
	m_MainTabControl_Calibration.MoveWindow(&rs); 
	m_MainTabControl_Test.MoveWindow(&rs); 
	m_MainTabControl_Pcb_Setting.MoveWindow(&rs); 

	// Show or Hide
	m_MainTabControl_Help.ShowWindow(true); 
	m_MainTabControl_Calibration.ShowWindow(false); 
	
	// Set the default 
	m_MainTabControl.SetCurSel(0);
	
	/*
	CString temp;
	temp.Format("%d",IDC_TAB_MAIN);
	AfxMessageBox(temp);
	*/

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CQBDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CQBDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CQBDlg::OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CString temp;
	int Tab_index = m_MainTabControl.GetCurSel();
	/*
	temp.Format("%d",Tab_index);
	
	AfxMessageBox(temp);
	*/
	
	// Show or Hide
	
	switch (Tab_index)
	{
	case 0:
		m_MainTabControl_Help.ShowWindow(true); 
		m_MainTabControl_Calibration.ShowWindow(false); 
		m_MainTabControl_Pcb_Setting.ShowWindow(false);
		m_MainTabControl_Test.ShowWindow(false);
		break;
	case 1:
		m_MainTabControl_Help.ShowWindow(false); 
		m_MainTabControl_Calibration.ShowWindow(true); 
		m_MainTabControl_Pcb_Setting.ShowWindow(false);
		m_MainTabControl_Test.ShowWindow(false);
		break;
	case 2:
		m_MainTabControl_Help.ShowWindow(false); 
		m_MainTabControl_Calibration.ShowWindow(false); 
		m_MainTabControl_Pcb_Setting.ShowWindow(true);
		m_MainTabControl_Test.ShowWindow(false);
		break;
	case 3:
		m_MainTabControl_Help.ShowWindow(false); 
		m_MainTabControl_Calibration.ShowWindow(false); 
		m_MainTabControl_Pcb_Setting.ShowWindow(false);
		m_MainTabControl_Test.ShowWindow(true);
		break;
	default:
		m_MainTabControl_Help.ShowWindow(true); 
		m_MainTabControl_Test.ShowWindow(false);
		m_MainTabControl_Calibration.ShowWindow(false); 
		m_MainTabControl_Pcb_Setting.ShowWindow(false);
	}

	*pResult = 0;
}

void CQBDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	exit(0);
}
