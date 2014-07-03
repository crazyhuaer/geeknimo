// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkPublicKeyWH
#define _C_CkPublicKeyWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkPublicKeyW CkPublicKeyW_Create(void);
void CkPublicKeyW_Dispose(HCkPublicKeyW handle);
void CkPublicKeyW_getDebugLogFilePath(HCkPublicKeyW cHandle, HCkString retval);
void CkPublicKeyW_putDebugLogFilePath(HCkPublicKeyW cHandle, const wchar_t *newVal);
const wchar_t *CkPublicKeyW_debugLogFilePath(HCkPublicKeyW cHandle);
void CkPublicKeyW_getLastErrorHtml(HCkPublicKeyW cHandle, HCkString retval);
const wchar_t *CkPublicKeyW_lastErrorHtml(HCkPublicKeyW cHandle);
void CkPublicKeyW_getLastErrorText(HCkPublicKeyW cHandle, HCkString retval);
const wchar_t *CkPublicKeyW_lastErrorText(HCkPublicKeyW cHandle);
void CkPublicKeyW_getLastErrorXml(HCkPublicKeyW cHandle, HCkString retval);
const wchar_t *CkPublicKeyW_lastErrorXml(HCkPublicKeyW cHandle);
BOOL CkPublicKeyW_getVerboseLogging(HCkPublicKeyW cHandle);
void CkPublicKeyW_putVerboseLogging(HCkPublicKeyW cHandle, BOOL newVal);
void CkPublicKeyW_getVersion(HCkPublicKeyW cHandle, HCkString retval);
const wchar_t *CkPublicKeyW_version(HCkPublicKeyW cHandle);
BOOL CkPublicKeyW_GetOpenSslDer(HCkPublicKeyW cHandle, HCkByteData outData);
BOOL CkPublicKeyW_GetOpenSslPem(HCkPublicKeyW cHandle, HCkString outStr);
const wchar_t *CkPublicKeyW_getOpenSslPem(HCkPublicKeyW cHandle);
BOOL CkPublicKeyW_GetRsaDer(HCkPublicKeyW cHandle, HCkByteData outData);
BOOL CkPublicKeyW_GetXml(HCkPublicKeyW cHandle, HCkString outStr);
const wchar_t *CkPublicKeyW_getXml(HCkPublicKeyW cHandle);
BOOL CkPublicKeyW_LoadOpenSslDer(HCkPublicKeyW cHandle, HCkByteData data);
BOOL CkPublicKeyW_LoadOpenSslDerFile(HCkPublicKeyW cHandle, const wchar_t *path);
BOOL CkPublicKeyW_LoadOpenSslPem(HCkPublicKeyW cHandle, const wchar_t *str);
BOOL CkPublicKeyW_LoadOpenSslPemFile(HCkPublicKeyW cHandle, const wchar_t *path);
BOOL CkPublicKeyW_LoadPkcs1Pem(HCkPublicKeyW cHandle, const wchar_t *str);
BOOL CkPublicKeyW_LoadRsaDer(HCkPublicKeyW cHandle, HCkByteData data);
BOOL CkPublicKeyW_LoadRsaDerFile(HCkPublicKeyW cHandle, const wchar_t *path);
BOOL CkPublicKeyW_LoadXml(HCkPublicKeyW cHandle, const wchar_t *xml);
BOOL CkPublicKeyW_LoadXmlFile(HCkPublicKeyW cHandle, const wchar_t *path);
BOOL CkPublicKeyW_SaveLastError(HCkPublicKeyW cHandle, const wchar_t *path);
BOOL CkPublicKeyW_SaveOpenSslDerFile(HCkPublicKeyW cHandle, const wchar_t *path);
BOOL CkPublicKeyW_SaveOpenSslPemFile(HCkPublicKeyW cHandle, const wchar_t *path);
BOOL CkPublicKeyW_SaveRsaDerFile(HCkPublicKeyW cHandle, const wchar_t *path);
BOOL CkPublicKeyW_SaveXmlFile(HCkPublicKeyW cHandle, const wchar_t *path);
#endif
