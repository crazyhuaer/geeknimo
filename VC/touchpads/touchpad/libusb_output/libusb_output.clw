; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLibusb_outputDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "libusb_output.h"

ClassCount=2
Class1=CLibusb_outputApp
Class2=CLibusb_outputDlg

ResourceCount=3
Resource2=IDR_MAINFRAME
Resource3=IDD_LIBUSB_OUTPUT_DIALOG

[CLS:CLibusb_outputApp]
Type=0
HeaderFile=libusb_output.h
ImplementationFile=libusb_output.cpp
Filter=N

[CLS:CLibusb_outputDlg]
Type=0
HeaderFile=libusb_outputDlg.h
ImplementationFile=libusb_outputDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_RICHEDIT_OUTPUT_MESSAGE



[DLG:IDD_LIBUSB_OUTPUT_DIALOG]
Type=1
Class=CLibusb_outputDlg
ControlCount=2
Control1=IDC_BUTTON_DETECT,button,1342242816
Control2=IDC_RICHEDIT_OUTPUT_MESSAGE,RICHEDIT,1350631556

