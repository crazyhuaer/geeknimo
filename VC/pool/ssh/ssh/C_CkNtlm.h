// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkNtlm_H
#define _C_CkNtlm_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkNtlm CkNtlm_Create(void);
void CkNtlm_Dispose(HCkNtlm handle);
void CkNtlm_getClientChallenge(HCkNtlm cHandle, HCkString retval);
void CkNtlm_putClientChallenge(HCkNtlm cHandle, const char *newVal);
const char *CkNtlm_clientChallenge(HCkNtlm cHandle);
void CkNtlm_getDebugLogFilePath(HCkNtlm cHandle, HCkString retval);
void CkNtlm_putDebugLogFilePath(HCkNtlm cHandle, const char *newVal);
const char *CkNtlm_debugLogFilePath(HCkNtlm cHandle);
void CkNtlm_getDnsComputerName(HCkNtlm cHandle, HCkString retval);
void CkNtlm_putDnsComputerName(HCkNtlm cHandle, const char *newVal);
const char *CkNtlm_dnsComputerName(HCkNtlm cHandle);
void CkNtlm_getDnsDomainName(HCkNtlm cHandle, HCkString retval);
void CkNtlm_putDnsDomainName(HCkNtlm cHandle, const char *newVal);
const char *CkNtlm_dnsDomainName(HCkNtlm cHandle);
void CkNtlm_getDomain(HCkNtlm cHandle, HCkString retval);
void CkNtlm_putDomain(HCkNtlm cHandle, const char *newVal);
const char *CkNtlm_domain(HCkNtlm cHandle);
void CkNtlm_getEncodingMode(HCkNtlm cHandle, HCkString retval);
void CkNtlm_putEncodingMode(HCkNtlm cHandle, const char *newVal);
const char *CkNtlm_encodingMode(HCkNtlm cHandle);
void CkNtlm_getFlags(HCkNtlm cHandle, HCkString retval);
void CkNtlm_putFlags(HCkNtlm cHandle, const char *newVal);
const char *CkNtlm_flags(HCkNtlm cHandle);
void CkNtlm_getLastErrorHtml(HCkNtlm cHandle, HCkString retval);
const char *CkNtlm_lastErrorHtml(HCkNtlm cHandle);
void CkNtlm_getLastErrorText(HCkNtlm cHandle, HCkString retval);
const char *CkNtlm_lastErrorText(HCkNtlm cHandle);
void CkNtlm_getLastErrorXml(HCkNtlm cHandle, HCkString retval);
const char *CkNtlm_lastErrorXml(HCkNtlm cHandle);
void CkNtlm_getNetBiosComputerName(HCkNtlm cHandle, HCkString retval);
void CkNtlm_putNetBiosComputerName(HCkNtlm cHandle, const char *newVal);
const char *CkNtlm_netBiosComputerName(HCkNtlm cHandle);
void CkNtlm_getNetBiosDomainName(HCkNtlm cHandle, HCkString retval);
void CkNtlm_putNetBiosDomainName(HCkNtlm cHandle, const char *newVal);
const char *CkNtlm_netBiosDomainName(HCkNtlm cHandle);
int CkNtlm_getNtlmVersion(HCkNtlm cHandle);
void CkNtlm_putNtlmVersion(HCkNtlm cHandle, int newVal);
int CkNtlm_getOemCodePage(HCkNtlm cHandle);
void CkNtlm_putOemCodePage(HCkNtlm cHandle, int newVal);
void CkNtlm_getPassword(HCkNtlm cHandle, HCkString retval);
void CkNtlm_putPassword(HCkNtlm cHandle, const char *newVal);
const char *CkNtlm_password(HCkNtlm cHandle);
void CkNtlm_getServerChallenge(HCkNtlm cHandle, HCkString retval);
void CkNtlm_putServerChallenge(HCkNtlm cHandle, const char *newVal);
const char *CkNtlm_serverChallenge(HCkNtlm cHandle);
void CkNtlm_getTargetName(HCkNtlm cHandle, HCkString retval);
void CkNtlm_putTargetName(HCkNtlm cHandle, const char *newVal);
const char *CkNtlm_targetName(HCkNtlm cHandle);
void CkNtlm_getUserName(HCkNtlm cHandle, HCkString retval);
void CkNtlm_putUserName(HCkNtlm cHandle, const char *newVal);
const char *CkNtlm_userName(HCkNtlm cHandle);
BOOL CkNtlm_getUtf8(HCkNtlm cHandle);
void CkNtlm_putUtf8(HCkNtlm cHandle, BOOL newVal);
BOOL CkNtlm_getVerboseLogging(HCkNtlm cHandle);
void CkNtlm_putVerboseLogging(HCkNtlm cHandle, BOOL newVal);
void CkNtlm_getVersion(HCkNtlm cHandle, HCkString retval);
const char *CkNtlm_version(HCkNtlm cHandle);
void CkNtlm_getWorkstation(HCkNtlm cHandle, HCkString retval);
void CkNtlm_putWorkstation(HCkNtlm cHandle, const char *newVal);
const char *CkNtlm_workstation(HCkNtlm cHandle);
BOOL CkNtlm_CompareType3(HCkNtlm cHandle, const char *msg1, const char *msg2);
BOOL CkNtlm_GenType1(HCkNtlm cHandle, HCkString outStr);
const char *CkNtlm_genType1(HCkNtlm cHandle);
BOOL CkNtlm_GenType2(HCkNtlm cHandle, const char *type1Msg, HCkString outStr);
const char *CkNtlm_genType2(HCkNtlm cHandle, const char *type1Msg);
BOOL CkNtlm_GenType3(HCkNtlm cHandle, const char *type2Msg, HCkString outStr);
const char *CkNtlm_genType3(HCkNtlm cHandle, const char *type2Msg);
BOOL CkNtlm_LoadType3(HCkNtlm cHandle, const char *type3Msg);
BOOL CkNtlm_ParseType1(HCkNtlm cHandle, const char *type1Msg, HCkString outStr);
const char *CkNtlm_parseType1(HCkNtlm cHandle, const char *type1Msg);
BOOL CkNtlm_ParseType2(HCkNtlm cHandle, const char *type2Msg, HCkString outStr);
const char *CkNtlm_parseType2(HCkNtlm cHandle, const char *type2Msg);
BOOL CkNtlm_ParseType3(HCkNtlm cHandle, const char *type3Msg, HCkString outStr);
const char *CkNtlm_parseType3(HCkNtlm cHandle, const char *type3Msg);
BOOL CkNtlm_SaveLastError(HCkNtlm cHandle, const char *path);
BOOL CkNtlm_SetFlag(HCkNtlm cHandle, const char *flagLetter, BOOL onOrOff);
BOOL CkNtlm_UnlockComponent(HCkNtlm cHandle, const char *unlockCode);
#endif
