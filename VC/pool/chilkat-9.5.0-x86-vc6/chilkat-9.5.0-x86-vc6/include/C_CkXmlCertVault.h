// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkXmlCertVault_H
#define _C_CkXmlCertVault_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkXmlCertVault CkXmlCertVault_Create(void);
void CkXmlCertVault_Dispose(HCkXmlCertVault handle);
void CkXmlCertVault_getDebugLogFilePath(HCkXmlCertVault cHandle, HCkString retval);
void CkXmlCertVault_putDebugLogFilePath(HCkXmlCertVault cHandle, const char *newVal);
const char *CkXmlCertVault_debugLogFilePath(HCkXmlCertVault cHandle);
void CkXmlCertVault_getLastErrorHtml(HCkXmlCertVault cHandle, HCkString retval);
const char *CkXmlCertVault_lastErrorHtml(HCkXmlCertVault cHandle);
void CkXmlCertVault_getLastErrorText(HCkXmlCertVault cHandle, HCkString retval);
const char *CkXmlCertVault_lastErrorText(HCkXmlCertVault cHandle);
void CkXmlCertVault_getLastErrorXml(HCkXmlCertVault cHandle, HCkString retval);
const char *CkXmlCertVault_lastErrorXml(HCkXmlCertVault cHandle);
void CkXmlCertVault_getMasterPassword(HCkXmlCertVault cHandle, HCkString retval);
void CkXmlCertVault_putMasterPassword(HCkXmlCertVault cHandle, const char *newVal);
const char *CkXmlCertVault_masterPassword(HCkXmlCertVault cHandle);
BOOL CkXmlCertVault_getUtf8(HCkXmlCertVault cHandle);
void CkXmlCertVault_putUtf8(HCkXmlCertVault cHandle, BOOL newVal);
BOOL CkXmlCertVault_getVerboseLogging(HCkXmlCertVault cHandle);
void CkXmlCertVault_putVerboseLogging(HCkXmlCertVault cHandle, BOOL newVal);
void CkXmlCertVault_getVersion(HCkXmlCertVault cHandle, HCkString retval);
const char *CkXmlCertVault_version(HCkXmlCertVault cHandle);
BOOL CkXmlCertVault_AddCert(HCkXmlCertVault cHandle, HCkCert cert);
BOOL CkXmlCertVault_AddCertBinary(HCkXmlCertVault cHandle, HCkByteData certBytes);
BOOL CkXmlCertVault_AddCertChain(HCkXmlCertVault cHandle, HCkCertChain certChain);
BOOL CkXmlCertVault_AddCertEncoded(HCkXmlCertVault cHandle, const char *encodedBytes, const char *encoding);
BOOL CkXmlCertVault_AddCertFile(HCkXmlCertVault cHandle, const char *path);
BOOL CkXmlCertVault_AddCertString(HCkXmlCertVault cHandle, const char *certData);
BOOL CkXmlCertVault_AddPemFile(HCkXmlCertVault cHandle, const char *path, const char *password);
BOOL CkXmlCertVault_AddPfx(HCkXmlCertVault cHandle, HCkPfx pfx);
BOOL CkXmlCertVault_AddPfxBinary(HCkXmlCertVault cHandle, HCkByteData pfxBytes, const char *password);
BOOL CkXmlCertVault_AddPfxEncoded(HCkXmlCertVault cHandle, const char *encodedBytes, const char *encoding, const char *password);
BOOL CkXmlCertVault_AddPfxFile(HCkXmlCertVault cHandle, const char *path, const char *password);
BOOL CkXmlCertVault_GetXml(HCkXmlCertVault cHandle, HCkString outStr);
const char *CkXmlCertVault_getXml(HCkXmlCertVault cHandle);
BOOL CkXmlCertVault_LoadXml(HCkXmlCertVault cHandle, const char *xml);
BOOL CkXmlCertVault_LoadXmlFile(HCkXmlCertVault cHandle, const char *path);
BOOL CkXmlCertVault_SaveLastError(HCkXmlCertVault cHandle, const char *path);
BOOL CkXmlCertVault_SaveXml(HCkXmlCertVault cHandle, const char *path);
#endif
