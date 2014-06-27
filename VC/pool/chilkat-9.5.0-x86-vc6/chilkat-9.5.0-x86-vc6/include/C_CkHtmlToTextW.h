// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkHtmlToTextWH
#define _C_CkHtmlToTextWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkHtmlToTextW CkHtmlToTextW_Create(void);
void CkHtmlToTextW_Dispose(HCkHtmlToTextW handle);
void CkHtmlToTextW_getDebugLogFilePath(HCkHtmlToTextW cHandle, HCkString retval);
void CkHtmlToTextW_putDebugLogFilePath(HCkHtmlToTextW cHandle, const wchar_t *newVal);
const wchar_t *CkHtmlToTextW_debugLogFilePath(HCkHtmlToTextW cHandle);
BOOL CkHtmlToTextW_getDecodeHtmlEntities(HCkHtmlToTextW cHandle);
void CkHtmlToTextW_putDecodeHtmlEntities(HCkHtmlToTextW cHandle, BOOL newVal);
void CkHtmlToTextW_getLastErrorHtml(HCkHtmlToTextW cHandle, HCkString retval);
const wchar_t *CkHtmlToTextW_lastErrorHtml(HCkHtmlToTextW cHandle);
void CkHtmlToTextW_getLastErrorText(HCkHtmlToTextW cHandle, HCkString retval);
const wchar_t *CkHtmlToTextW_lastErrorText(HCkHtmlToTextW cHandle);
void CkHtmlToTextW_getLastErrorXml(HCkHtmlToTextW cHandle, HCkString retval);
const wchar_t *CkHtmlToTextW_lastErrorXml(HCkHtmlToTextW cHandle);
int CkHtmlToTextW_getRightMargin(HCkHtmlToTextW cHandle);
void CkHtmlToTextW_putRightMargin(HCkHtmlToTextW cHandle, int newVal);
BOOL CkHtmlToTextW_getSuppressLinks(HCkHtmlToTextW cHandle);
void CkHtmlToTextW_putSuppressLinks(HCkHtmlToTextW cHandle, BOOL newVal);
BOOL CkHtmlToTextW_getVerboseLogging(HCkHtmlToTextW cHandle);
void CkHtmlToTextW_putVerboseLogging(HCkHtmlToTextW cHandle, BOOL newVal);
void CkHtmlToTextW_getVersion(HCkHtmlToTextW cHandle, HCkString retval);
const wchar_t *CkHtmlToTextW_version(HCkHtmlToTextW cHandle);
BOOL CkHtmlToTextW_IsUnlocked(HCkHtmlToTextW cHandle);
BOOL CkHtmlToTextW_ReadFileToString(HCkHtmlToTextW cHandle, const wchar_t *filename, const wchar_t *srcCharset, HCkString outStr);
const wchar_t *CkHtmlToTextW_readFileToString(HCkHtmlToTextW cHandle, const wchar_t *filename, const wchar_t *srcCharset);
BOOL CkHtmlToTextW_SaveLastError(HCkHtmlToTextW cHandle, const wchar_t *path);
BOOL CkHtmlToTextW_ToText(HCkHtmlToTextW cHandle, const wchar_t *html, HCkString outStr);
const wchar_t *CkHtmlToTextW_toText(HCkHtmlToTextW cHandle, const wchar_t *html);
BOOL CkHtmlToTextW_UnlockComponent(HCkHtmlToTextW cHandle, const wchar_t *code);
BOOL CkHtmlToTextW_WriteStringToFile(HCkHtmlToTextW cHandle, const wchar_t *stringToWrite, const wchar_t *filename, const wchar_t *outpuCharset);
#endif
