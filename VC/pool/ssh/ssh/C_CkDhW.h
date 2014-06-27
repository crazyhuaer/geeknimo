// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkDhWH
#define _C_CkDhWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkDhW CkDhW_Create(void);
void CkDhW_Dispose(HCkDhW handle);
void CkDhW_getDebugLogFilePath(HCkDhW cHandle, HCkString retval);
void CkDhW_putDebugLogFilePath(HCkDhW cHandle, const wchar_t *newVal);
const wchar_t *CkDhW_debugLogFilePath(HCkDhW cHandle);
int CkDhW_getG(HCkDhW cHandle);
void CkDhW_getLastErrorHtml(HCkDhW cHandle, HCkString retval);
const wchar_t *CkDhW_lastErrorHtml(HCkDhW cHandle);
void CkDhW_getLastErrorText(HCkDhW cHandle, HCkString retval);
const wchar_t *CkDhW_lastErrorText(HCkDhW cHandle);
void CkDhW_getLastErrorXml(HCkDhW cHandle, HCkString retval);
const wchar_t *CkDhW_lastErrorXml(HCkDhW cHandle);
void CkDhW_getP(HCkDhW cHandle, HCkString retval);
const wchar_t *CkDhW_p(HCkDhW cHandle);
BOOL CkDhW_getVerboseLogging(HCkDhW cHandle);
void CkDhW_putVerboseLogging(HCkDhW cHandle, BOOL newVal);
void CkDhW_getVersion(HCkDhW cHandle, HCkString retval);
const wchar_t *CkDhW_version(HCkDhW cHandle);
BOOL CkDhW_CreateE(HCkDhW cHandle, int numBits, HCkString outStr);
const wchar_t *CkDhW_createE(HCkDhW cHandle, int numBits);
BOOL CkDhW_FindK(HCkDhW cHandle, const wchar_t *E, HCkString outStr);
const wchar_t *CkDhW_findK(HCkDhW cHandle, const wchar_t *E);
BOOL CkDhW_GenPG(HCkDhW cHandle, int numBits, int G);
BOOL CkDhW_SaveLastError(HCkDhW cHandle, const wchar_t *path);
BOOL CkDhW_SetPG(HCkDhW cHandle, const wchar_t *p, int g);
BOOL CkDhW_UnlockComponent(HCkDhW cHandle, const wchar_t *unlockCode);
void CkDhW_UseKnownPrime(HCkDhW cHandle, int index);
#endif
