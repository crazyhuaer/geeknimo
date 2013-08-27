// dialog_usb_testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dialog_usb_test.h"
#include "dialog_usb_testDlg.h"

#include "libusb.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_usb_testDlg dialog

CDialog_usb_testDlg::CDialog_usb_testDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_usb_testDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_usb_testDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	devs = NULL;
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialog_usb_testDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_usb_testDlg)
	DDX_Control(pDX, IDC_RICHEDIT_OUTPUT_MESSAGE, m_cRichEdit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDialog_usb_testDlg, CDialog)
	//{{AFX_MSG_MAP(CDialog_usb_testDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DETECT, OnButtonDetect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_usb_testDlg message handlers

BOOL CDialog_usb_testDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here


//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDialog_usb_testDlg::OnPaint() 
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
HCURSOR CDialog_usb_testDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDialog_usb_testDlg::OnButtonDetect() 
{
	// TODO: Add your control notification handler code here
	CString Temp;
	int r;
	ssize_t cnt;
	
	
	r = libusb_init(NULL);
	if (r < 0)
		return;
	
	cnt = libusb_get_device_list(NULL, &devs);
	if (cnt < 0)
		return;
	
	
	m_cRichEdit.UpdateData(TRUE);
	m_cRichEdit.SetWindowText("");
	Temp.Format("总共发现设备%d个\n",cnt);
	
	m_cRichEdit.SetSel(-1, -1);
	m_cRichEdit.ReplaceSel(Temp);
	
	m_cRichEdit.UpdateData(FALSE);
	libusb_device *dev;
	int i = 0;
	m_cRichEdit.UpdateData(TRUE);

	while ((dev = devs[i++]) != NULL) {
		struct libusb_device_descriptor desc;
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0) {
			AfxMessageBox("failed to get device descriptor");
			return;
		}
			
		Temp.Format("Vendor:%04x_Product:%04x (bus %d, device %d)\n",
			desc.idVendor, desc.idProduct,
			libusb_get_bus_number(dev), libusb_get_device_address(dev));
		m_cRichEdit.SetSel(-1, -1);
		m_cRichEdit.ReplaceSel(Temp);

			
	}
	m_cRichEdit.PostMessage(WM_VSCROLL, SB_BOTTOM, 0);
	m_cRichEdit.UpdateData(FALSE);

}
