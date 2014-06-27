// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkUnixCompress_H
#define _C_CkUnixCompress_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkUnixCompress CkUnixCompress_Create(void);
void CkUnixCompress_Dispose(HCkUnixCompress handle);
void CkUnixCompress_getDebugLogFilePath(HCkUnixCompress cHandle, HCkString retval);
void CkUnixCompress_putDebugLogFilePath(HCkUnixCompress cHandle, const char *newVal);
const char *CkUnixCompress_debugLogFilePath(HCkUnixCompress cHandle);
int CkUnixCompress_getHeartbeatMs(HCkUnixCompress cHandle);
void CkUnixCompress_putHeartbeatMs(HCkUnixCompress cHandle, int newVal);
void CkUnixCompress_getLastErrorHtml(HCkUnixCompress cHandle, HCkString retval);
const char *CkUnixCompress_lastErrorHtml(HCkUnixCompress cHandle);
void CkUnixCompress_getLastErrorText(HCkUnixCompress cHandle, HCkString retval);
const char *CkUnixCompress_lastErrorText(HCkUnixCompress cHandle);
void CkUnixCompress_getLastErrorXml(HCkUnixCompress cHandle, HCkString retval);
const char *CkUnixCompress_lastErrorXml(HCkUnixCompress cHandle);
BOOL CkUnixCompress_getUtf8(HCkUnixCompress cHandle);
void CkUnixCompress_putUtf8(HCkUnixCompress cHandle, BOOL newVal);
BOOL CkUnixCompress_getVerboseLogging(HCkUnixCompress cHandle);
void CkUnixCompress_putVerboseLogging(HCkUnixCompress cHandle, BOOL newVal);
void CkUnixCompress_getVersion(HCkUnixCompress cHandle, HCkString retval);
const char *CkUnixCompress_version(HCkUnixCompress cHandle);
BOOL CkUnixCompress_CompressFile(HCkUnixCompress cHandle, const char *inFilename, const char *destPath);
BOOL CkUnixCompress_CompressFileToMem(HCkUnixCompress cHandle, const char *inFilename, HCkByteData outData);
BOOL CkUnixCompress_CompressMemToFile(HCkUnixCompress cHandle, HCkByteData inData, const char *destPath);
BOOL CkUnixCompress_CompressMemory(HCkUnixCompress cHandle, HCkByteData inData, HCkByteData outData);
BOOL CkUnixCompress_CompressString(HCkUnixCompress cHandle, const char *inStr, const char *charset, HCkByteData outBytes);
BOOL CkUnixCompress_CompressStringToFile(HCkUnixCompress cHandle, const char *inStr, const char *charset, const char *outPath);
BOOL CkUnixCompress_IsUnlocked(HCkUnixCompress cHandle);
BOOL CkUnixCompress_SaveLastError(HCkUnixCompress cHandle, const char *path);
BOOL CkUnixCompress_UnTarZ(HCkUnixCompress cHandle, const char *zFilename, const char *destDir, BOOL bNoAbsolute);
BOOL CkUnixCompress_UncompressFile(HCkUnixCompress cHandle, const char *inFilename, const char *destPath);
BOOL CkUnixCompress_UncompressFileToMem(HCkUnixCompress cHandle, const char *inFilename, HCkByteData outData);
BOOL CkUnixCompress_UncompressFileToString(HCkUnixCompress cHandle, const char *zFilename, const char *charset, HCkString outStr);
const char *CkUnixCompress_uncompressFileToString(HCkUnixCompress cHandle, const char *zFilename, const char *charset);
BOOL CkUnixCompress_UncompressMemToFile(HCkUnixCompress cHandle, HCkByteData inData, const char *destPath);
BOOL CkUnixCompress_UncompressMemory(HCkUnixCompress cHandle, HCkByteData inData, HCkByteData outData);
BOOL CkUnixCompress_UncompressString(HCkUnixCompress cHandle, HCkByteData inCompressedData, const char *charset, HCkString outStr);
const char *CkUnixCompress_uncompressString(HCkUnixCompress cHandle, HCkByteData inCompressedData, const char *charset);
BOOL CkUnixCompress_UnlockComponent(HCkUnixCompress cHandle, const char *unlockCode);
#endif
