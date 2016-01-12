
#include <queue.h>
#include "stdafx.h"
#include "Form1.h"
#include "doRoutines.h"

#define PI 3.141592654

/* Globals */


int dataIsReady = FALSE;
int input_tag = 0;

char filterSet[NUMFILTERS] = {'U','B','V','R','I','C'};
X_INFO x_info;
extern gpointer dummy;
int DontShowImageProgress;
int DontShowGuidingProgress;
int ImagingShutterClosed=TRUE;
int ImageInProgress=FALSE;

/* Externals */

extern SINGLESETTINGS singleSettings;
extern DARKFRAMESETTINGS darkFrameSettings;
extern FLATFRAMESETTINGS flatFrameSettings;
extern STACKSETTINGS stackSettings;
extern PHOTOMETRYSETTINGS photometrySettings;
extern GUIDINGSLITSETTINGS GuidingSlitSettings;
extern int GetScopeRADEC;
extern int queueID;
extern int PauseSeries;
extern float queryr_dialog_answer;
extern int DownLoadCancel;
extern int CancelCurrentAcquire;
extern int CancelCurrentGuidingAcquire;
extern GtkWidget *DownLoadingDialog;
extern GtkWidget *CCDAutoSave;
extern GtkWidget *ProgressDialog;
extern GtkWidget *GuidingProgressDialog;
extern GtkWidget *DarkFrameSettingsDialog;
extern GtkWidget *FlatFrameSettingsDialog;
extern GtkWidget *StackSettingsDialog;
extern GtkWidget *PickAlignStarDialog;
extern int DontUpdate;
extern char binningString[3][4];
extern OBSSETTINGS ObsSettings;
extern guchar *RGBBuf;
extern int RGBw, RGBh;
extern guchar *RGBGuideBuf;
extern int RGBGuidew, RGBGuideh;
extern GtkWidget *CurrentImageWindow;
extern GtkWidget *GuideFrameWindow;
extern CCD *ccd;
extern short ccd_temp_table[4096];
extern short amb_temp_table[4096];
extern double ScopeRA, ScopeDEC;
extern int SeriesStarted;
extern IMAGE guideImage;
extern int CancelSetAlignStar;
extern int AlignStarFound;
extern int ImagingDownloadInProgress;

OBJNODE *ObjectListHead;
char objectListFileName[160];

/* Support routines */

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
  int items, nObjects;

  OBJECT obj;
  OBJNODE *optr, *next;
  FILE *OBJfptr;

  /* Open object list file */

  if (fileName == NULL) {
    sprintf(Message, "*** Warning - OBJECTLIST environment variable"
	   " not set...\n No objects available...\n");
    StatusPrint(Message);
    return FALSE;
  }

    OBJfptr = fopen(fileName, "r");
  //  OBJfptr = fopen("/usr/share/astro/ObjectList.lst","r");
  if (OBJfptr == NULL) {
    sprintf(Message, "*** Fatal - can't open objects file: %s\n", fileName);
    StatusPrint(Message);
    return FALSE;
  }
  strcpy(objectListFileName, fileName);

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
    strncpy(obj.name,bptr,10);       obj.name[10] = 0;       bptr += 11;
    stripTrailingBlanks(obj.name);
    strncpy(obj.objectType,bptr,10); obj.objectType[10] = 0; bptr += 11;
    stripTrailingBlanks(obj.objectType);
    strncpy(obj.specType,bptr,10);   obj.specType[10] = 0;   bptr += 11;
    stripTrailingBlanks(obj.specType);
    strncpy(obj.varType,bptr,10);    obj.varType[10] = 0;    bptr += 11;
    stripTrailingBlanks(obj.varType);
    strncpy(obj.ra,bptr,10);         obj.ra[10] = 0;         bptr += 11;
    strncpy(obj.dec,bptr,9);         obj.dec[9] = 0;         bptr += 10;
    items = sscanf(bptr,"%f %f %f %f %f", &obj.Mags[0],
		   &obj.Mags[1], &obj.Mags[2], &obj.Mags[3], &obj.Mags[4]);
    if (items != 5) {
      sprintf(Message, "*** WARNING - bad format on object %d\n"
	      "Object list truncated\n", nObjects+1);
      StatusPrint(Message);
      fclose(OBJfptr);
      return TRUE;
    }
    if (! AddObject(&obj)) {
      return FALSE;
    }
    nObjects++;
  } while (TRUE);
  fclose(OBJfptr);

  sprintf(Message, "*** INFO - Read in %d objects\n", nObjects);
  StatusPrint(Message);

  return TRUE;
}

int AddObject(OBJECT *obj)
{
  char Message[160];
  OBJNODE *optr;

  if (ObjectListHead == NULL) {              /* Empty List */
    ObjectListHead = (OBJNODE *) malloc(sizeof(OBJNODE));
    if (ObjectListHead == NULL) {
      sprintf(Message,"*** Fatal - Can't allocate memory for Object List\n");
      StatusPrint(Message);
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

int GetObjectInfo(char *objectName, OBJECT *objectInfo)
{
  int len;
  char Message[80];
  OBJNODE *optr;

  /* Check if we have any objects in list */

  if (ObjectListHead == NULL) {
    sprintf(Message,"Warning - no objects in Objects Lists...\n");
    StatusPrint(Message);
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
    memcpy(objectInfo, &optr->obj, sizeof(OBJECT));
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
    sprintf(Message,"Warning - no objects in Objects Lists...\n");
    StatusPrint(Message);
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
    memcpy(&optr->obj,objectInfo,sizeof(OBJECT));
    success = TRUE;
  } else {
    success = AddObject(objectInfo);
  }

  return success;
}

void WriteObjectList(void)
{
  char Message[160];
  OBJNODE *optr;
  OBJECT *obj;
  FILE *OBJfptr;

  OBJfptr = fopen(objectListFileName,"w");
  if (OBJfptr == NULL){
    sprintf(Message, "\nWarning - Can't write out new object list to file: %s\n",
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
  int success;
  double ccd_temp, air_temp, setpointTemp, percentTE;

  if (!ccd->Linked) {
    sprintf(Message, "*** Not linked to ccd...\n");
    StatusPrint(Message);
    return;
  }

  /* Show current status */

  switch (ccd->make) {
    case SBIG_MAKE:
      *status = pCam_QueryTemperatureStatus(&enabled, &ccd_temp, &air_temp,
					    &setpointTemp, &percentTE);
      if (*status != CE_NO_ERROR) {
	StatusPrint("*** WARNING - Can't get ccd temperature, "
		    "aborting exposure...\n");
	return;
      }
      sprintf(Message, "ccd temp: %f --  air temp: %f\n",
	      ccd_temp, air_temp);
      StatusPrint(Message);
      sprintf(Message, "cooling power: %d %%\n", ((int) (percentTE*100.0)));
      StatusPrint(Message);
      sprintf(Message, "Filter Position: %d\n", ccd->filterPosition);
      StatusPrint(Message);
      break;
    case APOGEE_MAKE:
      ccd_temp = apCam_GetCCDTemperature();
      sprintf(Message, "ccd temp: %f\n", ccd_temp);
      StatusPrint(Message);
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

  if (!ccd->Linked) {
    printf("\n*** WARNING - Can't change filter. Not linked to ccd...\n");
    return;
  }

  switch (ccd->make) {
  case SBIG_MAKE:
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
	sprintf(Message,"*** WARNING - Error changing filter...\n");
	StatusPrint(Message);
	return;
      }
      RunMainIteration(1.0);
    }
    ccd->filterPosition = Position;
    sprintf(Message,"Now using filter: %c\n", filterSet[Position-1]);
    StatusPrint(Message);
    updateStatusInfo(dummy);
    break;
  case APOGEE_MAKE:
    sprintf(Message,"Make sure %c filter is placed on camera.",
	    filterSet[Position-1]);
    MessageBox(Message,OKAY);
    ccd->filterPosition = Position;
    break;
  case SXPRESS_MAKE:
    sprintf(Message,"Make sure %c filter is placed on camera.",
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
  struct tm *broken_time=NULL;
  OBJECT objectInfo;
  FRAME *frame;

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
    fits_report_error(stderr, status); /* print error report */
    strcpy(Image->FileName,"FITS error");
    return;
  }

  /* Create the image */

  naxis = 2;
  naxes[0] = frame->w;
  naxes[1] = frame->h;
  status = 0;
  if (fits_create_img(fptr, bitpix, naxis, naxes, &status)) {
    fits_report_error(stderr, status); /* print error report */
    strcpy(Image->FileName,"FITS error");
    return;
  }

  /* Write out the image */

  fpixel = 1;
  nelements = frame->w*frame->h;
  if (fits_write_img(fptr, TUSHORT, fpixel, nelements,
		     frame->frame, &status)) {
    fits_report_error(stderr, status); /* print error report */
    strcpy(Image->FileName,"FITS error");
    return;
  }

  /* Update "general" keywords */

  ccdgain = CCDGAIN;
  readnoise = READNOISE;
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
    broken_time = gmtime(&frame->time);
    strftime(buffer,sizeof(buffer),"%T",broken_time);
    strcpy(frame->UT,buffer);
  } else {
    strcpy(buffer,frame->UT);
  }
  fits_update_key(fptr, TSTRING, "UT", buffer,
		 "Observation start universal time", &status);
  if (strlen(frame->UTDATE) == 0) {
    strftime(buffer,sizeof(buffer),"%Y-%m-%d", broken_time);
    strcpy(frame->UTDATE,buffer);
  } else {
    strcpy(buffer,frame->UTDATE);
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
    sprintf(buffer, "*** Warning - Can't find info on %s, using scope position...\n",
	   objectName);
    StatusPrint(buffer);
    strcpy(objectInfo.name, "unknown");
    hours = (int) ScopeRA;
    mins  = (int) ((ScopeRA - hours)*60.0);
    secs  = (int) ((ScopeRA - hours - mins/60.0)*3600.0);
    sprintf(objectInfo.ra, "%02d:%02d:%02d", hours, mins, secs);
    degs = (int) ScopeDEC;
    mins = (int) ((ScopeDEC - degs)*60.0);
    secs = (int) ((ScopeDEC - degs - mins/60.0)*3600.0);
    sprintf(objectInfo.dec, "%3d:%02d:%02d", degs, mins, secs);
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
    strcpy(Image->FileName,"FITS error");
    return;
  }

  strcpy(Image->FileName,FileName);
  Image->saved = TRUE;

  return;
}

void doUnlinkToCamera(CCD *ccd, int *status)
{
  doSetTempOffCamera(ccd, status);
  ccd->Linked = FALSE;
  updateStatusInfo(dummy);
  return;
}

/* void doFinish(CCD *ccd, int *status) */
/* { */
/*   char FileName[160]; */
/*   char Object[80]; */
/*   GtkWidget* UnlinkCameraQu; */

/*   if (ccd->Image.light_frame.active && (!ccd->Image.saved)) { */
/*     if (query("Want to save current image")) { */
/*       strcpy(FileName,"image.fits"); */
/*       querys("\nEnter fits file name", FileName, -sizeof(FileName)); */
/*       querys("\nEnter object name", Object, -sizeof(Object)); */
/*       writeFITS(&ccd->Image, 1, FileName, Object); */
/*       ccd->Image.saved = TRUE; */
/*     } */
/*   } */
/*   if (ccd->Linked) { */
/*     UnlinkCameraQu = create_UnlinkCameraQu(); */
/*     gtk_widget_show(UnlinkCameraQu); */
/*   } */
/*   freeImageBuffers(ccd); */
/* } */

void doSetTempOnCamera(CCD *ccd, int *status)
{
  char Message[160];
  double f;

  if (!ccd->Linked) {
    sprintf(Message, "*** Can't turn regulation on, link to ccd first\n");
    StatusPrint(Message);
    return;
  }

  f = queryr_dialog_answer;

  switch (ccd->make) {
    case SBIG_MAKE:
      *status = pCam_SetTemperatureRegulation(TRUE, f);
      if (*status != CE_NO_ERROR) {
	StatusPrint("*** WARNING - Can't set temperature regulation...\n");
	return;
      }
      sprintf(Message,"*** Info - Setting cooling to: %f\n", queryr_dialog_answer);
      StatusPrint(Message);
      updateStatusInfo(dummy);
      break;
    case APOGEE_MAKE:
      apCam_SetTemperatureRegulation(TRUE,f);
      break;
    case SXPRESS_MAKE:
      StatusPrint("*** WARNING - Can't set temperature regulation on "
		  "Starlight Xpress cameras\n");
      break;
  }

  return;
}

void doSetTempOffCamera(CCD *ccd, int *status)
{
  char Message[160];

  if (!ccd->Linked) {
    sprintf(Message, "*** Can't turn regulation off, link to ccd first\n");
    StatusPrint(Message);
    return;
  }

  switch (ccd->make) {
    case SBIG_MAKE:
      *status = pCam_SetTemperatureRegulation(FALSE, 0.0);
      if (*status != CE_NO_ERROR) {
	StatusPrint("*** WARNING - Can't turn off temperature regulation...\n");
	return;
      }
      updateStatusInfo(dummy);
      break;
    case APOGEE_MAKE:
      apCam_SetTemperatureRegulation(FALSE,0);
      break;
    case SXPRESS_MAKE:
      StatusPrint("*** WARNING - Can't set temperature regulation on "
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
  sprintf(Message,"min=%d at (%d,%d)\n", min, i_min%w, i_min/w);
  StatusPrint(Message);
  sprintf(Message,"max=%d at (%d,%d)\n", max, i_max%w, i_max/w);
  StatusPrint(Message);
}

void loadImageImaging(unsigned short *sp, int x, int y, int w, int h, int binning)
{
  char Message[80], buffer[80];
  guchar  *dp;
  double  f, sum, ave;
  float gamma;
  int  d, i, j, min, max, npixels, iave, fullh, fullw;
  GtkWidget *widget;

  /* Allocate RGB buffer for image */

  //  fullw = ccd->info.readoutInfo[binning].width;
  //  fullh = ccd->info.readoutInfo[binning].height;
  //  npixels = fullw*fullh;
  //  if ( npixels <= 0) {
    fullw = ccd->Image.light_frame.w;
    fullh = ccd->Image.light_frame.h;
    npixels = fullw * fullh;
    //  }
  RGBBuf = (guchar *) realloc(RGBBuf, npixels*3);
  RGBw = fullw;
  RGBh = fullh;

  if (CurrentImageWindow == NULL) {
    CurrentImageWindow = create_CurrentImageWindow();
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

  widget = lookup_widget(CurrentImageWindow,"CurrentImageBackEntry");
  sprintf(buffer, "%d", iave);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);

  widget = lookup_widget(CurrentImageWindow,"CurrentImageRangeEntry");
  sprintf(buffer, "%d", max);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);

  gamma = 0.33;
  widget = lookup_widget(CurrentImageWindow,"CurrentImageGammaEntry");
  sprintf(buffer, "%f", gamma);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);

  /* Set the image values */

  widget = lookup_widget(CurrentImageWindow,"CurrentImageMinPixEntry");
  sprintf(Message,"%d", min);
  gtk_entry_set_text(GTK_ENTRY(widget),Message);
  widget = lookup_widget(CurrentImageWindow,"CurrentImageMaxPixEntry");
  sprintf(Message,"%d", max);
  gtk_entry_set_text(GTK_ENTRY(widget),Message);
  widget = lookup_widget(CurrentImageWindow,"CurrentImageAvePixEntry");
  sprintf(Message,"%7.1f", ave);
  gtk_entry_set_text(GTK_ENTRY(widget),Message);

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
	  dp[RED] = 255;
	  dp[GREEN] = 0;
	  dp[BLUE] = 0;
	} else {
	  dp[RED] = d;
	  dp[GREEN] = d;
	  dp[BLUE] = d;
	}
/*       } else { */
/* 	dp[RED] = 0; */
/* 	dp[GREEN] = 0; */
/* 	dp[BLUE] = 0; */
/*       } */
      dp += 3;
    }
  }

  widget = lookup_widget(CurrentImageWindow,"CurrentImageDrawingArea");
  gtk_drawing_area_size(GTK_DRAWING_AREA(widget), fullw, fullh);
  gtk_widget_show(CurrentImageWindow);
}

void loadImageTracking(unsigned short *sp, int x, int y, int w, int h,
		       int binning)
{
  char Message[80], buffer[80];
  guchar  *dp;
  double  f, sum, ave;
  int  d, i, j, min, max, npixels, iave, fullh, fullw;
  GtkWidget *widget;

  /* Allocate RGB buffer for image */

  fullw = ccd->info1.readoutInfo[binning].width;
  fullh = ccd->info1.readoutInfo[binning].height;
  npixels = fullw*fullh;
  if ( npixels <= 0) {
    fullw = guideImage.light_frame.w;
    fullh = guideImage.light_frame.h;
    npixels = fullw * fullh;
  }
  RGBGuideBuf = (guchar *) realloc(RGBGuideBuf, npixels*3);
  RGBGuidew = fullw;
  RGBGuideh = fullh;

  if (CurrentImageWindow == NULL) {
    CurrentImageWindow = create_CurrentImageWindow();
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

  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowBackEntry");
  sprintf(buffer, "%d", iave);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);
  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowRangeEntry");
  sprintf(buffer, "%d", max);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);
  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowGammaEntry");
  sprintf(buffer, "%f", 0.33);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);

  /* Set the image values */

  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowMinPixEntry");
  sprintf(Message,"%d", min);
  gtk_entry_set_text(GTK_ENTRY(widget),Message);
  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowMaxPixEntry");
  sprintf(Message,"%d", max);
  gtk_entry_set_text(GTK_ENTRY(widget),Message);
  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowAvePixEntry");
  sprintf(Message,"%7.1f", ave);
  gtk_entry_set_text(GTK_ENTRY(widget),Message);

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

  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowDrawingArea");
  gtk_drawing_area_size(GTK_DRAWING_AREA(widget), fullw, fullh);
  gtk_widget_show(GuideFrameWindow);
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
    ret = spCam_StartExposure(ccd, expose, readout);
    break;
  }

  return ret;
}

int QueryCCDExposureStatus(CCD *ccd, StartExposureParams *expose)
{
  int ret, status, done, err;
  QueryCommandStatusParams  query_command_status_params;
  QueryCommandStatusResults  query_command_status_results;
  int stat;

  done = FALSE;
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
      stat = apCam_ReadStatus();
      done = (stat == Camera_Status_ImageReady);
      break;
    case SXPRESS_MAKE:
      ret = TRUE;
      break;
  }

  return ret;
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


static void sxDataReady(gpointer data, gint fd, GdkInputCondition in)
{
  gdk_input_remove(input_tag);
  dataIsReady = TRUE;
  return;
}

int GetImage(CCD *ccd, StartReadoutParams *readout, int Light,
	     unsigned short *image_data)
{
  char Message[80];
  short xbinning, ybinning;
  int i, status, percent, success, itry;
  ReadoutLineParams  readout_line_params;
  GtkWidget *Entry;

  Entry = lookup_widget(CCDAutoSave,"MainCCDStatusEntry");
  switch (ccd->make) {
    case SBIG_MAKE:
      if (Light)
	ShowImageProgress("Downloading - Light Frame", 0);
      else
	ShowImageProgress("Downloading - Dark Frame", 0);
      for (i=0; i<readout->height; i++) {
	readout_line_params.ccd = readout->ccd;
	readout_line_params.readoutMode = readout->readoutMode;
	readout_line_params.pixelStart = readout->left;
	readout_line_params.pixelLength = readout->width;
	status = pCam_ReadoutLine(&readout_line_params, 
				  image_data+i*readout->width, 0);
	if (status != CE_NO_ERROR) {
	  sprintf(Message,
		  "*** WARNING - Error reading out image line: %d\n",i);
	  ShowImageProgress(NULL, 0);
	  return FALSE;
	}
	percent = (int) rint(100.0 * ((float)  i) / readout->height);
	if (Light) {
	  ShowImageProgress("Downloading - Light Frame", percent);
	  sprintf(Message,"load: %d%%", percent);
	} else {
	  ShowImageProgress("Downloading - Dark Frame", percent);
	  sprintf(Message,"load: %d%%", percent);
	}
	gtk_entry_set_text(GTK_ENTRY(Entry), Message);
	RunMainIteration(0.01);
	if (CancelCurrentAcquire) {
	  StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	  ShowImageProgress(NULL, 0);
	  return FALSE;
	}
      }
	ShowImageProgress(NULL, 0);
      return TRUE;
      break;
    case APOGEE_MAKE:
      xbinning = ybinning = readout->readoutMode + 1;
      success = apCam_GetImage(image_data, readout->left, readout->top,
			       readout->width, readout->height,
			       xbinning, ybinning);
      return success;
      break;
    case SXPRESS_MAKE:
      dataIsReady = FALSE;
      input_tag  = gdk_input_add(ccd->mx_sxv_info.fd, GDK_INPUT_READ,
				 (GdkInputFunction)sxDataReady, NULL);
      itry = 0;
      do {
	if (dataIsReady)
	  break;
	RunMainIteration(0.01);
	itry++;
      } while (itry < 1000);
      if (itry >= 1000) {
	printf("*** DEBUG - Waited 10 seconds for data ready, exiting...\n");
	exit(-1);
      }
      if (Light)
	ShowImageProgress("Downloading - Light Frame", 0);
      else
	ShowImageProgress("Downloading - Dark Frame", 0);
      for (i=0; i<readout->height; i++) {
	itry = 0;
	do {
	  success = spCam_ReadoutLine(ccd, readout,
				      image_data+i*readout->width,(i==0));
	  if (success)
	    break;
	  RunMainIteration(0.1);
	  itry++;
	} while (itry < 100);
	if (! success) {
	  sprintf(Message,
		  "*** WARNING - Error reading out image line: %d\n",i);
	  ShowImageProgress(NULL, 0);
	  return FALSE;
	}
	percent = (int) rint(100.0 * ((float)  i) / readout->height);
	if (Light) {
	  ShowImageProgress("Downloading - Light Frame", percent);
	  sprintf(Message,"load: %d%%", percent);
	} else {
	  ShowImageProgress("Downloading - Dark Frame", percent);
	  sprintf(Message,"load: %d%%", percent);
	}
	gtk_entry_set_text(GTK_ENTRY(Entry), Message);
	RunMainIteration(0.01);
	if (CancelCurrentAcquire) {
	  StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	  ShowImageProgress(NULL, 0);
	  return FALSE;
	}
      }
	ShowImageProgress(NULL, 0);
      return TRUE;
      break;
  }

}


 /*
  * This is the 'progress' callback
  * passed to sbig_readout()
  */

void snapImaging(CCD *ccd, StartExposureParams *expose,
		 StartReadoutParams *readout, IMAGE *Image)
{
  int  ret, i, percent, status, err, success, done;
  unsigned short *image_data;
  char Message[80];
  double ccd_temp;
  GtkWidget *Entry;
  EndExposureParams  end_exposure_params;
  ReadoutLineParams  readout_line_params;
  QueryCommandStatusParams  query_command_status_params;
  QueryCommandStatusResults  query_command_status_results;

  ImageInProgress = TRUE;

  /*
   * take a dark if needed
   */

  DontUpdate = TRUE;
  Entry = lookup_widget(CCDAutoSave,"MainCCDStatusEntry");
  
  /* Get current temp of dark frame */

  if (! Image->lightOnly) {
    success = GetCCDTemperature(ccd, &ccd_temp);
    if (! success) {
      StatusPrint("*** WARNING - Can't get ccd temperature, "
		  "aborting exposure...\n");
      ImageInProgress = FALSE;
      return;
    }
    Image->dark_frame.temp = ccd_temp;
    
    gtk_entry_set_text(GTK_ENTRY(Entry), "Exposing Dark");
    sprintf(Message,"Starting %f sec. dark frame...\n",
	    expose->exposureTime/100.0);
    StatusPrint(Message);
    
    expose->openShutter = 2;
    time(&Image->dark_frame.time);
    ImagingShutterClosed = TRUE;
    success = StartExposure(ccd, expose, readout);
    if (! success) {
      StatusPrint("*** WARNING - Error starting dark frame...\n");
      ImageInProgress = FALSE;
      return;
    }

    /* Wait to start waiting */

    if (expose->exposureTime > 100) {
      ShowImageProgress("Exposing - Dark Frame", 0);
      for (i = 0; i < expose->exposureTime; i += 20) {
	ShowImageProgress("Exposing - Dark Frame",
			  (int) rint(100.0*i/expose->exposureTime));
	sprintf(Message,"Expose: %4.1f%%", 100.0*i/expose->exposureTime);
	gtk_entry_set_text(GTK_ENTRY(Entry), Message);
	RunMainIteration(0.2);
	if (CancelCurrentAcquire) {
	  StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	  ShowImageProgress(NULL, 0);
	  ImageInProgress = FALSE;
	  return;
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
	StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	ShowImageProgress(NULL, 0);
	ImageInProgress = FALSE;
	EndCCDExposure(ccd, expose);
	return;
      }
    }
    if (i == 1000) {
      StatusPrint("*** WARNING - Dark exposure didn't finish...\n");
      return;
    }
    ShowImageProgress(NULL, 0);
    
    /* Readout dark frame */

    image_data = Image->dark_frame.frame;
    memset(image_data, 0 ,readout->height*readout->width*2);
    ImagingDownloadInProgress = TRUE;
    success = GetImage(ccd, readout, FALSE, image_data);
    if (! success) {
      sprintf(Message, "*** WARNING - Error reading out image\n");
      ImagingDownloadInProgress = FALSE;
      ImageInProgress = FALSE;
      return;
    }
    ImagingDownloadInProgress = FALSE;
		    
    sprintf(Message, "dark frame: \n");
    StatusPrint(Message);
    print_stats(Image->dark_frame.frame, readout->width, readout->height);
    Image->dark_frame.active = TRUE;
    Image->dark_frame.whichCCD = expose->ccd;
    Image->dark_frame.binning = readout->readoutMode;
    Image->dark_frame.x = readout->left;
    Image->dark_frame.y = readout->top;
    Image->dark_frame.w = readout->width;
    Image->dark_frame.h = readout->height;
    Image->dark_frame.exposure = expose->exposureTime/100.0;
  }

  /*
   * take a light frame if required
   */
  
  if (! Image->darkOnly) {

    /* Get current temp of light frame */

    success = GetCCDTemperature(ccd, &ccd_temp);
    if (! success) {
      StatusPrint("*** WARNING - Can't get ccd temperature, "
		  "aborting exposure...\n");
      ImageInProgress = FALSE;
      return;
    }
    Image->light_frame.temp = ccd_temp;
    
    gtk_entry_set_text(GTK_ENTRY(Entry), "Exposing Light");
    sprintf(Message,"Starting %f sec. light frame...\n",
	    expose->exposureTime/100.0);
    StatusPrint(Message);
    time(&Image->light_frame.time);
    expose->openShutter = 1;
    ImagingShutterClosed = FALSE;
    success = StartExposure(ccd, expose, readout);
    if (! success) {
      StatusPrint("*** WARNING - Error starting light frame...\n");
      ImageInProgress = FALSE;
      return;
    }

    /* Wait to start waiting */

    if (expose->exposureTime > 100) {
      ShowImageProgress("Exposing - Light Frame", 0);
      for (i = 0; i < expose->exposureTime; i += 20) {
	ShowImageProgress("Exposing - Light Frame", 
			  (int) rint(100.0*i/expose->exposureTime));
	sprintf(Message,"Expose: %4.1f%%", 100.0*i/expose->exposureTime);
	gtk_entry_set_text(GTK_ENTRY(Entry), Message);
	RunMainIteration(0.2);
	if (CancelCurrentAcquire) {
	  StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	  ShowImageProgress(NULL, 0);
	  ImageInProgress = FALSE;
	  EndCCDExposure(ccd, expose);
	  return;
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
	StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	ShowImageProgress(NULL, 0);
	ImageInProgress = FALSE;
	return;
      }
    }
    if (i >= 1000) {
      StatusPrint("*** WARNING - Light exposure didn't finish...\n");
      return;
    }
    ShowImageProgress(NULL, 0);

    /* Readout light frame */

    image_data = Image->light_frame.frame;
    memset(image_data, 0, readout->height*readout->width*2);
    ImagingDownloadInProgress = TRUE;
    success = GetImage(ccd, readout, TRUE, image_data);
    if (! success) {
      sprintf(Message, "*** WARNING - Error reading out image\n");
      ImagingDownloadInProgress = FALSE;
      ImageInProgress = FALSE;
      return;
    }

    ImagingDownloadInProgress = FALSE;

    Image->light_frame.exposure = expose->exposureTime/100.0;;
     
    /* update image parameters and return */

    sprintf(Message,"image: \n");
    StatusPrint(Message);
    print_stats(Image->light_frame.frame, readout->width, readout->height);
    Image->light_frame.active = TRUE;
    Image->light_frame.whichCCD = expose->ccd;
    Image->light_frame.binning = readout->readoutMode;
    Image->light_frame.x = readout->left;
    Image->light_frame.y = readout->top;
    Image->light_frame.w = readout->width;
    Image->light_frame.h = readout->height;
    Image->light_frame.exposure = expose->exposureTime/100.0;
  }
  DontUpdate = FALSE;
   
  /* Reset system clock from hardware clock because downloading screws up
     system clock */
   
  system("/sbin/hwclock --hctosys");

  ShowImageProgress(NULL, 0);
  updateStatusInfo(dummy);
  ImageInProgress = FALSE;

  return;
}


int snapTracking(CCD *ccd, StartExposureParams *expose,
		 StartReadoutParams *readout, IMAGE *Image)
{
  int  ret, i, percent, status, err;
  unsigned short *image_data;
  char Message[80];
  GtkWidget *Entry;
  double ccd_temp;
  EndExposureParams  end_exposure_params;
  ReadoutLineParams  readout_line_params;
  QueryCommandStatusParams  query_command_status_params;
  QueryCommandStatusResults  query_command_status_results;


  if (ImageInProgress && ImagingShutterClosed)
    return FALSE;

  /*
   * take a dark if needed
   */

  DontUpdate = TRUE;
  Entry = lookup_widget(CCDAutoSave,"MainCCDStatusEntry");
  
  /* Get current temp of dark frame */

  if (! Image->lightOnly) {
    status = pCam_GetCCDTemperature(&ccd_temp);
    if (status != 0) {
      StatusPrint("*** WARNING - Can't get ccd temperature, "
		  "aborting exposure...\n");
      return FALSE;
    }
    Image->dark_frame.temp = ccd_temp;
    
    gtk_entry_set_text(GTK_ENTRY(Entry), "Exposing Dark");
    sprintf(Message,"Starting %f sec. dark frame...\n",
	    expose->exposureTime/100.0);
    StatusPrint(Message);

    if (GuidingSlitSettings.Running && ImageInProgress) {
      expose->openShutter = 0;
    } else {
      expose->openShutter = 2;
    }
    time(&Image->dark_frame.time);
    //ret = SBIGUnivDrvCommand(CC_START_EXPOSURE, expose, NULL);
    ret = pCam_StartExposure(expose);
    if (ret != CE_NO_ERROR) {
      StatusPrint("*** WARNING - Error starting dark frame...\n");
      return FALSE;
    }

    /* Wait to start waiting */

    if (expose->exposureTime > 100) {
      ShowGuidingProgress("Exposing - Dark Frame", 0);
      for (i = 0; i < expose->exposureTime; i += 20) {
	ShowGuidingProgress("Exposing - Dark Frame",
			  (int) rint(100.0*i/expose->exposureTime));
	sprintf(Message,"Dark Expose: %4.1f%%", 100.0*i/expose->exposureTime);
	gtk_entry_set_text(GTK_ENTRY(Entry), Message);
	RunMainIteration(0.2);
	if (CancelCurrentGuidingAcquire) {
	  StatusPrint("*** INFO - Canceling acquisition on user's request\n");
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
	StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	ShowGuidingProgress(NULL, 0);
	return FALSE;
      }
    }

    if (i == 1000) {
      StatusPrint("*** WARNING - Dark exposure didn't finish...\n");
      return FALSE;
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
	sprintf(Message, "*** WARNING - Error reading out image line: %d\n",
		i);
	return FALSE;
      }
      percent = (int) rint(100.0 * ((float)  i) / readout->height);
      
      ShowGuidingProgress("Downloading - Dark Frame", percent);
      sprintf(Message,"Dark load: %d%%", percent);
      gtk_entry_set_text(GTK_ENTRY(Entry), Message);
      RunMainIteration(0.01);
      if (CancelCurrentGuidingAcquire) {
	StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	ShowGuidingProgress(NULL, 0);
	return FALSE;
      }
    }
		    
    sprintf(Message, "dark frame: \n");
    StatusPrint(Message);
    print_stats(Image->dark_frame.frame, readout->width, readout->height);
    Image->dark_frame.active = TRUE;
    Image->dark_frame.whichCCD = expose->ccd;
    Image->dark_frame.binning = readout->readoutMode;
    Image->dark_frame.x = readout->left;
    Image->dark_frame.y = readout->top;
    Image->dark_frame.w = readout->width;
    Image->dark_frame.h = readout->height;
    Image->dark_frame.exposure = expose->exposureTime/100.0;
  }

  /*
   * take a light frame if required
   */
  
  if (! Image->darkOnly) {

    /* Get current temp of light frame */

    status = pCam_GetCCDTemperature(&ccd_temp);
    if (status != 0) {
      StatusPrint("*** WARNING - Can't get ccd temperature, "
		  "aborting exposure...\n");
      return FALSE;
    }
    Image->light_frame.temp = ccd_temp;
    
    gtk_entry_set_text(GTK_ENTRY(Entry), "Exposing Light");
    sprintf(Message,"Starting %f sec. light frame...\n",
	    expose->exposureTime/100.0);
    StatusPrint(Message);
    time(&Image->light_frame.time);
    if (GuidingSlitSettings.Running && ImageInProgress) {
      expose->openShutter = 0;
    } else {
      expose->openShutter = 1;
    }
    //ret = SBIGUnivDrvCommand(CC_START_EXPOSURE, expose, NULL);
    ret = pCam_StartExposure(expose);
    if (ret != CE_NO_ERROR) {
      StatusPrint("*** WARNING - Error starting dark frame...\n");
      return FALSE;
    }

    /* Wait to start waiting */

    if (expose->exposureTime > 100) {
      ShowGuidingProgress("Exposing - Light Frame", 0);
      for (i = 0; i < expose->exposureTime; i += 20) {
	ShowGuidingProgress("Exposing - Light Frame", 
			  (int) rint(100.0*i/expose->exposureTime));
	sprintf(Message,"Light Expose: %4.1f%%", 100.0*i/expose->exposureTime);
	gtk_entry_set_text(GTK_ENTRY(Entry), Message);
	RunMainIteration(0.2);
	if (CancelCurrentGuidingAcquire) {
	  StatusPrint("*** INFO - Canceling acquisition on user's request\n");
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
	StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	ShowGuidingProgress(NULL, 0);
	return FALSE;
      }
    }

    if (i == 1000) {
      StatusPrint("*** WARNING - Light exposure didn't finish...\n");
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
	sprintf(Message, "*** WARNING - Error reading light frame line: %d\n",
		i);
	return FALSE;
      }
      percent = (int) rint(100.0 * ((float) i) / readout->height);
      ShowGuidingProgress("Downloading - Light Frame", percent);
      sprintf(Message,"Light load: %d%%", percent);
      gtk_entry_set_text(GTK_ENTRY(Entry), Message);
      RunMainIteration(0.01);
      if (CancelCurrentGuidingAcquire) {
	StatusPrint("*** INFO - Canceling acquisition on user's request\n");
	ShowGuidingProgress(NULL, 0);
	return FALSE;
      }
    }

    Image->light_frame.exposure = expose->exposureTime/100.0;;
     
    /* update image parameters and return */

    sprintf(Message,"image: \n");
    StatusPrint(Message);
    print_stats(Image->light_frame.frame, readout->width, readout->height);
    Image->light_frame.active = TRUE;
    Image->light_frame.whichCCD = expose->ccd;
    Image->light_frame.binning = readout->readoutMode;
    Image->light_frame.x = readout->left;
    Image->light_frame.y = readout->top;
    Image->light_frame.w = readout->width;
    Image->light_frame.h = readout->height;
    Image->light_frame.exposure = expose->exposureTime/100.0;
  } 
  DontUpdate = FALSE;
   
  /* Reset system clock from hardware clock because downloading screws up
     system clock */
   
  system("/sbin/hwclock --hctosys");

  ShowGuidingProgress(NULL, 0);
  updateStatusInfo(dummy);

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
  
  value = min - 1.;
  do {
    printf("%s (%f) %s : ", prefix, *answer, suffix);
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] == '\n')
      break;
    if (sscanf(buffer, "%f", &value) != 1)
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
    if (sscanf(buffer, "%i", &value) != 1)
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

  sprintf(fileName, "%s/Dark%s_%d.fits",Dir,binningString[lightFrame->binning],
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
    sprintf(Message,"*** Warning - Light (%d,%d) & Dark (%d,%d) sizes"
	    " not compatible, aborting...\n",
	    lightFrame->w, lightFrame->h, darkFrame->w, darkFrame->h);
    StatusPrint(Message);
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
    sprintf(Message,"*** Warning - Temp diff between light and dark frames"
	    " too big: %f %f\n", lightFrame->temp, darkFrame->temp);
    StatusPrint(Message);
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
    sprintf(Message,"*** Warning - Light (%d,%d) & Dark (%d,%d) start"
	    " positions not compatible, aborting...\n",
	    lightFrame->x, lightFrame->y, darkFrame->x, darkFrame->y);
    StatusPrint(Message);
    return FALSE;
  }

  if (fits_read_key(fptr, TINT, "BINNING", &darkFrame->binning,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }

  if (darkFrame->binning != lightFrame->binning) {
    sprintf(Message,"*** Warning - Light (%d) & Dark (%d) binning"
	    " not the same, aborting...\n",
	    lightFrame->binning, darkFrame->binning);
    StatusPrint(Message);
    return FALSE;
  }

  if (fits_read_key(fptr, TINT, "WHICHCCD", &darkFrame->whichCCD,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }

  if (darkFrame->whichCCD != lightFrame->whichCCD) {
    sprintf(Message,"*** Warning - Light (%d) & Dark (%d) whichCCD"
	    " not the same, aborting...\n",
	    lightFrame->whichCCD, darkFrame->whichCCD);
    StatusPrint(Message);
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

  sprintf(fileName, "%s/Flat%s%c.fits", Dir,
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
    sprintf(Message,"*** Warning - Light (%d,%d) & Flat (%d,%d) sizes"
	    " not compatible, aborting...\n",
	    lightFrame->w, lightFrame->h, flatFrame->w, flatFrame->h);
    StatusPrint(Message);
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
    sprintf(Message,"*** Warning - Light (%d,%d) & Flat (%d,%d) start"
	    " positions not compatible, aborting...\n",
	    lightFrame->x, lightFrame->y, flatFrame->x, flatFrame->y);
    StatusPrint(Message);
    return FALSE;
  }

  if (fits_read_key(fptr, TINT, "BINNING", &flatFrame->binning,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }

  if (flatFrame->binning != lightFrame->binning) {
    sprintf(Message,"*** Warning - Light (%d) & Flat (%d) binning"
	    " not the same, aborting...\n",
	    lightFrame->binning, flatFrame->binning);
    StatusPrint(Message);
    return FALSE;
  }

  if (fits_read_key(fptr, TINT, "WHICHCCD", &flatFrame->whichCCD,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    return FALSE;
  }

  if (flatFrame->whichCCD != lightFrame->whichCCD) {
    sprintf(Message,"*** Warning - Light (%d) & Flat (%d) whichCCD"
	    " not the same, aborting...\n",
	    lightFrame->whichCCD, flatFrame->whichCCD);
    StatusPrint(Message);
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
  strcpy(ccd->FlatImage.FileName,fileName);

  return TRUE;
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
    fits_report_error(stderr, status); /* print error report */
    return FALSE;
  }

  /* get image size keywords */

  lightFrame = &Image->light_frame;
  if (fits_read_keys_lng(fptr, "NAXIS", 1, 2, naxes, &nfound, &status)) {
    fits_report_error(stderr, status); /* print error report */
    return FALSE;
  }
  npixels = naxes[0]*naxes[1];

  /* (Re)Allocate memory for image */

  lightFrame->frame = (unsigned short *) realloc(lightFrame->frame,
			      npixels*sizeof(unsigned short));

  /* read in image */

  fpixel = 1;
  nullval = 0;
  if (fits_read_img(fptr, TUSHORT, fpixel, npixels, &nullval,
		    lightFrame->frame, &anynull, &status)) {
    fits_report_error(stderr, status); /* print error report */
    return FALSE;
  }

  /* get some keywords */

  if (fits_read_key(fptr, TFLOAT, "EXPOSURE", &lightFrame->exposure,
		    Comment, &status)) {
    status = 0;
    if (fits_read_key(fptr, TFLOAT, "EXPTIME", &lightFrame->exposure,
		      Comment, &status)) {
      fits_report_error(stderr, status);
      return FALSE;
    }
  }

  if (fits_read_key(fptr, TSTRING, "OBJECT", &Image->ObjectName,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    strcpy(Image->ObjectName, "none");
  }

  if (fits_read_key(fptr, TSTRING, "OBSERVAT", &ObsSettings.name,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    strcpy(ObsSettings.name, "none");
  }

  if (fits_read_key(fptr, TSTRING, "FILTER", &Image->Filter,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    strcpy(Image->Filter, "n");
  }

  if (fits_read_key(fptr, TSTRING, "OBSERVER", &ObsSettings.Observer,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    strcpy(ObsSettings.Observer, "n");
  }

  if (fits_read_key(fptr, TSTRING, "PROJECT", &ObsSettings.Project,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    strcpy(ObsSettings.Project, "n");
  }

  if (fits_read_key(fptr, TINT, "STARTX", &lightFrame->x,
		    Comment, &status)) {
    if (fits_read_key(fptr, TINT, "XORGSUBF", &lightFrame->x,
		      Comment, &status)) {
      fits_report_error(stderr, status);
      lightFrame->x = 0;
    }
  }

  if (fits_read_key(fptr, TINT, "STARTY", &lightFrame->y,
		    Comment, &status)) {
    if (fits_read_key(fptr, TINT, "YORGSUBF", &lightFrame->y,
		      Comment, &status)) {
      fits_report_error(stderr, status);
      lightFrame->y = 0;
    }
  }

  if (fits_read_key(fptr, TINT, "BINNING", &lightFrame->binning,
		    Comment, &status)) {
    if (fits_read_key(fptr, TINT, "XBINNING", &lightFrame->binning,
		      Comment, &status)) {
      fits_report_error(stderr, status);
      lightFrame->binning = 0;
    }
  }

  if (fits_read_key(fptr, TSTRING, "UT", &lightFrame->UT,
		    Comment, &status)) {
    if (fits_read_key(fptr, TSTRING, "TIME-OBS", &lightFrame->UT,
		      Comment, &status)) {
      fits_report_error(stderr, status);
      strcpy(lightFrame->UT,"00:00:00");
    }
  }

  if (fits_read_key(fptr, TSTRING, "DATE-OBS", &lightFrame->UTDATE,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    strcpy(lightFrame->UTDATE,"0000-00-00T00:00:00");
  }

  if (fits_read_key(fptr, TINT, "WHICHCCD", &lightFrame->whichCCD,
		    Comment, &status)) {
    fits_report_error(stderr, status);
    lightFrame->whichCCD = 1;
  }

  lightFrame->w = naxes[0];
  lightFrame->h = naxes[1];
  lightFrame->active = TRUE;
  strcpy(Image->FileName,fileName);

  /* Close the FITS file */

  status = 0;
  if (fits_close_file(fptr, &status)) {
    fits_report_error(stderr, status); /* print error report */
    strcpy(Image->FileName,"FITS error");
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

  sscanf(objectInfo->ra,"%2d:%2d:%f", &hours, &mins, &secs);
  raHours = (hours + mins/60.0 + secs/3600.0);
  r = raHours;
  raRad   = raHours *2.0*PI/24.0;
  sscanf(objectInfo->dec, "%3d:%2d:%f", &deg, &mins, &secs);
  decDeg = deg + mins/60.0 + secs/360.0;
  d = decDeg;
  decRad = decDeg *2.0*PI/360.0;
  sscanf(UTBuffer,"%2d:%2d:%f", &hours, &mins, &secs);
  xhours = hours + mins/60.0 + (secs+exposure/2.0)/3600.0;
  dayFrac = xhours/24.0;
  sscanf(UTDBuffer,"%4d-%2d-%2d", &year, &month, &day);
  latRad = ObsSettings->latitude * 2.0*PI/360.0;

  /* Compute geocentric Julian Day */

  *JD = JulDay(day, dayFrac, month, year);
  
  /* Compute local sidereal time */

  lst = LocalSiderealTime(*JD, ObsSettings->longitude);

  /* Compute hour angle */

  haHours = lst - raHours;
  haRad = haHours * 2.0*PI/24.0;

  /* Compute air mass */

  *AirMass = 1.0/(sin(latRad)*sin(decRad)+cos(latRad)*cos(decRad)*cos(haRad));

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
  UT = (JD - JD0 - 0.5) * 24.0;
  T = (JD0 - 2451544.5)/36525.0;
  GMST = 6.697374558 + 1.0027379093*UT +
         (8640184.812866+(0.093104-6.2e-6*T)*T)*T/3600.0;
  LMST = GMST - longitude/15.0;
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
  S = 1.675104E-2 - 4.18E-5*T - 1.26E-7*T2;
  MA = RRad*MS;
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
  *RSN = 1.0000002*(1.-S*cos(EA))+DR;
  while (LSN < 0.0) {
    LSN += RPi2;
  }
  while (LSN > RPi2) {
    LSN -= RPi2;
  }
  *SunLong = LSN;
}


void Anomaly(float MA, float S, float *NU, float *EA)
{
  /* Given the mean anomaly (MA) and the eccentricity (S <1),
     this routine computes the true anomaly (NU) and
     the eccentric anomaly (EA).  All angles in RADIANS */

  double APi2, RM, DLA, TNU2;

  APi2 = 6.283185308;
  RM = MA - APi2 * floor(MA/APi2);
  *EA = RM;

  do {
    DLA = *EA - (S*sin(*EA))-RM;
    if (fabs(DLA) < 1.0e-6)
      break;
    DLA = DLA/(1.-(S*cos(*EA)));
    *EA -= DLA;
  } while (TRUE);

  TNU2 = sqrt( (1.+S)/(1.-S))*tan(*EA/2.);
  *NU = 2.*atan(TNU2);
}


void ShowImageProgress(char *Label, int percent)
{
  static GtkWidget *bar, *label;
  static int Shown=FALSE;

  if (DontShowImageProgress)
    return;

  if (ProgressDialog == NULL) {
    ProgressDialog = create_ProgressDialog();
    bar = lookup_widget(ProgressDialog, "ProgressDialogBar");
    label = lookup_widget(ProgressDialog, "ProgressDialogLabel");
  }
  gtk_widget_show(ProgressDialog);
  Shown = TRUE;

  if (Label == NULL) {
    gtk_widget_hide(ProgressDialog);
  } else {
    if (percent == 0) {
      gtk_label_set_text(GTK_LABEL(label), Label);
      gtk_progress_set_percentage(GTK_PROGRESS(bar), ((gfloat)percent)/100.0);
    } else {
      gtk_progress_set_percentage(GTK_PROGRESS(bar), ((gfloat)percent)/100.0);
    }
  }
}


void ShowGuidingProgress(char *Label, int percent)
{
  static GtkWidget *bar, *label;
  static int Shown=FALSE;

  if (DontShowGuidingProgress)
    return;

  if (GuidingProgressDialog == NULL) {
    GuidingProgressDialog = create_GuidingProgressDialog();
    bar = lookup_widget(GuidingProgressDialog, "GuidingProgressDialogBar");
    label = lookup_widget(GuidingProgressDialog, "GuidingProgressDialogLabel");
  }
  gtk_widget_show(GuidingProgressDialog);
  Shown = TRUE;

  if (Label == NULL) {
    gtk_widget_hide(GuidingProgressDialog);
  } else {
    if (percent == 0) {
      gtk_label_set_text(GTK_LABEL(label), Label);
      gtk_progress_set_percentage(GTK_PROGRESS(bar), ((gfloat)percent)/100.0);
    } else {
      gtk_progress_set_percentage(GTK_PROGRESS(bar), ((gfloat)percent)/100.0);
    }
  }
}


void RunMainIteration(float seconds)
{
  int runMainIterationTimer;
  guint timerID;

  runMainIterationTimer = (int) rint(seconds * 100.0);

  timerID = gtk_timeout_add(10, decrementRunMainIterationTimer,
			    &runMainIterationTimer);

  do {
    gtk_main_iteration_do(FALSE);
  } while (runMainIterationTimer > 0);

  gtk_timeout_remove(timerID);

  return;

}

int decrementRunMainIterationTimer(gpointer data)
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



void MsgQueueFlush(int queueID)
{
  size_t msgsiz;
  int msgflg, istat;
  long msgtyp, sleepTime;
  struct msgbuf {
    long mtype;
    char mtext[MESSAGE_SIZE];
  } msg;
  key_t key;

  msgtyp = MTYPE_FROM_SCOPE;
  msgsiz = MESSAGE_SIZE;
  key = MESSAGE_QUEUE_KEY;
  msgflg = IPC_NOWAIT;

  sleepTime = 0;
  do {
    istat = msgrcv(queueID, &msg, msgsiz, msgtyp, msgflg);
  } while (istat >= 0);

  return;
}


int GetScopePosition(double *ScopeRA, double *ScopeDEC)
{
  char buffer[160];
  size_t msgsiz;
  long msgtyp, sleepTime;
  int msgflg, istat, hours, mins, secs, degs;
  struct msgbuf {
    long mtype;
    char mtext[MESSAGE_SIZE];
  } msg;
  key_t key;
  
  /* Get TCS200 message queue if not already done */
  
  if (queueID < 0) {
    key = MESSAGE_QUEUE_KEY;
    msgflg = 0;
    queueID = msgget(key, msgflg);
    if (queueID < 0) {
      StatusPrint("*** WARNING - Can't get ID for message queue to TCS200\n");
      return FALSE;
    } else {
      sprintf(buffer, "*** INFO - Got TCS200 message queue: %d\n", queueID);
      StatusPrint(buffer);
    }
  }

  /* Send TCS200 message to send back ra */

  strcpy(msg.mtext, ":GR#");
  msg.mtype = MTYPE_TO_SCOPE;
  msgsiz = strlen(msg.mtext) + 1;
  msgflg = IPC_NOWAIT;
  istat = msgsnd(queueID, &msg, msgsiz, msgflg);
  if (istat < 0) {
    StatusPrint("*** WARNING - Can't sent message to TCS200\n");
  } else {
    sprintf(buffer, "*** INFO - Sent message to TCS200: %s\n", msg.mtext);
    StatusPrint(buffer);
  }

  // Get ra reply

  msgtyp = MTYPE_FROM_SCOPE;
  msgsiz = MESSAGE_SIZE;
  msgflg = IPC_NOWAIT;
  sleepTime = 0;
  do {
    istat = msgrcv(queueID, &msg, msgsiz, msgtyp, msgflg);
    if (istat >= 0) {
      sscanf(msg.mtext,"%02d:%02d:%02d#", &hours, &mins, &secs);
      if ((hours < 0) || (hours >= 24) || (mins < 0) || (mins >= 60) ||
	  (secs < 0) || (secs >= 60)) {
	sprintf(buffer,"*** Warning - Bad coords from scope: %s\n", msg.mtext);
	StatusPrint(buffer);
	usleep(2000000);
	MsgQueueFlush(queueID);
	return FALSE;
      } else {
	*ScopeRA = hours + ((float) mins)/60.0 + ((float) secs)/3600.0;
	sprintf(buffer,"*** Info - Current scope RA: %8.4lf\n", *ScopeRA);
	StatusPrint(buffer);
	break;
      }
    }
    usleep(100000);
    sleepTime += 100000;
  } while (sleepTime < 2000000);

  if (sleepTime >= 2000000) {
    StatusPrint("*** Warning - Timed out getting scope RA position.\n");
    return FALSE;
  }

  /* Send TCS200 message to send back dec */

  strcpy(msg.mtext, ":GD#");
  msg.mtype = MTYPE_TO_SCOPE;
  msgsiz = strlen(msg.mtext) + 1;
  msgflg = IPC_NOWAIT;
  istat = msgsnd(queueID, &msg, msgsiz, msgflg);
  if (istat < 0) {
    StatusPrint("*** WARNING - Can't sent message to TCS200\n");
  } else {
    sprintf(buffer, "*** INFO - Sent message to TCS200: %s\n", msg.mtext);
    StatusPrint(buffer);
  }

  // Get dec reply

  msgtyp = MTYPE_FROM_SCOPE;
  msgsiz = MESSAGE_SIZE;
  msgflg = IPC_NOWAIT;
  sleepTime = 0;
  do {
    istat = msgrcv(queueID, &msg, msgsiz, msgtyp, msgflg);
    if (istat >= 0) {
      sscanf(msg.mtext,"%03d:%02d:%02d#", &degs, &mins, &secs);
      if ((degs <= -90) || (degs >= 90) || (mins < 0) || (mins >= 60) ||
	  (secs < 0) || (secs >= 60)) {
	sprintf(buffer,"*** Warning - Bad coords from scope: %s\n", msg.mtext);
	StatusPrint(buffer);
	usleep(2000000);
	MsgQueueFlush(queueID);
	return FALSE;
      } else {
	*ScopeDEC = degs + ((float) mins)/60.0 + ((float) secs)/3600.0;
	sprintf(buffer,"*** Info - Current scope DEC: %8.4lf\n", *ScopeDEC);
	StatusPrint(buffer);
	break;
      }
    }
    usleep(100000);
    sleepTime += 100000;
  } while (sleepTime < 2000000);

  if (sleepTime >= 2000000) {
    StatusPrint("*** Warning - Timed out getting scope DEC position.\n");
    return FALSE;
  }

  return TRUE;
}  

GList *MakeObjectNameList(void)
{
  GList *items=NULL;
  OBJNODE *optr;

  optr = ObjectListHead;
  while (optr != NULL) {
    items = g_list_append(items, optr->obj.name);
    optr = optr->next;
  }
  return items;
}


int updateStatusInfo(gpointer data)
{
  MY_LOGICAL enabled;
  char Message[80];
  int status, success;
  double ccd_temp, air_temp, setpointTemp, percentTE;
  GtkWidget *Entry;
  int cooler_status;

  /* Don't update if exposure, download or getting ccd status in progress */

  if (DontUpdate) return TRUE;

  if (ccd->Linked) {

    /* Show current status of ccd */

    Entry = lookup_widget(CCDAutoSave, "MainCCDStatusEntry");
    gtk_entry_set_text(GTK_ENTRY(Entry), "Linked");

       /* Get temperature status of ccd */

    switch (ccd->make) {
    case SBIG_MAKE:
      success = pCam_QueryTemperatureStatus(&enabled, &ccd_temp, &air_temp,
					    &setpointTemp, &percentTE);
      if (! success) {
	StatusPrint("*** WARNING - Can't get ccd temperature status...\n");
	sleep(1);
	success = pCam_QueryTemperatureStatus(&enabled, &ccd_temp, &air_temp,
					     &setpointTemp, &percentTE);
	if (! success) {
	  StatusPrint("*** WARNING - Can't get ccd temperature status...\n");
	  return TRUE;
	}
      }
      Entry = lookup_widget(CCDAutoSave, "MainCCDTempEntry");
      sprintf(Message, "%4.1f C (%4.1f)", ccd_temp, setpointTemp);
      gtk_entry_set_text(GTK_ENTRY(Entry), Message);
      Entry = lookup_widget(CCDAutoSave, "MainCoolingEntry");
      sprintf(Message, "%5.1f %%", ((float) (percentTE*100.0)));
      gtk_entry_set_text(GTK_ENTRY(Entry), Message);
      break;
    case APOGEE_MAKE:
      success = apCam_QueryTemperatureStatus(&ccd_temp, &setpointTemp,
					     &cooler_status);
      if (! success) {
	StatusPrint("*** WARNING - Can't get ccd temperature status...\n");
	return TRUE;
      }
      Entry = lookup_widget(CCDAutoSave, "MainCCDTempEntry");
      sprintf(Message, "%4.1f C (%4.1f)", ccd_temp, setpointTemp);
      gtk_entry_set_text(GTK_ENTRY(Entry), Message);
      Entry = lookup_widget(CCDAutoSave, "MainCoolingEntry");
      switch (cooler_status) {
      case Camera_CoolerStatus_Off:
	strcpy(Message,"Off");
	break;
      case Camera_CoolerStatus_RampingToSetPoint:
	strcpy(Message,"RampDown");
	break;
      case Camera_CoolerStatus_Correcting:
	strcpy(Message,"Correcting");
	break;
      case Camera_CoolerStatus_RampingToAmbient:
	strcpy(Message,"RampUp");
	break;
      case Camera_CoolerStatus_AtAmbient:
	strcpy(Message,"AtAmbient");
	break;
      case Camera_CoolerStatus_AtMax:
	strcpy(Message,"AtMax");
	break;
      case Camera_CoolerStatus_AtMin:
	strcpy(Message,"AtMin");
	break;
      case Camera_CoolerStatus_AtSetPoint:
	strcpy(Message,"AtSetPoint");
	break;
      }
      gtk_entry_set_text(GTK_ENTRY(Entry), Message);
      break;
    case SXPRESS_MAKE:
      break;
    }

    Entry = lookup_widget(CCDAutoSave, "MainFilterEntry");
    sprintf(Message, "%c", filterSet[ccd->filterPosition-1]);
    gtk_entry_set_text(GTK_ENTRY(Entry), Message);

  } else {   /* Not Linked */
    Entry = lookup_widget(CCDAutoSave, "MainCCDStatusEntry");
    gtk_entry_set_text(GTK_ENTRY(Entry), "UnLinked");
  }

  /* If Image active, show its status */

  if (ccd->Image.light_frame.active) {
    Entry = lookup_widget(CCDAutoSave, "MainSingleStatusEntry");
    gtk_entry_set_text(GTK_ENTRY(Entry), "Active");
    Entry = lookup_widget(CCDAutoSave, "MainExposureEntry");
    sprintf(Message,"%6.2f", ccd->Image.light_frame.exposure);
    gtk_entry_set_text(GTK_ENTRY(Entry), Message);
    Entry = lookup_widget(CCDAutoSave, "MainWhichCCDEntry");
    if (ccd->Image.light_frame.whichCCD == 0) {
      gtk_entry_set_text(GTK_ENTRY(Entry), "Imaging");
    } else {
      gtk_entry_set_text(GTK_ENTRY(Entry), "Tracking");
    }
    Entry = lookup_widget(CCDAutoSave, "MainBinningEntry");
    if (ccd->Image.light_frame.binning == 0) {
      gtk_entry_set_text(GTK_ENTRY(Entry), "1x1");
    } else if (singleSettings.binning == 1) {
      gtk_entry_set_text(GTK_ENTRY(Entry), "2x2");
    } else {
      gtk_entry_set_text(GTK_ENTRY(Entry), "3x3");
    }
    Entry = lookup_widget(CCDAutoSave, "MainFrameSizeEntry");
    sprintf(Message,"%d, %d, %d, %d", ccd->Image.light_frame.x, ccd->Image.light_frame.y,
	    ccd->Image.light_frame.h, ccd->Image.light_frame.w);
    gtk_entry_set_text(GTK_ENTRY(Entry), Message);
    Entry = lookup_widget(CCDAutoSave, "MainFileNameEntry");
    gtk_entry_set_text(GTK_ENTRY(Entry), ccd->Image.FileName);
    Entry = lookup_widget(CCDAutoSave, "MainObjectNameEntry");
    gtk_entry_set_text(GTK_ENTRY(Entry), ccd->Image.ObjectName);
  } else {
    Entry = lookup_widget(CCDAutoSave, "MainSingleStatusEntry");
    gtk_entry_set_text(GTK_ENTRY(Entry), "Not Active");
    Entry = lookup_widget(CCDAutoSave, "MainExposureEntry");
    sprintf(Message,"%6.2f", singleSettings.exposureTime);
    gtk_entry_set_text(GTK_ENTRY(Entry), Message);
    Entry = lookup_widget(CCDAutoSave, "MainWhichCCDEntry");
    if (singleSettings.whichCCD == 0) {
      gtk_entry_set_text(GTK_ENTRY(Entry), "Imaging");
    } else {
      gtk_entry_set_text(GTK_ENTRY(Entry), "Tracking");
    }
    Entry = lookup_widget(CCDAutoSave, "MainBinningEntry");
    if (singleSettings.binning == 0) {
      gtk_entry_set_text(GTK_ENTRY(Entry), "1x1");
    } else if (singleSettings.binning == 1) {
      gtk_entry_set_text(GTK_ENTRY(Entry), "2x2");
    } else {
      gtk_entry_set_text(GTK_ENTRY(Entry), "3x3");
    }
    Entry = lookup_widget(CCDAutoSave, "MainFrameSizeEntry");
    sprintf(Message,"%d, %d, %d, %d", singleSettings.x, singleSettings.y,
	    singleSettings.h, singleSettings.w);
    gtk_entry_set_text(GTK_ENTRY(Entry), Message);
    Entry = lookup_widget(CCDAutoSave, "MainObjectNameEntry");
    gtk_entry_set_text(GTK_ENTRY(Entry), singleSettings.ObjectName);
    Entry = lookup_widget(CCDAutoSave, "MainImageDirEntry");
    gtk_entry_set_text(GTK_ENTRY(Entry), singleSettings.ImageDir);
  }

  if (SeriesStarted) {
    if (PauseSeries) {
      Entry = lookup_widget(CCDAutoSave, "MainSeriesStatusEntry");
      gtk_entry_set_text(GTK_ENTRY(Entry), "Paused");
    } else {
      Entry = lookup_widget(CCDAutoSave, "MainSeriesStatusEntry");
      gtk_entry_set_text(GTK_ENTRY(Entry), "Running");
    }
  } else {
    Entry = lookup_widget(CCDAutoSave, "MainSeriesStatusEntry");
    gtk_entry_set_text(GTK_ENTRY(Entry), "Not Active");
  }

  return TRUE;
}


void UpdateDarkFrameSettings(void)
{
  gchar *buffer;
  GtkWidget *Entry;

  /* Get parms not already gotten */

  Entry = lookup_widget(DarkFrameSettingsDialog,
			       "DarkFrameSettingsFrameSizeEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%d, %d, %d, %d", &darkFrameSettings.x, &darkFrameSettings.y,
	 &darkFrameSettings.h, &darkFrameSettings.w);

  Entry = lookup_widget(DarkFrameSettingsDialog,
			"DarkFrameSettingsNumFramesEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%d", &darkFrameSettings.numFrames);

  Entry = lookup_widget(DarkFrameSettingsDialog,
			"DarkFrameSettingsExpTimeEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%f", &darkFrameSettings.exposureTime);

  Entry = lookup_widget(DarkFrameSettingsDialog,
			       "DarkFrameSettingsImageDirEntry");
  strcpy(darkFrameSettings.imageDir,gtk_entry_get_text(GTK_ENTRY(Entry)));

  updateStatusInfo(dummy);
}


void UpdateFlatFrameSettings(void)
{
  int i;
  char name[80], Message[80], *darkOption;
  gchar *buffer;
  GtkWidget *Entry, *filterButton;

  /* Get parms not already gotten */

  /* Get dark frame option */

  Entry = lookup_widget(FlatFrameSettingsDialog,
			     "FlatFrameSettingsDarkComboEntry");
  darkOption = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  if (strcmp(darkOption,"Reuse old dark frame") == 0) {
    flatFrameSettings.darkOption = 1;
  } else if (strcmp(darkOption,"Force new dark frame") == 0) {
    flatFrameSettings.darkOption = 2;
  } else if (strcmp(darkOption,"Use dark frame from file") == 0) {
    flatFrameSettings.darkOption = 3;
  } else if (strcmp(darkOption,"Don't do dark subtract") == 0) {
    flatFrameSettings.darkOption = 4;
  } else {
    sprintf(Message,
	    "*** Internal error - bad dark option: %s (FlatFrameSettings\n)",
	    darkOption);
    StatusPrint(Message);
  }

  /* Get filter sequence values */

  for (i=0; i<NUMFILTERS; i++) {
    sprintf(name,"FlatFrameSettings%cButton", filterSet[i]);
    filterButton = lookup_widget(FlatFrameSettingsDialog, name);
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(filterButton))) {
      flatFrameSettings.filterSeq.Use[i] = TRUE;
      sprintf(name,"FlatFrameSettings%cExpEntry", filterSet[i]);
      Entry = lookup_widget(FlatFrameSettingsDialog, name);
      buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
      sscanf(buffer, "%f", &flatFrameSettings.filterSeq.exposures[i]);
    }
  }

  Entry = lookup_widget(FlatFrameSettingsDialog,
			       "FlatFrameSettingsFrameSizeEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%d, %d, %d, %d", &flatFrameSettings.x,
	 &flatFrameSettings.y, &flatFrameSettings.h, &flatFrameSettings.w);

  Entry = lookup_widget(FlatFrameSettingsDialog,
			"FlatFrameSettingsNumFramesEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%d", &flatFrameSettings.numFrames);

  Entry = lookup_widget(FlatFrameSettingsDialog,
			       "FlatFrameSettingsImageDirEntry");
  strcpy(flatFrameSettings.imageDir,gtk_entry_get_text(GTK_ENTRY(Entry)));

  updateStatusInfo(dummy);
}


void UpdateStackSettings(void)
{
  gchar *buffer;
  GtkWidget *Entry;

  /* Get parms not already gotten */

  Entry = lookup_widget(StackSettingsDialog,
			       "StackSettingsFrameSizeEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%d, %d, %d, %d", &stackSettings.x, &stackSettings.y,
	 &stackSettings.h, &stackSettings.w);

  Entry = lookup_widget(StackSettingsDialog,
			"StackSettingsNumFramesEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%d", &stackSettings.numFrames);

  Entry = lookup_widget(StackSettingsDialog,
			"StackSettingsExpTimeEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%f", &stackSettings.exposureTime);

  Entry = lookup_widget(StackSettingsDialog,
			       "StackSettingsImageDirEntry");
  strcpy(stackSettings.imageDir,gtk_entry_get_text(GTK_ENTRY(Entry)));

  updateStatusInfo(dummy);
}


int setAlignStar(FRAME *frame, float *starX, float *starY)
{
  GtkWidget *Entry;
  char *bufptr;

  if (PickAlignStarDialog == NULL) {
    PickAlignStarDialog = create_PickAlignStarDialog();
  }

  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarXEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry), "-999");
  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarYEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry), "-999");
  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarMaxEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry), "-999");

  CancelSetAlignStar = FALSE;
  AlignStarFound = FALSE;
  gtk_widget_show(PickAlignStarDialog);

  do {
    gtk_main_iteration_do(FALSE);
  } while ((! AlignStarFound) && (! CancelSetAlignStar));

  if (CancelSetAlignStar) {
    return FALSE;
  }
  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarXEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bufptr,"%f", starX);
  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarYEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bufptr,"%f", starY);

  return TRUE;
}

int findAlignStar(FRAME *frame, float starX, float starY,
		  int *offsetX, int *offsetY)
{
  int Found;
  int xmin, xmax, ymin, ymax, max;
  float x, y;

  /* Define search region */

  xmin = (int) rint(starX - 10);
  if (xmin < 0) 
    xmin = 0;
  xmax = (int) rint(starX + 10);
  if (xmax > frame->w)
    xmax = frame->w;
  ymin = (int) rint(starY - 10);
  if (ymin < 0)
    ymin = 0;
  ymax = (int) rint(starY + 10);
  if (ymax > frame->h)
    ymax = frame->h;

  /* search for star in this region */

  Found = FindStar(frame, xmin, ymin, xmax, ymax, &x, &y, &max);
  if (Found) {
    *offsetX = (int) rint(x - starX);
    *offsetY = (int) rint(y - starY);
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
      r = (x-xAtMax)*(x-xAtMax);
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
	r = (x-xAtMax)*(x-xAtMax) + (y-yAtMax)*(y-yAtMax);
	if (r > 0.0) r = sqrt(r);
	putpix(val, x, y, r, &PixList);
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

void MarkStar(GtkWidget *drawingArea, float starx, float stary)
{
  GdkColor color, save_color;
  GdkGCValues values;
  int x1, y1, x2, y2;

  color.pixel = 10000;
  color.red = 5000;
  color.blue = 0;
  color.green = 0;
  x1 = (int) rint(starx - 5.0);
  y1 = (int) rint(stary - 5.0);
  x2 = (int) rint(starx + 5.0);
  y2 = (int) rint(stary + 5.0);
  gdk_gc_get_values(drawingArea->style->fg_gc[GTK_STATE_NORMAL], &values);
  memcpy(&save_color, &values.foreground, sizeof(GdkColor));
  
  gdk_gc_set_foreground(drawingArea->style->fg_gc[GTK_STATE_NORMAL],&color);
  gdk_draw_line(drawingArea->window,
		drawingArea->style->fg_gc[GTK_STATE_NORMAL],
		(int) starx, y1, (int) starx, y2);
  gdk_draw_line(drawingArea->window,
		drawingArea->style->fg_gc[GTK_STATE_NORMAL],
		x1, (int) stary, x2, (int) stary);
  gdk_gc_set_foreground(drawingArea->style->fg_gc[GTK_STATE_NORMAL],
			&save_color);

  return;
}

void CircleStar(GtkWidget *drawingArea, float starx, float stary)
{
  GdkColor color, save_color;
  GdkGCValues values;
  int x1, y1;

  color.pixel = 10000;
  color.red = 5000;
  color.blue = 0;
  color.green = 0;
  gdk_gc_get_values(drawingArea->style->fg_gc[GTK_STATE_NORMAL], &values);
  memcpy(&save_color, &values.foreground, sizeof(GdkColor));
  gdk_gc_set_foreground(drawingArea->style->fg_gc[GTK_STATE_NORMAL],&color);
  x1 = (int) rint(starx - photometrySettings.aperatureRadius);
  y1 = (int) rint(stary - photometrySettings.aperatureRadius);
  gdk_draw_arc(drawingArea->window,
	       drawingArea->style->fg_gc[GTK_STATE_NORMAL],
	       FALSE, x1, y1, ((gint) photometrySettings.aperatureRadius)*2,
	       ((gint) photometrySettings.aperatureRadius)*2, 0, 24386);
  //  gdk_gc_set_foreground(widget->style->fg_gc[GTK_STATE_NORMAL],&color);
  x1 = (int) rint(starx - photometrySettings.skyInnerRadius);
  y1 = (int) rint(stary - photometrySettings.skyInnerRadius);
  gdk_draw_arc(drawingArea->window,
	       drawingArea->style->fg_gc[GTK_STATE_NORMAL],
	       FALSE, x1, y1, ((gint) photometrySettings.skyInnerRadius)*2,
	       ((gint) photometrySettings.skyInnerRadius)*2, 0, 24386);
  x1 = (int) rint(starx - photometrySettings.skyOuterRadius);
  y1 = (int) rint(stary - photometrySettings.skyOuterRadius);
  gdk_draw_arc(drawingArea->window,
	       drawingArea->style->fg_gc[GTK_STATE_NORMAL],
	       FALSE, x1, y1, ((gint) photometrySettings.skyOuterRadius)*2,
	       ((gint) photometrySettings.skyOuterRadius)*2, 0, 24386);
  gdk_gc_set_foreground(drawingArea->style->fg_gc[GTK_STATE_NORMAL],
			&save_color);

  return;
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
  GtkWidget *widget;
  guchar *dp;
  char *bufptr;
  unsigned short *sp;
  int background, range, d, i, j, npixels, h, w;
  int x, y, fullh, fullw;
  float gamma;
  double f;

  fullh = RGBw;
  fullw = RGBh;
  h = ccd->Image.light_frame.h;
  w = ccd->Image.light_frame.w;
  x = ccd->Image.light_frame.x;
  y = ccd->Image.light_frame.y;

  npixels = fullh * fullw;
  widget = lookup_widget(CurrentImageWindow,"CurrentImageBackEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%d", &background);

  widget = lookup_widget(CurrentImageWindow,"CurrentImageRangeEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%d", &range);

  widget = lookup_widget(CurrentImageWindow,"CurrentImageGammaEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &gamma);
  if ((gamma < 0.01) || (gamma > 3.0)) {
    StatusPrint("*** Warning - Gamma out of range (0.01:3.0), "
		"using default of 0.33\n");
    gamma = 0.33;
  }

  sp = ccd->Image.light_frame.frame;
  dp = RGBBuf;
  if (background == range)
    background--;

  for (j = 0; j < h; ++j) {
    for (i = 0; i < w; ++i) {
      //      if ((j >= y) && (j < y+h) && (i >= x) && (i < x+w)) {
	f = ((double)*sp++ - background)/(range);
	if (f < 0.0) f=0.0;
	d = (int)(255.0*pow(f, gamma));	/* gamma correct */
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
/*       } else { */
/* 	dp[RED] = 0; */
/* 	dp[GREEN] = 0; */
/* 	dp[BLUE] = 0; */
/*       } */
      dp += 3;
    }
  }

  widget = lookup_widget(CurrentImageWindow,"CurrentImageDrawingArea");
  gtk_drawing_area_size(GTK_DRAWING_AREA(widget), w, h);
  gtk_widget_show(CurrentImageWindow);
}


void UpdateGuideImage(void)
{
  GtkWidget *widget;
  guchar *dp;
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
  sscanf(bufptr, "%d", &background);
  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowRangeEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%d", &range);
  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowGammaEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &gamma);
  if ((gamma < 0.01) || (gamma > 3.0)) {
    StatusPrint("*** Warning - Gamma out of range (0.01:3.0), "
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
	d = (int)(255.0*pow(f, gamma));	/* gamma correct */
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
  gtk_widget_show(GuideFrameWindow);

  return;
}


void removeHotPixels(FRAME *light)
{
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
      pixval = (int) rint(globalAvep);
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
      avep = nearpix[numpix/2];
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
  printf("\nReplaced %d hot pixels...", numReplaced);

  return;
}
