// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkCsvWH
#define _C_CkCsvWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkCsvW CkCsvW_Create(void);
void CkCsvW_Dispose(HCkCsvW handle);
BOOL CkCsvW_getAutoTrim(HCkCsvW cHandle);
void CkCsvW_putAutoTrim(HCkCsvW cHandle, BOOL newVal);
BOOL CkCsvW_getCrlf(HCkCsvW cHandle);
void CkCsvW_putCrlf(HCkCsvW cHandle, BOOL newVal);
void CkCsvW_getDebugLogFilePath(HCkCsvW cHandle, HCkString retval);
void CkCsvW_putDebugLogFilePath(HCkCsvW cHandle, const wchar_t *newVal);
const wchar_t *CkCsvW_debugLogFilePath(HCkCsvW cHandle);
void CkCsvW_getDelimiter(HCkCsvW cHandle, HCkString retval);
void CkCsvW_putDelimiter(HCkCsvW cHandle, const wchar_t *newVal);
const wchar_t *CkCsvW_delimiter(HCkCsvW cHandle);
BOOL CkCsvW_getHasColumnNames(HCkCsvW cHandle);
void CkCsvW_putHasColumnNames(HCkCsvW cHandle, BOOL newVal);
void CkCsvW_getLastErrorHtml(HCkCsvW cHandle, HCkString retval);
const wchar_t *CkCsvW_lastErrorHtml(HCkCsvW cHandle);
void CkCsvW_getLastErrorText(HCkCsvW cHandle, HCkString retval);
const wchar_t *CkCsvW_lastErrorText(HCkCsvW cHandle);
void CkCsvW_getLastErrorXml(HCkCsvW cHandle, HCkString retval);
const wchar_t *CkCsvW_lastErrorXml(HCkCsvW cHandle);
int CkCsvW_getNumColumns(HCkCsvW cHandle);
int CkCsvW_getNumRows(HCkCsvW cHandle);
BOOL CkCsvW_getVerboseLogging(HCkCsvW cHandle);
void CkCsvW_putVerboseLogging(HCkCsvW cHandle, BOOL newVal);
void CkCsvW_getVersion(HCkCsvW cHandle, HCkString retval);
const wchar_t *CkCsvW_version(HCkCsvW cHandle);
BOOL CkCsvW_DeleteColumn(HCkCsvW cHandle, int index);
BOOL CkCsvW_DeleteColumnByName(HCkCsvW cHandle, const wchar_t *columnName);
BOOL CkCsvW_DeleteRow(HCkCsvW cHandle, int index);
BOOL CkCsvW_GetCell(HCkCsvW cHandle, int row, int col, HCkString outStr);
const wchar_t *CkCsvW_getCell(HCkCsvW cHandle, int row, int col);
BOOL CkCsvW_GetCellByName(HCkCsvW cHandle, int rowIndex, const wchar_t *columnName, HCkString outStr);
const wchar_t *CkCsvW_getCellByName(HCkCsvW cHandle, int rowIndex, const wchar_t *columnName);
BOOL CkCsvW_GetColumnName(HCkCsvW cHandle, int index, HCkString outStr);
const wchar_t *CkCsvW_getColumnName(HCkCsvW cHandle, int index);
int CkCsvW_GetIndex(HCkCsvW cHandle, const wchar_t *columnName);
int CkCsvW_GetNumCols(HCkCsvW cHandle, int row);
BOOL CkCsvW_LoadFile(HCkCsvW cHandle, const wchar_t *path);
BOOL CkCsvW_LoadFile2(HCkCsvW cHandle, const wchar_t *filename, const wchar_t *charset);
BOOL CkCsvW_LoadFromString(HCkCsvW cHandle, const wchar_t *csvData);
BOOL CkCsvW_RowMatches(HCkCsvW cHandle, int rowIndex, const wchar_t *matchPattern, BOOL caseSensitive);
BOOL CkCsvW_SaveFile(HCkCsvW cHandle, const wchar_t *path);
BOOL CkCsvW_SaveFile2(HCkCsvW cHandle, const wchar_t *filename, const wchar_t *charset);
BOOL CkCsvW_SaveLastError(HCkCsvW cHandle, const wchar_t *path);
BOOL CkCsvW_SaveToString(HCkCsvW cHandle, HCkString outStr);
const wchar_t *CkCsvW_saveToString(HCkCsvW cHandle);
BOOL CkCsvW_SetCell(HCkCsvW cHandle, int row, int col, const wchar_t *content);
BOOL CkCsvW_SetCellByName(HCkCsvW cHandle, int rowIndex, const wchar_t *columnName, const wchar_t *contentStr);
BOOL CkCsvW_SetColumnName(HCkCsvW cHandle, int index, const wchar_t *columnName);
BOOL CkCsvW_SortByColumn(HCkCsvW cHandle, const wchar_t *columnName, BOOL ascending, BOOL caseSensitive);
#endif
