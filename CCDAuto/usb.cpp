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
#include "USB/usb.h"
#include <setupapi.h>
#include <string>

extern "C" {
#include "USB/hidsdi.h"
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
    GUID Guid[2];
    HDEVINFO hardwareDeviceInfoSet;
    SP_DEVICE_INTERFACE_DATA deviceInterfaceData;
    PSP_INTERFACE_DEVICE_DETAIL_DATA deviceDetail;
    ULONG requiredSize;
    HANDLE deviceHandle = INVALID_HANDLE_VALUE;
    DWORD result;

    //Get the HID GUID value - used as mask to get list of devices
    HidD_GetHidGuid (&Guid[0]);

	Guid[1].Data1 = 0x606377C1;
    Guid[1].Data2 = 0x2270;
	Guid[1].Data3 = 0x11D4;
	Guid[1].Data4[0] = 0xBF;
	Guid[1].Data4[1] = 0xD8;
	Guid[1].Data4[2] = 0x0;
	Guid[1].Data4[3] = 0x20;
	Guid[1].Data4[4] = 0x78;
	Guid[1].Data4[5] = 0x12;
	Guid[1].Data4[6] = 0xF5;
	Guid[1].Data4[7] = 0xD5;

    //Get a list of devices matching the criteria (hid interface, present)
    hardwareDeviceInfoSet = SetupDiGetClassDevs (&Guid[1],
                                                 NULL, // Define no enumerator (global)
                                                 NULL, // Define no
                                                 (DIGCF_PRESENT | // Only Devices present
                                                 DIGCF_DEVICEINTERFACE)); // Function class devices.

    deviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

    //Go through the list and get the interface data
    result = SetupDiEnumDeviceInterfaces (hardwareDeviceInfoSet,
                                          NULL, //infoData,
                                          &Guid[1], //interfaceClassGuid,
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
    while (index < 20) {
		handle = ConnectToIthDevice (index);
		if (handle != INVALID_HANDLE_VALUE) {
			if (HidD_GetAttributes (handle, &deviceAttributes)) {
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
			}
			CloseHandle (handle); /* not a match - close and try again */
		}

		
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
