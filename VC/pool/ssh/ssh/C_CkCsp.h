// This is a generated source file for Chilkat version 9.5.0.40
#if defined(WIN32) || defined(WINCE)

#ifndef _C_CkCsp_H
#define _C_CkCsp_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCsp CkCsp_Create(void);
void CkCsp_Dispose(HCkCsp handle);
void CkCsp_getDebugLogFilePath(HCkCsp cHandle, HCkString retval);
void CkCsp_putDebugLogFilePath(HCkCsp cHandle, const char *newVal);
const char *CkCsp_debugLogFilePath(HCkCsp cHandle);
void CkCsp_getEncryptAlgorithm(HCkCsp cHandle, HCkString retval);
const char *CkCsp_encryptAlgorithm(HCkCsp cHandle);
int CkCsp_getEncryptAlgorithmID(HCkCsp cHandle);
int CkCsp_getEncryptNumBits(HCkCsp cHandle);
void CkCsp_getHashAlgorithm(HCkCsp cHandle, HCkString retval);
const char *CkCsp_hashAlgorithm(HCkCsp cHandle);
int CkCsp_getHashAlgorithmID(HCkCsp cHandle);
int CkCsp_getHashNumBits(HCkCsp cHandle);
void CkCsp_getKeyContainerName(HCkCsp cHandle, HCkString retval);
void CkCsp_putKeyContainerName(HCkCsp cHandle, const char *newVal);
const char *CkCsp_keyContainerName(HCkCsp cHandle);
void CkCsp_getLastErrorHtml(HCkCsp cHandle, HCkString retval);
const char *CkCsp_lastErrorHtml(HCkCsp cHandle);
void CkCsp_getLastErrorText(HCkCsp cHandle, HCkString retval);
const char *CkCsp_lastErrorText(HCkCsp cHandle);
void CkCsp_getLastErrorXml(HCkCsp cHandle, HCkString retval);
const char *CkCsp_lastErrorXml(HCkCsp cHandle);
BOOL CkCsp_getMachineKeyset(HCkCsp cHandle);
void CkCsp_putMachineKeyset(HCkCsp cHandle, BOOL newVal);
int CkCsp_getNumEncryptAlgorithms(HCkCsp cHandle);
int CkCsp_getNumHashAlgorithms(HCkCsp cHandle);
int CkCsp_getNumKeyContainers(HCkCsp cHandle);
int CkCsp_getNumKeyExchangeAlgorithms(HCkCsp cHandle);
int CkCsp_getNumSignatureAlgorithms(HCkCsp cHandle);
void CkCsp_getProviderName(HCkCsp cHandle, HCkString retval);
void CkCsp_putProviderName(HCkCsp cHandle, const char *newVal);
const char *CkCsp_providerName(HCkCsp cHandle);
int CkCsp_getProviderType(HCkCsp cHandle);
BOOL CkCsp_getUtf8(HCkCsp cHandle);
void CkCsp_putUtf8(HCkCsp cHandle, BOOL newVal);
BOOL CkCsp_getVerboseLogging(HCkCsp cHandle);
void CkCsp_putVerboseLogging(HCkCsp cHandle, BOOL newVal);
void CkCsp_getVersion(HCkCsp cHandle, HCkString retval);
const char *CkCsp_version(HCkCsp cHandle);
HCkStringArray CkCsp_GetKeyContainerNames(HCkCsp cHandle);
BOOL CkCsp_HasEncryptAlgorithm(HCkCsp cHandle, const char *name, int numBits);
BOOL CkCsp_HasHashAlgorithm(HCkCsp cHandle, const char *name, int numBits);
BOOL CkCsp_Initialize(HCkCsp cHandle);
BOOL CkCsp_NthEncryptionAlgorithm(HCkCsp cHandle, int index, HCkString outName);
const char *CkCsp_nthEncryptionAlgorithm(HCkCsp cHandle, int index);
int CkCsp_NthEncryptionNumBits(HCkCsp cHandle, int index);
BOOL CkCsp_NthHashAlgorithmName(HCkCsp cHandle, int index, HCkString outName);
const char *CkCsp_nthHashAlgorithmName(HCkCsp cHandle, int index);
int CkCsp_NthHashNumBits(HCkCsp cHandle, int index);
BOOL CkCsp_NthKeyContainerName(HCkCsp cHandle, int index, HCkString outName);
const char *CkCsp_nthKeyContainerName(HCkCsp cHandle, int index);
BOOL CkCsp_NthKeyExchangeAlgorithm(HCkCsp cHandle, int index, HCkString outName);
const char *CkCsp_nthKeyExchangeAlgorithm(HCkCsp cHandle, int index);
int CkCsp_NthKeyExchangeNumBits(HCkCsp cHandle, int index);
BOOL CkCsp_NthSignatureAlgorithm(HCkCsp cHandle, int index, HCkString outName);
const char *CkCsp_nthSignatureAlgorithm(HCkCsp cHandle, int index);
int CkCsp_NthSignatureNumBits(HCkCsp cHandle, int index);
BOOL CkCsp_SaveLastError(HCkCsp cHandle, const char *path);
int CkCsp_SetEncryptAlgorithm(HCkCsp cHandle, const char *name);
int CkCsp_SetHashAlgorithm(HCkCsp cHandle, const char *name);
BOOL CkCsp_SetProviderMicrosoftBase(HCkCsp cHandle);
BOOL CkCsp_SetProviderMicrosoftEnhanced(HCkCsp cHandle);
BOOL CkCsp_SetProviderMicrosoftRsaAes(HCkCsp cHandle);
BOOL CkCsp_SetProviderMicrosoftStrong(HCkCsp cHandle);
#endif

#endif // WIN32 (entire file)
