// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkHttpRequestWH
#define _C_CkHttpRequestWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkHttpRequestW CkHttpRequestW_Create(void);
void CkHttpRequestW_Dispose(HCkHttpRequestW handle);
void CkHttpRequestW_getCharset(HCkHttpRequestW cHandle, HCkString retval);
void CkHttpRequestW_putCharset(HCkHttpRequestW cHandle, const wchar_t *newVal);
const wchar_t *CkHttpRequestW_charset(HCkHttpRequestW cHandle);
void CkHttpRequestW_getContentType(HCkHttpRequestW cHandle, HCkString retval);
void CkHttpRequestW_putContentType(HCkHttpRequestW cHandle, const wchar_t *newVal);
const wchar_t *CkHttpRequestW_contentType(HCkHttpRequestW cHandle);
void CkHttpRequestW_getDebugLogFilePath(HCkHttpRequestW cHandle, HCkString retval);
void CkHttpRequestW_putDebugLogFilePath(HCkHttpRequestW cHandle, const wchar_t *newVal);
const wchar_t *CkHttpRequestW_debugLogFilePath(HCkHttpRequestW cHandle);
void CkHttpRequestW_getEntireHeader(HCkHttpRequestW cHandle, HCkString retval);
void CkHttpRequestW_putEntireHeader(HCkHttpRequestW cHandle, const wchar_t *newVal);
const wchar_t *CkHttpRequestW_entireHeader(HCkHttpRequestW cHandle);
void CkHttpRequestW_getHttpVerb(HCkHttpRequestW cHandle, HCkString retval);
void CkHttpRequestW_putHttpVerb(HCkHttpRequestW cHandle, const wchar_t *newVal);
const wchar_t *CkHttpRequestW_httpVerb(HCkHttpRequestW cHandle);
void CkHttpRequestW_getHttpVersion(HCkHttpRequestW cHandle, HCkString retval);
void CkHttpRequestW_putHttpVersion(HCkHttpRequestW cHandle, const wchar_t *newVal);
const wchar_t *CkHttpRequestW_httpVersion(HCkHttpRequestW cHandle);
void CkHttpRequestW_getLastErrorHtml(HCkHttpRequestW cHandle, HCkString retval);
const wchar_t *CkHttpRequestW_lastErrorHtml(HCkHttpRequestW cHandle);
void CkHttpRequestW_getLastErrorText(HCkHttpRequestW cHandle, HCkString retval);
const wchar_t *CkHttpRequestW_lastErrorText(HCkHttpRequestW cHandle);
void CkHttpRequestW_getLastErrorXml(HCkHttpRequestW cHandle, HCkString retval);
const wchar_t *CkHttpRequestW_lastErrorXml(HCkHttpRequestW cHandle);
int CkHttpRequestW_getNumHeaderFields(HCkHttpRequestW cHandle);
int CkHttpRequestW_getNumParams(HCkHttpRequestW cHandle);
void CkHttpRequestW_getPath(HCkHttpRequestW cHandle, HCkString retval);
void CkHttpRequestW_putPath(HCkHttpRequestW cHandle, const wchar_t *newVal);
const wchar_t *CkHttpRequestW_path(HCkHttpRequestW cHandle);
BOOL CkHttpRequestW_getSendCharset(HCkHttpRequestW cHandle);
void CkHttpRequestW_putSendCharset(HCkHttpRequestW cHandle, BOOL newVal);
BOOL CkHttpRequestW_getVerboseLogging(HCkHttpRequestW cHandle);
void CkHttpRequestW_putVerboseLogging(HCkHttpRequestW cHandle, BOOL newVal);
void CkHttpRequestW_getVersion(HCkHttpRequestW cHandle, HCkString retval);
const wchar_t *CkHttpRequestW_version(HCkHttpRequestW cHandle);
BOOL CkHttpRequestW_AddBytesForUpload(HCkHttpRequestW cHandle, const wchar_t *name, const wchar_t *remoteFileName, HCkByteData byteData);
BOOL CkHttpRequestW_AddBytesForUpload2(HCkHttpRequestW cHandle, const wchar_t *name, const wchar_t *remoteFileName, HCkByteData byteData, const wchar_t *contentType);
BOOL CkHttpRequestW_AddFileForUpload(HCkHttpRequestW cHandle, const wchar_t *name, const wchar_t *filePath);
BOOL CkHttpRequestW_AddFileForUpload2(HCkHttpRequestW cHandle, const wchar_t *name, const wchar_t *filePath, const wchar_t *contentType);
void CkHttpRequestW_AddHeader(HCkHttpRequestW cHandle, const wchar_t *name, const wchar_t *value);
void CkHttpRequestW_AddParam(HCkHttpRequestW cHandle, const wchar_t *name, const wchar_t *value);
BOOL CkHttpRequestW_AddStringForUpload(HCkHttpRequestW cHandle, const wchar_t *name, const wchar_t *filename, const wchar_t *strData, const wchar_t *charset);
BOOL CkHttpRequestW_AddStringForUpload2(HCkHttpRequestW cHandle, const wchar_t *name, const wchar_t *filename, const wchar_t *strData, const wchar_t *charset, const wchar_t *contentType);
BOOL CkHttpRequestW_GenerateRequestText(HCkHttpRequestW cHandle, HCkString outStr);
const wchar_t *CkHttpRequestW_generateRequestText(HCkHttpRequestW cHandle);
BOOL CkHttpRequestW_GetHeaderField(HCkHttpRequestW cHandle, const wchar_t *name, HCkString outStr);
const wchar_t *CkHttpRequestW_getHeaderField(HCkHttpRequestW cHandle, const wchar_t *name);
BOOL CkHttpRequestW_GetHeaderName(HCkHttpRequestW cHandle, int index, HCkString outStr);
const wchar_t *CkHttpRequestW_getHeaderName(HCkHttpRequestW cHandle, int index);
BOOL CkHttpRequestW_GetHeaderValue(HCkHttpRequestW cHandle, int index, HCkString outStr);
const wchar_t *CkHttpRequestW_getHeaderValue(HCkHttpRequestW cHandle, int index);
BOOL CkHttpRequestW_GetParam(HCkHttpRequestW cHandle, const wchar_t *name, HCkString outStr);
const wchar_t *CkHttpRequestW_getParam(HCkHttpRequestW cHandle, const wchar_t *name);
BOOL CkHttpRequestW_GetParamName(HCkHttpRequestW cHandle, int index, HCkString outStr);
const wchar_t *CkHttpRequestW_getParamName(HCkHttpRequestW cHandle, int index);
BOOL CkHttpRequestW_GetParamValue(HCkHttpRequestW cHandle, int index, HCkString outStr);
const wchar_t *CkHttpRequestW_getParamValue(HCkHttpRequestW cHandle, int index);
BOOL CkHttpRequestW_GetUrlEncodedParams(HCkHttpRequestW cHandle, HCkString outStr);
const wchar_t *CkHttpRequestW_getUrlEncodedParams(HCkHttpRequestW cHandle);
BOOL CkHttpRequestW_LoadBodyFromBytes(HCkHttpRequestW cHandle, HCkByteData byteData);
BOOL CkHttpRequestW_LoadBodyFromFile(HCkHttpRequestW cHandle, const wchar_t *filePath);
BOOL CkHttpRequestW_LoadBodyFromString(HCkHttpRequestW cHandle, const wchar_t *bodyStr, const wchar_t *charset);
void CkHttpRequestW_RemoveAllParams(HCkHttpRequestW cHandle);
BOOL CkHttpRequestW_RemoveHeader(HCkHttpRequestW cHandle, const wchar_t *name);
void CkHttpRequestW_RemoveParam(HCkHttpRequestW cHandle, const wchar_t *name);
BOOL CkHttpRequestW_SaveLastError(HCkHttpRequestW cHandle, const wchar_t *path);
void CkHttpRequestW_SetFromUrl(HCkHttpRequestW cHandle, const wchar_t *url);
BOOL CkHttpRequestW_StreamBodyFromFile(HCkHttpRequestW cHandle, const wchar_t *filePath);
void CkHttpRequestW_UseGet(HCkHttpRequestW cHandle);
void CkHttpRequestW_UseHead(HCkHttpRequestW cHandle);
void CkHttpRequestW_UsePost(HCkHttpRequestW cHandle);
void CkHttpRequestW_UsePostMultipartForm(HCkHttpRequestW cHandle);
void CkHttpRequestW_UsePut(HCkHttpRequestW cHandle);
void CkHttpRequestW_UseUpload(HCkHttpRequestW cHandle);
void CkHttpRequestW_UseUploadPut(HCkHttpRequestW cHandle);
void CkHttpRequestW_UseXmlHttp(HCkHttpRequestW cHandle, const wchar_t *xmlBody);
#endif
