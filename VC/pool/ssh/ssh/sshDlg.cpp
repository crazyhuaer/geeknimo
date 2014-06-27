// sshDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ssh.h"
#include "sshDlg.h"

#include "CkSsh.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
#define destPORT 137  //ssh name port
#define myPORT 3254

int i;
CSshDlg* pDlg;
BYTE bs[50]={0x0,0x00,0x0,0x10,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x20,0x43,0x4b,0x41,0x41,0x41,0x41,0x41,
0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,
0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,
0x41,0x41,0x41,0x41,0x41,0x0,0x0,0x21,0x0,0x1};

unsigned char B1[4],B2[4];
HANDLE wait_handle;

CString strOldIP="";


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
// CSshDlg dialog

CSshDlg::CSshDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSshDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSshDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//---------------------------------------------
	pDlg=this;
	AfxSocketInit();
	if(!m_UDPSocket.Create(myPORT,SOCK_DGRAM))
	{	
		CString str;
		str.Format("Error code:%d", CSocket::GetLastError());
		AfxMessageBox("Failed Create Socket\n"+str);
	}
	//---------------
}

void CSshDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSshDlg)
	DDX_Control(pDX, IDC_EDIT9, m_passwordEdit2);
	DDX_Control(pDX, IDC_EDIT8, m_passwordEdit3);
	DDX_Control(pDX, IDC_EDIT7, m_usernameEdit3);
	DDX_Control(pDX, IDC_EDIT6, m_usernameEdit2);
	DDX_Control(pDX, IDC_EDIT5, m_passwordEdit1);
	DDX_Control(pDX, IDC_EDIT4, m_usernameEdit1);
	DDX_Control(pDX, IDC_EDIT3, m_poolUrlEdit3);
	DDX_Control(pDX, IDC_EDIT2, m_poolUrlEdit2);
	DDX_Control(pDX, IDC_EDIT1, m_poolUrlEdit1);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_IPADDRESS2, m_IPEdit2);
	DDX_Control(pDX, IDC_IPADDRESS1, m_IPEdit1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSshDlg, CDialog)
	//{{AFX_MSG_MAP(CSshDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSshDlg message handlers

BOOL CSshDlg::OnInitDialog()
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
	m_IPEdit1.SetAddress(192,168,1,1); //设置ip地址默认范围
	m_IPEdit2.SetAddress(192,168,1,255);
	wait_handle=CreateEvent(NULL,true,false,"receive data");//创建处于非触发状态的事件。类型为手动
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSshDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSshDlg::OnPaint() 
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
HCURSOR CSshDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//--------------------------nbtstat线程----------------------
UINT sshThread(LPVOID param)
{
	//循环对要查询的ip发数据
	do
	{
		pDlg->m_strIP.Format("%d.%d.%d.%d",B1[0],B1[1],B1[2],B1[3]);//得到ip
		pDlg->m_ListBox.InsertString(0,pDlg->m_strIP);//将该ip插入ListView的ip字段
		
		//		if(B1[3]!=0&&B1[2]!=0)  //此句限制了很多网段的扫描
		int len;
		if(B1[3]!=0&&B1[1]!=0) 
			len = pDlg->m_UDPSocket.SendTo((void*)bs,50,destPORT,pDlg->m_strIP,0);//向指定的ip发数据报
		
		if (len == 50)
		{
			WaitForSingleObject(
				wait_handle,        // 等待事件的句柄
				500   // 超时
				);
			ResetEvent(wait_handle);//将事件重新置回非触发状态
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
	pDlg->m_ListBox.InsertString(0,"-----complete!-----");
	
	return 0;
}
//-----------------------------------------------------------

UINT processSSH(LPVOID param)
{
	BYTE Buf[512];
	memset(Buf, 0, sizeof(Buf));
	CString str,strIP,strHost,strHex,strMac,Host,Group,User,command, strHostTmp;
	UINT dport;
	pDlg->m_UDPSocket.ReceiveFrom(Buf,512,strIP,dport,0);//接收数据
    //如果接收到的ip为空或者与原来接收到的ip相同，则返回
	if(strIP==(char)NULL||strIP==strOldIP)
		return 0;
	strOldIP=strIP;
	strHost=""; //机器名字
	strHex="";//MAC地址
	User="?";//
	Host="\\";
	command="";
	int tem=0,num=0;
	bool bAdd=true;
	//根据数据报规则取出相应的信息
	for(i=57;i<500;i++) //57-72
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
				//m_ListView.SetItem(index,2,LVIF_TEXT,strHost, 0, 0, 0,0);  //机器名
				
				Host=strHost;
				num++;
			}
			else
			{
				if(Host!=strHost && num==1&& strHost!="")
				{
					//m_ListView.SetItem(index,1,LVIF_TEXT,strHost, 0, 0, 0,0);  //工作组名
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
							//m_ListView.SetItem(index,3,LVIF_TEXT,User, 0, 0, 0,0);
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
	//AfxMessageBox(strIP);
	//AfxMessageBox(Host);
	if (Host == "RASPBERRYPI")
	{
		int idx =strIP.ReverseFind('.');
				
		CString url1, url2, url3;
		pDlg->m_poolUrlEdit1.GetWindowText(url1);
		if (url1=="")
			url1="http://uk1.ghash.io:3333";
		
		pDlg->m_poolUrlEdit2.GetWindowText(url2);
		if (url2=="")
			url2="stratum+tcp://stratum.f2pool.com:3333";
		
		pDlg->m_poolUrlEdit3.GetWindowText(url3);
		if (url3=="")
			url3="http://baidu.com";
		
		CString user1, user2, user3;
		pDlg->m_usernameEdit1.GetWindowText(user1);
		if (user1=="")
			user1="lketc.10";
		else
			user1 += strIP.Mid(idx,strIP.GetLength());

		pDlg->m_usernameEdit2.GetWindowText(user2);
		if (user2=="")
			user2="qq123456.10";
		else
			user2 += strIP.Mid(idx,strIP.GetLength()); 

		pDlg->m_usernameEdit3.GetWindowText(user3);
		if (user3=="")
			user3="lkpool3";
		else
			user3 += strIP.Mid(idx,strIP.GetLength());
		
		CString passwd1, passwd2, passwd3;
		pDlg->m_passwordEdit1.GetWindowText(passwd1);
		if (passwd1=="")
			passwd1="1234";

		pDlg->m_passwordEdit2.GetWindowText(passwd2);
		if (passwd2=="")
			passwd2="1234";
		else 
			passwd2="lkpool";

		pDlg->m_passwordEdit3.GetWindowText(passwd3);
		if (passwd3=="")
			passwd3="lkpool";
		
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
	}
	//触发事件，导致线程函数的继续执行
	SetEvent(wait_handle);
	return 0;
}

void CSshDlg::OnReceive()
{
	CWinThread *pThread = AfxBeginThread(processSSH,(LPVOID)0,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
	pThread->m_bAutoDelete=FALSE;
	int suspendCnt=pThread->ResumeThread();
	
	DWORD exitcode;
	do{
		
		BOOL result = GetExitCodeThread(pThread, &exitcode);
			
		Sleep(200);
			
	}while(exitcode == STILL_ACTIVE);
}

void CSshDlg::OnButton1() 
{

	//从ip控件得到要查询的ip范围
	m_IPEdit1.GetAddress(B1[0],B1[1],B1[2],B1[3]);
	m_IPEdit2.GetAddress(B2[0],B2[1],B2[2],B2[3]);
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

	AfxBeginThread(sshThread,this->GetSafeHwnd(),THREAD_PRIORITY_NORMAL);
}


void CSshDlg::sshSrv(CString command, CString hostname, int port)
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
    ssh.put_IdleTimeoutMs(5000);

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
        strOut.append(ssh.lastErrorText());
        strOut.append("\r\n");
        //SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
        return;
    }

    //  Start a shell on the channel:
    success = ssh.SendReqShell(channelNum);
    if (success != true) {
        strOut.append(ssh.lastErrorText());
        strOut.append("\r\n");
        //SetDlgItemText(IDC_EDIT1,strOut.getUnicode());
        return;
    }

	//  Start a command in the remote shell.  This example
	//  will send a "ls" command to retrieve the directory listing.
	success = ssh.ChannelSendString(channelNum,command,"ansi");
	if (success != true) {
		strOut.append(ssh.lastErrorText());
		strOut.append("\r\n");
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

