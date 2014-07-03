// networksDlg.cpp : implementation file
//

#include "stdafx.h"
#include "networks.h"
#include "networksDlg.h"

#include "CkSsh.h"

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

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetworksDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetworksDlg)
	DDX_Control(pDX, IDC_REFRESH, m_bFresh);
	DDX_Control(pDX, IDC_LIST_IP_STATUS, m_ListCtrl);
	DDX_Control(pDX, IDC_STATIC_MULTI, m_Multi);
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
	DDX_Control(pDX, IDC_BUTTON_REFRESH, m_Button_Fresh);
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

	m_IPStart.SetAddress(192,168,1,1); //设置ip地址默认范围
	m_IPStop.SetAddress(192,168,1,255);
	m_PoolUrlEdit1.SetWindowText("http://uk1.ghash.io:3333");
	m_UsernameEdit1.SetWindowText("lketc");
	m_PasswordEdit1.SetWindowText("1234");
	m_PoolUrlEdit2.SetWindowText("stratum+tcp://stratum.f2pool.com:3333");
	m_UsernameEdit2.SetWindowText("qq123456");
	m_PasswordEdit2.SetWindowText("1234");
	m_PoolUrlEdit3.SetWindowText("stratum+tcp://");
	m_UsernameEdit3.SetWindowText("lkpool");
	m_PasswordEdit3.SetWindowText("1234");
	//pDlg->m_ListCtrl.SetBkColor(RGB(0,0,0));
	

	wait_handle=CreateEvent(NULL,true,false,"receive data");//创建处于非触发状态的事件。类型为手动
	// Init
	m_ListCtrl.InsertColumn(0, _T("IP"), LVCFMT_LEFT, 90, -1);
	m_ListCtrl.InsertColumn(1, _T("SV-STATUS"), LVCFMT_LEFT, 90);
	m_ListCtrl.InsertColumn(2,_T("BA1"),LVCFMT_LEFT, 30);
	m_ListCtrl.InsertColumn(3,_T("BA2"),LVCFMT_LEFT, 30);
	m_ListCtrl.InsertColumn(4,_T("BA3"),LVCFMT_LEFT, 30);
	m_ListCtrl.InsertColumn(5,_T("BA4"),LVCFMT_LEFT, 30);
	m_ListCtrl.InsertColumn(6,_T("SUM"),LVCFMT_LEFT, 40);
	m_ListCtrl.InsertColumn(7, _T("PL1"), LVCFMT_LEFT, 160);
	m_ListCtrl.InsertColumn(8, _T("PL1-STATUS"), LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(9, _T("PL2"), LVCFMT_LEFT, 160);
	m_ListCtrl.InsertColumn(10, _T("PL2-STATUS"), LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(11, _T("PL3"), LVCFMT_LEFT, 160);
	m_ListCtrl.InsertColumn(12, _T("PL3-STATUS"), LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(13, _T("RUN-TIME"), LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(14, _T("BA10-TEMP"), LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(15, _T("BA11-TEMP"), LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(16, _T("BA12-TEMP"), LVCFMT_LEFT, 75);
	m_ListCtrl.InsertColumn(17, _T("BA13-TEMP"), LVCFMT_LEFT, 75);
	
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
	//循环对要查询的ip发数据
	do
	{
		pDlg->m_strIP.Format("%d.%d.%d.%d",B1[0],B1[1],B1[2],B1[3]);//得到ip
		pDlg->m_ListBox.InsertString(0,pDlg->m_strIP);//将该ip插入ListView的ip字段
		
		//		if(B1[3]!=0&&B1[2]!=0)  //此句限制了很多网段的扫描
		int len;
		if(B1[3]!=0&&B1[1]!=0)
			len = pDlg->m_UDPSocket.SendTo((void*)pDlg->bs,50,destPORT,pDlg->m_strIP,0);//向指定的ip发数据报
		
		if (len == 50)
		{
			WaitForSingleObject(
				pDlg->wait_handle,        // 等待事件的句柄
				500   // 超时
				);
			ResetEvent(pDlg->wait_handle);//将事件重新置回非触发状态
		}
		
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
		pDlg->m_SoftStatus.SetWindowText("刷新完毕");
		pDlg->m_bFresh.EnableWindow(TRUE);
	}
	else
	{
		pDlg->m_Multi.SetWindowText("修改完毕");
		pDlg->m_Button_Fresh.EnableWindow(TRUE);
	}
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
	
	//CString hostname = "192.168.1.52";
	//int port = 22;
    success = ssh.Connect((LPTSTR)(LPCTSTR)hostname,port);
    if (success != true) {
        strOut.append(ssh.lastErrorText());
        strOut.append("\r\n");
        //SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
        return;
    }

    //  Wait a max of 5 seconds when reading responses..
    ssh.put_IdleTimeoutMs(8000);

    //  Authenticate using login/password:
    success = ssh.AuthenticatePw("pi","lk20140422smallfish");
    if (success != true) {
        strOut.append(ssh.lastErrorText());
        strOut.append("\r\n");
        //SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
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
	//if(strIP==(char)NULL||strIP==CMyPage->strOldIP)
	//	return -1;
	//CMyPage->strOldIP=strIP;
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

	CMyPage->m_ListBox.InsertString(0,strIP + " receive msg");
	if (Host == "RASPBERRYPI" && (CMyPage->bRef == false))
	{
		CMyPage->m_thread->SuspendThread();
		///////ssh 登陆后修改cgminer配置
		int idx =strIP.ReverseFind('.');
		
		CString url1, url2, url3;
		pDlg->m_PoolUrlEdit1.GetWindowText(url1);	
		pDlg->m_PoolUrlEdit2.GetWindowText(url2);
		pDlg->m_PoolUrlEdit3.GetWindowText(url3);
	
		CString user1, user2, user3;
		pDlg->m_UsernameEdit1.GetWindowText(user1);
		user1 += strIP.Mid(idx,strIP.GetLength());
		
		pDlg->m_UsernameEdit2.GetWindowText(user2);
		user2 += strIP.Mid(idx,strIP.GetLength()); 
		
		pDlg->m_UsernameEdit3.GetWindowText(user3);
		user3 += strIP.Mid(idx,strIP.GetLength());
		
		CString passwd1, passwd2, passwd3;
		pDlg->m_PasswordEdit1.GetWindowText(passwd1);		
		pDlg->m_PasswordEdit2.GetWindowText(passwd2);		
		pDlg->m_PasswordEdit3.GetWindowText(passwd3);

		command="echo ''> /var/config/user.log\r\necho "+url1+" > /var/config/user.log\r\n";
		command += "echo "+user1+" >>/var/config/user.log\r\n";
		command += "echo "+passwd1+" >>/var/config/user.log\r\n";
		command += "echo "+url2+" >> /var/config/user.log\r\n";
		command += "echo "+user2+" >>/var/config/user.log\r\n";
		command += "echo "+passwd2+" >>/var/config/user.log\r\n";
		command += "echo "+url3+" >> /var/config/user.log\r\n";
		command += "echo "+user3+" >>/var/config/user.log\r\n";
		command += "echo "+passwd3+" >>/var/config/user.log\r\n";
		command += "sudo pkill cgminer\r\n";
		CString cgminer="sudo /var/config/cgminer -o "+url1+" -u "+user1+" -p "+passwd1+" -o "+url2+" -u "+user2+" -p "+passwd2+" -o "+url3+" -u "+user3+" -p "+passwd3+"  --A1Pll1 1000 --A1Pll2 1000 --A1Pll3 1000 --A1Pll4 1000 --A1Pll5 1000 --api-listen --cs 8 --stmcu 0 -T --diff 128 > /var/www/cgminer.log&\r\n";
		command +=cgminer; 
		command += "echo '#!/bin/bash' > /var/config/run.sh\r\necho 'sudo chmod 777 /var/www/cgminer.log' >> /var/config/run.sh\r\necho '"+cgminer+"' >> /var/config/run.sh\r\n";

		pDlg->sshSrv(command, strIP, 22);
		pDlg->m_ListBox.InsertString(0, "ssh " + strIP + " success,modify cgminer configurate over");
		((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("ssh:"+strHost);
		CMyPage->m_ListCtrl.InsertItem(0, strIP);
		////////解析HTML获取矿机状态
		/*((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("strHost:"+strHost);
		// alive.
		CString line(strIP);
		
		idx = strIP.ReverseFind('.'); //idx 的值为4;
		
		line = line.Mid(idx+1, strIP.GetLength());
		
		CString thetemp;
		thetemp.Format("%d",atoi(line)-2);
		((CNetworksApp*)AfxGetApp())->m_Log.LogMessage("line:"+thetemp);
		
					ret = CMyPage->LkMachine_GetStatus(strIP,1,0);
		*/
		CMyPage->m_thread->ResumeThread();
	}

	if (Host == "RASPBERRYPI" && (CMyPage->bRef == true))
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
	//从ip控件得到要查询的ip范围
	m_IPStart.GetAddress(B1[0],B1[1],B1[2],B1[3]);
	m_IPStop.GetAddress(B2[0],B2[1],B2[2],B2[3]);
	//判断ip范围是否合法
	if(B2[2]<B1[2])
	{
		AfxMessageBox("终止地址应大于起始地址！");
		return ;
	}
	else if(B2[2]==B1[2]&&B2[3]<B1[3])
	{
		AfxMessageBox("终止地址应大于起始地址！");
		return ;
	}
	if(B2[0]!=B1[0]||B2[1]!=B1[1])
	{
		AfxMessageBox("不支持A类或B类网！");
		return ;
	}

	m_Multi.SetWindowText("正在修改多个机器配置");
	pDlg->bRef = false;
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
			m_ListCtrl.SetItemText(curline, 14+i,temp.Mid(1,iPos-1));
			
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
			BOOL	TrunRed = FALSE;
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

			CString		temp = FindBA(&strHtmlData);
			m_ListCtrl.SetItemText(line, 2,temp);
			strHtmlData = strHtmlData.Mid(3,strHtmlData.GetLength());

			if (temp == "")
			{
				TrunRed = TRUE;
			}

			temp = FindBA(&strHtmlData);
			m_ListCtrl.SetItemText(line, 3,temp);
			strHtmlData = strHtmlData.Mid(3,strHtmlData.GetLength());
	
			if (temp == "")
			{
				TrunRed = TRUE;
			}

			temp = FindBA(&strHtmlData);
			m_ListCtrl.SetItemText(line, 4,temp);
			strHtmlData = strHtmlData.Mid(3,strHtmlData.GetLength());

			if (temp == "")
			{
				TrunRed = TRUE;
			}

			temp = FindBA(&strHtmlData);
			m_ListCtrl.SetItemText(line, 5,temp);
			strHtmlData = strHtmlData.Mid(3,strHtmlData.GetLength());
		
			if (temp == "")
			{
				TrunRed = TRUE;
			}

			//CString ALLSpeed = FindSummary(&strHtmlData);
			m_ListCtrl.SetItemText(line, 6,FindSummary(&strHtmlData));
			strHtmlData = strHtmlData.Mid(3,strHtmlData.GetLength());

			CString Pool1Status = FindPoolStatus(&strHtmlData,line);


			//////////////////////////////////////////////////////////////////////////
			// 抓取温度、运行时间
			//////////////////////////////////////////////////////////////////////////	
			strUrl = "http://"+iDestAddr+"/miner.php?ref=0&pg=Stats";
			pstrURL = (char*)LPCTSTR(strUrl);
			pFile = (CHttpFile *) m_session.OpenURL(pstrURL, 1, 
				INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
			
			while (pFile->Read(&ch, sizeof(TCHAR)))
			{
				strHtmlData += ch;
			}		

			m_ListCtrl.SetItemText(line, 13,FindRunTime(&strHtmlData,line));
			
			CString findtemp = FindTemp(strHtmlData,line);

			if (findtemp == "1")
			{
				TrunRed = TRUE;
			}
			
			if (TrunRed)
			{
				m_ListCtrl.SetItemColor(line,RGB(255,0,0));
			}
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

    pDlg->m_ListCtrl.SetItemColor(0, RGB(255,0,0));

	CString url1, url2, url3;
	pDlg->m_PoolUrlEdit1.GetWindowText(url1);	
	pDlg->m_PoolUrlEdit2.GetWindowText(url2);
	pDlg->m_PoolUrlEdit3.GetWindowText(url3);
	
	CString user1, user2, user3;
	pDlg->m_UsernameEdit1.GetWindowText(user1);
	user1 += strIP.Mid(idx,strIP.GetLength());
	
	pDlg->m_UsernameEdit2.GetWindowText(user2);
	user2 += strIP.Mid(idx,strIP.GetLength()); 
	
	pDlg->m_UsernameEdit3.GetWindowText(user3);
	user3 += strIP.Mid(idx,strIP.GetLength());
	
	CString passwd1, passwd2, passwd3;
	pDlg->m_PasswordEdit1.GetWindowText(passwd1);		
	pDlg->m_PasswordEdit2.GetWindowText(passwd2);		
	pDlg->m_PasswordEdit3.GetWindowText(passwd3);
	
	command="echo ''> /var/config/user.log\r\necho "+url1+" > /var/config/user.log\r\n";
	command += "echo "+user1+" >>/var/config/user.log\r\n";
	command += "echo "+passwd1+" >>/var/config/user.log\r\n";
	command += "echo "+url2+" >> /var/config/user.log\r\n";
	command += "echo "+user2+" >>/var/config/user.log\r\n";
	command += "echo "+passwd2+" >>/var/config/user.log\r\n";
	command += "echo "+url3+" >> /var/config/user.log\r\n";
	command += "echo "+user3+" >>/var/config/user.log\r\n";
	command += "echo "+passwd3+" >>/var/config/user.log\r\n";
	command += "sudo pkill cgminer\r\n";
	CString cgminer="sudo /var/config/cgminer -o "+url1+" -u "+user1+" -p "+passwd1+" -o "+url2+" -u "+user2+" -p "+passwd2+" -o "+url3+" -u "+user3+" -p "+passwd3+"  --A1Pll1 1000 --A1Pll2 1000 --A1Pll3 1000 --A1Pll4 1000 --A1Pll5 1000 --api-listen --cs 8 --stmcu 0 -T --diff 128 > /var/www/cgminer.log&\r\n";
	command +=cgminer; 
	command += "echo '#!/bin/bash' > /var/config/run.sh\r\necho 'sudo chmod 777 /var/www/cgminer.log' >> /var/config/run.sh\r\necho '"+cgminer+"' >> /var/config/run.sh\r\n";
	
	pDlg->sshSrv(command, strIP, 22);
	
	pDlg->m_ListBox.InsertString(0, "modify "+strIP);
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
		AfxMessageBox("终止地址应大于起始地址！");
		return ;
	}
	else if(B2[2]==B1[2]&&B2[3]<B1[3])
	{
		AfxMessageBox("终止地址应大于起始地址！");
		return ;
	}
	if(B2[0]!=B1[0]||B2[1]!=B1[1])
	{
		AfxMessageBox("不支持A类或B类网！");
		return ;
	}
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	m_SoftStatus.SetWindowText("正在刷新系统机器状态");
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	pDlg->bRef = true;
	m_ListCtrl.DeleteAllItems(); 
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
	AfxBeginThread(ModifyOnerecordThread,(LPVOID)this,CREATE_SUSPENDED);
	//GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
}
