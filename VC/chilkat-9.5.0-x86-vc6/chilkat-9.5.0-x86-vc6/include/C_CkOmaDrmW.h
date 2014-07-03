// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkOmaDrmWH
#define _C_CkOmaDrmWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkOmaDrmW CkOmaDrmW_Create(void);
void CkOmaDrmW_Dispose(HCkOmaDrmW handle);
void CkOmaDrmW_getBase64Key(HCkOmaDrmW cHandle, HCkString retval);
void CkOmaDrmW_putBase64Key(HCkOmaDrmW cHandle, const wchar_t *newVal);
const wchar_t *CkOmaDrmW_base64Key(HCkOmaDrmW cHandle);
void CkOmaDrmW_getContentType(HCkOmaDrmW cHandle, HCkString retval);
void CkOmaDrmW_putContentType(HCkOmaDrmW cHandle, const wchar_t *newVal);
const wchar_t *CkOmaDrmW_contentType(HCkOmaDrmW cHandle);
void CkOmaDrmW_getContentUri(HCkOmaDrmW cHandle, HCkString retval);
void CkOmaDrmW_putContentUri(HCkOmaDrmW cHandle, const wchar_t *newVal);
const wchar_t *CkOmaDrmW_contentUri(HCkOmaDrmW cHandle);
void CkOmaDrmW_getDebugLogFilePath(HCkOmaDrmW cHandle, HCkString retval);
void CkOmaDrmW_putDebugLogFilePath(HCkOmaDrmW cHandle, const wchar_t *newVal);
const wchar_t *CkOmaDrmW_debugLogFilePath(HCkOmaDrmW cHandle);
void CkOmaDrmW_getDecryptedData(HCkOmaDrmW cHandle, HCkByteData retval);
int CkOmaDrmW_getDrmContentVersion(HCkOmaDrmW cHandle);
void CkOmaDrmW_getEncryptedData(HCkOmaDrmW cHandle, HCkByteData retval);
void CkOmaDrmW_getHeaders(HCkOmaDrmW cHandle, HCkString retval);
void CkOmaDrmW_putHeaders(HCkOmaDrmW cHandle, const wchar_t *newVal);
const wchar_t *CkOmaDrmW_headers(HCkOmaDrmW cHandle);
void CkOmaDrmW_getIV(HCkOmaDrmW cHandle, HCkByteData retval);
void CkOmaDrmW_putIV(HCkOmaDrmW cHandle, HCkByteData  newVal);
void CkOmaDrmW_getLastErrorHtml(HCkOmaDrmW cHandle, HCkString retval);
const wchar_t *CkOmaDrmW_lastErrorHtml(HCkOmaDrmW cHandle);
void CkOmaDrmW_getLastErrorText(HCkOmaDrmW cHandle, HCkString retval);
const wchar_t *CkOmaDrmW_lastErrorText(HCkOmaDrmW cHandle);
void CkOmaDrmW_getLastErrorXml(HCkOmaDrmW cHandle, HCkString retval);
const wchar_t *CkOmaDrmW_lastErrorXml(HCkOmaDrmW cHandle);
BOOL CkOmaDrmW_getVerboseLogging(HCkOmaDrmW cHandle);
void CkOmaDrmW_putVerboseLogging(HCkOmaDrmW cHandle, BOOL newVal);
void CkOmaDrmW_getVersion(HCkOmaDrmW cHandle, HCkString retval);
const wchar_t *CkOmaDrmW_version(HCkOmaDrmW cHandle);
BOOL CkOmaDrmW_CreateDcfFile(HCkOmaDrmW cHandle, const wchar_t *filename);
BOOL CkOmaDrmW_GetHeaderField(HCkOmaDrmW cHandle, const wchar_t *fieldName, HCkString outVal);
const wchar_t *CkOmaDrmW_getHeaderField(HCkOmaDrmW cHandle, const wchar_t *fieldName);
BOOL CkOmaDrmW_LoadDcfData(HCkOmaDrmW cHandle, HCkByteData data);
BOOL CkOmaDrmW_LoadDcfFile(HCkOmaDrmW cHandle, const wchar_t *filename);
void CkOmaDrmW_LoadUnencryptedData(HCkOmaDrmW cHandle, HCkByteData data);
BOOL CkOmaDrmW_LoadUnencryptedFile(HCkOmaDrmW cHandle, const wchar_t *filename);
BOOL CkOmaDrmW_SaveDecrypted(HCkOmaDrmW cHandle, const wchar_t *filename);
BOOL CkOmaDrmW_SaveLastError(HCkOmaDrmW cHandle, const wchar_t *path);
void CkOmaDrmW_SetEncodedIV(HCkOmaDrmW cHandle, const wchar_t *encodedIv, const wchar_t *encoding);
BOOL CkOmaDrmW_UnlockComponent(HCkOmaDrmW cHandle, const wchar_t *b1);
#endif
