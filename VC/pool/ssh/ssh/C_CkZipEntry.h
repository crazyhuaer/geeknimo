// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkZipEntry_H
#define _C_CkZipEntry_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkZipEntry CkZipEntry_Create(void);
void CkZipEntry_Dispose(HCkZipEntry handle);
void CkZipEntry_getComment(HCkZipEntry cHandle, HCkString retval);
void CkZipEntry_putComment(HCkZipEntry cHandle, const char *newVal);
const char *CkZipEntry_comment(HCkZipEntry cHandle);
unsigned long CkZipEntry_getCompressedLength(HCkZipEntry cHandle);
__int64 CkZipEntry_getCompressedLength64(HCkZipEntry cHandle);
void CkZipEntry_getCompressedLengthStr(HCkZipEntry cHandle, HCkString retval);
const char *CkZipEntry_compressedLengthStr(HCkZipEntry cHandle);
int CkZipEntry_getCompressionLevel(HCkZipEntry cHandle);
void CkZipEntry_putCompressionLevel(HCkZipEntry cHandle, int newVal);
int CkZipEntry_getCompressionMethod(HCkZipEntry cHandle);
void CkZipEntry_putCompressionMethod(HCkZipEntry cHandle, int newVal);
int CkZipEntry_getCrc(HCkZipEntry cHandle);
void CkZipEntry_getDebugLogFilePath(HCkZipEntry cHandle, HCkString retval);
void CkZipEntry_putDebugLogFilePath(HCkZipEntry cHandle, const char *newVal);
const char *CkZipEntry_debugLogFilePath(HCkZipEntry cHandle);
int CkZipEntry_getEntryID(HCkZipEntry cHandle);
int CkZipEntry_getEntryType(HCkZipEntry cHandle);
void CkZipEntry_getFileDateTime(HCkZipEntry cHandle, SYSTEMTIME *retval);
void CkZipEntry_putFileDateTime(HCkZipEntry cHandle, SYSTEMTIME *newVal);
void CkZipEntry_getFileDateTimeStr(HCkZipEntry cHandle, HCkString retval);
void CkZipEntry_putFileDateTimeStr(HCkZipEntry cHandle, const char *newVal);
const char *CkZipEntry_fileDateTimeStr(HCkZipEntry cHandle);
void CkZipEntry_getFileName(HCkZipEntry cHandle, HCkString retval);
void CkZipEntry_putFileName(HCkZipEntry cHandle, const char *newVal);
const char *CkZipEntry_fileName(HCkZipEntry cHandle);
void CkZipEntry_getFileNameHex(HCkZipEntry cHandle, HCkString retval);
const char *CkZipEntry_fileNameHex(HCkZipEntry cHandle);
int CkZipEntry_getHeartbeatMs(HCkZipEntry cHandle);
void CkZipEntry_putHeartbeatMs(HCkZipEntry cHandle, int newVal);
BOOL CkZipEntry_getIsDirectory(HCkZipEntry cHandle);
void CkZipEntry_getLastErrorHtml(HCkZipEntry cHandle, HCkString retval);
const char *CkZipEntry_lastErrorHtml(HCkZipEntry cHandle);
void CkZipEntry_getLastErrorText(HCkZipEntry cHandle, HCkString retval);
const char *CkZipEntry_lastErrorText(HCkZipEntry cHandle);
void CkZipEntry_getLastErrorXml(HCkZipEntry cHandle, HCkString retval);
const char *CkZipEntry_lastErrorXml(HCkZipEntry cHandle);
BOOL CkZipEntry_getTextFlag(HCkZipEntry cHandle);
void CkZipEntry_putTextFlag(HCkZipEntry cHandle, BOOL newVal);
unsigned long CkZipEntry_getUncompressedLength(HCkZipEntry cHandle);
__int64 CkZipEntry_getUncompressedLength64(HCkZipEntry cHandle);
void CkZipEntry_getUncompressedLengthStr(HCkZipEntry cHandle, HCkString retval);
const char *CkZipEntry_uncompressedLengthStr(HCkZipEntry cHandle);
BOOL CkZipEntry_getUtf8(HCkZipEntry cHandle);
void CkZipEntry_putUtf8(HCkZipEntry cHandle, BOOL newVal);
BOOL CkZipEntry_getVerboseLogging(HCkZipEntry cHandle);
void CkZipEntry_putVerboseLogging(HCkZipEntry cHandle, BOOL newVal);
void CkZipEntry_getVersion(HCkZipEntry cHandle, HCkString retval);
const char *CkZipEntry_version(HCkZipEntry cHandle);
BOOL CkZipEntry_AppendData(HCkZipEntry cHandle, HCkByteData inData);
BOOL CkZipEntry_AppendString(HCkZipEntry cHandle, const char *strContent, const char *charset);
BOOL CkZipEntry_Copy(HCkZipEntry cHandle, HCkByteData outData);
BOOL CkZipEntry_CopyToBase64(HCkZipEntry cHandle, HCkString outStr);
const char *CkZipEntry_copyToBase64(HCkZipEntry cHandle);
BOOL CkZipEntry_CopyToHex(HCkZipEntry cHandle, HCkString outStr);
const char *CkZipEntry_copyToHex(HCkZipEntry cHandle);
BOOL CkZipEntry_Extract(HCkZipEntry cHandle, const char *dirPath);
BOOL CkZipEntry_ExtractInto(HCkZipEntry cHandle, const char *dirPath);
HCkDateTime CkZipEntry_GetDt(HCkZipEntry cHandle);
BOOL CkZipEntry_Inflate(HCkZipEntry cHandle, HCkByteData outData);
HCkZipEntry CkZipEntry_NextEntry(HCkZipEntry cHandle);
BOOL CkZipEntry_ReplaceData(HCkZipEntry cHandle, HCkByteData inData);
BOOL CkZipEntry_ReplaceString(HCkZipEntry cHandle, const char *strContent, const char *charset);
BOOL CkZipEntry_SaveLastError(HCkZipEntry cHandle, const char *path);
void CkZipEntry_SetDt(HCkZipEntry cHandle, HCkDateTime dt);
BOOL CkZipEntry_UnzipToString(HCkZipEntry cHandle, int lineEndingBehavior, const char *srcCharset, HCkString outStr);
const char *CkZipEntry_unzipToString(HCkZipEntry cHandle, int lineEndingBehavior, const char *srcCharset);
#endif
