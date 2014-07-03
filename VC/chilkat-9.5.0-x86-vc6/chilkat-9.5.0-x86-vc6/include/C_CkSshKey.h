// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkSshKey_H
#define _C_CkSshKey_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkSshKey CkSshKey_Create(void);
void CkSshKey_Dispose(HCkSshKey handle);
void CkSshKey_getComment(HCkSshKey cHandle, HCkString retval);
void CkSshKey_putComment(HCkSshKey cHandle, const char *newVal);
const char *CkSshKey_comment(HCkSshKey cHandle);
void CkSshKey_getDebugLogFilePath(HCkSshKey cHandle, HCkString retval);
void CkSshKey_putDebugLogFilePath(HCkSshKey cHandle, const char *newVal);
const char *CkSshKey_debugLogFilePath(HCkSshKey cHandle);
BOOL CkSshKey_getIsDsaKey(HCkSshKey cHandle);
BOOL CkSshKey_getIsPrivateKey(HCkSshKey cHandle);
BOOL CkSshKey_getIsRsaKey(HCkSshKey cHandle);
void CkSshKey_getLastErrorHtml(HCkSshKey cHandle, HCkString retval);
const char *CkSshKey_lastErrorHtml(HCkSshKey cHandle);
void CkSshKey_getLastErrorText(HCkSshKey cHandle, HCkString retval);
const char *CkSshKey_lastErrorText(HCkSshKey cHandle);
void CkSshKey_getLastErrorXml(HCkSshKey cHandle, HCkString retval);
const char *CkSshKey_lastErrorXml(HCkSshKey cHandle);
void CkSshKey_getPassword(HCkSshKey cHandle, HCkString retval);
void CkSshKey_putPassword(HCkSshKey cHandle, const char *newVal);
const char *CkSshKey_password(HCkSshKey cHandle);
BOOL CkSshKey_getUtf8(HCkSshKey cHandle);
void CkSshKey_putUtf8(HCkSshKey cHandle, BOOL newVal);
BOOL CkSshKey_getVerboseLogging(HCkSshKey cHandle);
void CkSshKey_putVerboseLogging(HCkSshKey cHandle, BOOL newVal);
void CkSshKey_getVersion(HCkSshKey cHandle, HCkString retval);
const char *CkSshKey_version(HCkSshKey cHandle);
BOOL CkSshKey_FromOpenSshPrivateKey(HCkSshKey cHandle, const char *keyStr);
BOOL CkSshKey_FromOpenSshPublicKey(HCkSshKey cHandle, const char *keyStr);
BOOL CkSshKey_FromPuttyPrivateKey(HCkSshKey cHandle, const char *keyStr);
BOOL CkSshKey_FromRfc4716PublicKey(HCkSshKey cHandle, const char *keyStr);
BOOL CkSshKey_FromXml(HCkSshKey cHandle, const char *xmlKey);
BOOL CkSshKey_GenFingerprint(HCkSshKey cHandle, HCkString outStr);
const char *CkSshKey_genFingerprint(HCkSshKey cHandle);
BOOL CkSshKey_GenerateDsaKey(HCkSshKey cHandle, int numBits);
BOOL CkSshKey_GenerateRsaKey(HCkSshKey cHandle, int numBits, int exponent);
BOOL CkSshKey_LoadText(HCkSshKey cHandle, const char *filename, HCkString outStr);
const char *CkSshKey_loadText(HCkSshKey cHandle, const char *filename);
BOOL CkSshKey_SaveLastError(HCkSshKey cHandle, const char *path);
BOOL CkSshKey_SaveText(HCkSshKey cHandle, const char *strToSave, const char *filename);
BOOL CkSshKey_ToOpenSshPrivateKey(HCkSshKey cHandle, BOOL bEncrypt, HCkString outStr);
const char *CkSshKey_toOpenSshPrivateKey(HCkSshKey cHandle, BOOL bEncrypt);
BOOL CkSshKey_ToOpenSshPublicKey(HCkSshKey cHandle, HCkString outStr);
const char *CkSshKey_toOpenSshPublicKey(HCkSshKey cHandle);
BOOL CkSshKey_ToPuttyPrivateKey(HCkSshKey cHandle, BOOL bEncrypt, HCkString outStr);
const char *CkSshKey_toPuttyPrivateKey(HCkSshKey cHandle, BOOL bEncrypt);
BOOL CkSshKey_ToRfc4716PublicKey(HCkSshKey cHandle, HCkString outStr);
const char *CkSshKey_toRfc4716PublicKey(HCkSshKey cHandle);
BOOL CkSshKey_ToXml(HCkSshKey cHandle, HCkString outStr);
const char *CkSshKey_toXml(HCkSshKey cHandle);
#endif
