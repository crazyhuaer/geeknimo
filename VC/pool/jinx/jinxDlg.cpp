// jinxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "jinx.h"
#include "jinxDlg.h"

#include <afxinet.h>
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>

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
// CJinxDlg dialog

CJinxDlg::CJinxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJinxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJinxDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJinxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJinxDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CJinxDlg, CDialog)
	//{{AFX_MSG_MAP(CJinxDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJinxDlg message handlers

BOOL CJinxDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.
	m_ListCtrl.InsertColumn(1, _T("SV-STATUS"), LVCFMT_LEFT, 90);
	m_ListCtrl.InsertColumn(2, _T("PL-STATUS"), LVCFMT_LEFT, 90);
	m_ListCtrl.InsertColumn(3,_T("BA1"),LVCFMT_LEFT, 60);
	m_ListCtrl.InsertColumn(4,_T("BA2"),LVCFMT_LEFT, 60);
	m_ListCtrl.InsertColumn(5,_T("BA3"),LVCFMT_LEFT, 60);
	m_ListCtrl.InsertColumn(6,_T("BA4"),LVCFMT_LEFT, 60);
	m_ListCtrl.InsertColumn(7,_T("SUM"),LVCFMT_LEFT, 60);
	m_ListCtrl.InsertColumn(0, _T("IP"), LVCFMT_LEFT, 90, -1);
	

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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CJinxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CJinxDlg::OnPaint() 
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
HCURSOR CJinxDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CJinxDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

// 
// ICMP header 
// 
typedef struct _ihdr { 
	BYTE i_type; 
	BYTE i_code; /* type sub code */ 
	USHORT i_cksum; 
	USHORT i_id; 
	USHORT i_seq; 
	/* This is not the std header, but we reserve space for time */ 
	ULONG timestamp; 
}IcmpHeader;

//checksum function
USHORT checksum(USHORT *buffer, int size) { 
	
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

int CJinxDlg::MyPing(CString szDestHost)
{
	WSADATA wsaData;   
    SOCKET sockRaw;   
    srand(time(NULL));  
    struct sockaddr_in dest,from;   
    char  recvbuf[100];    
    int fromlen = sizeof(from);    
    int timeout = 1000, i = 3; //超时时间为1秒   

    //WSAStartup完成对WinSocket服务的初始化  
    //MAKEWORD(2,1)表示请求使用的Socket版本,高位为副版本,低位为主版本,wsaData保存返回请求的Socket版本信息  
    if(WSAStartup(MAKEWORD(2,1),&wsaData))  
    {  
        ::AfxMessageBox("WINSOCK初始化失败!");  
        return -1;  
    }  
    
	sockRaw = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); //创建套接字,套接字类型为原始套接字   
    setsockopt(sockRaw, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout) );//设置套接字状态,限制接收时限   
    memset(&dest, 0, sizeof(dest));          

	dest.sin_addr.s_addr = inet_addr(szDestHost);
	dest.sin_family = AF_INET;   
    dest.sin_port = rand()%1024; //随机端口  
    char *icmp_data = new char[10];  
    memset(icmp_data, 0, sizeof(icmp_data));//清空分配到的空间 


	((IcmpHeader*)icmp_data)->i_type = 8; //为8表示回送请求  
    ((IcmpHeader*)icmp_data)->i_code = 0;   
    ((IcmpHeader*)icmp_data)->i_id = (u_short)GetCurrentProcessId(); //获得进程ID作为ICMP的ID号  
	((IcmpHeader*)icmp_data)->i_seq = 0; //序号  

	for(int k=0; k<i; k++)  
	{  
		((IcmpHeader*)icmp_data)->i_cksum = 0;//初始化ICMP的效验码为0  
        ((IcmpHeader*)icmp_data)->i_cksum = checksum((u_short *)icmp_data, 8);//计算效验码   
        sendto(sockRaw, icmp_data, 8, 0, (struct sockaddr*)&dest, sizeof(dest));//使用指定的套接字发送字节流数据到指定地址    
        int bread=recvfrom(sockRaw, recvbuf, 100, 0, (struct sockaddr*)&from, &fromlen);//接收数据   
        if (bread == SOCKET_ERROR)	
			return -1;
    }  

	return 0;
}

void CJinxDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString strHtmlData, iTmp, iDestAddr;
	TCHAR	ch;
	INT32   ret, i;
	
	for (i = 2; i < 255; i++)
	{	
		CString ipHead = "192.168.1.";
		iTmp.Format(_T("%d"),i);

		iDestAddr = ipHead + iTmp;
		ret =  MyPing(iDestAddr);
		if (ret < 0){
			m_ListCtrl.InsertItem(0, _T(iDestAddr));
			m_ListCtrl.SetItemText(0, 1, _T("down"));
			m_ListCtrl.SetItemText(0, 2, _T("down"));
			m_ListCtrl.SetItemText(0, 3, _T("0"));
			m_ListCtrl.SetItemText(0, 4, _T("0"));
			m_ListCtrl.SetItemText(0, 5, _T("0"));
			m_ListCtrl.SetItemText(0, 6, _T("0"));
			m_ListCtrl.SetItemText(0, 7, _T("0"));
			continue;
		}

		CString strURL = "http://192.168.1.";
		strURL += iTmp;
		strURL += "/miner.php";
		char *pstrURL = (char*)LPCTSTR(strURL);

		CInternetSession m_session;
		CHttpFile *pFile = (CHttpFile *) m_session.OpenURL(pstrURL, 1, 
			INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
		
		while (pFile->Read(&ch, sizeof(TCHAR)))
		{
			strHtmlData += ch;
		}
		
		//解析strData
		m_ListCtrl.InsertItem(1, _T("iDestAddr"));

		
		//清空
		iDestAddr = "0";
		strURL = "0";
	}
}
