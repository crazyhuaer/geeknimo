// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCacheWH
#define _C_CkCacheWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCacheW CkCacheW_Create(void);
void CkCacheW_Dispose(HCkCacheW handle);
void CkCacheW_getDebugLogFilePath(HCkCacheW cHandle, HCkString retval);
void CkCacheW_putDebugLogFilePath(HCkCacheW cHandle, const wchar_t *newVal);
const wchar_t *CkCacheW_debugLogFilePath(HCkCacheW cHandle);
void CkCacheW_getLastErrorHtml(HCkCacheW cHandle, HCkString retval);
const wchar_t *CkCacheW_lastErrorHtml(HCkCacheW cHandle);
void CkCacheW_getLastErrorText(HCkCacheW cHandle, HCkString retval);
const wchar_t *CkCacheW_lastErrorText(HCkCacheW cHandle);
void CkCacheW_getLastErrorXml(HCkCacheW cHandle, HCkString retval);
const wchar_t *CkCacheW_lastErrorXml(HCkCacheW cHandle);
void CkCacheW_getLastEtagFetched(HCkCacheW cHandle, HCkString retval);
const wchar_t *CkCacheW_lastEtagFetched(HCkCacheW cHandle);
void CkCacheW_getLastExpirationFetched(HCkCacheW cHandle, SYSTEMTIME *retval);
void CkCacheW_getLastExpirationFetchedStr(HCkCacheW cHandle, HCkString retval);
const wchar_t *CkCacheW_lastExpirationFetchedStr(HCkCacheW cHandle);
BOOL CkCacheW_getLastHitExpired(HCkCacheW cHandle);
void CkCacheW_getLastKeyFetched(HCkCacheW cHandle, HCkString retval);
const wchar_t *CkCacheW_lastKeyFetched(HCkCacheW cHandle);
int CkCacheW_getLevel(HCkCacheW cHandle);
void CkCacheW_putLevel(HCkCacheW cHandle, int newVal);
int CkCacheW_getNumRoots(HCkCacheW cHandle);
BOOL CkCacheW_getVerboseLogging(HCkCacheW cHandle);
void CkCacheW_putVerboseLogging(HCkCacheW cHandle, BOOL newVal);
void CkCacheW_getVersion(HCkCacheW cHandle, HCkString retval);
const wchar_t *CkCacheW_version(HCkCacheW cHandle);
void CkCacheW_AddRoot(HCkCacheW cHandle, const wchar_t *path);
int CkCacheW_DeleteAll(HCkCacheW cHandle);
int CkCacheW_DeleteAllExpired(HCkCacheW cHandle);
BOOL CkCacheW_DeleteFromCache(HCkCacheW cHandle, const wchar_t *key);
int CkCacheW_DeleteOlder(HCkCacheW cHandle, SYSTEMTIME *dateTime);
int CkCacheW_DeleteOlderDt(HCkCacheW cHandle, HCkDateTimeW dateTime);
int CkCacheW_DeleteOlderStr(HCkCacheW cHandle, const wchar_t *dateTimeStr);
BOOL CkCacheW_FetchFromCache(HCkCacheW cHandle, const wchar_t *key, HCkByteData outBytes);
BOOL CkCacheW_FetchText(HCkCacheW cHandle, const wchar_t *key, HCkString outStr);
const wchar_t *CkCacheW_fetchText(HCkCacheW cHandle, const wchar_t *key);
BOOL CkCacheW_GetEtag(HCkCacheW cHandle, const wchar_t *key, HCkString outStr);
const wchar_t *CkCacheW_getEtag(HCkCacheW cHandle, const wchar_t *key);
BOOL CkCacheW_GetExpiration(HCkCacheW cHandle, const wchar_t *key, SYSTEMTIME *outSysTime);
HCkDateTimeW CkCacheW_GetExpirationDt(HCkCacheW cHandle, const wchar_t *key);
BOOL CkCacheW_GetExpirationStr(HCkCacheW cHandle, const wchar_t *url, HCkString outStr);
const wchar_t *CkCacheW_getExpirationStr(HCkCacheW cHandle, const wchar_t *url);
BOOL CkCacheW_GetFilename(HCkCacheW cHandle, const wchar_t *key, HCkString outStr);
const wchar_t *CkCacheW_getFilename(HCkCacheW cHandle, const wchar_t *key);
BOOL CkCacheW_GetRoot(HCkCacheW cHandle, int index, HCkString outStr);
const wchar_t *CkCacheW_getRoot(HCkCacheW cHandle, int index);
BOOL CkCacheW_IsCached(HCkCacheW cHandle, const wchar_t *key);
BOOL CkCacheW_SaveLastError(HCkCacheW cHandle, const wchar_t *path);
BOOL CkCacheW_SaveText(HCkCacheW cHandle, const wchar_t *key, SYSTEMTIME *expireDateTime, const wchar_t *eTag, const wchar_t *itemTextData);
BOOL CkCacheW_SaveTextDt(HCkCacheW cHandle, const wchar_t *key, HCkDateTimeW expireDateTime, const wchar_t *eTag, const wchar_t *itemTextData);
BOOL CkCacheW_SaveTextNoExpire(HCkCacheW cHandle, const wchar_t *key, const wchar_t *eTag, const wchar_t *itemTextData);
BOOL CkCacheW_SaveTextStr(HCkCacheW cHandle, const wchar_t *key, const wchar_t *expireDateTime, const wchar_t *eTag, const wchar_t *itemTextData);
BOOL CkCacheW_SaveToCache(HCkCacheW cHandle, const wchar_t *key, SYSTEMTIME *expireDateTime, const wchar_t *eTag, HCkByteData itemData);
BOOL CkCacheW_SaveToCacheDt(HCkCacheW cHandle, const wchar_t *key, HCkDateTimeW expireDateTime, const wchar_t *eTag, HCkByteData itemData);
BOOL CkCacheW_SaveToCacheNoExpire(HCkCacheW cHandle, const wchar_t *key, const wchar_t *eTag, HCkByteData itemData);
BOOL CkCacheW_SaveToCacheStr(HCkCacheW cHandle, const wchar_t *key, const wchar_t *expireDateTime, const wchar_t *eTag, HCkByteData itemData);
BOOL CkCacheW_UpdateExpiration(HCkCacheW cHandle, const wchar_t *key, SYSTEMTIME *expireDateTime);
BOOL CkCacheW_UpdateExpirationDt(HCkCacheW cHandle, const wchar_t *key, HCkDateTimeW expireDateTime);
BOOL CkCacheW_UpdateExpirationStr(HCkCacheW cHandle, const wchar_t *key, const wchar_t *expireDateTime);
#endif
