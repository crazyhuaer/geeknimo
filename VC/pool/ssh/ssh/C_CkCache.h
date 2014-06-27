// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCache_H
#define _C_CkCache_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCache CkCache_Create(void);
void CkCache_Dispose(HCkCache handle);
void CkCache_getDebugLogFilePath(HCkCache cHandle, HCkString retval);
void CkCache_putDebugLogFilePath(HCkCache cHandle, const char *newVal);
const char *CkCache_debugLogFilePath(HCkCache cHandle);
void CkCache_getLastErrorHtml(HCkCache cHandle, HCkString retval);
const char *CkCache_lastErrorHtml(HCkCache cHandle);
void CkCache_getLastErrorText(HCkCache cHandle, HCkString retval);
const char *CkCache_lastErrorText(HCkCache cHandle);
void CkCache_getLastErrorXml(HCkCache cHandle, HCkString retval);
const char *CkCache_lastErrorXml(HCkCache cHandle);
void CkCache_getLastEtagFetched(HCkCache cHandle, HCkString retval);
const char *CkCache_lastEtagFetched(HCkCache cHandle);
void CkCache_getLastExpirationFetched(HCkCache cHandle, SYSTEMTIME *retval);
void CkCache_getLastExpirationFetchedStr(HCkCache cHandle, HCkString retval);
const char *CkCache_lastExpirationFetchedStr(HCkCache cHandle);
BOOL CkCache_getLastHitExpired(HCkCache cHandle);
void CkCache_getLastKeyFetched(HCkCache cHandle, HCkString retval);
const char *CkCache_lastKeyFetched(HCkCache cHandle);
int CkCache_getLevel(HCkCache cHandle);
void CkCache_putLevel(HCkCache cHandle, int newVal);
int CkCache_getNumRoots(HCkCache cHandle);
BOOL CkCache_getUtf8(HCkCache cHandle);
void CkCache_putUtf8(HCkCache cHandle, BOOL newVal);
BOOL CkCache_getVerboseLogging(HCkCache cHandle);
void CkCache_putVerboseLogging(HCkCache cHandle, BOOL newVal);
void CkCache_getVersion(HCkCache cHandle, HCkString retval);
const char *CkCache_version(HCkCache cHandle);
void CkCache_AddRoot(HCkCache cHandle, const char *path);
int CkCache_DeleteAll(HCkCache cHandle);
int CkCache_DeleteAllExpired(HCkCache cHandle);
BOOL CkCache_DeleteFromCache(HCkCache cHandle, const char *key);
int CkCache_DeleteOlder(HCkCache cHandle, SYSTEMTIME *dateTime);
int CkCache_DeleteOlderDt(HCkCache cHandle, HCkDateTime dateTime);
int CkCache_DeleteOlderStr(HCkCache cHandle, const char *dateTimeStr);
BOOL CkCache_FetchFromCache(HCkCache cHandle, const char *key, HCkByteData outBytes);
BOOL CkCache_FetchText(HCkCache cHandle, const char *key, HCkString outStr);
const char *CkCache_fetchText(HCkCache cHandle, const char *key);
BOOL CkCache_GetEtag(HCkCache cHandle, const char *key, HCkString outStr);
const char *CkCache_getEtag(HCkCache cHandle, const char *key);
BOOL CkCache_GetExpiration(HCkCache cHandle, const char *key, SYSTEMTIME *outSysTime);
HCkDateTime CkCache_GetExpirationDt(HCkCache cHandle, const char *key);
BOOL CkCache_GetExpirationStr(HCkCache cHandle, const char *url, HCkString outStr);
const char *CkCache_getExpirationStr(HCkCache cHandle, const char *url);
BOOL CkCache_GetFilename(HCkCache cHandle, const char *key, HCkString outStr);
const char *CkCache_getFilename(HCkCache cHandle, const char *key);
BOOL CkCache_GetRoot(HCkCache cHandle, int index, HCkString outStr);
const char *CkCache_getRoot(HCkCache cHandle, int index);
BOOL CkCache_IsCached(HCkCache cHandle, const char *key);
BOOL CkCache_SaveLastError(HCkCache cHandle, const char *path);
BOOL CkCache_SaveText(HCkCache cHandle, const char *key, SYSTEMTIME *expireDateTime, const char *eTag, const char *itemTextData);
BOOL CkCache_SaveTextDt(HCkCache cHandle, const char *key, HCkDateTime expireDateTime, const char *eTag, const char *itemTextData);
BOOL CkCache_SaveTextNoExpire(HCkCache cHandle, const char *key, const char *eTag, const char *itemTextData);
BOOL CkCache_SaveTextStr(HCkCache cHandle, const char *key, const char *expireDateTime, const char *eTag, const char *itemTextData);
BOOL CkCache_SaveToCache(HCkCache cHandle, const char *key, SYSTEMTIME *expireDateTime, const char *eTag, HCkByteData itemData);
BOOL CkCache_SaveToCacheDt(HCkCache cHandle, const char *key, HCkDateTime expireDateTime, const char *eTag, HCkByteData itemData);
BOOL CkCache_SaveToCacheNoExpire(HCkCache cHandle, const char *key, const char *eTag, HCkByteData itemData);
BOOL CkCache_SaveToCacheStr(HCkCache cHandle, const char *key, const char *expireDateTime, const char *eTag, HCkByteData itemData);
BOOL CkCache_UpdateExpiration(HCkCache cHandle, const char *key, SYSTEMTIME *expireDateTime);
BOOL CkCache_UpdateExpirationDt(HCkCache cHandle, const char *key, HCkDateTime expireDateTime);
BOOL CkCache_UpdateExpirationStr(HCkCache cHandle, const char *key, const char *expireDateTime);
#endif
