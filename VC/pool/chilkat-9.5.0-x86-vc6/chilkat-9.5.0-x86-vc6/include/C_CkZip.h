// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkZip_H
#define _C_CkZip_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkZip CkZip_Create(void);
void CkZip_Dispose(HCkZip handle);
void CkZip_getAppendFromDir(HCkZip cHandle, HCkString retval);
void CkZip_putAppendFromDir(HCkZip cHandle, const char *newVal);
const char *CkZip_appendFromDir(HCkZip cHandle);
#if defined(CK_SFX_INCLUDED)
void CkZip_getAutoRun(HCkZip cHandle, HCkString retval);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_putAutoRun(HCkZip cHandle, const char *newVal);
#endif
#if defined(CK_SFX_INCLUDED)
const char *CkZip_autoRun(HCkZip cHandle);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_getAutoRunParams(HCkZip cHandle, HCkString retval);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_putAutoRunParams(HCkZip cHandle, const char *newVal);
#endif
#if defined(CK_SFX_INCLUDED)
const char *CkZip_autoRunParams(HCkZip cHandle);
#endif
#if defined(CK_SFX_INCLUDED)
BOOL CkZip_getAutoTemp(HCkZip cHandle);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_putAutoTemp(HCkZip cHandle, BOOL newVal);
#endif
BOOL CkZip_getCaseSensitive(HCkZip cHandle);
void CkZip_putCaseSensitive(HCkZip cHandle, BOOL newVal);
BOOL CkZip_getClearArchiveAttribute(HCkZip cHandle);
void CkZip_putClearArchiveAttribute(HCkZip cHandle, BOOL newVal);
BOOL CkZip_getClearReadOnlyAttr(HCkZip cHandle);
void CkZip_putClearReadOnlyAttr(HCkZip cHandle, BOOL newVal);
void CkZip_getComment(HCkZip cHandle, HCkString retval);
void CkZip_putComment(HCkZip cHandle, const char *newVal);
const char *CkZip_comment(HCkZip cHandle);
void CkZip_getDebugLogFilePath(HCkZip cHandle, HCkString retval);
void CkZip_putDebugLogFilePath(HCkZip cHandle, const char *newVal);
const char *CkZip_debugLogFilePath(HCkZip cHandle);
void CkZip_getDecryptPassword(HCkZip cHandle, HCkString retval);
void CkZip_putDecryptPassword(HCkZip cHandle, const char *newVal);
const char *CkZip_decryptPassword(HCkZip cHandle);
BOOL CkZip_getDiscardPaths(HCkZip cHandle);
void CkZip_putDiscardPaths(HCkZip cHandle, BOOL newVal);
int CkZip_getEncryptKeyLength(HCkZip cHandle);
void CkZip_putEncryptKeyLength(HCkZip cHandle, int newVal);
void CkZip_getEncryptPassword(HCkZip cHandle, HCkString retval);
void CkZip_putEncryptPassword(HCkZip cHandle, const char *newVal);
const char *CkZip_encryptPassword(HCkZip cHandle);
int CkZip_getEncryption(HCkZip cHandle);
void CkZip_putEncryption(HCkZip cHandle, int newVal);
#if defined(CK_SFX_INCLUDED)
void CkZip_getExeDefaultDir(HCkZip cHandle, HCkString retval);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_putExeDefaultDir(HCkZip cHandle, const char *newVal);
#endif
#if defined(CK_SFX_INCLUDED)
const char *CkZip_exeDefaultDir(HCkZip cHandle);
#endif
#if defined(CK_SFX_INCLUDED)
BOOL CkZip_getExeFinishNotifier(HCkZip cHandle);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_putExeFinishNotifier(HCkZip cHandle, BOOL newVal);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_getExeIconFile(HCkZip cHandle, HCkString retval);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_putExeIconFile(HCkZip cHandle, const char *newVal);
#endif
#if defined(CK_SFX_INCLUDED)
const char *CkZip_exeIconFile(HCkZip cHandle);
#endif
#if defined(CK_SFX_INCLUDED)
BOOL CkZip_getExeNoInterface(HCkZip cHandle);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_putExeNoInterface(HCkZip cHandle, BOOL newVal);
#endif
#if defined(CK_SFX_INCLUDED)
BOOL CkZip_getExeSilentProgress(HCkZip cHandle);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_putExeSilentProgress(HCkZip cHandle, BOOL newVal);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_getExeTitle(HCkZip cHandle, HCkString retval);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_putExeTitle(HCkZip cHandle, const char *newVal);
#endif
#if defined(CK_SFX_INCLUDED)
const char *CkZip_exeTitle(HCkZip cHandle);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_getExeUnzipCaption(HCkZip cHandle, HCkString retval);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_putExeUnzipCaption(HCkZip cHandle, const char *newVal);
#endif
#if defined(CK_SFX_INCLUDED)
const char *CkZip_exeUnzipCaption(HCkZip cHandle);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_getExeUnzipDir(HCkZip cHandle, HCkString retval);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_putExeUnzipDir(HCkZip cHandle, const char *newVal);
#endif
#if defined(CK_SFX_INCLUDED)
const char *CkZip_exeUnzipDir(HCkZip cHandle);
#endif
#if defined(CK_SFX_INCLUDED)
BOOL CkZip_getExeWaitForSetup(HCkZip cHandle);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_putExeWaitForSetup(HCkZip cHandle, BOOL newVal);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_getExeXmlConfig(HCkZip cHandle, HCkString retval);
#endif
#if defined(CK_SFX_INCLUDED)
void CkZip_putExeXmlConfig(HCkZip cHandle, const char *newVal);
#endif
#if defined(CK_SFX_INCLUDED)
const char *CkZip_exeXmlConfig(HCkZip cHandle);
#endif
int CkZip_getFileCount(HCkZip cHandle);
void CkZip_getFileName(HCkZip cHandle, HCkString retval);
void CkZip_putFileName(HCkZip cHandle, const char *newVal);
const char *CkZip_fileName(HCkZip cHandle);
BOOL CkZip_getHasZipFormatErrors(HCkZip cHandle);
int CkZip_getHeartbeatMs(HCkZip cHandle);
void CkZip_putHeartbeatMs(HCkZip cHandle, int newVal);
BOOL CkZip_getIgnoreAccessDenied(HCkZip cHandle);
void CkZip_putIgnoreAccessDenied(HCkZip cHandle, BOOL newVal);
void CkZip_getLastErrorHtml(HCkZip cHandle, HCkString retval);
const char *CkZip_lastErrorHtml(HCkZip cHandle);
void CkZip_getLastErrorText(HCkZip cHandle, HCkString retval);
const char *CkZip_lastErrorText(HCkZip cHandle);
void CkZip_getLastErrorXml(HCkZip cHandle, HCkString retval);
const char *CkZip_lastErrorXml(HCkZip cHandle);
int CkZip_getNumEntries(HCkZip cHandle);
int CkZip_getOemCodePage(HCkZip cHandle);
void CkZip_putOemCodePage(HCkZip cHandle, int newVal);
BOOL CkZip_getOverwriteExisting(HCkZip cHandle);
void CkZip_putOverwriteExisting(HCkZip cHandle, BOOL newVal);
BOOL CkZip_getPasswordProtect(HCkZip cHandle);
void CkZip_putPasswordProtect(HCkZip cHandle, BOOL newVal);
void CkZip_getPathPrefix(HCkZip cHandle, HCkString retval);
void CkZip_putPathPrefix(HCkZip cHandle, const char *newVal);
const char *CkZip_pathPrefix(HCkZip cHandle);
void CkZip_getTempDir(HCkZip cHandle, HCkString retval);
void CkZip_putTempDir(HCkZip cHandle, const char *newVal);
const char *CkZip_tempDir(HCkZip cHandle);
BOOL CkZip_getTextFlag(HCkZip cHandle);
void CkZip_putTextFlag(HCkZip cHandle, BOOL newVal);
BOOL CkZip_getUtf8(HCkZip cHandle);
void CkZip_putUtf8(HCkZip cHandle, BOOL newVal);
BOOL CkZip_getVerboseLogging(HCkZip cHandle);
void CkZip_putVerboseLogging(HCkZip cHandle, BOOL newVal);
void CkZip_getVersion(HCkZip cHandle, HCkString retval);
const char *CkZip_version(HCkZip cHandle);
BOOL CkZip_getZipx(HCkZip cHandle);
void CkZip_putZipx(HCkZip cHandle, BOOL newVal);
void CkZip_getZipxDefaultAlg(HCkZip cHandle, HCkString retval);
void CkZip_putZipxDefaultAlg(HCkZip cHandle, const char *newVal);
const char *CkZip_zipxDefaultAlg(HCkZip cHandle);
#if defined(CK_SFX_INCLUDED)
BOOL CkZip_AddEmbedded(HCkZip cHandle, const char *exeFilename, const char *resourceName, const char *zipFilename);
#endif
void CkZip_AddNoCompressExtension(HCkZip cHandle, const char *fileExtension);
HCkZipEntry CkZip_AppendBase64(HCkZip cHandle, const char *fileName, const char *encodedCompressedData);
HCkZipEntry CkZip_AppendCompressed(HCkZip cHandle, const char *filename, HCkByteData inData);
HCkZipEntry CkZip_AppendData(HCkZip cHandle, const char *fileName, HCkByteData inData);
BOOL CkZip_AppendFiles(HCkZip cHandle, const char *filePattern, BOOL recurse);
BOOL CkZip_AppendFilesEx(HCkZip cHandle, const char *filePattern, BOOL recurse, BOOL saveExtraPath, BOOL archiveOnly, BOOL includeHidden, BOOL includeSystem);
HCkZipEntry CkZip_AppendHex(HCkZip cHandle, const char *fileName, const char *encodedCompressedData);
BOOL CkZip_AppendMultiple(HCkZip cHandle, HCkStringArray fileSpecs, BOOL recurse);
HCkZipEntry CkZip_AppendNew(HCkZip cHandle, const char *fileName);
HCkZipEntry CkZip_AppendNewDir(HCkZip cHandle, const char *dirName);
BOOL CkZip_AppendOneFileOrDir(HCkZip cHandle, const char *fileOrDirPath, BOOL saveExtraPath);
HCkZipEntry CkZip_AppendString(HCkZip cHandle, const char *internalZipFilepath, const char *textData);
HCkZipEntry CkZip_AppendString2(HCkZip cHandle, const char *internalZipFilepath, const char *textData, const char *charset);
BOOL CkZip_AppendZip(HCkZip cHandle, const char *zipFileName);
void CkZip_CloseZip(HCkZip cHandle);
BOOL CkZip_DeleteEntry(HCkZip cHandle, HCkZipEntry entry);
void CkZip_ExcludeDir(HCkZip cHandle, const char *dirName);
BOOL CkZip_Extract(HCkZip cHandle, const char *dirPath);
BOOL CkZip_ExtractInto(HCkZip cHandle, const char *dirPath);
BOOL CkZip_ExtractMatching(HCkZip cHandle, const char *dirPath, const char *pattern);
BOOL CkZip_ExtractNewer(HCkZip cHandle, const char *dirPath);
BOOL CkZip_ExtractOne(HCkZip cHandle, HCkZipEntry entry, const char *dirPath);
HCkZipEntry CkZip_FirstEntry(HCkZip cHandle);
HCkZipEntry CkZip_FirstMatchingEntry(HCkZip cHandle, const char *pattern);
BOOL CkZip_GetDirectoryAsXML(HCkZip cHandle, HCkString outXml);
const char *CkZip_getDirectoryAsXML(HCkZip cHandle);
HCkZipEntry CkZip_GetEntryByID(HCkZip cHandle, int entryID);
HCkZipEntry CkZip_GetEntryByIndex(HCkZip cHandle, int index);
HCkZipEntry CkZip_GetEntryByName(HCkZip cHandle, const char *entryName);
HCkStringArray CkZip_GetExclusions(HCkZip cHandle);
#if defined(CK_SFX_INCLUDED)
BOOL CkZip_GetExeConfigParam(HCkZip cHandle, const char *name, HCkString outStr);
#endif
#if defined(CK_SFX_INCLUDED)
const char *CkZip_getExeConfigParam(HCkZip cHandle, const char *name);
#endif
HCkZipEntry CkZip_InsertNew(HCkZip cHandle, const char *fileName, int beforeIndex);
BOOL CkZip_IsNoCompressExtension(HCkZip cHandle, const char *fileExtension);
BOOL CkZip_IsPasswordProtected(HCkZip cHandle, const char *zipFilename);
BOOL CkZip_IsUnlocked(HCkZip cHandle);
BOOL CkZip_NewZip(HCkZip cHandle, const char *zipFilePath);
#if defined(CK_SFX_INCLUDED)
BOOL CkZip_OpenEmbedded(HCkZip cHandle, const char *exeFilename, const char *resourceName);
#endif
BOOL CkZip_OpenFromByteData(HCkZip cHandle, HCkByteData byteData);
BOOL CkZip_OpenFromMemory(HCkZip cHandle, HCkByteData inData);
#if defined(CK_SFX_INCLUDED)
BOOL CkZip_OpenMyEmbedded(HCkZip cHandle, const char *resourceName);
#endif
BOOL CkZip_OpenZip(HCkZip cHandle, const char *ZipFileName);
BOOL CkZip_QuickAppend(HCkZip cHandle, const char *ZipFileName);
#if defined(CK_SFX_INCLUDED)
BOOL CkZip_RemoveEmbedded(HCkZip cHandle, const char *exeFilename, const char *resourceName);
#endif
void CkZip_RemoveNoCompressExtension(HCkZip cHandle, const char *fileExtension);
#if defined(CK_SFX_INCLUDED)
BOOL CkZip_ReplaceEmbedded(HCkZip cHandle, const char *exeFilename, const char *resourceName, const char *zipFilename);
#endif
BOOL CkZip_SaveLastError(HCkZip cHandle, const char *path);
void CkZip_SetCompressionLevel(HCkZip cHandle, int level);
void CkZip_SetExclusions(HCkZip cHandle, HCkStringArray excludePatterns);
#if defined(CK_SFX_INCLUDED)
void CkZip_SetExeConfigParam(HCkZip cHandle, const char *paramName, const char *paramValue);
#endif
void CkZip_SetPassword(HCkZip cHandle, const char *password);
BOOL CkZip_UnlockComponent(HCkZip cHandle, const char *regCode);
int CkZip_Unzip(HCkZip cHandle, const char *dirPath);
int CkZip_UnzipInto(HCkZip cHandle, const char *dirPath);
int CkZip_UnzipMatching(HCkZip cHandle, const char *dirPath, const char *pattern, BOOL verbose);
int CkZip_UnzipMatchingInto(HCkZip cHandle, const char *dirPath, const char *pattern, BOOL verbose);
int CkZip_UnzipNewer(HCkZip cHandle, const char *dirPath);
BOOL CkZip_VerifyPassword(HCkZip cHandle);
#if defined(CK_SFX_INCLUDED)
BOOL CkZip_WriteExe(HCkZip cHandle, const char *exeFilename);
#endif
#if defined(CK_SFX_INCLUDED)
BOOL CkZip_WriteExe2(HCkZip cHandle, const char *exePath, const char *destExePath, BOOL bAesEncrypt, int keyLength, const char *password);
#endif
#if defined(CK_SFX_INCLUDED)
BOOL CkZip_WriteExeToMemory(HCkZip cHandle, HCkByteData outBytes);
#endif
BOOL CkZip_WriteToMemory(HCkZip cHandle, HCkByteData outData);
BOOL CkZip_WriteZip(HCkZip cHandle);
BOOL CkZip_WriteZipAndClose(HCkZip cHandle);
#endif
