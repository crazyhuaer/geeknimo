// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkFileAccessWH
#define _C_CkFileAccessWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkFileAccessW CkFileAccessW_Create(void);
void CkFileAccessW_Dispose(HCkFileAccessW handle);
void CkFileAccessW_getCurrentDir(HCkFileAccessW cHandle, HCkString retval);
const wchar_t *CkFileAccessW_currentDir(HCkFileAccessW cHandle);
void CkFileAccessW_getDebugLogFilePath(HCkFileAccessW cHandle, HCkString retval);
void CkFileAccessW_putDebugLogFilePath(HCkFileAccessW cHandle, const wchar_t *newVal);
const wchar_t *CkFileAccessW_debugLogFilePath(HCkFileAccessW cHandle);
BOOL CkFileAccessW_getEndOfFile(HCkFileAccessW cHandle);
int CkFileAccessW_getFileOpenError(HCkFileAccessW cHandle);
void CkFileAccessW_getFileOpenErrorMsg(HCkFileAccessW cHandle, HCkString retval);
const wchar_t *CkFileAccessW_fileOpenErrorMsg(HCkFileAccessW cHandle);
void CkFileAccessW_getLastErrorHtml(HCkFileAccessW cHandle, HCkString retval);
const wchar_t *CkFileAccessW_lastErrorHtml(HCkFileAccessW cHandle);
void CkFileAccessW_getLastErrorText(HCkFileAccessW cHandle, HCkString retval);
const wchar_t *CkFileAccessW_lastErrorText(HCkFileAccessW cHandle);
void CkFileAccessW_getLastErrorXml(HCkFileAccessW cHandle, HCkString retval);
const wchar_t *CkFileAccessW_lastErrorXml(HCkFileAccessW cHandle);
BOOL CkFileAccessW_getVerboseLogging(HCkFileAccessW cHandle);
void CkFileAccessW_putVerboseLogging(HCkFileAccessW cHandle, BOOL newVal);
void CkFileAccessW_getVersion(HCkFileAccessW cHandle, HCkString retval);
const wchar_t *CkFileAccessW_version(HCkFileAccessW cHandle);
BOOL CkFileAccessW_AppendAnsi(HCkFileAccessW cHandle, const wchar_t *text);
BOOL CkFileAccessW_AppendText(HCkFileAccessW cHandle, const wchar_t *str, const wchar_t *charset);
BOOL CkFileAccessW_AppendUnicodeBOM(HCkFileAccessW cHandle);
BOOL CkFileAccessW_AppendUtf8BOM(HCkFileAccessW cHandle);
BOOL CkFileAccessW_DirAutoCreate(HCkFileAccessW cHandle, const wchar_t *dirPath);
BOOL CkFileAccessW_DirCreate(HCkFileAccessW cHandle, const wchar_t *dirPath);
BOOL CkFileAccessW_DirDelete(HCkFileAccessW cHandle, const wchar_t *dirPath);
BOOL CkFileAccessW_DirEnsureExists(HCkFileAccessW cHandle, const wchar_t *filePath);
void CkFileAccessW_FileClose(HCkFileAccessW cHandle);
BOOL CkFileAccessW_FileContentsEqual(HCkFileAccessW cHandle, const wchar_t *filePath1, const wchar_t *filePath2);
BOOL CkFileAccessW_FileCopy(HCkFileAccessW cHandle, const wchar_t *existingFilepath, const wchar_t *newFilepath, BOOL failIfExists);
BOOL CkFileAccessW_FileDelete(HCkFileAccessW cHandle, const wchar_t *filePath);
BOOL CkFileAccessW_FileExists(HCkFileAccessW cHandle, const wchar_t *filePath);
BOOL CkFileAccessW_FileOpen(HCkFileAccessW cHandle, const wchar_t *filePath, unsigned long accessMode, unsigned long shareMode, unsigned long createDisposition, unsigned long attributes);
BOOL CkFileAccessW_FileRead(HCkFileAccessW cHandle, int maxNumBytes, HCkByteData outBytes);
BOOL CkFileAccessW_FileRename(HCkFileAccessW cHandle, const wchar_t *existingFilepath, const wchar_t *newFilepath);
BOOL CkFileAccessW_FileSeek(HCkFileAccessW cHandle, int offset, int origin);
int CkFileAccessW_FileSize(HCkFileAccessW cHandle, const wchar_t *filePath);
BOOL CkFileAccessW_FileWrite(HCkFileAccessW cHandle, HCkByteData data);
BOOL CkFileAccessW_GetTempFilename(HCkFileAccessW cHandle, const wchar_t *dirPath, const wchar_t *prefix, HCkString outStr);
const wchar_t *CkFileAccessW_getTempFilename(HCkFileAccessW cHandle, const wchar_t *dirPath, const wchar_t *prefix);
BOOL CkFileAccessW_OpenForAppend(HCkFileAccessW cHandle, const wchar_t *filePath);
BOOL CkFileAccessW_OpenForRead(HCkFileAccessW cHandle, const wchar_t *filePath);
BOOL CkFileAccessW_OpenForReadWrite(HCkFileAccessW cHandle, const wchar_t *filePath);
BOOL CkFileAccessW_OpenForWrite(HCkFileAccessW cHandle, const wchar_t *filePath);
BOOL CkFileAccessW_ReadBinaryToEncoded(HCkFileAccessW cHandle, const wchar_t *filePath, const wchar_t *encoding, HCkString outStr);
const wchar_t *CkFileAccessW_readBinaryToEncoded(HCkFileAccessW cHandle, const wchar_t *filePath, const wchar_t *encoding);
BOOL CkFileAccessW_ReadEntireFile(HCkFileAccessW cHandle, const wchar_t *filePath, HCkByteData outBytes);
BOOL CkFileAccessW_ReadEntireTextFile(HCkFileAccessW cHandle, const wchar_t *filePath, const wchar_t *charset, HCkString outStrFileContents);
const wchar_t *CkFileAccessW_readEntireTextFile(HCkFileAccessW cHandle, const wchar_t *filePath, const wchar_t *charset);
BOOL CkFileAccessW_ReassembleFile(HCkFileAccessW cHandle, const wchar_t *partsDirPath, const wchar_t *partPrefix, const wchar_t *partExtension, const wchar_t *reassembledFilename);
int CkFileAccessW_ReplaceStrings(HCkFileAccessW cHandle, const wchar_t *filePath, const wchar_t *charset, const wchar_t *existingString, const wchar_t *replacementString);
BOOL CkFileAccessW_SaveLastError(HCkFileAccessW cHandle, const wchar_t *path);
BOOL CkFileAccessW_SetCurrentDir(HCkFileAccessW cHandle, const wchar_t *dirPath);
BOOL CkFileAccessW_SetFileTimes(HCkFileAccessW cHandle, const wchar_t *filePath, HCkDateTimeW createTime, HCkDateTimeW lastAccessTime, HCkDateTimeW lastModTime);
BOOL CkFileAccessW_SetLastModified(HCkFileAccessW cHandle, const wchar_t *filePath, HCkDateTimeW lastModified);
BOOL CkFileAccessW_SplitFile(HCkFileAccessW cHandle, const wchar_t *fileToSplit, const wchar_t *partPrefix, const wchar_t *partExtension, int partSize, const wchar_t *destDir);
BOOL CkFileAccessW_TreeDelete(HCkFileAccessW cHandle, const wchar_t *path);
BOOL CkFileAccessW_WriteEntireFile(HCkFileAccessW cHandle, const wchar_t *filePath, HCkByteData fileData);
BOOL CkFileAccessW_WriteEntireTextFile(HCkFileAccessW cHandle, const wchar_t *filePath, const wchar_t *textData, const wchar_t *charset, BOOL includedPreamble);
#endif
