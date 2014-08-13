// networksDlg.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "networksDlg.h"

#include "CkSsh.h"
#include "MyListCtrl1.h"
#include "LoginDialog.h"
#include <shlwapi.h>
#include "ModifyPassowrd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define UNICODE
#define destPORT 137
#define myPORT 1578
CNetworksDlg *pDlg;
unsigned char B1[4],B2[4];
int EngOrCn;
int suspend = 1;
#define ENG 1
#define CHN 2

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
// CNetworksDlg dialog

CNetworksDlg::CNetworksDlg(CWnd* pParent /*=NULL*/)
: CDialog(CNetworksDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetworksDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	if (!PathFileExists("data"))
	{
		CFileException e;
		if (CreateDirectory("log",NULL))
		{
#ifdef _DEBUG  
			afxDump << "Directory could not be Create " << e.m_cause << "\n";
#endif 

		}
		else
		{			
			CFile *m_pLogFile;
			m_pLogFile = new CFile();
			ASSERT (m_pLogFile != NULL);
			
			if(!m_pLogFile->Open( "data.ini",	CFile::modeCreate	 |	// if not there create it
				CFile::modeNoTruncate|	// Dont truncate 
				CFile::shareDenyNone |	// Let others also read
				CFile::modeWrite, NULL ) )// Write into it
			{
				delete  m_pLogFile;
				m_pLogFile = NULL;	// we were not able to create the file so set ptr to NULL
			}
			if (m_pLogFile != NULL)
			{
				m_IniFile.SetFileName("data","data.ini");
				m_section = "poolinfo";

				m_poolInfo[0] = "POOLA";
				m_IniFile.SetString(m_section,m_poolInfo[0],"http://uk1.ghash.io:3333");
				m_poolInfo[1] = "USERA";
				m_IniFile.SetString(m_section,m_poolInfo[1],"lketc");
				m_poolInfo[2] = "PASSA";
				m_IniFile.SetString(m_section,m_poolInfo[2],"1234");


				m_poolInfo[3] = "POOLB";
				m_IniFile.SetString(m_section,m_poolInfo[3],"stratum+tcp://stratum.f2pool.com:3333");
				m_poolInfo[4] = "USERB";
				m_IniFile.SetString(m_section,m_poolInfo[4],"qq123456");
				m_poolInfo[5] = "PASSB";
				m_IniFile.SetString(m_section,m_poolInfo[5],"1234");

				m_poolInfo[6] = "POOLC";
				m_IniFile.SetString(m_section,m_poolInfo[6],"stratum+tcp://");
				m_poolInfo[7] = "USERC";
				m_IniFile.SetString(m_section,m_poolInfo[7],"lkpool");
				m_poolInfo[8] = "PASSC";
				m_IniFile.SetString(m_section,m_poolInfo[8],"123");

				m_poolInfo[9] = "POOLAONLY";
				m_IniFile.SetInt(m_section,m_poolInfo[9],0);
				m_poolInfo[10] = "POOLBONLY";
				m_IniFile.SetInt(m_section,m_poolInfo[10],0);
				m_poolInfo[11] = "POOLCONLY";
				m_IniFile.SetInt(m_section,m_poolInfo[11],0);
				m_poolInfo[12] = "DIFF";
				m_IniFile.SetInt(m_section,m_poolInfo[12],11);
			}
			m_pLogFile->Close ();
			delete m_pLogFile;
			m_pLogFile = NULL;
		}
	}
	else
	{
		m_IniFile.SetFileName("data","data.ini");
		m_section = "poolinfo";

		m_poolInfo[0] = "POOLA";
		m_poolInfo[1] = "USERA";
		m_poolInfo[2] = "PASSA";
		
		
		m_poolInfo[3] = "POOLB";
		m_poolInfo[4] = "USERB";
		m_poolInfo[5] = "PASSB";
		
		m_poolInfo[6] = "POOLC";
		m_poolInfo[7] = "USERC";
		m_poolInfo[8] = "PASSC";

		m_poolInfo[9] = "POOLAONLY";
		m_poolInfo[10] = "POOLBONLY";
		m_poolInfo[11] = "POOLCONLY";
		m_poolInfo[12] = "DIFF";
	}
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetworksDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetworksDlg)
	DDX_Control(pDX, IDC_CHECK_SINGLE_MACHINE, m_machine_type_know);
	DDX_Control(pDX, IDC_TAB1, m_MainTab);
	DDX_Control(pDX, IDC_COMBO_FRE, m_combo_fre);
	DDX_Control(pDX, IDC_COMBO_COIN_TYPE, m_coinType);
	DDX_Control(pDX, IDC_SINGLE_UPDATE, m_single_update);
	DDX_Control(pDX, IDC_COMBO_DIFF, m_ComboBox_diff);
	DDX_Control(pDX, IDC_CHECK3, m_user_check3);
	DDX_Control(pDX, IDC_CHECK2, m_user_check2);
	DDX_Control(pDX, IDC_CHECK1, m_user_check1);
	DDX_Control(pDX, IDC_STATIC_SINGLE, m_Single);
	DDX_Control(pDX, IDC_MUTIPLE_REBOOT, m_multi_reboot);
	DDX_Control(pDX, IDC_SINGLE_REBOOT, m_sing_reboot);
	DDX_Control(pDX, IDC_STATIC_MULTI, m_Multi);
	DDX_Control(pDX, IDC_BUTTON_REFRESH, m_Button_Fresh);
	DDX_Control(pDX, IDC_REFRESH, m_bFresh);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_EDIT_PASSWORD3, m_PasswordEdit3);
	DDX_Control(pDX, IDC_EDIT_PASSWORD2, m_PasswordEdit2);
	DDX_Control(pDX, IDC_EDIT_PASSWORD1, m_PasswordEdit1);
	DDX_Control(pDX, IDC_EDIT_USERNAME3, m_UsernameEdit3);
	DDX_Control(pDX, IDC_EDIT_USERNAME2, m_UsernameEdit2);
	DDX_Control(pDX, IDC_EDIT_USERNAME1, m_UsernameEdit1);
	DDX_Control(pDX, IDC_EDIT_POOL3, m_PoolUrlEdit3);
	DDX_Control(pDX, IDC_EDIT_POOL2, m_PoolUrlEdit2);
	DDX_Control(pDX, IDC_EDIT_POOL1, m_PoolUrlEdit1);
	DDX_Control(pDX, IDC_IPADDRESS_STOP, m_IPStop);
	DDX_Control(pDX, IDC_IPADDRESS_START, m_IPStart);
	DDX_Control(pDX, IDC_SOFT_STATUS, m_SoftStatus);
	DDX_Control(pDX, IDC_SPIN_TIMEOUT, m_SpinTimeOut);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNetworksDlg, CDialog)
//{{AFX_MSG_MAP(CNetworksDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON_REFRESH, OnButtonRefresh)
ON_BN_CLICKED(IDC_REFRESH, OnRefresh)
ON_BN_CLICKED(IDC_SINGLE_UPDATE, OnSingleUpdate)
	ON_BN_CLICKED(IDC_SINGLE_REBOOT, OnSingleReboot)
	ON_BN_CLICKED(IDC_MUTIPLE_REBOOT, OnMutipleReboot)
	ON_WM_CLOSE()
	ON_COMMAND(ID_MENUITEM32771, OnMenuitemEng)
	ON_COMMAND(ID_MENUITEM32772, OnMenuitemCN)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_SUSPEND, OnButtonSuspend)
	ON_COMMAND(ID_MENUITEM32773, OnMenuitemModifyPassword)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_IP_STATUS, OnDblclkListIpStatus)
	ON_CBN_SELCHANGE(IDC_COMBO_COIN_TYPE, OnSelchangeComboCoinType)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetworksDlg message handlers

BOOL CNetworksDlg::OnInitDialog()
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
	///初始化TAB
	m_MainTab.InsertItem(0,_T("BTC1T"));
	m_MainTab.InsertItem(1,_T("LTC30M"));
	m_MainTab.InsertItem(2,_T("LTC60M"));
	m_MainTab.InsertItem(3,_T("UNKNOWTYPE"));
	m_BTC1T.Create(IDD_DIALOG_BTC1T,GetDlgItem(IDC_TAB1));
	m_LTC30M.Create(IDD_DIALOG_LTC30M,GetDlgItem(IDC_TAB1));
	m_LTC60M.Create(IDD_DIALOG_LTC60M,GetDlgItem(IDC_TAB1));
	m_UnknowType.Create(IDD_DIALOG_UNKNOWTYPE,GetDlgItem(IDC_TAB1));
	CRect rc;
	m_MainTab.GetClientRect(&rc);
	rc.top += 20;
	rc.bottom -= 4;
	rc.left += 4;
	rc.right -= 4;
	m_BTC1T.MoveWindow(&rc);
	m_LTC30M.MoveWindow(&rc);
	m_LTC60M.MoveWindow(&rc);
	m_UnknowType.MoveWindow(&rc);

	m_BTC1T.SetWindowPos(NULL,0,0,1300,500,SWP_NOMOVE);
	m_LTC30M.SetWindowPos(NULL,0,0,1300,500,SWP_NOMOVE);
	m_LTC60M.SetWindowPos(NULL,0,0,1300,500,SWP_NOMOVE);
	m_UnknowType.SetWindowPos(NULL,0,0,1300,500,SWP_NOMOVE);
	
	m_BTC1T.m_List_BTC1T.SetWindowPos(NULL,0,0,1200,360,SWP_NOMOVE);
	m_LTC30M.m_List_LTC30M.SetWindowPos(NULL,0,0,1200,360,SWP_NOMOVE);
	m_LTC60M.m_List_LTC60M.SetWindowPos(NULL,0,0,1200,360,SWP_NOMOVE);
	m_UnknowType.m_List_UnknowType.SetWindowPos(NULL,0,0,1200,360,SWP_NOMOVE);
	
	m_BTC1T.ShowWindow(SW_SHOW);
	m_LTC30M.ShowWindow(0);
    m_LTC60M.ShowWindow(0);
	m_UnknowType.ShowWindow(0);
	//m_MainTab.SetCurFocus(0);
	m_MainTab.SetCurSel(0);


	// Add by topseten
	//---------------------------------------------
	bExit = false;
	bs = (char *) malloc( 50*sizeof(char) );
	strOldIP = "";
	pDlg = this;
	m_line = 0;
	EngOrCn = CHN;//语言默认为中文
	m_thread = NULL;
	
	if(!m_UDPSocket.Create(myPORT,SOCK_DGRAM))
	{
		AfxMessageBox("Failed Create Socket");
	}
	//---------------------------------------------
	
	char bs1[50]={0x0,0x00,0x0,0x10,0x0,0x1,0x0,0x0,0x0,0x0,
		0x0,0x0,0x20,0x43,0x4b,0x41,0x41,0x41,0x41,0x41,
		0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,
		0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,
		0x41,0x41,0x41,0x41,0x41,0x0,0x0,0x21,0x0,0x1};
	
	memcpy(bs,bs1,50);
	
	m_IPStart.SetAddress(192,168,1,1); //设置ip地址默认范围
	m_IPStop.SetAddress(192,168,1,255);

	if (((CNetworksApp*)AfxGetApp())->isAdmin == FALSE)
	{
		GetDlgItem(IDC_BUTTON_REFRESH)->EnableWindow(FALSE);
		GetDlgItem(IDC_SINGLE_UPDATE)->EnableWindow(FALSE);
	}

	//////////////////////////////////////////////////////////////////////////
	// Read Ini
	m_IniFile.ReadIniFile();
	
	CString temp = m_IniFile.GetString(m_section,m_poolInfo[0],"http://uk1.ghash.io:3333");

	m_PoolUrlEdit1.SetWindowText(m_IniFile.GetString(m_section,m_poolInfo[0],"http://uk1.ghash.io:3333"));
	m_UsernameEdit1.SetWindowText(m_IniFile.GetString(m_section,m_poolInfo[1],"lketc"));
	m_PasswordEdit1.SetWindowText(m_IniFile.GetString(m_section,m_poolInfo[2],"1234"));
	m_PoolUrlEdit2.SetWindowText(m_IniFile.GetString(m_section,m_poolInfo[3],"stratum+tcp://stratum.f2pool.com:3333"));
	m_UsernameEdit2.SetWindowText(m_IniFile.GetString(m_section,m_poolInfo[4],"qq123456"));
	m_PasswordEdit2.SetWindowText(m_IniFile.GetString(m_section,m_poolInfo[5],"1234"));
	m_PoolUrlEdit3.SetWindowText(m_IniFile.GetString(m_section,m_poolInfo[6],"stratum+tcp://"));
	m_UsernameEdit3.SetWindowText(m_IniFile.GetString(m_section,m_poolInfo[7],"lketc"));
	m_PasswordEdit3.SetWindowText(m_IniFile.GetString(m_section,m_poolInfo[8],"1234"));

	m_user_check1.SetCheck(m_IniFile.GetInt(m_section,m_poolInfo[9],0));
	m_user_check2.SetCheck(m_IniFile.GetInt(m_section,m_poolInfo[10],0));
	m_user_check3.SetCheck(m_IniFile.GetInt(m_section,m_poolInfo[11],0));
	int inttemp = m_IniFile.GetInt(m_section,m_poolInfo[12],11);
	m_ComboBox_diff.SetCurSel(m_IniFile.GetInt(m_section,m_poolInfo[12],11));

	m_coinType.SetCurSel(0);
	m_combo_fre.SetCurSel(0);
	m_ComboBox_diff.SetCurSel(13);
	
	
	wait_handle=CreateEvent(NULL,true,false,"receive data");//创建处于非触发状态的事件。类型为手动

	m_BTC1T.m_List_BTC1T.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_BTC1T.m_List_BTC1T.SetHeadings(_T("IP,90;BA1,50;BA2,50;BA3,50;BA4,50;SUM,40;PL1-USER,100;PL1_STATUS,75;PL2-USER,100;PL2-STATUS,75;PL3-USER,100;PL3-STATUS,75;RUN-TIME,90;BA10-TEMP,75;BA11-TEMP,75;BA12-TEMP,75;BA13-TEMP,75"));
	
	m_LTC30M.m_List_LTC30M.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_LTC30M.m_List_LTC30M.SetHeadings(_T("IP,90;ICA1,50;ICA2,50;ICA3,50;ICA4,50;SUM,40;PL1-USER,100;PL1_STATUS,75;PL2-USER,100;PL2-STATUS,75;PL3-USER,100;PL3-STATUS,75;RUN-TIME,90;BA10-TEMP,75;BA11-TEMP,75;BA12-TEMP,75;BA13-TEMP,75"));
	
	m_LTC60M.m_List_LTC60M.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_LTC60M.m_List_LTC60M.SetHeadings(_T("IP,90;BA1,50;BA2,50;BA3,50;BA4,50;SUM,40;PL1-USER,100;PL1_STATUS,75;PL2-USER,100;PL2-STATUS,75;PL3-USER,100;PL3-STATUS,75;RUN-TIME,90;BA10-TEMP,75;BA11-TEMP,75;BA12-TEMP,75;BA13-TEMP,75"));
	
	m_UnknowType.m_List_UnknowType.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_UnknowType.m_List_UnknowType.SetHeadings(_T("IP,90;BA1/ICA1,50;BA2/ICA2,50;BA3/ICA3,50;BA4/ICA4,50;SUM,40;PL1-USER,100;PL1_STATUS,75;PL2-USER,100;PL2-STATUS,75;PL3-USER,100;PL3-STATUS,75;RUN-TIME,90;BA10-TEMP,75;BA11-TEMP,75;BA12-TEMP,75;BA13-TEMP,75"));
	
	COLORREF crText,crBak;
	crText=0;
	crBak=0;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNetworksDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNetworksDlg::OnPaint() 
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
HCURSOR CNetworksDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CNetworksDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if((pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) || 
		(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) )  
		return TRUE;
	
    return CDialog::PreTranslateMessage(pMsg);
}

void CNetworksDlg::countMachine()
{
	CString iCount, itemName;
	TC_ITEM ti;
	TCHAR buffer[256] = {0};
	ti.pszText = buffer;
	ti.cchTextMax = 256;
	iCount.Format(_T("%d"), m_BTC1T.m_List_BTC1T.GetItemCount());
	itemName = "BTC1T(" +iCount+ ")";
	//pDlg->m_ListBox.InsertString(0, itemName);
	m_MainTab.GetItem(0,&ti);
	ti.mask = TCIF_TEXT;
	ti.pszText = (LPTSTR)(LPCTSTR)itemName;
	m_MainTab.SetItem (0, &ti);
	
	iCount.Format(_T("%d"), m_LTC30M.m_List_LTC30M.GetItemCount());
	itemName = "LTC30M(" +iCount+")";
	m_MainTab.GetItem(1,&ti);
	ti.mask = TCIF_TEXT;
	ti.pszText = (LPTSTR)(LPCTSTR)itemName;
	m_MainTab.SetItem (1, &ti);
	
	iCount.Format(_T("%d"), m_LTC60M.m_List_LTC60M.GetItemCount());
	itemName = "LTC60M(" +iCount+")";
	m_MainTab.GetItem(2,&ti); 
	ti.pszText = (LPTSTR)(LPCTSTR)itemName;
	ti.mask = TCIF_TEXT;
	m_MainTab.SetItem(2, &ti);
	
	iCount.Format(_T("%d"), m_UnknowType.m_List_UnknowType.GetItemCount());
	itemName = "UNKNOWTYPE(" +iCount+")";
	m_MainTab.GetItem(3,&ti); 
	ti.pszText = (LPTSTR)(LPCTSTR)itemName;
	ti.mask = TCIF_TEXT;	
	m_MainTab.SetItem (3, &ti);
	
	this->UpdateWindow();
	this->Invalidate();
	m_MainTab.Invalidate();
}

void CNetworksDlg::countMachineStatus()
{
	int i;
	CString temp;
	int count_BTC1T=0;
	int count_LTC30M=0;
	int count_LTC60M=0;
	//BTC1T
	for (i = 0; i < m_BTC1T.m_List_BTC1T.GetItemCount(); i++)
	{
		if (atoi(m_BTC1T.m_List_BTC1T.GetItemText(i, 1)) >280 || atoi(m_BTC1T.m_List_BTC1T.GetItemText(i, 1)) < 230 ||
			atoi(m_BTC1T.m_List_BTC1T.GetItemText(i, 2)) >280 || atoi(m_BTC1T.m_List_BTC1T.GetItemText(i, 2)) < 230 ||
			atoi(m_BTC1T.m_List_BTC1T.GetItemText(i, 3)) >280 || atoi(m_BTC1T.m_List_BTC1T.GetItemText(i, 3)) < 230 ||
			atoi(m_BTC1T.m_List_BTC1T.GetItemText(i, 4)) >280 || atoi(m_BTC1T.m_List_BTC1T.GetItemText(i, 4)) < 230 ||
			atoi(m_BTC1T.m_List_BTC1T.GetItemText(i, 5)) >1000 || atoi(m_BTC1T.m_List_BTC1T.GetItemText(i, 5)) < 990)
			count_BTC1T++;
	}

	for (i = 0; i < m_LTC30M.m_List_LTC30M.GetItemCount(); i++)
	{
		if (atoi(m_LTC30M.m_List_LTC30M.GetItemText(i, 1)) >15 || atoi(m_LTC30M.m_List_LTC30M.GetItemText(i, 1)) < 14 ||
			atoi(m_LTC30M.m_List_LTC30M.GetItemText(i, 2)) >15 || atoi(m_LTC30M.m_List_LTC30M.GetItemText(i, 2)) < 14 ||
			atoi(m_LTC30M.m_List_LTC30M.GetItemText(i, 3)) >15 || atoi(m_LTC30M.m_List_LTC30M.GetItemText(i, 3)) < 14 ||
			atoi(m_LTC30M.m_List_LTC30M.GetItemText(i, 4)) >15 || atoi(m_LTC30M.m_List_LTC30M.GetItemText(i, 4)) < 14 ||
			atoi(m_LTC30M.m_List_LTC30M.GetItemText(i, 5)) >60 || atoi(m_LTC30M.m_List_LTC30M.GetItemText(i, 5)) < 58)
			count_LTC30M++;
	}

	for (i = 0; i < m_LTC60M.m_List_LTC60M.GetItemCount(); i++)
	{
		if (atoi(m_LTC60M.m_List_LTC60M.GetItemText(i, 1)) >15 || atoi(m_LTC60M.m_List_LTC60M.GetItemText(i, 1)) < 14 ||
			atoi(m_LTC60M.m_List_LTC60M.GetItemText(i, 2)) >15 || atoi(m_LTC60M.m_List_LTC60M.GetItemText(i, 2)) < 14 ||
			atoi(m_LTC60M.m_List_LTC60M.GetItemText(i, 3)) >15 || atoi(m_LTC60M.m_List_LTC60M.GetItemText(i, 3)) < 14 ||
			atoi(m_LTC60M.m_List_LTC60M.GetItemText(i, 4)) >15 || atoi(m_LTC60M.m_List_LTC60M.GetItemText(i, 4)) < 14 ||
			atoi(m_LTC60M.m_List_LTC60M.GetItemText(i, 5)) >30 || atoi(m_LTC60M.m_List_LTC60M.GetItemText(i, 5)) < 29 )
			count_LTC60M++;
	}
}

//--------------------------nbtstat线程----------------------
UINT CNetworksDlg::NbtstatThread(LPVOID param)
{
	MSG msg;
	//循环对要查询的ip发数据
	do
	{
		while(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{      //将消息队列里的消息逐个读入msg
			if(msg.message==WM_QUIT)
			{     //如果收到终止消息则退出
				//TODO：放在堆里的变量要在这里手动清理
				return 0;      //线程正常返回，会释放局部变量等内存资源
			}
			else
			{
				DispatchMessage(&msg);//字面意思，不解释
			}
		}
		pDlg->m_strIP.Format("%d.%d.%d.%d",B1[0],B1[1],B1[2],B1[3]);//得到ip
		pDlg->m_ListBox.InsertString(0,pDlg->m_strIP);//将该ip插入ListView的ip字段
		
		//		if(B1[3]!=0&&B1[2]!=0)  //此句限制了很多网段的扫描
		int len;
		if(B1[3]!=0&&B1[1]!=0)
			len = pDlg->m_UDPSocket.SendTo((void*)pDlg->bs,50,destPORT,pDlg->m_strIP,0);//向指定的ip发数据报
		//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage(pDlg->m_strIP + " enter wait");
		if (len == 50)
		{
			WaitForSingleObject(
				pDlg->wait_handle,        // 等待事件的句柄
				500   // 超时
				);
			
			ResetEvent(pDlg->wait_handle);//将事件重新置回非触发状态
		}
		//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage(pDlg->m_strIP + " end wait");
		//=============================================
		//生成下一个要查询的ip
		if(B1[2]<=B2[2])
		{
			if(B1[3]<B2[3])B1[3]++;
			else if(B1[2]<B2[2]&&B1[3]<255)B1[3]++;
			else if(B1[2]<B2[2]&&B1[3]==255)
			{
				B1[3]=0;
				B1[2]++;
			}
		}
		else
			break;
		if(B1[3]>=B2[3]&&B1[2]>=B2[2])
			break;
	}while(B1[2]<=255&&B1[3]<=255);
	
	//pDlg->m_ListBox.InsertString(0,"-----complete!-----");
	if (pDlg->bRef == true)
	{
		if (EngOrCn == 2)
			pDlg->m_SoftStatus.SetWindowText("刷新完毕");
		if (EngOrCn == 1)
			pDlg->m_SoftStatus.SetWindowText("Scan over");
		pDlg->m_bFresh.EnableWindow(TRUE);
		pDlg->m_Button_Fresh.EnableWindow(TRUE);
		pDlg->m_sing_reboot.EnableWindow(TRUE);
		pDlg->m_multi_reboot.EnableWindow(TRUE);
		if (((CNetworksApp*)AfxGetApp())->isAdmin == TRUE)
			pDlg->m_single_update.EnableWindow(TRUE);
		pDlg->m_ListBox.InsertString(0,"-----刷新完成!-----");
		//pDlg->m_ListBox.InsertString(0, "------机型数统计如下------");
	}
	else
	{
		if (EngOrCn == 2)
			pDlg->m_Multi.SetWindowText("修改完毕");
		if (EngOrCn == 1)
			pDlg->m_Multi.SetWindowText("Modify over");
		pDlg->m_Button_Fresh.EnableWindow(TRUE);
		pDlg->m_bFresh.EnableWindow(TRUE);
		pDlg->m_sing_reboot.EnableWindow(TRUE);
		pDlg->m_multi_reboot.EnableWindow(TRUE);
		pDlg->m_single_update.EnableWindow(TRUE);
	}
	
	pDlg->countMachine();
	pDlg->countMachineStatus();
	//清除记录的ip 
	pDlg->strOldIP = "";	
	return 0;
}

void CNetworksDlg::sshSrv(CString command, CString hostname, int port)
{
	// TODO: Add your control notification handler code here
	// Needs #include <CkSsh.h>
	
    CkString strOut;
	
    //  Important: It is helpful to send the contents of the
    //  ssh.LastErrorText property when requesting support.
	
    CkSsh ssh;
	
    //  Any string automatically begins a fully-functional 30-day trial.
    bool success;
    success = ssh.UnlockComponent("30-day trial");
    if (success != true) {
        strOut.append(ssh.lastErrorText());
        strOut.append("\r\n");
        //SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
        return;
    }
	
    success = ssh.Connect((LPTSTR)(LPCTSTR)hostname,port);
    if (success != true) {
        strOut.append(ssh.lastErrorText());
        strOut.append("\r\n");
        m_ListBox.InsertString(0, hostname + " ssh connect fail");
        return;
    }
	
    //  Wait a max of 5 seconds when reading responses..
    ssh.put_IdleTimeoutMs(8000);
	
    //  Authenticate using login/password:
    success = ssh.AuthenticatePw("pi","lk20140422smallfish");
    if (success != true) {
        strOut.append(ssh.lastErrorText());
        strOut.append("\r\n");
        m_ListBox.InsertString(0, hostname + " ssh Authenticate fail");
        return;
    }
	
    //  Open a session channel.  (It is possible to have multiple
    //  session channels open simultaneously.)
    int channelNum;
    channelNum = ssh.OpenSessionChannel();
    if (channelNum < 0) {
        strOut.append(ssh.lastErrorText());
        strOut.append("\r\n");
        //SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
		m_ListBox.InsertString(0, hostname + "ssh open session fail");
        return;
    }
	
    //  Some SSH servers require a pseudo-terminal
    //  If so, include the call to SendReqPty.  If not, then
    //  comment out the call to SendReqPty.
    //  Note: The 2nd argument of SendReqPty is the terminal type,
    //  which should be something like "xterm", "vt100", "dumb", etc.
    //  A "dumb" terminal is one that cannot process escape sequences.
    //  Smart terminals, such as "xterm", "vt100", etc. process
    //  escape sequences.  If you select a type of smart terminal,
    //  your application will receive these escape sequences
    //  included in the command's output.  Use "dumb" if you do not
    //  want to receive escape sequences.  (Assuming your SSH
    //  server recognizes "dumb" as a standard dumb terminal.)
    const char * termType;
    termType = "dumb";
    int widthInChars;
    widthInChars = 120;
    int heightInChars;
    heightInChars = 40;
    //  Use 0 for pixWidth and pixHeight when the dimensions
    //  are set in number-of-chars.
    int pixWidth;
    pixWidth = 0;
    int pixHeight;
    pixHeight = 0;
    success = ssh.SendReqPty(channelNum,termType,widthInChars,heightInChars,pixWidth,pixHeight);
    if (success != true) {
        //strOut.append(ssh.lastErrorText());
        //strOut.append("\r\n");
        //SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
        return;
    }
	
    //  Start a shell on the channel:
    success = ssh.SendReqShell(channelNum);
    if (success != true) {
        //strOut.append(ssh.lastErrorText());
        //strOut.append("\r\n");
        //SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
		m_ListBox.InsertString(0, hostname + "ssh send req shell fail");
        return;
    }
	
	//  Start a command in the remote shell.  This example
	//  will send a "ls" command to retrieve the directory listing.
	success = ssh.ChannelSendString(channelNum,command,"ansi");
	if (success != true) {
		m_ListBox.InsertString(0, "ssh command error");
		//strOut.append(ssh.lastErrorText());
		//strOut.append("\r\n");
		//SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
		return;
	}
    //  Send an EOF.  This tells the server that no more data will
    //  be sent on this channel.  The channel remains open, and
    //  the SSH client may still receive output on this channel.
    success = ssh.ChannelSendEof(channelNum);
    if (success != true) {
        strOut.append(ssh.lastErrorText());
        strOut.append("\r\n");
        //SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
        return;
    }
	
    //  Read whatever output may already be available on the
    //  SSH connection.  ChannelReadAndPoll returns the number of bytes
    //  that are available in the channel's internal buffer that
    //  are ready to be "picked up" by calling GetReceivedText
    //  or GetReceivedData.
    //  A return value of -1 indicates failure.
    //  A return value of -2 indicates a failure via timeout.
	
    //  The ChannelReadAndPoll method waits
    //  for data to arrive on the connection usingi the IdleTimeoutMs
    //  property setting.  Once the first data arrives, it continues
    //  reading but instead uses the pollTimeoutMs passed in the 2nd argument:
    //  A return value of -2 indicates a timeout where no data is received.
    int n;
    int pollTimeoutMs;
    pollTimeoutMs = 2000;
    n = ssh.ChannelReadAndPoll(channelNum,pollTimeoutMs);
    if (n < 0) {
        strOut.append(ssh.lastErrorText());
        strOut.append("\r\n");
        //SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
        return;
    }
	
    //  Close the channel:
    success = ssh.ChannelSendClose(channelNum);
    if (success != true) {
        strOut.append(ssh.lastErrorText());
        strOut.append("\r\n");
        //SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
        return;
    }
	
    //  Perhaps we did not receive all of the commands output.
    //  To make sure,  call ChannelReceiveToClose to accumulate any remaining
    //  output until the server's corresponding "channel close" is received.
    success = ssh.ChannelReceiveToClose(channelNum);
    if (success != true) {
        strOut.append(ssh.lastErrorText());
        strOut.append("\r\n");
        //SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
        return;
    }
	
    //  Let's pickup the accumulated output of the command:
    const char * cmdOutput;
    cmdOutput = ssh.getReceivedText(channelNum,"ansi");
    if (cmdOutput == 0 ) {
        strOut.append(ssh.lastErrorText());
        strOut.append("\r\n");
        //SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
        return;
    }
	
    //  Display the remote shell's command output:
    strOut.append(cmdOutput);
    strOut.append("\r\n");
	
    //  Disconnect
    ssh.Disconnect();
	
    //SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
}	


//////////////////////////////////////////////////////////////////////////
// 执行相应事件
//////////////////////////////////////////////////////////////////////////
//--------------------------nbtstat线程----------------------
UINT CNetworksDlg::GetStatusThread(LPVOID param)
{
	CNetworksDlg *CMyPage = (CNetworksDlg*)param;
	int ret;
	BYTE Buf[512];
	memset(Buf, 0, sizeof(Buf));
	CString str,strIP,strHost,strHex,strMac,Host,Group,User,command;
	UINT dport;
	
	CMyPage->m_UDPSocket.ReceiveFrom(Buf,512,strIP,dport,0);//接收数据
    //如果接收到的ip为空或者与原来接收到的ip相同，则返回
	if(strIP==(char)NULL||strIP==CMyPage->strOldIP)
		return -1;
	CMyPage->strOldIP=strIP;
	//int index=m_ListCtrl.InsertItem(0,strIP);//将ip插入ListView
	
	//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage(strIP + " enter get status thread");
	strHost=""; //机器名字
	strHex="";//MAC地址
	User="?";//
	Host="\\";
	int tem=0,num=0;
	bool bAdd=true;
	//根据数据报规则取出相应的信息
	for(int i=57;i<500;i++) //57-72
	{
		//		if(Buf[i]==0xcc)
		//			break; 
		if (num>3)
			break; 
		if(Buf[i]==0x20)
			bAdd=false;
		if(bAdd)
		{
			str.Format("%c",Buf[i]);
			if(Buf[i]>=' ')
				strHost+=str;
			
			str.Format("%02x.",Buf[i]);
			strHex+=str;
		}
		
		if((++tem)%18==0)
		{
            bAdd=true; 
			strHost.TrimRight((char)NULL);
			if(strHost=="")
			{
				strMac.Delete(17,strMac.GetLength()-17);
				//m_ListView.SetItem(index,4,LVIF_TEXT,strMac, 0, 0, 0,0);  //MAC地址
				num++;
				break;
			}
			
			
			if(num==0&&strHost!="")
			{
				//m_ListCtrl.SetItem(index,2,LVIF_TEXT,strHost, 0, 0, 0,0);  //机器名
				//m_ListCtrl.SetItemText(m_line,1,strHost);
				Host=strHost;					
				num++;
			}
			else
			{
				if(Host!=strHost && num==1&& strHost!="")
				{
					//m_ListCtrl.SetItem(index,1,LVIF_TEXT,strHost, 0, 0, 0,0);  //工作组名
					Group=strHost;
					num++;
				}
				else 
				{
					if(strHost!=Host&&strHost!=Group&&num==2&&strHost!="")
					{
						User=strHost;
						if(User!="__MSBROWSE__")
						{
							//m_ListCtrl.SetItem(index,3,LVIF_TEXT,User, 0, 0, 0,0);
							num++;
						}
					}
				}
				
			}
			
			strMac=strHex;
			strHost="";
			strHex="";			
		}		
	}
	
	/*//////////////////////////////test/////////////////////////
	CString HTML;
	//pDlg->MachineType("192.168.1.3", &HTML);
	CInternetSession m_session;
	try
		{
		CHttpFile *pFile  = (CHttpFile *)m_session.OpenURL("http://192.168.1.3", 1, 
			INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
		
		m_session.Close();
		}
		catch (CException* e)
		{
			e->ReportError();
			e->Delete();
		}
	*///////////////////////////////test////////////////////////
	CMyPage->m_ListBox.InsertString(0,strIP + " receive msg");
	if (Host == "RASPBERRYPI" && (CMyPage->bRef == false))
	{
		CMyPage->m_thread->SuspendThread();

		//分币种
		//CString coinType;
		//pDlg->m_coinType.GetWindowText(coinType);
		int coinType = pDlg->m_coinType.GetCurSel();


		///////ssh 登陆后修改cgminer配置
		int idx =strIP.ReverseFind('.');
		
		CString url1, url2, url3;
		pDlg->m_PoolUrlEdit1.GetWindowText(url1);	
		pDlg->m_PoolUrlEdit2.GetWindowText(url2);
		pDlg->m_PoolUrlEdit3.GetWindowText(url3);
		if (url1 == "")
			url1 = "/";

		if (url2 == "")
			url2 = "/";
		
		if (url3 == "")
			url3 = "/";

		
		
		CString user1, user2, user3;
		pDlg->m_UsernameEdit1.GetWindowText(user1);
		if (pDlg->m_user_check1.GetCheck() == BST_CHECKED)
		{
			//AfxMessageBox("check");
		}
		else
		{
			user1 += strIP.Mid(idx,strIP.GetLength());
			if (coinType == 0 || coinType == 1)
				user1 += "b";
			else if (coinType == 2 || coinType == 3)
				user1 += "l";
		}

		pDlg->m_UsernameEdit2.GetWindowText(user2);
		if (pDlg->m_user_check2.GetCheck() == BST_CHECKED)
		{
		}
		else
		{
			user2 += strIP.Mid(idx,strIP.GetLength());
			if (coinType == 0 || coinType == 1)
				user2 += "b";
			else if (coinType == 2 || coinType == 3)
				user2 += "l";
		}

		pDlg->m_UsernameEdit3.GetWindowText(user3);
		if (pDlg->m_user_check3.GetCheck() == BST_CHECKED)
		{
		}
		else
		{
			user3 += strIP.Mid(idx,strIP.GetLength());
			if (coinType == 0 || coinType == 1)
				user3 += "b";
			else if (coinType == 2 || coinType == 3)
				user3 += "l";
		}

		CString passwd1, passwd2, passwd3;
		pDlg->m_PasswordEdit1.GetWindowText(passwd1);		
		pDlg->m_PasswordEdit2.GetWindowText(passwd2);		
		pDlg->m_PasswordEdit3.GetWindowText(passwd3);

		CString diff, strHTML;
		pDlg->m_ComboBox_diff.GetWindowText(diff);
		CString diff_num;
		diff_num.Format("%d", pDlg->m_ComboBox_diff.GetCurSel() + 1);
		//diff_num = itoa(pDlg->m_ComboBox_diff.GetCurSel() + 1);
		CString ifre;
		pDlg->m_combo_fre.GetWindowText(ifre);
		int iResult = pDlg->MachineType(strIP, &strHTML);

		command = "echo ''> /var/config/user.log\r\necho "+url1+" > /var/config/user.log\r\n";
		command += "echo "+user1+" >>/var/config/user.log\r\n";
		command += "echo "+passwd1+" >>/var/config/user.log\r\n";
		command += "echo "+url2+" >> /var/config/user.log\r\n";
		command += "echo "+user2+" >>/var/config/user.log\r\n";
		command += "echo "+passwd2+" >>/var/config/user.log\r\n";
		command += "echo "+url3+" >> /var/config/user.log\r\n";
		command += "echo "+user3+" >>/var/config/user.log\r\n";
		command += "echo "+passwd3+" >>/var/config/user.log\r\n";
		command += "echo 1 >>/var/config/user.log\r\n";
		command += "sudo pkill cgminer\r\n";
		CString cgminer;
		if (pDlg->m_machine_type_know.GetCheck() == BST_CHECKED)//局域网内知道机型且单一机型
		{
			if ((coinType == 0 || coinType == 1))
			{
				cgminer = "sudo /var/config/cgminer -o "+url1+" -u "+user1+" -p "+passwd1+" -o "+url2+" -u "+user2+" -p "+passwd2+" -o "+url3+" -u "+user3+" -p "+passwd3+"  --A1Pll1 1000 --A1Pll2 1000 --A1Pll3 1000 --A1Pll4 1000 --A1Pll5 1000 --api-listen --cs 8 --stmcu 0 -T --diff "+diff_num+" > /var/www/cgminer.log&\r\n";
				command +=cgminer;
				command += "echo "+diff_num+" > /var/config/diff\r\n";
				command += "echo '#!/bin/bash' > /var/config/run.sh\r\necho 'sudo chmod 777 /var/www/cgminer.log' >> /var/config/run.sh\r\necho '"+cgminer+"' >> /var/config/run.sh\r\n";
				
				pDlg->sshSrv(command, strIP, 22);
				pDlg->m_ListBox.InsertString(0, "ssh " + strIP + " success,modify cgminer configurate over");
				//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("ssh:"+strHost);
				CMyPage->m_BTC1T.m_List_BTC1T.AddItem(strIP, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("wait..."), _T("0"), _T("wait..."),  \
					_T("0"), _T("wait..."), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
			}
			else if(coinType == 3)
			{
				cgminer = "sudo /var/config/cgminer -o "+url1+" -u "+user1+" -p "+passwd1+" -o "+url2+" -u "+user2+" -p "+passwd2+" -o "+url3+" -u "+user3+" -p "+passwd3+"  --A1Pll1 "+ifre+" --A1Pll2 "+ifre+" --A1Pll3 "+ifre+" --A1Pll4 "+ifre+" --A1Pll5 "+ifre+" --api-listen --cs 8 --stmcu 0 -T --diff "+diff_num+" --no-submit-stale --lowmem> /var/www/cgminer.log&\r\n";
				command +=cgminer;
				command +="sudo chmod 777 /var/config/sysclock\r\n";
				command += "echo "+ifre+" > /var/config/sysclock\r\n";
				command += "echo "+diff_num+" > /var/config/diff\r\n";
				command += "echo '#!/bin/bash' > /var/config/run.sh\r\necho 'sudo chmod 777 /var/www/cgminer.log' >> /var/config/run.sh\r\necho '"+cgminer+"' >> /var/config/run.sh\r\n";
				
				pDlg->sshSrv(command, strIP, 22);
				pDlg->m_ListBox.InsertString(0, "ssh " + strIP + " success,modify cgminer configurate over");
				//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("ssh:"+strHost);
				CMyPage->m_LTC60M.m_List_LTC60M.AddItem(strIP, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("wait..."), _T("0"), _T("wait..."),  \
					_T("0"), _T("wait..."), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
			}
			else if(coinType == 2)
			{
				cgminer = "sudo /var/config/cgminer -o "+url1+" -u "+user1+" -p "+passwd1+" -o "+url2+" -u "+user2+" -p "+passwd2+" -o "+url3+" -u "+user3+" -p "+passwd3+"  --chips 36  --fixdiff "+diff+" --clock "+ifre+" -S /dev/ttyUSB3 -S /dev/ttyUSB2 -S /dev/ttyUSB1 -S /dev/ttyUSB0   --api-listen --quiet > /var/www/cgminer.log&\r\n";
				command +=cgminer;
				command += "echo "+ifre+" > /var/config/sysclk\r\n";
				command += "echo "+diff+" > /var/config/diff\r\n";
				command += "echo '#!/bin/bash' > /var/config/run.sh\r\necho 'sudo chmod 777 /var/www/cgminer.log' >> /var/config/run.sh\r\necho '"+cgminer+"' >> /var/config/run.sh\r\n";
				
				pDlg->sshSrv(command, strIP, 22);
				pDlg->m_ListBox.InsertString(0, "ssh " + strIP + " success,modify cgminer configurate over");
				//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("ssh:"+strHost);
				CMyPage->m_LTC30M.m_List_LTC30M.AddItem(strIP, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("wait..."), _T("0"), _T("wait..."),  \
					_T("0"), _T("wait..."), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
			}
			else
			{
				CMyPage->m_UnknowType.m_List_UnknowType.AddItem(strIP, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("unknown type"), _T("0"), _T("unknown type"),  \
					_T("0"), _T("unknown type"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
			}
		}
		else //局域网内多种机型机器都存在
		{
			if ((coinType == 0 || coinType == 1) && iResult == 1)
			{
				cgminer = "sudo /var/config/cgminer -o "+url1+" -u "+user1+" -p "+passwd1+" -o "+url2+" -u "+user2+" -p "+passwd2+" -o "+url3+" -u "+user3+" -p "+passwd3+"  --A1Pll1 1000 --A1Pll2 1000 --A1Pll3 1000 --A1Pll4 1000 --A1Pll5 1000 --api-listen --cs 8 --stmcu 0 -T --diff "+diff_num+" > /var/www/cgminer.log&\r\n";
				command +=cgminer;
				command += "echo "+diff_num+" > /var/config/diff\r\n";
				command += "echo '#!/bin/bash' > /var/config/run.sh\r\necho 'sudo chmod 777 /var/www/cgminer.log' >> /var/config/run.sh\r\necho '"+cgminer+"' >> /var/config/run.sh\r\n";
				
				pDlg->sshSrv(command, strIP, 22);
				pDlg->m_ListBox.InsertString(0, "ssh " + strIP + " success,modify cgminer configurate over");
				//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("ssh:"+strHost);
				CMyPage->m_BTC1T.m_List_BTC1T.AddItem(strIP, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("wait..."), _T("0"), _T("wait..."),  \
					_T("0"), _T("wait..."), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
			}
			else if(coinType == 3 && iResult == 3)
			{
				cgminer = "sudo /var/config/cgminer -o "+url1+" -u "+user1+" -p "+passwd1+" -o "+url2+" -u "+user2+" -p "+passwd2+" -o "+url3+" -u "+user3+" -p "+passwd3+"  --A1Pll1 "+ifre+" --A1Pll2 "+ifre+" --A1Pll3 "+ifre+" --A1Pll4 "+ifre+" --A1Pll5 "+ifre+" --api-listen --cs 8 --stmcu 0 -T --diff "+diff_num+" --no-submit-stale --lowmem> /var/www/cgminer.log&\r\n";
				command +=cgminer;
				command +="sudo chmod 777 /var/config/sysclock\r\n";
				command += "echo "+ifre+" > /var/config/sysclock\r\n";
				command += "echo "+diff_num+" > /var/config/diff\r\n";
				command += "echo '#!/bin/bash' > /var/config/run.sh\r\necho 'sudo chmod 777 /var/www/cgminer.log' >> /var/config/run.sh\r\necho '"+cgminer+"' >> /var/config/run.sh\r\n";
				
				pDlg->sshSrv(command, strIP, 22);
				pDlg->m_ListBox.InsertString(0, "ssh " + strIP + " success,modify cgminer configurate over");
				//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("ssh:"+strHost);
				CMyPage->m_LTC60M.m_List_LTC60M.AddItem(strIP, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("wait..."), _T("0"), _T("wait..."),  \
					_T("0"), _T("wait..."), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
			}
			else if(coinType == 2 && iResult == 2)
			{
				cgminer = "sudo /var/config/cgminer -o "+url1+" -u "+user1+" -p "+passwd1+" -o "+url2+" -u "+user2+" -p "+passwd2+" -o "+url3+" -u "+user3+" -p "+passwd3+"  --chips 36  --fixdiff "+diff+" --clock "+ifre+" -S /dev/ttyUSB3 -S /dev/ttyUSB2 -S /dev/ttyUSB1 -S /dev/ttyUSB0   --api-listen --quiet > /var/www/cgminer.log&\r\n";
				command +=cgminer;
				command += "echo "+ifre+" > /var/config/sysclk\r\n";
				command += "echo "+diff+" > /var/config/diff\r\n";
				command += "echo '#!/bin/bash' > /var/config/run.sh\r\necho 'sudo chmod 777 /var/www/cgminer.log' >> /var/config/run.sh\r\necho '"+cgminer+"' >> /var/config/run.sh\r\n";
				
				pDlg->sshSrv(command, strIP, 22);
				pDlg->m_ListBox.InsertString(0, "ssh " + strIP + " success,modify cgminer configurate over");
				//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("ssh:"+strHost);
				CMyPage->m_LTC30M.m_List_LTC30M.AddItem(strIP, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("wait..."), _T("0"), _T("wait..."),  \
					_T("0"), _T("wait..."), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
			}
			else if(iResult == -1)
			{
				CMyPage->m_UnknowType.m_List_UnknowType.AddItem(strIP, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("unknown type"), _T("0"), _T("unknown type"),  \
					_T("0"), _T("unknown type"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
			}
		}
			CMyPage->m_thread->ResumeThread();
	}

	if (Host == "RASPBERRYPI" && (CMyPage->bRef == true))
	{
		CMyPage->m_thread->SuspendThread();
	////////////////////////////////
		int idx =strIP.ReverseFind('.');
		CString user ="lketc" + strIP.Mid(idx,strIP.GetLength());
		CFile configfile;
		configfile.Open("machine.cfg", CFile::modeCreate	 |	// if not there create it
			CFile::modeNoTruncate|	// Dont truncate 
			CFile::shareDenyNone |	// Let others also read
			CFile::modeWrite, NULL);// Write into it
		configfile.SeekToEnd();
		CString config_info = strIP + ",pi,lk20140422smallfish," + user +"\n";
		configfile.Write((char*)(LPCTSTR)config_info, config_info.GetLength());
		configfile.Close();
	/////////////////////////////////

		//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("strHost:"+strIP);
		// alive.

		CString strHtmlData;
		int coinType = pDlg->m_coinType.GetCurSel();
		ret = CMyPage->MachineType(strIP,&strHtmlData);
		pDlg->m_ListBox.InsertString(0, "get machine type");
		//CString temp;
		//temp.Format("%d", ret);
		//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("machintype:" + temp);
		//temp.Format("%d", coinType);
		//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("cointype:" + temp);
		if (ret == 1)
		{	
			CMyPage->MultiLkMachine_GetStatus(strIP, ret, strHtmlData);
			//ret = CMyPage->LkMachine_GetStatus(strIP,1,CMyPage->m_line);
			//CMyPage->m_BTC1T.m_line = CMyPage->m_BTC1T.m_line+1;
		}
		else if (ret == 2)
		{
			CMyPage->MultiLkMachine_GetStatus(strIP, ret, strHtmlData);
			
			//ret = CMyPage->LkMachine_GetStatus(strIP,1,CMyPage->m_line);
			//CMyPage->m_LTC30M.m_line = CMyPage->m_LTC30M.m_line+1;
		}
		else if(ret == 3)
		{
			CMyPage->MultiLkMachine_GetStatus(strIP, ret, strHtmlData);
			//ret = CMyPage->LkMachine_GetStatus(strIP,1,CMyPage->m_line);
			//CMyPage->m_LTC60M.m_line = CMyPage->m_LTC60M.m_line+1;
		}
		else if (ret == -1)
		{
			CMyPage->m_UnknowType.m_List_UnknowType.AddItem(strIP, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("unknown type"), _T("0"), _T("unknown type"),  \
				_T("0"), _T("unknown type"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
			CMyPage->m_UnknowType.m_List_UnknowType.SetItemColor(CMyPage->m_UnknowType.m_line, 0, RGB(255,0,0), RGB(255,255,255));
			CMyPage->m_UnknowType.m_line = CMyPage->m_UnknowType.m_line+1;
		}
		CMyPage->m_thread->ResumeThread();
	}
	
	//触发事件，导致线程函数的继续执行
	SetEvent(CMyPage->wait_handle);
	return 0;
}
void CNetworksDlg::OnReceive()
{	
	//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage(pDlg->m_strIP + " enter Onreceive");
	CWinThread *pThread = AfxBeginThread(GetStatusThread,(LPVOID)this,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
	pThread->m_bAutoDelete=FALSE;
	int suspendCnt=pThread->ResumeThread();
	
	/*
	DWORD exitcode;
	do{
		
		BOOL result = GetExitCodeThread(pThread, &exitcode);
		
		Sleep(200);
		
	}while(exitcode == STILL_ACTIVE);*/
}

void CNetworksDlg::OnButtonRefresh()
{
	// TODO: Add your control notification handler code here
	//从ip控件得到要查询的ip范围
	m_IPStart.GetAddress(B1[0],B1[1],B1[2],B1[3]);
	m_IPStop.GetAddress(B2[0],B2[1],B2[2],B2[3]);
	//判断ip范围是否合法
	if(B2[2]<B1[2])
	{	
		if (EngOrCn == 2)
			AfxMessageBox("终止地址应大于起始地址！");
		if (EngOrCn == 1)
			AfxMessageBox("The last IP must bigger than the first");
		return ;
	}
	else if(B2[2]==B1[2]&&B2[3]<B1[3])
	{
		if (EngOrCn == 2)
			AfxMessageBox("终止地址应大于起始地址！");
		if (EngOrCn == 1)
			AfxMessageBox("The last IP must bigger than the first");
		return ;
	}
	if(B2[0]!=B1[0]||B2[1]!=B1[1])
	{
		if (EngOrCn == 2)
			AfxMessageBox("");
		if (EngOrCn == 1)
			AfxMessageBox("Does not support A or B type of network");
		return ;
	}

	if (EngOrCn == 2)
		m_Multi.SetWindowText("正在修改cgminer配置...");
	if (EngOrCn == 1)
		m_Multi.SetWindowText("Being modified...");
	pDlg->bRef = false;
	
	GetDlgItem(IDC_BUTTON_REFRESH)->EnableWindow(FALSE);
	GetDlgItem(IDC_REFRESH)->EnableWindow(FALSE);
	GetDlgItem(IDC_SINGLE_REBOOT)->EnableWindow(FALSE);
	GetDlgItem(IDC_MUTIPLE_REBOOT)->EnableWindow(FALSE);
	GetDlgItem(IDC_SINGLE_UPDATE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SUSPEND)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(TRUE);

	pDlg->m_BTC1T.m_line = 0;
	pDlg->m_LTC30M.m_line = 0;
	pDlg->m_LTC60M.m_line = 0;
	pDlg->m_UnknowType.m_line = 0;
	m_BTC1T.m_List_BTC1T.DeleteAllItems();
	m_LTC30M.m_List_LTC30M.DeleteAllItems(); 
	m_LTC60M.m_List_LTC60M.DeleteAllItems(); 
	m_UnknowType.m_List_UnknowType.DeleteAllItems(); 
	
	m_thread = AfxBeginThread(NbtstatThread,(LPVOID)this,CREATE_SUSPENDED);
	m_thread->m_bAutoDelete=FALSE;
	int suspendCnt=m_thread->ResumeThread();

	WriteINI();
}

//checksum function
USHORT CNetworksDlg::checksum(USHORT *buffer, int size) { 
	
	unsigned long cksum=0;
	
	while(size >1) { 
		cksum+=*buffer++; 
		size -=sizeof(USHORT); 
	} 
	
	if(size ) { 
		cksum += *(UCHAR*)buffer; 
	} 
	
	cksum = (cksum >> 16) + (cksum & 0xffff); 
	cksum += (cksum >>16); 
	return (USHORT)(~cksum); 
} 

CString CNetworksDlg::FindBA(CString *strHtmlData)
{
	CString BASpeed;
	int iPos = (*strHtmlData).Find("BA1");
	//int strLength = strHtmlData.GetLength();
	CString	temp = (*strHtmlData).Mid(iPos,500);
	*strHtmlData = (*strHtmlData).Mid(iPos,(*strHtmlData).GetLength());
	{
		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,500);
		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,500);
		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,500);
		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,500);
		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos,500);
		
		iPos = temp.Find(">");
		temp = temp.Mid(iPos,500);

		iPos = temp.Find("</td>");
		BASpeed = temp.Mid(1,iPos-1);
		temp.Format("%d",int(atoi(BASpeed)+0.5));
		BASpeed = temp;
		//AfxMessageBox(temp);
	}
	return BASpeed;
}

CString CNetworksDlg::FindSummary(CString *strHtmlData)
{
	CString ALLSpeed;
	int iPos = (*strHtmlData).Find("SUMMARY");
	//int strLength = strHtmlData.GetLength();
	CString	temp = (*strHtmlData).Mid(iPos,500);
	*strHtmlData = (*strHtmlData).Mid(iPos+10,(*strHtmlData).GetLength());

	{
		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,500);
		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,500);
		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,500);

		
		iPos = temp.Find(">");
		temp = temp.Mid(iPos,500);
		
		iPos = temp.Find("</td>");
		ALLSpeed = temp.Mid(1,iPos-1);
		temp.Format("%d",int((atoi(ALLSpeed)+0.5)/1000));
		ALLSpeed = temp;
		//AfxMessageBox(temp);
	}
	return ALLSpeed;
}


CString CNetworksDlg::FindPoolStatus(CString *strHtmlData,int curline)
{
	CString thetemp;
	thetemp.Format("%d",curline);
	//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("FindPoolStatus curline:"+thetemp);

	CString PoolAUrl,PoolAStatus;
	CString PoolBUrl,PoolBStatus;
	CString PoolCUrl,PoolCStatus;
	int iPos = (*strHtmlData).Find("Stratum URL");
	//int strLength = strHtmlData.GetLength();
	CString	temp = (*strHtmlData).Mid(iPos,2500);
	*strHtmlData = (*strHtmlData).Mid(iPos+10,(*strHtmlData).GetLength());
	
	{
		// Get the pool0 status

		for (int k =0; k < 16; k++)
		{
		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,2500);
		}

		iPos = temp.Find(">");
		temp = temp.Mid(iPos,2500);
		
		iPos = temp.Find("</td>");
		PoolAUrl = temp.Mid(1,iPos-1);

		m_ListCtrl.SetItemText(curline, 6,PoolAUrl);


		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,2500);


		iPos = temp.Find(">");
		temp = temp.Mid(iPos,2500);
		
		iPos = temp.Find("</td>");
		PoolAStatus = temp.Mid(1,iPos-1);

		m_ListCtrl.SetItemText(curline, 7,PoolAStatus);

		// Get the pool1 status
		int i = 0 ;
		for (i=0;i<29;i++)
		{
			iPos = temp.Find("<td ");
			temp = temp.Mid(iPos+5,2500);
		}

		iPos = temp.Find(">");
		temp = temp.Mid(iPos,2500);
		
		iPos = temp.Find("</td>");
		PoolBUrl = temp.Mid(1,iPos-1);
		
		m_ListCtrl.SetItemText(curline, 8,PoolBUrl);

		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,2500);

		iPos = temp.Find(">");
		temp = temp.Mid(iPos,2500);
		
		iPos = temp.Find("</td>");
		PoolBStatus = temp.Mid(1,iPos-1);
		
		m_ListCtrl.SetItemText(curline, 9,PoolBStatus);

		// Get the pool2 status
		for (i=0;i<29;i++)
		{
			iPos = temp.Find("<td ");
			temp = temp.Mid(iPos+5,2500);
		}
		
		iPos = temp.Find(">");
		temp = temp.Mid(iPos,2500);
		
		iPos = temp.Find("</td>");
		PoolCUrl = temp.Mid(1,iPos-1);
		
		m_ListCtrl.SetItemText(curline, 10,PoolCUrl);
		
		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,2500);
		
		iPos = temp.Find(">");
		temp = temp.Mid(iPos,2500);
		
		iPos = temp.Find("</td>");
		PoolCStatus = temp.Mid(1,iPos-1);
		
		m_ListCtrl.SetItemText(curline, 11,PoolCStatus);


	}
	return	"0";
}

CString CNetworksDlg::FindRunTime(CString *strHtmlData,int curline)
{
	CString RunTime;
	int iPos = (*strHtmlData).Find("Work Utility");
	//int strLength = strHtmlData.GetLength();
	CString	temp = (*strHtmlData).Mid(iPos,500);
	
	{
		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,500);
		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,500);

		iPos = temp.Find(">");
		temp = temp.Mid(iPos,500);

		iPos = temp.Find("</td>");
		RunTime = temp.Mid(1,iPos-1);
		RunTime.Replace("&nbsp;","");
		//AfxMessageBox(temp);
	}
	return RunTime;
}

CString CNetworksDlg::FindTemp(CString strHtmlData,int curline)
{

	int		iPos;
	CString strFind[]={"BA10","BA11","BA12","BA13"};
	CString	temp = strHtmlData;

	CString ret = "0";

	for (int i = 0;i < 4;i++)
	{
		iPos = strHtmlData.Find(strFind[i]);
		temp = strHtmlData.Mid(iPos,2500);
		{
			iPos = temp.Find("<td ");
			temp = temp.Mid(iPos+5,2500);
			iPos = temp.Find("<td ");
			temp = temp.Mid(iPos+5,2500);
			iPos = temp.Find("<td ");
			temp = temp.Mid(iPos+5,2500);
			/*
			iPos = temp.Find("<td ");
			temp = temp.Mid(iPos+5,2500);
			*/
			iPos = temp.Find(">");
			temp = temp.Mid(iPos,2500);
			
			iPos = temp.Find("</td>");
			m_ListCtrl.SetItemText(curline, 13+i,temp.Mid(1,iPos-1));
			
			if (temp.Mid(1,iPos-1) > 75)
			{
				ret = "1";
			}

			//AfxMessageBox(temp);
		}
	}

	return	ret;
}

//////////////////////////////////////////////////////////////////////////
// ret :
//		0:ok
//		1:stop
//////////////////////////////////////////////////////////////////////////
int CNetworksDlg::LkMachine_GetStatus(CString iDestAddr,int Output,int line)
{
	int ret = 0;
	//CString coinType;
	//pDlg->m_coinType.GetWindowText(coinType);
	int coinType = pDlg->m_coinType.GetCurSel();

	switch (Output)
	{
		// machine have no ip
	case 0:
		{
			m_ListCtrl.AddItem(iDestAddr, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"),  \
				_T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
		}
		break;

		// machine start
	case 1:
		{
			//BOOL	TrunRed = FALSE;
			CString strHtmlData, iTmp, strUrl;
			
			strUrl = "http://"+iDestAddr+"/miner.php";
			
			TCHAR	ch;
			char *pstrURL = (char*)LPCTSTR(strUrl);
			
			CInternetSession m_session;
			CHttpFile *pFile = (CHttpFile *) m_session.OpenURL(pstrURL, 1, 
				INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
			
			while (pFile->Read(&ch, sizeof(TCHAR)))
			{
				strHtmlData += ch;
			}		
			CString strHtml = strHtmlData;
			//////////////////////抓取BA 值 begin///////////////////////////////
			CString	BA1 = FindBA(&strHtmlData);
			strHtmlData = strHtmlData.Mid(3,strHtmlData.GetLength());

			CString BA2 = FindBA(&strHtmlData);
			strHtmlData = strHtmlData.Mid(3,strHtmlData.GetLength());
	
			CString BA3 = FindBA(&strHtmlData);
			strHtmlData = strHtmlData.Mid(3,strHtmlData.GetLength());

			CString BA4 = FindBA(&strHtmlData);
			strHtmlData = strHtmlData.Mid(3,strHtmlData.GetLength());
            
			CString SUM = FindSummary(&strHtmlData);
			strHtmlData = strHtml.Mid(3,strHtml.GetLength());
			/////////////////////////抓取BA值end//////////////////////////////////////

			/////////////////////////抓取pool 值begin///////////////////////////////
			//CString Pool1Status = FindPoolStatus(&strHtmlData,line);
			CString tempPool;
			CString PoolAUrl,PoolAStatus;
			CString PoolBUrl,PoolBStatus;
			CString PoolCUrl,PoolCStatus;
			int iPos = strHtmlData.Find("Stratum URL");
			//int strLength = strHtmlData.GetLength();
			CString	temp = strHtmlData.Mid(iPos,2500);
			strHtmlData = strHtmlData.Mid(iPos+10,strHtmlData.GetLength());
			
			{
	// Get the pool0 status
				iPos = temp.Find("<td ");
				temp = temp.Mid(iPos+5,2500);
				iPos = temp.Find("<td ");
				temp = temp.Mid(iPos+5,2500);
				iPos = temp.Find("<td ");
				temp = temp.Mid(iPos+5,2500);
				iPos = temp.Find("<td ");
				temp = temp.Mid(iPos+5,2500);		
				iPos = temp.Find("<td ");
				temp = temp.Mid(iPos+5,2500);
				iPos = temp.Find("<td ");
				temp = temp.Mid(iPos+5,2500);


				iPos = temp.Find(">");
				temp = temp.Mid(iPos,2500);
				
				iPos = temp.Find("</td>");
				PoolAUrl = temp.Mid(1,iPos-1);

				//m_ListCtrl.SetItemText(line, 6,PoolAUrl);


				iPos = temp.Find("<td ");
				temp = temp.Mid(iPos+5,2500);


				iPos = temp.Find(">");
				temp = temp.Mid(iPos,2500);
				
				iPos = temp.Find("</td>");
				PoolAStatus = temp.Mid(1,iPos-1);
				for (int i =0;i<12;i++)
				{
					iPos = temp.Find("<td ");
					temp = temp.Mid(iPos+5,2500);
				}

				iPos = temp.Find(">");
				temp = temp.Mid(iPos,2500);
				
				iPos = temp.Find("</td>");
				PoolAUrl = temp.Mid(1,iPos-1);
				//m_ListCtrl.SetItemText(curline, 7,PoolAStatus);

				// Get the pool1 status
				for (i=0;i<17;i++)
				{
					iPos = temp.Find("<td ");
					temp = temp.Mid(iPos+5,2500);
				}

				iPos = temp.Find(">");
				temp = temp.Mid(iPos,2500);
				
				iPos = temp.Find("</td>");
				PoolBUrl = temp.Mid(1,iPos-1);
				
				//m_ListCtrl.SetItemText(curline, 8,PoolBUrl);

				iPos = temp.Find("<td ");
				temp = temp.Mid(iPos+5,2500);

				iPos = temp.Find(">");
				temp = temp.Mid(iPos,2500);
				
				iPos = temp.Find("</td>");
				PoolBStatus = temp.Mid(1,iPos-1);
				for (i =0;i<12;i++)
				{
					iPos = temp.Find("<td ");
					temp = temp.Mid(iPos+5,2500);
				}
				
				iPos = temp.Find(">");
				temp = temp.Mid(iPos,2500);
				
				iPos = temp.Find("</td>");
				PoolBUrl = temp.Mid(1,iPos-1);
				//m_ListCtrl.SetItemText(curline, 9,PoolBStatus);

				// Get the pool2 status
				for (i=0;i<17;i++)
				{
					iPos = temp.Find("<td ");
					temp = temp.Mid(iPos+5,2500);
				}
				
				iPos = temp.Find(">");
				temp = temp.Mid(iPos,2500);
				
				iPos = temp.Find("</td>");
				PoolCUrl = temp.Mid(1,iPos-1);
				
				//m_ListCtrl.SetItemText(curline, 10,PoolCUrl);
				
				iPos = temp.Find("<td ");
				temp = temp.Mid(iPos+5,2500);
				
				iPos = temp.Find(">");
				temp = temp.Mid(iPos,2500);
				
				iPos = temp.Find("</td>");
				PoolCStatus = temp.Mid(1,iPos-1);
				for (i =0;i<12;i++)
				{
					iPos = temp.Find("<td ");
					temp = temp.Mid(iPos+5,2500);
				}
				
				iPos = temp.Find(">");
				temp = temp.Mid(iPos,2500);
				
				iPos = temp.Find("</td>");
				PoolCUrl = temp.Mid(1,iPos-1);

			}	
				//m_ListCtrl.SetItemText(curline, 11,PoolCStatus);
			////////////////////////抓取pool 值end//////////////////////////////

			
			////////////////////////抓取温度、运行时间////////////////////////
			
			strUrl = "http://"+iDestAddr+"/miner.php?ref=0&pg=Stats";
			pstrURL = (char*)LPCTSTR(strUrl);
			pFile = (CHttpFile *) m_session.OpenURL(pstrURL, 1, 
				INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
			
			while (pFile->Read(&ch, sizeof(TCHAR)))
			{
				strHtmlData += ch;
			}		
			
			//m_ListCtrl.SetItemText(line, 12,FindRunTime(&strHtmlData,line));
			CString runTime = FindRunTime(&strHtmlData,line);
		
			/////////////////////////////温度
			//CString findtemp = FindTemp(strHtmlData,line);
			int		iPosTemp;
			CString strFind[]={"BA10","BA11","BA12","BA13"};
			CString	iTemp = strHtmlData;
			CString strTemp[4]={"","","",""};
			
			for (int i = 0;i < 4;i++)
			{
				iPosTemp = strHtmlData.Find(strFind[i]);
				if (iPosTemp == -1)
				{
					strTemp[i] = "0";
				} 
				else
				{
					iTemp = strHtmlData.Mid(iPosTemp,2500);
					{
						iPosTemp = iTemp.Find("<td ");
						iTemp = iTemp.Mid(iPosTemp+5,2500);
						iPosTemp = iTemp.Find("<td ");
						iTemp = iTemp.Mid(iPosTemp+5,2500);
						iPosTemp = iTemp.Find("<td ");
						iTemp = iTemp.Mid(iPosTemp+5,2500);
						/*
						iPos = temp.Find("<td ");
						temp = temp.Mid(iPos+5,2500);
						*/
						iPosTemp = iTemp.Find(">");
						iTemp = iTemp.Mid(iPosTemp,2500);
						
						iPosTemp = iTemp.Find("</td>");
						//m_ListCtrl.SetItemText(curline, 13+i,temp.Mid(1,iPos-1));
						strTemp[i]=iTemp.Mid(1,iPosTemp-1);
						
					}
				}

			}


			if (atoi(BA1) == 0 && atoi(BA2) ==0 && atoi(BA3) ==0 && atoi(BA4) ==0)
			{
				m_ListCtrl.AddItem(iDestAddr, "0", "0", "0", "0", "0", "0","0",  \
				"0","0", "0","0", "0", "0", "0","0","0");
				for (int k=0;k<17;k++)
				{
					m_ListCtrl.SetItemColor(m_line, k, RGB(255,0,0), RGB(255,255,255));	
				}
			}
			else
			{
				m_ListCtrl.AddItem(iDestAddr, BA1, BA2, BA3, BA4, SUM, PoolAUrl,PoolAStatus,  \
				PoolBUrl,PoolBStatus, PoolCUrl,PoolCStatus, runTime, strTemp[0], strTemp[1],strTemp[2],strTemp[3]);
				
				if (coinType == 0)
				{
					if (atoi(BA1) < 240 || atoi(BA1) > 270)	
						m_ListCtrl.SetItemColor(m_line, 1, RGB(255,0,0), RGB(255,255,255));
					if (atoi(BA2) < 240 || atoi(BA2) > 270)	
						m_ListCtrl.SetItemColor(m_line, 2, RGB(255,0,0), RGB(255,255,255));
					if (atoi(BA3) < 240 || atoi(BA3) > 270)	
						m_ListCtrl.SetItemColor(m_line, 3, RGB(255,0,0), RGB(255,255,255));
					if (atoi(BA4) < 240 || atoi(BA4) > 270)	
						m_ListCtrl.SetItemColor(m_line, 4, RGB(255,0,0), RGB(255,255,255));	
					if (SUM == "0" || atoi(SUM) > 1100 || atoi(SUM) < 900)
						m_ListCtrl.SetItemColor(m_line, 5, RGB(255,0,0), RGB(255,255,255));
				}
				else if (coinType == 3)
				{
					if (atoi(BA1) < 12 || atoi(BA1) > 15)	
						m_ListCtrl.SetItemColor(m_line, 1, RGB(255,0,0), RGB(255,255,255));
					if (atoi(BA2) < 12 || atoi(BA2) > 15)	
						m_ListCtrl.SetItemColor(m_line, 2, RGB(255,0,0), RGB(255,255,255));
					if (atoi(BA3) < 12 || atoi(BA3) > 15)	
						m_ListCtrl.SetItemColor(m_line, 3, RGB(255,0,0), RGB(255,255,255));
					if (atoi(BA4) < 12 || atoi(BA4) > 15270)	
						m_ListCtrl.SetItemColor(m_line, 4, RGB(255,0,0), RGB(255,255,255));	
					if (SUM == "0" || atoi(SUM) > 60 || atoi(SUM) < 50)
						m_ListCtrl.SetItemColor(m_line, 5, RGB(255,0,0), RGB(255,255,255));
				}

				
				CString strUrl1, strUrl2, strUrl3;
				pDlg->m_UsernameEdit1.GetWindowText(strUrl1);
				pDlg->m_UsernameEdit2.GetWindowText(strUrl2);
				pDlg->m_UsernameEdit3.GetWindowText(strUrl3);

				if (m_user_check1.GetCheck() == BST_CHECKED)
				{
					if (PoolAUrl != strUrl1)
						m_ListCtrl.SetItemColor(m_line, 6, RGB(255,0,0), RGB(255,255,255));
				}
				else
				{
					strUrl1+=iDestAddr.Mid(iDestAddr.ReverseFind('.'),iDestAddr.GetLength());
					if (coinType == 0 || coinType == 1)
						strUrl1 += "b";
					else if (coinType == 2 || coinType == 3)
						strUrl1 += "l";
					if (PoolAUrl != strUrl1)
						m_ListCtrl.SetItemColor(m_line, 6, RGB(255,0,0), RGB(255,255,255));
				}
				
				if (m_user_check2.GetCheck() == BST_CHECKED)
				{
					if (PoolBUrl != strUrl2)
						m_ListCtrl.SetItemColor(m_line, 8, RGB(255,0,0), RGB(255,255,255));
				}
				else
				{
					strUrl2+=iDestAddr.Mid(iDestAddr.ReverseFind('.'),iDestAddr.GetLength());
					if (coinType == 0 || coinType == 1)
						strUrl2 += "b";
					else if (coinType == 2 || coinType == 3)
						strUrl2 += "l";
					if (PoolBUrl != strUrl2)
						m_ListCtrl.SetItemColor(m_line, 8, RGB(255,0,0), RGB(255,255,255));
				}

				if (m_user_check3.GetCheck() == BST_CHECKED)
				{
					if (PoolCUrl != strUrl3)
						m_ListCtrl.SetItemColor(m_line, 10, RGB(255,0,0), RGB(255,255,255));
				}
				else
				{
					strUrl3+=iDestAddr.Mid(iDestAddr.ReverseFind('.'),iDestAddr.GetLength());
					if (coinType == 0 || coinType == 1)
						strUrl3 += "b";
					else if (coinType == 2 || coinType == 3)
						strUrl3 += "l";
					if (PoolCUrl != strUrl3)
						m_ListCtrl.SetItemColor(m_line, 10, RGB(255,0,0), RGB(255,255,255));
				}

				//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage(PoolAUrl + " " + PoolBUrl + " " + PoolCUrl);
				
	
				if (PoolAStatus != "Alive")
					m_ListCtrl.SetItemColor(m_line, 7, RGB(255,0,0), RGB(255,255,255));
				if (PoolBStatus != "Alive")
					m_ListCtrl.SetItemColor(m_line, 9, RGB(255,0,0), RGB(255,255,255));
				if (PoolCStatus != "Alive")
					m_ListCtrl.SetItemColor(m_line, 11, RGB(255,0,0), RGB(255,255,255));
				
				
				if (strTemp[0] > 70 || strTemp[0] == "0")
					m_ListCtrl.SetItemColor(m_line, 13, RGB(255,0,0), RGB(255,255,255));
				if (strTemp[1] > 70 || strTemp[1] == "0")
					m_ListCtrl.SetItemColor(m_line, 14, RGB(255,0,0), RGB(255,255,255));
				if (strTemp[2] > 70 || strTemp[2] == "0")
					m_ListCtrl.SetItemColor(m_line, 15, RGB(255,0,0), RGB(255,255,255));
				if (strTemp[3] > 70 || strTemp[3] == "0")
					m_ListCtrl.SetItemColor(m_line, 16, RGB(255,0,0), RGB(255,255,255));
			}	
		//m_line++;
		}
		break;
	case 2:
		{
			CString strHtmlData, iTmp, strUrl;
			
			strUrl = "http://"+iDestAddr;
			
			((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("strUrl:"+strUrl);
			
			TCHAR ch;
			char *pstrURL = (char*)LPCTSTR(strUrl);
			
			CInternetSession m_session;
			CHttpFile *pFile = (CHttpFile *) m_session.OpenURL(pstrURL, 1, 
				INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
			
			while (pFile->Read(&ch, sizeof(TCHAR)))
			{
				strHtmlData += ch;
			}	

			int iPos = strHtmlData.Find("value=\"start\"");
			CString	temp = _T(strHtmlData.Mid(iPos,50));
			
			iPos = temp.Find("checked");
			if(iPos == -1)
			{
				iPos = strHtmlData.Find("value=\"stop\"");
				temp = _T(strHtmlData.Mid(iPos,50));

				iPos = temp.Find("checked");
				if (iPos == -1)
				{
					ret = 1;
				} 
				else
				{
					ret = 0;
				}
			}
			else
			{
				ret = 1;
			}
			
			//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage(strHtmlData);
		}
		break;
	case 3:
		{
			m_ListCtrl.AddItem(iDestAddr, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"),  \
				_T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
		}
		break;
	default :
		{

		}
	}
	return ret;
}

/////////////////修改单条记录线程
UINT CNetworksDlg::ModifyOnerecordThread(LPVOID param)
{
	// TODO: Add your control notification handler code here
	//把选择的那一列放入编辑框中
	//当前选中项的索引
	int listIndex;  
	CString command;
	
	//首先得到点击的位置 
	POSITION pos=pDlg->m_ListCtrl.GetFirstSelectedItemPosition(); 
	
	//加入没有选择则返回
	if(pos==NULL) 
		return -1; 
	
	//得索引，通过POSITION转化 
	listIndex=(int)pDlg->m_ListCtrl.GetNextSelectedItem(pos); 

	//得到选中项的内容（0表示第一列，同理1,2,3...表示第二，三，四...列）
	CString strIP=pDlg->m_ListCtrl.GetItemText(listIndex,0);
	int idx =strIP.ReverseFind('.');

	if (EngOrCn == 2)
		pDlg->m_Single.SetWindowText("正在修改IP:" + strIP);
	if (EngOrCn == 1)
		pDlg->m_Single.SetWindowText("Being modified" + strIP);
    //pDlg->m_ListCtrl.SetItemColor(0, RGB(255,0,0));
	
	//分币种
	//CString coinType;
	//pDlg->m_coinType.GetWindowText(coinType);
	int coinType = pDlg->m_coinType.GetCurSel();

	CString url1, url2, url3;
	pDlg->m_PoolUrlEdit1.GetWindowText(url1);	
	pDlg->m_PoolUrlEdit2.GetWindowText(url2);
	pDlg->m_PoolUrlEdit3.GetWindowText(url3);
	if (url1 == "")
		url1 = "/";
	
	if (url2 == "")
		url2 = "/";
	
	if (url3 == "")
		url3 = "/";
	
	CString user1, user2, user3;
	pDlg->m_UsernameEdit1.GetWindowText(user1);
	if (BST_CHECKED == pDlg->m_user_check1.GetCheck())
	{
	}
	else
	{
		user1 += strIP.Mid(idx,strIP.GetLength());
		if (coinType == 0 || coinType == 1)
			user1 += "b";
		else if (coinType == 2 || coinType == 3)
				user1 += "l";
	}

	pDlg->m_UsernameEdit2.GetWindowText(user2);
	if (BST_CHECKED == pDlg->m_user_check2.GetCheck())
	{
	}
	else
	{
		user2 += strIP.Mid(idx,strIP.GetLength());
		if (coinType == 0 || coinType == 1)
			user2 += "b";
		else if (coinType == 2 || coinType == 3)
				user2 += "l";
	}
	
	pDlg->m_UsernameEdit3.GetWindowText(user3);
	if (BST_CHECKED == pDlg->m_user_check3.GetCheck())
	{
	}
	else
	{
		user3 += strIP.Mid(idx,strIP.GetLength());
		if (coinType == 0 || coinType == 1)
			user3 += "b";
		else if (coinType == 2 || coinType == 3)
				user3 += "l";
	}

	CString passwd1, passwd2, passwd3;
	pDlg->m_PasswordEdit1.GetWindowText(passwd1);		
	pDlg->m_PasswordEdit2.GetWindowText(passwd2);		
	pDlg->m_PasswordEdit3.GetWindowText(passwd3);

	CString diff, strHTML;
	pDlg->m_ComboBox_diff.GetWindowText(diff);
	CString diff_num;
	diff_num.Format("%d", pDlg->m_ComboBox_diff.GetCurSel() + 1);
	CString ifre;
	pDlg->m_combo_fre.GetWindowText(ifre);
	int iResult = pDlg->MachineType(strIP, &strHTML);
	
	command = "echo ''> /var/config/user.log\r\necho "+url1+" > /var/config/user.log\r\n";
	command += "echo "+user1+" >>/var/config/user.log\r\n";
	command += "echo "+passwd1+" >>/var/config/user.log\r\n";
	command += "echo "+url2+" >> /var/config/user.log\r\n";
	command += "echo "+user2+" >>/var/config/user.log\r\n";
	command += "echo "+passwd2+" >>/var/config/user.log\r\n";
	command += "echo "+url3+" >> /var/config/user.log\r\n";
	command += "echo "+user3+" >>/var/config/user.log\r\n";
	command += "echo "+passwd3+" >>/var/config/user.log\r\n";
	command += "echo 1 >>/var/config/user.log\r\n";
	command += "sudo pkill cgminer\r\n";
	CString cgminer;
	if (iResult == 1)
	{
		cgminer = "sudo /var/config/cgminer -o "+url1+" -u "+user1+" -p "+passwd1+" -o "+url2+" -u "+user2+" -p "+passwd2+" -o "+url3+" -u "+user3+" -p "+passwd3+"  --A1Pll1 1000 --A1Pll2 1000 --A1Pll3 1000 --A1Pll4 1000 --A1Pll5 1000 --api-listen --cs 8 --stmcu 0 -T --diff "+diff_num+" > /var/www/cgminer.log&\r\n";
		command +=cgminer;
		command += "echo "+diff_num+" > /var/config/diff\r\n";
		command += "echo '#!/bin/bash' > /var/config/run.sh\r\necho 'sudo chmod 777 /var/www/cgminer.log' >> /var/config/run.sh\r\necho '"+cgminer+"' >> /var/config/run.sh\r\n";
		
		pDlg->sshSrv(command, strIP, 22);
		pDlg->m_ListBox.InsertString(0, "ssh " + strIP + " success,modify cgminer configurate over");
		pDlg->m_ListCtrl.AddItem(strIP, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("wait..."), _T("0"), _T("wait..."),  \
			_T("0"), _T("wait..."), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
	}
	else if(iResult == 3)
	{
		cgminer = "sudo /var/config/cgminer -o "+url1+" -u "+user1+" -p "+passwd1+" -o "+url2+" -u "+user2+" -p "+passwd2+" -o "+url3+" -u "+user3+" -p "+passwd3+"  --A1Pll1 "+ifre+" --A1Pll2 "+ifre+" --A1Pll3 "+ifre+" --A1Pll4 "+ifre+" --A1Pll5 "+ifre+" --api-listen --cs 8 --stmcu 0 -T --diff "+diff_num+" --no-submit-stale --lowmem> /var/www/cgminer.log&\r\n";
		command +=cgminer;
		command += "echo "+ifre+" > /var/config/sysclock\r\n";
		command += "echo "+diff_num+" > /var/config/diff\r\n";
		command += "echo '#!/bin/bash' > /var/config/run.sh\r\necho 'sudo chmod 777 /var/www/cgminer.log' >> /var/config/run.sh\r\necho '"+cgminer+"' >> /var/config/run.sh\r\n";
		
		pDlg->sshSrv(command, strIP, 22);
		pDlg->m_ListBox.InsertString(0, "ssh " + strIP + " success,modify cgminer configurate over");
		pDlg->m_ListCtrl.AddItem(strIP, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("wait..."), _T("0"), _T("wait..."),  \
			_T("0"), _T("wait..."), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
	}
	else if(iResult == 2)
	{
		cgminer = "sudo /var/config/cgminer -o "+url1+" -u "+user1+" -p "+passwd1+" -o "+url2+" -u "+user2+" -p "+passwd2+" -o "+url3+" -u "+user3+" -p "+passwd3+"  --chips 36  --fixdiff "+diff+" --clock "+ifre+" -S /dev/ttyUSB3 -S /dev/ttyUSB2 -S /dev/ttyUSB1 -S /dev/ttyUSB0   --api-listen --quiet > /var/www/cgminer.log&\r\n";
		command +=cgminer;
		command += "echo "+ifre+" > /var/config/sysclk\r\n";
		command += "echo "+diff+" > /var/config/diff\r\n";
		command += "echo '#!/bin/bash' > /var/config/run.sh\r\necho 'sudo chmod 777 /var/www/cgminer.log' >> /var/config/run.sh\r\necho '"+cgminer+"' >> /var/config/run.sh\r\n";
		
		pDlg->sshSrv(command, strIP, 22);
		pDlg->m_ListBox.InsertString(0, "ssh " + strIP + " success,modify cgminer configurate over");
		pDlg->m_ListCtrl.AddItem(strIP, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("wait..."), _T("0"), _T("wait..."),  \
			_T("0"), _T("wait..."), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
	}
	else if(iResult == -1)
	{
		pDlg->m_ListCtrl.AddItem(strIP, _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("unknown type"), _T("0"), _T("unknown type"),  \
			_T("0"), _T("unknown type"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"), _T("0"));
	}
	
	if (EngOrCn == 2)
		pDlg->m_Single.SetWindowText("修改完毕");
	if (EngOrCn == 1)
		pDlg->m_Single.SetWindowText("Modification is completed");
	return 0;
}

UINT CNetworksDlg::SingleRebootThread(LPVOID param)
{
	//把选择的那一列放入编辑框中
	//当前选中项的索引
	int listIndex;  
	CString command;
	POSITION pos;
	
	int tab = pDlg->m_MainTab.GetCurSel();
	if (tab == 0)
	{
	//首先得到点击的位置 
		pos=pDlg->m_BTC1T.m_List_BTC1T.GetFirstSelectedItemPosition();
		if(pos==NULL) 
			return -1; 
		
		//得索引，通过POSITION转化 
		listIndex=(int)pDlg->m_BTC1T.m_List_BTC1T.GetNextSelectedItem(pos); 
		
		//得到选中项的内容（0表示第一列，同理1,2,3...表示第二，三，四...列）
		CString strIP=pDlg->m_BTC1T.m_List_BTC1T.GetItemText(listIndex,0);
		
		command = "sudo reboot\r\n";
		//command = "sudo pkill cgminer\r\n";
		//command +="cd /var/config\r\n";
		//command += "sudo ./run.sh\r\n";
		pDlg->sshSrv(command, strIP, 22);
		pDlg->m_ListBox.InsertString(0, "reboot "+strIP);
	}
	else if (tab == 1)
	{
		pos=pDlg->m_LTC30M.m_List_LTC30M.GetFirstSelectedItemPosition();
		if(pos==NULL) 
			return -1; 
		
		//得索引，通过POSITION转化 
		listIndex=(int)pDlg->m_LTC30M.m_List_LTC30M.GetNextSelectedItem(pos); 
		
		//得到选中项的内容（0表示第一列，同理1,2,3...表示第二，三，四...列）
		CString strIP=pDlg->m_LTC30M.m_List_LTC30M.GetItemText(listIndex,0);
		command = "sudo reboot\r\n";
		//command = "sudo pkill cgminer\r\n";
		//command +="cd /var/config\r\n";
		//command += "sudo ./run.sh\r\n";
		pDlg->sshSrv(command, strIP, 22);
		pDlg->m_ListBox.InsertString(0, "reboot "+strIP);
	}
	else if (tab == 2)
	{
		pos=pDlg->m_LTC60M.m_List_LTC60M.GetFirstSelectedItemPosition();
		if(pos==NULL) 
			return -1; 
		
		//得索引，通过POSITION转化 
		listIndex=(int)pDlg->m_LTC60M.m_List_LTC60M.GetNextSelectedItem(pos); 
		
		//得到选中项的内容（0表示第一列，同理1,2,3...表示第二，三，四...列）
		CString strIP=pDlg->m_LTC60M.m_List_LTC60M.GetItemText(listIndex,0);
		command = "sudo reboot\r\n";
		//command = "sudo pkill cgminer\r\n";
		//command +="cd /var/config\r\n";
		//command += "sudo ./run.sh\r\n";
		pDlg->sshSrv(command, strIP, 22);
		pDlg->m_ListBox.InsertString(0, "reboot "+strIP);
	}
	else if (tab == 3)
	{
		pos=pDlg->m_UnknowType.m_List_UnknowType.GetFirstSelectedItemPosition();
		if(pos==NULL) 
			return -1; 
		
		//得索引，通过POSITION转化 
		listIndex=(int)pDlg->m_UnknowType.m_List_UnknowType.GetNextSelectedItem(pos); 
		
		//得到选中项的内容（0表示第一列，同理1,2,3...表示第二，三，四...列）
		CString strIP=pDlg->m_UnknowType.m_List_UnknowType.GetItemText(listIndex,0);
		command = "sudo reboot\r\n";
		//command = "sudo pkill cgminer\r\n";
		//command +="cd /var/config\r\n";
		//command += "sudo ./run.sh\r\n";
		pDlg->sshSrv(command, strIP, 22);
		pDlg->m_ListBox.InsertString(0, "reboot "+strIP);
	}

	return 0;
}

UINT CNetworksDlg::MultiRebootThread(LPVOID param)
{
	CString command, strIP;

	command = "sudo pkill cgminer\r\n";
	command +="cd /var/config\r\n";
	command += "sudo ./run.sh\r\n";
	
	int tab = pDlg->m_MainTab.GetCurSel();
	if (tab == 0)
	{
		for (int i =0 ; i< (pDlg->m_BTC1T.m_List_BTC1T.GetItemCount()); i++)
		{
			strIP = pDlg->m_BTC1T.m_List_BTC1T.GetItemText(i, 0);
			
			pDlg->sshSrv(command, strIP, 22);
			pDlg->m_ListBox.InsertString(0, "reboot "+strIP);
		}
	}
	else if (tab == 1)
	{
		for (int i =0 ; i< (pDlg->m_LTC60M.m_List_LTC60M.GetItemCount()); i++)
		{
			strIP = pDlg->m_LTC60M.m_List_LTC60M.GetItemText(i, 0);
			
			pDlg->sshSrv(command, strIP, 22);
			pDlg->m_ListBox.InsertString(0, "reboot "+strIP);
		}
	}
	else if (tab == 2)
	{
		for (int i =0 ; i< (pDlg->m_LTC30M.m_List_LTC30M.GetItemCount()); i++)
		{
			strIP = pDlg->m_LTC30M.m_List_LTC30M.GetItemText(i, 0);
			
			pDlg->sshSrv(command, strIP, 22);
			pDlg->m_ListBox.InsertString(0, "reboot "+strIP);
		}
	}
	else if (tab == 3)
	{
		for (int i =0 ; i< (pDlg->m_UnknowType.m_List_UnknowType.GetItemCount()); i++)
		{
			strIP = pDlg->m_UnknowType.m_List_UnknowType.GetItemText(i, 0);
			
			pDlg->sshSrv(command, strIP, 22);
			pDlg->m_ListBox.InsertString(0, "reboot "+strIP);
		}
	}

	pDlg->GetDlgItem(IDC_REFRESH)->EnableWindow(TRUE);
	pDlg->GetDlgItem(IDC_SINGLE_REBOOT)->EnableWindow(TRUE);
	if (((CNetworksApp*)AfxGetApp())->isAdmin == FALSE)
	{
		pDlg->GetDlgItem(IDC_BUTTON_REFRESH)->EnableWindow(FALSE);
		pDlg->GetDlgItem(IDC_SINGLE_UPDATE)->EnableWindow(FALSE);
	}else
	{
		pDlg->GetDlgItem(IDC_BUTTON_REFRESH)->EnableWindow(TRUE);
		pDlg->GetDlgItem(IDC_SINGLE_UPDATE)->EnableWindow(TRUE);
	}

	return 0;
}

void CNetworksDlg::OnRefresh() 
{
	// TODO: Add your control notification handler code here
	//从ip控件得到要查询的ip范围
	m_IPStart.GetAddress(B1[0],B1[1],B1[2],B1[3]);
	m_IPStop.GetAddress(B2[0],B2[1],B2[2],B2[3]);
	//判断ip范围是否合法
	if(B2[2]<B1[2])
	{	
		if (EngOrCn == 2)
			AfxMessageBox("终止地址应大于起始地址！");
		if (EngOrCn == 1)
			AfxMessageBox("The last IP must bigger than the first");
		return ;
	}
	else if(B2[2]==B1[2]&&B2[3]<B1[3])
	{
		if (EngOrCn == 2)
			AfxMessageBox("终止地址应大于起始地址！");
		if (EngOrCn == 1)
			AfxMessageBox("The last IP must bigger than the first");
		return ;
	}
	if(B2[0]!=B1[0]||B2[1]!=B1[1])
	{
		if (EngOrCn == 2)
			AfxMessageBox("");
		if (EngOrCn == 1)
			AfxMessageBox("Does not support A or B type of network");
			return ;
	}
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	if (EngOrCn == 2)
		m_SoftStatus.SetWindowText("正在刷新机器状态...");
	if (EngOrCn == 1)
		m_SoftStatus.SetWindowText("Scanning...");
	GetDlgItem(IDC_BUTTON_REFRESH)->EnableWindow(FALSE);
	GetDlgItem(IDC_REFRESH)->EnableWindow(FALSE);
	GetDlgItem(IDC_SINGLE_REBOOT)->EnableWindow(FALSE);
	GetDlgItem(IDC_MUTIPLE_REBOOT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SUSPEND)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(TRUE);

	pDlg->bRef = true;
	pDlg->m_line = 0;
	pDlg->m_BTC1T.m_line = 0;
	pDlg->m_LTC30M.m_line = 0;
	pDlg->m_LTC60M.m_line = 0;
	pDlg->m_UnknowType.m_line = 0;
	m_BTC1T.m_List_BTC1T.DeleteAllItems();
	m_LTC30M.m_List_LTC30M.DeleteAllItems(); 
	m_LTC60M.m_List_LTC60M.DeleteAllItems(); 
	m_UnknowType.m_List_UnknowType.DeleteAllItems(); 
	//删除配置文件,重新生成
	::DeleteFile("machine.cfg");

	m_thread = AfxBeginThread(NbtstatThread,(LPVOID)this,CREATE_NEW);
 	/*
	m_thread = AfxBeginThread(NbtstatThread,(LPVOID)this,CREATE_SUSPENDED);
	m_thread->m_bAutoDelete=FALSE;
	int suspendCnt=m_thread->ResumeThread();
	*/
	//	LkMachine_GetStatus("192.168.1.52",1);
	// 	CString strIP = "192.168.1.52";
	// 	int ret = LkMachine_GetStatus(strIP,2);
	// 	if (ret == 0)
	// 	{
	// 		ret = LkMachine_GetStatus(strIP,1);
	// 	} 
	// 	else
	// 	{
	// 		ret = LkMachine_GetStatus(strIP,3);
	// 	}
}

void CNetworksDlg::OnSingleUpdate() 
{
	// TODO: Add your control notification handler code here
	AfxBeginThread(ModifyOnerecordThread,(LPVOID)this,CREATE_NEW);
	WriteINI();
}

void CNetworksDlg::OnSingleReboot() 
{
	// TODO: Add your control notification handler code here
	AfxBeginThread(SingleRebootThread,(LPVOID)this,CREATE_NEW);
}

void CNetworksDlg::OnMutipleReboot() 
{
	// TODO: Add your control notification handler code here
	AfxBeginThread(MultiRebootThread,(LPVOID)this,CREATE_NEW);
	GetDlgItem(IDC_BUTTON_REFRESH)->EnableWindow(FALSE);
	GetDlgItem(IDC_REFRESH)->EnableWindow(FALSE);
	GetDlgItem(IDC_SINGLE_REBOOT)->EnableWindow(FALSE);
	GetDlgItem(IDC_SINGLE_UPDATE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SUSPEND)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(TRUE);
}


void CNetworksDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	this->WriteINI();
	CLoginDialog *logindlg = (CLoginDialog *)this->GetParent();
	logindlg->DestroyWindow();
	CDialog::OnClose();
}

void CNetworksDlg::OnMenuitemEng() 
{
	// TODO: Add your command handler code here
	EngOrCn = ENG;
	GetDlgItem(IDC_STATIC_IP_RANGE)->SetWindowText("IP range:");
	GetDlgItem(IDC_STATIC_IP_BEGIN)->SetWindowText("First IP:");
	GetDlgItem(IDC_STATIC_IP_END)->SetWindowText("Last IP:");
	GetDlgItem(IDC_STATIC_URL_INFO)->SetWindowText("Pool URL information:");
	GetDlgItem(IDC_STATIC_URL1)->SetWindowText("Pool url1:");
	GetDlgItem(IDC_STATIC_URL2)->SetWindowText("Pool url2:");
	GetDlgItem(IDC_STATIC_URL3)->SetWindowText("Pool url3:");
	GetDlgItem(IDC_STATIC_USERNAME1)->SetWindowText("Username:");
	GetDlgItem(IDC_STATIC_USERNAME2)->SetWindowText("Username:");
	GetDlgItem(IDC_STATIC_USERNAME3)->SetWindowText("Username:");
	GetDlgItem(IDC_STATIC_PD1)->SetWindowText("Password:");
	GetDlgItem(IDC_STATIC_PD2)->SetWindowText("Password:");
	GetDlgItem(IDC_STATIC_PD3)->SetWindowText("Password:");
	GetDlgItem(IDC_CHECK1)->SetWindowText("Single user");
	GetDlgItem(IDC_CHECK2)->SetWindowText("Single user");
	GetDlgItem(IDC_CHECK3)->SetWindowText("Single user");
	GetDlgItem(IDC_STATIC_LISTBOX)->SetWindowText("Running Status:");
	GetDlgItem(IDC_STATIC_DIFF)->SetWindowText("Difficulty:");
	GetDlgItem(IDC_SINGLE_UPDATE)->SetWindowText("Single modify");
	GetDlgItem(IDC_STATIC_STATUS1)->SetWindowText("Status:");
	GetDlgItem(IDC_STATIC_STATUS2)->SetWindowText("Status:");
	GetDlgItem(IDC_STATIC_STATUS3)->SetWindowText("Status:");
	GetDlgItem(IDC_STATIC_SINGLE)->SetWindowText("Stop");
	GetDlgItem(IDC_STATIC_MULTI)->SetWindowText("Stop");
	GetDlgItem(IDC_SOFT_STATUS)->SetWindowText("Stop");
	GetDlgItem(IDC_SINGLE_REBOOT)->SetWindowText("Single Reboot");
	GetDlgItem(IDC_MUTIPLE_REBOOT)->SetWindowText("Multiple Reboot");
	GetDlgItem(IDC_BUTTON_REFRESH)->SetWindowText("Multiple modify");
	GetDlgItem(IDC_REFRESH)->SetWindowText("Scan");
	GetDlgItem(IDC_BUTTON_SUSPEND)->SetWindowText("Pause");
	GetDlgItem(IDC_BUTTON_STOP)->SetWindowText("Stop");
}

void CNetworksDlg::OnMenuitemCN() 
{
	// TODO: Add your command handler code here
	EngOrCn = CHN;
	GetDlgItem(IDC_STATIC_IP_RANGE)->SetWindowText("IP 范围:");
	GetDlgItem(IDC_STATIC_IP_BEGIN)->SetWindowText("开始 IP:");
	GetDlgItem(IDC_STATIC_IP_END)->SetWindowText("结束 IP:");
	GetDlgItem(IDC_STATIC_URL_INFO)->SetWindowText("矿池URL信息:");
	GetDlgItem(IDC_STATIC_URL1)->SetWindowText("矿池 URL 1:");
	GetDlgItem(IDC_STATIC_URL2)->SetWindowText("矿池 URL 2:");
	GetDlgItem(IDC_STATIC_URL3)->SetWindowText("矿池 URL 3:");
	GetDlgItem(IDC_STATIC_USERNAME1)->SetWindowText("用户名:");
	GetDlgItem(IDC_STATIC_USERNAME2)->SetWindowText("用户名:");
	GetDlgItem(IDC_STATIC_USERNAME3)->SetWindowText("用户名:");
	GetDlgItem(IDC_STATIC_PD1)->SetWindowText("密码");
	GetDlgItem(IDC_STATIC_PD2)->SetWindowText("密码:");
	GetDlgItem(IDC_STATIC_PD3)->SetWindowText("密码:");
	GetDlgItem(IDC_CHECK1)->SetWindowText("单用户");
	GetDlgItem(IDC_CHECK2)->SetWindowText("单用户");
	GetDlgItem(IDC_CHECK3)->SetWindowText("单用户");
	GetDlgItem(IDC_STATIC_LISTBOX)->SetWindowText("运行状态:");
	GetDlgItem(IDC_STATIC_DIFF)->SetWindowText("难度:");
	GetDlgItem(IDC_SINGLE_UPDATE)->SetWindowText("单机修改");
	GetDlgItem(IDC_STATIC_STATUS1)->SetWindowText("状态:");
	GetDlgItem(IDC_STATIC_STATUS2)->SetWindowText("状态:");
	GetDlgItem(IDC_STATIC_STATUS3)->SetWindowText("状态:");
	GetDlgItem(IDC_STATIC_SINGLE)->SetWindowText("未开始");
	GetDlgItem(IDC_STATIC_MULTI)->SetWindowText("未开始");
	GetDlgItem(IDC_SOFT_STATUS)->SetWindowText("未开始");
	GetDlgItem(IDC_SINGLE_REBOOT)->SetWindowText("单机重启");
	GetDlgItem(IDC_MUTIPLE_REBOOT)->SetWindowText("多机重启");
	GetDlgItem(IDC_BUTTON_REFRESH)->SetWindowText("多机修改");
	GetDlgItem(IDC_REFRESH)->SetWindowText("扫描");
	GetDlgItem(IDC_BUTTON_SUSPEND)->SetWindowText("暂停");
	GetDlgItem(IDC_BUTTON_STOP)->SetWindowText("停止");

}

void CNetworksDlg::WriteINI()
{
	CString	temp;

	m_poolInfo[0] = "POOLA";
	m_PoolUrlEdit1.GetWindowText(temp);
	m_IniFile.SetString(m_section,m_poolInfo[0],temp);

	m_poolInfo[1] = "USERA";
	m_UsernameEdit1.GetWindowText(temp);
	m_IniFile.SetString(m_section,m_poolInfo[1],temp);

	m_poolInfo[2] = "PASSA";
	m_PasswordEdit1.GetWindowText(temp);
	m_IniFile.SetString(m_section,m_poolInfo[2],temp);
	
	
	m_poolInfo[3] = "POOLB";
	m_PoolUrlEdit2.GetWindowText(temp);
	m_IniFile.SetString(m_section,m_poolInfo[3],temp);

	m_poolInfo[4] = "USERB";
	m_UsernameEdit2.GetWindowText(temp);
	m_IniFile.SetString(m_section,m_poolInfo[4],temp);

	m_poolInfo[5] = "PASSB";
	m_PasswordEdit2.GetWindowText(temp);
	m_IniFile.SetString(m_section,m_poolInfo[5],temp);
	
	m_poolInfo[6] = "POOLC";
	m_PoolUrlEdit3.GetWindowText(temp);
	m_IniFile.SetString(m_section,m_poolInfo[6],temp);

	m_poolInfo[7] = "USERC";
	m_UsernameEdit3.GetWindowText(temp);
	m_IniFile.SetString(m_section,m_poolInfo[7],temp);

	m_poolInfo[8] = "PASSC";
	m_PasswordEdit3.GetWindowText(temp);
	m_IniFile.SetString(m_section,m_poolInfo[8],temp);

	m_poolInfo[9] = "POOLAONLY";
	m_IniFile.SetInt(m_section,m_poolInfo[9],m_user_check1.GetCheck());
	m_poolInfo[10] = "POOLBONLY";
	m_IniFile.SetInt(m_section,m_poolInfo[10],m_user_check2.GetCheck());
	m_poolInfo[11] = "POOLCONLY";
	m_IniFile.SetInt(m_section,m_poolInfo[11],m_user_check3.GetCheck());
	m_poolInfo[12] = "DIFF";
	m_IniFile.SetInt(m_section,m_poolInfo[12],m_ComboBox_diff.GetCurSel());
}

void CNetworksDlg::OnButtonStop() 
{
	// TODO: Add your control notification handler code here
	if (m_thread == NULL)
		return;
	::PostThreadMessage(m_thread->m_nThreadID,WM_QUIT,0,0);
	GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SUSPEND)->EnableWindow(FALSE);
	GetDlgItem(IDC_SINGLE_UPDATE)->EnableWindow(TRUE);
	if (((CNetworksApp*)AfxGetApp())->isAdmin == FALSE)
	{
		GetDlgItem(IDC_BUTTON_REFRESH)->EnableWindow(FALSE);
		GetDlgItem(IDC_SINGLE_UPDATE)->EnableWindow(FALSE);
	}else
	{
		GetDlgItem(IDC_BUTTON_REFRESH)->EnableWindow(TRUE);
		GetDlgItem(IDC_SINGLE_UPDATE)->EnableWindow(TRUE);
	}
	GetDlgItem(IDC_REFRESH)->EnableWindow(TRUE);
	GetDlgItem(IDC_SINGLE_REBOOT)->EnableWindow(TRUE);
	GetDlgItem(IDC_MUTIPLE_REBOOT)->EnableWindow(TRUE);
	if (EngOrCn == 2)
	{
		GetDlgItem(IDC_SOFT_STATUS)->SetWindowText("未开始");
		GetDlgItem(IDC_STATIC_MULTI)->SetWindowText("未开始");
	}
	if (EngOrCn == 1)
	{
		GetDlgItem(IDC_SOFT_STATUS)->SetWindowText("stop");
		GetDlgItem(IDC_STATIC_MULTI)->SetWindowText("stop");
	}

	countMachine();
}

void CNetworksDlg::OnButtonSuspend() 
{
	// TODO: Add your control notification handler code here
	if (m_thread == NULL)
		return;
	
	if (suspend == 0)
	{
		m_thread->ResumeThread();
		suspend = 1;
		if (EngOrCn == 2)
			GetDlgItem(IDC_BUTTON_SUSPEND)->SetWindowText("暂停");
		if (EngOrCn == 1)
			GetDlgItem(IDC_BUTTON_SUSPEND)->SetWindowText("Pause");
	}
	else if (suspend == 1)
	{
		m_thread->SuspendThread();
		suspend = 0;
		if (EngOrCn == 2)
			GetDlgItem(IDC_BUTTON_SUSPEND)->SetWindowText("恢复");
		if (EngOrCn == 1)
			GetDlgItem(IDC_BUTTON_SUSPEND)->SetWindowText("Resume");
	}
	countMachine();
}

void CNetworksDlg::OnMenuitemModifyPassword() 
{
	// TODO: Add your command handler code here
	//CDialog* pDlg = new CDialog;
	//pDlg->Create(IDD_ADMIN_REGISTER,this); 
	//pDlg->ShowWindow(SW_SHOW); 
	//pDlg->CenterWindow();

	CModifyPassowrd *pDlg = new CModifyPassowrd;
	pDlg->DoModal();
}

void CNetworksDlg::OnDblclkListIpStatus(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int listIndex;  
	CString command;
	
	POSITION pos=pDlg->m_ListCtrl.GetFirstSelectedItemPosition(); 
	if(pos==NULL) 
		return; 
	
	listIndex=(int)pDlg->m_ListCtrl.GetNextSelectedItem(pos); 
	
	CString strIP=pDlg->m_ListCtrl.GetItemText(listIndex,0);

	char userName[MAX_PATH];
	CString sUsername;
	DWORD size=MAX_PATH;
	::GetUserName(userName,&size);
	sUsername.Format("%s",userName);
	
	CString url = "C:\\Users\\lenovo\\AppData\\Roaming\\360se6\\Application\\360se.exe";
	url.Replace("lenovo", sUsername);

	if (PathFileExists(url))
		ShellExecute(NULL,"open",url,strIP,"",SW_SHOWNORMAL);
	else
		ShellExecute(NULL,"open","IEXPLORE.EXE",strIP,"",SW_SHOWNORMAL);

	*pResult = 0;
}

void CNetworksDlg::OnSelchangeComboCoinType() 
{
	// TODO: Add your control notification handler code here
	CString strTemp;
	((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->ResetContent();//消除现有所有内容
	((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->ResetContent();
  
	if (m_coinType.GetCurSel() == 0 || m_coinType.GetCurSel() == 1 || m_coinType.GetCurSel() == 3)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("1");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("2");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("4");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("8");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("16");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("32");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("52");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("64");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("86");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("103");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("128");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("256");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("512");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("1024");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("2048");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("4096");

		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("1000");
		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("1080");
		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("1100");
		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("1200");
		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("1280");
		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("1300");
		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("1400");

		m_ComboBox_diff.SetCurSel(13);
		m_combo_fre.SetCurSel(3);
	}
	else if (m_coinType.GetCurSel() == 2)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("128");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("256");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("512");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("1024");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("2048");
		((CComboBox*)GetDlgItem(IDC_COMBO_DIFF))->AddString("4096");

		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("200");
		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("250");
		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("300");
		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("310");
		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("320");
		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("325");
		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("330");
		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("340");
		((CComboBox*)GetDlgItem(IDC_COMBO_FRE))->AddString("350");

		m_ComboBox_diff.SetCurSel(3);
		m_combo_fre.SetCurSel(5);
	}
}

/************************************************************************/
/* return type:
int ret:
ret =	1:BTC 1T
2:LTC 30M
3:LTC 60M

*/
/************************************************************************/
int CNetworksDlg::MachineType(CString ipAddr,CString *strHtmlData)
{
	int ret = 0;
	
	CString strUrl;
	
	strUrl = "http://"+ipAddr+"/miner.php";
	
	TCHAR	ch;
	char *pstrURL = (char*)LPCTSTR(strUrl);
	
	CInternetSession m_session;
	CHttpFile *pFile = NULL;
	//CHttpFile *pFile = (CHttpFile *) m_session.OpenURL(pstrURL, 1, 
	//	INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
	///////////////////////////////////////////
	try
	{
		pFile  = (CHttpFile *) m_session.OpenURL(pstrURL, 1, 
		INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
	
		//m_session.Close();
	}
	catch (CException* e)
	{
		//e->ReportError();
		e->Delete();
		return -1;
	}
	////////////////////////////////////////////
	m_ListBox.InsertString(0, "open url");
	while (pFile->Read(&ch, sizeof(TCHAR)))
	{
		*strHtmlData += ch;
	}		
	m_ListBox.InsertString(0, "read html data");
	//int iPos = (*strHtmlData).Find("BA1");
	int iPos = strHtmlData->Find("BA1");
	if (iPos < 0)
	{
		iPos = strHtmlData->Find("ICA");
		if (iPos < 0)
		{
			ret = -1;
		}
		else
		{
			ret = 2;
		}
	}
	else
	{
		iPos = strHtmlData->Find("SUMMARY");
		if (iPos < 0)
		{
			ret = -1;
		}
		else
		{
			CString	temp = strHtmlData->Mid(iPos,500);
			iPos = temp.Find("<td ");
			temp = temp.Mid(iPos+5,500);
			iPos = temp.Find("<td ");
			temp = temp.Mid(iPos+5,500);
			iPos = temp.Find(">");
			temp = temp.Mid(iPos,500);
			
			iPos = temp.Find("</td>");
			temp = temp.Mid(1,iPos-1);
		
			temp.Remove(',');
			temp.Format("%d",int(atoi(temp)+0.5));
			//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage(temp);
			if (atoi(temp) < 100)
			{
				ret = 3;
			}
			else
			{
				ret = 1;
			}
		}
	}
	
	return ret;
}

void CNetworksDlg::MultiLkMachine_GetStatus(CString iDestAddr, int ret, CString strHtmlData)
{
	int line = 1;
	int Output = 1;
	
	CString	tempHtml,temp;

	switch (ret)
	{
	//LTC 60M
	case 3:
		{
			CString BA1, BA2, BA3, BA4, SUM, poolUser1, pool1Status, poolUser2, pool2Status, poolUser3, pool3Status, RunTime;
			CString strTemp[4]={"","","",""};
			int iPos = strHtmlData.Find("BA1");
			if (iPos == -1)
			{
				break;
			}
			//int strLength = strHtmlData.GetLength();

			//first
			CString	tempHtml = strHtmlData.Mid(iPos,5000);
			{
				temp = tempHtml;
				for (int i = 0;i < 5; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				//temp.Remove(',');
				//temp.Format("%d",int(atoi(temp)/1000+0.5));
				BA1 = temp;
				
				// second
				for (i = 0;i < 23; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				BA2 = temp;
				// third
				for (i = 0;i < 23; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				BA3 = temp;
				// forth
				for (i = 0;i < 23; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				BA4 = temp;

				// summary
				iPos = strHtmlData.Find("SUMMARY");
				if (iPos < 0)
				{
					ret = -1;
				}
				else
				{
					tempHtml = strHtmlData.Mid(iPos,500);
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,500);
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,500);
					iPos = tempHtml.Find(">");
					tempHtml = tempHtml.Mid(iPos,500);
					
					iPos = tempHtml.Find("</td>");
					temp = tempHtml.Mid(1,iPos-1);
					//temp.Remove(',');
					//temp.Format("%d",int(atoi(temp)/1000+0.5));
				}
				SUM = temp;
				// pool-user1
				iPos = strHtmlData.Find("Stratum URL");
				tempHtml = strHtmlData.Mid(iPos,5000);
				for (i = 0;i < 7; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				pool1Status = temp;
				
				for (i = 0;i < 12; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				poolUser1 = temp;
				// pool-user2
				
				for (i = 0;i < 18; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				pool2Status = temp;
				
				for (i = 0;i < 12; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				poolUser2 = temp;
				// pool-user3
				for (i = 0;i < 18; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				pool3Status = temp;
				
				for (i = 0;i < 12; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				poolUser3 = temp;
				// run time
				CString strUrl = "http://"+iDestAddr+"/miner.php?ref=0&pg=Stats";
				TCHAR	ch;
				char *pstrURL = (char*)LPCTSTR(strUrl);
				CInternetSession m_session;
				strHtmlData = "";
				pstrURL = (char*)LPCTSTR(strUrl);
				CHttpFile *pFile;

				//CHttpFile *pFile  = (CHttpFile *) m_session.OpenURL(pstrURL, 1, 
				//	INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
				///////////////////////////////////////////
				try
				{
					pFile  = (CHttpFile *) m_session.OpenURL(pstrURL, 1, 
					INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
				
					//m_session.Close();
				}
				catch (CException* e)
				{
					//e->ReportError();
					e->Delete();
					goto OUTP;
				}
				////////////////////////////////////////////
				while (pFile->Read(&ch, sizeof(TCHAR)))
				{
					strHtmlData += ch;
				}	
				
				iPos = strHtmlData.Find("Work Utility");
				//int strLength = strHtmlData.GetLength();
				tempHtml = strHtmlData.Mid(iPos,500);
				
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,500);
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,500);
					
					iPos = tempHtml.Find(">");
					tempHtml = tempHtml.Mid(iPos,500);
					
					iPos = tempHtml.Find("</td>");
					RunTime = tempHtml.Mid(1,iPos-1);
					RunTime.Replace("&nbsp;","");
					//AfxMessageBox(RunTime);
				}

				int		iPosTemp;
				CString strFind[]={"BA10","BA11","BA12","BA13"};
				CString	iTemp = strHtmlData;
				
				for (i = 0;i < 4;i++)
				{
					iPosTemp = strHtmlData.Find(strFind[i]);
					if (iPosTemp == -1)
					{
						strTemp[i] = "0";
					} 
					else
					{
						iTemp = strHtmlData.Mid(iPosTemp,2500);
						{
							if (ret == 1)
							{
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
							} 
							else if (ret == 3)
							{
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
							}
							else
							{
								;
							}
							/*
							iPos = temp.Find("<td ");
							temp = temp.Mid(iPos+5,2500);
							*/
							iPosTemp = iTemp.Find(">");
							iTemp = iTemp.Mid(iPosTemp,2500);
							
							iPosTemp = iTemp.Find("</td>");
							//m_ListCtrl.SetItemText(curline, 13+i,temp.Mid(1,iPos-1));
							strTemp[i]=iTemp.Mid(1,iPosTemp-1);
							
						}
					}
					
				}
			}
			if (atoi(BA1) < 13.75 || atoi(BA1) > 16.00 || atoi(BA2) < 13.75 || atoi(BA2) > 16.00 \
				|| atoi(BA3) < 13.75 || atoi(BA3) > 16.00 || atoi(BA4) < 13.75 || atoi(BA4) > 16.00)
			{
				m_UnknowType.m_List_UnknowType.AddItem(iDestAddr, BA1, BA2, BA3, BA4, SUM, poolUser1, pool1Status,  \
				poolUser2, pool2Status, poolUser3, pool3Status, RunTime, strTemp[0], strTemp[1],strTemp[2],strTemp[3]);
				if (atof(BA1) < 13.75 || atof(BA1) > 16.00)	
					m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, 1, RGB(255,0,0), RGB(255,255,255));
				if (atof(BA2) < 13.75 || atof(BA2) > 16.00)	
					m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, 2, RGB(255,0,0), RGB(255,255,255));
				if (atof(BA3) < 13.75 || atof(BA3) > 16.00)	
					m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, 3, RGB(255,0,0), RGB(255,255,255));
				if (atof(BA4) < 13.75 || atof(BA4) > 16.00)	
					m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, 4, RGB(255,0,0), RGB(255,255,255));	
				if (SUM == "0" || atof(SUM) > 62.00|| atof(SUM) < 55.00)
					m_LTC60M.m_List_LTC60M.SetItemColor(m_LTC60M.m_line, 5, RGB(255,0,0), RGB(255,255,255));
				m_UnknowType.m_line=m_UnknowType.m_line + 1;
			}
			else
			{
				m_LTC60M.m_List_LTC60M.AddItem(iDestAddr, BA1, BA2, BA3, BA4, SUM, poolUser1, pool1Status,  \
					poolUser2, pool2Status, poolUser3, pool3Status, RunTime, strTemp[0], strTemp[1],strTemp[2],strTemp[3]);
				CString strUser1, strUser2, strUser3;
				pDlg->m_UsernameEdit1.GetWindowText(strUser1);
				pDlg->m_UsernameEdit2.GetWindowText(strUser2);
				pDlg->m_UsernameEdit3.GetWindowText(strUser3);
				
				if (m_user_check1.GetCheck() == BST_CHECKED)
				{
					if (poolUser1 != strUser1)
						m_LTC60M.m_List_LTC60M.SetItemColor(m_LTC60M.m_line, 6, RGB(255,0,0), RGB(255,255,255));
				}
				else
				{
					strUser1+=iDestAddr.Mid(iDestAddr.ReverseFind('.'),iDestAddr.GetLength());	
					strUser1 += "l";
					if (poolUser1 != strUser1)
						m_LTC60M.m_List_LTC60M.SetItemColor(m_LTC60M.m_line, 6, RGB(255,0,0), RGB(255,255,255));
				}
				
				if (m_user_check2.GetCheck() == BST_CHECKED)
				{
					if (poolUser2 != strUser2)
						m_LTC60M.m_List_LTC60M.SetItemColor(m_LTC60M.m_line, 8, RGB(255,0,0), RGB(255,255,255));
				}
				else
				{
					strUser2+=iDestAddr.Mid(iDestAddr.ReverseFind('.'),iDestAddr.GetLength());
					strUser2 += "l";
					if (poolUser2 != strUser2)
						m_LTC60M.m_List_LTC60M.SetItemColor(m_LTC60M.m_line, 8, RGB(255,0,0), RGB(255,255,255));
				}
				
				if (m_user_check3.GetCheck() == BST_CHECKED)
				{
					if (poolUser3 != strUser3)
						m_LTC60M.m_List_LTC60M.SetItemColor(m_LTC60M.m_line, 10, RGB(255,0,0), RGB(255,255,255));
				}
				else
				{
					strUser3+=iDestAddr.Mid(iDestAddr.ReverseFind('.'),iDestAddr.GetLength());
					strUser3 += "l";
					if (poolUser3 != strUser3)
						m_LTC60M.m_List_LTC60M.SetItemColor(m_LTC60M.m_line, 10, RGB(255,0,0), RGB(255,255,255));
				}
				
				if (pool1Status != "Alive")
					m_LTC60M.m_List_LTC60M.SetItemColor(m_LTC60M.m_line, 7, RGB(255,0,0), RGB(255,255,255));
				if (pool2Status != "Alive")
					m_LTC60M.m_List_LTC60M.SetItemColor(m_LTC60M.m_line, 9, RGB(255,0,0), RGB(255,255,255));
				if (pool3Status != "Alive")
					m_LTC60M.m_List_LTC60M.SetItemColor(m_LTC60M.m_line, 11, RGB(255,0,0), RGB(255,255,255));
				
				
				if (strTemp[0] > 70 || strTemp[0] == "0")
					m_LTC60M.m_List_LTC60M.SetItemColor(m_LTC60M.m_line, 13, RGB(255,0,0), RGB(255,255,255));
				if (strTemp[1] > 70 || strTemp[1] == "0")
					m_LTC60M.m_List_LTC60M.SetItemColor(m_LTC60M.m_line, 14, RGB(255,0,0), RGB(255,255,255));
				if (strTemp[2] > 70 || strTemp[2] == "0")
					m_LTC60M.m_List_LTC60M.SetItemColor(m_LTC60M.m_line, 15, RGB(255,0,0), RGB(255,255,255));
				if (strTemp[3] > 70 || strTemp[3] == "0")
				m_LTC60M.m_List_LTC60M.SetItemColor(m_LTC60M.m_line, 16, RGB(255,0,0), RGB(255,255,255));	
				m_LTC60M.m_line = m_LTC60M.m_line + 1;
			}	
		}
		break;	
	case 1:
		{
			// "BTC 1T"
			//	AfxMessageBox("BTC 1T");
			CString BA1, BA2, BA3, BA4, SUM, poolUser1, pool1Status, poolUser2, pool2Status, poolUser3, pool3Status, RunTime;
			CString strTemp[4]={"","","",""};
			int iPos = strHtmlData.Find("BA1");
			if (iPos == -1)
			{
				break;
			}
			//int strLength = strHtmlData.GetLength();

			//first
			CString	tempHtml = strHtmlData.Mid(iPos,5000);
			{
				temp = tempHtml;
				for (int i = 0;i < 5; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				temp.Remove(',');
				temp.Mid(0, temp.Find('.')-1);

				temp.Format("%d",int(atoi(temp)/1000+0.5));
				BA1 = temp;
				
				// second
				for (i = 0;i < 23; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				temp.Remove(',');
				temp.Mid(0, temp.Find('.')-1);
				temp.Format("%d",int(atoi(temp)/1000+0.5));
				BA2 = temp;
				// third
				for (i = 0;i < 23; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				temp.Remove(',');
				temp.Mid(0, temp.Find('.')-1);
				temp.Format("%d",int(atoi(temp)/1000+0.5));
				BA3 = temp;
				// forth
				for (i = 0;i < 23; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				temp.Remove(',');
				temp.Mid(0, temp.Find('.')-1);
				temp.Format("%d",int(atoi(temp)/1000+0.5));
				BA4 = temp;

				// summary
				iPos = strHtmlData.Find("SUMMARY");
				if (iPos < 0)
				{
					ret = -1;
				}
				else
				{
					tempHtml = strHtmlData.Mid(iPos,500);
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,500);
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,500);
					iPos = tempHtml.Find(">");
					tempHtml = tempHtml.Mid(iPos,500);
					
					iPos = tempHtml.Find("</td>");
					temp = tempHtml.Mid(1,iPos-1);
					temp.Remove(',');
					temp.Mid(0, temp.Find('.')-1);
					temp.Format("%d",int(atoi(temp)/1000+0.5));
				}
				SUM = temp;
				// pool-user1
				iPos = strHtmlData.Find("Stratum URL");
				tempHtml = strHtmlData.Mid(iPos,5000);
				for (i = 0;i < 7; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}

				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				pool1Status = temp;

				for (i = 0;i < 12; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				poolUser1 = temp;
				// pool-user2

				for (i = 0;i < 18; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				pool2Status = temp;

				for (i = 0;i < 12; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				poolUser2 = temp;
				// pool-user3
				for (i = 0;i < 18; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				pool3Status = temp;

				for (i = 0;i < 12; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				poolUser3 = temp;
				// run time
				CString strUrl = "http://"+iDestAddr+"/miner.php?ref=0&pg=Stats";
				TCHAR	ch;
				char *pstrURL = (char*)LPCTSTR(strUrl);
				CInternetSession m_session;
				strHtmlData = "";
				pstrURL = (char*)LPCTSTR(strUrl);

				CHttpFile *pFile;//  = (CHttpFile *) m_session.OpenURL(pstrURL, 1, 
				//	INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
				try
				{
					pFile  = (CHttpFile *) m_session.OpenURL(pstrURL, 1, 
						INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
					
					//m_session.Close();
				}
				catch (CException* e)
				{
					//e->ReportError();
					e->Delete();
					goto OUTP;
				}

				while (pFile->Read(&ch, sizeof(TCHAR)))
				{
					strHtmlData += ch;
				}	
				
				iPos = strHtmlData.Find("Work Utility");
				//int strLength = strHtmlData.GetLength();
				tempHtml = strHtmlData.Mid(iPos,500);
				
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,500);
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,500);
					
					iPos = tempHtml.Find(">");
					tempHtml = tempHtml.Mid(iPos,500);
					
					iPos = tempHtml.Find("</td>");
					RunTime = tempHtml.Mid(1,iPos-1);
					RunTime.Replace("&nbsp;","");
					//AfxMessageBox(RunTime);
				}

				int		iPosTemp;
				CString strFind[]={"BA10","BA11","BA12","BA13"};
				CString	iTemp = strHtmlData;
				
				for (i = 0;i < 4;i++)
				{
					iPosTemp = strHtmlData.Find(strFind[i]);
					if (iPosTemp == -1)
					{
						strTemp[i] = "0";
					} 
					else
					{
						iTemp = strHtmlData.Mid(iPosTemp,2500);
						{
							if (ret == 1)
							{
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
							} 
							else if (ret == 3)
							{
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
								iPosTemp = iTemp.Find("<td ");
								iTemp = iTemp.Mid(iPosTemp+5,2500);
							}
							else
							{
								;
							}
							/*
							iPos = temp.Find("<td ");
							temp = temp.Mid(iPos+5,2500);
							*/
							iPosTemp = iTemp.Find(">");
							iTemp = iTemp.Mid(iPosTemp,2500);
							
							iPosTemp = iTemp.Find("</td>");
							//m_ListCtrl.SetItemText(curline, 13+i,temp.Mid(1,iPos-1));
							strTemp[i]=iTemp.Mid(1,iPosTemp-1);
							
						}
					}
					
				}
			}
		
			if (atoi(BA1) < 240 || atoi(BA1) > 275 || atoi(BA2) < 240 || atoi(BA2) > 275 \
				|| atoi(BA3) < 240 || atoi(BA3) > 275 || atoi(BA4) < 240 || atoi(BA4) > 275)
			{
				m_UnknowType.m_List_UnknowType.AddItem(iDestAddr, BA1, BA2, BA3, BA4, SUM, poolUser1, pool1Status,  \
					poolUser2, pool2Status, poolUser3, pool3Status, RunTime, strTemp[0], strTemp[1],strTemp[2],strTemp[3]);
				if (atoi(BA1) < 240 || atoi(BA1) > 275)	
					m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, 1, RGB(255,0,0), RGB(255,255,255));
				if (atoi(BA2) < 240 || atoi(BA2) > 275)	
					m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, 2, RGB(255,0,0), RGB(255,255,255));
				if (atoi(BA3) < 240 || atoi(BA3) > 275)	
					m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, 3, RGB(255,0,0), RGB(255,255,255));
				if (atoi(BA4) < 240 || atoi(BA4) > 275)	
					m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, 4, RGB(255,0,0), RGB(255,255,255));	
				if (SUM == "0" || atoi(SUM) > 1100 || atoi(SUM) < 980)
					m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, 5, RGB(255,0,0), RGB(255,255,255));
				m_UnknowType.m_line=m_UnknowType.m_line+1;
			}
			else
			{
				m_BTC1T.m_List_BTC1T.AddItem(iDestAddr, BA1, BA2, BA3, BA4, SUM, poolUser1, pool1Status,  \
					poolUser2, pool2Status, poolUser3, pool3Status, RunTime, strTemp[0], strTemp[1],strTemp[2],strTemp[3]);
				CString strUser1, strUser2, strUser3;
				pDlg->m_UsernameEdit1.GetWindowText(strUser1);
				pDlg->m_UsernameEdit2.GetWindowText(strUser2);
				pDlg->m_UsernameEdit3.GetWindowText(strUser3);
				
				if (m_user_check1.GetCheck() == BST_CHECKED)
				{
					if (poolUser1 != strUser1)
						m_BTC1T.m_List_BTC1T.SetItemColor(m_BTC1T.m_line, 6, RGB(255,0,0), RGB(255,255,255));
				}
				else
				{
					strUser1+=iDestAddr.Mid(iDestAddr.ReverseFind('.'),iDestAddr.GetLength());
					strUser1 += "b";
					
					if (poolUser1 != strUser1)
						m_BTC1T.m_List_BTC1T.SetItemColor(m_BTC1T.m_line, 6, RGB(255,0,0), RGB(255,255,255));
				}
				
				if (m_user_check2.GetCheck() == BST_CHECKED)
				{
					if (poolUser2 != strUser2)
						m_BTC1T.m_List_BTC1T.SetItemColor(m_BTC1T.m_line, 8, RGB(255,0,0), RGB(255,255,255));
				}
				else
				{
					strUser2+=iDestAddr.Mid(iDestAddr.ReverseFind('.'),iDestAddr.GetLength());
					strUser2 += "b";
					
					if (poolUser2 != strUser2)
						m_BTC1T.m_List_BTC1T.SetItemColor(m_BTC1T.m_line, 8, RGB(255,0,0), RGB(255,255,255));
				}
				
				if (m_user_check3.GetCheck() == BST_CHECKED)
				{
					if (poolUser3 != strUser3)
						m_BTC1T.m_List_BTC1T.SetItemColor(m_BTC1T.m_line, 10, RGB(255,0,0), RGB(255,255,255));
				}
				else
				{
					strUser3+=iDestAddr.Mid(iDestAddr.ReverseFind('.'),iDestAddr.GetLength());
					strUser3 += "b";
					
					if (poolUser3 != strUser3)
						m_BTC1T.m_List_BTC1T.SetItemColor(m_BTC1T.m_line, 10, RGB(255,0,0), RGB(255,255,255));
				}
				
				if (pool1Status != "Alive")
					m_BTC1T.m_List_BTC1T.SetItemColor(m_BTC1T.m_line, 7, RGB(255,0,0), RGB(255,255,255));
				if (pool2Status != "Alive")
					m_BTC1T.m_List_BTC1T.SetItemColor(m_BTC1T.m_line, 9, RGB(255,0,0), RGB(255,255,255));
				if (pool3Status != "Alive")
					m_BTC1T.m_List_BTC1T.SetItemColor(m_BTC1T.m_line, 11, RGB(255,0,0), RGB(255,255,255));
				
				
				if (strTemp[0] > 70 || strTemp[0] == "0")
					m_BTC1T.m_List_BTC1T.SetItemColor(m_BTC1T.m_line, 13, RGB(255,0,0), RGB(255,255,255));
				if (strTemp[1] > 70 || strTemp[1] == "0")
					m_BTC1T.m_List_BTC1T.SetItemColor(m_BTC1T.m_line, 14, RGB(255,0,0), RGB(255,255,255));
				if (strTemp[2] > 70 || strTemp[2] == "0")
					m_BTC1T.m_List_BTC1T.SetItemColor(m_BTC1T.m_line, 15, RGB(255,0,0), RGB(255,255,255));
				if (strTemp[3] > 70 || strTemp[3] == "0")
					m_BTC1T.m_List_BTC1T.SetItemColor(m_BTC1T.m_line, 16, RGB(255,0,0), RGB(255,255,255));
				m_BTC1T.m_line=m_BTC1T.m_line + 1;
			}	
		}
		break;
	case 2:
		{
			// "LTC 30M"
			//AfxMessageBox("LTC 30M");
			CString ICA1, ICA2, ICA3, ICA4, SUM, poolUser1, pool1Status, poolUser2, pool2Status, poolUser3, pool3Status, RunTime;
			int iPos = strHtmlData.Find("ICA");
			if (iPos == -1)
			{
				break;
			}
			//int strLength = strHtmlData.GetLength();
			
			//first
			CString	tempHtml = strHtmlData.Mid(iPos,5000);
			{
				temp = tempHtml;
				for (int i = 0;i < 5; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				ICA1 = temp;
				
				// second
				for (i = 0;i < 21; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				ICA2 = temp;
				// third
				for (i = 0;i < 21; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				ICA3 = temp;
				// forth
				for (i = 0;i < 21; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				ICA4 = temp;
				// summary
				iPos = strHtmlData.Find("SUMMARY");
				if (iPos < 0)
				{
					ret = -1;
				}
				else
				{
					tempHtml = strHtmlData.Mid(iPos,500);
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,500);
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,500);
					iPos = tempHtml.Find(">");
					tempHtml = tempHtml.Mid(iPos,500);
					
					iPos = tempHtml.Find("</td>");
					temp = tempHtml.Mid(1,iPos-1);
				}
				SUM = temp;
				// pool-user1
				iPos = strHtmlData.Find("Stratum URL");
				tempHtml = strHtmlData.Mid(iPos,5000);

				for (i = 0;i < 5; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				pool1Status = temp;

				for (i = 0;i < 10; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				poolUser1 = temp;
				// pool-user2

				for (i = 0;i < 16; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				pool2Status = temp;

				for (i = 0;i < 10; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				poolUser2 = temp;
				// pool-user3

				for (i = 0;i < 16; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				pool3Status = temp;

				for (i = 0;i < 10; i++)
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,5000);
				}
				iPos = tempHtml.Find(">");
				tempHtml = tempHtml.Mid(iPos,5000);
				
				iPos = tempHtml.Find("</td>");
				temp = tempHtml.Mid(1,iPos-1);
				poolUser3 = temp;
				// run time
				CString strUrl = "http://"+iDestAddr+"/miner.php?ref=0&pg=Stats";
				TCHAR	ch;
				char *pstrURL = (char*)LPCTSTR(strUrl);
				CInternetSession m_session;
				strHtmlData = "";
				pstrURL = (char*)LPCTSTR(strUrl);
				CHttpFile *pFile;
				//CHttpFile *pFile  = (CHttpFile *) m_session.OpenURL(pstrURL, 1, 
				//	INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
				try
				{
					pFile  = (CHttpFile *) m_session.OpenURL(pstrURL, 1, 
						INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
					
					//m_session.Close();
				}
				catch (CException* e)
				{
					//e->ReportError();
					e->Delete();
					goto OUTP;
				}

				while (pFile->Read(&ch, sizeof(TCHAR)))
				{
					strHtmlData += ch;
				}	
				
				iPos = strHtmlData.Find("Work Utility");
				//int strLength = strHtmlData.GetLength();
				tempHtml = strHtmlData.Mid(iPos,500);
				
				{
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,500);
					iPos = tempHtml.Find("<td ");
					tempHtml = tempHtml.Mid(iPos+5,500);
					
					iPos = tempHtml.Find(">");
					tempHtml = tempHtml.Mid(iPos,500);
					
					iPos = tempHtml.Find("</td>");
					RunTime = tempHtml.Mid(1,iPos-1);
					RunTime.Replace("&nbsp;","");
					//AfxMessageBox(RunTime);
				}

			}
		if (atof(ICA1) < 7.0 || atof(ICA1) > 8.8 || atof(ICA2) < 7.0 || atof(ICA2) > 8.8 || \
			atof(ICA3) < 7.0 || atof(ICA3) > 8.8 || atof(ICA4) < 7.0 || atof(ICA4) > 8.8)
		{
			m_UnknowType.m_List_UnknowType.AddItem(iDestAddr, ICA1, ICA2, ICA3, ICA4, SUM, poolUser1, pool1Status,  \
					poolUser2, pool2Status, poolUser3, pool3Status, RunTime, _T(""), _T(""),_T(""),_T(""));
			if (atof(ICA1) < 7.0 || atof(ICA1) > 8.8)	
				m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, 1, RGB(255,0,0), RGB(255,255,255));
			if (atof(ICA2) < 7.0 || atof(ICA2) > 8.8)	
				m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, 2, RGB(255,0,0), RGB(255,255,255));
			if (atof(ICA3) < 7.0 || atof(ICA3) > 8.8)	
				m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, 3, RGB(255,0,0), RGB(255,255,255));
			if (atof(ICA4) < 7.0 || atof(ICA4) > 8.8)	
				m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, 4, RGB(255,0,0), RGB(255,255,255));	
			if (SUM == "0" || atoi(SUM) > 35.0 || atoi(SUM) < 28.0)
				m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, 5, RGB(255,0,0), RGB(255,255,255));
			m_UnknowType.m_line = m_UnknowType.m_line +1;
		}
		else 
		{
			m_LTC30M.m_List_LTC30M.AddItem(iDestAddr, ICA1, ICA2, ICA3, ICA4, SUM, poolUser1, pool1Status,  \
					poolUser2, pool2Status, poolUser3, pool3Status, RunTime, _T(""), _T(""),_T(""),_T(""));
			CString strUser1, strUser2, strUser3;
			pDlg->m_UsernameEdit1.GetWindowText(strUser1);
			pDlg->m_UsernameEdit2.GetWindowText(strUser2);
			pDlg->m_UsernameEdit3.GetWindowText(strUser3);
			
			if (m_user_check1.GetCheck() == BST_CHECKED)
			{
				if (poolUser1 != strUser1)
					m_LTC30M.m_List_LTC30M.SetItemColor(m_LTC30M.m_line, 6, RGB(255,0,0), RGB(255,255,255));
			}
			else
			{
				strUser1+=iDestAddr.Mid(iDestAddr.ReverseFind('.'),iDestAddr.GetLength());
				strUser1 += "l";
				if (poolUser1 != strUser1)
					m_LTC30M.m_List_LTC30M.SetItemColor(m_LTC30M.m_line, 6, RGB(255,0,0), RGB(255,255,255));
			}
			
			if (m_user_check2.GetCheck() == BST_CHECKED)
			{
				if (poolUser2 != strUser2)
					m_LTC30M.m_List_LTC30M.SetItemColor(m_LTC30M.m_line, 8, RGB(255,0,0), RGB(255,255,255));
			}
			else
			{
				strUser2+=iDestAddr.Mid(iDestAddr.ReverseFind('.'),iDestAddr.GetLength());
				strUser2 += "l";
				if (poolUser2 != strUser2)
					m_LTC30M.m_List_LTC30M.SetItemColor(m_LTC30M.m_line, 8, RGB(255,0,0), RGB(255,255,255));
			}
			
			if (m_user_check3.GetCheck() == BST_CHECKED)
			{
				if (poolUser3 != strUser3)
					m_LTC30M.m_List_LTC30M.SetItemColor(m_LTC30M.m_line, 10, RGB(255,0,0), RGB(255,255,255));
			}
			else
			{
				strUser3+=iDestAddr.Mid(iDestAddr.ReverseFind('.'),iDestAddr.GetLength());
				strUser3 += "l";
				if (poolUser3 != strUser3)
					m_LTC30M.m_List_LTC30M.SetItemColor(m_LTC30M.m_line, 10, RGB(255,0,0), RGB(255,255,255));
			}
			
			if (pool1Status != "Alive")
				m_LTC30M.m_List_LTC30M.SetItemColor(m_LTC30M.m_line, 7, RGB(255,0,0), RGB(255,255,255));
			if (pool2Status != "Alive")
				m_LTC30M.m_List_LTC30M.SetItemColor(m_LTC30M.m_line, 9, RGB(255,0,0), RGB(255,255,255));
			if (pool3Status != "Alive")
				m_LTC30M.m_List_LTC30M.SetItemColor(m_LTC30M.m_line, 11, RGB(255,0,0), RGB(255,255,255));

			m_LTC30M.m_line = m_LTC30M.m_line + 1;
		}

		}
		break;
	case 4:
		{
			
		}
		break;
OUTP:	default:
		{
			m_UnknowType.m_List_UnknowType.AddItem(iDestAddr, "0", "0", "0", "0", "0", "0","0",  \
				"0","0", "0","0", "0", "0", "0","0","0");
			for (int k=0;k<17;k++)
			{
				m_UnknowType.m_List_UnknowType.SetItemColor(m_UnknowType.m_line, k, RGB(255,0,0), RGB(255,255,255));	
			}
		}
	}
}

void CNetworksDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int CurSel = m_MainTab.GetCurSel();
	
    switch(CurSel)
    {
	case 0:
		m_BTC1T.ShowWindow(true);
		m_LTC30M.ShowWindow(false);
		m_LTC60M.ShowWindow(false);
		m_UnknowType.ShowWindow(false);
		break;
	case 1:
		m_BTC1T.ShowWindow(false);
		m_LTC30M.ShowWindow(true);
		m_LTC60M.ShowWindow(false);
		m_UnknowType.ShowWindow(false);
		break;
	case 2:
		m_BTC1T.ShowWindow(false);
		m_LTC30M.ShowWindow(false);
		m_LTC60M.ShowWindow(true);
		m_UnknowType.ShowWindow(false);
		break;
	case 3:
		m_BTC1T.ShowWindow(false);
		m_LTC30M.ShowWindow(false);
		m_LTC60M.ShowWindow(false);
		m_UnknowType.ShowWindow(true);
		break;
	default:
		;
	}
	*pResult = 0;
}
