// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkDirTreeWH
#define _C_CkDirTreeWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkDirTreeW CkDirTreeW_Create(void);
void CkDirTreeW_Dispose(HCkDirTreeW handle);
void CkDirTreeW_getBaseDir(HCkDirTreeW cHandle, HCkString retval);
void CkDirTreeW_putBaseDir(HCkDirTreeW cHandle, const wchar_t *newVal);
const wchar_t *CkDirTreeW_baseDir(HCkDirTreeW cHandle);
void CkDirTreeW_getDebugLogFilePath(HCkDirTreeW cHandle, HCkString retval);
void CkDirTreeW_putDebugLogFilePath(HCkDirTreeW cHandle, const wchar_t *newVal);
const wchar_t *CkDirTreeW_debugLogFilePath(HCkDirTreeW cHandle);
BOOL CkDirTreeW_getDoneIterating(HCkDirTreeW cHandle);
int CkDirTreeW_getFileSize32(HCkDirTreeW cHandle);
__int64 CkDirTreeW_getFileSize64(HCkDirTreeW cHandle);
void CkDirTreeW_getFullPath(HCkDirTreeW cHandle, HCkString retval);
const wchar_t *CkDirTreeW_fullPath(HCkDirTreeW cHandle);
void CkDirTreeW_getFullUncPath(HCkDirTreeW cHandle, HCkString retval);
const wchar_t *CkDirTreeW_fullUncPath(HCkDirTreeW cHandle);
BOOL CkDirTreeW_getIsDirectory(HCkDirTreeW cHandle);
void CkDirTreeW_getLastErrorHtml(HCkDirTreeW cHandle, HCkString retval);
const wchar_t *CkDirTreeW_lastErrorHtml(HCkDirTreeW cHandle);
void CkDirTreeW_getLastErrorText(HCkDirTreeW cHandle, HCkString retval);
const wchar_t *CkDirTreeW_lastErrorText(HCkDirTreeW cHandle);
void CkDirTreeW_getLastErrorXml(HCkDirTreeW cHandle, HCkString retval);
const wchar_t *CkDirTreeW_lastErrorXml(HCkDirTreeW cHandle);
BOOL CkDirTreeW_getRecurse(HCkDirTreeW cHandle);
void CkDirTreeW_putRecurse(HCkDirTreeW cHandle, BOOL newVal);
void CkDirTreeW_getRelativePath(HCkDirTreeW cHandle, HCkString retval);
const wchar_t *CkDirTreeW_relativePath(HCkDirTreeW cHandle);
BOOL CkDirTreeW_getVerboseLogging(HCkDirTreeW cHandle);
void CkDirTreeW_putVerboseLogging(HCkDirTreeW cHandle, BOOL newVal);
void CkDirTreeW_getVersion(HCkDirTreeW cHandle, HCkString retval);
const wchar_t *CkDirTreeW_version(HCkDirTreeW cHandle);
BOOL CkDirTreeW_AdvancePosition(HCkDirTreeW cHandle);
BOOL CkDirTreeW_BeginIterate(HCkDirTreeW cHandle);
BOOL CkDirTreeW_SaveLastError(HCkDirTreeW cHandle, const wchar_t *path);
#endif
