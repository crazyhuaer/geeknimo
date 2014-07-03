// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkSFtpDir_H
#define _C_CkSFtpDir_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkSFtpDir CkSFtpDir_Create(void);
void CkSFtpDir_Dispose(HCkSFtpDir handle);
void CkSFtpDir_getDebugLogFilePath(HCkSFtpDir cHandle, HCkString retval);
void CkSFtpDir_putDebugLogFilePath(HCkSFtpDir cHandle, const char *newVal);
const char *CkSFtpDir_debugLogFilePath(HCkSFtpDir cHandle);
void CkSFtpDir_getLastErrorHtml(HCkSFtpDir cHandle, HCkString retval);
const char *CkSFtpDir_lastErrorHtml(HCkSFtpDir cHandle);
void CkSFtpDir_getLastErrorText(HCkSFtpDir cHandle, HCkString retval);
const char *CkSFtpDir_lastErrorText(HCkSFtpDir cHandle);
void CkSFtpDir_getLastErrorXml(HCkSFtpDir cHandle, HCkString retval);
const char *CkSFtpDir_lastErrorXml(HCkSFtpDir cHandle);
int CkSFtpDir_getNumFilesAndDirs(HCkSFtpDir cHandle);
void CkSFtpDir_getOriginalPath(HCkSFtpDir cHandle, HCkString retval);
const char *CkSFtpDir_originalPath(HCkSFtpDir cHandle);
BOOL CkSFtpDir_getUtf8(HCkSFtpDir cHandle);
void CkSFtpDir_putUtf8(HCkSFtpDir cHandle, BOOL newVal);
BOOL CkSFtpDir_getVerboseLogging(HCkSFtpDir cHandle);
void CkSFtpDir_putVerboseLogging(HCkSFtpDir cHandle, BOOL newVal);
void CkSFtpDir_getVersion(HCkSFtpDir cHandle, HCkString retval);
const char *CkSFtpDir_version(HCkSFtpDir cHandle);
HCkSFtpFile CkSFtpDir_GetFileObject(HCkSFtpDir cHandle, int index);
BOOL CkSFtpDir_GetFilename(HCkSFtpDir cHandle, int index, HCkString outStr);
const char *CkSFtpDir_getFilename(HCkSFtpDir cHandle, int index);
BOOL CkSFtpDir_SaveLastError(HCkSFtpDir cHandle, const char *path);
#endif
