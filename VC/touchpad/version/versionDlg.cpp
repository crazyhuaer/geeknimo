// versionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "version.h"
#include "versionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IDC_HISTOGRAM 200
#define IDC_BUTTON	  300
/////////////////////////////////////////////////////////////////////////////
// CVersionDlg dialog

CVersionDlg::CVersionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVersionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVersionDlg)
		// NOTE: the ClassWizard will add member initialization here
		Button_ID_Increase = 0;
		Histogram_ID_Increase = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVersionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVersionDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVersionDlg, CDialog)
	//{{AFX_MSG_MAP(CVersionDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON, OnScanOrigin)
	ON_BN_CLICKED(IDC_BUTTON+1, OnScanLeft)
	ON_BN_CLICKED(IDC_BUTTON+2, OnScanRight)
	ON_BN_CLICKED(IDC_BUTTON+3, OnExit)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVersionDlg message handlers

BOOL CVersionDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	// Set Full Screen
	RECT r;
	SystemParametersInfo( SPI_GETWORKAREA, sizeof(RECT), &r, 0 );
	SetWindowPos(NULL,
		r.left, r.top,
		r.right, r.bottom,
	SWP_SHOWWINDOW);

	// Set the button of origin lef right
	m_ScanOrigin.Create("ÕýÉ¨",WS_VISIBLE,CRect(10,10,80,40),this,IDC_BUTTON + Button_ID_Increase++);
	m_ScanLeft.Create("×óÐ±É¨",WS_VISIBLE,CRect(90,10,160,40),this,IDC_BUTTON + Button_ID_Increase++);
	m_ScanRight.Create("ÓÒÐ±É¨",WS_VISIBLE,CRect(170,10,240,40),this,IDC_BUTTON + Button_ID_Increase++);
	m_Exit.Create("ÍË³ö",WS_VISIBLE,CRect(250,10,320,40),this,IDC_BUTTON + Button_ID_Increase++);

	// Set the control of histogram
	//0
	m_AlexfStaticHistogram[0].Create("XPAD1", WS_VISIBLE | WS_CHILD,
	CRect( 50, 50, 380, 370 ), this, IDC_HISTOGRAM + Histogram_ID_Increase++ );
	m_AlexfStaticHistogram[0].ModifyStyleEx( 0, WS_EX_CLIENTEDGE, SWP_DRAWFRAME );

	//1
	m_AlexfStaticHistogram[1].Create("XPAD2", WS_VISIBLE | WS_CHILD,
		CRect( 400, 50, 730, 370 ), this, IDC_HISTOGRAM + Histogram_ID_Increase++ );
	m_AlexfStaticHistogram[1].ModifyStyleEx( 0, WS_EX_CLIENTEDGE, SWP_DRAWFRAME );

	//2
	m_AlexfStaticHistogram[2].Create("XPAD3", WS_VISIBLE | WS_CHILD,
		CRect( 750, 50, 1080, 370 ), this, IDC_HISTOGRAM + Histogram_ID_Increase++ );
	m_AlexfStaticHistogram[2].ModifyStyleEx( 0, WS_EX_CLIENTEDGE, SWP_DRAWFRAME );

	//3
	m_AlexfStaticHistogram[3].Create("YPAD1", WS_VISIBLE | WS_CHILD,
		CRect( 50, 390, 380, 710 ), this, IDC_HISTOGRAM + Histogram_ID_Increase++ );
	m_AlexfStaticHistogram[3].ModifyStyleEx( 0, WS_EX_CLIENTEDGE, SWP_DRAWFRAME );

	//4
	m_AlexfStaticHistogram[4].Create("YPAD2", WS_VISIBLE | WS_CHILD,
		CRect( 400, 390, 730, 710 ), this, IDC_HISTOGRAM + Histogram_ID_Increase++ );
	m_AlexfStaticHistogram[4].ModifyStyleEx( 0, WS_EX_CLIENTEDGE, SWP_DRAWFRAME );

	// Initialization the Histogram
	for (int i=0;i<5;i++)
	{
		//m_AlexfStaticHistogram[i].Initialization();
		//m_AlexfStaticHistogram[i].Initialization(RGB(0,255,255),3,4,RGB(255,0,0),64);
		m_AlexfStaticHistogram[i].Initialization(RGB(0,255,255),3,4,RGB(255,0,0),64);
/*
		m_AlexfStaticHistogram[i].Add(10);
		m_AlexfStaticHistogram[i].Add(20);
		m_AlexfStaticHistogram[i].Add(30);
		m_AlexfStaticHistogram[i].Add(40);
		m_AlexfStaticHistogram[i].Add(50);
		m_AlexfStaticHistogram[i].Add(60);
		m_AlexfStaticHistogram[i].Add(50);
		m_AlexfStaticHistogram[i].Add(40);
		m_AlexfStaticHistogram[i].Add(20);
		m_AlexfStaticHistogram[i].Add(30);
		
		m_AlexfStaticHistogram[i].Add(10);
		m_AlexfStaticHistogram[i].Add(20);
		m_AlexfStaticHistogram[i].Add(30);
		m_AlexfStaticHistogram[i].Add(40);
		m_AlexfStaticHistogram[i].Add(50);
		m_AlexfStaticHistogram[i].Add(60);
		m_AlexfStaticHistogram[i].Add(50);
		m_AlexfStaticHistogram[i].Add(40);
		m_AlexfStaticHistogram[i].Add(20);
		m_AlexfStaticHistogram[i].Add(30);
		
		m_AlexfStaticHistogram[i].Add(10);
		m_AlexfStaticHistogram[i].Add(20);
		m_AlexfStaticHistogram[i].Add(30);
		m_AlexfStaticHistogram[i].Add(40);
		m_AlexfStaticHistogram[i].Add(50);
		m_AlexfStaticHistogram[i].Add(60);
		m_AlexfStaticHistogram[i].Add(50);
		m_AlexfStaticHistogram[i].Add(40);
		m_AlexfStaticHistogram[i].Add(20);
		m_AlexfStaticHistogram[i].Add(30);
		
		
		m_AlexfStaticHistogram[i].Add(10);
		m_AlexfStaticHistogram[i].Add(20);
		m_AlexfStaticHistogram[i].Add(30);
		m_AlexfStaticHistogram[i].Add(40);
		m_AlexfStaticHistogram[i].Add(50);
		m_AlexfStaticHistogram[i].Add(60);
		m_AlexfStaticHistogram[i].Add(50);
		m_AlexfStaticHistogram[i].Add(40);
		m_AlexfStaticHistogram[i].Add(20);
		m_AlexfStaticHistogram[i].Add(30);
		
		m_AlexfStaticHistogram[i].Add(10);
		m_AlexfStaticHistogram[i].Add(20);
		m_AlexfStaticHistogram[i].Add(30);
		m_AlexfStaticHistogram[i].Add(40);
		m_AlexfStaticHistogram[i].Add(50);
		m_AlexfStaticHistogram[i].Add(60);
		m_AlexfStaticHistogram[i].Add(50);
		m_AlexfStaticHistogram[i].Add(40);
		m_AlexfStaticHistogram[i].Add(20);
		m_AlexfStaticHistogram[i].Add(30);
		
		m_AlexfStaticHistogram[i].Add(10);
		m_AlexfStaticHistogram[i].Add(20);
		m_AlexfStaticHistogram[i].Add(30);
		m_AlexfStaticHistogram[i].Add(40);
		m_AlexfStaticHistogram[i].Add(50);
		m_AlexfStaticHistogram[i].Add(60);
		m_AlexfStaticHistogram[i].Add(50);
		m_AlexfStaticHistogram[i].Add(40);
		m_AlexfStaticHistogram[i].Add(20);
		m_AlexfStaticHistogram[i].Add(30);
		
		m_AlexfStaticHistogram[i].Add(50);
		m_AlexfStaticHistogram[i].Add(40);
		m_AlexfStaticHistogram[i].Add(20);
		m_AlexfStaticHistogram[i].Add(30);*/

	}
	
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVersionDlg::OnPaint() 
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
HCURSOR CVersionDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CVersionDlg::OnScanOrigin()
{
	m_AlexfStaticHistogram[0].UPDATE(0,50);
	m_AlexfStaticHistogram[0].UPDATE(4,50);
	m_AlexfStaticHistogram[0].UPDATE(8,50);
	m_AlexfStaticHistogram[0].RedrawWindow();
}

void CVersionDlg::OnScanLeft()
{
	m_AlexfStaticHistogram[0].UPDATE(3,50);
	m_AlexfStaticHistogram[0].UPDATE(7,50);
	m_AlexfStaticHistogram[0].UPDATE(9,50);	
	m_AlexfStaticHistogram[0].RedrawWindow();
}

void CVersionDlg::OnScanRight()
{
	m_AlexfStaticHistogram[0].UPDATE(11,50);
	m_AlexfStaticHistogram[0].UPDATE(16,50);
	m_AlexfStaticHistogram[0].UPDATE(26,50);
	m_AlexfStaticHistogram[0].RedrawWindow();
}

void CVersionDlg::OnExit()
{
	this->OnCancel();
}

BOOL CVersionDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE)  return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) return TRUE; 
	else
		return CDialog::PreTranslateMessage(pMsg);
}
