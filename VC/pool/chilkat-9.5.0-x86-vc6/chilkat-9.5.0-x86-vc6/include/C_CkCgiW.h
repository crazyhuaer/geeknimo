// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCgiWH
#define _C_CkCgiWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCgiW CkCgiW_Create(void);
void CkCgiW_Dispose(HCkCgiW handle);
unsigned long CkCgiW_getAsyncBytesRead(HCkCgiW cHandle);
BOOL CkCgiW_getAsyncInProgress(HCkCgiW cHandle);
unsigned long CkCgiW_getAsyncPostSize(HCkCgiW cHandle);
BOOL CkCgiW_getAsyncSuccess(HCkCgiW cHandle);
void CkCgiW_getDebugLogFilePath(HCkCgiW cHandle, HCkString retval);
void CkCgiW_putDebugLogFilePath(HCkCgiW cHandle, const wchar_t *newVal);
const wchar_t *CkCgiW_debugLogFilePath(HCkCgiW cHandle);
int CkCgiW_getHeartbeatMs(HCkCgiW cHandle);
void CkCgiW_putHeartbeatMs(HCkCgiW cHandle, int newVal);
int CkCgiW_getIdleTimeoutMs(HCkCgiW cHandle);
void CkCgiW_putIdleTimeoutMs(HCkCgiW cHandle, int newVal);
void CkCgiW_getLastErrorHtml(HCkCgiW cHandle, HCkString retval);
const wchar_t *CkCgiW_lastErrorHtml(HCkCgiW cHandle);
void CkCgiW_getLastErrorText(HCkCgiW cHandle, HCkString retval);
const wchar_t *CkCgiW_lastErrorText(HCkCgiW cHandle);
void CkCgiW_getLastErrorXml(HCkCgiW cHandle, HCkString retval);
const wchar_t *CkCgiW_lastErrorXml(HCkCgiW cHandle);
int CkCgiW_getNumParams(HCkCgiW cHandle);
int CkCgiW_getNumUploadFiles(HCkCgiW cHandle);
int CkCgiW_getReadChunkSize(HCkCgiW cHandle);
void CkCgiW_putReadChunkSize(HCkCgiW cHandle, int newVal);
unsigned long CkCgiW_getSizeLimitKB(HCkCgiW cHandle);
void CkCgiW_putSizeLimitKB(HCkCgiW cHandle, unsigned long newVal);
BOOL CkCgiW_getStreamToUploadDir(HCkCgiW cHandle);
void CkCgiW_putStreamToUploadDir(HCkCgiW cHandle, BOOL newVal);
void CkCgiW_getUploadDir(HCkCgiW cHandle, HCkString retval);
void CkCgiW_putUploadDir(HCkCgiW cHandle, const wchar_t *newVal);
const wchar_t *CkCgiW_uploadDir(HCkCgiW cHandle);
BOOL CkCgiW_getVerboseLogging(HCkCgiW cHandle);
void CkCgiW_putVerboseLogging(HCkCgiW cHandle, BOOL newVal);
void CkCgiW_getVersion(HCkCgiW cHandle, HCkString retval);
const wchar_t *CkCgiW_version(HCkCgiW cHandle);
void CkCgiW_AbortAsync(HCkCgiW cHandle);
BOOL CkCgiW_GetEnv(HCkCgiW cHandle, const wchar_t *varName, HCkString outStr);
const wchar_t *CkCgiW_getEnv(HCkCgiW cHandle, const wchar_t *varName);
BOOL CkCgiW_GetParam(HCkCgiW cHandle, const wchar_t *paramName, HCkString outStr);
const wchar_t *CkCgiW_getParam(HCkCgiW cHandle, const wchar_t *paramName);
BOOL CkCgiW_GetParamName(HCkCgiW cHandle, int index, HCkString outStr);
const wchar_t *CkCgiW_getParamName(HCkCgiW cHandle, int index);
BOOL CkCgiW_GetParamValue(HCkCgiW cHandle, int index, HCkString outStr);
const wchar_t *CkCgiW_getParamValue(HCkCgiW cHandle, int index);
BOOL CkCgiW_GetRawPostData(HCkCgiW cHandle, HCkByteData outData);
BOOL CkCgiW_GetUploadData(HCkCgiW cHandle, int index, HCkByteData outData);
BOOL CkCgiW_GetUploadFilename(HCkCgiW cHandle, int index, HCkString outStr);
const wchar_t *CkCgiW_getUploadFilename(HCkCgiW cHandle, int index);
unsigned long CkCgiW_GetUploadSize(HCkCgiW cHandle, int index);
BOOL CkCgiW_IsGet(HCkCgiW cHandle);
BOOL CkCgiW_IsHead(HCkCgiW cHandle);
BOOL CkCgiW_IsPost(HCkCgiW cHandle);
BOOL CkCgiW_IsUpload(HCkCgiW cHandle);
BOOL CkCgiW_ReadRequest(HCkCgiW cHandle);
BOOL CkCgiW_SaveLastError(HCkCgiW cHandle, const wchar_t *path);
BOOL CkCgiW_SaveNthToUploadDir(HCkCgiW cHandle, int index);
void CkCgiW_SleepMs(HCkCgiW cHandle, int millisec);
BOOL CkCgiW_TestConsumeAspUpload(HCkCgiW cHandle, const wchar_t *path);
#endif
