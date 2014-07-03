// This is a generated source file for Chilkat version 9.5.0.40
#if defined(WIN32) || defined(WINCE)

#ifndef _C_CkCspWH
#define _C_CkCspWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCspW CkCspW_Create(void);
void CkCspW_Dispose(HCkCspW handle);
void CkCspW_getDebugLogFilePath(HCkCspW cHandle, HCkString retval);
void CkCspW_putDebugLogFilePath(HCkCspW cHandle, const wchar_t *newVal);
const wchar_t *CkCspW_debugLogFilePath(HCkCspW cHandle);
void CkCspW_getEncryptAlgorithm(HCkCspW cHandle, HCkString retval);
const wchar_t *CkCspW_encryptAlgorithm(HCkCspW cHandle);
int CkCspW_getEncryptAlgorithmID(HCkCspW cHandle);
int CkCspW_getEncryptNumBits(HCkCspW cHandle);
void CkCspW_getHashAlgorithm(HCkCspW cHandle, HCkString retval);
const wchar_t *CkCspW_hashAlgorithm(HCkCspW cHandle);
int CkCspW_getHashAlgorithmID(HCkCspW cHandle);
int CkCspW_getHashNumBits(HCkCspW cHandle);
void CkCspW_getKeyContainerName(HCkCspW cHandle, HCkString retval);
void CkCspW_putKeyContainerName(HCkCspW cHandle, const wchar_t *newVal);
const wchar_t *CkCspW_keyContainerName(HCkCspW cHandle);
void CkCspW_getLastErrorHtml(HCkCspW cHandle, HCkString retval);
const wchar_t *CkCspW_lastErrorHtml(HCkCspW cHandle);
void CkCspW_getLastErrorText(HCkCspW cHandle, HCkString retval);
const wchar_t *CkCspW_lastErrorText(HCkCspW cHandle);
void CkCspW_getLastErrorXml(HCkCspW cHandle, HCkString retval);
const wchar_t *CkCspW_lastErrorXml(HCkCspW cHandle);
BOOL CkCspW_getMachineKeyset(HCkCspW cHandle);
void CkCspW_putMachineKeyset(HCkCspW cHandle, BOOL newVal);
int CkCspW_getNumEncryptAlgorithms(HCkCspW cHandle);
int CkCspW_getNumHashAlgorithms(HCkCspW cHandle);
int CkCspW_getNumKeyContainers(HCkCspW cHandle);
int CkCspW_getNumKeyExchangeAlgorithms(HCkCspW cHandle);
int CkCspW_getNumSignatureAlgorithms(HCkCspW cHandle);
void CkCspW_getProviderName(HCkCspW cHandle, HCkString retval);
void CkCspW_putProviderName(HCkCspW cHandle, const wchar_t *newVal);
const wchar_t *CkCspW_providerName(HCkCspW cHandle);
int CkCspW_getProviderType(HCkCspW cHandle);
BOOL CkCspW_getVerboseLogging(HCkCspW cHandle);
void CkCspW_putVerboseLogging(HCkCspW cHandle, BOOL newVal);
void CkCspW_getVersion(HCkCspW cHandle, HCkString retval);
const wchar_t *CkCspW_version(HCkCspW cHandle);
HCkStringArrayW CkCspW_GetKeyContainerNames(HCkCspW cHandle);
BOOL CkCspW_HasEncryptAlgorithm(HCkCspW cHandle, const wchar_t *name, int numBits);
BOOL CkCspW_HasHashAlgorithm(HCkCspW cHandle, const wchar_t *name, int numBits);
BOOL CkCspW_Initialize(HCkCspW cHandle);
BOOL CkCspW_NthEncryptionAlgorithm(HCkCspW cHandle, int index, HCkString outName);
const wchar_t *CkCspW_nthEncryptionAlgorithm(HCkCspW cHandle, int index);
int CkCspW_NthEncryptionNumBits(HCkCspW cHandle, int index);
BOOL CkCspW_NthHashAlgorithmName(HCkCspW cHandle, int index, HCkString outName);
const wchar_t *CkCspW_nthHashAlgorithmName(HCkCspW cHandle, int index);
int CkCspW_NthHashNumBits(HCkCspW cHandle, int index);
BOOL CkCspW_NthKeyContainerName(HCkCspW cHandle, int index, HCkString outName);
const wchar_t *CkCspW_nthKeyContainerName(HCkCspW cHandle, int index);
BOOL CkCspW_NthKeyExchangeAlgorithm(HCkCspW cHandle, int index, HCkString outName);
const wchar_t *CkCspW_nthKeyExchangeAlgorithm(HCkCspW cHandle, int index);
int CkCspW_NthKeyExchangeNumBits(HCkCspW cHandle, int index);
BOOL CkCspW_NthSignatureAlgorithm(HCkCspW cHandle, int index, HCkString outName);
const wchar_t *CkCspW_nthSignatureAlgorithm(HCkCspW cHandle, int index);
int CkCspW_NthSignatureNumBits(HCkCspW cHandle, int index);
BOOL CkCspW_SaveLastError(HCkCspW cHandle, const wchar_t *path);
int CkCspW_SetEncryptAlgorithm(HCkCspW cHandle, const wchar_t *name);
int CkCspW_SetHashAlgorithm(HCkCspW cHandle, const wchar_t *name);
BOOL CkCspW_SetProviderMicrosoftBase(HCkCspW cHandle);
BOOL CkCspW_SetProviderMicrosoftEnhanced(HCkCspW cHandle);
BOOL CkCspW_SetProviderMicrosoftRsaAes(HCkCspW cHandle);
BOOL CkCspW_SetProviderMicrosoftStrong(HCkCspW cHandle);
#endif

#endif // WIN32 (entire file)
