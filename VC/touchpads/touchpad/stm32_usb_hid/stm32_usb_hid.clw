; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CStm32_usb_hidDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "stm32_usb_hid.h"

ClassCount=2
Class1=CStm32_usb_hidApp
Class2=CStm32_usb_hidDlg

ResourceCount=3
Resource2=IDR_MAINFRAME
Resource3=IDD_STM32_USB_HID_DIALOG

[CLS:CStm32_usb_hidApp]
Type=0
HeaderFile=stm32_usb_hid.h
ImplementationFile=stm32_usb_hid.cpp
Filter=N

[CLS:CStm32_usb_hidDlg]
Type=0
HeaderFile=stm32_usb_hidDlg.h
ImplementationFile=stm32_usb_hidDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT_VID



[DLG:IDD_STM32_USB_HID_DIALOG]
Type=1
Class=CStm32_usb_hidDlg
ControlCount=10
Control1=IDC_BUTTON_DETECT,button,1342242816
Control2=IDC_RICHEDIT_OUTPUT_MESSAGE,RICHEDIT,1352728772
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_VID,edit,1350631552
Control6=IDC_EDIT_PID,edit,1350631552
Control7=IDC_BUTTON_READREPORT,button,1342242816
Control8=IDC_BUTTON_WRITEREPORT,button,1342242816
Control9=IDC_BUTTON_CLEAR,button,1342242816
Control10=IDC_BUTTON_OTHER,button,1342242816

