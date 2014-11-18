// modifyipDlg.cpp : implementation file
//

#include "stdafx.h"
#include "modifyip.h"
#include "modifyipDlg.h"

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
// CModifyipDlg dialog

CModifyipDlg::CModifyipDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModifyipDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CModifyipDlg)
	m_MessageBox = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//////////////////////////////////////////////////////////////////////////
	strIpTarget = "";

	strIpNetmask = "";
	strIpGateway = "";
	strIpDns = "";

	strIpStart = "";
	strIpEnd = "";

	m_MessageBox = "";

	strCmdPath = "c:\\windows\\system32\\cmd.exe /c ";

	memset(m_chIpStart,0,sizeof(m_chIpStart));
	memset(m_chIpEnd,0,sizeof(m_chIpEnd));
	//////////////////////////////////////////////////////////////////////////
}

void CModifyipDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModifyipDlg)
	DDX_Control(pDX, IDC_BUTTON_CREATE_IPPOOL, m_btnCreateIpPool);
	DDX_Control(pDX, IDC_BUTTON_MODIFYIP, m_btnModifyIp);
	DDX_Control(pDX, IDC_BUTTON_PING, m_btnPing);
	DDX_Control(pDX, IDC_IPADDRESS_NETMASK, m_coIpAddressNetMask);
	DDX_Control(pDX, IDC_IPADDRESS_DNS, m_coIpaddressDns);
	DDX_Control(pDX, IDC_IPADDRESS_GATEWAY, m_coIpAddressGateway);
	DDX_Control(pDX, IDC_RICHEDIT_MESSAGE, m_coMessage);
	DDX_Control(pDX, IDC_LIST_IPPOOL, m_coListIpPool);
	DDX_Control(pDX, IDC_IPADDRESS_IPPOOL_2, m_coIpAddressIpPool2);
	DDX_Control(pDX, IDC_IPADDRESS_IPPOOL_1, m_coIpAddressIpPool1);
	DDX_Control(pDX, IDC_IPADDRESS_TARGET, m_coIpAddressTarget);
	DDX_Text(pDX, IDC_RICHEDIT_MESSAGE, m_MessageBox);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CModifyipDlg, CDialog)
	//{{AFX_MSG_MAP(CModifyipDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CREATE_IPPOOL, OnButtonCreateIppool)
	ON_BN_CLICKED(IDC_BUTTON_PING, OnButtonPing)
	ON_BN_CLICKED(IDC_BUTTON_MODIFYIP, OnButtonModifyip)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModifyipDlg message handlers

BOOL CModifyipDlg::OnInitDialog()
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
	// Target machine ip
	m_coIpAddressTarget.SetAddress(192,168,1,10);

	// netmask gateway dns
	m_coIpAddressNetMask.SetAddress(255,255,255,0);
	m_coIpAddressGateway.SetAddress(192,168,1,1);
	m_coIpaddressDns.SetAddress(114,114,114,114);

	// IP pool 
	m_coIpAddressIpPool1.SetAddress(192,168,1,10);
	m_coIpAddressIpPool2.SetAddress(192,168,1,250);

	m_coListIpPool.SetColumnWidth(0,125);
	m_coListIpPool.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	//m_coMessage.PostMessage(WM_VSCROLL, SB_BOTTOM, 0);
	//////////////////////////////////////////////////////////////////////////
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CModifyipDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CModifyipDlg::OnPaint() 
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
HCURSOR CModifyipDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CModifyipDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if((pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) || 
		(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) )  
		return TRUE;

	return CDialog::PreTranslateMessage(pMsg);
}


//////////////////////////////////////////////////////////////////////////
UINT CModifyipDlg::funTheadPing(LPVOID param)
{
	CModifyipDlg *pDlg = (CModifyipDlg*)param;

	// 对矿机进行连接测试
	DWORD dwIp;
	IN_ADDR ia;
	
	pDlg->m_coIpAddressTarget.GetAddress(dwIp);
	ia.S_un.S_addr = htonl(dwIp);
	pDlg->strIpTarget = inet_ntoa(ia);
	//AfxMessageBox(strIpTarget);
	
	//////////////////////////////////////////////////////////////////////////
	{   
		SECURITY_ATTRIBUTES   sa;   
		HANDLE   hRead,hWrite;   
		
		sa.nLength   =   sizeof(SECURITY_ATTRIBUTES);   
		sa.lpSecurityDescriptor   =   NULL;   
		sa.bInheritHandle   =   TRUE;   
		
		if   (!CreatePipe(&hRead,&hWrite,&sa,0))   {   
			//MessageBox("Error   On   CreatePipe()");   
            return -1;   
		}     
		
		STARTUPINFO   si;   
		PROCESS_INFORMATION   pi; 
		
		si.cb   =   sizeof(STARTUPINFO);   
		GetStartupInfo(&si);     
		si.hStdError   =   hWrite;   
		si.hStdOutput   =   hWrite;   
		si.wShowWindow   =   SW_HIDE;   
		si.dwFlags   =   STARTF_USESHOWWINDOW   |   STARTF_USESTDHANDLES;   
		
		CString tempCmd = pDlg->strCmdPath +  "ping -n 1 " + pDlg->strIpTarget;
		char	*pCmdLine = tempCmd.GetBuffer(tempCmd.GetLength());
		
		if   (!CreateProcess(NULL,pCmdLine,NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi))   {   
			pDlg->MessageBox("Error   on   CreateProcess()");   
			return -1;   
		}   
		
		CloseHandle(hWrite);   
		pDlg->UpdateData(TRUE); 
		
		char ret = 0x00;
		char   buffer[1024]   =   {0};   
		DWORD   bytesRead;    
		
		while   (true)   
		{   
			if   (ReadFile(hRead,buffer,1023,&bytesRead,NULL)   ==   NULL)   
				break;   
			//m_MessageBox= buffer;
			CString temp;
			temp.Format("%s",buffer);
			int ipos =  temp.Find("TTL");
			if (ipos > 0)
			{
				//AfxMessageBox("可以ping通");
				ret |= 0x01;
			}
			else
			{
				ret |= 0x00;		
			}
			
			//m_MessageBox   +=   buffer;   
			
			Sleep(200);     
		}   
		pDlg->m_MessageBox   = tempCmd + "\n" + pDlg->m_MessageBox;
		if (ret == 0x01)
		{
			pDlg->m_MessageBox = "可以进行连接\n" + pDlg->m_MessageBox;
		} 
		else
		{
			pDlg->m_MessageBox = "无法进行连接\n" +pDlg-> m_MessageBox;
		}

		{
			pDlg->m_btnPing.EnableWindow(TRUE);
			pDlg->m_btnModifyIp.EnableWindow(TRUE);
			pDlg->m_btnCreateIpPool.EnableWindow(TRUE);
		}

		pDlg->UpdateData(false); 
	}   
	return 0;
}

UINT  CModifyipDlg::funTheadModifyIp(LPVOID param)
{
	CModifyipDlg *pDlg = (CModifyipDlg*)param;
	{
		int countLine = pDlg->m_coListIpPool.GetItemCount();
		if (countLine > 0)
		{
			// 对矿机进行修改
			DWORD dwIp;
			IN_ADDR ia;
			
			// modifyip.exe
			char pBuf[MAX_PATH];
			GetCurrentDirectory(MAX_PATH,pBuf);
			CString strCurPath;
			strCurPath.Format("%s",pBuf);

			// target
			pDlg->m_coIpAddressTarget.GetAddress(dwIp);
			ia.S_un.S_addr = htonl(dwIp);
			pDlg->strIpTarget = inet_ntoa(ia);
			//AfxMessageBox(strIpTarget);
			
			// dest
			CString strIpDest = pDlg->m_coListIpPool.GetItemText(0,0);
			
			// netmask
			pDlg->m_coIpAddressNetMask.GetAddress(dwIp);
			ia.S_un.S_addr = htonl(dwIp);
			pDlg->strIpNetmask = inet_ntoa(ia);
			//AfxMessageBox(strIpNetmask);

			// gateway
			pDlg->m_coIpAddressGateway.GetAddress(dwIp);
			ia.S_un.S_addr = htonl(dwIp);
			pDlg->strIpGateway = inet_ntoa(ia);
			//AfxMessageBox(strIpGateway);

			// dns
			pDlg->m_coIpaddressDns.GetAddress(dwIp);
			ia.S_un.S_addr = htonl(dwIp);
			pDlg->strIpDns = inet_ntoa(ia);
			//AfxMessageBox(strIpDns);
	
			//////////////////////////////////////////////////////////////////////////
			{   
				SECURITY_ATTRIBUTES   sa;   
				HANDLE   hRead,hWrite;   
				
				sa.nLength   =   sizeof(SECURITY_ATTRIBUTES);   
				sa.lpSecurityDescriptor   =   NULL;   
				sa.bInheritHandle   =   TRUE;   
				
				if   (!CreatePipe(&hRead,&hWrite,&sa,0))   {   
					pDlg->MessageBox("Error   On   CreatePipe()");   
					return -1;   
				}     
				
				STARTUPINFO   si;   
				PROCESS_INFORMATION   pi; 
				
				si.cb   =   sizeof(STARTUPINFO);   
				GetStartupInfo(&si);     
				si.hStdError   =   hWrite;   
				si.hStdOutput   =   hWrite;   
				si.wShowWindow   =   SW_HIDE;   
				si.dwFlags   =   STARTF_USESHOWWINDOW   |   STARTF_USESTDHANDLES;   
				
				CString tempCmd = "\"" + strCurPath  + "\\modifyip.exe" + "\" "  + pDlg->strIpTarget + " "+
									strIpDest + " " + pDlg->strIpNetmask + " " + 
									pDlg->strIpGateway + " " + pDlg->strIpDns;
				char	*pCmdLine = tempCmd.GetBuffer(tempCmd.GetLength());
				
				if   (!CreateProcess(NULL,pCmdLine,NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi))   {   
					pDlg->MessageBox("Error   on   CreateProcess()");   
					return -1;   
				}   
				
				CloseHandle(hWrite);   
				pDlg->UpdateData(TRUE); 
				
				char ret = 0x00;
				char   buffer[1024]   =   {0};   
				DWORD   bytesRead;    
				
				while   (true)   
				{   
					if   (ReadFile(hRead,buffer,1023,&bytesRead,NULL)   ==   NULL)   
						break;   
					//pDlg->m_MessageBox += buffer;
					CString temp;
					temp.Format("%s",buffer);
					int ipos =  temp.Find("Traceback");
					if (ipos > 0)
					{
						//AfxMessageBox("可以ping通");
						ret |= 0x01;
					}
					else
					{
						ret |= 0x00;		
					}
					
					//m_MessageBox   +=   buffer;   
					
					Sleep(200);     
				}   
				//pDlg->m_MessageBox   = tempCmd + "\n" + pDlg->m_MessageBox;
				pDlg->m_MessageBox = "修改完毕\n" + pDlg->m_MessageBox;
				pDlg->m_coListIpPool.DeleteItem(0);

				{
					pDlg->m_btnPing.EnableWindow(TRUE);
					pDlg->m_btnModifyIp.EnableWindow(TRUE);
					pDlg->m_btnCreateIpPool.EnableWindow(TRUE);
				}

				/*
				if (ret == 0x01)
				{
					pDlg->m_MessageBox= "修改成功\n" + pDlg->m_MessageBox;
					// 修改成功后删除IP池中对应的数据
					pDlg->m_coListIpPool.DeleteItem(0);
				} 
				else
				{
					pDlg->m_MessageBox= "修改失败，请重新再试试\n" + pDlg->m_MessageBox;
				}
				*/
				pDlg->UpdateData(false); 
			}   
			//////////////////////////////////////////////////////////////////////////
		} 
		else
		{
			AfxMessageBox("IP池中没有数据，请先生成IP池");
			int ret = pDlg->MessageBox("是否现在生成IP池","生成IP池？", MB_OKCANCEL );
			if (ret == 1)
			{
				pDlg->OnButtonCreateIppool();
			}
			else
			{
			
			}
		}
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////

void CModifyipDlg::OnButtonCreateIppool() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_MessageBox= "==============================\n" + m_MessageBox;
	
	// 获取生成IP池的起始和终止地址
	m_coIpAddressIpPool1.GetAddress(m_chIpStart[0],m_chIpStart[1],m_chIpStart[2],m_chIpStart[3]);
	m_coIpAddressIpPool2.GetAddress(m_chIpEnd[0],m_chIpEnd[1],m_chIpEnd[2],m_chIpEnd[3]);

	//判断ip范围是否合法
	if(m_chIpEnd[2]<m_chIpStart[2])
	{	
		AfxMessageBox("终止地址应大于起始地址！");
		m_MessageBox= "终止地址应大于起始地址！\n" + m_MessageBox;
		m_MessageBox= "==============================\n" + m_MessageBox;
		return ;
	}
	else if(m_chIpEnd[2]==m_chIpStart[2]&&m_chIpEnd[3]<m_chIpStart[3])
	{
		AfxMessageBox("终止地址应大于起始地址！");
		m_MessageBox= "终止地址应大于起始地址！\n" + m_MessageBox;
		m_MessageBox= "==============================\n" + m_MessageBox;
		return ;
	}
	if(m_chIpEnd[0]!=m_chIpStart[0]||m_chIpEnd[1]!=m_chIpStart[1])
	{
		AfxMessageBox("不支持A或者B类网络");
		m_MessageBox= "不支持A或者B类网络";
		m_MessageBox= "==============================\n" + m_MessageBox;
		return ;
	}

	{
		m_coListIpPool.DeleteAllItems();
		int countLine = 0;
		CString	ItemStr = "";
		unsigned char uStart,uEnd,uNetworkA,uNetworkB;
		
		int nRow = 0;
		
		uNetworkA = m_chIpStart[2];
		uNetworkB = m_chIpEnd[2];
		
		do 
		{
			uStart = m_chIpStart[3];
			uEnd = m_chIpEnd[3];
			
			do
			{
				ItemStr.Format("%d%s%d%s%d%s%d",m_chIpStart[0],".",m_chIpStart[1],".",uNetworkA,".",uStart);
				nRow = m_coListIpPool.InsertItem( countLine++, ItemStr);	
				m_coListIpPool.SetItemText(nRow, 0, ItemStr);
			}while(uStart++ < uEnd);
		} while (uNetworkA++ < uNetworkB);
	}
	m_MessageBox= "生成完毕\n" + m_MessageBox;
	m_MessageBox= "==============================\n" + m_MessageBox;
	UpdateData(FALSE);
}

void CModifyipDlg::OnButtonPing() 
{
	// TODO: Add your control notification handler code here
	m_thread = AfxBeginThread(funTheadPing,(LPVOID)this,CREATE_NEW);
	m_btnPing.EnableWindow(FALSE);
	m_btnModifyIp.EnableWindow(FALSE);
	m_btnCreateIpPool.EnableWindow(FALSE);
}

void CModifyipDlg::OnButtonModifyip() 
{
	// TODO: Add your control notification handler code here
	m_thread = AfxBeginThread(funTheadModifyIp,(LPVOID)this,CREATE_NEW);
	m_btnPing.EnableWindow(FALSE);
	m_btnModifyIp.EnableWindow(FALSE);
	m_btnCreateIpPool.EnableWindow(FALSE);
}
