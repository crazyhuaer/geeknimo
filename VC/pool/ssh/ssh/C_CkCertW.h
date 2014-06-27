// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCertWH
#define _C_CkCertWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCertW CkCertW_Create(void);
void CkCertW_Dispose(HCkCertW handle);
void CkCertW_getAuthorityKeyId(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_authorityKeyId(HCkCertW cHandle);
BOOL CkCertW_getAvoidWindowsPkAccess(HCkCertW cHandle);
void CkCertW_putAvoidWindowsPkAccess(HCkCertW cHandle, BOOL newVal);
int CkCertW_getCertVersion(HCkCertW cHandle);
void CkCertW_getCspName(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_cspName(HCkCertW cHandle);
void CkCertW_getDebugLogFilePath(HCkCertW cHandle, HCkString retval);
void CkCertW_putDebugLogFilePath(HCkCertW cHandle, const wchar_t *newVal);
const wchar_t *CkCertW_debugLogFilePath(HCkCertW cHandle);
BOOL CkCertW_getExpired(HCkCertW cHandle);
BOOL CkCertW_getForClientAuthentication(HCkCertW cHandle);
BOOL CkCertW_getForCodeSigning(HCkCertW cHandle);
BOOL CkCertW_getForSecureEmail(HCkCertW cHandle);
BOOL CkCertW_getForServerAuthentication(HCkCertW cHandle);
BOOL CkCertW_getForTimeStamping(HCkCertW cHandle);
BOOL CkCertW_getHasKeyContainer(HCkCertW cHandle);
unsigned long CkCertW_getIntendedKeyUsage(HCkCertW cHandle);
BOOL CkCertW_getIsRoot(HCkCertW cHandle);
void CkCertW_getIssuerC(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_issuerC(HCkCertW cHandle);
void CkCertW_getIssuerCN(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_issuerCN(HCkCertW cHandle);
void CkCertW_getIssuerDN(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_issuerDN(HCkCertW cHandle);
void CkCertW_getIssuerE(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_issuerE(HCkCertW cHandle);
void CkCertW_getIssuerL(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_issuerL(HCkCertW cHandle);
void CkCertW_getIssuerO(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_issuerO(HCkCertW cHandle);
void CkCertW_getIssuerOU(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_issuerOU(HCkCertW cHandle);
void CkCertW_getIssuerS(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_issuerS(HCkCertW cHandle);
void CkCertW_getKeyContainerName(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_keyContainerName(HCkCertW cHandle);
void CkCertW_getLastErrorHtml(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_lastErrorHtml(HCkCertW cHandle);
void CkCertW_getLastErrorText(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_lastErrorText(HCkCertW cHandle);
void CkCertW_getLastErrorXml(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_lastErrorXml(HCkCertW cHandle);
BOOL CkCertW_getMachineKeyset(HCkCertW cHandle);
void CkCertW_getOcspUrl(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_ocspUrl(HCkCertW cHandle);
BOOL CkCertW_getPrivateKeyExportable(HCkCertW cHandle);
BOOL CkCertW_getRevoked(HCkCertW cHandle);
void CkCertW_getRfc822Name(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_rfc822Name(HCkCertW cHandle);
BOOL CkCertW_getSelfSigned(HCkCertW cHandle);
void CkCertW_getSerialNumber(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_serialNumber(HCkCertW cHandle);
void CkCertW_getSha1Thumbprint(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_sha1Thumbprint(HCkCertW cHandle);
BOOL CkCertW_getSignatureVerified(HCkCertW cHandle);
BOOL CkCertW_getSilent(HCkCertW cHandle);
void CkCertW_getSubjectC(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_subjectC(HCkCertW cHandle);
void CkCertW_getSubjectCN(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_subjectCN(HCkCertW cHandle);
void CkCertW_getSubjectDN(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_subjectDN(HCkCertW cHandle);
void CkCertW_getSubjectE(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_subjectE(HCkCertW cHandle);
void CkCertW_getSubjectKeyId(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_subjectKeyId(HCkCertW cHandle);
void CkCertW_getSubjectL(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_subjectL(HCkCertW cHandle);
void CkCertW_getSubjectO(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_subjectO(HCkCertW cHandle);
void CkCertW_getSubjectOU(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_subjectOU(HCkCertW cHandle);
void CkCertW_getSubjectS(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_subjectS(HCkCertW cHandle);
BOOL CkCertW_getTrustedRoot(HCkCertW cHandle);
void CkCertW_getValidFrom(HCkCertW cHandle, SYSTEMTIME *retval);
void CkCertW_getValidFromStr(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_validFromStr(HCkCertW cHandle);
void CkCertW_getValidTo(HCkCertW cHandle, SYSTEMTIME *retval);
void CkCertW_getValidToStr(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_validToStr(HCkCertW cHandle);
BOOL CkCertW_getVerboseLogging(HCkCertW cHandle);
void CkCertW_putVerboseLogging(HCkCertW cHandle, BOOL newVal);
void CkCertW_getVersion(HCkCertW cHandle, HCkString retval);
const wchar_t *CkCertW_version(HCkCertW cHandle);
int CkCertW_CheckRevoked(HCkCertW cHandle);
BOOL CkCertW_ExportCertDer(HCkCertW cHandle, HCkByteData outData);
BOOL CkCertW_ExportCertDerFile(HCkCertW cHandle, const wchar_t *path);
BOOL CkCertW_ExportCertPem(HCkCertW cHandle, HCkString outStr);
const wchar_t *CkCertW_exportCertPem(HCkCertW cHandle);
BOOL CkCertW_ExportCertPemFile(HCkCertW cHandle, const wchar_t *path);
BOOL CkCertW_ExportCertXml(HCkCertW cHandle, HCkString outStr);
const wchar_t *CkCertW_exportCertXml(HCkCertW cHandle);
HCkPrivateKeyW CkCertW_ExportPrivateKey(HCkCertW cHandle);
HCkPublicKeyW CkCertW_ExportPublicKey(HCkCertW cHandle);
BOOL CkCertW_ExportToPfxData(HCkCertW cHandle, const wchar_t *password, BOOL includeCertChain, HCkByteData outBytes);
BOOL CkCertW_ExportToPfxFile(HCkCertW cHandle, const wchar_t *pfxFilename, const wchar_t *pfxPassword, BOOL bIncludeCertChain);
HCkCertW CkCertW_FindIssuer(HCkCertW cHandle);
HCkCertChainW CkCertW_GetCertChain(HCkCertW cHandle);
BOOL CkCertW_GetEncoded(HCkCertW cHandle, HCkString outStr);
const wchar_t *CkCertW_getEncoded(HCkCertW cHandle);
BOOL CkCertW_GetPrivateKeyPem(HCkCertW cHandle, HCkString outStr);
const wchar_t *CkCertW_getPrivateKeyPem(HCkCertW cHandle);
HCkDateTimeW CkCertW_GetValidFromDt(HCkCertW cHandle);
HCkDateTimeW CkCertW_GetValidToDt(HCkCertW cHandle);
BOOL CkCertW_HasPrivateKey(HCkCertW cHandle);
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkCertW_LinkPrivateKey(HCkCertW cHandle, const wchar_t *keyContainerName, BOOL bMachineKeyset, BOOL bForSigning);
#endif
BOOL CkCertW_LoadByCommonName(HCkCertW cHandle, const wchar_t *cn);
BOOL CkCertW_LoadByEmailAddress(HCkCertW cHandle, const wchar_t *emailAddress);
BOOL CkCertW_LoadByIssuerAndSerialNumber(HCkCertW cHandle, const wchar_t *issuerCN, const wchar_t *serialNumber);
BOOL CkCertW_LoadFromBase64(HCkCertW cHandle, const wchar_t *encodedCert);
BOOL CkCertW_LoadFromBinary(HCkCertW cHandle, HCkByteData data);
#if !defined(CHILKAT_MONO)
BOOL CkCertW_LoadFromBinary2(HCkCertW cHandle, const unsigned char *pByteData, unsigned long szByteData);
#endif
BOOL CkCertW_LoadFromFile(HCkCertW cHandle, const wchar_t *path);
BOOL CkCertW_LoadPfxData(HCkCertW cHandle, HCkByteData pfxData, const wchar_t *password);
#if !defined(CHILKAT_MONO)
BOOL CkCertW_LoadPfxData2(HCkCertW cHandle, const unsigned char *pByteData, unsigned long szByteData, const wchar_t *password);
#endif
BOOL CkCertW_LoadPfxFile(HCkCertW cHandle, const wchar_t *pfxPath, const wchar_t *password);
BOOL CkCertW_PemFileToDerFile(HCkCertW cHandle, const wchar_t *fromPath, const wchar_t *toPath);
BOOL CkCertW_SaveLastError(HCkCertW cHandle, const wchar_t *path);
BOOL CkCertW_SaveToFile(HCkCertW cHandle, const wchar_t *path);
BOOL CkCertW_SetFromEncoded(HCkCertW cHandle, const wchar_t *encodedCert);
BOOL CkCertW_SetPrivateKey(HCkCertW cHandle, HCkPrivateKeyW privKey);
BOOL CkCertW_SetPrivateKeyPem(HCkCertW cHandle, const wchar_t *privKeyPem);
BOOL CkCertW_UseCertVault(HCkCertW cHandle, HCkXmlCertVaultW vault);
BOOL CkCertW_VerifySignature(HCkCertW cHandle);
#endif
