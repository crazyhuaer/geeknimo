// ScanTraffic.cpp: implementation of the CScanTraffic class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "ScanTraffic.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CScanTraffic::CScanTraffic()
{
	m_nRecvIn = 0;
	m_nRecvOut = 0;

	m_hKillThreadEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	m_hThreadKilledEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	
	InitializeCriticalSection(&m_csRecv);
	
	AfxBeginThread(ScanThread, this, THREAD_PRIORITY_NORMAL);
}

CScanTraffic::~CScanTraffic()
{
	SetEvent(m_hKillThreadEvent);			// Event for close the sub thread
	WaitForSingleObject(m_hThreadKilledEvent, INFINITE);	// wait for sub thread closed info
	
	DeleteCriticalSection(&m_csRecv);
	
	CloseHandle(m_hKillThreadEvent);
	CloseHandle(m_hThreadKilledEvent);
}

void CScanTraffic::PutRecvMessage(SCAN_PARAM* pSmParam)
{
	EnterCriticalSection(&m_csRecv);
	
	memcpy(&m_ScanRecv[m_nRecvIn], pSmParam, sizeof(SCAN_PARAM));
	
	m_nRecvIn++;
	if (m_nRecvIn >= MAX_NETBIOS_RECV)  m_nRecvIn = 0;
	
	LeaveCriticalSection(&m_csRecv);
}

BOOL CScanTraffic::GetRecvMessage(SCAN_PARAM* pSmParam)
{
	BOOL fSuccess = FALSE;

	EnterCriticalSection(&m_csRecv);
	
	if (m_nRecvOut != m_nRecvIn)
	{
		memcpy(pSmParam, &m_ScanRecv[m_nRecvOut], sizeof(SCAN_PARAM));
		
		m_nRecvOut++;
		if (m_nRecvOut >= MAX_NETBIOS_RECV)  m_nRecvOut = 0;
		
		fSuccess = TRUE;
	}
	
	LeaveCriticalSection(&m_csRecv);

	return fSuccess;
}

UINT CScanTraffic::ScanThread(LPVOID lpParam)
{
	CScanTraffic* p=(CScanTraffic *)lpParam;	// this
	SCAN_PARAM param[256];	
	CTime tmOrg, tmNow;		
	enum {
		stBeginRest,				// Start or Delay
		stContinueRest,				// Continue or Delay
		stExitThread				// Exit
	} nState;				// Process Status

	// Start Status
	nState = stBeginRest;

	// Send and Recv Process
	while (nState != stExitThread)
	{
		switch(nState)
		{
			case stBeginRest:
				tmOrg = CTime::GetCurrentTime();
				nState = stContinueRest;
				break;

			case stContinueRest:
				Sleep(15);
				tmNow = CTime::GetCurrentTime();
				if (p->GetRecvMessage(&param[0]))
				{
					nState = stContinueRest;	
					// just do it
					
				}
				break;


			default:
				;
		}

		// 检测是否有关闭本线程的信号
		DWORD dwEvent = WaitForSingleObject(p->m_hKillThreadEvent, 20);
		if (dwEvent == WAIT_OBJECT_0)  nState = stExitThread;
	}

	// 置该线程结束标志
	SetEvent(p->m_hThreadKilledEvent);

	return 9999;
}