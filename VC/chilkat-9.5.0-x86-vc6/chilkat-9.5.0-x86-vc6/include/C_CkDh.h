// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkDh_H
#define _C_CkDh_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkDh CkDh_Create(void);
void CkDh_Dispose(HCkDh handle);
void CkDh_getDebugLogFilePath(HCkDh cHandle, HCkString retval);
void CkDh_putDebugLogFilePath(HCkDh cHandle, const char *newVal);
const char *CkDh_debugLogFilePath(HCkDh cHandle);
int CkDh_getG(HCkDh cHandle);
void CkDh_getLastErrorHtml(HCkDh cHandle, HCkString retval);
const char *CkDh_lastErrorHtml(HCkDh cHandle);
void CkDh_getLastErrorText(HCkDh cHandle, HCkString retval);
const char *CkDh_lastErrorText(HCkDh cHandle);
void CkDh_getLastErrorXml(HCkDh cHandle, HCkString retval);
const char *CkDh_lastErrorXml(HCkDh cHandle);
void CkDh_getP(HCkDh cHandle, HCkString retval);
const char *CkDh_p(HCkDh cHandle);
BOOL CkDh_getUtf8(HCkDh cHandle);
void CkDh_putUtf8(HCkDh cHandle, BOOL newVal);
BOOL CkDh_getVerboseLogging(HCkDh cHandle);
void CkDh_putVerboseLogging(HCkDh cHandle, BOOL newVal);
void CkDh_getVersion(HCkDh cHandle, HCkString retval);
const char *CkDh_version(HCkDh cHandle);
BOOL CkDh_CreateE(HCkDh cHandle, int numBits, HCkString outStr);
const char *CkDh_createE(HCkDh cHandle, int numBits);
BOOL CkDh_FindK(HCkDh cHandle, const char *E, HCkString outStr);
const char *CkDh_findK(HCkDh cHandle, const char *E);
BOOL CkDh_GenPG(HCkDh cHandle, int numBits, int G);
BOOL CkDh_SaveLastError(HCkDh cHandle, const char *path);
BOOL CkDh_SetPG(HCkDh cHandle, const char *p, int g);
BOOL CkDh_UnlockComponent(HCkDh cHandle, const char *unlockCode);
void CkDh_UseKnownPrime(HCkDh cHandle, int index);
#endif
