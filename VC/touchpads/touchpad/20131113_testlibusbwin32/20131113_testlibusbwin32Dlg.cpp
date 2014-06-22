// 20131113_testlibusbwin32Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "20131113_testlibusbwin32.h"
#include "20131113_testlibusbwin32Dlg.h"
#include "lusb0_usb.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy20131113_testlibusbwin32Dlg dialog

CMy20131113_testlibusbwin32Dlg::CMy20131113_testlibusbwin32Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy20131113_testlibusbwin32Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy20131113_testlibusbwin32Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy20131113_testlibusbwin32Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy20131113_testlibusbwin32Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy20131113_testlibusbwin32Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy20131113_testlibusbwin32Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy20131113_testlibusbwin32Dlg message handlers

BOOL CMy20131113_testlibusbwin32Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy20131113_testlibusbwin32Dlg::OnPaint() 
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
HCURSOR CMy20131113_testlibusbwin32Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy20131113_testlibusbwin32Dlg::OnOK() 
{
	CString	my_vid = "";
	CString my_pid = "";
	usb_dev_handle	*handle;

	HANDLE	m_hDevice = INVALID_HANDLE_VALUE;
	CWinThread	*m_pReadReportThread = NULL;
	OVERLAPPED	ReadOverLapped;
	char	ReadReportBuffer[16] = {0};
	BYTE	KeyStatus = 0;
	volatile	BOOL	m_bReadReportRunFlag = FALSE;


	struct	usb_bus	*busses,*bus;
	usb_init();
	usb_find_busses();
	usb_find_devices();

	busses = usb_get_busses();

	for (bus = busses; bus; bus = bus->next)
	{
		struct	usb_device	*dev;
		for (dev = bus->devices; dev; dev = dev->next)
		{
			struct	usb_device_descriptor	*desc = &(dev->descriptor);

			if ((desc->idVendor==0x093a) && (desc->idProduct == 0x2510))
			{
				handle = usb_open(dev);
				if (!handle)
				{
					MessageBox("error opening device:\n%s\n",usb_strerror());
					return;
				}
			}
		}
	}

	usb_set_configuration(handle,1);
	usb_claim_interface(handle,0);
}
