// This is a generated source file for Chilkat version 9.5.0.40
#if defined(WIN32) || defined(WINCE)

#ifndef _C_CkKeyContainer_H
#define _C_CkKeyContainer_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkKeyContainer CkKeyContainer_Create(void);
void CkKeyContainer_Dispose(HCkKeyContainer handle);
#if defined(CK_CRYPTOAPI_INCLUDED)
void CkKeyContainer_getContainerName(HCkKeyContainer cHandle, HCkString retval);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
const char *CkKeyContainer_containerName(HCkKeyContainer cHandle);
#endif
void CkKeyContainer_getDebugLogFilePath(HCkKeyContainer cHandle, HCkString retval);
void CkKeyContainer_putDebugLogFilePath(HCkKeyContainer cHandle, const char *newVal);
const char *CkKeyContainer_debugLogFilePath(HCkKeyContainer cHandle);
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkKeyContainer_getIsMachineKeyset(HCkKeyContainer cHandle);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkKeyContainer_getIsOpen(HCkKeyContainer cHandle);
#endif
void CkKeyContainer_getLastErrorHtml(HCkKeyContainer cHandle, HCkString retval);
const char *CkKeyContainer_lastErrorHtml(HCkKeyContainer cHandle);
void CkKeyContainer_getLastErrorText(HCkKeyContainer cHandle, HCkString retval);
const char *CkKeyContainer_lastErrorText(HCkKeyContainer cHandle);
void CkKeyContainer_getLastErrorXml(HCkKeyContainer cHandle, HCkString retval);
const char *CkKeyContainer_lastErrorXml(HCkKeyContainer cHandle);
BOOL CkKeyContainer_getUtf8(HCkKeyContainer cHandle);
void CkKeyContainer_putUtf8(HCkKeyContainer cHandle, BOOL newVal);
BOOL CkKeyContainer_getVerboseLogging(HCkKeyContainer cHandle);
void CkKeyContainer_putVerboseLogging(HCkKeyContainer cHandle, BOOL newVal);
void CkKeyContainer_getVersion(HCkKeyContainer cHandle, HCkString retval);
const char *CkKeyContainer_version(HCkKeyContainer cHandle);
#if defined(CK_CRYPTOAPI_INCLUDED)
void CkKeyContainer_CloseContainer(HCkKeyContainer cHandle);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkKeyContainer_CreateContainer(HCkKeyContainer cHandle, const char *name, BOOL machineKeyset);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkKeyContainer_DeleteContainer(HCkKeyContainer cHandle);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkKeyContainer_FetchContainerNames(HCkKeyContainer cHandle, BOOL bMachineKeyset);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkKeyContainer_GenerateKeyPair(HCkKeyContainer cHandle, BOOL bKeyExchangePair, int keyLengthInBits);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkKeyContainer_GenerateUuid(HCkKeyContainer cHandle, HCkString outGuid);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
const char *CkKeyContainer_generateUuid(HCkKeyContainer cHandle);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkKeyContainer_GetNthContainerName(HCkKeyContainer cHandle, BOOL bMachineKeyset, int index, HCkString outName);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
const char *CkKeyContainer_getNthContainerName(HCkKeyContainer cHandle, BOOL bMachineKeyset, int index);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
int CkKeyContainer_GetNumContainers(HCkKeyContainer cHandle, BOOL bMachineKeyset);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
HCkPrivateKey CkKeyContainer_GetPrivateKey(HCkKeyContainer cHandle, BOOL bKeyExchangePair);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
HCkPublicKey CkKeyContainer_GetPublicKey(HCkKeyContainer cHandle, BOOL bKeyExchangePair);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkKeyContainer_ImportPrivateKey(HCkKeyContainer cHandle, HCkPrivateKey key, BOOL bKeyExchangePair);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkKeyContainer_ImportPublicKey(HCkKeyContainer cHandle, HCkPublicKey key, BOOL bKeyExchangePair);
#endif
#if defined(CK_CRYPTOAPI_INCLUDED)
BOOL CkKeyContainer_OpenContainer(HCkKeyContainer cHandle, const char *name, BOOL needPrivateKeyAccess, BOOL machineKeyset);
#endif
BOOL CkKeyContainer_SaveLastError(HCkKeyContainer cHandle, const char *path);
#endif

#endif // WIN32 (entire file)
