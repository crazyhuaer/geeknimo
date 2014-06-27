// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkGzipWH
#define _C_CkGzipWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkGzipW CkGzipW_Create(void);
HCkGzipW CkGzipW_Create2(BOOL bCallbackOwned);
void CkGzipW_Dispose(HCkGzipW handle);
void CkGzipW_getComment(HCkGzipW cHandle, HCkString retval);
void CkGzipW_putComment(HCkGzipW cHandle, const wchar_t *newVal);
const wchar_t *CkGzipW_comment(HCkGzipW cHandle);
void CkGzipW_getDebugLogFilePath(HCkGzipW cHandle, HCkString retval);
void CkGzipW_putDebugLogFilePath(HCkGzipW cHandle, const wchar_t *newVal);
const wchar_t *CkGzipW_debugLogFilePath(HCkGzipW cHandle);
void CkGzipW_getExtraData(HCkGzipW cHandle, HCkByteData retval);
void CkGzipW_putExtraData(HCkGzipW cHandle, HCkByteData  newVal);
void CkGzipW_getFilename(HCkGzipW cHandle, HCkString retval);
void CkGzipW_putFilename(HCkGzipW cHandle, const wchar_t *newVal);
const wchar_t *CkGzipW_filename(HCkGzipW cHandle);
int CkGzipW_getHeartbeatMs(HCkGzipW cHandle);
void CkGzipW_putHeartbeatMs(HCkGzipW cHandle, int newVal);
void CkGzipW_getLastErrorHtml(HCkGzipW cHandle, HCkString retval);
const wchar_t *CkGzipW_lastErrorHtml(HCkGzipW cHandle);
void CkGzipW_getLastErrorText(HCkGzipW cHandle, HCkString retval);
const wchar_t *CkGzipW_lastErrorText(HCkGzipW cHandle);
void CkGzipW_getLastErrorXml(HCkGzipW cHandle, HCkString retval);
const wchar_t *CkGzipW_lastErrorXml(HCkGzipW cHandle);
void CkGzipW_getLastMod(HCkGzipW cHandle, SYSTEMTIME *retval);
void CkGzipW_putLastMod(HCkGzipW cHandle, SYSTEMTIME *newVal);
void CkGzipW_getLastModStr(HCkGzipW cHandle, HCkString retval);
void CkGzipW_putLastModStr(HCkGzipW cHandle, const wchar_t *newVal);
const wchar_t *CkGzipW_lastModStr(HCkGzipW cHandle);
BOOL CkGzipW_getUseCurrentDate(HCkGzipW cHandle);
void CkGzipW_putUseCurrentDate(HCkGzipW cHandle, BOOL newVal);
BOOL CkGzipW_getVerboseLogging(HCkGzipW cHandle);
void CkGzipW_putVerboseLogging(HCkGzipW cHandle, BOOL newVal);
void CkGzipW_getVersion(HCkGzipW cHandle, HCkString retval);
const wchar_t *CkGzipW_version(HCkGzipW cHandle);
BOOL CkGzipW_CompressFile(HCkGzipW cHandle, const wchar_t *inFilename, const wchar_t *outGzipFilename);
BOOL CkGzipW_CompressFile2(HCkGzipW cHandle, const wchar_t *inFilename, const wchar_t *embeddedFilename, const wchar_t *outGzipFilename);
BOOL CkGzipW_CompressFileToMem(HCkGzipW cHandle, const wchar_t *inFilename, HCkByteData outData);
BOOL CkGzipW_CompressMemToFile(HCkGzipW cHandle, HCkByteData inData, const wchar_t *destPath);
BOOL CkGzipW_CompressMemory(HCkGzipW cHandle, HCkByteData inData, HCkByteData outData);
BOOL CkGzipW_CompressString(HCkGzipW cHandle, const wchar_t *inStr, const wchar_t *destCharset, HCkByteData outBytes);
BOOL CkGzipW_CompressStringENC(HCkGzipW cHandle, const wchar_t *inStr, const wchar_t *charset, const wchar_t *encoding, HCkString outStr);
const wchar_t *CkGzipW_compressStringENC(HCkGzipW cHandle, const wchar_t *inStr, const wchar_t *charset, const wchar_t *encoding);
BOOL CkGzipW_CompressStringToFile(HCkGzipW cHandle, const wchar_t *inStr, const wchar_t *destCharset, const wchar_t *destPath);
BOOL CkGzipW_Decode(HCkGzipW cHandle, const wchar_t *encodedStr, const wchar_t *encoding, HCkByteData outBytes);
BOOL CkGzipW_DeflateStringENC(HCkGzipW cHandle, const wchar_t *inString, const wchar_t *charsetName, const wchar_t *outputEncoding, HCkString outStr);
const wchar_t *CkGzipW_deflateStringENC(HCkGzipW cHandle, const wchar_t *inString, const wchar_t *charsetName, const wchar_t *outputEncoding);
BOOL CkGzipW_Encode(HCkGzipW cHandle, HCkByteData byteData, const wchar_t *encoding, HCkString outStr);
const wchar_t *CkGzipW_encode(HCkGzipW cHandle, HCkByteData byteData, const wchar_t *encoding);
BOOL CkGzipW_ExamineFile(HCkGzipW cHandle, const wchar_t *inGzFilename);
BOOL CkGzipW_ExamineMemory(HCkGzipW cHandle, HCkByteData inGzData);
HCkDateTimeW CkGzipW_GetDt(HCkGzipW cHandle);
BOOL CkGzipW_InflateStringENC(HCkGzipW cHandle, const wchar_t *inString, const wchar_t *convertFromCharset, const wchar_t *inputEncoding, HCkString outStr);
const wchar_t *CkGzipW_inflateStringENC(HCkGzipW cHandle, const wchar_t *inString, const wchar_t *convertFromCharset, const wchar_t *inputEncoding);
BOOL CkGzipW_IsUnlocked(HCkGzipW cHandle);
BOOL CkGzipW_ReadFile(HCkGzipW cHandle, const wchar_t *path, HCkByteData outBytes);
BOOL CkGzipW_SaveLastError(HCkGzipW cHandle, const wchar_t *path);
BOOL CkGzipW_SetDt(HCkGzipW cHandle, HCkDateTimeW dt);
BOOL CkGzipW_UnTarGz(HCkGzipW cHandle, const wchar_t *tgzFilename, const wchar_t *destDir, BOOL bNoAbsolute);
BOOL CkGzipW_UncompressFile(HCkGzipW cHandle, const wchar_t *srcPath, const wchar_t *destPath);
BOOL CkGzipW_UncompressFileToMem(HCkGzipW cHandle, const wchar_t *inFilename, HCkByteData outData);
BOOL CkGzipW_UncompressFileToString(HCkGzipW cHandle, const wchar_t *gzFilename, const wchar_t *charset, HCkString outStr);
const wchar_t *CkGzipW_uncompressFileToString(HCkGzipW cHandle, const wchar_t *gzFilename, const wchar_t *charset);
BOOL CkGzipW_UncompressMemToFile(HCkGzipW cHandle, HCkByteData inData, const wchar_t *destPath);
BOOL CkGzipW_UncompressMemory(HCkGzipW cHandle, HCkByteData inData, HCkByteData outData);
BOOL CkGzipW_UncompressString(HCkGzipW cHandle, HCkByteData inData, const wchar_t *inCharset, HCkString outStr);
const wchar_t *CkGzipW_uncompressString(HCkGzipW cHandle, HCkByteData inData, const wchar_t *inCharset);
BOOL CkGzipW_UncompressStringENC(HCkGzipW cHandle, const wchar_t *inStr, const wchar_t *charset, const wchar_t *encoding, HCkString outStr);
const wchar_t *CkGzipW_uncompressStringENC(HCkGzipW cHandle, const wchar_t *inStr, const wchar_t *charset, const wchar_t *encoding);
BOOL CkGzipW_UnlockComponent(HCkGzipW cHandle, const wchar_t *unlockCode);
BOOL CkGzipW_WriteFile(HCkGzipW cHandle, const wchar_t *path, HCkByteData binaryData);
BOOL CkGzipW_XfdlToXml(HCkGzipW cHandle, const wchar_t *xfldData, HCkString outStr);
const wchar_t *CkGzipW_xfdlToXml(HCkGzipW cHandle, const wchar_t *xfldData);
#endif
