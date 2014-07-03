// This is a generated source file for Chilkat version 9.5.0.40
#if defined(WIN32) || defined(WINCE)

#ifndef _C_CkCreateCS_H
#define _C_CkCreateCS_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCreateCS CkCreateCS_Create(void);
void CkCreateCS_Dispose(HCkCreateCS handle);
void CkCreateCS_getDebugLogFilePath(HCkCreateCS cHandle, HCkString retval);
void CkCreateCS_putDebugLogFilePath(HCkCreateCS cHandle, const char *newVal);
const char *CkCreateCS_debugLogFilePath(HCkCreateCS cHandle);
void CkCreateCS_getLastErrorHtml(HCkCreateCS cHandle, HCkString retval);
const char *CkCreateCS_lastErrorHtml(HCkCreateCS cHandle);
void CkCreateCS_getLastErrorText(HCkCreateCS cHandle, HCkString retval);
const char *CkCreateCS_lastErrorText(HCkCreateCS cHandle);
void CkCreateCS_getLastErrorXml(HCkCreateCS cHandle, HCkString retval);
const char *CkCreateCS_lastErrorXml(HCkCreateCS cHandle);
BOOL CkCreateCS_getReadOnly(HCkCreateCS cHandle);
void CkCreateCS_putReadOnly(HCkCreateCS cHandle, BOOL newVal);
BOOL CkCreateCS_getUtf8(HCkCreateCS cHandle);
void CkCreateCS_putUtf8(HCkCreateCS cHandle, BOOL newVal);
BOOL CkCreateCS_getVerboseLogging(HCkCreateCS cHandle);
void CkCreateCS_putVerboseLogging(HCkCreateCS cHandle, BOOL newVal);
void CkCreateCS_getVersion(HCkCreateCS cHandle, HCkString retval);
const char *CkCreateCS_version(HCkCreateCS cHandle);
HCkCertStore CkCreateCS_CreateFileStore(HCkCreateCS cHandle, const char *path);
HCkCertStore CkCreateCS_CreateMemoryStore(HCkCreateCS cHandle);
HCkCertStore CkCreateCS_CreateRegistryStore(HCkCreateCS cHandle, const char *regRoot, const char *regPath);
HCkCertStore CkCreateCS_OpenChilkatStore(HCkCreateCS cHandle);
HCkCertStore CkCreateCS_OpenCurrentUserStore(HCkCreateCS cHandle);
HCkCertStore CkCreateCS_OpenFileStore(HCkCreateCS cHandle, const char *path);
HCkCertStore CkCreateCS_OpenLocalSystemStore(HCkCreateCS cHandle);
HCkCertStore CkCreateCS_OpenOutlookStore(HCkCreateCS cHandle);
HCkCertStore CkCreateCS_OpenRegistryStore(HCkCreateCS cHandle, const char *regRoot, const char *regPath);
BOOL CkCreateCS_SaveLastError(HCkCreateCS cHandle, const char *path);
#endif

#endif // WIN32 (entire file)
