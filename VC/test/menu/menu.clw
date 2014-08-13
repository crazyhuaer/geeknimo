; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMenuDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "menu.h"

ClassCount=3
Class1=CMenuApp
Class2=CMenuDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_DIALOG1
Resource2=IDR_MAINFRAME
Resource3=IDD_MENU_DIALOG
Resource4=IDR_MENU_CHOOSE

[CLS:CMenuApp]
Type=0
HeaderFile=menu.h
ImplementationFile=menu.cpp
Filter=N

[CLS:CMenuDlg]
Type=0
HeaderFile=menuDlg.h
ImplementationFile=menuDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_MENUITEM32771

[CLS:CAboutDlg]
Type=0
HeaderFile=menuDlg.h
ImplementationFile=menuDlg.cpp
Filter=D

[DLG:IDD_MENU_DIALOG]
Type=1
Class=CMenuDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BUTTON_GETUSERNAME,button,1342242816

[MNU:IDR_MENU_CHOOSE]
Type=1
Class=CMenuDlg
Command1=ID_MENUITEM32773
Command2=ID_MENUITEM32771
Command3=ID_MENUITEM32772
CommandCount=3

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

