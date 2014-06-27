// This is a generated source file for Chilkat version 9.5.0.40
#if defined(WIN32) || defined(WINCE)

#ifndef _C_CkCreateCSWH
#define _C_CkCreateCSWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCreateCSW CkCreateCSW_Create(void);
void CkCreateCSW_Dispose(HCkCreateCSW handle);
void CkCreateCSW_getDebugLogFilePath(HCkCreateCSW cHandle, HCkString retval);
void CkCreateCSW_putDebugLogFilePath(HCkCreateCSW cHandle, const wchar_t *newVal);
const wchar_t *CkCreateCSW_debugLogFilePath(HCkCreateCSW cHandle);
void CkCreateCSW_getLastErrorHtml(HCkCreateCSW cHandle, HCkString retval);
const wchar_t *CkCreateCSW_lastErrorHtml(HCkCreateCSW cHandle);
void CkCreateCSW_getLastErrorText(HCkCreateCSW cHandle, HCkString retval);
const wchar_t *CkCreateCSW_lastErrorText(HCkCreateCSW cHandle);
void CkCreateCSW_getLastErrorXml(HCkCreateCSW cHandle, HCkString retval);
const wchar_t *CkCreateCSW_lastErrorXml(HCkCreateCSW cHandle);
BOOL CkCreateCSW_getReadOnly(HCkCreateCSW cHandle);
void CkCreateCSW_putReadOnly(HCkCreateCSW cHandle, BOOL newVal);
BOOL CkCreateCSW_getVerboseLogging(HCkCreateCSW cHandle);
void CkCreateCSW_putVerboseLogging(HCkCreateCSW cHandle, BOOL newVal);
void CkCreateCSW_getVersion(HCkCreateCSW cHandle, HCkString retval);
const wchar_t *CkCreateCSW_version(HCkCreateCSW cHandle);
HCkCertStoreW CkCreateCSW_CreateFileStore(HCkCreateCSW cHandle, const wchar_t *path);
HCkCertStoreW CkCreateCSW_CreateMemoryStore(HCkCreateCSW cHandle);
HCkCertStoreW CkCreateCSW_CreateRegistryStore(HCkCreateCSW cHandle, const wchar_t *regRoot, const wchar_t *regPath);
HCkCertStoreW CkCreateCSW_OpenChilkatStore(HCkCreateCSW cHandle);
HCkCertStoreW CkCreateCSW_OpenCurrentUserStore(HCkCreateCSW cHandle);
HCkCertStoreW CkCreateCSW_OpenFileStore(HCkCreateCSW cHandle, const wchar_t *path);
HCkCertStoreW CkCreateCSW_OpenLocalSystemStore(HCkCreateCSW cHandle);
HCkCertStoreW CkCreateCSW_OpenOutlookStore(HCkCreateCSW cHandle);
HCkCertStoreW CkCreateCSW_OpenRegistryStore(HCkCreateCSW cHandle, const wchar_t *regRoot, const wchar_t *regPath);
BOOL CkCreateCSW_SaveLastError(HCkCreateCSW cHandle, const wchar_t *path);
#endif

#endif // WIN32 (entire file)
