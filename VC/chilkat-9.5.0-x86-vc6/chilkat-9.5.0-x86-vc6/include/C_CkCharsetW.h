// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCharsetWH
#define _C_CkCharsetWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCharsetW CkCharsetW_Create(void);
void CkCharsetW_Dispose(HCkCharsetW handle);
void CkCharsetW_getAltToCharset(HCkCharsetW cHandle, HCkString retval);
void CkCharsetW_putAltToCharset(HCkCharsetW cHandle, const wchar_t *newVal);
const wchar_t *CkCharsetW_altToCharset(HCkCharsetW cHandle);
void CkCharsetW_getDebugLogFilePath(HCkCharsetW cHandle, HCkString retval);
void CkCharsetW_putDebugLogFilePath(HCkCharsetW cHandle, const wchar_t *newVal);
const wchar_t *CkCharsetW_debugLogFilePath(HCkCharsetW cHandle);
int CkCharsetW_getErrorAction(HCkCharsetW cHandle);
void CkCharsetW_putErrorAction(HCkCharsetW cHandle, int newVal);
void CkCharsetW_getFromCharset(HCkCharsetW cHandle, HCkString retval);
void CkCharsetW_putFromCharset(HCkCharsetW cHandle, const wchar_t *newVal);
const wchar_t *CkCharsetW_fromCharset(HCkCharsetW cHandle);
void CkCharsetW_getLastErrorHtml(HCkCharsetW cHandle, HCkString retval);
const wchar_t *CkCharsetW_lastErrorHtml(HCkCharsetW cHandle);
void CkCharsetW_getLastErrorText(HCkCharsetW cHandle, HCkString retval);
const wchar_t *CkCharsetW_lastErrorText(HCkCharsetW cHandle);
void CkCharsetW_getLastErrorXml(HCkCharsetW cHandle, HCkString retval);
const wchar_t *CkCharsetW_lastErrorXml(HCkCharsetW cHandle);
void CkCharsetW_getLastInputAsHex(HCkCharsetW cHandle, HCkString retval);
const wchar_t *CkCharsetW_lastInputAsHex(HCkCharsetW cHandle);
void CkCharsetW_getLastInputAsQP(HCkCharsetW cHandle, HCkString retval);
const wchar_t *CkCharsetW_lastInputAsQP(HCkCharsetW cHandle);
void CkCharsetW_getLastOutputAsHex(HCkCharsetW cHandle, HCkString retval);
const wchar_t *CkCharsetW_lastOutputAsHex(HCkCharsetW cHandle);
void CkCharsetW_getLastOutputAsQP(HCkCharsetW cHandle, HCkString retval);
const wchar_t *CkCharsetW_lastOutputAsQP(HCkCharsetW cHandle);
BOOL CkCharsetW_getSaveLast(HCkCharsetW cHandle);
void CkCharsetW_putSaveLast(HCkCharsetW cHandle, BOOL newVal);
void CkCharsetW_getToCharset(HCkCharsetW cHandle, HCkString retval);
void CkCharsetW_putToCharset(HCkCharsetW cHandle, const wchar_t *newVal);
const wchar_t *CkCharsetW_toCharset(HCkCharsetW cHandle);
BOOL CkCharsetW_getVerboseLogging(HCkCharsetW cHandle);
void CkCharsetW_putVerboseLogging(HCkCharsetW cHandle, BOOL newVal);
void CkCharsetW_getVersion(HCkCharsetW cHandle, HCkString retval);
const wchar_t *CkCharsetW_version(HCkCharsetW cHandle);
int CkCharsetW_CharsetToCodePage(HCkCharsetW cHandle, const wchar_t *charsetName);
BOOL CkCharsetW_CodePageToCharset(HCkCharsetW cHandle, int codePage, HCkString outCharset);
const wchar_t *CkCharsetW_codePageToCharset(HCkCharsetW cHandle, int codePage);
BOOL CkCharsetW_ConvertData(HCkCharsetW cHandle, HCkByteData inData, HCkByteData outData);
BOOL CkCharsetW_ConvertFile(HCkCharsetW cHandle, const wchar_t *inPath, const wchar_t *outPath);
BOOL CkCharsetW_ConvertFileNoPreamble(HCkCharsetW cHandle, const wchar_t *inPath, const wchar_t *outPath);
BOOL CkCharsetW_ConvertFromUnicode(HCkCharsetW cHandle, const wchar_t *inData, HCkByteData outBytes);
BOOL CkCharsetW_ConvertFromUtf16(HCkCharsetW cHandle, HCkByteData uniData, HCkByteData outMbData);
BOOL CkCharsetW_ConvertHtml(HCkCharsetW cHandle, HCkByteData inData, HCkByteData outHtml);
BOOL CkCharsetW_ConvertHtmlFile(HCkCharsetW cHandle, const wchar_t *inPath, const wchar_t *outPath);
BOOL CkCharsetW_ConvertToUnicode(HCkCharsetW cHandle, HCkByteData inData, HCkString outStr);
const wchar_t *CkCharsetW_convertToUnicode(HCkCharsetW cHandle, HCkByteData inData);
BOOL CkCharsetW_ConvertToUtf16(HCkCharsetW cHandle, HCkByteData mbData, HCkByteData outUniData);
BOOL CkCharsetW_EntityEncodeDec(HCkCharsetW cHandle, const wchar_t *str, HCkString outStr);
const wchar_t *CkCharsetW_entityEncodeDec(HCkCharsetW cHandle, const wchar_t *str);
BOOL CkCharsetW_EntityEncodeHex(HCkCharsetW cHandle, const wchar_t *str, HCkString outStr);
const wchar_t *CkCharsetW_entityEncodeHex(HCkCharsetW cHandle, const wchar_t *str);
BOOL CkCharsetW_GetHtmlCharset(HCkCharsetW cHandle, HCkByteData inData, HCkString outCharset);
const wchar_t *CkCharsetW_getHtmlCharset(HCkCharsetW cHandle, HCkByteData inData);
BOOL CkCharsetW_GetHtmlFileCharset(HCkCharsetW cHandle, const wchar_t *htmlFilePath, HCkString outCharset);
const wchar_t *CkCharsetW_getHtmlFileCharset(HCkCharsetW cHandle, const wchar_t *htmlFilePath);
BOOL CkCharsetW_HtmlDecodeToStr(HCkCharsetW cHandle, const wchar_t *inStr, HCkString outStr);
const wchar_t *CkCharsetW_htmlDecodeToStr(HCkCharsetW cHandle, const wchar_t *inStr);
BOOL CkCharsetW_HtmlEntityDecode(HCkCharsetW cHandle, HCkByteData inHtml, HCkByteData outData);
BOOL CkCharsetW_HtmlEntityDecodeFile(HCkCharsetW cHandle, const wchar_t *inPath, const wchar_t *outPath);
BOOL CkCharsetW_IsUnlocked(HCkCharsetW cHandle);
BOOL CkCharsetW_LowerCase(HCkCharsetW cHandle, const wchar_t *inStr, HCkString outStr);
const wchar_t *CkCharsetW_lowerCase(HCkCharsetW cHandle, const wchar_t *inStr);
BOOL CkCharsetW_ReadFile(HCkCharsetW cHandle, const wchar_t *path, HCkByteData outData);
BOOL CkCharsetW_ReadFileToString(HCkCharsetW cHandle, const wchar_t *path, const wchar_t *charset, HCkString outStr);
const wchar_t *CkCharsetW_readFileToString(HCkCharsetW cHandle, const wchar_t *path, const wchar_t *charset);
BOOL CkCharsetW_SaveLastError(HCkCharsetW cHandle, const wchar_t *path);
void CkCharsetW_SetErrorBytes(HCkCharsetW cHandle, HCkByteData data);
void CkCharsetW_SetErrorString(HCkCharsetW cHandle, const wchar_t *str, const wchar_t *charset);
BOOL CkCharsetW_UnlockComponent(HCkCharsetW cHandle, const wchar_t *unlockCode);
BOOL CkCharsetW_UpperCase(HCkCharsetW cHandle, const wchar_t *inStr, HCkString outStr);
const wchar_t *CkCharsetW_upperCase(HCkCharsetW cHandle, const wchar_t *inStr);
BOOL CkCharsetW_UrlDecodeStr(HCkCharsetW cHandle, const wchar_t *inStr, HCkString outStr);
const wchar_t *CkCharsetW_urlDecodeStr(HCkCharsetW cHandle, const wchar_t *inStr);
BOOL CkCharsetW_VerifyData(HCkCharsetW cHandle, const wchar_t *charset, HCkByteData inData);
BOOL CkCharsetW_VerifyFile(HCkCharsetW cHandle, const wchar_t *charset, const wchar_t *path);
BOOL CkCharsetW_WriteFile(HCkCharsetW cHandle, const wchar_t *path, HCkByteData byteData);
BOOL CkCharsetW_WriteStringToFile(HCkCharsetW cHandle, const wchar_t *textData, const wchar_t *path, const wchar_t *charset);
#endif
