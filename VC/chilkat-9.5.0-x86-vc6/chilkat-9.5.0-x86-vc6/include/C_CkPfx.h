// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkPfx_H
#define _C_CkPfx_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkPfx CkPfx_Create(void);
void CkPfx_Dispose(HCkPfx handle);
void CkPfx_getDebugLogFilePath(HCkPfx cHandle, HCkString retval);
void CkPfx_putDebugLogFilePath(HCkPfx cHandle, const char *newVal);
const char *CkPfx_debugLogFilePath(HCkPfx cHandle);
void CkPfx_getLastErrorHtml(HCkPfx cHandle, HCkString retval);
const char *CkPfx_lastErrorHtml(HCkPfx cHandle);
void CkPfx_getLastErrorText(HCkPfx cHandle, HCkString retval);
const char *CkPfx_lastErrorText(HCkPfx cHandle);
void CkPfx_getLastErrorXml(HCkPfx cHandle, HCkString retval);
const char *CkPfx_lastErrorXml(HCkPfx cHandle);
int CkPfx_getNumCerts(HCkPfx cHandle);
int CkPfx_getNumPrivateKeys(HCkPfx cHandle);
BOOL CkPfx_getUtf8(HCkPfx cHandle);
void CkPfx_putUtf8(HCkPfx cHandle, BOOL newVal);
BOOL CkPfx_getVerboseLogging(HCkPfx cHandle);
void CkPfx_putVerboseLogging(HCkPfx cHandle, BOOL newVal);
void CkPfx_getVersion(HCkPfx cHandle, HCkString retval);
const char *CkPfx_version(HCkPfx cHandle);
HCkCert CkPfx_GetCert(HCkPfx cHandle, int index);
HCkPrivateKey CkPfx_GetPrivateKey(HCkPfx cHandle, int index);
BOOL CkPfx_LoadPfxBytes(HCkPfx cHandle, HCkByteData pfxData, const char *password);
BOOL CkPfx_LoadPfxEncoded(HCkPfx cHandle, const char *encodedData, const char *encoding, const char *password);
BOOL CkPfx_LoadPfxFile(HCkPfx cHandle, const char *path, const char *password);
BOOL CkPfx_SaveLastError(HCkPfx cHandle, const char *path);
#endif
