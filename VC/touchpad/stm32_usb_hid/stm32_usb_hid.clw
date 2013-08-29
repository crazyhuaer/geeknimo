; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CStm32_usb_hidDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "stm32_usb_hid.h"

ClassCount=4
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



[DLG:IDD_STM32_USB_HID_DIALOG]
Type=1
Class=CStm32_usb_hidDlg
ControlCount=1
Control1=IDC_BUTTON_DETECT,button,1342242816

