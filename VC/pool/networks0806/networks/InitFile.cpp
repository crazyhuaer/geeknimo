// InitFile.cpp: implementation of the CInitFile class.
//

#include "stdafx.h"
#include "InitFile.h"
#include "imagehlp.h"//用于创建文件夹用的头文件，并且应该先加载库imagehlp.lib


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInitFile::CInitFile()
{
	m_sFileName = "";
}

CInitFile::~CInitFile()
{
}

/***************************************************************** 
** 函数名称: SetFileName()
** 输入参数: 保存文件的文件夹名NewFolderName,保存的文件名FileName
** 输    出: 返回文件的详细路径，包括创建的文件夹
** 函数功能: 设置文件夹名和文件名
** 创 建 人: 
** Version : 1.01 修改：张步阳2011.6.22
******************************************************************/
CString CInitFile::SetFileName(CString NewFolderName,CString FileName)
{
	GetModulePath();
	if (NewFolderName=="")
	{
		m_strFileParaPath=m_strFileParaPath+"\\";
	} 
	else
	{
		m_strFileParaPath=m_strFileParaPath+"\\"+NewFolderName+"\\";
	}	
	BOOL bRet=MakeSureDirectoryPathExists(m_strFileParaPath); //如果文件夹不存在，创建文件夹
	ASSERT(bRet);
	if (FileName=="")
	{
		m_sFileName = m_strFileParaPath;
	}
	else
	{
		m_sFileName =m_strFileParaPath+FileName;
	}	
	bRet=MakeSureDirectoryPathExists(m_sFileName); 
	ASSERT(bRet);
	return m_sFileName;
}

/***************************************************************** 
** 函数名称: SetFileName()
** 输入参数: 保存文件的文件夹名或文件名FileNameorNewFolderName
** 输    出: 返回文件的详细路径
** 函数功能: 设置文件夹名或文件名
** 创 建 人: 
** Version : 1.01 修改：张步阳2011.6.22
******************************************************************/
CString CInitFile::SetFileName(CString FileNameorNewFolderName)
{
	GetModulePath();
	if (0 < FileNameorNewFolderName.Find(".", 0))// 如果传给形参的是文件名
	{
		m_sFileName=m_strFileParaPath+"\\"+FileNameorNewFolderName;
	} 
	else//如果传给形参的是文件夹名
	{
		m_sFileName=m_strFileParaPath+"\\"+FileNameorNewFolderName+"\\";
	}		
	BOOL bRet=MakeSureDirectoryPathExists(m_sFileName); //如果文件夹或文件不存在，则创建
	ASSERT(bRet);
	return m_sFileName;
}

/***************************************************************** 
** 函数名称: SetInt()
** 输入参数: 
		Section		--系统配置文件还是各模块参数	
		Item		--要修改的参数名
		Value		--要修改的参数值
** 输    出: 无
** 函数功能: 修改配置文件中相应字段(整型)的值
** 创 建 人: 
** Version : 1.01    修改：张步阳2011.6.22
******************************************************************/
BOOL CInitFile::SetInt(CString Section, CString Item, int Value)
{
	CString strtemp;
	strtemp.Format("%d", Value);
	WriteFileString(Section, Item, strtemp);
	return TRUE;
}

/***************************************************************** 
** 函数名称: SetString()
** 输入参数: 
		Section		--系统配置文件还是各模块参数	
		Item		--要修改的参数名
		Value		--要修改的参数值
** 输    出: 无
** 函数功能: 修改配置文件中相应字段(字符串)的值
** 创 建 人: 
** Version : 1.01    修改：张步阳2011.6.22
******************************************************************/
BOOL CInitFile::SetString(CString Section, CString Item, CString Value)
{
	WriteFileString(Section, Item, Value);
	return TRUE;
}

/***************************************************************** 
** 函数名称: SetFloat()
** 输入参数: 
		Section		--系统配置文件还是各模块参数	
		Item		--参数名
		Value		--参数值
** 输    出: 无
** 函数功能: 修改配置文件中相应字段(浮点型)的值
** 创 建 人: 
** Version : 1.01    修改：张步阳2011.6.22
******************************************************************/
BOOL CInitFile::SetFloat(CString Section, CString Item, float Value)
{
	CString strtemp;
	strtemp.Format("%f", Value);
	WriteFileString(Section, Item, strtemp);
	return TRUE;
}

/***************************************************************** 
** 函数名称: GetString()
** 输入参数: 
		Section		--系统配置文件还是各模块参数	
		Item		--参数名
		Value		--参数值默认值
** 输    出: 参数值
** 函数功能: 得到配置文件中相应字段(字符串)的值
** 创 建 人: 
** Version : 1.01        修改：张步阳2011.6.22
******************************************************************/
CString CInitFile::GetString(CString Section, CString Item, CString Value)
{
	return GetFileString(Section, Item, Value);
}

/***************************************************************** 
** 函数名称: GetInt()
** 输入参数: 
		Section		--系统配置文件还是各模块参数	
		Item		--参数名
		Value		--参数值默认值
** 输    出: 参数值
** 函数功能: 得到配置文件中相应字段(整型)的值
** 创 建 人:
** Version : 1.01     修改：张步阳2011.6.22
******************************************************************/
int CInitFile::GetInt(CString Section, CString Item, int Value)
{
	CString strtemp;
	strtemp.Format("%d", Value);
	return atoi(GetFileString(Section, Item, strtemp));
}

/***************************************************************** 
** 函数名称: GetFloat()
** 输入参数: 
		Section		--系统配置文件还是各模块参数	
		Item		--参数名
		Value		--参数值默认值
** 输    出: 参数值
** 函数功能: 获取配置文件中相应字段(浮点型)的值
** 创 建 人: 
** Version : 1.01        修改：张步阳2011.6.22
******************************************************************/
float CInitFile::GetFloat(CString Section, CString Item, float Value)
{
	CString strtemp;
	strtemp.Format("%f", Value);
	return (float)atof(GetFileString(Section, Item, strtemp));
}

/***************************************************************** 
** 函数名称: ReadIniFile()
** 输入参数: 无
** 输    出: 无
** 函数功能: 读取配置文件
** 创 建 人: 
** Version : 1.01     修改：梅爽 2012.4.15
******************************************************************/
BOOL CInitFile::ReadIniFile()
{
	return TRUE;
}

/***************************************************************** 
** 函数名称: WriteIniFile()
** 输入参数: 无
** 输    出: 无
** 函数功能: 写配置文件
** 创 建 人: 
** Version : 1.01      修改：梅爽 2012.4.15
******************************************************************/
BOOL CInitFile::WriteIniFile()
{
	return TRUE;
}

/***************************************************************** 
** 函数名称: GetFileString()
** 输入参数: 
		Section		--系统配置文件还是各模块参数	
		Item		--参数名
		Value		--参数值默认值
** 输    出: 参数值
** 函数功能: 得到配置文件中相应字段(字符串)的值
** 创 建 人: 
** Version : 1.01           修改：梅爽 2012.4.15
******************************************************************/
CString CInitFile::GetFileString(CString Section, CString Item, CString Value)
{
	::GetPrivateProfileString(Section,Item,"",Value.GetBuffer(100),100,m_sFileName);
	return Value;
}

/***************************************************************** 
** 函数名称: WriteFileString()
** 输入参数: 
		Section		--系统配置文件还是各模块参数	
		Item		--参数名
		Value		--存放参数值
** 输    出: 无
** 函数功能: 修改配置文件中相应字段(字符串)的值
** 创 建 人: 
** Version : 1.01            修改：梅爽 2012.4.15
******************************************************************/
void CInitFile::WriteFileString(CString Section, CString Item, CString Value)
{
	::WritePrivateProfileString(Section,Item,Value,m_sFileName);
	return;
}

/***************************************************************** 
** 函数名称: GetModulePath()
** 输入参数: 无
** 输    出: 返回程序exe所在文件夹的上一级文件夹路径
** 函数功能: 获取模板文件的路径
** 创 建 人: 
** Version : 1.01 修改：梅爽  2012.4.15
******************************************************************/
CString CInitFile::GetModulePath()
{
	m_strFileParaPath=".";
	return m_strFileParaPath;
}