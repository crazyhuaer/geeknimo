// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkUnixCompressWH
#define _C_CkUnixCompressWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkUnixCompressW CkUnixCompressW_Create(void);
HCkUnixCompressW CkUnixCompressW_Create2(BOOL bCallbackOwned);
void CkUnixCompressW_Dispose(HCkUnixCompressW handle);
void CkUnixCompressW_getDebugLogFilePath(HCkUnixCompressW cHandle, HCkString retval);
void CkUnixCompressW_putDebugLogFilePath(HCkUnixCompressW cHandle, const wchar_t *newVal);
const wchar_t *CkUnixCompressW_debugLogFilePath(HCkUnixCompressW cHandle);
int CkUnixCompressW_getHeartbeatMs(HCkUnixCompressW cHandle);
void CkUnixCompressW_putHeartbeatMs(HCkUnixCompressW cHandle, int newVal);
void CkUnixCompressW_getLastErrorHtml(HCkUnixCompressW cHandle, HCkString retval);
const wchar_t *CkUnixCompressW_lastErrorHtml(HCkUnixCompressW cHandle);
void CkUnixCompressW_getLastErrorText(HCkUnixCompressW cHandle, HCkString retval);
const wchar_t *CkUnixCompressW_lastErrorText(HCkUnixCompressW cHandle);
void CkUnixCompressW_getLastErrorXml(HCkUnixCompressW cHandle, HCkString retval);
const wchar_t *CkUnixCompressW_lastErrorXml(HCkUnixCompressW cHandle);
BOOL CkUnixCompressW_getVerboseLogging(HCkUnixCompressW cHandle);
void CkUnixCompressW_putVerboseLogging(HCkUnixCompressW cHandle, BOOL newVal);
void CkUnixCompressW_getVersion(HCkUnixCompressW cHandle, HCkString retval);
const wchar_t *CkUnixCompressW_version(HCkUnixCompressW cHandle);
BOOL CkUnixCompressW_CompressFile(HCkUnixCompressW cHandle, const wchar_t *inFilename, const wchar_t *destPath);
BOOL CkUnixCompressW_CompressFileToMem(HCkUnixCompressW cHandle, const wchar_t *inFilename, HCkByteData outData);
BOOL CkUnixCompressW_CompressMemToFile(HCkUnixCompressW cHandle, HCkByteData inData, const wchar_t *destPath);
BOOL CkUnixCompressW_CompressMemory(HCkUnixCompressW cHandle, HCkByteData inData, HCkByteData outData);
BOOL CkUnixCompressW_CompressString(HCkUnixCompressW cHandle, const wchar_t *inStr, const wchar_t *charset, HCkByteData outBytes);
BOOL CkUnixCompressW_CompressStringToFile(HCkUnixCompressW cHandle, const wchar_t *inStr, const wchar_t *charset, const wchar_t *outPath);
BOOL CkUnixCompressW_IsUnlocked(HCkUnixCompressW cHandle);
BOOL CkUnixCompressW_SaveLastError(HCkUnixCompressW cHandle, const wchar_t *path);
BOOL CkUnixCompressW_UnTarZ(HCkUnixCompressW cHandle, const wchar_t *zFilename, const wchar_t *destDir, BOOL bNoAbsolute);
BOOL CkUnixCompressW_UncompressFile(HCkUnixCompressW cHandle, const wchar_t *inFilename, const wchar_t *destPath);
BOOL CkUnixCompressW_UncompressFileToMem(HCkUnixCompressW cHandle, const wchar_t *inFilename, HCkByteData outData);
BOOL CkUnixCompressW_UncompressFileToString(HCkUnixCompressW cHandle, const wchar_t *zFilename, const wchar_t *charset, HCkString outStr);
const wchar_t *CkUnixCompressW_uncompressFileToString(HCkUnixCompressW cHandle, const wchar_t *zFilename, const wchar_t *charset);
BOOL CkUnixCompressW_UncompressMemToFile(HCkUnixCompressW cHandle, HCkByteData inData, const wchar_t *destPath);
BOOL CkUnixCompressW_UncompressMemory(HCkUnixCompressW cHandle, HCkByteData inData, HCkByteData outData);
BOOL CkUnixCompressW_UncompressString(HCkUnixCompressW cHandle, HCkByteData inCompressedData, const wchar_t *charset, HCkString outStr);
const wchar_t *CkUnixCompressW_uncompressString(HCkUnixCompressW cHandle, HCkByteData inCompressedData, const wchar_t *charset);
BOOL CkUnixCompressW_UnlockComponent(HCkUnixCompressW cHandle, const wchar_t *unlockCode);
#endif
