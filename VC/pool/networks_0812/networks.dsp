# Microsoft Developer Studio Project File - Name="networks" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=networks - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "networks.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "networks.mak" CFG="networks - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "networks - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "networks - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "networks - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# SUBTRACT RSC /x
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 ChilkatDbgDll.lib ChilkatDbgMt.lib ChilkatDbgSt.lib ChilkatRelDll.lib ChilkatRelMt.lib ChilkatRelSt.lib ws2_32.lib Crypt32.lib Shlwapi.lib sqlite3.lib /nologo /subsystem:windows /profile /machine:I386 /nodefaultlib:"MSVCRTD" /out:"Release/networks.exe "

!ELSEIF  "$(CFG)" == "networks - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ChilkatDbgDll.lib ChilkatDbgMt.lib ChilkatDbgSt.lib ChilkatRelDll.lib ChilkatRelMt.lib ChilkatRelSt.lib ws2_32.lib Crypt32.lib Shlwapi.lib sqlite3.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "networks - Win32 Release"
# Name "networks - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Dialog_BTC1T.cpp
# End Source File
# Begin Source File

SOURCE=.\DialogLTC30M.cpp
# End Source File
# Begin Source File

SOURCE=.\DialogLTC60M.cpp
# End Source File
# Begin Source File

SOURCE=.\InitFile.cpp
# End Source File
# Begin Source File

SOURCE=.\Log.cpp
# End Source File
# Begin Source File

SOURCE=.\LoginDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\md5_password.cpp
# End Source File
# Begin Source File

SOURCE=.\ModifyPassowrd.cpp
# End Source File
# Begin Source File

SOURCE=.\MyHeaderCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\MyListCtrl1.cpp
# End Source File
# Begin Source File

SOURCE=.\networks.cpp
# End Source File
# Begin Source File

SOURCE=.\networks.rc
# End Source File
# Begin Source File

SOURCE=.\networksDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\UDP.cpp
# End Source File
# Begin Source File

SOURCE=.\UnknowType.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Dialog_BTC1T.h
# End Source File
# Begin Source File

SOURCE=.\DialogLTC30M.h
# End Source File
# Begin Source File

SOURCE=.\DialogLTC60M.h
# End Source File
# Begin Source File

SOURCE=.\InitFile.h
# End Source File
# Begin Source File

SOURCE=.\Log.h
# End Source File
# Begin Source File

SOURCE=.\LoginDialog.h
# End Source File
# Begin Source File

SOURCE=.\md5_password.h
# End Source File
# Begin Source File

SOURCE=.\ModifyPassowrd.h
# End Source File
# Begin Source File

SOURCE=.\MyHeaderCtrl.h
# End Source File
# Begin Source File

SOURCE=.\MyListCtrl1.h
# End Source File
# Begin Source File

SOURCE=.\networks.h
# End Source File
# Begin Source File

SOURCE=.\networksDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\UDP.h
# End Source File
# Begin Source File

SOURCE=.\UnknowType.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\networks.ico
# End Source File
# Begin Source File

SOURCE=.\res\networks.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
