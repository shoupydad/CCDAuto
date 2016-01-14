
//#include <queue.h>
#include "stdafx.h"
#include <sys\stat.h>
#define _CRT_RAND_S

#include <stdlib.h>
#include "defines.h"
#include "Form1.h"
#include "CurrentImageWindow.h"
#include "GuideFrameWindow.h"
#include "ProgressDialog.h"
#include "GuidingProgressDialog.h"
#include "SingleSettingsDialog.h"
#include "SeriesSettingsDialog.h"
#include "DarkFrameSettingsDialog.h"
#include "FlatFrameSettingsDialog.h"
#include "StackSettingsDialog.h"
#include "PickAlignStarDialog.h"
#include "OkayDialog.h"
#include "YesNoDialog.h"
#include "DataPlotWindow.h"
#include "DefineListDialog.h"
#include "PhotometrySettingsDialog.h"
#include "PhotometryPlotWindow.h"
#include "ObjectListDialog.h"
#include "QueryrDialog.h"
#include "AstrometryWindow.h"
#include "InitializeAstrometryDialog.h"
#include "cbw.h"
#include "GuideFrameWindow.h"
#include "AAVSOPhotoDialog.h"
#include "UpdateMX916Keywords.h"

//using namespace CCDAuto;

using namespace System;
using namespace System::Drawing;
using namespace Meade::Imager;

namespace CCDAuto {

/* Support routines */

int MessageBox(char *prompt, int buttons, bool Modal)
{

	switch (buttons) {
		case OKAY:
			if (! OkayDialogExists) {
				gcnew OkayDialog();
			}
			OkayDialog::SetMessage(prompt);
			MessageBoxAnswer = NOANSWER;
			OkayDialog::ShowTheDialog(Modal);
			return MessageBoxAnswer;
			break;
		case YESNO:
			if (! YesNoDialogExists) {
				gcnew YesNoDialog();
			}
			YesNoDialog::SetMessage(prompt);
			MessageBoxAnswer = NOANSWER;
			YesNoDialog::ShowTheDialog(Modal);
			return MessageBoxAnswer;
			break;
	}
	return NOANSWER;
}

void usleep(int usecs)
{
  int msecs;
  msecs =  usecs/1000;
  System::Threading::Thread::Sleep(msecs);
  DoMainEvents();
  return;
}

void stripTrailingBlanks(char *string)
{
  char *cptr;
  int blank=' ';

  do {
    cptr = strrchr(string, blank);  /* find a blank */
    if (cptr == NULL)
      break;
    if (*(cptr+1) != 0)   /* check if its a trailing blank */
      break;
    *cptr = 0;
  } while (true);

  return;
}

bool GetCCDTemperature(CCD *ccd, double *ccd_temp) {
	
	bool success;
	
	switch (ccd->make) {
		case SBIG_MAKE:
			success = (pCam_GetCCDTemperature(ccd_temp) == CE_NO_ERROR);
			break;
		case APOGEE47P_MAKE:
			*ccd_temp = apCam_GetCCDTemperature();
			success = true;
			break;
		case APOGEEU8300_MAKE:
			*ccd_temp = altaCam_GetCCDTemperature();
			success = true;
			break;
		case SXPRESS_MAKE:
			*ccd_temp = 999.0;
			success = true;
			break;
		case MEADE_MAKE:
			*ccd_temp = 999.0;
			success = true;
			break;
		case SSPRO_MAKE:
			*ccd_temp = 999.0;
			success = true;
			break;
	}
	
	return success;
}


bool InitObjectList(char *fileName) {
	
	char Message[120];
	char buffer[160], *bptr;
	int items, nObjects, errStatus;	
	OBJECT obj;
	OBJNODE *optr, *next;
	FILE *OBJfptr;
	
	/* Open object list file */
	
	if (fileName == NULL) {
		sprintf_s(Message, sizeof(Message), "*** Warning - OBJECTLIST environment variable"
			" not set...\n No objects available...\n");
		Form1::StatusPrint(Message);
		return false;
	}
	
	errStatus = fopen_s(&OBJfptr, fileName, "r");
	if (OBJfptr == NULL) {
		sprintf_s(Message, sizeof(Message), "*** Fatal - can't open objects file: %s\n", fileName);
		Form1::StatusPrint(Message);
		return false;
	}
	strcpy_s(objectListFileName, sizeof(objectListFileName), fileName);
	
	/* If object list exists, then free its memory and start again */
	
	optr = ObjectListHead;
	while (optr != NULL) {
		next = optr->next;
		free(optr);
		optr = next;
	}
	ObjectListHead = NULL;
	
	/* Main loop:  read object, add to list */
	
	nObjects=0;
	do {
		fgets(buffer,sizeof(buffer),OBJfptr);
		if (feof(OBJfptr))
			break;
		bptr = buffer;
		strncpy_s(obj.name,sizeof(obj.name),bptr,10);       obj.name[10] = 0;       bptr += 11;
		stripTrailingBlanks(obj.name);
		strncpy_s(obj.objectType,sizeof(obj.objectType),bptr,10); obj.objectType[10] = 0; bptr += 11;
		stripTrailingBlanks(obj.objectType);
		strncpy_s(obj.specType,sizeof(obj.specType),bptr,10);   obj.specType[10] = 0;   bptr += 11;
		stripTrailingBlanks(obj.specType);
		strncpy_s(obj.varType,sizeof(obj.varType),bptr,10);    obj.varType[10] = 0;    bptr += 11;
		stripTrailingBlanks(obj.varType);
		strncpy_s(obj.ra,sizeof(obj.ra),bptr,10);         obj.ra[10] = 0;         bptr += 11;
		strncpy_s(obj.dec,sizeof(obj.dec),bptr,9);         obj.dec[9] = 0;         bptr += 10;
		items = sscanf_s(bptr,"%f %f %f %f %f", &obj.Mags[0],
			&obj.Mags[1], &obj.Mags[2], &obj.Mags[3], &obj.Mags[4]);
		if (items != 5) {
			sprintf_s(Message, sizeof(Message), "*** WARNING - bad format on object %d\n"
				"Object list truncated\n", nObjects+1);
			Form1::StatusPrint(Message);
			fclose(OBJfptr);
			return true;
		}
		if (! AddObject(&obj)) {
			return false;
		}
		nObjects++;
	} while (true);
	fclose(OBJfptr);
	
	sprintf_s(Message, sizeof(Message), "*** INFO - Read in %d objects\n", nObjects);
	Form1::StatusPrint(Message);
	
	return true;
}

bool AddObject(OBJECT *obj)
{
  char Message[160];
  OBJNODE *optr;

  if (ObjectListHead == NULL) {              /* Empty List */
    ObjectListHead = (OBJNODE *) malloc(sizeof(OBJNODE));
    if (ObjectListHead == NULL) {
      sprintf_s(Message, sizeof(Message),"*** Fatal - Can't allocate memory for Object List\n");
      Form1::StatusPrint(Message);
      return false;
    }
    optr = ObjectListHead;
  } else {
    optr = ObjectListHead;
    while (optr->next != NULL)
      optr = optr->next;
    optr->next = (OBJNODE *) malloc(sizeof(OBJNODE));
    optr = optr->next;
  }
  memcpy(&optr->obj, obj, sizeof(OBJECT));
  optr->next = NULL;

  return true;
}

bool DeleteObject(char *objectName) {

	int len;
	char Message[160];
	OBJNODE *optr, *prev;

	if (objectName == NULL) return false;

	/* Check if we have any objects in list */

	if (ObjectListHead == NULL) {
		sprintf_s(Message, sizeof(Message),"*** Warning - no objects in Objects Lists...\n");
		Form1::StatusPrint(Message);
		return false;
	}

	/* Find the requested object and return its info if found */

	optr = ObjectListHead;
	prev = NULL;
	len = strlen(objectName);
	if (len == 0)
		return false;
	while (optr != NULL) {
		if (strncmp(optr->obj.name,objectName, len) == 0)
			break;
		prev = optr;
		optr = optr->next;
	}

	if (optr == NULL)
		return false;
	else {
		if (prev == NULL) {
			ObjectListHead = optr->next;
		} else {
			prev->next = optr->next;
		}
		free(optr);
	}
    return true;
}


bool GetObjectInfo(char *objectName, OBJECT *objectInfo)
{
  int len;
  char Message[120];
  OBJNODE *optr;

  /* Check if we have any objects in list */

  if (ObjectListHead == NULL) {
    sprintf_s(Message, sizeof(Message),"*** Warning - no objects in Objects Lists...\n");
    Form1::StatusPrint(Message);
    return false;
  }

  /* Find the requested object and return its info if found */

  optr = ObjectListHead;
  len = strlen(objectName);
  if (len == 0)
    return false;
  while (optr != NULL) {
    if (strncmp(optr->obj.name,objectName, len) == 0)
      break;
    optr = optr->next;
  }

  if (optr == NULL) {
      return false;
  } else {
	  memcpy_s(objectInfo, sizeof(OBJECT), &optr->obj, sizeof(OBJECT));
    return true;
  }
}

bool SetObjectInfo(char *objectName, OBJECT *objectInfo)
{
  char Message[120];
  bool success;
  OBJNODE *optr;

  /* Check if we have any objects in list */

  if (ObjectListHead == NULL) {
    sprintf_s(Message, sizeof(Message),"Warning - no objects in Objects Lists...\n");
    Form1::StatusPrint(Message);
    return false;
  }

  /* Find the requested object and return pointer to it if found */

  optr = ObjectListHead;
  while (optr != NULL) {
    if (strncmp(optr->obj.name,objectName, 10) == 0)
      break;
    optr = optr->next;
  }

  /* if found, replace it , else add it to the list */

  if (optr != NULL) {
    memcpy_s(&optr->obj, sizeof(OBJECT), objectInfo, sizeof(OBJECT));
    success = true;
  } else {
    success = AddObject(objectInfo);
  }

  return success;
}

void WriteObjectList(void)
{
  char Message[160];
  int errStatus;
  OBJNODE *optr;
  OBJECT *obj;
  FILE *OBJfptr;

  errStatus = fopen_s(&OBJfptr, objectListFileName, "w");
  if (OBJfptr == NULL){
    sprintf_s(Message, sizeof(Message), "\nWarning - Can't write out new object list to file: %s\n",
	    objectListFileName);
    return;
  }

  optr = ObjectListHead;
  while (optr != NULL) {
    obj = &optr->obj;
    fprintf(OBJfptr, "%-10s %-10s %-10s %-10s %-10s %-9s %f %f %f %f %f\n",
	    obj->name, obj->objectType, obj->specType, obj->varType,
	    obj->ra, obj->dec,
	    obj->Mags[0], obj->Mags[1], obj->Mags[2], obj->Mags[3],
	    obj->Mags[4]);
    optr = optr->next;
  }
  fclose(OBJfptr);
  return;
}

void doShowStatus(CCD *ccd, int *status)
{
  MY_LOGICAL enabled;
  char Message[160];
  double ccd_temp, air_temp, setpointTemp, percentTE;

  if (!ccd->Linked) {
    sprintf_s(Message, sizeof(Message), "*** Not linked to ccd...\n");
    Form1::StatusPrint(Message);
    return;
  }

  /* Show current status */

  switch (ccd->make) {
    case SBIG_MAKE:
      *status = pCam_QueryTemperatureStatus(&enabled, &ccd_temp, &air_temp,
					    &setpointTemp, &percentTE);
      if (*status != CE_NO_ERROR) {
	    Form1::StatusPrint("*** WARNING - Can't get ccd temperature, "
		      "aborting exposure...\n");
	    return;
      }
      sprintf_s(Message, sizeof(Message), "ccd temp: %f --  air temp: %f\n",
	      ccd_temp, air_temp);
      Form1::StatusPrint(Message);
      sprintf_s(Message, sizeof(Message), "cooling power: %d %%\n", ((int) (percentTE*100.0)));
      Form1::StatusPrint(Message);
      sprintf_s(Message, sizeof(Message), "Filter Position: %d\n", ccd->filterPosition);
      Form1::StatusPrint(Message);
      break; 
    case APOGEE47P_MAKE:
      ccd_temp = apCam_GetCCDTemperature();
      sprintf_s(Message, sizeof(Message), "ccd temp: %f\n", ccd_temp);
      Form1::StatusPrint(Message);
      break;
    case APOGEEU8300_MAKE:
      ccd_temp = altaCam_GetCCDTemperature();
      sprintf_s(Message, sizeof(Message), "ccd temp: %f\n", ccd_temp);
      Form1::StatusPrint(Message);
      break;
    case SXPRESS_MAKE:
      break;
	case SSPRO_MAKE:
	  ccd_temp = ssCam_GetCCDTemperature();
      sprintf_s(Message, sizeof(Message), "ccd temp: %f\n", ccd_temp);
      Form1::StatusPrint(Message);
      break;

  }

  return;
}

void doFilterWheel(CCD *ccd, int *status, int Position)
{
  char Message[120];
  int itry;
  CFWParams cfwp;
  CFWResults cfwr;
  bool success;

  switch (ccd->make) {
  case SBIG_MAKE:
	if (!ccd->Linked) {
		sprintf_s(Message, sizeof(Message),
			"\n*** WARNING - Can't change filter. Not linked to ccd...\n");
		Form1::StatusPrint(Message);
		return;
	}
    cfwp.cfwModel = CFWSEL_CFW8;
    cfwp.cfwCommand = CFWC_QUERY;
    *status = pCam_CFWCommand(&cfwp, &cfwr);
    cfwp.cfwCommand = CFWC_GOTO;
    cfwp.cfwParam1 = Position;
    *status = pCam_CFWCommand(&cfwp, &cfwr);
    itry = 0;
    while (itry++ < 5) {
      cfwp.cfwCommand = CFWC_QUERY;
      *status = pCam_CFWCommand(&cfwp, &cfwr);
      if ((*status == CE_NO_ERROR) && (cfwr.cfwStatus == CFWS_IDLE)) {
	break;
      } else if (itry >= 5) {
	sprintf_s(Message, sizeof(Message),"*** WARNING - Error changing filter...\n");
	Form1::StatusPrint(Message);
	return;
      }
      RunMainIteration(1.0);
    }
    ccd->filterPosition = Position;
    sprintf_s(Message, sizeof(Message),"Now using filter: %c\n", filterSet[Position-1]);
    Form1::StatusPrint(Message);
//    updateStatusInfo();
    break;
  case APOGEE47P_MAKE:
  case APOGEEU8300_MAKE:
  case SXPRESS_MAKE:
  case CANON_MAKE:
  case SSPRO_MAKE:
  case SSAG_MAKE:
    success = SetOrionFWPosition(Position);
//    success = SetCFW6APosition(Position);
	if (! success) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Unable to set filter wheel position to: %c.\n",
			filterSet[Position-1]);
		Form1::StatusPrint(Message);
	} else {
		sprintf_s(Message, sizeof(Message),"*** Info - Now using filter: %c\n", filterSet[Position-1]);
		Form1::StatusPrint(Message);
		ccd->filterPosition = Position;
	}
    break;
  }
}




void writeFITS(IMAGE *Image, int WhichFrame, char *FileName, char *objectName)
{
  char buffer[160];
  int status, success;
  unsigned int epoch;
  int bitpix = USHORT_IMG, hours, mins, secs, degs;
  long nelements, fpixel, naxis, naxes[2];
  float ccdgain, readnoise, AirMass;
  double JD, HJD;
  struct tm broken_time;
  OBJECT objectInfo;
  FRAME *frame;
//  errno_t errno;

  fitsfile *fptr;

  if (WhichFrame == 1) {
    frame = &Image->light_frame;
  } else {
    frame = &Image->dark_frame;
  }
  if (!frame->active) {
    printf("\nCan't save image, it isn't active...\n");
    return;
  }

  /* Create the FITS file */

  status = 0;
  if (fits_create_file(&fptr, FileName, &status)) {
	  ShowFitsError();
	  strcpy_s(Image->FileName, sizeof(Image->FileName), "FITS error");
	  return;
  }

  /* Create the image */

  naxis = 2;
  naxes[0] = frame->w;
  naxes[1] = frame->h;
  status = 0;
  if (fits_create_img(fptr, bitpix, naxis, naxes, &status)) {
	  ShowFitsError();
	  strcpy_s(Image->FileName, sizeof(Image->FileName), "FITS error");
	  fits_close_file(fptr, &status);
	  return;
  }

  /* Write out the image */

  fpixel = 1;
  nelements = frame->w*frame->h;
  if (fits_write_img(fptr, TUSHORT, fpixel, nelements, frame->frame, &status)) {
	  ShowFitsError();
	  strcpy_s(Image->FileName, sizeof(Image->FileName), "FITS error");
	  fits_close_file(fptr, &status);
	  return;
  }

  /* Update "general" keywords */

  ccdgain = ((float) ccd->gain);
  readnoise = ((float) ccd->readNoise);
  fits_update_key(fptr, TFLOAT, "GAIN", &ccdgain,
		 "CCD gain (e-/adu)", &status);
  fits_update_key(fptr, TFLOAT, "RDNOISE", &readnoise,
		 "CCD readnoise (e-)", &status);
  fits_update_key(fptr, TSTRING, "OBSERVAT", &ObsSettings.name,
		 "Observatory site", &status);
  fits_update_key(fptr, TSTRING, "FILTER", &Image->Filter,
		 "Filter wheel setting", &status);
  fits_update_key(fptr, TSTRING, "OBSERVER", &ObsSettings.Observer,
		 "Name of Observer", &status);
  fits_update_key(fptr, TSTRING, "PROJECT", &ObsSettings.Project,
		 "Project Name", &status);
  if (strlen(frame->UT) == 0) {
    _gmtime64_s(&broken_time, &frame->time);
	strftime(buffer,sizeof(buffer),"%H:%M:%S",&broken_time);
	strcpy_s(frame->UT, sizeof(frame->UT), buffer);
  } else {
    strcpy_s(buffer, sizeof(buffer), frame->UT);
  }
  fits_update_key(fptr, TSTRING, "UT", buffer,
		 "Observation start universal time", &status);
  if (strlen(frame->UTDATE) == 0) {
    strftime(buffer,sizeof(buffer),"%Y-%m-%d", &broken_time);
	strcpy_s(frame->UTDATE, sizeof(frame->UTDATE), buffer);
  } else {
    strcpy_s(buffer, sizeof(buffer), frame->UTDATE);
  }
  fits_update_key(fptr, TSTRING, "DATE-OBS", buffer,
		 "Observation start universal date", &status);
  fits_update_key(fptr, TFLOAT, "EXPOSURE", &frame->exposure,
		 "Exposure time in seconds", &status);
  fits_update_key(fptr, TFLOAT, "CCDTEMP", &frame->temp,
		 "CCD temperature in C", &status);
  fits_update_key(fptr, TINT, "BINNING", &frame->binning,
		 "CCD binning 1x1,2x2,3x3", &status);
  fits_update_key(fptr, TINT, "WHICHCCD", &frame->whichCCD,
		  "0=Imaging, 1=Tracking", &status);
  fits_update_key(fptr, TINT, "STARTX", &frame->x,
		  "Starting x pixel", &status);
  fits_update_key(fptr, TINT, "STARTY", &frame->y,
		  "Starting y pixel", &status);

  /* Update Object related keywords */

	/* Get info on this object (RA, DEC, etc) */
      
  success = GetObjectInfo(objectName, &objectInfo);
  if (! success) {
    sprintf_s(buffer, sizeof(buffer), "*** Warning - Can't find info on %s, using scope position...\n",
	   objectName);
    Form1::StatusPrint(buffer);
	strcpy_s(objectInfo.name, sizeof(objectInfo.name), "unknown");
    hours = (int) ScopeRA;
    mins  = (int) ((ScopeRA - hours)*60.0);
    secs  = (int) ((ScopeRA - hours - mins/60.0)*3600.0);
    sprintf_s(objectInfo.ra, sizeof(objectInfo.ra), "%02d:%02d:%02d", hours, mins, secs);
    degs = (int) ScopeDEC;
    mins = (int) ((ScopeDEC - degs)*60.0);
    secs = (int) ((ScopeDEC - degs - mins/60.0)*3600.0);
    sprintf_s(objectInfo.dec, sizeof(objectInfo.dec), "%3d:%02d:%02d", degs, mins, secs);
  }
  status = 0;
  fits_update_key(fptr, TSTRING, "OBJECT", objectInfo.name,
		  "Program object", &status);
  fits_update_key(fptr, TSTRING, "RA", objectInfo.ra,
		  "Program object RA", &status);
  fits_update_key(fptr, TSTRING, "DEC", objectInfo.dec,
		  "Program object DEC", &status);
  epoch = EPOCH;
  fits_update_key(fptr, TUINT, "EPOCH", &epoch,
		  "Epoch for coordinates", &status);

    /* Compute airmass & heliocentric JD */

  CalcObsParms(&AirMass, &JD, &HJD, &objectInfo, &ObsSettings,
	       frame->UT, frame->UTDATE, frame->exposure);
  fits_update_key(fptr, TDOUBLE, "JD", &JD,
		  "Julian Date at mid-exposure", &status);
  fits_update_key(fptr, TDOUBLE, "HJD", &HJD,
		  "Heliocentric Julian Date at mid-exposure", &status);
  fits_update_key(fptr, TFLOAT, "AIRMASS", &AirMass,
		  "AirMass", &status);

  /* Update plate solution related keywords (astrometry) */

  if (Image->plateSolution.status == 0) { // valid solution
	  fits_update_key(fptr, TDOUBLE, "PLATERA", &Image->plateSolution.FieldCenterRA,
		  "Plate Solution Field Center RA", &status);
	  fits_update_key(fptr, TDOUBLE, "PLATEDEC", &Image->plateSolution.FieldCenterDEC,
		  "Plate Solution Field Center DEC", &status);
	  fits_update_key(fptr, TDOUBLE, "PLATEA", &Image->plateSolution.coeffs[0],
		  "Plate Solution Parm A", &status);
	  fits_update_key(fptr, TDOUBLE, "PLATEB", &Image->plateSolution.coeffs[1],
		  "Plate Solution Parm B", &status);
	  fits_update_key(fptr, TDOUBLE, "PLATEC", &Image->plateSolution.coeffs[2],
		  "Plate Solution Parm C", &status);
	  fits_update_key(fptr, TDOUBLE, "PLATED", &Image->plateSolution.coeffs[3],
		  "Plate Solution Parm D", &status);
	  fits_update_key(fptr, TDOUBLE, "PLATEE", &Image->plateSolution.coeffs[4],
		  "Plate Solution Parm E", &status);
	  fits_update_key(fptr, TDOUBLE, "PLATEF", &Image->plateSolution.coeffs[5],
		  "Plate Solution Parm F", &status);
  }

  /* Close the FITS file */

  status = 0;
  if (fits_close_file(fptr, &status)) {
	  ShowFitsError();
	  strcpy_s(Image->FileName, sizeof(Image->FileName), "FITS error");
	  return;
  }

  strcpy_s(Image->FileName,sizeof(Image->FileName),FileName);
  Image->saved = true;

  return;
}

void doUnlinkToCamera(CCD *ccd, int *status)
{
  doSetTempOffCamera(ccd);
  ccd->Linked = false;
//  updateStatusInfo();
  return;
}

bool Queryr(char *prompt, float *answer) {

	bool okay;

	if (! QueryrDialogExists)
		gcnew QueryrDialog();

	okay = QueryrDialog::FormPtr->ShowTheDialog(prompt, answer);
	return okay;

}


bool doSetTempOnCamera(CCD *ccd, double f)
{
  char Message[160];
  bool Success;
  int status;

  if (!ccd->Linked) {
    sprintf_s(Message, sizeof(Message), "*** Can't turn regulation on, link to ccd first\n");
    Form1::StatusPrint(Message);
    return false;
  }

  switch (ccd->make) {
    case SBIG_MAKE:
      status = pCam_SetTemperatureRegulation(true, f);
	  if (status != CE_NO_ERROR) {
		  Form1::StatusPrint("*** WARNING - Can't set temperature regulation...\n");
	      Success = false;
	  } else {
		  sprintf_s(Message, sizeof(Message),"*** Info - Setting cooling to: %5.1f\n", f);
		  Form1::StatusPrint(Message);
		  Success = true;
	  }
      break;
    case APOGEE47P_MAKE:
      apCam_SetTemperatureRegulation(true,f);
	  sprintf_s(Message, sizeof(Message),"*** Info - Setting cooling to: %5.1f\n", f);
	  Form1::StatusPrint(Message);
	  Success = true;
      break;
    case APOGEEU8300_MAKE:
      altaCam_SetTemperatureRegulation(true,f);
	  sprintf_s(Message, sizeof(Message),"*** Info - Setting cooling to: %5.1f\n", f);
	  Form1::StatusPrint(Message);
	  Success = true;
      break;
    case SXPRESS_MAKE:
      Form1::StatusPrint("*** WARNING - Can't set temperature regulation on Starlight Xpress cameras\n");
	  Success = false;
      break;
    case MEADE_MAKE:
      Form1::StatusPrint("*** WARNING - Can't set temperature regulation on Meade LPI cameras\n");
	  Success = false;
      break;
    case SSPRO_MAKE:
      Form1::StatusPrint("*** WARNING - Can't set temperature regulation on StarShootPro cameras\n");
	  Success = false;
      break;
    case SSAG_MAKE:
      Form1::StatusPrint("*** WARNING - Can't set temperature regulation on StarShoot Autoguider cameras\n");
	  Success = false;
      break;
  }

  return Success;
}

void doSetTempOffCamera(CCD *ccd)
{
  char Message[160];
  int status;

  if (!ccd->Linked) {
    sprintf_s(Message, sizeof(Message), "*** WARNING - Can't turn regulation off, link to ccd first\n");
    Form1::StatusPrint(Message);
    return;
  }

  switch (ccd->make) {
    case SBIG_MAKE:
      status = pCam_SetTemperatureRegulation(false, 0.0);
      if (status != CE_NO_ERROR) {
		  Form1::StatusPrint("*** WARNING - Can't turn off temperature regulation...\n");
		  return;
      }
      break;
    case APOGEE47P_MAKE:
      apCam_SetTemperatureRegulation(false,0);
      break;
    case APOGEEU8300_MAKE:
      altaCam_SetTemperatureRegulation(false,0);
      break;
    case SXPRESS_MAKE:
      Form1::StatusPrint("*** WARNING - Can't set temperature regulation on Starlight Xpress cameras\n");
      break;
	case MEADE_MAKE:
	  Form1::StatusPrint("*** WARNING - Can't set temperature regulation on Meade LPI\n");
	  break;
	case SSPRO_MAKE:
	  Form1::StatusPrint("*** WARNING - Can't set temperature regulation on StarShoot Pro cameras\n");
	  break;
	case SSAG_MAKE:
	  Form1::StatusPrint("*** WARNING - Can't set temperature regulation on StarShoot Autoguider cameras\n");
	  break;
  }

  return;
}


void print_stats(unsigned short *b, int w, int h)
{
  char Message[120];

  int	 min = 65536, max = -1;
  int  i_min = 0, i_max = 0, i;
  
  for (i = w*h; --i >= 0; ) {
    if ((int)b[i] < min) {
      i_min = i;
      min = b[i];
    }
    if ((int)b[i] > max) {
      i_max = i;
      max = b[i];
    }
  }
  sprintf_s(Message, sizeof(Message),"min=%d at (%d,%d)\n", min, i_min%w, i_min/w);
  Form1::StatusPrint(Message);
  sprintf_s(Message, sizeof(Message),"max=%d at (%d,%d)\n", max, i_max%w, i_max/w);
  Form1::StatusPrint(Message);
}

void loadImageImaging(unsigned short *sp, int x, int y, int w, int h, int binning)
{
  char buffer[80];
  double  f, sum, ave;
  float gamma;
  int  d, i, j, min, max, npixels, iave, fullh, fullw;
  Color pixel;

    fullw = ccd->Image.light_frame.w;
    fullh = ccd->Image.light_frame.h;
    npixels = fullw * fullh;

  if (! CurrentImageWindowExists) {
	  gcnew CurrentImageWindow();
	  CurrentImageWindow::FormPtr->CurrentImageBitmap =
		  (gcnew System::Drawing::Bitmap(fullw,fullh));
	  CurrentImageWindow::FormPtr->CurrentImagePictureBox->Image =
		  CurrentImageWindow::FormPtr->CurrentImageBitmap;
  } else {
	  if ((CurrentImageWindow::FormPtr->CurrentImageBitmap->Width != fullw) ||
		  (CurrentImageWindow::FormPtr->CurrentImageBitmap->Height != fullh)) {  // Size changed, redo bitmap
		  delete CurrentImageWindow::FormPtr->CurrentImageBitmap;
		  CurrentImageWindow::FormPtr->CurrentImageBitmap =
			  (gcnew System::Drawing::Bitmap(fullw,fullh));
		  CurrentImageWindow::FormPtr->CurrentImagePictureBox->Image =
			  CurrentImageWindow::FormPtr->CurrentImageBitmap;
	  }
  }
  CurrentImageWindow::FormPtr->CurrentImagePictureBox->Height = fullh;
  CurrentImageWindow::FormPtr->CurrentImagePictureBox->Width = fullw;
  CurrentImageWindow::FormPtr->FlipImageIfRequested();

  /* get min and max */

  min = 65535;
  max = 0;
  sum = 0.0;
  for (i=w*h; --i >= 0; ) {
    if (sp[i] > max)
      max = sp[i];
    else if (sp[i] < min)
      min = sp[i];
    sum += sp[i];
  }
  ave = sum/npixels;
  iave = ((int) ave);

  /* Set display parameters */

  sprintf_s(buffer, sizeof(buffer), "%d", iave);
  CCDAuto::CurrentImageWindow::SetCurrentImageBgndTextBox(buffer);

  sprintf_s(buffer, sizeof(buffer), "%d", max);
  CCDAuto::CurrentImageWindow::SetCurrentImageRangeTextBox(buffer);

  gamma = ((float) 0.33);
  sprintf_s(buffer, sizeof(buffer), "%f", gamma);
  CCDAuto::CurrentImageWindow::SetCurrentImageGammaTextBox(buffer);

  /* Set the image values */

  sprintf_s(buffer, sizeof(buffer), "%d", min);
  CCDAuto::CurrentImageWindow::SetCurrentImageMinPixTextBox(buffer);
  sprintf_s(buffer, sizeof(buffer),"%d", max);
  CCDAuto::CurrentImageWindow::SetCurrentImageMaxPixTextBox(buffer);
  sprintf_s(buffer, sizeof(buffer),"%7.1f", ave);
  CCDAuto::CurrentImageWindow::SetCurrentImageAvePixTextBox(buffer);

  min = iave;
  if (max == min)
    min = max - 1;
  //for (j = 0; j < fullh; ++j) {
  for (j = fullh-1; j >= 0; --j) {  // Reversed so that (0,0) origin in lower left instead of upper left ALS 04-03-09
    for (i = 0; i < fullw; ++i) {
      //      if ((j >= y) && (j < y+h) && (i >= x) && (i < x+w)) {
	f = ((double)*sp++ - min)/(max - min);
	if (f < 0.0) f=0.0;
	d = (int)(255.0*pow(f, 0.33));	/* gamma correct */
	if (d < 0) {
	  d = 0;
	} else if (d > 255) {
	  d = 255;
	}
	//if (*(sp-1) == 65000) {
	//	pixel = Color::FromArgb(255,0,0);
	//} else {
	pixel = Color::FromArgb(d,d,d);
	//}
	CurrentImageWindow::FormPtr->CurrentImageBitmap->SetPixel(i,j,pixel);
  }
}

  CurrentImageWindow::ClearMarkedStarList();
  CurrentImageWindow::ShowThisDialog();
}

void loadImageAstrometry(unsigned short *sp, int x, int y, int w, int h, int binning) {

//	char buffer[80];
	double  f, sum, ave;
//	float gamma;
	int  d, i, j, min, max, npixels, iave, fullh, fullw;
	Color pixel;
	
    fullw = ccd->Image.light_frame.w;
    fullh = ccd->Image.light_frame.h;
    npixels = fullw * fullh;

	if (! AstrometryWindowExists) {
		gcnew AstrometryWindow();
		AstrometryWindow::FormPtr->ImageBitmap =
			(gcnew System::Drawing::Bitmap(fullw,fullh));
		AstrometryWindow::FormPtr->ImagePictureBox->Image =
			AstrometryWindow::FormPtr->ImageBitmap;
		AstrometryWindow::FormPtr->imagePtr = &ccd->Image;
	} else {
		if ((AstrometryWindow::FormPtr->ImageBitmap->Width != fullw) ||
			(AstrometryWindow::FormPtr->ImageBitmap->Height != fullh)) {  // Size changed, redo bitmap
				delete AstrometryWindow::FormPtr->ImageBitmap;
				AstrometryWindow::FormPtr->ImageBitmap =
					(gcnew System::Drawing::Bitmap(fullw,fullh));
				AstrometryWindow::FormPtr->ImagePictureBox->Image =
					AstrometryWindow::FormPtr->ImageBitmap;
		}
	}
	AstrometryWindow::FormPtr->ImagePictureBox->Height = fullh;
	AstrometryWindow::FormPtr->ImagePictureBox->Width = fullw;
	
	/* get min and max */
	
	min = 65535;
	max = 0;
	sum = 0.0;
	for (i=w*h; --i >= 0; ) {
		if (sp[i] > max)
			max = sp[i];
		else if (sp[i] < min)
			min = sp[i];
		sum += sp[i];
	}
	ave = sum/npixels;
	iave = ((int) ave);
	min = iave;
	if (max == min)
		min = max - 1;
	//for (j = 0; j < fullh; ++j) {
	for (j = fullh-1; j >= 0; --j) {  // Reversed so that (0,0) origin in lower left instead of upper left ALS 04-03-09
		for (i = 0; i < fullw; ++i) {
			//      if ((j >= y) && (j < y+h) && (i >= x) && (i < x+w)) {
			f = ((double)*sp++ - min)/(max - min);
			if (f < 0.0) f=0.0;
			d = (int)(255.0*pow(f, 0.33));	/* gamma correct */
			if (d < 0) {
				d = 0;
			} else if (d > 255) {
				d = 255;
			}
			//if (*(sp-1) == 65000) {
			//	pixel = Color::FromArgb(255,0,0);
			//} else {
				pixel = Color::FromArgb(d,d,d);
			//}
			AstrometryWindow::FormPtr->ImageBitmap->SetPixel(i,j,pixel);
		}
	}
	
	AstrometryWindow::ClearMarkedStarList();
	AstrometryWindow::FormPtr->ShowTheWindow();
}

void loadImageTracking(unsigned short *sp, int x, int y, int w, int h, int binning)
{
  char buffer[80];
  double  f, sum, ave;
  float gamma;
  int  d, i, j, min, max, npixels, iave, fullh, fullw;
  Color pixel;
  static bool First=true;


   fullw = TrackingCCD.Image.light_frame.w;
   fullh = TrackingCCD.Image.light_frame.h;
   npixels = fullw * fullh;

  if (! GuideFrameWindowExists) {
	  gcnew GuideFrameWindow();
  }
  if (First) {
	  GuideFrameWindow::FormPtr->Bitmap = (gcnew System::Drawing::Bitmap(fullw,fullh));
	  GuideFrameWindow::FormPtr->PictureBox->Image = GuideFrameWindow::FormPtr->Bitmap;
	  First = false;
  }
  GuideFrameWindow::FormPtr->PictureBox->Height = fullh;
  GuideFrameWindow::FormPtr->PictureBox->Width = fullw;

  /* get min and max */

  min = 65535;
  max = 0;
  sum = 0.0;
  for (i=w*h; --i >= 0; ) {
    if (sp[i] > max)
      max = sp[i];
    else if (sp[i] < min)
      min = sp[i];
    sum += sp[i];
  }
  ave = sum/npixels;
  iave = ((int) ave);

  /* Set display parameters */

  sprintf_s(buffer, sizeof(buffer), "%d", iave);
  GuideFrameWindow::SetBgndTextBox(buffer);

  sprintf_s(buffer, sizeof(buffer), "%d", max);
  GuideFrameWindow::SetRangeTextBox(buffer);

  gamma = ((float) 0.33);
  sprintf_s(buffer, sizeof(buffer), "%f", gamma);
  GuideFrameWindow::SetGammaTextBox(buffer);

  /* Set the image values */

  sprintf_s(buffer, sizeof(buffer), "%d", min);
  GuideFrameWindow::SetMinPixTextBox(buffer);
  sprintf_s(buffer, sizeof(buffer),"%d", max);
  GuideFrameWindow::SetMaxPixTextBox(buffer);
  sprintf_s(buffer, sizeof(buffer),"%7.1f", ave);
  GuideFrameWindow::SetAvePixTextBox(buffer);

  min = iave;
  if (max == min)
    min = max - 1;
  for (j = 0; j < fullh; ++j) {
    for (i = 0; i < fullw; ++i) {
      //      if ((j >= y) && (j < y+h) && (i >= x) && (i < x+w)) {
	f = ((double)*sp++ - min)/(max - min);
	if (f < 0.0) f=0.0;
	d = (int)(255.0*pow(f, 0.33));	/* gamma correct */
	if (d < 0) {
	  d = 0;
	} else if (d > 255) {
	  d = 255;
	}
	//if (*(sp-1) == 65000) {
	//	pixel = Color::FromArgb(255,0,0);
	//} else {
		pixel = Color::FromArgb(d,d,d);
	//}
	GuideFrameWindow::FormPtr->Bitmap->SetPixel(i,j,pixel);
    }
  }

  GuideFrameWindow::FormPtr->RefreshImage();

}

bool StartExposure(CCD *ccd, StartExposureParams *expose, StartReadoutParams *readout) {
	
	int ret;
	bool success;
	
	ret = success = false;
	switch (ccd->make) {
		case SBIG_MAKE:
			ret = pCam_StartExposure(expose);
			success = (ret == CE_NO_ERROR);
			break;
		case APOGEE47P_MAKE:
			success = apCam_StartExposure(expose);
			break;
		case APOGEEU8300_MAKE:
			success = altaCam_StartExposure(expose, readout);
			break;
		case SXPRESS_MAKE:
			ret = spCam_StartExposure(ccd, expose, readout);
			success = (ret == 1);
			break;
		case MEADE_MAKE:
			success = LPI_StartExposure(expose);
			break;
		case SSPRO_MAKE:
			success = ssCam_StartExposure(expose, readout);
			break;
	}
	
	return success;
}

bool QueryCCDExposureStatus(CCD *ccd, StartExposureParams *expose) {

	int status, err;
	bool done;
	QueryCommandStatusParams  query_command_status_params;
	QueryCommandStatusResults  query_command_status_results;
	
	done = false;
	switch (ccd->make) {
		case SBIG_MAKE:
			query_command_status_params.command = CC_START_EXPOSURE;
			err = pCam_QueryCommandStatus(&query_command_status_params,
				&query_command_status_results);
			if (expose->ccd == 0)
				status = query_command_status_results.status & 3;
			else
				status = (query_command_status_results.status >> 2) & 3;
			done = (status == CS_INTEGRATION_COMPLETE);
			break;
		case APOGEE47P_MAKE:
			status = apCam_ReadStatus();
			done = (status == APOGEE_STATUS_IMAGEREADY);
			break;
		case APOGEEU8300_MAKE:
			status = altaCam_ReadStatus();
			done = (status == ALTA_STATUS_IMAGEREADY);
			break;
		case SXPRESS_MAKE:
//			done = spCam_ReadStatus(&TimerValue);
//			done = (TimerValue <= 100);
			done = true;
			break;
		case MEADE_MAKE:
			status = LPI_GetStatus();
			done = (status == (int) Meade::Imager::AImager::ImagerStatusType::Idle);
			break;
		case SSPRO_MAKE:
			done = ssCam_ImageReady();
			break;
		case SSAG_MAKE:
			done = false;
			break;
	}
	
	return done;
}

void EndCCDExposure(CCD *ccd, StartExposureParams *expose, bool Digitize) {

	EndExposureParams  end_exposure_params;
	
	switch (ccd->make) {
		case SBIG_MAKE:
			end_exposure_params.ccd = expose->ccd;
			pCam_EndExposure(&end_exposure_params);
			break;
		case APOGEE47P_MAKE:
			break;
		case APOGEEU8300_MAKE:
			altaCam_StopExposure(Digitize);
			break;
		case SXPRESS_MAKE:
			break;
		case MEADE_MAKE:
			break;
		case SSPRO_MAKE:
			break;
		case SSAG_MAKE:
			break;
	}
	
	return;
}


static void sxDataReady(void *data, int fd, void *in)
{
	CCDAuto::dataIsReady = true;
  return;
}

bool GetImage(CCD *ccd, StartReadoutParams *readout, int Light, unsigned short *image_data) {

	char Message[120];
	short xbinning, ybinning;
	int i, status, percent, nBytesToRead;
	bool success;
	ReadoutLineParams  readout_line_params;
	
	switch (ccd->make) {
		case SBIG_MAKE:
			if (Light) {
				ShowImageProgress("Downloading - Light Frame", 0);
			} else {
				ShowImageProgress("Downloading - Dark Frame", 0);
			}
			for (i=0; i<readout->height; i++) {
				readout_line_params.ccd = readout->ccd;
				readout_line_params.readoutMode = readout->readoutMode;
				readout_line_params.pixelStart = readout->left;
				readout_line_params.pixelLength = readout->width;
				status = pCam_ReadoutLine(&readout_line_params, 
					image_data+i*readout->width, 0);
				if (status != CE_NO_ERROR) {
					sprintf_s(Message, sizeof(Message),
						"*** WARNING - Error reading out image line: %d\n",i);
					ShowImageProgress(NULL, 0);
					return false;
				}
				percent = (int) (100.0 * ((float)  i) / readout->height);
				if (Light) {
					ShowImageProgress("Downloading - Light Frame", percent);
					sprintf_s(Message, sizeof(Message),"load: %d%%", percent);
				} else {
					ShowImageProgress("Downloading - Dark Frame", percent);
					sprintf_s(Message, sizeof(Message),"load: %d%%", percent);
				}
				Form1::SetCCDStatusTextBox(Message);
				//	RunMainIteration(0.01);
				if (CancelCurrentAcquire) {
					Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
					ShowImageProgress(NULL, 0);
					return false;
				}
			}
			ShowImageProgress(NULL, 0);
			return true;
			break;
		case APOGEE47P_MAKE:
			xbinning = ybinning = readout->readoutMode + 1;
			if (Light) {
				// ShowImageProgress("Downloading - Light Frame", 0);
				Form1::SetCCDStatusTextBox("Reading-Light");
			} else {
				// ShowImageProgress("Downloading - Dark Frame", 0);
				Form1::SetCCDStatusTextBox("Reading-Dark");
			}
			RunMainIteration(0.5);
			success = apCam_GetImage(image_data, readout->left, readout->top,
				readout->width, readout->height, xbinning, ybinning);
			if (! success) {
				sprintf_s(Message, sizeof(Message), "*** WARNING - Error reading out image\n");
				return false;
			}
			return success;
			break;
		case APOGEEU8300_MAKE:
			xbinning = ybinning = readout->readoutMode + 1;
			if (Light) {
				// ShowImageProgress("Downloading - Light Frame", 0);
				Form1::SetCCDStatusTextBox("Reading-Light");
			} else {
				// ShowImageProgress("Downloading - Dark Frame", 0);
				Form1::SetCCDStatusTextBox("Reading-Dark");
			}
			RunMainIteration(0.5);
			success = altaCam_GetImage(image_data, readout->left, readout->top,
				readout->width, readout->height, xbinning, ybinning);
			if (! success) {
				sprintf_s(Message, sizeof(Message), "*** WARNING - Error reading out image\n");
				return false;
			}
			return success;
			break;
		case SXPRESS_MAKE:
			xbinning = ybinning = readout->readoutMode + 1;
			if (Light) {
				// ShowImageProgress("Downloading - Light Frame", 0);
				Form1::SetCCDStatusTextBox("Reading-Light");
			} else {
				// ShowImageProgress("Downloading - Dark Frame", 0);
				Form1::SetCCDStatusTextBox("Reading-Dark");
			}
			RunMainIteration(0.5);
			if (ccd->mx_sxv_info.dac_bits > 8) {
				nBytesToRead = 2;
			} else {
				nBytesToRead = 1;
			}
			nBytesToRead *= (readout->width-readout->left)*(readout->height-readout->top);
			success = spCam_GetImage(readout, image_data, nBytesToRead);
			if (! success) {
				sprintf_s(Message, sizeof(Message), "*** WARNING - Error reading out image\n");
				return false;
			}
			return success;

			ShowImageProgress(NULL, 0);
			return true;
			break;
		case MEADE_MAKE:
			Form1::SetCCDStatusTextBox("Reading LPI");
			success = LPI_GetImage(image_data);
			return success;
			break;
		case SSPRO_MAKE:
			if (Light)
				Form1::SetCCDStatusTextBox("Reading-Light");
			else
				Form1::SetCCDStatusTextBox("Reading-Dark");
			success = ssCam_GetImage(image_data);
			return success;
			break;
	}
	
	return true;

}


 /*
  * This is the 'progress' callback
  * passed to sbig_readout()
  */

bool snapImaging(CCD *ccd, StartExposureParams *expose, StartReadoutParams *readout, IMAGE *Image) {

	bool success, done;
	unsigned int i;
	unsigned short *image_data;
	char Message[120];
	double ccd_temp;
	bool ShowedImageProgress=false;
	
	if (expose->exposureTime <= 0) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Invalid exposure time: %d in snapImaging,\n"
			"              no exposure taken.\n", expose->exposureTime);
		Form1::StatusPrint(Message);
		return false;
	}
	
	ImageInProgress = true;
	
	/*
	* take a dark if needed
	*/
	
	DontUpdate = true;
	
	/* Get current temp of dark frame */
	
	if (! Image->lightOnly) {
		success = GetCCDTemperature(ccd, &ccd_temp);
		if (! success) {
			Form1::StatusPrint("*** WARNING - Can't get ccd temperature, "
				"aborting exposure...\n");
			ImageInProgress = false;
			return false;
		}
		Image->dark_frame.temp = ((float) ccd_temp);

		Form1::SetCCDStatusTextBox("Exposing Dark");
		sprintf_s(Message, sizeof(Message),"Starting %f sec. dark frame...\n",
			expose->exposureTime/100.0);
		Form1::StatusPrint(Message);
		usleep(500000);
		
		expose->openShutter = 2;
		time(&Image->dark_frame.time);
		ImagingShutterClosed = true;
		success = StartExposure(ccd, expose, readout);
		if (! success) {
			Form1::StatusPrint("*** WARNING - Error starting dark frame...\n");
			ImageInProgress = false;
			DontUpdate = false;
			return false;
		}
		
		/* Wait to start waiting */
		
		ShowedImageProgress = false;
		if (expose->exposureTime > 100) {
			ShowImageProgress("Exposing - Dark Frame", 0);
			ShowedImageProgress = true;
			for (i = 0; i < expose->exposureTime; i += 100) {
				ShowImageProgress("Exposing - Dark Frame", (int) (100.0*i/expose->exposureTime));
				sprintf_s(Message, sizeof(Message),"Expose: %4.1f%%", 100.0*i/expose->exposureTime);
				Form1::SetCCDStatusTextBox(Message);
				usleep(1000000);
				if (CancelCurrentAcquire) {
					Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
					ShowImageProgress(NULL, 0);
					EndCCDExposure(ccd, expose, false);  // dont digitize
					ImageInProgress = false;
					DontUpdate = false;
					return false;
				}
			}
		} else
			usleep(expose->exposureTime*10000);
		
		/* wait for exposure to complete */
		
		for (i = 0; i < 1000; ++i) {
			done = QueryCCDExposureStatus(ccd, expose);
			if (done) {
				EndCCDExposure(ccd, expose, true);  // digitize
				break;
			}
			usleep(50000);
			if (CancelCurrentAcquire) {
				Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
				if (ShowedImageProgress)
					ShowImageProgress(NULL, 0);
				EndCCDExposure(ccd, expose, false);  // dont digitize
				ImageInProgress = false;
				DontUpdate = false;
				return false;
			}
		}
		if (i == 1000) {
			Form1::StatusPrint("*** WARNING - Dark exposure didn't finish...\n");
			ImageInProgress = false;
			DontUpdate = false;
			return false;
		}
		if (ShowedImageProgress)
			ShowImageProgress(NULL, 0);
		
		/* Readout dark frame */
		
		image_data = Image->dark_frame.frame;
		memset(image_data, 0 ,readout->height*readout->width*2);
		ImagingDownloadInProgress = true;
		Form1::SetCCDStatusTextBox("Reading Dark");
		usleep(500000);
		//	Form1::CCDAutoForm->SetDownloadTimerState(true);
		success = GetImage(ccd, readout, false, image_data);
		//	Form1::CCDAutoForm->SetDownloadTimerState(false);
		if (! success) {
			sprintf_s(Message, sizeof(Message), "*** WARNING - Error reading out image\n");
			ImagingDownloadInProgress = false;
			ImageInProgress = false;
			DontUpdate = false;
			return false;
		}
		ImagingDownloadInProgress = false;
		
		sprintf_s(Message, sizeof(Message), "dark frame: \n");
		Form1::StatusPrint(Message);
		print_stats(Image->dark_frame.frame, readout->width, readout->height);
		Image->dark_frame.active = true;
		Image->dark_frame.whichCCD = expose->ccd;
		Image->dark_frame.binning = readout->readoutMode;
		Image->dark_frame.x = readout->left;
		Image->dark_frame.y = readout->top;
		Image->dark_frame.w = readout->width;
		Image->dark_frame.h = readout->height;
		Image->dark_frame.exposure = ((float) (expose->exposureTime/100.0));
	}
	
	/*
	* take a light frame if required
	*/
	
	if (! Image->darkOnly) {
		
		/* Get current temp of light frame */
		
		success = GetCCDTemperature(ccd, &ccd_temp);
		if (! success) {
			Form1::StatusPrint("*** WARNING - Can't get ccd temperature, "
				"aborting exposure...\n");
			ImageInProgress = false;
			DontUpdate = false;
			return false;
		}
		Image->light_frame.temp = ((float) ccd_temp);
		
		Form1::SetCCDStatusTextBox("Exposing Light");
		sprintf_s(Message, sizeof(Message),"Starting %f sec. light frame...\n",
			expose->exposureTime/100.0);
		Form1::StatusPrint(Message);
		usleep(500000);
		time(&Image->light_frame.time);
		expose->openShutter = 1;
		ImagingShutterClosed = false;
		success = StartExposure(ccd, expose, readout);
		if (! success) {
			Form1::StatusPrint("*** WARNING - Error starting light frame...\n");
			ImageInProgress = false;
			DontUpdate = false;
			return false;
		}
		
		/* Wait to start waiting */
		
		ShowedImageProgress = false;
		if ((expose->exposureTime > 100) && (ccd->make != SXPRESS_MAKE)) {
			ShowImageProgress("Exposing - Light Frame", 0);
			ShowedImageProgress = true;
			for (i = 0; i < expose->exposureTime; i += 100) {
				ShowImageProgress("Exposing - Light Frame", 
					(int) (100.0*i/expose->exposureTime));
				sprintf_s(Message, sizeof(Message),"Expose: %4.1f%%", 100.0*i/expose->exposureTime);
				Form1::SetCCDStatusTextBox(Message);
				usleep(1000000);
				if (CancelCurrentAcquire) {
					Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
					ShowImageProgress(NULL, 0);
					EndCCDExposure(ccd, expose, false); // dont digitize
					ImageInProgress = false;
					DontUpdate = false;
					return false;
				}
			}
		} else if (ccd->make != SXPRESS_MAKE)
			usleep(expose->exposureTime*10000);
		
		/* wait for exposure to complete */
		
		for (i = 0; i < 1000; ++i) {
			done = QueryCCDExposureStatus(ccd, expose);
			if (done) {
				EndCCDExposure(ccd, expose, true); // digitize
				break;
			}
			usleep(50000);
			if (CancelCurrentAcquire) {
				Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
				if (ShowedImageProgress)
					ShowImageProgress(NULL, 0);
				EndCCDExposure(ccd, expose,false);  // dont digitize
				ImageInProgress = false;
				DontUpdate = false;
				return false;
			}
		}
		if (i >= 1000) {
			Form1::StatusPrint("*** WARNING - Light exposure didn't finish...\n");
			ImageInProgress = false;
			DontUpdate = false;
			return false;
		}
		if (ShowedImageProgress)
			ShowImageProgress(NULL, 0);
		
		/* Readout light frame */
		
		image_data = Image->light_frame.frame;
		memset(image_data, 0, readout->height*readout->width*2);
		ImagingDownloadInProgress = true;
		Form1::SetCCDStatusTextBox("Reading Light");
		usleep(500000);
		success = GetImage(ccd, readout, true, image_data);
		if (! success) {
			sprintf_s(Message, sizeof(Message), "*** WARNING - Error reading out image\n");
			ImagingDownloadInProgress = false;
			ImageInProgress = false;
			DontUpdate = false;
			return false;
		}
		
		ImagingDownloadInProgress = false;
		
		Image->light_frame.exposure = ((float) (expose->exposureTime/100.0));
		
		/* update image parameters and return */
		
		sprintf_s(Message, sizeof(Message),"image: \n");
		Form1::StatusPrint(Message);
		print_stats(Image->light_frame.frame, readout->width, readout->height);
		Image->light_frame.active = true;
		Image->light_frame.whichCCD = expose->ccd;
		Image->light_frame.binning = readout->readoutMode;
		Image->light_frame.x = readout->left;
		Image->light_frame.y = readout->top;
		Image->light_frame.w = readout->width;
		Image->light_frame.h = readout->height;
		Image->light_frame.exposure = ((float) (expose->exposureTime/100.0));
	}
	
	DontUpdate = false;
	ImageInProgress = false;
	
	return true;
}


bool snapTracking(CCD *ccd, StartExposureParams *expose, StartReadoutParams *readout, IMAGE *Image) {
	
	int success, done;
	unsigned int i;
	unsigned short *image_data;
	char Message[120];
	double ccd_temp;
	bool ShowedImageProgress=false;
	
	if (expose->exposureTime <= 0) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Invalid exposure time: %d in snapTracking,\n"
			"              no exposure taken.\n", expose->exposureTime);
		Form1::StatusPrint(Message);
		return false;
	}
	
	/*
	* take a dark if needed
	*/
	
	DontUpdate = true;
	
	/* Get current temp of dark frame */
	
	if (! Image->lightOnly) {
		success = GetCCDTemperature(ccd, &ccd_temp);
		if (! success) {
			Form1::StatusPrint("*** WARNING - Can't get ccd temperature, aborting exposure (tracking)...\n");
			return false;
		}
		Image->dark_frame.temp = ((float) ccd_temp);
		
		usleep(500000);
		
		expose->openShutter = 2;
		time(&Image->dark_frame.time);
		ImagingShutterClosed = true;
		success = StartExposure(ccd, expose, readout);
		if (! success) {
			Form1::StatusPrint("*** WARNING - Error starting dark frame (tracking)...\n");
			return false;
		}
		
		/* Wait to start waiting */
		
		if (expose->exposureTime > 100) {
			for (i = 0; i < expose->exposureTime; i += 20) {
				usleep(200000);
			}
		} else
			usleep(expose->exposureTime*10000);
		
		/* wait for exposure to complete */
		
		for (i = 0; i < 1000; ++i) {
			done = QueryCCDExposureStatus(ccd, expose);
			if (done) {
				EndCCDExposure(ccd, expose, true);  // digitize
				break;
			}
			usleep(50000);
		}
		if (i == 1000) {
			Form1::StatusPrint("*** WARNING - Dark exposure didn't finish (tracking)...\n");
			return false;
		}
		
		/* Readout dark frame */
		
		image_data = Image->dark_frame.frame;
		memset(image_data, 0 ,readout->height*readout->width*2);
		usleep(500000);
		success = GetImage(ccd, readout, false, image_data);
		if (! success) {
			Form1::StatusPrint("*** WARNING - Error reading out 'dark' of image (tracking)\n");
			return false;
		}
		
		Image->dark_frame.active = true;
		Image->dark_frame.whichCCD = expose->ccd;
		Image->dark_frame.binning = readout->readoutMode;
		Image->dark_frame.x = readout->left;
		Image->dark_frame.y = readout->top;
		Image->dark_frame.w = readout->width;
		Image->dark_frame.h = readout->height;
		Image->dark_frame.exposure = ((float) (expose->exposureTime/100.0));
	}
	
	/*
	* take a light frame if required
	*/
	
	if (! Image->darkOnly) {
		
		/* Get current temp of light frame */
		
		success = GetCCDTemperature(ccd, &ccd_temp);
		if (! success) {
			Form1::StatusPrint("*** WARNING - Can't get ccd temperature, aborting exposure (tracking)...\n");
			return false;
		}
		Image->light_frame.temp = ((float) ccd_temp);
		
		usleep(500000);
		time(&Image->light_frame.time);
		expose->openShutter = 1;
		success = StartExposure(ccd, expose, readout);
		if (! success) {
			Form1::StatusPrint("*** WARNING - Error starting light frame (tracking)...\n");
			return false;
		}
		
		/* Wait to start waiting */
		
		if (expose->exposureTime > 100) {
			for (i = 0; i < expose->exposureTime; i += 20) {
				usleep(200000);
			}
		} else
			usleep(expose->exposureTime*10000);

		/* wait for exposure to complete */

		for (i = 0; i < 1000; ++i) {
			done = QueryCCDExposureStatus(ccd, expose);
			if (done) {
				EndCCDExposure(ccd, expose, true);  // digitize
				break;
			}
			usleep(50000);
		}
		if (i >= 1000) {
			Form1::StatusPrint("*** WARNING - Light exposure didn't finish (tracking)...\n");
			return false;
		}

		/* Readout light frame */

		image_data = Image->light_frame.frame;
		memset(image_data, 0, readout->height*readout->width*2);
		usleep(500000);
		success = GetImage(ccd, readout, true, image_data);
		if (! success) {
			sprintf_s(Message, sizeof(Message), "*** WARNING - Error reading out image (tracking)\n");
			return false;
		}

		Image->light_frame.exposure = ((float) (expose->exposureTime/100.0));

		/* update image parameters and return */

		Image->light_frame.active = true;
		Image->light_frame.whichCCD = expose->ccd;
		Image->light_frame.binning = readout->readoutMode;
		Image->light_frame.x = readout->left;
		Image->light_frame.y = readout->top;
		Image->light_frame.w = readout->width;
		Image->light_frame.h = readout->height;
		Image->light_frame.exposure = ((float) (expose->exposureTime/100.0));
	}
	
	return true;
}


bool query(char *prompt)
{
  /* Declarations */
  
  char	buffer[80];		/* Input buffer */
  bool answer;
  
  /* Print question and get y/n answer */

  answer = false;
  do {
    printf("%s (y/n): ", prompt);
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] == '\n')
      break;
    if ((buffer[0] == 'y') || (buffer[0] == 'Y')) {
      answer = true;
      break;
    } else if ((buffer[0] == 'n') || (buffer[0] == 'N')) {
      answer = false;
      break;
    }
  } while (true);

  return answer;
}


/*
	ROUTINE:	queryr
	PURPOSE:	This routine will print the specified prompt and
			input a real number from the user.
	DATE:		20 SEPT 86
	BY:		A.L. Shoup
*/

void queryr(char *prefix, float *answer, char *suffix, float min, float max)
{
  float	value;		/* Working variable for user's input */
  char	buffer[80];	/* Input buffer for user input */
  
  value = (float) (min - 1.0);
  do {
    printf("%s (%f) %s : ", prefix, *answer, suffix);
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] == '\n')
      break;
    if (sscanf_s(buffer, "%f", &value) != 1)
      value = min - 1;
  } while ((value < min) || (value > max));
  if (buffer[0] != '\n') *answer = value;
  return;
}


/*
	ROUTINE:	queryi
	PURPOSE:	Prints the passed prefix and inputs a short unsigned
	                integer.
	DATE:		11 AUG 86
	BY:		A.L. Shoup
	Modifications:  (Shoup, 12/10/96) put args def's on proc line
*/

			/* Include files */

void queryi(char *prefix, int *answer, char *suffix, int Min, int Max)
{
  /* Declarations */
  
  char	buffer[80];		/* Input buffer */
  int value;
  
  /* Print prefix and get answer */
  
  value = Min - 1;
  do {
    printf("%s (%i) %s : ", prefix, *answer, suffix);
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] == '\n')
      break;
    if (sscanf_s(buffer, "%i", &value) != 1)
      value = Min - 1;
  } while ((value < Min) || (value > Max));
  if (buffer[0] != '\n') *answer = value;
  return;
}


void freeImageBuffers(CCD *ccd)
{
/*  if (ccd->Image.light_frame.frame != NULL)
    free(ccd->Image.light_frame.frame);
  if (ccd->Image.dark_frame.frame != NULL)
    free(ccd->Image.dark_frame.frame);

  if (ccd->FlatImage.light_frame.frame != NULL)
    free(ccd->FlatImage.light_frame.frame);
  if (ccd->FlatImage.dark_frame.frame != NULL)
    free(ccd->FlatImage.dark_frame.frame);  */

  return;
}

/* gint updateImageDisplay(gpointer data) */
/* { */
/*   fd_set read_fds; */

/*   FD_ZERO(&read_fds); */
/*   FD_SET(0, &read_fds); */
/*   FD_SET(ConnectionNumber(x_info.display), &read_fds); */
/*   select(32, &read_fds, NULL, NULL, NULL); */
/*   if (FD_ISSET(ConnectionNumber(x_info.display), &read_fds)) { */

    /*    XEvent ev;
        if (XCheckWindowEvent(x_info.display, x_info.window, 0, &ev)) {
      XNextEvent(x_info.display, &ev); 
      if (ev.type==Expose) {
      if (ev.xexpose.count == 0 && x_info.image != NULL) { */

/* 	  Imlib_paste_image(x_info.im, x_info.image, x_info.window, */
/* 			    0, 0, x_info.image->rgb_width, */
/* 			    x_info.image->rgb_height); */
/* 	  XFlush(x_info.display); */

	  /*	}
      }
      } */
/*    }  */
/*   return true; */
/* } */

bool readDark(char *Dir, IMAGE *Image)
{
  char Comment[160], Message[160];
  char fileName[160];
  int anynull, status, nfound;
  float nullval;
  long naxes[2], fpixel, npixels;
  fitsfile *fptr;
  FRAME *darkFrame, *lightFrame;

  darkFrame = &Image->dark_frame;
  lightFrame = &Image->light_frame;
  darkFrame->active = false;

  /* Form compatible file name and open it */
  
  if (Image->light_frame.exposure >= 10.0) {
	  sprintf_s(fileName, sizeof(fileName), "%s/Dark%s_%d.fits",
		  Dir, binningString[Image->light_frame.binning], 
		  ((int)Image->light_frame.exposure));
  } else {
	  sprintf_s(fileName, sizeof(fileName), "%s/Dark%s_%dms.fits",
		  Dir, binningString[Image->light_frame.binning], 
		  ((int)(Image->light_frame.exposure*1000)));
  }

  /* Open fits file for reading */

  status = 0;
  if (fits_open_file(&fptr, fileName, READONLY, &status)) {
	  ShowFitsError();
	  return false;
  }

  /* get image keywords */

  if (fits_read_keys_lng(fptr, "NAXIS", 1, 2, naxes, &nfound, &status)) {
	  ShowFitsError();
	  return false;
  }
  npixels = naxes[0]*naxes[1];
  darkFrame->w = naxes[0];
  darkFrame->h = naxes[1];

  if ((darkFrame->w != lightFrame->w) ||
      (darkFrame->h != lightFrame->h)) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d,%d) & Dark (%d,%d) sizes"
	    " not compatible, aborting...\n",
	    lightFrame->w, lightFrame->h, darkFrame->w, darkFrame->h);
    Form1::StatusPrint(Message);
	fits_close_file(fptr, &status);
    return false;
  }

  if (fits_read_key(fptr, TFLOAT, "EXPOSURE", &darkFrame->exposure, Comment, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }

  if (fits_read_key(fptr, TFLOAT, "CCDTEMP", &darkFrame->temp, Comment, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }

  if (fabs(darkFrame->temp-lightFrame->temp) > MAXTEMPDIFF) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Temp diff between light and dark frames"
	    " too big: %f %f\n", lightFrame->temp, darkFrame->temp);
    Form1::StatusPrint(Message);
	fits_close_file(fptr, &status);
    return false;
  }

  if (fits_read_key(fptr, TINT, "STARTX", &darkFrame->x, Comment, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }
  if (fits_read_key(fptr, TINT, "STARTY", &darkFrame->y, Comment, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }

  if ((darkFrame->x != lightFrame->x) ||
      (darkFrame->y != lightFrame->y)) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d,%d) & Dark (%d,%d) start"
	    " positions not compatible, aborting...\n",
	    lightFrame->x, lightFrame->y, darkFrame->x, darkFrame->y);
    Form1::StatusPrint(Message);
	fits_close_file(fptr, &status);
    return false;
  }

  if (fits_read_key(fptr, TINT, "BINNING", &darkFrame->binning, Comment, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }

  if (darkFrame->binning != lightFrame->binning) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d) & Dark (%d) binning"
	    " not the same, aborting...\n",
	    lightFrame->binning, darkFrame->binning);
    Form1::StatusPrint(Message);
	fits_close_file(fptr, &status);
    return false;
  }

  if (fits_read_key(fptr, TINT, "WHICHCCD", &darkFrame->whichCCD, Comment, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }

  if (darkFrame->whichCCD != lightFrame->whichCCD) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d) & Dark (%d) whichCCD"
	    " not the same, aborting...\n",
	    lightFrame->whichCCD, darkFrame->whichCCD);
    Form1::StatusPrint(Message);
	fits_close_file(fptr, &status);
    return false;
  }

  /* Allocate memory for image */

//ALS  darkFrame->frame = (unsigned short *)
//    realloc(darkFrame->frame, npixels*sizeof(unsigned short));

  /* read in image */

  fpixel = 1;
  nullval = 0;
  if (fits_read_img(fptr, TUSHORT, fpixel, npixels, &nullval,
		    darkFrame->frame, &anynull, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }

  fits_close_file(fptr, &status);
  darkFrame->active = true;
  
  return true;
}

bool readFlat(char *Dir, CCD *ccd)
{
  char Comment[160], fileName[160];
  char Message[160];
  int anynull, status, nfound;
  float nullval;
  long naxes[2], fpixel, npixels;
  fitsfile *fptr;
  FRAME *flatFrame, *lightFrame;
  FILE *fptr_check;

  flatFrame = &ccd->FlatImage.light_frame;
  lightFrame = &ccd->Image.light_frame;

  flatFrame->active = false;

  /* Open fits file for reading */

  sprintf_s (fileName, sizeof(fileName), "%s/Flat%s%c.fits", Dir,
	  binningString[ccd->Image.light_frame.binning],
	  ccd->Image.Filter[0]);

  fopen_s(&fptr_check, fileName, "r");
  if (fptr_check == NULL) {
	  sprintf_s(Message, sizeof(Message), "*** WARNING - Can't find flat file: %s\n", fileName);
	  Form1::StatusPrint(Message);
	  return false;
  } else {
	  fclose(fptr_check);
  }

  status = 0;
  if (fits_open_file(&fptr, fileName, READONLY, &status)) {
	  sprintf_s(Message, sizeof(Message), "*** Warning - Can't open fits file: %s\n", fileName);
	  Form1::StatusPrint(Message);
	  return false;
  }

  /* get image size keywords */

  if (fits_read_keys_lng(fptr, "NAXIS", 1, 2, naxes, &nfound, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }
  npixels = naxes[0]*naxes[1];
  flatFrame->w = naxes[0];
  flatFrame->h = naxes[1];

  if ((flatFrame->w != lightFrame->w)) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d,%d) & Flat (%d,%d) sizes"
	    " not compatible, aborting...\n",
	    lightFrame->w, lightFrame->h, flatFrame->w, flatFrame->h);
    Form1::StatusPrint(Message);
	fits_close_file(fptr, &status);
    return false;
  }

  /* get some keywords */

  if (fits_read_key(fptr, TFLOAT, "EXPOSURE", &flatFrame->exposure, Comment, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }

  if (fits_read_key(fptr, TSTRING, "OBJECT", ccd->FlatImage.ObjectName, Comment, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }

  if (fits_read_key(fptr, TINT, "STARTX", &flatFrame->x, Comment, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }
  if (fits_read_key(fptr, TINT, "STARTY", &flatFrame->y, Comment, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }

  if ((flatFrame->x != lightFrame->x) ||
      (flatFrame->y != lightFrame->y)) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d,%d) & Flat (%d,%d) start"
	    " positions not compatible, aborting...\n",
	    lightFrame->x, lightFrame->y, flatFrame->x, flatFrame->y);
    Form1::StatusPrint(Message);
	fits_close_file(fptr, &status);
    return false;
  }

  if (fits_read_key(fptr, TINT, "BINNING", &flatFrame->binning, Comment, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }

  if (flatFrame->binning != lightFrame->binning) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d) & Flat (%d) binning"
	    " not the same, aborting...\n",
	    lightFrame->binning, flatFrame->binning);
    Form1::StatusPrint(Message);
	fits_close_file(fptr, &status);
    return false;
  }

  if (fits_read_key(fptr, TINT, "WHICHCCD", &flatFrame->whichCCD, Comment, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }

  if (flatFrame->whichCCD != lightFrame->whichCCD) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d) & Flat (%d) whichCCD"
	    " not the same, aborting...\n",
	    lightFrame->whichCCD, flatFrame->whichCCD);
    Form1::StatusPrint(Message);
	fits_close_file(fptr, &status);
    return false;
  }

  /* Allocate memory for image */

//ALS  flatFrame->frame = (unsigned short *)
//    realloc(flatFrame->frame, npixels*sizeof(unsigned short));

  /* read in image */

  fpixel = 1;
  nullval = 0;
  if (fits_read_img(fptr, TUSHORT, fpixel, npixels, &nullval,
		    flatFrame->frame, &anynull, &status)) {
	  ShowFitsError();
	  fits_close_file(fptr, &status);
	  return false;
  }

  fits_close_file(fptr, &status);
  flatFrame->active = true;
  strcpy_s(ccd->FlatImage.FileName,sizeof(ccd->FlatImage.FileName),fileName);

  return true;
}

void ShowFitsError(void) {
	int status;
	char buffer[80], Message[160];
	status = fits_read_errmsg(buffer);
	if (strlen(buffer) > 0) {
	  sprintf_s(Message, sizeof(Message), "*** FITS Error - %s\n", buffer);
	  Form1::StatusPrint(Message);        // print error report
	}
}


bool readLight(char *fileName, IMAGE *Image) {
  char Comment[160], buffer[160], Message[160];
  int anynull, status, nfound, nItems, hours, degs, mins;
  float nullval, secs;
  long naxes[2], fpixel, npixels;
  fitsfile *fptr;
  FRAME *lightFrame;
  OBJECT objectInfo;
  bool success;

  /* Open fits file for reading */

  status = 0;
  if (fits_open_file(&fptr, fileName, READONLY, &status)) {
    ShowFitsError();
    return false;
  }

  /* get image size keywords */

  lightFrame = &Image->light_frame;
  naxes[0] = naxes[1] = 0;
  if (fits_read_keys_lng(fptr, "NAXIS", 1, 2, naxes, &nfound, &status)) {
    ShowFitsError();
    fits_close_file(fptr, &status);
    return false;
  }
  npixels = naxes[0]*naxes[1];

  if (npixels <= 0) { // if NAXIS not found, try Image Width, etc.
	  if (fits_read_key_lng(fptr, "ImageWidth", &naxes[0], Comment, &status)) {
		  ShowFitsError();
          fits_close_file(fptr, &status);
		  return false;
	  }
	  if (fits_read_key_lng(fptr, "ImageHeight", &naxes[1], Comment, &status)) {
		  ShowFitsError();
		  fits_close_file(fptr, &status);
		  return false;
	  }
	  npixels = naxes[0]*naxes[1];
	  if (npixels <= 0) {
		  Form1::StatusPrint("*** Warning - Invalid size of image...\n");
		  fits_close_file(fptr, &status);
		  return false;
	  }
  }

  /* (Re)Allocate memory for image */

//ALS  lightFrame->frame = (unsigned short *) realloc(lightFrame->frame,
//			      npixels*sizeof(unsigned short));

  	ccd->Image.light_frame.frame = ImagingLightFrame; // use static acquire frames
	ccd->Image.dark_frame.frame = ImagingDarkFrame;
	ccd->FlatImage.light_frame.frame = ImagingFlatLightFrame;
	ccd->FlatImage.dark_frame.frame = ImagingFlatDarkFrame;

  /* read in image */

  fpixel = 1;
  nullval = 0;

  if ((naxes[0] == 752) && (naxes[1] == 580)) { // BIG clug to handle MX916 images
	  if (fits_read_img(fptr, TSHORT, fpixel, npixels, &nullval,
		  lightFrame->frame, &anynull, &status)) {
		 ShowFitsError();
		 fits_close_file(fptr, &status);
		 return false;
	  }
  } else {
	  if (fits_read_img(fptr, TUSHORT, fpixel, npixels, &nullval,
		  lightFrame->frame, &anynull, &status)) {
		 ShowFitsError();
		 fits_close_file(fptr, &status);
		 return false;
	  }
  }

  /* get some keywords */

  if (fits_read_key(fptr, TFLOAT, "EXPOSURE", &lightFrame->exposure,
		    Comment, &status)) {
    status = 0;
    if (fits_read_key(fptr, TFLOAT, "EXPTIME", &lightFrame->exposure,
		      Comment, &status)) {
	  ShowFitsError();
      fits_close_file(fptr, &status);
      return false;
    }
  }

  if (fits_read_key(fptr, TFLOAT, "CCDTEMP", &lightFrame->temp, Comment, &status)) {
	  status = 0;
	  if (fits_read_key(fptr, TFLOAT, "CCD-TEMP", &lightFrame->temp, Comment, &status)) {
		  ShowFitsError();
		  lightFrame->temp = -999.0;  /// No ccd temperature available?
//		  fits_close_file(fptr, &status);
//		  return false;
	  }
  }

  if (fits_read_key(fptr, TFLOAT, "GAIN", &ccd->gain, Comment, &status)) {
	  ShowFitsError();
	  ccd->gain = DEFAULTU8300GAIN;
	  Form1::StatusPrint("*** Warning fits has no GAIN keyword, setting gain to 1.75 e-'s/ADC\n");
  }

  if (fits_read_key(fptr, TFLOAT, "RDNOISE", &ccd->readNoise, Comment, &status)) {
	  ShowFitsError();
	  ccd->readNoise = DEFAULTU8300READNOISE;
	  Form1::StatusPrint("*** Warning fits has no RDNOISE keyword, setting noise to 15.0 e-'s RMS\n");
  }

  if (fits_read_key(fptr, TSTRING, "OBJECT", &Image->ObjectName,
		    Comment, &status)) {
	ShowFitsError();
    strcpy_s(Image->ObjectName, sizeof(Image->ObjectName), "none");
  }
  if (strcmp(Image->ObjectName, "none") == 0) {
	if (fits_read_key(fptr, TSTRING, "RA", buffer, Comment, &status)) {
		ShowFitsError();
		Image->plateSolution.InitFieldCenterRA = 0.0;
	} else {
		nItems = sscanf_s(buffer, "%d:%d:%f", &hours, &mins, &secs);
		if (nItems != 3) {
			sprintf_s(Message, sizeof(Message), "*** Warning - Bad RA format in fits file: %s\n", buffer);
			Form1::StatusPrint(Message);
			Image->plateSolution.InitFieldCenterRA = 0.0;
		} else {
			ConvertHMStoRA(hours, mins, secs, &Image->plateSolution.InitFieldCenterRA);
		}
	}
	if (fits_read_key(fptr, TSTRING, "DEC", buffer, Comment, &status)) {
		ShowFitsError();
		Image->plateSolution.InitFieldCenterDEC = 0.0;
	} else {
		nItems = sscanf_s(buffer, "%d:%d:%f", &degs, &mins, &secs);
		if (nItems != 3) {
			sprintf_s(Message, sizeof(Message), "*** Warning - Bad DEC format in fits file: %s\n", buffer);
			Form1::StatusPrint(Message);
			Image->plateSolution.InitFieldCenterDEC = 0.0;
		} else {
			ConvertDMStoDEC(degs, mins, secs, &Image->plateSolution.InitFieldCenterDEC);
		}
	}
  } else {
	  success = GetObjectInfo(Image->ObjectName, &objectInfo);
	  if (success) {
		  sscanf_s(objectInfo.ra, "%d:%d:%f", &hours, &mins, &secs);
		  ConvertHMStoRA(hours, mins, secs, &Image->plateSolution.InitFieldCenterRA);
		  sscanf_s(objectInfo.dec, "%d:%d:%f", &degs, &mins, &secs);
		  ConvertDMStoDEC(degs, mins, secs, &Image->plateSolution.InitFieldCenterDEC);
	  }
  }
  
  if (fits_read_key(fptr, TSTRING, "OBSERVAT", &ObsSettings.name,
		    Comment, &status)) {
	ShowFitsError();
    //strcpy_s(ObsSettings.name, sizeof(ObsSettings.name), "none");
  }

  if (fits_read_key(fptr, TSTRING, "FILTER", &Image->Filter,
		    Comment, &status)) {
	ShowFitsError();
    strcpy_s(Image->Filter, sizeof(Image->Filter), "n");
  }

  if (fits_read_key(fptr, TSTRING, "OBSERVER", &ObsSettings.Observer,
		    Comment, &status)) {
	ShowFitsError();
    //strcpy_s(ObsSettings.Observer, sizeof(ObsSettings.Observer), "n");
  }

  if (fits_read_key(fptr, TSTRING, "PROJECT", &ObsSettings.Project,
		    Comment, &status)) {
	ShowFitsError();
	//strcpy_s(ObsSettings.Project, sizeof(ObsSettings.Project), "n");
  }

  if (fits_read_key(fptr, TINT, "STARTX", &lightFrame->x,
		    Comment, &status)) {
    if (fits_read_key(fptr, TINT, "XORGSUBF", &lightFrame->x,
		      Comment, &status)) {
	  ShowFitsError();
      lightFrame->x = 0;
    }
  }

  if (fits_read_key(fptr, TINT, "STARTY", &lightFrame->y,
		    Comment, &status)) {
    if (fits_read_key(fptr, TINT, "YORGSUBF", &lightFrame->y,
		      Comment, &status)) {
	  ShowFitsError();
      lightFrame->y = 0;
    }
  }

  if (fits_read_key(fptr, TINT, "BINNING", &lightFrame->binning,
		    Comment, &status)) {
    if (fits_read_key(fptr, TINT, "XBINNING", &lightFrame->binning,
		      Comment, &status)) {
	  ShowFitsError();
      lightFrame->binning = 0;
    }
  }

  if (fits_read_key(fptr, TSTRING, "UT", &lightFrame->UT,
		    Comment, &status)) {
    if (fits_read_key(fptr, TSTRING, "TIME-OBS", &lightFrame->UT,
		      Comment, &status)) {
	  ShowFitsError();
      strcpy_s(lightFrame->UT, sizeof(lightFrame->UT), "");
    }
  }

  if (fits_read_key(fptr, TSTRING, "DATE-OBS", &lightFrame->UTDATE,
		    Comment, &status)) {
	ShowFitsError();
    strcpy_s(lightFrame->UTDATE, sizeof(lightFrame->UTDATE), "");
  }

  if (fits_read_key(fptr, TINT, "WHICHCCD", &lightFrame->whichCCD,
		    Comment, &status)) {
	ShowFitsError();
    lightFrame->whichCCD = 0;
  }

  /* Get plate solution related keywords (astrometry) */

  Image->plateSolution.status = 0;
  if (fits_read_key(fptr, TDOUBLE, "PLATERA", &Image->plateSolution.FieldCenterRA, Comment, &status)) {
	  Image->plateSolution.FieldCenterRA = 0.0;
	  Image->plateSolution.status = -4;
  }
  if (fits_read_key(fptr, TDOUBLE, "PLATEDEC", &Image->plateSolution.FieldCenterDEC, Comment, &status)) {
	  Image->plateSolution.FieldCenterDEC = 0.0;
	  Image->plateSolution.status = -4;
  }
  if (fits_read_key(fptr, TDOUBLE, "PLATEA", &Image->plateSolution.coeffs[0], Comment, &status)) {
	  Image->plateSolution.coeffs[0] = 0.0;
	  Image->plateSolution.status = -4;
  }
  if (fits_read_key(fptr, TDOUBLE, "PLATEB", &Image->plateSolution.coeffs[1], Comment, &status)) {
	  Image->plateSolution.coeffs[1] = 0.0;
	  Image->plateSolution.status = -4;
  }
  if (fits_read_key(fptr, TDOUBLE, "PLATEC", &Image->plateSolution.coeffs[2], Comment, &status)) {
	  Image->plateSolution.coeffs[2] = 0.0;
	  Image->plateSolution.status = -4;
  }
  if (fits_read_key(fptr, TDOUBLE, "PLATED", &Image->plateSolution.coeffs[3], Comment, &status)) {
	  Image->plateSolution.coeffs[3] = 0.0;
	  Image->plateSolution.status = -4;
  }
  if (fits_read_key(fptr, TDOUBLE, "PLATEE", &Image->plateSolution.coeffs[4], Comment, &status)) {
	  Image->plateSolution.coeffs[4] = 0.0;
	  Image->plateSolution.status = -4;
  }
  if (fits_read_key(fptr, TDOUBLE, "PLATEF", &Image->plateSolution.coeffs[5], Comment, &status)) {
	  Image->plateSolution.coeffs[5] = 0.0;
	  Image->plateSolution.status = -4;
  }

  if (Image->plateSolution.status != 0) {

  }

  lightFrame->w = naxes[0];
  lightFrame->h = naxes[1];
  lightFrame->active = true;
  strcpy_s(Image->FileName, sizeof(Image->FileName), fileName);

  /* Close the FITS file */

  status = 0;
  if (fits_close_file(fptr, &status)) {
    ShowFitsError();
    strcpy_s(Image->FileName, sizeof(Image->FileName), "FITS error");
    return true;
  }

  return true;
}

void CalcObsParms(float *AirMass, double *JD, double *HJD,
		  OBJECT *objectInfo, OBSSETTINGS *ObsSettings,
		  char *UTBuffer, char *UTDBuffer, float exposure)
{
  float raHours, raRad, decDeg, decRad, latRad, xhours, haRad, haHours;
  float dayFrac, lst, secs;
  double r, d, TCorr;
  int hours, mins, deg, day, month, year;

  /* get needed parameters */

  sscanf_s(objectInfo->ra,"%2d:%2d:%f", &hours, &mins, &secs);
  raHours = (float) (hours + mins/60.0 + secs/3600.0);
  r = raHours;
  raRad   = (float) (raHours *2.0*PI/24.0);
  sscanf_s(objectInfo->dec, "%3d:%2d:%f", &deg, &mins, &secs);
  decDeg = (float) (deg + mins/60.0 + secs/360.0);
  d = decDeg;
  decRad = (float) (decDeg *2.0*PI/360.0);
  sscanf_s(UTBuffer,"%2d:%2d:%f", &hours, &mins, &secs);
  xhours = (float) (hours + mins/60.0 + (secs+exposure/2.0)/3600.0);
  dayFrac = (float) (xhours/24.0);
  sscanf_s(UTDBuffer,"%4d-%2d-%2d", &year, &month, &day);
  latRad = (float) (ObsSettings->latitude * 2.0*PI/360.0);

  /* Compute geocentric Julian Day */

  *JD = JulDay(day, dayFrac, month, year);
  
  /* Compute local sidereal time */

  lst = LocalSiderealTime(*JD, ObsSettings->longitude);

  /* Compute hour angle */

  haHours = lst - raHours;
  haRad = (float) (haHours * 2.0*PI/24.0);

  /* Compute air mass */

  *AirMass = (float) (1.0/(sin(latRad)*sin(decRad)+cos(latRad)*cos(decRad)*cos(haRad)));

  /* Compute heliocenteric Julian day */

  ConvertJDtoHJD(r, d, *JD, &TCorr, HJD);

  return;
}

double JulDay(int IDay, float RFrac, int IMon, int IYear)
{
  double A, B, DJD;

  A = 10000.0*IYear + 100.0*IMon + IDay;
  if (IMon <= 2) {
    IMon += 12;
    IYear--;
  }
  if (A <= 15821004.1) {
    B = -2 + ((int)(IYear+4716)/4) - 1179;
  } else {
    B = ((int) (IYear/400)) - ((int)(IYear/100)) + ((int)(IYear/4));
  }
  A = 365.0 * IYear - 679004.0;
  DJD = A + B + ((int)(30.6001*(IMon+1))) + IDay + RFrac;
  DJD += 2400000.5;

  return DJD;
}

float LocalSiderealTime(double JD, double longitude)
{
  long int JD0;
  float UT, LMST;
  double T, GMST;

  JD0 = ((int) JD);
  UT = (float) ((JD - JD0 - 0.5) * 24.0);
  T = (JD0 - 2451544.5)/36525.0;
  GMST = 6.697374558 + 1.0027379093*UT +
         (8640184.812866+(0.093104-6.2e-6*T)*T)*T/3600.0;
  LMST = (float) (GMST - longitude/15.0);
  if (LMST < 0.0) LMST += 24.0;
  if (LMST >= 24.0) LMST -= 24.0;
  return LMST;
}

void Sun(double JD, float *SunLong, float *RSN)
{
  /*	For the date given by IDay,RFrac,IMon,IYear, compute the
	Ecliptic Longitude of the sun (radians) and the distance from
	the earth to the sun (AU). */

  /*	COMMON/MoonDat/LongSun, LongMoon, LatMoon, MoonMD, MoonMS
	REAL*8 LongSun, LongMoon, LatMoon, MoonMD, MoonMS */

  double RRad, T, T2, A, B, LS, MS;
  double A1, B1, C1, D1, E1, H1, DL, DR, LSN;
  double RPi2;
  float MA, S, EA, NU;


  RRad = 1.745329252E-2;
  /*   JD = DaysSince( JD); */
  T = JD/36525.;
  T2 = T*T;
  A = 1.000021359E2 * T;
  B = 360.0 * (A - floor(A));
  LS = 2.7969668E2 + 3.025E-4 * T2 + B;
  A = 9.999736042E1 * T;
  B = 360.0 * (A - floor(A));
  MS = 3.5847583E2-(1.5E-4 + 3.3E-6*T)*T2+B;
  S = (float) (1.675104E-2 - 4.18E-5*T - 1.26E-7*T2);
  MA = (float) (RRad*MS);
  Anomaly(MA, S, &NU, &EA);
  A = 6.255209472E1*T;
  B = 360.0 * (A - floor(A));
  A1 = (153.23+B)*RRad;
  A = 1.251041894E2*T;
  B = 360.0 * (A - floor(A));
  B1 = (216.57+B)*RRad;
  A = 9.156766028E1*T;
  B = 360.0 * (A - floor(A));
  C1 = (312.69+B)*RRad;
  A = 1.236853095E3*T;
  B = 360.0 * (A - floor(A));
  D1 = (350.74-1.44E-3*T2+B)*RRad;
  E1 = (231.19+20.2*T)*RRad;
  A = 1.831353208E2*T;
  B = 360.0 * (A - floor(A));
  H1 = (353.4+B)*RRad;
  DL = 1.34E-3*cos(A1) + 1.54E-3*cos(B1) +
    2E-3*cos(C1) + 1.79E-3*sin(D1) +
    1.78E-3*sin(E1);
  DR = 5.43E-6*sin(A1) + 1.575E-5*sin(B1) +
    1.627E-5*sin(C1) + 3.076E-5*cos(D1) +
    9.27E-6*sin(H1);
  LSN = NU + (LS-MS+DL)*RRad;
  RPi2 = 6.283185308;
  *RSN = (float) (1.0000002*(1.-S*cos(EA))+DR);
  while (LSN < 0.0) {
    LSN += RPi2;
  }
  while (LSN > RPi2) {
    LSN -= RPi2;
  }
  *SunLong = (float) LSN;
}


void Anomaly(float MA, float S, float *NU, float *EA)
{
  /* Given the mean anomaly (MA) and the eccentricity (S <1),
     this routine computes the true anomaly (NU) and
     the eccentric anomaly (EA).  All angles in RADIANS */

  double APi2, RM, DLA, TNU2;

  APi2 = 6.283185308;
  RM = MA - APi2 * floor(MA/APi2);
  *EA = (float) RM;

  do {
    DLA = *EA - (S*sin(*EA))-RM;
    if (fabs(DLA) < 1.0e-6)
      break;
    DLA = DLA/(1.-(S*cos(*EA)));
    *EA -= (float) DLA;
  } while (true);

  TNU2 = sqrt( (1.+S)/(1.-S))*tan(*EA/2.);
  *NU = (float) (2.*atan(TNU2));
}


void ShowImageProgress(char *Label, int percent)
{
  static int Shown=false;

  if (DontShowImageProgress)
    return;

  if (! ProgressDialogExists) {
    gcnew ProgressDialog();
  }
  ProgressDialog::ShowProgressDialog();
  Shown = true;

  if (Label == NULL) {
	  ProgressDialog::HideProgressDialog();
  } else {
    if (percent == 0) {
		ProgressDialog::SetProgressDialogLabel(Label);
		ProgressDialog::SetProgressDialogBar(percent);
    } else {
		ProgressDialog::SetProgressDialogBar(percent);
    }
  }
}


void ShowGuidingProgress(char *Label, int percent)
{
  static int Shown=false;

  if (DontShowGuidingProgress)
    return;

  if (! GuidingProgressDialogExists) {
    gcnew GuidingProgressDialog();
  }
  GuidingProgressDialog::ShowGuidingProgressDialog();
  Shown = true;

  if (Label == NULL) {
	  GuidingProgressDialog::HideGuidingProgressDialog();
  } else {
    if (percent == 0) {
		GuidingProgressDialog::SetGuidingProgressDialogLabel(Label);
		GuidingProgressDialog::SetGuidingProgressDialogBar(percent);
    } else {
		GuidingProgressDialog::SetGuidingProgressDialogBar(percent);
    }
  }
}


void RunMainIteration(double seconds)
{
  int runMainIterationTimer;
//  unsigned int timerID;

  runMainIterationTimer = (int) (seconds * 100.0);

//  timerID = gtk_timeout_add(10, decrementRunMainIterationTimer,
//			    &runMainIterationTimer);

/*  do {
    gtk_main_iteration_do(false);
  } while (runMainIterationTimer > 0);

  gtk_timeout_remove(timerID); */

  return;

}

int decrementRunMainIterationTimer(void *data)
{
  int *timer;

  timer = (int *)data;
  (*timer)--;

  if (*timer <= 0)
    return false;
  else
    return true;
}


void ConvertJDtoHJD(double ra, double dec, double jd, double *lt, double *hjd)
{
  /*  double	ra;    Right ascension of observation (hours)
      double	dec;   Declination of observation (degrees)
      double	jd;    Geocentric Julian date of observation
      double	lt;    Light travel time in seconds
      double	hjd;   Helocentric Julian Day
  */

  double t, manom, lperi, oblq, eccen, tanom, slong, r, d, l, b, rsun;
  // JD is the geocentric Julian date.
  // T is the number of Julian centuries since J1900.

  t = (jd - 2415020.0) / 36525.0;

  // MANOM is the mean anomaly of the Earth's orbit (degrees)
  // LPERI is the mean longitude of perihelion (degrees)
  // OBLQ is the mean obliquity of the ecliptic (degrees)
  // ECCEN is the eccentricity of the Earth's orbit (dimensionless)

  manom = 358.47583 +
    t * (35999.04975 - t * (0.000150 + t * 0.000003));
  lperi = 101.22083 +
    t * (1.7191733 + t * (0.000453 + t * 0.000003));
  oblq = 23.452294 -
    t * (0.0130125 + t * (0.00000164 - t * 0.000000503));
  eccen = 0.01675104 - t * (0.00004180 + t * 0.000000126);

  // Convert to principle angles

  manom = fmod(manom,360.0);
  lperi = fmod(lperi,360.0);

  // Convert to radians

  r = ra * 2.0*PI/24.0;
  d = dec * 2.0*PI/360.0;
  manom = manom * 2.0*PI/360.0;
  lperi = lperi * 2.0*PI/360.0;
  oblq = oblq * 2.0*PI/360.0;

  // TANOM is the true anomaly (approximate formula) (radians)

  tanom = manom + (2 * eccen - 0.25 * eccen*eccen*eccen) * sin (manom) +
    1.25 * eccen*eccen * sin (2 * manom) +
    13./12. * eccen*eccen*eccen * sin (3 * manom);

  // SLONG is the true longitude of the Sun seen from the Earth (radians)

  slong = lperi + tanom + PI;

  // L and B are the longitude and latitude of the star in the orbital
  // plane of the Earth (radians)

  ast_coord(0.0, 0.0, -HALFPI, HALFPI - oblq, r, d, &l, &b);

  // R is the distance to the Sun.

  rsun = (1. - eccen*eccen) / (1. + eccen * cos(tanom));

  // LT is the light travel difference to the Sun.

  *lt = -0.005770 * rsun * cos(b) * cos(l - slong);
  *hjd = jd + *lt;

  return;
}


// AST_COORD -- Convert spherical coordinates to new system.

// This procedure converts the longitude-latitude coordinates (a1, b1)
// of a point on a sphere into corresponding coordinates (a2, b2) in a
// different coordinate system that is specified by the coordinates of its
// origin (ao, bo).  The range of a2 will be from -pi to pi.

void ast_coord(double ao, double bo, double ap, double bp, double a1,
	       double b1, double *a2, double *b2)
{

  /* 
     double ao, bo;     Origin of new coordinates (radians)
     double ap, bp;	Pole of new coordinates (radians)
     double a1, b1;	Coordinates to be converted (radians)
     double a2, b2;	Converted coordinates (radians)
  */

  double sao, cao, sbo, cbo, sbp, cbp;
  double x, y, z, xp, yp, zp, temp;

  x = cos(a1) * cos(b1);
  y = sin(a1) * cos(b1);
  z = sin(b1);
  xp = cos(ap) * cos(bp);
  yp = sin(ap) * cos(bp);
  zp = sin(bp);

  // Rotate the origin about z.

  sao = sin(ao);
  cao = cos(ao);
  sbo = sin(bo);
  cbo = cos(bo);
  temp = -xp * sao + yp * cao;
  xp = xp * cao + yp * sao;
  yp = temp;
  temp = -x * sao + y * cao;
  x = x * cao + y * sao;
  y = temp;

  // Rotate the origin about y.

  temp = -xp * sbo + zp * cbo;
  xp = xp * cbo + zp * sbo;
  zp = temp;
  temp = -x * sbo + z * cbo;
  x = x * cbo + z * sbo;
  z = temp;

  // Rotate pole around x.

  sbp = zp;
  cbp = yp;
  temp = y * cbp + z * sbp;
  y = y * sbp - z * cbp;
  z = temp;

  // Final angular coordinates.

  *a2 = atan2(y, x);
  *b2 = asin(z);

  return;
}


bool GetScopePosition(double *ScopeRA, double *ScopeDEC) {

	double parms[2];
	bool success;

	success = SendOSUrobMessage('G', NULL, parms);
	if (success) {
		*ScopeRA = parms[0];
		*ScopeDEC = parms[1];
	} else {
		*ScopeRA = 0.0;
		*ScopeDEC = 0.0;
	}
	return success;
}


void UpdateDarkFrameSettings(void) {
	
	char buffer[80];

  /* Get parms not already gotten */

  DarkFrameSettingsDialog::GetFrameTextBox(buffer);
  sscanf_s(buffer, "%d, %d, %d, %d", &darkFrameSettings.x, &darkFrameSettings.y,
	 &darkFrameSettings.h, &darkFrameSettings.w);

  DarkFrameSettingsDialog::GetNumFramesTextBox(buffer);
  sscanf_s(buffer, "%d", &darkFrameSettings.numFrames);

  DarkFrameSettingsDialog::GetExpTimeTextBox(buffer);
  sscanf_s(buffer, "%f", &darkFrameSettings.exposureTime);

  DarkFrameSettingsDialog::GetDarkDirTextBox(darkFrameSettings.imageDir);

//  updateStatusInfo();
}

void WriteStatus(char *text) {

	Form1::StatusPrint(text);
}


void UpdateFlatFrameSettings(void)
{
  int i, darkOption;
  char Message[120];
  char buffer[80];

  /* Get parms not already gotten */

  /* Get dark frame option */

  darkOption = FlatFrameSettingsDialog::GetDarkFrameOptionComboBox() + 1;
  if ((darkOption < 1) || (darkOption > 4)) {
    sprintf_s(Message, sizeof(Message),
	    "*** Internal error - bad dark option: %d (FlatFrameSettings\n)",
	    darkOption);
    Form1::StatusPrint(Message);
  }

  /* Get filter sequence values */

  for (i=0; i<NUMFILTERS; i++) {
	if (FlatFrameSettingsDialog::GetFilterCheckBoxState(filterSet[i])) {
      flatFrameSettings.filterSeq.Use[i] = true;
	  FlatFrameSettingsDialog::GetFilterExpTimeTextBox(filterSet[i], buffer);
      sscanf_s(buffer, "%f", &flatFrameSettings.filterSeq.exposures[i]);
    }
  }

  FlatFrameSettingsDialog::GetFrameTextBox(buffer);
  sscanf_s(buffer, "%d, %d, %d, %d", &flatFrameSettings.x,
	 &flatFrameSettings.y, &flatFrameSettings.h, &flatFrameSettings.w);

  FlatFrameSettingsDialog::GetNumFramesTextBox(buffer);
  sscanf_s(buffer, "%d", &flatFrameSettings.numFrames);

  FlatFrameSettingsDialog::GetFlatDirTextBox(flatFrameSettings.imageDir);

//  updateStatusInfo();
}


void UpdateStackSettings(void)
{
  char buffer[80];

  /* Get parms not already gotten */

  StackSettingsDialog::GetFrameTextBox(buffer);
  sscanf_s(buffer, "%d, %d, %d, %d", &stackSettings.x, &stackSettings.y,
	 &stackSettings.h, &stackSettings.w);

  StackSettingsDialog::GetNumFramesTextBox(buffer);
  sscanf_s(buffer, "%d", &stackSettings.numFrames);

  StackSettingsDialog::GetExpTimeTextBox(buffer);
  sscanf_s(buffer, "%f", &stackSettings.exposureTime);

  StackSettingsDialog::GetImageDirTextBox(stackSettings.imageDir);

//  updateStatusInfo();
}


bool setAlignStar(FRAME *frame, float *starX, float *starY) {
	
	char buffer[80];

	if (! PickAlignStarDialogExists) {
		gcnew PickAlignStarDialog();
	}

	PickAlignStarDialog::SetStarXTextBox("-999");
	PickAlignStarDialog::SetStarYTextBox("-999");
	PickAlignStarDialog::SetStarMaxTextBox("-999");

	CancelSetAlignStar = false;
	AlignStarFound = false;
	PickAlignStarDialog::FormPtr->ShowPickAlignStarDialog();

	do {
		usleep(100000);
	} while ((! AlignStarFound) && (! CancelSetAlignStar));

	if (CancelSetAlignStar) {
		return false;
	}
	PickAlignStarDialog::GetStarXTextBox(buffer);
	sscanf_s(buffer,"%f", starX);
	PickAlignStarDialog::GetStarYTextBox(buffer);
	sscanf_s(buffer,"%f", starY);

	return true;
}

bool findAlignStar(FRAME *frame, float starX, float starY, int *offsetX, int *offsetY) {
	
	bool Found;
	int xmin, xmax, ymin, ymax, max;
	float x, y;
	
	/* Define search region */
	
	xmin = (int) Math::Round(starX - 10);
	if (xmin < 0) 
		xmin = 0;
	xmax = (int) Math::Round(starX + 10);
	if (xmax > frame->w)
		xmax = frame->w;
	ymin = (int) Math::Round(starY - 10);
	if (ymin < 0)
		ymin = 0;
	ymax = (int) Math::Round(starY + 10);
	if (ymax > frame->h)
		ymax = frame->h;
	
	/* search for star in this region */
	
	Found = FindStar(frame, xmin, ymin, xmax, ymax, &x, &y, &max);
	if (Found) {
		*offsetX = (int) Math::Round(x - starX);
		*offsetY = (int) Math::Round(y - starY);
	}
	
	return Found;
}

void sumFrames(IMAGE *Image, IMAGE *workingImage, int offsetX, int offsetY)
{
  int h, w, x, y, newx, newy, ipix, newipix;
  FRAME *light, *workingLight;

  /* sum pixels from working Image into Image, after shifting by offset */

  h = Image->light_frame.h;
  w = Image->light_frame.w;
  light = &Image->light_frame;
  workingLight = &workingImage->light_frame;

  for (y=0; y<h; y++) {
    newy = y + offsetY;
    if ((newy >= 0) && (newy < h)) {
      for (x=0; x<w; x++) {
	newx = x + offsetX;
	if ((newx >= 0) && (newx < w)) {
	  //ipix = y * w + x;
	  ipix = XYtoPixel(light,x,y); // Changed to macro (doRoutines.h) ALS - 04-03-09
	  //newipix = newy*w + newx;
	  newipix = XYtoPixel(workingLight,newx,newy); // Changed to macro (doRoutines.h) ALS - 04-03-09
	  light->frame[ipix] += workingLight->frame[newipix];
	  if (Image->light_frame.frame[ipix] > 65000)
	    Image->light_frame.frame[ipix] = 65000;
	}
      }
    }
  }

  return;
}


bool FindStar(FRAME *frame, int x1, int y1, int x2, int y2,
	     float *starx, float *stary, int *starmax)
{
  int w, h, maxval, x, y, ipix, x0, y0;
  int yAtMax, xAtMax, pixval;
  int numpix;
  float sumx, sumy, sumval, val, r, aveval, background;
  float sigma, findRad;
  bool FoundStar;
//  PIXCELL *PixList;

  /* Max pixel value in region */

  FoundStar = false;
  w = frame->w;
  h = frame->h;
  x0 = frame->x;
  y0 = frame->y;
  findRad = (float) (x2-x1);
  if (x1 < 0)  x1 = 0;  if (x1 > w)  x1 = w;
  if (y1 < 0)  y1 = 0;  if (y1 > h)  y1 = h;
  if (x2 < 0)  x2 = 0;  if (x2 > w)  x2 = w;
  if (y2 < 0)  y2 = 0;  if (y2 > h)  y2 = h;
  maxval = -999;
  yAtMax = xAtMax = 0;
  for (x=x1; x<=x2; x++) {
	  for (y=y1; y<=y2; y++) {
		  //ipix =  (y-y0)* w + (x-x0);
		  ipix = XYtoPixel(frame,x,y); // Changed to macro (doRoutines.h) ALS - 04-03-09
		  if (ipix < 0)
			  continue;
		  pixval = frame->frame[ipix];
		  if (pixval > maxval) {
			  maxval = pixval;
			  xAtMax = x;
			  yAtMax = y;
		  }
	  }
  }
  if ((maxval < photometrySettings.minPeak) || (maxval > photometrySettings.maxPeak)) return false;
	  

  /* Compute "background" around max pixel (centered on max pixel */

  sumval = 0.0;
  numpix = 0;
  for (x=x1; x<=x2; x++) {
    for (y=y1; y<=y2; y++) {
      r = ((float) (x-xAtMax)*(x-xAtMax));
      if (r > 0.0) r = ((float) sqrt(r));
      if (r >= 8.0) {
		  //ipix = (y-y0) * w + (x-x0);
		  ipix = XYtoPixel(frame,x,y); // Changed to macro (doRoutines.h) ALS - 04-03-09
		  pixval = frame->frame[ipix];
		  sumval += ((float) pixval);
		  numpix++;
      }
    }
  }
  if (numpix > 0) {
    aveval = sumval / ((float) numpix);
  } else {
    aveval = 0.0;
  }
  background = aveval;
  if (background > 0.0)
    sigma = ((float) sqrt(background));
  else
    sigma = 1.0;

  /* compute centroid of "star" */

  sumval = 0.0; sumx = 0.0; sumy = 0.0;
//  PixList = NULL;

  for (x=xAtMax-(int)findRad; x<=xAtMax+(int)findRad; x++) {
    for (y=yAtMax-(int)findRad; y<=yAtMax+(int)findRad; y++) {
      if ((x >= x0) && (x < (x0+w)) && (y >= y0) && (y < (y0+h))) {
		  //ipix = (y-y0) * w + (x-x0);
		  ipix = XYtoPixel(frame,x,y); // Changed to macro (doRoutines.h) ALS - 04-03-09
		  pixval = frame->frame[ipix];
		  if (pixval > photometrySettings.maxPeak) return false;
		  val = ((float) pixval) - background;
//		  r = ((float) (x-xAtMax)*(x-xAtMax) + (y-yAtMax)*(y-yAtMax));
//		  if (r > 0.0) r = sqrt(r);
//		  putpix((float)val, (float)x, (float)y, (float)r, &PixList);
		  if (val > 2.0*sigma) {
			  sumx += val * x;
			  sumy += val * y;
			  sumval += val;
		  }
	  }
	}
  }


  if (sumval > 0) {
    *starx = sumx/sumval;
    *stary = sumy/sumval;
    *starmax = maxval;
    FoundStar = true;
  }

//  freepix(PixList);

  return FoundStar;
}

void freepix(PIXCELL *PixList)
{

  PIXCELL *pptr, *next;

  pptr = PixList;
  while (pptr != NULL) {
    next = pptr->next;
    free(pptr);
    pptr = next;
  }
  return;
}

void putpix(float val, float x, float y, float r, PIXCELL *(*PixList))
{
  PIXCELL *newptr, *endptr, *prevptr;

  newptr = (PIXCELL *) malloc(sizeof(PIXCELL));
  if (newptr == NULL) {
    printf("\n*** FATAL - Can't allocate memory for pixel list (putpix)");
    exit(-1);
  }
  newptr->x = x;
  newptr->y = y;
  newptr->r = r;
  newptr->val = val;
  newptr->next = NULL;
  if (*PixList == NULL) {
    *PixList = newptr;
  } else {
    endptr = *PixList;
    prevptr = NULL;
    do {
      if (endptr->r > r) {
	if (prevptr == NULL) {
	  newptr->next = *PixList;
	  *PixList = newptr;
	} else {
	  newptr->next = endptr;
	  prevptr->next = newptr;
	}
	break;
      } else {
	prevptr = endptr;
	endptr = endptr->next;
      }
    } while (endptr != NULL);

    if (endptr == NULL) {
      prevptr->next = newptr;
    }
  }
  return;
}

void putpixval(float val, float rawval, float x, float y, float r, PIXCELL *(*PixList))
{
  PIXCELL *newptr, *endptr, *prevptr;

  newptr = (PIXCELL *) malloc(sizeof(PIXCELL));
  if (newptr == NULL) {
    printf("\n*** FATAL - Can't allocate memory for pixel list (putpix)");
    exit(-1);
  }
  newptr->x = x;
  newptr->y = y;
  newptr->r = r;
  newptr->val = val;
  newptr->rawval = rawval;
  newptr->next = NULL;
  if (*PixList == NULL) {
    *PixList = newptr;
  } else {
    endptr = *PixList;
    prevptr = NULL;
    do {
      if (endptr->val > val) {
	if (prevptr == NULL) {
	  newptr->next = *PixList;
	  *PixList = newptr;
	} else {
	  newptr->next = endptr;
	  prevptr->next = newptr;
	}
	break;
      } else {
	prevptr = endptr;
	endptr = endptr->next;
      }
    } while (endptr != NULL);

    if (endptr == NULL) {
      prevptr->next = newptr;
    }
  }
  return;
}


void UpdateImage(void)
{
  char buffer[80];
  unsigned short *sp;
  int background, range, d, i, j, h, w;
  int x, y;
  float gamma;
  double f;
  Color pixel;

  h = ccd->Image.light_frame.h;
  w = ccd->Image.light_frame.w;
  x = ccd->Image.light_frame.x;
  y = ccd->Image.light_frame.y;

  CurrentImageWindow::FormPtr->GetCurrentImageBgndTextBox(buffer);
  sscanf_s(buffer, "%d", &background);

  CurrentImageWindow::FormPtr->GetCurrentImageRangeTextBox(buffer);
  sscanf_s(buffer, "%d", &range);

  CurrentImageWindow::FormPtr->GetCurrentImageGammaTextBox(buffer);
  sscanf_s(buffer, "%f", &gamma);
  if ((gamma < 0.01) || (gamma > 3.0)) {
    Form1::StatusPrint("*** Warning - Gamma out of range (0.01:3.0), "
		"using default of 0.33\n");
    gamma = (float) 0.33;
  }

  sp = ccd->Image.light_frame.frame;
  if (range <= 0) range = 10;
  if (background <= 0) background = 0;

//  for (j = y; j < h; ++j) {
  for (j = h-1; j >= 0; --j) {  // Reversed so that (0,0) origin in lower left instead of upper left ALS 04-03-09
    for (i = x; i < w; ++i) {
		f = ((double)*sp++ - background)/(range);
		if (f < 0.0) f=0.0;
		d = (int)(255.0*Math::Pow(f, (double)gamma));	// gamma correct
		if (d < 0)
			d = 0;
		else if (d > 255)
			d = 255;
		//if (*(sp-1) == 65000)
		//	pixel = Color::FromArgb(255,0,0);
		//else
		pixel = Color::FromArgb(d,d,d);
		CurrentImageWindow::FormPtr->CurrentImageBitmap->SetPixel(i,j,pixel);
	}
  }

  CurrentImageWindow::FormPtr->ClearMarkedStarList();
  CurrentImageWindow::FormPtr->Refresh();
//  CurrentImageWindow::ShowThisDialog();

}


void UpdateGuideImage(void) {

	unsigned short *sp;
	char buffer[80];
	int background, range, d, i, j, npixels, h, w;
	int x, y;
	float gamma;
	double f;
	IMAGE *Image;
	Color pixel;

	Image = &TrackingCCD.Image;
	
	h = Image->light_frame.h;
	w = Image->light_frame.w;
	x = Image->light_frame.x;
	y = Image->light_frame.y;
	
	npixels = h * w;
	GuideFrameWindow::FormPtr->GetBgndTextBox(buffer);
	sscanf_s(buffer, "%d", &background);
	GuideFrameWindow::FormPtr->GetRangeTextBox(buffer);
	sscanf_s(buffer, "%d", &range);
	GuideFrameWindow::FormPtr->GetGammaTextBox(buffer);
	sscanf_s(buffer, "%f", &gamma);
	if ((gamma < 0.01) || (gamma > 3.0)) {
		Form1::StatusPrint("*** Warning - Gamma out of range (0.01:3.0), "
			"using default of 0.33\n");
		gamma = (float) 0.33;
	}
	
	sp = Image->light_frame.frame;
	if (background == range)
		background--;
	
	for (j = y; j < h; ++j) {
		for (i = x; i < w; ++i) {
			f = ((double)*sp++ - background)/(range);
			if (f < 0.0) f=0.0;
			d = (int)(255.0*Math::Pow(f, (double)gamma));	// gamma correct
			if (d < 0)
				d = 0;
			else if (d > 255)
				d = 255;
			//if (*(sp-1) == 65000)
			//	pixel = Color::FromArgb(255,0,0);
			//else
			pixel = Color::FromArgb(d,d,d);

			GuideFrameWindow::FormPtr->Bitmap->SetPixel(i, j, pixel);
		}
	}

	GuideFrameWindow::FormPtr->RefreshImage();
	
	return;
}


void removeHotPixels(FRAME *light)
{
  char Message[160];
  int offset[8], ipix, numpix, pixval, j, jpix;
  int nearpix[8], npixels, i, numReplaced;
  float avep, sigp, numsig, sump, globalAvep;

  /* Remove "hot" pixels */

  npixels = light->w * light->h;
  offset[0] = - (light->w + 1); offset[1] = offset[0] + 1;
  offset[2] = offset[0] + 2;    offset[3] = -1;
  offset[4] = 1;                offset[5] = light->w - 1;
  offset[6] = light->w;         offset[7] = light->w + 1;

  // Compute global average

  numpix = 0;
  sump = 0.0;
  for (ipix=0; ipix<npixels; ipix++) {
    pixval = light->frame[ipix];
    if (pixval < 40000) {
      sump += pixval;
      numpix++;
    }
  }
  if (numpix > 0) {
    avep = sump / numpix;
  } else {
    avep = 0.0;
  }
  globalAvep = avep;

  // Replace extremely hot pixels with global average

  numReplaced = 0;
  for (ipix=0; ipix<npixels; ipix++) {
    pixval = light->frame[ipix];
    if ((pixval > 65000) || (pixval < 0)) {
      pixval = (int) Math::Round(globalAvep);
      light->frame[ipix] = pixval;
      numReplaced++;
    }
  }

  for (ipix=0; ipix<npixels; ipix++) {

    sump = 0.0;
    numpix = 0;
    pixval = light->frame[ipix];
    for (j=0; j<8; j++) {
      jpix = ipix + offset[j];
      if ((jpix >= 0) && (jpix < npixels)) {
	for (i=numpix-1; i>=0; i--) {
	  if (light->frame[jpix] > nearpix[i]) {
	    break;
	  } else {
	    nearpix[i+1] = nearpix[i];
	  }
	}
	nearpix[i+1] = light->frame[jpix];
	numpix++;
      }
    }

    if (numpix > 0) {
      avep = (float) nearpix[numpix/2];
      if (avep < 1.0) avep = 1.0;
      sigp = ((float) sqrt(avep));
      numsig = ((float) fabs(((float)pixval) - avep)/sigp);
    }
  }
  sprintf_s(Message,sizeof(Message),"*** Info: Replaced %d hot pixels in image\n",
			numReplaced);
  Form1::StatusPrint(Message);

  return;
}

bool establish_link(CCD *ccd, int Open) {
	
	char Message[160];
	int  status;
	bool success;
	
	// Establish link if requested to open & not already linked
	
	if (Open) {  //link
		if (strstr(ccd->name,"SBIG") != NULL) {
			status = pCam_EstablishLink(ccd->port);
			if (status == CE_NO_ERROR) {
				sprintf_s(Message, sizeof(Message), "*** INFO - Link Established to SBIG ccd "
					"on device %s\n", ccd->port);
				Form1::StatusPrint(Message);
				success = true;
			} else {
				sprintf_s(Message, sizeof(Message), "*** WARNING - Link Failed, code: %d\n", status);
				Form1::StatusPrint(Message);
				success = false;
			}
			ccd->make = SBIG_MAKE;
		} else if (strstr(ccd->name,"47p") != NULL) {
			success = apCam_EstablishLink();
			if (! success) {
				sprintf_s(Message, sizeof(Message), "*** Warning - Couldn't link to ccd %s on device %s\n",
					ccd->name, ccd->port);
				Form1::StatusPrint(Message);
			} else {
				sprintf_s(Message,sizeof(Message), "*** Info - Connected to ccd %s on device %s\n",	ccd->name, ccd->port);
				Form1::StatusPrint(Message);
			}
			ccd->make = APOGEE47P_MAKE;
		} else if (strstr(ccd->name,"U8300") != NULL) {
			success = altaCam_EstablishLink();
			if (! success) {
				sprintf_s(Message, sizeof(Message), "*** Warning - Couldn't link to ccd %s on device %s\n",
					ccd->name, ccd->port);
				Form1::StatusPrint(Message);
			} else {
				sprintf_s(Message,sizeof(Message), "*** Info - Connected to ccd %s on device %s\n",	ccd->name, ccd->port);
				Form1::StatusPrint(Message);
			}
			ccd->make = APOGEEU8300_MAKE;
		} else if ((strstr(ccd->name,"MX") != NULL) || (strstr(ccd->name,"SXV") != NULL)) { 
			strcpy_s(ccd->mx_sxv_info.filename, sizeof(ccd->mx_sxv_info.filename), "/dev/ccda");
			success = spCam_EstablishLink(ccd);
			if (! success) {
				sprintf_s(Message, sizeof(Message),	"*** Warning - Couldn't link to ccd %s on device %s\n",
					ccd->name, ccd->port);
				Form1::StatusPrint(Message);
			} else {
				sprintf_s(Message, sizeof(Message), "*** Info - Connected to ccd %s on device %s\n", ccd->name, ccd->port);
				Form1::StatusPrint(Message);
			}
			ccd->make = SXPRESS_MAKE;
		} else if (strstr(ccd->name,"Meade") != NULL) {
			success = LPI_EstablishLink(ccd);
			if (! success) {
				sprintf_s(Message, sizeof(Message),	"*** Warning - Couldn't link to ccd %s on device %s\n", 
					ccd->name, ccd->port);
				Form1::StatusPrint(Message);
			} else {
				sprintf_s(Message,sizeof(Message), "*** Info - Connected to ccd %s on device %s\n", ccd->name, ccd->port);
				Form1::StatusPrint(Message);
			}
			ccd->make = MEADE_MAKE;
		} else if (strstr(ccd->name,"Canon") != NULL) {
			success = Canon_EstablishLink(ccd);
			if (! success) {
				sprintf_s(Message, sizeof(Message),	"*** Warning - Couldn't link to ccd %s on device %s\n", 
					ccd->name, ccd->port);
				Form1::StatusPrint(Message);
			} else {
				sprintf_s(Message,sizeof(Message), "*** Info - Connected to ccd %s on device %s\n", ccd->name, ccd->port);
				Form1::StatusPrint(Message);
			}
			ccd->make = CANON_MAKE;
		} else if (strstr(ccd->name,"Pro V2.0") != NULL) {
			success = ssCam_EstablishLink();
			ccd->make = SSPRO_MAKE;
		} else if (strstr(ccd->name,"Autoguider") != NULL) {
			ccd->make = SSAG_MAKE;
		}
		if (ccd == &ImagingCCD) {
			ccd->Image.light_frame.frame = ImagingLightFrame; // use static frames
			ccd->Image.dark_frame.frame = ImagingDarkFrame;
			ccd->FlatImage.light_frame.frame = ImagingFlatLightFrame;
			ccd->FlatImage.dark_frame.frame = ImagingFlatDarkFrame;
		} else if (ccd == &SpectroCCD) {
			ccd->Image.light_frame.frame = SpectroLightFrame; // use static frames
			ccd->Image.dark_frame.frame = SpectroDarkFrame;
			ccd->FlatImage.light_frame.frame = SpectroFlatLightFrame;
			ccd->FlatImage.dark_frame.frame = SpectroFlatDarkFrame;
		} else if (ccd == &TrackingCCD) {
			ccd->Image.light_frame.frame = TrackingLightFrame; // use static frames
			ccd->Image.dark_frame.frame = TrackingDarkFrame;
			ccd->FlatImage.light_frame.frame = TrackingFlatLightFrame;
			ccd->FlatImage.dark_frame.frame = TrackingFlatDarkFrame;
		}
	
	} else { // unlink

		if (strstr(ccd->name,"SBIG") != NULL) {
			pCam_Unlink();
		} else if (strstr(ccd->name,"47p") != NULL) {
			apCam_Unlink();
		} else if (strstr(ccd->name,"U8300") != NULL) {
			altaCam_Unlink();
		} else if ((strstr(ccd->name,"MX") != NULL) || (strstr(ccd->port,"SXV") != NULL)) {
			spCam_Unlink(ccd);
		} else if (strstr(ccd->name,"Meade") != NULL) {
			LPI_Unlink(ccd);
		} else if (strstr(ccd->name,"Canon") != NULL) {
			Canon_Unlink(ccd);
		} else if (strstr(ccd->name,"Pro V2.0") != NULL) {
			ssCam_Unlink();
		} else if (strstr(ccd->name,"Autoguider") != NULL) {
		}
		success = true;
	}
	return success;
}



bool get_ccd_info(CCD *ccd) {

	char Message[240], statusString[80];
	int result;
	bool success;
	GetCCDInfoParams in;
	
	/* Get basic imaging ccd info */
	
	switch (ccd->make) {
		case SBIG_MAKE:
			in.request = 0;
			result = pCam_GetCCDInfo(&in, (void *)&ccd->info);
			if (result != CE_NO_ERROR) {
				Form1::StatusPrint(    "*** WARNING - Can't get basic imaging CCD info.\n");
				pCam_GetStatusString(statusString);
				sprintf_s(Message, sizeof(Message), "              [%d]: %s\n", result,
					statusString);
				Form1::StatusPrint(Message);
				return false;
			}
			in.request = 1;
			result = pCam_GetCCDInfo(&in, (void *)&ccd->info1);
			if (result != CE_NO_ERROR) {
				Form1::StatusPrint("*** WARNING - Can't get basic tracking CCD info...\n");
				pCam_GetStatusString(statusString);
				sprintf_s(Message, sizeof(Message), "              [%d]: %s\n", result,
					statusString);
				Form1::StatusPrint(Message);
				return false;
			}
			in.request = 2;
			pCam_GetCCDInfo(&in, (void *)&ccd->info2);
			if (result != CE_NO_ERROR) {
				Form1::StatusPrint("*** WARNING - Can't get extended CCD info...\n");
				pCam_GetStatusString(statusString);
				sprintf_s(Message, sizeof(Message), "              [%d]: %s\n", result,
					statusString);
				Form1::StatusPrint(Message);
				return false;
			}
			break;
		case APOGEE47P_MAKE:
			success = apCam_GetCCDInfo(&ccd->apogee_info);
			ccd->gain = ccd->apogee_info.Gain;
			break;
		case APOGEEU8300_MAKE:
			success = altaCam_GetCCDInfo(&ccd->apogee_info);
			ccd->gain = ccd->apogee_info.Gain;
			break;
		case SXPRESS_MAKE:
			success = spCam_GetCCDInfo(&ccd->mx_sxv_info);
			break;
		case MEADE_MAKE:
			success = LPI_GetCCDInfo(&ccd->meade_info);
			break;
		case CANON_MAKE:
			success = Canon_GetCCDInfo(&ccd->canon_info);
			break;
		case SSPRO_MAKE:
			success = ssCam_GetCCDInfo(&ccd->sspro_info);
			break;
		case SSAG_MAKE:
			break;
	}
	
	return success;
}
void GetCCDFrameSettings(CCD *ccd, int *x, int *y, int *w, int *h, int *b) {
	
	*x = 0;
	*y = 0;
	switch (ccd->make) {
		case SBIG_MAKE:
			*w = ccd->info.readoutInfo[*b].width;
			*h = ccd->info.readoutInfo[*b].height;
			break;
		case APOGEE47P_MAKE:
			*w = ccd->apogee_info.ImgColumns/(*b+1);
			*h = ccd->apogee_info.ImgRows/(*b+1);
			break;
		case APOGEEU8300_MAKE:
			*w = ccd->apogee_info.ImgColumns/(*b+1);
			*h = ccd->apogee_info.ImgRows/(*b+1);
			break;
		case SXPRESS_MAKE:
			*w = ccd->mx_sxv_info.width/(*b+1);
			*h = ccd->mx_sxv_info.height/(*b+1);
			break;
		case MEADE_MAKE:
			*w = ccd->meade_info.MaxColumns/(*b+1);
			*h = ccd->meade_info.MaxRows/(*b+1);
			break;
		case CANON_MAKE:
			*w = ccd->canon_info.MaxColumns;
			*h = ccd->canon_info.MaxRows;
			break;
		case SSPRO_MAKE:
			*w = ccd->sspro_info.CameraXSize;
			*h = ccd->sspro_info.CameraYSize;
			break;
		case SSAG_MAKE:
			*w = 0;
			*h = 0;
			break;
	}
	return;
}


bool ExposeSingleFrame(void) {
	
	static int Busy=false;
	int i, d;
	bool darkNeeded, gotFlat, gotDark, success;
	int hours, mins, isecs, degs, answer;
	char Message[160];
	float secs;
	double ccd_temp, dark_temp;
	OBJECT objectInfo;
	StartExposureParams expose;
	StartReadoutParams readout;
	
	if (!ccd->Linked) {
		Form1::StatusPrint("*** WARNING - Can't start exposure, link to camera first.\n");
		return false;
	}
	
	if (Busy) {
		Form1::StatusPrint("*** Warning - Imaging CCD is busy, try again later...\n");
		return false;
	}

	Busy = true;
	
	// Get telescopes current position
	
	if (GetScopeRADEC) {
		success = GetScopePosition(&ScopeRA, &ScopeDEC);
		if (! success) {
			success = GetObjectInfo(singleSettings.ObjectName, &objectInfo);
			if (success) {
				sscanf_s(objectInfo.ra,"%02d:%02d:%f", &hours, &mins, &secs);
				ScopeRA = hours + ((float) mins)/60.0 + secs/3600.0;
				sscanf_s(objectInfo.dec,"%02d:%02d:%02d", &degs, &mins, &isecs);
				ScopeDEC = degs + ((float) mins)/60.0 + ((float) isecs)/3600.0;
			}
		}
	}
	
	if ((! ccd->Image.saved) && (ccd->Image.light_frame.active) &&
		(! DontAskSaveImage)) {
		answer = MessageBox("Current Image Not Saved, saved it?", YESNO, true);
		if (answer == CANCEL) {
			Busy = false;
			return false;
		} else if (answer == YES) {
			Busy = false;
			return false;
		}
	}
	
	expose.ccd = singleSettings.whichCCD;
	expose.exposureTime = ((int) (100.0*singleSettings.exposureTime));
	expose.abgState = 0;
	readout.ccd = expose.ccd;
	readout.readoutMode = singleSettings.binning;
	readout.left = singleSettings.x;
	readout.top = singleSettings.y;
	readout.width = singleSettings.w;
	readout.height = singleSettings.h;
	
	success = GetCCDTemperature(ccd, &ccd_temp);
	if (! success) {
		Form1::StatusPrint("*** WARNING - Can't get ccd temperature, "
			"aborting exposure...\n");
		Busy = false;
		return false;
	}
	ccd->Image.darkOnly = false;
	ccd->Image.lightOnly = false;
	ccd->Image.light_frame.binning = singleSettings.binning;
	ccd->Image.light_frame.whichCCD = singleSettings.whichCCD;
	ccd->Image.light_frame.x = singleSettings.x;
	ccd->Image.light_frame.y = singleSettings.y;
	ccd->Image.light_frame.w = singleSettings.w;
	ccd->Image.light_frame.h = singleSettings.h;
	ccd->Image.light_frame.temp = (float) ccd_temp;
	ccd->Image.light_frame.exposure = singleSettings.exposureTime;
	ccd->Image.Filter[0] = filterSet[ccd->filterPosition-1];
	ccd->Image.Filter[1] = '\000';
	dark_temp = ccd->Image.dark_frame.temp;
	strcpy_s(ccd->Image.light_frame.UT,sizeof(ccd->Image.light_frame.UT),"");
	strcpy_s(ccd->Image.light_frame.UTDATE,sizeof(ccd->Image.light_frame.UTDATE),"");
	strcpy_s(ccd->Image.dark_frame.UT,sizeof(ccd->Image.dark_frame.UT),"");
	strcpy_s(ccd->Image.dark_frame.UTDATE,sizeof(ccd->Image.dark_frame.UTDATE),"");
	
	gotDark = false;
	switch (singleSettings.darkOption) {
		case 1:
			gotDark = true;
			break;
		case 2:
			gotDark = true;
			ccd->Image.lightOnly = false;
			break;
		case 3:
			gotDark = readDark(singleSettings.DarkDir, &ccd->Image);
			if (! gotDark) {
				sprintf_s(Message,sizeof(Message),"*** Warning - Couldn't find compatible dark frame"
					"in directory: %s aborting\n", singleSettings.DarkDir);
				Form1::StatusPrint(Message);
				Busy = false;
				return false;
			}
			dark_temp = ccd->Image.dark_frame.temp;
			ccd->Image.lightOnly = true;
			break;
		case 4:
			gotDark = false;
			ccd->Image.lightOnly = true;
			break;
	}
	
	gotFlat = false;
	switch (singleSettings.flatOption) {
		case 1:
			gotFlat = false;
			break;
		case 2:
			if ((singleSettings.binning == ccd->FlatImage.light_frame.binning) &&
				(singleSettings.whichCCD == ccd->FlatImage.light_frame.whichCCD) &&
				(singleSettings.x == ccd->FlatImage.light_frame.x) &&
				(singleSettings.y == ccd->FlatImage.light_frame.y) &&
				(singleSettings.h == ccd->FlatImage.light_frame.h) &&
				(singleSettings.w == ccd->FlatImage.light_frame.w)) {
					gotFlat = true;
			} else {
				sprintf_s(Message, sizeof(Message), "*** Warning - current flat frame not compatible"
					" with current settings\n");
				Form1::StatusPrint(Message);
				gotFlat = false;
			}
			break;
		case 3:
			gotFlat = readFlat(singleSettings.FlatDir, ccd);
			if (! gotFlat) {
				sprintf_s(Message, sizeof(Message), "*** Warning - couldn't find compatible flat"
					" frame in directory: %s, aborting\n", singleSettings.FlatDir);
				Form1::StatusPrint(Message);
				Busy = false;
				return false;
			}
			break;
	}
	
	/* allocate buffers */

//  nbytes = readout.width*readout.height*sizeof(short);
//  if (ccd->Image.light_frame.frame == NULL) {
//	ccd->Image.light_frame.frame = (unsigned short *)
//		realloc(ccd->Image.light_frame.frame, nbytes);
//  }
//  if (ccd->Image.dark_frame.frame == NULL) {
//	ccd->Image.dark_frame.frame = (unsigned short *)
//		realloc(ccd->Image.dark_frame.frame, nbytes);
//  }
 


  /* Check if dark frame needed */
	
	if ((singleSettings.darkOption == 1) ||
		(singleSettings.darkOption == 3)) {
			darkNeeded = ((fabs(dark_temp-ccd_temp) > MAXTEMPDIFF) ||
				(! ccd->Image.dark_frame.active) ||
				(ccd->Image.dark_frame.exposure !=
				singleSettings.exposureTime) ||
				(singleSettings.binning !=
				ccd->Image.dark_frame.binning) ||
				(singleSettings.whichCCD !=
				ccd->Image.dark_frame.whichCCD) ||
				(singleSettings.x != ccd->Image.dark_frame.x) ||
				(singleSettings.y != ccd->Image.dark_frame.y) ||
				(singleSettings.w != ccd->Image.dark_frame.w) ||
				(singleSettings.h != ccd->Image.dark_frame.h));
			darkNeeded = (darkNeeded || (! gotDark)); /* gotdark set by option 3 */
			if (darkNeeded) {
				gotDark = true;
				ccd->Image.lightOnly = false;
			} else 
				ccd->Image.lightOnly = true;
	}
	
	/* Do exposure */
	
	CancelCurrentAcquire = false;
	success = snapImaging(ccd, &expose, &readout, &ccd->Image);
	if (CancelCurrentAcquire || (! success)) {
		Busy = false;
		return false;
	}
	
	/* subtract out the dark, and adjust the image if required */
	
	if (gotDark) {
		for (i = readout.width*readout.height; --i >= 0; ) {
			d = ccd->Image.light_frame.frame[i] - ccd->Image.dark_frame.frame[i];
			if (d < 0)
				d = 0;
			else if (d > 65535)
				d = 65535;
			ccd->Image.light_frame.frame[i] = d;
		}
	}
	
	/* Flatten field if required */
	
	if (gotFlat) {
		flattenFrame(&ccd->Image.light_frame, &ccd->FlatImage.light_frame);
	} else {
		removeHotPixels(&ccd->Image.light_frame);  // else remove hot pixels
	}
	
	/* Display Image */
	
	loadImageImaging(ccd->Image.light_frame.frame, ccd->Image.light_frame.x,
		ccd->Image.light_frame.y, ccd->Image.light_frame.w,
		ccd->Image.light_frame.h, ccd->Image.light_frame.binning);
	
	CurrentImageWindow::ClearMarkedStarList();
	ccd->Image.saved = false;
	ccd->Image.Filter[0] = filterSet[ccd->filterPosition-1];
	ccd->Image.Filter[1] = '\000';
	strcpy_s(ccd->Image.FileName,sizeof(ccd->Image.FileName),"");
	strcpy_s(ccd->Image.ObjectName,sizeof(ccd->Image.ObjectName),singleSettings.ObjectName);
	
	Busy = false;
	return true;
}

bool ExposeSeriesFrames(void) {
  static int readoutTime[3]={60,20,10};

  char objectName[20], imageDir[80], Message[320];
  char FileName[160], buffer[120];
  __time64_t currentSeconds, startSeconds, endSeconds;
  struct tm startTime, broken_time;
  unsigned int ihours, imins, isecs;
  unsigned int nSequences, nFrames, nExposures;
  int d;
  int position, i, status, nfilters;
  int ifilter, idum;
  bool success, gotDark, gotFlat, darkNeeded;
  long int diff;
  float startHours, endHours, prevExposure;
  float duration, interval, sequenceDuration;
  float eTime;
  double ccd_temp, dark_temp, ddum;

  StartExposureParams expose;
  StartReadoutParams readout;
  FILTERSET filterSeq;
  OBJECT objectInfo;

  /* Init control flags */

  PauseSeries = false;
  StopSeries = false;

  /* Check if linked to camera */

  if (!ccd->Linked) {
    sprintf_s(Message, sizeof(Message), "Can't start series, link to camera first.\n");
	Form1::StatusPrint(Message);
    return false;
  }

  /* Get series parameters */

     /* Get object name & check if in data base */

  strcpy_s(objectName,sizeof(objectName),seriesSettings.objectName);
  status = GetObjectInfo(objectName, &objectInfo);
  if (status == -1) {
    sprintf_s(Message,sizeof(Message),"*** Warning - Can't find info on %s,"
	    " skipping object info...\n", objectName);
	Form1::StatusPrint(Message);
	Form1::StatusPrint("Object info won't be in output files\n");
  }

     /* Get image directory */

  strcpy_s(imageDir,sizeof(imageDir),seriesSettings.imageDir);

     /* start & end times */

  startHours = seriesSettings.startHours;
  endHours = startHours + seriesSettings.duration;
  duration = seriesSettings.duration;

  /* Sequence interval */
  
  interval = seriesSettings.interval;
  
  /* get input about which ccd and binning */
  
  expose.ccd = seriesSettings.whichCCD;
  readout.readoutMode = seriesSettings.binning;
  
  /* get info about size of frame */
  
  readout.ccd = seriesSettings.whichCCD;
  readout.left = seriesSettings.x;
  readout.top = seriesSettings.y;
  readout.height = seriesSettings.h;
  readout.width = seriesSettings.w;
  
  /* Compute sequence duration & # of sequences & frames */
  
  sequenceDuration = 0.0;
  prevExposure = 0.0;
  nfilters = 0;
  for (i=0; i<NUMFILTERS; i++) 
    if (seriesSettings.filterSeq.Use[i])
      nfilters++;
  
  for (i=0; i<NUMFILTERS; i++) {
    if (seriesSettings.filterSeq.Use[i]) {
      sequenceDuration += seriesSettings.filterSeq.exposures[i] +
			readoutTime[readout.readoutMode];
      if ((prevExposure != seriesSettings.filterSeq.exposures[i]) &&
		  (nfilters != 1)) {
		 sequenceDuration += filterSeq.exposures[i] +
			  readoutTime[readout.readoutMode];  /* dark frame */
      }
    }
    prevExposure = seriesSettings.filterSeq.exposures[i];
  }
  sequenceDuration /= 3600.0;
  
  if (nfilters == 1) {
    nSequences = (unsigned int )
      (((duration-seriesSettings.filterSeq.exposures[0]/3600.0) /
	(interval/3600.0+sequenceDuration)));
  } else {
    nSequences = (unsigned int) (duration / (interval/3600.0+sequenceDuration));
  }
  nFrames = nSequences * nfilters;
  
  /* Let user review parameters */
  
  sprintf_s(Message,sizeof(Message), "Your series is:\n"
	  "  Start Time:     %f (hours)\n"
	  "  End Time:       %f (hours)\n"
	  "  Duration:       %f (hours)\n"
	  "  Interval:       %f (seconds)\n"
	  "  # of sequences: %d\n"
	  "  # of frames:    %d\n"
	  "  Binning:        %d\n"
	  "  Frame Size:     %d x %d\n",
	  startHours, endHours, duration, interval,
	  nSequences, nFrames, readout.readoutMode, readout.width,
	  readout.height);
  Form1::StatusPrint(Message);
  sprintf_s(Message,sizeof(Message),"Using filters: \n");
  Form1::StatusPrint(Message);
  for (i=0; i<NUMFILTERS; i++) {
    if (seriesSettings.filterSeq.Use[i]) {
      sprintf_s(Message,sizeof(Message)," Filter: %c  -  Exposure: %f (secs)\n",
	      filterSet[i], seriesSettings.filterSeq.exposures[i]);
	  Form1::StatusPrint(Message);
    }
  }
  
  /* setup dark frame options */

  ccd->Image.darkOnly = false;
  ccd->Image.lightOnly = false;
  ccd->Image.light_frame.binning = seriesSettings.binning;
  ccd->Image.light_frame.whichCCD = seriesSettings.whichCCD;
  ccd->Image.light_frame.x = seriesSettings.x;
  ccd->Image.light_frame.y = seriesSettings.y;
  ccd->Image.light_frame.w = seriesSettings.w;
  ccd->Image.light_frame.h = seriesSettings.h;
  
  gotDark = false;
  switch (seriesSettings.darkOption) {
    case 1:
      gotDark = ccd->Image.dark_frame.active;
      break;
    case 2:
      gotDark = false;
      ccd->Image.lightOnly = false;
      break;
    case 3:
      ccd->Image.lightOnly = true;
      break;
    case 4:
      gotDark = false;
      ccd->Image.lightOnly = true;
      break;
  }
  
  gotFlat = false;
  switch (seriesSettings.flatOption) {
    case 1:
      gotFlat = false;
      break;
    case 2:
      if ((seriesSettings.binning == ccd->FlatImage.light_frame.binning) &&
	      (seriesSettings.whichCCD == ccd->FlatImage.light_frame.whichCCD) &&
	      (seriesSettings.x == ccd->FlatImage.light_frame.x) &&
	      (seriesSettings.y == ccd->FlatImage.light_frame.y) &&
	      (seriesSettings.h == ccd->FlatImage.light_frame.h) &&
	      (seriesSettings.w == ccd->FlatImage.light_frame.w)) {
		 gotFlat = true;
      } else {
		 sprintf_s(Message, sizeof(Message), "*** Warning - current flat frame not compatible"
		            " with current settings\n");
		 Form1::StatusPrint(Message);
		 gotFlat = false;
      }
      break;
    case 3:
      break;
  }
  
  /* allocate buffers */

//ALS  nbytes = readout.width*readout.height*sizeof(short);
//  ccd->Image.light_frame.frame = (unsigned short *)
//    realloc(ccd->Image.light_frame.frame, nbytes);
//  ccd->Image.dark_frame.frame = (unsigned short *)
//    realloc(ccd->Image.dark_frame.frame, nbytes);

  /* Start series */

     /* Convert times to seconds from epoch */

  _time64(&currentSeconds);
  _localtime64_s(&broken_time, &currentSeconds);

  ihours = ((int) startHours);
  imins  = ((int) ((startHours-ihours)*60.0));
  isecs  = ((int) ((startHours-ihours-imins/60.0)*3600.0));
  startTime.tm_hour = ihours;
  startTime.tm_min  = imins;
  startTime.tm_sec  = isecs;
  startTime.tm_mday  = broken_time.tm_mday;
  startTime.tm_mon  = broken_time.tm_mon;
  startTime.tm_year = broken_time.tm_year;
  startSeconds = _mktime64(&startTime);
  endSeconds = (__time64_t) (startSeconds + duration*3600.0);

  /* Wait for start of series, if required */

  if (! seriesSettings.StartSeriesASAP) {
    diff = ((int) (startSeconds - currentSeconds));
    if (diff > 0.0) {
      ihours = ((int) (diff/3600.0));
      imins = ((int) ((diff - ihours*3600.0)/60.0));
      isecs = ((int) (diff - ihours*3600.0 - imins*60.0));
      sprintf_s(Message, sizeof(Message), "%02d:%02d:%02d until start...\n",
				ihours, imins, isecs);
	  Form1::StatusPrint(Message);
    }
    
	Form1::SetCurrentSeriesStatusTextBox("Waiting to start...");
    while (currentSeconds < startSeconds) {
      diff = (int) (startSeconds - currentSeconds);
      ihours = ((int) (diff/3600.0));
      imins = ((int) ((diff - ihours*3600.0)/60.0));
      isecs = ((int) (diff - ihours*3600.0 - imins*60.0));
      fflush(stdout);
      if (diff < 121.0) {
		 if (diff%10 == 0) {
			sprintf_s(Message, sizeof(Message), "%02d:%02d:%02d left until start...\n",
					ihours, imins, isecs);
			Form1::StatusPrint(Message);
		 }
		 usleep(1000000);
      } else {
		 if (diff%60 == 0) {
			sprintf_s(Message, sizeof(Message), "%02d:%02d:%02d left until start...\n",
					  ihours, imins, isecs);
			Form1::StatusPrint(Message);
		 }
		 usleep(1000000);
      }
      _time64(&currentSeconds);
	  
			/* Check for user intervention */

      if (StopSeries) {  // Set by button click routine
	    SeriesStarted = false;
	    return true;
      }
    }
  } else {
	  _time64(&startSeconds);
	  endSeconds = (__time64_t) (startSeconds + duration*3600.0);
  }

  sprintf_s(Message, sizeof(Message), "Starting series...\n");
  Form1::StatusPrint(Message);
  Form1::SetCurrentSeriesStatusTextBox("Running...");

  nExposures = 0;
  nSequences = seriesSettings.startSeqNum;
  expose.abgState = 0;
  SeriesStarted = true;
  if (seriesSettings.AutoBumpScope)
    baseStarList = NULL;
  do {

	sprintf_s(buffer, sizeof(buffer), "%d", nSequences);
	Form1::CCDAutoForm->SetProcessingSeqNumTextBox(buffer);

       /* Loop over filters in sequence */

    for (ifilter=0; ifilter<NUMFILTERS; ifilter++) {

      sprintf_s(buffer, sizeof(buffer), "%d", nExposures+1);
	  Form1::CCDAutoForm->SetProcessingExpNumTextBox(buffer);

      /* Check for user intervention */

      if (StopSeries) {  // Set by button click routine
	    SeriesStarted = false;
	    return true;
      }

      while (PauseSeries) {  // Set by button click routine
	     if (StopSeries) {
	        SeriesStarted = false;
	        return true;
	     }
		 usleep(100000);
      }
	 
      if (! seriesSettings.filterSeq.Use[ifilter]) continue;

      /* Position filter wheel */

      position = ifilter+1;
      doFilterWheel(ccd, &status, position);
	  updateStatusInfo();

      /* Check if dark frame needed */

      ccd_temp = 0.0;
      eTime = seriesSettings.filterSeq.exposures[ifilter];
      if ((seriesSettings.darkOption == 1) ||
	      (seriesSettings.darkOption == 3)) {
		success = GetCCDTemperature(ccd, &ccd_temp);
		if (! success) {
			Form1::StatusPrint("*** WARNING - Can't get ccd temperature...\n");
		  SeriesStarted = false;
		  return true;
		}
		ccd->Image.light_frame.temp = (float) ccd_temp;
      }
      if (seriesSettings.darkOption == 1) {
		dark_temp = ccd->Image.dark_frame.temp;
		darkNeeded = ((fabs(dark_temp-ccd_temp) > MAXTEMPDIFF) ||
		              (! ccd->Image.dark_frame.active) ||
		              (ccd->Image.dark_frame.exposure != eTime) ||
		              (seriesSettings.binning != ccd->Image.dark_frame.binning) ||
		              (seriesSettings.whichCCD != ccd->Image.dark_frame.whichCCD) ||
					  (seriesSettings.x != ccd->Image.dark_frame.x) ||
					  (seriesSettings.y != ccd->Image.dark_frame.y) ||
					  (seriesSettings.w != ccd->Image.dark_frame.w) ||
					  (seriesSettings.h != ccd->Image.dark_frame.h));
		if (darkNeeded) {
		  ccd->Image.lightOnly = false;
		} else {
		  ccd->Image.lightOnly = true;
		}
		gotDark = true;
      } else if (seriesSettings.darkOption == 3) {
		ccd->Image.light_frame.exposure = eTime;
		gotDark = readDark(seriesSettings.DarkDir, &ccd->Image);
		if (! gotDark) {
		  sprintf_s(Message, sizeof(Message), "*** Warning - Couldn't find compatible dark frame"
											  " in directory: %s, forcing dark frame\n", seriesSettings.DarkDir);
		  Form1::StatusPrint(Message);
		  ccd->Image.lightOnly = false;
		  gotDark = true;
		} else {
		  ccd->Image.lightOnly = true;
		}
      }

      /* Take exposure */

      sprintf_s(Message, sizeof(Message), "Taking frame #%d (%c,%f)\n", ++nExposures, filterSet[position-1], eTime);
	  Form1::StatusPrint(Message);
      expose.exposureTime = (int)(100.0*eTime);
      time(&ccd->Image.light_frame.time);
      DontShowImageProgress = true;
      CancelCurrentAcquire = false;
      success = snapImaging(ccd, &expose, &readout, &ccd->Image);
      DontShowImageProgress = false;
      if (CancelCurrentAcquire || (! success)) {
		SeriesStarted = false;
		return true;
      }

      /* update image parameters */

      ccd->Image.saved = false;
	  strcpy_s(ccd->Image.FileName, sizeof(ccd->Image.FileName),"");
	  strcpy_s(ccd->Image.ObjectName,sizeof(ccd->Image.ObjectName), seriesSettings.objectName);

	  /* Save raw image before calibrations if required */

      ccd->Image.Filter[0] = filterSet[position-1];
      ccd->Image.Filter[1] = '\000';
	  if (seriesSettings.SaveRawImages) {
		  sprintf_s(FileName, sizeof(FileName), "%s/%s%03d%craw.fits", imageDir, objectName,
			  nSequences, filterSet[position-1]);
		  sprintf_s(Message, sizeof(Message), "Writing image to file: %s\n", FileName);
		  Form1::StatusPrint(Message);
		  strcpy_s(ccd->Image.light_frame.UT, sizeof(ccd->Image.light_frame.UT), "");
		  strcpy_s(ccd->Image.light_frame.UTDATE,sizeof(ccd->Image.light_frame.UTDATE), "");
		  writeFITS(&ccd->Image, 1, FileName, objectName);
		  ccd->Image.saved = true;
		  strcpy_s(ccd->Image.FileName, sizeof(ccd->Image.FileName), FileName);
		  Form1::CCDAutoForm->SetCurrentSeriesFileNameTextBox(FileName);
	  }

      /* subtract out the dark, and adjust the image if required */

      if (gotDark) {
		for (i = readout.width*readout.height; --i >= 0; ) {
		  d = ccd->Image.light_frame.frame[i] - ccd->Image.dark_frame.frame[i];
		  if (d < 0) {
			d = 0;
		  } else if (d > 65535) {
			d = 65535;
		  }
		  ccd->Image.light_frame.frame[i] = d;
		}
      }

      /* Flatten frame if required */

      if (seriesSettings.flatOption == 3) {
		gotFlat = readFlat(seriesSettings.FlatDir, ccd);
		if (! gotFlat) {
		  sprintf_s(Message, sizeof(Message),
			  "*** Warning - couldn't find compatible flat frame in directory: %s, aborting...\n",
			  seriesSettings.FlatDir);
		  Form1::StatusPrint(Message);
		  return true;
		}
      }
      if (gotFlat) {
		flattenFrame(&ccd->Image.light_frame, &ccd->FlatImage.light_frame);
      }

      /* Display Image */

      loadImageImaging(ccd->Image.light_frame.frame, ccd->Image.light_frame.x,
		       ccd->Image.light_frame.y, ccd->Image.light_frame.w,
		       ccd->Image.light_frame.h,
		       ccd->Image.light_frame.binning);
	  CurrentImageWindow::ClearMarkedStarList();
	  if (CurrentImageWindowExists)
		  RefreshCurrentImageWindow();

      /* Write out image */

	  if (! seriesSettings.SaveRawImages) {
		  sprintf_s(FileName, sizeof(FileName), "%s/%s%03d%c.fits", imageDir, objectName,
			  nSequences, filterSet[position-1]);
		  sprintf_s(Message, sizeof(Message), "Writing image to file: %s\n", FileName);
		  Form1::StatusPrint(Message);
		  strcpy_s(ccd->Image.light_frame.UT, sizeof(ccd->Image.light_frame.UT), "");
		  strcpy_s(ccd->Image.light_frame.UTDATE,sizeof(ccd->Image.light_frame.UTDATE), "");
		  writeFITS(&ccd->Image, 1, FileName, objectName);
		  ccd->Image.saved = true;
		  strcpy_s(ccd->Image.FileName, sizeof(ccd->Image.FileName), FileName);
		  Form1::CCDAutoForm->SetCurrentSeriesFileNameTextBox(FileName);
	  }

      /* Do auto photometry if requested */

      if (photometrySettings.autoFind) {
		success = updateListStars(&ccd->Image, CurrentStarList);
		if (! success) {
			sprintf_s(buffer, sizeof(buffer),
				"*** WARNING - Couldn't update stars' positions, \n"
				"              Skipping image # %d\n", nSequences);
			Form1::StatusPrint(buffer);
		}
		success = measureListStars(&ccd->Image, CurrentStarList);
		if (! success) {
		  sprintf_s(buffer, sizeof(buffer),
				"*** WARNING - Couldn't measure stars in frame\n"
		        "              Skipping frame # %d\n", nSequences);
		  Form1::StatusPrint(buffer);
		} else if (seriesSettings.AutoBumpScope) {
		  AutoBumpScope(CurrentStarList);
		}
      }
    }

    /* Tell user time left in series */

    nSequences++;
    _time64(&currentSeconds);
    if (currentSeconds < startSeconds)
      currentSeconds += 86400;
    diff = (int) (endSeconds-currentSeconds);
    if (diff > 0.0) {
      ihours = ((int) (diff/3600.0));
      imins = ((int) ((diff - ihours*3600.0)/60.0));
      isecs = ((int) (diff - ihours*3600.0 - imins*60.0));
      sprintf_s(Message, sizeof(Message), "%02d:%02d:%02d left in series...\n", 
	      ihours, imins, isecs);
	  Form1::StatusPrint(Message);
      sprintf_s(Message, sizeof(Message), "%02d:%02d:%02d", ihours, imins, isecs);
	  Form1::CCDAutoForm->SetTimeToSeriesEndTextBox(Message);
    } else {
      break;
    }

    /* Wait until time for next sequence */

	if (seriesSettings.interval > 0.0) {
		interval = seriesSettings.interval;
      sprintf_s(Message, sizeof(Message), "Sequence done, sleeping for %6.2f seconds\n",
	      interval);
	  Form1::StatusPrint(Message);
      do {

		  /* Check for user intervention */

		  if (StopSeries) {  // Set by button click routine
			  SeriesStarted = false;
			  return true;
		  }
		  while (PauseSeries) { // Set by button click routine
			  if (StopSeries) {
				  SeriesStarted = false;
				  return true;
			  }
			  usleep(100000);
		  }
		  sprintf_s(Message, sizeof(Message), "%6.1f", interval);
		  Form1::CCDAutoForm->SetTimeToNextExpTextBox(Message);
		  usleep(1000000);
		  interval--;
	  } while (interval > 0);
      
    }
    
  } while (currentSeconds < endSeconds);

  sprintf_s(Message, sizeof(Message), "Finished %d exposures...\n", nExposures);
  Form1::StatusPrint(Message);
  SeriesStarted = false;
  Form1::SetCurrentSeriesStatusTextBox("Not Running...");

  // Check if need to close observatory

  if (seriesSettings.CloseObservatoryWhenDone)
	  SendOSUrobMessage('C', &idum, &ddum);

  return true;
}

bool measureListStars(IMAGE *Image, STAR *List) {
	
	STAR *sptr, *sptr_var, *sptr_comp, *sptr_check;
	char buffer[240], ImageFileName[160], *cptr, *dotptr;
	int starNum, c, status, AnyStarFailed, GroupNum;
	OBJECT objectInfo;
	double JD, HJD, x, y;
	float AirMass, sumFWHM, aveFWHM;
	
	if (List == NULL) return true;  // No stars in list
	
	c = '\\';
	
	// Set image file name for photometry listing
	
	strcpy_s(buffer, sizeof(buffer), Image->FileName);
	if (strlen(buffer) <= 0) {
		strcpy_s(ImageFileName, sizeof(ImageFileName), "NotSaved");
	} else {
		cptr = strrchr(buffer, c);
		if (cptr != NULL) {
			strcpy_s(ImageFileName, sizeof(ImageFileName), cptr+1);
		} else {
			strcpy_s(ImageFileName, sizeof(ImageFileName), buffer);
		}
	}
	
	// Get time and airmass parms
	
	status = GetObjectInfo(Image->ObjectName, &objectInfo);
	if (status) {
		CalcObsParms(&AirMass, &JD, &HJD, &objectInfo, &ObsSettings, Image->light_frame.UT, Image->light_frame.UTDATE,
			Image->light_frame.exposure);
	} else {
		AirMass = 999.0;
		JD = 999.0;
		HJD = 999.0;
	}
	
	// Compute average FWHM (from PSF) to set aperature radius if necessary
	
	sumFWHM = 0.0;
	sptr = List;
	starNum = 1;
	if (photometrySettings.AperatureScaledToFWHM) {
		sptr = List;
		sumFWHM = 0.0;
		while (sptr != NULL) {
			doPhotometry(&ccd->Image, CURRENTIMAGEWINDOW, sptr->x, sptr->y, sptr->max, true, &sptr->fwhm,
				&sptr->skyFlux, &sptr->flux, &sptr->mag, &sptr->magErr);
			if ((sptr->fwhm < photometrySettings.minFWHM) || (sptr->fwhm > photometrySettings.maxFWHM)) {
				AnyStarFailed = true;
			} else {
				sumFWHM += sptr->fwhm;
				starNum++;
			}
			sptr = sptr->next;
		}
		if (starNum > 1) {
			aveFWHM = sumFWHM/(starNum-1);
			sprintf_s(buffer, sizeof(buffer), "*** Info - Average FWHM is %7.3f pixels\n", aveFWHM);
			Form1::StatusPrint(buffer);
		} else {
			aveFWHM = sumFWHM;
		}
		photometrySettings.aperatureRadius = aveFWHM * photometrySettings.ApFWHMScale;
	}
	
	AnyStarFailed = false;
	sumFWHM = 0.0;
	sptr = List;
	starNum = 1;
	while (sptr != NULL) {
		doPhotometry(&ccd->Image, CURRENTIMAGEWINDOW, sptr->x, sptr->y, sptr->max, false, &sptr->fwhm,
			&sptr->skyFlux, &sptr->flux, &sptr->mag, &sptr->magErr);
		if (ccd->Image.plateSolution.status == 0) {
			Pixel2Equatorial((double) sptr->x, (double) sptr->y, &x, &y);
		} else {
			x = sptr->x;
			y = sptr->y;
		}
		sprintf_s(buffer, sizeof(buffer), "%3d %8s %13.5lf %10.6lf %10.6lf %8.0f %8.0f %5.1f %7.3f +/- %6.3f %6.4f %s %20s\n",
			starNum, Image->light_frame.UT, HJD, x, y, sptr->skyFlux, sptr->flux, sptr->fwhm, sptr->mag, sptr->magErr,
			AirMass, Image->Filter, ImageFileName);
		Form1::StatusPrint(buffer);
		if ((sptr->fwhm < photometrySettings.minFWHM) || (sptr->fwhm > photometrySettings.maxFWHM) || (sptr->mag < 0.0)) {
			Form1::StatusPrint("*** WARNING - Skipping measurement of above star...\n");
			AnyStarFailed = true;
			sptr = sptr->next;
			continue;
		}
		sumFWHM += sptr->fwhm;
		if (photometrySettings.logCCDAutoFormat) {  // CCDAuto Format
			sprintf_s(buffer, sizeof(buffer), "%3d\t%8s\t%13.5lf\t%10.6lf\t%10.6lf\t%8.0f\t%8.0f\t"
				"%5.1f\t%7.3f\t%6.3f\t%6.4f\t%s\t%20s\n", starNum, Image->light_frame.UT, HJD, x, y, sptr->skyFlux,
				sptr->flux, sptr->fwhm, sptr->mag, sptr->magErr, AirMass, Image->Filter, ImageFileName);
			fprintf(photometrySettings.logCCDAutoFilePtr, "%s", buffer);
			fflush(photometrySettings.logCCDAutoFilePtr);
		}
		if (photometrySettings.logAAVSOFormat) {  // AAVSO format
			if (photometrySettings.AAVSOPrintHeading) {
				fprintf(photometrySettings.logAAVSOFilePtr, "#TYPE=%s\n", AAVSOTYPE);
				fprintf(photometrySettings.logAAVSOFilePtr, "#OBSCOD=%s\n", AAVSOOBSCOD);
				fprintf(photometrySettings.logAAVSOFilePtr, "#SOFTWARE=%s\n", AAVSOSOFTWARE);
				fprintf(photometrySettings.logAAVSOFilePtr, "#DELIM=%s\n", AAVSODELIM);
				fprintf(photometrySettings.logAAVSOFilePtr, "#DATE=%s\n", AAVSODATE);
				fprintf(photometrySettings.logAAVSOFilePtr, "#OBSTYPE=%s\n", AAVSOOBSTYPE);
				fprintf(photometrySettings.logAAVSOFilePtr, "#%s",
					"NAME,DATE,MAG,MERR,FILT,TRANS,MTYPE,CNAME,CMAG,KNAME,KMAG,AMASS,GROUP,CHART,NOTES\n");
				fflush(photometrySettings.logAAVSOFilePtr);
				photometrySettings.AAVSOPrintHeading = false;
			}
			if (starNum == 1) {
				sptr_var = sptr;
				sptr_comp = sptr->next;
				if (sptr_comp == NULL) {
					MessageBox("Warning - Need to have comp star for AAVSO format!", OKAY, true);
					return false;
				}
				sptr_check = sptr_comp->next;
				if (sptr_check == NULL) {
					MessageBox("Warning - Need to have check star for AAVSO format!", OKAY, true);
					return false;
				}
				dotptr = strstr(Image->FileName,"raw.fits");
				if (dotptr == NULL)
					dotptr = strstr(Image->FileName,".fits");
				sscanf_s(dotptr-3, "%3d", &GroupNum);
				sprintf_s(buffer, sizeof(buffer), "%s,%13.5lf,%7.3f,%6.3f,%s,%s,%s,%s,%7.3f,%s,%7.3f,%6.4f,%d,%s,%s\n",
					photometrySettings.AAVSOVarStarID, HJD, sptr_var->mag, sptr_var->magErr, Image->Filter, "NO", "ABS",
					photometrySettings.AAVSOCompStarID, sptr_comp->mag, photometrySettings.AAVSOCheckStarID,
					sptr_check->mag, AirMass, GroupNum, photometrySettings.AAVSOChartDate, "na");
				fprintf(photometrySettings.logAAVSOFilePtr, "%s", buffer);
				fflush(photometrySettings.logAAVSOFilePtr);
			}
		}
		if (photometrySettings.plotResults && (! AnyStarFailed)) {
			AddToPhotPlot(starNum, sptr, Image->light_frame.UT, HJD, Image->Filter[0]);
		}
		sptr = sptr->next;
		starNum++;
	}
	if (starNum > 1) {
		aveFWHM = sumFWHM/(starNum-1);
		sprintf_s(buffer, sizeof(buffer), "*** Info - Average FWHM is %7.3f pixels\n", aveFWHM);
		Form1::StatusPrint(buffer);
	}
	if (photometrySettings.plotResults && (! AnyStarFailed))
		AddToPhotPlot(0, sptr, Image->light_frame.UT, HJD, Image->Filter[0]);  /* Display plot */
	
	return (! AnyStarFailed);
}


void doPhotometry(IMAGE *Image, short Window, float starX, float starY, int max, bool JustPSF,
		  float *FWHM, float *SkyFlux, float *StarFlux,
		  float *Magnitude, float *MagErr)
{
  FRAME *light, *dark;
  unsigned int rx, ry;
  int imageMinX, imageMaxX, imageMinY, imageMaxY;
  int minX, maxX, minY, maxY, x, y, ipix, pixval, centerVal;
  int numPixels, w, h, ntries, hours, degs, mins;
  float r, val, medianSky, sigma, error, fitMax, fitFWHM, fitX, fitY, rmin, secs;
  float medianSkyRaw, StarFluxRaw, SkyFluxRaw, rawval;
  char buffer[80];
  PIXCELL *PixList, *pptr, *prev, *next;
  double ra, dec;

  /* Default values */

  *FWHM = -999.0;
  *SkyFlux = -999.0;
  *StarFlux = -999.0;
  *Magnitude = (float) -99.999;
  *MagErr = (float) -9.999;

  /* Get needed image parameters */

  light = &Image->light_frame;
  dark  = &Image->dark_frame;
  h = Image->light_frame.h;
  w = Image->light_frame.w;
  imageMinX = Image->light_frame.x;
  imageMaxX = Image->light_frame.x + w;
  imageMinY = Image->light_frame.y;
  imageMaxY = Image->light_frame.y + h;

  /* Get needed photometry parameters */

  minX = (int) (starX - photometrySettings.skyOuterRadius + 1);
  if (minX < imageMinX) minX = imageMinX;
  maxX = (int) (starX + photometrySettings.skyOuterRadius + 1);
  if (maxX > imageMaxX) maxX = imageMaxX;

  minY = (int) (starY - photometrySettings.skyOuterRadius + 1);
  if (minY < imageMinY) minY = imageMinY;
  maxY = (int) (starY + photometrySettings.skyOuterRadius + 1);
  if (maxY > imageMaxY) maxY = imageMaxY;

  /* Find median sky pixel value (1st with no cuts) */

  PixList = NULL;
  numPixels = 0;
  for (x=minX; x<=maxX; x++) {
    for (y=minY; y<=maxY; y++) {
      //ipix = (y-imageMinY) * w + (x-imageMinX);
      ipix = XYtoPixel(light,x,y); // Changed to macro (doRoutines.h) ALS - 04-03-09
      pixval = light->frame[ipix];
	  rawval = 0;
	  if (dark != NULL)
		  rawval = dark->frame[ipix];
	  if ((rawval > 0) && (rawval < 32767))
		  rawval += pixval;
	  else
		  rawval = (float) (pixval + 1400+ccd->Image.light_frame.exposure*0.1); // guesstimate of dark+bias
      r = (x-starX)*(x-starX) + (y-starY)*(y-starY);
      if (r > 0.0) r = ((float) sqrt(r));
      if ((r >= photometrySettings.skyInnerRadius) &&
	      (r <= photometrySettings.skyOuterRadius)) {
		val = ((float) pixval);
		putpixval(val, rawval, (float) x, (float) y, r, &PixList);
		numPixels++;
      }
    }
  }
  if (numPixels <= 0) {
	  Form1::StatusPrint("*** WARNING - No pixels in sky annulus...\n");
    return;
  } else {
    pptr = PixList;
    for (ipix=0; ipix<(numPixels/2); ipix++) {
      pptr = pptr->next;
    }
    medianSky = pptr->val;
  }

  /* Find median sky pixel value (now with cuts) */

  pptr = PixList;
  prev = NULL;
  while (pptr != NULL) {
    val = pptr->val;
    if (val > 0.0)
      sigma = ((float) sqrt(val));
    else
      sigma = 1.0;
    if (fabs(val-medianSky)/sigma > photometrySettings.skySigmaCut) {
		if (prev == NULL) {
			PixList = pptr->next;
			next = pptr->next;
		} else {
			prev->next = pptr->next;
			next = pptr->next;
		}
		free(pptr);
		numPixels--;
		pptr = next;
	} else {
		prev = pptr;
		pptr = pptr->next;
	}
  }
  if (numPixels <= 0) {
	  Form1::StatusPrint("*** WARNING - No pixels in sky annulus (after cuts)...\n");
    return;
  } else {
    pptr = PixList;
    for (ipix=0; ipix<(numPixels/2); ipix++) {
      pptr = pptr->next;
    }
    medianSky = pptr->val;
	medianSkyRaw = pptr->rawval;
  }


  /* Fit PSF */

  freepix(PixList);
  PixList = NULL;
  numPixels = 0;
  rmin = 99999.0;
  for (x=minX; x<=maxX; x++) {
    for (y=minY; y<=maxY; y++) {
      //ipix = (y-imageMinY) * w + (x-imageMinX);
	  ipix = XYtoPixel(light,x,y); // Changed to macro (doRoutines.h) ALS - 04-03-09
      pixval = light->frame[ipix];
      r = (x-starX)*(x-starX) + (y-starY)*(y-starY);
      if (r > 0.0) r = ((float) sqrt(r));
      if (r <= photometrySettings.skyOuterRadius) {
		val = ((float) pixval) - medianSky;
		putpix(val, (float) x, (float) y, r, &PixList);
		numPixels++;
		if (r < rmin) {
			rmin = r;
			centerVal = pixval;
		}
      }
    }
  }

  /* If valid data for star, fit PSF */

  if (numPixels > 0) {
	  ntries = 0;
	  do {
		  rand_s(&rx);
		  rand_s(&ry);
		  fitX = ((float) (starX + ntries*(((double) UINT_MAX) - 2*rx)/UINT_MAX));
		  fitY = ((float) (starY + ntries*(((double) UINT_MAX) - 2*ry)/UINT_MAX));
		  //fitX = starX + ntries;
		  //fitY = starY + ntries;
		  fitMax = (float) centerVal;
//		  fitMax = (float) max;
		  FitPSF(PixList, &fitMax, &fitFWHM, &fitX, &fitY);
		  if ((fitFWHM >= photometrySettings.minFWHM) && (fitFWHM <= photometrySettings.maxFWHM))
			  break;
		  ntries++;
	  } while (ntries < 5);
	  *FWHM = fitFWHM;
	  starX = fitX;
	  starY = fitY;
	  
		// Recompute r distribution w/ new fitted x & y

	  freepix(PixList);
	  PixList = NULL;
	  numPixels = 0;
	  rmin = 99999.0;
	  for (x=minX; x<=maxX; x++) {
		  for (y=minY; y<=maxY; y++) {
			  //ipix = (y-imageMinY) * w + (x-imageMinX);
			  ipix = XYtoPixel(light,x,y); // Changed to macro (doRoutines.h) ALS - 04-03-09
			  pixval = light->frame[ipix];
			  r = (x-starX)*(x-starX) + (y-starY)*(y-starY);
			  if (r > 0.0) r = ((float) sqrt(r));
			  if (r <= photometrySettings.skyOuterRadius) {
				  val = ((float) pixval) - medianSky;
				  putpix(val, (float) x, (float) y, r, &PixList);
				  numPixels++;
				  if (r < rmin) {
					  rmin = r;
					  centerVal = pixval;
				  }
			  }
		  }
	  }
  }

  if (JustPSF)
	  return;

  /* Find star flux */

  numPixels = 0;
  *StarFlux = StarFluxRaw = 0.0;
  for (x=minX; x<=maxX; x++) {
    for (y=minY; y<=maxY; y++) {
      //ipix = (y-imageMinY) * w + (x-imageMinX);
	  ipix = XYtoPixel(light,x,y); // Changed to macro (doRoutines.h) ALS - 04-03-09
      pixval = light->frame[ipix];
	  rawval = 0;
	  if (dark != NULL)
		  rawval = dark->frame[ipix];
	  if ((rawval > 0) && (rawval < 32767))
		  rawval += pixval;
	  else
		  rawval = (float) (pixval + 1400+ccd->Image.light_frame.exposure*DEFAULTU8300DARKNOISE); // guesstimate of dark+bias
      r = (x-starX)*(x-starX) + (y-starY)*(y-starY);
      if (r > 0.0) r = ((float) sqrt(r));
      if (r <= photometrySettings.aperatureRadius) {
	     *StarFlux += ((float) pixval);
		 StarFluxRaw += ((float) rawval);
	     numPixels++;
      }
    }
  }

  /* compute sky flux inside star aperature */

  *SkyFlux = medianSky * numPixels;
  SkyFluxRaw = medianSkyRaw * numPixels;

  //  *SkyFlux = medianSky * (3.14159 * photometrySettings.aperatureRadius *
  //			  photometrySettings.aperatureRadius);

  /* Subtract sky flux from star */

  *StarFlux -= *SkyFlux;
  if (*StarFlux <= 0.0) {
	  Form1::StatusPrint("*** WARNING - star flux <= 0.0 in photometry...\n");
    return;
  }

  /* Convert star flux to magnitude */

  *Magnitude = (float) (photometrySettings.zeroPoint - 2.5 * log10(*StarFlux) +
    2.5 * log10(Image->light_frame.exposure));

//  error = (float) sqrt(*StarFlux/ccd->gain + *SkyFlux/ccd->gain);
  error = (float) sqrt(StarFluxRaw*ccd->gain + SkyFluxRaw*ccd->gain + ccd->readNoise*ccd->readNoise);
//  *MagErr = (float) (error / (*StarFlux*ccd->gain));
  *MagErr = (float) (2.5*log10(1.0 + error / (*StarFlux*ccd->gain)));

  /* Show results on current image window, Guiding window, or astrometry window */

  switch (Window) {
	  case CURRENTIMAGEWINDOW:
		  sprintf_s(buffer, sizeof(buffer), "%5.1f", *FWHM);
		  CurrentImageWindow::FormPtr->SetCurrentImageFWHMTextBox(buffer);
		  sprintf_s(buffer, sizeof(buffer), "%8.0f", *StarFlux);
		  CurrentImageWindow::FormPtr->SetCurrentImageStarFluxTextBox(buffer);
		  sprintf_s(buffer, sizeof(buffer), "%8.0f", *SkyFlux);
		  CurrentImageWindow::FormPtr->SetCurrentImageSkyFluxTextBox(buffer);
		  sprintf_s(buffer, sizeof(buffer), "%6.3f", *Magnitude);
		  CurrentImageWindow::FormPtr->SetCurrentImageMagTextBox(buffer);
		  sprintf_s(buffer, sizeof(buffer), "%7.2f", fitX);
		  CurrentImageWindow::FormPtr->SetCurrentImageStarXTextBox(buffer);
		  sprintf_s(buffer, sizeof(buffer), "%7.2f", fitY);
		  CurrentImageWindow::FormPtr->SetCurrentImageStarYTextBox(buffer);
		  if (Image->plateSolution.status == 0) {
			  Pixel2Equatorial((double) fitX, (double) fitY, &ra, &dec);
			  ConvertRAtoHMS(ra, &hours, &mins, &secs);
			  sprintf_s(buffer, sizeof(buffer), "%02d:%02d:%04.2f", hours, mins, secs);
			  CurrentImageWindow::FormPtr->SetCurrentImageRATextBox(buffer);
			  ConvertDECtoDMS(dec, &degs, &mins, &secs);
			  sprintf_s(buffer, sizeof(buffer), "%03d:%02d:%04.2f", degs, mins, secs);
			  CurrentImageWindow::FormPtr->SetCurrentImageDECTextBox(buffer);
		  }

		  /* Show PSF plot if requested */
		  
		  if (CurrentImageWindow::FormPtr->PlotCheckBoxChecked()) {
			  DisplayPSF(PixList, fitMax, fitFWHM);
		  }
		  CurrentImageWindow::MarkStar(starX, starY);
		  break;
	  case GUIDEIMAGEWINDOW:
		  sprintf_s(buffer, sizeof(buffer), "%5.1f", *FWHM);
		  GuideFrameWindow::FormPtr->SetFWHMTextBox(buffer);
		  sprintf_s(buffer, sizeof(buffer), "%7.2f", fitX);
		  GuideFrameWindow::FormPtr->SetStarXTextBox(buffer);
		  sprintf_s(buffer, sizeof(buffer), "%7.2f", fitY);
		  GuideFrameWindow::FormPtr->SetStarYTextBox(buffer); 
		  
		  /* Show PSF plot if requested */
		  
		  if (GuideFrameWindow::FormPtr->PlotCheckBoxChecked()) {
			  DisplayPSF(PixList, fitMax, fitFWHM);
		  }
		  GuideFrameWindow::FormPtr->MarkStar(starX, starY);
		  break;
	  case ASTROMETRYWINDOW:
		  sprintf_s(buffer, sizeof(buffer), "%6.2f", *FWHM);
		  AstrometryWindow::FormPtr->SetObjectFWHMTextBox(buffer);
		  sprintf_s(buffer, sizeof(buffer), "%6.3f+/-%5.3f", *Magnitude, *MagErr);
		  AstrometryWindow::FormPtr->SetObjectMagTextBox(buffer);

		  /* Show PSF plot if requested */
		  
		  if (CurrentImageWindow::FormPtr->PlotCheckBoxChecked()) {
			  DisplayPSF(PixList, fitMax, fitFWHM);
		  }
		  AstrometryWindow::FormPtr->MarkStar(starX, starY);
		  break;
  }

  freepix(PixList);

  return;
}

bool FitPSF(PIXCELL *PixList, float *fitMax, float *fitFWHM, float *fitX, float *fitY) {

	int NumPoints, i, Success;
	static double covar[4][4], alpha[4][4], parms[4];
	static double chisq, ochisq, alambda;
	float x[2000], y[2000], val[2000], sig[2000], delx, dely;
	PIXCELL *pptr;

	pptr = PixList;
	i = 0;
	while (pptr != NULL) {
		delx = pptr->x - *fitX;
		dely = pptr->y - *fitY;
		if (delx*delx+dely*dely < 10.0) {
			x[i] = pptr->x;
			y[i] = pptr->y;
			val[i] = pptr->val;
			if (pptr->val > 1.0)
				sig[i] = ((float) sqrt(pptr->val));
			else
				sig[i] = 1.0;
			i++;
			if (i > 1999) {
				break;
			}
		}
		pptr = pptr->next;
	}
	NumPoints = i;
	parms[0] = *fitX;    // Starting x & y values to fit
	parms[1] = *fitY;
	parms[2] = 2.0;      // Starting sigma;
	parms[3] = *fitMax;  // Starting content;

	alambda = -1.0;
	Success = mrqmin(x,y,val,sig,NumPoints,parms,covar,alpha,&chisq,&alambda);
	if (! Success) {
		Form1::StatusPrint("*** Warning - PSF Fit failed...\n");
		return false;
	}

	do {
		ochisq = chisq; 
		Success = mrqmin(x,y,val,sig,NumPoints,parms,covar,alpha,&chisq,&alambda);
		if (! Success) {
			Form1::StatusPrint("*** Warning - PSF Fit failed...\n");
			return false;
		}
	} while (((chisq>=ochisq) || (fabs(ochisq-chisq)>1.0)) &&
			 (fabs(log10(alambda)) < 30.0));

	alambda = 0.0;
	Success = mrqmin(x,y,val,sig,NumPoints,parms,covar,alpha,&chisq,&alambda);
	if (! Success) {
		Form1::StatusPrint("*** Warning - PSF Fit failed...\n");
		return false;
	}
	*fitMax = (float) parms[3];
	*fitFWHM = (float) (parms[2]*2.34);
	*fitX = (float) parms[0];
	*fitY = (float) parms[1];

	return true;
}

void funcs(float x, float y, double a[4], double *zmod, double dzda[4])
{
  double argx, argy, expx, expy, argx2, argy2;

  argx = (x-a[0])/a[2];
  argx2 = argx*argx;
  argy = (y-a[1])/a[2];
  argy2 = argy*argy;
  if (fabs(argx) > 5.0)
    expx = 0.0;
  else
    expx = exp(-0.5*argx2);
  if (fabs(argy) > 5.0)
    expy = 0.0;
  else
    expy = exp(-0.5*argy2);
  *zmod = a[3]/(PI2*a[2]*a[2])*expx*expy;
  dzda[0] = argx/a[2] * *zmod;
  dzda[1] = argy/a[2] * *zmod;
  dzda[2] = *zmod/a[2]*(argx2 + argy2 - 2.0);
  dzda[3] = *zmod/a[3];
}

#define PI2  6.28318530718


int mrqmin(float x[], float y[], float z[], float sig[], int ndata,
	    double a[4], double covar[4][4], double alpha[4][4],
	    double *chisq, double *alambda)

/* Levenberg-Marquardt Method:  attempting to reduce the value of Chi-sq of a
fit between a set of data points x[1..ndata], y[1...ndata], and z[1..ndata]
with individual standard deviations sig[1..ndata], and a nonlinear function
dependent on ma coefficients a[1..ma].  The input array ia[1..ma] indicates
by non-zero entries those components of a that should be fitted for, and by
zero entries those components which should be held fixed at their input values.
The routine returns current best-fit values for the parameters a[1..ma], and
chisq.  The arrays covar[1..ma][1..ma], alpha[1..ma][1..ma] are used as
working space during most iterations.  Supply a routine
funcs(x,y,a,zfit,dzda,ma) that evaluates the fitting function, yfit, its
derivatives dyda[1..ma] with respect to the fitting parameters a at (x,y). On
the first call provide an initial guess for the parameters a, and set alamda
< 0 for initialization (which then sets alambda = 0.001).  If a step succeeds
chisq becomes smaller and alambda decreases by a factor of 10.  If a step
fails alambda grows by a factor of 10.  You must call this routine repeatedly
until convergence is achieved.  Then make one final call with alambda=0, so
that covar[1..ma][1..ma] returns the covariance matrix, and alpha the
curvature matrix.  (Parameters held fixed will return zero covariances)
NOTE: modified for only 4 parameters */

{
  void covsrt(float **covar, int ma, int ia[], int mfit); 

  int j,k;
  static double ochisq, atry[4], beta[4], da[4], oneda[4][4];
  float temp;

  if (*alambda < 0.0) {            /* Initialization */
    *alambda = 1.0;
    mrqcof(x,y,z,sig,ndata,a,alpha,beta,chisq);
    ochisq = *chisq;
    atry[0] = a[0];
    atry[1] = a[1];
    atry[2] = a[2];
    atry[3] = a[3];
    for (j=0; j<4; j++)
      for (k=0; k<4; k++) oneda[j][k] = 0.0;
  }
  temp = (float) (1.0 + *alambda);
  for (j=0; j<4; j++) {
    for (k=0; k<4; k++) covar[j][k] = alpha[j][k];
    covar[j][j] *= temp;
    oneda[j][0] = beta[j];
  }
  if (! gaussj(covar,oneda)) {  /* terminate fit */
    return false;
  }
  da[0] = oneda[0][0];
  da[1] = oneda[1][0];
  da[2] = oneda[2][0];
  da[3] = oneda[3][0];
  if (*alambda == 0.0) {
    /* covsrt(covar); */
    return true;
  }
  atry[0] = a[0] + da[0];
  atry[1] = a[1] + da[1];
  atry[2] = fabs(a[2]+da[2]);
  atry[3] = a[3] + da[3];
  mrqcof(x,y,z,sig,ndata,atry,covar,da,chisq);
  if (*chisq < ochisq) {
    *alambda *= 0.1;
    ochisq = *chisq;
    for (j=0; j<4; j++) {
      for (k=0; k<4; k++) alpha[j][k] = covar[j][k];
      beta[j] = da[j];
    }
    a[0] = atry[0];
    a[1] = atry[1];
    a[2] = atry[2];
    a[3] = atry[3];
  } else {
    *alambda *= 10.0;
    *chisq = ochisq;
  }
  return true;
}

void mrqcof(float x[], float y[], float z[], float sig[], int ndata,
	    double a[4], double alpha[4][4], double beta[4], double *chisq)
{
  int i,j,k;
  double zmod,wt,sig2i,dz,dzda[4];

  for (j=0; j<4; j++) {
    for (k=0; k<=j; k++) alpha[j][k] = 0.0;
    beta[j] = 0.0;
  }
  *chisq = 0.0;
  for (i=0; i<ndata; i++) {
    funcs(x[i],y[i],a,&zmod,dzda);
    /*    if ((zmod < 0.5) && (z[i]< 0.5)) continue;*/
    sig2i = sig[i];
    dz = z[i] - zmod;
    for (j=0; j<4; j++) {
      wt = dzda[j]*sig2i;
      for (k=0; k<=j; k++) alpha[j][k] += wt*dzda[k];
      beta[j] += dz*wt;
    }
    *chisq += dz*dz*sig2i;
  }
  for (j=1; j<4; j++)
    for (k=0; k<j; k++) alpha[k][j] = alpha[j][k];
}


#define SWAP(a,b) {temp=(a);(a)=(b);(b)=temp;}

int gaussj(double a[4][4], double b[4][4])
{
  static int indxc[4]={0}, indxr[4]={0}, ipiv[4]={0};
  static int i, icol, irow, j, k, l, ll;
  static double big, dum, pivinv, temp;

  ipiv[0] = 0;
  ipiv[1] = 0;
  ipiv[2] = 0;
  ipiv[3] = 0;

  for (i=0; i<4; i++) {
    big = 0.0;
    for (j=0; j<4; j++)
      if (ipiv[j] != 1)
	for (k=0; k<4; k++) {
	  if (ipiv[k] == 0) {
	    if (fabs(a[j][k]) > big) {
	      big = fabs(a[j][k]);
	      irow = j;
	      icol = k;
	    }
	  } else if (ipiv[k] > 1) {
	    /*	    printf("\ngaussj: Singular Matrix-1"); */
	    return false;
	  }
	}
    ++(ipiv[icol]);
    if (irow != icol) {
      for (l=0; l<4; l++) SWAP(a[irow][l],a[icol][l]);
      for (l=0; l<4; l++) SWAP(b[irow][l],b[icol][l]);
    }
    indxr[i] = irow;
    indxc[i] = icol;
    if (a[icol][icol] == 0.0) {
      /*      printf("\ngaussj: Singular Matrix-2"); */
      return false;
    }
    pivinv = 1.0/a[icol][icol];
    a[icol][icol] = 1.0;
    for (l=0; l<4; l++) a[icol][l] *= pivinv;
    for (l=0; l<4; l++) b[icol][l] *= pivinv;
    for (ll=0; ll<4; ll++)
      if (ll != icol) {
	dum = a[ll][icol];
	a[ll][icol] = 0.0;
	for (l=0; l<4; l++) a[ll][l] -= a[icol][l]*dum;
	for (l=0; l<4; l++) b[ll][l] -= b[icol][l]*dum;
      }
  }
  for (l=3; l>=0; l--) {
    if (indxr[l] != indxc[l])
      for (k=0; k<4; k++)
	SWAP(a[k][indxr[l]],a[k][indxc[l]]);
  }
  return true;
}

void AutoBumpScope(STAR *starList)
{
  char Message[160];
  STAR *sptr, *bptr, *ptr;
  int numStars;
  double delXSum, delYSum, DeltaRA, DeltaDEC, deltaX, deltaY;

  // If 1st time, define base star positions & exit (no bump 1st time)

  Form1::StatusPrint("*** DEBUG - Starting AutoBumpScope\n");
  if (baseStarList == NULL) {
	  Form1::StatusPrint("*** DEBUG - Saving base star list\n");
	  sptr = starList;
      while (sptr != NULL) {
		  bptr = (STAR *) malloc(sizeof(STAR));
		  if (bptr == NULL) {
			  Form1::StatusPrint("*** Warning - Can' allocate memory for star list,"
									  "AutoBump scope is turned off\n");
			  seriesSettings.AutoBumpScope = false;
			  return;
		  }
		  memcpy(bptr, sptr, sizeof(STAR));
		  bptr->next = NULL;
		  bptr->prev = NULL;
		  if (baseStarList == NULL) {
			  baseStarList = bptr;
		  } else {
			  ptr = baseStarList;
			  while (ptr->next != NULL) {
				  ptr = ptr->next;
			  }
			  ptr->next = bptr;
			  bptr->prev = ptr;
		  }
		  sptr = sptr->next;
	  }
	  Form1::StatusPrint("*** DEBUG - Got AutoBumpScope\n");
  } else {

    // Computer average star offset in current frame

    bptr = baseStarList;
    sptr = starList;

    delXSum = 0.0;
    delYSum = 0.0;
    numStars = 0;
	Form1::StatusPrint("*** DEBUG - Computing average offset\n");
    while (sptr != NULL) {
      delXSum += sptr->x - bptr->x;
      delYSum += bptr->y - sptr->y;
      numStars++;
      bptr = bptr->next;
      sptr = sptr->next;
    }

    // Average & Covert to arcsecs;

    if (numStars > 0) {
      deltaX = delXSum / numStars;
      deltaY = delYSum / numStars;
    } else {
      deltaX = 0.0;
      deltaY = 0.0;
    }
	sprintf_s(Message, sizeof(Message), "*** DEBUG - Offsets: %d %f %f\n",
			  numStars, deltaX, deltaY);
	Form1::StatusPrint(Message);

    DeltaRA = (deltaX*GuidingSlitSettings.XScale)/cos(ScopeDEC*3.14159/180.0);
    DeltaDEC = (deltaY*GuidingSlitSettings.YScale);

	sprintf_s(Message, sizeof(Message), "*** DEBUG - Offsets(arcsec): %d %f %f\n",
			  numStars, DeltaRA, DeltaDEC);
	Form1::StatusPrint(Message);

    // Move scope

//    SendTCS200Step(DeltaRA, DeltaDEC);
//    RunMainIteration(5.0);  // wait 5 secs
  }

  return;
}

void AddToPhotPlot(int starNum, STAR *sptr, char *UT, double HJD, char Filter)
{
  static int nPoints=0;
  static DIFFPHOT *List=NULL, *dptr;
  DIFFPHOT *pptr;
  int hour, min, sec;
  float UTTime;

  if (! PhotometryPlotWindowExists) {
	  gcnew PhotometryPlotWindow();
	  PhotometryPlotWindow::FormPtr->ShowTheDialog();
  }

  if (starNum < 0) {  // Close plot if open & do hardcopy
//	  PhotometryPlotWindow::HideTheDialog();
	  if (strcmp(photometrySettings.plotHardcopyType, "none") != 0) {
		  if (strcmp(photometrySettings.plotHardcopyType,"postscript file") == 0) {
			  // set device to postscript file
		  } else if (strcmp(photometrySettings.plotHardcopyType,"gif file") == 0) {
			  // set device to gif file
		  }
		  // do the plot here
          // DoPhotPlot(List, 0);
          // DoPhotPlot(List, 1);
	  }
	  pptr = List;
	  while (pptr != NULL) {
		  dptr = pptr->next;
		  free(pptr);
		  pptr = dptr;
	  }
	  nPoints = 0;
	  return;
  }

  switch (starNum) {

    case 0:  /* Update plots */
		PhotometryPlotWindow::FormPtr->AddGraphPoint(dptr);
      break;

    case 1:  /* Save Variable star magnitude */
      dptr = (DIFFPHOT *) malloc(sizeof(DIFFPHOT));
      if (dptr == NULL) {
		  Form1::CCDAutoForm->StatusPrint("*** WARNING - Can't allocate memory for diff photo.\n");
		  photometrySettings.plotResults = false;
      } else {
		  dptr->VarMag = sptr->mag;
		  dptr->VarMagErr = sptr->magErr;
		  dptr->Filter = Filter;
	  }
      break;      

    case 2:  /* Save Comparison star magnitude */
      dptr->CmpMag = sptr->mag;
      dptr->CmpMagErr = sptr->magErr;
      break;

    case 3:  /* Save Check star magnitude */
      dptr->ChkMag = sptr->mag;
      dptr->ChkMagErr = sptr->magErr;
      sscanf_s(UT, "%2d:%2d:%2d", &hour, &min, &sec);
      UTTime = (float) (((float) hour) + ((float) min)/60.0 + ((float) sec)/3600.0);
      dptr->UT = UTTime;
      dptr->HJD = HJD;
      dptr->next = NULL;
      dptr->prev = NULL;
      if (List == NULL) {
		  List = dptr;
      } else {
		  pptr = List;
		  while (pptr->next != NULL) {
			  pptr = pptr->next;
		  }
		  pptr->next = dptr;
		  dptr->prev = pptr;
      }
      nPoints++;
      break;
  }
  return;
}

void flattenFrame(FRAME *light, FRAME *flat)
{
  int ipix, npixels;

  npixels = flat->h*flat->w;

  /* Flatten light frame */

  for (ipix=0; ipix<npixels; ipix++) {
    light->frame[ipix] =  (unsigned short)
		Math::Round(light->frame[ipix]/(((float)flat->frame[ipix])/10000.0));
  }

  /* Remove "hot" pixels */

  removeHotPixels(light);

  return;
}

bool updateListStars(IMAGE *Image, STAR *List)
{
  char buffer[160];
  STAR *sptr;
  FRAME *frame;
  float starX, starY, findRad;
  int xmin, xmax, ymin, ymax;
  float x, y;
  int max, starNum;
  bool Found;

  frame = &Image->light_frame;
  sptr = List;
  findRad = photometrySettings.findRadius;

  starNum = 1;
  while (sptr != NULL) {
    starX = sptr->x;
    starY = sptr->y;
    xmin = (int) Math::Round(starX - findRad);
    xmax = (int) Math::Round(starX + findRad);
    ymin = (int) Math::Round(starY - findRad);
    ymax = (int) Math::Round(starY + findRad);
    Found = FindStar(frame, xmin, ymin, xmax, ymax, &x, &y, &max);
    if (! Found) {
      sprintf_s(buffer, sizeof(buffer), "*** WARNING - Can't find star #%d at (%7.2f,%7.2f)\n",
	      starNum, starX, starY);
	  Form1::StatusPrint(buffer);
	  //answer = MessageBox("Can't find star, still want to continue?", YESNO, true);
	  //if (answer != YES) {
		 // Form1::StatusPrint(    "      Terminating list measurement for this image\n");
		 // return false;
	  //}
	  sptr = sptr->next;
	  continue;
    } else if ((fabs(starX-x) > findRad) || (fabs(starY-y) > findRad)) {
      sprintf_s(buffer, sizeof(buffer), "*** WARNING - Star #%d at (%7.2f,%7.2f) shifted by: "
	      " (%5.1f,%5.1f)\n",
	      starNum, starX, starY, (starX-x), (starY-y));
	  Form1::StatusPrint(buffer);
	  //answer = MessageBox("Star shifted, still want to continue?", YESNO, true);
	  //if (answer != YES) {
		 // Form1::StatusPrint(    "      Terminating list measurement for this image\n");
		 // return false;
	  //}
	  sptr = sptr->next;
	  continue;
    } else {
      sprintf_s(buffer, sizeof(buffer),
	      "*** INFO - Updated position for star #%d is: (%7.2f,%7.2f)\n",
	      starNum, x, y);
	  Form1::StatusPrint(buffer);
      sptr->x = x;
      sptr->y = y;
      sptr->max = max;
    }
    sptr = sptr->next;
    starNum++;
  }

  Form1::StatusPrint("*** INFO - Finished updating star list positions...\n");
  return true;
}


void DisplayPSF(PIXCELL *PixList, float fitMax, float fitFWHM)
{
  PIXCELL *pptr;
  float xData[2000], yData[2000], maxval, maxr, r;
  float xFit[200], yFit[200];
  int i, numDataPts, numFitPts;

  // Find max and min x & y

  pptr = PixList;
  maxval = -999.0;
  maxr = -999.0;
  i = 0;
  while (pptr != NULL) {
      if (pptr->val > maxval) {
	maxval = pptr->val;
      }
      if (pptr->r > maxr) {
	maxr = pptr->r;
      }
      yData[i] = pptr->val;
      xData[i++] = pptr->r;
      pptr = pptr->next;
  }
  numDataPts = i;


  i = 0;
  for (r=0.0; r<maxr; r += (float) (maxr/100.0)) {
    xFit[i] = r;
    yFit[i++] = gaussian(((double) fitMax), ((double) fitFWHM/2.34), r);
  }
  numFitPts = i;

  if (! PlotWindowExists)
		gcnew DataPlotWindow();

  DataPlotWindow::FormPtr->xData = xData;
  DataPlotWindow::FormPtr->yData = yData;
  DataPlotWindow::FormPtr->numDataPts = numDataPts;
  DataPlotWindow::FormPtr->xFit = xFit;
  DataPlotWindow::FormPtr->yFit = yFit;
  DataPlotWindow::FormPtr->numFitPts = numFitPts;
  DataPlotWindow::FormPtr->XAxisLabel = gcnew String("Distance from Centroid (pixels)");
  DataPlotWindow::FormPtr->YAxisLabel = gcnew String("Pixel value (ADC units)");
  DataPlotWindow::FormPtr->XName = gcnew String("Star PSF Data");
  DataPlotWindow::FormPtr->YName = gcnew String("Star PSF Fit");
  DataPlotWindow::FormPtr->PlotTitle = gcnew String("Star Point Spread Function Plot");

  DataPlotWindow::FormPtr->ShowTheDialog();

//  DataPlotWindow::FormPtr->GraphData(numDataPts, xData, yData, numFitPts, xFit, yFit);

//  DataPlotWindow::FormPtr->ShowTheDialog();

	//  cpgline(i, xs, ys);
//  sprintf(buffer, "Max: %6.0f, FHWM: %6.2f", fitMax, fitFWHM);
//  cpgtext(8.0, maxval*0.75, buffer);

//  r = (float) (maxval/2.0);
//  cpgtext(10.0, r, "Type q to close plot"); 
  
//  do {
//    cpgcurs(&x, &y, &ch);
//  } while ((ch != 'q') && (ch != 'Q'));

//  cpgclos(); */

  return;

}

float gaussian(double fitMax, double sigma, float r)
{
  double arg, norm;
  float g;

  arg = r / sigma;
  norm = PI*2.0*sigma*sigma;

  g = (float) (fitMax/norm * exp(- 0.5 * arg*arg));

  return g;
}

void ShowDefineListDialog(void) {

	STAR *save_sptr, *list_sptr, *sptr;

	// Create dialog if doesn't exist

	if (! DefineListDialogExists)
		gcnew DefineListDialog();

	// Save "old" star list in case of "cancel"

	if (CurrentStarList != NULL) {
		save_sptr = (STAR *) malloc(sizeof(STAR));
		if (save_sptr == NULL) {
			Form1::CCDAutoForm->StatusPrint("*** WARNING - Can't allocate memory for 'saved' star list...\n");
		} else {
			CurrentStarListSave = save_sptr;
			list_sptr = CurrentStarList;
			memcpy_s(save_sptr, sizeof(STAR), list_sptr, 1);
			save_sptr->next = save_sptr->prev = NULL;
			while (list_sptr->next != NULL) {
				list_sptr = list_sptr->next;
				sptr = (STAR *) malloc(sizeof(STAR));
				if (sptr == NULL) {
					Form1::CCDAutoForm->StatusPrint("*** WARNING - Can't allocate memory for 'saved' star list...\n");
					break;
				}
				memcpy_s(sptr, sizeof(STAR), list_sptr, 1);
				save_sptr->next = sptr;
				sptr->prev = save_sptr;
				sptr->next = NULL;
				save_sptr = sptr;
			}
		}
	}

	DefineListDialog::FormPtr->ShowTheDialog();
}

bool AddStar(void) {

	char buffer[160];
	STAR *sptr, *ptr;
	float min;

	sptr = (STAR *) malloc(sizeof(STAR));
	if (sptr == NULL) {
		Form1::CCDAutoForm->StatusPrint("*** WARNING - Can't allocate memory for new star...\n");
		return false;
	}
	
	CurrentImageWindow::GetCurrentImageStarXTextBox(buffer);
	sscanf_s(buffer, "%f", &sptr->x);
	CurrentImageWindow::GetCurrentImageStarYTextBox(buffer);
	sscanf_s(buffer, "%f", &sptr->y);
	CurrentImageWindow::GetCurrentImageStarMaxTextBox(buffer);
	sscanf_s(buffer, "%d", &sptr->max);
	CurrentImageWindow::GetCurrentImageFWHMTextBox(buffer);
	sscanf_s(buffer, "%f", &sptr->fwhm);
	CurrentImageWindow::GetCurrentImageMagTextBox(buffer);
	sscanf_s(buffer, "%f -/+ %f", &sptr->mag, &sptr->magErr);
	CurrentImageWindow::GetCurrentImageStarFluxTextBox(buffer);
	sscanf_s(buffer, "%f", &sptr->flux);
	CurrentImageWindow::GetCurrentImageSkyFluxTextBox(buffer);
	sscanf_s(buffer, "%f", &sptr->skyFlux);
	
	/* Check if star already in list (choose largest flux) */
	
	ptr = CurrentStarList;
	min = photometrySettings.minSeparation;
	while (ptr != NULL) {
		if ((fabs(ptr->x-sptr->x) < min) && (fabs(ptr->y-sptr->y) < min)) {
			if (ptr->flux < sptr->flux) {
				ptr->x = sptr->x;  ptr->y = sptr->y; ptr->max = sptr->max;
				ptr->fwhm = sptr->fwhm; ptr->mag = sptr->mag;
				ptr->magErr = sptr->magErr;
				ptr->flux = sptr->flux; ptr->skyFlux = sptr->skyFlux;
				sprintf_s(buffer, sizeof(buffer), "*** INFO - Replacing star: (%7.2f,%7.2f), "
					"max: %d, FWHM: %6.2f\n", sptr->x, sptr->y, sptr->max, sptr->fwhm);
				Form1::CCDAutoForm->StatusPrint(buffer);
			}
			return false;
		}
		ptr = ptr->next;
	}
	
	/* Add to list */
	
	sptr->found = true;
	sptr->measured = true;
	sptr->ra = 0.0;
	sptr->dec = 0.0;
	sptr->next = NULL;
	sptr->prev = NULL;
	
	if (CurrentStarList == NULL) {
		CurrentStarList = sptr;
	} else {
		ptr = CurrentStarList;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = sptr;
		sptr->prev = ptr;
	}
	
	sprintf_s(buffer, sizeof(buffer),
		"*** INFO - Adding star: (%7.2f,%7.2f), max: %d, FWHM: %6.2f\n", sptr->x, sptr->y, sptr->max, sptr->fwhm);
	Form1::CCDAutoForm->StatusPrint(buffer);
	
	return true;
}

void DeleteStar(void) {

  char buffer[120];
  float starX, starY;
  STAR *sptr;

  /* Get Current Star's parameters */

  CurrentImageWindow::FormPtr->GetCurrentImageStarXTextBox(buffer);
  sscanf_s(buffer, "%f", &starX);
  CurrentImageWindow::FormPtr->GetCurrentImageStarYTextBox(buffer);
  sscanf_s(buffer, "%f", &starY);

  if (CurrentStarList == NULL) {
	  Form1::StatusPrint("*** WARNING - Can't delete star, list is empty...\n");
    return;
  }

  sptr = CurrentStarList;
  while (sptr != NULL) {
    if ((fabs(sptr->x-starX) < 3.0) && (fabs(sptr->y-starY) < 3.0)) {
      if (sptr == CurrentStarList) {
		  CurrentStarList = sptr->next;
		  CurrentStarList->prev = NULL;
      } else {
		  (sptr->prev)->next = sptr->next;
		  if (sptr->next != NULL)
			  (sptr->next)->prev = sptr->prev;
      }
      free(sptr);
      break;
    }
    sptr = sptr->next;
  }

  if (sptr == NULL) {
	Form1::StatusPrint("*** Warning - Could find star in list, not deleted...\n");
  } else {
    sprintf_s(buffer, sizeof(buffer), "*** INFO - Star at: (%5.1f,%5.1f) was deleted...\n",
	    starX, starY);
	Form1::StatusPrint(buffer);
  }

  return;
}

void clearListStars(void)
{
  STAR *sptr, *next;

  sptr = CurrentStarList;

  while (sptr != NULL) {
    next = sptr->next;
    free(sptr);
    sptr = next;
  }

  CurrentStarList = NULL;
  CurrentStarListDefined = false;

  return;
}



void SetPhotometrySettingsDialogValues(void) {

	char buffer[80];

    sprintf_s(buffer, sizeof(buffer), "%5.1f", photometrySettings.aperatureRadius);
	PhotometrySettingsDialog::FormPtr->SetAperatureRadiusTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%5.1f", photometrySettings.ApFWHMScale);
	PhotometrySettingsDialog::FormPtr->SetApRadiusFWHMTextBox(buffer);
	PhotometrySettingsDialog::FormPtr->SetFWHMRadioButton(photometrySettings.AperatureScaledToFWHM);
    sprintf_s(buffer, sizeof(buffer), "%7.3f", photometrySettings.zeroPoint);
	PhotometrySettingsDialog::FormPtr->SetZeroPointTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%5.1f", photometrySettings.findRadius);
	PhotometrySettingsDialog::FormPtr->SetFindRadiusTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%5.1f", photometrySettings.minPeak);
	PhotometrySettingsDialog::FormPtr->SetMinPeakTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%5.1f", photometrySettings.maxPeak);
	PhotometrySettingsDialog::FormPtr->SetMaxPeakTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%5.1f", photometrySettings.minFWHM);
	PhotometrySettingsDialog::FormPtr->SetMinFWHMTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%5.1f", photometrySettings.maxFWHM);
	PhotometrySettingsDialog::FormPtr->SetMaxFWHMTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%5.1f", photometrySettings.minSeparation);
	PhotometrySettingsDialog::FormPtr->SetMinSeparationTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%5.1f", photometrySettings.skyInnerRadius);
	PhotometrySettingsDialog::FormPtr->SetSkyInnerRadiusTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%5.1f", photometrySettings.skyOuterRadius);
	PhotometrySettingsDialog::FormPtr->SetSkyOuterRadiusTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%5.1f", photometrySettings.skySigmaCut);
	PhotometrySettingsDialog::FormPtr->SetSkySigmaCutTextBox(buffer);
	PhotometrySettingsDialog::FormPtr->SetLogDirTextBox(photometrySettings.logDir);
	PhotometrySettingsDialog::FormPtr->SetLogFileBaseNameTextBox(photometrySettings.logBaseName);
	PhotometrySettingsDialog::FormPtr->SetCCDAutoCheckBox(photometrySettings.logCCDAutoFormat);
	PhotometrySettingsDialog::FormPtr->SetAAVSOCheckBox(photometrySettings.logAAVSOFormat);
	PhotometrySettingsDialog::FormPtr->SetPlotResultsCheckBox(photometrySettings.plotResults);
	PhotometrySettingsDialog::FormPtr->SetAutoFindCheckBox(photometrySettings.autoFind);
	PhotometrySettingsDialog::FormPtr->SetOffsetSkyCheckBox(photometrySettings.offsetSky);
	PhotometrySettingsDialog::FormPtr->SetCalibrateCheckBox(photometrySettings.CalibrateImages);
	PhotometrySettingsDialog::FormPtr->SetInteractiveCheckBox(photometrySettings.Interactive);
}

void GetPhotometrySettingsDialogValues(void) {

	char buffer[80], Message[160];
	char Dir[160], BaseName[80], NewLogFileName[160], LogFileName[160];
	int answer;
	FILE *fptr;

	PhotometrySettingsDialog::FormPtr->GetAperatureRadiusTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.aperatureRadius);
	PhotometrySettingsDialog::FormPtr->GetApRadiusFWHMTextBox(buffer);
	sscanf_s(buffer, "%f", &photometrySettings.ApFWHMScale);
	PhotometrySettingsDialog::FormPtr->GetFWHMRadioButton(&photometrySettings.AperatureScaledToFWHM);
	PhotometrySettingsDialog::FormPtr->GetZeroPointTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.zeroPoint);
	PhotometrySettingsDialog::FormPtr->GetFindRadiusTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.findRadius);
	PhotometrySettingsDialog::FormPtr->GetMinPeakTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.minPeak);
	PhotometrySettingsDialog::FormPtr->GetMaxPeakTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.maxPeak);
	PhotometrySettingsDialog::FormPtr->GetMinFWHMTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.minFWHM);
	PhotometrySettingsDialog::FormPtr->GetMaxFWHMTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.maxFWHM);
	PhotometrySettingsDialog::FormPtr->GetMinSeparationTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.minSeparation);
	PhotometrySettingsDialog::FormPtr->GetSkyInnerRadiusTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.skyInnerRadius);
	PhotometrySettingsDialog::FormPtr->GetSkyOuterRadiusTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.skyOuterRadius);
	PhotometrySettingsDialog::FormPtr->GetSkySigmaCutTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.skySigmaCut);
	PhotometrySettingsDialog::FormPtr->GetPlotResultsCheckBox(&photometrySettings.plotResults);
	PhotometrySettingsDialog::FormPtr->GetAutoFindCheckBox(&photometrySettings.autoFind);
	PhotometrySettingsDialog::FormPtr->GetOffsetSkyCheckBox(&photometrySettings.offsetSky);
	PhotometrySettingsDialog::FormPtr->GetLogFileBaseNameTextBox(BaseName);
	PhotometrySettingsDialog::FormPtr->GetLogDirTextBox(Dir);
	PhotometrySettingsDialog::FormPtr->GetCCDAutoCheckBox(&photometrySettings.logCCDAutoFormat);
	PhotometrySettingsDialog::FormPtr->GetAAVSOCheckBox(&photometrySettings.logAAVSOFormat);
	PhotometrySettingsDialog::FormPtr->GetCalibrateCheckBox(&photometrySettings.CalibrateImages);
	PhotometrySettingsDialog::FormPtr->GetInteractiveCheckBox(&photometrySettings.Interactive);

	// If not checked, stop logging if logging & close file if open

	strcpy_s(NewLogFileName, sizeof(NewLogFileName), Dir);
	strcat_s(NewLogFileName, sizeof(NewLogFileName), "\\");
	strcat_s(NewLogFileName, sizeof(NewLogFileName), BaseName);
	
	strcpy_s(LogFileName, sizeof(LogFileName), photometrySettings.logDir);
	strcat_s(LogFileName, sizeof(LogFileName), "\\");
	strcat_s(LogFileName, sizeof(LogFileName), photometrySettings.logBaseName);

	// Open/Close CCDAuto log file

	if (! photometrySettings.logCCDAutoFormat) {    // CCDAuto Format log file
		if (photometrySettings.logCCDAutoFilePtr != NULL) {
		    fclose(photometrySettings.logCCDAutoFilePtr);
			photometrySettings.logCCDAutoFilePtr = NULL;
			sprintf_s(Message, sizeof(Message), "*** Info - Closed photometry log file: %s\n",
				photometrySettings.logCCDAutoFileName);
			Form1::StatusPrint(Message);
		}

		  //  If checked, check for different log file name

	} else {

		if (strcmp(NewLogFileName, LogFileName) != 0) { // If different log file name
			if (photometrySettings.logCCDAutoFilePtr != NULL) {  // close old log file
				fclose(photometrySettings.logCCDAutoFilePtr);
				photometrySettings.logCCDAutoFilePtr = NULL;
				sprintf_s(Message, sizeof(Message), "*** Info - Closed photometry log file: %s (CCDAuto format)\n",
					LogFileName);
				Form1::StatusPrint(Message);
			}
		}
		strcpy_s(photometrySettings.logBaseName, sizeof(photometrySettings.logBaseName), BaseName);
		strcpy_s(photometrySettings.logDir, sizeof(photometrySettings.logDir), Dir);
		strcpy_s(LogFileName, sizeof(LogFileName), photometrySettings.logDir);
		strcat_s(LogFileName, sizeof(LogFileName), "\\");
		strcat_s(LogFileName, sizeof(LogFileName), photometrySettings.logBaseName);
		strcat_s(LogFileName, sizeof(LogFileName), "CCDAuto.log");
		strcpy_s(photometrySettings.logCCDAutoFileName, sizeof(photometrySettings.logCCDAutoFileName), LogFileName);
		if (photometrySettings.logCCDAutoFilePtr == NULL) {
			fopen_s(&fptr, LogFileName, "r"); // check if log file exists
			if (fptr != NULL) {
				fclose(fptr);
				sprintf_s(Message, sizeof(Message), "Photometry Log File: %s exists, want to append to it?", LogFileName);
				answer = MessageBox(Message, YESNO, true);
				if (answer != YES) {
					answer = MessageBox("Want to overwrite it?", YESNO, true);
					if (answer != YES) {
						MessageBox("Then change log file name and try again", OKAY, true);
						Form1::StatusPrint("*** Info - Photometry logging remains off\n");
						photometrySettings.logCCDAutoFormat = false;
						PhotometrySettingsDialog::FormPtr->SetCCDAutoCheckBox(false);
					} else {
						Form1::StatusPrint("*** Info - Overwriting log file...\n");
						fopen_s(&fptr, LogFileName, "w");
						if (fptr == NULL) {
							sprintf_s(Message, sizeof(Message), "*** WARNING - Can't create log file: %s\n", LogFileName);
							Form1::StatusPrint(Message);
							photometrySettings.logCCDAutoFormat = false;
							PhotometrySettingsDialog::FormPtr->SetCCDAutoCheckBox(false);
						} else {
							sprintf_s(Message, sizeof(Message), "*** Info - Photometry log file %s is open (overwrite)\n",
										LogFileName);
							Form1::StatusPrint(Message);
							photometrySettings.logCCDAutoFilePtr = fptr;
						}
					}
				} else {
					fopen_s(&fptr, LogFileName, "a");
					if (fptr == NULL) {
						sprintf_s(Message, sizeof(Message), "*** WARNING - Can't open log file %s for appending...\n",
									LogFileName);
						Form1::StatusPrint(Message);
						photometrySettings.logCCDAutoFormat = false;
						PhotometrySettingsDialog::FormPtr->SetCCDAutoCheckBox(false);
					} else {
						sprintf_s(Message, sizeof(Message),"*** Info - Photometry log file %s is open (append)\n",
									LogFileName);
						Form1::StatusPrint(Message);
						photometrySettings.logCCDAutoFilePtr = fptr;
					}
				}
			} else {
				fopen_s(&fptr, LogFileName, "w");
				if (fptr == NULL) {
					sprintf_s(Message, sizeof(Message), "*** WARNING - Can't open log file %s for overwriting...\n",
								LogFileName);
					Form1::StatusPrint(Message);
					photometrySettings.logCCDAutoFormat = false;
					PhotometrySettingsDialog::FormPtr->SetCCDAutoCheckBox(false);
				} else {
					sprintf_s(Message, sizeof(Message), "*** INFO - Photometry log file %s is open (new)\n", LogFileName);
					Form1::StatusPrint(Message);
					photometrySettings.logCCDAutoFilePtr = fptr;
				}
			}
		}
	}

	// Open/Close AAVSO log file

	if (! photometrySettings.logAAVSOFormat) {    // AAVSO Format log file
		if (photometrySettings.logAAVSOFilePtr != NULL) {
		    fclose(photometrySettings.logAAVSOFilePtr);
			photometrySettings.logAAVSOFilePtr = NULL;
			sprintf_s(Message, sizeof(Message), "*** Info - Closed photometry log file: %s\n",
				photometrySettings.logAAVSOFileName);
			Form1::StatusPrint(Message);
		}

		  //  If checked, check for different log file name

	} else {

		if (strcmp(NewLogFileName, LogFileName) != 0) { // If different log file name
			if (photometrySettings.logAAVSOFilePtr != NULL) {  // close old log file
				fclose(photometrySettings.logAAVSOFilePtr);
				photometrySettings.logAAVSOFilePtr = NULL;
				sprintf_s(Message, sizeof(Message), "*** Info - Closed photometry log file: %s (AAVSO format)\n",
					LogFileName);
				Form1::StatusPrint(Message);
			}
		}
		strcpy_s(photometrySettings.logBaseName, sizeof(photometrySettings.logBaseName), BaseName);
		strcpy_s(photometrySettings.logDir, sizeof(photometrySettings.logDir), Dir);
		strcpy_s(LogFileName, sizeof(LogFileName), photometrySettings.logDir);
		strcat_s(LogFileName, sizeof(LogFileName), "\\");
		strcat_s(LogFileName, sizeof(LogFileName), photometrySettings.logBaseName);
		strcat_s(LogFileName, sizeof(LogFileName), "AAVSO.log");
		strcpy_s(photometrySettings.logAAVSOFileName, sizeof(photometrySettings.logCCDAutoFileName), LogFileName);
		if (photometrySettings.logAAVSOFilePtr == NULL) {
			fopen_s(&fptr, LogFileName, "r"); // check if log file exists
			if (fptr != NULL) {
				fclose(fptr);
				sprintf_s(Message, sizeof(Message), "Photometry Log File: %s exists, want to append to it?", LogFileName);
				answer = MessageBox(Message, YESNO, true);
				if (answer != YES) {
					answer = MessageBox("Want to overwrite it?", YESNO, true);
					if (answer != YES) {
						MessageBox("Then change log file name and try again", OKAY, true);
						Form1::StatusPrint("*** Info - Photometry logging remains off\n");
						photometrySettings.logAAVSOFormat = false;
						PhotometrySettingsDialog::FormPtr->SetAAVSOCheckBox(false);
					} else {
						Form1::StatusPrint("*** Info - Overwriting log file...\n");
						fopen_s(&fptr, LogFileName, "w");
						if (fptr == NULL) {
							sprintf_s(Message, sizeof(Message), "*** WARNING - Can't create log file: %s\n", LogFileName);
							Form1::StatusPrint(Message);
							photometrySettings.logAAVSOFormat = false;
							PhotometrySettingsDialog::FormPtr->SetAAVSOCheckBox(false);
						} else {
							sprintf_s(Message, sizeof(Message), "*** Info - Photometry log file %s is open (overwrite)\n",
										LogFileName);
							Form1::StatusPrint(Message);
							photometrySettings.logAAVSOFilePtr = fptr;
							photometrySettings.AAVSOPrintHeading = true;
						}
					}
				} else {
					fopen_s(&fptr, LogFileName, "a");
					if (fptr == NULL) {
						sprintf_s(Message, sizeof(Message), "*** WARNING - Can't open log file %s for appending...\n",
									LogFileName);
						Form1::StatusPrint(Message);
						photometrySettings.logAAVSOFormat = false;
						PhotometrySettingsDialog::FormPtr->SetAAVSOCheckBox(false);
					} else {
						sprintf_s(Message, sizeof(Message),"*** Info - Photometry log file %s is open (append)\n",
									LogFileName);
						Form1::StatusPrint(Message);
						photometrySettings.logAAVSOFilePtr = fptr;
						photometrySettings.AAVSOPrintHeading =false;
					}
				}
			} else {
				fopen_s(&fptr, LogFileName, "w");
				if (fptr == NULL) {
					sprintf_s(Message, sizeof(Message), "*** WARNING - Can't open log file %s for overwriting...\n",
								LogFileName);
					Form1::StatusPrint(Message);
					photometrySettings.logAAVSOFormat = false;
					PhotometrySettingsDialog::FormPtr->SetAAVSOCheckBox(false);
				} else {
					sprintf_s(Message, sizeof(Message), "*** INFO - Photometry log file %s is open (new)\n", LogFileName);
					Form1::StatusPrint(Message);
					photometrySettings.logAAVSOFilePtr = fptr;
					photometrySettings.AAVSOPrintHeading = true;					
				}
			}
		}
	}
	if (photometrySettings.AAVSOPrintHeading) {
		if (! AAVSOPhotoDialogExists) {
			gcnew AAVSOPhotoDialog();
			if (AAVSOPhotoDialog::ShowTheDialog())
				return;
		}

	}
}

void ShowPhotometrySettingsDialog(void) {
	if (! PhotometrySettingsDialogExists)
		gcnew PhotometrySettingsDialog();

	SetPhotometrySettingsDialogValues();
	PhotometrySettingsDialog::FormPtr->ShowTheDialog();
}


void ShowObjectListDialog(void) {
	int EditState;
	char buffer[80];
	OBJECT obj;
	OBJNODE *optr;

	if (! ObjectListDialogExists)
		gcnew ObjectListDialog();

	/* Read in object list from file in case changed */

	InitObjectList(objectListFileName);

	/* update the dialog components */

      /* Combo box */

	optr = ObjectListHead;
	while (optr != NULL) {
		ObjectListDialog::AddObjectNameToList(optr->obj.name);
		optr = optr->next;
	}

	ObjectListDialog::FormPtr->SetEditCheckBox(false);
	EditState = false;

	/* select object from combo box */

	obj = ObjectListHead->obj;
	ObjectListDialog::FormPtr->SetComboBoxSelectedText(obj.name);

	/* Display object's info */

	ObjectListDialog::FormPtr->SetNameTextBox(obj.name);
	ObjectListDialog::FormPtr->SetObjectTypeTextBox(obj.objectType);
	ObjectListDialog::FormPtr->SetSpectralTypeTextBox(obj.specType);
	ObjectListDialog::FormPtr->SetVarTypeTextBox(obj.varType);
	ObjectListDialog::FormPtr->SetRATextBox(obj.ra);
	ObjectListDialog::FormPtr->SetDECTextBox(obj.dec);
    sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[0]);
	ObjectListDialog::FormPtr->SetUTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[1]);
	ObjectListDialog::FormPtr->SetBTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[2]);
	ObjectListDialog::FormPtr->SetVTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[3]);
	ObjectListDialog::FormPtr->SetRTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[4]);
	ObjectListDialog::FormPtr->SetITextBox(buffer);

	ObjectListEditable = false;
	ObjectListDialog::FormPtr->ShowTheDialog();
}


void RefreshCurrentImageWindow(void) {
	CurrentImageWindow::FormPtr->Refresh();
}

void RefreshPhotometryPlotWindow(void) {
	PhotometryPlotWindow::FormPtr->Refresh();
}

void RefreshPhotometySettingsDialog(void) {
	PhotometrySettingsDialog::FormPtr->Refresh();
}

void DoMainEvents(void) {
	Application::DoEvents();
}


void DoDarkFrameSeries(void) {

	int i, iframe, sumd;
	int d[MAXNUMDARKS], m;
	int numFrames, nrows, ncols, npixels, nbytes;
	IMAGE darkFrames[MAXNUMDARKS], *iptr;
	unsigned short *DFptr;
	StartExposureParams expose;
	StartReadoutParams readout;
	char Message[120], FileName[160];
	unsigned short *savePtr;

	// Check if linked to camera

	if (! ccd->Linked) {
		sprintf_s(Message, sizeof(Message), "Can't start dark frames, link to camera first.\n");
		Form1::StatusPrint(Message);
		return;
	}

	/* Init controls */

	StopSeries = false;
	PauseSeries = false;

	/* Init frames */

	numFrames = darkFrameSettings.numFrames;
    nrows = darkFrameSettings.h;
    ncols = darkFrameSettings.w;
    npixels = nrows*ncols;
    nbytes = npixels * sizeof(unsigned short);
    for (iframe=0; iframe<numFrames; iframe++) {
		iptr = &darkFrames[iframe];
		strcpy_s(iptr->Filter, sizeof(iptr->Filter), "C");
		strcpy_s(iptr->FileName, sizeof(iptr->Filter), "");
		strcpy_s(iptr->ObjectName, sizeof(iptr->ObjectName), "Dark");
		iptr->dark_frame.whichCCD = darkFrameSettings.whichCCD;
		iptr->dark_frame.binning = darkFrameSettings.binning;
		iptr->dark_frame.x = darkFrameSettings.x;
		iptr->dark_frame.y = darkFrameSettings.y;
		iptr->dark_frame.h = darkFrameSettings.h;
		iptr->dark_frame.w = darkFrameSettings.w;
		iptr->dark_frame.active = false;
		iptr->light_frame.active = false;
		iptr->saved = false;
		iptr->darkOnly = true;
		iptr->lightOnly = false;
		iptr->dark_frame.temp = 999.0;
		iptr->dark_frame.exposure = darkFrameSettings.exposureTime;
		iptr->dark_frame.time = (time_t) 0.0;
		iptr->dark_frame.frame = (unsigned short *) realloc(NULL, nbytes);
		iptr->light_frame.frame = iptr->dark_frame.frame;
	}

	/* Init expose/readout data */

	expose.ccd = darkFrameSettings.whichCCD;
	expose.abgState = 0;
	expose.exposureTime = ((int) (100.0 * darkFrameSettings.exposureTime));
	readout.ccd = expose.ccd;
	readout.readoutMode = darkFrameSettings.binning;
	readout.left = darkFrameSettings.x;
	readout.top = darkFrameSettings.y;
	readout.width = darkFrameSettings.w;
	readout.height = darkFrameSettings.h;

	/* Loop over exposing dark frames */

	ccd->Image.light_frame.w = darkFrameSettings.w;
	ccd->Image.light_frame.h = darkFrameSettings.h;
	if (ccd == &ImagingCCD) {
		DFptr = ImagingDarkFrame;
	} else if (ccd == &SpectroCCD) {
		DFptr = SpectroDarkFrame;
	} else {
		DFptr = TrackingDarkFrame;
	}
	SeriesStarted = true;
	for (iframe=0; iframe<numFrames; iframe++) {

		/* Expose dark */

		sprintf_s(Message, sizeof(Message), "%d", iframe+1);
		Form1::CCDAutoForm->SetProcessingExpNumTextBox(Message);

		iptr = &darkFrames[iframe];
		sprintf_s(Message, sizeof(Message), "Exposing dark frame #%d, %f sec.\n",
			iframe, darkFrameSettings.exposureTime);
		Form1::StatusPrint(Message);
		CancelCurrentAcquire = false;
		savePtr = iptr->dark_frame.frame;
		iptr->dark_frame.frame = DFptr;;
		snapImaging(ccd, &expose, &readout, iptr);
		iptr->dark_frame.frame = savePtr;
		memcpy_s(iptr->dark_frame.frame, nbytes, DFptr, nbytes);
		if (CancelCurrentAcquire || StopSeries) {
			
			// Free up dark frame memory
			
			for (iframe=0; iframe<numFrames; iframe++) {
				free(darkFrames[iframe].dark_frame.frame);
			}
			StopSeries = false;
			SeriesStarted = false;
			return;
		}


		/* Display dark */

		memcpy_s(ccd->Image.light_frame.frame, nbytes, iptr->dark_frame.frame, nbytes);
		loadImageImaging(iptr->dark_frame.frame, iptr->dark_frame.x,
		     iptr->dark_frame.y, iptr->dark_frame.w,
		     iptr->dark_frame.h, iptr->dark_frame.binning);


		/* update frame parms */

		iptr->dark_frame.active = true;
		iptr->light_frame.active = true;
		iptr->saved = false;
		iptr->Filter[0] = filterSet[ccd->filterPosition];
		iptr->Filter[1] = '\000';

		/* Save dark frame if required */

		if (DarkSaveEachDarkFrame) {
			if (darkFrameSettings.exposureTime >= 10.0) {
				sprintf_s(FileName, sizeof(FileName), "%s/Dark%s_%d_%03d.fits",
					darkFrameSettings.imageDir, binningString[iptr->dark_frame.binning], 
					((int)darkFrameSettings.exposureTime), iframe);
			} else {
				sprintf_s(FileName, sizeof(FileName), "%s/Dark%s_%dms_%03d.fits",
					darkFrameSettings.imageDir, binningString[iptr->dark_frame.binning], 
					((int)(darkFrameSettings.exposureTime*1000)), iframe);
			}
			strcpy_s(iptr->dark_frame.UT, sizeof(iptr->dark_frame.UT), "");
			strcpy_s(iptr->dark_frame.UTDATE, sizeof(iptr->dark_frame.UTDATE), "");
			writeFITS(iptr, 2, FileName, iptr->ObjectName);
		}
	}

	/* Combine dark frames */

	for (i=npixels; --i>=0; ) {
		sumd = 0;
		for (iframe=0; iframe<numFrames; iframe++) {
			iptr = &darkFrames[iframe];
			d[iframe] = iptr->dark_frame.frame[i];
			sumd += d[iframe];
		}
		if (darkFrameSettings.combineMethod == 1) {
			m = imedian(d, numFrames);
		} else {
			m = ((int) (((float) sumd)/numFrames));
		}
		ccd->Image.dark_frame.frame[i] = m;
	}
	ccd->Image.dark_frame.active = true;
	ccd->Image.dark_frame.whichCCD = darkFrameSettings.whichCCD;
	ccd->Image.dark_frame.binning = darkFrameSettings.binning;
	ccd->Image.dark_frame.x = darkFrameSettings.x;
	ccd->Image.dark_frame.y = darkFrameSettings.y;
	ccd->Image.dark_frame.w = darkFrameSettings.w;
	ccd->Image.dark_frame.h = darkFrameSettings.h;
	ccd->Image.dark_frame.exposure = darkFrameSettings.exposureTime;
	ccd->Image.dark_frame.temp = darkFrames[numFrames/2].dark_frame.temp;

	/* Write out combined dark frame */

	if (darkFrameSettings.exposureTime >= 10.0) {
		sprintf_s(FileName, sizeof(FileName), "%s/Dark%s_%d.fits",
			darkFrameSettings.imageDir, binningString[iptr->dark_frame.binning], 
			((int)darkFrameSettings.exposureTime));
	} else {
		sprintf_s(FileName, sizeof(FileName), "%s/Dark%s_%dms.fits",
			darkFrameSettings.imageDir, binningString[iptr->dark_frame.binning], 
			((int)(darkFrameSettings.exposureTime*1000)));
	}
	strcpy_s(ccd->Image.dark_frame.UT, sizeof(ccd->Image.dark_frame.UT), "");
	strcpy_s(ccd->Image.dark_frame.UTDATE, sizeof(ccd->Image.dark_frame.UTDATE), "");
	ccd->Image.dark_frame.time = darkFrames[0].dark_frame.time;
	writeFITS(&ccd->Image, 2, FileName, "Dark");

	// Display combined dark frame

	iptr = &ccd->Image;
	memcpy_s(iptr->light_frame.frame, nbytes, iptr->dark_frame.frame, nbytes);
	loadImageImaging(iptr->dark_frame.frame, iptr->dark_frame.x,
		   iptr->dark_frame.y, iptr->dark_frame.w,
		   iptr->dark_frame.h, iptr->dark_frame.binning);

	// Free up dark frame memory

	for (iframe=0; iframe<numFrames; iframe++) {
		free(darkFrames[iframe].dark_frame.frame);
	}
	SeriesStarted = false;
  
	return;

}

int imedian(int *data, int num) {
  int max, i, j, jmax;
  int list[100], temp[100];

  memcpy_s(temp,sizeof(temp), data,num*sizeof(int));
  jmax = 0;
  for (i=0; i<num; i++) {
    max = 0;
    for (j=0; j<num; j++) {
      if (temp[j] > max) {
	jmax = j;
	max = temp[j];
      }
    }
    list[i] = max;
    temp[jmax] = 0;
  }
  return list[num/2];
}

bool GetAFolder(char *description, char *folder) {

	int i;
	char *cptr;
	String ^buffer, ^InitFolder;

	buffer = gcnew String(description);
	InitFolder = gcnew String(folder);

	Form1::CCDAutoForm->OpenFileDialog->InitialDirectory = InitFolder;
	Form1::CCDAutoForm->OpenFileDialog->Title = buffer;
	Form1::CCDAutoForm->OpenFileDialog->RestoreDirectory = true;
	Form1::CCDAutoForm->OpenFileDialog->Filter = "*.*";
//	System::Windows::Forms::DialogResult res = Form1::CCDAutoForm->FolderBrowserDialog->ShowDialog();
	System::Windows::Forms::DialogResult res = Form1::CCDAutoForm->OpenFileDialog->ShowDialog();
	if ( res != System::Windows::Forms::DialogResult::OK) {
		delete buffer;
		delete InitFolder;
		return false;
	}
	String ^path = Form1::CCDAutoForm->OpenFileDialog->FileName;
//	String^ path = Form1::CCDAutoForm->FolderBrowserDialog->SelectedPath;
	for (i = 0; i < path->Length; i++) {
		folder[i] = (char)path[i];
	}
	folder[i] = '\0';
	cptr = strrchr(folder, '\\');
	*cptr = 0;

	 delete buffer;
	 delete InitFolder;
	 return true;
}

void DoFlatFrameSeries(void) {

	unsigned short *saveptr;
	bool darkNeeded, gotDark, success;
	int i, iframe, sumd, ifilter, status;
	int pixval;
	int numFrames, nrows, ncols, npixels, nbytes;
	double sumpixval;
	int d[MAXNUMFLATS], m;
	float eTime, meanpixval, normpixval;
	FLATNODE *ffptr, *next;
	StartExposureParams expose;
	StartReadoutParams readout;
	char Message[160], FileName[160];
	double ccd_temp, dark_temp;
	
	/* Init control flags */
	
	PauseSeries = false;
	StopSeries = false;

	/* Set the dark frame settings */

	ccd->FlatImage.darkOnly = false;
	ccd->FlatImage.lightOnly = false;
	ccd->FlatImage.light_frame.binning = flatFrameSettings.binning;
	ccd->FlatImage.light_frame.whichCCD = flatFrameSettings.whichCCD;
	ccd->FlatImage.light_frame.x = ccd->Image.light_frame.x = flatFrameSettings.x;
	ccd->FlatImage.light_frame.y = ccd->Image.light_frame.y = flatFrameSettings.y;
	ccd->FlatImage.light_frame.w = ccd->Image.light_frame.w = flatFrameSettings.w;
	ccd->FlatImage.light_frame.h = ccd->Image.light_frame.h = flatFrameSettings.h;

	gotDark = false;
	switch (flatFrameSettings.darkOption) {
		case 1:
			break;
		case 2:
			gotDark = true;
			ccd->FlatImage.lightOnly = false;
			break;
		case 3:
			ccd->FlatImage.lightOnly = true;
			break;
		case 4:
			gotDark = false;
			ccd->FlatImage.lightOnly = true;
			break;
	}

	/* Check if linked to camera */

	if (!ccd->Linked) {
		sprintf_s(Message, sizeof(Message), "Can't start flat frames, link to camera first.\n");
		Form1::StatusPrint(Message);
		return;
	}

	/* Init frames */

	numFrames = flatFrameSettings.numFrames;
	nrows = flatFrameSettings.h;
	ncols = flatFrameSettings.w;
	npixels = nrows*ncols;
	nbytes = npixels * sizeof(unsigned short);

	/* Allocate memory for final (combined) flat frame */

//	ccd->FlatImage.dark_frame.frame = (unsigned short *)
//		realloc(ccd->FlatImage.dark_frame.frame, nbytes);
//	ccd->FlatImage.light_frame.frame = (unsigned short *)
//		realloc(ccd->FlatImage.light_frame.frame, nbytes);

	/* If reusing dark frame, copy it from Image frame if active */

	if ((flatFrameSettings.darkOption == 1) && (ccd->Image.dark_frame.active)) {
		saveptr = ccd->FlatImage.dark_frame.frame;
		memcpy(&ccd->FlatImage.dark_frame, &ccd->Image.dark_frame, sizeof(FRAME));
		ccd->FlatImage.dark_frame.frame = saveptr;
		memcpy(ccd->FlatImage.dark_frame.frame, ccd->Image.dark_frame.frame, nbytes);
	}
  
	/* Init expose/readout data */

	expose.ccd = flatFrameSettings.whichCCD;
	expose.abgState = 0;
	readout.ccd = expose.ccd;
	readout.readoutMode = flatFrameSettings.binning;
	readout.left = flatFrameSettings.x;
	readout.top = flatFrameSettings.y;
	readout.width = flatFrameSettings.w;
	readout.height = flatFrameSettings.h;

	/* Loop over exposing flat frames */

	SeriesStarted = true;
	for (ifilter=0; ifilter<NUMFILTERS; ifilter++) {

		/* If filter not required, skip it */

		if (! flatFrameSettings.filterSeq.Use[ifilter])
			continue;

		sprintf_s(Message, sizeof(Message), "*** Info - Doing filter: %c, exposures: %f sec\n",
			filterSet[ifilter], flatFrameSettings.filterSeq.exposures[ifilter]);
		Form1::StatusPrint(Message);

		/* Set the filter position */

		doFilterWheel(ccd, &status, ifilter+1);
		updateStatusInfo();

		for (iframe=0; iframe<numFrames; iframe++) {

			sprintf_s(Message, sizeof(Message), "%d", iframe+1);
			Form1::SetProcessingExpNumTextBox(Message);

			/* Check if dark frame needed */

			ccd_temp = 0.0;
			eTime = flatFrameSettings.filterSeq.exposures[ifilter];
			if ((flatFrameSettings.darkOption == 1) ||
				(flatFrameSettings.darkOption == 3)) {
				success = GetCCDTemperature(ccd, &ccd_temp);
				if (! success) {
					Form1::StatusPrint("*** WARNING - Can't get ccd temperature, aborting exposure...\n");
					SeriesStarted = false;
					return;
				}
				ccd->FlatImage.light_frame.temp = ((float) ccd_temp);
			}
			if (flatFrameSettings.darkOption == 1) {
				dark_temp = ccd->FlatImage.dark_frame.temp;
				darkNeeded = ((fabs(dark_temp-ccd_temp) > MAXTEMPDIFF) ||
						      (! ccd->FlatImage.dark_frame.active) ||
							  (ccd->FlatImage.dark_frame.exposure != eTime) ||
							  (flatFrameSettings.binning != ccd->FlatImage.dark_frame.binning) ||
							  (flatFrameSettings.whichCCD != ccd->FlatImage.dark_frame.whichCCD) ||
							  (flatFrameSettings.x != ccd->FlatImage.dark_frame.x) ||
							  (flatFrameSettings.y != ccd->FlatImage.dark_frame.y) ||
							  (flatFrameSettings.w != ccd->FlatImage.dark_frame.w) ||
							  (flatFrameSettings.h != ccd->FlatImage.dark_frame.h));
				if (darkNeeded) {
					ccd->FlatImage.lightOnly = false;
				} else {
					ccd->FlatImage.lightOnly = true;
				}
				gotDark = true;
			} else if (flatFrameSettings.darkOption == 3) {
				ccd->FlatImage.light_frame.exposure = eTime;
				gotDark = readDark(flatFrameSettings.DarkDir, &ccd->FlatImage);
				if (! gotDark) {
					sprintf_s(Message, sizeof(Message), "*** Warning - Couldn't find compatible dark frame\n"
						" in directory: %s, forcing dark frame\n", flatFrameSettings.DarkDir);
					Form1::StatusPrint(Message);
					ccd->FlatImage.lightOnly = false;
					gotDark = true;
				} else {
					ccd->Image.lightOnly = true;
				}
			}

			/* Expose flat */

			expose.exposureTime = ((int) (100.0 * eTime));
			CancelCurrentAcquire = false;
			snapImaging(ccd, &expose, &readout, &ccd->FlatImage);
			if (CancelCurrentAcquire || StopSeries) {
				ffptr = FlatFrameHead;    /* Free flat frame memory */
				while (ffptr != NULL) {
					next = ffptr->next;
					if (ffptr->Image.light_frame.frame != NULL) {
						free(ffptr->Image.light_frame.frame);
					}
					if (ffptr->Image.dark_frame.frame != NULL) {
						free(ffptr->Image.dark_frame.frame);
					}
					free(ffptr);
					ffptr = next;
				}
				FlatFrameHead = NULL;
				SeriesStarted = false;
				return;
			}

			/* subtract out the dark, and adjust the image if required */

			if (gotDark) {
				for (i = readout.width*readout.height; --i >= 0; ) {
					pixval = ccd->FlatImage.light_frame.frame[i] - ccd->FlatImage.dark_frame.frame[i];
					if (pixval < 0)
						pixval = 0;
					else if (pixval > 65535)
						pixval = 65535;
					ccd->FlatImage.light_frame.frame[i] = pixval;
				}
			}
      

			/* Save current flat in memory */

			if (FlatFrameHead == NULL) {
				FlatFrameHead = (FLATNODE *) malloc(sizeof(FLATNODE));
				ffptr = FlatFrameHead;
				ffptr->next = NULL;
			} else {
				ffptr = FlatFrameHead;
				while (ffptr->next != NULL)
					ffptr = ffptr->next;
				ffptr->next = (FLATNODE *) malloc(sizeof(FLATNODE));
				ffptr = ffptr->next;
				ffptr->next = NULL;
			}
			memcpy(&ffptr->Image, &ccd->FlatImage, sizeof(IMAGE));
			ffptr->Image.light_frame.frame = (unsigned short *) malloc(nbytes);
			memcpy(ffptr->Image.light_frame.frame, ccd->FlatImage.light_frame.frame, nbytes);
			ffptr->Image.dark_frame.frame = (unsigned short *) malloc(nbytes);
			memcpy(ffptr->Image.dark_frame.frame, ccd->FlatImage.dark_frame.frame, nbytes);
			ffptr->Image.saved = false;
			ffptr->Image.Filter[0] = filterSet[ifilter];
			ffptr->Image.Filter[1] = '\000';

			/* Normalize flat using mean */

			sumpixval = 0.0;
			for (i = readout.width*readout.height; --i >= 0; ) {
				sumpixval += ffptr->Image.light_frame.frame[i];
			}
			meanpixval = ((float) (sumpixval / (readout.width*readout.height)));
      
			for (i = readout.width*readout.height; --i >= 0; ) {
				normpixval = ((float) ffptr->Image.light_frame.frame[i]) / meanpixval;
				if (normpixval > 6.0) {
					Form1::StatusPrint("*** WARNING - Got > 6.0 while normalizing flat\n");
					normpixval = 6.0;
				}
				ffptr->Image.light_frame.frame[i] = ((int) (normpixval * 10000.0));
			}
      
			/* Display flat */
      
			loadImageImaging(ffptr->Image.light_frame.frame, ffptr->Image.light_frame.x,
							 ffptr->Image.light_frame.y, ffptr->Image.light_frame.w,
							 ffptr->Image.light_frame.h, ffptr->Image.light_frame.binning);
      
			/* Save flat frame if required */

			if (SaveEachFlatFrame) {
				sprintf_s(FileName, sizeof(FileName), "%s/Flat%s%03d%c.fits", flatFrameSettings.imageDir,
						binningString[ffptr->Image.light_frame.binning],
						iframe, filterSet[ifilter]);
				ffptr->Image.light_frame.UT[0] = '\0';
				ffptr->Image.light_frame.UTDATE[0] = '\0';
				writeFITS(&ffptr->Image, 1, FileName, "flat");
			}

			/* Save dark frame if required */

			if ((FlatSaveEachDarkFrame) && (flatFrameSettings.darkOption != 4)) {
				sprintf_s(FileName, sizeof(FileName), "%s/Dark%s%03d%c.fits", flatFrameSettings.imageDir,
						binningString[ffptr->Image.dark_frame.binning],
						iframe, filterSet[ifilter]);
				ffptr->Image.dark_frame.UT[0] = '\0';
				ffptr->Image.dark_frame.UTDATE[0] = '\0';
				writeFITS(&ffptr->Image, 2, FileName, ffptr->Image.ObjectName);
			}
		}

		/* Combine flat frames */

		for (i=npixels; --i>=0; ) {
			sumd = 0;
			ffptr = FlatFrameHead;
			iframe = 0;
			while (ffptr != NULL) {
				d[iframe] = ffptr->Image.light_frame.frame[i];
				sumd += d[iframe++];
				ffptr = ffptr->next;
			}
			if (flatFrameSettings.combineMethod == 1) {
				m = imedian(d, numFrames);
			} else {
				m = ((int) (((float) sumd)/numFrames));
			}
			ccd->FlatImage.light_frame.frame[i] = m;
		}

		/* Update current flat frame in memory */

		ccd->FlatImage.light_frame.whichCCD = flatFrameSettings.whichCCD;
		ccd->FlatImage.light_frame.binning = flatFrameSettings.binning;
		ccd->FlatImage.light_frame.x = flatFrameSettings.x;
		ccd->FlatImage.light_frame.y = flatFrameSettings.y;
		ccd->FlatImage.light_frame.w = flatFrameSettings.w;
		ccd->FlatImage.light_frame.h = flatFrameSettings.h;
		ccd->FlatImage.light_frame.active = true;
		ccd->FlatImage.Filter[0] = filterSet[ifilter];
		ccd->FlatImage.Filter[1] = 0;

		/* Write out combined flat frame */

		sprintf_s(FileName, sizeof(FileName), "%s/Flat%s%c.fits", flatFrameSettings.imageDir,
				binningString[flatFrameSettings.binning], filterSet[ifilter]);
		ccd->FlatImage.light_frame.UT[0] = '\0';
		ccd->FlatImage.light_frame.UTDATE[0] = '\0';
		writeFITS(&ccd->FlatImage, 1, FileName, "flat");

		/* Free flat frame memory */

		ffptr = FlatFrameHead;
		while (ffptr != NULL) {
			next = ffptr->next;
			if (ffptr->Image.light_frame.frame != NULL) {
				free(ffptr->Image.light_frame.frame);
			}
			if (ffptr->Image.dark_frame.frame != NULL) {
				free(ffptr->Image.dark_frame.frame);
			}
			free(ffptr);
			ffptr = next;
		}
		FlatFrameHead = NULL;
	}

	/* Save last dark frame, it might be useful */

	if (ccd->FlatImage.dark_frame.active) {
//		ccd->Image.dark_frame.frame = (unsigned short *) realloc(ccd->Image.dark_frame.frame, nbytes);
		saveptr = ccd->Image.dark_frame.frame;
		memcpy(&ccd->Image.dark_frame,&ccd->FlatImage.dark_frame, sizeof(FRAME));
		ccd->Image.dark_frame.frame = saveptr;
		memcpy(ccd->Image.dark_frame.frame,ccd->FlatImage.dark_frame.frame, nbytes);
	}

	/* Display combined flat */

	loadImageImaging(ccd->Image.light_frame.frame, ccd->Image.light_frame.x,
		   ccd->Image.light_frame.y, ccd->FlatImage.light_frame.w,
		   ccd->Image.light_frame.h, ccd->Image.light_frame.binning);
	SeriesStarted = false;

	return;
}

/*=======================================================================}
{*  Procedure julian_day                                                *}
{*  Calling Parameters: None                                            *}
{*  Return Parameters: jd                                               *}
{*  Reference: "Astronomical Algorithms"  Page 59                       *}
{*  Description: JULIAN_DAY returns the julian day for the current      *}
{*    system calendar date and time.                                    *}
{*======================================================================*/
void JulianDay(int year, int month, int day, int hour, int minute,
	       int second, int sec100, double *jd)
{
   int A, B, m, y;
   double d;

   DecimalDay(day,hour,minute,second,sec100,&d);
   month++;  // correct for 0-11 instead of 1-12
   if (month > 2) {
      y = year;
      m = month;
   } else {
      y = year-1;  // was y = year - 1
      m = month+12;  // was m = month + 12;
   }

   A = y / 100;

   if ((year <= 1582) ||
       ((year == 1582) &&
	((month <= 10) ||
	 ((month == 10) && (day <= 4)))))
      B = 0;
   else
      B = 2 - A + A / 4;

   *jd = floor(365.25 * (y + 4716)) +
	floor(30.6001 * (m + 1)) + d + B - 1524.5;
}




/*=======================================================================}
{*  Procedure decimal_day                                               *}
{*  Calling Parameters: none                                            *}
{*  Return Parameters: dec_day                                          *}
{*  Reference: David Genet                                              *}
{*  Description: DECIMAL_DAY returns the day and the fractional part    *}
{*     of a day for the current system date and time.                   *}
{*======================================================================*/
void DecimalDay(int day, int hour, int minute, int second, int sec100,
		double *DecDay)
{
   double FracDay;
   long int TempHour;

   TempHour = (long) hour;    //for the muliplication by 3600 to prevent overflow
   FracDay  = (TempHour*3600.0+minute*60.0+second+sec100/100.0)/86400.0;
   *DecDay = day+FracDay;
}




/*=======================================================================}
{*  Procedure LMST                                                      *}
{*  Calling Parameters: None                                            *}
{*  Return Parameters: lst                                              *}
{*  Reference: "Astronomical Algorithms"  Page 83 Formulas 11.1 & 11.4  *}
{*  Description: LMST returns the current mean sidereal time for the    *}
{*    location specified by the global variable site_longitude and the  *}
{*    passed julian date.                                               *}
{*======================================================================*/
void lmst(double julian_date, double *lst)
{

#define num1 280.46061837

   double t; // number of Julian centuries since j2000
   double Theta, Theta1; // IAU convention for mean sidereal time at Greenwhich at 0h UT
   double num2, num3, num4, gmst;
   long int x;

   t = (julian_date-2451545.0)/36525.0;
   num2 = 360.98564736629*(julian_date-2451545.0);
   num3 = t*t*0.000387933;
   num4 = -(t*t*t)/38710000.0;
   Theta1 = num1+num2+num3+num4;

   Theta = 0;
   if (Theta1 < 0) {
      x = (long) (-floorl(Theta1/360.0) - 1);
      Theta = ((x+1)*360)+Theta1;
   }

   if (Theta1 >= 360.0) {
      x = (long) floorl(Theta1/360.0);
      Theta = Theta1 - (x*360);
   }

   gmst = Theta/15.0;
   *lst  = gmst-(ObsSettings.longitude/15.0);

   /* convert from Greenwich mean sidereal time to local mean sidereal
      time and also convert from degrees to hours */

   if (*lst<0) *lst = *lst+24.0;
   if (*lst>=24.0) *lst = *lst-24.0;
}

void ShowAstrometryWindow(void) {

	char Message[160], buffer[80];
	int hours, mins, degs;
	float secs;

	Form1::StatusPrint("*** Info - Loading image into astrometry window.\n");
	usleep(500000);
	loadImageAstrometry(ccd->Image.light_frame.frame, ccd->Image.light_frame.x,
	     ccd->Image.light_frame.y, ccd->Image.light_frame.w,
	     ccd->Image.light_frame.h, ccd->Image.light_frame.binning);
	AstrometryWindow::FormPtr->ClearFlippedCheckBoxes();
	if (plateSolution.status != 0) {
		plateStars.numStars = 0;
		refStars.numStars = 0;
		Form1::StatusPrint("*** Info - Searching stellar database for stars in image field.\n");
		usleep(500000);
		loadRefChartAstrometry(&ccd->Image);
		sprintf_s(Message, sizeof(Message), "*** Info - Found %d reference stars\n", refStars.numStars);
		Form1::StatusPrint(Message);
	} else {
		AstrometryWindow::FormPtr->SetSolutionStatusTextBox("Okay");
		sprintf_s(buffer, sizeof(buffer), "%f", plateSolution.coeffs[0]);
		AstrometryWindow::SetATextBox(buffer);
		sprintf_s(buffer, sizeof(buffer), "%f", plateSolution.coeffs[1]);
		AstrometryWindow::SetBTextBox(buffer);
		sprintf_s(buffer, sizeof(buffer), "%f", plateSolution.coeffs[2]);
		AstrometryWindow::SetCTextBox(buffer);
		sprintf_s(buffer, sizeof(buffer), "%f", plateSolution.coeffs[3]);
		AstrometryWindow::SetDTextBox(buffer);
		sprintf_s(buffer, sizeof(buffer), "%f", plateSolution.coeffs[4]);
		AstrometryWindow::SetETextBox(buffer);
		sprintf_s(buffer, sizeof(buffer), "%f", plateSolution.coeffs[5]);
		AstrometryWindow::SetFTextBox(buffer);
		plateSolution.PixelScale = (plateSolution.coeffs[1]*15.0*3600.0*Math::Cos(plateSolution.coeffs[3]*DEG2RAD)
			- plateSolution.coeffs[5]*3600.0)/2.0;
		sprintf_s(buffer, sizeof(buffer), "%f \"/pixel", plateSolution.PixelScale);
		AstrometryWindow::SetScaleTextBox(buffer);
		Pixel2Equatorial(ccd->Image.light_frame.w/2.0, ccd->Image.light_frame.h/2.0,
			&plateSolution.FieldCenterRA, &plateSolution.FieldCenterDEC);
		ConvertRAtoHMS(plateSolution.FieldCenterRA, &hours, &mins, &secs);
		sprintf_s(buffer, sizeof(buffer), "%02d:%02d:%04.2f", hours, mins, secs);
		AstrometryWindow::FormPtr->SetCenterRATextBox(buffer);
		ConvertDECtoDMS(plateSolution.FieldCenterDEC, &degs, &mins, &secs);
		sprintf_s(buffer, sizeof(buffer), "%03d:%02d:%04.2f", degs, mins, secs);
		AstrometryWindow::FormPtr->SetCenterDECTextBox(buffer);
	}
	AstrometryWindow::FormPtr->Show();
}

void ShowInitializeAstrometryDialog(void) {

	char buffer[80];

	if (! InitializeAstrometryDialogExists) {
		gcnew InitializeAstrometryDialog();
	}

	sprintf_s(buffer, sizeof(buffer), "%6.3lf", ccd->Image.plateSolution.PixelScale);
	InitializeAstrometryDialog::FormPtr->SetPixelScaleTextBox(buffer);
	sprintf_s(buffer, sizeof(buffer), "%6.3lf", ccd->Image.plateSolution.InitFieldCenterRA);
	InitializeAstrometryDialog::FormPtr->SetFieldCenterRATextBox(buffer);
	sprintf_s(buffer, sizeof(buffer), "%6.3lf", ccd->Image.plateSolution.InitFieldCenterDEC);
	InitializeAstrometryDialog::FormPtr->SetFieldCenterDECTextBox(buffer);
	
	InitializeAstrometryDialog::FormPtr->ShowTheDialog();
}

bool loadRefChartAstrometry(IMAGE *image) {

	double CenterRA, CenterDEC, PixelScale;
	double MinRA, MaxRA, MinDEC, MaxDEC, FieldWidthHours, FieldHeightDegs, ra, dec;
	int fullw, fullh, pictboxfullw, pictboxfullh, i, imageYear, delYear;

	// Get "rough" RA & DEC of image center

	if (plateSolution.status != 0) {
		CenterRA = image->plateSolution.InitFieldCenterRA;
		CenterDEC = image->plateSolution.InitFieldCenterDEC;
		PixelScale = image->plateSolution.PixelScale;
	} else {
		CenterRA = image->plateSolution.FieldCenterRA;
		CenterDEC = image->plateSolution.FieldCenterDEC;
		PixelScale = image->plateSolution.PixelScale;
	}
	fullw = image->light_frame.w;
	fullh = image->light_frame.h;
	FieldWidthHours = PixelScale*fullw/3600.0/15.0/Math::Cos(CenterDEC*DEG2RAD);
	FieldHeightDegs = PixelScale*fullh/3600.0;
	MinRA = CenterRA - FieldWidthHours/2.0;
	if (MinRA < 0.0) MinRA += 24.0;
	if (MinRA > 24.0) MinRA -= 24.0;
	MaxRA = MinRA + FieldWidthHours;
	if (MaxRA > 24.0) MaxRA -= 24.0;
	MinDEC = CenterDEC - FieldHeightDegs/2.0;
	if (MinDEC < -90.0) MinDEC = -90.0;
	if (MinDEC > 90.0) MinDEC = 90.0;
	MaxDEC = MinDEC + FieldHeightDegs;
	if (MaxDEC > 90.0) MaxDEC = 90.0;
	if (MinDEC >= MaxDEC) MinDEC = MaxDEC - FieldHeightDegs;

	// Go get list of Ref. stars in this field

	GetRefStarsFromUSNOB1(MinRA, MaxRA, MinDEC, MaxDEC, MAX_MAG_REF_STARS, &refStars);

	pictboxfullw = AstrometryWindow::FormPtr->ChartPictureBox->Size.Width;
	pictboxfullh = AstrometryWindow::FormPtr->ChartPictureBox->Size.Height;
	refStars.ChartXScale = FieldWidthHours/pictboxfullw;
	refStars.ChartYScale = FieldHeightDegs/pictboxfullh;
	refStars.ChartMinRA = MinRA;
	refStars.ChartMinDEC = MinDEC;
	sscanf_s(image->light_frame.UTDATE, "%4d", &imageYear);
	delYear = imageYear - 2000;
	for (i = 0; i < refStars.numStars; i++) {
		refStars.Marked[i] = false;
		ra = refStars.RA[i] + (refStars.ProperMotionRA[i]*delYear) / 3600.0 * 24.0/360.0;
		dec = refStars.DEC[i] + (refStars.ProperMotionDEC[i]*delYear)/3600.0;
		refStars.x[i] = pictboxfullw - ((int)((ra - refStars.ChartMinRA) / refStars.ChartXScale));
		refStars.y[i] = pictboxfullh - ((int)((dec - refStars.ChartMinDEC) / refStars.ChartYScale));
	}

	AstrometryWindow::FormPtr->Refresh();

	return true;

}


bool GetRefStarsFromUSNOB1(double MinRA, double MaxRA, double MinDEC, double MaxDEC, double MaxMag, REFSTARS *refStars) {

	// Local defines

#define RAIndex 0
#define SPDIndex 4
#define PMIndex 8
#define BMagIndex 20
#define RMagIndex 24

	// Local variables

	int SPDMin, SPDMax;					// South Pole Distance (degrees)
	int SPDMinInTenths, SPDMaxInTenths;
	int SPD, Tenths;
	int nRecordsRead, value;
	int StellarProb;
	char FileName[160];					// USNOB file name covering region minimum dec
	char message[200];
	unsigned char record[80];			// read buffer for each star record
	double RA_arcsecs, RA_hours;
	double DEC_deg;
	double RMag;
	FILE *fptr;

	// Convert DEC into south pole distance in degrees & tenths

	SPDMin = (int)(MinDEC + 90.0);
	SPDMinInTenths = (int)(10.0*(MinDEC+90.0));
	SPDMax = (int)(MaxDEC + 90.0);
	SPDMaxInTenths = (int)(10.0*(MaxDEC+90.0));

	// Loop through all USNOB files covering this region

	refStars->numStars = 0;
	for (Tenths = SPDMinInTenths; Tenths <= SPDMaxInTenths; Tenths++) {
		SPD = (Tenths / 10);
		if (refStars->numStars >= MAXNUMREFSTARS)
			break;
		sprintf_s(FileName, sizeof(FileName), "%s\\%03i\\b%04i.cat", USNOB_CATALOG_PATH, SPD, Tenths);
		fopen_s(&fptr, FileName, "rb");
		if (fptr == NULL) {
			sprintf_s(message, sizeof(message), "*** Warning - Can't open USNOB file: %s (GetRefStarsFromUSNOB)\n",
				FileName);
			Form1::StatusPrint(message);
			return false;
		}
		while (true) {
			nRecordsRead = fread(record, sizeof(record), 1, fptr);
			if (nRecordsRead != 1) {
				fclose(fptr);
				break;
			}
			memcpy_s(&value, sizeof(value), &record[RAIndex], 4);
			RA_arcsecs = (float)(value / 100.0);
			RA_hours = (float)(RA_arcsecs*0.0000185185);		//  0.0000185185 = 24.0/360.0 / 3600.0
			if ((RA_hours < MinRA) || (RA_hours > MaxRA))
				continue;
			memcpy_s(&value, sizeof(value), &record[SPDIndex], 4);
			DEC_deg = (float)(value * 0.00000277778 - 90.0); // 0.00000277778 = 1.0/100 / 3600.0
			if ((DEC_deg < MinDEC) || (DEC_deg > MaxDEC))
				continue;
			memcpy_s(&value, sizeof(value), &record[RMagIndex], 4);
			RMag = (value % 10000) / 100.0;
			StellarProb = (int)(value / 1.0e8);
			if ((RMag > MaxMag) || (RMag <= 0.0))
				continue;
//			if (StellarProb < 3)
//				continue;
			memcpy_s(&value, sizeof(value), &record[PMIndex], 4);
			refStars->ProperMotionRA[refStars->numStars]= (value % 10000) * 0.002 * cos(DEC_deg*3.14159/180.0); // pm in "/yr
			refStars->ProperMotionDEC[refStars->numStars] = (((int)(value / 10000)) / 10000) * 0.002;           // pm in "/yr
			refStars->RA[refStars->numStars] = RA_hours;
			refStars->DEC[refStars->numStars] = DEC_deg;
			refStars->Mag[refStars->numStars++] = RMag;
			if (refStars->numStars > MAXNUMREFSTARS) {
				sprintf_s(message, sizeof(message), "*** Warning - Too many reference stars (%d), truncated to %d\n",
					refStars->numStars, MAXNUMREFSTARS);
				MessageBox(message, OKAY, true);
				break;
			}
		}
	}

	return true;
}


bool Pixel2Equatorial(double x, double y, double *ra, double *dec) {

	double *coeffs;

	if (ccd->Image.plateSolution.status != 0)
		return false;

	coeffs = ccd->Image.plateSolution.coeffs;
	*ra = coeffs[0] + coeffs[1]*x + coeffs[2]*y;
	*dec = coeffs[3] + coeffs[4]*x + coeffs[5]*y;
	return true;
}

bool Equatorial2Pixel(double ra, double dec, double *x, double *y) {

	double a, b, c, d, e, f, *coeffs, denom;

	if (ccd->Image.plateSolution.status != 0)
		return false;

	coeffs = ccd->Image.plateSolution.coeffs;
	denom = coeffs[5]*coeffs[1] - coeffs[2]*coeffs[4];
	a = (coeffs[2]*coeffs[3]-coeffs[5]*coeffs[0])/denom;
	b = coeffs[5]/denom;
	c = - coeffs[2]/denom;
	denom = coeffs[4]*coeffs[2] - coeffs[1]*coeffs[5];
	d = (coeffs[1]*coeffs[3]-coeffs[4]*coeffs[0])/denom;
	e = coeffs[4]/denom;
	f = - coeffs[1]/denom;
	*x = a + b*ra + c*dec;
	*y = d + e*ra + f*dec;
	return true;
}

void ConvertRAtoHMS(double ra, int *hours, int *mins, float *secs) {

	*hours = ((int) ra);
	*mins = ((int) ((ra - *hours)*60.0));
	*secs = ((float) ((ra - *hours - *mins/60.0)*3600.0));
	return;
}
void ConvertDECtoDMS(double dec, int *degs, int *mins, float *secs){
	
	*degs = ((int) dec);
	*mins = ((int) (fabs(dec-*degs)*60.0));
	*secs = ((float) ((fabs(dec-*degs) - *mins/60.0)*3600.0));
	return;
}
void ConvertDMStoDEC(int degs, int mins, float secs, double *dec) {

	*dec = ((double) (abs(degs) + mins/60.0 + secs/3600.0));
	if (degs < 0) *dec = - *dec;
}
void ConvertHMStoRA(int hours, int mins, float secs, double *ra) {

	*ra = ((double) (hours + mins/60.0 + secs/3600.0));
	return;
}

bool BumpScope(double delra, double deldec) {

	bool status;
	char message[160];
	double parms[2];

	if ((fabs(delra) > 1.0) || (fabs(deldec) > 1.0)) {
		sprintf_s(message, sizeof(message), "*** Warning - bump too big: (%lf,%lf) (BumpScope)\n", delra, deldec);
		Form1::StatusPrint(message);
		return false;
	}
	parms[0] = delra;
	parms[1] = deldec;
	status = SendOSUrobMessage('B', NULL, parms);
	return status;
}

bool SendOSUrobMessage(char Command, int *IntParms, double *DoubleParms) {
	
	char message[160], buffer[160];;
	int nTries, hours, ra_mins, degs, dec_mins, nItems, status;
	int FWPosition;
	float ra_secs, dec_secs;
	FILE *fptr;
	struct _stat statbuf;
	bool success;
	static bool Busy=false;

	if (Command == 'R') {
		Busy = false;
		return true;
	}

	if (Busy) {
		if (GlobalDebug) {
			Form1::StatusPrint("*** Debug - SendOSUrobMessage is busy...\n");
		}
		return false;
	}

	Busy = true;

	// Construct message to OSUrob

	success = false;
	nTries = 20;
	switch (Command) {
		case 'B': // bump scope position
			sprintf_s(message, sizeof(message), "B %8.5lf %8.5lf\n", DoubleParms[0], DoubleParms[1]);
			break;
		case 'f': // bump focus position
			sprintf_s(message, sizeof(message), "f %f\n", ((float) *DoubleParms));
			break;
		case 'G': // get scope position
			sprintf_s(message, sizeof(message), "G\n");
			break;
		case 'F': // Move filter wheel to position
			sprintf_s(message, sizeof(message), "F %d\n", *IntParms);
			break;
		case 'g': // Get filter wheel position
			sprintf_s(message, sizeof(message), "g\n");
			break;
		default:
			sprintf_s(message, sizeof(message), "*** Warning - Bad Command for OSUrob message: %c (SendOSUrobMessage)\n",
				Command);
			Form1::StatusPrint(message);
			Busy = false;
			return success;
			break;
	}

	status = _stat(MESSAGEFILENAME, &statbuf);
	if (status == 0) {
		if (GlobalDebug) {
			sprintf_s(buffer, sizeof(buffer),
				"*** Warning - OSUrob message file exists, can't send message: %s", message);
			Form1::StatusPrint(buffer);
		}
		Busy = false;
		return success;
	} else {
		_unlink(RESPONSEFILENAME);
		fopen_s(&fptr, MESSAGEFILENAME, "w");
		if (fptr == NULL) {
			if (GlobalDebug) 
				Form1::StatusPrint("*** Warning - Can't open OSUrob message file.\n");
			Busy = false;
			return success;
		}
		fprintf_s(fptr, "%s", message);
		fclose(fptr);
		fptr = NULL;
		do {
			fopen_s(&fptr, RESPONSEFILENAME, "r");
			if (fptr != NULL) {
				switch (Command) {
					case 'G': // get scope position
						if (fgets(message, sizeof(message), fptr) != NULL) {
							if (GlobalDebug) {
								sprintf_s(buffer, sizeof(buffer), "*** Debug - Got response from OSUrob: %s\n",
									message);
							}
							nItems = sscanf_s(message, "Success: %d:%d:%f %d:%d:%f", &hours, &ra_mins, &ra_secs,
								&degs, &dec_mins, &dec_secs);
							if (nItems == 6) {
								DoubleParms[0] =  hours + ra_mins/60.0 + ra_secs/3600.0;
								DoubleParms[1] = abs(degs) + dec_mins/60.0 + dec_secs/3600.0;
								if (degs < 0.0) DoubleParms[1] = - DoubleParms[1];
								success = true;
							} else if (strcmp(message,"Success: Unknown Unknown") == 0) {
								DoubleParms[0] = DoubleParms[1] = 0.0;
								success = true;
							}
						}
						if (GlobalDebug && (! success))
							Form1::StatusPrint("*** Warning - Can't get scope position from OSUROB\n");
						break;
					case 'g': // get filter wheel position
						if (fgets(message, sizeof(message), fptr) != NULL) {
							if (GlobalDebug) {
								sprintf_s(buffer, sizeof(buffer), "*** Debug - Got response from OSUrob: %s\n",
									message);
							}
							nItems = sscanf_s(message, "Success: %d", &FWPosition);
							if (nItems == 1) {
								IntParms[0] = FWPosition;
								success = true;
							}
						}
						if (GlobalDebug && (! success))
							Form1::StatusPrint("*** Warning - Can't get filterwheel position from OSUROB\n");
						break;
					default:  // every other command
						if (fgets(message, sizeof(message), fptr) != NULL) {
							if (strcmp(message, "Success") == 0) {
								success = true;
							}
						}
						if (GlobalDebug && (! success)) {
							Form1::StatusPrint("*** Warning - No success from OSUROB\n");
							Form1::StatusPrint(message);
						}
						break;
				}
				fclose(fptr);
				_unlink(RESPONSEFILENAME);
			}
			nTries--;
			usleep(1000000);
		} while ((nTries > 0) && (! success));
		if (nTries <= 0) {
			if (GlobalDebug) 
				Form1::StatusPrint("*** Warning - Timed out waiting for OSUrob to do function.\n");
			_unlink(MESSAGEFILENAME);
			success = false;
		}
	}

	Busy = false;
	return success;
}

void UpdatePlateSolution(CCD *ccd) {

	STAR *sptr;
	int i;
	bool found;
	double delx, dely, dist, ra, dec;

	// Check if we have plates stars  (was plate solution done during this session?)

	if (plateStars.numStars <= 0) {
		Form1::StatusPrint("*** Warning - Can't update plate solution for new image, no plate stars");
		return;
	}

	// Find first list star to find (x,y) shift

	sptr = CurrentStarList;
	found = false;
	for (i=0; i<plateStars.numStars; i++) {
		delx = sptr->x - plateStars.pixelX[i];
		dely = sptr->y - plateStars.pixelY[i];
		dist = delx*delx + dely*dely;
		if (dist > 0.0) dist = Math::Sqrt(dist);
		if (dist < 10.0) {
			found = true;
			break;
		}
	}
	if (! found) {
		Form1::StatusPrint("*** Warning - Can't match a plate star to current star list (UpdatePlateSolution)\n");
		return;
	}
	Pixel2Equatorial((double) sptr->x, (double) sptr->y, &ra, &dec);
	ccd->Image.plateSolution.coeffs[0] -= (ra - plateStars.RA[i]);
	ccd->Image.plateSolution.coeffs[3] -= (dec - plateStars.DEC[i]);

}

bool DoCalibrations(char *DarkDir, int DarkOption, char *FlatDir, int FlatOption, CCD *ccd) {

	char Message[160];
	int i, d;
	bool gotFlat, gotDark, Success;

	// Dark frame

	gotDark = false;
	Success = true;
	switch (DarkOption) {
		case 0:  // auto dark
			MessageBox("*** Info - Can't do automatic darks on existing images", OKAY, true);
			break;
		case 1:  // force dark
			MessageBox("*** Info - Can't do force dark on existing images", OKAY, true);
			break;
		case 2:  // dark frame from file
			gotDark = (bool) readDark(DarkDir, &ccd->Image);
			if (! gotDark) {
				sprintf_s(Message,sizeof(Message),"*** Warning - Couldn't find compatible dark frame"
					"in directory: %s aborting\n", DarkDir);
				Form1::StatusPrint(Message);
				Success = false;
			}
			break;
		case 3:  // no dark
			break;
	}
	if (gotDark) {
		for (i = ccd->Image.light_frame.h*ccd->Image.light_frame.w; --i >= 0; ) {
			d = ccd->Image.light_frame.frame[i] - ccd->Image.dark_frame.frame[i];
			if (d < 0)
				d = 0;
			else if (d > 65535)
				d = 65535;
			ccd->Image.light_frame.frame[i] = d;
		}
		ccd->Image.saved = false;
	}
	
	// Flat frame

	gotFlat = false;
	switch (OpenCalDialog::FormPtr->FlatOption) {
		case 0:  // don't do flat
			break;
		case 1:  // reuse flat
			MessageBox("*** Info - Can't reuse flat frame with existing image", OKAY, true);
			break;
		case 2:  // use flat from file
			gotFlat = readFlat(FlatDir, ccd);
			if (! gotFlat) {
				sprintf_s(Message, sizeof(Message), "*** Warning - couldn't find compatible flat"
					" frame in directory: %s, aborting\n", FlatDir);
				Form1::StatusPrint(Message);
				Success = false;
			}
			break;
	}
	if (gotFlat) {
		flattenFrame(&ccd->Image.light_frame, &ccd->FlatImage.light_frame);
		ccd->Image.saved = false;
	}

	return Success;

}

bool ComputePlateSolution(PLATESOLU *solution) {

	double  XYE[2][100], XYM[2][100], ra, dec, delra, deldec, sumdev;
	int i, hours, degs, mins;
	float secs;
	char buffer[80];
	bool success;
	
	// Check to see if we have enough matched ref. stars & objects
	
	if (plateStars.numStars < 3) {
		MessageBox("*** Info - Haven't matched enough stars, need at least 3", OKAY, true);
		return false;
	}
	
	// Put data into arrays for fixy
	
	for (i=0; i<plateStars.numStars; i++) {
		XYM[0][i] = plateStars.pixelX[i];
		XYM[1][i] = plateStars.pixelY[i];
		XYE[0][i] = plateStars.RA[i];
		XYE[1][i] = plateStars.DEC[i];
	}
	sla_FITXY(6, plateStars.numStars, XYE, XYM, plateSolution.coeffs, &plateSolution.status);
	sprintf_s(buffer, sizeof(buffer), "%d", plateSolution.status);
	AstrometryWindow::SetSolutionStatusTextBox(buffer);
	if (plateSolution.status == 0) {
		AstrometryWindow::FormPtr->SetSolutionStatusTextBox("Okay");
		sprintf_s(buffer, sizeof(buffer), "%f", plateSolution.coeffs[0]);
		AstrometryWindow::SetATextBox(buffer);
		sprintf_s(buffer, sizeof(buffer), "%f", plateSolution.coeffs[1]);
		AstrometryWindow::SetBTextBox(buffer);
		sprintf_s(buffer, sizeof(buffer), "%f", plateSolution.coeffs[2]);
		AstrometryWindow::SetCTextBox(buffer);
		sprintf_s(buffer, sizeof(buffer), "%f", plateSolution.coeffs[3]);
		AstrometryWindow::SetDTextBox(buffer);
		sprintf_s(buffer, sizeof(buffer), "%f", plateSolution.coeffs[4]);
		AstrometryWindow::SetETextBox(buffer);
		sprintf_s(buffer, sizeof(buffer), "%f", plateSolution.coeffs[5]);
		AstrometryWindow::SetFTextBox(buffer);
		plateSolution.PixelScale = (Math::Abs(plateSolution.coeffs[1])*15.0*3600.0*
			Math::Cos(Math::Abs(plateSolution.coeffs[3])*DEG2RAD)
			+ Math::Abs(plateSolution.coeffs[5])*3600.0)/2.0;
		sprintf_s(buffer, sizeof(buffer), "%f \"/pixel", plateSolution.PixelScale);
		AstrometryWindow::SetScaleTextBox(buffer);
		memcpy_s(&ccd->Image.plateSolution, sizeof(ccd->Image.plateSolution), &plateSolution,
			sizeof(plateSolution));
		Pixel2Equatorial(ccd->Image.light_frame.w/2.0, ccd->Image.light_frame.h/2.0,
			&plateSolution.FieldCenterRA, &plateSolution.FieldCenterDEC);
		ConvertRAtoHMS(plateSolution.FieldCenterRA, &hours, &mins, &secs);
		sprintf_s(buffer, sizeof(buffer), "%02d:%02d:%04.2f", hours, mins, secs);
		AstrometryWindow::FormPtr->SetCenterRATextBox(buffer);
		ConvertDECtoDMS(plateSolution.FieldCenterDEC, &degs, &mins, &secs);
		sprintf_s(buffer, sizeof(buffer), "%03d:%02d:%04.2f", degs, mins, secs);
		AstrometryWindow::FormPtr->SetCenterDECTextBox(buffer);
		sumdev = 0.0;
		for (i=0; i<plateStars.numStars; i++) {
			Pixel2Equatorial(plateStars.pixelX[i], plateStars.pixelY[i], &ra, &dec);
			delra = (ra - plateStars.RA[i])*Math::Cos(plateStars.DEC[i]*DEG2RAD)*15.0;
			deldec = dec - plateStars.DEC[i];
			sumdev += delra*delra + deldec*deldec;
		}
		sumdev /= plateStars.numStars;
		sumdev = Math::Sqrt(sumdev)*3600.0;
		sprintf_s(buffer, sizeof(buffer), "%lf \"", sumdev);
		AstrometryWindow::FormPtr->SetEstErrorTextBox(buffer);
		plateSolution.ErrorEst = sumdev;
		memcpy_s(&ccd->Image.plateSolution, sizeof(ccd->Image.plateSolution), &plateSolution,
			sizeof(plateSolution));
		Form1::StatusPrint("*** Info - Searching for reference stars...\n");
		usleep(200000);
		loadRefChartAstrometry(&ccd->Image);
		success = true;
	} else if (plateSolution.status == -1) {
		MessageBox("*** Warning - Internal error - Illegal ITYPE in sla_FITXY, no solution computed", OKAY, true);
		success = false;
	} else if (plateSolution.status == -2) {
		MessageBox("*** Warning - Internal error - Insufficent data in sla_FITXY, no solution computed", OKAY, true);
		success = false;
	} else if (plateSolution.status == -3) {
		MessageBox("*** Warning - Singular solution in sla_FITXY, no solution computed", OKAY, true);
		success = false;
	}

	return success;
}

bool AcquireGuideFrame(CCD *ccd, SINGLESETTINGS *Settings) {
	
	static bool Busy=false;
	int i, d, nbytes, darkNeeded, gotDark, success;
	char Message[80];
	double ccd_temp, dark_temp;
	StartExposureParams expose;
	StartReadoutParams readout;
	IMAGE *Image;
	
	if (! ccd->Linked) {
		Form1::StatusPrint("*** WARNING - Can't start exposure, link to tracking camera first.\n");
		return false;
	}
	
	if (Busy) {
		Form1::StatusPrint("*** Warning - Guide ccd busy, try again later...\n");
		return false;
	}
	
	Busy = true;
	Image = &ccd->Image;
	expose.ccd = Settings->whichCCD;
	expose.exposureTime = ((int) (100.0*Settings->exposureTime));
	expose.abgState = 0;
	readout.ccd = expose.ccd;
	readout.readoutMode = Settings->binning;
	readout.left = Settings->x;
	readout.top = Settings->y;
	readout.width = Settings->w;
	readout.height = Settings->h;
	
	success = GetCCDTemperature(ccd, &ccd_temp);
	if (! success) {
		Form1::StatusPrint("*** WARNING - Can't get ccd temperature, aborting exposure...\n");
		Busy = false;
		return false;
	}
	Image->darkOnly = false;
	Image->lightOnly = false;
	Image->light_frame.binning = Settings->binning;
	Image->light_frame.whichCCD = Settings->whichCCD;
	Image->light_frame.x = Settings->x;
	Image->light_frame.y = Settings->y;
	Image->light_frame.w = Settings->w;
	Image->light_frame.h = Settings->h;
	Image->light_frame.temp = (float) ccd_temp;
	Image->light_frame.exposure = Settings->exposureTime;
	Image->Filter[0] = 'C';
	Image->Filter[1] = '\000';
	dark_temp = Image->dark_frame.temp;
	strcpy_s(Image->light_frame.UT, sizeof(Image->light_frame.UT), "");
	strcpy_s(Image->light_frame.UTDATE, sizeof(Image->light_frame.UTDATE), "");
	strcpy_s(Image->dark_frame.UT, sizeof(Image->dark_frame.UT), "");
	strcpy_s(Image->dark_frame.UTDATE, sizeof(Image->dark_frame.UTDATE), "");
	
	gotDark = false;
	switch (Settings->darkOption) {
		case 1:
			gotDark = true;
			break;
		case 2:
			gotDark = false;
			Image->lightOnly = false;
			break;
		case 3:
			gotDark = readDark(Settings->DarkDir, Image);
			if (! gotDark) {
				sprintf_s(Message, sizeof(Message), "*** Warning - Couldn't find compatible dark frame in directory: %s aborting\n",
					Settings->DarkDir);
				Form1::StatusPrint(Message);
				return false;
			}
			dark_temp = Image->dark_frame.temp;
			Image->lightOnly = true;
			break;
		case 4:
			gotDark = false;
			Image->lightOnly = true;
			break;
	}
	
	/* allocate buffers */
	
	nbytes = readout.width*readout.height*sizeof(short);
	//Image->light_frame.frame = (unsigned short *) realloc(Image->light_frame.frame, nbytes);
	//Image->dark_frame.frame = (unsigned short *) realloc(Image->dark_frame.frame, nbytes);
	
	/* Check if dark frame needed */
	
	if ((Settings->darkOption == 1) ||(Settings->darkOption == 3)) {
		darkNeeded = ((fabs(dark_temp-ccd_temp) > MAXTEMPDIFF) || (! Image->dark_frame.active) ||
			(Image->dark_frame.exposure != Settings->exposureTime) ||
			(Settings->binning != Image->dark_frame.binning) ||
			(Settings->whichCCD != Image->dark_frame.whichCCD) ||
			(Settings->x != Image->dark_frame.x) ||
			(Settings->y != Image->dark_frame.y) ||
			(Settings->w != Image->dark_frame.w) ||
			(Settings->h != Image->dark_frame.h));
		darkNeeded = (darkNeeded || (! gotDark)); /* gotdark set by option 3 */
		if (darkNeeded) {
			gotDark = true;
			Image->lightOnly = false;
		} else 
			Image->lightOnly = true;
	}
	
	/* Do exposure */
	
	CancelCurrentGuidingAcquire = false;
	success = snapTracking(ccd, &expose, &readout, Image);
	if (CancelCurrentGuidingAcquire || (! success)) {
		Busy = false;
		return false;
	}
	
	/* subtract out the dark, and adjust the image if required */
	
	if (gotDark) {
		for (i = readout.width*readout.height; --i >= 0; ) {
			d = Image->light_frame.frame[i] - Image->dark_frame.frame[i];
			if (d < 0)
				d = 0;
			else if (d > 65535)
				d = 65535;
			Image->light_frame.frame[i] = d;
		}
	}
	
	/* Display Image */

	loadImageTracking(Image->light_frame.frame, Image->light_frame.x, Image->light_frame.y, Image->light_frame.w,
		Image->light_frame.h, Image->light_frame.binning);
	
	Image->saved = false;
	Image->Filter[0] = 'C';
	Image->Filter[1] = '\000';
	strcpy_s(Image->FileName, sizeof(Image->FileName), "");
	strcpy_s(Image->ObjectName, sizeof(Image->ObjectName), "");
	
	Busy = false;
	return true;
}

bool autoGuider(void) { 

	static int Busy=false;
	char buffer[80];
	int max, xmin, xmax, ymin, ymax;
	float diffMax, StarX, StarY;
	double deltaX, deltaY, DeltaRA, DeltaDEC;
	bool gotFrame, Found;
	
	//  FRAME *frame;
	
	if (Busy)
		return false;
	
	Busy = true;
	if (GuidingSlitSettings.Running == false) {  // Turn off guiding
		Busy = false;
		return false;
	}
	
	// Acquire guiding frame
	
	Form1::StatusPrint("*** INFO - Acquiring autoguiding frame\n");
	
	DontShowGuidingProgress = true;
	gotFrame = AcquireGuideFrame(&TrackingCCD, &guideImageSettings);
	DontShowGuidingProgress = false;
	if (! gotFrame) {
		Busy = false;
		return false;   // skip this one, but keep trying
	}
	
	// Find star in new image and target-star difference
	
	max = 0;
	xmin = (int) Math::Round(GuidingSlitSettings.TargetX - 10);
	xmax = xmin + 20;
	ymin = (int) Math::Round(GuidingSlitSettings.TargetY - 10);
	ymax = ymin + 20;
	Found = FindStar(&TrackingCCD.Image.light_frame, xmin, ymin, xmax, ymax, &StarX, &StarY, &max);
	
	// Debuging simulation section
	
	if (! Found) {
		if (GlobalDebug)
			Form1::StatusPrint("*** Debug - Guide star not found...\n");
		Busy = false;
		return false;  // skip this bad image, but try again
	}

	diffMax = GuidingSlitSettings.TargetMax - max;
	diffMax = ((float) fabs(diffMax)/GuidingSlitSettings.TargetMax);
	
	// Compute target - star difference in pixels
	
	deltaX = (GuidingSlitSettings.TargetX - StarX);
	deltaY = - (GuidingSlitSettings.TargetY - StarY);
	DeltaRA = - (deltaX * GuidingSlitSettings.XScale);
	DeltaDEC = - (deltaY * GuidingSlitSettings.YScale);

	sprintf_s(buffer, sizeof(buffer), "%4.1f", DeltaRA);
	GuideFrameWindow::FormPtr->SetXOffsetTextBox(buffer);
	sprintf_s(buffer, sizeof(buffer), "%4.1f", DeltaDEC);
	GuideFrameWindow::FormPtr->SetYOffsetTextBox(buffer);
	
	if (GlobalDebug) {
		sprintf_s(buffer, sizeof(buffer), "*** DEBUG - DelRA: %f, DelDEC: %f\n", DeltaRA, DeltaDEC);
		Form1::StatusPrint(buffer);
	}
	
	if ((fabs(DeltaRA) > 0.5) || (fabs(DeltaDEC) > 0.5)) {
		if (GlobalDebug) 
			Form1::StatusPrint("*** DEBUG - Telling scope to move...\n");
		BumpScope(DeltaRA/3600.0, DeltaDEC/3600.0);  // converting to degrees
	}
	
	Busy = false;
	return true;
}

bool CalibrateSlitEnd(int *x, int *y) {
	
	char buffer[80];
	
	GuideFrameWindow::FormPtr->GetStarXTextBox(buffer);
	sscanf_s(buffer, "%d", x);
	GuideFrameWindow::FormPtr->GetStarYTextBox(buffer);
	sscanf_s(buffer, "%d", y);

	return true;
}


void SetScopePositionPolling(bool On)
{
	if (On) {
		Form1::CCDAutoForm->DontGetScopePosition = false;
	} else {
		Form1::CCDAutoForm->DontGetScopePosition = true;
	}
}


void ShowUpdateMX916Keywords(void) {

	char buffer[80];
	struct tm broken_time;
	__time64_t CurTime;

	if (! UpdateMX916KeywordsExists) {
		gcnew UpdateMX916Keywords();
	}

	time(&CurTime);
    _gmtime64_s(&broken_time, &CurTime);
	if (strlen(ccd->Image.light_frame.UT) <= 0) {
		strftime(buffer,sizeof(buffer),"%H:%M:%S",&broken_time);
	} else {
		strcpy_s(buffer, sizeof(buffer), ccd->Image.light_frame.UT);
	}
	UpdateMX916Keywords::FormPtr->SetOBSUTTextBox(buffer);
	if (strlen(ccd->Image.light_frame.UTDATE) <= 0) {
		strftime(buffer,sizeof(buffer),"%Y-%m-%d", &broken_time);
	} else {
		strcpy_s(buffer, sizeof(buffer), ccd->Image.light_frame.UTDATE);
	}
	UpdateMX916Keywords::FormPtr->SetOBSDateTextBox(buffer);

	if (strcmp(ccd->Image.ObjectName,"none") == 0) {
		UpdateMX916Keywords::FormPtr->SetObjectNameTextBox(singleSettings.ObjectName);
	} else {
		UpdateMX916Keywords::FormPtr->SetObjectNameTextBox(ccd->Image.ObjectName);
	}
	sprintf_s(buffer, sizeof(buffer), "%5.2f", ccd->gain);
	UpdateMX916Keywords::FormPtr->SetCCDGainTextBox(buffer);
	sprintf_s(buffer, sizeof(buffer), "%5.2f", ccd->readNoise);
	UpdateMX916Keywords::FormPtr->SetCCDReadNoiseTextBox(buffer);
	sprintf_s(buffer, sizeof(buffer), "%8.3f", ccd->Image.light_frame.exposure);
	UpdateMX916Keywords::FormPtr->SetExposureTimeTextBox(buffer);
	UpdateMX916Keywords::FormPtr->SetObservatoryTextBox(ObsSettings.name);
	UpdateMX916Keywords::FormPtr->SetObserverTextBox(ObsSettings.Observer);
	UpdateMX916Keywords::FormPtr->SetProjectTextBox(ObsSettings.Project);

	UpdateMX916Keywords::FormPtr->ShowTheDialog();

}

}

