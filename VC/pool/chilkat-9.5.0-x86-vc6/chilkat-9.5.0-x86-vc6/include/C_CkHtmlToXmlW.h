// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkHtmlToXmlWH
#define _C_CkHtmlToXmlWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkHtmlToXmlW CkHtmlToXmlW_Create(void);
void CkHtmlToXmlW_Dispose(HCkHtmlToXmlW handle);
void CkHtmlToXmlW_getDebugLogFilePath(HCkHtmlToXmlW cHandle, HCkString retval);
void CkHtmlToXmlW_putDebugLogFilePath(HCkHtmlToXmlW cHandle, const wchar_t *newVal);
const wchar_t *CkHtmlToXmlW_debugLogFilePath(HCkHtmlToXmlW cHandle);
BOOL CkHtmlToXmlW_getDropCustomTags(HCkHtmlToXmlW cHandle);
void CkHtmlToXmlW_putDropCustomTags(HCkHtmlToXmlW cHandle, BOOL newVal);
void CkHtmlToXmlW_getHtml(HCkHtmlToXmlW cHandle, HCkString retval);
void CkHtmlToXmlW_putHtml(HCkHtmlToXmlW cHandle, const wchar_t *newVal);
const wchar_t *CkHtmlToXmlW_html(HCkHtmlToXmlW cHandle);
void CkHtmlToXmlW_getLastErrorHtml(HCkHtmlToXmlW cHandle, HCkString retval);
const wchar_t *CkHtmlToXmlW_lastErrorHtml(HCkHtmlToXmlW cHandle);
void CkHtmlToXmlW_getLastErrorText(HCkHtmlToXmlW cHandle, HCkString retval);
const wchar_t *CkHtmlToXmlW_lastErrorText(HCkHtmlToXmlW cHandle);
void CkHtmlToXmlW_getLastErrorXml(HCkHtmlToXmlW cHandle, HCkString retval);
const wchar_t *CkHtmlToXmlW_lastErrorXml(HCkHtmlToXmlW cHandle);
int CkHtmlToXmlW_getNbsp(HCkHtmlToXmlW cHandle);
void CkHtmlToXmlW_putNbsp(HCkHtmlToXmlW cHandle, int newVal);
BOOL CkHtmlToXmlW_getVerboseLogging(HCkHtmlToXmlW cHandle);
void CkHtmlToXmlW_putVerboseLogging(HCkHtmlToXmlW cHandle, BOOL newVal);
void CkHtmlToXmlW_getVersion(HCkHtmlToXmlW cHandle, HCkString retval);
const wchar_t *CkHtmlToXmlW_version(HCkHtmlToXmlW cHandle);
void CkHtmlToXmlW_getXmlCharset(HCkHtmlToXmlW cHandle, HCkString retval);
void CkHtmlToXmlW_putXmlCharset(HCkHtmlToXmlW cHandle, const wchar_t *newVal);
const wchar_t *CkHtmlToXmlW_xmlCharset(HCkHtmlToXmlW cHandle);
BOOL CkHtmlToXmlW_ConvertFile(HCkHtmlToXmlW cHandle, const wchar_t *inHtmlPath, const wchar_t *destXmlPath);
void CkHtmlToXmlW_DropTagType(HCkHtmlToXmlW cHandle, const wchar_t *tagName);
void CkHtmlToXmlW_DropTextFormattingTags(HCkHtmlToXmlW cHandle);
BOOL CkHtmlToXmlW_IsUnlocked(HCkHtmlToXmlW cHandle);
BOOL CkHtmlToXmlW_ReadFile(HCkHtmlToXmlW cHandle, const wchar_t *path, HCkByteData outBytes);
BOOL CkHtmlToXmlW_ReadFileToString(HCkHtmlToXmlW cHandle, const wchar_t *filename, const wchar_t *srcCharset, HCkString outStr);
const wchar_t *CkHtmlToXmlW_readFileToString(HCkHtmlToXmlW cHandle, const wchar_t *filename, const wchar_t *srcCharset);
BOOL CkHtmlToXmlW_SaveLastError(HCkHtmlToXmlW cHandle, const wchar_t *path);
void CkHtmlToXmlW_SetHtmlBytes(HCkHtmlToXmlW cHandle, HCkByteData inData);
BOOL CkHtmlToXmlW_SetHtmlFromFile(HCkHtmlToXmlW cHandle, const wchar_t *filename);
BOOL CkHtmlToXmlW_ToXml(HCkHtmlToXmlW cHandle, HCkString outStr);
const wchar_t *CkHtmlToXmlW_toXml(HCkHtmlToXmlW cHandle);
void CkHtmlToXmlW_UndropTagType(HCkHtmlToXmlW cHandle, const wchar_t *tagName);
void CkHtmlToXmlW_UndropTextFormattingTags(HCkHtmlToXmlW cHandle);
BOOL CkHtmlToXmlW_UnlockComponent(HCkHtmlToXmlW cHandle, const wchar_t *unlockCode);
BOOL CkHtmlToXmlW_WriteFile(HCkHtmlToXmlW cHandle, const wchar_t *path, HCkByteData fileData);
BOOL CkHtmlToXmlW_WriteStringToFile(HCkHtmlToXmlW cHandle, const wchar_t *stringToWrite, const wchar_t *filename, const wchar_t *outpuCharset);
BOOL CkHtmlToXmlW_Xml(HCkHtmlToXmlW cHandle, HCkString outStr);
const wchar_t *CkHtmlToXmlW_xml(HCkHtmlToXmlW cHandle);
#endif
