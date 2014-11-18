// ScanTraffic.h: interface for the CScanTraffic class
//
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCANTRAFFIC_H__3A4D81DE_C363_42D6_8A47_3BA017BFBF56__INCLUDED_)
#define AFX_SCANTRAFFIC_H__3A4D81DE_C363_42D6_8A47_3BA017BFBF56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAX_NETBIOS_RECV 65535

typedef struct {
	CString	IPADDRESS;
	CString	MACADDRESS;
	CString	HOST;
	CString	WORKGROUP;
}SCAN_PARAM;

class CScanTraffic
{
	// Construct function and Deconstruct function
public:
	CScanTraffic();
	virtual ~CScanTraffic();
	
	// Class Members var
public:

	int		m_nRecvIn;
	int		m_nRecvOut;

	SCAN_PARAM	m_ScanRecv[MAX_NETBIOS_RECV];

	CRITICAL_SECTION m_csRecv;

	HANDLE m_hKillThreadEvent;		// Event for notify the sub thread killed
	HANDLE m_hThreadKilledEvent;	// Event for the sub thread killed

	void PutRecvMessage(SCAN_PARAM* pSmParam);	// PUSH a Message 
	BOOL GetRecvMessage(SCAN_PARAM* pSmParam);	// PULL a Message 
	
	static UINT ScanThread(LPVOID lpParam);	// The sub thread
	// Class Members function
public:


protected:

private:

};

#endif	// !defined(AFX_SCANTRAFFIC_H__3A4D81DE_C363_42D6_8A47_3BA017BFBF56__INCLUDED_)