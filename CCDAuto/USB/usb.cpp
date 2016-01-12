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


  Nov 16, 2004, Golden Crater Software, Jim Koornneef
  Write C++ class around code. Create ExploreTODebugWindow, Read and Writing routines. Added Overlapped read support.

  Code written by Jim Koornneef is copyright, simply so I don't get sued by someone else copyrighting it on me. I assume
  code written by Alan Macek is copyright by him, and claim no ownership over his work.
  You are free to use this code for anything, and it comes with no warranty. You must still contact Alan Macek (as per above)
*/
#include "stdafx.h"
#include "usb.h"
#include <setupapi.h>
#include <string>

extern "C" {
#include "hidsdi.h"
}

#pragma comment(lib, "setupapi.lib")
#pragma comment(lib, "hid.lib")

CUSBDevice::CUSBDevice()
{
	handle = INVALID_HANDLE_VALUE;
	EventObject = INVALID_HANDLE_VALUE;
	//HIDOverlapped;  whatever is in there should be fine.
}

CUSBDevice::~CUSBDevice()
{
	Disconnect();
}

CUSBDevice::CUSBDevice(const DWORD *vendorID, const DWORD *productID, const DWORD *versionNumber)
{
	handle = INVALID_HANDLE_VALUE;
	EventObject = INVALID_HANDLE_VALUE;
	//HIDOverlapped;  whatever is in there should be fine.
	Connect(vendorID, productID, versionNumber);
}


HANDLE CUSBDevice::ConnectToIthDevice (DWORD deviceIndex)
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
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,        // no SECURITY_ATTRIBUTES structure
		OPEN_EXISTING, // No special create flags
		FILE_FLAG_OVERLAPPED, 
		NULL);       // No template file

	
    SetupDiDestroyDeviceInfoList (hardwareDeviceInfoSet);
    free (deviceDetail);
    return deviceHandle;
}

bool CUSBDevice::Connect(const DWORD *vendorID, const DWORD *productID, const DWORD *versionNumber)
{
	Disconnect();
    handle = INVALID_HANDLE_VALUE;
    DWORD index = 0;
    HIDD_ATTRIBUTES deviceAttributes;
    BOOL matched = FALSE;
//	LPCWSTR dummy ( L"" );
	
//    while (!matched && (handle = ConnectToIthDevice (index)) != INVALID_HANDLE_VALUE)
    while (!matched)
    {
        if (!HidD_GetAttributes (handle, &deviceAttributes))
            return INVALID_HANDLE_VALUE;
		
        if ((vendorID == 0 || deviceAttributes.VendorID == *vendorID) &&
            (productID == 0 || deviceAttributes.ProductID == *productID) &&
            (versionNumber == 0 || deviceAttributes.VersionNumber == *versionNumber)) {
				EventObject = CreateEvent(NULL, TRUE, TRUE, NULL);
				//Set the members of the overlapped structure.
				HIDOverlapped.Offset = 0;
				HIDOverlapped.OffsetHigh = 0;
				HIDOverlapped.hEvent = EventObject;
			
				return true; /* matched */
		}
        
        CloseHandle (handle); /* not a match - close and try again */
		
        index++;
    }
	
    return false;
}


void CUSBDevice::Disconnect()
{
	if (EventObject != INVALID_HANDLE_VALUE)
		CloseHandle(EventObject);
	EventObject = INVALID_HANDLE_VALUE;
	
	if (handle != INVALID_HANDLE_VALUE)
		CloseHandle(handle);
	handle = INVALID_HANDLE_VALUE;
}

bool CUSBDevice::Write(const BYTE *bytes, int nBuffLen) 
{
	unsigned long BytesWritten;
	return WriteFile(handle, (LPCVOID)bytes, nBuffLen, &BytesWritten, NULL);
}


int CUSBDevice::Read(BYTE *bytes, int nBuffLen)
{
	unsigned long BytesRead = 0;
	ReadFile(handle, (LPVOID)bytes, nBuffLen, &BytesRead, &HIDOverlapped);
	DWORD Result = WaitForSingleObject(EventObject, 50);
	if (Result == WAIT_OBJECT_0) {		
		ResetEvent(EventObject);
		return BytesRead;
	}
	if(Result == WAIT_TIMEOUT) {
		Result = CancelIo(handle);			
	}

	ResetEvent(EventObject);
	return 0;
}
