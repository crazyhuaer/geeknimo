// networks.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "networks.h"
#include "networksDlg.h"
#include "LoginDialog.h"
#include "sqlite3.h"
#include <io.h>
#include <stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNetworksApp

BEGIN_MESSAGE_MAP(CNetworksApp, CWinApp)
	//{{AFX_MSG_MAP(CNetworksApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetworksApp construction

CNetworksApp::CNetworksApp():m_Log("log/"+((CTime)CTime::GetCurrentTime ()).Format ("20%y-%m-%d")+".log")
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CNetworksApp object

CNetworksApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CNetworksApp initialization

BOOL CNetworksApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	/////////////Êý¾Ý¿â
   	if( (_access( "./user.db", 0 )) == -1 )
	{
		char * pErrMsg = 0;  
		int ret = 0;  
		sqlite3 * db = 0;  
		ret = sqlite3_open("./user.db", &db);  
		if ( ret != SQLITE_OK )  
		{  
		AfxMessageBox(sqlite3_errmsg(db));  
		exit(1);  
		} 
		ret = sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);  
		
		  sqlite3_exec(db, "CREATE TABLE login(username varchar(64), password varchar(64));", NULL, NULL, NULL);
		  ret = sqlite3_exec(db, "INSERT INTO login VALUES('18d86ccba6c49512154e5abfe51eaa06','d8c993d0e022c4849ac0c27db27ecf69'); \
		  INSERT INTO login VALUES('5efb93a618588266af575fb8a381d60f','ccf82797241106ef5cbb8c28f2edd63d')", NULL, NULL, &pErrMsg); 
		  ret = sqlite3_exec(db, "COMMIT TRANSACTION;", NULL, NULL, NULL);                     
		  sqlite3_close(db);  
		  db = 0; 
	}
    /////////////////

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	/*
	CNetworksDlg dlg;
	m_pMainWnd = &dlg;
	*/

	CLoginDialog dlg;
	m_pMainWnd = &dlg;

	int nResponse = dlg.DoModal();

	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
