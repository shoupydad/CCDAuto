/*
 * GCCD - Gnome CCD Camera Controller
 * Copyright (C) 2001 David Schmenk
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */


#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <Setupapi.h>
extern "C" {
#include "USB/hidsdi.h"
}

#include "USB/usb.h"
#include "sxusbcam.h"
#include "doRoutines.h"

#pragma comment(lib, "USB/setupapi.lib")
#pragma comment(lib, "USB/hid.lib")

#define SXV_M916_VENDORID 1278
#define SXV_M916_PRODUCTID 200
#define SXV_M916_VERSIONNUMBER 0

namespace CCDAuto {

HANDLE BlockIOHandle=INVALID_HANDLE_VALUE;

bool OpenUSBinterfaces=false;

/***************************************************************************\
*                                                                           *
*                     Low level CCD camera control                          *
*                                                                           *
\***************************************************************************/
/*
 * Connect to CCD camera.
 */

bool spCam_EstablishLink(CCD *ccd) {

	GUID Guid[2];  //	  Dim Guid(1) As Guid
	SP_DEVICE_INTERFACE_DATA DeviceInterfaceData; // Dim DeviceInterfaceData As Device_Interface_Data
	PSP_DEVICE_INTERFACE_DETAIL_DATA_W FunctionClassDeviceData; // Dim FunctionClassDeviceData As Device_Interface_Detail
	int Device, Interface;  // Dim Device As Integer, Interface As Integer, i As Integer
	unsigned int PathLength, i;
    HDEVINFO hardwareDeviceInfoSet;
	DWORD BytesReturned; // Dim BytesReturned As Long
	DWORD Success;
	HANDLE DebugHandleValue;
	char buffer[256];
	DWORD *BytesReturnedPtr = &BytesReturned; // BytesReturnedPtr& = VarPtr(BytesReturned&)
	char v[80], *vptr;
	char p[80], *pptr;
	char Name[160];
	char camname[80];
	WCHAR deviceName[160];

	HANDLE   hCams[SXCCD_MAX_CAMS], hCam;
    int      nCams;

	 /*
     * Open the first camera in list.
     */
    if ((nCams = sxOpen(hCams)) == 0)
        return (0);
    while (nCams-- > 1)
        sxClose(hCams[nCams]);
    hCam = hCams[0];



//	vid = SXV_M916_VENDORID;
//	pid = SXV_M916_PRODUCTID;
//	ver = SXV_M916_VERSIONNUMBER;

	// Initialize the GUID array

	HidD_GetHidGuid(&Guid[0]); // Call HidD_GetHidGuid(Guid(0).Data0)
   
	// This is the Guid for the BlockIO interface
   
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
        
	// Open the BlockIO interface

	Interface = 1;

		// Get a handle for the BlockIO class and request currently active devices

	hardwareDeviceInfoSet = SetupDiGetClassDevs(&Guid[Interface],
		NULL, // Define no enumerator (global)
		NULL, // Define no
		(DIGCF_PRESENT | // Only Devices present
		DIGCF_DEVICEINTERFACE)); // Function class devices
    DeviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

	strcpy_s(v, sizeof(v), "0");
	strcpy_s(p, sizeof(p), "0");

	for (Device=0; Device<20; Device++) {

		// Is there a device at this table entry?

		Success = SetupDiEnumDeviceInterfaces(hardwareDeviceInfoSet, 0,
			&Guid[Interface], Device, &DeviceInterfaceData);
		if (Success == TRUE) {

			// There is a device here, get its name

			Success = SetupDiGetDeviceInterfaceDetail(hardwareDeviceInfoSet, &DeviceInterfaceData, NULL, 0,
				&BytesReturned, 0);
			FunctionClassDeviceData = (PSP_INTERFACE_DEVICE_DETAIL_DATA)malloc(BytesReturned);
			FunctionClassDeviceData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA_W);
			Success = SetupDiGetDeviceInterfaceDetail(hardwareDeviceInfoSet, &DeviceInterfaceData, FunctionClassDeviceData, BytesReturned,
				&BytesReturned, NULL);
			PathLength = BytesReturned - sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA_W);
			if (Success == FALSE) {
				MessageBox("Could not find the system name for this device", OKAY);
				SetupDiDestroyDeviceInfoList (hardwareDeviceInfoSet);
				free (FunctionClassDeviceData);
				return false;
			}

			deviceName[0] = 0;
			Name[0] = 0;
			for (i=0; i<PathLength; i++) {
				deviceName[i] = FunctionClassDeviceData->DevicePath[i];
				Name[i] = (char) deviceName[i];
			}
			deviceName[i] = Name[i] = 0;

			//i = 0;
			//while (FunctionClassDeviceData->DevicePath[i] != 0) {
			//	deviceName[i] = FunctionClassDeviceData->DevicePath[i];
			//	Name[i] = (char) deviceName[i];
			//	i++;
			//}

			vptr = strstr(Name, "vid");
            pptr = strstr(Name, "pid");
			strncpy_s(v, sizeof(v), vptr+4, 4);
			strncpy_s(p, sizeof(p), pptr+4, 4);
			
			if (strcmp(v,"1278") == 0) {
				if (strcmp(p,"0115") == 0) {
					strcpy_s(camname, sizeof(camname), "SXV-H5");
					break;
				} else if (strcmp(p,"0119") == 0) {
					strcpy_s(camname,sizeof(camname),"SXV-H9");
					break;
				} else if (strcmp(p,"0319") == 0) {
					strcpy_s(camname,sizeof(camname),"SXV-H9C");
					break;
				} else if (strcmp(p,"0105") == 0) {
					strcpy_s(camname,sizeof(camname),"SXV-M5");
					break;
				} else if (strcmp(p,"0305") == 0) {
					strcpy_s(camname,sizeof(camname),"SXV-M5C");
					break;
				} else if (strcmp(p,"0107") == 0) {
					strcpy_s(camname,sizeof(camname),"SXV-M7");
					break;
				} else if (strcmp(p,"0307") == 0) {
					strcpy_s(camname,sizeof(camname),"SXV-M7C");
					break;
				} else if (strcmp(p,"0109") == 0) {
					strcpy_s(camname,sizeof(camname),"SXV-M9");
					break;
				} else if (strcmp(p,"0325") == 0) {
					strcpy_s(camname,sizeof(camname),"SXV-M25C");
					break;
				} else if (strcmp(p,"0125") == 0) {
					strcpy_s(camname,sizeof(camname),"SXV-M25C");
					break;
				} else if (strcmp(p,"0100") == 0) {
					strcpy_s(camname,sizeof(camname),"Generic SXV camera");
					break;
				} else if (strcmp(p,"0200") == 0) {
					strcpy_s(camname,"USB2 interface module for MX");
					break;
				} else if (strcmp(p,"1010") == 0) {
					strcpy_s(camname,sizeof(camname),"");
					break;
				}
			} else if ((strcmp(v,"04B4") == 0) && (strcmp(p,"8613") == 0)) {
				strcpy_s(camname,sizeof(camname),"Empty Cypress USB2 chip");
			}
		}
	}

	if (Device >= 20) {
		MessageBox("Sorry, no SXV cameras found...", OKAY);
		return false;
	}
                        
	// Can now open this device

    BlockIOHandle = CreateFile(deviceName, 0xC0000000, 3, NULL, 3, 0, 0);
  //  BlockIOHandle = CreateFile(deviceName,
		//GENERIC_READ | GENERIC_WRITE,
		//FILE_SHARE_READ | FILE_SHARE_WRITE,
		//NULL,        // no SECURITY_ATTRIBUTES structure
		//OPEN_EXISTING, // No special create flags
		//FILE_FLAG_OVERLAPPED, 
		//NULL);       // No template file
	if (BlockIOHandle == INVALID_HANDLE_VALUE) {
//		MessageBox("Could not open BlockIO device", OKAY);
		OpenUSBinterfaces = false;
	} else {
		sprintf_s(buffer, sizeof(buffer), "Connected to Starlight Xpress %s camera (VID: %s, PID: %s", camname, v, p);
		MessageBox(buffer, OKAY);
		OpenUSBinterfaces = true;
		DebugHandleValue = BlockIOHandle;
	}

	spCam_Reset();

	return OpenUSBinterfaces;
}

bool spCam_Reset(void) {

	DWORD ByteCount, BytesWritten;
	bool Success;
	unsigned char CommandBlock[8];

	// Setup command block for 'Get CCD info' command & send it.
	
	CommandBlock[0] = 64;
	CommandBlock[1] = 6;  // reset CCD device
	CommandBlock[2] = 0;
	CommandBlock[3] = 0;
	CommandBlock[4] = 0;
	CommandBlock[5] = 0;
	CommandBlock[6] = 0; // parameter block length
	CommandBlock[7] = 0;
 	ByteCount = 8;
	Success = WriteFile(BlockIOHandle, CommandBlock, ByteCount, &BytesWritten, 0);
	if (! Success) {
		MessageBox("Could not write 'Get CCD' command to Starlight Xpress camera - Try re-booting it", OKAY);
		return false;
	}
	return true;
}

bool spCam_Unlink(CCD *ccd) {
	CloseHandle(BlockIOHandle);
	BlockIOHandle = INVALID_HANDLE_VALUE;
	OpenUSBinterfaces = false;
	return true;
}

/*
 * Get CCD information
 */

bool spCam_GetCCDInfo(MX_SXV_INFO *info) {

	DWORD ByteCount, BytesWritten, BytesReturned, ErrorNum;
	int iTries;
	bool Success;
	HANDLE DebugHandleValue;
	unsigned char CommandBlock[8];
	unsigned char ReportBuffer[256];

	DebugHandleValue = BlockIOHandle;

	if (BlockIOHandle == INVALID_HANDLE_VALUE) {
		MessageBox("INVALID VALUE FOR BLOCKIOHANDLE IN spCam_GetCCDInfo", OKAY);
		return false;
	}

	// Setup command block for 'Get CCD info' command & send it.
	
	CommandBlock[0] = 64;
	CommandBlock[1] = 8;  // get CCD device
	CommandBlock[2] = 0;
	CommandBlock[3] = 0;
	CommandBlock[4] = 0;
	CommandBlock[5] = 0;
	CommandBlock[6] = 0; // parameter block length
	CommandBlock[7] = 0;
 	ByteCount = 8;
	Success = WriteFile(BlockIOHandle, CommandBlock, ByteCount, &BytesWritten, 0);
	if (! Success) {
		MessageBox("Could not write 'Get CCD' command to Starlight Xpress camera - Try re-booting it", OKAY);
		return false;
	}

	// Read in CCD info

	ByteCount = 16;
	iTries = 0;
//	do {
		Success = ReadFile(BlockIOHandle, ReportBuffer, ByteCount, &BytesReturned, 0);
		ErrorNum = GetLastError();
//		usleep(500000);
//	} while ((! Success) && iTries++ < 10);
	if (! Success) {
		MessageBox("Could not read 'CCD info' - Try re-booting USB device", OKAY);
		return false;
	}

	//  Save CCD info to be returned

	info->height = ReportBuffer[6] + ReportBuffer[7] * 256;
	info->width  = ReportBuffer[2] + ReportBuffer[3] * 256;
	info->color  = ReportBuffer[12] + ReportBuffer[13] * 256;
	info->pixel_height =  (float) ((ReportBuffer[10] + ReportBuffer[11] * 256) / 256.0);
	info->pixel_width  = (float) ((ReportBuffer[8] + ReportBuffer[9] * 256) / 256.0);
	info->dac_bits = ReportBuffer[14];

	return true;
}

/*
 * Device control.
 */

void ccd_control(MX_SXV_INFO *ccd, int cmd, unsigned long param)
{
}

/*
 * Request exposure.
 */

bool spCam_StartExposure(CCD *ccd, StartExposureParams *expose, StartReadoutParams *readout) {

	DWORD ByteCount, BytesWritten;
	unsigned int ExTimeMS;
	bool Success;
	unsigned char Ex1, Ex2, Ex3, Ex4, BinV, BinH, CommandBlock[64];

	// Wipe charge from pixels (exposure is continuously running?)

	CommandBlock[0] = 64;
	CommandBlock[1] = 1;
	CommandBlock[2] = 0;  // don't clear the registers
	CommandBlock[3] = 0;
	CommandBlock[4] = 0;
	CommandBlock[5] = 0;
	CommandBlock[6] = 0;
	CommandBlock[7] = 0;
	ByteCount = 8;        //command block size 8
	Success = WriteFile(BlockIOHandle, CommandBlock, ByteCount, &BytesWritten, 0);
	if (! Success) {
		MessageBox("Could not write 'Clear pixels' command to Starlight Xpress camera - Try re-booting it", OKAY);
		return false;
	}

	// Set exposure timer

		// Command Block

	CommandBlock[0] = 64;
	CommandBlock[1] = 2;  // read camera data
	CommandBlock[2] = 3;  // even + odd field
	CommandBlock[3] = 0;
	CommandBlock[4] = 0;  // main camera
	CommandBlock[5] = 0;
	CommandBlock[6] = 14; // parameter block length
	CommandBlock[7] = 0;
                        
		// parameter block

	ExTimeMS = expose->exposureTime*10; // convert from 0.01 to 0.001 seconds
	Ex4 = (ExTimeMS & 0xff000000)>>24;
	Ex3 = (ExTimeMS & 0x00ff0000)>>16;
	Ex2 = (ExTimeMS & 0x0000ff00)>>8;
	Ex1 = (ExTimeMS & 0x000000ff);
	BinH = BinV = 1;
	switch (readout->readoutMode) {
		case 0: // 1x1 binning
			BinH = BinV = 1;
			break;
		case 1: // 2x2 binning
			BinH = BinV = 2;
			break;
		case 2: // 3x3 binning
			BinH = BinV = 3;
			break;
	}

	CommandBlock[8] = 0;
	CommandBlock[9] = 0;
	CommandBlock[10] = 0;
	CommandBlock[11] = 0;
	CommandBlock[12] = readout->width & 0x00ff;
	CommandBlock[13] = readout->width >> 8;
	CommandBlock[14] = readout->height & 0x00ff;
	CommandBlock[15] = readout->height >> 8;
	CommandBlock[16] = BinH;
	CommandBlock[17] = BinV;
	CommandBlock[18] = Ex4;
	CommandBlock[19] = Ex3;
	CommandBlock[20] = Ex2;
	CommandBlock[21] = Ex1;
	
	ByteCount = 22;  // command block + parameter block size 22
	Success = WriteFile(BlockIOHandle, CommandBlock, ByteCount, &BytesWritten, 0);
	if (! Success) {
		MessageBox("Could not write 'READ_PIXELS_DELAYED' command to Starlight Xpress camera - Try re-booting it", OKAY);
		return false;
	}
	
	return true;
}

/*
 * Check on status of exposure (i.e. is timer done?)
 */

bool spCam_ReadStatus(unsigned int *TimerValue) {

	DWORD ByteCount, BytesWritten, BytesReturned;
	bool Success;
	unsigned char CommandBlock[64], ReportBuffer[16];

	// Send command to read current timer value

	CommandBlock[0] = 64;
	CommandBlock[1] = 5;
	CommandBlock[2] = 0;
	CommandBlock[3] = 0;
	CommandBlock[4] = 0;
	CommandBlock[5] = 0;
	CommandBlock[6] = 0;
	CommandBlock[7] = 0;
	ByteCount = 8;        //command block size 8
	Success = WriteFile(BlockIOHandle, CommandBlock, ByteCount, &BytesWritten, 0);
	if (! Success) {
		MessageBox("Could not write 'Clear pixels' command to Starlight Xpress camera - Try re-booting it", OKAY);
		return false;
	}

	// Get the timer value

	ByteCount = 4;
	Success = ReadFile(BlockIOHandle, ReportBuffer, ByteCount, &BytesReturned, 0);
	if (! Success) {
		MessageBox("Could not read 'CCD timer value' - Try re-booting USB device", OKAY);
		return false;
	}

	*TimerValue = ReportBuffer[0] + (ReportBuffer[1]<<8) + (ReportBuffer[2]<<16) + (ReportBuffer[3]<<24);
	return true;
}

/*
 *  Clear vertical  registers
 */

void spCam_ClearVert(void) {

	DWORD ByteCount, BytesWritten;
	bool Success;
	unsigned char CommandBlock[64];
	
	CommandBlock[0] = 64;
	CommandBlock[1] = 1;
	CommandBlock[2] = 8;  // clear all the registers only, not frame
	CommandBlock[3] = 0;
	CommandBlock[4] = 0;
	CommandBlock[5] = 0;
	CommandBlock[6] = 0;
	CommandBlock[7] = 0;
	ByteCount = 8;         // command block size 8
	Success = WriteFile(BlockIOHandle, CommandBlock, ByteCount, &BytesWritten, 0);
	if (! Success) {
		MessageBox("Could not write 'Clear registers' command to Starlight Xpress camera - Try re-booting it", OKAY);
		return;
	}

	return;
}

/*
 * Abort current exposures.
 */

bool spCam_EndExposure(CCD *ccd)
{

  return FALSE;
}

/*
 * Load exposed image one row at a time.
 */

bool spCam_GetImage(unsigned short *image_data, unsigned int nBytesToRead) {

	// Read the image in

	DWORD ByteCount, BytesReturned;
	bool Success;

	ByteCount = nBytesToRead;
	Success = ReadFile(BlockIOHandle, image_data, ByteCount, &BytesReturned, 0);
	if (! Success) {
		MessageBox("Could not read 'CCD timer value' - Try re-booting USB device", OKAY);
		return false;
	}

	return true;
}

}