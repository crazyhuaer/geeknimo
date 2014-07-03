// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkUploadWH
#define _C_CkUploadWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkUploadW CkUploadW_Create(void);
HCkUploadW CkUploadW_Create2(BOOL bCallbackOwned);
void CkUploadW_Dispose(HCkUploadW handle);
int CkUploadW_getChunkSize(HCkUploadW cHandle);
void CkUploadW_putChunkSize(HCkUploadW cHandle, int newVal);
void CkUploadW_getDebugLogFilePath(HCkUploadW cHandle, HCkString retval);
void CkUploadW_putDebugLogFilePath(HCkUploadW cHandle, const wchar_t *newVal);
const wchar_t *CkUploadW_debugLogFilePath(HCkUploadW cHandle);
BOOL CkUploadW_getExpect100Continue(HCkUploadW cHandle);
void CkUploadW_putExpect100Continue(HCkUploadW cHandle, BOOL newVal);
int CkUploadW_getHeartbeatMs(HCkUploadW cHandle);
void CkUploadW_putHeartbeatMs(HCkUploadW cHandle, int newVal);
void CkUploadW_getHostname(HCkUploadW cHandle, HCkString retval);
void CkUploadW_putHostname(HCkUploadW cHandle, const wchar_t *newVal);
const wchar_t *CkUploadW_hostname(HCkUploadW cHandle);
int CkUploadW_getIdleTimeoutMs(HCkUploadW cHandle);
void CkUploadW_putIdleTimeoutMs(HCkUploadW cHandle, int newVal);
void CkUploadW_getLastErrorHtml(HCkUploadW cHandle, HCkString retval);
const wchar_t *CkUploadW_lastErrorHtml(HCkUploadW cHandle);
void CkUploadW_getLastErrorText(HCkUploadW cHandle, HCkString retval);
const wchar_t *CkUploadW_lastErrorText(HCkUploadW cHandle);
void CkUploadW_getLastErrorXml(HCkUploadW cHandle, HCkString retval);
const wchar_t *CkUploadW_lastErrorXml(HCkUploadW cHandle);
void CkUploadW_getLogin(HCkUploadW cHandle, HCkString retval);
void CkUploadW_putLogin(HCkUploadW cHandle, const wchar_t *newVal);
const wchar_t *CkUploadW_login(HCkUploadW cHandle);
unsigned long CkUploadW_getNumBytesSent(HCkUploadW cHandle);
void CkUploadW_getPassword(HCkUploadW cHandle, HCkString retval);
void CkUploadW_putPassword(HCkUploadW cHandle, const wchar_t *newVal);
const wchar_t *CkUploadW_password(HCkUploadW cHandle);
void CkUploadW_getPath(HCkUploadW cHandle, HCkString retval);
void CkUploadW_putPath(HCkUploadW cHandle, const wchar_t *newVal);
const wchar_t *CkUploadW_path(HCkUploadW cHandle);
unsigned long CkUploadW_getPercentUploaded(HCkUploadW cHandle);
int CkUploadW_getPort(HCkUploadW cHandle);
void CkUploadW_putPort(HCkUploadW cHandle, int newVal);
BOOL CkUploadW_getPreferIpv6(HCkUploadW cHandle);
void CkUploadW_putPreferIpv6(HCkUploadW cHandle, BOOL newVal);
void CkUploadW_getProxyDomain(HCkUploadW cHandle, HCkString retval);
void CkUploadW_putProxyDomain(HCkUploadW cHandle, const wchar_t *newVal);
const wchar_t *CkUploadW_proxyDomain(HCkUploadW cHandle);
void CkUploadW_getProxyLogin(HCkUploadW cHandle, HCkString retval);
void CkUploadW_putProxyLogin(HCkUploadW cHandle, const wchar_t *newVal);
const wchar_t *CkUploadW_proxyLogin(HCkUploadW cHandle);
void CkUploadW_getProxyPassword(HCkUploadW cHandle, HCkString retval);
void CkUploadW_putProxyPassword(HCkUploadW cHandle, const wchar_t *newVal);
const wchar_t *CkUploadW_proxyPassword(HCkUploadW cHandle);
int CkUploadW_getProxyPort(HCkUploadW cHandle);
void CkUploadW_putProxyPort(HCkUploadW cHandle, int newVal);
void CkUploadW_getResponseBody(HCkUploadW cHandle, HCkByteData retval);
void CkUploadW_getResponseHeader(HCkUploadW cHandle, HCkString retval);
const wchar_t *CkUploadW_responseHeader(HCkUploadW cHandle);
int CkUploadW_getResponseStatus(HCkUploadW cHandle);
BOOL CkUploadW_getSsl(HCkUploadW cHandle);
void CkUploadW_putSsl(HCkUploadW cHandle, BOOL newVal);
unsigned long CkUploadW_getTotalUploadSize(HCkUploadW cHandle);
BOOL CkUploadW_getUploadInProgress(HCkUploadW cHandle);
BOOL CkUploadW_getUploadSuccess(HCkUploadW cHandle);
BOOL CkUploadW_getVerboseLogging(HCkUploadW cHandle);
void CkUploadW_putVerboseLogging(HCkUploadW cHandle, BOOL newVal);
void CkUploadW_getVersion(HCkUploadW cHandle, HCkString retval);
const wchar_t *CkUploadW_version(HCkUploadW cHandle);
void CkUploadW_AddCustomHeader(HCkUploadW cHandle, const wchar_t *name, const wchar_t *value);
void CkUploadW_AddFileReference(HCkUploadW cHandle, const wchar_t *name, const wchar_t *filename);
void CkUploadW_AddParam(HCkUploadW cHandle, const wchar_t *name, const wchar_t *value);
BOOL CkUploadW_BlockingUpload(HCkUploadW cHandle);
void CkUploadW_ClearFileReferences(HCkUploadW cHandle);
void CkUploadW_ClearParams(HCkUploadW cHandle);
BOOL CkUploadW_SaveLastError(HCkUploadW cHandle, const wchar_t *path);
void CkUploadW_SleepMs(HCkUploadW cHandle, int millisec);
BOOL CkUploadW_UploadToMemory(HCkUploadW cHandle, HCkByteData outData);
#endif
