// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkSshKeyWH
#define _C_CkSshKeyWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkSshKeyW CkSshKeyW_Create(void);
void CkSshKeyW_Dispose(HCkSshKeyW handle);
void CkSshKeyW_getComment(HCkSshKeyW cHandle, HCkString retval);
void CkSshKeyW_putComment(HCkSshKeyW cHandle, const wchar_t *newVal);
const wchar_t *CkSshKeyW_comment(HCkSshKeyW cHandle);
void CkSshKeyW_getDebugLogFilePath(HCkSshKeyW cHandle, HCkString retval);
void CkSshKeyW_putDebugLogFilePath(HCkSshKeyW cHandle, const wchar_t *newVal);
const wchar_t *CkSshKeyW_debugLogFilePath(HCkSshKeyW cHandle);
BOOL CkSshKeyW_getIsDsaKey(HCkSshKeyW cHandle);
BOOL CkSshKeyW_getIsPrivateKey(HCkSshKeyW cHandle);
BOOL CkSshKeyW_getIsRsaKey(HCkSshKeyW cHandle);
void CkSshKeyW_getLastErrorHtml(HCkSshKeyW cHandle, HCkString retval);
const wchar_t *CkSshKeyW_lastErrorHtml(HCkSshKeyW cHandle);
void CkSshKeyW_getLastErrorText(HCkSshKeyW cHandle, HCkString retval);
const wchar_t *CkSshKeyW_lastErrorText(HCkSshKeyW cHandle);
void CkSshKeyW_getLastErrorXml(HCkSshKeyW cHandle, HCkString retval);
const wchar_t *CkSshKeyW_lastErrorXml(HCkSshKeyW cHandle);
void CkSshKeyW_getPassword(HCkSshKeyW cHandle, HCkString retval);
void CkSshKeyW_putPassword(HCkSshKeyW cHandle, const wchar_t *newVal);
const wchar_t *CkSshKeyW_password(HCkSshKeyW cHandle);
BOOL CkSshKeyW_getVerboseLogging(HCkSshKeyW cHandle);
void CkSshKeyW_putVerboseLogging(HCkSshKeyW cHandle, BOOL newVal);
void CkSshKeyW_getVersion(HCkSshKeyW cHandle, HCkString retval);
const wchar_t *CkSshKeyW_version(HCkSshKeyW cHandle);
BOOL CkSshKeyW_FromOpenSshPrivateKey(HCkSshKeyW cHandle, const wchar_t *keyStr);
BOOL CkSshKeyW_FromOpenSshPublicKey(HCkSshKeyW cHandle, const wchar_t *keyStr);
BOOL CkSshKeyW_FromPuttyPrivateKey(HCkSshKeyW cHandle, const wchar_t *keyStr);
BOOL CkSshKeyW_FromRfc4716PublicKey(HCkSshKeyW cHandle, const wchar_t *keyStr);
BOOL CkSshKeyW_FromXml(HCkSshKeyW cHandle, const wchar_t *xmlKey);
BOOL CkSshKeyW_GenFingerprint(HCkSshKeyW cHandle, HCkString outStr);
const wchar_t *CkSshKeyW_genFingerprint(HCkSshKeyW cHandle);
BOOL CkSshKeyW_GenerateDsaKey(HCkSshKeyW cHandle, int numBits);
BOOL CkSshKeyW_GenerateRsaKey(HCkSshKeyW cHandle, int numBits, int exponent);
BOOL CkSshKeyW_LoadText(HCkSshKeyW cHandle, const wchar_t *filename, HCkString outStr);
const wchar_t *CkSshKeyW_loadText(HCkSshKeyW cHandle, const wchar_t *filename);
BOOL CkSshKeyW_SaveLastError(HCkSshKeyW cHandle, const wchar_t *path);
BOOL CkSshKeyW_SaveText(HCkSshKeyW cHandle, const wchar_t *strToSave, const wchar_t *filename);
BOOL CkSshKeyW_ToOpenSshPrivateKey(HCkSshKeyW cHandle, BOOL bEncrypt, HCkString outStr);
const wchar_t *CkSshKeyW_toOpenSshPrivateKey(HCkSshKeyW cHandle, BOOL bEncrypt);
BOOL CkSshKeyW_ToOpenSshPublicKey(HCkSshKeyW cHandle, HCkString outStr);
const wchar_t *CkSshKeyW_toOpenSshPublicKey(HCkSshKeyW cHandle);
BOOL CkSshKeyW_ToPuttyPrivateKey(HCkSshKeyW cHandle, BOOL bEncrypt, HCkString outStr);
const wchar_t *CkSshKeyW_toPuttyPrivateKey(HCkSshKeyW cHandle, BOOL bEncrypt);
BOOL CkSshKeyW_ToRfc4716PublicKey(HCkSshKeyW cHandle, HCkString outStr);
const wchar_t *CkSshKeyW_toRfc4716PublicKey(HCkSshKeyW cHandle);
BOOL CkSshKeyW_ToXml(HCkSshKeyW cHandle, HCkString outStr);
const wchar_t *CkSshKeyW_toXml(HCkSshKeyW cHandle);
#endif
