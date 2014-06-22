
// Bar_TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Bar_Test.h"
#include "Bar_TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CBar_TestDlg 对话框




CBar_TestDlg::CBar_TestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBar_TestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBar_TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBar_TestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CBar_TestDlg 消息处理程序

BOOL CBar_TestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CRect rcClient;
	GetClientRect(&rcClient);

	if (!m_chart.Create(CRect(20, 20, rcClient.Width()-20, rcClient.Height() - 20), this, 1050 ))
	{
		if (!m_chart.GetSafeHwnd())
		{
			AfxMessageBox(_T("不能创建图表控件！"));
			return FALSE;
		}

		m_chart.Reset();
		m_chart.SetAutoScale(FALSE);
	}

	m_chart.SetTitle(_T("一个测试图，显示一些虚拟数据"));
	m_chart.SetBKColor(RGB(255, 255, 240));
	m_chart.ShowTooltip(TRUE);

	m_chart.AddBar(1600.356,_T("一月"), RGB(255,255,0));
	m_chart.AddBar(2841.5468,_T("二月"), RGB(255,0,0));
	m_chart.AddBar(1045.3258,_T("三月"), RGB(100,100,200));
	m_chart.AddBar(1502.215,_T("四月"), RGB(0,255,0));
	m_chart.AddBar(1467,_T("五月"), RGB(255,255,255));
	m_chart.AddBar(1678.354,_T("六月"), RGB(200,255,255));
	m_chart.AddBar(1785.689,_T("七月"), RGB(255,240,40));
	m_chart.AddBar(1283.099,_T("八月"), RGB(255,60,130));
	m_chart.AddBar(1554.879,_T("九月"), RGB(255,255,200));
	m_chart.AddBar(1400.10,_T("十月"), RGB(130,235,250));
	m_chart.AddBar(1600.556,_T("十一月"), RGB(100,150,200));
	m_chart.AddBar(1900.3546,_T("十二月"), RGB(150,240,80), TRUE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CBar_TestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CBar_TestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CBar_TestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

