// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCert_H
#define _C_CkCert_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCert CkCert_Create(void);
void CkCert_Dispose(HCkCert handle);
void CkCert_getAuthorityKeyId(HCkCert cHandle, HCkString retval);
const char *CkCert_authorityKeyId(HCkCert cHandle);
BOOL CkCert_getAvoidWindowsPkAccess(HCkCert cHandle);
void CkCert_putAvoidWindowsPkAccess(HCkCert cHandle, BOOL newVal);
int CkCert_getCertVersion(HCkCert cHandle);
void CkCert_getCspName(HCkCert cHandle, HCkString retval);
const char *CkCert_cspName(HCkCert cHandle);
void CkCert_getDebugLogFilePath(HCkCert cHandle, HCkString retval);
void CkCert_putDebugLogFilePath(HCkCert cHandle, const char *newVal);
const char *CkCert_debugLogFilePath(HCkCert cHandle);
BOOL CkCert_getExpired(HCkCert cHandle);
BOOL CkCert_getForClientAuthentication(HCkCert cHandle);
BOOL CkCert_getForCodeSigning(HCkCert cHandle);
BOOL CkCert_getForSecureEmail(HCkCert cHandle);
BOOL CkCert_getForServerAuthentication(HCkCert cHandle);
BOOL CkCert_getForTimeStamping(HCkCert cHandle);
BOOL CkCert_getHasKeyContainer(HCkCert cHandle);
unsigned long CkCert_getIntendedKeyUsage(HCkCert cHandle);
BOOL CkCert_getIsRoot(HCkCert cHandle);
void CkCert_getIssuerC(HCkCert cHandle, HCkString retval);
const char *CkCert_issuerC(HCkCert cHandle);
void CkCert_getIssuerCN(HCkCert cHandle, HCkString retval);
const char *CkCert_issuerCN(HCkCert cHandle);
void CkCert_getIssuerDN(HCkCert cHandle, HCkString retval);
const char *CkCert_issuerDN(HCkCert cHandle);
void CkCert_getIssuerE(HCkCert cHandle, HCkString retval);
const char *CkCert_issuerE(HCkCert cHandle);
void CkCert_getIssuerL(HCkCert cHandle, HCkString retval);
const char *CkCert_issuerL(HCkCert cHandle);
void CkCert_getIssuerO(HCkCert cHandle, HCkString retval);
const char *CkCert_issuerO(HCkCert cHandle);
void CkCert_getIssuerOU(HCkCert cHandle, HCkString retval);
const char *CkCert_issuerOU(HCkCert cHandle);
void CkCert_getIssuerS(HCkCert cHandle, HCkString retval);
const char *CkCert_issuerS(HCkCert cHandle);
void CkCert_getKeyContainerName(HCkCert cHandle, HCkString retval);
const char *CkCert_keyContainerName(HCkCert cHandle);
void CkCert_getLastErrorHtml(HCkCert cHandle, HCkString retval);
const char *CkCert_lastErrorHtml(HCkCert cHandle);
void CkCert_getLastErrorText(HCkCert cHandle, HCkString retval);
const char *CkCert_lastErrorText(HCkCert cHandle);
void CkCert_getLastErrorXml(HCkCert cHandle, HCkString retval);
const char *CkCert_lastErrorXml(HCkCert cHandle);
BOOL CkCert_getMachineKeyset(HCkCert cHandle);
void CkCert_getOcspUrl(HCkCert cHandle, HCkString retval);
const char *CkCert_ocspUrl(HCkCert cHandle);
BOOL CkCert_getPrivateKeyExportable(HCkCert cHandle);
BOOL CkCert_getRevoked(HCkCert cHandle);
void CkCert_getRfc822Name(HCkCert cHandle, HCkString retval);
const char *CkCert_rfc822Name(HCkCert cHandle);
BOOL CkCert_getSelfSigned(HCkCert cHandle);
void CkCert_getSerialNumber(HCkCert cHandle, HCkString retval);
const char *CkCert_serialNumber(HCkCert cHandle);
void CkCert_getSha1Thumbprint(HCkCert cHandle, HCkString retval);
const char *CkCert_sha1Thumbprint(HCkCert cHandle);
BOOL CkCert_getSignatureVerified(HCkCert cHandle);
BOOL CkCert_getSilent(HCkCert cHandle);
void CkCert_getSubjectC(HCkCert cHandle, HCkString retval);
const char *CkCert_subjectC(HCkCert cHandle);
void CkCert_getSubjectCN(HCkCert cHandle, HCkString retval);
const char *CkCert_subjectCN(HCkCert cHandle);
void CkCert_getSubjectDN(HCkCert cHandle, HCkString retval);
const char *CkCert_subjectDN(HCkCert cHandle);
void CkCert_getSubjectE(HCkCert cHandle, HCkString retval);
const char *CkCert_subjectE(HCkCert cHandle);
void CkCert_getSubjectKeyId(HCkCert cHandle, HCkString retval);
const char *CkCert_subjectKeyId(HCkCert cHandle);
void CkCert_getSubjectL(HCkCert cHandle, HCkString retval);
const char *CkCert_subjectL(HCkCert cHandle);
void CkCert_getSubjectO(HCkCert cHandle, HCkString retval);
const char *CkCert_subjectO(HCkCert cHandle);
void CkCert_getSubjectOU(HCkCert cHandle, HCkString retval);
const char *CkCert_subjectOU(HCkCert cHandle);
void CkCert_getSubjectS(HCkCert cHandle, HCkString retval);
const char *CkCert_subjectS(HCkCert cHandle);
BOOL CkCert_getTrustedRoot(HCkCert cHandle);
BOOL CkCert_getUtf8(HCkCert cHandle);
void CkCert_putUtf8(HCkCert cHandle, BOOL newVal);
void CkCert_getValidFrom(HCkCert cHandle, SYSTEMTIME *retval);
void CkCert_getValidFromStr(HCkCert cHandle, HCkString retval);
const char *CkCert_validFromStr(HCkCert cHandle);
void CkCert_getValidTo(HCkCert cHandle, SYSTEMTIME *retval);
void CkCert_getValidToStr(HCkCert cHandle, HCkString retval);
const char *CkCert_validToStr(HCkCert cHandle);
BOOL CkCert_getVerboseLogging(HCkCert cHandle);
void CkCert_putVerboseLogging(HCkCert cHandle, BOOL newVal);
void CkCert_getVersion(HCkCert cHandle, HCkString retval);
const char *CkCert_version(HCkCert cHandle);
int CkCert_CheckRevoked(HCkCert cHandle);
BOOL CkCert_ExportCertDer(HCkCert cHandle, HCkByteData outData);
BOOL CkCert_ExportCertDerFile(HCkCert cHandle, const char *path);
BOOL CkCert_ExportCertPem(HCkCert cHandle, HCkString outStr);
const char *CkCert_exportCertPem(HCkCert cHandle);
BOOL CkCert_ExportCertPemFile(HCkCert cHandle, const char *path);
BOOL CkCert_ExportCertXml(HCkCert cHandle, HCkString outStr);
const char *CkCert_exportCertXml(HCkCert cHandle);
HCkPrivateKey CkCert_ExportPrivateKey(HCkCert cHandle);
HCkPublicKey CkCert_ExportPublicKey(HCkCert cHandle);
BOOL CkCert_ExportToPfxData(HCkCert cHandle, const char *password, BOOL includeCertChain, HCkByteData outBytes);
BOOL CkCert_ExportToPfxFile(HCkCert cHandle, const char *pfxFilename, const char *pfxPassword, BOOL bIncludeCertChain);
HCkCert CkCert_FindIssuer(HCkCert cHandle);
HCkCertChain CkCert_GetCertChain(HCkCert cHandle);
BOOL CkCert_GetEncoded(HCkCert cHandle, HCkString outStr);
const char *CkCert_getEncoded(HCkCert cHandle);
BOOL CkCert_GetPrivateKeyPem(HCkCert cHandle, HCkString outStr);
const char *CkCert_getPrivateKeyPem(HCkCert cHandle);
HCkDateTime CkCert_GetValidFromDt(HCkCert cHandle);
HCkDateTime CkCert_GetValidToDt(HCkCert cHandle);
BOOL CkCert_HasPrivateKey(HCkCert cHandle);
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkCert_LinkPrivateKey(HCkCert cHandle, const char *keyContainerName, BOOL bMachineKeyset, BOOL bForSigning);
#endif
BOOL CkCert_LoadByCommonName(HCkCert cHandle, const char *cn);
BOOL CkCert_LoadByEmailAddress(HCkCert cHandle, const char *emailAddress);
BOOL CkCert_LoadByIssuerAndSerialNumber(HCkCert cHandle, const char *issuerCN, const char *serialNumber);
BOOL CkCert_LoadFromBase64(HCkCert cHandle, const char *encodedCert);
BOOL CkCert_LoadFromBinary(HCkCert cHandle, HCkByteData data);
#if !defined(CHILKAT_MONO)
BOOL CkCert_LoadFromBinary2(HCkCert cHandle, const unsigned char *pByteData, unsigned long szByteData);
#endif
BOOL CkCert_LoadFromFile(HCkCert cHandle, const char *path);
BOOL CkCert_LoadPfxData(HCkCert cHandle, HCkByteData pfxData, const char *password);
#if !defined(CHILKAT_MONO)
BOOL CkCert_LoadPfxData2(HCkCert cHandle, const unsigned char *pByteData, unsigned long szByteData, const char *password);
#endif
BOOL CkCert_LoadPfxFile(HCkCert cHandle, const char *pfxPath, const char *password);
BOOL CkCert_PemFileToDerFile(HCkCert cHandle, const char *fromPath, const char *toPath);
BOOL CkCert_SaveLastError(HCkCert cHandle, const char *path);
BOOL CkCert_SaveToFile(HCkCert cHandle, const char *path);
BOOL CkCert_SetFromEncoded(HCkCert cHandle, const char *encodedCert);
BOOL CkCert_SetPrivateKey(HCkCert cHandle, HCkPrivateKey privKey);
BOOL CkCert_SetPrivateKeyPem(HCkCert cHandle, const char *privKeyPem);
BOOL CkCert_UseCertVault(HCkCert cHandle, HCkXmlCertVault vault);
BOOL CkCert_VerifySignature(HCkCert cHandle);
#endif
