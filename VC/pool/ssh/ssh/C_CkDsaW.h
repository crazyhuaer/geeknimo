// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkDsaWH
#define _C_CkDsaWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkDsaW CkDsaW_Create(void);
void CkDsaW_Dispose(HCkDsaW handle);
void CkDsaW_getDebugLogFilePath(HCkDsaW cHandle, HCkString retval);
void CkDsaW_putDebugLogFilePath(HCkDsaW cHandle, const wchar_t *newVal);
const wchar_t *CkDsaW_debugLogFilePath(HCkDsaW cHandle);
int CkDsaW_getGroupSize(HCkDsaW cHandle);
void CkDsaW_putGroupSize(HCkDsaW cHandle, int newVal);
void CkDsaW_getHash(HCkDsaW cHandle, HCkByteData retval);
void CkDsaW_putHash(HCkDsaW cHandle, HCkByteData  newVal);
void CkDsaW_getHexG(HCkDsaW cHandle, HCkString retval);
const wchar_t *CkDsaW_hexG(HCkDsaW cHandle);
void CkDsaW_getHexP(HCkDsaW cHandle, HCkString retval);
const wchar_t *CkDsaW_hexP(HCkDsaW cHandle);
void CkDsaW_getHexQ(HCkDsaW cHandle, HCkString retval);
const wchar_t *CkDsaW_hexQ(HCkDsaW cHandle);
void CkDsaW_getHexX(HCkDsaW cHandle, HCkString retval);
const wchar_t *CkDsaW_hexX(HCkDsaW cHandle);
void CkDsaW_getHexY(HCkDsaW cHandle, HCkString retval);
const wchar_t *CkDsaW_hexY(HCkDsaW cHandle);
void CkDsaW_getLastErrorHtml(HCkDsaW cHandle, HCkString retval);
const wchar_t *CkDsaW_lastErrorHtml(HCkDsaW cHandle);
void CkDsaW_getLastErrorText(HCkDsaW cHandle, HCkString retval);
const wchar_t *CkDsaW_lastErrorText(HCkDsaW cHandle);
void CkDsaW_getLastErrorXml(HCkDsaW cHandle, HCkString retval);
const wchar_t *CkDsaW_lastErrorXml(HCkDsaW cHandle);
void CkDsaW_getSignature(HCkDsaW cHandle, HCkByteData retval);
void CkDsaW_putSignature(HCkDsaW cHandle, HCkByteData  newVal);
BOOL CkDsaW_getVerboseLogging(HCkDsaW cHandle);
void CkDsaW_putVerboseLogging(HCkDsaW cHandle, BOOL newVal);
void CkDsaW_getVersion(HCkDsaW cHandle, HCkString retval);
const wchar_t *CkDsaW_version(HCkDsaW cHandle);
BOOL CkDsaW_FromDer(HCkDsaW cHandle, HCkByteData derData);
BOOL CkDsaW_FromDerFile(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_FromEncryptedPem(HCkDsaW cHandle, const wchar_t *password, const wchar_t *pemData);
BOOL CkDsaW_FromPem(HCkDsaW cHandle, const wchar_t *pemData);
BOOL CkDsaW_FromPublicDer(HCkDsaW cHandle, HCkByteData derData);
BOOL CkDsaW_FromPublicDerFile(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_FromPublicPem(HCkDsaW cHandle, const wchar_t *pemData);
BOOL CkDsaW_FromXml(HCkDsaW cHandle, const wchar_t *xmlKey);
BOOL CkDsaW_GenKey(HCkDsaW cHandle, int numBits);
BOOL CkDsaW_GenKeyFromParamsDer(HCkDsaW cHandle, HCkByteData derBytes);
BOOL CkDsaW_GenKeyFromParamsDerFile(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_GenKeyFromParamsPem(HCkDsaW cHandle, const wchar_t *pem);
BOOL CkDsaW_GenKeyFromParamsPemFile(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_GetEncodedHash(HCkDsaW cHandle, const wchar_t *encoding, HCkString outStr);
const wchar_t *CkDsaW_getEncodedHash(HCkDsaW cHandle, const wchar_t *encoding);
BOOL CkDsaW_GetEncodedSignature(HCkDsaW cHandle, const wchar_t *encoding, HCkString outStr);
const wchar_t *CkDsaW_getEncodedSignature(HCkDsaW cHandle, const wchar_t *encoding);
BOOL CkDsaW_LoadText(HCkDsaW cHandle, const wchar_t *path, HCkString outStr);
const wchar_t *CkDsaW_loadText(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_SaveLastError(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_SaveText(HCkDsaW cHandle, const wchar_t *strToSave, const wchar_t *path);
BOOL CkDsaW_SetEncodedHash(HCkDsaW cHandle, const wchar_t *encoding, const wchar_t *encodedHash);
BOOL CkDsaW_SetEncodedSignature(HCkDsaW cHandle, const wchar_t *encoding, const wchar_t *encodedSig);
BOOL CkDsaW_SetEncodedSignatureRS(HCkDsaW cHandle, const wchar_t *encoding, const wchar_t *encodedR, const wchar_t *encodedS);
BOOL CkDsaW_SetKeyExplicit(HCkDsaW cHandle, int groupSizeInBytes, const wchar_t *pHex, const wchar_t *qHex, const wchar_t *gHex, const wchar_t *xHex);
BOOL CkDsaW_SetPubKeyExplicit(HCkDsaW cHandle, int groupSizeInBytes, const wchar_t *pHex, const wchar_t *qHex, const wchar_t *gHex, const wchar_t *yHex);
BOOL CkDsaW_SignHash(HCkDsaW cHandle);
BOOL CkDsaW_ToDer(HCkDsaW cHandle, HCkByteData outBytes);
BOOL CkDsaW_ToDerFile(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_ToEncryptedPem(HCkDsaW cHandle, const wchar_t *password, HCkString outStr);
const wchar_t *CkDsaW_toEncryptedPem(HCkDsaW cHandle, const wchar_t *password);
BOOL CkDsaW_ToPem(HCkDsaW cHandle, HCkString outStr);
const wchar_t *CkDsaW_toPem(HCkDsaW cHandle);
BOOL CkDsaW_ToPublicDer(HCkDsaW cHandle, HCkByteData outBytes);
BOOL CkDsaW_ToPublicDerFile(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_ToPublicPem(HCkDsaW cHandle, HCkString outStr);
const wchar_t *CkDsaW_toPublicPem(HCkDsaW cHandle);
BOOL CkDsaW_ToXml(HCkDsaW cHandle, BOOL bPublicOnly, HCkString outStr);
const wchar_t *CkDsaW_toXml(HCkDsaW cHandle, BOOL bPublicOnly);
BOOL CkDsaW_UnlockComponent(HCkDsaW cHandle, const wchar_t *unlockCode);
BOOL CkDsaW_Verify(HCkDsaW cHandle);
BOOL CkDsaW_VerifyKey(HCkDsaW cHandle);
#endif
