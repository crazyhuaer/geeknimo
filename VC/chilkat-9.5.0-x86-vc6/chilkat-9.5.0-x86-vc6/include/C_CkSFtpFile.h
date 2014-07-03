// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkSFtpFile_H
#define _C_CkSFtpFile_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkSFtpFile CkSFtpFile_Create(void);
void CkSFtpFile_Dispose(HCkSFtpFile handle);
void CkSFtpFile_getCreateTime(HCkSFtpFile cHandle, SYSTEMTIME *retval);
void CkSFtpFile_getCreateTimeStr(HCkSFtpFile cHandle, HCkString retval);
const char *CkSFtpFile_createTimeStr(HCkSFtpFile cHandle);
void CkSFtpFile_getDebugLogFilePath(HCkSFtpFile cHandle, HCkString retval);
void CkSFtpFile_putDebugLogFilePath(HCkSFtpFile cHandle, const char *newVal);
const char *CkSFtpFile_debugLogFilePath(HCkSFtpFile cHandle);
void CkSFtpFile_getFileType(HCkSFtpFile cHandle, HCkString retval);
const char *CkSFtpFile_fileType(HCkSFtpFile cHandle);
void CkSFtpFile_getFilename(HCkSFtpFile cHandle, HCkString retval);
const char *CkSFtpFile_filename(HCkSFtpFile cHandle);
int CkSFtpFile_getGid(HCkSFtpFile cHandle);
void CkSFtpFile_getGroup(HCkSFtpFile cHandle, HCkString retval);
const char *CkSFtpFile_group(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsAppendOnly(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsArchive(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsCaseInsensitive(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsCompressed(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsDirectory(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsEncrypted(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsHidden(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsImmutable(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsReadOnly(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsRegular(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsSparse(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsSymLink(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsSync(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsSystem(HCkSFtpFile cHandle);
void CkSFtpFile_getLastAccessTime(HCkSFtpFile cHandle, SYSTEMTIME *retval);
void CkSFtpFile_getLastAccessTimeStr(HCkSFtpFile cHandle, HCkString retval);
const char *CkSFtpFile_lastAccessTimeStr(HCkSFtpFile cHandle);
void CkSFtpFile_getLastErrorHtml(HCkSFtpFile cHandle, HCkString retval);
const char *CkSFtpFile_lastErrorHtml(HCkSFtpFile cHandle);
void CkSFtpFile_getLastErrorText(HCkSFtpFile cHandle, HCkString retval);
const char *CkSFtpFile_lastErrorText(HCkSFtpFile cHandle);
void CkSFtpFile_getLastErrorXml(HCkSFtpFile cHandle, HCkString retval);
const char *CkSFtpFile_lastErrorXml(HCkSFtpFile cHandle);
void CkSFtpFile_getLastModifiedTime(HCkSFtpFile cHandle, SYSTEMTIME *retval);
void CkSFtpFile_getLastModifiedTimeStr(HCkSFtpFile cHandle, HCkString retval);
const char *CkSFtpFile_lastModifiedTimeStr(HCkSFtpFile cHandle);
void CkSFtpFile_getOwner(HCkSFtpFile cHandle, HCkString retval);
const char *CkSFtpFile_owner(HCkSFtpFile cHandle);
int CkSFtpFile_getPermissions(HCkSFtpFile cHandle);
int CkSFtpFile_getSize32(HCkSFtpFile cHandle);
__int64 CkSFtpFile_getSize64(HCkSFtpFile cHandle);
void CkSFtpFile_getSizeStr(HCkSFtpFile cHandle, HCkString retval);
const char *CkSFtpFile_sizeStr(HCkSFtpFile cHandle);
int CkSFtpFile_getUid(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getUtf8(HCkSFtpFile cHandle);
void CkSFtpFile_putUtf8(HCkSFtpFile cHandle, BOOL newVal);
BOOL CkSFtpFile_getVerboseLogging(HCkSFtpFile cHandle);
void CkSFtpFile_putVerboseLogging(HCkSFtpFile cHandle, BOOL newVal);
void CkSFtpFile_getVersion(HCkSFtpFile cHandle, HCkString retval);
const char *CkSFtpFile_version(HCkSFtpFile cHandle);
HCkDateTime CkSFtpFile_GetCreateDt(HCkSFtpFile cHandle);
HCkDateTime CkSFtpFile_GetLastAccessDt(HCkSFtpFile cHandle);
HCkDateTime CkSFtpFile_GetLastModifiedDt(HCkSFtpFile cHandle);
BOOL CkSFtpFile_SaveLastError(HCkSFtpFile cHandle, const char *path);
#endif
