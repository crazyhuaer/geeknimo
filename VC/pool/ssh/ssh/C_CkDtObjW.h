// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkDtObjWH
#define _C_CkDtObjWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkDtObjW CkDtObjW_Create(void);
void CkDtObjW_Dispose(HCkDtObjW handle);
int CkDtObjW_getDay(HCkDtObjW cHandle);
void CkDtObjW_putDay(HCkDtObjW cHandle, int newVal);
void CkDtObjW_getDebugLogFilePath(HCkDtObjW cHandle, HCkString retval);
void CkDtObjW_putDebugLogFilePath(HCkDtObjW cHandle, const wchar_t *newVal);
const wchar_t *CkDtObjW_debugLogFilePath(HCkDtObjW cHandle);
int CkDtObjW_getHour(HCkDtObjW cHandle);
void CkDtObjW_putHour(HCkDtObjW cHandle, int newVal);
void CkDtObjW_getLastErrorHtml(HCkDtObjW cHandle, HCkString retval);
const wchar_t *CkDtObjW_lastErrorHtml(HCkDtObjW cHandle);
void CkDtObjW_getLastErrorText(HCkDtObjW cHandle, HCkString retval);
const wchar_t *CkDtObjW_lastErrorText(HCkDtObjW cHandle);
void CkDtObjW_getLastErrorXml(HCkDtObjW cHandle, HCkString retval);
const wchar_t *CkDtObjW_lastErrorXml(HCkDtObjW cHandle);
int CkDtObjW_getMinute(HCkDtObjW cHandle);
void CkDtObjW_putMinute(HCkDtObjW cHandle, int newVal);
int CkDtObjW_getMonth(HCkDtObjW cHandle);
void CkDtObjW_putMonth(HCkDtObjW cHandle, int newVal);
int CkDtObjW_getSecond(HCkDtObjW cHandle);
void CkDtObjW_putSecond(HCkDtObjW cHandle, int newVal);
int CkDtObjW_getStructTmMonth(HCkDtObjW cHandle);
void CkDtObjW_putStructTmMonth(HCkDtObjW cHandle, int newVal);
int CkDtObjW_getStructTmYear(HCkDtObjW cHandle);
void CkDtObjW_putStructTmYear(HCkDtObjW cHandle, int newVal);
BOOL CkDtObjW_getUtc(HCkDtObjW cHandle);
void CkDtObjW_putUtc(HCkDtObjW cHandle, BOOL newVal);
BOOL CkDtObjW_getVerboseLogging(HCkDtObjW cHandle);
void CkDtObjW_putVerboseLogging(HCkDtObjW cHandle, BOOL newVal);
void CkDtObjW_getVersion(HCkDtObjW cHandle, HCkString retval);
const wchar_t *CkDtObjW_version(HCkDtObjW cHandle);
int CkDtObjW_getYear(HCkDtObjW cHandle);
void CkDtObjW_putYear(HCkDtObjW cHandle, int newVal);
void CkDtObjW_DeSerialize(HCkDtObjW cHandle, const wchar_t *serializedDtObj);
BOOL CkDtObjW_SaveLastError(HCkDtObjW cHandle, const wchar_t *path);
BOOL CkDtObjW_Serialize(HCkDtObjW cHandle, HCkString outStr);
const wchar_t *CkDtObjW_serialize(HCkDtObjW cHandle);
#endif
