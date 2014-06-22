// stm32_usb_hidDlg.cpp : implementation file
//


#include "stdafx.h"
#include "stm32_usb_hid.h"
#include "stm32_usb_hidDlg.h"
#include <dbt.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStm32_usb_hidDlg dialog

CStm32_usb_hidDlg::CStm32_usb_hidDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStm32_usb_hidDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStm32_usb_hidDlg)
	//}}AFX_DATA_INIT
	MyDeviceDetected = FALSE;
// 	VendorID = 0x093a;
// 	ProductID = 0x2510;

	VendorID = 0x808;
	ProductID = 0x1010;

	//ReportType = 1;
	
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStm32_usb_hidDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStm32_usb_hidDlg)
	DDX_Control(pDX, IDC_EDIT_VID, m_CEditVid);
	DDX_Control(pDX, IDC_EDIT_PID, m_CEditPid);
	DDX_Control(pDX, IDC_RICHEDIT_OUTPUT_MESSAGE, m_CRichOutputMessage);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStm32_usb_hidDlg, CDialog)
	//{{AFX_MSG_MAP(CStm32_usb_hidDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DETECT, OnButtonDetect)
	ON_EN_CHANGE(IDC_EDIT_VID, OnChangeEditVid)
	ON_EN_CHANGE(IDC_EDIT_PID, OnChangeEditPid)
	ON_BN_CLICKED(IDC_BUTTON_READREPORT, OnButtonReadreport)
	ON_BN_CLICKED(IDC_BUTTON_WRITEREPORT, OnButtonWritereport)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStm32_usb_hidDlg message handlers

BOOL CStm32_usb_hidDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_CRichOutputMessage.SetReadOnly(TRUE);
	//m_CRichOutputMessage.EnableWindow(FALSE);
	//m_CEditVid.SetWindowText("8080");
	//m_CEditPid.SetWindowText("0101");
	m_CEditVid.SetWindowText("093a");
	m_CEditPid.SetWindowText("2510");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStm32_usb_hidDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStm32_usb_hidDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStm32_usb_hidDlg::OnButtonDetect() 
{
	FindTheDevice();
}


void CStm32_usb_hidDlg::RegisterForDeviceNotifications()
{
	// Request to receive messages when a device is attached or removed.
	// Also see WM_DEVICECHANGE in BEGIN_MESSAGE_MAP(CUsbhidiocDlg, CDialog).
	
	DEV_BROADCAST_DEVICEINTERFACE DevBroadcastDeviceInterface;
	HDEVNOTIFY DeviceNotificationHandle;
	
	DevBroadcastDeviceInterface.dbcc_size = sizeof(DevBroadcastDeviceInterface);
	DevBroadcastDeviceInterface.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
	DevBroadcastDeviceInterface.dbcc_classguid = HidGuid;
	
	DeviceNotificationHandle =
	RegisterDeviceNotification(m_hWnd, &DevBroadcastDeviceInterface, DEVICE_NOTIFY_WINDOW_HANDLE);
}

void CStm32_usb_hidDlg::DisplayLastError(CString Operation)
{
	//Display a message and the last error in the log List Box.
	
	LPVOID lpMsgBuf;
	USHORT Index = 0;
	CString	strLastError = "";
	FormatMessage( 
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM | 
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0,
		NULL 
		);
	
	//Display the last error.
	
	strLastError = Operation + (LPCTSTR)lpMsgBuf; 
	
	//Trim CR/LF from the error message.
	
	strLastError.TrimRight(); 
	
// 	Index = m_ResultsList.InsertString(-1, strLastError);
// 	ScrollToBottomOfListBox(Index);
// 	LocalFree(lpMsgBuf); 
}

void CStm32_usb_hidDlg::GetDeviceCapabilities()
{
	//Get the Capabilities structure for the device.
	
	PHIDP_PREPARSED_DATA	PreparsedData;
	
	/*
	API function: HidD_GetPreparsedData
	Returns: a pointer to a buffer containing the information about the device's capabilities.
	Requires: A handle returned by CreateFile.
	There's no need to access the buffer directly,
	but HidP_GetCaps and other API functions require a pointer to the buffer.
	*/
	
	HidD_GetPreparsedData 
		(DeviceHandle, 
		&PreparsedData);
	DisplayLastError("HidD_GetPreparsedData: ");
	
	/*
	API function: HidP_GetCaps
	Learn the device's capabilities.
	For standard devices such as joysticks, you can find out the specific
	capabilities of the device.
	For a custom device, the software will probably know what the device is capable of,
	and the call only verifies the information.
	Requires: the pointer to the buffer returned by HidD_GetPreparsedData.
	Returns: a Capabilities structure containing the information.
	*/
	
	HidP_GetCaps 
		(PreparsedData, 
		&Capabilities);
	DisplayLastError("HidP_GetCaps: ");
	
	//Display the capabilities
	
	ValueToDisplay.Format("%s%X", "Usage Page: ", Capabilities.UsagePage);
	DisplayData(ValueToDisplay);
	ValueToDisplay.Format("%s%d", "Input Report Byte Length: ", Capabilities.InputReportByteLength);
	DisplayData(ValueToDisplay);
	ValueToDisplay.Format("%s%d", "Output Report Byte Length: ", Capabilities.OutputReportByteLength);
	DisplayData(ValueToDisplay);
	ValueToDisplay.Format("%s%d", "Feature Report Byte Length: ", Capabilities.FeatureReportByteLength);
	DisplayData(ValueToDisplay);
	ValueToDisplay.Format("%s%d", "Number of Link Collection Nodes: ", Capabilities.NumberLinkCollectionNodes);
	DisplayData(ValueToDisplay);
	ValueToDisplay.Format("%s%d", "Number of Input Button Caps: ", Capabilities.NumberInputButtonCaps);
	DisplayData(ValueToDisplay);
	ValueToDisplay.Format("%s%d", "Number of InputValue Caps: ", Capabilities.NumberInputValueCaps);
	DisplayData(ValueToDisplay);
	ValueToDisplay.Format("%s%d", "Number of InputData Indices: ", Capabilities.NumberInputDataIndices);
	DisplayData(ValueToDisplay);
	ValueToDisplay.Format("%s%d", "Number of Output Button Caps: ", Capabilities.NumberOutputButtonCaps);
	DisplayData(ValueToDisplay);
	ValueToDisplay.Format("%s%d", "Number of Output Value Caps: ", Capabilities.NumberOutputValueCaps);
	DisplayData(ValueToDisplay);
	ValueToDisplay.Format("%s%d", "Number of Output Data Indices: ", Capabilities.NumberOutputDataIndices);
	DisplayData(ValueToDisplay);
	ValueToDisplay.Format("%s%d", "Number of Feature Button Caps: ", Capabilities.NumberFeatureButtonCaps);
	DisplayData(ValueToDisplay);
	ValueToDisplay.Format("%s%d", "Number of Feature Value Caps: ", Capabilities.NumberFeatureValueCaps);
	DisplayData(ValueToDisplay);
	ValueToDisplay.Format("%s%d", "Number of Feature Data Indices: ", Capabilities.NumberFeatureDataIndices);
	DisplayData(ValueToDisplay);
	
	//No need for PreparsedData any more, so free the memory it's using.
	
	HidD_FreePreparsedData(PreparsedData);
	DisplayLastError("HidD_FreePreparsedData: ") ;
}

void CStm32_usb_hidDlg::PrepareForOverlappedTransfer()
{
	//Get a handle to the device for the overlapped ReadFiles.
	
	ReadHandle=CreateFile 
		(detailData->DevicePath, 
		GENERIC_READ, 
		FILE_SHARE_READ|FILE_SHARE_WRITE,
		(LPSECURITY_ATTRIBUTES)NULL, 
		OPEN_EXISTING, 
		FILE_FLAG_OVERLAPPED, 
		NULL);
	
	DisplayLastError("CreateFile (ReadHandle): ");
	
	//Get an event object for the overlapped structure.
	
	/*API function: CreateEvent
	Requires:
	Security attributes or Null
	Manual reset (true). Use ResetEvent to set the event object's state to non-signaled.
	Initial state (true = signaled) 
	Event object name (optional)
	Returns: a handle to the event object
	*/
	
	if (hEventObject == 0)
	{
		hEventObject = CreateEvent 
			(NULL, 
			TRUE, 
			TRUE, 
			"");
		DisplayLastError("CreateEvent: ") ;
		
		//Set the members of the overlapped structure.
		
		HIDOverlapped.hEvent = hEventObject;
		HIDOverlapped.Offset = 0;
		HIDOverlapped.OffsetHigh = 0;
	}
}


void CStm32_usb_hidDlg::DisplayData(CString sOutputData)
{
	m_CRichOutputMessage.SetSel(-1, -1);
	m_CRichOutputMessage.ReplaceSel(sOutputData+"\n");
}

void CStm32_usb_hidDlg::DisplayCurrentTime()
{

}


void CStm32_usb_hidDlg::OnChangeEditVid() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
	CString VendorIDtext;
	
	// Get the text in the edit box.
	m_CEditVid.GetWindowText(VendorIDtext);
	
	// Convert the hex string in the edit box to anS integer.
	
	VendorID = strtoul("0x" + VendorIDtext, 0, 16); 
}

void CStm32_usb_hidDlg::OnChangeEditPid() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString ProductIDtext;

	// Get the text in the edit box.

	m_CEditPid.GetWindowText(ProductIDtext);

	// Convert the hex string in the edit box to an integer.
	
	ProductID = strtoul("0x" + ProductIDtext, 0, 16); 
}

bool CStm32_usb_hidDlg::FindTheDevice()
{
	//Use a series of API calls to find a HID with a specified Vendor IF and Product ID.
	HIDD_ATTRIBUTES						Attributes;
	DWORD								DeviceUsage;
	SP_DEVICE_INTERFACE_DATA			devInfoData;
	bool								LastDevice = FALSE;
	int									MemberIndex = 0;
	LONG								Result;	
	CString								UsageDescription;

	Length = 0;
	detailData = NULL;
	DeviceHandle=NULL;

	/*
	API function: HidD_GetHidGuid
	Get the GUID for all system HIDs.
	Returns: the GUID in HidGuid.
	*/

	HidD_GetHidGuid(&HidGuid);	
	
	/*
	API function: SetupDiGetClassDevs
	Returns: a handle to a device information set for all installed devices.
	Requires: the GUID returned by GetHidGuid.
	*/
	
	hDevInfo=SetupDiGetClassDevs 
		(&HidGuid, 
		NULL, 
		NULL, 
		DIGCF_PRESENT|DIGCF_INTERFACEDEVICE);
		
	devInfoData.cbSize = sizeof(devInfoData);

	//Step through the available devices looking for the one we want. 
	//Quit on detecting the desired device or checking all available devices without success.

	MemberIndex = 0;
	LastDevice = FALSE;

	do
	{
		/*
		API function: SetupDiEnumDeviceInterfaces
		On return, MyDeviceInterfaceData contains the handle to a
		SP_DEVICE_INTERFACE_DATA structure for a detected device.
		Requires:
		The DeviceInfoSet returned in SetupDiGetClassDevs.
		The HidGuid returned in GetHidGuid.
		An index to specify a device.
		*/

		Result=SetupDiEnumDeviceInterfaces 
			(hDevInfo, 
			0, 
			&HidGuid, 
			MemberIndex, 
			&devInfoData);

		if (Result != 0)
		{
			//A device has been detected, so get more information about it.

			/*
			API function: SetupDiGetDeviceInterfaceDetail
			Returns: an SP_DEVICE_INTERFACE_DETAIL_DATA structure
			containing information about a device.
			To retrieve the information, call this function twice.
			The first time returns the size of the structure in Length.
			The second time returns a pointer to the data in DeviceInfoSet.
			Requires:
			A DeviceInfoSet returned by SetupDiGetClassDevs
			The SP_DEVICE_INTERFACE_DATA structure returned by SetupDiEnumDeviceInterfaces.
			
			The final parameter is an optional pointer to an SP_DEV_INFO_DATA structure.
			This application doesn't retrieve or use the structure.			
			If retrieving the structure, set 
			MyDeviceInfoData.cbSize = length of MyDeviceInfoData.
			and pass the structure's address.
			*/
			
			//Get the Length value.
			//The call will return with a "buffer too small" error which can be ignored.

			Result = SetupDiGetDeviceInterfaceDetail 
				(hDevInfo, 
				&devInfoData, 
				NULL, 
				0, 
				&Length, 
				NULL);

			//Allocate memory for the hDevInfo structure, using the returned Length.

			detailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA)malloc(Length);
			
			//Set cbSize in the detailData structure.

			detailData -> cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

			//Call the function again, this time passing it the returned buffer size.

			Result = SetupDiGetDeviceInterfaceDetail 
				(hDevInfo, 
				&devInfoData, 
				detailData, 
				Length, 
				&Required, 
				NULL);

			// Open a handle to the device.
			// To enable retrieving information about a system mouse or keyboard,
			// don't request Read or Write access for this handle.

			/*
			API function: CreateFile
			Returns: a handle that enables reading and writing to the device.
			Requires:
			The DevicePath in the detailData structure
			returned by SetupDiGetDeviceInterfaceDetail.
			*/

			DeviceHandle=CreateFile 
				(detailData->DevicePath, 
				0, 
				FILE_SHARE_READ|FILE_SHARE_WRITE, 
				(LPSECURITY_ATTRIBUTES)NULL,
				OPEN_EXISTING, 
				0, 
				NULL);

			DisplayLastError("CreateFile: ");

			/*
			API function: HidD_GetAttributes
			Requests information from the device.
			Requires: the handle returned by CreateFile.
			Returns: a HIDD_ATTRIBUTES structure containing
			the Vendor ID, Product ID, and Product Version Number.
			Use this information to decide if the detected device is
			the one we're looking for.
			*/

			//Set the Size to the number of bytes in the structure.

			Attributes.Size = sizeof(Attributes);

			Result = HidD_GetAttributes 
				(DeviceHandle, 
				&Attributes);
			
			DisplayLastError("HidD_GetAttributes: ");
			
			//Is it the desired device?

			MyDeviceDetected = FALSE;
			

			if (Attributes.VendorID == VendorID)
			{
				if (Attributes.ProductID == ProductID)
				{
					//Both the Vendor ID and Product ID match.

					MyDeviceDetected = TRUE;
					MyDevicePathName = detailData->DevicePath;
					////DisplayData("Device detected");

					//Register to receive device notifications.

					RegisterForDeviceNotifications();

					//Get the device's capablities.

					GetDeviceCapabilities();

					// Find out if the device is a system mouse or keyboard.
					
					DeviceUsage = (Capabilities.UsagePage * 256) + Capabilities.Usage;

					if (DeviceUsage == 0x102)
					{
						UsageDescription = "mouse";
					}
				
					if (DeviceUsage == 0x106)
					{
						UsageDescription = "keyboard";
					}

					if ((DeviceUsage == 0x102) | (DeviceUsage == 0x106)) 
					{
						DisplayData("");
						DisplayData("*************************");
						DisplayData("The device is " + UsageDescription + ".");
						DisplayData("*************************");
						DisplayData("");
					}

					// Get a handle for writing Output reports.

					WriteHandle=CreateFile 
						(detailData->DevicePath, 
						GENERIC_WRITE, 
						FILE_SHARE_READ|FILE_SHARE_WRITE, 
						(LPSECURITY_ATTRIBUTES)NULL,
						OPEN_EXISTING, 
						0, 
						NULL);

					DisplayLastError("CreateFile: ");

					// Prepare to read reports using Overlapped I/O.

					PrepareForOverlappedTransfer();

				} //if (Attributes.ProductID == ProductID)

				else
					//The Product ID doesn't match.

					CloseHandle(DeviceHandle);

			} //if (Attributes.VendorID == VendorID)

			else
			{
				//The Vendor ID doesn't match.
				CString temp;
				temp.Format("  VendorID:0x%04x,ProductID:0x%04x  ",VendorID,ProductID);
				DisplayData("没有找到"+temp+"的设备");
				CloseHandle(DeviceHandle);
			}
			//Free the memory used by the detailData structure (no longer needed).

			free(detailData);

		}  //if (Result != 0)

		else
			//SetupDiEnumDeviceInterfaces returned 0, so there are no more devices to check.

			LastDevice=TRUE;

		//If we haven't found the device yet, and haven't tried every available device,
		//try the next one.

		MemberIndex = MemberIndex + 1;

	} //do

	while ((LastDevice == FALSE) && (MyDeviceDetected == FALSE));

	// display the data
	
	//Free the memory reserved for hDevInfo by SetupDiClassDevs.
	
	SetupDiDestroyDeviceInfoList(hDevInfo);
	DisplayLastError("SetupDiDestroyDeviceInfoList");
	return MyDeviceDetected;
}

void CStm32_usb_hidDlg::ReadAndWriteToDevice(bool ReportType)
{
	//If necessary, find the device and learn its capabilities.
	//Then send a report and request a report.
	
	//Clear the List Box (optional).
	//m_ResultsList.ResetContent();
	
	DisplayData("***HID Test Report***");
	DisplayCurrentTime();
	
	//If the device hasn't been detected already, look for it.
	
	if (MyDeviceDetected==FALSE)
	{
		MyDeviceDetected=FindTheDevice(); 
	}
	
	// Do nothing if the device isn't detected.
	
	if (MyDeviceDetected==TRUE)
	{
		switch (ReportType)
		{
			case 0:
			{
				// Output and Input Reports
				
				//Write a report to the device.
				
				//WriteOutputReport();
				
				//Read a report from the device.
				
				ReadInputReport();	
				
				break;
			}
			case 1:
			{
				// Feature reports
				
				//Write a report to the device.
				
				//WriteFeatureReport();
				
				//Read a report from the device.
				
				ReadFeatureReport();
				
				break;
			}
				
// 			default:
// 			{
// 				break;
// 			}
		} // switch
	} // else
}

void CStm32_usb_hidDlg::ReadInputReport()
{
	// Retrieve an Input report from the device.

	CString	ByteToDisplay = "";

	DWORD	Result;
	
	//The first byte is the report number.
	InputReport[0]=0;

	// Find out if the "Use Control Transfers Only" check box is checked.

	UpdateData(true);

	// template add 
	bool m_UseControlTransfersOnly = true;

	if (m_UseControlTransfersOnly) 
	{

		//Read a report from the device using a control transfer.
	
		/*
		HidD_GetInputReport
		Returns:
		True on success
		Requires: 
		A device handle returned by CreateFile.
		A buffer to hold the report.
		The report length returned by HidP_GetCaps in Capabilities.InputReportByteLength.
		*/
		
		if (ReadHandle != INVALID_HANDLE_VALUE)
		{
			Result = HidD_GetInputReport
			(ReadHandle,
			InputReport,
			Capabilities.InputReportByteLength);

			DisplayLastError("HidD_GetInputReport: ");
		}
		else
		{
			Result = FALSE;
		}

		if (!Result)
		{
			//The read attempt failed, so close the handles, display a message,
			//and set MyDeviceDetected to FALSE so the next attempt will look for the device.

			CloseHandles();
			DisplayData("Can't read from device");
			MyDeviceDetected = FALSE;
		}
		else
		{
			DisplayData("Received Input report: ");
			
			//Display the report data.

			DisplayInputReport();
		
			/*
			USHORT	ByteNumber;
			CHAR	ReceivedByte;
		
			//Display the received data in the log and the Bytes Received List boxes.
			//Start at the top of the List Box.

			m_BytesReceived.ResetContent();
	
			//Step through the received bytes and display each.

			for (ByteNumber=0; ByteNumber < Capabilities.InputReportByteLength; ByteNumber++)
			{
				//Get a byte.

				ReceivedByte = InputReport[ByteNumber];

				//Display it.

				DisplayReceivedData(ReceivedByte);
			}
			*/
		}	// if result
	} 
	else
	{
 	
		/*API call:ReadFile
		'Returns: the report in InputReport.
		'Requires: a device handle returned by CreateFile
		'(for overlapped I/O, CreateFile must be called with FILE_FLAG_OVERLAPPED),
		'the Input report length in bytes returned by HidP_GetCaps,
		'and an overlapped structure whose hEvent member is set to an event object.
		*/

		if (ReadHandle != INVALID_HANDLE_VALUE)
		{
			Result = ReadFile 
			(ReadHandle, 
			InputReport, 
			Capabilities.InputReportByteLength, 
			&NumberOfBytesRead,
			(LPOVERLAPPED) &HIDOverlapped); 
		}
 
		DisplayLastError("ReadFile: ") ;

		/*API call:WaitForSingleObject
		'Used with overlapped ReadFile.
		'Returns when ReadFile has received the requested amount of data or on timeout.
		'Requires an event object created with CreateEvent
		'and a timeout value in milliseconds.
		*/

		Result = WaitForSingleObject 
			(hEventObject, 
			6000);

		DisplayLastError("WaitForSingleObject: ") ;
 
		switch (Result)
		{
			case WAIT_OBJECT_0:
			{
				DisplayData("Received Input report,");
							
				break;
			}
			case WAIT_TIMEOUT:
			{
				ValueToDisplay.Format("%s", "ReadFile timeout");
				DisplayData(ValueToDisplay);
				//Cancel the Read operation.

				/*API call: CancelIo
				Cancels the ReadFile
				Requires the device handle.
				Returns non-zero on success.
				*/
				
				Result = CancelIo(ReadHandle);
				
				//A timeout may mean that the device has been removed. 
				//Close the device handles and set MyDeviceDetected = False 
				//so the next access attempt will search for the device.
				CloseHandles();
				DisplayData("Can't read from device");
				MyDeviceDetected = FALSE;
				break;
			}
			default:
			{
				ValueToDisplay.Format("%s", "Undefined error");

				//Close the device handles and set MyDeviceDetected = False 
				//so the next access attempt will search for the device.

				CloseHandles();
				DisplayData("Can't read from device");
				MyDeviceDetected = FALSE;
				break;
			}
		}

		/*
		API call: ResetEvent
		Sets the event object to non-signaled.
		Requires a handle to the event object.
		Returns non-zero on success.
		*/

		ResetEvent(hEventObject);

		//Display the report data.

		DisplayInputReport();

	}
}

void CStm32_usb_hidDlg::WriteOutputReport()
{
	//Send a report to the device.

	DWORD	BytesWritten = 0;
	INT		Index =0;
	ULONG	Result;
	CString	strBytesWritten = "";

	UpdateData(true);

	//The first byte is the report number.

	OutputReport[0]=0;

	//Can set the other report values here, or get them from the combo boxes.
	//OutputReport[1]=33;
	//OutputReport[2]=6;

	//Get the bytes to send from the combo boxes.
	
	//If Autoincrement is checked, increment the selection.

// 	if (m_cbutAutoIncrement.GetCheck()>0)
// 		{
// 		Index=m_cboByteToSend0.GetCurSel();
// 		Index=Index+1;
// 		if(Index > 0xff) 
// 			Index = 0;
// 		m_cboByteToSend0.SetCurSel(Index);
// 		}
// 
// 	if (m_cbutAutoIncrement.GetCheck()>0)
// 		{
// 		Index=m_cboByteToSend1.GetCurSel();
// 		Index=Index+1;
// 		if(Index > 255)
// 			Index = 0;
// 		m_cboByteToSend1.SetCurSel(Index);
// 		}	
// 
// 	//Get the values from the combo boxes.
// 
// 	OutputReport[1]=m_cboByteToSend0.GetCurSel();
// 	OutputReport[2]=m_cboByteToSend1.GetCurSel();


	//The first byte is the report number.

	OutputReport[0]=0;

	// template add
	bool m_UseControlTransfersOnly = false;

	if (m_UseControlTransfersOnly)
	{

		//Send a report to the device.

		/*
		HidD_SetOutputReport
		Sends a report to the device.
		Returns: success or failure.
		Requires:
		The device handle returned by CreateFile.
		A buffer that holds the report.
		The Output Report length returned by HidP_GetCaps,
		*/

		if (WriteHandle != INVALID_HANDLE_VALUE)
		{
			Result = HidD_SetOutputReport
			(WriteHandle,
			OutputReport,
			Capabilities.OutputReportByteLength);

			DisplayLastError("HidD_SetOutputReport: ");
		}

		if (Result)
		{
			DisplayData("An Output report was written to the device.");
		}
		else
		{
			//The write attempt failed, so close the handles, display a message,
			//and set MyDeviceDetected to FALSE so the next attempt will look for the device.

			CloseHandles();
			DisplayData("Can't write to device");
			MyDeviceDetected = FALSE;
		}

	}
	else
	{

		/*
		API Function: WriteFile
		Sends a report to the device.
		Returns: success or failure.
		Requires:
		A device handle returned by CreateFile.
		A buffer that holds the report.
		The Output Report length returned by HidP_GetCaps,
		A variable to hold the number of bytes written.
		*/

		if (WriteHandle != INVALID_HANDLE_VALUE)
		{
			Result = WriteFile 
			(WriteHandle, 
			OutputReport, 
			Capabilities.OutputReportByteLength, 
			&BytesWritten, 
			NULL);
		}

		//Display the result of the API call and the report bytes.

		DisplayLastError("WriteFile: ");

		if (!Result)
		{
			//The WriteFile failed, so close the handles, display a message,
			//and set MyDeviceDetected to FALSE so the next attempt will look for the device.

			CloseHandles();
			DisplayData("Can't write to device");
			MyDeviceDetected = FALSE;
		}
		else
		{
			DisplayData("An Output report was written to the device.");
			strBytesWritten.Format("%s%d", "Bytes Written: ", BytesWritten); 
			DisplayData(strBytesWritten);
		}
	}
}


void CStm32_usb_hidDlg::WriteFeatureReport()
{
	//Send a report to the device.
	
	DWORD	BytesWritten = 0;
	INT		Index =0;
	ULONG	Result;
	CString	strBytesWritten = "";
	
	//The first byte is the report number.
	
	FeatureReport[0]=0;
	
	//Can set the other report values here, or get them from the combo boxes.
	//OutputReport[1]=33;
	//OutputReport[2]=6;
	
	//Get the bytes to send from the combo boxes.
	
	//If Autoincrement is checked, increment the selection.
	
// 	if (m_cbutAutoIncrement.GetCheck()>0)
// 	{
// 		Index=m_cboByteToSend0.GetCurSel();
// 		Index=Index+1;
// 		m_cboByteToSend0.SetCurSel(Index);
// 	}
// 	
// 	if (m_cbutAutoIncrement.GetCheck()>0)
// 	{
// 		Index=m_cboByteToSend1.GetCurSel();
// 		Index=Index+1;
// 		m_cboByteToSend1.SetCurSel(Index);
// 	}
	
	//Get the values from the combo boxes.
	
// 	FeatureReport[1]=m_cboByteToSend0.GetCurSel();
// 	FeatureReport[2]=m_cboByteToSend1.GetCurSel();
	
	
	//The first byte is the report number.
	
	FeatureReport[0]=0;
	
	//Send a report to the device.
	
	/*
	HidD_SetFeature
	Sends a report to the device.
	Returns: success or failure.
	Requires:
	A device handle returned by CreateFile.
	A buffer that holds the report.
	The Output Report length returned by HidP_GetCaps,
	*/
	
	if (DeviceHandle != INVALID_HANDLE_VALUE)
	{
		Result = HidD_SetFeature
			(DeviceHandle,
			FeatureReport,
			Capabilities.FeatureReportByteLength);
	}
	
	DisplayLastError("HidD_SetFeature: ");
	
	if (!Result)
	{
		//The write attempt failed, so close the handles, display a message,
		//and set MyDeviceDetected to FALSE so the next attempt will look for the device.
		
		CloseHandles();
		DisplayData("Can't write to device");
		MyDeviceDetected = FALSE;
	}
	else
	{
		DisplayData("A Feature report was written to the device.");
	}
}

void CStm32_usb_hidDlg::ReadFeatureReport()
{
	// Read a Feature report from the device.
	
	CString	ByteToDisplay = "";
	BOOLEAN	Result;
	
	//The first byte is the report number.
	FeatureReport[0]=0;
	
	//Read a report from the device.
	
	/*
	HidD_GetFeature
	Returns:
	True on success
	Requires: 
	A device handle returned by CreateFile.
	A buffer to hold the report.
	The report length returned by HidP_GetCaps in Capabilities.InputReportByteLength.
	*/
	
	if (DeviceHandle != INVALID_HANDLE_VALUE)
	{
		Result = HidD_GetFeature
			(DeviceHandle,
			FeatureReport,
			Capabilities.FeatureReportByteLength);
		
		DisplayLastError("HidD_GetFeature: ");
	}
				
	if (!Result)
	{
		//The read attempt failed, so close the handles, display a message,
		//and set MyDeviceDetected to FALSE so the next attempt will look for the device.
		
		CloseHandles();
		DisplayData("Can't read from device");
		MyDeviceDetected = FALSE;
	}
	else
	{
		DisplayData("Received Feature report: ");
		
		DisplayFeatureReport();
	}
}

void CStm32_usb_hidDlg::DisplayInputReport()
{
	USHORT	ByteNumber;
	CHAR	ReceivedByte;
	
	//Display the received data in the log and the Bytes Received List boxes.
	//Start at the top of the List Box.
	
//	m_BytesReceived.ResetContent();
	
	//Step through the received bytes and display each.
	
	for (ByteNumber=0; ByteNumber < Capabilities.InputReportByteLength; ByteNumber++)
	{
		//Get a byte.
		
		ReceivedByte = InputReport[ByteNumber];
		
		//Display it.
		
//		DisplayReceivedData(ReceivedByte);
	}
}

void CStm32_usb_hidDlg::CloseHandles()
{
	//Close open handles.
	
	if (DeviceHandle != INVALID_HANDLE_VALUE)
	{
		CloseHandle(DeviceHandle);
	}
	
	if (ReadHandle != INVALID_HANDLE_VALUE)
	{
		CloseHandle(ReadHandle);
	}
	
	if (WriteHandle != INVALID_HANDLE_VALUE)
	{
		CloseHandle(WriteHandle);
	}
}

void CStm32_usb_hidDlg::DisplayFeatureReport()
{
	USHORT	ByteNumber;
	CHAR	ReceivedByte;
	
	//Display the received data in the log and the Bytes Received List boxes.
	//Start at the top of the List Box.
	
// 	m_BytesReceived.ResetContent();
	
	//Step through the received bytes and display each.
	
	for (ByteNumber=0; ByteNumber < Capabilities.FeatureReportByteLength; ByteNumber++)
	{
		//Get a byte.
		
		ReceivedByte = FeatureReport[ByteNumber];
		
		//Display it.
		
// 		DisplayReceivedData(ReceivedByte);
	}
}

void CStm32_usb_hidDlg::OnButtonReadreport() 
{
	// TODO: Add your control notification handler code here
	CStm32_usb_hidDlg::ReadAndWriteToDevice(0);
	m_CRichOutputMessage.PostMessage(WM_VSCROLL, SB_BOTTOM,0);
}

void CStm32_usb_hidDlg::OnButtonWritereport() 
{
	// TODO: Add your control notification handler code here
	CStm32_usb_hidDlg::ReadAndWriteToDevice(1);
	m_CRichOutputMessage.PostMessage(WM_VSCROLL, SB_BOTTOM,0);
}

void CStm32_usb_hidDlg::OnButtonClear() 
{
	// TODO: Add your control notification handler code here
	m_CRichOutputMessage.SetWindowText("");
}
