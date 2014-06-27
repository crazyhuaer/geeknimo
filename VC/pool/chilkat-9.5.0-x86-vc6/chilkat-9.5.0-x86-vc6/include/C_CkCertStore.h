// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCertStore_H
#define _C_CkCertStore_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCertStore CkCertStore_Create(void);
void CkCertStore_Dispose(HCkCertStore handle);
BOOL CkCertStore_getAvoidWindowsPkAccess(HCkCertStore cHandle);
void CkCertStore_putAvoidWindowsPkAccess(HCkCertStore cHandle, BOOL newVal);
void CkCertStore_getDebugLogFilePath(HCkCertStore cHandle, HCkString retval);
void CkCertStore_putDebugLogFilePath(HCkCertStore cHandle, const char *newVal);
const char *CkCertStore_debugLogFilePath(HCkCertStore cHandle);
void CkCertStore_getLastErrorHtml(HCkCertStore cHandle, HCkString retval);
const char *CkCertStore_lastErrorHtml(HCkCertStore cHandle);
void CkCertStore_getLastErrorText(HCkCertStore cHandle, HCkString retval);
const char *CkCertStore_lastErrorText(HCkCertStore cHandle);
void CkCertStore_getLastErrorXml(HCkCertStore cHandle, HCkString retval);
const char *CkCertStore_lastErrorXml(HCkCertStore cHandle);
int CkCertStore_getNumCertificates(HCkCertStore cHandle);
#if defined(CK_WINCERTSTORE_INCLUDED)
int CkCertStore_getNumEmailCerts(HCkCertStore cHandle);
#endif
BOOL CkCertStore_getUtf8(HCkCertStore cHandle);
void CkCertStore_putUtf8(HCkCertStore cHandle, BOOL newVal);
BOOL CkCertStore_getVerboseLogging(HCkCertStore cHandle);
void CkCertStore_putVerboseLogging(HCkCertStore cHandle, BOOL newVal);
void CkCertStore_getVersion(HCkCertStore cHandle, HCkString retval);
const char *CkCertStore_version(HCkCertStore cHandle);
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStore_AddCertificate(HCkCertStore cHandle, HCkCert cert);
#endif
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStore_CreateFileStore(HCkCertStore cHandle, const char *filename);
#endif
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStore_CreateMemoryStore(HCkCertStore cHandle);
#endif
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStore_CreateRegistryStore(HCkCertStore cHandle, const char *regRoot, const char *regPath);
#endif
HCkCert CkCertStore_FindCertByRfc822Name(HCkCertStore cHandle, const char *name);
HCkCert CkCertStore_FindCertBySerial(HCkCertStore cHandle, const char *str);
HCkCert CkCertStore_FindCertBySha1Thumbprint(HCkCertStore cHandle, const char *str);
HCkCert CkCertStore_FindCertBySubject(HCkCertStore cHandle, const char *str);
HCkCert CkCertStore_FindCertBySubjectCN(HCkCertStore cHandle, const char *str);
HCkCert CkCertStore_FindCertBySubjectE(HCkCertStore cHandle, const char *str);
HCkCert CkCertStore_FindCertBySubjectO(HCkCertStore cHandle, const char *str);
HCkCert CkCertStore_FindCertForEmail(HCkCertStore cHandle, const char *emailAddress);
HCkCert CkCertStore_GetCertificate(HCkCertStore cHandle, int index);
#if defined(CK_WINCERTSTORE_INCLUDED)
HCkCert CkCertStore_GetEmailCert(HCkCertStore cHandle, int index);
#endif
BOOL CkCertStore_LoadPemFile(HCkCertStore cHandle, const char *pemPath);
BOOL CkCertStore_LoadPemStr(HCkCertStore cHandle, const char *pemString);
BOOL CkCertStore_LoadPfxData(HCkCertStore cHandle, HCkByteData pfxData, const char *password);
#if !defined(CHILKAT_MONO)
BOOL CkCertStore_LoadPfxData2(HCkCertStore cHandle, const unsigned char *pByteData, unsigned long szByteData, const char *password);
#endif
BOOL CkCertStore_LoadPfxFile(HCkCertStore cHandle, const char *pfxFilename, const char *password);
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStore_OpenCurrentUserStore(HCkCertStore cHandle, BOOL readOnly);
#endif
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStore_OpenFileStore(HCkCertStore cHandle, const char *filename, BOOL readOnly);
#endif
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStore_OpenLocalSystemStore(HCkCertStore cHandle, BOOL readOnly);
#endif
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStore_OpenRegistryStore(HCkCertStore cHandle, const char *regRoot, const char *regPath, BOOL readOnly);
#endif
#if defined(CK_WINCERTSTORE_INCLUDED)
BOOL CkCertStore_RemoveCertificate(HCkCertStore cHandle, HCkCert cert);
#endif
BOOL CkCertStore_SaveLastError(HCkCertStore cHandle, const char *path);
#endif
