// InitFile.h: interface for the CInitFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INITFILE_H__743A0DE0_7D49_4FFF_96E7_478E0D34DEBC__INCLUDED_)
#define AFX_INITFILE_H__743A0DE0_7D49_4FFF_96E7_478E0D34DEBC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma comment (lib,"imagehlp.lib")

class CInitFile  
{
public:
	CInitFile();
	virtual ~CInitFile();
	CString m_strFileParaPath;	
	float GetFloat(CString Section, CString Item, float Value=0.0);
	BOOL SetFloat(CString Section, CString Item, float Value);
	CString SetFileName(CString NewFolderName,CString FileName);
	CString SetFileName(CString NewFolderNameorFileName);
	void WriteFileString(CString Section, CString Item, CString Value);
	CString GetFileString(CString Section, CString Item, CString Value="");	
	CString GetString(CString Section, CString Item, CString Value="");
	int GetInt(CString Section, CString Item, int Value=0);	
	BOOL SetString(CString Section, CString Item, CString Value);
	BOOL SetInt(CString Section, CString Item, int Value);	
	BOOL WriteIniFile();
	BOOL ReadIniFile();
	CString GetModulePath();
/*protected:*/
	CString m_sFileName;
	CStdioFile IniFile;
	BOOL  bFileExist;
	CStringArray FileContainer;
};

#endif // !defined(AFX_INITFILE_H__743A0DE0_7D49_4FFF_96E7_478E0D34DEBC__INCLUDED_)
