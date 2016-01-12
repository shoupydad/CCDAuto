
#include "stdafx.h"
//#include <stdio.h>
//#include <unistd.h>
//#include <fcntl.h>
//#include <errno.h>
//#include <sys/ioctl.h>
//#include <math.h>
//#include <time.h>
//#include <stdlib.h>

//#include "lsbigusbcam.h"
//#include "lsbiglptcam.h"

#include "csbigcam.h"

namespace CCDAuto {


CSBIGCam *pCam = (CSBIGCam *) NULL;

int pCam_QueryTemperatureStatus(MY_LOGICAL *enabled, double *ccd_temp,
					   double *air_temp, double *setpointTemp,
					   double *percentTE)
{
  PAR_ERROR status;

  status = pCam->QueryTemperatureStatus(enabled, ccd_temp, air_temp,
					setpointTemp, percentTE);
  return status;
}

int pCam_GetCCDTemperature(double *ccdTemp)
{
  return pCam->GetCCDTemperature(ccdTemp);
}

int pCam_GetStatus(void)
{
  return pCam->GetError();
}

void pCam_GetStatusString(char *text)
{
//  return pCam->GetErrorString();
	text = "Error Not Available";
	return;
}

int pCam_EstablishLink(char *device)
{
  int status;
  SBIG_DEVICE_TYPE dev;

  if (strstr(device,"USB"))
    dev = DEV_USB;
  else if (strstr(device,"LPT0"))
    dev = DEV_LPT1;
  else if (strstr(device,"LPT1"))
    dev = DEV_LPT2;
  else if (strstr(device,"LPT2"))
    dev = DEV_LPT3;
    
  pCam = new CSBIGCam(dev);
  status = pCam->GetError();
  if (status == CE_NO_ERROR)
    status = pCam->EstablishLink();

  return status;
}

int pCam_Unlink(void)
{
  delete pCam;
  pCam = (CSBIGCam *) NULL;
  return CE_NO_ERROR;
}


int pCam_GetCCDInfo(GetCCDInfoParams *parms, void *results)
{
  return pCam->GetCCDInfo(parms, results);
}

int pCam_SetTemperatureRegulation(MY_LOGICAL enable,
					     double setpoint)
{
  return pCam->SetTemperatureRegulation(enable, setpoint);
}

int pCam_StartExposure(StartExposureParams *parms)
{
  if (pCam->CheckLink())
    return pCam->SBIGUnivDrvCommand(CC_START_EXPOSURE, parms, NULL);
  else
    return pCam->GetError();
}

int pCam_QueryCommandStatus(QueryCommandStatusParams *parms,
				       QueryCommandStatusResults *results)
{
  if (pCam->CheckLink())
    return SBIGUnivDrvCommand(CC_QUERY_COMMAND_STATUS, parms, results);
  else
    return pCam->GetError();
}

int pCam_EndExposure(EndExposureParams *parms)
{
  if (pCam->CheckLink())
    return pCam->SBIGUnivDrvCommand(CC_END_EXPOSURE, parms, NULL);
  else
    return pCam->GetError();
}

int pCam_ReadoutLine(ReadoutLineParams *parms,
				unsigned short *results, MY_LOGICAL subtract)
{
  if (pCam->CheckLink())
    return pCam->SBIGUnivDrvCommand(CC_READOUT_LINE, parms, results);
  else 
    return pCam->GetError();
}

int pCam_CFWCommand(CFWParams *cfwp, CFWResults *cfwr)
{
  if (pCam->CheckLink())
    return pCam->CFWCommand(cfwp, cfwr);
  else
    return pCam->GetError();

}
}