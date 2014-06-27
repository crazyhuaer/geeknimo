// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkTarWH
#define _C_CkTarWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkTarW CkTarW_Create(void);
HCkTarW CkTarW_Create2(BOOL bCallbackOwned);
void CkTarW_Dispose(HCkTarW handle);
void CkTarW_getCharset(HCkTarW cHandle, HCkString retval);
void CkTarW_putCharset(HCkTarW cHandle, const wchar_t *newVal);
const wchar_t *CkTarW_charset(HCkTarW cHandle);
void CkTarW_getDebugLogFilePath(HCkTarW cHandle, HCkString retval);
void CkTarW_putDebugLogFilePath(HCkTarW cHandle, const wchar_t *newVal);
const wchar_t *CkTarW_debugLogFilePath(HCkTarW cHandle);
int CkTarW_getDirMode(HCkTarW cHandle);
void CkTarW_putDirMode(HCkTarW cHandle, int newVal);
void CkTarW_getDirPrefix(HCkTarW cHandle, HCkString retval);
void CkTarW_putDirPrefix(HCkTarW cHandle, const wchar_t *newVal);
const wchar_t *CkTarW_dirPrefix(HCkTarW cHandle);
int CkTarW_getFileMode(HCkTarW cHandle);
void CkTarW_putFileMode(HCkTarW cHandle, int newVal);
int CkTarW_getGroupId(HCkTarW cHandle);
void CkTarW_putGroupId(HCkTarW cHandle, int newVal);
void CkTarW_getGroupName(HCkTarW cHandle, HCkString retval);
void CkTarW_putGroupName(HCkTarW cHandle, const wchar_t *newVal);
const wchar_t *CkTarW_groupName(HCkTarW cHandle);
int CkTarW_getHeartbeatMs(HCkTarW cHandle);
void CkTarW_putHeartbeatMs(HCkTarW cHandle, int newVal);
void CkTarW_getLastErrorHtml(HCkTarW cHandle, HCkString retval);
const wchar_t *CkTarW_lastErrorHtml(HCkTarW cHandle);
void CkTarW_getLastErrorText(HCkTarW cHandle, HCkString retval);
const wchar_t *CkTarW_lastErrorText(HCkTarW cHandle);
void CkTarW_getLastErrorXml(HCkTarW cHandle, HCkString retval);
const wchar_t *CkTarW_lastErrorXml(HCkTarW cHandle);
BOOL CkTarW_getNoAbsolutePaths(HCkTarW cHandle);
void CkTarW_putNoAbsolutePaths(HCkTarW cHandle, BOOL newVal);
int CkTarW_getNumDirRoots(HCkTarW cHandle);
int CkTarW_getScriptFileMode(HCkTarW cHandle);
void CkTarW_putScriptFileMode(HCkTarW cHandle, int newVal);
BOOL CkTarW_getUntarCaseSensitive(HCkTarW cHandle);
void CkTarW_putUntarCaseSensitive(HCkTarW cHandle, BOOL newVal);
BOOL CkTarW_getUntarDebugLog(HCkTarW cHandle);
void CkTarW_putUntarDebugLog(HCkTarW cHandle, BOOL newVal);
BOOL CkTarW_getUntarDiscardPaths(HCkTarW cHandle);
void CkTarW_putUntarDiscardPaths(HCkTarW cHandle, BOOL newVal);
void CkTarW_getUntarFromDir(HCkTarW cHandle, HCkString retval);
void CkTarW_putUntarFromDir(HCkTarW cHandle, const wchar_t *newVal);
const wchar_t *CkTarW_untarFromDir(HCkTarW cHandle);
void CkTarW_getUntarMatchPattern(HCkTarW cHandle, HCkString retval);
void CkTarW_putUntarMatchPattern(HCkTarW cHandle, const wchar_t *newVal);
const wchar_t *CkTarW_untarMatchPattern(HCkTarW cHandle);
int CkTarW_getUntarMaxCount(HCkTarW cHandle);
void CkTarW_putUntarMaxCount(HCkTarW cHandle, int newVal);
int CkTarW_getUserId(HCkTarW cHandle);
void CkTarW_putUserId(HCkTarW cHandle, int newVal);
void CkTarW_getUserName(HCkTarW cHandle, HCkString retval);
void CkTarW_putUserName(HCkTarW cHandle, const wchar_t *newVal);
const wchar_t *CkTarW_userName(HCkTarW cHandle);
BOOL CkTarW_getVerboseLogging(HCkTarW cHandle);
void CkTarW_putVerboseLogging(HCkTarW cHandle, BOOL newVal);
void CkTarW_getVersion(HCkTarW cHandle, HCkString retval);
const wchar_t *CkTarW_version(HCkTarW cHandle);
void CkTarW_getWriteFormat(HCkTarW cHandle, HCkString retval);
void CkTarW_putWriteFormat(HCkTarW cHandle, const wchar_t *newVal);
const wchar_t *CkTarW_writeFormat(HCkTarW cHandle);
BOOL CkTarW_AddDirRoot(HCkTarW cHandle, const wchar_t *dirPath);
BOOL CkTarW_GetDirRoot(HCkTarW cHandle, int index, HCkString outStr);
const wchar_t *CkTarW_getDirRoot(HCkTarW cHandle, int index);
BOOL CkTarW_ListXml(HCkTarW cHandle, const wchar_t *tarPath, HCkString outStr);
const wchar_t *CkTarW_listXml(HCkTarW cHandle, const wchar_t *tarPath);
BOOL CkTarW_SaveLastError(HCkTarW cHandle, const wchar_t *path);
BOOL CkTarW_UnlockComponent(HCkTarW cHandle, const wchar_t *unlockCode);
int CkTarW_Untar(HCkTarW cHandle, const wchar_t *tarPath);
BOOL CkTarW_UntarBz2(HCkTarW cHandle, const wchar_t *tarPath);
BOOL CkTarW_UntarFirstMatchingToMemory(HCkTarW cHandle, HCkByteData tarFileBytes, const wchar_t *matchPattern, HCkByteData outBytes);
int CkTarW_UntarFromMemory(HCkTarW cHandle, HCkByteData tarFileBytes);
BOOL CkTarW_UntarGz(HCkTarW cHandle, const wchar_t *tarPath);
BOOL CkTarW_UntarZ(HCkTarW cHandle, const wchar_t *tarPath);
BOOL CkTarW_VerifyTar(HCkTarW cHandle, const wchar_t *tarPath);
BOOL CkTarW_WriteTar(HCkTarW cHandle, const wchar_t *tarPath);
BOOL CkTarW_WriteTarBz2(HCkTarW cHandle, const wchar_t *bz2Path);
BOOL CkTarW_WriteTarGz(HCkTarW cHandle, const wchar_t *gzPath);
#endif
