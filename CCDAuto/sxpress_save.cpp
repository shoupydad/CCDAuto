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
#include <hidsdi.h>
#include "doRoutines.h"

namespace CCDAuto {

/***************************************************************************\
*                                                                           *
*                     Low level CCD camera control                          *
*                                                                           *
\***************************************************************************/
/*
 * Connect to CCD camera.
 */

typedef struct {
	long int cbsize;
	_GUID InterfaceClassGuid;
	long int flags;
	long int ReservedPtr;
} DEVICE_INTERFACE_DATA;

typedef struct {
	long int cbsize;
	char DataPath[256];
} DEVICE_INTERFACE_DETAIL;

typedef struct {
	long int nLength;
	long int lpSecurityDescriptor;
	long int bIneritHandle;
} SECURITY_ATTRIBUTES;      

bool spCam_EstablishLink(CCD *ccd) {

	_GUID Guid[2];  //	  Dim Guid(1) As Guid
	DEVICE_INTERFACE_DATA DeviceInterfaceData; // Dim DeviceInterfaceData As Device_Interface_Data
	DEVICE_INTERFACE_DETAIL FunctionClassDeviceData; // Dim FunctionClassDeviceData As Device_Interface_Detail
	int Device, Interface, i;  // Dim Device As Integer, Interface As Integer, i As Integer
	long int PnPHandle; // Dim PnPHandle As Long
	long int BytesReturned; // Dim BytesReturned As Long
	bool Success, Openned; // Dim Success As Boolean, Openned As Boolean
	char DeviceName[256]; // Dim DeviceName As String
	char Buffer1[256]; // Dim Buffer1(256) As Byte
	long int *BytesReturnedPtr = &BytesReturned; // BytesReturnedPtr& = VarPtr(BytesReturned&)
	char *BufferPtr = Buffer1; // BufferPtr& = VarPtr(Buffer1(0))
	char v[80], *vptr;
	char p[80], *pptr;
	char Name[160];
	char camname[80];

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

		// Get a handle for the PnP node and request currently active devices

	PnPHandle = SetupDiGetClassDevs(&Guid[Interface], 0, 0, 0x12);
	if (PnPHandle == -1) {
		MessageBox("Could not attach to PnP node", OKAY);
		return false;
	}
	DeviceInterfaceData.cbsize = sizeof(DeviceInterfaceData);

	// Look for a maximum of 20 devices (Handle(Interface) = -1)

	strcpy_s(v, sizeof(v), "0");
	strcpy_s(p, sizeof(p), "0");

	for (Device=0; Device<20; Device++) {

		// Is there a device at this table entry?

		Success = SetupDiEnumDeviceInterfaces(&PnPHandle, 0, Guid[Interface], Device, &DeviceInterfaceData);
		if (Success) {

			// There is a device here, get its name

			FunctionClassDeviceData.cbsize = 5;
			Success = SetupDiGetDeviceInterfaceDetail(&PnPHandle, &DeviceInterfaceData, &FunctionClassDeviceData, 256,
				&BytesReturned, 0);
			if (! Success) {
				MessageBox("Could not find the system name for this device", OKAY);
				return false;
			}

			Name[0] = 0;
			i = 0;
			while (FunctionClassDeviceData.DataPath[i] != 0) {
				Name[i] = FunctionClassDeviceData.DataPath[i];
				i++;
			}

			vptr = strstr(Name, "vid");
            pptr = strstr(Name, "pid");
			strncpy_s(v, sizeof(v), vptr, 4);
			strncpy_s(v, sizeof(v), vptr, 4);
			
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

//	SECURITY_ATTRIBUTES sa; // Dim sa As Security_Attributes
//
//            Handle(Interface) = CreateFile(Name$, &HC0000000, 3, sa, 3, 0, 0)
//
//            BlockIOHandle& = Handle(Interface)
//                      
//            If Handle(Interface) = -1 Then MsgBox "Could not open BlockIO device": CloseHandle (PnPHandle): OpenUSBinterfaces = False: GoTo USB_end
//            MsgBox "Starlight Xpress " + camname$ + " camera found, VID = " + v$ + ", PID = " + p$ + ", Handle = " + Str$(Handle(Interface))
//            
//            OpenUSBinterfaces = True
//
//USB_end:
//DoEvents
// 'Stop
//End Function

	return false;
}

bool spCam_Unlink(CCD *ccd)
{
  return FALSE;
}

/*
 * Get CCD information
 */

bool spCam_GetCCDInfo(MX_SXV_INFO *info)
{
	return FALSE;
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

bool spCam_StartExposure(CCD *ccd, StartExposureParams *expose,
			StartReadoutParams *readout)
{
  return FALSE;
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

bool spCam_ReadoutLine(CCD *ccd, StartReadoutParams *readout,
		      unsigned short *linePtr, unsigned short firstRow)
{

	return FALSE;
}

}