; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CVersion1Dlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "version1.h"

ClassCount=3
Class1=CVersion1App
Class2=CVersion1Dlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CAlexfStaticHistogram
Resource2=IDD_VERSION1_DIALOG

[CLS:CVersion1App]
Type=0
HeaderFile=version1.h
ImplementationFile=version1.cpp
Filter=N

[CLS:CVersion1Dlg]
Type=0
HeaderFile=version1Dlg.h
ImplementationFile=version1Dlg.cpp
Filter=D
LastObject=IDC_HISTOGRAM2
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_VERSION1_DIALOG]
Type=1
Class=CVersion1Dlg
ControlCount=5
Control1=IDC_HISTOGRAM,static,1342312448
Control2=IDC_BUTTON_ORIGIN,button,1342242816
Control3=IDC_BUTTON_LEFT,button,1342242816
Control4=IDC_BUTTON_RIGHT,button,1342242816
Control5=IDC_BUTTON_EXIT,button,1342242816

[CLS:CAlexfStaticHistogram]
Type=0
HeaderFile=AlexfStaticHistogram.h
ImplementationFile=AlexfStaticHistogram.cpp
BaseClass=CStatic
Filter=W
LastObject=CAlexfStaticHistogram

