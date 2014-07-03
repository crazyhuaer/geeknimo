// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkDkimWH
#define _C_CkDkimWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkDkimW CkDkimW_Create(void);
HCkDkimW CkDkimW_Create2(BOOL bCallbackOwned);
void CkDkimW_Dispose(HCkDkimW handle);
void CkDkimW_getDebugLogFilePath(HCkDkimW cHandle, HCkString retval);
void CkDkimW_putDebugLogFilePath(HCkDkimW cHandle, const wchar_t *newVal);
const wchar_t *CkDkimW_debugLogFilePath(HCkDkimW cHandle);
void CkDkimW_getDkimAlg(HCkDkimW cHandle, HCkString retval);
void CkDkimW_putDkimAlg(HCkDkimW cHandle, const wchar_t *newVal);
const wchar_t *CkDkimW_dkimAlg(HCkDkimW cHandle);
int CkDkimW_getDkimBodyLengthCount(HCkDkimW cHandle);
void CkDkimW_putDkimBodyLengthCount(HCkDkimW cHandle, int newVal);
void CkDkimW_getDkimCanon(HCkDkimW cHandle, HCkString retval);
void CkDkimW_putDkimCanon(HCkDkimW cHandle, const wchar_t *newVal);
const wchar_t *CkDkimW_dkimCanon(HCkDkimW cHandle);
void CkDkimW_getDkimDomain(HCkDkimW cHandle, HCkString retval);
void CkDkimW_putDkimDomain(HCkDkimW cHandle, const wchar_t *newVal);
const wchar_t *CkDkimW_dkimDomain(HCkDkimW cHandle);
void CkDkimW_getDkimHeaders(HCkDkimW cHandle, HCkString retval);
void CkDkimW_putDkimHeaders(HCkDkimW cHandle, const wchar_t *newVal);
const wchar_t *CkDkimW_dkimHeaders(HCkDkimW cHandle);
void CkDkimW_getDkimSelector(HCkDkimW cHandle, HCkString retval);
void CkDkimW_putDkimSelector(HCkDkimW cHandle, const wchar_t *newVal);
const wchar_t *CkDkimW_dkimSelector(HCkDkimW cHandle);
void CkDkimW_getDomainKeyAlg(HCkDkimW cHandle, HCkString retval);
void CkDkimW_putDomainKeyAlg(HCkDkimW cHandle, const wchar_t *newVal);
const wchar_t *CkDkimW_domainKeyAlg(HCkDkimW cHandle);
void CkDkimW_getDomainKeyCanon(HCkDkimW cHandle, HCkString retval);
void CkDkimW_putDomainKeyCanon(HCkDkimW cHandle, const wchar_t *newVal);
const wchar_t *CkDkimW_domainKeyCanon(HCkDkimW cHandle);
void CkDkimW_getDomainKeyDomain(HCkDkimW cHandle, HCkString retval);
void CkDkimW_putDomainKeyDomain(HCkDkimW cHandle, const wchar_t *newVal);
const wchar_t *CkDkimW_domainKeyDomain(HCkDkimW cHandle);
void CkDkimW_getDomainKeyHeaders(HCkDkimW cHandle, HCkString retval);
void CkDkimW_putDomainKeyHeaders(HCkDkimW cHandle, const wchar_t *newVal);
const wchar_t *CkDkimW_domainKeyHeaders(HCkDkimW cHandle);
void CkDkimW_getDomainKeySelector(HCkDkimW cHandle, HCkString retval);
void CkDkimW_putDomainKeySelector(HCkDkimW cHandle, const wchar_t *newVal);
const wchar_t *CkDkimW_domainKeySelector(HCkDkimW cHandle);
int CkDkimW_getHeartbeatMs(HCkDkimW cHandle);
void CkDkimW_putHeartbeatMs(HCkDkimW cHandle, int newVal);
void CkDkimW_getLastErrorHtml(HCkDkimW cHandle, HCkString retval);
const wchar_t *CkDkimW_lastErrorHtml(HCkDkimW cHandle);
void CkDkimW_getLastErrorText(HCkDkimW cHandle, HCkString retval);
const wchar_t *CkDkimW_lastErrorText(HCkDkimW cHandle);
void CkDkimW_getLastErrorXml(HCkDkimW cHandle, HCkString retval);
const wchar_t *CkDkimW_lastErrorXml(HCkDkimW cHandle);
BOOL CkDkimW_getVerboseLogging(HCkDkimW cHandle);
void CkDkimW_putVerboseLogging(HCkDkimW cHandle, BOOL newVal);
void CkDkimW_getVersion(HCkDkimW cHandle, HCkString retval);
const wchar_t *CkDkimW_version(HCkDkimW cHandle);
BOOL CkDkimW_AddDkimSignature(HCkDkimW cHandle, HCkByteData mimeIn, HCkByteData outBytes);
BOOL CkDkimW_AddDomainKeySignature(HCkDkimW cHandle, HCkByteData mimeIn, HCkByteData outBytes);
BOOL CkDkimW_LoadDkimPk(HCkDkimW cHandle, const wchar_t *privateKey, const wchar_t *optionalPassword);
BOOL CkDkimW_LoadDkimPkBytes(HCkDkimW cHandle, HCkByteData privateKeyDer, const wchar_t *optionalPassword);
BOOL CkDkimW_LoadDkimPkFile(HCkDkimW cHandle, const wchar_t *privateKeyFilePath, const wchar_t *optionalPassword);
BOOL CkDkimW_LoadDomainKeyPk(HCkDkimW cHandle, const wchar_t *privateKey, const wchar_t *optionalPassword);
BOOL CkDkimW_LoadDomainKeyPkBytes(HCkDkimW cHandle, HCkByteData privateKeyDer, const wchar_t *optionalPassword);
BOOL CkDkimW_LoadDomainKeyPkFile(HCkDkimW cHandle, const wchar_t *privateKeyFilePath, const wchar_t *optionalPassword);
BOOL CkDkimW_LoadPublicKey(HCkDkimW cHandle, const wchar_t *selector, const wchar_t *domain, const wchar_t *publicKey);
BOOL CkDkimW_LoadPublicKeyFile(HCkDkimW cHandle, const wchar_t *selector, const wchar_t *domain, const wchar_t *publicKeyFilepath);
int CkDkimW_NumDkimSignatures(HCkDkimW cHandle, HCkByteData mimeData);
int CkDkimW_NumDomainKeySignatures(HCkDkimW cHandle, HCkByteData mimeData);
BOOL CkDkimW_PrefetchPublicKey(HCkDkimW cHandle, const wchar_t *selector, const wchar_t *domain);
BOOL CkDkimW_SaveLastError(HCkDkimW cHandle, const wchar_t *path);
BOOL CkDkimW_UnlockComponent(HCkDkimW cHandle, const wchar_t *unlockCode);
BOOL CkDkimW_VerifyDkimSignature(HCkDkimW cHandle, int sigIndex, HCkByteData mimeData);
BOOL CkDkimW_VerifyDomainKeySignature(HCkDkimW cHandle, int sigIndex, HCkByteData mimeData);
#endif
