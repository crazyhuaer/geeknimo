// networksDlg.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "networksDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define UNICODE
#define destPORT 137
#define myPORT 1578
CNetworksDlg *pDlg;
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
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetworksDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetworksDlg)
	DDX_Control(pDX, IDC_BUTTON_REFRESH, m_Button_Fresh);
	DDX_Control(pDX, IDC_SOFT_STATUS, m_SoftStatus);
	DDX_Control(pDX, IDC_SPIN_TIMEOUT, m_SpinTimeOut);
	DDX_Control(pDX, IDC_LIST_IP_STATUS, m_ListCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNetworksDlg, CDialog)
	//{{AFX_MSG_MAP(CNetworksDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_REFRESH, OnButtonRefresh)
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
	// Add by topseten
	//---------------------------------------------
	bExit = false;
	bs = (char *) malloc( 50*sizeof(char) );
	strOldIP = "";
	pDlg = this;
	m_line = 0;

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

	wait_handle=CreateEvent(NULL,true,false,"receive data");//创建处于非触发状态的事件。类型为手动
	// Init
	m_ListCtrl.InsertColumn(1, _T("SV-STATUS"), LVCFMT_LEFT, 90);
	m_ListCtrl.InsertColumn(2,_T("BA1(MHZ)"),LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(3,_T("BA2(MHZ)"),LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(4,_T("BA3(MHZ)"),LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(5,_T("BA4(MHZ)"),LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(6,_T("SUM(MHZ)"),LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(7, _T("PL1"), LVCFMT_LEFT, 160);
	m_ListCtrl.InsertColumn(8, _T("PL1-STATUS"), LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(9, _T("PL2"), LVCFMT_LEFT, 160);
	m_ListCtrl.InsertColumn(10, _T("PL2-STATUS"), LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(11, _T("PL3"), LVCFMT_LEFT, 160);
	m_ListCtrl.InsertColumn(12, _T("PL3-STATUS"), LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(0, _T("IP"), LVCFMT_LEFT, 90, -1);
	
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);	

	//////////////////////////////////////////////////////////////////////////
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

//--------------------------nbtstat线程----------------------
UINT CNetworksDlg::NbtstatThread(LPVOID param)
{
	CNetworksDlg *CMyPage = (CNetworksDlg*)param;

	CString strHtmlData, iTmp, iDestAddr;

	for (int i=2;i<254;i++)
	{
		CString ipHead = "192.168.1.";
		iTmp.Format(_T("%d"),i);

		CMyPage->m_line = i - 2;
		
		iDestAddr = ipHead + iTmp;
	
		int len = CMyPage->m_UDPSocket.SendTo((void*)(CMyPage->bs),50,destPORT,iDestAddr,0);//向指定的ip发数据报

		int nWait=CMyPage->m_SpinTimeOut.GetPos();//设置超时
		nWait = 500;

		if (len == 50)
		{
			DWORD ret = WaitForSingleObject(
				CMyPage->wait_handle,        // 等待事件的句柄
				nWait   // 超时
				);
			
			switch (ret)
			{

			case WAIT_OBJECT_0:
				{	
					//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage(iDestAddr+":WAIT_OBJECT_0");
					break;
				}
			case WAIT_ABANDONED:
				{
					//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage(iDestAddr+":WAIT_ABANDONED");
					//CMyPage->LkMachine_GetStatus(iDestAddr,0,CMyPage->m_line);
					
					break;
				}
			case WAIT_TIMEOUT:
				{
					//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage(iDestAddr+":WAIT_TIMEOUT");
					//CMyPage->LkMachine_GetStatus(iDestAddr,0,CMyPage->m_line);
					//ResetEvent(CMyPage->wait_handle);//将事件重新置回非触发状态
					break;
				}
			default:
				{
					//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage(iDestAddr+":default");
				}
			}	
			
		}
		ResetEvent(CMyPage->wait_handle);//将事件重新置回非触发状态
	}

	CMyPage->m_SoftStatus.SetWindowText("刷新完毕");
	CMyPage->m_Button_Fresh.EnableWindow(TRUE);
	return 0;
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
	CString str,strIP,strHost,strHex,strMac,Host,Group,User;
	UINT dport;
	CMyPage->m_UDPSocket.ReceiveFrom(Buf,512,strIP,dport,0);//接收数据
    //如果接收到的ip为空或者与原来接收到的ip相同，则返回
	if(strIP==(char)NULL||strIP==CMyPage->strOldIP)
		return -1;
	CMyPage->strOldIP=strIP;
	//int index=m_ListCtrl.InsertItem(0,strIP);//将ip插入ListView
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
				
				if ( strHost == "RASPBERRYPI")
				{
					((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("strHost:"+strHost);
					// alive.
					CString line(strIP);
					
					int idx = strIP.ReverseFind('.'); //idx 的值为4;
					
					line = line.Mid(idx+1, strIP.GetLength());

					CString thetemp;
					thetemp.Format("%d",atoi(line)-2);
					((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("line:"+thetemp);

					ret = CMyPage->LkMachine_GetStatus(strIP,1,0);
					/*
					ret = LkMachine_GetStatus(strIP,2,atoi(line)-2);
					if (ret == 0)
					{
						ret = LkMachine_GetStatus(strIP,1,atoi(line)-2);
					} 
					else
					{
						ret = LkMachine_GetStatus(strIP,3,atoi(line)-2);
					}
					*/
					
				}

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
	
	//触发事件，导致线程函数的继续执行
	SetEvent(CMyPage->wait_handle);
	return 0;
}
void CNetworksDlg::OnReceive()
{
	CWinThread *pThread = AfxBeginThread(GetStatusThread,(LPVOID)this,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
	pThread->m_bAutoDelete=FALSE;
	int suspendCnt=pThread->ResumeThread();
	
	DWORD exitcode;
	do{
		
		BOOL result = GetExitCodeThread(pThread, &exitcode);
		
		Sleep(200);
		
	}while(exitcode == STILL_ACTIVE);
}

void CNetworksDlg::OnButtonRefresh() 
{
	// TODO: Add your control notification handler code here
	m_SoftStatus.SetWindowText("正在刷新系统机器状态");
	GetDlgItem(IDC_BUTTON_REFRESH)->EnableWindow(FALSE);
	m_ListCtrl.DeleteAllItems(); 
	m_thread = AfxBeginThread(NbtstatThread,(LPVOID)this,CREATE_SUSPENDED);
	m_thread->m_bAutoDelete=FALSE;
	int suspendCnt=m_thread->ResumeThread();

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
		//AfxMessageBox(temp);
	}
	return ALLSpeed;
}


CString CNetworksDlg::FindPoolStatus(CString *strHtmlData,int curline)
{
	CString thetemp;
	thetemp.Format("%d",curline);
	((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("FindPoolStatus curline:"+thetemp);

	CString PoolAUrl,PoolAStatus;
	CString PoolBUrl,PoolBStatus;
	CString PoolCUrl,PoolCStatus;
	int iPos = (*strHtmlData).Find("Stratum URL");
	//int strLength = strHtmlData.GetLength();
	CString	temp = (*strHtmlData).Mid(iPos,2500);
	*strHtmlData = (*strHtmlData).Mid(iPos+10,(*strHtmlData).GetLength());
	
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

		m_ListCtrl.SetItemText(curline, 7,PoolAUrl);


		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,2500);


		iPos = temp.Find(">");
		temp = temp.Mid(iPos,2500);
		
		iPos = temp.Find("</td>");
		PoolAStatus = temp.Mid(1,iPos-1);

		m_ListCtrl.SetItemText(curline, 8,PoolAStatus);

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
		
		m_ListCtrl.SetItemText(curline, 9,PoolBUrl);

		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,2500);

		iPos = temp.Find(">");
		temp = temp.Mid(iPos,2500);
		
		iPos = temp.Find("</td>");
		PoolBStatus = temp.Mid(1,iPos-1);
		
		m_ListCtrl.SetItemText(curline, 10,PoolBStatus);

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
		
		m_ListCtrl.SetItemText(curline, 11,PoolCUrl);
		
		iPos = temp.Find("<td ");
		temp = temp.Mid(iPos+5,2500);
		
		iPos = temp.Find(">");
		temp = temp.Mid(iPos,2500);
		
		iPos = temp.Find("</td>");
		PoolCStatus = temp.Mid(1,iPos-1);
		
		m_ListCtrl.SetItemText(curline, 12,PoolCStatus);


	}
	return	"0";
}


//////////////////////////////////////////////////////////////////////////
// ret :
//		0:ok
//		1:stop
//////////////////////////////////////////////////////////////////////////
int CNetworksDlg::LkMachine_GetStatus(CString iDestAddr,int Output,int line)
{
	int ret = 0;

	switch (Output)
	{
		// machine have no ip
	case 0:
		{
			m_ListCtrl.InsertItem(line, _T(iDestAddr));
			m_ListCtrl.SetItemText(line, 1, _T("NoMachine"));
			m_ListCtrl.SetItemText(line, 2, _T("0"));
			m_ListCtrl.SetItemText(line, 3, _T("0"));
			m_ListCtrl.SetItemText(line, 4, _T("0"));
			m_ListCtrl.SetItemText(line, 5, _T("0"));
			m_ListCtrl.SetItemText(line, 6, _T("0"));
			m_ListCtrl.SetItemText(line, 7, _T("0"));
			m_ListCtrl.SetItemText(line, 8, _T("0"));
			m_ListCtrl.SetItemText(line, 9, _T("0"));
			m_ListCtrl.SetItemText(line, 10, _T("0"));
			m_ListCtrl.SetItemText(line, 11, _T("0"));
			m_ListCtrl.SetItemText(line, 12, _T("0"));
		}
		break;

		// machine start
	case 1:
		{
			CString strHtmlData, iTmp, strUrl;
			
			strUrl = "http://"+iDestAddr+"/miner.php";
			
			((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("strUrl:"+strUrl);
			CString thetemp;
			thetemp.Format("%d",line);
			((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("LkMachine_GetStatus line:"+thetemp);


			TCHAR	ch;
			char *pstrURL = (char*)LPCTSTR(strUrl);
			
			CInternetSession m_session;
			CHttpFile *pFile = (CHttpFile *) m_session.OpenURL(pstrURL, 1, 
				INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
			
			while (pFile->Read(&ch, sizeof(TCHAR)))
			{
				strHtmlData += ch;
			}		

			m_ListCtrl.InsertItem(line, iDestAddr);
			//m_ListCtrl.SetItemText(m_curLine, 1, _T("start"));
			m_ListCtrl.SetItem(line,1,LVIF_TEXT,_T("start"), 0, 0, 0,0);

			//CString BASpeedA = FindBA(&strHtmlData);
			m_ListCtrl.SetItemText(line, 2,FindBA(&strHtmlData));
			//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("BASpeedA:"+BASpeedA);
			
			strHtmlData = strHtmlData.Mid(3,strHtmlData.GetLength());
			//CString BASpeedB = FindBA(&strHtmlData);
			m_ListCtrl.SetItemText(line, 3,FindBA(&strHtmlData));
			//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("BASpeedB:"+BASpeedB);
			
			strHtmlData = strHtmlData.Mid(3,strHtmlData.GetLength());
			//CString BASpeedC = FindBA(&strHtmlData);
			m_ListCtrl.SetItemText(line, 4,FindBA(&strHtmlData));
			//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("BASpeedC:"+BASpeedC);
			
			strHtmlData = strHtmlData.Mid(3,strHtmlData.GetLength());
			//CString BASpeedD = FindBA(&strHtmlData);
			m_ListCtrl.SetItemText(line, 5,FindBA(&strHtmlData));
			//((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("BASpeedD:"+BASpeedD);
			
			strHtmlData = strHtmlData.Mid(3,strHtmlData.GetLength());
			//CString ALLSpeed = FindSummary(&strHtmlData);
			m_ListCtrl.SetItemText(line, 6,FindSummary(&strHtmlData));
			
			strHtmlData = strHtmlData.Mid(3,strHtmlData.GetLength());
			CString Pool1Status = FindPoolStatus(&strHtmlData,line);
		}
		break;
	case 2:
		{
			CString strHtmlData, iTmp, strUrl;
			
			strUrl = "http://"+iDestAddr;
			
			((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("strUrl:"+strUrl);
			
			TCHAR	ch;
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
			m_ListCtrl.InsertItem(line, _T(iDestAddr));
			m_ListCtrl.SetItemText(line, 1, _T("stop"));
			m_ListCtrl.SetItemText(line, 2, _T("stop"));
			m_ListCtrl.SetItemText(line, 3, _T("0"));
			m_ListCtrl.SetItemText(line, 4, _T("0"));
			m_ListCtrl.SetItemText(line, 5, _T("0"));
			m_ListCtrl.SetItemText(line, 6, _T("0"));
			m_ListCtrl.SetItemText(line, 7, _T("0"));
			m_ListCtrl.SetItemText(line, 8, _T("0"));
			m_ListCtrl.SetItemText(line, 9, _T("0"));
			m_ListCtrl.SetItemText(line, 10, _T("0"));
			m_ListCtrl.SetItemText(line, 11, _T("0"));
			m_ListCtrl.SetItemText(line, 12, _T("0"));
		}
		break;
	default :
		{

		}
	}
	return ret;
}
