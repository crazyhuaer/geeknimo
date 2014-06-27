// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkXmpWH
#define _C_CkXmpWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkXmpW CkXmpW_Create(void);
void CkXmpW_Dispose(HCkXmpW handle);
void CkXmpW_getDebugLogFilePath(HCkXmpW cHandle, HCkString retval);
void CkXmpW_putDebugLogFilePath(HCkXmpW cHandle, const wchar_t *newVal);
const wchar_t *CkXmpW_debugLogFilePath(HCkXmpW cHandle);
void CkXmpW_getLastErrorHtml(HCkXmpW cHandle, HCkString retval);
const wchar_t *CkXmpW_lastErrorHtml(HCkXmpW cHandle);
void CkXmpW_getLastErrorText(HCkXmpW cHandle, HCkString retval);
const wchar_t *CkXmpW_lastErrorText(HCkXmpW cHandle);
void CkXmpW_getLastErrorXml(HCkXmpW cHandle, HCkString retval);
const wchar_t *CkXmpW_lastErrorXml(HCkXmpW cHandle);
int CkXmpW_getNumEmbedded(HCkXmpW cHandle);
BOOL CkXmpW_getStructInnerDescrip(HCkXmpW cHandle);
void CkXmpW_putStructInnerDescrip(HCkXmpW cHandle, BOOL newVal);
BOOL CkXmpW_getVerboseLogging(HCkXmpW cHandle);
void CkXmpW_putVerboseLogging(HCkXmpW cHandle, BOOL newVal);
void CkXmpW_getVersion(HCkXmpW cHandle, HCkString retval);
const wchar_t *CkXmpW_version(HCkXmpW cHandle);
BOOL CkXmpW_AddArray(HCkXmpW cHandle, HCkXmlW xml, const wchar_t *arrType, const wchar_t *propName, HCkStringArrayW values);
void CkXmpW_AddNsMapping(HCkXmpW cHandle, const wchar_t *ns, const wchar_t *uri);
BOOL CkXmpW_AddSimpleDate(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *propName, SYSTEMTIME *propVal);
BOOL CkXmpW_AddSimpleInt(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *propName, int propVal);
BOOL CkXmpW_AddSimpleStr(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *propName, const wchar_t *propVal);
BOOL CkXmpW_AddStructProp(HCkXmpW cHandle, HCkXmlW iChilkatXml, const wchar_t *structName, const wchar_t *propName, const wchar_t *propValue);
BOOL CkXmpW_Append(HCkXmpW cHandle, HCkXmlW iXml);
BOOL CkXmpW_DateToString(HCkXmpW cHandle, SYSTEMTIME *d, HCkString outStr);
const wchar_t *CkXmpW_dateToString(HCkXmpW cHandle, SYSTEMTIME *d);
HCkStringArrayW CkXmpW_GetArray(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *propName);
HCkXmlW CkXmpW_GetEmbedded(HCkXmpW cHandle, int index);
HCkXmlW CkXmpW_GetProperty(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *propName);
BOOL CkXmpW_GetSimpleDate(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *propName, SYSTEMTIME *outSysTime);
int CkXmpW_GetSimpleInt(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *propName);
BOOL CkXmpW_GetSimpleStr(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *propName, HCkString outStr);
const wchar_t *CkXmpW_getSimpleStr(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *propName);
HCkStringArrayW CkXmpW_GetStructPropNames(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *structName);
BOOL CkXmpW_GetStructValue(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *structName, const wchar_t *propName, HCkString outStr);
const wchar_t *CkXmpW_getStructValue(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *structName, const wchar_t *propName);
BOOL CkXmpW_LoadAppFile(HCkXmpW cHandle, const wchar_t *filename);
BOOL CkXmpW_LoadFromBuffer(HCkXmpW cHandle, HCkByteData fileData, const wchar_t *ext);
HCkXmlW CkXmpW_NewXmp(HCkXmpW cHandle);
BOOL CkXmpW_RemoveAllEmbedded(HCkXmpW cHandle);
BOOL CkXmpW_RemoveArray(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *propName);
BOOL CkXmpW_RemoveEmbedded(HCkXmpW cHandle, int index);
void CkXmpW_RemoveNsMapping(HCkXmpW cHandle, const wchar_t *ns);
BOOL CkXmpW_RemoveSimple(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *propName);
BOOL CkXmpW_RemoveStruct(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *structName);
BOOL CkXmpW_RemoveStructProp(HCkXmpW cHandle, HCkXmlW iXml, const wchar_t *structName, const wchar_t *propName);
BOOL CkXmpW_SaveAppFile(HCkXmpW cHandle, const wchar_t *filename);
BOOL CkXmpW_SaveLastError(HCkXmpW cHandle, const wchar_t *path);
BOOL CkXmpW_SaveToBuffer(HCkXmpW cHandle, HCkByteData outBytes);
BOOL CkXmpW_StringToDate(HCkXmpW cHandle, const wchar_t *str, SYSTEMTIME *outSysTime);
BOOL CkXmpW_UnlockComponent(HCkXmpW cHandle, const wchar_t *unlockCode);
#endif
