
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "lsbigusbcam.h"
#include "lsbiglptcam.h"

SbigCam *pCam = (SbigCam *) NULL;

extern "C" int pCam_QueryTemperatureStatus(QueryTemperatureStatusResults *ptr)
{
  return pCam->QueryTemperatureStatus(ptr);
}

extern "C" double pCam_CalcCcdTemperature(QueryTemperatureStatusResults *ptr)
{
  return pCam->CalcCcdTemperature(ptr);
}

extern "C" int pCam_GetStatus(void)
{
  return pCam->GetStatus();
}

extern "C" char *pCam_GetStatusString(void)
{
  return pCam->GetStatusString();
}

extern "C" int pCam_EstablishLink(char *device)
{
  int status;

  if (strstr(device,"lpt") != NULL) {
    pCam = new SbigLptCam(device);
    status = pCam->GetStatus();
    if (status == CE_NO_ERROR)
      status = pCam->EstablishLink();
    return status;
  } else if (strstr(device,"usb") != NULL) {
    pCam = new SbigUsbCam(device);
    status = pCam->GetStatus();
    if (status == CE_NO_ERROR)
      status = pCam->EstablishLink();
  } else {
    status = -1;
  }

  return status;
}

extern "C" int pCam_Unlink(void)
{
  delete pCam;
  pCam = (SbigCam *) NULL;
  return CE_NO_ERROR;
}


extern "C" int pCam_GetCCDInfo(GetCCDInfoParams *parms, void *results)
{
  return pCam->GetCCDInfo(parms, results);
}

extern "C" double pCam_CalcAmbTemperature(QueryTemperatureStatusResults *ptr)
{
  return pCam->CalcAmbTemperature(ptr);
}

extern "C" int pCam_PulseOut(PulseOutParams *parms)
{
  return pCam->PulseOut(parms);
}

extern "C" int pCam_CalcSetpoint(float t)
{
  return pCam->CalcSetpoint(t);
}

extern "C" int pCam_SetTemperatureRegulation(SetTemperatureRegulationParams *ptr)
{
  return pCam->SetTemperatureRegulation(ptr);
}

extern "C" int pCam_StartExposure(StartExposureParams *parms)
{
  return pCam->StartExposure(parms);
}

extern "C" int pCam_QueryCommandStatus(QueryCommandStatusParams *parms,
				       QueryCommandStatusResults *results)
{
  return pCam->QueryCommandStatus(parms, results);
}

extern "C" int pCam_EndExposure(EndExposureParams *parms)
{
  return pCam->EndExposure(parms);
}

extern "C" int pCam_ReadoutLine(ReadoutLineParams *parms,
				unsigned short *results, bool subtract)
{
  return pCam->ReadoutLine(parms, results, subtract);
}
