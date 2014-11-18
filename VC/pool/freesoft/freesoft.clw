; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFreesoftDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "freesoft.h"

ClassCount=7
Class1=CFreesoftApp
Class2=CFreesoftDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDR_MAINFRAME
Resource2=IDD_DIALOG_LKBTC1T
Resource3=IDD_DIALOG_LKBTC15T
Class4=CDialog_LKBTC1T
Class5=CMyListCtrl
Class6=CMyHeaderCtrl
Class7=CDialog_LK_BTC15T
Resource4=IDD_FREESOFT_DIALOG
Resource5=IDR_MENU_DIALOG

[CLS:CFreesoftApp]
Type=0
HeaderFile=freesoft.h
ImplementationFile=freesoft.cpp
Filter=N

[CLS:CFreesoftDlg]
Type=0
HeaderFile=freesoftDlg.h
ImplementationFile=freesoftDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CFreesoftDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=freesoftDlg.h
ImplementationFile=freesoftDlg.cpp
Filter=D

[DLG:IDD_FREESOFT_DIALOG]
Type=1
Class=CFreesoftDlg
ControlCount=9
Control1=IDC_STATIC,button,1342177287
Control2=IDC_TAB_DATA_LIST,SysTabControl32,1342177280
Control3=IDC_BUTTON_SCAN,button,1342242816
Control4=IDC_IPADDRESS_START,SysIPAddress32,1342242816
Control5=IDC_IPADDRESS_END,SysIPAddress32,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_RICHEDIT_MESSAGE,RICHEDIT,1352730692
Control9=IDC_STATIC,button,1342177287

[MNU:IDR_MENU_DIALOG]
Type=1
Class=?
Command1=ID_MENUITEM_EXIT
CommandCount=1

[DLG:IDD_DIALOG_LKBTC1T]
Type=1
Class=CDialog_LKBTC1T
ControlCount=1
Control1=IDC_LIST_LK_BTC1T,SysListView32,1350631685

[CLS:CDialog_LKBTC1T]
Type=0
HeaderFile=Dialog_LKBTC1T.h
ImplementationFile=Dialog_LKBTC1T.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LIST_LK_BTC1T

[CLS:CMyListCtrl]
Type=0
HeaderFile=mylistctrl.h
ImplementationFile=mylistctrl.cpp
BaseClass=CListCtrl
Filter=W

[CLS:CMyHeaderCtrl]
Type=0
HeaderFile=myheaderctrl.h
ImplementationFile=myheaderctrl.cpp
BaseClass=CHeaderCtrl
Filter=W

[DLG:IDD_DIALOG_LKBTC15T]
Type=1
Class=CDialog_LK_BTC15T
ControlCount=1
Control1=IDC_LIST_LK_BTC15T,SysListView32,1350631685

[CLS:CDialog_LK_BTC15T]
Type=0
HeaderFile=Dialog_LK_BTC15T.h
ImplementationFile=Dialog_LK_BTC15T.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST_LK_BTC15T
VirtualFilter=dWC

