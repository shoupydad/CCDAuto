
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "apogee.h"
#include "truefalse.h"

CCameraIO *apCam = (CCameraIO *) NULL;


extern "C" int apCam_EstablishLink(void)
{
  bool success;
  
  apCam = new CCameraIO(); // create camera class object
  if (apCam != NULL) {
    success = apCam->InitDriver(0);   // open device (i.e. /dev/apppi0 )
    if (success) {
      success = apCam->read_Present();  // Check if camera attached & on
    }
  } else {
    success = FALSE;
  }

  return success;
}

extern "C" int apCam_Unlink(void)
{

  delete apCam;
  apCam = NULL;

  return TRUE;
}

extern "C" int apCam_GetCCDTemperature(double *ccd_temp)
{

  *ccd_temp = apCam->read_Temperature();
  return TRUE;

}
