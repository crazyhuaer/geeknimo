// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCertChain_H
#define _C_CkCertChain_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCertChain CkCertChain_Create(void);
void CkCertChain_Dispose(HCkCertChain handle);
void CkCertChain_getDebugLogFilePath(HCkCertChain cHandle, HCkString retval);
void CkCertChain_putDebugLogFilePath(HCkCertChain cHandle, const char *newVal);
const char *CkCertChain_debugLogFilePath(HCkCertChain cHandle);
void CkCertChain_getLastErrorHtml(HCkCertChain cHandle, HCkString retval);
const char *CkCertChain_lastErrorHtml(HCkCertChain cHandle);
void CkCertChain_getLastErrorText(HCkCertChain cHandle, HCkString retval);
const char *CkCertChain_lastErrorText(HCkCertChain cHandle);
void CkCertChain_getLastErrorXml(HCkCertChain cHandle, HCkString retval);
const char *CkCertChain_lastErrorXml(HCkCertChain cHandle);
int CkCertChain_getNumCerts(HCkCertChain cHandle);
int CkCertChain_getNumExpiredCerts(HCkCertChain cHandle);
BOOL CkCertChain_getUtf8(HCkCertChain cHandle);
void CkCertChain_putUtf8(HCkCertChain cHandle, BOOL newVal);
BOOL CkCertChain_getVerboseLogging(HCkCertChain cHandle);
void CkCertChain_putVerboseLogging(HCkCertChain cHandle, BOOL newVal);
void CkCertChain_getVersion(HCkCertChain cHandle, HCkString retval);
const char *CkCertChain_version(HCkCertChain cHandle);
HCkCert CkCertChain_GetCert(HCkCertChain cHandle, int index);
BOOL CkCertChain_IsRootTrusted(HCkCertChain cHandle, HCkTrustedRoots trustedRoots);
BOOL CkCertChain_SaveLastError(HCkCertChain cHandle, const char *path);
BOOL CkCertChain_VerifyCertSignatures(HCkCertChain cHandle);
#endif
