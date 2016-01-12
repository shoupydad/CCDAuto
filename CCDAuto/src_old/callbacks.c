#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "truefalse.h"
#include <gnome.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <math.h>
#include <X11/Xlib.h>
#include <Imlib.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
//#include <linux/unistd.h>
//#include <linux/dirent.h>
#include <cpgplot.h>
#include <queue.h>
#include "cfortran.h"
#include "hbook.h"
#include "minuit.h"
#include "temp_tables.h"
#include "doRoutines.h"

/* Defines */

#define MAXNUMDARKS 20
#define MAXNUMFLATS 20
#define NOANSWER 0
#define YESNO 1
#define CANCEL 2
#define YES 3
#define NO 4
#define OKAY 5
#define OK 6

/* Externs */

extern GtkWidget *CCDAutoSave;
extern OBJNODE *ObjectListHead;
extern char objectListFileName[160];
extern  char filterSet[NUMFILTERS];
extern int DontShowImageProgress;
extern int DontShowGuidingProgress;

/* globals */

guchar *RGBBuf=NULL;
int RGBw=0;
int RGBh=0;
guchar *RGBGuideBuf=NULL;
int RGBGuidew=0;
int RGBGuideh=0;
CCD ImagingCCD;
CCD SpectroCCD;
CCD *ccd=&ImagingCCD;
CCDSETTINGS ccdSettings;
IMAGE guideImage;
GtkWidget *queryr_dialog=NULL;
int MessageBoxAnswer = NOANSWER;
void (*queryr_dialog_ok_function)(CCD *ccd, int *status);
float queryr_dialog_answer;
gpointer dummy;
char CurrentImageFileName[160];
GtkWidget *singleSettings_dialog=NULL;
GtkWidget singleSettings_dialog_save;
GtkWidget *seriesSettings_dialog=NULL;
GtkWidget seriesSettings_dialog_save;
GtkWidget *ObjectListDialog=NULL;
GtkWidget *DownLoadingDialog=NULL;
GtkWidget *SaveCurrentImageDialog=NULL;
GtkWidget *DarkFrameSettingsDialog=NULL;
GtkWidget *FlatFrameSettingsDialog=NULL;
GtkWidget *StackSettingsDialog=NULL;
GtkWidget *OpenFileDialog=NULL;
GtkWidget *ObsSettingsDialog=NULL;
GtkWidget *OverWriteDialog=NULL;
GtkWidget *PickAlignStarDialog=NULL;
GtkWidget *CurrentImageWindow=NULL;
GtkWidget *GuideFrameWindow=NULL;
GtkWidget *YesNoDialog=NULL;
GtkWidget *OkayDialog=NULL;
GtkWidget *ProgressDialog=NULL;
GtkWidget *GuidingProgressDialog=NULL;
GtkWidget *PhotometrySettingsDialog=NULL;
GtkWidget *DefineListDialog=NULL;
GtkWidget *GuidingSlitSettingsDialog=NULL;
GtkWidget *CameraSettingsDialog=NULL;

int DownLoadCancel=false;
int ObjectListEditable=false;
int CancelSetAlignStar;
int CancelCurrentAcquire=false;
int CancelCurrentGuidingAcquire=false;
int AlignStarFound;
int ImagingDownloadInProgress=false;
int queueID = -1;
double ScopeRA=0.0;
double ScopeDEC=0.0;
int GetScopeRADEC=true;

SINGLESETTINGS singleSettings;
SINGLESETTINGS singleSettings_Save;
SINGLESETTINGS guideImageSettings;
SINGLESETTINGS guideImageSettings_Save;
SERIESSETTINGS seriesSettings;
SERIESSETTINGS seriesSettings_Save;
DARKFRAMESETTINGS darkFrameSettings;
DARKFRAMESETTINGS darkFrameSettings_Save;
FLATFRAMESETTINGS flatFrameSettings;
FLATFRAMESETTINGS flatFrameSettings_Save;
STACKSETTINGS stackSettings;
STACKSETTINGS stackSettings_Save;
OBSSETTINGS ObsSettings;
OBSSETTINGS ObsSettings_Save;
GUIDINGSLITSETTINGS GuidingSlitSettings;
GUIDINGSLITSETTINGS GuidingSlitSettings_save;
PHOTOMETRYSETTINGS photometrySettings;
PLATESOLU plateSolution;
PLATESOLU plateSolution_save;
PLATESTARS plateStars;

int UserStopBatch=false;
int DontUpdate=false;
int StartSeriesASAP=false;
int PauseSeries=false;
int StopSeries=false;
int SeriesStarted=false;
char binningString[3][4]={"1x1","2x2","3x3"};

int SingleSaveEachDarkFrame=false;
int SeriesSaveEachDarkFrame=false;
int FlatSaveEachDarkFrame=false;
int DarkSaveEachDarkFrame=false;
int SaveEachFlatFrame=false;
int StackSaveEachDarkFrame=false;
int StackSaveEachLightFrame=false;
FLATNODE *FlatFrameHead=NULL;
STAR *CurrentStarList=NULL;
STAR *CurrentStarListSave=NULL;
STAR *baseStarList=NULL;
int CurrentStarListDefined=false;
int DoingAstrometry=false;


int MessageBox(char *prompt, int buttons)
{
  GtkWidget *DlgPtr, *label;

  DlgPtr = NULL;
  switch (buttons) {
     case YESNO:
       if (YesNoDialog == NULL) {
	 YesNoDialog = create_YesNoDialog();
       }
       label = lookup_widget(YesNoDialog,"YesNoDialogQuestion");
       gtk_label_set_text(GTK_LABEL(label),prompt);
       gtk_widget_show(YesNoDialog);
       DlgPtr = YesNoDialog;
       break;
     case OKAY:
       if (OkayDialog == NULL) {
	 OkayDialog = create_OkayDialog();
       }
       label = lookup_widget(OkayDialog,"OkayDialogQuestion");
       gtk_label_set_text(GTK_LABEL(label),prompt);
       gtk_widget_show(OkayDialog);
       DlgPtr = OkayDialog;
       break;
  }

  MessageBoxAnswer = NOANSWER;
  do {
    gtk_main_iteration_do(false);
  } while (MessageBoxAnswer == NOANSWER);

  if (DlgPtr != NULL) 
    gtk_widget_hide(DlgPtr);

  return MessageBoxAnswer;
}

/*****************************************************************/

void on_open1_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  if (OpenFileDialog == NULL) {
    OpenFileDialog = create_OpenFileDialog();
  }
  gtk_widget_show(OpenFileDialog);

}

/*****************************************************************/

void on_save1_activate (GtkMenuItem *menuitem, gpointer user_data)
{
  if (strlen(ccd->Image.FileName) == 0) {
    if (SaveCurrentImageDialog == NULL) {
      SaveCurrentImageDialog = create_SaveCurrentImageDialog();
    }
    gtk_widget_show(SaveCurrentImageDialog);
  } else {
    unlink(ccd->Image.FileName);
    writeFITS(&ccd->Image, 1, ccd->Image.FileName, ccd->Image.ObjectName);
  }    
}

void on_SaveCurrentImageOkButton_clicked(GtkButton *button,
					 gpointer user_data)
{
  char *bptr, prompt[80];
  FILE *fptr;
  GtkWidget *widget;

  bptr = (char *) gtk_file_selection_get_filename(
		       GTK_FILE_SELECTION(SaveCurrentImageDialog));
  fptr = fopen(bptr,"rb");
  if (fptr != NULL) {
    fclose(fptr);
    if (OverWriteDialog == NULL) {
      OverWriteDialog = create_OverWriteDialog();
    }
    widget = lookup_widget(OverWriteDialog,"OverWritePrompt");
    sprintf(prompt,"File %s exists, overwrite?", bptr);
    gtk_label_set_text(GTK_LABEL(widget),prompt);
    gtk_widget_show(OverWriteDialog);
  } else {
    writeFITS(&ccd->Image, 1, bptr, singleSettings.ObjectName);
  }
  gtk_widget_hide(SaveCurrentImageDialog);
  updateStatusInfo(dummy);
}


void on_SaveCurrentImageCancelButton_clicked(GtkButton *button,
					     gpointer user_data)
{
  gtk_widget_hide(SaveCurrentImageDialog);
}


/*****************************************************************/

void on_save_as1_activate(GtkMenuItem *menuitem, gpointer  user_data)
{
  if (SaveCurrentImageDialog == NULL) {
    SaveCurrentImageDialog = create_SaveCurrentImageDialog();
  }
  gtk_widget_show(SaveCurrentImageDialog);
}

/*****************************************************************/

void on_exit1_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  GtkWidget *UnlinkCameraQu, *ExitSaveImageQu;

  /* If image active and not saved, ask if save wanted */

  if (ccd->Image.light_frame.active && (! ccd->Image.saved)) {
    ExitSaveImageQu = create_ExitSaveImageQu();
    gtk_widget_show(ExitSaveImageQu);
    return;
  }

  /* If camera linked, ask if unlink wanted */

  if (ccd->Linked) {
    UnlinkCameraQu = create_UnlinkCameraQu();
    gtk_widget_show(UnlinkCameraQu);
    return;
  }
  gtk_exit(0);
}

/*****************************************************************/

void on_u1_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  int status;

  if (ccd->filterPosition == 1) return;
  if (!ccd->Linked) {
    StatusPrint("*** WARNING - Can't move filter wheel to U position,"
		" link to ccd first...\n");
    return;
  }
  doFilterWheel(ccd, &status, 1);
}

/*****************************************************************/

void on_b1_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  int status;

  if (ccd->filterPosition == 2) return;
  if (!ccd->Linked) {
    StatusPrint("*** WARNING - Can't move filter wheel to B position,"
		" link to ccd first...\n");
    return;
  }
  doFilterWheel(ccd, &status, 2);

}

/*****************************************************************/

void on_v1_activate (GtkMenuItem *menuitem, gpointer user_data)
{
  int status;

  if (ccd->filterPosition == 3) return;
  if (!ccd->Linked) {
    StatusPrint("*** WARNING - Can't move filter wheel to V position,"
		" link to ccd first...\n");
    return;
  }
  doFilterWheel(ccd, &status, 3);

}

/*****************************************************************/

void on_r1_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  int status;

  if (ccd->filterPosition == 4) return;
  if (!ccd->Linked) {
    StatusPrint("*** WARNING - Can't move filter wheel to R position,"
		" link to ccd first...\n");
    return;
  }
  doFilterWheel(ccd, &status, 4);

}

/*****************************************************************/

void on_i1_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  int status;

  if (ccd->filterPosition == 5) return;
  if (!ccd->Linked) {
    StatusPrint("*** WARNING - Can't move filter wheel to I position,"
		" link to ccd first...\n");
    return;
  }
  doFilterWheel(ccd, &status, 5);

}

/*****************************************************************/

void on_c1_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  int status;

  if (ccd->filterPosition == 6) return;
  if (!ccd->Linked) {
    StatusPrint("*** WARNING - Can't move filter wheel to I position,"
		" link to ccd first...\n");
    return;
  }
  doFilterWheel(ccd, &status, 6);

}

/*****************************************************************/

void on_about1_activate(GtkMenuItem *menuitem, gpointer user_data)
{
}

/*****************************************************************/

void on_unlink_yes_click(GtkButton *button, gpointer user_data)
{
  int status;

  if (!ccd->Linked)
    return;

  doSetTempOffCamera(ccd, &status);
  ccd->Linked = false;
  establish_link(ccd, false);
  freeImageBuffers(ccd);

  gtk_exit(0);
}

/*****************************************************************/

void on_unlink_cancel_clicked(GtkButton *button, gpointer user_data)
{
  return;
}

/*****************************************************************/

void on_unlink_no_clicked(GtkButton *button, gpointer user_data)
{
  freeImageBuffers(ccd);
  gtk_exit(0);

}

/*****************************************************************/

void on_exit_save_yes_clicked(GtkButton *button, gpointer user_data)
{
  gchar *buffer;
  char FileName[80], ObjectName[20], *bptr;
  GtkWidget *UnlinkCameraQu;

  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(((GtkWidget *) user_data)));
  bptr = strchr(buffer,'&');
  if (bptr == NULL) {
    sscanf(buffer,"%s", FileName);
    strcpy(ObjectName," ");
  } else {
    strncpy(FileName,buffer,(bptr-buffer));
    FileName[bptr-buffer] = 0;
    strcpy(ObjectName,++bptr);
  }
  writeFITS(&ccd->Image, 1, FileName, ObjectName);
  
  if (ccd->Linked) {
    UnlinkCameraQu = create_UnlinkCameraQu();
    gtk_widget_show(UnlinkCameraQu);
    return;
  }
  /*  gtk_exit(0); */
}

/*****************************************************************/

void on_exit_save_no_clicked(GtkButton *button, gpointer user_data)
{
  GtkWidget *UnlinkCameraQu;

  if (ccd->Linked) {
    UnlinkCameraQu = create_UnlinkCameraQu();
    gtk_widget_show(UnlinkCameraQu);
    return;
  } else
    gtk_exit(0);
}

/*****************************************************************/

void on_exit_save_cancel_clicked(GtkButton *button, gpointer user_data)
{
  return;
}

/*****************************************************************/


void StatusPrint(char *Message)
{
  GtkWidget *view;
  GtkTextMark *mark;
  GtkTextBuffer *buffer;
  GtkTextIter end;
  GtkTextTag *tag;
  gint linecount;
  
  static char *StatusPrintPtr=NULL;
  char *ptr;
  GtkWidget *Label;
  int len;

  if (Message == NULL) return;
  if (CCDAutoSave == NULL) return;

  view = lookup_widget(CCDAutoSave,"StatusLogTextView");
  buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
  gtk_text_buffer_get_end_iter(buffer,&end);
  if (strstr(Message,"WARNING")) {
    tag = gtk_text_buffer_create_tag(buffer,NULL, "foreground",
				   "red", NULL);
  } else {
    tag = gtk_text_buffer_create_tag(buffer,NULL, "foreground",
				   "black", NULL);
  }
  gtk_text_buffer_insert_with_tags(buffer,&end,Message,-1,tag,NULL);
  mark = gtk_text_buffer_create_mark(buffer,NULL,&end,false);
  gtk_text_view_scroll_to_mark(GTK_TEXT_VIEW(view),mark,0.0,true,0.0,1.0);

  return;
}

/*****************************************************************/

void on_SingleSettingsExecute_clicked(GtkButton  *button, gpointer user_data)
{

  gtk_widget_hide(singleSettings_dialog);

  ExposeSingleFrame();
  return;
}

int ExposeSingleFrame(void)
{
  static int Busy=false;
  int status, i, d, nbytes, darkNeeded, gotDark, gotFlat;
  int success, hours, mins, isecs, degs, answer;
  char Message[80];
  float secs;
  double ccd_temp, dark_temp;
  OBJECT objectInfo;
  StartExposureParams expose;
  StartReadoutParams readout;

  if (!ccd->Linked) {
    StatusPrint("*** WARNING - Can't start exposure, link to camera first.\n");
    return 0;
  }

  if (Busy) {
    StatusPrint("*** Warning - Imaging CCD is busy, try again later...\n");
    return false;
  }

  Busy = true;

  // Get telescopes current position

  if (GetScopeRADEC) {
    success = GetScopePosition(&ScopeRA, &ScopeDEC);
    if (! success) {
      success = GetObjectInfo(singleSettings.ObjectName, &objectInfo);
      if (success) {
	sscanf(objectInfo.ra,"%02d:%02d:%f", &hours, &mins, &secs);
	ScopeRA = hours + ((float) mins)/60.0 + secs/3600.0;
	sscanf(objectInfo.dec,"%02d:%02d:%02d", &degs, &mins, &isecs);
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
    StatusPrint("*** WARNING - Can't get ccd temperature, "
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
  ccd->Image.light_frame.temp = ccd_temp;
  ccd->Image.light_frame.exposure = singleSettings.exposureTime;
  ccd->Image.Filter[0] = filterSet[ccd->filterPosition-1];
  ccd->Image.Filter[1] = '\000';
  dark_temp = ccd->Image.dark_frame.temp;
  strcpy(ccd->Image.light_frame.UT,"");
  strcpy(ccd->Image.light_frame.UTDATE,"");
  strcpy(ccd->Image.dark_frame.UT,"");
  strcpy(ccd->Image.dark_frame.UTDATE,"");

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
	sprintf(Message,"*** Warning - Couldn't find compatible dark frame"
		"in directory: %s aborting\n", singleSettings.DarkDir);
	StatusPrint(Message);
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
	sprintf(Message, "*** Warning - current flat frame not compatible"
		" with current settings\n");
	StatusPrint(Message);
	gotFlat = false;
      }
      break;
    case 3:
      gotFlat = readFlat(singleSettings.FlatDir, ccd);
      if (! gotFlat) {
	sprintf(Message, "*** Warning - couldn't find compatible flat"
		" frame in directory: %s, aborting\n", singleSettings.FlatDir);
	StatusPrint(Message);
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
  snapImaging(ccd, &expose, &readout, &ccd->Image);
  if (CancelCurrentAcquire) {
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

  ccd->Image.saved = false;
  ccd->Image.Filter[0] = filterSet[ccd->filterPosition-1];
  ccd->Image.Filter[1] = '\000';
  strcpy(ccd->Image.FileName,"");
  strcpy(ccd->Image.ObjectName,singleSettings.ObjectName);

  Busy = false;
  return true;
}



/*****************************************************************/

void on_SeriesSettingsExecute_clicked(GtkButton *button, gpointer user_data)
{
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
  GtkWidget *entry;

  StartExposureParams expose;
  StartReadoutParams readout;
  FILTERSET filterSeq;
  OBJECT objectInfo;

  /* Init control flags */

  PauseSeries = false;
  StopSeries = false;

  /* Check if linked to camera */

  if (!ccd->Linked) {
    sprintf(Message,"Can't start series, link to camera first.\n");
    StatusPrint(Message);
    return;
  }

  /* Get series parameters */

     /* Get object name & check if in data base */

  strcpy(objectName,seriesSettings.objectName);
  status = GetObjectInfo(objectName, &objectInfo);
  if (status == -1) {
    sprintf(Message,"*** Warning - Can't find info on %s,"
	    " skipping object info...\n", objectName);
    StatusPrint(Message);
    StatusPrint("Object info won't be in output files\n");
  }

     /* Get image directory */

  strcpy(imageDir,seriesSettings.imageDir);

     /* start & end times */

  startHours = seriesSettings.startHours;
  endHours = startHours + seriesSettings.duration;
  duration = seriesSettings.duration;

  /* Sequence interval */
  
  interval = seriesSettings.interval/60.0; /* convert to hours */
  
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
  
  sprintf(Message,"Your series is:\n"
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
  StatusPrint(Message);
  sprintf(Message,"Using filters: \n");
  StatusPrint(Message);
  for (i=0; i<NUMFILTERS; i++) {
    if (seriesSettings.filterSeq.Use[i]) {
      sprintf(Message," Filter: %c  -  Exposure: %f (secs)\n",
	      filterSet[i], seriesSettings.filterSeq.exposures[i]);
      StatusPrint(Message);
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
	sprintf(Message, "*** Warning - current flat frame not compatible"
		" with current settings\n");
	StatusPrint(Message);
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
  broken_time = localtime(&currentSeconds);

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
    diff = startSeconds - currentSeconds;
    if (diff > 0.0) {
      ihours = ((int) (diff/3600.0));
      imins = ((int) ((diff - ihours*3600.0)/60.0));
      isecs = ((int) (diff - ihours*3600.0 - imins*60.0));
      sprintf(Message, "%02d:%02d:%02d until start...\n",
	      ihours, imins, isecs);
      StatusPrint(Message);
    }
    
    while (currentSeconds < startSeconds) {
      diff = startSeconds - currentSeconds;
      ihours = ((int) (diff/3600.0));
      imins = ((int) ((diff - ihours*3600.0)/60.0));
      isecs = ((int) (diff - ihours*3600.0 - imins*60.0));
      fflush(stdout);
      if (diff < 121.0) {
	if (diff%10 == 0) {
	  sprintf(Message, "%02d:%02d:%02d left until start...\n",
		  ihours, imins, isecs);
	  StatusPrint(Message);
	}
	RunMainIteration(1.0);
      } else {
	if (diff%60 == 0) {
	  sprintf(Message,"%02d:%02d:%02d left until start...\n",
		  ihours, imins, isecs);
	  StatusPrint(Message);
	}
	RunMainIteration(10.0);
      }
      time(&currentSeconds);
    }
  }

  sprintf(Message, "Starting series...\n");
  StatusPrint(Message);

  nExposures = 0;
  nSequences = seriesSettings.startSeqNum;
  expose.abgState = 0;
  SeriesStarted = true;
  if (seriesSettings.AutoBumpScope)
    baseStarList = NULL;
  do {

    entry = lookup_widget(CCDAutoSave,"MainSeqNumEntry");
    sprintf(buffer,"%d", nSequences);
    gtk_entry_set_text(GTK_ENTRY(entry),buffer);

       /* Loop over filters in sequence */

    for (ifilter=0; ifilter<NUMFILTERS; ifilter++) {

      entry = lookup_widget(CCDAutoSave,"MainExpNumEntry");
      sprintf(buffer,"%d", nExposures);
      gtk_entry_set_text(GTK_ENTRY(entry),buffer);

      /* Check for user intervention */

      if (StopSeries) {
	SeriesStarted = false;
	return;
      }

      while (PauseSeries) {
	if (StopSeries) {
	  SeriesStarted = false;
	  return;
	}
	gtk_main_iteration();
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
	  StatusPrint("*** WARNING - Can't get ccd temperature...\n");
	  SeriesStarted = false;
	  return;
	}
	ccd->Image.light_frame.temp = ccd_temp;
      }
      if (seriesSettings.darkOption == 1) {
	dark_temp = ccd->Image.dark_frame.temp;
	darkNeeded = ((fabs(dark_temp-ccd_temp) > MAXTEMPDIFF) ||
		      (! ccd->Image.dark_frame.active) ||
		      (ccd->Image.dark_frame.exposure != eTime) ||
		      (seriesSettings.binning !=
		       ccd->Image.dark_frame.binning) ||
		      (seriesSettings.whichCCD !=
		       ccd->Image.dark_frame.whichCCD) ||
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
	  sprintf(Message,"*** Warning - Couldn't find compatible dark frame"
		  " in directory: %s, forcing dark frame\n",
		  seriesSettings.DarkDir);
	  StatusPrint(Message);
	  ccd->Image.lightOnly = false;
	  gotDark = true;
	} else {
	  ccd->Image.lightOnly = true;
	}
      }

      /* Take exposure */

      sprintf(Message, "Taking frame #%d (%c,%f)\n", ++nExposures,
	     filterSet[position-1],eTime);
      StatusPrint(Message);
      expose.exposureTime = (int)(100.0*eTime);
      time(&ccd->Image.light_frame.time);
      DontShowImageProgress = true;
      CancelCurrentAcquire = false;
      snapImaging(ccd, &expose, &readout, &ccd->Image);
      DontShowImageProgress = false;
      if (CancelCurrentAcquire) {
	SeriesStarted = false;
	return;
      }

      /* subtract out the dark, and adjust the image if required */

      if (gotDark) {
	for (i = readout.width*readout.height; --i >= 0; ) {
	  d = ccd->Image.light_frame.frame[i] - ccd->Image.dark_frame.frame[i];
	  if (d < 0)
	    d = 0;
	  else if (d > 65535) {
	    printf("*** DEBUG - d: %d\n", d);
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
	  sprintf(Message, "*** Warning - couldn't find compatible flat"
		  " frame in directory: %s, aborting...\n",
		  seriesSettings.FlatDir);
	  StatusPrint(Message);
	  return;
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


      /* update image parameters */

      ccd->Image.saved = false;
      strcpy(ccd->Image.FileName,"");
      strcpy(ccd->Image.ObjectName,seriesSettings.objectName);

      /* Write out image */

      sprintf(FileName,"%s/%s%c%03d.fits", imageDir, objectName,
	      filterSet[position-1], nSequences);
      sprintf(Message, "Writing image to file: %s\n", FileName);
      StatusPrint(Message);
      strcpy(ccd->Image.light_frame.UT,"");
      strcpy(ccd->Image.light_frame.UTDATE,"");
      writeFITS(&ccd->Image, 1, FileName, objectName);
      ccd->Image.saved = true;
      strcpy(ccd->Image.FileName,FileName);
      entry = lookup_widget(CCDAutoSave,"MainFileNameSeriesEntry");
      gtk_entry_set_text(GTK_ENTRY(entry),FileName);

      /* Do auto photometry if requested */

      if (photometrySettings.autoFind) {
	success = updateListStars(&ccd->Image, CurrentStarList);
	if (! success) {
	  sprintf(buffer, "*** WARNING - Couldn't update stars' positions, \n"
		          "              Skipping image # %d\n", nSequences);
	  StatusPrint(buffer);
	}
	success = measureListStars(&ccd->Image, CurrentStarList);
	if (! success) {
	  sprintf(buffer, "*** WARNING - Couldn't measure stars in frame\n"
		          "              Skipping frame # %d\n", nSequences);
	  StatusPrint(buffer);
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
    diff = (endSeconds-currentSeconds);
    if (diff > 0.0) {
      ihours = ((int) (diff/3600.0));
      imins = ((int) ((diff - ihours*3600.0)/60.0));
      isecs = ((int) (diff - ihours*3600.0 - imins*60.0));
      sprintf(Message, "%02d:%02d:%02d left in series...\n", 
	      ihours, imins, isecs);
      StatusPrint(Message);
      entry = lookup_widget(CCDAutoSave,"MainSeriesTimeToEnd");
      sprintf(Message, "%02d:%02d:%02d", ihours, imins, isecs);
      gtk_entry_set_text(GTK_ENTRY(entry), Message);
    } else {
      break;
    }

    /* Wait until time for next sequence */

    if (interval > 0.0) {
      intervalSec = ((int) (interval*3600.0));
      sprintf(Message, "Sequence done, sleeping for %d seconds\n",
	      intervalSec);
      StatusPrint(Message);
      do {
	sprintf(Message, "%d", intervalSec);
	entry = lookup_widget(CCDAutoSave,"MainSeriesTimeNextExp");
	gtk_entry_set_text(GTK_ENTRY(entry), Message);
	RunMainIteration(1.0);
	intervalSec--;
      } while (intervalSec > 0);
      
    }
    
  } while (currentSeconds < endSeconds);

  sprintf(Message, "Finished %d exposures...\n", nExposures);
  StatusPrint(Message);
  SeriesStarted = false;
}

/*****************************************************************/

void on_queryr_dialog_ok_clicked(GtkButton *button, gpointer user_data)
{
  GtkWidget *entry;
  gchar *buffer;
  int status;

  entry = lookup_widget(queryr_dialog,"answer");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(entry));
  sscanf(buffer,"%f", &queryr_dialog_answer);
  gtk_widget_hide(queryr_dialog);
  (*queryr_dialog_ok_function)(ccd, &status);
}

/*****************************************************************/

void on_expose_single_frame_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  gchar buffer[20], Option[80];
  GtkWidget *Entry, *Button;

  /* Save current settings in case "cancel" button hit */

  memcpy(&singleSettings_Save,&singleSettings, sizeof(singleSettings));

  /* Create the dialog if not already done */

  if (singleSettings_dialog == NULL) {
    singleSettings_dialog = create_SingleSettingsDialog();
  }

  /* Update the dialog values */

     /* exposure time */

  Entry = lookup_widget(singleSettings_dialog,
			       "SingleSettingsExpTimEntry");
  sprintf(buffer,"%-7.2f",singleSettings.exposureTime);
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);

     /* Which ccd */

  if (ccd->make != SBIG_MAKE) {
    Button = lookup_widget(singleSettings_dialog,
			   "SingleSettingsWhichCCDTrackButton");
    gtk_widget_hide(Button);
    Button = lookup_widget(singleSettings_dialog,
			   "SingleSettingsWhichCCDImageButton");
    gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				 check_button.toggle_button,true);
  } else {
    Button = lookup_widget(singleSettings_dialog,
			   "SingleSettingsWhichCCDTrackButton");
    gtk_widget_show(Button);
    if (singleSettings.whichCCD == 1)
      gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				   check_button.toggle_button,true);
    else
      gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				   check_button.toggle_button,false);
  }

     /* Binning */

  switch (singleSettings.binning) {
    case 0:
      Button = lookup_widget(singleSettings_dialog,
			     "SingleSettings1x1Button");
      break;
    case 1:
      Button = lookup_widget(singleSettings_dialog,
			     "SingleSettings2x2Button");
      break;
    case 2:
      Button = lookup_widget(singleSettings_dialog,
			     "SingleSettings3x3Button");
      break;
  }
  gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
			       check_button.toggle_button,true);

     /* ccd Frame size */

  Entry = lookup_widget(singleSettings_dialog,
			       "SingleSettingsCCDFrameEntry");
  sprintf(buffer,"%d, %d, %d, %d", singleSettings.x, singleSettings.y,
	  singleSettings.h, singleSettings.w);
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);

  /* Set dark frame option */

  Entry = lookup_widget(singleSettings_dialog,
			     "SingleSettingsDarkComboEntry");
  switch (singleSettings.darkOption) {
    case 1:
      strcpy(Option,"Reuse old dark frame");
      break;
    case 2:
      strcpy(Option,"Force new dark frame");
      break;
    case 3:
      strcpy(Option,"Use dark frame from file");
      break;
    case 4:
      strcpy(Option,"Don't do dark subtract");
      break;
  }
  gtk_entry_set_text(GTK_ENTRY(Entry), Option);
  Entry = lookup_widget(singleSettings_dialog,
			     "SingleSettingsDarkNameEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry), singleSettings.DarkDir);

  /* Set flat frame option */

  Entry = lookup_widget(singleSettings_dialog,
			     "SingleSettingsFlatComboEntry");
  switch (singleSettings.flatOption) {
    case 1:
      strcpy(Option,"Do not do flat fielding");
      break;
    case 2:
      strcpy(Option,"Use current flat field");
      break;
    case 3:
      strcpy(Option,"Use flat field from file");
      break;
  }
  gtk_entry_set_text(GTK_ENTRY(Entry), Option);
  Entry = lookup_widget(singleSettings_dialog,
			     "SingleSettingsFlatNameEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry), singleSettings.FlatDir);

     /* Object Name */

  Entry = lookup_widget(singleSettings_dialog,
			       "SingleSettingsObjectNameEntry");
  sprintf(buffer,"%s",singleSettings.ObjectName);
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);

     /* Image Directory */

  Entry = lookup_widget(singleSettings_dialog,
			       "SingleSettingsImageDirEntry");
  sprintf(buffer,"%s",singleSettings.ImageDir);
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);

  /* show the dialog */

  gtk_widget_show(singleSettings_dialog);

}

/*****************************************************************/

void on_expose_series_frames_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  int i;
  char entryName[80], buffer[80], Option[80];
  GtkWidget *Entry, *Button;

  /* Create the dialog if not already done */

  if (seriesSettings_dialog == NULL) {
    seriesSettings_dialog = create_SeriesSettingsDialog();
  }

  /* Save current settings in case "cancel" button hit */

  memcpy(&seriesSettings_Save,&seriesSettings, sizeof(seriesSettings));

  /* Update the dialog values */

     /* Which ccd */

  if (ccd->make != SBIG_MAKE) {
    Button = lookup_widget(seriesSettings_dialog,
			   "SeriesSettingsWhichCCDTrackButton");
    gtk_widget_hide(Button);
    Button = lookup_widget(seriesSettings_dialog,
			   "SeriesSettingsWhichCCDImageButton");
    gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				 check_button.toggle_button,true);
  } else {
    Button = lookup_widget(seriesSettings_dialog,
			   "SeriesSettingsWhichCCDTrackButton");
    gtk_widget_show(Button);
    if (seriesSettings.whichCCD == 1)
      gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				   check_button.toggle_button,true);
    else
      gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				   check_button.toggle_button,false);
  }
  
     /* Binning */

  switch (seriesSettings.binning) {
    case 0:
      Button = lookup_widget(seriesSettings_dialog,
			     "SeriesSettings1x1Button");
      break;
    case 1:
      Button = lookup_widget(seriesSettings_dialog,
			     "SeriesSettings2x2Button");
      break;
    case 2:
      Button = lookup_widget(seriesSettings_dialog,
			     "SeriesSettings3x3Button");
      break;
  }
  gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
			       check_button.toggle_button,true);

     /* ccd Frame size */

  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsCCDFrameEntry");
  sprintf(buffer,"%d, %d, %d, %d", seriesSettings.x, seriesSettings.y,
	  seriesSettings.h, seriesSettings.w);
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);

  /* Set dark frame option */

  Entry = lookup_widget(seriesSettings_dialog,
			     "SeriesSettingsDarkComboEntry");
  switch (seriesSettings.darkOption) {
    case 1:
      strcpy(Option,"Reuse old dark frame");
      break;
    case 2:
      strcpy(Option,"Force new dark frame");
      break;
    case 3:
      strcpy(Option,"Use dark frame from file");
      break;
    case 4:
      strcpy(Option,"Don't do dark subtract");
      break;
  }
  gtk_entry_set_text(GTK_ENTRY(Entry), Option);
  Entry = lookup_widget(seriesSettings_dialog,
			     "SeriesSettingsDarkNameEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry), seriesSettings.DarkDir);

  /* Set flat frame option */

  Entry = lookup_widget(seriesSettings_dialog,
			     "SeriesSettingsFlatComboEntry");
  switch (seriesSettings.flatOption) {
    case 1:
      strcpy(Option,"Do not do flat fielding");
      break;
    case 2:
      strcpy(Option,"Use current flat field");
      break;
    case 3:
      strcpy(Option,"Use flat field from file");
      break;
  }
  gtk_entry_set_text(GTK_ENTRY(Entry), Option);
  Entry = lookup_widget(seriesSettings_dialog,
			     "SeriesSettingsFlatNameEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry), seriesSettings.FlatDir);

  /* Set the filter sequence values */

  for (i=0; i<NUMFILTERS; i++) {
    if (seriesSettings.filterSeq.Use[i]) {
      sprintf(buffer,"%-6.2f",seriesSettings.filterSeq.exposures[i]);
    } else {
      strcpy(buffer," ");
    }
    sprintf(entryName,"SeriesSettings%cExpEntry",filterSet[i]);
    Entry = lookup_widget(seriesSettings_dialog, entryName);
    gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
  } 

  sprintf(buffer,"%5.2f",seriesSettings.duration);
  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsDurEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);

  sprintf(buffer,"%5.2f",seriesSettings.interval);
  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsIntervalEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);

  sprintf(buffer,"%d",seriesSettings.startSeqNum);
  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsSeqNoEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);

  sprintf(buffer,"%5.2f",seriesSettings.startHours);
  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsStartEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);

  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsObjectEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry), seriesSettings.objectName);

  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsImageDirEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry), seriesSettings.imageDir);

  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsFrameSizeEntry");
  sprintf(buffer,"%d, %d, %d, %d", seriesSettings.x, seriesSettings.y,
	  seriesSettings.h, seriesSettings.w);
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);

  /* Show dialog */

  gtk_widget_show(seriesSettings_dialog);
}

/*****************************************************************/


void on_SingleSettingsWhichCCDButton_toggled(GtkToggleButton *togglebutton,
					     gpointer user_data)
{
  char buffer[80];
  GtkWidget *Imagebutton, *Entry;

  Imagebutton = lookup_widget(singleSettings_dialog,
				  "SingleSettingsWhichCCDImageButton");
  if (gtk_toggle_button_get_active(&(GTK_RADIO_BUTTON(Imagebutton))
				    ->check_button.toggle_button)) {
    singleSettings.whichCCD = 0;
    GetCCDFrameSettings(ccd, &singleSettings.x, &singleSettings.y,
			&singleSettings.w, &singleSettings.h,
			&singleSettings.binning);
  } else {
    if (ccd->make == SBIG_MAKE) {
      singleSettings.whichCCD = 1;
      singleSettings.x = singleSettings.y = 0;
      singleSettings.w = ccd->info1.readoutInfo[0].width;
      singleSettings.h = ccd->info1.readoutInfo[0].height;
    } else {
      sprintf(buffer,"*** Warning - %s only has one ccd\n", ccd->name);
      StatusPrint(buffer);
    }
  }

  Entry = lookup_widget(singleSettings_dialog,
			"SingleSettingsCCDFrameEntry");
  sprintf(buffer,"%d, %d, %d, %d", singleSettings.x, singleSettings.y,
	  singleSettings.h, singleSettings.w);
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
  
}

/*****************************************************************/

void on_SingleSettingsOkay_clicked(GtkButton *button, gpointer user_data)
{
  char Message[160], *Option;
  gchar *buffer;
  GtkWidget *Entry;

  /* Get exposure time */

  Entry = lookup_widget(singleSettings_dialog,
			       "SingleSettingsExpTimEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%f", &singleSettings.exposureTime);

  /* Get ccd frame size */

  Entry = lookup_widget(singleSettings_dialog,
			       "SingleSettingsCCDFrameEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%d, %d, %d, %d", &singleSettings.x, &singleSettings.y,
	 &singleSettings.h, &singleSettings.w);

  /* Get Object Name */

  Entry = lookup_widget(singleSettings_dialog,
			       "SingleSettingsObjectNameEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(singleSettings.ObjectName,buffer);

  /* Get Image Directory */

  Entry = lookup_widget(singleSettings_dialog,
			       "SingleSettingsImageDirEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(singleSettings.ImageDir,buffer);

  /* Get dark frame option */

  Entry = lookup_widget(singleSettings_dialog,
			     "SingleSettingsDarkComboEntry");
  Option = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  if (strcmp(Option,"Reuse old dark frame") == 0) {
    singleSettings.darkOption = 1;
  } else if (strcmp(Option,"Force new dark frame") == 0) {
    singleSettings.darkOption = 2;
  } else if (strcmp(Option,"Use dark frame from file") == 0) {
    singleSettings.darkOption = 3;
  } else if (strcmp(Option,"Don't do dark subtract") == 0) {
    singleSettings.darkOption = 4;
  } else {
    sprintf(Message, "*** Internal error - bad dark option: %s"
	    " (singleSettings)\n",Option);
    StatusPrint(Message);
  }
  Entry = lookup_widget(singleSettings_dialog,
			     "SingleSettingsDarkNameEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(singleSettings.DarkDir, buffer);

  /* Get flat frame option */

  Entry = lookup_widget(singleSettings_dialog,
			     "SingleSettingsFlatComboEntry");
  Option = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  if (strcmp(Option,"Do not do flat fielding") == 0) {
    singleSettings.flatOption = 1;
  } else if (strcmp(Option,"Use current flat field") == 0) {
    singleSettings.flatOption = 2;
  } else if (strcmp(Option,"Use flat field from file") == 0) {
    singleSettings.flatOption = 3;
  } else {
    sprintf(Message, "*** Internal error - bad flat option: %s"
	    " (singleSettings)\n", Option);
    StatusPrint(Message);
  }
  Entry = lookup_widget(singleSettings_dialog,
			     "SingleSettingsFlatNameEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(singleSettings.FlatDir, buffer);

  gtk_widget_hide(singleSettings_dialog);
  updateStatusInfo(dummy);
}

/*****************************************************************/

void on_SingleSettingsCancel_clicked(GtkButton *button, gpointer user_data)
{
  gtk_widget_hide(singleSettings_dialog);
  memcpy(&singleSettings,&singleSettings_Save,sizeof(singleSettings));
}

/*****************************************************************/

void on_SingleSettings1x1Button_toggled(GtkToggleButton *togglebutton,
					gpointer user_data)
{
  char buffer[80];
  int iccd;
  GtkWidget *Entry;

  if (singleSettings.binning != 0) {
    singleSettings.binning = 0;
    iccd = singleSettings.whichCCD;
    if (iccd == 0) {
      GetCCDFrameSettings(ccd, &singleSettings.x, &singleSettings.y,
			  &singleSettings.w, &singleSettings.h,
			  &singleSettings.binning);
    } else {
      singleSettings.w = ccd->info1.readoutInfo[0].width;
      singleSettings.h = ccd->info1.readoutInfo[0].height;
    }
    Entry = lookup_widget(singleSettings_dialog,
			  "SingleSettingsCCDFrameEntry");
    sprintf(buffer,"%d, %d, %d, %d", singleSettings.x, singleSettings.y,
	    singleSettings.h, singleSettings.w);
    gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
  }
}

/*****************************************************************/

void on_SingleSettings2x2Button_toggled(GtkToggleButton *togglebutton,
						  gpointer user_data)
{
  char buffer[80];
  int iccd;
  GtkWidget *Entry;

  if (singleSettings.binning != 1) {
    singleSettings.binning = 1;
    iccd = singleSettings.whichCCD;
    if (iccd == 0) {
      GetCCDFrameSettings(ccd, &singleSettings.x, &singleSettings.y,
			  &singleSettings.w, &singleSettings.h,
			  &singleSettings.binning);
    } else {
      singleSettings.w = ccd->info1.readoutInfo[1].width;
      singleSettings.h = ccd->info1.readoutInfo[1].height;
    }
    Entry = lookup_widget(singleSettings_dialog,
			  "SingleSettingsCCDFrameEntry");
    sprintf(buffer,"%d, %d, %d, %d", singleSettings.x, singleSettings.y,
	    singleSettings.h, singleSettings.w);
    gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
  }
}

/*****************************************************************/

void on_SingleSettings3x3Button_toggled(GtkToggleButton *togglebutton,
						  gpointer user_data)
{
  static int Tried=false;

  char buffer[80];
  int iccd;
  GtkWidget *Trackbutton, *Entry;

  if (singleSettings.binning != 2) {
    Trackbutton = lookup_widget(singleSettings_dialog,
				"SingleSettingsWhichCCDTrackButton");
    if (gtk_toggle_button_get_active(&(GTK_RADIO_BUTTON(Trackbutton))
				     ->check_button.toggle_button)) {
      if (! Tried) {
	StatusPrint("*** Warning - Can't do 3x3 binning with tracking ccd\n");
	Tried = true;
      } else
	Tried = false;
    } else {
      singleSettings.binning = 2;
      iccd = singleSettings.whichCCD;
      if (iccd == 0) {
	GetCCDFrameSettings(ccd, &singleSettings.x, &singleSettings.y,
			    &singleSettings.w, &singleSettings.h,
			    &singleSettings.binning);
      } else {
	singleSettings.w = ccd->info1.readoutInfo[2].width;
	singleSettings.h = ccd->info1.readoutInfo[2].height;
      }
      Entry = lookup_widget(singleSettings_dialog,
			    "SingleSettingsCCDFrameEntry");
      sprintf(buffer,"%d, %d, %d, %d", singleSettings.x, singleSettings.y,
	      singleSettings.h, singleSettings.w);
      gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
    }
  }
}

/*****************************************************************/

void on_SeriesSettingsWhichCCDImageButton_toggled(GtkToggleButton *togglebutton,
						  gpointer user_data)
{
  char buffer[80];
  GtkWidget *Imagebutton, *Entry;

  Imagebutton = lookup_widget(seriesSettings_dialog,
				  "SeriesSettingsWhichCCDImageButton");
  if (gtk_toggle_button_get_active(&(GTK_RADIO_BUTTON(Imagebutton))
				    ->check_button.toggle_button)) {
    seriesSettings.whichCCD = 0;
    GetCCDFrameSettings(ccd, &seriesSettings.x, &seriesSettings.y,
			&seriesSettings.w, &seriesSettings.h,
			&seriesSettings.binning);
  } else {
    seriesSettings.whichCCD = 1;
    if (ccd->make == SBIG_MAKE) {
      seriesSettings.whichCCD = 1;
      seriesSettings.x = seriesSettings.y = 0;
      seriesSettings.w = ccd->info1.readoutInfo[0].width;
      seriesSettings.h = ccd->info1.readoutInfo[0].height;
    } else {
      sprintf(buffer,"*** Warning - %s only has one ccd\n", ccd->name);
      StatusPrint(buffer);
    }
  }
  Entry = lookup_widget(seriesSettings_dialog,
			"SeriesSettingsFrameSizeEntry");
  sprintf(buffer,"%d, %d, %d, %d", seriesSettings.x, seriesSettings.y,
	  seriesSettings.h, seriesSettings.w);
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
}

/*****************************************************************/

void on_SeriesSettings1x1Button_toggled(GtkToggleButton *togglebutton,
					       gpointer user_data)
{
  int iccd;
  char buffer[80];
  GtkWidget *Entry;

  if (seriesSettings.binning != 0) {
    StatusPrint("Changing to 1x1 binning\n");
    seriesSettings.binning = 0;
    iccd = seriesSettings.whichCCD;
    if (iccd == 0) {
      GetCCDFrameSettings(ccd, &seriesSettings.x, &seriesSettings.y,
			  &seriesSettings.w, &seriesSettings.h,
			  &seriesSettings.binning);
    } else {
      seriesSettings.w = ccd->info1.readoutInfo[0].width;
      seriesSettings.h = ccd->info1.readoutInfo[0].height;
    }
    Entry = lookup_widget(seriesSettings_dialog,
			  "SeriesSettingsFrameSizeEntry");
    sprintf(buffer,"%d, %d, %d, %d", seriesSettings.x, seriesSettings.y,
	    seriesSettings.h, seriesSettings.w);
    gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
  }
}

/*****************************************************************/

void on_SeriesSettings2x2Button_toggled(GtkToggleButton *togglebutton,
					       gpointer user_data)
{
  int iccd;
  char buffer[80];
  GtkWidget *Entry;

  if (seriesSettings.binning != 1) {
    StatusPrint("Changing to 2x2 binning\n");
    seriesSettings.binning = 1;
    iccd = seriesSettings.whichCCD;
    if (iccd == 0) {
      GetCCDFrameSettings(ccd, &seriesSettings.x, &seriesSettings.y,
			  &seriesSettings.w, &seriesSettings.h,
			  &seriesSettings.binning);
    } else {
      seriesSettings.w = ccd->info1.readoutInfo[1].width;
      seriesSettings.h = ccd->info1.readoutInfo[1].height;
    }
    Entry = lookup_widget(seriesSettings_dialog,
			  "SeriesSettingsFrameSizeEntry");
    sprintf(buffer,"%d, %d, %d, %d", seriesSettings.x, seriesSettings.y,
	    seriesSettings.h, seriesSettings.w);
    gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
  }
}

/*****************************************************************/

void on_SeriesSettings3x3Button_toggled(GtkToggleButton *togglebutton,
					       gpointer user_data)
{
  static int Tried=false;

  int iccd;
  char buffer[80];
  GtkWidget *Entry;
  GtkWidget *Trackbutton;

  if (seriesSettings.binning != 2) {
    Trackbutton = lookup_widget(seriesSettings_dialog,
				"SeriesSettingsWhichCCDTrackButton");
    if (gtk_toggle_button_get_active(&(GTK_RADIO_BUTTON(Trackbutton))
				     ->check_button.toggle_button)) {
      if (! Tried) {
	StatusPrint("*** Warning - Can't do 3x3 binning with tracking ccd\n");
	Tried = true;
      } else
	Tried = false;
    } else {
      StatusPrint("Changing to 3x3 binning\n");
      seriesSettings.binning = 2; 
      iccd = seriesSettings.whichCCD;
      if (iccd == 0) {
	GetCCDFrameSettings(ccd, &seriesSettings.x, &seriesSettings.y,
			    &seriesSettings.w, &seriesSettings.h,
			    &seriesSettings.binning);
      } else {
	seriesSettings.w = ccd->info1.readoutInfo[2].width;
	seriesSettings.h = ccd->info1.readoutInfo[2].height;
      }
      Entry = lookup_widget(seriesSettings_dialog,
			    "SeriesSettingsFrameSizeEntry");
      sprintf(buffer,"%d, %d, %d, %d", seriesSettings.x, seriesSettings.y,
	      seriesSettings.h, seriesSettings.w);
      gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
    }
  }
}

/*****************************************************************/

void on_SeriesSettingsUButton_toggled(GtkToggleButton *togglebutton,
				      gpointer user_data)
{
  GtkWidget *button;

  button = lookup_widget(seriesSettings_dialog,
			 "SeriesSettingsUButton");
  if (gtk_toggle_button_get_active(&(GTK_CHECK_BUTTON(button))
				     ->toggle_button)) {
    seriesSettings.filterSeq.Use[0] = true;
  } else {
    seriesSettings.filterSeq.Use[0] = false;
  }
}

/*****************************************************************/

void on_SeriesSettingsBButton_toggled(GtkToggleButton *togglebutton,
				      gpointer user_data)
{
  GtkWidget *button;

  button = lookup_widget(seriesSettings_dialog,
			 "SeriesSettingsBButton");
  if (gtk_toggle_button_get_active(&(GTK_CHECK_BUTTON(button))
				     ->toggle_button)) {
    seriesSettings.filterSeq.Use[1] = true;
  } else {
    seriesSettings.filterSeq.Use[1] = false;
  }
}

/*****************************************************************/

void on_SeriesSettingsVButton_toggled(GtkToggleButton *togglebutton,
                                        gpointer user_data)
{
  GtkWidget *button;

  button = lookup_widget(seriesSettings_dialog,
			 "SeriesSettingsVButton");
  if (gtk_toggle_button_get_active(&(GTK_CHECK_BUTTON(button))
				     ->toggle_button)) {
    seriesSettings.filterSeq.Use[2] = true;
  } else {
    seriesSettings.filterSeq.Use[2] = false;
  }
}

/*****************************************************************/

void on_SeriesSettingsRButton_toggled(GtkToggleButton *togglebutton,
				      gpointer user_data)
{
  GtkWidget *button;

  button = lookup_widget(seriesSettings_dialog,
			 "SeriesSettingsRButton");
  if (gtk_toggle_button_get_active(&(GTK_CHECK_BUTTON(button))
				     ->toggle_button)) {
    seriesSettings.filterSeq.Use[3] = true;
  } else {
    seriesSettings.filterSeq.Use[3] = false;
  }
}

/*****************************************************************/

void on_SeriesSettingsIButton_toggled(GtkToggleButton *togglebutton,
                                        gpointer user_data)
{
  GtkWidget *button;

  button = lookup_widget(seriesSettings_dialog,
			 "SeriesSettingsIButton");
  if (gtk_toggle_button_get_active(&(GTK_CHECK_BUTTON(button))
				     ->toggle_button)) {
    seriesSettings.filterSeq.Use[4] = true;
  } else {
    seriesSettings.filterSeq.Use[4] = false;
  }
}

/*****************************************************************/

void on_SeriesSettingsCButton_toggled(GtkToggleButton *togglebutton,
				      gpointer user_data)
{
  GtkWidget *button;

  button = lookup_widget(seriesSettings_dialog,
			 "SeriesSettingsCButton");
  if (gtk_toggle_button_get_active(&(GTK_CHECK_BUTTON(button))
				     ->toggle_button)) {
    seriesSettings.filterSeq.Use[5] = true;
  } else {
    seriesSettings.filterSeq.Use[5] = false;
  }
}


/*****************************************************************/

void on_SeriesSettingsOkay_clicked(GtkButton *button, gpointer user_data)
{
  UpdateSeriesSettings();

  /* Hide Dialog */

  gtk_widget_hide(seriesSettings_dialog);

  return;
}

void UpdateSeriesSettings(void)
{
  int i;
  time_t now;
  struct tm *broken_time;
  char *Option, Message[80];
  gchar name[80];
  gchar *buffer;
  GtkWidget *Entry, *filterButton;

  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsFrameSizeEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%d, %d, %d, %d", &seriesSettings.x, &seriesSettings.y,
	 &seriesSettings.h, &seriesSettings.w);

  /* Get dark frame option */

  Entry = lookup_widget(seriesSettings_dialog,
			     "SeriesSettingsDarkComboEntry");
  Option = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  if (strcmp(Option,"Reuse old dark frame") == 0) {
    seriesSettings.darkOption = 1;
  } else if (strcmp(Option,"Force new dark frame") == 0) {
    seriesSettings.darkOption = 2;
  } else if (strcmp(Option,"Use dark frame from file") == 0) {
    seriesSettings.darkOption = 3;
  } else if (strcmp(Option,"Don't do dark subtract") == 0) {
    seriesSettings.darkOption = 4;
  } else {
    sprintf(Message, "*** Internal error - bad dark option: %s"
	    " (seriesSettings)\n", Option);
    StatusPrint(Message);
  }
  Entry = lookup_widget(seriesSettings_dialog,
			     "SeriesSettingsDarkNameEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(seriesSettings.DarkDir, buffer);

  /* Get flat frame option */

  Entry = lookup_widget(seriesSettings_dialog,
			     "SeriesSettingsFlatComboEntry");
  Option = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  if (strcmp(Option,"Do not do flat fielding") == 0) {
    seriesSettings.flatOption = 1;
  } else if (strcmp(Option,"Use curent flat field") == 0) {
    seriesSettings.flatOption = 2;
  } else if (strcmp(Option,"Use flat field from file") == 0) {
    seriesSettings.flatOption = 3;
  } else {
    sprintf(Message, "*** Internal error - bad flat option: %s"
	    " (seriesSettings)\n", Option);
    StatusPrint(Message);
  }
  Entry = lookup_widget(seriesSettings_dialog,
			     "SeriesSettingsFlatNameEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(seriesSettings.FlatDir, buffer);

  /* Get the filter sequence values */

  for (i=0; i<NUMFILTERS; i++) {
    sprintf(name,"SeriesSettings%cButton", filterSet[i]);
    filterButton = lookup_widget(seriesSettings_dialog, name);
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(filterButton))) {
      seriesSettings.filterSeq.Use[i] = true;
      sprintf(name,"SeriesSettings%cExpEntry", filterSet[i]);
      Entry = lookup_widget(seriesSettings_dialog, name);
      buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
      sscanf(buffer, "%f", &seriesSettings.filterSeq.exposures[i]);
    }
  }
  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsStartEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  if (strcmp(buffer,"now") == 0) {
    time(&now);
    broken_time = localtime(&now);
    seriesSettings.startHours = broken_time->tm_hour +
      broken_time->tm_min/60.0 + broken_time->tm_sec/3600.0;
  } else {
    sscanf(buffer, "%f", &seriesSettings.startHours);
  }
  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsDurEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%f", &seriesSettings.duration);
  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsIntervalEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%f", &seriesSettings.interval);
  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsSeqNoEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%d", &seriesSettings.startSeqNum);
  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsObjectEntry");
  strcpy(seriesSettings.objectName,gtk_entry_get_text(GTK_ENTRY(Entry)));
  Entry = lookup_widget(seriesSettings_dialog,
			       "SeriesSettingsImageDirEntry");
  strcpy(seriesSettings.imageDir,gtk_entry_get_text(GTK_ENTRY(Entry)));
  updateStatusInfo(dummy);
}

gboolean on_CurrentImagePixMap_expose_event(GtkWidget *widget,
					    GdkEventExpose *event,
					    gpointer user_data)
{
  return false;
}


void viewEdit_object_list_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  int EditState;
  GtkWidget *comboBox, *checkButton, *entry;
  GList *items=NULL;
  char *name, buffer[80];
  OBJECT obj;

  /* Create the dialog widget if necessary */

  if (ObjectListDialog == NULL) {
    ObjectListDialog = create_ObjectListDialog();
  }

  /* Read in object list from file in case changed */

  InitObjectList(objectListFileName);

  /* update the dialog components */

     /* Combo box */

  items = MakeObjectNameList();
  if (items != NULL) {
    comboBox = lookup_widget(ObjectListDialog,"ObjectListCombo");
    gtk_combo_set_popdown_strings(GTK_COMBO(comboBox), items);
  }

  checkButton = lookup_widget(ObjectListDialog,"ObjectListEditButton");
  gtk_toggle_button_set_active(&GTK_CHECK_BUTTON(checkButton)->toggle_button,
			       false);
  EditState = false;


  /* select object from combo box */

  entry = lookup_widget(ObjectListDialog,"ObjectListComboEntry");
  name = (gchar *) gtk_entry_get_text(GTK_ENTRY(entry));
  if (! GetObjectInfo(name, &obj)) {
    sprintf(buffer,"*** Internal Error - Can't find object: %s\n", name);
    StatusPrint(buffer);
    return;
  }

  /* Display object's info */

  entry = lookup_widget(ObjectListDialog,"ObjectListNameEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.name);
  entry = lookup_widget(ObjectListDialog,"ObjectListObjTypeEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.objectType);
  entry = lookup_widget(ObjectListDialog,"ObjectListSpecTypeEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.specType);
  entry = lookup_widget(ObjectListDialog,"ObjectListVarTypeEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.varType);
  entry = lookup_widget(ObjectListDialog,"ObjectListRAEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.ra);
  entry = lookup_widget(ObjectListDialog,"ObjectListDECEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.dec);
  entry = lookup_widget(ObjectListDialog,"ObjectListUEntry");
  sprintf(buffer,"%6.3f", obj.Mags[0]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);
  entry = lookup_widget(ObjectListDialog,"ObjectListBEntry");
  sprintf(buffer,"%6.3f", obj.Mags[1]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);
  entry = lookup_widget(ObjectListDialog,"ObjectListVEntry");
  sprintf(buffer,"%6.3f", obj.Mags[2]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);
  entry = lookup_widget(ObjectListDialog,"ObjectListREntry");
  sprintf(buffer,"%6.3f", obj.Mags[3]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);
  entry = lookup_widget(ObjectListDialog,"ObjectListIEntry");
  sprintf(buffer,"%6.3f", obj.Mags[4]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);

  ObjectListEditable = false;

  gtk_widget_show(ObjectListDialog);
}


void on_ObjectListOkButton_clicked(GtkButton *button, gpointer user_data)
{
  WriteObjectList();
  gtk_widget_hide(ObjectListDialog);
  updateStatusInfo(dummy);
}


void on_ObjectListSelectButton_clicked(GtkButton *button, gpointer user_data)
{
  gchar *name, buffer[20], Message[160];
  OBJECT obj;
  GtkWidget *comboEntry, *entry;

  /* select selects object from combo box */

  comboEntry = lookup_widget(ObjectListDialog,"ObjectListComboEntry");
  name = (gchar *) gtk_entry_get_text(GTK_ENTRY(comboEntry));
  if (! GetObjectInfo(name, &obj)) {
    sprintf(Message,"*** Internal Error - Can't find object: %s\n", name);
    StatusPrint(Message);
    return;
  }

  /* Display object's info */

  entry = lookup_widget(ObjectListDialog,"ObjectListNameEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.name);
  entry = lookup_widget(ObjectListDialog,"ObjectListObjTypeEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.objectType);
  entry = lookup_widget(ObjectListDialog,"ObjectListSpecTypeEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.specType);
  entry = lookup_widget(ObjectListDialog,"ObjectListVarTypeEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.varType);
  entry = lookup_widget(ObjectListDialog,"ObjectListRAEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.ra);
  entry = lookup_widget(ObjectListDialog,"ObjectListDECEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.dec);
  entry = lookup_widget(ObjectListDialog,"ObjectListUEntry");
  sprintf(buffer,"%f", obj.Mags[0]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);
  entry = lookup_widget(ObjectListDialog,"ObjectListBEntry");
  sprintf(buffer,"%f", obj.Mags[1]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);
  entry = lookup_widget(ObjectListDialog,"ObjectListVEntry");
  sprintf(buffer,"%f", obj.Mags[2]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);
  entry = lookup_widget(ObjectListDialog,"ObjectListREntry");
  sprintf(buffer,"%f", obj.Mags[3]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);
  entry = lookup_widget(ObjectListDialog,"ObjectListIEntry");
  sprintf(buffer,"%f", obj.Mags[4]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);

  strcpy(singleSettings.ObjectName, obj.name);
  strcpy(seriesSettings.objectName, obj.name);

  return;
}


void on_ObjectListApplyButton_clicked(GtkButton *button, gpointer user_data)
{
  OBJECT obj;
  GtkWidget *comboBox, *entry;
  GList *items=NULL;
  int nitems;

  /* Update object list with changes */

  entry = lookup_widget(ObjectListDialog,"ObjectListNameEntry");
  strcpy(obj.name,gtk_entry_get_text(GTK_ENTRY(entry)));
  if (strstr(obj.name," ") != NULL) {
    MessageBox("WARNING - blanks are not allowed in object names,\n"
	       " object not updated...\n", OKAY);
    return;
  }
 entry = lookup_widget(ObjectListDialog,"ObjectListObjTypeEntry");
  strcpy(obj.objectType,gtk_entry_get_text(GTK_ENTRY(entry)));
  entry = lookup_widget(ObjectListDialog,"ObjectListSpecTypeEntry");
  strcpy(obj.specType,gtk_entry_get_text(GTK_ENTRY(entry)));
  entry = lookup_widget(ObjectListDialog,"ObjectListVarTypeEntry");
  strcpy(obj.varType,gtk_entry_get_text(GTK_ENTRY(entry)));
  entry = lookup_widget(ObjectListDialog,"ObjectListRAEntry");
  strcpy(obj.ra,gtk_entry_get_text(GTK_ENTRY(entry)));
  entry = lookup_widget(ObjectListDialog,"ObjectListDECEntry");
  strcpy(obj.dec,gtk_entry_get_text(GTK_ENTRY(entry)));
  entry = lookup_widget(ObjectListDialog,"ObjectListUEntry");
  nitems = sscanf(gtk_entry_get_text(GTK_ENTRY(entry)), "%f", &obj.Mags[0]);
  if (nitems <= 0)
    obj.Mags[0] = 0.0;
  entry = lookup_widget(ObjectListDialog,"ObjectListBEntry");
  nitems = sscanf(gtk_entry_get_text(GTK_ENTRY(entry)), "%f", &obj.Mags[1]);
  if (nitems <= 0)
    obj.Mags[1] = 0.0;
  entry = lookup_widget(ObjectListDialog,"ObjectListVEntry");
  nitems = sscanf(gtk_entry_get_text(GTK_ENTRY(entry)), "%f", &obj.Mags[2]);
  if (nitems <= 0)
    obj.Mags[2] = 0.0;
  entry = lookup_widget(ObjectListDialog,"ObjectListREntry");
  nitems = sscanf(gtk_entry_get_text(GTK_ENTRY(entry)), "%f", &obj.Mags[3]);
  if (nitems <= 0)
    obj.Mags[3] = 0.0;
  entry = lookup_widget(ObjectListDialog,"ObjectListIEntry");
  nitems = sscanf(gtk_entry_get_text(GTK_ENTRY(entry)), "%f", &obj.Mags[4]);
  if (nitems <= 0)
    obj.Mags[4] = 0.0;

  SetObjectInfo(obj.name, &obj);
      
  /* Update combo box dropdown list */

  items = MakeObjectNameList();
  if (items != NULL) {
    comboBox = lookup_widget(ObjectListDialog,"ObjectListCombo");
    gtk_combo_set_popdown_strings(GTK_COMBO(comboBox), items);
  }

  return;
}


void on_ObjectListNewButton_clicked(GtkButton *button, gpointer user_data)
{
  GtkWidget *Entry, *checkButton;

  Entry = lookup_widget(ObjectListDialog, "ObjectListNameEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry),"");
  gtk_entry_set_editable(GTK_ENTRY(Entry), true);

  Entry = lookup_widget(ObjectListDialog, "ObjectListObjTypeEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry),"");
  gtk_entry_set_editable(GTK_ENTRY(Entry), true);

  Entry = lookup_widget(ObjectListDialog, "ObjectListVarTypeEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry),"");
  gtk_entry_set_editable(GTK_ENTRY(Entry), true);

  Entry = lookup_widget(ObjectListDialog, "ObjectListSpecTypeEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry),"");
  gtk_entry_set_editable(GTK_ENTRY(Entry), true);

  Entry = lookup_widget(ObjectListDialog, "ObjectListRAEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry),"");
  gtk_entry_set_editable(GTK_ENTRY(Entry), true);

  Entry = lookup_widget(ObjectListDialog, "ObjectListDECEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry),"");
  gtk_entry_set_editable(GTK_ENTRY(Entry), true);

  Entry = lookup_widget(ObjectListDialog, "ObjectListUEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry),"");
  gtk_entry_set_editable(GTK_ENTRY(Entry), true);

  Entry = lookup_widget(ObjectListDialog, "ObjectListBEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry),"");
  gtk_entry_set_editable(GTK_ENTRY(Entry), true);

  Entry = lookup_widget(ObjectListDialog, "ObjectListVEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry),"");
  gtk_entry_set_editable(GTK_ENTRY(Entry), true);

  Entry = lookup_widget(ObjectListDialog, "ObjectListREntry");
  gtk_entry_set_text(GTK_ENTRY(Entry),"");
  gtk_entry_set_editable(GTK_ENTRY(Entry), true);

  Entry = lookup_widget(ObjectListDialog, "ObjectListIEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry),"");
  gtk_entry_set_editable(GTK_ENTRY(Entry), true);

  ObjectListEditable = true;
  checkButton = lookup_widget(ObjectListDialog,"ObjectListEditButton");
  gtk_toggle_button_set_active(&GTK_CHECK_BUTTON(checkButton)->toggle_button,
			       true);
}

void on_ObjectListEditButton_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
  GtkWidget *Entry;

  if (gtk_toggle_button_get_active(togglebutton)) {
    Entry = lookup_widget(ObjectListDialog, "ObjectListNameEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), true);
    Entry = lookup_widget(ObjectListDialog, "ObjectListObjTypeEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), true);
    Entry = lookup_widget(ObjectListDialog, "ObjectListVarTypeEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), true);
    Entry = lookup_widget(ObjectListDialog, "ObjectListSpecTypeEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), true);
    Entry = lookup_widget(ObjectListDialog, "ObjectListRAEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), true);
    Entry = lookup_widget(ObjectListDialog, "ObjectListDECEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), true);
    Entry = lookup_widget(ObjectListDialog, "ObjectListUEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), true);
    Entry = lookup_widget(ObjectListDialog, "ObjectListBEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), true);
    Entry = lookup_widget(ObjectListDialog, "ObjectListVEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), true);
    Entry = lookup_widget(ObjectListDialog, "ObjectListREntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), true);
    Entry = lookup_widget(ObjectListDialog, "ObjectListIEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), true);
    ObjectListEditable = true;
  } else {
    Entry = lookup_widget(ObjectListDialog, "ObjectListNameEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), false);
    Entry = lookup_widget(ObjectListDialog, "ObjectListObjTypeEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), false);
    Entry = lookup_widget(ObjectListDialog, "ObjectListVarTypeEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), false);
    Entry = lookup_widget(ObjectListDialog, "ObjectListSpecTypeEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), false);
    Entry = lookup_widget(ObjectListDialog, "ObjectListRAEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), false);
    Entry = lookup_widget(ObjectListDialog, "ObjectListDECEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), false);
    Entry = lookup_widget(ObjectListDialog, "ObjectListUEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), false);
    Entry = lookup_widget(ObjectListDialog, "ObjectListBEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), false);
    Entry = lookup_widget(ObjectListDialog, "ObjectListVEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), false);
    Entry = lookup_widget(ObjectListDialog, "ObjectListREntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), false);
    Entry = lookup_widget(ObjectListDialog, "ObjectListIEntry");
    gtk_entry_set_editable(GTK_ENTRY(Entry), false);
    ObjectListEditable = false;
  }
}

void on_ObjectListCancelButton_clicked(GtkButton *button, gpointer user_data)
{
  gtk_widget_hide(ObjectListDialog);
  return;
}


void on_DownLoadingCancelButton_clicked(GtkButton *button, gpointer user_data)
{
  DownLoadCancel = true;
  gtk_widget_hide(DownLoadingDialog);
}




void on_SeriesSettingsStartASAPButton_toggled(GtkToggleButton *togglebutton,
					      gpointer user_data)
{
  char buffer[40];
  time_t now;
  struct tm *broken_time;
  GtkWidget *Entry;

  StartSeriesASAP = ! StartSeriesASAP;
  if (StartSeriesASAP) {
    time(&now);
    broken_time = localtime(&now);
    seriesSettings.startHours = broken_time->tm_hour +
      broken_time->tm_min/60.0 + broken_time->tm_sec/3600.0;
    sprintf(buffer,"%5.2f", seriesSettings.startHours);
    Entry = lookup_widget(seriesSettings_dialog, 
			  "SeriesSettingsStartEntry");
    gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
  }
}

void on_MainSeriesPauseButton_clicked(GtkButton *button,
				      gpointer user_data)
{
  if (! SeriesStarted) return;
  PauseSeries = true;
}


void on_MainSeriesResumeButton_clicked(GtkButton *button,
				       gpointer user_data)
{
  if (! SeriesStarted) return;
  PauseSeries = false;
}

void on_expose_dark_frames_activate(GtkMenuItem *menuitem,
				    gpointer user_data)
{
  char buffer[80];
  GtkWidget *entry, *Button;

  /* Create dialog if not already created */

  if (DarkFrameSettingsDialog == NULL) {
    DarkFrameSettingsDialog = create_DarkFrameSettings();
  }

  /* Save current settings in case "cancel" button hit */

  memcpy(&darkFrameSettings_Save,&darkFrameSettings,
	 sizeof(darkFrameSettings));

  /* Update the dialog values */

     /* Which ccd */

  if (ccd->make != SBIG_MAKE) {
    Button = lookup_widget(DarkFrameSettingsDialog,
			   "DarkFrameSettingsTrackingButton");
    gtk_widget_hide(Button);
    Button = lookup_widget(DarkFrameSettingsDialog,
			   "DarkFrameSettingsImagingButton");
    gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				 check_button.toggle_button,true);
  } else {
    Button = lookup_widget(DarkFrameSettingsDialog,
			   "DarkFrameSettingsTrackingButton");
    gtk_widget_show(Button);
    if (darkFrameSettings.whichCCD == 1)
      gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				   check_button.toggle_button,true);
    else
      gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				   check_button.toggle_button,false);
  }

     /* Binning */

  switch (darkFrameSettings.binning) {
    case 0:
      Button = lookup_widget(DarkFrameSettingsDialog,
			     "DarkFrameSettings1x1Button");
      break;
    case 1:
      Button = lookup_widget(DarkFrameSettingsDialog,
			     "DarkFrameSettings2x2Button");
      break;
    case 2:
      Button = lookup_widget(DarkFrameSettingsDialog,
			     "DarkFrameSettings3x3Button");
      break;
  }
  gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
			       check_button.toggle_button,true);

  /* Frame size */

  entry = lookup_widget(DarkFrameSettingsDialog,
			       "DarkFrameSettingsImageDirEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), darkFrameSettings.imageDir);

  entry = lookup_widget(DarkFrameSettingsDialog,
			       "DarkFrameSettingsFrameSizeEntry");
  sprintf(buffer,"%d, %d, %d, %d", darkFrameSettings.x, darkFrameSettings.y,
	  darkFrameSettings.h, darkFrameSettings.w);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);

  entry = lookup_widget(DarkFrameSettingsDialog,
			       "DarkFrameSettingsNumFramesEntry");
  sprintf(buffer,"%d", darkFrameSettings.numFrames);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);

  entry = lookup_widget(DarkFrameSettingsDialog,
			       "DarkFrameSettingsExpTimeEntry");
  sprintf(buffer,"%f", darkFrameSettings.exposureTime);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);

  /* Show dialog */

  gtk_widget_show(DarkFrameSettingsDialog);
}


void on_expose_flat_frames_activate(GtkMenuItem *menuitem,
				    gpointer user_data)
{
  char buffer[80], name[80], darkOption[80];
  int i, buttonState;
  GtkWidget *entry, *Button;

  /* Create dialog if not already created */

  if (FlatFrameSettingsDialog == NULL) {
    FlatFrameSettingsDialog = create_FlatFrameSettings();
  }

  /* Save current settings in case "cancel" button hit */

  memcpy(&flatFrameSettings_Save,&flatFrameSettings,
	 sizeof(flatFrameSettings));

  /* Update the dialog values */

     /* Which ccd */

  if (ccd->make != SBIG_MAKE) {
    Button = lookup_widget(FlatFrameSettingsDialog,
			   "FlatFrameSettingsTrackingButton");
    gtk_widget_hide(Button);
    Button = lookup_widget(FlatFrameSettingsDialog,
			   "FlatFrameSettingsImagingButton");
    gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				 check_button.toggle_button,true);
  } else {
    Button = lookup_widget(FlatFrameSettingsDialog,
			   "FlatFrameSettingsTrackingButton");
    gtk_widget_show(Button);
    if (flatFrameSettings.whichCCD == 1)
      gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				   check_button.toggle_button,true);
    else
      gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				   check_button.toggle_button,false);
  }

     /* Binning */

  switch (flatFrameSettings.binning) {
    case 0:
      Button = lookup_widget(FlatFrameSettingsDialog,
			     "FlatFrameSettings1x1Button");
      break;
    case 1:
      Button = lookup_widget(FlatFrameSettingsDialog,
			     "FlatFrameSettings2x2Button");
      break;
    case 2:
      Button = lookup_widget(FlatFrameSettingsDialog,
			     "FlatFrameSettings3x3Button");
      break;
  }
  gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
			       check_button.toggle_button,true);

  /* Set dark frame option */

  entry = lookup_widget(FlatFrameSettingsDialog,
			     "FlatFrameSettingsDarkComboEntry");

  switch (flatFrameSettings.darkOption) {
    case 1:
      strcpy(darkOption,"Reuse old dark frame");
      break;
    case 2:
      strcpy(darkOption,"Force new dark frame");
      break;
    case 3:
      strcpy(darkOption,"Use dark frame from file");
      break;
    case 4:
      strcpy(darkOption,"Don't do dark subtract");
      break;
  }
  gtk_entry_set_text(GTK_ENTRY(entry), darkOption);
  entry = lookup_widget(FlatFrameSettingsDialog,
			     "FlatFrameSettingsDarkNameEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), flatFrameSettings.DarkDir);

  /* Set the filter sequence */

  for (i=0; i<NUMFILTERS; i++) {
    if (flatFrameSettings.filterSeq.Use[i]) {
      sprintf(buffer,"%-6.2f",flatFrameSettings.filterSeq.exposures[i]);
      buttonState = true;
    } else {
      strcpy(buffer," ");
      buttonState = false;
    }
    sprintf(name,"FlatFrameSettings%cButton",filterSet[i]);
    Button = lookup_widget(FlatFrameSettingsDialog, name);
    gtk_toggle_button_set_active(&(GTK_CHECK_BUTTON(Button))
				 ->toggle_button, buttonState);
    sprintf(name,"FlatFrameSettings%cExpEntry",filterSet[i]);
    entry = lookup_widget(FlatFrameSettingsDialog, name);
    gtk_entry_set_text(GTK_ENTRY(entry), buffer);
  } 

  if (flatFrameSettings.whichCCD == 0) {
    Button = lookup_widget(FlatFrameSettingsDialog,
			   "FlatFrameSettingsImagingButton");
    gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))
				 ->check_button.toggle_button, true);
  } else {
    Button = lookup_widget(FlatFrameSettingsDialog,
			   "FlatFrameSettingsImagingButton");
    gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))
				 ->check_button.toggle_button, false);
  }

  entry = lookup_widget(FlatFrameSettingsDialog,
			       "FlatFrameSettingsImageDirEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), flatFrameSettings.imageDir);

  entry = lookup_widget(FlatFrameSettingsDialog,
			       "FlatFrameSettingsFrameSizeEntry");
  sprintf(buffer,"%d, %d, %d, %d", flatFrameSettings.x, flatFrameSettings.y,
	  flatFrameSettings.h, flatFrameSettings.w);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);

  entry = lookup_widget(FlatFrameSettingsDialog,
			       "FlatFrameSettingsNumFramesEntry");
  sprintf(buffer,"%d", flatFrameSettings.numFrames);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);

  /* Show dialog */

  gtk_widget_show(FlatFrameSettingsDialog);

}


void on_DarkFrameSettingsOkay_clicked(GtkButton *button,
				      gpointer user_data)
{
  UpdateDarkFrameSettings();

  /* Hide Dialog */

  gtk_widget_hide(FlatFrameSettingsDialog);

  return;
}




void on_DarkFrameSettingsCancelButton_clicked(GtkButton *button,
					      gpointer user_data)
{
  gtk_widget_hide(DarkFrameSettingsDialog);

  /* Restore old settings */

  memcpy(&darkFrameSettings,&darkFrameSettings_Save,
	 sizeof(darkFrameSettings));
}


void on_DarkFrameSettingsExecButton_clicked (GtkButton *button,
					     gpointer user_data)
{
  int i, iframe, sumd;
  int d[MAXNUMDARKS], m;
  int numFrames, nrows, ncols, npixels, nbytes;
  IMAGE darkFrames[MAXNUMDARKS], *iptr;
  StartExposureParams expose;
  StartReadoutParams readout;
  char Message[80], FileName[160];
  gchar *buffer;
  GtkWidget *Entry;

  /* Hide the dialog */

  gtk_widget_hide(DarkFrameSettingsDialog);

  /* Get settings not already gotten */

  Entry = lookup_widget(DarkFrameSettingsDialog,
			       "DarkFrameSettingsFrameSizeEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%d, %d, %d, %d",
	 &darkFrameSettings.x, &darkFrameSettings.y,
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

  /* Check if linked to camera */

  if (!ccd->Linked) {
    sprintf(Message,"Can't start dark frames, link to camera first.\n");
    StatusPrint(Message);
    return;
  }

  /* Init frames */

  numFrames = darkFrameSettings.numFrames;
  nrows = darkFrameSettings.h;
  ncols = darkFrameSettings.w;
  npixels = nrows*ncols;
  nbytes = npixels * sizeof(unsigned short);
  for (iframe=0; iframe<numFrames; iframe++) {
    iptr = &darkFrames[iframe];
    strcpy(iptr->Filter, "C");
    strcpy(iptr->FileName,"");
    strcpy(iptr->ObjectName,"Dark");
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
    if (iptr->dark_frame.frame == NULL) {
      sprintf(Message, "Can't allocate memory for dark frame %d...",
	      iframe);
      return;
    }
  }

  /* Allocate memory for final (combined) dark frame */

  ccd->Image.dark_frame.frame = (unsigned short *)
    realloc(ccd->Image.dark_frame.frame, nbytes);
  
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

  for (iframe=0; iframe<numFrames; iframe++) {

    /* Expose dark */

    Entry = lookup_widget(CCDAutoSave,"MainExpNumEntry");
    sprintf(buffer,"%d", iframe);
    gtk_entry_set_text(GTK_ENTRY(Entry),buffer);

    iptr = &darkFrames[iframe];
    sprintf(Message,"Exposing dark frame #%d, %f sec.\n",
	    iframe, darkFrameSettings.exposureTime);
    StatusPrint(Message);
    CancelCurrentAcquire = false;
    snapImaging(ccd, &expose, &readout, iptr);
    if (CancelCurrentAcquire) {
      for (iframe=0; iframe<numFrames; iframe++)  /* Free dark frame memory */
	if (darkFrames[iframe].dark_frame.frame != NULL) {
	  free(darkFrames[iframe].dark_frame.frame);
	}
      return;
    }

    /* Display dark */
    

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
      sprintf(FileName,"%s/Dark%s_%d_%03d.fits", darkFrameSettings.imageDir,
	      binningString[iptr->dark_frame.binning], 
	      ((int)darkFrameSettings.exposureTime), iframe);
      strcpy(iptr->dark_frame.UT,"");
      strcpy(iptr->dark_frame.UTDATE,"");
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

  /* Free dark frame memory */

  for (iframe=0; iframe<numFrames; iframe++)
    if (darkFrames[iframe].dark_frame.frame != NULL) {
      free(darkFrames[iframe].dark_frame.frame);
    }

  /* Write out combined dark frame */

  sprintf(FileName,"%s/Dark%s_%d.fits", darkFrameSettings.imageDir,
	  binningString[ccd->Image.dark_frame.binning],
	  ((int)darkFrameSettings.exposureTime));
  strcpy(ccd->Image.dark_frame.UT,"");
  strcpy(ccd->Image.dark_frame.UTDATE,"");
  writeFITS(&ccd->Image, 2, FileName, "Dark");

  // Display combined dark frame

  iptr = &ccd->Image;
  loadImageImaging(iptr->dark_frame.frame, iptr->dark_frame.x,
		   iptr->dark_frame.y, iptr->dark_frame.w,
		   iptr->dark_frame.h, iptr->dark_frame.binning);
  
  return;
}

int imedian(int *data, int num)
{
  int max, i, j, jmax;
  int list[100], temp[100];

  memcpy(temp,data,num*sizeof(int));
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
  

void on_DarkFrameSettingsImagingButton_toggled(GtkToggleButton *togglebutton,
					       gpointer user_data)
{
  char buffer[80];
  GtkWidget *Imagebutton, *Entry;
  
  Imagebutton = lookup_widget(DarkFrameSettingsDialog,
			      "DarkFrameSettingsImagingButton");
  if (gtk_toggle_button_get_active(&(GTK_RADIO_BUTTON(Imagebutton))
				   ->check_button.toggle_button)) {
    darkFrameSettings.whichCCD = 0;
    GetCCDFrameSettings(ccd, &darkFrameSettings.x, &darkFrameSettings.y,
			&darkFrameSettings.w, &darkFrameSettings.h,
			&darkFrameSettings.binning);
  } else {
    darkFrameSettings.whichCCD = 1;
    if (ccd->make == SBIG_MAKE) {
      darkFrameSettings.whichCCD = 1;
      darkFrameSettings.x = darkFrameSettings.y = 0;
      darkFrameSettings.w = ccd->info1.readoutInfo[0].width;
      darkFrameSettings.h = ccd->info1.readoutInfo[0].height;
    } else {
      sprintf(buffer,"*** Warning - %s only has one ccd\n", ccd->name);
      StatusPrint(buffer);
    }
  }
  Entry = lookup_widget(DarkFrameSettingsDialog,
			"DarkFrameSettingsFrameSizeEntry");
  sprintf(buffer,"%d, %d, %d, %d", darkFrameSettings.x, darkFrameSettings.y,
	  darkFrameSettings.h, darkFrameSettings.w);
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);

}


void on_DarkFrameSettings1x1Button_toggled(GtkToggleButton *togglebutton,
					   gpointer user_data)
{
  char buffer[80];
  int iccd;
  GtkWidget *Entry;

  if (darkFrameSettings.binning != 0) {
    darkFrameSettings.binning = 0;
    iccd = darkFrameSettings.whichCCD;
    if (iccd == 0) {
      GetCCDFrameSettings(ccd, &darkFrameSettings.x, &darkFrameSettings.y,
			  &darkFrameSettings.w, &darkFrameSettings.h,
			  &darkFrameSettings.binning);
    } else {
      darkFrameSettings.w = ccd->info1.readoutInfo[0].width;
      darkFrameSettings.h = ccd->info1.readoutInfo[0].height;
    }
    Entry = lookup_widget(DarkFrameSettingsDialog,
			  "DarkFrameSettingsFrameSizeEntry");
    sprintf(buffer,"%d, %d, %d, %d", darkFrameSettings.x, darkFrameSettings.y,
	    darkFrameSettings.h, darkFrameSettings.w);
    gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
  }

}


void on_DarkFrameSettings2x2Button_toggled(GtkToggleButton *togglebutton,
					   gpointer user_data)
{
  char buffer[80];
  int iccd;
  GtkWidget *Entry;

  if (darkFrameSettings.binning != 1) {
    darkFrameSettings.binning = 1;
    iccd = darkFrameSettings.whichCCD;
    if (iccd == 0) {
      GetCCDFrameSettings(ccd, &darkFrameSettings.x, &darkFrameSettings.y,
			  &darkFrameSettings.w, &darkFrameSettings.h,
			  &darkFrameSettings.binning);
    } else {
      darkFrameSettings.w = ccd->info1.readoutInfo[1].width;
      darkFrameSettings.h = ccd->info1.readoutInfo[1].height;
    }
    Entry = lookup_widget(DarkFrameSettingsDialog,
			  "DarkFrameSettingsFrameSizeEntry");
    sprintf(buffer,"%d, %d, %d, %d", darkFrameSettings.x, darkFrameSettings.y,
	    darkFrameSettings.h, darkFrameSettings.w);
    gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
  }
}


void on_DarkFrameSettings3x3Button_toggled(GtkToggleButton *togglebutton,
					   gpointer user_data)
{
  static int Tried=false;
  char buffer[80];
  int iccd;
  GtkWidget *Trackbutton, *Entry;

  if (darkFrameSettings.binning != 2) {
    Trackbutton = lookup_widget(DarkFrameSettingsDialog,
				"DarkFrameSettingsTrackingButton");
    if (gtk_toggle_button_get_active(&(GTK_RADIO_BUTTON(Trackbutton))
				     ->check_button.toggle_button)) {
      if (! Tried) {
	StatusPrint("*** Warning - Can't do 3x3 binning with tracking ccd\n");
	Tried = true;
      } else
	Tried = false;
    } else {
      darkFrameSettings.binning = 2;
      iccd = darkFrameSettings.whichCCD;
      if (iccd == 0) {
	GetCCDFrameSettings(ccd, &darkFrameSettings.x, &darkFrameSettings.y,
			    &darkFrameSettings.w, &darkFrameSettings.h,
			    &darkFrameSettings.binning);
      } else {
	darkFrameSettings.w = ccd->info1.readoutInfo[2].width;
	darkFrameSettings.h = ccd->info1.readoutInfo[2].height;
      }
      Entry = lookup_widget(DarkFrameSettingsDialog,
			    "DarkFrameSettingsFrameSizeEntry");
      sprintf(buffer,"%d, %d, %d, %d", darkFrameSettings.x,
	      darkFrameSettings.y, darkFrameSettings.h, darkFrameSettings.w);
      gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
    }
  }
}


void on_DarkFrameSettingsMedian_toggled(GtkToggleButton *togglebutton,
                                        gpointer user_data)
{
  GtkWidget *Medianbutton;
  
  Medianbutton = lookup_widget(DarkFrameSettingsDialog,
			      "DarkFrameSettingsMedianButton");
  if (gtk_toggle_button_get_active(&(GTK_RADIO_BUTTON(Medianbutton))
				   ->check_button.toggle_button)) {
    darkFrameSettings.combineMethod = 1;
  } else {
    darkFrameSettings.combineMethod = 2;
  }
}

void on_FlatFrameSettingsImagingButton_toggled(GtkToggleButton *togglebutton,
					       gpointer user_data)
{
  char buffer[80];
  GtkWidget *Imagebutton, *Entry;
  
  Imagebutton = lookup_widget(FlatFrameSettingsDialog,
			      "FlatFrameSettingsImagingButton");
  if (gtk_toggle_button_get_active(&(GTK_RADIO_BUTTON(Imagebutton))
				   ->check_button.toggle_button)) {
    flatFrameSettings.whichCCD = 0;
    GetCCDFrameSettings(ccd, &flatFrameSettings.x, &flatFrameSettings.y,
			&flatFrameSettings.w, &flatFrameSettings.h,
			&flatFrameSettings.binning);
  } else {
    flatFrameSettings.whichCCD = 1;
    if (ccd->make == SBIG_MAKE) {
      flatFrameSettings.whichCCD = 1;
      flatFrameSettings.x = flatFrameSettings.y = 0;
      flatFrameSettings.w = ccd->info1.readoutInfo[0].width;
      flatFrameSettings.h = ccd->info1.readoutInfo[0].height;
    } else {
      sprintf(buffer,"*** Warning - %s only has one ccd\n", ccd->name);
      StatusPrint(buffer);
    }
  }
  Entry = lookup_widget(FlatFrameSettingsDialog,
			"FlatFrameSettingsFrameSizeEntry");
  sprintf(buffer,"%d, %d, %d, %d", flatFrameSettings.x, flatFrameSettings.y,
	  flatFrameSettings.h, flatFrameSettings.w);
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);

}


void on_FlatFrameSettings1x1Button_toggled(GtkToggleButton *togglebutton,
					   gpointer user_data)
{
  char buffer[80];
  int iccd;
  GtkWidget *Entry;

  if (flatFrameSettings.binning != 0) {
    flatFrameSettings.binning = 0;
    iccd = flatFrameSettings.whichCCD;
    if (iccd == 0) {
      GetCCDFrameSettings(ccd, &flatFrameSettings.x, &flatFrameSettings.y,
			  &flatFrameSettings.w, &flatFrameSettings.h,
			  &flatFrameSettings.binning);
    } else {
      flatFrameSettings.w = ccd->info1.readoutInfo[0].width;
      flatFrameSettings.h = ccd->info1.readoutInfo[0].height;
    }
    Entry = lookup_widget(FlatFrameSettingsDialog,
			  "FlatFrameSettingsFrameSizeEntry");
    sprintf(buffer,"%d, %d, %d, %d", flatFrameSettings.x, flatFrameSettings.y,
	    flatFrameSettings.h, flatFrameSettings.w);
    gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
  }
}


void on_FlatFrameSettings2x2Button_toggled(GtkToggleButton *togglebutton,
					   gpointer user_data)
{
  char buffer[80];
  int iccd;
  GtkWidget *Entry;

  if (flatFrameSettings.binning != 1) {
    flatFrameSettings.binning = 1;
    iccd = flatFrameSettings.whichCCD;
    if (iccd == 0) {
      GetCCDFrameSettings(ccd, &flatFrameSettings.x, &flatFrameSettings.y,
			  &flatFrameSettings.w, &flatFrameSettings.h,
			  &flatFrameSettings.binning);
    } else {
      flatFrameSettings.w = ccd->info1.readoutInfo[1].width;
      flatFrameSettings.h = ccd->info1.readoutInfo[1].height;
    }
    Entry = lookup_widget(FlatFrameSettingsDialog,
			  "FlatFrameSettingsFrameSizeEntry");
    sprintf(buffer,"%d, %d, %d, %d", flatFrameSettings.x, flatFrameSettings.y,
	    flatFrameSettings.h, flatFrameSettings.w);
    gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
  }
}


void on_FlatFrameSettings3x3Button_toggled(GtkToggleButton *togglebutton,
                                        gpointer user_data)
{
  static int Tried=false;
  char buffer[80];
  int iccd;
  GtkWidget *Trackbutton, *Entry;

  if (flatFrameSettings.binning != 2) {
    Trackbutton = lookup_widget(FlatFrameSettingsDialog,
				"FlatFrameSettingsTrackingButton");
    if (gtk_toggle_button_get_active(&(GTK_RADIO_BUTTON(Trackbutton))
				     ->check_button.toggle_button)) {
      if (! Tried) {
	StatusPrint("*** Warning - Can't do 3x3 binning with tracking ccd\n");
	Tried = true;
      } else
	Tried = false;
    } else {
      flatFrameSettings.binning = 2;
      iccd = flatFrameSettings.whichCCD;
      if (iccd == 0) {
	GetCCDFrameSettings(ccd, &flatFrameSettings.x, &flatFrameSettings.y,
			    &flatFrameSettings.w, &flatFrameSettings.h,
			    &flatFrameSettings.binning);
      } else {
	flatFrameSettings.w = ccd->info1.readoutInfo[2].width;
	flatFrameSettings.h = ccd->info1.readoutInfo[2].height;
      }
      Entry = lookup_widget(FlatFrameSettingsDialog,
			    "FlatFrameSettingsFrameSizeEntry");
      sprintf(buffer,"%d, %d, %d, %d", flatFrameSettings.x,
	      flatFrameSettings.y, flatFrameSettings.h, flatFrameSettings.w);
      gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
    }
  }
}


void on_FlatFrameSettingsMedian_toggled(GtkToggleButton *togglebutton,
                                        gpointer user_data)
{
  GtkWidget *Medianbutton;
  
  Medianbutton = lookup_widget(FlatFrameSettingsDialog,
			      "FlatFrameSettingsMedianButton");
  if (gtk_toggle_button_get_active(&(GTK_RADIO_BUTTON(Medianbutton))
				   ->check_button.toggle_button)) {
    flatFrameSettings.combineMethod = 1;
  } else {
    flatFrameSettings.combineMethod = 2;
  }
}


void on_FlatFrameSettingsUButton_toggled(GtkToggleButton *togglebutton,
					 gpointer user_data)
{
  GtkWidget *button;

  button = lookup_widget(FlatFrameSettingsDialog,
			 "FlatFrameSettingsUButton");
  if (gtk_toggle_button_get_active(&(GTK_CHECK_BUTTON(button))
				     ->toggle_button)) {
    flatFrameSettings.filterSeq.Use[0] = true;
  } else {
    flatFrameSettings.filterSeq.Use[0] = false;
  }
}


void on_FlatFrameSettingsBButton_toggled(GtkToggleButton *togglebutton,
					 gpointer user_data)
{
  GtkWidget *button;

  button = lookup_widget(FlatFrameSettingsDialog,
			 "FlatFrameSettingsBButton");
  if (gtk_toggle_button_get_active(&(GTK_CHECK_BUTTON(button))
				     ->toggle_button)) {
    flatFrameSettings.filterSeq.Use[1] = true;
  } else {
    flatFrameSettings.filterSeq.Use[1] = false;
  }
}


void on_FlatFrameSettingsVButton_toggled(GtkToggleButton *togglebutton,
					 gpointer user_data)
{
  GtkWidget *button;

  button = lookup_widget(FlatFrameSettingsDialog,
			 "FlatFrameSettingsVButton");
  if (gtk_toggle_button_get_active(&(GTK_CHECK_BUTTON(button))
				     ->toggle_button)) {
    flatFrameSettings.filterSeq.Use[2] = true;
  } else {
    flatFrameSettings.filterSeq.Use[2] = false;
  }
}


void on_FlatFrameSettingsRButton_toggled(GtkToggleButton *togglebutton,
					 gpointer user_data)
{
  GtkWidget *button;

  button = lookup_widget(FlatFrameSettingsDialog,
			 "FlatFrameSettingsRButton");
  if (gtk_toggle_button_get_active(&(GTK_CHECK_BUTTON(button))
				     ->toggle_button)) {
    flatFrameSettings.filterSeq.Use[3] = true;
  } else {
    flatFrameSettings.filterSeq.Use[3] = false;
  }

}


void on_FlatFrameSettingsIButton_toggled(GtkToggleButton *togglebutton,
					 gpointer user_data)
{
  GtkWidget *button;

  button = lookup_widget(FlatFrameSettingsDialog,
			 "FlatFrameSettingsIButton");
  if (gtk_toggle_button_get_active(&(GTK_CHECK_BUTTON(button))
				     ->toggle_button)) {
    flatFrameSettings.filterSeq.Use[4] = true;
  } else {
    flatFrameSettings.filterSeq.Use[4] = false;
  }
}

void on_FlatFrameSettingsCButton_toggled(GtkToggleButton *togglebutton,
					 gpointer user_data)
{
  GtkWidget *button;

  button = lookup_widget(FlatFrameSettingsDialog,
			 "FlatFrameSettingsCButton");
  if (gtk_toggle_button_get_active(&(GTK_CHECK_BUTTON(button))
				     ->toggle_button)) {
    flatFrameSettings.filterSeq.Use[5] = true;
  } else {
    flatFrameSettings.filterSeq.Use[5] = false;
  }
}


void on_FlatFrameSettingsOkay_clicked(GtkButton *button,
				      gpointer user_data)
{
  UpdateFlatFrameSettings();

  /* Hide Dialog */

  gtk_widget_hide(FlatFrameSettingsDialog);

  return;
}



void on_FlatFrameSettingsCancelButton_clicked(GtkButton *button,
					      gpointer user_data)
{
  gtk_widget_hide(FlatFrameSettingsDialog);

  /* Restore old settings */

  memcpy(&flatFrameSettings,&flatFrameSettings_Save,
	 sizeof(flatFrameSettings));
}


void on_FlatFrameSettingsExecButton_clicked(GtkButton *button,
					    gpointer user_data)
{
  unsigned short *saveptr;
  int i, iframe, sumd, ifilter, status, darkNeeded;
  int gotDark, pixval, success;
  int numFrames, nrows, ncols, npixels, nbytes;
  double sumpixval;
  int d[MAXNUMFLATS], m;
  float eTime, meanpixval, normpixval;
  FLATNODE *ffptr, *next;
  StartExposureParams expose;
  StartReadoutParams readout;
  char Message[80], FileName[160], *darkOption, name[80];
  char *darkDir;
  gchar *buffer;
  GtkWidget *Entry, *filterButton;
  double ccd_temp, dark_temp;

  /* Hide the dialog */

  gtk_widget_hide(FlatFrameSettingsDialog);

  /* Get settings not already gotten */

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
	    "*** Internal error - bad dark option: %s (FlatFrameExec)\n",
	    darkOption);
    StatusPrint(Message);
  }

  /* Get the filter sequence values */

  for (i=0; i<NUMFILTERS; i++) {
    sprintf(name,"FlatFrameSettings%cButton", filterSet[i]);
    filterButton = lookup_widget(FlatFrameSettingsDialog, name);
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(filterButton))) {
      flatFrameSettings.filterSeq.Use[i] = true;
      sprintf(name,"FlatFrameSettings%cExpEntry", filterSet[i]);
      Entry = lookup_widget(FlatFrameSettingsDialog, name);
      buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
      sscanf(buffer, "%f", &flatFrameSettings.filterSeq.exposures[i]);
    }
  }

  Entry = lookup_widget(FlatFrameSettingsDialog,
			       "FlatFrameSettingsFrameSizeEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%d, %d, %d, %d",
	 &flatFrameSettings.x, &flatFrameSettings.y,
	 &flatFrameSettings.h, &flatFrameSettings.w);

  Entry = lookup_widget(FlatFrameSettingsDialog,
			"FlatFrameSettingsNumFramesEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%d", &flatFrameSettings.numFrames);

  Entry = lookup_widget(FlatFrameSettingsDialog,
			       "FlatFrameSettingsImageDirEntry");
  strcpy(flatFrameSettings.imageDir,gtk_entry_get_text(GTK_ENTRY(Entry)));


  /* Set the dark frame settings */

  ccd->FlatImage.darkOnly = false;
  ccd->FlatImage.lightOnly = false;
  ccd->FlatImage.light_frame.binning = flatFrameSettings.binning;
  ccd->FlatImage.light_frame.whichCCD = flatFrameSettings.whichCCD;
  ccd->FlatImage.light_frame.x = flatFrameSettings.x;
  ccd->FlatImage.light_frame.y = flatFrameSettings.y;
  ccd->FlatImage.light_frame.w = flatFrameSettings.w;
  ccd->FlatImage.light_frame.h = flatFrameSettings.h;

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
    sprintf(Message,"Can't start flat frames, link to camera first.\n");
    StatusPrint(Message);
    return;
  }

  /* Init frames */

  numFrames = flatFrameSettings.numFrames;
  nrows = flatFrameSettings.h;
  ncols = flatFrameSettings.w;
  npixels = nrows*ncols;
  nbytes = npixels * sizeof(unsigned short);

  /* Allocate memory for final (combined) flat frame */

  ccd->FlatImage.dark_frame.frame = (unsigned short *)
    realloc(ccd->FlatImage.dark_frame.frame, nbytes);
  ccd->FlatImage.light_frame.frame = (unsigned short *)
    realloc(ccd->FlatImage.light_frame.frame, nbytes);

  /* If reusing dark frame, copy it from Image frame if active*/

  if ((flatFrameSettings.darkOption == 1) && (ccd->Image.dark_frame.active)) {
    saveptr = ccd->FlatImage.dark_frame.frame;
    memcpy(&ccd->FlatImage.dark_frame,&ccd->Image.dark_frame,
	   sizeof(FRAME));
    ccd->FlatImage.dark_frame.frame = saveptr;
    memcpy(ccd->FlatImage.dark_frame.frame,ccd->Image.dark_frame.frame,
	   nbytes);
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

  for (ifilter=0; ifilter<NUMFILTERS; ifilter++) {

    /* If filter not required, skip it */

    if (! flatFrameSettings.filterSeq.Use[ifilter])
      continue;

    /* Set the filter position */

    doFilterWheel(ccd, &status, ifilter+1);

    for (iframe=0; iframe<numFrames; iframe++) {

      /* Check if dark frame needed */

      Entry = lookup_widget(CCDAutoSave,"MainExpNumEntry");
      sprintf(Message,"%d", iframe);
      gtk_entry_set_text(GTK_ENTRY(Entry),Message);

      ccd_temp = 0.0;
      eTime = flatFrameSettings.filterSeq.exposures[ifilter];
      if ((flatFrameSettings.darkOption == 1) ||
	  (flatFrameSettings.darkOption == 3)) {
	success = GetCCDTemperature(ccd, &ccd_temp);
	if (! success) {
	  StatusPrint("*** WARNING - Can't get ccd temperature, "
		      "aborting exposure...\n");
	  return;
	}
	ccd->FlatImage.light_frame.temp = ccd_temp;
      }
      if (flatFrameSettings.darkOption == 1) {
	dark_temp = ccd->FlatImage.dark_frame.temp;
	darkNeeded = ((fabs(dark_temp-ccd_temp) > MAXTEMPDIFF) ||
		      (! ccd->FlatImage.dark_frame.active) ||
		      (ccd->FlatImage.dark_frame.exposure != eTime) ||
		      (flatFrameSettings.binning !=
		       ccd->FlatImage.dark_frame.binning) ||
		      (flatFrameSettings.whichCCD !=
		       ccd->FlatImage.dark_frame.whichCCD) ||
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
	Entry = lookup_widget(FlatFrameSettingsDialog,
			      "FlatFrameSettingsDarkNameEntry");
	darkDir = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
	ccd->FlatImage.light_frame.exposure = eTime;
	gotDark = readDark(darkDir, &ccd->FlatImage);
	if (! gotDark) {
	  sprintf(Message,"*** Warning - Couldn't find compatible dark frame\n"
		  " in directory: %s, forcing dark frame\n",
		  flatFrameSettings.DarkDir);
	  StatusPrint(Message);
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
      if (CancelCurrentAcquire) {
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
	return;
      }

      /* subtract out the dark, and adjust the image if required */

      if (gotDark) {
	for (i = readout.width*readout.height; --i >= 0; ) {
	  pixval = ccd->FlatImage.light_frame.frame[i] -
	    ccd->FlatImage.dark_frame.frame[i];
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
      memcpy(ffptr->Image.light_frame.frame,ccd->FlatImage.light_frame.frame,
	     nbytes);
      ffptr->Image.dark_frame.frame = (unsigned short *) malloc(nbytes);
      memcpy(ffptr->Image.dark_frame.frame,ccd->FlatImage.dark_frame.frame,
	     nbytes);
      ffptr->Image.saved = false;
      ffptr->Image.Filter[0] = filterSet[ifilter];
      ffptr->Image.Filter[1] = '\000';

      /* Normalize flat using mean */

      sumpixval = 0.0;
      for (i = readout.width*readout.height; --i >= 0; ) {
	sumpixval += ffptr->Image.light_frame.frame[i];
      }
      meanpixval = sumpixval / (readout.width*readout.height);
      
      for (i = readout.width*readout.height; --i >= 0; ) {
	normpixval = ((float) ffptr->Image.light_frame.frame[i]) / meanpixval;
	if (normpixval > 6.0) {
	  //  StatusPrint("*** WARNING - Got > 6.0 while normalizing flat\n");
	  printf("*** WARNING - Got > 6.0 while normalizing flat (%f)\n",
		 normpixval);
	  normpixval = 6.0;
	}
	ffptr->Image.light_frame.frame[i] = ((int) (normpixval * 10000.0));
      }
      
      /* Display flat */
      
      loadImageImaging(ffptr->Image.light_frame.frame,
		 ffptr->Image.light_frame.x,
		 ffptr->Image.light_frame.y,ffptr->Image.light_frame.w,
		 ffptr->Image.light_frame.h,
		 ffptr->Image.light_frame.binning);
      
      /* Save flat frame if required */

      if (SaveEachFlatFrame) {
	sprintf(FileName,"%s/Flat%s%c%03d.fits", flatFrameSettings.imageDir,
		binningString[ffptr->Image.light_frame.binning],
		filterSet[ifilter], iframe);
	strcpy(ffptr->Image.light_frame.UT,"");
	strcpy(ffptr->Image.light_frame.UTDATE,"");
	writeFITS(&ffptr->Image, 1, FileName, "flat");
      }

      /* Save dark frame if required */

      if ((FlatSaveEachDarkFrame) && (flatFrameSettings.darkOption != 4)) {
	sprintf(FileName,"%s/Dark%s%c%03d.fits", flatFrameSettings.imageDir,
		binningString[ffptr->Image.dark_frame.binning],
		filterSet[ifilter],iframe);
	strcpy(ffptr->Image.dark_frame.UT,"");
	strcpy(ffptr->Image.dark_frame.UTDATE,"");
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

    sprintf(FileName,"%s/Flat%s%c.fits", flatFrameSettings.imageDir,
	    binningString[flatFrameSettings.binning], filterSet[ifilter]);
    strcpy(ccd->FlatImage.light_frame.UT,"");
    strcpy(ccd->FlatImage.light_frame.UTDATE,"");
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
    ccd->Image.dark_frame.frame = (unsigned short *)
      realloc(ccd->Image.dark_frame.frame, nbytes);
    saveptr = ccd->Image.dark_frame.frame;
    memcpy(&ccd->Image.dark_frame,&ccd->FlatImage.dark_frame,
	   sizeof(FRAME));
    ccd->Image.dark_frame.frame = saveptr;
    memcpy(ccd->Image.dark_frame.frame,ccd->FlatImage.dark_frame.frame,
	   nbytes);
  }

  /* Display combined flat */

  loadImageImaging(ccd->Image.light_frame.frame,
		   ccd->Image.light_frame.x,
		   ccd->Image.light_frame.y,ccd->FlatImage.light_frame.w,
		   ccd->Image.light_frame.h,
		   ccd->Image.light_frame.binning);

  return;
}

void on_SingleSettingsSaveDarkButton_toggled(GtkToggleButton *togglebutton,
					     gpointer user_data)
{
  if (gtk_toggle_button_get_active(togglebutton)) {
    SingleSaveEachDarkFrame = true;
  } else {
    SingleSaveEachDarkFrame = false;
  }
}


void on_SeriesSettingsDarkSaveButton_toggled(GtkToggleButton *togglebutton,
					     gpointer user_data)
{
  if (gtk_toggle_button_get_active(togglebutton)) {
    SeriesSaveEachDarkFrame = true;
  } else {
    SeriesSaveEachDarkFrame = false;
  }
}


void on_DarkFrameSettingsSaveDarkButton_toggled(GtkToggleButton *togglebutton,
						gpointer user_data)
{
  if (gtk_toggle_button_get_active(togglebutton)) {
    DarkSaveEachDarkFrame = true;
  } else {
    DarkSaveEachDarkFrame = false;
  }
}


void on_FlatFrameSettingsSaveFlatButton_toggled(GtkToggleButton *togglebutton,
						gpointer user_data)
{
  if (gtk_toggle_button_get_active(togglebutton)) {
    SaveEachFlatFrame = true;
  } else {
    SaveEachFlatFrame = false;
  }
}


void on_FlatFrameSettingsSaveDarkButton_toggled(GtkToggleButton *togglebutton,
						gpointer user_data)
{
  if (gtk_toggle_button_get_active(togglebutton)) {
    FlatSaveEachDarkFrame = true;
  } else {
    FlatSaveEachDarkFrame = false;
  }
}

void flattenFrame(FRAME *light, FRAME *flat)
{
  int ipix, npixels;

  npixels = flat->h*flat->w;

  /* Flatten light frame */

  for (ipix=0; ipix<npixels; ipix++) {
    light->frame[ipix] =  (unsigned short)
      rint(light->frame[ipix]/(((float)flat->frame[ipix])/10000.0));
  }

  /* Remove "hot" pixels */

  removeHotPixels(light);

  return;
}

void on_OpenFileOkayButton_clicked(GtkButton *button, 
				   gpointer user_data)
{
  char *bptr;

  gtk_widget_hide(OpenFileDialog);

  bptr = (char *) gtk_file_selection_get_filename(GTK_FILE_SELECTION(OpenFileDialog));
  strcpy(CurrentImageFileName, bptr);

  /* read in light frame */

  readLight(bptr, &ccd->Image);

  removeHotPixels(&ccd->Image.light_frame);

  /* display light frame */

  loadImageImaging(ccd->Image.light_frame.frame, ccd->Image.light_frame.x,
		   ccd->Image.light_frame.y, ccd->Image.light_frame.w,
		   ccd->Image.light_frame.h, ccd->Image.light_frame.binning);


  ccd->Image.saved = true;
  updateStatusInfo(dummy);
  return;
}


void on_OpenFileCancelButton_clicked(GtkButton *button,
				     gpointer user_data)
{
  gtk_widget_hide(OpenFileDialog);
  return;
}


void on_SeriesSettingsCancelButton_clicked(GtkButton *button,
					   gpointer user_data)
{
  gtk_widget_hide(seriesSettings_dialog);
  return;
}

void on_observatory_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  char buffer[80];
  GtkWidget *Entry, *but;

  if (ObsSettingsDialog == NULL) {
    ObsSettingsDialog = create_ObservatorySettingsDialog();
  }

  /* Save previous settings in case of cancel button */

  memcpy(&ObsSettings_Save, &ObsSettings, sizeof(OBSSETTINGS));

  /* Update Dialog settings */

  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsNameEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry),ObsSettings.name);
  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsLatEntry");
  sprintf(buffer,"%f", ObsSettings.latitude);
  gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsLongEntry");
  sprintf(buffer,"%f", ObsSettings.longitude);
  gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsElevEntry");
  sprintf(buffer,"%7.1f",ObsSettings.elevation);
  gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsTimZonEntry");
  sprintf(buffer,"%d",ObsSettings.TimeZone);
  gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsObserverEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry),ObsSettings.Observer);
  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsProjectEntry");
  gtk_entry_set_text(GTK_ENTRY(Entry),ObsSettings.Project);

  but = lookup_widget(ObsSettingsDialog,"ObsSettingsDaySavButton");
  if (ObsSettings.DaylightSavings) {
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(but),true);
  } else {
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(but),true);
  }

  gtk_widget_show(ObsSettingsDialog);
  return;
}


void on_ObsSettingsOKButton_clicked(GtkButton *button, gpointer user_data)
{
  gchar *bptr;
  GtkWidget *Entry, *but;

  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsNameEntry");
  bptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(ObsSettings.name, bptr);

  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsLatEntry");
  bptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bptr, "%f", &ObsSettings.latitude);

  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsLongEntry");
  bptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bptr, "%f", &ObsSettings.longitude);

  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsElevEntry");
  bptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bptr,"%f",&ObsSettings.elevation);

  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsTimZonEntry");
  bptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bptr,"%d",&ObsSettings.TimeZone);
  
  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsObserverEntry");
  bptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(ObsSettings.Observer, bptr);

  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsProjectEntry");
  bptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(ObsSettings.Project, bptr);

  but = lookup_widget(ObsSettingsDialog,"ObsSettingsDaySavButton");
  ObsSettings.DaylightSavings =
    gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(but));
  
  gtk_widget_hide(ObsSettingsDialog);
  updateStatusInfo(dummy);
}


void on_ObsSettingsApplyButton_clicked(GtkButton *button, gpointer user_data)
{
  char *bptr;
  GtkWidget *Entry, *but;

  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsNameEntry");
  bptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(ObsSettings.name, bptr);

  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsLatEntry");
  bptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bptr, "%f", &ObsSettings.latitude);

  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsLongEntry");
  bptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bptr, "%f", &ObsSettings.longitude);

  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsElevEntry");
  bptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bptr,"%f",&ObsSettings.elevation);

  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsTimZonEntry");
  bptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bptr,"%d",&ObsSettings.TimeZone);

  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsObserverEntry");
  bptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(ObsSettings.Observer, bptr);

  Entry = lookup_widget(ObsSettingsDialog,"ObsSettingsProjectEntry");
  bptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(ObsSettings.Project, bptr);

  but = lookup_widget(ObsSettingsDialog,"ObsSettingsDaySavButton");
  ObsSettings.DaylightSavings =
    gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(but));
  }


void on_ObsSettingsCancelButton_clicked(GtkButton *button, gpointer user_data)
{
  memcpy(&ObsSettings,&ObsSettings_Save, sizeof(OBSSETTINGS));
  gtk_widget_hide(ObsSettingsDialog);
  return;
}


void on_OverWriteYesButton_clicked(GtkButton *button, gpointer user_data)
{
  char *bptr;

  bptr = (char *) gtk_file_selection_get_filename(
		   GTK_FILE_SELECTION(SaveCurrentImageDialog));
  unlink(bptr);
  writeFITS(&ccd->Image, 1, bptr, singleSettings.ObjectName);
  gtk_widget_hide(OverWriteDialog);
  return;
}


void on_OverWriteNoButton_clicked(GtkButton *button, gpointer user_data)
{
  gtk_widget_hide(OverWriteDialog);
  gtk_widget_show(SaveCurrentImageDialog);
  return;
}


void on_OverWriteCancelButton_clicked(GtkButton *button, gpointer user_data)
{
  gtk_widget_hide(OverWriteDialog);
  return;
}


void on_expose_stack_frames1_activate(GtkMenuItem *menuitem,
				      gpointer user_data)
{
  char buffer[80];
  GtkWidget *entry, *Button;

  /* Create dialog if not already created */

  if (StackSettingsDialog == NULL) {
    StackSettingsDialog = create_StackSettingsDialog();
  }

  /* Save current settings in case "cancel" button hit */

  memcpy(&stackSettings_Save,&stackSettings,
	 sizeof(stackSettings));

  /* Update the dialog values */

     /* Which ccd */

  if (ccd->make != SBIG_MAKE) {
    Button = lookup_widget(StackSettingsDialog,
			   "StackSettingsTrackingButton");
    gtk_widget_hide(Button);
    Button = lookup_widget(StackSettingsDialog,
			   "StackSettingsImagingButton");
    gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				 check_button.toggle_button,true);
  } else {
    Button = lookup_widget(StackSettingsDialog,
			   "StackSettingsTrackingButton");
    gtk_widget_show(Button);
    if (stackSettings.whichCCD == 1)
      gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				   check_button.toggle_button,true);
    else
      gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
				   check_button.toggle_button,false);
  }

     /* Binning */

  switch (stackSettings.binning) {
    case 0:
      Button = lookup_widget(StackSettingsDialog,
			     "StackSettings1x1Button");
      break;
    case 1:
      Button = lookup_widget(StackSettingsDialog,
			     "StackSettings2x2Button");
      break;
    case 2:
      Button = lookup_widget(StackSettingsDialog,
			     "StackSettings3x3Button");
      break;
  }

  gtk_toggle_button_set_active(&(GTK_RADIO_BUTTON(Button))->
			       check_button.toggle_button,true);
  entry = lookup_widget(StackSettingsDialog,
			       "StackSettingsImageDirEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), stackSettings.imageDir);

  entry = lookup_widget(StackSettingsDialog,
			       "StackSettingsFrameSizeEntry");
  sprintf(buffer,"%d, %d, %d, %d", stackSettings.x, stackSettings.y,
	  stackSettings.h, stackSettings.w);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);

  entry = lookup_widget(StackSettingsDialog,
			       "StackSettingsNumFramesEntry");
  sprintf(buffer,"%d", stackSettings.numFrames);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);

  entry = lookup_widget(StackSettingsDialog,
			       "StackSettingsExpTimeEntry");
  sprintf(buffer,"%f", stackSettings.exposureTime);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);

  entry = lookup_widget(StackSettingsDialog,
			       "StackSettingsImageDirEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), stackSettings.imageDir);

  /* Show dialog */

  gtk_widget_show(StackSettingsDialog);

}


void on_StackSettingsSaveDarkButton_toggled(GtkToggleButton *togglebutton,
					    gpointer user)
{
  if (gtk_toggle_button_get_active(togglebutton)) {
    StackSaveEachDarkFrame = true;
  } else {
    StackSaveEachDarkFrame = false;
  }
}


void on_StackSettingsSaveLightButton_toggled(GtkToggleButton *togglebutton,
					     gpointer user_data)
{
  if (gtk_toggle_button_get_active(togglebutton)) {
    StackSaveEachLightFrame = true;
  } else {
    StackSaveEachLightFrame = false;
  }
}

void on_StackSettingsOkayButton_clicked(GtkButton *button, gpointer user_data)
{
  UpdateStackSettings();

  /* Hide the dialog */

  gtk_widget_hide(StackSettingsDialog);

  return;
}



void on_StackSettingsCancelButton_clicked(GtkButton *button,
					  gpointer user_data)
{
  gtk_widget_hide(StackSettingsDialog);

  /* Restore old settings */

  memcpy(&stackSettings,&stackSettings_Save,
	 sizeof(stackSettings));
}

void on_StackSettingsExecButton_clicked(GtkButton *button, gpointer user_data)
{
  int status, i, d, nbytes, darkNeeded, gotDark, gotFlat;
  int FirstFrame, numFrames, offsetX, offsetY;
  int found, iFrame, success;
  char Message[80], *buffer, *Option, *darkOption;
  float starX, starY;
  double ccd_temp, dark_temp;
  StartExposureParams expose;
  StartReadoutParams readout;
  IMAGE workingImage;
  unsigned short *saveptr;
  GtkWidget *Entry;

  i = 0;
  workingImage.light_frame.frame = NULL;
  workingImage.dark_frame.frame = NULL;

  gtk_widget_hide(StackSettingsDialog);

  if (!ccd->Linked) {
    StatusPrint("Can't start exposure, link to camera first.\n");
    return;
  } 

  /* If previous image not saved, ask if want to save */

  if (! ccd->Image.saved) {
  }

  /* Get settings not already gotten */

  Entry = lookup_widget(StackSettingsDialog,
			       "StackSettingsFrameSizeEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%d, %d, %d, %d",
	 &stackSettings.x, &stackSettings.y,
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

     /* Get dark frame option */

  Entry = lookup_widget(StackSettingsDialog,
			     "StackSettingsDarkComboEntry");
  darkOption = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  if (strcmp(darkOption,"Reuse old dark frame") == 0) {
    stackSettings.darkOption = 1;
  } else if (strcmp(darkOption,"Force new dark frame") == 0) {
    stackSettings.darkOption = 2;
  } else if (strcmp(darkOption,"Use dark frame from file") == 0) {
    stackSettings.darkOption = 3;
  } else if (strcmp(darkOption,"Don't do dark subtract") == 0) {
    stackSettings.darkOption = 4;
  } else {
    sprintf(Message,
	    "*** Internal error - bad dark option: %s (StackExec)\n",
	    darkOption);
    StatusPrint(Message);
  }
  Entry = lookup_widget(StackSettingsDialog,
			     "StackSettingsDarkNameEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(stackSettings.DarkDir, buffer);

     /* Get flat frame option */

  Entry = lookup_widget(StackSettingsDialog,
			     "StackSettingsFlatComboEntry");
  Option = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  if (strcmp(Option,"Do not do flat fielding") == 0) {
    stackSettings.flatOption = 1;
  } else if (strcmp(Option,"Use curent flat field") == 0) {
    stackSettings.flatOption = 2;
  } else if (strcmp(Option,"Use flat field from file") == 0) {
    stackSettings.flatOption = 3;
  } else {
    sprintf(Message, "*** Internal error - bad flat option: %s"
	    " (StackExec)\n", Option);
    StatusPrint(Message);
  }
  Entry = lookup_widget(StackSettingsDialog,
			     "StackSettingsFlatNameEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(stackSettings.FlatDir, buffer);

  /* Init expose & readout structures */

  expose.ccd = stackSettings.whichCCD;
  expose.exposureTime = ((int) (100.0*stackSettings.exposureTime));
  expose.abgState = 0;
  readout.ccd = expose.ccd;
  readout.readoutMode = singleSettings.binning;
  readout.left = singleSettings.x;
  readout.top = singleSettings.y;
  readout.width = singleSettings.w;
  readout.height = singleSettings.h;

  /* Get temperature & camera status */

  success = GetCCDTemperature(ccd, &ccd_temp);
  if (! success) {
    StatusPrint("*** WARNING - Can't get ccd temperature, "
		"aborting exposure...\n");
    return;
  }
  ccd->Image.darkOnly = false;
  ccd->Image.lightOnly = false;
  ccd->Image.light_frame.binning = stackSettings.binning;
  ccd->Image.light_frame.whichCCD = stackSettings.whichCCD;
  ccd->Image.light_frame.x = stackSettings.x;
  ccd->Image.light_frame.y = stackSettings.y;
  ccd->Image.light_frame.w = stackSettings.w;
  ccd->Image.light_frame.h = stackSettings.h;
  ccd->Image.light_frame.temp = ccd_temp;
  ccd->Image.light_frame.exposure = stackSettings.exposureTime;
  ccd->Image.Filter[0] = filterSet[ccd->filterPosition-1];
  ccd->Image.Filter[1] = '\000';
  dark_temp = ccd->Image.dark_frame.temp;
  strcpy(ccd->Image.light_frame.UT,"");
  strcpy(ccd->Image.light_frame.UTDATE,"");
  strcpy(ccd->Image.dark_frame.UT,"");
  strcpy(ccd->Image.dark_frame.UTDATE,"");

  /* Copy settings into working image */

  memcpy(&workingImage, &ccd->Image, sizeof(IMAGE));
  workingImage.light_frame.frame = NULL;
  workingImage.dark_frame.frame = NULL;
  
  /* allocate buffers */

     /* allocate buffers for final "stacked" image */

  nbytes = readout.width*readout.height*sizeof(short);
  ccd->Image.light_frame.frame = (unsigned short *)
    realloc(ccd->Image.light_frame.frame, nbytes);
  ccd->Image.dark_frame.frame = (unsigned short *)
    realloc(ccd->Image.dark_frame.frame, nbytes);

     /* allocate buffers for single "working" image */

  workingImage.light_frame.frame = (unsigned short *)
    realloc(workingImage.light_frame.frame, nbytes);
  workingImage.dark_frame.frame = (unsigned short *)
    realloc(workingImage.dark_frame.frame, nbytes);

  gotDark = false;
  switch (stackSettings.darkOption) {
    case 1:
      gotDark = true;
      break;
    case 2:
      gotDark = false;
      ccd->Image.lightOnly = false;
      break;
    case 3:
      gotDark = readDark(stackSettings.DarkDir, &ccd->Image);
      if (! gotDark) {
	sprintf(Message,"*** Warning - Couldn't find compatible dark frame"
		"in directory: %s aborting\n", stackSettings.DarkDir);
	StatusPrint(Message);
	return;
      }
      saveptr = workingImage.dark_frame.frame;
      memcpy(&workingImage.dark_frame,&ccd->Image.dark_frame,
	     sizeof(FRAME));
      workingImage.dark_frame.frame = saveptr;
      memcpy(workingImage.dark_frame.frame, ccd->Image.dark_frame.frame,
	     nbytes);
      dark_temp = ccd->Image.dark_frame.temp;
      ccd->Image.lightOnly = true;
      break;
    case 4:
      gotDark = false;
      ccd->Image.lightOnly = true;
      break;
  }
  
  gotFlat = false;
  switch (stackSettings.flatOption) {
    case 1:
      gotFlat = false;
      break;
    case 2:
      if ((stackSettings.binning == ccd->FlatImage.light_frame.binning) &&
	  (stackSettings.whichCCD == ccd->FlatImage.light_frame.whichCCD) &&
	  (stackSettings.x == ccd->FlatImage.light_frame.x) &&
	  (stackSettings.y == ccd->FlatImage.light_frame.y) &&
	  (stackSettings.h == ccd->FlatImage.light_frame.h) &&
	  (stackSettings.w == ccd->FlatImage.light_frame.w)) {
	gotFlat = true;
      } else {
	sprintf(Message, "*** Warning - current flat frame not compatible"
		" with current settings\n");
	StatusPrint(Message);
	gotFlat = false;
      }
      break;
    case 3:
      gotFlat = readFlat(stackSettings.FlatDir, ccd);
      if (! gotFlat) {
	sprintf(Message, "*** Warning - couldn't find compatible flat"
		" frame in directory: %s, aborting\n", stackSettings.FlatDir);
	StatusPrint(Message);
	return;
      }
      break;
  }

  /* Main loop of requested number of frames */

  FirstFrame = true;
  numFrames = stackSettings.numFrames;

  for (iFrame=0; iFrame<numFrames; iFrame++) {
    
    Entry = lookup_widget(CCDAutoSave,"MainExpNumEntry");
    sprintf(buffer,"%d", iFrame+1);
    gtk_entry_set_text(GTK_ENTRY(Entry),buffer);

    /* Check if dark frame needed */

    if ((stackSettings.darkOption == 1) ||
	(stackSettings.darkOption == 3)) {
      darkNeeded = ((fabs(dark_temp-ccd_temp) > MAXTEMPDIFF) ||
		    (! ccd->Image.dark_frame.active) ||
		    (ccd->Image.dark_frame.exposure !=
		     stackSettings.exposureTime) ||
		    (stackSettings.binning !=
		     ccd->Image.dark_frame.binning) ||
		    (stackSettings.whichCCD !=
		     ccd->Image.dark_frame.whichCCD) ||
		    (stackSettings.x != ccd->Image.dark_frame.x) ||
		    (stackSettings.y != ccd->Image.dark_frame.y) ||
		    (stackSettings.w != ccd->Image.dark_frame.w) ||
		    (stackSettings.h != ccd->Image.dark_frame.h));
      darkNeeded = (darkNeeded || (! gotDark)); /* gotdark set by option 3 */
      if (darkNeeded) {
	gotDark = true;
	workingImage.lightOnly = false;
      } else 
	workingImage.lightOnly = true;
    }
  
    /* Do exposure */

    sprintf(Message,"Exposing Frame #%d\n", iFrame+1);
    StatusPrint(Message);
    CancelCurrentAcquire = false;
    snapImaging(ccd, &expose, &readout, &workingImage);
    if (CancelCurrentAcquire) {
      free(workingImage.light_frame.frame);
      if (workingImage.dark_frame.frame != NULL) 
	free(workingImage.dark_frame.frame);
      return;
    }
    ccd_temp = workingImage.light_frame.temp;
    if (! workingImage.lightOnly) {
      saveptr = ccd->Image.dark_frame.frame;
      memcpy(&ccd->Image.dark_frame,&workingImage.dark_frame,
	     sizeof(FRAME));
      ccd->Image.dark_frame.frame = saveptr;
      memcpy(ccd->Image.dark_frame.frame, workingImage.dark_frame.frame,
	     nbytes);
      dark_temp = ccd->Image.dark_frame.temp;
    }

    /* subtract out the dark, and adjust the image if required */

    if (gotDark) {
      for (i = readout.width*readout.height; --i >= 0; ) {
	d = workingImage.light_frame.frame[i] -
	    workingImage.dark_frame.frame[i];
	if (d < 0)
	  d = 0;
	else if (d > 65535)
	  d = 65535;
	workingImage.light_frame.frame[i] = d;
      }
    }

    /* Flatten field if required */

    if (gotFlat) {
      flattenFrame(&workingImage.light_frame, &ccd->FlatImage.light_frame);
    }

    /* Align working image with stack and sum frames */

    if (FirstFrame) {
      memcpy(ccd->Image.light_frame.frame,workingImage.light_frame.frame,
	     nbytes);
      loadImageImaging(ccd->Image.light_frame.frame, ccd->Image.light_frame.x,
		       ccd->Image.light_frame.y, ccd->Image.light_frame.w,
		       ccd->Image.light_frame.h, ccd->Image.light_frame.binning);
      found = setAlignStar(&workingImage.light_frame, &starX, &starY);
      if (! found) {
	StatusPrint("Failed setting alignment star in 1st frame, aborting\n");
	free(workingImage.light_frame.frame);
	free(workingImage.dark_frame.frame);
	return;
      }
      FirstFrame = false;
    } else {
      found = findAlignStar(&workingImage.light_frame, starX, starY,
			    &offsetX, &offsetY);
      if (! found) {
	sprintf(Message,
		"Failed finding alignment star in frame #%d, aborting\n", i);
	StatusPrint(Message);
	free(workingImage.light_frame.frame);
	free(workingImage.dark_frame.frame);
	return;
      } else {
	sumFrames(&ccd->Image, &workingImage, offsetX, offsetY);
	ccd->Image.light_frame.exposure += stackSettings.exposureTime;
	Entry = lookup_widget(CurrentImageWindow,"CurrentImageXOffsetEntry");
	sprintf(Message,"%d", offsetX);
	gtk_entry_set_text(GTK_ENTRY(Entry), Message);
	Entry = lookup_widget(CurrentImageWindow,"CurrentImageYOffsetEntry");
	sprintf(Message,"%d", offsetY);
	gtk_entry_set_text(GTK_ENTRY(Entry), Message);
	ccd->Image.light_frame.active = true;
      }

      /* Display current sum Image */
      
      loadImageImaging(ccd->Image.light_frame.frame, ccd->Image.light_frame.x,
		       ccd->Image.light_frame.y, ccd->Image.light_frame.w,
		       ccd->Image.light_frame.h, ccd->Image.light_frame.binning);
    }

  }

  ccd->Image.saved = false;
  ccd->Image.Filter[0] = filterSet[ccd->filterPosition-1];
  ccd->Image.Filter[1] = '\000';
  strcpy(ccd->Image.FileName,"");
  strcpy(ccd->Image.ObjectName,stackSettings.ObjectName);

  free(workingImage.light_frame.frame);
  if (workingImage.dark_frame.frame != NULL) 
    free(workingImage.dark_frame.frame);

  return;

}


void on_CurrentWindowCloseButton_clicked(GtkButton *button, gpointer user_data)
{
  gtk_widget_hide(CurrentImageWindow);

  return;
}


void on_CurrentWindowPhotoButton_clicked(GtkButton *button, gpointer user_data)
{
  GtkWidget *widget;
  char buffer[80];

  if (PhotometrySettingsDialog == NULL) {
    PhotometrySettingsDialog = create_PhotometrySettingsDialog();
  }

  /* Set the dialog values from settings structure */

  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsAperRadEntry");
  sprintf(buffer,"%5.1f", photometrySettings.aperatureRadius);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsZeroPointEntry");
  sprintf(buffer,"%7.3f", photometrySettings.zeroPoint);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsFindRadEntry");
  sprintf(buffer,"%5.1f", photometrySettings.findRadius);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsMinPeakEntry");
  sprintf(buffer,"%5.1f", photometrySettings.minPeak);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsMinFWHMEntry");
  sprintf(buffer,"%5.1f", photometrySettings.minFWHM);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsSkyInnerRadEntry");
  sprintf(buffer,"%5.1f", photometrySettings.skyInnerRadius);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsSkyOuterRadEntry");
  sprintf(buffer,"%5.1f", photometrySettings.skyOuterRadius);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsSkySigmaCutEntry");
  sprintf(buffer,"%5.1f", photometrySettings.skySigmaCut);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsLogFileEntry");
  gtk_entry_set_text(GTK_ENTRY(widget), photometrySettings.logFileName);
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsPlotButton");
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget),
			       photometrySettings.plotResults);

  gtk_widget_show(PhotometrySettingsDialog);

  return;
}


gboolean on_CurrentImageDrawingArea_button_press_event(GtkWidget *widget,
						       GdkEventButton *event,
						       gpointer user_data)
{
  int xmin, ymin, xmax, ymax;
  float Magnitude, MagErr, SkyFlux, StarFlux, FWHM, x, y;
  int max, Found;
  GtkWidget *Entry;
  char buffer[80];

  if (event->button == 1) {
    if (PickAlignStarDialog == NULL)
      return false;
    sprintf(buffer,"%d", ((int) event->x));
    Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarBoxX1Entry");
    gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
    sprintf(buffer,"%d", ((int) event->y));
    Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarBoxY1Entry");
    gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
  } else if (event->button == 3) {
    xmin = (int) (event->x - photometrySettings.findRadius);
    if (xmin < 0)
      xmin = 0;
    ymin = (int) (event->y - photometrySettings.findRadius);
    if (ymin < 0)
      ymin = 0;
    xmax = (int) (event->x + photometrySettings.findRadius);
    if (xmax > ccd->Image.light_frame.w)
      xmax = ccd->Image.light_frame.w;
    ymax = (int) (event->y + photometrySettings.findRadius);
    if (ymax > ccd->Image.light_frame.h)
      ymax = ccd->Image.light_frame.h;
    Found = FindStar(&ccd->Image.light_frame, xmin, ymin, xmax, ymax,
		     &x, &y, &max);
    if (Found) {
      sprintf(buffer,"%f", x);
      Entry = lookup_widget(CurrentImageWindow,"CurrentImageStarXEntry");
      gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
      sprintf(buffer,"%f", y);
      Entry = lookup_widget(CurrentImageWindow,"CurrentImageStarYEntry");
      gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
      sprintf(buffer,"%d", max);
      Entry = lookup_widget(CurrentImageWindow,"CurrentImageStarMaxEntry");
      gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
      doPhotometry(&ccd->Image, x, y, max, &FWHM, &SkyFlux, &StarFlux,
		   &Magnitude, &MagErr);
      sprintf(buffer,"%6.2f", FWHM);
      Entry = lookup_widget(CurrentImageWindow,"CurrentImageStarFWHMEntry");
      gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
      sprintf(buffer,"%6.3f+/-%5.3f", Magnitude, MagErr);
      Entry = lookup_widget(CurrentImageWindow,"CurrentImageStarMagEntry");
      gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
      sprintf(buffer,"%8.0f", SkyFlux);
      Entry = lookup_widget(CurrentImageWindow,"CurrentImageSkyFluxEntry");
      gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
      sprintf(buffer,"%8.0f", StarFlux);
      Entry = lookup_widget(CurrentImageWindow,"CurrentImageStarFluxEntry");
      gtk_entry_set_text(GTK_ENTRY(Entry),buffer);

    }
  }
    
  return false;
}


gboolean on_CurrentImageDrawingArea_button_release_event(GtkWidget *widget,
							 GdkEventButton *event,
							 gpointer user_data)
{
  GtkWidget *Entry;
  char buffer[80];

  if (PickAlignStarDialog == NULL)
    return false;
  sprintf(buffer,"%d", ((int) event->x));
  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarBoxX2Entry");
  gtk_entry_set_text(GTK_ENTRY(Entry),buffer);

  sprintf(buffer,"%d", ((int) event->y));
  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarBoxY2Entry");
  gtk_entry_set_text(GTK_ENTRY(Entry),buffer);

  return false;
}


gboolean on_CurrentImageDrawingArea_configure_event(GtkWidget *widget,
						    GdkEventConfigure *event,
						    gpointer user_data)
{
  return false;
}


gboolean on_CurrentImageDrawingArea_expose_event(GtkWidget *widget,
						 GdkEventExpose *event,
						 gpointer user_data)
{
  if ((! ccd->Image.light_frame.active) &&
      (! ccd->Image.dark_frame.active))
    return true;
  gdk_draw_rgb_image(widget->window, widget->style->fg_gc[GTK_STATE_NORMAL],
		     0, 0, RGBw, RGBh, GDK_RGB_DITHER_MAX, RGBBuf, RGBw*3);
  return true;
}


gboolean on_CurrentImageDrawingArea_motion_notify_event(GtkWidget *widget,
							GdkEventMotion *event,
							gpointer user_data)
{
  char buffer[30];
  int i, j, pixel, x, y;
  GtkWidget *entry;

  i = ((int) event->x);
  j = ((int) event->y);
  x = ccd->Image.light_frame.x;
  y = ccd->Image.light_frame.y;
  x = 0;
  y = 0;

  entry = lookup_widget(CurrentImageWindow,"CurrentImageXEntry");
  sprintf(buffer,"%d", i);
  gtk_entry_set_text(GTK_ENTRY(entry),buffer);

  entry = lookup_widget(CurrentImageWindow,"CurrentImageYEntry");
  sprintf(buffer,"%d", j);
  gtk_entry_set_text(GTK_ENTRY(entry),buffer);

  entry = lookup_widget(CurrentImageWindow,"CurrentImageValueEntry");
  if (ccd->Image.light_frame.frame == NULL)
    return false;
  if ((i >= ccd->Image.light_frame.w+x)  || (i < x) ||
      (j >= ccd->Image.light_frame.h+y) || (j < y))
    return false;
  pixel = ccd->Image.light_frame.w * (j-y) + (i-x);
  sprintf(buffer,"%d", ccd->Image.light_frame.frame[pixel]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);

  return false;
}

void on_PickAlignStarOkButton_clicked(GtkButton *button, gpointer user_data)
{
  GtkWidget *Entry;
  char *bufptr;
  float x;

  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarXEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bufptr,"%f", &x);

  if (x < 0) {
    StatusPrint("Haven't picked an alignment star; 'drag' across star, then"
		"\nhit apply button...\n");
    return;
  } else {
    gtk_widget_hide(PickAlignStarDialog);
    AlignStarFound = true;
  }
  return;
}


void on_PickAlignStarApplyButton_clicked(GtkButton *button, gpointer user_data)
{
  GtkWidget *Entry;
  char *bufptr, buffer[80];
  float x, y;
  int x1, y1, x2, y2, max, Found;

  /* Search for alignment star in user specified region */

  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarBoxX1Entry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bufptr,"%d", &x1);
  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarBoxX2Entry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bufptr,"%d", &x2);
  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarBoxY1Entry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bufptr,"%d", &y1);
  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarBoxY2Entry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bufptr,"%d", &y2);

  Found = FindStar(&ccd->Image.light_frame, x1, y1, x2, y2, &x, &y, &max);
  if (! Found)
    return;

  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarXEntry");
  sprintf(buffer,"%7.2f", x);
  gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarYEntry");
  sprintf(buffer,"%7.2f", y);
  gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
  Entry = lookup_widget(PickAlignStarDialog,"PickAlignStarMaxEntry");
  sprintf(buffer,"%d", max);
  gtk_entry_set_text(GTK_ENTRY(Entry),buffer);

  return;
}

void on_PickAlignStarCancelButton_clicked(GtkButton *button,
					  gpointer user_data)
{
  CancelSetAlignStar = true;
  gtk_widget_hide(PickAlignStarDialog);
  return;
}


void on_CurrentWindowApplyButton_clicked(GtkButton *button,
					 gpointer user_data)
{
  UpdateImage();
  return;
}



void on_StackSettingsWhichCCDButton_toggled (GtkToggleButton *togglebutton,
					     gpointer user_data)
{
  char buffer[80];
  GtkWidget *Imagebutton, *Entry;

  Imagebutton = lookup_widget(StackSettingsDialog,
				  "StackSettingsWhichCCDImageButton");
  if (gtk_toggle_button_get_active(&(GTK_RADIO_BUTTON(Imagebutton))
				    ->check_button.toggle_button)) {
    stackSettings.whichCCD = 0;
    GetCCDFrameSettings(ccd, &stackSettings.x, &stackSettings.y,
			&stackSettings.w, &stackSettings.h,
			&stackSettings.binning);
  } else {
    stackSettings.whichCCD = 1;
    if (ccd->make == SBIG_MAKE) {
      stackSettings.whichCCD = 1;
      stackSettings.x = stackSettings.y = 0;
      stackSettings.w = ccd->info1.readoutInfo[0].width;
      stackSettings.h = ccd->info1.readoutInfo[0].height;
    } else {
      sprintf(buffer,"*** Warning - %s only has one ccd\n", ccd->name);
      StatusPrint(buffer);
    }
  }
  Entry = lookup_widget(StackSettingsDialog,
			"StackSettingsFrameSizeEntry");
  sprintf(buffer,"%d, %d, %d, %d", stackSettings.x, stackSettings.y,
	  stackSettings.h, stackSettings.w);
  gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
}


void on_StackSettings2x2Button_toggled(GtkToggleButton *togglebutton,
						 gpointer user_data)
{
  int iccd;
  char buffer[80];
  GtkWidget *Entry;

  if (stackSettings.binning != 1) {
    StatusPrint("Changing to 2x2 binning\n");
    stackSettings.binning = 1;
    iccd = stackSettings.whichCCD;
    if (iccd == 0) {
      GetCCDFrameSettings(ccd, &stackSettings.x, &stackSettings.y,
			  &stackSettings.w, &stackSettings.h,
			  &stackSettings.binning);
    } else {
      stackSettings.w = ccd->info1.readoutInfo[1].width;
      stackSettings.h = ccd->info1.readoutInfo[1].height;
    }
    Entry = lookup_widget(StackSettingsDialog,
			  "StackSettingsFrameSizeEntry");
    sprintf(buffer,"%d, %d, %d, %d", stackSettings.x, stackSettings.y,
	    stackSettings.h, stackSettings.w);
    gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
  }

}


void on_StackSettings1x1Button_toggled(GtkToggleButton *togglebutton,
						 gpointer user_data)
{
  int iccd;
  char buffer[80];
  GtkWidget *Entry;

  if (stackSettings.binning != 0) {
    StatusPrint("Changing to 1x1 binning\n");
    stackSettings.binning = 0;
    iccd = stackSettings.whichCCD;
    if (iccd == 0) {
      GetCCDFrameSettings(ccd, &stackSettings.x, &stackSettings.y,
			  &stackSettings.w, &stackSettings.h,
			  &stackSettings.binning);
    } else {
      stackSettings.w = ccd->info1.readoutInfo[0].width;
      stackSettings.h = ccd->info1.readoutInfo[0].height;
    }
    Entry = lookup_widget(StackSettingsDialog,
			  "StackSettingsFrameSizeEntry");
    sprintf(buffer,"%d, %d, %d, %d", stackSettings.x, stackSettings.y,
	    stackSettings.h, stackSettings.w);
    gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
  }

}


void on_StackSettings3x3Button_toggled(GtkToggleButton *togglebutton,
						 gpointer user_data)
{
  static int Tried=false;

  int iccd;
  char buffer[80];
  GtkWidget *Entry;
  GtkWidget *Trackbutton;

  if (stackSettings.binning != 2) {
    Trackbutton = lookup_widget(StackSettingsDialog,
				"StackSettingsTrackingButton");
    if (gtk_toggle_button_get_active(&(GTK_RADIO_BUTTON(Trackbutton))
				     ->check_button.toggle_button)) {
      if (! Tried) {
	StatusPrint("*** Warning - Can't do 3x3 binning with tracking ccd\n");
	Tried = true;
      } else
	Tried = false;
    } else {
      StatusPrint("Changing to 3x3 binning\n");
      stackSettings.binning = 2; 
      iccd = stackSettings.whichCCD;
      if (iccd == 0) {
	GetCCDFrameSettings(ccd, &stackSettings.x, &stackSettings.y,
			    &stackSettings.w, &stackSettings.h,
			    &stackSettings.binning);
      } else {
	stackSettings.w = ccd->info1.readoutInfo[2].width;
	stackSettings.h = ccd->info1.readoutInfo[2].height;
      }
      Entry = lookup_widget(StackSettingsDialog,
			    "StackSettingsFrameSizeEntry");
      sprintf(buffer,"%d, %d, %d, %d", stackSettings.x, stackSettings.y,
	      stackSettings.h, stackSettings.w);
      gtk_entry_set_text(GTK_ENTRY(Entry), buffer);
    }
  }
}

void on_ObjectListComboEntry_changed(GtkEditable *editable, gpointer user_data)
{
  gchar *name, buffer[20], Message[160];
  OBJECT obj;
  GtkWidget *comboEntry, *entry;

  /* select selects object from combo box */

  comboEntry = lookup_widget(ObjectListDialog,"ObjectListComboEntry");
  name = (gchar *) gtk_entry_get_text(GTK_ENTRY(comboEntry));
  if (! GetObjectInfo(name, &obj)) {
    sprintf(Message,"*** Internal Error - Can't find object: %s\n", name);
    StatusPrint(Message);
    return;
  }

  /* Display object's info */

  entry = lookup_widget(ObjectListDialog,"ObjectListNameEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.name);
  entry = lookup_widget(ObjectListDialog,"ObjectListObjTypeEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.objectType);
  entry = lookup_widget(ObjectListDialog,"ObjectListSpecTypeEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.specType);
  entry = lookup_widget(ObjectListDialog,"ObjectListVarTypeEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.varType);
  entry = lookup_widget(ObjectListDialog,"ObjectListRAEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.ra);
  entry = lookup_widget(ObjectListDialog,"ObjectListDECEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), obj.dec);
  entry = lookup_widget(ObjectListDialog,"ObjectListUEntry");
  sprintf(buffer,"%6.3f", obj.Mags[0]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);
  entry = lookup_widget(ObjectListDialog,"ObjectListBEntry");
  sprintf(buffer,"%6.3f", obj.Mags[1]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);
  entry = lookup_widget(ObjectListDialog,"ObjectListVEntry");
  sprintf(buffer,"%6.3f", obj.Mags[2]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);
  entry = lookup_widget(ObjectListDialog,"ObjectListREntry");
  sprintf(buffer,"%6.3f", obj.Mags[3]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);
  entry = lookup_widget(ObjectListDialog,"ObjectListIEntry");
  sprintf(buffer,"%6.3f", obj.Mags[4]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);

  return;
}

void on_show_current_image_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  if (CurrentImageWindow != NULL) {
    gtk_widget_show(CurrentImageWindow);
  }
  return;
}


void on_start_autofocus_activate(GtkMenuItem *menuitem, gpointer user_data)
{

}

void on_CurrentWindowAutoFocus_clicked(GtkButton *button, gpointer user_data)
{
  char *bufptr, buffer[80];
  GtkWidget *Entry;
  float starX, starY, starFWHM, fwhm, minFWHM;
  int starMax, starSum, i, mini, offset, answer, success;

  /* Inform user starting autofocus */

  StatusPrint("*** INFO - Starting autofocus function...\n");

  /* User should have "clicked" on a star, get its position, etc. */

  Entry = lookup_widget(CurrentImageWindow,"CurrentImageStarXEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bufptr, "%f", &starX);
  Entry = lookup_widget(CurrentImageWindow,"CurrentImageStarYEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bufptr, "%f", &starY);
  Entry = lookup_widget(CurrentImageWindow,"CurrentImageStarMaxEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bufptr, "%d", &starMax);
  Entry = lookup_widget(CurrentImageWindow,"CurrentImageStarFWHMEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bufptr, "%f", &starFWHM);
  Entry = lookup_widget(CurrentImageWindow,"CurrentImageStarMagEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(bufptr, "%d", &starSum);

  StatusPrint("*** INFO - Taking series of images of selected star and\n"
	      "             adjusting secondary position to minimize PSF\n");

  sprintf(buffer, "*** AutoFocus: Current FWHM: %6.2f pixels\n", starFWHM);
  StatusPrint(buffer);

  /* Take three images "around" star and average FWHM for current setting */

  fwhm = GetAveFWHM(starX, starY);
  if (fwhm < 0.0) {   /* Error */
    return;
  }

  sprintf(buffer, "Current FWHM is: %6.2f pixels, continue autofocusing",
	  fwhm);
  answer = MessageBox(buffer, YESNO);
  if (answer != YES) {
    return;
  }

  StatusPrint("*** INFO - Okay, starting autofocus...\n");

  success = SendTCS200Focus(-50);
  if (! success) {
    StatusPrint("*** WARNING - Couldn't send focus message to tcs200\n");
    return;
  }

  mini = 0;
  minFWHM = 999.0;
  for (i=0; i<=10; i++) {
    fwhm = GetAveFWHM(starX, starY);
    if (fwhm < 0.0) {
      return;
    }
    if (fwhm < minFWHM) {
      minFWHM = fwhm;
      mini = i;
    }
    success = SendTCS200Focus(10);
  }

  offset = - 50 + 10*mini;
  sprintf(buffer,"*** INFO - Best focus offset was: %d with %6.2f FWHM...\n",
	  offset, minFWHM);
  StatusPrint(buffer);
  answer = MessageBox("Want to accept this new focus?", YESNO);
  if (answer != YES) {
    StatusPrint("*** INFO - Moving to old focus...\n");
    success = SendTCS200Focus(-50);
  } else {
    StatusPrint("*** INFO - Moving to new focus...\n");
    success = SendTCS200Focus(offset-50);
  }

  return;
}

float GetAveFWHM(float starX, float starY)
{
  char buffer[120];
  float avefwhm, x, y;
  float FWHM, sumfwhm, SkyFlux, StarFlux, Magnitude, MagErr;
  int i, savex, savey, saveh, savew, error, GotFrame, Found, max;
  int xmin, ymin, xmax, ymax;

  savex = singleSettings.x;
  savey = singleSettings.y;
  savew = singleSettings.w;
  saveh = singleSettings.h;

  singleSettings.x = (int) (starX - 50);
  singleSettings.y = (int) (starY - 50);
  singleSettings.w = 100;
  singleSettings.h = 100;
  printf("frame: %d %d %d %d\n", singleSettings.x, singleSettings.y,
	 singleSettings.w, singleSettings.h);

  error = false;
  xmin = singleSettings.x;
  ymin = singleSettings.y;
  xmax = xmin + 100;
  ymax = ymin + 100;
  sumfwhm = 0.0;
  for (i=0; i<3; i++) {
    GotFrame = ExposeSingleFrame();
    if (! GotFrame) {
      StatusPrint("*** WARNING - Can't get autofocus image, aborting\n");
      error = true;
      break;
    }
    Found = FindStar(&ccd->Image.light_frame, xmin, ymin, xmax, ymax,
		     &x, &y, &max);
    if (! Found) {
      StatusPrint("*** WARNING - Can't find star in autofocus image, "
		  "aborting\n");
      error = true;
      break;
    }
    doPhotometry(&ccd->Image, x, y, max, &FWHM, &SkyFlux, &StarFlux,
		 &Magnitude, &MagErr);
    sumfwhm += FWHM;
  }

  singleSettings.x = savex;
  singleSettings.y = savey;
  singleSettings.w = savew;
  singleSettings.h = saveh;

  if (! error) {
    avefwhm = sumfwhm / 3.0;
    sprintf(buffer, "*** INFO - Current FWHM: %f\n", avefwhm);
    StatusPrint(buffer);
  } else {
    avefwhm = -1.0;
  }
  return avefwhm;
}


void DisplayPSF(PIXCELL *PixList, float fitMax, float fitFWHM)
{
  char ch, buffer[80];
  PIXCELL *pptr;
  float xs[2000], ys[2000], maxval, maxr, r, x, y;
  int i;

  if (cpgbeg(0, "/XWINDOW", 1, 1) != 1) {
    StatusPrint("*** WARNING - Can't open PSF Window...\n");
    return;
  }
  cpgask(false);

  /* Find max and min x & y */

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
      ys[i] = pptr->val;
      xs[i++] = pptr->r;
      pptr = pptr->next;
  }

  cpgenv(0.0, maxr, 0.0, maxval, 0, 1);
  cpglab("Radius (pixels)", "Pixel Value (raw)", "Star PSF");
  cpgpt(i, xs, ys, 9);

  i = 0;
  for (r=0.0; r<maxr; r += maxr/100.0) {
    xs[i] = r;
    ys[i++] = gaussian(((double) fitMax), ((double) fitFWHM/2.34), r);
  }
  cpgline(i, xs, ys);
  sprintf(buffer, "Max: %6.0f, FHWM: %6.2f", fitMax, fitFWHM);
  cpgtext(8.0, maxval*0.75, buffer);

  r = maxval/2.0;
  cpgtext(10.0, r, "Type q to close plot"); 
  
  do {
    cpgcurs(&x, &y, &ch);
  } while ((ch != 'q') && (ch != 'Q'));

  cpgclos();

  return;

}

PIXCELL *pixpointer;
float FitPSFfwhm;
float FitPSFmax;
float FitPSFx;
float FitPSFy;

int FitPSF(PIXCELL *PixList, float *fitMax, float *fitFWHM,
	   float *fitX, float *fitY)
{
  static int FIRST=true;
  char pnam[80];
  double pstart, pmin, pmax, pstep, arglis[10];
  int nprm, ierflag;

  if (FIRST) {
    HLIMIT(10000);
  }

  pixpointer = PixList;

  MNINIT(5, 0, 0);
  strcpy(pnam," Test of PSF fitter");
  MNSETI(pnam);
  nprm = 1;
  strcpy(pnam, "Max");
  pstart = PixList->val;
  pmin = 0.0;
  pmax = 65000.0;
  pstep = 100.0;
  MNPARM(nprm, pnam, pstart, pstep, pmin, pmax, ierflag);

  nprm = 2;
  strcpy(pnam, "Sigma");
  pstart = 3.0;
  pmin = 0.5;
  pmax = 10.0;
  pstep = 1.0;
  MNPARM(nprm, pnam, pstart, pstep, pmin, pmax, ierflag);

  nprm = 3;
  strcpy(pnam, "x");
  pstart = PixList->x;
  pmin = pstart - 10.0;
  pmax = pstart + 10.0;
  pstep = 2.0;
  MNPARM(nprm, pnam, pstart, pstep, pmin, pmax, ierflag);

  nprm = 4;
  strcpy(pnam, "y");
  pstart = PixList->y;
  pmin = pstart - 10.0;
  pmax = pstart + 10.0;
  pstep = 2.0;
  MNPARM(nprm, pnam, pstart, pstep, pmin, pmax, ierflag);

  nprm = 1;
  strcpy(pnam,"SET ERRDEF");
  arglis[0] = 0.5;
  MNEXCM(fcn, pnam, arglis, nprm, ierflag, fcn);

  nprm = 1;
  strcpy(pnam,"CALL FCN");
  arglis[0] = 1.0;
  MNEXCM(fcn, pnam, arglis, nprm, ierflag, fcn);

/*   nprm = 2; */
/*   arglis[0] = 3; */
/*   arglis[1] = 4; */
/*   strcpy(pnam, "FIX"); */
/*   MNEXCM(fcn, pnam, arglis, nprm, ierflag, fcn); */

  nprm = 0;
  strcpy(pnam, "SIMPLEX");
  MNEXCM(fcn, pnam, arglis, nprm, ierflag, fcn);

  nprm = 1;
  strcpy(pnam,"CALL FCN");
  arglis[0] = 3.0;
  MNEXCM(fcn, pnam, arglis, nprm, ierflag, fcn);

  *fitMax = FitPSFmax;
  *fitFWHM = FitPSFfwhm;
  *fitX = FitPSFx;
  *fitY = FitPSFy;

  return 0;
}

float gaussian(double fitMax, double sigma, float r)
{
  double arg;
  float g;

  arg = r / sigma;

  g = fitMax * exp(- 0.5 * arg*arg);

  return g;
}


void fcn( int *NPar, double *grad, double *fval, double *FitParms,
           int *iflag, float (*futil)(float[] ) )
{
  PIXCELL *pptr;
  double chiSq, chi;
  float r, th, sigma, val, delx, dely;

  switch (*iflag) {

  case 1:  /* Init stuff */
    
    break;

  case 2:  /* Compute gradients */

    break;

  case 3:

    FitPSFmax = FitParms[0];
    FitPSFfwhm = FitParms[1] * 2.34;
    FitPSFx = FitParms[2];
    FitPSFy = FitParms[3];

    break;
  }

  /* Compute ChiSquared */

  pptr = pixpointer;
  chiSq = 0.0;
  while (pptr != NULL) {
    val = pptr->val;
    if (val < 0.1*pixpointer->val)
      break;
    if (val > 0.0)
      sigma = sqrt(val);
    else
      sigma = 1.0;
    delx = pptr->x - FitParms[2];
    dely = pptr->y - FitParms[3];
    r = delx * delx + dely * dely;
    if (r > 0.0) r = sqrt(r);
    th = gaussian(FitParms[0], FitParms[1], r);
    chi = (val - th)/sigma;
    chiSq += chi*chi;
    pptr = pptr->next;
  }
  *fval = chiSq;
}

void on_SingleSettingsApply_clicked(GtkButton *button, gpointer  user_data)
{
  char Message[160], *Option;
  gchar *buffer;
  GtkWidget *Entry;

  /* Get exposure time */

  Entry = lookup_widget(singleSettings_dialog,
			       "SingleSettingsExpTimEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%f", &singleSettings.exposureTime);

  /* Get ccd frame size */

  Entry = lookup_widget(singleSettings_dialog,
			       "SingleSettingsCCDFrameEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  sscanf(buffer, "%d, %d, %d, %d", &singleSettings.x, &singleSettings.y,
	 &singleSettings.h, &singleSettings.w);

  /* Get Object Name */

  Entry = lookup_widget(singleSettings_dialog,
			       "SingleSettingsObjectNameEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(singleSettings.ObjectName,buffer);

  /* Get Image Directory */

  Entry = lookup_widget(singleSettings_dialog,
			       "SingleSettingsImageDirEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(singleSettings.ImageDir,buffer);

  /* Get dark frame option */

  Entry = lookup_widget(singleSettings_dialog,
			     "SingleSettingsDarkComboEntry");
  Option = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  if (strcmp(Option,"Reuse old dark frame") == 0) {
    singleSettings.darkOption = 1;
  } else if (strcmp(Option,"Force new dark frame") == 0) {
    singleSettings.darkOption = 2;
  } else if (strcmp(Option,"Use dark frame from file") == 0) {
    singleSettings.darkOption = 3;
  } else if (strcmp(Option,"Don't do dark subtract") == 0) {
    singleSettings.darkOption = 4;
  } else {
    sprintf(Message, "*** Internal error - bad dark option: %s"
	    " (singleSettings)\n",Option);
    StatusPrint(Message);
  }
  Entry = lookup_widget(singleSettings_dialog,
			     "SingleSettingsDarkNameEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(singleSettings.DarkDir, buffer);

  /* Get flat frame option */

  Entry = lookup_widget(singleSettings_dialog,
			     "SingleSettingsFlatComboEntry");
  Option = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  if (strcmp(Option,"Do not do flat fielding") == 0) {
    singleSettings.flatOption = 1;
  } else if (strcmp(Option,"Use current flat field") == 0) {
    singleSettings.flatOption = 2;
  } else if (strcmp(Option,"Use flat field from file") == 0) {
    singleSettings.flatOption = 3;
  } else {
    sprintf(Message, "*** Internal error - bad flat option: %s"
	    " (singleSettings)\n", Option);
    StatusPrint(Message);
  }
  Entry = lookup_widget(singleSettings_dialog,
			     "SingleSettingsFlatNameEntry");
  buffer = (gchar *) gtk_entry_get_text(GTK_ENTRY(Entry));
  strcpy(singleSettings.FlatDir, buffer);

  updateStatusInfo(dummy);
  return;
}


void on_CurrentWindowExposeButton_clicked(GtkButton *button,
					  gpointer user_data)
{
  ExposeSingleFrame();
  return;
}


void on_YesNoDialogYesButton_clicked(GtkButton *button, gpointer user_data)
{
  MessageBoxAnswer = YES;
  return;
}


void on_YesNoDialogNoButton_clicked(GtkButton *button, gpointer user_data)
{
  MessageBoxAnswer = NO;
  return;
}


void on_YesNoDialogCancelButton_clicked(GtkButton *button, gpointer user_data)
{
  MessageBoxAnswer = CANCEL;
  return;
}


void on_OkayDialogOKButton_clicked(GtkButton *button, gpointer user_data)
{
  MessageBoxAnswer = OK;
  return;
}


void on_OkayDialogCancelButton_clicked(GtkButton *button, gpointer user_data)
{
  MessageBoxAnswer = CANCEL;
  return;
}

int SendTCS200Focus(int offset)
{
  char Message[160], buffer[160];
  size_t msgsiz;
  int msgflg, istat;
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
      return false;
    } else {
      sprintf(Message, "*** INFO - Got TCS200 message queue: %d\n", queueID);
      StatusPrint(Message);
    }
  }

  /* Send TCS200 message to step secondary */

  if (offset > 0) {
    sprintf(Message, ":F+%02d", abs(offset));
  } else {
    sprintf(Message, ":F-%02d", abs(offset));
  }
  strcpy(msg.mtext, Message);
  msg.mtype = MTYPE_TO_SCOPE;
  msgsiz = strlen(Message) + 1;
  msgflg = IPC_NOWAIT;
  istat = msgsnd(queueID, &msg, msgsiz, msgflg);
  if (istat < 0) {
    StatusPrint("*** WARNING - Can't sent message to TCS200\n");
  } else {
    sprintf(buffer, "*** INFO - Sent message to TCS200: %s\n", Message);
    StatusPrint(buffer);
  }

  RunMainIteration(3.0);   /* Wait for secondary to move */

  return true;
}


int SendTCS200Step(double DeltaRA, double DeltaDEC)
{
  char Message[160], buffer[160];
  size_t msgsiz;
  int msgflg, istat, SendMessage;
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
      return false;
    } else {
      sprintf(Message, "*** INFO - Got TCS200 message queue: %d\n", queueID);
      StatusPrint(Message);
    }
  }

  /* Send TCS200 message to step scope in RA */

  SendMessage = true;
  if (DeltaRA < -0.5) {
    sprintf(Message, ":Mw%7.4lf", fabs(DeltaRA)/3600.0);
  } else if (DeltaRA > 0.5) {
    sprintf(Message, ":Me%7.4lf", DeltaRA/3600.0);
  } else
    SendMessage = false;

  if (SendMessage) {
    strcpy(msg.mtext, Message);
    msg.mtype = MTYPE_TO_SCOPE;
    msgsiz = strlen(Message) + 1;
    msgflg = IPC_NOWAIT;
    istat = msgsnd(queueID, &msg, msgsiz, msgflg);
    if (istat < 0) {
      StatusPrint("*** WARNING - Can't send message to TCS200\n");
    } else {
      sprintf(buffer, "*** INFO - Sent message to TCS200: %s\n", Message);
      StatusPrint(buffer);
    }
  }

  /* Send TCS200 message to step scope in DEC */

  SendMessage = true;
  if (DeltaDEC < -1.0) {
    sprintf(Message, ":Ms%7.4lf", fabs(DeltaDEC)/3600.0);
  } else if (DeltaDEC > 1.0) {
    sprintf(Message, ":Mn%7.4lf", DeltaDEC/3600.0);
  } else
    SendMessage = false;

  if (SendMessage) {
    strcpy(msg.mtext, Message);
    msg.mtype = MTYPE_TO_SCOPE;
    msgsiz = strlen(Message) + 1;
    msgflg = IPC_NOWAIT;
    istat = msgsnd(queueID, &msg, msgsiz, msgflg);
    if (istat < 0) {
      StatusPrint("*** WARNING - Can't send message to TCS200\n");
    } else {
      sprintf(buffer, "*** INFO - Sent message to TCS200: %s\n", Message);
      StatusPrint(buffer);
    }
  }

  return true;
}



void on_SeriesSettingsApplyButton_clicked(GtkButton *button,
					  gpointer user_data)
{
  UpdateSeriesSettings();
  return;
}


void on_DarkFrameSettingsApplyButton_clicked(GtkButton *button,
					     gpointer user_data)
{
  UpdateDarkFrameSettings();
  return;
}


void on_FlatFrameSettingsApplyButton_clicked(GtkButton *button,
					     gpointer user_data)
{
  UpdateFlatFrameSettings();
  return;
}


void on_StackSettingsApplyButton_clicked(GtkButton *button,
					 gpointer user_data)
{
  UpdateStackSettings();
  return;
}


void on_link_to_imaging_ccd_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  int i, Linked, status;

  if (ImagingCCD.Linked) {
    StatusPrint("*** INFO - Already Linked to imaging ccd\n");
    return;
  } else if (SpectroCCD.Linked) {
    StatusPrint("*** WARNING - Already Linked to Spectro CCD, can only "
		"hand one CCD at a time...\n");
    return;
  }

  /* Link to camera, try at most 4 times */

  ccd = &ImagingCCD;
  strcpy(ccd->name,ccdSettings.ImagingType);
  strcpy(ccd->port,ccdSettings.ImagingPort);

  Linked = false;
  for (i=0; i<4; i++) {
    Linked = establish_link(ccd, true);
    if (Linked)
      break;
    sleep(1);
  }
  if (! Linked) {
    StatusPrint("*** WARNING - Can't open camera, giving up...\n");
    return;
  }

  ccd->Linked = true;

  /* Get CCD info */

  if (get_ccd_info(ccd) < 0)
    ccd->Linked = false;

  GetCCDFrameSettings(ccd,&singleSettings.x,&singleSettings.y,
		      &singleSettings.w,&singleSettings.h,
		      &singleSettings.binning);
  GetCCDFrameSettings(ccd,&seriesSettings.x,&seriesSettings.y,
		      &seriesSettings.w,&seriesSettings.h,
		      &seriesSettings.binning);
  GetCCDFrameSettings(ccd,&darkFrameSettings.x,&darkFrameSettings.y,
		      &darkFrameSettings.w,&darkFrameSettings.h,
		      &darkFrameSettings.binning);
  GetCCDFrameSettings(ccd,&flatFrameSettings.x,&flatFrameSettings.y,
		      &flatFrameSettings.w,&flatFrameSettings.h,
		      &flatFrameSettings.binning);
  GetCCDFrameSettings(ccd,&stackSettings.x,&stackSettings.y,
		      &stackSettings.w,&stackSettings.h,
		      &stackSettings.binning);

  /* Move Filter wheel to C position */

  doFilterWheel(ccd, &status, 6);

  /* Also show current status */

  doShowStatus(ccd, &status);

  return;
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

void on_turn_on_imaging_temp_activate(GtkMenuItem *menuitem,
				      gpointer user_data)
{
  if (! ImagingCCD.Linked) {
    StatusPrint("*** WARNING - Can't turn temp. regulation on, "
		"link to ccd first...\n");
    return;
  }

  /* Ask user for temp set point */

  if (queryr_dialog == NULL)
    queryr_dialog = create_queryr_dialog();
  gtk_widget_show(queryr_dialog);
  gdk_window_raise(queryr_dialog->window);
  queryr_dialog_ok_function = &doSetTempOnCamera;

  return;
}


void on_turn_off_imaging_temp_activate(GtkMenuItem *menuitem,
				       gpointer user_data)
{
  int status;

  if (! ImagingCCD.Linked) {
    StatusPrint("*** WARNING - Can't turn regulation off, "
		"link to ccd first...\n");
    return;
  }
  doSetTempOffCamera(&ImagingCCD, &status);
  return;
}


void on_link_to_spectro_ccd_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  int i, Linked, status;

  if (SpectroCCD.Linked) {
    StatusPrint("*** INFO - Already Linked to spectrograph ccd\n");
    return;
  } else if (ImagingCCD.Linked) {
    StatusPrint("*** WARNING - Already Linked to Imaging CCD, can only "
		"hand one CCD at a time...\n");
    return;
  }

  /* Link to camera, try at most 4 times */

  ccd = &SpectroCCD;
  strcpy(ccd->name,ccdSettings.SpectroType);
  strcpy(ccd->port,ccdSettings.SpectroPort);

  Linked = false;
  for (i=0; i<4; i++) {
    Linked = establish_link(ccd, true);
    if (Linked)
      break;
    sleep(1);
  }
  if (! Linked) {
    StatusPrint("*** WARNING - Can't open camera, giving up...\n");
    return;
  }

  ccd->Linked = true;

  /* Get CCD info */

  if (get_ccd_info(ccd) < 0)
    ccd->Linked = false;

  GetCCDFrameSettings(ccd,&singleSettings.x,&singleSettings.y,
		      &singleSettings.w,&singleSettings.h,
		      &singleSettings.binning);
  GetCCDFrameSettings(ccd,&seriesSettings.x,&seriesSettings.y,
		      &seriesSettings.w,&seriesSettings.h,
		      &seriesSettings.binning);
  GetCCDFrameSettings(ccd,&darkFrameSettings.x,&darkFrameSettings.y,
		      &darkFrameSettings.w,&darkFrameSettings.h,
		      &darkFrameSettings.binning);
  GetCCDFrameSettings(ccd,&flatFrameSettings.x,&flatFrameSettings.y,
		      &flatFrameSettings.w,&flatFrameSettings.h,
		      &flatFrameSettings.binning);
  GetCCDFrameSettings(ccd,&stackSettings.x,&stackSettings.y,
		      &stackSettings.w,&stackSettings.h,
		      &stackSettings.binning);

  /* Also show current status */

  doShowStatus(ccd, &status);

  return;
}


void on_turn_on_spectro_temp_activate(GtkMenuItem *menuitem,
				      gpointer user_data)
{
  if (! SpectroCCD.Linked) {
    StatusPrint("*** WARNING - Can't turn temp. regulation on, "
		"link to ccd first...\n");
    return;
  }

  /* Ask user for temp set point */

  if (queryr_dialog == NULL)
    queryr_dialog = create_queryr_dialog();
  gtk_widget_show(queryr_dialog);
  gdk_window_raise(queryr_dialog->window);
  queryr_dialog_ok_function = &doSetTempOnCamera;

  return;
}


void on_turn_off_spectro_temp_activate(GtkMenuItem *menuitem,
				       gpointer user_data)
{
  int status;

  if (! SpectroCCD.Linked) {
    StatusPrint("*** WARNING - Can't turn regulation off, "
		"link to ccd first...\n");
    return;
  }
  doSetTempOffCamera(&SpectroCCD, &status);
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
	sprintf(Message, "*** INFO - Link Established to SBIG ccd "
		"on device %s\n", ccd->port);
	StatusPrint(Message);
	success = true;
      } else {
	sprintf(Message, "*** WARNING - Link Failed, code: %d\n", status);
	StatusPrint(Message);
	success = false;
      }
      ccd->make = SBIG_MAKE;
    } else if (strstr(ccd->name,"Apogee") != NULL) {
      success = apCam_EstablishLink();
      if (! success) {
	sprintf(Message,
		"*** Warning - Couldn't link to ccd %s on device %s\n",
		ccd->name, ccd->port);
	StatusPrint(Message);
	success = false;
      } else {
	sprintf(Message,"*** Info - Connected to ccd %s on device %s\n",
		ccd->name, ccd->port);
	StatusPrint(Message);
	success = true;
      }
      ccd->make = APOGEE_MAKE;
    } else if ((strstr(ccd->name,"MX") != NULL) ||
	       (strstr(ccd->name,"SXV") != NULL)) {
      strcpy(ccd->mx_sxv_info.filename,"/dev/ccda");
      success = spCam_EstablishLink(ccd);
      if (! success) {
	sprintf(Message,
		"*** Warning - Couldn't link to ccd %s on device %s\n",
		ccd->name, ccd->port);
	StatusPrint(Message);
	success = false;
      } else {
	sprintf(Message,"*** Info - Connected to ccd %s on device %s\n",
		ccd->name, ccd->port);
	StatusPrint(Message);
	success = true;
      }
      ccd->make = SXPRESS_MAKE;
    } else {
      sprintf(Message,"*** Warning - Invalid ccd type %s\n", ccd->name);
      StatusPrint(Message);
      success = false;
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
    success = true;
  }
  
  return success;
}



int get_ccd_info(CCD *ccd)
{
  char Message[240];
  int result, i, success;
  GetCCDInfoParams in;

  /* Get basic imaging ccd info */

  switch (ccd->make) {
    case SBIG_MAKE:
      in.request = 0;
      result = pCam_GetCCDInfo(&in, (void *)&ccd->info);
      if (result != CE_NO_ERROR) {
	StatusPrint(    "*** WARNING - Can't get basic imaging CCD info.\n");
	sprintf(Message,"              [%d]: %s\n", result, pCam_GetStatusString());
	StatusPrint(Message);
	return -1;
      }
      in.request = 1;
      result = pCam_GetCCDInfo(&in, (void *)&ccd->info1);
      if (result != CE_NO_ERROR) {
	StatusPrint("*** WARNING - Can't get basic tracking CCD info...\n");
	sprintf(Message,"              [%d]: %s\n", result, pCam_GetStatusString());
	StatusPrint(Message);
	return -1;
      }
      in.request = 2;
      pCam_GetCCDInfo(&in, (void *)&ccd->info2);
      if (result != CE_NO_ERROR) {
	StatusPrint("*** WARNING - Can't get extended CCD info...\n");
	sprintf(Message,"              [%d]: %s\n", result, pCam_GetStatusString());
	StatusPrint(Message);
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

void on_unlink_imaging_ccd_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  int status;

  if (! ImagingCCD.Linked) {
    StatusPrint("*** WARNING - Imaging CCD not linked...\n");
    return;
  }
  doSetTempOffCamera(&ImagingCCD, &status);
  ImagingCCD.Linked = false;
  establish_link(&ImagingCCD, false);
  freeImageBuffers(&ImagingCCD);
  return;
}


void on_unlink_spectro_ccd_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  int status;

  if (! SpectroCCD.Linked) {
    StatusPrint("*** WARNING - Spectrograph CCD not linked...\n");
    return;
  }
  doSetTempOffCamera(&SpectroCCD, &status);
  SpectroCCD.Linked = false;
  establish_link(&SpectroCCD, false);
  freeImageBuffers(&SpectroCCD);
  return;

}


void on_ProgressDialogCancelButton_clicked(GtkButton *button,
					   gpointer user_data)
{
  CancelCurrentAcquire = true;
  return;
}


void on_MainSeriesStopButton_clicked(GtkButton *button, gpointer user_data)
{
  StopSeries = true;
  return;
}


void on_PhotometrySettingsAutoFindButton_toggled(GtkToggleButton *togglebutton,
						 gpointer user_data)
{
  photometrySettings.autoFind = gtk_toggle_button_get_active(togglebutton);
  return;
}


void on_PhotometrySettingsOffsetSkyButton_toggled(GtkToggleButton *togglebutton,
						  gpointer user_data)
{
  photometrySettings.offsetSky = gtk_toggle_button_get_active(togglebutton);
  return;
}


void on_PhotometrySettingsLogResultsButton_toggled(
			    GtkToggleButton *togglebutton, gpointer user_data)
{
  FILE *fptr;
  int answer;
  char buffer[160];

  photometrySettings.logResults = gtk_toggle_button_get_active(togglebutton);

  if (! photometrySettings.logResults) {
    fclose(photometrySettings.logFilePtr);
    StatusPrint("*** INFO - Closed photometry log file...\n");
  } else {
    fptr = fopen(photometrySettings.logFileName, "r");
    if (fptr != NULL) {
      fclose(fptr);
      sprintf(buffer, "Photometry Log File: %s exists, want to append to it?",
	      photometrySettings.logFileName);
      answer = MessageBox(buffer, YESNO);
      if (answer != YES) {
	answer = MessageBox("Want to overwrite it?", YESNO);
	if (answer != YES) {
	  StatusPrint("*** INFO - Then change log file name and try again\n");
	  StatusPrint("*** WARNING - Photometry logging remains off\n");
	  photometrySettings.logResults = false;
	  gtk_toggle_button_set_active(togglebutton, false);
	  return;
	} else {
	  StatusPrint("*** INFO - Okay will overwrite log file...\n");
	  fptr = fopen(photometrySettings.logFileName, "w");
	  if (fptr == NULL) {
	    sprintf(buffer, "*** WARNING - Can't create log file: %s\n",
		    photometrySettings.logFileName);
	    StatusPrint(buffer);
	    photometrySettings.logResults = false;
	    gtk_toggle_button_set_active(togglebutton, false);
	    return;
	  } else {
	    sprintf(buffer,
		    "*** INFO - Photometry log file %s is open (overwrite)\n",
		    photometrySettings.logFileName);
	    StatusPrint(buffer);
	    photometrySettings.logFilePtr = fptr;
	    return;
	  }
	}
      } else {
	fptr = fopen(photometrySettings.logFileName, "a");
	if (fptr == NULL) {
	  sprintf(buffer,
		  "*** WARNING - Can't open log file %s for appending...\n",
		  photometrySettings.logFileName);
	  StatusPrint(buffer);
	  photometrySettings.logResults = false;
	  gtk_toggle_button_set_active(togglebutton, false);
	  return;
	} else {
	    sprintf(buffer,
		    "*** INFO - Photometry log file %s is open (append)\n",
		    photometrySettings.logFileName);
	    StatusPrint(buffer);
	    photometrySettings.logFilePtr = fptr;
	    return;
	}
      }
    } else {
      fptr = fopen(photometrySettings.logFileName, "w");
      sprintf(buffer,
	      "*** INFO - Photometry log file %s is open (new)\n",
	      photometrySettings.logFileName);
      StatusPrint(buffer);
      photometrySettings.logFilePtr = fptr;
    }
  }      
	    
  return;
}


void GetPhotometrySettings(void)
{
  GtkWidget *widget;
  float value;
  int ivalue;
  char *bufptr;
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsAperRadEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &value);
  if (value < 0.0) {
    StatusPrint("*** WARNING - Invalid aperature radius, using default...\n");
    photometrySettings.aperatureRadius = 10.0;
  } else {
    photometrySettings.aperatureRadius = value;
  }
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsZeroPointEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &value);
  photometrySettings.zeroPoint = value;
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsSkyInnerRadEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &value);
  if (value < 0.0) {
    StatusPrint("*** WARNING - Invalid inner sky radius, using default...\n");
    photometrySettings.skyInnerRadius = 15.0;
  } else {
    photometrySettings.skyInnerRadius = value;
  }
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsSkyOuterRadEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &value);
  if (value < 0.0) {
    StatusPrint("*** WARNING - Invalid outer sky radius, using default...\n");
    photometrySettings.skyOuterRadius = 20.0;
  } else {
    photometrySettings.skyOuterRadius = value;
  }
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsFindRadEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &value);
  if (value < 0.0) {
    StatusPrint("*** WARNING - Invalid find radius, using default...\n");
    photometrySettings.findRadius = 5.0;
  } else {
    photometrySettings.findRadius = value;
  }
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsMinPeakEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%d", &ivalue);
  if (ivalue < 0) {
    StatusPrint("*** WARNING - Invalid minimum finding peak, "
		"using default...\n");
    photometrySettings.minPeak = 5.0;
  } else {
    photometrySettings.minPeak = ivalue;
  }
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsMinFWHMEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &value);
  if (value < 0.0) {
    StatusPrint("*** WARNING - Invalid minimum finding FWHM, "
		"using default...\n");
    photometrySettings.minFWHM = 2.0;
  } else {
    photometrySettings.minFWHM = value;
  }
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsMaxFWHMEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &value);
  if (value < photometrySettings.minFWHM) {
    StatusPrint("*** WARNING - Invalid maxmimum finding FWHM, "
		"using default...\n");
    photometrySettings.maxFWHM = 10.0;
  } else {
    photometrySettings.maxFWHM = value;
  }
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsMinSepEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &value);
  if (value < 0.0) {
    StatusPrint("*** WARNING - Invalid minimum star separation, "
		"using default...\n");
    photometrySettings.minSeparation = 5.0;
  } else {
    photometrySettings.minSeparation = value;
  }
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsSkySigmaCutEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &value);
  if (value < 0.0) {
    StatusPrint("*** WARNING - Invalid sky sigma cut, using default...\n");
    photometrySettings.skySigmaCut = 3.0;
  } else {
    photometrySettings.skySigmaCut = value;
  }
  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsLogFileEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  strcpy(photometrySettings.logFileName, bufptr);

  widget = lookup_widget(PhotometrySettingsDialog,
			 "PhotometrySettingsHardcopyComboEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  strcpy(photometrySettings.plotHardcopyType, bufptr);

  return;
}



void on_PhotometrySettingsOKButton_clicked(GtkButton *button,
					   gpointer user_data)
{
  GetPhotometrySettings();

  gtk_widget_hide(PhotometrySettingsDialog);
  return;
}


void on_PhotometrySettingsApplyButton_clicked(GtkButton *button,
					      gpointer user_data)
{
  GetPhotometrySettings();

  return;
}


void on_PhotometrySettingsCancelButton_clicked(GtkButton *button,
					       gpointer user_data)
{
  gtk_widget_hide(PhotometrySettingsDialog);
  return;
}




void on_CurrentWindowMeasureListButton_clicked(GtkButton *button,
					       gpointer user_data)
{
  updateListStars(&ccd->Image, CurrentStarList);
  measureListStars(&ccd->Image, CurrentStarList);
  return;
}


void on_PhotometrySettingsPlotButton_toggled(GtkToggleButton *togglebutton,
					     gpointer user_data)
{
  photometrySettings.plotResults = gtk_toggle_button_get_active(togglebutton);
  if (! photometrySettings.plotResults) {
    AddToPhotPlot(-1, NULL, NULL, 0.0, ' ');
  }
  return;
}


void doPhotometry(IMAGE *Image, float starX, float starY, int max,
		  float *FWHM, float *SkyFlux, float *StarFlux,
		  float *Magnitude, float *MagErr)
{
  GtkWidget *widget;
  FRAME *frame;
  int imageMinX, imageMaxX, imageMinY, imageMaxY;
  int minX, maxX, minY, maxY, x, y, ipix, pixval;
  int numPixels, state, w, h;
  float r, val, medianSky, sigma, error, fitMax, fitFWHM, fitX, fitY;
  char buffer[80];
  PIXCELL *PixList, *pptr, *prev, *next;

  /* Default values */

  *FWHM = -999.0;
  *SkyFlux = -999.0;
  *StarFlux = -999.0;
  *Magnitude = -99.999;
  *MagErr = -9.999;

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
	putpixval(val, x, y, r, &PixList);
	numPixels++;
      }
    }
  }
  if (numPixels <= 0) {
    StatusPrint("*** WARNING - No pixels in sky annulus...\n");
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
    StatusPrint("*** WARNING - No pixels in sky annulus (after cuts)...\n");
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
  for (x=minX; x<=maxX; x++) {
    for (y=minY; y<=maxY; y++) {
      ipix = (y-imageMinY) * w + (x-imageMinX);
      pixval = frame->frame[ipix];
      r = (x-starX)*(x-starX) + (y-starY)*(y-starY);
      if (r > 0.0) r = sqrt(r);
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
    StatusPrint("*** WARNING - star flux <= 0.0 in photometry...\n");
    return;
  }

  /* Convert star flux to magnitude */

  *Magnitude = photometrySettings.zeroPoint - 2.5 * log10(*StarFlux) +
    2.5 * log10(Image->light_frame.exposure);

  error = sqrt(*StarFlux/CCDGAIN + *SkyFlux/CCDGAIN);
  *MagErr = 1.0857 * error / *StarFlux;

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
	putpix(val, x, y, r, &PixList);
	numPixels++;
      }
    }
  }

  /* If valid data for star, fit PSF */

  if (numPixels > 0) {
    FitPSF(PixList, &fitMax, &fitFWHM, &fitX, &fitY);
    *FWHM = fitFWHM;
    starX = fitX;
    starY = fitY;
  }

  /* Show results on current image window or Guiding window */

  if (Image != &guideImage) {
    widget = lookup_widget(CurrentImageWindow,"CurrentImageStarFWHMEntry");
    sprintf(buffer, "%5.1f", *FWHM);
    gtk_entry_set_text(GTK_ENTRY(widget), buffer);
    widget = lookup_widget(CurrentImageWindow,"CurrentImageStarFluxEntry");
    sprintf(buffer, "%8.0f", *StarFlux);
    gtk_entry_set_text(GTK_ENTRY(widget), buffer);
    widget = lookup_widget(CurrentImageWindow,"CurrentImageSkyFluxEntry");
    sprintf(buffer, "%8.0f", *SkyFlux);
    gtk_entry_set_text(GTK_ENTRY(widget), buffer);
    widget = lookup_widget(CurrentImageWindow,"CurrentImageStarMagEntry");
    sprintf(buffer, "%6.3f", *Magnitude);
    gtk_entry_set_text(GTK_ENTRY(widget), buffer);
    widget = lookup_widget(CurrentImageWindow,"CurrentImageStarXEntry");
    sprintf(buffer, "%7.2f", fitX);
    gtk_entry_set_text(GTK_ENTRY(widget), buffer);
    widget = lookup_widget(CurrentImageWindow,"CurrentImageStarYEntry");
    sprintf(buffer, "%7.2f", fitY);
    gtk_entry_set_text(GTK_ENTRY(widget), buffer);

    /* Show PSF plot if requested */

    widget = lookup_widget(CurrentImageWindow,"CurrentImagePlotPSFButton");
    state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
    if (state) {
      DisplayPSF(PixList, fitMax, fitFWHM);
    }
    widget = lookup_widget(CurrentImageWindow, "CurrentImageDrawingArea");
    MarkStar(widget, starX, starY);
    CircleStar(widget, starX, starY);
  } else {
    widget = lookup_widget(GuideFrameWindow, "GuideFrameWindowStarFWHMEntry");
    sprintf(buffer, "%5.1f", *FWHM);
    gtk_entry_set_text(GTK_ENTRY(widget), buffer);
    widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowStarSumEntry");
    sprintf(buffer, "%8.0f", *StarFlux);
    gtk_entry_set_text(GTK_ENTRY(widget), buffer);
    widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowStarXEntry");
    sprintf(buffer, "%7.2f", fitX);
    gtk_entry_set_text(GTK_ENTRY(widget), buffer);
    widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowStarYEntry");
    sprintf(buffer, "%7.2f", fitY);
    gtk_entry_set_text(GTK_ENTRY(widget), buffer);

    /* Show PSF plot if requested */

    widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowPlotPSFButton");
    state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
    if (state) {
      DisplayPSF(PixList, fitMax, fitFWHM);
    }
    
    widget = lookup_widget(GuideFrameWindow, "GuideFrameWindowDrawingArea");
    MarkStar(widget, starX, starY);
    CircleStar(widget, starX, starY);
  }

  freepix(PixList);

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
    xmin = (int) rint(starX - findRad);
    xmax = (int) rint(starX + findRad);
    ymin = (int) rint(starY - findRad);
    ymax = (int) rint(starY + findRad);
    Found = FindStar(frame, xmin, ymin, xmax, ymax, &x, &y, &max);
    if (! Found) {
      sprintf(buffer, "*** WARNING - Can't find star #%d at (%7.2f,%7.2f)\n",
	      starNum, starX, starY);
      StatusPrint(buffer);
      StatusPrint(    "      Terminating list measurement for this image\n");
      return false;
    } else if ((fabs(starX-x) > findRad) || (fabs(starY-y) > findRad)) {
      sprintf(buffer, "*** WARNING - Star #%d at (%7.2f,%7.2f) shifted by: "
	      " (%5.1f,%5.1f)\n",
	      starNum, starX, starY, (starX-x), (starY-y));
      StatusPrint(buffer);
      StatusPrint(    "      Terminating list measurement for this image\n");
      return false;
    } else {
      sprintf(buffer,
	      "*** INFO - Updated position for star #%d is: (%7.2f,%7.2f)\n",
	      starNum, x, y);
      StatusPrint(buffer);
      sptr->x = x;
      sptr->y = y;
      sptr->max = max;
    }
    sptr = sptr->next;
    starNum++;
  }

  StatusPrint("*** INFO - Finished updating star list positions...\n");
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

  if (List == NULL) return true;

  sptr = List;
  c = '/';

  starNum = 1;
  strcpy(buffer, Image->FileName);
  if (strlen(buffer) <= 0) {
    strcpy(ImageFileName, "NotSaved");
  } else {
    cptr = strrchr(buffer, c);
    if (cptr != NULL) {
      strcpy(ImageFileName, cptr+1);
    } else {
      strcpy(ImageFileName, buffer);
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
  AnyStarFailed = false;
  while (sptr != NULL) {
    doPhotometry(&ccd->Image, sptr->x, sptr->y, sptr->max, &sptr->fwhm,
		 &sptr->skyFlux, &sptr->flux, &sptr->mag, &sptr->magErr);
    sprintf(buffer, "%3d %8s %13.5lf %6.1f %6.1f %8.0f %8.0f "
	    "%5.1f %7.3f +/- %6.3f %6.4f %s %20s\n",
	    starNum, Image->light_frame.UT, HJD, sptr->x, sptr->y,
	    sptr->skyFlux, sptr->flux, sptr->fwhm, sptr->mag,
	    sptr->magErr, AirMass, Image->Filter, ImageFileName);
    StatusPrint(buffer);
    if ((sptr->fwhm < photometrySettings.minFWHM) ||
	(sptr->fwhm > photometrySettings.maxFWHM) || (sptr->mag < 0.0)) {
      StatusPrint("*** WARNING - Skipping measurement of above star...\n");
      AnyStarFailed = true;
      sptr = sptr->next;
      continue;
    }
    if (photometrySettings.logResults) {
      sprintf(buffer, "%3d\t%8s\t%13.5lf\t%6.1f\t%6.1f\t%8.0f\t%8.0f\t"
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


void AddToPhotPlot(int starNum, STAR *sptr, char *UT, double HJD, char Filter)
{
  static int PlotOpen=false, nPoints=0;
  static DIFFPHOT *List=NULL, *dptr;
  DIFFPHOT *pptr;
  int hour, min, sec, i;
  float UTTime, width;
  char pgdevice[80];

  if ((starNum < 0) && (PlotOpen)) {
    cpgclos();
    StatusPrint("*** INFO - Closed photometry plot window...\n");
    PlotOpen = false;
    if (strcmp(photometrySettings.plotHardcopyType, "none") != 0) {
      if (strcmp(photometrySettings.plotHardcopyType,"postscript file") == 0) {
	strcpy(pgdevice,"DiffPhot.ps/PS");
      } else if (strcmp(photometrySettings.plotHardcopyType,"gif file") == 0) {
	strcpy(pgdevice,"DiffPhot.gif/GIF");
      }
      if (cpgbeg(0, pgdevice, 1, 2) != 1) {
	StatusPrint("*** WARNING - Can't open Diff Photo Plot file...\n");
	return;
      }
      cpgscrn(0, "White", &i);
      cpgscrn(1, "Black", &i);
      cpgsci(1);
      DoPhotPlot(List, 0);
      DoPhotPlot(List, 1);
      cpgclos();
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
      if (! PlotOpen) {
	if (cpgbeg(0, "/XWINDOW", 1, 2) != 1) {
	  StatusPrint("*** WARNING - Can't open Photometry Plot window...\n");
	  return;
	}
	cpgask(false);
      }
      width = ((float) nPoints);
      width = 10.0;
      cpgpap(width,0.75);
      cpgeras();
      DoPhotPlot(List, 0);
      DoPhotPlot(List, 1);
      PlotOpen = true;
      break;

    case 1:  /* Save Variable star magnitude */
      dptr = (DIFFPHOT *) malloc(sizeof(DIFFPHOT));
      if (dptr == NULL) {
	StatusPrint("*** WARNING - Can't allocate memory for diff photo.\n");
	photometrySettings.plotResults = false;
	cpgclos();
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
      sscanf(UT, "%2d:%2d:%2d", &hour, &min, &sec);
      UTTime = ((float) hour) + ((float) min)/60.0 + ((float) sec)/3600.0;
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

void DoPhotPlot(DIFFPHOT *List, int whichOne)
{
  DIFFPHOT *pptr;
  float maxdiff, mindiff, maxUT, minUT;
  float diff[1000], diffErr[1000], ut[1000];
  float diffHi[1000], diffLo[1000];
  int i, j, ci, symbol[1000];
  char title[80], xlabel[80];

  pptr = List;
  if (List == NULL) return;
  maxdiff = -999.0;
  mindiff = 999.0;
  maxUT = -999.0;
  minUT = 999.0;
  i = 0;
  while (pptr != NULL) {
    if (whichOne == 0) { /* Do V-C */

      diff[i] = pptr->VarMag - pptr->CmpMag;
      diffErr[i] = sqrt(pptr->VarMagErr*pptr->VarMagErr + 
			pptr->CmpMagErr*pptr->CmpMagErr);

    } else { /* Do K-C */
      diff[i] = pptr->ChkMag - pptr->CmpMag;
      diffErr[i] = sqrt(pptr->ChkMagErr*pptr->ChkMagErr + 
			pptr->CmpMagErr*pptr->CmpMagErr);
    }
    diffHi[i] = diff[i] + diffErr[i];
    diffLo[i] = diff[i] - diffErr[i];
    ut[i] = pptr->UT;
    symbol[i] = pptr->Filter;
    if (diffHi[i] > maxdiff)
      maxdiff = diffHi[i];
    if (diffLo[i] < mindiff)
      mindiff = diffLo[i];
    if (ut[i] < minUT)
      minUT = ut[i];
    if (ut[i] > maxUT)
      maxUT = ut[i];
    i++;
    if (i > 1000) {
      StatusPrint("*** Warning - too many points in DoPhotPlot...\n");
      break;
    }
    pptr = pptr->next;
  }
  maxdiff += 0.05;
  mindiff -= 0.05;
  maxUT += 0.01;
  minUT -= 0.01;
  cpgsch(2.0);
  cpgenv(minUT, maxUT, maxdiff, mindiff, 0, 2);
  if (whichOne == 0) {
    sprintf(title, "Differential Photometry Plot of: %s",
	    ccd->Image.ObjectName);
    sprintf(xlabel, "Observation UT on %7.0lf", floor(List->HJD));
    cpglab(xlabel, "V-C", title);
  } else {
    cpglab(xlabel, "K-C", title);
  }
  for (j=0; j<i; j++) {
    switch (symbol[j]) {
    case 'R':
      ci = 2;
      break;
    case 'V':
      ci = 3;
      break;
    case 'B':
      ci = 4;
      break;
    default:
      ci = 1;
      break;
    }
    cpgsci(ci);
    cpgpt1(ut[j], diff[j], symbol[j]);
  }

  cpgsci(1);
  //  cpgpt(i, ut, diff, 5);
  cpgerry(i, ut, diffLo, diffHi, 1.0);

  return;
}


void on_CurrentWindowDefineListButton_clicked(GtkButton *button,
					      gpointer user_data)
{

  if (DefineListDialog == NULL) {
    DefineListDialog = create_DefineListDialog();
  }

  CurrentStarListSave = CurrentStarList;

  gtk_widget_show(DefineListDialog);
  return;
}


void on_DefineListAddButton_clicked(GtkButton *button, gpointer user_data)
{
  /* Get Current Star's parameters and add to star list */

  AddStar();
  return;
}


void on_DefineListDeleteButton_clicked(GtkButton *button, gpointer user_data)
{
  GtkWidget *widget;
  char *bufptr, buffer[120];
  float starX, starY;
  STAR *sptr;

  /* Get Current Star's parameters */

  widget = lookup_widget(CurrentImageWindow, "CurrentImageStarXEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &starX);
  widget = lookup_widget(CurrentImageWindow, "CurrentImageStarYEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &starY);

  if (CurrentStarList == NULL) {
    StatusPrint("*** WARNING - Can't delete star, list is empty...\n");
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
    StatusPrint("*** Warning - Could find star in list, not deleted...\n");
  } else {
    sprintf(buffer, "*** INFO - Star at: (%5.1f,%5.1f) was deleted...\n",
	    starX, starY);
    StatusPrint(buffer);
  }

  return;
}


void on_DefineListOkayButton_clicked(GtkButton *button, gpointer user_data)
{
  STAR *sptr;
  char buffer[120];
  int nStars;

  sptr = CurrentStarList;

  nStars = 0;
  while (sptr != NULL) {
    nStars++;
    sptr = sptr->next;
  }
  sprintf(buffer, "*** INFO - Star list define with %d stars...\n", nStars);
  StatusPrint(buffer);

  CurrentStarListDefined = true;
  CurrentStarListSave = NULL;

  gtk_widget_hide(DefineListDialog);

  return;
}


void on_DefineListClearButton_clicked(GtkButton *button, gpointer user_data)
{
  clearListStars();
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


void on_PhotometrySettingsBatchButton_clicked(GtkButton *button,
					      gpointer user_data)
{
  char *cptr, buffer[160], dirName[160], fileName[80], command[120];
  int nFiles, success, reTry, answer, len;
  FILE *names_fptr=NULL;

  cptr = strrchr(CurrentImageFileName, '/');
  if (cptr == NULL) {
    StatusPrint("*** WARNING - Can't extract current directory...\n");
    StatusPrint("              Aborting batch image processing...\n");
    return;
  }
  strncpy(dirName, CurrentImageFileName, (cptr-CurrentImageFileName)+1);
  dirName[(cptr-CurrentImageFileName)+1] = 0;

  sprintf(buffer, "*** INFO - Starting batch image processing in dir: %s\n",
	  dirName);
  StatusPrint(buffer);

  nFiles = 0;

  /* Create temp file of fits files */

  unlink("temp.lst");
  sprintf(command, "ls -1 %s/*.fits > temp.lst", dirName);
  system(command);

  /* Open temp file of fits file names */

  names_fptr = fopen("temp.lst","r");
  if (names_fptr == NULL) {
    StatusPrint("*** WARNING - Can't open temp file list file: temp.lst\n");
    return;
  }
  
  reTry = false;
  UserStopBatch = false;
  do {
    if (! reTry) {
      if (fgets(fileName, sizeof(fileName), names_fptr) == NULL)
	break;
      len = strlen(fileName);
      if (len <= 0)
	break;
      fileName[len-1] = 0;
      //      strcpy(buffer,dirName);
      //      strcat(buffer,fileName);
      //      strcpy(fileName,buffer);
      sprintf(buffer,"*** INFO - Processing fits file: %s\n", fileName); 
      StatusPrint(buffer);
      readLight(fileName, &ccd->Image);
      removeHotPixels(&ccd->Image.light_frame);
      loadImageImaging(ccd->Image.light_frame.frame, ccd->Image.light_frame.x,
		       ccd->Image.light_frame.y, ccd->Image.light_frame.w,
		       ccd->Image.light_frame.h,
		       ccd->Image.light_frame.binning);
      ccd->Image.saved = true;
    } else {
      sprintf(buffer,"*** INFO - ReProcessing fits file: %s\n", fileName);
      StatusPrint(buffer);
      reTry = false;
    }
    updateStatusInfo(dummy);
    success = updateListStars(&ccd->Image, CurrentStarList);
    if (! success) {
      sprintf(buffer,"*** WARNING - Aborting batch after file: %s\n",
	      fileName);
      StatusPrint(buffer);
      answer = MessageBox("Want to redefine star list (Yes=redefine, "
			  "No=skip this image, Cancel=Abort)?", YESNO);
      if (answer == CANCEL)
	return;
      else if (answer == YES) {
	clearListStars();
	gtk_widget_show(DefineListDialog);
	while (! CurrentStarListDefined) {
	  gtk_main_iteration_do(false);
	}
	reTry = true;
	continue;
      } else { /* NO */
	reTry = false;
	continue;
      }
      
    }
    success = measureListStars(&ccd->Image, CurrentStarList);
    if (! success) {
      sprintf(buffer,"*** WARNING - Aborting batch after file: %s\n",
	      fileName);
      StatusPrint(buffer);
      answer = MessageBox("Want to redefine star list (Yes=redefine, "
			  "No=skip this image, Cancel=Abort)?", YESNO);
      if (answer == CANCEL)
	return;
      else if (answer == YES) {
	clearListStars();
	gtk_widget_show(DefineListDialog);
	while (! CurrentStarListDefined) {
	  gtk_main_iteration_do(false);
	}
	reTry = true;
	continue;
      } else { /* NO */
	reTry = false;
	continue;
      }
    }
    nFiles++;
    RunMainIteration(0.1);
  } while (! UserStopBatch);

  if (UserStopBatch) {
    sprintf(buffer,
	    "*** INFO - User stopped  batch image processing at file #%d.\n",
	    nFiles);
  } else {
    sprintf(buffer,
	    "*** INFO - Finished batch image processing of %d files.\n",
	    nFiles);
  }
  StatusPrint(buffer);

  return;
}


void on_PhotometrySettingsStopButton_clicked(GtkButton *button,
					     gpointer user_data)
{
  UserStopBatch = true;
  return;
}



void on_DefineListAutoButton_clicked(GtkButton *button, gpointer user_data)
{
  GtkWidget *widget;
  char *DontUse, buffer[80];
  FRAME *frame;
  int x0, y0, x, y, i, j, starMax, Found, npixels, numStars;
  int xmin, xmax, ymin, ymax;
  float starX, starY, fwhm, skyFlux, starFlux, Magnitude, MagErr;
  float rad;

  /* Start with empty star list */

  CurrentStarList = NULL;

  frame = &ccd->Image.light_frame;

  npixels = frame->h * frame->w;
  DontUse = (char *) malloc(npixels);
  bzero(DontUse, npixels);
  x0 = frame->x;
  y0 = frame->y;

  numStars = 0;
  rad = photometrySettings.aperatureRadius;
  for (y=y0+5; y<y0+frame->h-5; y+=10) {
    for (x=x0+5; x<x0+frame->w-5; x+=10) {
      //      if (! *(DontUse+(y-y0)*frame->w + (x-x0))) {
      if (x > 0) {
	Found = FindStar(frame, x-10, y-10, x+10, y+10, &starX, &starY,
			 &starMax);
	sprintf(buffer,"%d", starMax);
	widget = lookup_widget(CurrentImageWindow,"CurrentImageStarMaxEntry");
	gtk_entry_set_text(GTK_ENTRY(widget),buffer);
	if ( (Found) && (starMax >= photometrySettings.minPeak)) {
	  doPhotometry(&ccd->Image, starX, starY, starMax, &fwhm, &skyFlux,
		       &starFlux, &Magnitude, &MagErr);
	  if ((starFlux > 0.0) && (fwhm > photometrySettings.minFWHM) &&
	      (fwhm < photometrySettings.maxFWHM) && (starX-rad > 0.0) &&
	      (starX+rad < x0+frame->w) && (starY-rad > 0.0) &&
	      (starY+rad < y0+frame->h)) {
	    if (! AddStar())
	      continue;
	    numStars++;
	    xmin = (int) rint(starX-5);
	    xmax = (int) rint(starX+5);
	    ymin = (int) rint(starY-5);
	    ymax = (int) rint(starY+5);
	    for (i=xmin; i<=xmax; i++) {
	      if ((i<0) || (i >= x0+frame->w))
		continue;
	      for (j=ymin; j<=ymax; j++) {
		if ((j<0) || (j >= y0+frame->h))
		  continue;
		*(DontUse+(j-y0)*frame->h+(i-x0)) = true;
	      }
	    }
	  }
	}
      }
    }
  }

  return;
}

int AddStar(void)
{
  GtkWidget *widget;
  char *bufptr, buffer[160];
  STAR *sptr, *ptr;
  float min;
  
  sptr = (STAR *) malloc(sizeof(STAR));
  if (sptr == NULL) {
    StatusPrint("*** WARNING - Can't allocate memory for new star...\n");
    return false;
  }

  widget = lookup_widget(CurrentImageWindow, "CurrentImageStarXEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &sptr->x);
  widget = lookup_widget(CurrentImageWindow, "CurrentImageStarYEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &sptr->y);
  widget = lookup_widget(CurrentImageWindow, "CurrentImageStarMaxEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%d", &sptr->max);
  widget = lookup_widget(CurrentImageWindow, "CurrentImageStarFWHMEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &sptr->fwhm);
  widget = lookup_widget(CurrentImageWindow, "CurrentImageStarMagEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f -/+ %f", &sptr->mag, &sptr->magErr);
  widget = lookup_widget(CurrentImageWindow, "CurrentImageStarFluxEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &sptr->flux);
  widget = lookup_widget(CurrentImageWindow, "CurrentImageSkyFluxEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &sptr->skyFlux);

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
	sprintf(buffer,	"*** INFO - Replacing star: (%7.2f,%7.2f), "
		"max: %d, FWHM: %6.2f\n", sptr->x, sptr->y, sptr->max,
		sptr->fwhm);
	StatusPrint(buffer);
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

  sprintf(buffer,
	  "*** INFO - Adding star: (%7.2f,%7.2f), max: %d, FWHM: %6.2f\n",
	  sptr->x, sptr->y, sptr->max, sptr->fwhm);
  StatusPrint(buffer);

  return true;
}


/* void on_SlitGuidingOnCheckButton_toggled(GtkToggleButton *togglebutton, */
/* 					 gpointer user_data) */
/* { */

int SendTCS200IS400(int port)
{
  char Message[160], buffer[160];
  size_t msgsiz;
  int msgflg, istat;
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
      return false;
    } else {
      sprintf(Message, "*** INFO - Got TCS200 message queue: %d\n", queueID);
      StatusPrint(Message);
    }
  }

  /* Send TCS200 message to change instrument port */

  sprintf(Message, ":I %d", port);
  strcpy(msg.mtext, Message);
  msg.mtype = MTYPE_TO_SCOPE;
  msgsiz = strlen(Message) + 1;
  msgflg = IPC_NOWAIT;
  istat = msgsnd(queueID, &msg, msgsiz, msgflg);
  if (istat < 0) {
    StatusPrint("*** WARNING - Can't send message to TCS200\n");
  } else {
    sprintf(buffer, "*** INFO - Sent message to TCS200: %s\n", Message);
    StatusPrint(buffer);
  }

  RunMainIteration(3.0);   /* Wait for selector to move */

  return true;
}


void on_SeriesSettingsAutoBumpButton_toggled(GtkToggleButton *togglebutton,
					     gpointer user_data)
{
  seriesSettings.AutoBumpScope = gtk_toggle_button_get_active(togglebutton);
  return;
}


void AutoBumpScope(STAR *starList)
{
  STAR *sptr, *bptr, *ptr;
  int numStars;
  double delXSum, delYSum, DeltaRA, DeltaDEC, deltaX, deltaY;

  // If 1st time, define base star positions & exit (no bump 1st time)

  printf("*** DEBUG - Starting AutoBumpScope\n");
  fflush(stdout);
  if (baseStarList == NULL) {
    printf("*** DEBUG - Saving base star list\n");
    fflush(stdout);
    sptr = starList;
    while (sptr != NULL) {
      bptr = (STAR *) malloc(sizeof(STAR));
      if (bptr == NULL) {
	StatusPrint("*** Warning - Can' allocate memory for star list,"
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
    printf("*** DEBUG - Got AutoBumpScope\n");
    fflush(stdout);
  } else {

    // Computer average star offset in current frame

    bptr = baseStarList;
    sptr = starList;

    delXSum = 0.0;
    delYSum = 0.0;
    numStars = 0;
    printf("*** DEBUG - Computing average offset\n");
    fflush(stdout);
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
    printf("*** DEBUG - Offsets: %d %f %f\n", numStars, deltaX, deltaY);
    fflush(stdout);


    DeltaRA = (deltaX*GuidingSlitSettings.XScale)/cos(ScopeDEC*3.14159/180.0);
    DeltaDEC = (deltaY*GuidingSlitSettings.YScale);

    printf("*** DEBUG - Offsets(arcsec): %d %f %f\n", numStars,
	   DeltaRA, DeltaDEC);
    fflush(stdout);

    // Move scope

    SendTCS200Step(DeltaRA, DeltaDEC);
    RunMainIteration(5.0);  // wait 5 secs
  }

  return;
}

void on_guiding_slit_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  if (GuideFrameWindow == NULL) {
    GuideFrameWindow = create_GuideFrameWindow();
  }

  gtk_widget_show(GuideFrameWindow);

  return;
}


void on_show_guiding_window_activate(GtkMenuItem *menuitem, gpointer user_data)
{

  if (GuideFrameWindow != NULL) {
    gtk_widget_show(GuideFrameWindow);
  }

  return;
}


void on_GuidingSlitSettingsDialogOkButton_clicked(GtkButton *button,
						  gpointer user_data)
{
  char *bufptr, message[120];
  float val;
  int ival;
  GtkWidget *widget;

  gtk_widget_hide(GuidingSlitSettingsDialog);

  // Get dialog values

  widget = lookup_widget(GuidingSlitSettingsDialog,"SlitX0Entry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%d", &ival);
  if ((ival < 0.0) || ival > 190) {
    sprintf(message,"*** Warning - SlitX0 value (%d) out of range, "
	    "using default\n", ival);
    StatusPrint(message);
    ival = DEFAULTSLITX0;
  }
  GuidingSlitSettings.slitX0 = ival;

  widget = lookup_widget(GuidingSlitSettingsDialog,"SlitY0Entry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%d", &ival);
  if ((ival < 0.0) || ival > 162) {
    sprintf(message,"*** Warning - SlitY0 value (%d) out of range, "
	    "using default\n", ival);
    StatusPrint(message);
    ival = DEFAULTSLITY0;
  }
  GuidingSlitSettings.slitY0 = ival;

  widget = lookup_widget(GuidingSlitSettingsDialog,"SlitX1Entry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%d", &ival);
  if ((ival < 0.0) || ival > 190) {
    sprintf(message,"*** Warning - SlitX1 value (%d) out of range, "
	    "using default\n", ival);
    StatusPrint(message);
    ival = DEFAULTSLITX1;
  }
  GuidingSlitSettings.slitX1 = ival;

  widget = lookup_widget(GuidingSlitSettingsDialog,"SlitY1Entry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%d", &ival);
  if ((ival < 0.0) || ival > 162) {
    sprintf(message,"*** Warning - SlitY1 value (%d) out of range, "
	    "using default\n", ival);
    StatusPrint(message);
    ival = DEFAULTSLITY1;
  }
  GuidingSlitSettings.slitY1 = ival;

  widget = lookup_widget(GuidingSlitSettingsDialog,"GuidingIntervalEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &val);
  if ((val < 0.0) || val > 300.0) {
    sprintf(message,"*** Warning - Guiding interval (%f) out of range, "
	    "using default\n", val);
    StatusPrint(message);
    val = DEFAULTGUIDINGINTERVAL;
  }
  GuidingSlitSettings.interval = val;

  widget = lookup_widget(GuidingSlitSettingsDialog,"ExposureTimeEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &val);
  if ((val < 0.0) || val > 60.0) {
    sprintf(message,"*** Warning - Exposure time (%f) out of range, "
	    "using default\n", val);
    StatusPrint(message);
    val = DEFAULTGUIDINGEXPTIME;
  }
  GuidingSlitSettings.exposure = val;

  widget = lookup_widget(GuidingSlitSettingsDialog,"XScaleEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &val);
  if ((val < 0.0) || val > 15.0) {
    sprintf(message,"*** Warning - X Pixel scale (%f) out of range, "
	    "using default\n", val);
    StatusPrint(message);
    val = DEFAULTGUIDINGXPIXELSCALE;
  }
  GuidingSlitSettings.XScale = val;

  widget = lookup_widget(GuidingSlitSettingsDialog,"YScaleEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &val);
  if ((val < 0.0) || val > 15.0) {
    sprintf(message,"*** Warning - Y Pixel scale (%f) out of range, "
	    "using default\n", val);
    StatusPrint(message);
    val = DEFAULTGUIDINGYPIXELSCALE;
  }
  GuidingSlitSettings.YScale = val;

  gtk_widget_hide(GuidingSlitSettingsDialog);
  return;
}


void on_GuidingSlitSettingsDialogCancelButton_clicked(GtkButton *button,
						      gpointer user_data)
{
  memcpy(&GuidingSlitSettings, &GuidingSlitSettings_save,
	 sizeof(GUIDINGSLITSETTINGS));
  gtk_widget_hide(GuidingSlitSettingsDialog);

  return;
}


void on_GuideFrameWindowCloseButton_clicked(GtkButton *button,
					    gpointer user_data)
{
  gtk_widget_hide(GuideFrameWindow);

  return;
}


void on_GuideFrameWindowSelectButton_clicked(GtkButton *button,
					     gpointer user_data)
{
  GtkWidget *widget;
  char *bufptr;

  // Get current star's position

  widget = lookup_widget(GuideFrameWindow, "GuideFrameWindowStarXEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &GuidingSlitSettings.TargetX);
  widget = lookup_widget(GuideFrameWindow, "GuideFrameWindowStarYEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &GuidingSlitSettings.TargetY);
  widget = lookup_widget(GuideFrameWindow, "GuideFrameWindowStarMaxEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &GuidingSlitSettings.TargetMax);

  return;
}


void on_GuideFrameWindowSettingsButton_clicked(GtkButton *button,
					       gpointer user_data)
{
  char buffer[120];
  GtkWidget *widget;

  if (GuidingSlitSettingsDialog == NULL) {
    GuidingSlitSettingsDialog = create_GuidingSlitSettingsDialog();
  }

  // Save settings in case cancel clicked

  memcpy(&GuidingSlitSettings_save,&GuidingSlitSettings,
	 sizeof(GUIDINGSLITSETTINGS));

  // Set dialog's objects

  widget = lookup_widget(GuidingSlitSettingsDialog,"SlitX0Entry");
  sprintf(buffer,"%d", GuidingSlitSettings.slitX0);
  gtk_entry_set_text(GTK_ENTRY(widget),buffer);

  widget = lookup_widget(GuidingSlitSettingsDialog,"SlitY0Entry");
  sprintf(buffer,"%d", GuidingSlitSettings.slitY0);
  gtk_entry_set_text(GTK_ENTRY(widget),buffer);

  widget = lookup_widget(GuidingSlitSettingsDialog,"SlitX1Entry");
  sprintf(buffer,"%d", GuidingSlitSettings.slitX1);
  gtk_entry_set_text(GTK_ENTRY(widget),buffer);

  widget = lookup_widget(GuidingSlitSettingsDialog,"SlitY1Entry");
  sprintf(buffer,"%d", GuidingSlitSettings.slitY1);
  gtk_entry_set_text(GTK_ENTRY(widget),buffer);

  widget = lookup_widget(GuidingSlitSettingsDialog, "GuidingIntervalEntry");
  sprintf(buffer,"%5.1f", GuidingSlitSettings.interval);
  gtk_entry_set_text(GTK_ENTRY(widget),buffer);

  widget = lookup_widget(GuidingSlitSettingsDialog,"ExposureTimeEntry");
  sprintf(buffer,"%5.1f", GuidingSlitSettings.exposure);
  gtk_entry_set_text(GTK_ENTRY(widget),buffer);

  widget = lookup_widget(GuidingSlitSettingsDialog,"XScaleEntry");
  sprintf(buffer,"%5.2f", GuidingSlitSettings.XScale);
  gtk_entry_set_text(GTK_ENTRY(widget),buffer);

  widget = lookup_widget(GuidingSlitSettingsDialog,"YScaleEntry");
  sprintf(buffer,"%5.2f", GuidingSlitSettings.YScale);
  gtk_entry_set_text(GTK_ENTRY(widget),buffer);

  gtk_widget_show(GuidingSlitSettingsDialog);

  return;
}




int autoGuider(gpointer data) 
{ 
  static int Busy=false;
  GtkWidget *widget;
  char buffer[80];
  int max, xmin, xmax, ymin, ymax, Found, gotFrame;
  float diffMax, StarX, StarY;
  double deltaX, deltaY, DeltaRA, DeltaDEC;
  //  FRAME *frame;

  if (Busy || ImagingDownloadInProgress)
    return true;

  Busy = true;
  if (GuidingSlitSettings.Running == false) {  // Turn off guiding
    Busy = false;
    return false;
  }

  // Acquire guiding frame

  StatusPrint("*** INFO - Acquiring autoguiding frame\n");

  DontShowGuidingProgress = true;
  gotFrame = AcquireGuideFrame(&guideImage, &guideImageSettings);
  DontShowGuidingProgress = false;
  if (! gotFrame) {
    Busy = false;
    return true;   // skip this one, but keep trying
  }

  // Find star in new image and target-star difference

  max = 0;
  /*   xmin = guideImageSettings.x; */
/*   ymin = guideImageSettings.y; */
/*   xmax = guideImageSettings.x + guideImageSettings.w; */
/*   ymax = guideImageSettings.y + guideImageSettings.h; */
  xmin = (int) rint(GuidingSlitSettings.TargetX - 10);
  xmax = xmin + 20;
  ymin = (int) rint(GuidingSlitSettings.TargetY - 10);
  ymax = ymin + 20;
  Found = FindStar(&guideImage.light_frame, xmin, ymin, xmax, ymax,
		   &StarX, &StarY, &max);

  // Debuging simulation section

  if (! Found) {
    StatusPrint("*** Debug - Guide star not found...\n");
    Busy = false;
    return true;  // skip this bad image, but try again
  }

/*   StarX = GuidingSlitSettings.TargetX; */
/*   StarY = GuidingSlitSettings.TargetY; */


  diffMax = GuidingSlitSettings.TargetMax - max;
  diffMax = fabs(diffMax)/GuidingSlitSettings.TargetMax;

  // Compute target - star difference in pixels

  deltaX = (GuidingSlitSettings.TargetX - StarX);
  deltaY = - (GuidingSlitSettings.TargetY - StarY);
  DeltaRA = (deltaX * GuidingSlitSettings.XScale)/cos(ScopeDEC*3.14159/180.0);
  DeltaDEC = (deltaY * GuidingSlitSettings.YScale);

  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowXOffsetEntry");
  sprintf(buffer, "%4.1f", DeltaRA);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);
  widget = lookup_widget(GuideFrameWindow,"GuideFrameWindowYOffsetEntry");
  sprintf(buffer, "%4.1f", DeltaDEC);
  gtk_entry_set_text(GTK_ENTRY(widget), buffer);
 
  sprintf(buffer, "*** DEBUG - DelRA: %f, DelDEC: %f\n", DeltaRA, DeltaDEC);
  StatusPrint(buffer);
  
  if ((fabs(DeltaRA) > 0.5) || (fabs(DeltaDEC) > 0.5)) {
    StatusPrint("*** DEBUG - Telling scope to move...\n");
    SendTCS200Step(DeltaRA, DeltaDEC);
  }

  Busy = false;
  return true;
}



void on_GuidingFrameWindowOnOffButton_toggled(GtkToggleButton *togglebutton,
					      gpointer user_data)
{
  static guint guidingTimerID;
  GtkWidget *widget;
  char *bufptr;
  int answer, intervalms, state;

  state = gtk_toggle_button_get_active(togglebutton);

  // Turn on guiding

  if (state) {
    answer = MessageBox("Sure you want to start auto guiding?", YESNO);
    if (answer != YES)
      return;
    GuidingSlitSettings.Running = true;

    // Get guide star info

    widget = lookup_widget(GuideFrameWindow, "GuideFrameWindowStarXEntry");
    bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
    sscanf(bufptr, "%f", &GuidingSlitSettings.TargetX);
    widget = lookup_widget(GuideFrameWindow, "GuideFrameWindowStarYEntry");
    bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
    sscanf(bufptr, "%f", &GuidingSlitSettings.TargetY);
    widget = lookup_widget(GuideFrameWindow, "GuideFrameWindowStarMaxEntry");
    bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
    sscanf(bufptr, "%f", &GuidingSlitSettings.TargetMax);

    // Save guiding image settings

    memcpy(&guideImageSettings_Save, &guideImageSettings,
	   sizeof(SINGLESETTINGS));

    // Setup so only 60x60 pixel box centered on target is readout

/*     guideImageSettings.x = GuidingSlitSettings.TargetX - 30; */
/*     if (guideImageSettings.x < 0) */
/*       guideImageSettings.x = 0; */
/*     if (guideImageSettings.x+60 > guideImageSettings.w) */
/*       guideImageSettings.x = guideImageSettings.w - 60; */
/*     guideImageSettings.w = 60; */

/*     guideImageSettings.y = GuidingSlitSettings.TargetY - 30; */
/*     if (guideImageSettings.y < 0) */
/*       guideImageSettings.y = 0; */
/*     if (guideImageSettings.y+60 > guideImageSettings.h) */
/*       guideImageSettings.y = guideImageSettings.h - 60; */
/*     guideImageSettings.h = 60; */

    // Start timer to do guiding

    autoGuider(NULL);
    intervalms = ((int) (GuidingSlitSettings.interval * 1000.0));
    guidingTimerID = gtk_timeout_add(intervalms, autoGuider, NULL);

  } else {

    // Turn off slit guiding

    answer = MessageBox("Sure you want to end auto guiding?", YESNO);
    if (answer != YES)
      return;
    GuidingSlitSettings.Running = false;
    gtk_timeout_remove(guidingTimerID);

    // Restore guiding image settings

    memcpy(&guideImageSettings, &guideImageSettings_Save,
	   sizeof(SINGLESETTINGS));
  }

  return;
}


void on_GuidingFrameWindowToSlit_clicked(GtkButton *button,
					 gpointer user_data)
{
  GtkWidget *widget;
  char *bufptr, Message[160];
  float StarX, StarY, StarMax, deltaX, deltaY, diffMax, slitX, slitY;
  double DeltaRA, DeltaDEC;
  int xmin, xmax, ymin, ymax, Found, max, nIterations;
  int gotFrame, success;
  FRAME *frame;

  slitX = (GuidingSlitSettings.slitX1 + GuidingSlitSettings.slitX0) / 2.0;
  slitY = (GuidingSlitSettings.slitY1 + GuidingSlitSettings.slitY0) / 2.0;
  frame = &guideImage.light_frame;
  xmin = (int) rint(slitX - 30);
  if (xmin < frame->x)
    xmin = frame->x;
  xmax = (int) rint(slitX + 30);
  if (xmax > (frame->x+frame->w))
    xmax = frame->x + frame->w;
  ymin = (int) rint(slitY - 30);
  if (ymin < frame->y)
    ymin = frame->y;
  ymax = (int) rint(slitY + 30);
  if (ymax > (frame->y+frame->h))
    ymax = frame->y + frame->h;

  // Get current object position
  
  widget = lookup_widget(GuideFrameWindow, "GuideFrameWindowStarXEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &StarX);
  widget = lookup_widget(GuideFrameWindow, "GuideFrameWindowStarYEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &StarY);
  widget = lookup_widget(GuideFrameWindow, "GuideFrameWindowStarMaxEntry");
  bufptr = (gchar *) gtk_entry_get_text(GTK_ENTRY(widget));
  sscanf(bufptr, "%f", &StarMax);

  // Compute slit - star difference in pixels

  deltaX = (slitX - StarX);
  deltaY = - (slitY - StarY);
  DeltaRA = (deltaX * GuidingSlitSettings.XScale)/cos(ScopeDEC*3.14159/180.0);
  DeltaDEC = (deltaY * GuidingSlitSettings.YScale);

  nIterations = 0;
  while (((fabs(DeltaRA)>1.0) || (fabs(DeltaDEC)>1.0)) &&
	 (nIterations < 5)) {

    // Send command to move scope 

    success = SendTCS200Step(DeltaRA, DeltaDEC);
    if (! success) {
      StatusPrint("*** WARNING - Couldn't move scope, aborting 'to slit'\n");
      return;
    }
    RunMainIteration(5.0);

    // Take new image and see how close we got

    gotFrame = AcquireGuideFrame(&guideImage, &guideImageSettings);
    if (! gotFrame) {
      StatusPrint("*** WARNING - Can't acquire new slit image, "
		  "aborting 'to slit' process\n");
      return;
    }
    max = 0;
    Found = FindStar(&guideImage.light_frame, xmin, ymin, xmax, ymax,
		     &StarX, &StarY, &max);
    diffMax = StarMax - max;
    diffMax = fabs(diffMax)/((float) StarMax);
    //    if ((! Found) || (diffMax > 0.50)) {
    if (! Found) {
      sprintf(Message, "*** WARNING - Lost star, aborting centering"
		  " on slit (%f,%d,%f)\n", StarMax, max, diffMax);
      StatusPrint(Message);
      return;
    }
    nIterations++;

    // Compute slit star difference in pixels

    deltaX = (slitX - StarX);
    deltaY = -(slitY - StarY);
    DeltaRA = (deltaX*GuidingSlitSettings.XScale)/cos(ScopeDEC*3.14159/180.0);
    DeltaDEC = (deltaY*GuidingSlitSettings.YScale);

  };
    
  return;

}


void on_GuidingFrameWindowCalSlitButton_clicked(GtkButton *button,
						gpointer user_data)
{
  char Message[120];
  FRAME *frame;
  int h, w, minX, minY, maxX, maxY, y, x, minVal, pixval;
  int xAtMin, ipix;

  // Find position of slit at each row by looking for lowest pixel value in
  // 1st and last rows

  frame = &guideImage.light_frame;
  h = guideImage.light_frame.h;
  w = guideImage.light_frame.w;
  minX = guideImage.light_frame.x;
  minY = guideImage.light_frame.y;
  maxX = minX + w;
  maxY = minY + h - 2;

  for (y=minY; y<=maxY; y+=maxY) {
    minVal = 99999;
    xAtMin = 0;
    for (x=minX; x<=maxX; x++) {
      ipix = (y-minY) * w + (x-minX);
      pixval = frame->frame[ipix];
      if (pixval < minVal) {
	minVal = pixval;
	xAtMin = x;
      }
    }
    if (y == minY) {
      GuidingSlitSettings.slitX0 = xAtMin;
      GuidingSlitSettings.slitY0 = y;
    } else {
      GuidingSlitSettings.slitX1 = xAtMin;
      GuidingSlitSettings.slitY1 = y;
    }
  }

  sprintf(Message, "*** INFO - New slit 'end' positions: (%d,%d) - (%d,%d)\n",
	  GuidingSlitSettings.slitX0, GuidingSlitSettings.slitY0,
	  GuidingSlitSettings.slitX1, GuidingSlitSettings.slitY1);
  StatusPrint(Message);

  return;
}


void on_GuideFrameWindowApplyButton_clicked(GtkButton *button,
					    gpointer user_data)
{
  UpdateGuideImage();
  
  return;
}


void on_GuideFrameWindowLogButton_toggled(GtkToggleButton *togglebutton,
					  gpointer user_data)
{

}


void on_GuideFrameWindowExposeButton_clicked(GtkButton *button,
					     gpointer user_data)
{
  int gotFrame;

  // Get current guiding images settings

  guideImageSettings.exposureTime = GuidingSlitSettings.exposure;

  gotFrame = AcquireGuideFrame(&guideImage, &guideImageSettings);

  return;
}


int AcquireGuideFrame(IMAGE *Image, SINGLESETTINGS *Settings)
{
  static int Busy=false;
  int status, i, d, nbytes, darkNeeded, gotDark, success;
  char Message[80];
  double ccd_temp, dark_temp;
  StartExposureParams expose;
  StartReadoutParams readout;

  if (!ccd->Linked) {
    StatusPrint("*** WARNING - Can't start exposure, link to camera first.\n");
    return 0;
  }

  if (Busy) {
    StatusPrint("*** Warning - Guide ccd busy, try again later...\n");
    return false;
  }

  Busy = true;
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
    StatusPrint("*** WARNING - Can't get ccd temperature, "
		"aborting exposure...\n");
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
  Image->light_frame.temp = ccd_temp;
  Image->light_frame.exposure = Settings->exposureTime;
  Image->Filter[0] = 'C';
  Image->Filter[1] = '\000';
  dark_temp = Image->dark_frame.temp;
  strcpy(Image->light_frame.UT,"");
  strcpy(Image->light_frame.UTDATE,"");
  strcpy(Image->dark_frame.UT,"");
  strcpy(Image->dark_frame.UTDATE,"");

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
	sprintf(Message,"*** Warning - Couldn't find compatible dark frame"
		"in directory: %s aborting\n", Settings->DarkDir);
	StatusPrint(Message);
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
  Image->light_frame.frame = (unsigned short *)
    realloc(Image->light_frame.frame, nbytes);

  Image->dark_frame.frame = (unsigned short *)
    realloc(Image->dark_frame.frame, nbytes);

  /* Check if dark frame needed */

  if ((Settings->darkOption == 1) ||
      (Settings->darkOption == 3)) {
    darkNeeded = ((fabs(dark_temp-ccd_temp) > MAXTEMPDIFF) ||
		  (! Image->dark_frame.active) ||
		  (Image->dark_frame.exposure !=
		   Settings->exposureTime) ||
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

  loadImageTracking(Image->light_frame.frame, Image->light_frame.x,
		    Image->light_frame.y, Image->light_frame.w,
		    Image->light_frame.h, Image->light_frame.binning);
  
  Image->saved = false;
  Image->Filter[0] = 'C';
  Image->Filter[1] = '\000';
  strcpy(Image->FileName,"");
  strcpy(Image->ObjectName,"");

  Busy = false;
  return true;
}

gboolean on_GuideFrameWindowDrawingArea_button_press_event(GtkWidget *widget,
							GdkEventButton *event,
							gpointer user_data)
{
  int xmin, ymin, xmax, ymax;
  float x, y, FWHM;
  float Magnitude, MagErr, SkyFlux, StarFlux;
  int max, Found;
  GtkWidget *Entry;
  char buffer[80];

  if (event->button == 1) {
  } else if (event->button == 3) {
    xmin = (int) rint(event->x - photometrySettings.findRadius);
    if (xmin < 0)
      xmin = 0;
    ymin = (int) rint(event->y - photometrySettings.findRadius);
    if (ymin < 0)
      ymin = 0;
    xmax = (int) rint(event->x + photometrySettings.findRadius);
    if (xmax > guideImage.light_frame.w)
      xmax = guideImage.light_frame.w;
    ymax = (int) rint(event->y + photometrySettings.findRadius);
    if (ymax > guideImage.light_frame.h)
      ymax = guideImage.light_frame.h;
    Found = FindStar(&guideImage.light_frame, xmin, ymin, xmax, ymax,
		     &x, &y, &max);
    if (Found) {
      sprintf(buffer,"%f", x);
      Entry = lookup_widget(GuideFrameWindow,"GuideFrameWindowStarXEntry");
      gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
      sprintf(buffer,"%f", y);
      Entry = lookup_widget(GuideFrameWindow,"GuideFrameWindowStarYEntry");
      gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
      sprintf(buffer,"%d", max);
      Entry = lookup_widget(GuideFrameWindow,"GuideFrameWindowStarMaxEntry");
      gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
      doPhotometry(&guideImage, x, y, max, &FWHM, &SkyFlux, &StarFlux,
		   &Magnitude, &MagErr);
      sprintf(buffer,"%6.2f", FWHM);
      Entry = lookup_widget(GuideFrameWindow,"GuideFrameWindowStarFWHMEntry");
      gtk_entry_set_text(GTK_ENTRY(Entry),buffer);
      sprintf(buffer,"%8.0f", StarFlux);
      Entry = lookup_widget(GuideFrameWindow,"GuideFrameWindowStarSumEntry");
      gtk_entry_set_text(GTK_ENTRY(Entry),buffer);

    }
  }

  return false;
}


gboolean on_GuideFrameWindowDrawingArea_button_release_event(GtkWidget *widget,
							GdkEventButton *event,
							gpointer user_data)
{

  return false;
}


gboolean on_GuideFrameWindowDrawingArea_configure_event(GtkWidget *widget,
						     GdkEventConfigure *event,
						     gpointer user_data)
{

  return false;
}


gboolean on_GuideFrameWindowDrawingArea_expose_event(GtkWidget *widget,
						     GdkEventExpose  *event,
						     gpointer user_data)
{
  if ((! guideImage.light_frame.active) &&
      (! guideImage.dark_frame.active))
    return true;
  gdk_draw_rgb_image(widget->window, widget->style->fg_gc[GTK_STATE_NORMAL],
		     0, 0, RGBGuidew, RGBGuideh, GDK_RGB_DITHER_MAX,
		     RGBGuideBuf, RGBGuidew*3);
  return true;

  return false;
}


gboolean on_GuideFrameWindowDrawingArea_motion_notify_event(GtkWidget *widget,
						       GdkEventMotion  *event,
						       gpointer user_data)
{
  char buffer[30];
  int i, j, pixel, x, y;
  GtkWidget *entry;

  i = ((int) event->x);
  j = ((int) event->y);
  x = guideImage.light_frame.x;
  y = guideImage.light_frame.y;

  entry = lookup_widget(GuideFrameWindow,"GuideFrameWindowCurXEntry");
  sprintf(buffer,"%d", i);
  gtk_entry_set_text(GTK_ENTRY(entry),buffer);

  entry = lookup_widget(GuideFrameWindow,"GuideFrameWindowCurYEntry");
  sprintf(buffer,"%d", j);
  gtk_entry_set_text(GTK_ENTRY(entry),buffer);

  entry = lookup_widget(GuideFrameWindow,"GuideFrameWindowCurValEntry");
  if (guideImage.light_frame.frame == NULL)
    return false;
  if ((i >= guideImage.light_frame.w+x)  || (i < x) ||
      (j >= guideImage.light_frame.h+y) || (j < y))
    return false;
  pixel = guideImage.light_frame.w * (j-y) + (i-x);
  sprintf(buffer,"%d", guideImage.light_frame.frame[pixel]);
  gtk_entry_set_text(GTK_ENTRY(entry), buffer);

  return false;
}


void on_GuidingProgressDialogCancelButton_clicked(GtkButton *button,
						  gpointer user_data)
{
  CancelCurrentGuidingAcquire = true;
  return;
}


void on_cameras_settings_activate(GtkMenuItem *menuitem, gpointer user_data)
{
  GtkWidget *entry;

  if (CameraSettingsDialog == NULL) {
    CameraSettingsDialog = create_CameraSettingsDialog();
  }

  // Set the values of the dialogs items

  entry = lookup_widget(CameraSettingsDialog, "ImagingCCDTypeComboEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), ccdSettings.ImagingType);

  entry = lookup_widget(CameraSettingsDialog, "ImagingCCDPortComboEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), ccdSettings.ImagingPort);

  entry = lookup_widget(CameraSettingsDialog, "SpectroCCDTypeComboEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), ccdSettings.SpectroType);

  entry = lookup_widget(CameraSettingsDialog, "SpectroCCDPortComboEntry");
  gtk_entry_set_text(GTK_ENTRY(entry), ccdSettings.SpectroPort);

  gtk_widget_show(CameraSettingsDialog);

  return;
}


void on_CameraSettingsDialogOKButton_clicked(GtkButton *button,
					     gpointer user_data)
{
  GtkWidget *entry;
  char *bufptr;

  entry = lookup_widget(CameraSettingsDialog, "ImagingCCDTypeComboEntry");
  bufptr = (char *) gtk_entry_get_text(GTK_ENTRY(entry));
  strcpy(ccdSettings.ImagingType,bufptr);

  entry = lookup_widget(CameraSettingsDialog, "ImagingCCDPortComboEntry");
  bufptr = (char *) gtk_entry_get_text(GTK_ENTRY(entry));
  strcpy(ccdSettings.ImagingPort,bufptr);

  entry = lookup_widget(CameraSettingsDialog, "SpectroCCDTypeComboEntry");
  bufptr = (char *) gtk_entry_get_text(GTK_ENTRY(entry));
  strcpy(ccdSettings.SpectroType,bufptr);

  entry = lookup_widget(CameraSettingsDialog, "SpectroCCDPortComboEntry");
  bufptr = (char *) gtk_entry_get_text(GTK_ENTRY(entry));
  strcpy(ccdSettings.SpectroPort,bufptr);

  gtk_widget_hide(CameraSettingsDialog);

  return;
}


void on_CameraSettingsDialogCancelButton_clicked(GtkButton *button,
						 gpointer user_data)
{
  gtk_widget_hide(CameraSettingsDialog);

  return;
}

