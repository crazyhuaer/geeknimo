; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNetworksDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "networks.h"

ClassCount=3
Class1=CNetworksApp
Class2=CNetworksDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_NETWORKS_DIALOG

[CLS:CNetworksApp]
Type=0
HeaderFile=networks.h
ImplementationFile=networks.cpp
Filter=N

[CLS:CNetworksDlg]
Type=0
HeaderFile=networksDlg.h
ImplementationFile=networksDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CNetworksDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=networksDlg.h
ImplementationFile=networksDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NETWORKS_DIALOG]
Type=1
Class=CNetworksDlg
ControlCount=7
Control1=IDC_LIST_IP_STATUS,SysListView32,1350631693
Control2=IDC_BUTTON_REFRESH,button,1342242816
Control3=IDC_STATIC,static,1073872896
Control4=IDC_SPIN_TIMEOUT,msctls_updown32,1073741856
Control5=IDC_EDIT1,edit,1082206336
Control6=IDC_STATIC,static,1342308864
Control7=IDC_SOFT_STATUS,static,1342308864

