// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCompressionWH
#define _C_CkCompressionWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCompressionW CkCompressionW_Create(void);
HCkCompressionW CkCompressionW_Create2(BOOL bCallbackOwned);
void CkCompressionW_Dispose(HCkCompressionW handle);
void CkCompressionW_getAlgorithm(HCkCompressionW cHandle, HCkString retval);
void CkCompressionW_putAlgorithm(HCkCompressionW cHandle, const wchar_t *newVal);
const wchar_t *CkCompressionW_algorithm(HCkCompressionW cHandle);
void CkCompressionW_getCharset(HCkCompressionW cHandle, HCkString retval);
void CkCompressionW_putCharset(HCkCompressionW cHandle, const wchar_t *newVal);
const wchar_t *CkCompressionW_charset(HCkCompressionW cHandle);
void CkCompressionW_getDebugLogFilePath(HCkCompressionW cHandle, HCkString retval);
void CkCompressionW_putDebugLogFilePath(HCkCompressionW cHandle, const wchar_t *newVal);
const wchar_t *CkCompressionW_debugLogFilePath(HCkCompressionW cHandle);
void CkCompressionW_getEncodingMode(HCkCompressionW cHandle, HCkString retval);
void CkCompressionW_putEncodingMode(HCkCompressionW cHandle, const wchar_t *newVal);
const wchar_t *CkCompressionW_encodingMode(HCkCompressionW cHandle);
int CkCompressionW_getHeartbeatMs(HCkCompressionW cHandle);
void CkCompressionW_putHeartbeatMs(HCkCompressionW cHandle, int newVal);
void CkCompressionW_getLastErrorHtml(HCkCompressionW cHandle, HCkString retval);
const wchar_t *CkCompressionW_lastErrorHtml(HCkCompressionW cHandle);
void CkCompressionW_getLastErrorText(HCkCompressionW cHandle, HCkString retval);
const wchar_t *CkCompressionW_lastErrorText(HCkCompressionW cHandle);
void CkCompressionW_getLastErrorXml(HCkCompressionW cHandle, HCkString retval);
const wchar_t *CkCompressionW_lastErrorXml(HCkCompressionW cHandle);
BOOL CkCompressionW_getVerboseLogging(HCkCompressionW cHandle);
void CkCompressionW_putVerboseLogging(HCkCompressionW cHandle, BOOL newVal);
void CkCompressionW_getVersion(HCkCompressionW cHandle, HCkString retval);
const wchar_t *CkCompressionW_version(HCkCompressionW cHandle);
BOOL CkCompressionW_BeginCompressBytes(HCkCompressionW cHandle, HCkByteData data, HCkByteData outData);
BOOL CkCompressionW_BeginCompressBytesENC(HCkCompressionW cHandle, HCkByteData data, HCkString outStr);
const wchar_t *CkCompressionW_beginCompressBytesENC(HCkCompressionW cHandle, HCkByteData data);
BOOL CkCompressionW_BeginCompressString(HCkCompressionW cHandle, const wchar_t *str, HCkByteData outData);
BOOL CkCompressionW_BeginCompressStringENC(HCkCompressionW cHandle, const wchar_t *str, HCkString outStr);
const wchar_t *CkCompressionW_beginCompressStringENC(HCkCompressionW cHandle, const wchar_t *str);
BOOL CkCompressionW_BeginDecompressBytes(HCkCompressionW cHandle, HCkByteData data, HCkByteData outData);
BOOL CkCompressionW_BeginDecompressBytesENC(HCkCompressionW cHandle, const wchar_t *str, HCkByteData outData);
BOOL CkCompressionW_BeginDecompressString(HCkCompressionW cHandle, HCkByteData data, HCkString outStr);
const wchar_t *CkCompressionW_beginDecompressString(HCkCompressionW cHandle, HCkByteData data);
BOOL CkCompressionW_BeginDecompressStringENC(HCkCompressionW cHandle, const wchar_t *str, HCkString outStr);
const wchar_t *CkCompressionW_beginDecompressStringENC(HCkCompressionW cHandle, const wchar_t *str);
BOOL CkCompressionW_CompressBytes(HCkCompressionW cHandle, HCkByteData data, HCkByteData outData);
BOOL CkCompressionW_CompressBytesENC(HCkCompressionW cHandle, HCkByteData data, HCkString outStr);
const wchar_t *CkCompressionW_compressBytesENC(HCkCompressionW cHandle, HCkByteData data);
BOOL CkCompressionW_CompressFile(HCkCompressionW cHandle, const wchar_t *srcPath, const wchar_t *destPath);
BOOL CkCompressionW_CompressString(HCkCompressionW cHandle, const wchar_t *str, HCkByteData outData);
BOOL CkCompressionW_CompressStringENC(HCkCompressionW cHandle, const wchar_t *str, HCkString outStr);
const wchar_t *CkCompressionW_compressStringENC(HCkCompressionW cHandle, const wchar_t *str);
BOOL CkCompressionW_DecompressBytes(HCkCompressionW cHandle, HCkByteData data, HCkByteData outData);
BOOL CkCompressionW_DecompressBytesENC(HCkCompressionW cHandle, const wchar_t *encodedCompressedData, HCkByteData outData);
BOOL CkCompressionW_DecompressFile(HCkCompressionW cHandle, const wchar_t *srcPath, const wchar_t *destPath);
BOOL CkCompressionW_DecompressString(HCkCompressionW cHandle, HCkByteData data, HCkString outStr);
const wchar_t *CkCompressionW_decompressString(HCkCompressionW cHandle, HCkByteData data);
BOOL CkCompressionW_DecompressStringENC(HCkCompressionW cHandle, const wchar_t *encodedCompressedData, HCkString outStr);
const wchar_t *CkCompressionW_decompressStringENC(HCkCompressionW cHandle, const wchar_t *encodedCompressedData);
BOOL CkCompressionW_EndCompressBytes(HCkCompressionW cHandle, HCkByteData outData);
BOOL CkCompressionW_EndCompressBytesENC(HCkCompressionW cHandle, HCkString outStr);
const wchar_t *CkCompressionW_endCompressBytesENC(HCkCompressionW cHandle);
BOOL CkCompressionW_EndCompressString(HCkCompressionW cHandle, HCkByteData outData);
BOOL CkCompressionW_EndCompressStringENC(HCkCompressionW cHandle, HCkString outStr);
const wchar_t *CkCompressionW_endCompressStringENC(HCkCompressionW cHandle);
BOOL CkCompressionW_EndDecompressBytes(HCkCompressionW cHandle, HCkByteData outData);
BOOL CkCompressionW_EndDecompressBytesENC(HCkCompressionW cHandle, HCkByteData outData);
BOOL CkCompressionW_EndDecompressString(HCkCompressionW cHandle, HCkString outStr);
const wchar_t *CkCompressionW_endDecompressString(HCkCompressionW cHandle);
BOOL CkCompressionW_EndDecompressStringENC(HCkCompressionW cHandle, HCkString outStr);
const wchar_t *CkCompressionW_endDecompressStringENC(HCkCompressionW cHandle);
BOOL CkCompressionW_MoreCompressBytes(HCkCompressionW cHandle, HCkByteData data, HCkByteData outData);
BOOL CkCompressionW_MoreCompressBytesENC(HCkCompressionW cHandle, HCkByteData data, HCkString outStr);
const wchar_t *CkCompressionW_moreCompressBytesENC(HCkCompressionW cHandle, HCkByteData data);
BOOL CkCompressionW_MoreCompressString(HCkCompressionW cHandle, const wchar_t *str, HCkByteData outData);
BOOL CkCompressionW_MoreCompressStringENC(HCkCompressionW cHandle, const wchar_t *str, HCkString outStr);
const wchar_t *CkCompressionW_moreCompressStringENC(HCkCompressionW cHandle, const wchar_t *str);
BOOL CkCompressionW_MoreDecompressBytes(HCkCompressionW cHandle, HCkByteData data, HCkByteData outData);
BOOL CkCompressionW_MoreDecompressBytesENC(HCkCompressionW cHandle, const wchar_t *str, HCkByteData outData);
BOOL CkCompressionW_MoreDecompressString(HCkCompressionW cHandle, HCkByteData data, HCkString outStr);
const wchar_t *CkCompressionW_moreDecompressString(HCkCompressionW cHandle, HCkByteData data);
BOOL CkCompressionW_MoreDecompressStringENC(HCkCompressionW cHandle, const wchar_t *str, HCkString outStr);
const wchar_t *CkCompressionW_moreDecompressStringENC(HCkCompressionW cHandle, const wchar_t *str);
BOOL CkCompressionW_SaveLastError(HCkCompressionW cHandle, const wchar_t *path);
BOOL CkCompressionW_UnlockComponent(HCkCompressionW cHandle, const wchar_t *unlockCode);
#endif
