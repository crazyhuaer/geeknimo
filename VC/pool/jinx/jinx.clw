; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CJinxDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "jinx.h"

ClassCount=3
Class1=CJinxApp
Class2=CJinxDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_JINX_DIALOG

[CLS:CJinxApp]
Type=0
HeaderFile=jinx.h
ImplementationFile=jinx.cpp
Filter=N

[CLS:CJinxDlg]
Type=0
HeaderFile=jinxDlg.h
ImplementationFile=jinxDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CJinxDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=jinxDlg.h
ImplementationFile=jinxDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_JINX_DIALOG]
Type=1
Class=CJinxDlg
ControlCount=2
Control1=IDC_LIST_IP_STATUS,SysListView32,1350631437
Control2=IDC_BUTTON_REFRESH,button,1342242816

