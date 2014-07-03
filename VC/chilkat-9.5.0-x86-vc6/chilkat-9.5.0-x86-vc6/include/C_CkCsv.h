// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCsv_H
#define _C_CkCsv_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCsv CkCsv_Create(void);
void CkCsv_Dispose(HCkCsv handle);
BOOL CkCsv_getAutoTrim(HCkCsv cHandle);
void CkCsv_putAutoTrim(HCkCsv cHandle, BOOL newVal);
BOOL CkCsv_getCrlf(HCkCsv cHandle);
void CkCsv_putCrlf(HCkCsv cHandle, BOOL newVal);
void CkCsv_getDebugLogFilePath(HCkCsv cHandle, HCkString retval);
void CkCsv_putDebugLogFilePath(HCkCsv cHandle, const char *newVal);
const char *CkCsv_debugLogFilePath(HCkCsv cHandle);
void CkCsv_getDelimiter(HCkCsv cHandle, HCkString retval);
void CkCsv_putDelimiter(HCkCsv cHandle, const char *newVal);
const char *CkCsv_delimiter(HCkCsv cHandle);
BOOL CkCsv_getHasColumnNames(HCkCsv cHandle);
void CkCsv_putHasColumnNames(HCkCsv cHandle, BOOL newVal);
void CkCsv_getLastErrorHtml(HCkCsv cHandle, HCkString retval);
const char *CkCsv_lastErrorHtml(HCkCsv cHandle);
void CkCsv_getLastErrorText(HCkCsv cHandle, HCkString retval);
const char *CkCsv_lastErrorText(HCkCsv cHandle);
void CkCsv_getLastErrorXml(HCkCsv cHandle, HCkString retval);
const char *CkCsv_lastErrorXml(HCkCsv cHandle);
int CkCsv_getNumColumns(HCkCsv cHandle);
int CkCsv_getNumRows(HCkCsv cHandle);
BOOL CkCsv_getUtf8(HCkCsv cHandle);
void CkCsv_putUtf8(HCkCsv cHandle, BOOL newVal);
BOOL CkCsv_getVerboseLogging(HCkCsv cHandle);
void CkCsv_putVerboseLogging(HCkCsv cHandle, BOOL newVal);
void CkCsv_getVersion(HCkCsv cHandle, HCkString retval);
const char *CkCsv_version(HCkCsv cHandle);
BOOL CkCsv_DeleteColumn(HCkCsv cHandle, int index);
BOOL CkCsv_DeleteColumnByName(HCkCsv cHandle, const char *columnName);
BOOL CkCsv_DeleteRow(HCkCsv cHandle, int index);
BOOL CkCsv_GetCell(HCkCsv cHandle, int row, int col, HCkString outStr);
const char *CkCsv_getCell(HCkCsv cHandle, int row, int col);
BOOL CkCsv_GetCellByName(HCkCsv cHandle, int rowIndex, const char *columnName, HCkString outStr);
const char *CkCsv_getCellByName(HCkCsv cHandle, int rowIndex, const char *columnName);
BOOL CkCsv_GetColumnName(HCkCsv cHandle, int index, HCkString outStr);
const char *CkCsv_getColumnName(HCkCsv cHandle, int index);
int CkCsv_GetIndex(HCkCsv cHandle, const char *columnName);
int CkCsv_GetNumCols(HCkCsv cHandle, int row);
BOOL CkCsv_LoadFile(HCkCsv cHandle, const char *path);
BOOL CkCsv_LoadFile2(HCkCsv cHandle, const char *filename, const char *charset);
BOOL CkCsv_LoadFromString(HCkCsv cHandle, const char *csvData);
BOOL CkCsv_RowMatches(HCkCsv cHandle, int rowIndex, const char *matchPattern, BOOL caseSensitive);
BOOL CkCsv_SaveFile(HCkCsv cHandle, const char *path);
BOOL CkCsv_SaveFile2(HCkCsv cHandle, const char *filename, const char *charset);
BOOL CkCsv_SaveLastError(HCkCsv cHandle, const char *path);
BOOL CkCsv_SaveToString(HCkCsv cHandle, HCkString outStr);
const char *CkCsv_saveToString(HCkCsv cHandle);
BOOL CkCsv_SetCell(HCkCsv cHandle, int row, int col, const char *content);
BOOL CkCsv_SetCellByName(HCkCsv cHandle, int rowIndex, const char *columnName, const char *contentStr);
BOOL CkCsv_SetColumnName(HCkCsv cHandle, int index, const char *columnName);
BOOL CkCsv_SortByColumn(HCkCsv cHandle, const char *columnName, BOOL ascending, BOOL caseSensitive);
#endif
