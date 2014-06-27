// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCertStoreWH
#define _C_CkCertStoreWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCertStoreW CkCertStoreW_Create(void);
void CkCertStoreW_Dispose(HCkCertStoreW handle);
BOOL CkCertStoreW_getAvoidWindowsPkAccess(HCkCertStoreW cHandle);
void CkCertStoreW_putAvoidWindowsPkAccess(HCkCertStoreW cHandle, BOOL newVal);
void CkCertStoreW_getDebugLogFilePath(HCkCertStoreW cHandle, HCkString retval);
void CkCertStoreW_putDebugLogFilePath(HCkCertStoreW cHandle, const wchar_t *newVal);
const wchar_t *CkCertStoreW_debugLogFilePath(HCkCertStoreW cHandle);
void CkCertStoreW_getLastErrorHtml(HCkCertStoreW cHandle, HCkString retval);
const wchar_t *CkCertStoreW_lastErrorHtml(HCkCertStoreW cHandle);
void CkCertStoreW_getLastErrorText(HCkCertStoreW cHandle, HCkString retval);
const wchar_t *CkCertStoreW_lastErrorText(HCkCertStoreW cHandle);
void CkCertStoreW_getLastErrorXml(HCkCertStoreW cHandle, HCkString retval);
const wchar_t *CkCertStoreW_lastErrorXml(HCkCertStoreW cHandle);
int CkCertStoreW_getNumCertificates(HCkCertStoreW cHandle);
#if defined(CK_WINCERTSTORE_INCLUDED)
int CkCertStoreW_getNumEmailCerts(HCkCertStoreW cHandle);
#endif
BOOL CkCertStoreW_getVerboseLogging(HCkCertStoreW cHandle);
void CkCertStoreW_putVerboseLogging(HCkCertStoreW cHandle, BOOL newVal);
void CkCertStoreW_getVersion(HCkCertStoreW cHandle, HCkString retval);
const wchar_t *CkCertStoreW_version(HCkCertStoreW cHandle);
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStoreW_AddCertificate(HCkCertStoreW cHandle, HCkCertW cert);
#endif
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStoreW_CreateFileStore(HCkCertStoreW cHandle, const wchar_t *filename);
#endif
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStoreW_CreateMemoryStore(HCkCertStoreW cHandle);
#endif
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStoreW_CreateRegistryStore(HCkCertStoreW cHandle, const wchar_t *regRoot, const wchar_t *regPath);
#endif
HCkCertW CkCertStoreW_FindCertByRfc822Name(HCkCertStoreW cHandle, const wchar_t *name);
HCkCertW CkCertStoreW_FindCertBySerial(HCkCertStoreW cHandle, const wchar_t *str);
HCkCertW CkCertStoreW_FindCertBySha1Thumbprint(HCkCertStoreW cHandle, const wchar_t *str);
HCkCertW CkCertStoreW_FindCertBySubject(HCkCertStoreW cHandle, const wchar_t *str);
HCkCertW CkCertStoreW_FindCertBySubjectCN(HCkCertStoreW cHandle, const wchar_t *str);
HCkCertW CkCertStoreW_FindCertBySubjectE(HCkCertStoreW cHandle, const wchar_t *str);
HCkCertW CkCertStoreW_FindCertBySubjectO(HCkCertStoreW cHandle, const wchar_t *str);
HCkCertW CkCertStoreW_FindCertForEmail(HCkCertStoreW cHandle, const wchar_t *emailAddress);
HCkCertW CkCertStoreW_GetCertificate(HCkCertStoreW cHandle, int index);
#if defined(CK_WINCERTSTORE_INCLUDED)
HCkCertW CkCertStoreW_GetEmailCert(HCkCertStoreW cHandle, int index);
#endif
BOOL CkCertStoreW_LoadPemFile(HCkCertStoreW cHandle, const wchar_t *pemPath);
BOOL CkCertStoreW_LoadPemStr(HCkCertStoreW cHandle, const wchar_t *pemString);
BOOL CkCertStoreW_LoadPfxData(HCkCertStoreW cHandle, HCkByteData pfxData, const wchar_t *password);
#if !defined(CHILKAT_MONO)
BOOL CkCertStoreW_LoadPfxData2(HCkCertStoreW cHandle, const unsigned char *pByteData, unsigned long szByteData, const wchar_t *password);
#endif
BOOL CkCertStoreW_LoadPfxFile(HCkCertStoreW cHandle, const wchar_t *pfxFilename, const wchar_t *password);
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStoreW_OpenCurrentUserStore(HCkCertStoreW cHandle, BOOL readOnly);
#endif
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStoreW_OpenFileStore(HCkCertStoreW cHandle, const wchar_t *filename, BOOL readOnly);
#endif
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStoreW_OpenLocalSystemStore(HCkCertStoreW cHandle, BOOL readOnly);
#endif
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStoreW_OpenRegistryStore(HCkCertStoreW cHandle, const wchar_t *regRoot, const wchar_t *regPath, BOOL readOnly);
#endif
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStoreW_RemoveCertificate(HCkCertStoreW cHandle, HCkCertW cert);
#endif
BOOL CkCertStoreW_SaveLastError(HCkCertStoreW cHandle, const wchar_t *path);
#endif
