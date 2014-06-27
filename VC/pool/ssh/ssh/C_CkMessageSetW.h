// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkMessageSetWH
#define _C_CkMessageSetWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkMessageSetW CkMessageSetW_Create(void);
void CkMessageSetW_Dispose(HCkMessageSetW handle);
int CkMessageSetW_getCount(HCkMessageSetW cHandle);
void CkMessageSetW_getDebugLogFilePath(HCkMessageSetW cHandle, HCkString retval);
void CkMessageSetW_putDebugLogFilePath(HCkMessageSetW cHandle, const wchar_t *newVal);
const wchar_t *CkMessageSetW_debugLogFilePath(HCkMessageSetW cHandle);
BOOL CkMessageSetW_getHasUids(HCkMessageSetW cHandle);
void CkMessageSetW_putHasUids(HCkMessageSetW cHandle, BOOL newVal);
void CkMessageSetW_getLastErrorHtml(HCkMessageSetW cHandle, HCkString retval);
const wchar_t *CkMessageSetW_lastErrorHtml(HCkMessageSetW cHandle);
void CkMessageSetW_getLastErrorText(HCkMessageSetW cHandle, HCkString retval);
const wchar_t *CkMessageSetW_lastErrorText(HCkMessageSetW cHandle);
void CkMessageSetW_getLastErrorXml(HCkMessageSetW cHandle, HCkString retval);
const wchar_t *CkMessageSetW_lastErrorXml(HCkMessageSetW cHandle);
BOOL CkMessageSetW_getVerboseLogging(HCkMessageSetW cHandle);
void CkMessageSetW_putVerboseLogging(HCkMessageSetW cHandle, BOOL newVal);
void CkMessageSetW_getVersion(HCkMessageSetW cHandle, HCkString retval);
const wchar_t *CkMessageSetW_version(HCkMessageSetW cHandle);
BOOL CkMessageSetW_ContainsId(HCkMessageSetW cHandle, int msgId);
BOOL CkMessageSetW_FromCompactString(HCkMessageSetW cHandle, const wchar_t *str);
int CkMessageSetW_GetId(HCkMessageSetW cHandle, int index);
void CkMessageSetW_InsertId(HCkMessageSetW cHandle, int id);
void CkMessageSetW_RemoveId(HCkMessageSetW cHandle, int id);
BOOL CkMessageSetW_SaveLastError(HCkMessageSetW cHandle, const wchar_t *path);
BOOL CkMessageSetW_ToCommaSeparatedStr(HCkMessageSetW cHandle, HCkString outStr);
const wchar_t *CkMessageSetW_toCommaSeparatedStr(HCkMessageSetW cHandle);
BOOL CkMessageSetW_ToCompactString(HCkMessageSetW cHandle, HCkString outStr);
const wchar_t *CkMessageSetW_toCompactString(HCkMessageSetW cHandle);
#endif
