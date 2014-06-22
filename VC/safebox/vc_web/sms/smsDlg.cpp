// smsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "sms.h"
#include "smsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSmsDlg dialog

CSmsDlg::CSmsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSmsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSmsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSmsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSmsDlg)
	DDX_Control(pDX, IDC_TAB_ALL, m_MainTabControl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSmsDlg, CDialog)
	//{{AFX_MSG_MAP(CSmsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_ALL, OnSelchangeTabAll)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSmsDlg message handlers

BOOL CSmsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	//////////////////////////////////////////////////////////////////////////
	//	User:	Topseten
	// Topseten Add
	//////////////////////////////////////////////////////////////////////////
	// Initialization Data
	// can use rich edit
	AfxInitRichEdit();

	TC_ITEM TabCtrlItem;
	TabCtrlItem.mask = TCIF_TEXT;
	TabCtrlItem.pszText = "µÇÂ½(Login Page)";
	m_MainTabControl.InsertItem( 0, &TabCtrlItem );

	m_Login_Tab.Create(IDD_DIALOG_LOGIN,GetDlgItem(IDC_TAB_ALL));
	m_Main_Tab.Create(DIALOG_MAIN_PAGE,GetDlgItem(IDC_TAB_ALL));

	// Get the IDC_TAB_MAIN window sizes.
	CRect rs; 
	m_MainTabControl.GetClientRect(&rs); 
	
	rs.top+=19; 
	//rs.bottom-=60; 
	//rs.left+=1; 
	//rs.right-=2; 
	
	// Move Help and Calibration dialogs to rs.
	m_Login_Tab.MoveWindow(&rs); 
	m_Main_Tab.MoveWindow(&rs);
	
	// Show or Hide
	m_Login_Tab.ShowWindow(true); 
	m_Main_Tab.ShowWindow(false);
	
	// Set the default 
	m_MainTabControl.SetCurSel(0);
	m_bLogin_Status = FALSE;
	//m_Login_Tab.m_login_username.SetFocus();
	//////////////////////////////////////////////////////////////////////////
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSmsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSmsDlg::OnPaint() 
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
HCURSOR CSmsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/************************************************************************/
/* 
	User:Topseten
	Time:2014-06-01 14:30

	This function is used to avoid key,such as Enter and ESC to quit the application.
*/
/************************************************************************/
BOOL CSmsDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE)  return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) 
	{
		return TRUE;
	}
	else 
	return CDialog::PreTranslateMessage(pMsg);
}

/************************************************************************/
/*	User:Topseten
	Set the TAB OnChange function.
*/
/************************************************************************/
void CSmsDlg::OnSelchangeTabAll(NMHDR* pNMHDR, LRESULT* pResult) 
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
		m_Login_Tab.ShowWindow(true); 
		m_Main_Tab.ShowWindow(false); 

		break;
	case 1:
		m_Login_Tab.ShowWindow(false); 
		m_Main_Tab.ShowWindow(true); 
		break;
	case 2:
	
		break;
	case 3:

		break;
	default:
		m_Login_Tab.ShowWindow(true); 
		m_Main_Tab.ShowWindow(false); 
	}

	*pResult = 0;
}
