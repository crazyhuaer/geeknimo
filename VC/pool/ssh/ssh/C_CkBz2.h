// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkBz2_H
#define _C_CkBz2_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkBz2 CkBz2_Create(void);
void CkBz2_Dispose(HCkBz2 handle);
void CkBz2_getDebugLogFilePath(HCkBz2 cHandle, HCkString retval);
void CkBz2_putDebugLogFilePath(HCkBz2 cHandle, const char *newVal);
const char *CkBz2_debugLogFilePath(HCkBz2 cHandle);
int CkBz2_getHeartbeatMs(HCkBz2 cHandle);
void CkBz2_putHeartbeatMs(HCkBz2 cHandle, int newVal);
void CkBz2_getLastErrorHtml(HCkBz2 cHandle, HCkString retval);
const char *CkBz2_lastErrorHtml(HCkBz2 cHandle);
void CkBz2_getLastErrorText(HCkBz2 cHandle, HCkString retval);
const char *CkBz2_lastErrorText(HCkBz2 cHandle);
void CkBz2_getLastErrorXml(HCkBz2 cHandle, HCkString retval);
const char *CkBz2_lastErrorXml(HCkBz2 cHandle);
BOOL CkBz2_getUtf8(HCkBz2 cHandle);
void CkBz2_putUtf8(HCkBz2 cHandle, BOOL newVal);
BOOL CkBz2_getVerboseLogging(HCkBz2 cHandle);
void CkBz2_putVerboseLogging(HCkBz2 cHandle, BOOL newVal);
void CkBz2_getVersion(HCkBz2 cHandle, HCkString retval);
const char *CkBz2_version(HCkBz2 cHandle);
BOOL CkBz2_CompressFile(HCkBz2 cHandle, const char *inFilename, const char *outBz2Filename);
BOOL CkBz2_CompressFileToMem(HCkBz2 cHandle, const char *inFilename, HCkByteData outBytes);
BOOL CkBz2_CompressMemToFile(HCkBz2 cHandle, HCkByteData inData, const char *toPath);
BOOL CkBz2_CompressMemory(HCkBz2 cHandle, HCkByteData inData, HCkByteData outBytes);
BOOL CkBz2_SaveLastError(HCkBz2 cHandle, const char *path);
BOOL CkBz2_UncompressFile(HCkBz2 cHandle, const char *inFilename, const char *toPath);
BOOL CkBz2_UncompressFileToMem(HCkBz2 cHandle, const char *inFilename, HCkByteData outBytes);
BOOL CkBz2_UncompressMemToFile(HCkBz2 cHandle, HCkByteData inData, const char *toPath);
BOOL CkBz2_UncompressMemory(HCkBz2 cHandle, HCkByteData inData, HCkByteData outBytes);
BOOL CkBz2_UnlockComponent(HCkBz2 cHandle, const char *regCode);
#endif
