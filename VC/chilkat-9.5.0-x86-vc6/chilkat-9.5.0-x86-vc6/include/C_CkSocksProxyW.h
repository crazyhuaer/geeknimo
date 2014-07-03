// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkSocksProxyWH
#define _C_CkSocksProxyWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkSocksProxyW CkSocksProxyW_Create(void);
HCkSocksProxyW CkSocksProxyW_Create2(BOOL bCallbackOwned);
void CkSocksProxyW_Dispose(HCkSocksProxyW handle);
BOOL CkSocksProxyW_getAllowUnauthenticatedSocks5(HCkSocksProxyW cHandle);
void CkSocksProxyW_putAllowUnauthenticatedSocks5(HCkSocksProxyW cHandle, BOOL newVal);
BOOL CkSocksProxyW_getAuthenticatedSocks5(HCkSocksProxyW cHandle);
void CkSocksProxyW_getClientIp(HCkSocksProxyW cHandle, HCkString retval);
const wchar_t *CkSocksProxyW_clientIp(HCkSocksProxyW cHandle);
int CkSocksProxyW_getClientPort(HCkSocksProxyW cHandle);
BOOL CkSocksProxyW_getConnectionPending(HCkSocksProxyW cHandle);
void CkSocksProxyW_getDebugLogFilePath(HCkSocksProxyW cHandle, HCkString retval);
void CkSocksProxyW_putDebugLogFilePath(HCkSocksProxyW cHandle, const wchar_t *newVal);
const wchar_t *CkSocksProxyW_debugLogFilePath(HCkSocksProxyW cHandle);
void CkSocksProxyW_getLastErrorHtml(HCkSocksProxyW cHandle, HCkString retval);
const wchar_t *CkSocksProxyW_lastErrorHtml(HCkSocksProxyW cHandle);
void CkSocksProxyW_getLastErrorText(HCkSocksProxyW cHandle, HCkString retval);
const wchar_t *CkSocksProxyW_lastErrorText(HCkSocksProxyW cHandle);
void CkSocksProxyW_getLastErrorXml(HCkSocksProxyW cHandle, HCkString retval);
const wchar_t *CkSocksProxyW_lastErrorXml(HCkSocksProxyW cHandle);
void CkSocksProxyW_getListenBindIpAddress(HCkSocksProxyW cHandle, HCkString retval);
void CkSocksProxyW_putListenBindIpAddress(HCkSocksProxyW cHandle, const wchar_t *newVal);
const wchar_t *CkSocksProxyW_listenBindIpAddress(HCkSocksProxyW cHandle);
void CkSocksProxyW_getLogin(HCkSocksProxyW cHandle, HCkString retval);
const wchar_t *CkSocksProxyW_login(HCkSocksProxyW cHandle);
void CkSocksProxyW_getOutboundBindIpAddress(HCkSocksProxyW cHandle, HCkString retval);
void CkSocksProxyW_putOutboundBindIpAddress(HCkSocksProxyW cHandle, const wchar_t *newVal);
const wchar_t *CkSocksProxyW_outboundBindIpAddress(HCkSocksProxyW cHandle);
int CkSocksProxyW_getOutboundBindPort(HCkSocksProxyW cHandle);
void CkSocksProxyW_putOutboundBindPort(HCkSocksProxyW cHandle, int newVal);
void CkSocksProxyW_getPassword(HCkSocksProxyW cHandle, HCkString retval);
const wchar_t *CkSocksProxyW_password(HCkSocksProxyW cHandle);
void CkSocksProxyW_getServerIp(HCkSocksProxyW cHandle, HCkString retval);
const wchar_t *CkSocksProxyW_serverIp(HCkSocksProxyW cHandle);
int CkSocksProxyW_getServerPort(HCkSocksProxyW cHandle);
int CkSocksProxyW_getSocksVersion(HCkSocksProxyW cHandle);
BOOL CkSocksProxyW_getVerboseLogging(HCkSocksProxyW cHandle);
void CkSocksProxyW_putVerboseLogging(HCkSocksProxyW cHandle, BOOL newVal);
void CkSocksProxyW_getVersion(HCkSocksProxyW cHandle, HCkString retval);
const wchar_t *CkSocksProxyW_version(HCkSocksProxyW cHandle);
BOOL CkSocksProxyW_AllowConnection(HCkSocksProxyW cHandle);
BOOL CkSocksProxyW_GetTunnelsXml(HCkSocksProxyW cHandle, HCkString outStr);
const wchar_t *CkSocksProxyW_getTunnelsXml(HCkSocksProxyW cHandle);
BOOL CkSocksProxyW_Initialize(HCkSocksProxyW cHandle, int port);
BOOL CkSocksProxyW_ProceedSocks5(HCkSocksProxyW cHandle);
BOOL CkSocksProxyW_RejectConnection(HCkSocksProxyW cHandle);
BOOL CkSocksProxyW_SaveLastError(HCkSocksProxyW cHandle, const wchar_t *path);
BOOL CkSocksProxyW_StopAllTunnels(HCkSocksProxyW cHandle, int maxWaitMs);
BOOL CkSocksProxyW_UnlockComponent(HCkSocksProxyW cHandle, const wchar_t *unlockCode);
BOOL CkSocksProxyW_WaitForConnection(HCkSocksProxyW cHandle, int maxWaitMs);
#endif
