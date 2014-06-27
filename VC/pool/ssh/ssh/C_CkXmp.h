// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkXmp_H
#define _C_CkXmp_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkXmp CkXmp_Create(void);
void CkXmp_Dispose(HCkXmp handle);
void CkXmp_getDebugLogFilePath(HCkXmp cHandle, HCkString retval);
void CkXmp_putDebugLogFilePath(HCkXmp cHandle, const char *newVal);
const char *CkXmp_debugLogFilePath(HCkXmp cHandle);
void CkXmp_getLastErrorHtml(HCkXmp cHandle, HCkString retval);
const char *CkXmp_lastErrorHtml(HCkXmp cHandle);
void CkXmp_getLastErrorText(HCkXmp cHandle, HCkString retval);
const char *CkXmp_lastErrorText(HCkXmp cHandle);
void CkXmp_getLastErrorXml(HCkXmp cHandle, HCkString retval);
const char *CkXmp_lastErrorXml(HCkXmp cHandle);
int CkXmp_getNumEmbedded(HCkXmp cHandle);
BOOL CkXmp_getStructInnerDescrip(HCkXmp cHandle);
void CkXmp_putStructInnerDescrip(HCkXmp cHandle, BOOL newVal);
BOOL CkXmp_getUtf8(HCkXmp cHandle);
void CkXmp_putUtf8(HCkXmp cHandle, BOOL newVal);
BOOL CkXmp_getVerboseLogging(HCkXmp cHandle);
void CkXmp_putVerboseLogging(HCkXmp cHandle, BOOL newVal);
void CkXmp_getVersion(HCkXmp cHandle, HCkString retval);
const char *CkXmp_version(HCkXmp cHandle);
BOOL CkXmp_AddArray(HCkXmp cHandle, HCkXml xml, const char *arrType, const char *propName, HCkStringArray values);
void CkXmp_AddNsMapping(HCkXmp cHandle, const char *ns, const char *uri);
BOOL CkXmp_AddSimpleDate(HCkXmp cHandle, HCkXml iXml, const char *propName, SYSTEMTIME *propVal);
BOOL CkXmp_AddSimpleInt(HCkXmp cHandle, HCkXml iXml, const char *propName, int propVal);
BOOL CkXmp_AddSimpleStr(HCkXmp cHandle, HCkXml iXml, const char *propName, const char *propVal);
BOOL CkXmp_AddStructProp(HCkXmp cHandle, HCkXml iChilkatXml, const char *structName, const char *propName, const char *propValue);
BOOL CkXmp_Append(HCkXmp cHandle, HCkXml iXml);
BOOL CkXmp_DateToString(HCkXmp cHandle, SYSTEMTIME *d, HCkString outStr);
const char *CkXmp_dateToString(HCkXmp cHandle, SYSTEMTIME *d);
HCkStringArray CkXmp_GetArray(HCkXmp cHandle, HCkXml iXml, const char *propName);
HCkXml CkXmp_GetEmbedded(HCkXmp cHandle, int index);
HCkXml CkXmp_GetProperty(HCkXmp cHandle, HCkXml iXml, const char *propName);
BOOL CkXmp_GetSimpleDate(HCkXmp cHandle, HCkXml iXml, const char *propName, SYSTEMTIME *outSysTime);
int CkXmp_GetSimpleInt(HCkXmp cHandle, HCkXml iXml, const char *propName);
BOOL CkXmp_GetSimpleStr(HCkXmp cHandle, HCkXml iXml, const char *propName, HCkString outStr);
const char *CkXmp_getSimpleStr(HCkXmp cHandle, HCkXml iXml, const char *propName);
HCkStringArray CkXmp_GetStructPropNames(HCkXmp cHandle, HCkXml iXml, const char *structName);
BOOL CkXmp_GetStructValue(HCkXmp cHandle, HCkXml iXml, const char *structName, const char *propName, HCkString outStr);
const char *CkXmp_getStructValue(HCkXmp cHandle, HCkXml iXml, const char *structName, const char *propName);
BOOL CkXmp_LoadAppFile(HCkXmp cHandle, const char *filename);
BOOL CkXmp_LoadFromBuffer(HCkXmp cHandle, HCkByteData fileData, const char *ext);
HCkXml CkXmp_NewXmp(HCkXmp cHandle);
BOOL CkXmp_RemoveAllEmbedded(HCkXmp cHandle);
BOOL CkXmp_RemoveArray(HCkXmp cHandle, HCkXml iXml, const char *propName);
BOOL CkXmp_RemoveEmbedded(HCkXmp cHandle, int index);
void CkXmp_RemoveNsMapping(HCkXmp cHandle, const char *ns);
BOOL CkXmp_RemoveSimple(HCkXmp cHandle, HCkXml iXml, const char *propName);
BOOL CkXmp_RemoveStruct(HCkXmp cHandle, HCkXml iXml, const char *structName);
BOOL CkXmp_RemoveStructProp(HCkXmp cHandle, HCkXml iXml, const char *structName, const char *propName);
BOOL CkXmp_SaveAppFile(HCkXmp cHandle, const char *filename);
BOOL CkXmp_SaveLastError(HCkXmp cHandle, const char *path);
BOOL CkXmp_SaveToBuffer(HCkXmp cHandle, HCkByteData outBytes);
BOOL CkXmp_StringToDate(HCkXmp cHandle, const char *str, SYSTEMTIME *outSysTime);
BOOL CkXmp_UnlockComponent(HCkXmp cHandle, const char *unlockCode);
#endif
