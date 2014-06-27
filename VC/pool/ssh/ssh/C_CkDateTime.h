// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkDateTime_H
#define _C_CkDateTime_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkDateTime CkDateTime_Create(void);
void CkDateTime_Dispose(HCkDateTime handle);
void CkDateTime_getDebugLogFilePath(HCkDateTime cHandle, HCkString retval);
void CkDateTime_putDebugLogFilePath(HCkDateTime cHandle, const char *newVal);
const char *CkDateTime_debugLogFilePath(HCkDateTime cHandle);
int CkDateTime_getIsDst(HCkDateTime cHandle);
void CkDateTime_getLastErrorHtml(HCkDateTime cHandle, HCkString retval);
const char *CkDateTime_lastErrorHtml(HCkDateTime cHandle);
void CkDateTime_getLastErrorText(HCkDateTime cHandle, HCkString retval);
const char *CkDateTime_lastErrorText(HCkDateTime cHandle);
void CkDateTime_getLastErrorXml(HCkDateTime cHandle, HCkString retval);
const char *CkDateTime_lastErrorXml(HCkDateTime cHandle);
int CkDateTime_getUtcOffset(HCkDateTime cHandle);
BOOL CkDateTime_getUtf8(HCkDateTime cHandle);
void CkDateTime_putUtf8(HCkDateTime cHandle, BOOL newVal);
BOOL CkDateTime_getVerboseLogging(HCkDateTime cHandle);
void CkDateTime_putVerboseLogging(HCkDateTime cHandle, BOOL newVal);
void CkDateTime_getVersion(HCkDateTime cHandle, HCkString retval);
const char *CkDateTime_version(HCkDateTime cHandle);
BOOL CkDateTime_AddDays(HCkDateTime cHandle, int numDays);
void CkDateTime_DeSerialize(HCkDateTime cHandle, const char *serializedDateTime);
__int64 CkDateTime_GetAsDateTimeTicks(HCkDateTime cHandle, BOOL bLocal);
#if !defined(CK_USE_UINT_T)
unsigned long CkDateTime_GetAsDosDate(HCkDateTime cHandle, BOOL bLocal);
#endif
double CkDateTime_GetAsOleDate(HCkDateTime cHandle, BOOL bLocal);
BOOL CkDateTime_GetAsRfc822(HCkDateTime cHandle, BOOL bLocal, HCkString outStr);
const char *CkDateTime_getAsRfc822(HCkDateTime cHandle, BOOL bLocal);
void CkDateTime_GetAsSystemTime(HCkDateTime cHandle, BOOL bLocal, SYSTEMTIME *outSysTime);
void CkDateTime_GetAsTmStruct(HCkDateTime cHandle, BOOL bLocal, struct tm *tmbuf);
time_t CkDateTime_GetAsUnixTime(HCkDateTime cHandle, BOOL bLocal);
__int64 CkDateTime_GetAsUnixTime64(HCkDateTime cHandle, BOOL bLocal);
double CkDateTime_GetAsUnixTimeDbl(HCkDateTime cHandle, BOOL bLocal);
#if !defined(CK_USE_UINT_T)
unsigned short CkDateTime_GetDosDateHigh(HCkDateTime cHandle, BOOL bLocal);
#endif
#if !defined(CK_USE_UINT_T)
unsigned short CkDateTime_GetDosDateLow(HCkDateTime cHandle, BOOL bLocal);
#endif
BOOL CkDateTime_SaveLastError(HCkDateTime cHandle, const char *path);
BOOL CkDateTime_Serialize(HCkDateTime cHandle, HCkString outStr);
const char *CkDateTime_serialize(HCkDateTime cHandle);
void CkDateTime_SetFromCurrentSystemTime(HCkDateTime cHandle);
void CkDateTime_SetFromDateTimeTicks(HCkDateTime cHandle, BOOL bLocal, __int64 ticks);
#if !defined(CK_USE_UINT_T)
void CkDateTime_SetFromDosDate(HCkDateTime cHandle, BOOL bLocal, unsigned long t);
#endif
#if !defined(CK_USE_UINT_T)
void CkDateTime_SetFromDosDate2(HCkDateTime cHandle, BOOL bLocal, unsigned short datePart, unsigned short timePart);
#endif
void CkDateTime_SetFromOleDate(HCkDateTime cHandle, BOOL bLocal, double dt);
BOOL CkDateTime_SetFromRfc822(HCkDateTime cHandle, const char *rfc822Str);
void CkDateTime_SetFromSystemTime(HCkDateTime cHandle, BOOL bLocal, SYSTEMTIME *sysTime);
void CkDateTime_SetFromTmStruct(HCkDateTime cHandle, BOOL bLocal, struct tm *tmbuf);
void CkDateTime_SetFromUnixTime(HCkDateTime cHandle, BOOL bLocal, time_t t);
void CkDateTime_SetFromUnixTime64(HCkDateTime cHandle, BOOL bLocal, __int64 t);
void CkDateTime_SetFromUnixTimeDbl(HCkDateTime cHandle, BOOL bLocal, double d);
#endif
