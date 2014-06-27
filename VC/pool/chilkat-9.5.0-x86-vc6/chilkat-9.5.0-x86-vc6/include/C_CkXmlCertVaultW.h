// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkXmlCertVaultWH
#define _C_CkXmlCertVaultWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkXmlCertVaultW CkXmlCertVaultW_Create(void);
void CkXmlCertVaultW_Dispose(HCkXmlCertVaultW handle);
void CkXmlCertVaultW_getDebugLogFilePath(HCkXmlCertVaultW cHandle, HCkString retval);
void CkXmlCertVaultW_putDebugLogFilePath(HCkXmlCertVaultW cHandle, const wchar_t *newVal);
const wchar_t *CkXmlCertVaultW_debugLogFilePath(HCkXmlCertVaultW cHandle);
void CkXmlCertVaultW_getLastErrorHtml(HCkXmlCertVaultW cHandle, HCkString retval);
const wchar_t *CkXmlCertVaultW_lastErrorHtml(HCkXmlCertVaultW cHandle);
void CkXmlCertVaultW_getLastErrorText(HCkXmlCertVaultW cHandle, HCkString retval);
const wchar_t *CkXmlCertVaultW_lastErrorText(HCkXmlCertVaultW cHandle);
void CkXmlCertVaultW_getLastErrorXml(HCkXmlCertVaultW cHandle, HCkString retval);
const wchar_t *CkXmlCertVaultW_lastErrorXml(HCkXmlCertVaultW cHandle);
void CkXmlCertVaultW_getMasterPassword(HCkXmlCertVaultW cHandle, HCkString retval);
void CkXmlCertVaultW_putMasterPassword(HCkXmlCertVaultW cHandle, const wchar_t *newVal);
const wchar_t *CkXmlCertVaultW_masterPassword(HCkXmlCertVaultW cHandle);
BOOL CkXmlCertVaultW_getVerboseLogging(HCkXmlCertVaultW cHandle);
void CkXmlCertVaultW_putVerboseLogging(HCkXmlCertVaultW cHandle, BOOL newVal);
void CkXmlCertVaultW_getVersion(HCkXmlCertVaultW cHandle, HCkString retval);
const wchar_t *CkXmlCertVaultW_version(HCkXmlCertVaultW cHandle);
BOOL CkXmlCertVaultW_AddCert(HCkXmlCertVaultW cHandle, HCkCertW cert);
BOOL CkXmlCertVaultW_AddCertBinary(HCkXmlCertVaultW cHandle, HCkByteData certBytes);
BOOL CkXmlCertVaultW_AddCertChain(HCkXmlCertVaultW cHandle, HCkCertChainW certChain);
BOOL CkXmlCertVaultW_AddCertEncoded(HCkXmlCertVaultW cHandle, const wchar_t *encodedBytes, const wchar_t *encoding);
BOOL CkXmlCertVaultW_AddCertFile(HCkXmlCertVaultW cHandle, const wchar_t *path);
BOOL CkXmlCertVaultW_AddCertString(HCkXmlCertVaultW cHandle, const wchar_t *certData);
BOOL CkXmlCertVaultW_AddPemFile(HCkXmlCertVaultW cHandle, const wchar_t *path, const wchar_t *password);
BOOL CkXmlCertVaultW_AddPfx(HCkXmlCertVaultW cHandle, HCkPfxW pfx);
BOOL CkXmlCertVaultW_AddPfxBinary(HCkXmlCertVaultW cHandle, HCkByteData pfxBytes, const wchar_t *password);
BOOL CkXmlCertVaultW_AddPfxEncoded(HCkXmlCertVaultW cHandle, const wchar_t *encodedBytes, const wchar_t *encoding, const wchar_t *password);
BOOL CkXmlCertVaultW_AddPfxFile(HCkXmlCertVaultW cHandle, const wchar_t *path, const wchar_t *password);
BOOL CkXmlCertVaultW_GetXml(HCkXmlCertVaultW cHandle, HCkString outStr);
const wchar_t *CkXmlCertVaultW_getXml(HCkXmlCertVaultW cHandle);
BOOL CkXmlCertVaultW_LoadXml(HCkXmlCertVaultW cHandle, const wchar_t *xml);
BOOL CkXmlCertVaultW_LoadXmlFile(HCkXmlCertVaultW cHandle, const wchar_t *path);
BOOL CkXmlCertVaultW_SaveLastError(HCkXmlCertVaultW cHandle, const wchar_t *path);
BOOL CkXmlCertVaultW_SaveXml(HCkXmlCertVaultW cHandle, const wchar_t *path);
#endif
