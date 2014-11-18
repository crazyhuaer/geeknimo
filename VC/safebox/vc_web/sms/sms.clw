; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDialog_Login
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "sms.h"

ClassCount=5
Class1=CSmsApp
Class2=CSmsDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_DIALOG_LOGIN
Resource2=IDR_MAINFRAME
Class4=CDialog_Login
Resource3=IDD_SMS_DIALOG
Class5=CDialog_Main
Resource4=DIALOG_MAIN_PAGE

[CLS:CSmsApp]
Type=0
HeaderFile=sms.h
ImplementationFile=sms.cpp
Filter=N

[CLS:CSmsDlg]
Type=0
HeaderFile=smsDlg.h
ImplementationFile=smsDlg.cpp
Filter=D
LastObject=IDC_TAB_ALL
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=smsDlg.h
ImplementationFile=smsDlg.cpp
Filter=D

[DLG:IDD_SMS_DIALOG]
Type=1
Class=CSmsDlg
ControlCount=3
Control1=IDC_TAB_ALL,SysTabControl32,1342177280
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_LOGIN]
Type=1
Class=CDialog_Login
ControlCount=9
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308866
Control3=IDC_LOGIN_USERNAME,edit,1350631552
Control4=IDC_STATIC,static,1342308866
Control5=IDC_LOGIN_PASSWORD,edit,1350631584
Control6=IDC_LOGIN_ON,button,1342242816
Control7=IDC_STATIC,static,1342308866
Control8=IDC_SERVER_URL,edit,1350631552
Control9=IDC_STATIC,static,1342308352

[CLS:CDialog_Login]
Type=0
HeaderFile=Dialog_Login.h
ImplementationFile=Dialog_Login.cpp
BaseClass=CDialog
Filter=D
LastObject=CDialog_Login
VirtualFilter=dWC

[DLG:DIALOG_MAIN_PAGE]
Type=1
Class=CDialog_Main
ControlCount=13
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATUS_INFORMATION,RICHEDIT,1352730692
Control3=IDC_STATIC,button,1342177543
Control4=IDC_ON_OFF_TC35,button,1342242816
Control5=IDC_COM_NUMBER,combobox,1344348419
Control6=IDC_TEST_GPRS,button,1342242816
Control7=IDC_START_SEND,button,1342242816
Control8=IDC_STATIC,static,1342308864
Control9=IDC_DATA_URL,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_PERIOD_SEND,edit,1350639746
Control13=IDC_STATIC,static,1342308352

[CLS:CDialog_Main]
Type=0
HeaderFile=Dialog_Main.h
ImplementationFile=Dialog_Main.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_PERIOD_SEND
VirtualFilter=dWC

