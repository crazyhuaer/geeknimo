// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkMailboxes_H
#define _C_CkMailboxes_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkMailboxes CkMailboxes_Create(void);
void CkMailboxes_Dispose(HCkMailboxes handle);
int CkMailboxes_getCount(HCkMailboxes cHandle);
void CkMailboxes_getDebugLogFilePath(HCkMailboxes cHandle, HCkString retval);
void CkMailboxes_putDebugLogFilePath(HCkMailboxes cHandle, const char *newVal);
const char *CkMailboxes_debugLogFilePath(HCkMailboxes cHandle);
void CkMailboxes_getLastErrorHtml(HCkMailboxes cHandle, HCkString retval);
const char *CkMailboxes_lastErrorHtml(HCkMailboxes cHandle);
void CkMailboxes_getLastErrorText(HCkMailboxes cHandle, HCkString retval);
const char *CkMailboxes_lastErrorText(HCkMailboxes cHandle);
void CkMailboxes_getLastErrorXml(HCkMailboxes cHandle, HCkString retval);
const char *CkMailboxes_lastErrorXml(HCkMailboxes cHandle);
BOOL CkMailboxes_getUtf8(HCkMailboxes cHandle);
void CkMailboxes_putUtf8(HCkMailboxes cHandle, BOOL newVal);
BOOL CkMailboxes_getVerboseLogging(HCkMailboxes cHandle);
void CkMailboxes_putVerboseLogging(HCkMailboxes cHandle, BOOL newVal);
void CkMailboxes_getVersion(HCkMailboxes cHandle, HCkString retval);
const char *CkMailboxes_version(HCkMailboxes cHandle);
BOOL CkMailboxes_GetFlags(HCkMailboxes cHandle, int index, HCkString outStr);
const char *CkMailboxes_getFlags(HCkMailboxes cHandle, int index);
int CkMailboxes_GetMailboxIndex(HCkMailboxes cHandle, const char *mbxName);
BOOL CkMailboxes_GetName(HCkMailboxes cHandle, int index, HCkString outStrName);
const char *CkMailboxes_getName(HCkMailboxes cHandle, int index);
BOOL CkMailboxes_GetNthFlag(HCkMailboxes cHandle, int index, int flagIndex, HCkString outStr);
const char *CkMailboxes_getNthFlag(HCkMailboxes cHandle, int index, int flagIndex);
int CkMailboxes_GetNumFlags(HCkMailboxes cHandle, int index);
BOOL CkMailboxes_HasFlag(HCkMailboxes cHandle, int index, const char *flagName);
BOOL CkMailboxes_HasInferiors(HCkMailboxes cHandle, int index);
BOOL CkMailboxes_IsMarked(HCkMailboxes cHandle, int index);
BOOL CkMailboxes_IsSelectable(HCkMailboxes cHandle, int index);
BOOL CkMailboxes_SaveLastError(HCkMailboxes cHandle, const char *path);
#endif
