// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkUpload_H
#define _C_CkUpload_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkUpload CkUpload_Create(void);
void CkUpload_Dispose(HCkUpload handle);
int CkUpload_getChunkSize(HCkUpload cHandle);
void CkUpload_putChunkSize(HCkUpload cHandle, int newVal);
void CkUpload_getDebugLogFilePath(HCkUpload cHandle, HCkString retval);
void CkUpload_putDebugLogFilePath(HCkUpload cHandle, const char *newVal);
const char *CkUpload_debugLogFilePath(HCkUpload cHandle);
BOOL CkUpload_getExpect100Continue(HCkUpload cHandle);
void CkUpload_putExpect100Continue(HCkUpload cHandle, BOOL newVal);
int CkUpload_getHeartbeatMs(HCkUpload cHandle);
void CkUpload_putHeartbeatMs(HCkUpload cHandle, int newVal);
void CkUpload_getHostname(HCkUpload cHandle, HCkString retval);
void CkUpload_putHostname(HCkUpload cHandle, const char *newVal);
const char *CkUpload_hostname(HCkUpload cHandle);
int CkUpload_getIdleTimeoutMs(HCkUpload cHandle);
void CkUpload_putIdleTimeoutMs(HCkUpload cHandle, int newVal);
void CkUpload_getLastErrorHtml(HCkUpload cHandle, HCkString retval);
const char *CkUpload_lastErrorHtml(HCkUpload cHandle);
void CkUpload_getLastErrorText(HCkUpload cHandle, HCkString retval);
const char *CkUpload_lastErrorText(HCkUpload cHandle);
void CkUpload_getLastErrorXml(HCkUpload cHandle, HCkString retval);
const char *CkUpload_lastErrorXml(HCkUpload cHandle);
void CkUpload_getLogin(HCkUpload cHandle, HCkString retval);
void CkUpload_putLogin(HCkUpload cHandle, const char *newVal);
const char *CkUpload_login(HCkUpload cHandle);
unsigned long CkUpload_getNumBytesSent(HCkUpload cHandle);
void CkUpload_getPassword(HCkUpload cHandle, HCkString retval);
void CkUpload_putPassword(HCkUpload cHandle, const char *newVal);
const char *CkUpload_password(HCkUpload cHandle);
void CkUpload_getPath(HCkUpload cHandle, HCkString retval);
void CkUpload_putPath(HCkUpload cHandle, const char *newVal);
const char *CkUpload_path(HCkUpload cHandle);
unsigned long CkUpload_getPercentUploaded(HCkUpload cHandle);
int CkUpload_getPort(HCkUpload cHandle);
void CkUpload_putPort(HCkUpload cHandle, int newVal);
BOOL CkUpload_getPreferIpv6(HCkUpload cHandle);
void CkUpload_putPreferIpv6(HCkUpload cHandle, BOOL newVal);
void CkUpload_getProxyDomain(HCkUpload cHandle, HCkString retval);
void CkUpload_putProxyDomain(HCkUpload cHandle, const char *newVal);
const char *CkUpload_proxyDomain(HCkUpload cHandle);
void CkUpload_getProxyLogin(HCkUpload cHandle, HCkString retval);
void CkUpload_putProxyLogin(HCkUpload cHandle, const char *newVal);
const char *CkUpload_proxyLogin(HCkUpload cHandle);
void CkUpload_getProxyPassword(HCkUpload cHandle, HCkString retval);
void CkUpload_putProxyPassword(HCkUpload cHandle, const char *newVal);
const char *CkUpload_proxyPassword(HCkUpload cHandle);
int CkUpload_getProxyPort(HCkUpload cHandle);
void CkUpload_putProxyPort(HCkUpload cHandle, int newVal);
void CkUpload_getResponseBody(HCkUpload cHandle, HCkByteData retval);
void CkUpload_getResponseHeader(HCkUpload cHandle, HCkString retval);
const char *CkUpload_responseHeader(HCkUpload cHandle);
int CkUpload_getResponseStatus(HCkUpload cHandle);
BOOL CkUpload_getSsl(HCkUpload cHandle);
void CkUpload_putSsl(HCkUpload cHandle, BOOL newVal);
unsigned long CkUpload_getTotalUploadSize(HCkUpload cHandle);
BOOL CkUpload_getUploadInProgress(HCkUpload cHandle);
BOOL CkUpload_getUploadSuccess(HCkUpload cHandle);
BOOL CkUpload_getUtf8(HCkUpload cHandle);
void CkUpload_putUtf8(HCkUpload cHandle, BOOL newVal);
BOOL CkUpload_getVerboseLogging(HCkUpload cHandle);
void CkUpload_putVerboseLogging(HCkUpload cHandle, BOOL newVal);
void CkUpload_getVersion(HCkUpload cHandle, HCkString retval);
const char *CkUpload_version(HCkUpload cHandle);
void CkUpload_AddCustomHeader(HCkUpload cHandle, const char *name, const char *value);
void CkUpload_AddFileReference(HCkUpload cHandle, const char *name, const char *filename);
void CkUpload_AddParam(HCkUpload cHandle, const char *name, const char *value);
BOOL CkUpload_BlockingUpload(HCkUpload cHandle);
void CkUpload_ClearFileReferences(HCkUpload cHandle);
void CkUpload_ClearParams(HCkUpload cHandle);
BOOL CkUpload_SaveLastError(HCkUpload cHandle, const char *path);
void CkUpload_SleepMs(HCkUpload cHandle, int millisec);
BOOL CkUpload_UploadToMemory(HCkUpload cHandle, HCkByteData outData);
#endif
