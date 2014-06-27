// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkEmailBundleWH
#define _C_CkEmailBundleWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkEmailBundleW CkEmailBundleW_Create(void);
void CkEmailBundleW_Dispose(HCkEmailBundleW handle);
void CkEmailBundleW_getDebugLogFilePath(HCkEmailBundleW cHandle, HCkString retval);
void CkEmailBundleW_putDebugLogFilePath(HCkEmailBundleW cHandle, const wchar_t *newVal);
const wchar_t *CkEmailBundleW_debugLogFilePath(HCkEmailBundleW cHandle);
void CkEmailBundleW_getLastErrorHtml(HCkEmailBundleW cHandle, HCkString retval);
const wchar_t *CkEmailBundleW_lastErrorHtml(HCkEmailBundleW cHandle);
void CkEmailBundleW_getLastErrorText(HCkEmailBundleW cHandle, HCkString retval);
const wchar_t *CkEmailBundleW_lastErrorText(HCkEmailBundleW cHandle);
void CkEmailBundleW_getLastErrorXml(HCkEmailBundleW cHandle, HCkString retval);
const wchar_t *CkEmailBundleW_lastErrorXml(HCkEmailBundleW cHandle);
int CkEmailBundleW_getMessageCount(HCkEmailBundleW cHandle);
BOOL CkEmailBundleW_getVerboseLogging(HCkEmailBundleW cHandle);
void CkEmailBundleW_putVerboseLogging(HCkEmailBundleW cHandle, BOOL newVal);
void CkEmailBundleW_getVersion(HCkEmailBundleW cHandle, HCkString retval);
const wchar_t *CkEmailBundleW_version(HCkEmailBundleW cHandle);
BOOL CkEmailBundleW_AddEmail(HCkEmailBundleW cHandle, HCkEmailW email);
HCkEmailW CkEmailBundleW_FindByHeader(HCkEmailBundleW cHandle, const wchar_t *headerFieldName, const wchar_t *headerFieldValue);
HCkEmailW CkEmailBundleW_GetEmail(HCkEmailBundleW cHandle, int index);
HCkStringArrayW CkEmailBundleW_GetUidls(HCkEmailBundleW cHandle);
BOOL CkEmailBundleW_GetXml(HCkEmailBundleW cHandle, HCkString outXml);
const wchar_t *CkEmailBundleW_getXml(HCkEmailBundleW cHandle);
BOOL CkEmailBundleW_LoadXml(HCkEmailBundleW cHandle, const wchar_t *filename);
BOOL CkEmailBundleW_LoadXmlString(HCkEmailBundleW cHandle, const wchar_t *xmlStr);
BOOL CkEmailBundleW_RemoveEmail(HCkEmailBundleW cHandle, HCkEmailW email);
BOOL CkEmailBundleW_RemoveEmailByIndex(HCkEmailBundleW cHandle, int index);
BOOL CkEmailBundleW_SaveLastError(HCkEmailBundleW cHandle, const wchar_t *path);
BOOL CkEmailBundleW_SaveXml(HCkEmailBundleW cHandle, const wchar_t *filename);
void CkEmailBundleW_SortByDate(HCkEmailBundleW cHandle, BOOL ascending);
void CkEmailBundleW_SortByRecipient(HCkEmailBundleW cHandle, BOOL ascending);
void CkEmailBundleW_SortBySender(HCkEmailBundleW cHandle, BOOL ascending);
void CkEmailBundleW_SortBySubject(HCkEmailBundleW cHandle, BOOL ascending);
#endif
