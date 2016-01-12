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

	HANDLE DebugHandleValue;

	HANDLE   hCams[SXCCD_MAX_CAMS];
    int      nCams;

	 /*
     * Open the first camera in list.
     */
    if ((nCams = sxOpen(hCams)) == 0)
        return (0);
    while (nCams-- > 1)
        sxClose(hCams[nCams]);
    BlockIOHandle = hCams[0];



//	vid = SXV_M916_VENDORID;
//	pid = SXV_M916_PRODUCTID;
//	ver = SXV_M916_VERSIONNUMBER;

                        
	if (BlockIOHandle == INVALID_HANDLE_VALUE) {
		MessageBox("*** Warning - Could not open BlockIO device", OKAY, true);
		OpenUSBinterfaces = false;
	} else {
		OpenUSBinterfaces = true;
		DebugHandleValue = BlockIOHandle;
	}

	spCam_Reset();

	return OpenUSBinterfaces;
}

bool spCam_Reset(void) {

	long returnVal;

	returnVal = sxReset(BlockIOHandle);

	return (returnVal != 1);

}

bool spCam_Unlink(CCD *ccd) {

	sxClose(BlockIOHandle);
	BlockIOHandle = INVALID_HANDLE_VALUE;
	OpenUSBinterfaces = false;
	return true;
}

/*
 * Get CCD information
 */

//bool spCam_GetCCDInfo(MX_SXV_INFO *info) {
//
//	DWORD ByteCount, BytesWritten, BytesReturned, ErrorNum;
//	int iTries;
//	BOOL Success;
//	HANDLE DebugHandleValue;
//	unsigned char CommandBlock[8];
//	unsigned char ReportBuffer[256];
//	char buffer[160];
//
//	DebugHandleValue = BlockIOHandle;
//
//	if (BlockIOHandle == INVALID_HANDLE_VALUE) {
//		MessageBox("INVALID VALUE FOR BLOCKIOHANDLE IN spCam_GetCCDInfo", OKAY, true);
//		return false;
//	}
//
//	// Setup command block for 'Get CCD info' command & send it.
//	
//	CommandBlock[0] = 64;
//	CommandBlock[1] = 8;  // get CCD device
//	CommandBlock[2] = 0;
//	CommandBlock[3] = 0;
//	CommandBlock[4] = 0;
//	CommandBlock[5] = 0;
//	CommandBlock[6] = 0; // parameter block length
//	CommandBlock[7] = 0;
// 	ByteCount = 8;
//	Success = WriteFile(BlockIOHandle, CommandBlock, ByteCount, &BytesWritten, 0);
//	if (! Success) {
//		MessageBox("Could not write 'Get CCD' command to Starlight Xpress camera - Try re-booting it", OKAY, true);
//		return false;
//	}
//
//	// Read in CCD info
//
//	ByteCount = 16;
//	iTries = 0;
//	do {
//		Success = ReadFile(BlockIOHandle, ReportBuffer, ByteCount, &BytesReturned, 0);
//		ErrorNum = GetLastError();
//		sprintf_s(buffer, sizeof(buffer), "*** Warning - Error # for reading from MX916 is: %d\n", ErrorNum);
//		MessageBox(buffer, OKAY, true);
//		usleep(500000);
//	} while ((! Success) && iTries++ < 10);
//	if (! Success) {
//		MessageBox("Could not read 'CCD info' - Try re-booting USB device", OKAY, true);
//		return false;
//	}
//
//	//  Save CCD info to be returned
//
//	info->height = ReportBuffer[6] + ReportBuffer[7] * 256;
//	info->width  = ReportBuffer[2] + ReportBuffer[3] * 256;
//	info->color  = ReportBuffer[12] + ReportBuffer[13] * 256;
//	info->pixel_height =  (float) ((ReportBuffer[10] + ReportBuffer[11] * 256) / 256.0);
//	info->pixel_width  = (float) ((ReportBuffer[8] + ReportBuffer[9] * 256) / 256.0);
//	info->dac_bits = ReportBuffer[14];
//
//	return true;
//}
//
/*
 * Device control.
 */

bool spCam_GetCCDInfo(MX_SXV_INFO *info) {


	ULONG returnValue;
	struct t_sxccd_params params;

	if (BlockIOHandle == INVALID_HANDLE_VALUE) {
		MessageBox("INVALID VALUE FOR BLOCKIOHANDLE IN spCam_GetCCDInfo", OKAY, true);
		return false;
	}

	// Get CCD information

	returnValue = sxGetCameraParams(BlockIOHandle, 0, &params);

	//  Save CCD info to be returned

//	params.height *= 2;
	info->height = params.height;
	info->width  = params.width;
	info->color  = params.color_matrix;
	info->pixel_height =  (float) params.pix_height;
	info->pixel_width  = (float) params.pix_width;
	info->dac_bits = params.bits_per_pixel;

	return true;
}


void ccd_control(MX_SXV_INFO *ccd, int cmd, unsigned long param)
{
}

/*
 * Request exposure.
 */

bool spCam_StartExposure(CCD *ccd, StartExposureParams *expose, StartReadoutParams *readout) {

	LONG returnVal;
	USHORT flags, xoffset, yoffset, width, height, xbin, ybin;
	ULONG msec;
	ULONG i;

	// Clear CCD pixels

	//flags = 0; // clear frame.
	//returnVal = sxClearPixels(BlockIOHandle, flags, 0);
	//flags = 8; // clear vert & horz regs.
	//returnVal = sxClearPixels(BlockIOHandle, flags, 0);

	// Set exposure parameters & start exposure

	flags = SXCCD_EXP_FLAGS_FIELD_BOTH;
	xoffset = readout->left;
	yoffset = readout->top;
	width = readout->width;
	height = readout->height;
	xbin = 1;
	ybin = 2;
	msec = expose->exposureTime * 10;

	returnVal = sxExposePixels(BlockIOHandle, flags, 0, xoffset, yoffset, width, height, xbin, ybin, msec);

	// Debugging code ******************************

	for (i=msec; i>0; i-=10) {
		if (i <= 10) {
			flags = SXCCD_EXP_FLAGS_NOWIPE_FRAME; // clear vert regs, don't clear frame pixels.
//			sxClearPixels(BlockIOHandle, flags, 0);
			usleep(i*1000);
			break;
		}
		usleep(10000);
	}

	return (returnVal != 0);

}

/*
 * Check on status of exposure (i.e. is timer done?)
 */

bool spCam_ReadStatus(unsigned int *TimerValue) {

	ULONG timerVal;

	timerVal = sxGetTimer(BlockIOHandle);


	*TimerValue = timerVal;
	return true;
}

/*
 *  Clear vertical  registers
 */

void spCam_ClearVert(void) {

	//DWORD ByteCount, BytesWritten;
	//BOOL Success;
	//unsigned char CommandBlock[64];
	//
	//CommandBlock[0] = 64;
	//CommandBlock[1] = 1;
	//CommandBlock[2] = 8;  // clear all the registers only, not frame
	//CommandBlock[3] = 0;
	//CommandBlock[4] = 0;
	//CommandBlock[5] = 0;
	//CommandBlock[6] = 0;
	//CommandBlock[7] = 0;
	//ByteCount = 8;         // command block size 8
	//Success = WriteFile(BlockIOHandle, CommandBlock, ByteCount, &BytesWritten, 0);
	//if (! Success) {
	//	MessageBox("Could not write 'Clear registers' command to Starlight Xpress camera - Try re-booting it", OKAY, true);
	//	return;
	//}

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

bool spCam_GetImage(StartReadoutParams *readout, unsigned short *image_data, unsigned int nBytesToRead) {

	// Read the image in

	LONG returnVal;
	ULONG count;
	USHORT flags, xoffset, yoffset, width, height, xbin, ybin;

	flags = SXCCD_EXP_FLAGS_FIELD_BOTH;
	xoffset = readout->left;
	yoffset = readout->top;
	width = readout->width;
	height = readout->height;
	xbin = 1;
	ybin = 1;
	count = width*height;

//	returnVal = sxLatchPixels(BlockIOHandle, flags, 0, xoffset, yoffset, width, height, xbin, ybin);
	returnVal = sxReadPixels(BlockIOHandle, image_data, count);
	return returnVal;

}

}