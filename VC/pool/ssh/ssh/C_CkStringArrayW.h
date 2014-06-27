// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkStringArrayWH
#define _C_CkStringArrayWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkStringArrayW CkStringArrayW_Create(void);
void CkStringArrayW_Dispose(HCkStringArrayW handle);
int CkStringArrayW_getCount(HCkStringArrayW cHandle);
BOOL CkStringArrayW_getCrlf(HCkStringArrayW cHandle);
void CkStringArrayW_putCrlf(HCkStringArrayW cHandle, BOOL newVal);
void CkStringArrayW_getDebugLogFilePath(HCkStringArrayW cHandle, HCkString retval);
void CkStringArrayW_putDebugLogFilePath(HCkStringArrayW cHandle, const wchar_t *newVal);
const wchar_t *CkStringArrayW_debugLogFilePath(HCkStringArrayW cHandle);
void CkStringArrayW_getLastErrorHtml(HCkStringArrayW cHandle, HCkString retval);
const wchar_t *CkStringArrayW_lastErrorHtml(HCkStringArrayW cHandle);
void CkStringArrayW_getLastErrorText(HCkStringArrayW cHandle, HCkString retval);
const wchar_t *CkStringArrayW_lastErrorText(HCkStringArrayW cHandle);
void CkStringArrayW_getLastErrorXml(HCkStringArrayW cHandle, HCkString retval);
const wchar_t *CkStringArrayW_lastErrorXml(HCkStringArrayW cHandle);
int CkStringArrayW_getLength(HCkStringArrayW cHandle);
BOOL CkStringArrayW_getTrim(HCkStringArrayW cHandle);
void CkStringArrayW_putTrim(HCkStringArrayW cHandle, BOOL newVal);
BOOL CkStringArrayW_getUnique(HCkStringArrayW cHandle);
void CkStringArrayW_putUnique(HCkStringArrayW cHandle, BOOL newVal);
BOOL CkStringArrayW_getVerboseLogging(HCkStringArrayW cHandle);
void CkStringArrayW_putVerboseLogging(HCkStringArrayW cHandle, BOOL newVal);
void CkStringArrayW_getVersion(HCkStringArrayW cHandle, HCkString retval);
const wchar_t *CkStringArrayW_version(HCkStringArrayW cHandle);
BOOL CkStringArrayW_Append(HCkStringArrayW cHandle, const wchar_t *str);
BOOL CkStringArrayW_AppendSerialized(HCkStringArrayW cHandle, const wchar_t *encodedStr);
void CkStringArrayW_Clear(HCkStringArrayW cHandle);
BOOL CkStringArrayW_Contains(HCkStringArrayW cHandle, const wchar_t *str);
int CkStringArrayW_Find(HCkStringArrayW cHandle, const wchar_t *findStr, int startIndex);
int CkStringArrayW_FindFirstMatch(HCkStringArrayW cHandle, const wchar_t *matchPattern, int startIndex);
BOOL CkStringArrayW_GetString(HCkStringArrayW cHandle, int index, HCkString outStr);
const wchar_t *CkStringArrayW_getString(HCkStringArrayW cHandle, int index);
int CkStringArrayW_GetStringLen(HCkStringArrayW cHandle, int index);
void CkStringArrayW_InsertAt(HCkStringArrayW cHandle, int index, const wchar_t *str);
BOOL CkStringArrayW_LastString(HCkStringArrayW cHandle, HCkString outStr);
const wchar_t *CkStringArrayW_lastString(HCkStringArrayW cHandle);
BOOL CkStringArrayW_LoadFromFile(HCkStringArrayW cHandle, const wchar_t *path);
BOOL CkStringArrayW_LoadFromFile2(HCkStringArrayW cHandle, const wchar_t *path, const wchar_t *charset);
void CkStringArrayW_LoadFromText(HCkStringArrayW cHandle, const wchar_t *str);
BOOL CkStringArrayW_Pop(HCkStringArrayW cHandle, HCkString outStr);
const wchar_t *CkStringArrayW_pop(HCkStringArrayW cHandle);
void CkStringArrayW_Prepend(HCkStringArrayW cHandle, const wchar_t *str);
void CkStringArrayW_Remove(HCkStringArrayW cHandle, const wchar_t *str);
BOOL CkStringArrayW_RemoveAt(HCkStringArrayW cHandle, int index);
BOOL CkStringArrayW_SaveLastError(HCkStringArrayW cHandle, const wchar_t *path);
BOOL CkStringArrayW_SaveNthToFile(HCkStringArrayW cHandle, int index, const wchar_t *saveToPath);
BOOL CkStringArrayW_SaveToFile(HCkStringArrayW cHandle, const wchar_t *path);
BOOL CkStringArrayW_SaveToFile2(HCkStringArrayW cHandle, const wchar_t *saveToPath, const wchar_t *charset);
BOOL CkStringArrayW_SaveToText(HCkStringArrayW cHandle, HCkString outStr);
const wchar_t *CkStringArrayW_saveToText(HCkStringArrayW cHandle);
BOOL CkStringArrayW_Serialize(HCkStringArrayW cHandle, HCkString outStr);
const wchar_t *CkStringArrayW_serialize(HCkStringArrayW cHandle);
void CkStringArrayW_Sort(HCkStringArrayW cHandle, BOOL ascending);
void CkStringArrayW_SplitAndAppend(HCkStringArrayW cHandle, const wchar_t *str, const wchar_t *boundary);
BOOL CkStringArrayW_StrAt(HCkStringArrayW cHandle, int index, HCkString outStr);
const wchar_t *CkStringArrayW_strAt(HCkStringArrayW cHandle, int index);
void CkStringArrayW_Subtract(HCkStringArrayW cHandle, HCkStringArrayW stringArrayObj);
void CkStringArrayW_Union(HCkStringArrayW cHandle, HCkStringArrayW stringArrayObj);
#endif
