// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCompression_H
#define _C_CkCompression_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCompression CkCompression_Create(void);
void CkCompression_Dispose(HCkCompression handle);
void CkCompression_getAlgorithm(HCkCompression cHandle, HCkString retval);
void CkCompression_putAlgorithm(HCkCompression cHandle, const char *newVal);
const char *CkCompression_algorithm(HCkCompression cHandle);
void CkCompression_getCharset(HCkCompression cHandle, HCkString retval);
void CkCompression_putCharset(HCkCompression cHandle, const char *newVal);
const char *CkCompression_charset(HCkCompression cHandle);
void CkCompression_getDebugLogFilePath(HCkCompression cHandle, HCkString retval);
void CkCompression_putDebugLogFilePath(HCkCompression cHandle, const char *newVal);
const char *CkCompression_debugLogFilePath(HCkCompression cHandle);
void CkCompression_getEncodingMode(HCkCompression cHandle, HCkString retval);
void CkCompression_putEncodingMode(HCkCompression cHandle, const char *newVal);
const char *CkCompression_encodingMode(HCkCompression cHandle);
int CkCompression_getHeartbeatMs(HCkCompression cHandle);
void CkCompression_putHeartbeatMs(HCkCompression cHandle, int newVal);
void CkCompression_getLastErrorHtml(HCkCompression cHandle, HCkString retval);
const char *CkCompression_lastErrorHtml(HCkCompression cHandle);
void CkCompression_getLastErrorText(HCkCompression cHandle, HCkString retval);
const char *CkCompression_lastErrorText(HCkCompression cHandle);
void CkCompression_getLastErrorXml(HCkCompression cHandle, HCkString retval);
const char *CkCompression_lastErrorXml(HCkCompression cHandle);
BOOL CkCompression_getUtf8(HCkCompression cHandle);
void CkCompression_putUtf8(HCkCompression cHandle, BOOL newVal);
BOOL CkCompression_getVerboseLogging(HCkCompression cHandle);
void CkCompression_putVerboseLogging(HCkCompression cHandle, BOOL newVal);
void CkCompression_getVersion(HCkCompression cHandle, HCkString retval);
const char *CkCompression_version(HCkCompression cHandle);
BOOL CkCompression_BeginCompressBytes(HCkCompression cHandle, HCkByteData data, HCkByteData outData);
BOOL CkCompression_BeginCompressBytesENC(HCkCompression cHandle, HCkByteData data, HCkString outStr);
const char *CkCompression_beginCompressBytesENC(HCkCompression cHandle, HCkByteData data);
BOOL CkCompression_BeginCompressString(HCkCompression cHandle, const char *str, HCkByteData outData);
BOOL CkCompression_BeginCompressStringENC(HCkCompression cHandle, const char *str, HCkString outStr);
const char *CkCompression_beginCompressStringENC(HCkCompression cHandle, const char *str);
BOOL CkCompression_BeginDecompressBytes(HCkCompression cHandle, HCkByteData data, HCkByteData outData);
BOOL CkCompression_BeginDecompressBytesENC(HCkCompression cHandle, const char *str, HCkByteData outData);
BOOL CkCompression_BeginDecompressString(HCkCompression cHandle, HCkByteData data, HCkString outStr);
const char *CkCompression_beginDecompressString(HCkCompression cHandle, HCkByteData data);
BOOL CkCompression_BeginDecompressStringENC(HCkCompression cHandle, const char *str, HCkString outStr);
const char *CkCompression_beginDecompressStringENC(HCkCompression cHandle, const char *str);
BOOL CkCompression_CompressBytes(HCkCompression cHandle, HCkByteData data, HCkByteData outData);
BOOL CkCompression_CompressBytesENC(HCkCompression cHandle, HCkByteData data, HCkString outStr);
const char *CkCompression_compressBytesENC(HCkCompression cHandle, HCkByteData data);
BOOL CkCompression_CompressFile(HCkCompression cHandle, const char *srcPath, const char *destPath);
BOOL CkCompression_CompressString(HCkCompression cHandle, const char *str, HCkByteData outData);
BOOL CkCompression_CompressStringENC(HCkCompression cHandle, const char *str, HCkString outStr);
const char *CkCompression_compressStringENC(HCkCompression cHandle, const char *str);
BOOL CkCompression_DecompressBytes(HCkCompression cHandle, HCkByteData data, HCkByteData outData);
BOOL CkCompression_DecompressBytesENC(HCkCompression cHandle, const char *encodedCompressedData, HCkByteData outData);
BOOL CkCompression_DecompressFile(HCkCompression cHandle, const char *srcPath, const char *destPath);
BOOL CkCompression_DecompressString(HCkCompression cHandle, HCkByteData data, HCkString outStr);
const char *CkCompression_decompressString(HCkCompression cHandle, HCkByteData data);
BOOL CkCompression_DecompressStringENC(HCkCompression cHandle, const char *encodedCompressedData, HCkString outStr);
const char *CkCompression_decompressStringENC(HCkCompression cHandle, const char *encodedCompressedData);
BOOL CkCompression_EndCompressBytes(HCkCompression cHandle, HCkByteData outData);
BOOL CkCompression_EndCompressBytesENC(HCkCompression cHandle, HCkString outStr);
const char *CkCompression_endCompressBytesENC(HCkCompression cHandle);
BOOL CkCompression_EndCompressString(HCkCompression cHandle, HCkByteData outData);
BOOL CkCompression_EndCompressStringENC(HCkCompression cHandle, HCkString outStr);
const char *CkCompression_endCompressStringENC(HCkCompression cHandle);
BOOL CkCompression_EndDecompressBytes(HCkCompression cHandle, HCkByteData outData);
BOOL CkCompression_EndDecompressBytesENC(HCkCompression cHandle, HCkByteData outData);
BOOL CkCompression_EndDecompressString(HCkCompression cHandle, HCkString outStr);
const char *CkCompression_endDecompressString(HCkCompression cHandle);
BOOL CkCompression_EndDecompressStringENC(HCkCompression cHandle, HCkString outStr);
const char *CkCompression_endDecompressStringENC(HCkCompression cHandle);
BOOL CkCompression_MoreCompressBytes(HCkCompression cHandle, HCkByteData data, HCkByteData outData);
BOOL CkCompression_MoreCompressBytesENC(HCkCompression cHandle, HCkByteData data, HCkString outStr);
const char *CkCompression_moreCompressBytesENC(HCkCompression cHandle, HCkByteData data);
BOOL CkCompression_MoreCompressString(HCkCompression cHandle, const char *str, HCkByteData outData);
BOOL CkCompression_MoreCompressStringENC(HCkCompression cHandle, const char *str, HCkString outStr);
const char *CkCompression_moreCompressStringENC(HCkCompression cHandle, const char *str);
BOOL CkCompression_MoreDecompressBytes(HCkCompression cHandle, HCkByteData data, HCkByteData outData);
BOOL CkCompression_MoreDecompressBytesENC(HCkCompression cHandle, const char *str, HCkByteData outData);
BOOL CkCompression_MoreDecompressString(HCkCompression cHandle, HCkByteData data, HCkString outStr);
const char *CkCompression_moreDecompressString(HCkCompression cHandle, HCkByteData data);
BOOL CkCompression_MoreDecompressStringENC(HCkCompression cHandle, const char *str, HCkString outStr);
const char *CkCompression_moreDecompressStringENC(HCkCompression cHandle, const char *str);
BOOL CkCompression_SaveLastError(HCkCompression cHandle, const char *path);
BOOL CkCompression_UnlockComponent(HCkCompression cHandle, const char *unlockCode);
#endif
