// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkDsa_H
#define _C_CkDsa_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkDsa CkDsa_Create(void);
void CkDsa_Dispose(HCkDsa handle);
void CkDsa_getDebugLogFilePath(HCkDsa cHandle, HCkString retval);
void CkDsa_putDebugLogFilePath(HCkDsa cHandle, const char *newVal);
const char *CkDsa_debugLogFilePath(HCkDsa cHandle);
int CkDsa_getGroupSize(HCkDsa cHandle);
void CkDsa_putGroupSize(HCkDsa cHandle, int newVal);
void CkDsa_getHash(HCkDsa cHandle, HCkByteData retval);
void CkDsa_putHash(HCkDsa cHandle, HCkByteData  newVal);
void CkDsa_getHexG(HCkDsa cHandle, HCkString retval);
const char *CkDsa_hexG(HCkDsa cHandle);
void CkDsa_getHexP(HCkDsa cHandle, HCkString retval);
const char *CkDsa_hexP(HCkDsa cHandle);
void CkDsa_getHexQ(HCkDsa cHandle, HCkString retval);
const char *CkDsa_hexQ(HCkDsa cHandle);
void CkDsa_getHexX(HCkDsa cHandle, HCkString retval);
const char *CkDsa_hexX(HCkDsa cHandle);
void CkDsa_getHexY(HCkDsa cHandle, HCkString retval);
const char *CkDsa_hexY(HCkDsa cHandle);
void CkDsa_getLastErrorHtml(HCkDsa cHandle, HCkString retval);
const char *CkDsa_lastErrorHtml(HCkDsa cHandle);
void CkDsa_getLastErrorText(HCkDsa cHandle, HCkString retval);
const char *CkDsa_lastErrorText(HCkDsa cHandle);
void CkDsa_getLastErrorXml(HCkDsa cHandle, HCkString retval);
const char *CkDsa_lastErrorXml(HCkDsa cHandle);
void CkDsa_getSignature(HCkDsa cHandle, HCkByteData retval);
void CkDsa_putSignature(HCkDsa cHandle, HCkByteData  newVal);
BOOL CkDsa_getUtf8(HCkDsa cHandle);
void CkDsa_putUtf8(HCkDsa cHandle, BOOL newVal);
BOOL CkDsa_getVerboseLogging(HCkDsa cHandle);
void CkDsa_putVerboseLogging(HCkDsa cHandle, BOOL newVal);
void CkDsa_getVersion(HCkDsa cHandle, HCkString retval);
const char *CkDsa_version(HCkDsa cHandle);
BOOL CkDsa_FromDer(HCkDsa cHandle, HCkByteData derData);
BOOL CkDsa_FromDerFile(HCkDsa cHandle, const char *path);
BOOL CkDsa_FromEncryptedPem(HCkDsa cHandle, const char *password, const char *pemData);
BOOL CkDsa_FromPem(HCkDsa cHandle, const char *pemData);
BOOL CkDsa_FromPublicDer(HCkDsa cHandle, HCkByteData derData);
BOOL CkDsa_FromPublicDerFile(HCkDsa cHandle, const char *path);
BOOL CkDsa_FromPublicPem(HCkDsa cHandle, const char *pemData);
BOOL CkDsa_FromXml(HCkDsa cHandle, const char *xmlKey);
BOOL CkDsa_GenKey(HCkDsa cHandle, int numBits);
BOOL CkDsa_GenKeyFromParamsDer(HCkDsa cHandle, HCkByteData derBytes);
BOOL CkDsa_GenKeyFromParamsDerFile(HCkDsa cHandle, const char *path);
BOOL CkDsa_GenKeyFromParamsPem(HCkDsa cHandle, const char *pem);
BOOL CkDsa_GenKeyFromParamsPemFile(HCkDsa cHandle, const char *path);
BOOL CkDsa_GetEncodedHash(HCkDsa cHandle, const char *encoding, HCkString outStr);
const char *CkDsa_getEncodedHash(HCkDsa cHandle, const char *encoding);
BOOL CkDsa_GetEncodedSignature(HCkDsa cHandle, const char *encoding, HCkString outStr);
const char *CkDsa_getEncodedSignature(HCkDsa cHandle, const char *encoding);
BOOL CkDsa_LoadText(HCkDsa cHandle, const char *path, HCkString outStr);
const char *CkDsa_loadText(HCkDsa cHandle, const char *path);
BOOL CkDsa_SaveLastError(HCkDsa cHandle, const char *path);
BOOL CkDsa_SaveText(HCkDsa cHandle, const char *strToSave, const char *path);
BOOL CkDsa_SetEncodedHash(HCkDsa cHandle, const char *encoding, const char *encodedHash);
BOOL CkDsa_SetEncodedSignature(HCkDsa cHandle, const char *encoding, const char *encodedSig);
BOOL CkDsa_SetEncodedSignatureRS(HCkDsa cHandle, const char *encoding, const char *encodedR, const char *encodedS);
BOOL CkDsa_SetKeyExplicit(HCkDsa cHandle, int groupSizeInBytes, const char *pHex, const char *qHex, const char *gHex, const char *xHex);
BOOL CkDsa_SetPubKeyExplicit(HCkDsa cHandle, int groupSizeInBytes, const char *pHex, const char *qHex, const char *gHex, const char *yHex);
BOOL CkDsa_SignHash(HCkDsa cHandle);
BOOL CkDsa_ToDer(HCkDsa cHandle, HCkByteData outBytes);
BOOL CkDsa_ToDerFile(HCkDsa cHandle, const char *path);
BOOL CkDsa_ToEncryptedPem(HCkDsa cHandle, const char *password, HCkString outStr);
const char *CkDsa_toEncryptedPem(HCkDsa cHandle, const char *password);
BOOL CkDsa_ToPem(HCkDsa cHandle, HCkString outStr);
const char *CkDsa_toPem(HCkDsa cHandle);
BOOL CkDsa_ToPublicDer(HCkDsa cHandle, HCkByteData outBytes);
BOOL CkDsa_ToPublicDerFile(HCkDsa cHandle, const char *path);
BOOL CkDsa_ToPublicPem(HCkDsa cHandle, HCkString outStr);
const char *CkDsa_toPublicPem(HCkDsa cHandle);
BOOL CkDsa_ToXml(HCkDsa cHandle, BOOL bPublicOnly, HCkString outStr);
const char *CkDsa_toXml(HCkDsa cHandle, BOOL bPublicOnly);
BOOL CkDsa_UnlockComponent(HCkDsa cHandle, const char *unlockCode);
BOOL CkDsa_Verify(HCkDsa cHandle);
BOOL CkDsa_VerifyKey(HCkDsa cHandle);
#endif
