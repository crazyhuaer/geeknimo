// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCgi_H
#define _C_CkCgi_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCgi CkCgi_Create(void);
void CkCgi_Dispose(HCkCgi handle);
unsigned long CkCgi_getAsyncBytesRead(HCkCgi cHandle);
BOOL CkCgi_getAsyncInProgress(HCkCgi cHandle);
unsigned long CkCgi_getAsyncPostSize(HCkCgi cHandle);
BOOL CkCgi_getAsyncSuccess(HCkCgi cHandle);
void CkCgi_getDebugLogFilePath(HCkCgi cHandle, HCkString retval);
void CkCgi_putDebugLogFilePath(HCkCgi cHandle, const char *newVal);
const char *CkCgi_debugLogFilePath(HCkCgi cHandle);
int CkCgi_getHeartbeatMs(HCkCgi cHandle);
void CkCgi_putHeartbeatMs(HCkCgi cHandle, int newVal);
int CkCgi_getIdleTimeoutMs(HCkCgi cHandle);
void CkCgi_putIdleTimeoutMs(HCkCgi cHandle, int newVal);
void CkCgi_getLastErrorHtml(HCkCgi cHandle, HCkString retval);
const char *CkCgi_lastErrorHtml(HCkCgi cHandle);
void CkCgi_getLastErrorText(HCkCgi cHandle, HCkString retval);
const char *CkCgi_lastErrorText(HCkCgi cHandle);
void CkCgi_getLastErrorXml(HCkCgi cHandle, HCkString retval);
const char *CkCgi_lastErrorXml(HCkCgi cHandle);
int CkCgi_getNumParams(HCkCgi cHandle);
int CkCgi_getNumUploadFiles(HCkCgi cHandle);
int CkCgi_getReadChunkSize(HCkCgi cHandle);
void CkCgi_putReadChunkSize(HCkCgi cHandle, int newVal);
unsigned long CkCgi_getSizeLimitKB(HCkCgi cHandle);
void CkCgi_putSizeLimitKB(HCkCgi cHandle, unsigned long newVal);
BOOL CkCgi_getStreamToUploadDir(HCkCgi cHandle);
void CkCgi_putStreamToUploadDir(HCkCgi cHandle, BOOL newVal);
void CkCgi_getUploadDir(HCkCgi cHandle, HCkString retval);
void CkCgi_putUploadDir(HCkCgi cHandle, const char *newVal);
const char *CkCgi_uploadDir(HCkCgi cHandle);
BOOL CkCgi_getUtf8(HCkCgi cHandle);
void CkCgi_putUtf8(HCkCgi cHandle, BOOL newVal);
BOOL CkCgi_getVerboseLogging(HCkCgi cHandle);
void CkCgi_putVerboseLogging(HCkCgi cHandle, BOOL newVal);
void CkCgi_getVersion(HCkCgi cHandle, HCkString retval);
const char *CkCgi_version(HCkCgi cHandle);
void CkCgi_AbortAsync(HCkCgi cHandle);
BOOL CkCgi_GetEnv(HCkCgi cHandle, const char *varName, HCkString outStr);
const char *CkCgi_getEnv(HCkCgi cHandle, const char *varName);
BOOL CkCgi_GetParam(HCkCgi cHandle, const char *paramName, HCkString outStr);
const char *CkCgi_getParam(HCkCgi cHandle, const char *paramName);
BOOL CkCgi_GetParamName(HCkCgi cHandle, int index, HCkString outStr);
const char *CkCgi_getParamName(HCkCgi cHandle, int index);
BOOL CkCgi_GetParamValue(HCkCgi cHandle, int index, HCkString outStr);
const char *CkCgi_getParamValue(HCkCgi cHandle, int index);
BOOL CkCgi_GetRawPostData(HCkCgi cHandle, HCkByteData outData);
BOOL CkCgi_GetUploadData(HCkCgi cHandle, int index, HCkByteData outData);
BOOL CkCgi_GetUploadFilename(HCkCgi cHandle, int index, HCkString outStr);
const char *CkCgi_getUploadFilename(HCkCgi cHandle, int index);
unsigned long CkCgi_GetUploadSize(HCkCgi cHandle, int index);
BOOL CkCgi_IsGet(HCkCgi cHandle);
BOOL CkCgi_IsHead(HCkCgi cHandle);
BOOL CkCgi_IsPost(HCkCgi cHandle);
BOOL CkCgi_IsUpload(HCkCgi cHandle);
BOOL CkCgi_ReadRequest(HCkCgi cHandle);
BOOL CkCgi_SaveLastError(HCkCgi cHandle, const char *path);
BOOL CkCgi_SaveNthToUploadDir(HCkCgi cHandle, int index);
void CkCgi_SleepMs(HCkCgi cHandle, int millisec);
BOOL CkCgi_TestConsumeAspUpload(HCkCgi cHandle, const char *path);
#endif
