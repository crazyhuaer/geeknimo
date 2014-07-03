// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkHtmlToXml_H
#define _C_CkHtmlToXml_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkHtmlToXml CkHtmlToXml_Create(void);
void CkHtmlToXml_Dispose(HCkHtmlToXml handle);
void CkHtmlToXml_getDebugLogFilePath(HCkHtmlToXml cHandle, HCkString retval);
void CkHtmlToXml_putDebugLogFilePath(HCkHtmlToXml cHandle, const char *newVal);
const char *CkHtmlToXml_debugLogFilePath(HCkHtmlToXml cHandle);
BOOL CkHtmlToXml_getDropCustomTags(HCkHtmlToXml cHandle);
void CkHtmlToXml_putDropCustomTags(HCkHtmlToXml cHandle, BOOL newVal);
void CkHtmlToXml_getHtml(HCkHtmlToXml cHandle, HCkString retval);
void CkHtmlToXml_putHtml(HCkHtmlToXml cHandle, const char *newVal);
const char *CkHtmlToXml_html(HCkHtmlToXml cHandle);
void CkHtmlToXml_getLastErrorHtml(HCkHtmlToXml cHandle, HCkString retval);
const char *CkHtmlToXml_lastErrorHtml(HCkHtmlToXml cHandle);
void CkHtmlToXml_getLastErrorText(HCkHtmlToXml cHandle, HCkString retval);
const char *CkHtmlToXml_lastErrorText(HCkHtmlToXml cHandle);
void CkHtmlToXml_getLastErrorXml(HCkHtmlToXml cHandle, HCkString retval);
const char *CkHtmlToXml_lastErrorXml(HCkHtmlToXml cHandle);
int CkHtmlToXml_getNbsp(HCkHtmlToXml cHandle);
void CkHtmlToXml_putNbsp(HCkHtmlToXml cHandle, int newVal);
BOOL CkHtmlToXml_getUtf8(HCkHtmlToXml cHandle);
void CkHtmlToXml_putUtf8(HCkHtmlToXml cHandle, BOOL newVal);
BOOL CkHtmlToXml_getVerboseLogging(HCkHtmlToXml cHandle);
void CkHtmlToXml_putVerboseLogging(HCkHtmlToXml cHandle, BOOL newVal);
void CkHtmlToXml_getVersion(HCkHtmlToXml cHandle, HCkString retval);
const char *CkHtmlToXml_version(HCkHtmlToXml cHandle);
void CkHtmlToXml_getXmlCharset(HCkHtmlToXml cHandle, HCkString retval);
void CkHtmlToXml_putXmlCharset(HCkHtmlToXml cHandle, const char *newVal);
const char *CkHtmlToXml_xmlCharset(HCkHtmlToXml cHandle);
BOOL CkHtmlToXml_ConvertFile(HCkHtmlToXml cHandle, const char *inHtmlPath, const char *destXmlPath);
void CkHtmlToXml_DropTagType(HCkHtmlToXml cHandle, const char *tagName);
void CkHtmlToXml_DropTextFormattingTags(HCkHtmlToXml cHandle);
BOOL CkHtmlToXml_IsUnlocked(HCkHtmlToXml cHandle);
BOOL CkHtmlToXml_ReadFile(HCkHtmlToXml cHandle, const char *path, HCkByteData outBytes);
BOOL CkHtmlToXml_ReadFileToString(HCkHtmlToXml cHandle, const char *filename, const char *srcCharset, HCkString outStr);
const char *CkHtmlToXml_readFileToString(HCkHtmlToXml cHandle, const char *filename, const char *srcCharset);
BOOL CkHtmlToXml_SaveLastError(HCkHtmlToXml cHandle, const char *path);
void CkHtmlToXml_SetHtmlBytes(HCkHtmlToXml cHandle, HCkByteData inData);
BOOL CkHtmlToXml_SetHtmlFromFile(HCkHtmlToXml cHandle, const char *filename);
BOOL CkHtmlToXml_ToXml(HCkHtmlToXml cHandle, HCkString outStr);
const char *CkHtmlToXml_toXml(HCkHtmlToXml cHandle);
void CkHtmlToXml_UndropTagType(HCkHtmlToXml cHandle, const char *tagName);
void CkHtmlToXml_UndropTextFormattingTags(HCkHtmlToXml cHandle);
BOOL CkHtmlToXml_UnlockComponent(HCkHtmlToXml cHandle, const char *unlockCode);
BOOL CkHtmlToXml_WriteFile(HCkHtmlToXml cHandle, const char *path, HCkByteData fileData);
BOOL CkHtmlToXml_WriteStringToFile(HCkHtmlToXml cHandle, const char *stringToWrite, const char *filename, const char *outpuCharset);
BOOL CkHtmlToXml_Xml(HCkHtmlToXml cHandle, HCkString outStr);
const char *CkHtmlToXml_xml(HCkHtmlToXml cHandle);
#endif
