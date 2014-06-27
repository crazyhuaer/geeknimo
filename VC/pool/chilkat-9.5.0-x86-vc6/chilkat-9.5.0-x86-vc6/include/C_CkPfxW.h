// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkPfxWH
#define _C_CkPfxWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkPfxW CkPfxW_Create(void);
void CkPfxW_Dispose(HCkPfxW handle);
void CkPfxW_getDebugLogFilePath(HCkPfxW cHandle, HCkString retval);
void CkPfxW_putDebugLogFilePath(HCkPfxW cHandle, const wchar_t *newVal);
const wchar_t *CkPfxW_debugLogFilePath(HCkPfxW cHandle);
void CkPfxW_getLastErrorHtml(HCkPfxW cHandle, HCkString retval);
const wchar_t *CkPfxW_lastErrorHtml(HCkPfxW cHandle);
void CkPfxW_getLastErrorText(HCkPfxW cHandle, HCkString retval);
const wchar_t *CkPfxW_lastErrorText(HCkPfxW cHandle);
void CkPfxW_getLastErrorXml(HCkPfxW cHandle, HCkString retval);
const wchar_t *CkPfxW_lastErrorXml(HCkPfxW cHandle);
int CkPfxW_getNumCerts(HCkPfxW cHandle);
int CkPfxW_getNumPrivateKeys(HCkPfxW cHandle);
BOOL CkPfxW_getVerboseLogging(HCkPfxW cHandle);
void CkPfxW_putVerboseLogging(HCkPfxW cHandle, BOOL newVal);
void CkPfxW_getVersion(HCkPfxW cHandle, HCkString retval);
const wchar_t *CkPfxW_version(HCkPfxW cHandle);
HCkCertW CkPfxW_GetCert(HCkPfxW cHandle, int index);
HCkPrivateKeyW CkPfxW_GetPrivateKey(HCkPfxW cHandle, int index);
BOOL CkPfxW_LoadPfxBytes(HCkPfxW cHandle, HCkByteData pfxData, const wchar_t *password);
BOOL CkPfxW_LoadPfxEncoded(HCkPfxW cHandle, const wchar_t *encodedData, const wchar_t *encoding, const wchar_t *password);
BOOL CkPfxW_LoadPfxFile(HCkPfxW cHandle, const wchar_t *path, const wchar_t *password);
BOOL CkPfxW_SaveLastError(HCkPfxW cHandle, const wchar_t *path);
#endif
