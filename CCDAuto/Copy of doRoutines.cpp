
//#include <queue.h>
#include "stdafx.h"
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
#include "cbw.h"


//using namespace CCDAuto;

using namespace System::Drawing;

namespace CCDAuto {

/* Support routines */

int MessageBox(char *prompt, int buttons)
{
	switch (buttons) {
		case OKAY:
			if (! OkayDialogExists) {
				gcnew OkayDialog();
			}
			OkayDialog::SetMessage(prompt);
			MessageBoxAnswer = NOANSWER;
			OkayDialog::ShowTheDialog();
			return MessageBoxAnswer;
			break;
		case YESNO:
			if (! YesNoDialogExists) {
				gcnew YesNoDialog();
			}
			YesNoDialog::SetMessage(prompt);
			MessageBoxAnswer = NOANSWER;
			YesNoDialog::ShowTheDialog();
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
  } while (TRUE);

  return;
}

int GetCCDTemperature(CCD *ccd, double *ccd_temp)
{
  int success;

  switch (ccd->make) {
    case SBIG_MAKE:
      success = (pCam_GetCCDTemperature(ccd_temp) == CE_NO_ERROR);
      break;
    case APOGEE_MAKE:
      *ccd_temp = apCam_GetCCDTemperature();
      success = TRUE;
      break;
    case SXPRESS_MAKE:
      *ccd_temp = 999.0;
      success = TRUE;
//      success = spCam_GetCCDTemperature(ccd_temp);
      break;
  }
    
  return success;
}


int InitObjectList(char *fileName)
{
  char Message[80];
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
    return FALSE;
  }

    errStatus = fopen_s(&OBJfptr, fileName, "r");
  //  OBJfptr = fopen("/usr/share/astro/ObjectList.lst","r");
  if (OBJfptr == NULL) {
    sprintf_s(Message, sizeof(Message), "*** Fatal - can't open objects file: %s\n", fileName);
    Form1::StatusPrint(Message);
    return FALSE;
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
      return TRUE;
    }
    if (! AddObject(&obj)) {
      return FALSE;
    }
    nObjects++;
  } while (TRUE);
  fclose(OBJfptr);

  sprintf_s(Message, sizeof(Message), "*** INFO - Read in %d objects\n", nObjects);
  Form1::StatusPrint(Message);

  return TRUE;
}

int AddObject(OBJECT *obj)
{
  char Message[160];
  OBJNODE *optr;

  if (ObjectListHead == NULL) {              /* Empty List */
    ObjectListHead = (OBJNODE *) malloc(sizeof(OBJNODE));
    if (ObjectListHead == NULL) {
      sprintf_s(Message, sizeof(Message),"*** Fatal - Can't allocate memory for Object List\n");
      Form1::StatusPrint(Message);
      return FALSE;
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

  return TRUE;
}

int DeleteObject(char *objectName) {

	int len;
	char Message[160];
	OBJNODE *optr, *prev;

	if (objectName == NULL) return false;

	/* Check if we have any objects in list */

	if (ObjectListHead == NULL) {
		sprintf_s(Message, sizeof(Message),"*** Warning - no objects in Objects Lists...\n");
		Form1::StatusPrint(Message);
		return FALSE;
	}

	/* Find the requested object and return its info if found */

	optr = ObjectListHead;
	prev = NULL;
	len = strlen(objectName);
	if (len == 0)
		return FALSE;
	while (optr != NULL) {
		if (strncmp(optr->obj.name,objectName, len) == 0)
			break;
		prev = optr;
		optr = optr->next;
	}

	if (optr == NULL)
		return FALSE;
	else {
		if (prev == NULL) {
			ObjectListHead = optr->next;
		} else {
			prev->next = optr->next;
		}
		free(optr);
	}
    return TRUE;
}


int GetObjectInfo(char *objectName, OBJECT *objectInfo)
{
  int len;
  char Message[80];
  OBJNODE *optr;

  /* Check if we have any objects in list */

  if (ObjectListHead == NULL) {
    sprintf_s(Message, sizeof(Message),"*** Warning - no objects in Objects Lists...\n");
    Form1::StatusPrint(Message);
    return FALSE;
  }

  /* Find the requested object and return its info if found */

  optr = ObjectListHead;
  len = strlen(objectName);
  if (len == 0)
    return FALSE;
  while (optr != NULL) {
    if (strncmp(optr->obj.name,objectName, len) == 0)
      break;
    optr = optr->next;
  }

  if (optr == NULL) {
      return FALSE;
  } else {
	  memcpy_s(objectInfo, sizeof(OBJECT), &optr->obj, sizeof(OBJECT));
    return TRUE;
  }
}

int SetObjectInfo(char *objectName, OBJECT *objectInfo)
{
  char Message[80];
  int success;
  OBJNODE *optr;

  /* Check if we have any objects in list */

  if (ObjectListHead == NULL) {
    sprintf_s(Message, sizeof(Message),"Warning - no objects in Objects Lists...\n");
    Form1::StatusPrint(Message);
    return FALSE;
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
    success = TRUE;
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
    case APOGEE_MAKE:
      ccd_temp = apCam_GetCCDTemperature();
      sprintf_s(Message, sizeof(Message), "ccd temp: %f\n", ccd_temp);
      Form1::StatusPrint(Message);
      break;
    case SXPRESS_MAKE:
      break;
  }

  return;
}

void doFilterWheel(CCD *ccd, int *status, int Position)
{
  char Message[80];
  int itry;
  CFWParams cfwp;
  CFWResults cfwr;

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
  case APOGEE_MAKE:
//    sprintf_s(Message, sizeof(Message),"Make sure %c filter is placed on camera.",
//	    filterSet[Position-1]);
//    MessageBox(Message,OKAY);
    SetCFW6APosition(Position-1);
    ccd->filterPosition = Position;
    break;
  case SXPRESS_MAKE:
    sprintf_s(Message, sizeof(Message),"Make sure %c filter is placed on camera.",
	    filterSet[Position-1]);
    MessageBox(Message,OKAY);
    ccd->filterPosition = Position;
    break;
  }
}




void writeFITS(IMAGE *Image, int WhichFrame, char *FileName, char *objectName)
{
  char buffer[160];
  int status;
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
    status = fits_read_errmsg(buffer);
	Form1::StatusPrint(buffer);
//    fits_report_error(stderr, status); /* print error report */
	strcpy_s(Image->FileName, sizeof(Image->FileName), "FITS error");
    return;
  }

  /* Create the image */

  naxis = 2;
  naxes[0] = frame->w;
  naxes[1] = frame->h;
  status = 0;
  if (fits_create_img(fptr, bitpix, naxis, naxes, &status)) {
    fits_report_error(stderr, status); /* print error report */
	strcpy_s(Image->FileName, sizeof(Image->FileName), "FITS error");
    return;
  }

  /* Write out the image */

  fpixel = 1;
  nelements = frame->w*frame->h;
  if (fits_write_img(fptr, TUSHORT, fpixel, nelements,
		     frame->frame, &status)) {
    fits_report_error(stderr, status); /* print error report */
	strcpy_s(Image->FileName, sizeof(Image->FileName), "FITS error");
    return;
  }

  /* Update "general" keywords */

  ccdgain = ((float) CCDGAIN);
  readnoise = ((float) READNOISE);
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
    gmtime_s(&broken_time, &frame->time);
    strftime(buffer,sizeof(buffer),"%T",&broken_time);
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
      
  status = GetObjectInfo(objectName, &objectInfo);
  if (status == FALSE) {
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

  /* Close the FITS file */

  status = 0;
  if (fits_close_file(fptr, &status)) {
    fits_report_error(stderr, status); /* print error report */
	strcpy_s(Image->FileName, sizeof(Image->FileName), "FITS error");
    return;
  }

  strcpy_s(Image->FileName,sizeof(Image->FileName),FileName);
  Image->saved = TRUE;

  return;
}

void doUnlinkToCamera(CCD *ccd, int *status)
{
  doSetTempOffCamera(ccd);
  ccd->Linked = FALSE;
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
      status = pCam_SetTemperatureRegulation(TRUE, f);
	  if (status != CE_NO_ERROR) {
		  Form1::StatusPrint("*** WARNING - Can't set temperature regulation...\n");
	      Success = false;
	  } else {
		  sprintf_s(Message, sizeof(Message),"*** Info - Setting cooling to: %5.1f\n", f);
		  Form1::StatusPrint(Message);
		  Success = true;
	  }
      break;
    case APOGEE_MAKE:
      apCam_SetTemperatureRegulation(TRUE,f);
	  sprintf_s(Message, sizeof(Message),"*** Info - Setting cooling to: %5.1f\n", f);
	  Form1::StatusPrint(Message);
	  Success = true;
      break;
    case SXPRESS_MAKE:
      Form1::StatusPrint("*** WARNING - Can't set temperature regulation on "
		  "Starlight Xpress cameras\n");
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
      status = pCam_SetTemperatureRegulation(FALSE, 0.0);
      if (status != CE_NO_ERROR) {
		  Form1::StatusPrint("*** WARNING - Can't turn off temperature regulation...\n");
		  return;
      }
      break;
    case APOGEE_MAKE:
      apCam_SetTemperatureRegulation(FALSE,0);
      break;
    case SXPRESS_MAKE:
      Form1::StatusPrint("*** WARNING - Can't set temperature regulation on "
		  "Starlight Xpress cameras\n");
      break;
  }

  return;
}


void print_stats(unsigned short *b, int w, int h)
{
  char Message[80];

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
  char Message[80], buffer[80];
  unsigned char  *dp;
  double  f, sum, ave;
  float gamma;
  int  d, i, j, min, max, npixels, iave, fullh, fullw;
  Color pixel;

  /* Allocate RGB buffer for image */

  //  fullw = ccd->info.readoutInfo[binning].width;
  //  fullh = ccd->info.readoutInfo[binning].height;
  //  npixels = fullw*fullh;
  //  if ( npixels <= 0) {
    fullw = ccd->Image.light_frame.w;
    fullh = ccd->Image.light_frame.h;
    npixels = fullw * fullh;
    //  }

  if (! CurrentImageWindowExists) {
	  gcnew CurrentImageWindow();
	  CurrentImageWindow::FormPtr->CurrentImageBitmap =
		  (gcnew System::Drawing::Bitmap(fullw,fullh));
	  CurrentImageWindow::FormPtr->CurrentImagePictureBox->Image =
		  CurrentImageWindow::FormPtr->CurrentImageBitmap;
  }

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
  sprintf_s(Message, sizeof(Message),"%d", max);
  CCDAuto::CurrentImageWindow::SetCurrentImageMaxPixTextBox(buffer);
  sprintf_s(Message, sizeof(Message),"%7.1f", ave);
  CCDAuto::CurrentImageWindow::SetCurrentImageAvePixTextBox(buffer);

  dp = RGBBuf;
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
	if (*(sp-1) == 65000) {
//	  dp[RED] = 255;
//	  dp[GREEN] = 0;
//	  dp[BLUE] = 0;
		pixel = Color::FromArgb(255,0,0);
	} else {
		pixel = Color::FromArgb(d,d,d);
//	  dp[RED] = d;
//	  dp[GREEN] = d;
//	  dp[BLUE] = d;
	}
	CurrentImageWindow::FormPtr->CurrentImageBitmap->SetPixel(i,j,pixel);
/*       } else { */
/* 	dp[RED] = 0; */
/* 	dp[GREEN] = 0; */
/* 	dp[BLUE] = 0; */
/*       } */
      dp += 3;
    }
  }

//  widget = lookup_widget(CurrentImageWindow,"CurrentImageDrawingArea");
//  gtk_drawing_area_size(GTK_DRAWING_AREA(widget), fullw, fullh);
//  gtk_widget_show(CurrentImageWindow);

  CurrentImageWindow::ClearMarkedStarList();
  CurrentImageWindow::ShowThisDialog();
}

void loadImageTracking(unsigned short *sp, int x, int y, int w, int h,
		       int binning)
{
  char buffer[80];
  unsigned char  *dp;
  double  f, sum, ave;
  int  d, i, j, min, max, npixels, iave, fullh, fullw;

  /* Allocate RGB buffer for image */

  fullw = ccd->info1.readoutInfo[binning].width;
  fullh = ccd->info1.readoutInfo[binning].height;
  npixels = fullw*fullh;
  if ( npixels <= 0) {
    fullw = guideImage.light_frame.w;
    fullh = guideImage.light_frame.h;
    npixels = fullw * fullh;
  }
  RGBGuideBuf = (unsigned char *) realloc(RGBGuideBuf, npixels*3);
  RGBGuidew = fullw;
  RGBGuideh = fullh;

  if (! GuideFrameWindowExists) {
	  gcnew GuideFrameWindow();
  }

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
  CCDAuto::GuideFrameWindow::SetGuideFrameBgndTextBox(buffer);
  sprintf_s(buffer, sizeof(buffer), "%d", max);
  CCDAuto::GuideFrameWindow::SetGuideFrameRangeTextBox(buffer);
  sprintf_s(buffer, sizeof(buffer), "%d", 0.33);
  CCDAuto::GuideFrameWindow::SetGuideFrameGammaTextBox(buffer);

  /* Set the image values */

  sprintf_s(buffer, sizeof(buffer), "%d", min);
  CCDAuto::GuideFrameWindow::SetGuideFrameMinPixTextBox(buffer);
  sprintf_s(buffer, sizeof(buffer), "%d", max);
  CCDAuto::GuideFrameWindow::SetGuideFrameMaxPixTextBox(buffer);
  sprintf_s(buffer, sizeof(buffer), "%d", ave);
  CCDAuto::GuideFrameWindow::SetGuideFrameAvePixTextBox(buffer);

  dp = RGBGuideBuf;
  min = iave;
  if (max == min)
    min = max - 1;
  for (j = 0; j < fullh; ++j) {
    for (i = 0; i < fullw; ++i) {
      if ((j >= y) && (j < y+h) && (i >= x) && (i < x+w)) {
	f = ((double)*sp++ - min)/(max - min);
	if (f < 0.0) f=0.0;
	d = (int)(255.0*pow(f, 0.33));	/* gamma correct */
	if (d < 0) {
	  d = 0;
	} else if (d > 255) {
	  d = 255;
	}
	if (*(sp-1) == 65000) {
	  dp[RED] = 255;
	  dp[GREEN] = 0;
	  dp[BLUE] = 0;
	} else {
	  dp[RED] = d;
	  dp[GREEN] = d;
	  dp[BLUE] = d;
	}
      } else {
	dp[RED] = 0;
	dp[GREEN] = 0;
	dp[BLUE] = 0;
      }
      dp += 3;
    }
  }

//  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowDrawingArea");
//  gtk_drawing_area_size(GTK_DRAWING_AREA(widget), fullw, fullh);
//  gtk_widget_show(GuideFrameWindow);
  return;
}

int StartExposure(CCD *ccd, StartExposureParams *expose,
		  StartReadoutParams *readout)
{
  int ret;

  ret = FALSE;
  switch (ccd->make) {
    case SBIG_MAKE:
      ret = pCam_StartExposure(expose);
      ret = (ret == CE_NO_ERROR);
      break;
  case APOGEE_MAKE:
    ret = apCam_StartExposure(expose);
    break;
  case SXPRESS_MAKE:
//    ret = spCam_StartExposure(ccd, expose, readout);
    break;
  }

  return ret;
}

int QueryCCDExposureStatus(CCD *ccd, StartExposureParams *expose)
{
  int status, done, err;
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
    case APOGEE_MAKE:
      status = apCam_ReadStatus();
      done = (status == APOGEE_STATUS_IMAGEREADY);
      break;
    case SXPRESS_MAKE:
      done = false;
      break;
  }

  return done;
}

void EndCCDExposure(CCD *ccd, StartExposureParams *expose)
{
  EndExposureParams  end_exposure_params;

  switch (ccd->make) {
    case SBIG_MAKE:
      end_exposure_params.ccd = expose->ccd;
      pCam_EndExposure(&end_exposure_params);
      break;
    case APOGEE_MAKE:
      break;
    case SXPRESS_MAKE:
      //      spCam_EndExposure(ccd);
      break;
  }

  return;
}


static void sxDataReady(void *data, int fd, void *in)
{
//  gdk_input_remove(input_tag);
	CCDAuto::dataIsReady = TRUE;
  return;
}

int GetImage(CCD *ccd, StartReadoutParams *readout, int Light,
	     unsigned short *image_data)
{
  char Message[80];
  short xbinning, ybinning;
  int i, status, percent, success;
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
    case APOGEE_MAKE:
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
	 	sprintf_s(Message, sizeof(Message),
				"*** WARNING - Error reading out image\n");
		return false;
	  }
      return success;
      break;
    case SXPRESS_MAKE:
//    dataIsReady = FALSE;
//    input_tag  = gdk_input_add(ccd->mx_sxv_info.fd, GDK_INPUT_READ,
//		 (GdkInputFunction)sxDataReady, NULL);
//    itry = 0;
//    do {
//	    if (dataIsReady)
//	       break;
//	    RunMainIteration(0.01);
//	    itry++;
//      } while (itry < 1000);
//    if (itry >= 1000) {
//	     printf("*** DEBUG - Waited 10 seconds for data ready, exiting...\n");
//	     exit(-1);
//    }
//    if (Light)
//		ShowImageProgress("Downloading - Light Frame", 0);
//    else
//		ShowImageProgress("Downloading - Dark Frame", 0);
//    for (i=0; i<readout->height; i++) {
//	  itry = 0;
//	  do {
//	    success = spCam_ReadoutLine(ccd, readout,
//				      image_data+i*readout->width,(i==0));
//	    if (success)
//	      break;
//	    RunMainIteration(0.1);
//	    itry++;
//	  } while (itry < 100);
//	  if (! success) {
//	    sprintf_s(Message, sizeof(Message),
//		    "*** WARNING - Error reading out image line: %d\n",i);
//	    ShowImageProgress(NULL, 0);
//	    return FALSE;
//	  }
//	  percent = (int) Math::Round(100.0 * ((float)  i) / readout->height);
//	  if (Light) {
//	    ShowImageProgress("Downloading - Light Frame", percent);
//	    sprintf_s(Message, sizeof(Message),"load: %d%%", percent);
//	  } else {
//	    ShowImageProgress("Downloading - Dark Frame", percent);
//	    sprintf_s(Message, sizeof(Message),"load: %d%%", percent);
//	  }
//	  gtk_entry_set_text(GTK_ENTRY(Entry), Message);
//	  RunMainIteration(0.01);
//	  if (CancelCurrentAcquire) {
//	    Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
//	    ShowImageProgress(NULL, 0);
//	    return FALSE;
//	  }
//    }
	ShowImageProgress(NULL, 0);
      return TRUE;
      break;
  }
  return TRUE;

}


 /*
  * This is the 'progress' callback
  * passed to sbig_readout()
  */

bool snapImaging(CCD *ccd, StartExposureParams *expose,
		 StartReadoutParams *readout, IMAGE *Image)
{
  int success, done;
  unsigned int i;
  unsigned short *image_data;
  char Message[80];
  double ccd_temp;
//  EndExposureParams  end_exposure_params;
//  ReadoutLineParams  readout_line_params;
//  QueryCommandStatusParams  query_command_status_params;
//  QueryCommandStatusResults  query_command_status_results;

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
    
    expose->openShutter = 2;
    time(&Image->dark_frame.time);
    ImagingShutterClosed = true;
    success = StartExposure(ccd, expose, readout);
    if (! success) {
      Form1::StatusPrint("*** WARNING - Error starting dark frame...\n");
      ImageInProgress = false;
      return false;
    }

    /* Wait to start waiting */

    if (expose->exposureTime > 100) {
      ShowImageProgress("Exposing - Dark Frame", 0);
      for (i = 0; i < expose->exposureTime; i += 20) {
	ShowImageProgress("Exposing - Dark Frame",
			  (int) (100.0*i/expose->exposureTime));
	sprintf_s(Message, sizeof(Message),"Expose: %4.1f%%", 100.0*i/expose->exposureTime);
	Form1::SetCCDStatusTextBox(Message);
//	RunMainIteration(0.2);
	if (CancelCurrentAcquire) {
	  Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	  ShowImageProgress(NULL, 0);
	  ImageInProgress = false;
	  return false;
	}
      }
    } else
      usleep(expose->exposureTime*10000);
    
    /* wait for exposure to complete */
    
    for (i = 0; i < 1000; ++i) {
      done = QueryCCDExposureStatus(ccd, expose);
      if (done) {
		EndCCDExposure(ccd, expose);
		break;
      }
      usleep(50000);
      if (CancelCurrentAcquire) {
		Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
		ShowImageProgress(NULL, 0);
		ImageInProgress = false;
		EndCCDExposure(ccd, expose);
		return false;
      }
    }
    if (i == 1000) {
      Form1::StatusPrint("*** WARNING - Dark exposure didn't finish...\n");
	  ImageInProgress = false;
      return false;
    }
    ShowImageProgress(NULL, 0);
    
    /* Readout dark frame */

    image_data = Image->dark_frame.frame;
    memset(image_data, 0 ,readout->height*readout->width*2);
    ImagingDownloadInProgress = true;
    success = GetImage(ccd, readout, false, image_data);
    if (! success) {
      sprintf_s(Message, sizeof(Message), "*** WARNING - Error reading out image\n");
      ImagingDownloadInProgress = false;
      ImageInProgress = false;
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
      return false;
    }
    Image->light_frame.temp = ((float) ccd_temp);
    
	Form1::SetCCDStatusTextBox("Exposing Light");
    sprintf_s(Message, sizeof(Message),"Starting %f sec. light frame...\n",
	    expose->exposureTime/100.0);
    Form1::StatusPrint(Message);
    time(&Image->light_frame.time);
    expose->openShutter = 1;
    ImagingShutterClosed = false;
    success = StartExposure(ccd, expose, readout);
    if (! success) {
      Form1::StatusPrint("*** WARNING - Error starting light frame...\n");
      ImageInProgress = false;
      return false;
    }

    /* Wait to start waiting */

    if (expose->exposureTime > 100) {
      ShowImageProgress("Exposing - Light Frame", 0);
      for (i = 0; i < expose->exposureTime; i += 20) {
	ShowImageProgress("Exposing - Light Frame", 
			  (int) (100.0*i/expose->exposureTime));
	sprintf_s(Message, sizeof(Message),"Expose: %4.1f%%", 100.0*i/expose->exposureTime);
	Form1::SetCCDStatusTextBox(Message);
//	RunMainIteration(0.2);
	if (CancelCurrentAcquire) {
	  Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	  ShowImageProgress(NULL, 0);
	  ImageInProgress = false;
	  EndCCDExposure(ccd, expose);
	  return false;
	}
      }
    } else
      usleep(expose->exposureTime*10000);
    
    /* wait for exposure to complete */
    
    for (i = 0; i < 1000; ++i) {
      done = QueryCCDExposureStatus(ccd, expose);
      if (done) {
		EndCCDExposure(ccd, expose);
		break;
      }
      usleep(50000);
      if (CancelCurrentAcquire) {
		Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
		ShowImageProgress(NULL, 0);
		ImageInProgress = false;
		return false;
      }
    }
    if (i >= 1000) {
      Form1::StatusPrint("*** WARNING - Light exposure didn't finish...\n");
	  ImageInProgress = false;
      return false;
    }
    ShowImageProgress(NULL, 0);

    /* Readout light frame */

    image_data = Image->light_frame.frame;
    memset(image_data, 0, readout->height*readout->width*2);
    ImagingDownloadInProgress = true;
    success = GetImage(ccd, readout, true, image_data);
    if (! success) {
      sprintf_s(Message, sizeof(Message), "*** WARNING - Error reading out image\n");
      ImagingDownloadInProgress = FALSE;
      ImageInProgress = false;
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
   
  /* Reset system clock from hardware clock because downloading screws up
     system clock */
   
//  system("/sbin/hwclock --hctosys");

  ShowImageProgress(NULL, 0);
//  updateStatusInfo();
  ImageInProgress = false;

  return true;
}


bool snapTracking(CCD *ccd, StartExposureParams *expose,
		 StartReadoutParams *readout, IMAGE *Image)
{
  int  ret, percent, status, err;
  unsigned int i;
  unsigned short *image_data;
  char Message[80];
  double ccd_temp;
  EndExposureParams  end_exposure_params;
  ReadoutLineParams  readout_line_params;
  QueryCommandStatusParams  query_command_status_params;
  QueryCommandStatusResults  query_command_status_results;


  if (ImageInProgress && ImagingShutterClosed)
    return false;

  /*
   * take a dark if needed
   */

  DontUpdate = true;
  
  /* Get current temp of dark frame */

  if (! Image->lightOnly) {
    status = pCam_GetCCDTemperature(&ccd_temp);
    if (status != 0) {
      Form1::StatusPrint("*** WARNING - Can't get ccd temperature, "
		  "aborting exposure...\n");
      return false;
    }
    Image->dark_frame.temp = (float) ccd_temp;
    
	Form1::SetCCDStatusTextBox("Exposing Dark");
    sprintf_s(Message, sizeof(Message),"Starting %f sec. dark frame...\n",
	    (float) (expose->exposureTime/100.0));
    Form1::StatusPrint(Message);

    if (GuidingSlitSettings.Running && ImageInProgress) {
      expose->openShutter = 0;
    } else {
      expose->openShutter = 2;
    }
    time(&Image->dark_frame.time);
    //ret = SBIGUnivDrvCommand(CC_START_EXPOSURE, expose, NULL);
    ret = pCam_StartExposure(expose);
    if (ret != CE_NO_ERROR) {
      Form1::StatusPrint("*** WARNING - Error starting dark frame...\n");
      return false;
    }

    /* Wait to start waiting */

    if (expose->exposureTime > 100) {
      ShowGuidingProgress("Exposing - Dark Frame", 0);
      for (i = 0; i < expose->exposureTime; i += 20) {
	ShowGuidingProgress("Exposing - Dark Frame",
			  (int) (100.0*i/expose->exposureTime));
	sprintf_s(Message, sizeof(Message),"Dark Expose: %4.1f%%", 100.0*i/expose->exposureTime);
	Form1::SetCCDStatusTextBox(Message);
//	RunMainIteration(0.2);
	if (CancelCurrentGuidingAcquire) {
	  Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	  ShowGuidingProgress(NULL, 0);
	  return false;
	}
      }
    } else
      usleep(expose->exposureTime*10000);
    
    /* wait for exposure to complete */
    
    for (i = 0; i < 1000; ++i) {
      query_command_status_params.command = CC_START_EXPOSURE;
      //err = SBIGUnivDrvCommand(CC_QUERY_COMMAND_STATUS,
      //		       &query_command_status_params, 
      //		       &query_command_status_results);
      err = pCam_QueryCommandStatus(&query_command_status_params,
				     &query_command_status_results);
      if (expose->ccd == 0)
	status = query_command_status_results.status & 3;
      else
	status = (query_command_status_results.status >> 2) & 3;
      if (status == CS_INTEGRATION_COMPLETE) {
	end_exposure_params.ccd = expose->ccd;
	//SBIGUnivDrvCommand(CC_END_EXPOSURE, &end_exposure_params, NULL);
	pCam_EndExposure(&end_exposure_params);
	break;
      }
      usleep(50000);
      if (CancelCurrentGuidingAcquire) {
	Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	ShowGuidingProgress(NULL, 0);
	return false;
      }
    }

    if (i == 1000) {
      Form1::StatusPrint("*** WARNING - Dark exposure didn't finish...\n");
      return false;
    }

    ShowGuidingProgress(NULL, 0);
    
    /* Readout dark frame */

    //sync();
    //SBIGUnivDrvCommand(CC_START_READOUT, readout, NULL);

    image_data = Image->dark_frame.frame;
    memset(image_data, 0 ,readout->height*readout->width*2);
    ShowGuidingProgress("Downloadng - Dark Frame", 0);
    for (i=0; i<readout->height; i++) {
      readout_line_params.ccd = readout->ccd;
      readout_line_params.readoutMode = readout->readoutMode;
      readout_line_params.pixelStart = readout->left;
      readout_line_params.pixelLength = readout->width;
      //status = SBIGUnivDrvCommand(CC_READOUT_LINE, &readout_line_params,
      //			  image_data + i*readout->width);
      status = pCam_ReadoutLine(&readout_line_params, 
				 image_data+i*readout->width, 0);
      if (status != CE_NO_ERROR) {
	sprintf_s(Message, sizeof(Message), "*** WARNING - Error reading out image line: %d\n",
		i);
	return false;
      }
      percent = (int) (100.0 * ((float)  i) / readout->height);
      
      ShowGuidingProgress("Downloading - Dark Frame", percent);
      sprintf_s(Message, sizeof(Message),"Dark load: %d%%", percent);
	  Form1::SetCCDStatusTextBox(Message);
//      RunMainIteration(0.01);
      if (CancelCurrentGuidingAcquire) {
	Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	ShowGuidingProgress(NULL, 0);
	return false;
      }
    }
		    
    sprintf_s(Message, sizeof(Message), "dark frame: \n");
    Form1::StatusPrint(Message);
    print_stats(Image->dark_frame.frame, readout->width, readout->height);
    Image->dark_frame.active = TRUE;
    Image->dark_frame.whichCCD = expose->ccd;
    Image->dark_frame.binning = readout->readoutMode;
    Image->dark_frame.x = readout->left;
    Image->dark_frame.y = readout->top;
    Image->dark_frame.w = readout->width;
    Image->dark_frame.h = readout->height;
    Image->dark_frame.exposure = (float) (expose->exposureTime/100.0);
  }

  /*
   * take a light frame if required
   */
  
  if (! Image->darkOnly) {

    /* Get current temp of light frame */

    status = pCam_GetCCDTemperature(&ccd_temp);
    if (status != 0) {
      Form1::StatusPrint("*** WARNING - Can't get ccd temperature, "
		  "aborting exposure...\n");
      return FALSE;
    }
    Image->light_frame.temp = (float) ccd_temp;
    
	Form1::SetCCDStatusTextBox("Exposing Light");
    sprintf_s(Message, sizeof(Message),"Starting %f sec. light frame...\n",
	    expose->exposureTime/100.0);
    Form1::StatusPrint(Message);
    time(&Image->light_frame.time);
    if (GuidingSlitSettings.Running && ImageInProgress) {
      expose->openShutter = 0;
    } else {
      expose->openShutter = 1;
    }
    //ret = SBIGUnivDrvCommand(CC_START_EXPOSURE, expose, NULL);
    ret = pCam_StartExposure(expose);
    if (ret != CE_NO_ERROR) {
      Form1::StatusPrint("*** WARNING - Error starting dark frame...\n");
      return FALSE;
    }

    /* Wait to start waiting */

    if (expose->exposureTime > 100) {
      ShowGuidingProgress("Exposing - Light Frame", 0);
      for (i = 0; i < expose->exposureTime; i += 20) {
	ShowGuidingProgress("Exposing - Light Frame", 
			  (int) (100.0*i/expose->exposureTime));
	sprintf_s(Message, sizeof(Message),"Light Expose: %4.1f%%", 100.0*i/expose->exposureTime);
	Form1::SetCCDStatusTextBox(Message);
//	RunMainIteration(0.2);
	if (CancelCurrentGuidingAcquire) {
	  Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	  ShowGuidingProgress(NULL, 0);
	  return FALSE;
	}
      }
    } else
      usleep(expose->exposureTime*10000);
    
    /* wait for exposure to complete */
    
    for (i = 0; i < 1000; ++i) {
      query_command_status_params.command = CC_START_EXPOSURE;
      //err = SBIGUnivDrvCommand(CC_QUERY_COMMAND_STATUS,
      //		       &query_command_status_params, 
      //		       &query_command_status_results);
      err = pCam_QueryCommandStatus(&query_command_status_params,
				     &query_command_status_results);
      if (expose->ccd == 0)
	status = query_command_status_results.status & 3;
      else
	status = (query_command_status_results.status >> 2) & 3;
      if (status == CS_INTEGRATION_COMPLETE) {
	end_exposure_params.ccd = expose->ccd;
	//SBIGUnivDrvCommand(CC_END_EXPOSURE, &end_exposure_params, NULL);
	pCam_EndExposure(&end_exposure_params);
	break;
      }
      usleep(50000);
      if (CancelCurrentGuidingAcquire) {
	Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	ShowGuidingProgress(NULL, 0);
	return FALSE;
      }
    }

    if (i == 1000) {
      Form1::StatusPrint("*** WARNING - Light exposure didn't finish...\n");
      return FALSE;
    }

    ShowGuidingProgress(NULL, 0);

    /* Readout light frame */

    //sync();
    //SBIGUnivDrvCommand(CC_START_READOUT, readout, NULL);

    image_data = Image->light_frame.frame;
    memset(image_data, 0, readout->height*readout->width*2);
    ShowGuidingProgress("Downloading - Light Frame", 0);
    for (i=0; i<readout->height; i++) {
      readout_line_params.ccd = readout->ccd;
      readout_line_params.readoutMode = readout->readoutMode;
      readout_line_params.pixelStart = readout->left;
      readout_line_params.pixelLength = readout->width;
      //status = SBIGUnivDrvCommand(CC_READOUT_LINE, &readout_line_params,
      //			  image_data + i*readout->width);
      status = pCam_ReadoutLine(&readout_line_params, 
				 image_data+i*readout->width, 0);
      if (status != CE_NO_ERROR) {
	sprintf_s(Message, sizeof(Message), "*** WARNING - Error reading light frame line: %d\n",
		i);
	return FALSE;
      }
      percent = (int) (100.0 * ((float) i) / readout->height);
      ShowGuidingProgress("Downloading - Light Frame", percent);
      sprintf_s(Message, sizeof(Message),"Light load: %d%%", percent);
	  Form1::SetCCDStatusTextBox(Message);
//      RunMainIteration(0.01);
      if (CancelCurrentGuidingAcquire) {
	Form1::StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	ShowGuidingProgress(NULL, 0);
	return FALSE;
      }
    }

    Image->light_frame.exposure = (float) (expose->exposureTime/100.0);
     
    /* update image parameters and return */

    sprintf_s(Message, sizeof(Message),"image: \n");
    Form1::StatusPrint(Message);
    print_stats(Image->light_frame.frame, readout->width, readout->height);
    Image->light_frame.active = TRUE;
    Image->light_frame.whichCCD = expose->ccd;
    Image->light_frame.binning = readout->readoutMode;
    Image->light_frame.x = readout->left;
    Image->light_frame.y = readout->top;
    Image->light_frame.w = readout->width;
    Image->light_frame.h = readout->height;
    Image->light_frame.exposure = (float) (expose->exposureTime/100.0);
  } 
  DontUpdate = FALSE;
   
  /* Reset system clock from hardware clock because downloading screws up
     system clock */
   
//  system("/sbin/hwclock --hctosys");

  ShowGuidingProgress(NULL, 0);
//  updateStatusInfo();

  return TRUE;
}


/*
	ROUTINE:	queryi
	PURPOSE:	Prints the passed prefix and inputs a short unsigned
	                integer.
	DATE:		11 AUG 86
	BY:		 A.L. Shoup
	Modifications:  (Shoup, 12/10/96) put args def's on proc line
*/

			/* Include files */

int query(char *prompt)
{
  /* Declarations */
  
  char	buffer[80];		/* Input buffer */
  int answer;
  
  /* Print question and get y/n answer */

  answer = FALSE;
  do {
    printf("%s (y/n): ", prompt);
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] == '\n')
      break;
    if ((buffer[0] == 'y') || (buffer[0] == 'Y')) {
      answer = TRUE;
      break;
    } else if ((buffer[0] == 'n') || (buffer[0] == 'N')) {
      answer = FALSE;
      break;
    }
  } while (TRUE);

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
  if (ccd->Image.light_frame.frame != NULL)
    free(ccd->Image.light_frame.frame);
  if (ccd->Image.dark_frame.frame != NULL)
    free(ccd->Image.dark_frame.frame);

  if (ccd->FlatImage.light_frame.frame != NULL)
    free(ccd->FlatImage.light_frame.frame);
  if (ccd->FlatImage.dark_frame.frame != NULL)
    free(ccd->FlatImage.dark_frame.frame);

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
/*   return TRUE; */
/* } */

int readDark(char *Dir, IMAGE *Image)
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
  darkFrame->active = FALSE;

  /* Form compatible file name and open it */

  sprintf_s(fileName, sizeof(fileName), "%s/Dark%s_%d.fits",Dir,binningString[lightFrame->binning],
	  ((int)(lightFrame->exposure)));

  /* Open fits file for reading */

  status = 0;
  if (fits_open_file(&fptr, fileName, READONLY, &status)) {
    fits_report_error(stderr, status); /* print error report */
    return FALSE;
  }

  /* get image keywords */

  if (fits_read_keys_lng(fptr, "NAXIS", 1, 2, naxes, &nfound, &status)) {
    fits_report_error(stderr, status); /* print error report */
    return FALSE;
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
    return FALSE;
  }

  if (fits_read_key(fptr, TFLOAT, "EXPOSURE", &darkFrame->exposure,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }

  if (fits_read_key(fptr, TFLOAT, "CCDTEMP", &darkFrame->temp,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }

  if (fabs(darkFrame->temp-lightFrame->temp) > MAXTEMPDIFF) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Temp diff between light and dark frames"
	    " too big: %f %f\n", lightFrame->temp, darkFrame->temp);
    Form1::StatusPrint(Message);
    return FALSE;
  }

  if (fits_read_key(fptr, TINT, "STARTX", &darkFrame->x,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }
  if (fits_read_key(fptr, TINT, "STARTY", &darkFrame->y,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }

  if ((darkFrame->x != lightFrame->x) ||
      (darkFrame->y != lightFrame->y)) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d,%d) & Dark (%d,%d) start"
	    " positions not compatible, aborting...\n",
	    lightFrame->x, lightFrame->y, darkFrame->x, darkFrame->y);
    Form1::StatusPrint(Message);
    return FALSE;
  }

  if (fits_read_key(fptr, TINT, "BINNING", &darkFrame->binning,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }

  if (darkFrame->binning != lightFrame->binning) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d) & Dark (%d) binning"
	    " not the same, aborting...\n",
	    lightFrame->binning, darkFrame->binning);
    Form1::StatusPrint(Message);
    return FALSE;
  }

  if (fits_read_key(fptr, TINT, "WHICHCCD", &darkFrame->whichCCD,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }

  if (darkFrame->whichCCD != lightFrame->whichCCD) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d) & Dark (%d) whichCCD"
	    " not the same, aborting...\n",
	    lightFrame->whichCCD, darkFrame->whichCCD);
    Form1::StatusPrint(Message);
    return FALSE;
  }

  /* Allocate memory for image */

  darkFrame->frame = (unsigned short *)
    realloc(darkFrame->frame, npixels*sizeof(unsigned short));

  /* read in image */

  fpixel = 1;
  nullval = 0;
  if (fits_read_img(fptr, TUSHORT, fpixel, npixels, &nullval,
		    darkFrame->frame, &anynull, &status)) {
    fits_report_error(stderr, status); /* print error report */
    return FALSE;
  }

  darkFrame->active = TRUE;
  
  return TRUE;
}

int readFlat(char *Dir, CCD *ccd)
{
  char Comment[160], fileName[160];
  char Message[160];
  int anynull, status, nfound;
  float nullval;
  long naxes[2], fpixel, npixels;
  fitsfile *fptr;
  FRAME *flatFrame, *lightFrame;

  flatFrame = &ccd->FlatImage.light_frame;
  lightFrame = &ccd->Image.light_frame;

  flatFrame->active = FALSE;

  /* Open fits file for reading */

  sprintf_s (fileName, sizeof(fileName), "%s/Flat%s%c.fits", Dir,
	  binningString[ccd->Image.light_frame.binning],
	  ccd->Image.Filter[0]);

  status = 0;
  if (fits_open_file(&fptr, fileName, READONLY, &status)) {
    fits_report_error(stderr, status); /* print error report */
    return FALSE;
  }

  /* get image size keywords */

  if (fits_read_keys_lng(fptr, "NAXIS", 1, 2, naxes, &nfound, &status)) {
    fits_report_error(stderr, status); /* print error report */
    return FALSE;
  }
  npixels = naxes[0]*naxes[1];
  flatFrame->w = naxes[0];
  flatFrame->h = naxes[1];

  if ((flatFrame->w != lightFrame->w)) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d,%d) & Flat (%d,%d) sizes"
	    " not compatible, aborting...\n",
	    lightFrame->w, lightFrame->h, flatFrame->w, flatFrame->h);
    Form1::StatusPrint(Message);
    return FALSE;
  }

  /* get some keywords */

  if (fits_read_key(fptr, TFLOAT, "EXPOSURE", &flatFrame->exposure,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }

  if (fits_read_key(fptr, TSTRING, "OBJECT", ccd->FlatImage.ObjectName,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }

  if (fits_read_key(fptr, TINT, "STARTX", &flatFrame->x,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }
  if (fits_read_key(fptr, TINT, "STARTY", &flatFrame->y,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }

  if ((flatFrame->x != lightFrame->x) ||
      (flatFrame->y != lightFrame->y)) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d,%d) & Flat (%d,%d) start"
	    " positions not compatible, aborting...\n",
	    lightFrame->x, lightFrame->y, flatFrame->x, flatFrame->y);
    Form1::StatusPrint(Message);
    return FALSE;
  }

  if (fits_read_key(fptr, TINT, "BINNING", &flatFrame->binning,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }

  if (flatFrame->binning != lightFrame->binning) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d) & Flat (%d) binning"
	    " not the same, aborting...\n",
	    lightFrame->binning, flatFrame->binning);
    Form1::StatusPrint(Message);
    return FALSE;
  }

  if (fits_read_key(fptr, TINT, "WHICHCCD", &flatFrame->whichCCD,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }

  if (flatFrame->whichCCD != lightFrame->whichCCD) {
    sprintf_s(Message, sizeof(Message),"*** Warning - Light (%d) & Flat (%d) whichCCD"
	    " not the same, aborting...\n",
	    lightFrame->whichCCD, flatFrame->whichCCD);
    Form1::StatusPrint(Message);
    return FALSE;
  }

  /* Allocate memory for image */

  flatFrame->frame = (unsigned short *)
    realloc(flatFrame->frame, npixels*sizeof(unsigned short));

  /* read in image */

  fpixel = 1;
  nullval = 0;
  if (fits_read_img(fptr, TUSHORT, fpixel, npixels, &nullval,
		    flatFrame->frame, &anynull, &status)) {
    fits_report_error(stderr, status); /* print error report */
    return FALSE;
  }

  flatFrame->active = TRUE;
  strcpy_s(ccd->FlatImage.FileName,sizeof(ccd->FlatImage.FileName),fileName);

  return TRUE;
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


int readLight(char *fileName, IMAGE *Image)
{
  char Comment[160];
  int anynull, status, nfound;
  float nullval;
  long naxes[2], fpixel, npixels;
  fitsfile *fptr;
  FRAME *lightFrame;

  /* Open fits file for reading */

  status = 0;
  if (fits_open_file(&fptr, fileName, READONLY, &status)) {
    ShowFitsError();
    return FALSE;
  }

  /* get image size keywords */

  lightFrame = &Image->light_frame;
  naxes[0] = naxes[1] = 0;
  if (fits_read_keys_lng(fptr, "NAXIS", 1, 2, naxes, &nfound, &status)) {
    ShowFitsError();
    fits_close_file(fptr, &status);
    return FALSE;
  }
  npixels = naxes[0]*naxes[1];

  if (npixels <= 0) { // if NAXIS not found, try Image Width, etc.
	  if (fits_read_key_lng(fptr, "ImageWidth", &naxes[0], Comment, &status)) {
		  ShowFitsError();
          fits_close_file(fptr, &status);
		  return FALSE;
	  }
	  if (fits_read_key_lng(fptr, "ImageHeight", &naxes[1], Comment, &status)) {
		  ShowFitsError();
		  fits_close_file(fptr, &status);
		  return FALSE;
	  }
	  npixels = naxes[0]*naxes[1];
	  if (npixels <= 0) {
		  Form1::StatusPrint("*** Warning - Invalid size of image...\n");
		  fits_close_file(fptr, &status);
		  return FALSE;
	  }
  }

  /* (Re)Allocate memory for image */

  lightFrame->frame = (unsigned short *) realloc(lightFrame->frame,
			      npixels*sizeof(unsigned short));

  /* read in image */

  fpixel = 1;
  nullval = 0;
  if (fits_read_img(fptr, TUSHORT, fpixel, npixels, &nullval,
		    lightFrame->frame, &anynull, &status)) {
	ShowFitsError();
    fits_close_file(fptr, &status);
    return FALSE;
  }

  /* get some keywords */

  if (fits_read_key(fptr, TFLOAT, "EXPOSURE", &lightFrame->exposure,
		    Comment, &status)) {
    status = 0;
    if (fits_read_key(fptr, TFLOAT, "EXPTIME", &lightFrame->exposure,
		      Comment, &status)) {
	  ShowFitsError();
//      fits_close_file(fptr, &status);
//      return FALSE;
    }
  }

  if (fits_read_key(fptr, TSTRING, "OBJECT", &Image->ObjectName,
		    Comment, &status)) {
	ShowFitsError();
    strcpy_s(Image->ObjectName, sizeof(Image->ObjectName), "none");
  }

  if (fits_read_key(fptr, TSTRING, "OBSERVAT", &ObsSettings.name,
		    Comment, &status)) {
	ShowFitsError();
    strcpy_s(ObsSettings.name, sizeof(ObsSettings.name), "none");
  }

  if (fits_read_key(fptr, TSTRING, "FILTER", &Image->Filter,
		    Comment, &status)) {
	ShowFitsError();
    strcpy_s(Image->Filter, sizeof(Image->Filter), "n");
  }

  if (fits_read_key(fptr, TSTRING, "OBSERVER", &ObsSettings.Observer,
		    Comment, &status)) {
	ShowFitsError();
    strcpy_s(ObsSettings.Observer, sizeof(ObsSettings.Observer), "n");
  }

  if (fits_read_key(fptr, TSTRING, "PROJECT", &ObsSettings.Project,
		    Comment, &status)) {
	ShowFitsError();
	strcpy_s(ObsSettings.Project, sizeof(ObsSettings.Project), "n");
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
      strcpy_s(lightFrame->UT, sizeof(lightFrame->UT), "00:00:00");
    }
  }

  if (fits_read_key(fptr, TSTRING, "DATE-OBS", &lightFrame->UTDATE,
		    Comment, &status)) {
	ShowFitsError();
    strcpy_s(lightFrame->UTDATE, sizeof(lightFrame->UTDATE), "0000-00-00T00:00:00");
  }

  if (fits_read_key(fptr, TINT, "WHICHCCD", &lightFrame->whichCCD,
		    Comment, &status)) {
	ShowFitsError();
    lightFrame->whichCCD = 0;
  }

  lightFrame->w = naxes[0];
  lightFrame->h = naxes[1];
  lightFrame->active = TRUE;
  strcpy_s(Image->FileName, sizeof(Image->FileName), fileName);

  /* Close the FITS file */

  status = 0;
  if (fits_close_file(fptr, &status)) {
    ShowFitsError();
    strcpy_s(Image->FileName, sizeof(Image->FileName), "FITS error");
    return TRUE;
  }

  return TRUE;
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
  } while (TRUE);

  TNU2 = sqrt( (1.+S)/(1.-S))*tan(*EA/2.);
  *NU = (float) (2.*atan(TNU2));
}


void ShowImageProgress(char *Label, int percent)
{
  static int Shown=FALSE;

  if (DontShowImageProgress)
    return;

  if (! ProgressDialogExists) {
    gcnew ProgressDialog();
  }
  ProgressDialog::ShowProgressDialog();
  Shown = TRUE;

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
  static int Shown=FALSE;

  if (DontShowGuidingProgress)
    return;

  if (! GuidingProgressDialogExists) {
    gcnew GuidingProgressDialog();
  }
  GuidingProgressDialog::ShowGuidingProgressDialog();
  Shown = TRUE;

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


void RunMainIteration(float seconds)
{
  int runMainIterationTimer;
//  unsigned int timerID;

  runMainIterationTimer = (int) (seconds * 100.0);

//  timerID = gtk_timeout_add(10, decrementRunMainIterationTimer,
//			    &runMainIterationTimer);

/*  do {
    gtk_main_iteration_do(FALSE);
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
    return FALSE;
  else
    return TRUE;
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


int GetScopePosition(double *ScopeRA, double *ScopeDEC)
{
  *ScopeRA = 0.0;
  *ScopeDEC = 0.0;
  return FALSE;
}


void UpdateDarkFrameSettings(void)
{
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


void UpdateFlatFrameSettings(void)
{
  int i, darkOption;
  char Message[80];
  char buffer[80];

  /* Get parms not already gotten */

  /* Get dark frame option */

  darkOption = FlatFrameSettingsDialog::GetDarkFrameOptionComboBox() + 1;
  if ((darkOption < 1) || (darkOption > 4)) {
    sprintf_s(Message, sizeof(Message),
	    "*** Internal error - bad dark option: %s (FlatFrameSettings\n)",
	    darkOption);
    Form1::StatusPrint(Message);
  }

  /* Get filter sequence values */

  for (i=0; i<NUMFILTERS; i++) {
	if (FlatFrameSettingsDialog::GetFilterCheckBoxState(filterSet[i])) {
      flatFrameSettings.filterSeq.Use[i] = TRUE;
	  FlatFrameSettingsDialog::GetFilterExpTimeTextBox(filterSet[i], buffer);
      sscanf_s(buffer, "%f", &flatFrameSettings.filterSeq.exposures[i]);
    }
  }

  FlatFrameSettingsDialog::GetFrameTextBox(buffer);
  sscanf_s(buffer, "%d, %d, %d, %d", &flatFrameSettings.x,
	 &flatFrameSettings.y, &flatFrameSettings.h, &flatFrameSettings.w);

  FlatFrameSettingsDialog::GetNumFramesTextBox(buffer);
  sscanf_s(buffer, "%d", &flatFrameSettings.numFrames);

  FlatFrameSettingsDialog::GetImageDirTextBox(flatFrameSettings.imageDir);

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


int setAlignStar(FRAME *frame, float *starX, float *starY)
{
  char buffer[80];

  if (! PickAlignStarDialogExists) {
    gcnew PickAlignStarDialog();
  }

  PickAlignStarDialog::SetStarXTextBox("-999");
  PickAlignStarDialog::SetStarYTextBox("-999");
  PickAlignStarDialog::SetStarMaxTextBox("-999");

  CancelSetAlignStar = FALSE;
  AlignStarFound = FALSE;
  PickAlignStarDialog::FormPtr->ShowPickAlignStarDialog();

  do {
    usleep(100000);
  } while ((! AlignStarFound) && (! CancelSetAlignStar));

  if (CancelSetAlignStar) {
    return FALSE;
  }
  PickAlignStarDialog::GetStarXTextBox(buffer);
  sscanf_s(buffer,"%f", starX);
  PickAlignStarDialog::GetStarYTextBox(buffer);
  sscanf_s(buffer,"%f", starY);

  return TRUE;
}

int findAlignStar(FRAME *frame, float starX, float starY,
		  int *offsetX, int *offsetY)
{
  int Found;
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

  /* sum pixels from working Image into Image, after shifting by offset */

  h = Image->light_frame.h;
  w = Image->light_frame.w;

  for (y=0; y<h; y++) {
    newy = y + offsetY;
    if ((newy >= 0) && (newy < h)) {
      for (x=0; x<w; x++) {
	newx = x + offsetX;
	if ((newx >= 0) && (newx < w)) {
	  ipix = y * w + x;
	  newipix = newy*w + newx;
	  Image->light_frame.frame[ipix] +=
	    workingImage->light_frame.frame[newipix];
	  if (Image->light_frame.frame[ipix] > 65000)
	    Image->light_frame.frame[ipix] = 65000;
	}
      }
    }
  }

  return;
}


int FindStar(FRAME *frame, int x1, int y1, int x2, int y2,
	     float *starx, float *stary, int *starmax)
{
  int w, h, maxval, x, y, ipix, x0, y0;
  int yAtMax, xAtMax, pixval;
  int FoundStar, numpix;
  float sumx, sumy, sumval, val, r, aveval, background;
  float sigma;
  PIXCELL *PixList;

  /* Max pixel value in region */

  FoundStar = FALSE;
  w = frame->w;
  h = frame->h;
  x0 = frame->x;
  y0 = frame->y;
  if (x1 < 0)  x1 = 0;  if (x1 > w)  x1 = w;
  if (y1 < 0)  y1 = 0;  if (y1 > h)  y1 = h;
  if (x2 < 0)  x2 = 0;  if (x2 > w)  x2 = w;
  if (y2 < 0)  y2 = 0;  if (y2 > h)  y2 = h;
  maxval = -999;
  yAtMax = xAtMax = 0;
  for (x=x1; x<=x2; x++) {
    for (y=y1; y<=y2; y++) {
      ipix =  (y-y0)* w + (x-x0);
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

  if (maxval <= 0.0) return FALSE;

  /* Compute "background" around max pixel */

  sumval = 0.0;
  numpix = 0;
  for (x=x1; x<=x2; x++) {
    for (y=y1; y<=y2; y++) {
      r = ((float) (x-xAtMax)*(x-xAtMax));
      if (r > 0.0) r = sqrt(r);
      if (r >= 8.0) {
	ipix = (y-y0) * w + (x-x0);
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
    sigma = sqrt(background);
  else
    sigma = 1.0;

  /* compute centroid of "star" */

  sumval = 0.0; sumx = 0.0; sumy = 0.0;
  PixList = NULL;
  for (x=xAtMax-10; x<=xAtMax+10; x++) {
    for (y=yAtMax-10; y<=yAtMax+10; y++) {
      if ((x >= x0) && (x < (x0+w)) && (y >= y0) && (y < (y0+h))) {
	ipix = (y-y0) * w + (x-x0);
	pixval = frame->frame[ipix];
	val = ((float) pixval) - background;
	r = ((float) (x-xAtMax)*(x-xAtMax) + (y-yAtMax)*(y-yAtMax));
	if (r > 0.0) r = sqrt(r);
	putpix((float)val, (float)x, (float)y, (float)r, &PixList);
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
    FoundStar = TRUE;
  }

  freepix(PixList);

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

void putpixval(float val, float x, float y, float r, PIXCELL *(*PixList))
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

  for (j = y; j < h; ++j) {
    for (i = x; i < w; ++i) {
		f = ((double)*sp++ - background)/(range);
		if (f < 0.0) f=0.0;
		d = (int)(255.0*Math::Pow(f, (double)gamma));	// gamma correct
		if (d < 0)
			d = 0;
		else if (d > 255)
			d = 255;
		if (*(sp-1) == 65000)
			pixel = Color::FromArgb(255,0,0);
		else
			pixel = Color::FromArgb(d,d,d);
		CurrentImageWindow::FormPtr->CurrentImageBitmap->SetPixel(i,j,pixel);
	}
  }

  CurrentImageWindow::FormPtr->ClearMarkedStarList();
  CurrentImageWindow::FormPtr->Refresh();
//  CurrentImageWindow::ShowThisDialog();

}


void UpdateGuideImage(void)
{
/*  GtkWidget *widget;
  unsigned char *dp;
  unsigned short *sp;
  char *bufptr;
  int background, range, d, i, j, npixels, h, w;
  int x, y, fullh, fullw;
  float gamma;
  double f;

  fullh = RGBw;
  fullw = RGBh;
  h = guideImage.light_frame.h;
  w = guideImage.light_frame.w;
  x = guideImage.light_frame.x;
  y = guideImage.light_frame.y;

  npixels = fullh * fullw;
  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowBackEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf_s(bufptr, "%d", &background);
  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowRangeEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf_s(bufptr, "%d", &range);
  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowGammaEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf_s(bufptr, "%f", &gamma);
  if ((gamma < 0.01) || (gamma > 3.0)) {
    Form1::StatusPrint("*** Warning - Gamma out of range (0.01:3.0), "
		"using default of 0.33\n");
    gamma = 0.33;
  }

  sp = guideImage.light_frame.frame;
  dp = RGBGuideBuf;
  if (background == range)
    background--;

  for (j = 0; j < h; ++j) {
    for (i = 0; i < w; ++i) {
      if ((j >= y) && (j < y+h) && (i >= x) && (i < x+w)) {
	f = ((double)*sp++ - background)/(range);
	if (f < 0.0) f=0.0;
	d = (int)(255.0*pow(f, gamma));	// gamma correct
	if (d < 0) {
	  d = 0;
	} else if (d > 255) {
	  d = 255;
	}
	if (*(sp-1) == 65000) {
	  dp[RED] = 255;
	  dp[GREEN] = 0;
	  dp[BLUE] = 0;
	} else {
	  dp[RED] = d;
	  dp[GREEN] = d;
	  dp[BLUE] = d;
	}
      } else {
	dp[RED] = 0;
	dp[GREEN] = 0;
	dp[BLUE] = 0;
      }
      dp += 3;
    }
  }

  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowDrawingArea");
  gtk_drawing_area_size(GTK_DRAWING_AREA(widget), w, h);
  gtk_widget_show(GuideFrameWindow);   */

  return;
}


void removeHotPixels(FRAME *light)
{
  char Message[160];
  int offset[8], ipix, numpix, pixval, j, jpix;
  int nearpix[8], x, y, npixels, i, numReplaced;
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
    if ((pixval > 60000) || (pixval < 0)) {
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
      sigp = sqrt(avep);
      numsig = fabs(((float)pixval) - avep)/sigp;
      if (numsig > 100.0) {
	y = ipix/light->w;
	x = ipix - y*light->w;
/* 	printf("\nGot hot pixel (%d) at (%d,%d), replaced it with %d", */
/* 	       pixval, x, y, ((int) avep)); */
/* 	if (pixval < 60000) { */
/* 	  printf("\nReplacing small hot pixel: %d %d %d %f",  */
/* 		 pixval, x, y, avep); */
/* 	} */
	light->frame[ipix] = (unsigned short) avep;
	numReplaced++;
      }
    }
  }
  sprintf_s(Message,sizeof(Message),"*** Info: Replaced %d hot pixels in image\n",
			numReplaced);
  Form1::StatusPrint(Message);

  return;
}

int establish_link(CCD *ccd, int Open)
{
  char Message[160];
  int  status, success;

  // Establish link if requested to open & not already linked

  if (Open) {  //link
    if (strstr(ccd->name,"SBIG") != NULL) {
      status = pCam_EstablishLink(ccd->port);
      if (status == CE_NO_ERROR) {
		sprintf_s(Message, sizeof(Message), "*** INFO - Link Established to SBIG ccd "
			"on device %s\n", ccd->port);
		Form1::StatusPrint(Message);
		success = TRUE;
      } else {
		sprintf_s(Message, sizeof(Message), "*** WARNING - Link Failed, code: %d\n", status);
		Form1::StatusPrint(Message);
		success = FALSE;
      }
      ccd->make = SBIG_MAKE;
    } else if (strstr(ccd->name,"Apogee") != NULL) {
      success = apCam_EstablishLink();
      if (! success) {
		sprintf_s(Message, sizeof(Message),
			"*** Warning - Couldn't link to ccd %s on device %s\n",
			ccd->name, ccd->port);
		Form1::StatusPrint(Message);
		success = FALSE;
      } else {
		sprintf_s(Message,sizeof(Message), "*** Info - Connected to ccd %s on device %s\n",
			ccd->name, ccd->port);
		Form1::StatusPrint(Message);
		success = TRUE;
      }
      ccd->make = APOGEE_MAKE;
    } else if ((strstr(ccd->name,"MX") != NULL) ||
	       (strstr(ccd->name,"SXV") != NULL)) {
      strcpy_s(ccd->mx_sxv_info.filename, sizeof(ccd->mx_sxv_info.filename), "/dev/ccda");
      success = spCam_EstablishLink(ccd);

      if (! success) {
		sprintf_s(Message, sizeof(Message),
			"*** Warning - Couldn't link to ccd %s on device %s\n",
			ccd->name, ccd->port);
		Form1::StatusPrint(Message);
		success = FALSE;
      } else {
		sprintf_s(Message, sizeof(Message), "*** Info - Connected to ccd %s on device %s\n",
			ccd->name, ccd->port);
		Form1::StatusPrint(Message);
		success = TRUE;
      }
      ccd->make = SXPRESS_MAKE;
    } else {
      sprintf_s(Message, sizeof(Message), "*** Warning - Invalid ccd type %s\n", ccd->name);
	  Form1::StatusPrint(Message);
      success = FALSE;
    }

  } else { // unlink

    if (strstr(ccd->name,"SBIG") != NULL) {
      pCam_Unlink();
    } else if (strstr(ccd->name,"Apogee") != NULL) {
      apCam_Unlink();
    } else if ((strstr(ccd->name,"MX") != NULL) ||
	       (strstr(ccd->port,"SXV") != NULL)) {
      spCam_Unlink(ccd);
    }
    success = TRUE;
  }
  
  return success;
}



int get_ccd_info(CCD *ccd)
{
  char Message[240], statusString[80];
  int result, success;
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
		return -1;
      }
      in.request = 1;
      result = pCam_GetCCDInfo(&in, (void *)&ccd->info1);
      if (result != CE_NO_ERROR) {
		Form1::StatusPrint("*** WARNING - Can't get basic tracking CCD info...\n");
		pCam_GetStatusString(statusString);
		sprintf_s(Message, sizeof(Message), "              [%d]: %s\n", result,
				  statusString);
		Form1::StatusPrint(Message);
		return -1;
      }
      in.request = 2;
      pCam_GetCCDInfo(&in, (void *)&ccd->info2);
      if (result != CE_NO_ERROR) {
		Form1::StatusPrint("*** WARNING - Can't get extended CCD info...\n");
		pCam_GetStatusString(statusString);
		sprintf_s(Message, sizeof(Message), "              [%d]: %s\n", result,
				statusString);
		Form1::StatusPrint(Message);
		return -1;
      }
      break;
    case APOGEE_MAKE:
      success = apCam_GetCCDInfo(&ccd->apogee_info);
      break;
    case SXPRESS_MAKE:
      success = spCam_GetCCDInfo(&ccd->mx_sxv_info);
      break;
  }

  return 0;
}
void GetCCDFrameSettings(CCD *ccd, int *x, int *y, int *w, int *h, int *b)
{
  *x = 0;
  *y = 0;
  switch (ccd->make) {
    case SBIG_MAKE:
      *w = ccd->info.readoutInfo[*b].width;
      *h = ccd->info.readoutInfo[*b].height;
      break;
    case APOGEE_MAKE:
      *w = ccd->apogee_info.ImgColumns/(*b+1);
      *h = ccd->apogee_info.ImgRows/(*b+1);
      break;
    case SXPRESS_MAKE:
      *w = ccd->mx_sxv_info.width/(*b+1);
      *h = ccd->mx_sxv_info.height/(*b+1);
      break;
  }
  return;
}


int ExposeSingleFrame(void)
{
  static int Busy=false;
  int i, d, nbytes, darkNeeded, gotDark, gotFlat;
  int success, hours, mins, isecs, degs, answer;
  char Message[80];
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

  if ((! ccd->Image.saved) && (ccd->Image.light_frame.active)) {
    answer = MessageBox("Current Image Not Saved, saved it?", YESNO);
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

  nbytes = readout.width*readout.height*sizeof(short);
  ccd->Image.light_frame.frame = (unsigned short *)
    realloc(ccd->Image.light_frame.frame, nbytes);

  ccd->Image.dark_frame.frame = (unsigned short *)
    realloc(ccd->Image.dark_frame.frame, nbytes);

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

int ExposeSeriesFrames(void) {
  static int readoutTime[3]={60,20,10};

  char objectName[20], imageDir[80], Message[320];
  char FileName[160], buffer[80];
  time_t currentSeconds, startSeconds, endSeconds;
  struct tm startTime, *broken_time;
  unsigned int ihours, imins, isecs, nbytes;
  unsigned int nSequences, nFrames, nExposures;
  int d;
  int position, i, diff, status, nfilters, gotDark, gotFlat;
  int darkNeeded, ifilter, intervalSec, success;
  float startHours, endHours, prevExposure;
  float duration, interval, sequenceDuration;
  float eTime;
  double ccd_temp, dark_temp;

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
  
  interval = (float) (seriesSettings.interval/60.0); /* convert to hours */
  
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
	(interval+sequenceDuration)));
  } else {
    nSequences = (unsigned int) (duration / (interval+sequenceDuration));
  }
  nFrames = nSequences * nfilters;
  
  /* Let user review parameters */
  
  sprintf_s(Message,sizeof(Message), "Your series is:\n"
	  "  Start Time:     %f (hours)\n"
	  "  End Time:       %f (hours)\n"
	  "  Duration:       %f (hours)\n"
	  "  Interval:       %f (hours)\n"
	  "  # of sequences: %d\n"
	  "  # of frames:    %d\n"
	  "  Binning:        %d\n"
	  "  Frame Size:     %d x %d\n",
	  startHours, endHours, duration, interval*60.0,
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

  nbytes = readout.width*readout.height*sizeof(short);
  ccd->Image.light_frame.frame = (unsigned short *)
    realloc(ccd->Image.light_frame.frame, nbytes);
  ccd->Image.dark_frame.frame = (unsigned short *)
    realloc(ccd->Image.dark_frame.frame, nbytes);

  /* Start series */

     /* Convert times to seconds from epoch */

  time(&currentSeconds);
  broken_time = NULL;
  localtime_s(broken_time, &currentSeconds);

  ihours = ((int) startHours);
  imins  = ((int) ((startHours-ihours)*60.0));
  isecs  = ((int) ((startHours-ihours-imins/60.0)*3600.0));
  startTime.tm_hour = ihours;
  startTime.tm_min  = imins;
  startTime.tm_sec  = isecs;
  startTime.tm_mday  = broken_time->tm_mday;
  startTime.tm_mon  = broken_time->tm_mon;
  startTime.tm_year = broken_time->tm_year;
  startSeconds = (time_t) mktime(&startTime);
  endSeconds = (time_t) (startSeconds + duration*3600.0);

  /* Wait for start of series, if required */

  if (! StartSeriesASAP) {
    diff = ((int) (startSeconds - currentSeconds));
    if (diff > 0.0) {
      ihours = ((int) (diff/3600.0));
      imins = ((int) ((diff - ihours*3600.0)/60.0));
      isecs = ((int) (diff - ihours*3600.0 - imins*60.0));
      sprintf_s(Message, sizeof(Message), "%02d:%02d:%02d until start...\n",
				ihours, imins, isecs);
	  Form1::StatusPrint(Message);
    }
    
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
      time(&currentSeconds);
    }
  }

  sprintf_s(Message, sizeof(Message), "Starting series...\n");
  Form1::StatusPrint(Message);

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

      sprintf_s(buffer, sizeof(buffer), "%d", nExposures);
	  Form1::CCDAutoForm->SetProcessingExpNumTextBox(buffer);

      /* Check for user intervention */

      if (StopSeries) {
	    SeriesStarted = false;
	    return true;
      }

      while (PauseSeries) {
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

      ccd->Image.Filter[0] = filterSet[position-1];
      ccd->Image.Filter[1] = '\000';
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

      /* update image parameters */

      ccd->Image.saved = FALSE;
	  strcpy_s(ccd->Image.FileName, sizeof(ccd->Image.FileName),"");
	  strcpy_s(ccd->Image.ObjectName,sizeof(ccd->Image.ObjectName), seriesSettings.objectName);

      /* Write out image */

      sprintf_s(FileName, sizeof(FileName), "%s/%s%c%03d.fits", imageDir, objectName,
				filterSet[position-1], nSequences);
      sprintf_s(Message, sizeof(Message), "Writing image to file: %s\n", FileName);
	  Form1::StatusPrint(Message);
	  strcpy_s(ccd->Image.light_frame.UT, sizeof(ccd->Image.light_frame.UT), "");
	  strcpy_s(ccd->Image.light_frame.UTDATE,sizeof(ccd->Image.light_frame.UTDATE), "");
      writeFITS(&ccd->Image, 1, FileName, objectName);
      ccd->Image.saved = true;
	  strcpy_s(ccd->Image.FileName, sizeof(ccd->Image.FileName), FileName);
	  Form1::CCDAutoForm->SetCurrentSeriesFileNameTextBox(FileName);

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
    time(&currentSeconds);
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

    if (interval > 0.0) {
      intervalSec = ((int) (interval*3600.0));
      sprintf_s(Message, sizeof(Message), "Sequence done, sleeping for %d seconds\n",
	      intervalSec);
	  Form1::StatusPrint(Message);
      do {
		sprintf_s(Message, sizeof(Message), "%d", intervalSec);
		Form1::CCDAutoForm->SetTimeToNextExpTextBox(Message);
		usleep(1000000);
		intervalSec--;
      } while (intervalSec > 0);
      
    }
    
  } while (currentSeconds < endSeconds);

  sprintf_s(Message, sizeof(Message), "Finished %d exposures...\n", nExposures);
  Form1::StatusPrint(Message);
  SeriesStarted = false;

  return true;
}

int measureListStars(IMAGE *Image, STAR *List)
{
  STAR *sptr;
  char buffer[160], ImageFileName[160], *cptr;
  int starNum, c, status, AnyStarFailed;
  OBJECT objectInfo;
  double JD, HJD;
  float AirMass;

  if (List == NULL) return TRUE;

  sptr = List;
  c = '\\';

  starNum = 1;
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
  status = GetObjectInfo(Image->ObjectName, &objectInfo);
  if (status) {
    CalcObsParms(&AirMass, &JD, &HJD, &objectInfo, &ObsSettings,
		 Image->light_frame.UT, Image->light_frame.UTDATE,
		 Image->light_frame.exposure);
  } else {
    AirMass = 999.0;
    JD = 999.0;
    HJD = 999.0;
  }
  AnyStarFailed = FALSE;
  while (sptr != NULL) {
    doPhotometry(&ccd->Image, sptr->x, sptr->y, sptr->max, &sptr->fwhm,
		 &sptr->skyFlux, &sptr->flux, &sptr->mag, &sptr->magErr);
    sprintf_s(buffer, sizeof(buffer), "%3d %8s %13.5lf %6.1f %6.1f %8.0f %8.0f "
	    "%5.1f %7.3f +/- %6.3f %6.4f %s %20s\n",
	    starNum, Image->light_frame.UT, HJD, sptr->x, sptr->y,
	    sptr->skyFlux, sptr->flux, sptr->fwhm, sptr->mag,
	    sptr->magErr, AirMass, Image->Filter, ImageFileName);
	Form1::StatusPrint(buffer);
    if ((sptr->fwhm < photometrySettings.minFWHM) ||
	(sptr->fwhm > photometrySettings.maxFWHM) || (sptr->mag < 0.0)) {
		Form1::StatusPrint("*** WARNING - Skipping measurement of above star...\n");
      AnyStarFailed = TRUE;
      sptr = sptr->next;
      continue;
    }
    if (photometrySettings.logResults) {
      sprintf_s(buffer, sizeof(buffer), "%3d\t%8s\t%13.5lf\t%6.1f\t%6.1f\t%8.0f\t%8.0f\t"
	      "%5.1f\t%7.3f\t%6.3f\t%6.4f\t%s\t%20s\n",
	      starNum, Image->light_frame.UT, HJD, sptr->x, sptr->y,
	      sptr->skyFlux, sptr->flux, sptr->fwhm, sptr->mag,
	      sptr->magErr, AirMass, Image->Filter, ImageFileName);
      fprintf(photometrySettings.logFilePtr, "%s", buffer);
      fflush(photometrySettings.logFilePtr);
    }
    if (photometrySettings.plotResults) {
      AddToPhotPlot(starNum, sptr, Image->light_frame.UT, HJD,
		    Image->Filter[0]);
    }
    sptr = sptr->next;
    starNum++;
  }
  if (photometrySettings.plotResults)
    AddToPhotPlot(0, sptr, Image->light_frame.UT, HJD,
		  Image->Filter[0]);  /* Display plot */

  return (! AnyStarFailed);
}


void doPhotometry(IMAGE *Image, float starX, float starY, int max,
		  float *FWHM, float *SkyFlux, float *StarFlux,
		  float *Magnitude, float *MagErr)
{
  FRAME *frame;
  int imageMinX, imageMaxX, imageMinY, imageMaxY;
  int minX, maxX, minY, maxY, x, y, ipix, pixval, centerVal;
  int numPixels, w, h;
  float r, val, medianSky, sigma, error, fitMax, fitFWHM, fitX, fitY, rmin;
  char buffer[80];
  PIXCELL *PixList, *pptr, *prev, *next;

  /* Default values */

  *FWHM = -999.0;
  *SkyFlux = -999.0;
  *StarFlux = -999.0;
  *Magnitude = (float) -99.999;
  *MagErr = (float) -9.999;

  /* Get needed image parameters */

  frame = &Image->light_frame;
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
      ipix = (y-imageMinY) * w + (x-imageMinX);
      pixval = frame->frame[ipix];
      r = (x-starX)*(x-starX) + (y-starY)*(y-starY);
      if (r > 0.0) r = sqrt(r);
      if ((r >= photometrySettings.skyInnerRadius) &&
	      (r <= photometrySettings.skyOuterRadius)) {
		val = ((float) pixval);
		putpixval(val, (float) x, (float) y, r, &PixList);
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
      sigma = sqrt(val);
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
  }

  freepix(PixList);

  /* Find star flux */

  numPixels = 0;
  *StarFlux = 0.0;
  rmin = 99999.0;
  for (x=minX; x<=maxX; x++) {
    for (y=minY; y<=maxY; y++) {
      ipix = (y-imageMinY) * w + (x-imageMinX);
      pixval = frame->frame[ipix];
      r = (x-starX)*(x-starX) + (y-starY)*(y-starY);
      if (r > 0.0) r = sqrt(r);
	  if (r < rmin) {
		  rmin = r;
		  centerVal = pixval;
	  }
      if (r <= photometrySettings.aperatureRadius) {
	     *StarFlux += ((float) pixval);
	     numPixels++;
      }
    }
  }

  /* compute sky flux inside star aperature */

  *SkyFlux = medianSky * numPixels;

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

  error = (float) sqrt(*StarFlux/CCDGAIN + *SkyFlux/CCDGAIN);
  *MagErr = (float) (1.0857 * error / *StarFlux);

  /* Fit PSF */

  PixList = NULL;
  numPixels = 0;
  for (x=minX; x<=maxX; x++) {
    for (y=minY; y<=maxY; y++) {
      ipix = (y-imageMinY) * w + (x-imageMinX);
      pixval = frame->frame[ipix];
      r = (x-starX)*(x-starX) + (y-starY)*(y-starY);
      if (r > 0.0) r = sqrt(r);
      if (r <= photometrySettings.skyOuterRadius) {
		val = ((float) pixval) - medianSky;
		putpix(val, (float) x, (float) y, r, &PixList);
		numPixels++;
      }
    }
  }

  /* If valid data for star, fit PSF */

  if (numPixels > 0) {
    fitX = starX;
	fitY = starY;
	fitMax = (float) centerVal;
    FitPSF(PixList, &fitMax, &fitFWHM, &fitX, &fitY);
    *FWHM = fitFWHM;
    starX = fitX;
    starY = fitY;
  }

  /* Show results on current image window or Guiding window */

  if (Image != &guideImage) {
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

    /* Show PSF plot if requested */

	if (CurrentImageWindow::FormPtr->PlotCheckBoxChecked()) {
		DisplayPSF(PixList, fitMax, fitFWHM);
	}
	CurrentImageWindow::MarkStar(starX, starY);
  } else {
    sprintf_s(buffer, sizeof(buffer), "%5.1f", *FWHM);
	GuideFrameWindow::FormPtr->SetGuideFrameFWHMTextBox(buffer);
//  sprintf_s(buffer, sizeof(buffer), "%8.0f", *StarFlux);
//	GuideFrameWindow::FormPtr->SetGuideFrameStarFluxTextBox(buffer);
//  sprintf_s(buffer, sizeof(buffer), "%8.0f", *SkyFlux);
//	GuideFrameWindow::FormPtr->SetGuideFrameSkyFluxTextBox(buffer);
//  sprintf_s(buffer, sizeof(buffer), "%6.3f", *Magnitude);
//	GuideFrameWindow::FormPtr->SetGuideFrameMagTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%7.2f", fitX);
	GuideFrameWindow::FormPtr->SetGuideFrameStarXTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%7.2f", fitY);
	GuideFrameWindow::FormPtr->SetGuideFrameStarYTextBox(buffer);

    /* Show PSF plot if requested */

	if (GuideFrameWindow::FormPtr->PlotCheckBoxChecked()) {
		DisplayPSF(PixList, fitMax, fitFWHM);
	}
//	MarkStar(GuideFrameWindow::FormPtr->GuideFramePictureBox, starX, starY);
  }

  freepix(PixList);

  return;
}

int FitPSF(PIXCELL *PixList, float *fitMax, float *fitFWHM,
	   float *fitX, float *fitY)
{
	int NumPoints, i, Success;
	static double covar[4][4], alpha[4][4], parms[4];
	static double chisq, ochisq, alambda;
	float x[2000], y[2000], val[2000], sig[2000];
	PIXCELL *pptr;

	pptr = PixList;
	i = 0;
	while (pptr != NULL) {
		x[i] = pptr->x;
		y[i] = pptr->y;
		val[i] = pptr->val;
		if (pptr->val > 1.0)
			sig[i] = sqrt(pptr->val);
		else
			sig[i] = 1.0;
		i++;
		if (i > 1999) {
			break;
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
    return FALSE;
  }
  da[0] = oneda[0][0];
  da[1] = oneda[1][0];
  da[2] = oneda[2][0];
  da[3] = oneda[3][0];
  if (*alambda == 0.0) {
    /* covsrt(covar); */
    return TRUE;
  }
  atry[0] = a[0] + da[0];
  atry[1] = a[1] + da[1];
  atry[2] = fabs(a[2]+da[2]);
//  if (atry[2] > G) atry[2] = G;
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
  return TRUE;
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
	    return FALSE;
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
      return FALSE;
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
  return TRUE;
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
			  seriesSettings.AutoBumpScope = FALSE;
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
		PhotometryPlotWindow::AddGraphPoint(dptr);
      break;

    case 1:  /* Save Variable star magnitude */
      dptr = (DIFFPHOT *) malloc(sizeof(DIFFPHOT));
      if (dptr == NULL) {
		  Form1::CCDAutoForm->StatusPrint("*** WARNING - Can't allocate memory for diff photo.\n");
		  photometrySettings.plotResults = FALSE;
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

int updateListStars(IMAGE *Image, STAR *List)
{
  char buffer[160];
  STAR *sptr;
  FRAME *frame;
  float starX, starY, findRad;
  int xmin, xmax, ymin, ymax;
  float x, y;
  int Found, max, starNum;

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
	  Form1::StatusPrint(    "      Terminating list measurement for this image\n");
      return FALSE;
    } else if ((fabs(starX-x) > findRad) || (fabs(starY-y) > findRad)) {
      sprintf_s(buffer, sizeof(buffer), "*** WARNING - Star #%d at (%7.2f,%7.2f) shifted by: "
	      " (%5.1f,%5.1f)\n",
	      starNum, starX, starY, (starX-x), (starY-y));
	  Form1::StatusPrint(buffer);
	  Form1::StatusPrint(    "      Terminating list measurement for this image\n");
      return FALSE;
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
  return TRUE;
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

	if (! DefineListDialogExists)
		gcnew DefineListDialog();

	CurrentStarListSave = CurrentStarList;
	DefineListDialog::FormPtr->ShowTheDialog();
}

int AddStar(void)
{
  char buffer[160];
  STAR *sptr, *ptr;
  float min;
  
  sptr = (STAR *) malloc(sizeof(STAR));
  if (sptr == NULL) {
	  Form1::CCDAutoForm->StatusPrint("*** WARNING - Can't allocate memory for new star...\n");
    return FALSE;
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
			"max: %d, FWHM: %6.2f\n", sptr->x, sptr->y, sptr->max,
			sptr->fwhm);
		Form1::CCDAutoForm->StatusPrint(buffer);
	  }
      return FALSE;
    }
    ptr = ptr->next;
  }

  /* Add to list */

  sptr->found = TRUE;
  sptr->measured = TRUE;
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
	  "*** INFO - Adding star: (%7.2f,%7.2f), max: %d, FWHM: %6.2f\n",
	  sptr->x, sptr->y, sptr->max, sptr->fwhm);
  Form1::CCDAutoForm->StatusPrint(buffer);

  return TRUE;
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
  CurrentStarListDefined = FALSE;

  return;
}



void SetPhotometrySettingsDialogValues(void) {

	char buffer[80];

    sprintf_s(buffer, sizeof(buffer), "%5.1f", photometrySettings.aperatureRadius);
	PhotometrySettingsDialog::FormPtr->SetAperatureRadiusTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%7.3f", photometrySettings.zeroPoint);
	PhotometrySettingsDialog::FormPtr->SetZeroPointTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%5.1f", photometrySettings.findRadius);
	PhotometrySettingsDialog::FormPtr->SetFindRadiusTextBox(buffer);
    sprintf_s(buffer, sizeof(buffer), "%5.1f", photometrySettings.minPeak);
	PhotometrySettingsDialog::FormPtr->SetMinPeakTextBox(buffer);
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
	PhotometrySettingsDialog::FormPtr->SetLogFileNameTextBox(photometrySettings.logFileName);
	PhotometrySettingsDialog::FormPtr->SetLogResultsCheckBox(photometrySettings.logResults);
	PhotometrySettingsDialog::FormPtr->SetPlotResultsCheckBox(photometrySettings.plotResults);
	PhotometrySettingsDialog::FormPtr->SetAutoFindCheckBox(photometrySettings.autoFind);
	PhotometrySettingsDialog::FormPtr->SetOffsetSkyCheckBox(photometrySettings.offsetSky);
}

void GetPhotometrySettingsDialogValues(void) {

	char buffer[80];

	PhotometrySettingsDialog::FormPtr->GetAperatureRadiusTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.aperatureRadius);
	PhotometrySettingsDialog::FormPtr->GetZeroPointTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.zeroPoint);
	PhotometrySettingsDialog::FormPtr->GetFindRadiusTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.findRadius);
	PhotometrySettingsDialog::FormPtr->GetMinPeakTextBox(buffer);
    sscanf_s(buffer, "%f", &photometrySettings.minPeak);
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
	PhotometrySettingsDialog::FormPtr->GetSkyOuterRadiusTextBox(photometrySettings.logFileName);
	PhotometrySettingsDialog::FormPtr->GetLogResultsCheckBox(&photometrySettings.logResults);
	PhotometrySettingsDialog::FormPtr->GetPlotResultsCheckBox(&photometrySettings.plotResults);
	PhotometrySettingsDialog::FormPtr->GetAutoFindCheckBox(&photometrySettings.autoFind);
	PhotometrySettingsDialog::FormPtr->GetOffsetSkyCheckBox(&photometrySettings.offsetSky);
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


void ConfigDIO(void) {

	int status;
	char message[160];

	// Configuration as of 02/06/07
		// Port A - not used, set to input
		// Port B - not used, set to input
		// Port C - set to output
			// bits 0-2 -> Filter Wheel positions 0-6
			// bit  3   ->  not used
			// bit  4   -> Mirror Cover 1 is open, 0 is closed
			// bits 5-7 -> not used

	status = cbDConfigPort(USB1024BOARD0, FIRSTPORTA, DIGITALIN); // not used yet
	if (status != NOERRORS) {
		sprintf_s(message,sizeof(message),"*** Warning - Can't configure DIO - Error #%d\n",
			status);
			Form1::StatusPrint(message);
		return;
	}
	status = cbDConfigPort(USB1024BOARD0, FIRSTPORTB, DIGITALIN);  // not used yet
	status = cbDConfigPort(USB1024BOARD0, FIRSTPORTCL, DIGITALOUT);  // filter wheel
	status = cbDConfigPort(USB1024BOARD0, FIRSTPORTCH, DIGITALOUT);  // bit1 mirror cover
	
	cbDOut(USB1024BOARD0, FIRSTPORTCL, 0); // set filterwheel to postion 0
	cbDOut(USB1024BOARD0, FIRSTPORTCH, 0); // Mirror cover closed
}

int SetCFW6APosition(unsigned short position) {

	char message[160];

	if ((position < 0) || (position > 5)) {
		sprintf_s(message,sizeof(message),
			"*** Warning - Internal Error, bad filterwheel position: %d\n",position);
		Form1::StatusPrint(message);
		return FALSE;
	}

	cbDOut(USB1024BOARD0, FIRSTPORTCL, position);
	return TRUE;
}

int MirrorCover(bool open) {

	if (open) {
		cbDBitOut(USB1024BOARD0, FIRSTPORTA, 20, 1);
	} else {
		cbDBitOut(USB1024BOARD0, FIRSTPORTA, 20, 0);
	}
	return TRUE;
}




}

