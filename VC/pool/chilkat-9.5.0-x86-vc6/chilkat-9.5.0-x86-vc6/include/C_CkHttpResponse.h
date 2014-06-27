// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkHttpResponse_H
#define _C_CkHttpResponse_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkHttpResponse CkHttpResponse_Create(void);
void CkHttpResponse_Dispose(HCkHttpResponse handle);
void CkHttpResponse_getBody(HCkHttpResponse cHandle, HCkByteData retval);
void CkHttpResponse_getBodyQP(HCkHttpResponse cHandle, HCkString retval);
const char *CkHttpResponse_bodyQP(HCkHttpResponse cHandle);
void CkHttpResponse_getBodyStr(HCkHttpResponse cHandle, HCkString retval);
const char *CkHttpResponse_bodyStr(HCkHttpResponse cHandle);
void CkHttpResponse_getCharset(HCkHttpResponse cHandle, HCkString retval);
const char *CkHttpResponse_charset(HCkHttpResponse cHandle);
unsigned long CkHttpResponse_getContentLength(HCkHttpResponse cHandle);
__int64 CkHttpResponse_getContentLength64(HCkHttpResponse cHandle);
void CkHttpResponse_getDate(HCkHttpResponse cHandle, SYSTEMTIME *retval);
void CkHttpResponse_getDateStr(HCkHttpResponse cHandle, HCkString retval);
const char *CkHttpResponse_dateStr(HCkHttpResponse cHandle);
void CkHttpResponse_getDebugLogFilePath(HCkHttpResponse cHandle, HCkString retval);
void CkHttpResponse_putDebugLogFilePath(HCkHttpResponse cHandle, const char *newVal);
const char *CkHttpResponse_debugLogFilePath(HCkHttpResponse cHandle);
void CkHttpResponse_getDomain(HCkHttpResponse cHandle, HCkString retval);
const char *CkHttpResponse_domain(HCkHttpResponse cHandle);
void CkHttpResponse_getFullMime(HCkHttpResponse cHandle, HCkString retval);
const char *CkHttpResponse_fullMime(HCkHttpResponse cHandle);
void CkHttpResponse_getHeader(HCkHttpResponse cHandle, HCkString retval);
const char *CkHttpResponse_header(HCkHttpResponse cHandle);
void CkHttpResponse_getLastErrorHtml(HCkHttpResponse cHandle, HCkString retval);
const char *CkHttpResponse_lastErrorHtml(HCkHttpResponse cHandle);
void CkHttpResponse_getLastErrorText(HCkHttpResponse cHandle, HCkString retval);
const char *CkHttpResponse_lastErrorText(HCkHttpResponse cHandle);
void CkHttpResponse_getLastErrorXml(HCkHttpResponse cHandle, HCkString retval);
const char *CkHttpResponse_lastErrorXml(HCkHttpResponse cHandle);
int CkHttpResponse_getNumCookies(HCkHttpResponse cHandle);
int CkHttpResponse_getNumHeaderFields(HCkHttpResponse cHandle);
int CkHttpResponse_getStatusCode(HCkHttpResponse cHandle);
void CkHttpResponse_getStatusLine(HCkHttpResponse cHandle, HCkString retval);
const char *CkHttpResponse_statusLine(HCkHttpResponse cHandle);
BOOL CkHttpResponse_getUtf8(HCkHttpResponse cHandle);
void CkHttpResponse_putUtf8(HCkHttpResponse cHandle, BOOL newVal);
BOOL CkHttpResponse_getVerboseLogging(HCkHttpResponse cHandle);
void CkHttpResponse_putVerboseLogging(HCkHttpResponse cHandle, BOOL newVal);
void CkHttpResponse_getVersion(HCkHttpResponse cHandle, HCkString retval);
const char *CkHttpResponse_version(HCkHttpResponse cHandle);
BOOL CkHttpResponse_GetCookieDomain(HCkHttpResponse cHandle, int index, HCkString outStr);
const char *CkHttpResponse_getCookieDomain(HCkHttpResponse cHandle, int index);
BOOL CkHttpResponse_GetCookieExpires(HCkHttpResponse cHandle, int index, SYSTEMTIME *outSysTime);
BOOL CkHttpResponse_GetCookieExpiresStr(HCkHttpResponse cHandle, int index, HCkString outStr);
const char *CkHttpResponse_getCookieExpiresStr(HCkHttpResponse cHandle, int index);
BOOL CkHttpResponse_GetCookieName(HCkHttpResponse cHandle, int index, HCkString outStr);
const char *CkHttpResponse_getCookieName(HCkHttpResponse cHandle, int index);
BOOL CkHttpResponse_GetCookiePath(HCkHttpResponse cHandle, int index, HCkString outStr);
const char *CkHttpResponse_getCookiePath(HCkHttpResponse cHandle, int index);
BOOL CkHttpResponse_GetCookieValue(HCkHttpResponse cHandle, int index, HCkString outStr);
const char *CkHttpResponse_getCookieValue(HCkHttpResponse cHandle, int index);
BOOL CkHttpResponse_GetHeaderField(HCkHttpResponse cHandle, const char *fieldName, HCkString outStr);
const char *CkHttpResponse_getHeaderField(HCkHttpResponse cHandle, const char *fieldName);
BOOL CkHttpResponse_GetHeaderFieldAttr(HCkHttpResponse cHandle, const char *fieldName, const char *attrName, HCkString outStr);
const char *CkHttpResponse_getHeaderFieldAttr(HCkHttpResponse cHandle, const char *fieldName, const char *attrName);
BOOL CkHttpResponse_GetHeaderName(HCkHttpResponse cHandle, int index, HCkString outStr);
const char *CkHttpResponse_getHeaderName(HCkHttpResponse cHandle, int index);
BOOL CkHttpResponse_GetHeaderValue(HCkHttpResponse cHandle, int index, HCkString outStr);
const char *CkHttpResponse_getHeaderValue(HCkHttpResponse cHandle, int index);
BOOL CkHttpResponse_SaveBodyBinary(HCkHttpResponse cHandle, const char *path);
BOOL CkHttpResponse_SaveBodyText(HCkHttpResponse cHandle, BOOL bCrlf, const char *path);
BOOL CkHttpResponse_SaveLastError(HCkHttpResponse cHandle, const char *path);
BOOL CkHttpResponse_UrlEncParamValue(HCkHttpResponse cHandle, const char *encodedParamString, const char *paramName, HCkString outStr);
const char *CkHttpResponse_urlEncParamValue(HCkHttpResponse cHandle, const char *encodedParamString, const char *paramName);
#endif
