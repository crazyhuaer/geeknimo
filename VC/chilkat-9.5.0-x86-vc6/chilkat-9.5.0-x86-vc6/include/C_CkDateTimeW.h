// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkDateTimeWH
#define _C_CkDateTimeWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkDateTimeW CkDateTimeW_Create(void);
void CkDateTimeW_Dispose(HCkDateTimeW handle);
void CkDateTimeW_getDebugLogFilePath(HCkDateTimeW cHandle, HCkString retval);
void CkDateTimeW_putDebugLogFilePath(HCkDateTimeW cHandle, const wchar_t *newVal);
const wchar_t *CkDateTimeW_debugLogFilePath(HCkDateTimeW cHandle);
int CkDateTimeW_getIsDst(HCkDateTimeW cHandle);
void CkDateTimeW_getLastErrorHtml(HCkDateTimeW cHandle, HCkString retval);
const wchar_t *CkDateTimeW_lastErrorHtml(HCkDateTimeW cHandle);
void CkDateTimeW_getLastErrorText(HCkDateTimeW cHandle, HCkString retval);
const wchar_t *CkDateTimeW_lastErrorText(HCkDateTimeW cHandle);
void CkDateTimeW_getLastErrorXml(HCkDateTimeW cHandle, HCkString retval);
const wchar_t *CkDateTimeW_lastErrorXml(HCkDateTimeW cHandle);
int CkDateTimeW_getUtcOffset(HCkDateTimeW cHandle);
BOOL CkDateTimeW_getVerboseLogging(HCkDateTimeW cHandle);
void CkDateTimeW_putVerboseLogging(HCkDateTimeW cHandle, BOOL newVal);
void CkDateTimeW_getVersion(HCkDateTimeW cHandle, HCkString retval);
const wchar_t *CkDateTimeW_version(HCkDateTimeW cHandle);
BOOL CkDateTimeW_AddDays(HCkDateTimeW cHandle, int numDays);
void CkDateTimeW_DeSerialize(HCkDateTimeW cHandle, const wchar_t *serializedDateTime);
__int64 CkDateTimeW_GetAsDateTimeTicks(HCkDateTimeW cHandle, BOOL bLocal);
#if !defined(CK_USE_UINT_T)
unsigned long CkDateTimeW_GetAsDosDate(HCkDateTimeW cHandle, BOOL bLocal);
#endif
double CkDateTimeW_GetAsOleDate(HCkDateTimeW cHandle, BOOL bLocal);
BOOL CkDateTimeW_GetAsRfc822(HCkDateTimeW cHandle, BOOL bLocal, HCkString outStr);
const wchar_t *CkDateTimeW_getAsRfc822(HCkDateTimeW cHandle, BOOL bLocal);
void CkDateTimeW_GetAsSystemTime(HCkDateTimeW cHandle, BOOL bLocal, SYSTEMTIME *outSysTime);
void CkDateTimeW_GetAsTmStruct(HCkDateTimeW cHandle, BOOL bLocal, struct tm *tmbuf);
time_t CkDateTimeW_GetAsUnixTime(HCkDateTimeW cHandle, BOOL bLocal);
__int64 CkDateTimeW_GetAsUnixTime64(HCkDateTimeW cHandle, BOOL bLocal);
double CkDateTimeW_GetAsUnixTimeDbl(HCkDateTimeW cHandle, BOOL bLocal);
#if !defined(CK_USE_UINT_T)
unsigned short CkDateTimeW_GetDosDateHigh(HCkDateTimeW cHandle, BOOL bLocal);
#endif
#if !defined(CK_USE_UINT_T)
unsigned short CkDateTimeW_GetDosDateLow(HCkDateTimeW cHandle, BOOL bLocal);
#endif
BOOL CkDateTimeW_SaveLastError(HCkDateTimeW cHandle, const wchar_t *path);
BOOL CkDateTimeW_Serialize(HCkDateTimeW cHandle, HCkString outStr);
const wchar_t *CkDateTimeW_serialize(HCkDateTimeW cHandle);
void CkDateTimeW_SetFromCurrentSystemTime(HCkDateTimeW cHandle);
void CkDateTimeW_SetFromDateTimeTicks(HCkDateTimeW cHandle, BOOL bLocal, __int64 ticks);
#if !defined(CK_USE_UINT_T)
void CkDateTimeW_SetFromDosDate(HCkDateTimeW cHandle, BOOL bLocal, unsigned long t);
#endif
#if !defined(CK_USE_UINT_T)
void CkDateTimeW_SetFromDosDate2(HCkDateTimeW cHandle, BOOL bLocal, unsigned short datePart, unsigned short timePart);
#endif
void CkDateTimeW_SetFromOleDate(HCkDateTimeW cHandle, BOOL bLocal, double dt);
BOOL CkDateTimeW_SetFromRfc822(HCkDateTimeW cHandle, const wchar_t *rfc822Str);
void CkDateTimeW_SetFromSystemTime(HCkDateTimeW cHandle, BOOL bLocal, SYSTEMTIME *sysTime);
void CkDateTimeW_SetFromTmStruct(HCkDateTimeW cHandle, BOOL bLocal, struct tm *tmbuf);
void CkDateTimeW_SetFromUnixTime(HCkDateTimeW cHandle, BOOL bLocal, time_t t);
void CkDateTimeW_SetFromUnixTime64(HCkDateTimeW cHandle, BOOL bLocal, __int64 t);
void CkDateTimeW_SetFromUnixTimeDbl(HCkDateTimeW cHandle, BOOL bLocal, double d);
#endif
