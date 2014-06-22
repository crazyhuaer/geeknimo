// ChooseatypeiniDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Chooseatypeini.h"
#include "ChooseatypeiniDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChooseatypeiniDlg dialog

CChooseatypeiniDlg::CChooseatypeiniDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChooseatypeiniDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChooseatypeiniDlg)
		// NOTE: the ClassWizard will add member initialization here
		mTypeCount = 0;
		FConfigFileName = "data\\Ts_Cali.ini";
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChooseatypeiniDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChooseatypeiniDlg)
	DDX_Control(pDX, IDC_SCREEN_TYPE, m_Screen_Type);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChooseatypeiniDlg, CDialog)
	//{{AFX_MSG_MAP(CChooseatypeiniDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_READ_BUTTON, OnReadButton)
	ON_BN_CLICKED(IDC_WRITE_BUTTON, OnWriteButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChooseatypeiniDlg message handlers

BOOL CChooseatypeiniDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	//////////////////////////////////////////////////////////////////////////

	// if the Ts_Cali.ini 文件存在则读取，不存在则让用户自行选取

	CFileFind fileFind;

	if (!fileFind.FindFile(FConfigFileName))
	{
		AfxMessageBox("配置文件不存在，请选择你需要载入的配置文件");
		// jump a dialog to choose a config file
		// if no config choose then exit 
		// else read it

		CFileDialog filedlg(TRUE);
		filedlg.m_ofn.lpstrFilter="Ini Files(*.ini)\0*.ini\0All Files(*.*)\0*.*\0\0";
		if(IDOK == filedlg.DoModal())
		{
			FConfigFileName = filedlg.GetPathName();
		}
		else
			CChooseatypeiniDlg::OnCancel();
	}
	else
	{
		AfxMessageBox("文件存在");
	}
	fileFind.Close();


	mInitFile.SetFileName("",FConfigFileName);
	mInitFile.ReadIniFile();
	mSection = "TYPE_CNT";

	mTypeCount = mInitFile.GetInt(mSection,"m_TypeCount");
	
	// if get 0 or less than 0
	if (mTypeCount <= 0)
	{
		AfxMessageBox("error");
		return TRUE;
	}
	
	// get the combo box IDC_SCREEN_TYPE
	CComboBox* pCComboBox = (CComboBox*)GetDlgItem(IDC_SCREEN_TYPE);
	CString		InsertItemData = "";	
	
	// Get the All Types Name
	int i = 0;
	for (i = 0; i < mTypeCount; i++)
	{
		mSection.Format("TYPE%d",i);	
		InsertItemData = mInitFile.GetString(mSection,"m_Name");
		pCComboBox->InsertString(i, _T(InsertItemData));
	}
	pCComboBox->SetCurSel(0);
	
	//////////////////////////////////////////////////////////////////////////
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CChooseatypeiniDlg::OnPaint() 
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
HCURSOR CChooseatypeiniDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CChooseatypeiniDlg::OnReadButton() 
{
	// TODO: Add your control notification handler code here
	// 初始化与读取数据
	
	mInitFile.SetFileName("data","Ts_Cali.ini");
	mInitFile.ReadIniFile();

	mSection = "TYPE_CNT";

	mTypeCount = mInitFile.GetInt(mSection,"m_TypeCount");
	
	// if get 0 or less than 0
	if (mTypeCount <= 0)
	{
		AfxMessageBox("error");
		return;
	}

	// get the combo box IDC_SCREEN_TYPE
	CComboBox* pCComboBox = (CComboBox*)GetDlgItem(IDC_SCREEN_TYPE);
	CString		InsertItemData = "";	

	// Get the All Types Name
	int i = 0;
	for (i = 0; i < mTypeCount; i++)
	{
		mSection.Format("TYPE%d",i);	
		InsertItemData = mInitFile.GetString(mSection,"m_Name");
		pCComboBox->InsertString(i, _T(InsertItemData));
	}
	pCComboBox->SetCurSel(0);

	//m_nlength=mInitFile.GetInt(mSection,"m_TypeCount");
	//m_fwidth=mInitFile.GetFloat(mSection,"width");
	//m_strname=mInitFile.GetString(mSection,"m_Name");
}

void CChooseatypeiniDlg::OnWriteButton() 
{
// 	// TODO: Add your control notification handler code here
// 	UpdateData(TRUE);
// 	mInitFile.SetFileName("data","Ts_Cali.ini");
// 	mSection = "TYPE_CNT";
// 	int m_nlength = 30;
// 	mInitFile.SetInt(mSection,"m_TypeCount",m_nlength);
// 	//mInitFile.SetFloat(mSection,"width",m_fwidth);
// 	//mInitFile.SetString(mSection,"name",m_strname);
// 	UpdateData(FALSE);
}
