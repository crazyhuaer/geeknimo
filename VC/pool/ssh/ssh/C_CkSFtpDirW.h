// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkSFtpDirWH
#define _C_CkSFtpDirWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkSFtpDirW CkSFtpDirW_Create(void);
void CkSFtpDirW_Dispose(HCkSFtpDirW handle);
void CkSFtpDirW_getDebugLogFilePath(HCkSFtpDirW cHandle, HCkString retval);
void CkSFtpDirW_putDebugLogFilePath(HCkSFtpDirW cHandle, const wchar_t *newVal);
const wchar_t *CkSFtpDirW_debugLogFilePath(HCkSFtpDirW cHandle);
void CkSFtpDirW_getLastErrorHtml(HCkSFtpDirW cHandle, HCkString retval);
const wchar_t *CkSFtpDirW_lastErrorHtml(HCkSFtpDirW cHandle);
void CkSFtpDirW_getLastErrorText(HCkSFtpDirW cHandle, HCkString retval);
const wchar_t *CkSFtpDirW_lastErrorText(HCkSFtpDirW cHandle);
void CkSFtpDirW_getLastErrorXml(HCkSFtpDirW cHandle, HCkString retval);
const wchar_t *CkSFtpDirW_lastErrorXml(HCkSFtpDirW cHandle);
int CkSFtpDirW_getNumFilesAndDirs(HCkSFtpDirW cHandle);
void CkSFtpDirW_getOriginalPath(HCkSFtpDirW cHandle, HCkString retval);
const wchar_t *CkSFtpDirW_originalPath(HCkSFtpDirW cHandle);
BOOL CkSFtpDirW_getVerboseLogging(HCkSFtpDirW cHandle);
void CkSFtpDirW_putVerboseLogging(HCkSFtpDirW cHandle, BOOL newVal);
void CkSFtpDirW_getVersion(HCkSFtpDirW cHandle, HCkString retval);
const wchar_t *CkSFtpDirW_version(HCkSFtpDirW cHandle);
HCkSFtpFileW CkSFtpDirW_GetFileObject(HCkSFtpDirW cHandle, int index);
BOOL CkSFtpDirW_GetFilename(HCkSFtpDirW cHandle, int index, HCkString outStr);
const wchar_t *CkSFtpDirW_getFilename(HCkSFtpDirW cHandle, int index);
BOOL CkSFtpDirW_SaveLastError(HCkSFtpDirW cHandle, const wchar_t *path);
#endif
