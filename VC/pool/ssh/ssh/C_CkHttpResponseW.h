// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkHttpResponseWH
#define _C_CkHttpResponseWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkHttpResponseW CkHttpResponseW_Create(void);
void CkHttpResponseW_Dispose(HCkHttpResponseW handle);
void CkHttpResponseW_getBody(HCkHttpResponseW cHandle, HCkByteData retval);
void CkHttpResponseW_getBodyQP(HCkHttpResponseW cHandle, HCkString retval);
const wchar_t *CkHttpResponseW_bodyQP(HCkHttpResponseW cHandle);
void CkHttpResponseW_getBodyStr(HCkHttpResponseW cHandle, HCkString retval);
const wchar_t *CkHttpResponseW_bodyStr(HCkHttpResponseW cHandle);
void CkHttpResponseW_getCharset(HCkHttpResponseW cHandle, HCkString retval);
const wchar_t *CkHttpResponseW_charset(HCkHttpResponseW cHandle);
unsigned long CkHttpResponseW_getContentLength(HCkHttpResponseW cHandle);
__int64 CkHttpResponseW_getContentLength64(HCkHttpResponseW cHandle);
void CkHttpResponseW_getDate(HCkHttpResponseW cHandle, SYSTEMTIME *retval);
void CkHttpResponseW_getDateStr(HCkHttpResponseW cHandle, HCkString retval);
const wchar_t *CkHttpResponseW_dateStr(HCkHttpResponseW cHandle);
void CkHttpResponseW_getDebugLogFilePath(HCkHttpResponseW cHandle, HCkString retval);
void CkHttpResponseW_putDebugLogFilePath(HCkHttpResponseW cHandle, const wchar_t *newVal);
const wchar_t *CkHttpResponseW_debugLogFilePath(HCkHttpResponseW cHandle);
void CkHttpResponseW_getDomain(HCkHttpResponseW cHandle, HCkString retval);
const wchar_t *CkHttpResponseW_domain(HCkHttpResponseW cHandle);
void CkHttpResponseW_getFullMime(HCkHttpResponseW cHandle, HCkString retval);
const wchar_t *CkHttpResponseW_fullMime(HCkHttpResponseW cHandle);
void CkHttpResponseW_getHeader(HCkHttpResponseW cHandle, HCkString retval);
const wchar_t *CkHttpResponseW_header(HCkHttpResponseW cHandle);
void CkHttpResponseW_getLastErrorHtml(HCkHttpResponseW cHandle, HCkString retval);
const wchar_t *CkHttpResponseW_lastErrorHtml(HCkHttpResponseW cHandle);
void CkHttpResponseW_getLastErrorText(HCkHttpResponseW cHandle, HCkString retval);
const wchar_t *CkHttpResponseW_lastErrorText(HCkHttpResponseW cHandle);
void CkHttpResponseW_getLastErrorXml(HCkHttpResponseW cHandle, HCkString retval);
const wchar_t *CkHttpResponseW_lastErrorXml(HCkHttpResponseW cHandle);
int CkHttpResponseW_getNumCookies(HCkHttpResponseW cHandle);
int CkHttpResponseW_getNumHeaderFields(HCkHttpResponseW cHandle);
int CkHttpResponseW_getStatusCode(HCkHttpResponseW cHandle);
void CkHttpResponseW_getStatusLine(HCkHttpResponseW cHandle, HCkString retval);
const wchar_t *CkHttpResponseW_statusLine(HCkHttpResponseW cHandle);
BOOL CkHttpResponseW_getVerboseLogging(HCkHttpResponseW cHandle);
void CkHttpResponseW_putVerboseLogging(HCkHttpResponseW cHandle, BOOL newVal);
void CkHttpResponseW_getVersion(HCkHttpResponseW cHandle, HCkString retval);
const wchar_t *CkHttpResponseW_version(HCkHttpResponseW cHandle);
BOOL CkHttpResponseW_GetCookieDomain(HCkHttpResponseW cHandle, int index, HCkString outStr);
const wchar_t *CkHttpResponseW_getCookieDomain(HCkHttpResponseW cHandle, int index);
BOOL CkHttpResponseW_GetCookieExpires(HCkHttpResponseW cHandle, int index, SYSTEMTIME *outSysTime);
BOOL CkHttpResponseW_GetCookieExpiresStr(HCkHttpResponseW cHandle, int index, HCkString outStr);
const wchar_t *CkHttpResponseW_getCookieExpiresStr(HCkHttpResponseW cHandle, int index);
BOOL CkHttpResponseW_GetCookieName(HCkHttpResponseW cHandle, int index, HCkString outStr);
const wchar_t *CkHttpResponseW_getCookieName(HCkHttpResponseW cHandle, int index);
BOOL CkHttpResponseW_GetCookiePath(HCkHttpResponseW cHandle, int index, HCkString outStr);
const wchar_t *CkHttpResponseW_getCookiePath(HCkHttpResponseW cHandle, int index);
BOOL CkHttpResponseW_GetCookieValue(HCkHttpResponseW cHandle, int index, HCkString outStr);
const wchar_t *CkHttpResponseW_getCookieValue(HCkHttpResponseW cHandle, int index);
BOOL CkHttpResponseW_GetHeaderField(HCkHttpResponseW cHandle, const wchar_t *fieldName, HCkString outStr);
const wchar_t *CkHttpResponseW_getHeaderField(HCkHttpResponseW cHandle, const wchar_t *fieldName);
BOOL CkHttpResponseW_GetHeaderFieldAttr(HCkHttpResponseW cHandle, const wchar_t *fieldName, const wchar_t *attrName, HCkString outStr);
const wchar_t *CkHttpResponseW_getHeaderFieldAttr(HCkHttpResponseW cHandle, const wchar_t *fieldName, const wchar_t *attrName);
BOOL CkHttpResponseW_GetHeaderName(HCkHttpResponseW cHandle, int index, HCkString outStr);
const wchar_t *CkHttpResponseW_getHeaderName(HCkHttpResponseW cHandle, int index);
BOOL CkHttpResponseW_GetHeaderValue(HCkHttpResponseW cHandle, int index, HCkString outStr);
const wchar_t *CkHttpResponseW_getHeaderValue(HCkHttpResponseW cHandle, int index);
BOOL CkHttpResponseW_SaveBodyBinary(HCkHttpResponseW cHandle, const wchar_t *path);
BOOL CkHttpResponseW_SaveBodyText(HCkHttpResponseW cHandle, BOOL bCrlf, const wchar_t *path);
BOOL CkHttpResponseW_SaveLastError(HCkHttpResponseW cHandle, const wchar_t *path);
BOOL CkHttpResponseW_UrlEncParamValue(HCkHttpResponseW cHandle, const wchar_t *encodedParamString, const wchar_t *paramName, HCkString outStr);
const wchar_t *CkHttpResponseW_urlEncParamValue(HCkHttpResponseW cHandle, const wchar_t *encodedParamString, const wchar_t *paramName);
#endif
