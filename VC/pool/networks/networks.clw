; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNetworksDlg
LastTemplate=CListCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "networks.h"

ClassCount=5
Class1=CNetworksApp
Class2=CNetworksDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=MyListCtrl
Class5=MyListCtrl1
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
ControlCount=37
Control1=IDC_LIST_IP_STATUS,SysListView32,1350631693
Control2=IDC_BUTTON_REFRESH,button,1342242816
Control3=IDC_STATIC,static,1073872896
Control4=IDC_SPIN_TIMEOUT,msctls_updown32,1073741856
Control5=IDC_EDIT1,edit,1082206336
Control6=IDC_STATIC,static,1342308864
Control7=IDC_SOFT_STATUS,static,1342308864
Control8=IDC_STATIC,static,1342308864
Control9=IDC_IPADDRESS_START,SysIPAddress32,1342242816
Control10=IDC_STATIC,static,1342308864
Control11=IDC_IPADDRESS_STOP,SysIPAddress32,1342242816
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDIT_POOL1,edit,1350631552
Control18=IDC_EDIT_POOL2,edit,1350631552
Control19=IDC_EDIT_POOL3,edit,1350631552
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_EDIT_USERNAME1,edit,1350631552
Control24=IDC_EDIT_USERNAME2,edit,1350631552
Control25=IDC_EDIT_USERNAME3,edit,1350631552
Control26=IDC_EDIT_PASSWORD1,edit,1350631552
Control27=IDC_EDIT_PASSWORD2,edit,1350631552
Control28=IDC_EDIT_PASSWORD3,edit,1350631552
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_SINGLE_UPDATE,button,1342242816
Control33=IDC_LIST1,listbox,1352728835
Control34=IDC_STATIC,static,1342308352
Control35=IDC_REFRESH,button,1342242816
Control36=IDC_STATIC,static,1342308864
Control37=IDC_STATIC_MULTI,static,1342308864

[CLS:MyListCtrl]
Type=0
HeaderFile=MyListCtrl.h
ImplementationFile=MyListCtrl.cpp
BaseClass=CListCtrl
Filter=W
LastObject=MyListCtrl

[CLS:MyListCtrl1]
Type=0
HeaderFile=MyListCtrl1.h
ImplementationFile=MyListCtrl1.cpp
BaseClass=CListCtrl
Filter=W
LastObject=MyListCtrl1

