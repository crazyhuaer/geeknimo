// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkByteData_H
#define _C_CkByteData_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkByteData CkByteData_Create(void);
void CkByteData_Dispose(HCkByteData handle);
void CkByteData_append(HCkByteData cHandle, HCkByteData db);
void CkByteData_append2(HCkByteData cHandle, const void *pByteData, unsigned long szByteData);
void CkByteData_appendChar(HCkByteData cHandle, char ch);
void CkByteData_appendCharN(HCkByteData cHandle, char ch, int numTimes);
void CkByteData_appendEncoded(HCkByteData cHandle, const char *str, const char *encoding);
void CkByteData_appendEncodedW(HCkByteData cHandle, const wchar_t *str, const wchar_t *encoding);
BOOL CkByteData_appendFile(HCkByteData cHandle, const char *path);
BOOL CkByteData_appendFileW(HCkByteData cHandle, const wchar_t *path);
void CkByteData_appendInt(HCkByteData cHandle, int intValue, BOOL littleEndian);
void CkByteData_appendRandom(HCkByteData cHandle, int numBytes);
void CkByteData_appendRange(HCkByteData cHandle, HCkByteData byteData, unsigned long index, unsigned long numBytes);
void CkByteData_appendShort(HCkByteData cHandle, short shortValue, BOOL littleEndian);
void CkByteData_appendStr(HCkByteData cHandle, const char *str);
void CkByteData_appendStrW(HCkByteData cHandle, const wchar_t *str, const wchar_t *charset);
BOOL CkByteData_beginsWith(HCkByteData cHandle, HCkByteData byteDataObj);
BOOL CkByteData_beginsWith2(HCkByteData cHandle, const void *pByteData, unsigned long szByteData);
void CkByteData_borrowData(HCkByteData cHandle, void *pByteData, unsigned long szByteData);
void CkByteData_byteSwap4321(HCkByteData cHandle);
void CkByteData_clear(HCkByteData cHandle);
void CkByteData_encode(HCkByteData cHandle, const char *encoding, HCkString str);
void CkByteData_encodeW(HCkByteData cHandle, const wchar_t *encoding, HCkString str);
void CkByteData_ensureBuffer(HCkByteData cHandle, unsigned long expectedNumBytes);
BOOL CkByteData_equals(HCkByteData cHandle, HCkByteData compareBytes);
BOOL CkByteData_equals2(HCkByteData cHandle, const void *pCompareBytes, unsigned long numBytes);
int CkByteData_findBytes(HCkByteData cHandle, HCkByteData byteDataObj);
int CkByteData_findBytes2(HCkByteData cHandle, const void *findBytes, unsigned long findBytesLen);
unsigned char CkByteData_getByte(HCkByteData cHandle, unsigned long byteIndex);
const unsigned char *CkByteData_getBytes(HCkByteData cHandle);
char CkByteData_getChar(HCkByteData cHandle, unsigned long byteIndex);
const unsigned char *CkByteData_getData(HCkByteData cHandle);
const unsigned char *CkByteData_getDataAt(HCkByteData cHandle, unsigned long byteIndex);
const wchar_t *CkByteData_getEncodedW(HCkByteData cHandle, const wchar_t *encoding);
int CkByteData_getInt(HCkByteData cHandle, unsigned long byteIndex);
const unsigned char *CkByteData_getRange(HCkByteData cHandle, unsigned long byteIndex, unsigned long numBytes);
short CkByteData_getShort(HCkByteData cHandle, unsigned long byteIndex);
unsigned long CkByteData_getSize(HCkByteData cHandle);
unsigned int CkByteData_getUInt(HCkByteData cHandle, unsigned long byteIndex);
unsigned short CkByteData_getUShort(HCkByteData cHandle, unsigned long byteIndex);
BOOL CkByteData_is7bit(HCkByteData cHandle);
BOOL CkByteData_loadFile(HCkByteData cHandle, const char *path);
BOOL CkByteData_loadFileW(HCkByteData cHandle, const wchar_t *path);
void CkByteData_pad(HCkByteData cHandle, int blockSize, int paddingScheme);
BOOL CkByteData_preAllocate(HCkByteData cHandle, unsigned long expectedNumBytes);
void CkByteData_removeChunk(HCkByteData cHandle, unsigned long startIndex, unsigned long numBytes);
unsigned char *CkByteData_removeData(HCkByteData cHandle);
void CkByteData_replaceChar(HCkByteData cHandle, unsigned char existingByteValue, unsigned char replacementByteValue);
BOOL CkByteData_saveFile(HCkByteData cHandle, const char *path);
BOOL CkByteData_saveFileW(HCkByteData cHandle, const wchar_t *path);
void CkByteData_shorten(HCkByteData cHandle, unsigned long numBytes);
const wchar_t *CkByteData_to_ws(HCkByteData cHandle, const char *charset);
void CkByteData_unpad(HCkByteData cHandle, int blockSize, int paddingScheme);
#endif
