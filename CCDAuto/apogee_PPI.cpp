

#include "stdafx.h"

// Import the type library to create an easy to use wrapper class
#import "c:\Program Files\Common Files\System\Apogee.dll" no_namespace

#include "comutil.h"
#include "Form1.h"


ICameraPtr apCam;  // Delcare a smart pointer to the camera interface
HRESULT hr;		 // Return code from ActiveX methods

namespace CCDAuto {

bool apCam_EstablishLink(void)
{

  CoInitialize(NULL);  // Initialize the COM library

  // Create the ActiveX object from the universally unique identifier

  hr = apCam.CreateInstance(__uuidof(Camera));

  if (FAILED(hr)) {
	  Form1::StatusPrint("CreateInstance Failed...\n");
	  return false;
  } else {
  }

  // Open the camera using an ini file

  BSTR inifile = SysAllocString(L"c:\\Users\\shoup.31\\Documents\\Observatory\\CCDAuto\\ap47p.ini");
   hr = apCam->Init(inifile,-1,-1);

  if (FAILED(hr)) {
	  delete apCam;
	  apCam = NULL;
	  Form1::StatusPrint("Init failed...\n");
	  return false;
  } else {
	  apCam->PutHighPriority(false);
  }

  return true;

}

bool apCam_Unlink(void)
{
//  delete apCam;
//  apCam = NULL;

//  CoUninitialize();
  return true;
}

bool apCam_GetCCDInfo(APOGEE_INFO *info)
{
  info->MaxColumns     = apCam->Columns;
  info->MaxRows       = apCam->Rows;
  info->ImgColumns     = apCam->ImgColumns;
  if (info->ImgColumns > 1024)
	  info->ImgColumns = 1024;
  info->ImgRows       = apCam->ImgRows;
  info->MaxBinX       = apCam->MaxBinX;
  info->MaxBinY       = apCam->MaxBinY;
  info->TempCal       = apCam->TempCalibration;
  info->TempScale     = (float) apCam->TempScale;
  info->Noise         = (float) apCam->Noise;
  info->Gain          = (float) apCam->Gain;
  info->PixelXSize    = (float) apCam->PixelXSize;
  info->PixelYSize    = (float) apCam->PixelYSize;
  info->MinExposeTime = (float) apCam->MinExposure;
  info->MaxExposeTime = (float) apCam->MaxExposure;

  return true;
}

double apCam_GetCCDTemperature()
{
  double ccd_temp;
  ccd_temp = apCam->Temperature;

  return ccd_temp;
}

bool apCam_QueryTemperatureStatus(double *temp, double *setpoint,
					   int *status)
{
  Camera_CoolerStatus cstatus;
  *temp = apCam->Temperature;
  cstatus = apCam->CoolerStatus;
  *status = (int) cstatus;
  *setpoint = apCam->CoolerSetPoint;

  return true;
}

bool apCam_SetTemperatureRegulation(int enable, double setpoint)
{

  if (enable) {
    apCam->CoolerSetPoint = setpoint;
    apCam->CoolerMode = Camera_CoolerMode_On;
  } else {
    apCam->CoolerMode = Camera_CoolerMode_Shutdown;
  }
  
  return true;
}

bool apCam_StartExposure(StartExposureParams *expose)
{
  static bool success, Light;
  static double duration;
  static  int stat;
  static char Message[160];

  stat = apCam->Status;

  duration = ((double) expose->exposureTime)/100.0;
  Light = (expose->openShutter == 1);
  apCam->Expose(duration, Light);
  stat = apCam->Status;
  success = (stat == APOGEE_STATUS_EXPOSING);

  return success;
}

bool apCam_GetLine(unsigned short *image_data, short x, short y,
				  short w, short h, short xbinning, short ybinning)
{
  bool success;

  apCam->StartX = x;
  apCam->StartY = y;
  apCam->NumX = w;
  apCam->NumY = h;
  apCam->BinX = xbinning;
  apCam->BinY = ybinning;
  hr = apCam->GetLine((long) image_data);
  success = ! FAILED(hr);

  return success;
}

bool apCam_Flush(short row) {

	apCam->Flush(row);
	return true;
}

bool apCam_GetImage(unsigned short *image_data, short x, short y,
			      short w, short h, short xbinning,
			      short ybinning)
{
//  bool success;
//  short read_w, read_h;

  apCam->StartX = x;
  apCam->StartY = y;
  apCam->NumX = w;
  apCam->NumY = h;
  apCam->BinX = xbinning;
  apCam->BinY = ybinning;
  apCam->GetImage((long) image_data);

//  apCam->Flush(-1);


  return true;
}

int apCam_ReadStatus()
{
  int stat;

  stat = apCam->Status;

  return stat;
}
}