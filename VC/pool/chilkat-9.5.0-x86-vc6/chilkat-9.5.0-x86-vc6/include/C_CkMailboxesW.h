// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkMailboxesWH
#define _C_CkMailboxesWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkMailboxesW CkMailboxesW_Create(void);
void CkMailboxesW_Dispose(HCkMailboxesW handle);
int CkMailboxesW_getCount(HCkMailboxesW cHandle);
void CkMailboxesW_getDebugLogFilePath(HCkMailboxesW cHandle, HCkString retval);
void CkMailboxesW_putDebugLogFilePath(HCkMailboxesW cHandle, const wchar_t *newVal);
const wchar_t *CkMailboxesW_debugLogFilePath(HCkMailboxesW cHandle);
void CkMailboxesW_getLastErrorHtml(HCkMailboxesW cHandle, HCkString retval);
const wchar_t *CkMailboxesW_lastErrorHtml(HCkMailboxesW cHandle);
void CkMailboxesW_getLastErrorText(HCkMailboxesW cHandle, HCkString retval);
const wchar_t *CkMailboxesW_lastErrorText(HCkMailboxesW cHandle);
void CkMailboxesW_getLastErrorXml(HCkMailboxesW cHandle, HCkString retval);
const wchar_t *CkMailboxesW_lastErrorXml(HCkMailboxesW cHandle);
BOOL CkMailboxesW_getVerboseLogging(HCkMailboxesW cHandle);
void CkMailboxesW_putVerboseLogging(HCkMailboxesW cHandle, BOOL newVal);
void CkMailboxesW_getVersion(HCkMailboxesW cHandle, HCkString retval);
const wchar_t *CkMailboxesW_version(HCkMailboxesW cHandle);
BOOL CkMailboxesW_GetFlags(HCkMailboxesW cHandle, int index, HCkString outStr);
const wchar_t *CkMailboxesW_getFlags(HCkMailboxesW cHandle, int index);
int CkMailboxesW_GetMailboxIndex(HCkMailboxesW cHandle, const wchar_t *mbxName);
BOOL CkMailboxesW_GetName(HCkMailboxesW cHandle, int index, HCkString outStrName);
const wchar_t *CkMailboxesW_getName(HCkMailboxesW cHandle, int index);
BOOL CkMailboxesW_GetNthFlag(HCkMailboxesW cHandle, int index, int flagIndex, HCkString outStr);
const wchar_t *CkMailboxesW_getNthFlag(HCkMailboxesW cHandle, int index, int flagIndex);
int CkMailboxesW_GetNumFlags(HCkMailboxesW cHandle, int index);
BOOL CkMailboxesW_HasFlag(HCkMailboxesW cHandle, int index, const wchar_t *flagName);
BOOL CkMailboxesW_HasInferiors(HCkMailboxesW cHandle, int index);
BOOL CkMailboxesW_IsMarked(HCkMailboxesW cHandle, int index);
BOOL CkMailboxesW_IsSelectable(HCkMailboxesW cHandle, int index);
BOOL CkMailboxesW_SaveLastError(HCkMailboxesW cHandle, const wchar_t *path);
#endif
