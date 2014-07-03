// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkSFtpFileWH
#define _C_CkSFtpFileWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkSFtpFileW CkSFtpFileW_Create(void);
void CkSFtpFileW_Dispose(HCkSFtpFileW handle);
void CkSFtpFileW_getCreateTime(HCkSFtpFileW cHandle, SYSTEMTIME *retval);
void CkSFtpFileW_getCreateTimeStr(HCkSFtpFileW cHandle, HCkString retval);
const wchar_t *CkSFtpFileW_createTimeStr(HCkSFtpFileW cHandle);
void CkSFtpFileW_getDebugLogFilePath(HCkSFtpFileW cHandle, HCkString retval);
void CkSFtpFileW_putDebugLogFilePath(HCkSFtpFileW cHandle, const wchar_t *newVal);
const wchar_t *CkSFtpFileW_debugLogFilePath(HCkSFtpFileW cHandle);
void CkSFtpFileW_getFileType(HCkSFtpFileW cHandle, HCkString retval);
const wchar_t *CkSFtpFileW_fileType(HCkSFtpFileW cHandle);
void CkSFtpFileW_getFilename(HCkSFtpFileW cHandle, HCkString retval);
const wchar_t *CkSFtpFileW_filename(HCkSFtpFileW cHandle);
int CkSFtpFileW_getGid(HCkSFtpFileW cHandle);
void CkSFtpFileW_getGroup(HCkSFtpFileW cHandle, HCkString retval);
const wchar_t *CkSFtpFileW_group(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsAppendOnly(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsArchive(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsCaseInsensitive(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsCompressed(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsDirectory(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsEncrypted(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsHidden(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsImmutable(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsReadOnly(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsRegular(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsSparse(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsSymLink(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsSync(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsSystem(HCkSFtpFileW cHandle);
void CkSFtpFileW_getLastAccessTime(HCkSFtpFileW cHandle, SYSTEMTIME *retval);
void CkSFtpFileW_getLastAccessTimeStr(HCkSFtpFileW cHandle, HCkString retval);
const wchar_t *CkSFtpFileW_lastAccessTimeStr(HCkSFtpFileW cHandle);
void CkSFtpFileW_getLastErrorHtml(HCkSFtpFileW cHandle, HCkString retval);
const wchar_t *CkSFtpFileW_lastErrorHtml(HCkSFtpFileW cHandle);
void CkSFtpFileW_getLastErrorText(HCkSFtpFileW cHandle, HCkString retval);
const wchar_t *CkSFtpFileW_lastErrorText(HCkSFtpFileW cHandle);
void CkSFtpFileW_getLastErrorXml(HCkSFtpFileW cHandle, HCkString retval);
const wchar_t *CkSFtpFileW_lastErrorXml(HCkSFtpFileW cHandle);
void CkSFtpFileW_getLastModifiedTime(HCkSFtpFileW cHandle, SYSTEMTIME *retval);
void CkSFtpFileW_getLastModifiedTimeStr(HCkSFtpFileW cHandle, HCkString retval);
const wchar_t *CkSFtpFileW_lastModifiedTimeStr(HCkSFtpFileW cHandle);
void CkSFtpFileW_getOwner(HCkSFtpFileW cHandle, HCkString retval);
const wchar_t *CkSFtpFileW_owner(HCkSFtpFileW cHandle);
int CkSFtpFileW_getPermissions(HCkSFtpFileW cHandle);
int CkSFtpFileW_getSize32(HCkSFtpFileW cHandle);
__int64 CkSFtpFileW_getSize64(HCkSFtpFileW cHandle);
void CkSFtpFileW_getSizeStr(HCkSFtpFileW cHandle, HCkString retval);
const wchar_t *CkSFtpFileW_sizeStr(HCkSFtpFileW cHandle);
int CkSFtpFileW_getUid(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getVerboseLogging(HCkSFtpFileW cHandle);
void CkSFtpFileW_putVerboseLogging(HCkSFtpFileW cHandle, BOOL newVal);
void CkSFtpFileW_getVersion(HCkSFtpFileW cHandle, HCkString retval);
const wchar_t *CkSFtpFileW_version(HCkSFtpFileW cHandle);
HCkDateTimeW CkSFtpFileW_GetCreateDt(HCkSFtpFileW cHandle);
HCkDateTimeW CkSFtpFileW_GetLastAccessDt(HCkSFtpFileW cHandle);
HCkDateTimeW CkSFtpFileW_GetLastModifiedDt(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_SaveLastError(HCkSFtpFileW cHandle, const wchar_t *path);
#endif
