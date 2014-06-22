// FullScreenTouchPadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FullScreenTouchPad.h"
#include "FullScreenTouchPadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFullScreenTouchPadDlg dialog

CFullScreenTouchPadDlg::CFullScreenTouchPadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFullScreenTouchPadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFullScreenTouchPadDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFullScreenTouchPadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFullScreenTouchPadDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFullScreenTouchPadDlg, CDialog)
	//{{AFX_MSG_MAP(CFullScreenTouchPadDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFullScreenTouchPadDlg message handlers

BOOL CFullScreenTouchPadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	RECT r;
	SystemParametersInfo( SPI_GETWORKAREA, sizeof(RECT), &r, 0 );
	SetWindowPos(NULL,
		r.left, r.top,
		r.right, r.bottom,
		SWP_SHOWWINDOW);


	CRect rcClient; 
	GetClientRect(&rcClient); 	

	//if (!m_TestBar.Create(CRect(20, 20, rcClient.Width()-20, rcClient.Height()-20), this, 1050 ))
	if (!m_TestBar.Create(CRect(0, 0, rcClient.Width()/10+20, rcClient.Height()/6+20), this, 6 )) 
	{ 
		if (!m_TestBar.GetSafeHwnd()) 
		{ 
			AfxMessageBox(_T("不能创建图表控件！")); 
			return FALSE; 
		} 
		m_TestBar.Reset(); 
		//m_TestBar.SetAutoScale(true); 
	} 

	//m_TestBar.SetTitle(_T("一个测试图，显示一些虚拟数据")); 
	m_TestBar.SetBKColor(RGB(255, 255, 240)); 
	m_TestBar.ShowTooltip(TRUE); 
	m_TestBar.AddBar(1,_T("1"),RGB(255,255,0)); 
	m_TestBar.AddBar(1,_T(""), RGB(255,0,0)); 
	m_TestBar.AddBar(2,_T(""), RGB(100,100,200)); 
	m_TestBar.AddBar(3,_T(""), RGB(0,255,0)); 
	m_TestBar.AddBar(4,_T(""), RGB(255,255,255)); 
	m_TestBar.AddBar(4,_T(""), RGB(200,255,255)); 
	m_TestBar.AddBar(6,_T(""), RGB(255,240,40)); 
	m_TestBar.AddBar(1,_T(""), RGB(255,60,130)); 
	m_TestBar.AddBar(2,_T(""), RGB(255,255,200)); 
	m_TestBar.AddBar(2,_T(""), RGB(130,235,250)); 
	m_TestBar.AddBar(3,_T(""),RGB(100,150,200)); 
	m_TestBar.AddBar(1,_T(""),RGB(255,255,0)); 
	m_TestBar.AddBar(1,_T(""), RGB(255,0,0)); 
	m_TestBar.AddBar(2,_T(""), RGB(100,100,200)); 
	m_TestBar.AddBar(3,_T(""), RGB(0,255,0)); 
	m_TestBar.AddBar(4,_T(""), RGB(255,255,255)); 
	m_TestBar.AddBar(4,_T(""), RGB(200,255,255)); 
	m_TestBar.AddBar(6,_T(""), RGB(255,240,40)); 
	m_TestBar.AddBar(1,_T(""), RGB(255,60,130)); 
	m_TestBar.AddBar(2,_T(""), RGB(255,255,200)); 
	m_TestBar.AddBar(2,_T(""), RGB(130,235,250)); 
	m_TestBar.AddBar(3,_T(""),RGB(100,150,200)); 
	m_TestBar.AddBar(1,_T(""),RGB(255,255,0)); 
	m_TestBar.AddBar(1,_T(""), RGB(255,0,0)); 
	m_TestBar.AddBar(2,_T(""), RGB(100,100,200)); 
	m_TestBar.AddBar(3,_T(""), RGB(0,255,0)); 
	m_TestBar.AddBar(4,_T(""), RGB(255,255,255)); 
	m_TestBar.AddBar(4,_T(""), RGB(200,255,255)); 
	m_TestBar.AddBar(6,_T(""), RGB(255,240,40)); 
	m_TestBar.AddBar(1,_T(""), RGB(255,60,130)); 
	m_TestBar.AddBar(2,_T(""), RGB(255,255,200)); 
	m_TestBar.AddBar(2,_T(""), RGB(130,235,250)); 
	m_TestBar.AddBar(3,_T(""),RGB(100,150,200)); 
	m_TestBar.AddBar(9,_T("64"), RGB(150,240,80), TRUE); 


	m_TestBar.SetTitle(_T("XPCB")); 
	m_TestBar.ShowBarText(1,FALSE,FALSE);
	m_TestBar.ShowLabel(TRUE,TRUE);
	m_TestBar.ShowGrid(FALSE,TRUE);
	m_TestBar.SetAutoScale(TRUE); 

	m_TestBar.SetWindowPos( 0, 0, 0,
		rcClient.Width()/4,
		rcClient.Height()/4 , SWP_NOMOVE);

	m_TestBar.Refresh();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFullScreenTouchPadDlg::OnPaint() 
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
HCURSOR CFullScreenTouchPadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
