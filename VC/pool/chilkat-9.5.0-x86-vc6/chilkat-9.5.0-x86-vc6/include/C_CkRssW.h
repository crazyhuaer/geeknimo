// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkRssWH
#define _C_CkRssWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkRssW CkRssW_Create(void);
HCkRssW CkRssW_Create2(BOOL bCallbackOwned);
void CkRssW_Dispose(HCkRssW handle);
void CkRssW_getDebugLogFilePath(HCkRssW cHandle, HCkString retval);
void CkRssW_putDebugLogFilePath(HCkRssW cHandle, const wchar_t *newVal);
const wchar_t *CkRssW_debugLogFilePath(HCkRssW cHandle);
void CkRssW_getLastErrorHtml(HCkRssW cHandle, HCkString retval);
const wchar_t *CkRssW_lastErrorHtml(HCkRssW cHandle);
void CkRssW_getLastErrorText(HCkRssW cHandle, HCkString retval);
const wchar_t *CkRssW_lastErrorText(HCkRssW cHandle);
void CkRssW_getLastErrorXml(HCkRssW cHandle, HCkString retval);
const wchar_t *CkRssW_lastErrorXml(HCkRssW cHandle);
int CkRssW_getNumChannels(HCkRssW cHandle);
int CkRssW_getNumItems(HCkRssW cHandle);
BOOL CkRssW_getVerboseLogging(HCkRssW cHandle);
void CkRssW_putVerboseLogging(HCkRssW cHandle, BOOL newVal);
void CkRssW_getVersion(HCkRssW cHandle, HCkString retval);
const wchar_t *CkRssW_version(HCkRssW cHandle);
HCkRssW CkRssW_AddNewChannel(HCkRssW cHandle);
HCkRssW CkRssW_AddNewImage(HCkRssW cHandle);
HCkRssW CkRssW_AddNewItem(HCkRssW cHandle);
BOOL CkRssW_DownloadRss(HCkRssW cHandle, const wchar_t *url);
BOOL CkRssW_GetAttr(HCkRssW cHandle, const wchar_t *tag, const wchar_t *attrName, HCkString outStr);
const wchar_t *CkRssW_getAttr(HCkRssW cHandle, const wchar_t *tag, const wchar_t *attrName);
HCkRssW CkRssW_GetChannel(HCkRssW cHandle, int index);
int CkRssW_GetCount(HCkRssW cHandle, const wchar_t *tag);
BOOL CkRssW_GetDate(HCkRssW cHandle, const wchar_t *tag, SYSTEMTIME *outSysTime);
BOOL CkRssW_GetDateStr(HCkRssW cHandle, const wchar_t *tag, HCkString outStr);
const wchar_t *CkRssW_getDateStr(HCkRssW cHandle, const wchar_t *tag);
HCkRssW CkRssW_GetImage(HCkRssW cHandle);
int CkRssW_GetInt(HCkRssW cHandle, const wchar_t *tag);
HCkRssW CkRssW_GetItem(HCkRssW cHandle, int index);
BOOL CkRssW_GetString(HCkRssW cHandle, const wchar_t *tag, HCkString outStr);
const wchar_t *CkRssW_getString(HCkRssW cHandle, const wchar_t *tag);
BOOL CkRssW_LoadRssFile(HCkRssW cHandle, const wchar_t *filePath);
BOOL CkRssW_LoadRssString(HCkRssW cHandle, const wchar_t *rssString);
BOOL CkRssW_MGetAttr(HCkRssW cHandle, const wchar_t *tag, int index, const wchar_t *attrName, HCkString outStr);
const wchar_t *CkRssW_mGetAttr(HCkRssW cHandle, const wchar_t *tag, int index, const wchar_t *attrName);
BOOL CkRssW_MGetString(HCkRssW cHandle, const wchar_t *tag, int index, HCkString outStr);
const wchar_t *CkRssW_mGetString(HCkRssW cHandle, const wchar_t *tag, int index);
BOOL CkRssW_MSetAttr(HCkRssW cHandle, const wchar_t *tag, int idx, const wchar_t *attrName, const wchar_t *value);
BOOL CkRssW_MSetString(HCkRssW cHandle, const wchar_t *tag, int idx, const wchar_t *value);
void CkRssW_NewRss(HCkRssW cHandle);
void CkRssW_Remove(HCkRssW cHandle, const wchar_t *tag);
BOOL CkRssW_SaveLastError(HCkRssW cHandle, const wchar_t *path);
void CkRssW_SetAttr(HCkRssW cHandle, const wchar_t *tag, const wchar_t *attrName, const wchar_t *value);
void CkRssW_SetDate(HCkRssW cHandle, const wchar_t *tag, SYSTEMTIME *dateTime);
void CkRssW_SetDateNow(HCkRssW cHandle, const wchar_t *tag);
void CkRssW_SetDateStr(HCkRssW cHandle, const wchar_t *tag, const wchar_t *dateTimeStr);
void CkRssW_SetInt(HCkRssW cHandle, const wchar_t *tag, int value);
void CkRssW_SetString(HCkRssW cHandle, const wchar_t *tag, const wchar_t *value);
BOOL CkRssW_ToXmlString(HCkRssW cHandle, HCkString outStr);
const wchar_t *CkRssW_toXmlString(HCkRssW cHandle);
#endif
