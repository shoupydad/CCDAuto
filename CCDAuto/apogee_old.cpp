
#include "stdafx.h"
//#include <stdio.h>
//#include <math.h>
//#include <time.h>
//#include <stdlib.h>
#include "Form1.h"
#include "doRoutines.h"

// Import the type library to create an easy to use wrapper class
#import "c:\Program Files\Common Files\System\Apogee.dll" no_namespace

//ICameraPtr cam;  // Delcare a smart pointer to the camera interface
//HRESULT hr;		 // Return code from ActiveX methods

namespace CCDAuto {

int apCam_EstablishLink(void)
{
  bool success;

  CoInitialize(NULL);  // Initialize the COM library

  // Create the ActiveX object from the universally unique identifier

//  hr = cam.CreateInstance(__uuidof(Camera));

//  if (FAILED(hr)) {
//	  Form1::StatusPrint("apCam_EstablishLink: CreateInstance Failed...");
//	  CoUninitialize();
//	  return -1;
//  } else {
//	  Form1::StatusPrint("apCam_EstablishLink: CreateInstance Suceeded...");
//  }

  // Open the camera using an ini file

//  _bstr_t inifile = _bstr_t("ap47p.ini");
//  hr = cam->Init(inifile,-1,-1);
//  if (FAILED(hr)) {
//	  cam = NULL;
//	  Form1::SetStatus("Init failed...");
//	  return -1;
//  } else {
//	  Form1::SetStatus("Init Suceeded...");
//  }
//  success = (InitCam("/opt/apogee/config/ap47p.ini") == 0);
  //  apCam->Reset();
//  apCam->read_Present();

  return success;
}

/*
int apCam_Unlink(void)
{

  delete apCam;
  apCam = NULL;

  return TRUE;
}

int apCam_GetCCDInfo(APOGEE_INFO *info)
{
  info->MaxColumns     = apCam->m_Columns;
  info->MaxRows       = apCam->m_Rows;
  info->ImgColumns     = apCam->m_ImgColumns;
  info->ImgRows       = apCam->m_ImgRows;
  info->MaxBinX       = apCam->m_MaxBinX;
  info->MaxBinY       = apCam->m_MaxBinY;
  info->TempCal       = apCam->m_TempCalibration;
  info->TempScale     = (float) apCam->m_TempScale;
  info->Noise         = (float) apCam->m_Noise;
  info->Gain          = (float) apCam->m_Gain;
  info->PixelXSize    = (float) apCam->m_PixelXSize;
  info->PixelYSize    = (float) apCam->m_PixelYSize;
  info->MinExposeTime = (float) apCam->m_MinExposure;
  info->MaxExposeTime = (float) apCam->m_MaxExposure;

  return TRUE;
}

double apCam_GetCCDTemperature()
{
  double ccd_temp;
  ccd_temp = apCam->read_Temperature();

  return ccd_temp;
}

int apCam_QueryTemperatureStatus(double *temp, double *setpoint,
					    Camera_CoolerStatus *status)
{
  *temp = apCam->read_Temperature();
  *status = apCam->read_CoolerStatus();
  *setpoint = apCam->read_CoolerSetPoint();

  return TRUE;
}
  
int apCam_SetTemperatureRegulation(int enable, double setpoint)
{

  if (enable) {
    apCam->write_CoolerSetPoint(setpoint);
    apCam->write_CoolerMode(Camera_CoolerMode_On);
  } else {
    apCam->write_CoolerMode(Camera_CoolerMode_Shutdown);
  }
  
  return TRUE;
}

int apCam_StartExposure(StartExposureParams *expose)
{
  int success;
  bool Light;
  double duration;

  duration = ((double) expose->exposureTime)/100.0;
  Light = (expose->openShutter == 1);
  success = apCam->Expose(duration, Light);

  return success;
}

int apCam_GetImage(unsigned short *image_data, short x, short y,
			      short w, short h, short xbinning,
			      short ybinning)
{
  bool success;
  short read_w, read_h;

  apCam->m_ExposureSkipR = y;
  apCam->m_ExposureSkipC = x;
  apCam->m_ExposureNumX = read_w = w;
  apCam->m_ExposureNumY = read_h = h;
  apCam->m_ExposureBinX = xbinning;
  apCam->m_ExposureBinY = ybinning;
  success = apCam->GetImage(image_data, read_w, read_h);

  return success;
}

int apCam_ReadStatus()
{
  int stat;

  stat = apCam->read_Status();

  return stat;
} */

}