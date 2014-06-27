// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkAtomWH
#define _C_CkAtomWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkAtomW CkAtomW_Create(void);
HCkAtomW CkAtomW_Create2(BOOL bCallbackOwned);
void CkAtomW_Dispose(HCkAtomW handle);
void CkAtomW_getDebugLogFilePath(HCkAtomW cHandle, HCkString retval);
void CkAtomW_putDebugLogFilePath(HCkAtomW cHandle, const wchar_t *newVal);
const wchar_t *CkAtomW_debugLogFilePath(HCkAtomW cHandle);
void CkAtomW_getLastErrorHtml(HCkAtomW cHandle, HCkString retval);
const wchar_t *CkAtomW_lastErrorHtml(HCkAtomW cHandle);
void CkAtomW_getLastErrorText(HCkAtomW cHandle, HCkString retval);
const wchar_t *CkAtomW_lastErrorText(HCkAtomW cHandle);
void CkAtomW_getLastErrorXml(HCkAtomW cHandle, HCkString retval);
const wchar_t *CkAtomW_lastErrorXml(HCkAtomW cHandle);
int CkAtomW_getNumEntries(HCkAtomW cHandle);
BOOL CkAtomW_getVerboseLogging(HCkAtomW cHandle);
void CkAtomW_putVerboseLogging(HCkAtomW cHandle, BOOL newVal);
void CkAtomW_getVersion(HCkAtomW cHandle, HCkString retval);
const wchar_t *CkAtomW_version(HCkAtomW cHandle);
int CkAtomW_AddElement(HCkAtomW cHandle, const wchar_t *tag, const wchar_t *value);
int CkAtomW_AddElementDate(HCkAtomW cHandle, const wchar_t *tag, SYSTEMTIME *dateTimeStr);
int CkAtomW_AddElementDateStr(HCkAtomW cHandle, const wchar_t *tag, const wchar_t *dateTimeStr);
int CkAtomW_AddElementDt(HCkAtomW cHandle, const wchar_t *tag, HCkDateTimeW dateTime);
int CkAtomW_AddElementHtml(HCkAtomW cHandle, const wchar_t *tag, const wchar_t *htmlStr);
int CkAtomW_AddElementXHtml(HCkAtomW cHandle, const wchar_t *tag, const wchar_t *xmlStr);
int CkAtomW_AddElementXml(HCkAtomW cHandle, const wchar_t *tag, const wchar_t *xmlStr);
void CkAtomW_AddEntry(HCkAtomW cHandle, const wchar_t *xmlStr);
void CkAtomW_AddLink(HCkAtomW cHandle, const wchar_t *rel, const wchar_t *href, const wchar_t *title, const wchar_t *typ);
void CkAtomW_AddPerson(HCkAtomW cHandle, const wchar_t *tag, const wchar_t *name, const wchar_t *uri, const wchar_t *email);
void CkAtomW_DeleteElement(HCkAtomW cHandle, const wchar_t *tag, int index);
void CkAtomW_DeleteElementAttr(HCkAtomW cHandle, const wchar_t *tag, int index, const wchar_t *attrName);
void CkAtomW_DeletePerson(HCkAtomW cHandle, const wchar_t *tag, int index);
BOOL CkAtomW_DownloadAtom(HCkAtomW cHandle, const wchar_t *url);
BOOL CkAtomW_GetElement(HCkAtomW cHandle, const wchar_t *tag, int index, HCkString outStr);
const wchar_t *CkAtomW_getElement(HCkAtomW cHandle, const wchar_t *tag, int index);
BOOL CkAtomW_GetElementAttr(HCkAtomW cHandle, const wchar_t *tag, int index, const wchar_t *attrName, HCkString outStr);
const wchar_t *CkAtomW_getElementAttr(HCkAtomW cHandle, const wchar_t *tag, int index, const wchar_t *attrName);
int CkAtomW_GetElementCount(HCkAtomW cHandle, const wchar_t *tag);
BOOL CkAtomW_GetElementDate(HCkAtomW cHandle, const wchar_t *tag, int index, SYSTEMTIME *outSysTime);
BOOL CkAtomW_GetElementDateStr(HCkAtomW cHandle, const wchar_t *tag, int index, HCkString outStr);
const wchar_t *CkAtomW_getElementDateStr(HCkAtomW cHandle, const wchar_t *tag, int index);
HCkDateTimeW CkAtomW_GetElementDt(HCkAtomW cHandle, const wchar_t *tag, int index);
HCkAtomW CkAtomW_GetEntry(HCkAtomW cHandle, int index);
BOOL CkAtomW_GetLinkHref(HCkAtomW cHandle, const wchar_t *relName, HCkString outStr);
const wchar_t *CkAtomW_getLinkHref(HCkAtomW cHandle, const wchar_t *relName);
BOOL CkAtomW_GetPersonInfo(HCkAtomW cHandle, const wchar_t *tag, int index, const wchar_t *tag2, HCkString outStr);
const wchar_t *CkAtomW_getPersonInfo(HCkAtomW cHandle, const wchar_t *tag, int index, const wchar_t *tag2);
BOOL CkAtomW_GetTopAttr(HCkAtomW cHandle, const wchar_t *attrName, HCkString outStr);
const wchar_t *CkAtomW_getTopAttr(HCkAtomW cHandle, const wchar_t *attrName);
BOOL CkAtomW_HasElement(HCkAtomW cHandle, const wchar_t *tag);
BOOL CkAtomW_LoadXml(HCkAtomW cHandle, const wchar_t *xmlStr);
void CkAtomW_NewEntry(HCkAtomW cHandle);
void CkAtomW_NewFeed(HCkAtomW cHandle);
BOOL CkAtomW_SaveLastError(HCkAtomW cHandle, const wchar_t *path);
void CkAtomW_SetElementAttr(HCkAtomW cHandle, const wchar_t *tag, int index, const wchar_t *attrName, const wchar_t *attrValue);
void CkAtomW_SetTopAttr(HCkAtomW cHandle, const wchar_t *attrName, const wchar_t *value);
BOOL CkAtomW_ToXmlString(HCkAtomW cHandle, HCkString outStr);
const wchar_t *CkAtomW_toXmlString(HCkAtomW cHandle);
void CkAtomW_UpdateElement(HCkAtomW cHandle, const wchar_t *tag, int index, const wchar_t *value);
void CkAtomW_UpdateElementDate(HCkAtomW cHandle, const wchar_t *tag, int index, SYSTEMTIME *dateTime);
void CkAtomW_UpdateElementDateStr(HCkAtomW cHandle, const wchar_t *tag, int index, const wchar_t *dateTimeStr);
void CkAtomW_UpdateElementDt(HCkAtomW cHandle, const wchar_t *tag, int index, HCkDateTimeW dateTime);
void CkAtomW_UpdateElementHtml(HCkAtomW cHandle, const wchar_t *tag, int index, const wchar_t *htmlStr);
void CkAtomW_UpdateElementXHtml(HCkAtomW cHandle, const wchar_t *tag, int index, const wchar_t *xmlStr);
void CkAtomW_UpdateElementXml(HCkAtomW cHandle, const wchar_t *tag, int index, const wchar_t *xmlStr);
void CkAtomW_UpdatePerson(HCkAtomW cHandle, const wchar_t *tag, int index, const wchar_t *name, const wchar_t *uri, const wchar_t *email);
#endif
