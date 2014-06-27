// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkRss_H
#define _C_CkRss_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkRss CkRss_Create(void);
void CkRss_Dispose(HCkRss handle);
void CkRss_getDebugLogFilePath(HCkRss cHandle, HCkString retval);
void CkRss_putDebugLogFilePath(HCkRss cHandle, const char *newVal);
const char *CkRss_debugLogFilePath(HCkRss cHandle);
void CkRss_getLastErrorHtml(HCkRss cHandle, HCkString retval);
const char *CkRss_lastErrorHtml(HCkRss cHandle);
void CkRss_getLastErrorText(HCkRss cHandle, HCkString retval);
const char *CkRss_lastErrorText(HCkRss cHandle);
void CkRss_getLastErrorXml(HCkRss cHandle, HCkString retval);
const char *CkRss_lastErrorXml(HCkRss cHandle);
int CkRss_getNumChannels(HCkRss cHandle);
int CkRss_getNumItems(HCkRss cHandle);
BOOL CkRss_getUtf8(HCkRss cHandle);
void CkRss_putUtf8(HCkRss cHandle, BOOL newVal);
BOOL CkRss_getVerboseLogging(HCkRss cHandle);
void CkRss_putVerboseLogging(HCkRss cHandle, BOOL newVal);
void CkRss_getVersion(HCkRss cHandle, HCkString retval);
const char *CkRss_version(HCkRss cHandle);
HCkRss CkRss_AddNewChannel(HCkRss cHandle);
HCkRss CkRss_AddNewImage(HCkRss cHandle);
HCkRss CkRss_AddNewItem(HCkRss cHandle);
BOOL CkRss_DownloadRss(HCkRss cHandle, const char *url);
BOOL CkRss_GetAttr(HCkRss cHandle, const char *tag, const char *attrName, HCkString outStr);
const char *CkRss_getAttr(HCkRss cHandle, const char *tag, const char *attrName);
HCkRss CkRss_GetChannel(HCkRss cHandle, int index);
int CkRss_GetCount(HCkRss cHandle, const char *tag);
BOOL CkRss_GetDate(HCkRss cHandle, const char *tag, SYSTEMTIME *outSysTime);
BOOL CkRss_GetDateStr(HCkRss cHandle, const char *tag, HCkString outStr);
const char *CkRss_getDateStr(HCkRss cHandle, const char *tag);
HCkRss CkRss_GetImage(HCkRss cHandle);
int CkRss_GetInt(HCkRss cHandle, const char *tag);
HCkRss CkRss_GetItem(HCkRss cHandle, int index);
BOOL CkRss_GetString(HCkRss cHandle, const char *tag, HCkString outStr);
const char *CkRss_getString(HCkRss cHandle, const char *tag);
BOOL CkRss_LoadRssFile(HCkRss cHandle, const char *filePath);
BOOL CkRss_LoadRssString(HCkRss cHandle, const char *rssString);
BOOL CkRss_MGetAttr(HCkRss cHandle, const char *tag, int index, const char *attrName, HCkString outStr);
const char *CkRss_mGetAttr(HCkRss cHandle, const char *tag, int index, const char *attrName);
BOOL CkRss_MGetString(HCkRss cHandle, const char *tag, int index, HCkString outStr);
const char *CkRss_mGetString(HCkRss cHandle, const char *tag, int index);
BOOL CkRss_MSetAttr(HCkRss cHandle, const char *tag, int idx, const char *attrName, const char *value);
BOOL CkRss_MSetString(HCkRss cHandle, const char *tag, int idx, const char *value);
void CkRss_NewRss(HCkRss cHandle);
void CkRss_Remove(HCkRss cHandle, const char *tag);
BOOL CkRss_SaveLastError(HCkRss cHandle, const char *path);
void CkRss_SetAttr(HCkRss cHandle, const char *tag, const char *attrName, const char *value);
void CkRss_SetDate(HCkRss cHandle, const char *tag, SYSTEMTIME *dateTime);
void CkRss_SetDateNow(HCkRss cHandle, const char *tag);
void CkRss_SetDateStr(HCkRss cHandle, const char *tag, const char *dateTimeStr);
void CkRss_SetInt(HCkRss cHandle, const char *tag, int value);
void CkRss_SetString(HCkRss cHandle, const char *tag, const char *value);
BOOL CkRss_ToXmlString(HCkRss cHandle, HCkString outStr);
const char *CkRss_toXmlString(HCkRss cHandle);
#endif
