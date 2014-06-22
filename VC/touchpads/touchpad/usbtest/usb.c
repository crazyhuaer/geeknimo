/*
  File:   usb.c
  Author: Alan Macek <www.alanmacek.com>
  Date:   March 1, 2000

  This file contains the implementation for connecting to USB Hid devices

  You are free to use this code for anything you want but please send me
  (al@alanmacek.com) an email telling me what you are using it for and
  how it works out.  You are NOT ALLOWED to use this code until you send
  me an email.
    
  This code comes with absolutely no warranty at all.
*/

#include "usb.h"
#include "setupapi.h"
#include "hidsdi.h"

HANDLE connectToIthUSBHIDDevice (DWORD deviceIndex)
{
    GUID hidGUID;
    HDEVINFO hardwareDeviceInfoSet;
    SP_DEVICE_INTERFACE_DATA deviceInterfaceData;
    PSP_INTERFACE_DEVICE_DETAIL_DATA deviceDetail;
    ULONG requiredSize;
    HANDLE deviceHandle = INVALID_HANDLE_VALUE;
    DWORD result;

    //Get the HID GUID value - used as mask to get list of devices
    HidD_GetHidGuid (&hidGUID);

    //Get a list of devices matching the criteria (hid interface, present)
    hardwareDeviceInfoSet = SetupDiGetClassDevs (&hidGUID,
                                                 NULL, // Define no enumerator (global)
                                                 NULL, // Define no
                                                 (DIGCF_PRESENT | // Only Devices present
                                                 DIGCF_DEVICEINTERFACE)); // Function class devices.

    deviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

    //Go through the list and get the interface data
    result = SetupDiEnumDeviceInterfaces (hardwareDeviceInfoSet,
                                          NULL, //infoData,
                                          &hidGUID, //interfaceClassGuid,
                                          deviceIndex, 
                                          &deviceInterfaceData);

    /* Failed to get a device - possibly the index is larger than the number of devices */
    if (result == FALSE)
    {
        SetupDiDestroyDeviceInfoList (hardwareDeviceInfoSet);
        return INVALID_HANDLE_VALUE;
    }

    //Get the details with null values to get the required size of the buffer
    SetupDiGetDeviceInterfaceDetail (hardwareDeviceInfoSet,
                                     &deviceInterfaceData,
                                     NULL, //interfaceDetail,
                                     0, //interfaceDetailSize,
                                     &requiredSize,
                                     0); //infoData))

    //Allocate the buffer
    deviceDetail = (PSP_INTERFACE_DEVICE_DETAIL_DATA)malloc(requiredSize);
    deviceDetail->cbSize = sizeof(SP_INTERFACE_DEVICE_DETAIL_DATA);

    //Fill the buffer with the device details
    if (!SetupDiGetDeviceInterfaceDetail (hardwareDeviceInfoSet,
                                          &deviceInterfaceData,
                                          deviceDetail,
                                          requiredSize,
                                          &requiredSize,
                                          NULL)) 
    {
        SetupDiDestroyDeviceInfoList (hardwareDeviceInfoSet);
        free (deviceDetail);
        return INVALID_HANDLE_VALUE;
    }

    //Open file on the device
    deviceHandle = CreateFile (deviceDetail->DevicePath,
                               GENERIC_READ,
                               FILE_SHARE_READ | FILE_SHARE_WRITE,
                               NULL,        // no SECURITY_ATTRIBUTES structure
                               OPEN_EXISTING, // No special create flags
                               0, 
                               NULL);       // No template file

    SetupDiDestroyDeviceInfoList (hardwareDeviceInfoSet);
    free (deviceDetail);
    return deviceHandle;
}

HANDLE connectToUSBHIDDevice (DWORD *vendorID, DWORD *productID, DWORD *versionNumber)
{
    HANDLE deviceHandle = INVALID_HANDLE_VALUE;
    DWORD index = 0;
    HIDD_ATTRIBUTES deviceAttributes;
    BOOL matched = FALSE;

    while (!matched && (deviceHandle = connectToIthUSBHIDDevice (index)) != INVALID_HANDLE_VALUE)
    {
        if (!HidD_GetAttributes (deviceHandle, &deviceAttributes))
            return INVALID_HANDLE_VALUE;

        if ((vendorID == 0 || deviceAttributes.VendorID == *vendorID) &&
            (productID == 0 || deviceAttributes.ProductID == *productID) &&
            (versionNumber == 0 || deviceAttributes.VersionNumber == *versionNumber))
            return deviceHandle; /* matched */
        
        CloseHandle (deviceHandle); /* not a match - close and try again */

        index++;
    }

    return INVALID_HANDLE_VALUE;
}



