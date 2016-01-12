
#include "stdafx.h"
#include <stdio.h>
//#include <unistd.h>
//#include <fcntl.h>
//#include <errno.h>
//#include <sys/ioctl.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "apogee.h"
#include "doRoutines.h"
//#include "truefalse.h"
//#include "sbigudrv.h"

namespace CCDAuto {

typedef struct {
  int MaxColumns;
  int MaxRows;
  int ImgColumns;
  int ImgRows;
  int MaxBinX;
  int MaxBinY;
  float TempCal;
  float TempScale;
  float Noise;
  float Gain;
  float PixelXSize;
  float PixelYSize;
  float MinExposeTime;
  float MaxExposeTime;
} APOGEE_INFO;


int InitCam( char* cfgname );

CCameraIO *apCam = (CCameraIO *) NULL;


extern "C" int apCam_EstablishLink(void)
{
  bool success;

  success = (InitCam("/opt/apogee/config/ap47p.ini") == 0);
  //  apCam->Reset();
  apCam->read_Present();

  return success;
}

extern "C" int apCam_Unlink(void)
{

  delete apCam;
  apCam = NULL;

  return TRUE;
}

extern "C" int apCam_GetCCDInfo(APOGEE_INFO *info)
{
  info->MaxColumns     = apCam->m_Columns;
  info->MaxRows       = apCam->m_Rows;
  info->ImgColumns     = apCam->m_ImgColumns;
  info->ImgRows       = apCam->m_ImgRows;
  info->MaxBinX       = apCam->m_MaxBinX;
  info->MaxBinY       = apCam->m_MaxBinY;
  info->TempCal       = apCam->m_TempCalibration;
  info->TempScale     = apCam->m_TempScale;
  info->Noise         = apCam->m_Noise;
  info->Gain          = apCam->m_Gain;
  info->PixelXSize    = apCam->m_PixelXSize;
  info->PixelYSize    = apCam->m_PixelYSize;
  info->MinExposeTime = apCam->m_MinExposure;
  info->MaxExposeTime = apCam->m_MaxExposure;

  return TRUE;
}

extern "C" double apCam_GetCCDTemperature()
{
  double ccd_temp;
  ccd_temp = apCam->read_Temperature();

  return ccd_temp;
}

extern "C" int apCam_QueryTemperatureStatus(double *temp, double *setpoint,
					    Camera_CoolerStatus *status)
{
  *temp = apCam->read_Temperature();
  *status = apCam->read_CoolerStatus();
  *setpoint = apCam->read_CoolerSetPoint();

  return TRUE;
}
  
extern "C" int apCam_SetTemperatureRegulation(int enable, double setpoint)
{

  if (enable) {
    apCam->write_CoolerSetPoint(setpoint);
    apCam->write_CoolerMode(Camera_CoolerMode_On);
  } else {
    apCam->write_CoolerMode(Camera_CoolerMode_Shutdown);
  }
  
  return TRUE;
}

extern "C" int apCam_StartExposure(StartExposureParams *expose)
{
  int success;
  bool Light;
  double duration;

  duration = ((double) expose->exposureTime)/100.0;
  Light = (expose->openShutter == 1);
  success = apCam->Expose(duration, Light);

  return success;
}

extern "C" int apCam_GetImage(unsigned short *image_data, short x, short y,
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

extern "C" int apCam_ReadStatus()
{
  int stat;

  stat = apCam->read_Status();

  return stat;
}

}