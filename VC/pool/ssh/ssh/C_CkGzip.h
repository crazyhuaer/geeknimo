// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkGzip_H
#define _C_CkGzip_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkGzip CkGzip_Create(void);
void CkGzip_Dispose(HCkGzip handle);
void CkGzip_getComment(HCkGzip cHandle, HCkString retval);
void CkGzip_putComment(HCkGzip cHandle, const char *newVal);
const char *CkGzip_comment(HCkGzip cHandle);
void CkGzip_getDebugLogFilePath(HCkGzip cHandle, HCkString retval);
void CkGzip_putDebugLogFilePath(HCkGzip cHandle, const char *newVal);
const char *CkGzip_debugLogFilePath(HCkGzip cHandle);
void CkGzip_getExtraData(HCkGzip cHandle, HCkByteData retval);
void CkGzip_putExtraData(HCkGzip cHandle, HCkByteData  newVal);
void CkGzip_getFilename(HCkGzip cHandle, HCkString retval);
void CkGzip_putFilename(HCkGzip cHandle, const char *newVal);
const char *CkGzip_filename(HCkGzip cHandle);
int CkGzip_getHeartbeatMs(HCkGzip cHandle);
void CkGzip_putHeartbeatMs(HCkGzip cHandle, int newVal);
void CkGzip_getLastErrorHtml(HCkGzip cHandle, HCkString retval);
const char *CkGzip_lastErrorHtml(HCkGzip cHandle);
void CkGzip_getLastErrorText(HCkGzip cHandle, HCkString retval);
const char *CkGzip_lastErrorText(HCkGzip cHandle);
void CkGzip_getLastErrorXml(HCkGzip cHandle, HCkString retval);
const char *CkGzip_lastErrorXml(HCkGzip cHandle);
void CkGzip_getLastMod(HCkGzip cHandle, SYSTEMTIME *retval);
void CkGzip_putLastMod(HCkGzip cHandle, SYSTEMTIME *newVal);
void CkGzip_getLastModStr(HCkGzip cHandle, HCkString retval);
void CkGzip_putLastModStr(HCkGzip cHandle, const char *newVal);
const char *CkGzip_lastModStr(HCkGzip cHandle);
BOOL CkGzip_getUseCurrentDate(HCkGzip cHandle);
void CkGzip_putUseCurrentDate(HCkGzip cHandle, BOOL newVal);
BOOL CkGzip_getUtf8(HCkGzip cHandle);
void CkGzip_putUtf8(HCkGzip cHandle, BOOL newVal);
BOOL CkGzip_getVerboseLogging(HCkGzip cHandle);
void CkGzip_putVerboseLogging(HCkGzip cHandle, BOOL newVal);
void CkGzip_getVersion(HCkGzip cHandle, HCkString retval);
const char *CkGzip_version(HCkGzip cHandle);
BOOL CkGzip_CompressFile(HCkGzip cHandle, const char *inFilename, const char *outGzipFilename);
BOOL CkGzip_CompressFile2(HCkGzip cHandle, const char *inFilename, const char *embeddedFilename, const char *outGzipFilename);
BOOL CkGzip_CompressFileToMem(HCkGzip cHandle, const char *inFilename, HCkByteData outData);
BOOL CkGzip_CompressMemToFile(HCkGzip cHandle, HCkByteData inData, const char *destPath);
BOOL CkGzip_CompressMemory(HCkGzip cHandle, HCkByteData inData, HCkByteData outData);
BOOL CkGzip_CompressString(HCkGzip cHandle, const char *inStr, const char *destCharset, HCkByteData outBytes);
BOOL CkGzip_CompressStringENC(HCkGzip cHandle, const char *inStr, const char *charset, const char *encoding, HCkString outStr);
const char *CkGzip_compressStringENC(HCkGzip cHandle, const char *inStr, const char *charset, const char *encoding);
BOOL CkGzip_CompressStringToFile(HCkGzip cHandle, const char *inStr, const char *destCharset, const char *destPath);
BOOL CkGzip_Decode(HCkGzip cHandle, const char *encodedStr, const char *encoding, HCkByteData outBytes);
BOOL CkGzip_DeflateStringENC(HCkGzip cHandle, const char *inString, const char *charsetName, const char *outputEncoding, HCkString outStr);
const char *CkGzip_deflateStringENC(HCkGzip cHandle, const char *inString, const char *charsetName, const char *outputEncoding);
BOOL CkGzip_Encode(HCkGzip cHandle, HCkByteData byteData, const char *encoding, HCkString outStr);
const char *CkGzip_encode(HCkGzip cHandle, HCkByteData byteData, const char *encoding);
BOOL CkGzip_ExamineFile(HCkGzip cHandle, const char *inGzFilename);
BOOL CkGzip_ExamineMemory(HCkGzip cHandle, HCkByteData inGzData);
HCkDateTime CkGzip_GetDt(HCkGzip cHandle);
BOOL CkGzip_InflateStringENC(HCkGzip cHandle, const char *inString, const char *convertFromCharset, const char *inputEncoding, HCkString outStr);
const char *CkGzip_inflateStringENC(HCkGzip cHandle, const char *inString, const char *convertFromCharset, const char *inputEncoding);
BOOL CkGzip_IsUnlocked(HCkGzip cHandle);
BOOL CkGzip_ReadFile(HCkGzip cHandle, const char *path, HCkByteData outBytes);
BOOL CkGzip_SaveLastError(HCkGzip cHandle, const char *path);
BOOL CkGzip_SetDt(HCkGzip cHandle, HCkDateTime dt);
BOOL CkGzip_UnTarGz(HCkGzip cHandle, const char *tgzFilename, const char *destDir, BOOL bNoAbsolute);
BOOL CkGzip_UncompressFile(HCkGzip cHandle, const char *srcPath, const char *destPath);
BOOL CkGzip_UncompressFileToMem(HCkGzip cHandle, const char *inFilename, HCkByteData outData);
BOOL CkGzip_UncompressFileToString(HCkGzip cHandle, const char *gzFilename, const char *charset, HCkString outStr);
const char *CkGzip_uncompressFileToString(HCkGzip cHandle, const char *gzFilename, const char *charset);
BOOL CkGzip_UncompressMemToFile(HCkGzip cHandle, HCkByteData inData, const char *destPath);
BOOL CkGzip_UncompressMemory(HCkGzip cHandle, HCkByteData inData, HCkByteData outData);
BOOL CkGzip_UncompressString(HCkGzip cHandle, HCkByteData inData, const char *inCharset, HCkString outStr);
const char *CkGzip_uncompressString(HCkGzip cHandle, HCkByteData inData, const char *inCharset);
BOOL CkGzip_UncompressStringENC(HCkGzip cHandle, const char *inStr, const char *charset, const char *encoding, HCkString outStr);
const char *CkGzip_uncompressStringENC(HCkGzip cHandle, const char *inStr, const char *charset, const char *encoding);
BOOL CkGzip_UnlockComponent(HCkGzip cHandle, const char *unlockCode);
BOOL CkGzip_WriteFile(HCkGzip cHandle, const char *path, HCkByteData binaryData);
BOOL CkGzip_XfdlToXml(HCkGzip cHandle, const char *xfldData, HCkString outStr);
const char *CkGzip_xfdlToXml(HCkGzip cHandle, const char *xfldData);
#endif
