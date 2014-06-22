// version1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "version1.h"
#include "version1Dlg.h"
#include "AlexfStaticHistogram.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define IDC_STATICTEST 200
/////////////////////////////////////////////////////////////////////////////
// CVersion1Dlg dialog

CVersion1Dlg::CVersion1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVersion1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVersion1Dlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVersion1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVersion1Dlg)
	DDX_Control(pDX, IDC_HISTOGRAM, m_AlexfStaticHistogram);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVersion1Dlg, CDialog)
	//{{AFX_MSG_MAP(CVersion1Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_ORIGIN, OnButtonOrigin)
	ON_BN_CLICKED(IDC_BUTTON_LEFT, OnButtonLeft)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, OnButtonRight)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVersion1Dlg message handlers

BOOL CVersion1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
/*
			RECT r;
			SystemParametersInfo( SPI_GETWORKAREA, sizeof(RECT), &r, 0 );
			SetWindowPos(NULL,
				r.left, r.top,
				r.right, r.bottom,
				SWP_SHOWWINDOW);*/
	
/*	
	m_AlexfStaticHistogram.SetTextWidth(50); // Set text width (0 - no text)
	m_AlexfStaticHistogram.SetTextLines(5);  // Set number of text lines (0 - none)

		m_AlexfStaticHistogram.text[0] = "Z1";   // Set text (too easy to create special
		m_AlexfStaticHistogram.text[1] = "Zz2";  // function for that)
		// ...
		m_AlexfStaticHistogram.SetMaxValue(99.9); // Set relatival maximum*/

/*
	m_AlexfStaticHistogram.SetBackColor(RGB(255,255,255));
	m_AlexfStaticHistogram.SetMotionLtoR(FALSE);
	m_AlexfStaticHistogram.SetTextWidth(50);
	m_AlexfStaticHistogram.SetDataWidth(4);
	m_AlexfStaticHistogram.SetColor(RGB(255,0,0));

	m_AlexfStaticHistogram.SetTextLines(64);  // Set number of text lines (0 - none)
	m_AlexfStaticHistogram.text[0] = "0";   // Set text (too easy to create special
	m_AlexfStaticHistogram.text[1] = "8";  // function for that)
	m_AlexfStaticHistogram.text[2] = "16";
	m_AlexfStaticHistogram.text[3] = "24";
	m_AlexfStaticHistogram.text[4] = "32";
	m_AlexfStaticHistogram.text[5] = "40";
	m_AlexfStaticHistogram.text[6] = "48";
	m_AlexfStaticHistogram.text[7] = "56";
	m_AlexfStaticHistogram.text[8] = "64";*/

	m_AlexfStaticHistogram.Initialization();

	m_AlexfStaticHistogram.Add(50);          // Add new column to histogram
	m_AlexfStaticHistogram.Add(70); 
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);


	m_AlexfStaticHistogram.Add(50);          // Add new column to histogram
	m_AlexfStaticHistogram.Add(70); 
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);
	
	
	m_AlexfStaticHistogram.Add(50);          // Add new column to histogram
	m_AlexfStaticHistogram.Add(70); 
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);

	
	
	m_AlexfStaticHistogram.Add(50);          // Add new column to histogram
	m_AlexfStaticHistogram.Add(70); 
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);

	
	
	m_AlexfStaticHistogram.Add(50);          // Add new column to histogram
	m_AlexfStaticHistogram.Add(70); 
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);

	
	
	m_AlexfStaticHistogram.Add(50);          // Add new column to histogram
	m_AlexfStaticHistogram.Add(70); 
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);

	
	
	m_AlexfStaticHistogram.Add(50);          // Add new column to histogram
	m_AlexfStaticHistogram.Add(70); 
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);


	m_AlexfStaticHistogram.Add(50);          // Add new column to histogram
	m_AlexfStaticHistogram.Add(70); 
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);
	m_AlexfStaticHistogram.Add(90); 
	m_AlexfStaticHistogram.Add(30); 
	m_AlexfStaticHistogram.Add(70);

	
/*
		m_AlexfStaticHistogram_Test.Create( "My Static", WS_VISIBLE | WS_CHILD,
			CRect( 100, 100, 500, 500 ), this, IDC_STATICTEST );
		m_AlexfStaticHistogram_Test.ModifyStyleEx( 0, WS_EX_CLIENTEDGE, SWP_DRAWFRAME );*/
	


	//m_AlexfStaticHistogram.UPDATE(0,100.0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVersion1Dlg::OnPaint() 
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
HCURSOR CVersion1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CVersion1Dlg::OnButtonExit() 
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}

void CVersion1Dlg::OnButtonOrigin() 
{
	// TODO: Add your control notification handler code here
	m_AlexfStaticHistogram.UPDATE(1,100.0);
	m_AlexfStaticHistogram.UPDATE(0,100.0);
	m_AlexfStaticHistogram.RedrawWindow();
}

void CVersion1Dlg::OnButtonLeft() 
{
	// TODO: Add your control notification handler code here
	m_AlexfStaticHistogram.UPDATE(5,100.0);
	m_AlexfStaticHistogram.UPDATE(18,100.0);
	m_AlexfStaticHistogram.RedrawWindow();
}

void CVersion1Dlg::OnButtonRight() 
{
	// TODO: Add your control notification handler code here
	m_AlexfStaticHistogram.UPDATE(34,100.0);
	m_AlexfStaticHistogram.UPDATE(58,100.0);
	m_AlexfStaticHistogram.RedrawWindow();	
}
