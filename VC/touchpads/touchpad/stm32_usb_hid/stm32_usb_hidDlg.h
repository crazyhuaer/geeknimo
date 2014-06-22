// stm32_usb_hidDlg.h : header file
//

#if !defined(AFX_STM32_USB_HIDDLG_H__68C026C6_D89F_40E3_9D81_DCB9F0900461__INCLUDED_)
#define AFX_STM32_USB_HIDDLG_H__68C026C6_D89F_40E3_9D81_DCB9F0900461__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//#include <initguid.h>
#include <dbt.h>

extern "C" {

#include "hidsdi.h"
#include <setupapi.h>

}
/////////////////////////////////////////////////////////////////////////////
// CStm32_usb_hidDlg dialog

class CStm32_usb_hidDlg : public CDialog
{
// Construction
public:
	CStm32_usb_hidDlg(CWnd* pParent = NULL);	// standard constructor

public:
	//Application global variables 
	DWORD								ActualBytesRead;
	DWORD								BytesRead;
	HIDP_CAPS							Capabilities;
	DWORD								cbBytesRead;
	PSP_DEVICE_INTERFACE_DETAIL_DATA	detailData;
	HANDLE								DeviceHandle;
	DWORD								dwError;
	char								FeatureReport[256];
	HANDLE								hEventObject;
	HANDLE								hDevInfo;
	GUID								HidGuid;
	OVERLAPPED							HIDOverlapped;
	char								InputReport[256];
	ULONG								Length;
	LPOVERLAPPED						lpOverLap;
	bool								MyDeviceDetected; 
	CString								MyDevicePathName;
	DWORD								NumberOfBytesRead;
	char								OutputReport[256];
	HANDLE								ReadHandle;
	//DWORD								ReportType;
	ULONG								Required;
	CString								ValueToDisplay;
	HANDLE								WriteHandle;
public:
	// function for common
	bool	FindTheDevice();
	void	ReadAndWriteToDevice(bool ReportType);
	void	ReadInputReport();
	void	WriteOutputReport();
	void	WriteFeatureReport();
	void	ReadFeatureReport();


	void	RegisterForDeviceNotifications();
	void	GetDeviceCapabilities();
	void	PrepareForOverlappedTransfer();
	
	void	DisplayLastError(CString Operation);
	void	DisplayData(CString sOutputData);
	void	DisplayCurrentTime();
	void	DisplayInputReport();
	void	DisplayFeatureReport();

	void	CloseHandles();
	
	//These are the vendor and product IDs to look for.
	//Uses Lakeview Research's Vendor ID.
	int VendorID;
	int ProductID;

// Dialog Data
	//{{AFX_DATA(CStm32_usb_hidDlg)
	enum { IDD = IDD_STM32_USB_HID_DIALOG };
	CEdit	m_CEditVid;
	CEdit	m_CEditPid;
	CRichEditCtrl	m_CRichOutputMessage;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStm32_usb_hidDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStm32_usb_hidDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonDetect();
	afx_msg void OnChangeEditVid();
	afx_msg void OnChangeEditPid();
	afx_msg void OnButtonReadreport();
	afx_msg void OnButtonWritereport();
	afx_msg void OnButtonClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STM32_USB_HIDDLG_H__68C026C6_D89F_40E3_9D81_DCB9F0900461__INCLUDED_)
