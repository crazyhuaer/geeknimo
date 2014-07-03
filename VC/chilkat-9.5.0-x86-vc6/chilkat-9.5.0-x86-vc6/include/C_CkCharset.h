// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCharset_H
#define _C_CkCharset_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCharset CkCharset_Create(void);
void CkCharset_Dispose(HCkCharset handle);
void CkCharset_getAltToCharset(HCkCharset cHandle, HCkString retval);
void CkCharset_putAltToCharset(HCkCharset cHandle, const char *newVal);
const char *CkCharset_altToCharset(HCkCharset cHandle);
void CkCharset_getDebugLogFilePath(HCkCharset cHandle, HCkString retval);
void CkCharset_putDebugLogFilePath(HCkCharset cHandle, const char *newVal);
const char *CkCharset_debugLogFilePath(HCkCharset cHandle);
int CkCharset_getErrorAction(HCkCharset cHandle);
void CkCharset_putErrorAction(HCkCharset cHandle, int newVal);
void CkCharset_getFromCharset(HCkCharset cHandle, HCkString retval);
void CkCharset_putFromCharset(HCkCharset cHandle, const char *newVal);
const char *CkCharset_fromCharset(HCkCharset cHandle);
void CkCharset_getLastErrorHtml(HCkCharset cHandle, HCkString retval);
const char *CkCharset_lastErrorHtml(HCkCharset cHandle);
void CkCharset_getLastErrorText(HCkCharset cHandle, HCkString retval);
const char *CkCharset_lastErrorText(HCkCharset cHandle);
void CkCharset_getLastErrorXml(HCkCharset cHandle, HCkString retval);
const char *CkCharset_lastErrorXml(HCkCharset cHandle);
void CkCharset_getLastInputAsHex(HCkCharset cHandle, HCkString retval);
const char *CkCharset_lastInputAsHex(HCkCharset cHandle);
void CkCharset_getLastInputAsQP(HCkCharset cHandle, HCkString retval);
const char *CkCharset_lastInputAsQP(HCkCharset cHandle);
void CkCharset_getLastOutputAsHex(HCkCharset cHandle, HCkString retval);
const char *CkCharset_lastOutputAsHex(HCkCharset cHandle);
void CkCharset_getLastOutputAsQP(HCkCharset cHandle, HCkString retval);
const char *CkCharset_lastOutputAsQP(HCkCharset cHandle);
BOOL CkCharset_getSaveLast(HCkCharset cHandle);
void CkCharset_putSaveLast(HCkCharset cHandle, BOOL newVal);
void CkCharset_getToCharset(HCkCharset cHandle, HCkString retval);
void CkCharset_putToCharset(HCkCharset cHandle, const char *newVal);
const char *CkCharset_toCharset(HCkCharset cHandle);
BOOL CkCharset_getUtf8(HCkCharset cHandle);
void CkCharset_putUtf8(HCkCharset cHandle, BOOL newVal);
BOOL CkCharset_getVerboseLogging(HCkCharset cHandle);
void CkCharset_putVerboseLogging(HCkCharset cHandle, BOOL newVal);
void CkCharset_getVersion(HCkCharset cHandle, HCkString retval);
const char *CkCharset_version(HCkCharset cHandle);
int CkCharset_CharsetToCodePage(HCkCharset cHandle, const char *charsetName);
BOOL CkCharset_CodePageToCharset(HCkCharset cHandle, int codePage, HCkString outCharset);
const char *CkCharset_codePageToCharset(HCkCharset cHandle, int codePage);
BOOL CkCharset_ConvertData(HCkCharset cHandle, HCkByteData inData, HCkByteData outData);
BOOL CkCharset_ConvertFile(HCkCharset cHandle, const char *inPath, const char *outPath);
BOOL CkCharset_ConvertFileNoPreamble(HCkCharset cHandle, const char *inPath, const char *outPath);
BOOL CkCharset_ConvertFromUnicode(HCkCharset cHandle, const char *inData, HCkByteData outBytes);
BOOL CkCharset_ConvertFromUtf16(HCkCharset cHandle, HCkByteData uniData, HCkByteData outMbData);
BOOL CkCharset_ConvertHtml(HCkCharset cHandle, HCkByteData inData, HCkByteData outHtml);
BOOL CkCharset_ConvertHtmlFile(HCkCharset cHandle, const char *inPath, const char *outPath);
BOOL CkCharset_ConvertToUnicode(HCkCharset cHandle, HCkByteData inData, HCkString outStr);
const char *CkCharset_convertToUnicode(HCkCharset cHandle, HCkByteData inData);
BOOL CkCharset_ConvertToUtf16(HCkCharset cHandle, HCkByteData mbData, HCkByteData outUniData);
BOOL CkCharset_EntityEncodeDec(HCkCharset cHandle, const char *str, HCkString outStr);
const char *CkCharset_entityEncodeDec(HCkCharset cHandle, const char *str);
BOOL CkCharset_EntityEncodeHex(HCkCharset cHandle, const char *str, HCkString outStr);
const char *CkCharset_entityEncodeHex(HCkCharset cHandle, const char *str);
BOOL CkCharset_GetHtmlCharset(HCkCharset cHandle, HCkByteData inData, HCkString outCharset);
const char *CkCharset_getHtmlCharset(HCkCharset cHandle, HCkByteData inData);
BOOL CkCharset_GetHtmlFileCharset(HCkCharset cHandle, const char *htmlFilePath, HCkString outCharset);
const char *CkCharset_getHtmlFileCharset(HCkCharset cHandle, const char *htmlFilePath);
BOOL CkCharset_HtmlDecodeToStr(HCkCharset cHandle, const char *inStr, HCkString outStr);
const char *CkCharset_htmlDecodeToStr(HCkCharset cHandle, const char *inStr);
BOOL CkCharset_HtmlEntityDecode(HCkCharset cHandle, HCkByteData inHtml, HCkByteData outData);
BOOL CkCharset_HtmlEntityDecodeFile(HCkCharset cHandle, const char *inPath, const char *outPath);
BOOL CkCharset_IsUnlocked(HCkCharset cHandle);
BOOL CkCharset_LowerCase(HCkCharset cHandle, const char *inStr, HCkString outStr);
const char *CkCharset_lowerCase(HCkCharset cHandle, const char *inStr);
BOOL CkCharset_ReadFile(HCkCharset cHandle, const char *path, HCkByteData outData);
BOOL CkCharset_ReadFileToString(HCkCharset cHandle, const char *path, const char *charset, HCkString outStr);
const char *CkCharset_readFileToString(HCkCharset cHandle, const char *path, const char *charset);
BOOL CkCharset_SaveLastError(HCkCharset cHandle, const char *path);
void CkCharset_SetErrorBytes(HCkCharset cHandle, HCkByteData data);
void CkCharset_SetErrorString(HCkCharset cHandle, const char *str, const char *charset);
BOOL CkCharset_UnlockComponent(HCkCharset cHandle, const char *unlockCode);
BOOL CkCharset_UpperCase(HCkCharset cHandle, const char *inStr, HCkString outStr);
const char *CkCharset_upperCase(HCkCharset cHandle, const char *inStr);
BOOL CkCharset_UrlDecodeStr(HCkCharset cHandle, const char *inStr, HCkString outStr);
const char *CkCharset_urlDecodeStr(HCkCharset cHandle, const char *inStr);
BOOL CkCharset_VerifyData(HCkCharset cHandle, const char *charset, HCkByteData inData);
BOOL CkCharset_VerifyFile(HCkCharset cHandle, const char *charset, const char *path);
BOOL CkCharset_WriteFile(HCkCharset cHandle, const char *path, HCkByteData byteData);
BOOL CkCharset_WriteStringToFile(HCkCharset cHandle, const char *textData, const char *path, const char *charset);
#endif
