#include "stdafx.h"

// Import the type library to create an easy to use wrapper class
//#import "C:\Documents and Settings\tshoup\My Documents\Visual Studio 2005\EDSDK21_Win\Windows\EDSDK\Dll\EDSDK.dll" no_namespace

//#include "comutil.h"
#include "Form1.h"
//#include "EDSDK.h"
//#include "EDSDKTypes.h"
//#include "EDSDKErrors.h"


//EdsCameraRef camera = NULL;
bool SDKInitialized = false;

namespace CCDAuto {

bool Canon_EstablishLink(CCD *ccd)
{
	//EdsError err = EDS_ERR_OK;
	//EdsCameraListRef cameraList = NULL;
	//EdsUInt32	 count = 0;	
	//EdsDeviceInfo deviceInfo;

	//// Initialize Canon EDSDK library

	//if (! SDKInitialized) {
	//	err = EdsInitializeSDK();
	//	if (err != EDS_ERR_OK) {
	//		Form1::StatusPrint("*** Error - Can't initialize Canon EDSDK Library.\n");
	//		return false;
	//	}
	//	SDKInitialized = true;
	//}

	//// Get list of Canon cameras attached to pc

	//err = EdsGetCameraList(&cameraList);
	//if (err != EDS_ERR_OK) {
	//	Form1::StatusPrint("*** Error - Can't get list of Canon cameras attached to pc.\n");
	//	EdsTerminateSDK();
	//	SDKInitialized = false;
	//	return false;
	//}

	//// Get # of cameras attached
	//
	//err = EdsGetChildCount(cameraList, &count);
	//if (err != EDS_ERR_OK) {
	//	Form1::StatusPrint("*** Error - Can't get # of Canon cameras attached to pc.\n");
	//	if (cameraList != NULL)
	//		EdsRelease(cameraList);
	//	EdsTerminateSDK();
	//	SDKInitialized = false;
	//	return false;
	//}
	//if (count <= 0) {
	//	Form1::StatusPrint("*** Warning - No Canon cameras can be found.\n");
	//	if (cameraList != NULL)
	//		EdsRelease(cameraList);
	//	EdsTerminateSDK();
	//	SDKInitialized = false;
	//	return false;
	//}

	//// Connect to camera at head of camera list & its info
	//
	//err = EdsGetChildAtIndex(cameraList , 0 , &camera);	
	//if (err != EDS_ERR_OK) {
	//	Form1::StatusPrint("*** Warning - Can't lookup camera.\n");
	//	if (camera != NULL)
	//		EdsRelease(camera);
	//	if (cameraList != NULL)
	//		EdsRelease(cameraList);
	//	EdsTerminateSDK();
	//	SDKInitialized = false;
	//	return false;
	//}
	//err = EdsGetDeviceInfo(camera , &deviceInfo);
	//if (err != EDS_ERR_OK) {
	//	Form1::StatusPrint("*** Warning - Can't get info on camera.\n");
	//	if (camera != NULL)
	//		EdsRelease(camera);
	//	if (cameraList != NULL)
	//		EdsRelease(cameraList);
	//	EdsTerminateSDK();
	//	SDKInitialized = false;
	//	return false;
	//}

	////Release camera list

	//if (cameraList != NULL) {
	//	EdsRelease(cameraList);
	//}

	//// Open Session to camera

	//err = EdsOpenSession(camera);
	//if (err != EDS_ERR_OK) {
	//	Form1::StatusPrint("*** Warning - Can't open session with camera.\n");
	//	if (camera != NULL)
	//		EdsRelease(camera);
	//	EdsTerminateSDK();
	//	SDKInitialized = false;
	//	return false;
	//}

  return false;

}

bool Canon_Unlink(CCD *ccd)
{
	//EdsCloseSession(camera);
	//EdsRelease(camera);
	//EdsTerminateSDK();
	//SDKInitialized = false;
	return false;
}

bool Canon_GetCCDInfo(CANON_INFO *info)
{

	info->MaxColumns = 3456;
	info->MaxRows = 2304;
	return true;
}

bool Canon_StartExposure(StartExposureParams *expose)
{
  static bool success, Light;
  static double duration;
  static  int stat;
  static char Message[160];

//  stat = apCam->Status;

  duration = ((double) expose->exposureTime)/100.0;
  Light = (expose->openShutter == 1);
//  apCam->Expose(duration, Light);
//  stat = apCam->Status;
//  success = (stat == APOGEE_STATUS_EXPOSING);
  success = false;

  return success;
}

bool Canon_GetImage(unsigned short *image_data, short x, short y,
			      short w, short h, short xbinning,
			      short ybinning)
{

  //apCam->StartX = x;
  //apCam->StartY = y;
  //apCam->NumX = w;
  //apCam->NumY = h;
  //apCam->BinX = xbinning;
  //apCam->BinY = ybinning;
  //apCam->GetImage((long) image_data);

  return false;
}

int Canon_GetStatus()
{
  int stat;

//  stat = apCam->Status;
  stat = 0;

  return stat;
}
}