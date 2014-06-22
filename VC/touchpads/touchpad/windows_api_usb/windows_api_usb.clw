; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWindows_api_usbDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "windows_api_usb.h"

ClassCount=4
Class1=CWindows_api_usbApp
Class2=CWindows_api_usbDlg

ResourceCount=3
Resource2=IDR_MAINFRAME
Resource3=IDD_WINDOWS_API_USB_DIALOG

[CLS:CWindows_api_usbApp]
Type=0
HeaderFile=windows_api_usb.h
ImplementationFile=windows_api_usb.cpp
Filter=N

[CLS:CWindows_api_usbDlg]
Type=0
HeaderFile=windows_api_usbDlg.h
ImplementationFile=windows_api_usbDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_WINDOWS_API_USB_DIALOG]
Type=1
Class=CWindows_api_usbDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

