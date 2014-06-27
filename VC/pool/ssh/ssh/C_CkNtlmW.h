// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkNtlmWH
#define _C_CkNtlmWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkNtlmW CkNtlmW_Create(void);
void CkNtlmW_Dispose(HCkNtlmW handle);
void CkNtlmW_getClientChallenge(HCkNtlmW cHandle, HCkString retval);
void CkNtlmW_putClientChallenge(HCkNtlmW cHandle, const wchar_t *newVal);
const wchar_t *CkNtlmW_clientChallenge(HCkNtlmW cHandle);
void CkNtlmW_getDebugLogFilePath(HCkNtlmW cHandle, HCkString retval);
void CkNtlmW_putDebugLogFilePath(HCkNtlmW cHandle, const wchar_t *newVal);
const wchar_t *CkNtlmW_debugLogFilePath(HCkNtlmW cHandle);
void CkNtlmW_getDnsComputerName(HCkNtlmW cHandle, HCkString retval);
void CkNtlmW_putDnsComputerName(HCkNtlmW cHandle, const wchar_t *newVal);
const wchar_t *CkNtlmW_dnsComputerName(HCkNtlmW cHandle);
void CkNtlmW_getDnsDomainName(HCkNtlmW cHandle, HCkString retval);
void CkNtlmW_putDnsDomainName(HCkNtlmW cHandle, const wchar_t *newVal);
const wchar_t *CkNtlmW_dnsDomainName(HCkNtlmW cHandle);
void CkNtlmW_getDomain(HCkNtlmW cHandle, HCkString retval);
void CkNtlmW_putDomain(HCkNtlmW cHandle, const wchar_t *newVal);
const wchar_t *CkNtlmW_domain(HCkNtlmW cHandle);
void CkNtlmW_getEncodingMode(HCkNtlmW cHandle, HCkString retval);
void CkNtlmW_putEncodingMode(HCkNtlmW cHandle, const wchar_t *newVal);
const wchar_t *CkNtlmW_encodingMode(HCkNtlmW cHandle);
void CkNtlmW_getFlags(HCkNtlmW cHandle, HCkString retval);
void CkNtlmW_putFlags(HCkNtlmW cHandle, const wchar_t *newVal);
const wchar_t *CkNtlmW_flags(HCkNtlmW cHandle);
void CkNtlmW_getLastErrorHtml(HCkNtlmW cHandle, HCkString retval);
const wchar_t *CkNtlmW_lastErrorHtml(HCkNtlmW cHandle);
void CkNtlmW_getLastErrorText(HCkNtlmW cHandle, HCkString retval);
const wchar_t *CkNtlmW_lastErrorText(HCkNtlmW cHandle);
void CkNtlmW_getLastErrorXml(HCkNtlmW cHandle, HCkString retval);
const wchar_t *CkNtlmW_lastErrorXml(HCkNtlmW cHandle);
void CkNtlmW_getNetBiosComputerName(HCkNtlmW cHandle, HCkString retval);
void CkNtlmW_putNetBiosComputerName(HCkNtlmW cHandle, const wchar_t *newVal);
const wchar_t *CkNtlmW_netBiosComputerName(HCkNtlmW cHandle);
void CkNtlmW_getNetBiosDomainName(HCkNtlmW cHandle, HCkString retval);
void CkNtlmW_putNetBiosDomainName(HCkNtlmW cHandle, const wchar_t *newVal);
const wchar_t *CkNtlmW_netBiosDomainName(HCkNtlmW cHandle);
int CkNtlmW_getNtlmVersion(HCkNtlmW cHandle);
void CkNtlmW_putNtlmVersion(HCkNtlmW cHandle, int newVal);
int CkNtlmW_getOemCodePage(HCkNtlmW cHandle);
void CkNtlmW_putOemCodePage(HCkNtlmW cHandle, int newVal);
void CkNtlmW_getPassword(HCkNtlmW cHandle, HCkString retval);
void CkNtlmW_putPassword(HCkNtlmW cHandle, const wchar_t *newVal);
const wchar_t *CkNtlmW_password(HCkNtlmW cHandle);
void CkNtlmW_getServerChallenge(HCkNtlmW cHandle, HCkString retval);
void CkNtlmW_putServerChallenge(HCkNtlmW cHandle, const wchar_t *newVal);
const wchar_t *CkNtlmW_serverChallenge(HCkNtlmW cHandle);
void CkNtlmW_getTargetName(HCkNtlmW cHandle, HCkString retval);
void CkNtlmW_putTargetName(HCkNtlmW cHandle, const wchar_t *newVal);
const wchar_t *CkNtlmW_targetName(HCkNtlmW cHandle);
void CkNtlmW_getUserName(HCkNtlmW cHandle, HCkString retval);
void CkNtlmW_putUserName(HCkNtlmW cHandle, const wchar_t *newVal);
const wchar_t *CkNtlmW_userName(HCkNtlmW cHandle);
BOOL CkNtlmW_getVerboseLogging(HCkNtlmW cHandle);
void CkNtlmW_putVerboseLogging(HCkNtlmW cHandle, BOOL newVal);
void CkNtlmW_getVersion(HCkNtlmW cHandle, HCkString retval);
const wchar_t *CkNtlmW_version(HCkNtlmW cHandle);
void CkNtlmW_getWorkstation(HCkNtlmW cHandle, HCkString retval);
void CkNtlmW_putWorkstation(HCkNtlmW cHandle, const wchar_t *newVal);
const wchar_t *CkNtlmW_workstation(HCkNtlmW cHandle);
BOOL CkNtlmW_CompareType3(HCkNtlmW cHandle, const wchar_t *msg1, const wchar_t *msg2);
BOOL CkNtlmW_GenType1(HCkNtlmW cHandle, HCkString outStr);
const wchar_t *CkNtlmW_genType1(HCkNtlmW cHandle);
BOOL CkNtlmW_GenType2(HCkNtlmW cHandle, const wchar_t *type1Msg, HCkString outStr);
const wchar_t *CkNtlmW_genType2(HCkNtlmW cHandle, const wchar_t *type1Msg);
BOOL CkNtlmW_GenType3(HCkNtlmW cHandle, const wchar_t *type2Msg, HCkString outStr);
const wchar_t *CkNtlmW_genType3(HCkNtlmW cHandle, const wchar_t *type2Msg);
BOOL CkNtlmW_LoadType3(HCkNtlmW cHandle, const wchar_t *type3Msg);
BOOL CkNtlmW_ParseType1(HCkNtlmW cHandle, const wchar_t *type1Msg, HCkString outStr);
const wchar_t *CkNtlmW_parseType1(HCkNtlmW cHandle, const wchar_t *type1Msg);
BOOL CkNtlmW_ParseType2(HCkNtlmW cHandle, const wchar_t *type2Msg, HCkString outStr);
const wchar_t *CkNtlmW_parseType2(HCkNtlmW cHandle, const wchar_t *type2Msg);
BOOL CkNtlmW_ParseType3(HCkNtlmW cHandle, const wchar_t *type3Msg, HCkString outStr);
const wchar_t *CkNtlmW_parseType3(HCkNtlmW cHandle, const wchar_t *type3Msg);
BOOL CkNtlmW_SaveLastError(HCkNtlmW cHandle, const wchar_t *path);
BOOL CkNtlmW_SetFlag(HCkNtlmW cHandle, const wchar_t *flagLetter, BOOL onOrOff);
BOOL CkNtlmW_UnlockComponent(HCkNtlmW cHandle, const wchar_t *unlockCode);
#endif
