// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkPrivateKeyWH
#define _C_CkPrivateKeyWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkPrivateKeyW CkPrivateKeyW_Create(void);
void CkPrivateKeyW_Dispose(HCkPrivateKeyW handle);
void CkPrivateKeyW_getDebugLogFilePath(HCkPrivateKeyW cHandle, HCkString retval);
void CkPrivateKeyW_putDebugLogFilePath(HCkPrivateKeyW cHandle, const wchar_t *newVal);
const wchar_t *CkPrivateKeyW_debugLogFilePath(HCkPrivateKeyW cHandle);
void CkPrivateKeyW_getLastErrorHtml(HCkPrivateKeyW cHandle, HCkString retval);
const wchar_t *CkPrivateKeyW_lastErrorHtml(HCkPrivateKeyW cHandle);
void CkPrivateKeyW_getLastErrorText(HCkPrivateKeyW cHandle, HCkString retval);
const wchar_t *CkPrivateKeyW_lastErrorText(HCkPrivateKeyW cHandle);
void CkPrivateKeyW_getLastErrorXml(HCkPrivateKeyW cHandle, HCkString retval);
const wchar_t *CkPrivateKeyW_lastErrorXml(HCkPrivateKeyW cHandle);
BOOL CkPrivateKeyW_getVerboseLogging(HCkPrivateKeyW cHandle);
void CkPrivateKeyW_putVerboseLogging(HCkPrivateKeyW cHandle, BOOL newVal);
void CkPrivateKeyW_getVersion(HCkPrivateKeyW cHandle, HCkString retval);
const wchar_t *CkPrivateKeyW_version(HCkPrivateKeyW cHandle);
BOOL CkPrivateKeyW_GetPkcs8(HCkPrivateKeyW cHandle, HCkByteData outData);
BOOL CkPrivateKeyW_GetPkcs8Encrypted(HCkPrivateKeyW cHandle, const wchar_t *password, HCkByteData outBytes);
BOOL CkPrivateKeyW_GetPkcs8EncryptedPem(HCkPrivateKeyW cHandle, const wchar_t *password, HCkString outStr);
const wchar_t *CkPrivateKeyW_getPkcs8EncryptedPem(HCkPrivateKeyW cHandle, const wchar_t *password);
BOOL CkPrivateKeyW_GetPkcs8Pem(HCkPrivateKeyW cHandle, HCkString outStr);
const wchar_t *CkPrivateKeyW_getPkcs8Pem(HCkPrivateKeyW cHandle);
BOOL CkPrivateKeyW_GetRsaDer(HCkPrivateKeyW cHandle, HCkByteData outData);
BOOL CkPrivateKeyW_GetRsaPem(HCkPrivateKeyW cHandle, HCkString outStr);
const wchar_t *CkPrivateKeyW_getRsaPem(HCkPrivateKeyW cHandle);
BOOL CkPrivateKeyW_GetXml(HCkPrivateKeyW cHandle, HCkString outStr);
const wchar_t *CkPrivateKeyW_getXml(HCkPrivateKeyW cHandle);
BOOL CkPrivateKeyW_LoadEncryptedPem(HCkPrivateKeyW cHandle, const wchar_t *pemStr, const wchar_t *password);
BOOL CkPrivateKeyW_LoadEncryptedPemFile(HCkPrivateKeyW cHandle, const wchar_t *path, const wchar_t *password);
BOOL CkPrivateKeyW_LoadPem(HCkPrivateKeyW cHandle, const wchar_t *str);
BOOL CkPrivateKeyW_LoadPemFile(HCkPrivateKeyW cHandle, const wchar_t *path);
BOOL CkPrivateKeyW_LoadPkcs8(HCkPrivateKeyW cHandle, HCkByteData data);
BOOL CkPrivateKeyW_LoadPkcs8Encrypted(HCkPrivateKeyW cHandle, HCkByteData data, const wchar_t *password);
BOOL CkPrivateKeyW_LoadPkcs8EncryptedFile(HCkPrivateKeyW cHandle, const wchar_t *path, const wchar_t *password);
BOOL CkPrivateKeyW_LoadPkcs8File(HCkPrivateKeyW cHandle, const wchar_t *path);
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkPrivateKeyW_LoadPvk(HCkPrivateKeyW cHandle, HCkByteData data, const wchar_t *password);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkPrivateKeyW_LoadPvkFile(HCkPrivateKeyW cHandle, const wchar_t *path, const wchar_t *password);
#endif
BOOL CkPrivateKeyW_LoadRsaDer(HCkPrivateKeyW cHandle, HCkByteData data);
BOOL CkPrivateKeyW_LoadRsaDerFile(HCkPrivateKeyW cHandle, const wchar_t *path);
BOOL CkPrivateKeyW_LoadXml(HCkPrivateKeyW cHandle, const wchar_t *xml);
BOOL CkPrivateKeyW_LoadXmlFile(HCkPrivateKeyW cHandle, const wchar_t *path);
BOOL CkPrivateKeyW_SaveLastError(HCkPrivateKeyW cHandle, const wchar_t *path);
BOOL CkPrivateKeyW_SavePkcs8EncryptedFile(HCkPrivateKeyW cHandle, const wchar_t *password, const wchar_t *path);
BOOL CkPrivateKeyW_SavePkcs8EncryptedPemFile(HCkPrivateKeyW cHandle, const wchar_t *password, const wchar_t *path);
BOOL CkPrivateKeyW_SavePkcs8File(HCkPrivateKeyW cHandle, const wchar_t *path);
BOOL CkPrivateKeyW_SavePkcs8PemFile(HCkPrivateKeyW cHandle, const wchar_t *path);
BOOL CkPrivateKeyW_SaveRsaDerFile(HCkPrivateKeyW cHandle, const wchar_t *path);
BOOL CkPrivateKeyW_SaveRsaPemFile(HCkPrivateKeyW cHandle, const wchar_t *path);
BOOL CkPrivateKeyW_SaveXmlFile(HCkPrivateKeyW cHandle, const wchar_t *path);
#endif
