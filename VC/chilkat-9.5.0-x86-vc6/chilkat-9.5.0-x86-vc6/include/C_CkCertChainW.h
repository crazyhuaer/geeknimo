// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCertChainWH
#define _C_CkCertChainWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCertChainW CkCertChainW_Create(void);
void CkCertChainW_Dispose(HCkCertChainW handle);
void CkCertChainW_getDebugLogFilePath(HCkCertChainW cHandle, HCkString retval);
void CkCertChainW_putDebugLogFilePath(HCkCertChainW cHandle, const wchar_t *newVal);
const wchar_t *CkCertChainW_debugLogFilePath(HCkCertChainW cHandle);
void CkCertChainW_getLastErrorHtml(HCkCertChainW cHandle, HCkString retval);
const wchar_t *CkCertChainW_lastErrorHtml(HCkCertChainW cHandle);
void CkCertChainW_getLastErrorText(HCkCertChainW cHandle, HCkString retval);
const wchar_t *CkCertChainW_lastErrorText(HCkCertChainW cHandle);
void CkCertChainW_getLastErrorXml(HCkCertChainW cHandle, HCkString retval);
const wchar_t *CkCertChainW_lastErrorXml(HCkCertChainW cHandle);
int CkCertChainW_getNumCerts(HCkCertChainW cHandle);
int CkCertChainW_getNumExpiredCerts(HCkCertChainW cHandle);
BOOL CkCertChainW_getVerboseLogging(HCkCertChainW cHandle);
void CkCertChainW_putVerboseLogging(HCkCertChainW cHandle, BOOL newVal);
void CkCertChainW_getVersion(HCkCertChainW cHandle, HCkString retval);
const wchar_t *CkCertChainW_version(HCkCertChainW cHandle);
HCkCertW CkCertChainW_GetCert(HCkCertChainW cHandle, int index);
BOOL CkCertChainW_IsRootTrusted(HCkCertChainW cHandle, HCkTrustedRootsW trustedRoots);
BOOL CkCertChainW_SaveLastError(HCkCertChainW cHandle, const wchar_t *path);
BOOL CkCertChainW_VerifyCertSignatures(HCkCertChainW cHandle);
#endif
