// freesoftDlg.cpp : implementation file
//

#include "stdafx.h"
#include "freesoft.h"
#include "freesoftDlg.h"
#include "Dialog_LKBTC1T.h"
#include "Dialog_LK_BTC15T.h"
#include <shlwapi.h>

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
// CFreesoftDlg dialog

CFreesoftDlg::CFreesoftDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFreesoftDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFreesoftDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	// Init the member data
	m_iTab_Select = 0;
}

void CFreesoftDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFreesoftDlg)
	DDX_Control(pDX, IDC_RICHEDIT_MESSAGE, m_cRichEdit_Message);
	DDX_Control(pDX, IDC_IPADDRESS_END, m_cIpAddress_End);
	DDX_Control(pDX, IDC_IPADDRESS_START, m_cIpAddress_Start);
	DDX_Control(pDX, IDC_TAB_DATA_LIST, m_cTabDataList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFreesoftDlg, CDialog)
	//{{AFX_MSG_MAP(CFreesoftDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENUITEM_EXIT, OnMenuitemExit)
	ON_BN_CLICKED(IDC_BUTTON_SCAN, OnButtonScan)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_DATA_LIST, OnSelchangeTabDataList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFreesoftDlg message handlers

BOOL CFreesoftDlg::OnInitDialog()
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
	// Set the ipaddress default value
	m_cIpAddress_Start.SetAddress(192,168,1,132); //设置ip地址默认范围
	m_cIpAddress_End.SetAddress(192,168,1,134);

	// Set the default TabList
	m_cTabDataList.InsertItem(0,_T("龙矿BTC-1T"));
	m_cTabDataList.InsertItem(1,_T("龙矿BTC-1.5T"));
	m_cTabDataList.InsertItem(2,_T("蚂蚁系列"));
	
	m_Dialog_LK_BTC1T.Create(IDD_DIALOG_LKBTC1T,GetDlgItem(IDC_TAB_DATA_LIST));
	m_Dialog_LK_BTC15T.Create(IDD_DIALOG_LKBTC15T,GetDlgItem(IDC_TAB_DATA_LIST));

	// Set the tab
	CRect rc;
	m_cTabDataList.GetClientRect(&rc);
	rc.top += 20;
	rc.bottom += 4;
	rc.left += 4;
	rc.right -= 20;
	m_Dialog_LK_BTC1T.MoveWindow(&rc);
	m_Dialog_LK_BTC15T.MoveWindow(&rc);

	m_Dialog_LK_BTC1T.SetWindowPos(NULL,0,0,rc.right - rc.left + 3  ,rc.bottom - rc.top - 10,SWP_NOMOVE);
	m_Dialog_LK_BTC15T.SetWindowPos(NULL,0,0,rc.right - rc.left + 3  ,rc.bottom - rc.top - 10,SWP_NOMOVE);
	
	m_Dialog_LK_BTC1T.m_cList_LK_BTC1T.SetWindowPos(NULL,0,0,rc.right - rc.left - 8,rc.bottom - rc.top -20,SWP_NOMOVE);
	m_Dialog_LK_BTC15T.m_cList_LK_BTC15T.SetWindowPos(NULL,0,0,rc.right - rc.left - 8,rc.bottom - rc.top -20,SWP_NOMOVE);
	

	m_Dialog_LK_BTC1T.ShowWindow(SW_SHOW);
	m_Dialog_LK_BTC15T.ShowWindow(SW_HIDE);

	m_cTabDataList.SetCurSel(0);
	
	// Set the Tab Dialog List
	// 1T
	m_Dialog_LK_BTC1T.m_cList_LK_BTC1T.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_Dialog_LK_BTC1T.m_cList_LK_BTC1T.SetHeadings(_T("IPAddress,90;总算力(5s),80;总算力(avg),80;池1用户,100;状态,75;池2用户,100;状态,75;池3用户,100;状态,75;运行时间,90;模组1温度,75;模组2温度,75;模组3温度,75;模组4温度75"));
	
	// 1.5T
	m_Dialog_LK_BTC15T.m_cList_LK_BTC15T.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_Dialog_LK_BTC15T.m_cList_LK_BTC15T.SetHeadings(_T("IPAddress,90;总算力(5s),80;总算力(avg),80;池1用户,100;状态,75;池2用户,100;状态,75;池3用户,100;状态,75;运行时间,90;模组1温度,75;模组2温度,75;模组3温度,75;模组4温度75"));
	
	
	// Test Data
	m_Dialog_LK_BTC1T.m_cList_LK_BTC1T.AddItem("192.168.1.1", _T("0"), _T("0"), _T("0"),_T("0"),  \
							_T("0"),_T("0"), _T("0"),_T("0"), _T("0"), _T("0"), _T("0"),_T("0"),_T("0"));

	m_Dialog_LK_BTC15T.m_cList_LK_BTC15T.AddItem("192.168.1.10", _T("0"), _T("0"), _T("0"),_T("0"),  \
							_T("0"),_T("0"), _T("0"),_T("0"), _T("0"), _T("0"), _T("0"),_T("0"),_T("0"));


	// Set the richedit some property
	m_cRichEdit_Message.PostMessage(WM_VSCROLL, SB_BOTTOM, 0);

	// Set the socket
	if(!m_UDPSocket.Create(myPORT,SOCK_DGRAM))
	{
		AfxMessageBox("Failed Create Socket");
	}
	char bs1[50]={0x0,0x00,0x0,0x10,0x0,0x1,0x0,0x0,0x0,0x0,
		0x0,0x0,0x20,0x43,0x4b,0x41,0x41,0x41,0x41,0x41,
		0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,
		0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,
		0x41,0x41,0x41,0x41,0x41,0x0,0x0,0x21,0x0,0x1};
	
	memcpy(bs,bs1,50);
	//////////////////////////////////////////////////////////////////////////
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFreesoftDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFreesoftDlg::OnPaint() 
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
HCURSOR CFreesoftDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFreesoftDlg::OnMenuitemExit() 
{
	// TODO: Add your command handler code here
	this->OnOK();
}

BOOL CFreesoftDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if((pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) || 
		(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) )  
		return TRUE;
	
    return CDialog::PreTranslateMessage(pMsg);
}


//////////////////////////////////////////////////////////////////////////
// Thread functions
//--------------------------nbtstat线程----------------------
UINT CFreesoftDlg::NetBiosThread(LPVOID param)
{
	MSG msg;
	CFreesoftDlg * pDlg = (CFreesoftDlg*)param;

	AfxMessageBox("Enter the thread");

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
		
		pDlg->m_strIP.Format("%d.%d.%d.%d",pDlg->B1[0],pDlg->B1[1],pDlg->B1[2],pDlg->B1[3]);//得到ip
		//		if(B1[3]!=0&&B1[2]!=0)  //此句限制了很多网段的扫描
		AfxMessageBox(pDlg->m_strIP);
		int len;
		if(pDlg->B1[3]!=0&&pDlg->B1[1]!=0)
			len = pDlg->m_UDPSocket.SendTo((void*)pDlg->bs,50,destPORT,pDlg->m_strIP,0);//向指定的ip发数据报
		
		if (len == 50)
		{
			WaitForSingleObject(
				pDlg->wait_handle,        // 等待事件的句柄
				20   // 超时
				);
			
			ResetEvent(pDlg->wait_handle);//将事件重新置回非触发状态
		}
		
		//=============================================
		//生成下一个要查询的ip
		if(pDlg->B1[2]<=pDlg->B2[2])
		{
			if(pDlg->B1[3]<pDlg->B2[3])pDlg->B1[3]++;
			else if(pDlg->B1[2]<pDlg->B2[2]&&pDlg->B1[3]<255)pDlg->B1[3]++;
			else if(pDlg->B1[2]<pDlg->B2[2]&&pDlg->B1[3]==255)
			{
				pDlg->B1[3]=0;
				pDlg->B1[2]++;
			}
		}
		else
			break;
		if(pDlg->B1[3]>=pDlg->B2[3]&&pDlg->B1[2]>=pDlg->B2[2])
			break;
	}while(pDlg->B1[2]<=255&&pDlg->B1[3]<=255);
	

	return 0;
}



// Receive function
void CFreesoftDlg::OnReceive()
{
	BYTE Buf[512];
	memset(Buf, 0, sizeof(Buf));
	CString str,strIP,strHost,strHex,strMac,Host,Group,User,command;
	UINT dport;

	// Receive the data
	m_UDPSocket.ReceiveFrom(Buf,512,strIP,dport,0);
	AfxMessageBox(strIP);
    // if receive the same ip then return.
	if(strIP==(char)NULL||strIP==strOldIP)
		return;
	strOldIP=strIP;
	
	strHost=""; // Machine Host
	strHex="";//MAC Address
	User="?";//
	Host="\\";
	int tem=0,num=0;
	bool bAdd=true;
	
	// 根据数据报规则取出相应的信息
	for(int i=57;i<500;i++) //57-72
	{
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
	
	if (Host == "RASPBERRYPI")
	{
		SCAN_PARAM SmParam;
		SmParam.IPADDRESS = strIP;
		SmParam.HOST = Host;
		SmParam.WORKGROUP = Group;
		SmParam.MACADDRESS = strMac;
		m_pScanTraffic->PutRecvMessage(&SmParam);
	}
	
	//触发事件，导致线程函数的继续执行
	SetEvent(wait_handle);
	return;	
}

//////////////////////////////////////////////////////////////////////////


void CFreesoftDlg::OnSelchangeTabDataList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int CurSel = m_cTabDataList.GetCurSel();
	
    switch(CurSel)
    {
	case 0:
		{
			m_Dialog_LK_BTC1T.ShowWindow(SW_SHOW);
			m_Dialog_LK_BTC15T.ShowWindow(SW_HIDE);
			m_iTab_Select = 0;
		}
		break;
	case 1:
		{
			m_Dialog_LK_BTC1T.ShowWindow(SW_HIDE);
			m_Dialog_LK_BTC15T.ShowWindow(SW_SHOW);
			m_iTab_Select = 1;
		}
		
		break;
	case 2:
		{
			AfxMessageBox("正在添加中，请耐心等候");
			m_cTabDataList.SetCurSel(m_iTab_Select);
		}
		break;
	case 3:
		{
			AfxMessageBox("正在添加中，请耐心等候");
			m_cTabDataList.SetCurSel(m_iTab_Select);
		}
		break;
	case 4:
		{
			AfxMessageBox("正在添加中，请耐心等候");
			m_cTabDataList.SetCurSel(m_iTab_Select);
		}
		break;
	case 5:
		{
			AfxMessageBox("正在添加中，请耐心等候");
			m_cTabDataList.SetCurSel(m_iTab_Select);
		}
		break;
	default:
		{
			m_iTab_Select = 0;
			m_cTabDataList.SetCurSel(m_iTab_Select);
			m_Dialog_LK_BTC1T.ShowWindow(SW_SHOW);
			m_Dialog_LK_BTC15T.ShowWindow(SW_HIDE);
		}
	}
	*pResult = 0;
}


void CFreesoftDlg::OnButtonScan() 
{
	// TODO: Add your control notification handler code here
	// Judge the ip is reasonable.
	m_cIpAddress_Start.GetAddress(B1[0],B1[1],B1[2],B1[3]);
	m_cIpAddress_End.GetAddress(B2[0],B2[1],B2[2],B2[3]);

	m_cRichEdit_Message.PostMessage(WM_VSCROLL, SB_BOTTOM, 0);

	// fill in message to richedit
	m_cRichEdit_Message.SetSel(-1, -1);
	m_cRichEdit_Message.ReplaceSel("开始监控系统，正在初始化\r\n");

	if(B2[2]<B1[2])
	{	
		AfxMessageBox("终止地址应大于起始地址！");
		m_cRichEdit_Message.SetSel(-1, -1);
        m_cRichEdit_Message.ReplaceSel("终止地址应大于起始地址\r\n");
		return ;
	}
	else if(B2[2]==B1[2]&&B2[3]<B1[3])
	{
		AfxMessageBox("终止地址应大于起始地址！");
		m_cRichEdit_Message.SetSel(-1, -1);
        m_cRichEdit_Message.ReplaceSel("终止地址应大于起始地址\r\n");
		return ;
	}
	if(B2[0]!=B1[0]||B2[1]!=B1[1])
	{
		AfxMessageBox("不支持A/B类网络");
		m_cRichEdit_Message.SetSel(-1, -1);
        m_cRichEdit_Message.ReplaceSel("不支持A/B类网络\r\n");
		return ;
	}

	// create a thread for send a netbios data
	m_thread = AfxBeginThread(NetBiosThread,(LPVOID)this,CREATE_NEW);

}
