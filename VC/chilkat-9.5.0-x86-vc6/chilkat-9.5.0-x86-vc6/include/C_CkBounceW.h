// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkBounceWH
#define _C_CkBounceWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkBounceW CkBounceW_Create(void);
void CkBounceW_Dispose(HCkBounceW handle);
void CkBounceW_getBounceAddress(HCkBounceW cHandle, HCkString retval);
const wchar_t *CkBounceW_bounceAddress(HCkBounceW cHandle);
void CkBounceW_getBounceData(HCkBounceW cHandle, HCkString retval);
const wchar_t *CkBounceW_bounceData(HCkBounceW cHandle);
int CkBounceW_getBounceType(HCkBounceW cHandle);
void CkBounceW_getDebugLogFilePath(HCkBounceW cHandle, HCkString retval);
void CkBounceW_putDebugLogFilePath(HCkBounceW cHandle, const wchar_t *newVal);
const wchar_t *CkBounceW_debugLogFilePath(HCkBounceW cHandle);
void CkBounceW_getLastErrorHtml(HCkBounceW cHandle, HCkString retval);
const wchar_t *CkBounceW_lastErrorHtml(HCkBounceW cHandle);
void CkBounceW_getLastErrorText(HCkBounceW cHandle, HCkString retval);
const wchar_t *CkBounceW_lastErrorText(HCkBounceW cHandle);
void CkBounceW_getLastErrorXml(HCkBounceW cHandle, HCkString retval);
const wchar_t *CkBounceW_lastErrorXml(HCkBounceW cHandle);
BOOL CkBounceW_getVerboseLogging(HCkBounceW cHandle);
void CkBounceW_putVerboseLogging(HCkBounceW cHandle, BOOL newVal);
void CkBounceW_getVersion(HCkBounceW cHandle, HCkString retval);
const wchar_t *CkBounceW_version(HCkBounceW cHandle);
BOOL CkBounceW_ExamineEmail(HCkBounceW cHandle, HCkEmailW email);
BOOL CkBounceW_ExamineEml(HCkBounceW cHandle, const wchar_t *emlFilename);
BOOL CkBounceW_ExamineMime(HCkBounceW cHandle, const wchar_t *mimeText);
BOOL CkBounceW_SaveLastError(HCkBounceW cHandle, const wchar_t *path);
BOOL CkBounceW_UnlockComponent(HCkBounceW cHandle, const wchar_t *unlockCode);
#endif
