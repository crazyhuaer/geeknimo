; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNetworksDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "networks.h"

ClassCount=16
Class1=CNetworksApp
Class2=CNetworksDlg
Class3=CAboutDlg

ResourceCount=10
Resource1=IDD_ADMIN_REGISTER
Resource2=IDR_MAINFRAME
Class4=MyListCtrl
Class5=MyListCtrl1
Class6=MyHeaderCtrl
Resource3=IDD_DIALOG_SZLTC30M
Class7=CLoginDialog
Resource4=IDD_DIALOG_LTC30M
Class8=CModifyPassowrd
Resource5=IDD_DIALOG_UNKNOWTYPE
Class9=BTC1T
Class10=LTC30M
Class11=LTC60M
Resource6=IDD_DIALOG_BTC1T
Resource7=IDD_NETWORKS_DIALOG
Class12=CDialog_BTC1T
Class13=CDialogLTC30M
Class14=CDialogLTC60M
Resource8=IDD_DIALOG_LTC60M
Class15=UnknowType
Resource9=IDD_LOGIN_DIALOG
Class16=SZLTC30M
Resource10=IDR_MENU_CHOOSE

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

[DLG:IDD_NETWORKS_DIALOG]
Type=1
Class=CNetworksDlg
ControlCount=53
Control1=IDC_BUTTON_REFRESH,button,1342242816
Control2=IDC_STATIC,static,1073872896
Control3=IDC_SPIN_TIMEOUT,msctls_updown32,1073741856
Control4=IDC_EDIT1,edit,1082206336
Control5=IDC_STATIC_STATUS3,static,1342308864
Control6=IDC_SOFT_STATUS,static,1342308864
Control7=IDC_STATIC_IP_BEGIN,static,1342308864
Control8=IDC_IPADDRESS_START,SysIPAddress32,1342242816
Control9=IDC_STATIC_IP_END,static,1342308864
Control10=IDC_IPADDRESS_STOP,SysIPAddress32,1342242816
Control11=IDC_STATIC_IP_RANGE,static,1342308352
Control12=IDC_STATIC_URL1,static,1342308352
Control13=IDC_STATIC_URL2,static,1342308352
Control14=IDC_STATIC_URL3,static,1342308352
Control15=IDC_STATIC_URL_INFO,static,1342308352
Control16=IDC_EDIT_POOL1,edit,1350631552
Control17=IDC_EDIT_POOL2,edit,1350631552
Control18=IDC_EDIT_POOL3,edit,1350631552
Control19=IDC_STATIC_USERNAME1,static,1342308352
Control20=IDC_STATIC_USERNAME2,static,1342308352
Control21=IDC_STATIC_USERNAME3,static,1342308352
Control22=IDC_EDIT_USERNAME1,edit,1350631552
Control23=IDC_EDIT_USERNAME2,edit,1350631552
Control24=IDC_EDIT_USERNAME3,edit,1350631552
Control25=IDC_EDIT_PASSWORD1,edit,1350631552
Control26=IDC_EDIT_PASSWORD2,edit,1350631552
Control27=IDC_EDIT_PASSWORD3,edit,1350631552
Control28=IDC_STATIC_PD1,static,1342308352
Control29=IDC_STATIC_PD2,static,1342308352
Control30=IDC_STATIC_PD3,static,1342308352
Control31=IDC_SINGLE_UPDATE,button,1342242816
Control32=IDC_LIST1,listbox,1352728835
Control33=IDC_STATIC_LISTBOX,static,1342308352
Control34=IDC_REFRESH,button,1342242816
Control35=IDC_STATIC_STATUS2,static,1342308864
Control36=IDC_STATIC_MULTI,static,1342308864
Control37=IDC_SINGLE_REBOOT,button,1342242816
Control38=IDC_MUTIPLE_REBOOT,button,1342242816
Control39=IDC_STATIC_STATUS1,static,1342308352
Control40=IDC_STATIC_SINGLE,static,1342308864
Control41=IDC_CHECK1,button,1342242819
Control42=IDC_CHECK2,button,1342242819
Control43=IDC_CHECK3,button,1342242819
Control44=IDC_COMBO_DIFF,combobox,1344339971
Control45=IDC_STATIC_DIFF,static,1342308352
Control46=IDC_BUTTON_SUSPEND,button,1342242816
Control47=IDC_BUTTON_STOP,button,1342242816
Control48=IDC_STATIC_COIN_TYPE,static,1342308352
Control49=IDC_COMBO_COIN_TYPE,combobox,1344340227
Control50=IDC_STATIC,static,1342308352
Control51=IDC_COMBO_FRE,combobox,1344339971
Control52=IDC_TAB1,SysTabControl32,1342177280
Control53=IDC_CHECK_SINGLE_MACHINE,button,1342242819

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

[CLS:MyHeaderCtrl]
Type=0
HeaderFile=MyHeaderCtrl.h
ImplementationFile=MyHeaderCtrl.cpp
BaseClass=CHeaderCtrl
Filter=W
LastObject=MyHeaderCtrl

[DLG:IDD_LOGIN_DIALOG]
Type=1
Class=CLoginDialog
ControlCount=5
Control1=IDC_STATIC,static,1342308864
Control2=IDC_USERNAME,edit,1350631424
Control3=IDC_STATIC,static,1342308864
Control4=IDC_PASSWORD,edit,1350631456
Control5=IDC_BUTTON_LOGIN,button,1342242816

[CLS:CLoginDialog]
Type=0
HeaderFile=LoginDialog.h
ImplementationFile=LoginDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CLoginDialog
VirtualFilter=dWC

[MNU:IDR_MENU_CHOOSE]
Type=1
Class=CNetworksDlg
Command1=ID_MENUITEM32772
Command2=ID_MENUITEM32771
Command3=ID_MENUITEM32773
CommandCount=3

[DLG:IDD_ADMIN_REGISTER]
Type=1
Class=CModifyPassowrd
ControlCount=5
Control1=IDC_ModifyPassword,button,1342242816
Control2=IDC_EDIT1,edit,1350631584
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT2,edit,1350631584
Control5=IDC_STATIC,static,1342308352

[CLS:CModifyPassowrd]
Type=0
HeaderFile=ModifyPassowrd.h
ImplementationFile=ModifyPassowrd.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_ModifyPassword
VirtualFilter=dWC

[CLS:BTC1T]
Type=0
HeaderFile=BTC1T.h
ImplementationFile=BTC1T.cpp
BaseClass=CDialog
Filter=D
LastObject=BTC1T

[CLS:LTC30M]
Type=0
HeaderFile=LTC30M.h
ImplementationFile=LTC30M.cpp
BaseClass=CDialog
Filter=D

[CLS:LTC60M]
Type=0
HeaderFile=LTC60M.h
ImplementationFile=LTC60M.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_DIALOG_BTC1T]
Type=1
Class=CDialog_BTC1T
ControlCount=1
Control1=IDC_LIST_BTC1T,SysListView32,1350631425

[DLG:IDD_DIALOG_LTC30M]
Type=1
Class=CDialogLTC30M
ControlCount=1
Control1=IDC_LIST_LTC30M,SysListView32,1350631425

[DLG:IDD_DIALOG_LTC60M]
Type=1
Class=CDialogLTC60M
ControlCount=1
Control1=IDC_LIST_LTC60M,SysListView32,1350631425

[CLS:CDialog_BTC1T]
Type=0
HeaderFile=Dialog_BTC1T.h
ImplementationFile=Dialog_BTC1T.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_STATIC_COUNT
VirtualFilter=dWC

[CLS:CDialogLTC30M]
Type=0
HeaderFile=DialogLTC30M.h
ImplementationFile=DialogLTC30M.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST_LTC30M
VirtualFilter=dWC

[CLS:CDialogLTC60M]
Type=0
HeaderFile=DialogLTC60M.h
ImplementationFile=DialogLTC60M.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST_LTC60M
VirtualFilter=dWC

[DLG:IDD_DIALOG_UNKNOWTYPE]
Type=1
Class=UnknowType
ControlCount=1
Control1=IDC_LIST_UNKNOWTYPE,SysListView32,1350631425

[CLS:UnknowType]
Type=0
HeaderFile=UnknowType.h
ImplementationFile=UnknowType.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LIST_UNKNOWTYPE

[DLG:IDD_DIALOG_SZLTC30M]
Type=1
Class=SZLTC30M
ControlCount=1
Control1=IDC_LIST_SZLTC30M,SysListView32,1350631425

[CLS:SZLTC30M]
Type=0
HeaderFile=SZLTC30M.h
ImplementationFile=SZLTC30M.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

