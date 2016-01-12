#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

#include <time.h>
#include "longnam.h"
#include "fitsio.h"
#include "CameraCode/SBig/sbigudrv.h"
#include "sxpress_msg.h"
#include "sxpress.h"
#include "defines.h"

namespace CCDAuto {

	using namespace System;

#define OBJECTLISTFILE "Objects.lst"  /* Text file of list of objects */
#define LONGITUDE 84.086241 /* longitude of OSUROB */
#define LATITUDE 40.721140 /* latitude of OSUROB */

#define TRUE 1
#define FALSE 0
#define RED 0
#define GREEN 1
#define BLUE 2
#define NUMFILTERS 6
#define MAXCOOLPOWER 255.0
#define CCDGAIN 2.68
#define READNOISE 18.6
#define TIMEZONE 8
#define OBSERVER "A. Shoup"
#define EPOCH 2000
#define OBJECTLISTFILE "Objects.lst"
#define OBSERVATORY "UCIROB"
#define MAXNUMOBJECTS 1000
#define MAXTEMPDIFF 1.0
//#define IMAGINGPORT 0x378
#define IMAGINGPORT "sbigusb0"
#define SPECTROPORT "sbiglpt1"

#define SBIG_MAKE 0
#define APOGEE_MAKE 1
#define SXPRESS_MAKE 2

#define DEFAULTGUIDINGXPIXELSCALE 0.83
#define DEFAULTGUIDINGYPIXELSCALE 0.83
#define DEFAULTGUIDINGINTERVAL 20.0
#define DEFAULTGUIDINGEXPTIME 5.0
#define DEFAULTSLITX0 75
#define DEFAULTSLITY0 0
#define DEFAULTSLITX1 87
#define DEFAULTSLITY1 160

#define DEFAULTIMAGECCDTYPE "Apogee - AP-47P"
#define DEFAULTIMAGECCDPORT "LPT1"
#define DEFAULTSPECTROCCDTYPE "Apogee - AP-47P"
#define DEFAULTSPECTROCCDPORT "LPT1"

#define APOGEE_STATUS_IDLE 0
#define APOGEE_STATUS_WAITINGFORTRIGGER 1
#define APOGEE_STATUS_EXPOSING 2
#define APOGEE_STATUS_DOWNLOADING 3
#define APOGEE_STATUS_LINEREADY 4
#define APOGEE_STATUS_IMAGEREADY 5
#define APOGEE_STATUS_FLUSHINGBIR 6

//#define PI 3.141592654
#define HALFPI 1.570796327

// Measurement Computing DIO Board #

#define USB1024BOARD0 0

#define OKAY 5

typedef struct _MARKSTAR {
	float x;
	float y;
	struct _MARKSTAR *next;
} MARKSTAR;

typedef struct {
  int slitX0;
  int slitY0;
  int slitX1;
  int slitY1;
  float interval;
  float exposure;
  float Running;
  float XScale;
  float YScale;
  float TargetX;
  float TargetY;
  float TargetMax;
  float lastOffsetX;
  float lastOffsetY;
} GUIDINGSLITSETTINGS;

typedef struct {
  int numStars;
  double pixelX[100];
  double pixelY[100];
  double RA[100];
  double Dec[100];
} PLATESTARS;

typedef struct {
  double coeffs[6];
  int status;
} PLATESOLU;


typedef struct _DIFFPHOT {
  float VarMag, VarMagErr;
  float CmpMag, CmpMagErr;
  float ChkMag, ChkMagErr;
  float UT;
  double HJD;
  char Filter;
  struct _DIFFPHOT *next;
  struct _DIFFPHOT *prev;
} DIFFPHOT;

typedef struct _PIXCELL{
  float val;
  float x, y, r;
  struct _PIXCELL *next;
} PIXCELL;

typedef struct _STAR {
  int found;
  int measured;
  int max;
  float x, y;
  float ra, dec;
  float fwhm;
  float mag;
  float magErr;
  float flux;
  float skyFlux;
  struct _STAR *next;
  struct _STAR *prev;
} STAR;

typedef struct {
  unsigned int Use[NUMFILTERS];
  float exposures[NUMFILTERS];
} FILTERSET;


/* typedef struct {
  Display  *display;
  ImlibData *im;
  ImlibImage *image;
  Window  window;
} X_INFO; */

typedef struct {
  int x,y,h,w;
  int whichCCD;
  int binning;
  int active;
  float temp;
  time_t time; // Should be redeclared as system time type
  char UT[20];
  char UTDATE[20];
  float exposure;
  unsigned short *frame;
} FRAME;

typedef struct {
  char Filter[2];     /* UBVRI */
  char FileName[160];
  char ObjectName[21];
  int saved;
  int darkOnly;
  int lightOnly;
  FRAME light_frame;
  FRAME dark_frame;
} IMAGE;

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

typedef struct {
  char name[80];
  char port[80];
  unsigned short make;
  int Linked;
  float Temp;
  int TempOn;
  int FanOn;
  int filterPosition;
  int ExposureInProgress;
  int DownLoadInProgress;
  int Busy;
  GetCCDInfoResults0 info;
  GetCCDInfoResults0 info1;
  GetCCDInfoResults2 info2;
  GetCCDInfoResults3 info3;
  MX_SXV_INFO mx_sxv_info;
  APOGEE_INFO apogee_info;
  IMAGE Image;
  IMAGE FlatImage;
} CCD;

typedef struct {
  char ImagingType[80];
  char ImagingPort[80];
  char SpectroType[80];
  char SpectroPort[80];
} CCDSETTINGS;

typedef struct {
  char ObjectName[21];
  char ImageDir[81];
  char DarkDir[161];
  char FlatDir[161];
  float exposureTime;
  int darkOption;
  int flatOption;
  int whichCCD;
  int binning;
  int x, y, h, w;
} SINGLESETTINGS;


typedef struct {
  FILTERSET filterSeq;
  char objectName[20];
  char imageDir[80];
  char DarkDir[161];
  char FlatDir[161];
  int darkOption;
  int flatOption;
  int whichCCD;
  int binning;
  int x, y, h, w;
  int startSeqNum;
  int AutoBumpScope;
  float startHours, duration;
  float interval;
} SERIESSETTINGS;

typedef struct {
  char imageDir[80];
  int whichCCD;
  int binning;
  int x, y, h, w;
  int numFrames;
  int combineMethod;
  float exposureTime;
  float ccdTemp;
} DARKFRAMESETTINGS;

typedef struct {
  FILTERSET filterSeq;
  char imageDir[80];
  char DarkDir[161];
  int whichCCD;
  int binning;
  int x, y, h, w;
  int numFrames;
  int darkOption;
  int combineMethod;
  float exposureTime;
  float ccdTemp;
} FLATFRAMESETTINGS;

typedef struct {
  char imageDir[80];
  char DarkDir[161];
  char FlatDir[161];
  char ObjectName[20];
  int whichCCD;
  int binning;
  int x, y, h, w;
  int numFrames;
  int darkOption;
  int flatOption;
  float exposureTime;
  float ccdTemp;
} STACKSETTINGS;

typedef struct {
  float aperatureRadius;
  float zeroPoint;
  float findRadius;
  float minPeak;
  float minFWHM;
  float maxFWHM;
  float minSeparation;
  bool   autoFind;
  bool  logResults;
  char  logFileName[80];
  FILE  *logFilePtr;
  bool  plotResults;
  char  plotHardcopyType[40];
  float skyInnerRadius;
  float skyOuterRadius;
  float skySigmaCut;
  bool  offsetSky;
} PHOTOMETRYSETTINGS;

typedef struct {
  char name[OBJECTSTRINGLENGTH];
  char objectType[OBJECTSTRINGLENGTH];
  char specType[OBJECTSTRINGLENGTH];
  char varType[OBJECTSTRINGLENGTH];
  char ra[12];
  char dec[13];
  float Mags[5];  /* 0=U, 1=B, 2=V, 3=R, 4=I */
} OBJECT;

typedef struct _OBJNODE {
  OBJECT obj;
  struct _OBJNODE *next;
} OBJNODE;

typedef struct _FLATNODE {
  IMAGE Image;
  struct _FLATNODE *next;
} FLATNODE;

typedef struct {
	char name[80];
	char type[80];
	float PrimaryDia;
	float FocalRatio;
	float FocalLength;
} SCOPE;

typedef struct {
  char  name[80];
  float  latitude;
  float  longitude;
  float elevation;
  int   TimeZone;
  SCOPE scope;
  int   ScopeNumber;
  char  Observer[80];
  char  Project[80];
  bool   DaylightSavings;
} OBSSETTINGS;

/* prototypes */

    /* These routines are because you can't have circular header files */

void ShowDefineListDialog(void);
void ShowPhotometrySettingsDialog(void);
void ShowObjectListDialog(void);
void RefreshCurrentImageWindow(void);
void RefreshPhotometryPlotWindow(void);
void RefreshPhotometySettingsDialog(void);

void SetPhotometrySettingsDialogValues(void);
void GetPhotometrySettingsDialogValues(void);
void updateStatusInfo(void);
void ConfigDIO(void);
void doLinkToCamera(CCD *ccd, int *status);
void doUnlinkToCamera(CCD *ccd, int *status);
void doFinish(CCD *ccd, int *status);
bool doSetTempOnCamera(CCD *ccd, double f);
void doSetTempOffCamera(CCD *ccd);
//void doImage(CCD *ccd, X_INFO *x_info, int *status);
void doFilterWheel(CCD *ccd, int *status, int Position);
void doShowStatus(CCD *ccd, int *status);
int MirrorCover(bool open);
void queryi(char *prefix, int *answer, char *suffix, int Min, int Max);
bool Queryr(char *prompt, float *answer);
void queryr(char *prefix, float *answer, char *suffix, float Min, float Max);
void querys(char *prompt, char *answer, int length);
int  query(char *prompt);
void writeFITS(IMAGE *Image, int WhichFrame, char *FileName, char *Object);
int  GetCCDTemperature(CCD *ccd, double *ccd_temp);
void GetCCDFrameSettings(CCD *ccd, int *x, int *y, int *w, int *h, int *b);
int SetCFW6APosition(unsigned short position);
int StartExposure(CCD *ccd, StartExposureParams *expose,
		  StartReadoutParams *readout);
int QueryCCDExposureStatus(CCD *ccd, StartExposureParams *expose);
void EndCCDExposure(CCD *ccd, StartExposureParams *expose);
int GetImage(CCD *ccd, StartReadoutParams *readout, int Light,
	     unsigned short *image_data);
bool snapImaging(CCD *ccd, StartExposureParams *expose, StartReadoutParams *readout,
		 IMAGE *image);
bool snapTracking(CCD *ccd, StartExposureParams *expose, StartReadoutParams *readout,
		  IMAGE *image);
void loadImageImaging(unsigned short *frame, int x, int y, int width,
		      int height, int binning);
void loadImageTracking(unsigned short *frame, int x, int y, int width,
		      int height, int binning);
int GetObjectInfo(char *objectName, OBJECT *objectInfo);
int InitObjectList(char *fileName);
int AddObject(OBJECT *obj);
int DeleteObject(char *name);
int SetObjectInfo(char *objectName, OBJECT *objectInfo);
void WriteObjectList(void);
void freeImageBuffers(CCD *ccd);
int updateImageDisplay(void *dummy);
void print_stats(unsigned short *b, int w, int h);
int snap_callback(float percent);
int readDark(char *dir, IMAGE *Image);
int readFlat(char *Dir, CCD *ccd);
int readLight(char *fileName, IMAGE *Image);
void stripTrailingBlanks(char *string);
void CalcObsParms(float *AirMass, double *JD, double *HJD,
		  OBJECT *objectInfo, OBSSETTINGS *ObsSettings,
		  char *UTBuffer, char *UTDBuffer, float exposure);
double JulDay(int IDay, float RFrac, int IMon, int IYear);
float LocalSiderealTime(double JD, double longitude);
void Sun(double JD, float *SunLong, float *RSN);
void Anomaly(float MA, float S, float *NU, float *EA);
int setAlignStar(FRAME *frame, float *starX, float *starY);
int findAlignStar(FRAME *frame, float starX, float starY,
		  int *offsetX, int *offsetY);
void sumFrames(IMAGE *Image, IMAGE *workingImage, int offsetX, int offsetY);
int FindStar(FRAME *frame, int x1, int y1, int x2, int y2,
	     float *starx, float *stary, int *starmax);
void removeHotPixels(FRAME *light);
void RunMainIteration(float seconds);
void ShowImageProgress(char *Label, int percent);
void ShowGuidingProgress(char *Label, int percent);
int decrementRunMainIterationTimer(void *data);
void doPhotometry(IMAGE *Image, float x, float y, int max, 
		  float *FWHM, float *SkyFlux, float *StarFlux,
		  float *Magnitude, float *MagErr);
void GetPhotometrySettings(void);
int updateListStars(IMAGE *Image, STAR *list);
int measureListStars(IMAGE *Image, STAR *list);
void clearListStars(void);
void AddToPhotPlot(int starNum, STAR *sptr, char *UT, double HJD, char filter);
void DoPhotPlot(DIFFPHOT *List, int whichOne);
void ConvertJDtoHJD(double ra, double dec, double jd, double *lt, double *hjd);
void ast_coord(double ao, double bo, double ap, double bp, double a1,
	       double b1, double *a2, double *b2);
void AutoBumpScope(STAR *starList);
int imedian(int *data, int num);
void flattenFrame(FRAME *light, FRAME *flat);
void putpix(float val, float x, float y, float r, PIXCELL *(*PixList));
void putpixval(float val, float x, float y, float r, PIXCELL *(*PixList));
void freepix(PIXCELL *PixList);
float HWHMPix(PIXCELL *PixList);
void DisplayPSF(PIXCELL *PixList, float fitMax, float fitFWHM);
int FitPSF(PIXCELL *PixList, float *fitMax, float *fitFWHM,
	   float *fitX, float *fitY);
float gaussian(double fitMax, double fitFWHM, float r);
void fcn( int *NPar, double *grad, double *fval, double *FitParms,
	  int *iflag, float (*futil)(float[] ) );
float GetAveFWHM(float starX, float starY);
int SendTCS200Focus(int offset);
int SendTCS200Step(double DeltaRA, double DeltaDEC);
int SendTCS200IS400(int port);
int ExposeSingleFrame(void);
int ExposeSeriesFrames(void);
int MessageBox(char *prompt, int buttons);
void usleep(int usecs);
void UpdateImage(void);
void UpdateGuideImage(void);
void UpdateSeriesSettings(void);
void UpdateDarkFrameSettings(void);
void UpdateFlatFrameSettings(void);
void UpdateStackSettings(void);
int establish_link(CCD *ccd, int Open);
int get_ccd_info(CCD *ccd);
void MarkStar(System::Windows::Forms::PictureBox^ pictureBox, float x, float y);
void ClearMarkStarList(void);
void CircleStar(System::Windows::Forms::PictureBox^ pictureBox, float x, float y);
int AddStar(void);
void DeleteStar(void);
int slitGuider(void *data);
int GetScopePosition(double *ScopeRA, double *ScopeDEC);
void MsgQueueFlush(int queueID);
int AcquireGuideFrame(IMAGE *image, SINGLESETTINGS *settinegs);
void ShowFitsError(void);
void funcs(float x, float y, double a[4], double *zmod, double dzda[4]);
int mrqmin(float x[], float y[], float z[], float sig[], int ndata,
	    double a[4], double covar[4][4], double alpha[4][4],
	    double *chisq, double *alambda);
void mrqcof(float x[], float y[], float z[], float sig[], int ndata,
	    double a[4], double alpha[4][4], double beta[4], double *chisq);
int gaussj(double a[4][4], double b[4][4]);
void MainTimerCallback(Object ^dummy);
void DoMainEvents(void);

// SBIG camera interface routines

int pCam_CFWCommand(CFWParams *cfwp, CFWResults *cfwr);
int pCam_EndExposure(EndExposureParams *parms);
int pCam_EstablishLink(char *device);
int pCam_GetCCDInfo(GetCCDInfoParams *parms, void *results);
int pCam_GetCCDTemperature(double *ccdTemp);
int pCam_GetStatus(void);
void pCam_GetStatusString(char *text);
int pCam_QueryCommandStatus(QueryCommandStatusParams *parms,
			    QueryCommandStatusResults *results);
int pCam_QueryTemperatureStatus(MY_LOGICAL *enabled, double *ccd_temp,
				double *air_temp, double *setpointTemp,
				double *percentTE);
int pCam_ReadoutLine(ReadoutLineParams *parms,
		     unsigned short *results, MY_LOGICAL subtract);
int pCam_SetTemperatureRegulation(MY_LOGICAL enable,
				  double setpoint);
int pCam_StartExposure(StartExposureParams *parms);
int pCam_Unlink(void);

// Apogee camera interface routines

int apCam_EstablishLink(void);
int apCam_Unlink(void);
int apCam_GetCCDInfo(APOGEE_INFO *apogee_info);
double apCam_GetCCDTemperature(void);
int apCam_QueryTemperatureStatus(double *temp, double *setpoint,
					    int *status);
int apCam_GetImage(unsigned short *image_data, short x, short y,
		   short width, short height, short xbinning, short ybinning);
int apCam_GetLine(unsigned short *image_data, short x, short y,
		   short width, short height, short xbinning, short ybinning);
int apCam_ReadStatus(void);
int apCam_SetTemperatureRegulation(int enable, double setpoint);
int apCam_StartExposure(StartExposureParams *expose);

// Starlight Xpress camera interface routines

int spCam_EndExposure(CCD *ccd);
int spCam_EstablishLink(CCD *ccd);
int spCam_GetCCDInfo(MX_SXV_INFO *sxpress_info);
int spCam_ReadoutLine(CCD *ccd, StartReadoutParams *readout,
		      unsigned short *linePtr, unsigned short firstRow);
int spCam_StartExposure(CCD *ccd, StartExposureParams *expose,
			StartReadoutParams *readout);
int spCam_Unlink(CCD *ccd);


/* externs */

extern PIXCELL *pixpointer;
extern float FitPSFfwhm;
extern float FitPSFmax;
extern float FitPSFx;
extern float FitPSFy;
extern char filterSet[NUMFILTERS];
extern OBJNODE *ObjectListHead;
extern char objectListFileName[160];
extern unsigned char *RGBBuf;
extern int RGBw;
extern int RGBh;
extern unsigned char *RGBGuideBuf;
extern int RGBGuidew;
extern int RGBGuideh;
extern CCD ImagingCCD;
extern CCD SpectroCCD;
extern CCD *ccd;
extern CCDSETTINGS ccdSettings;
extern IMAGE guideImage;
//GtkWidget *queryr_dialog=NULL;
extern int MessageBoxAnswer;
extern int OverWriteDialogAnswer;
//void (*queryr_dialog_ok_function)(CCD *ccd, int *status);
extern float queryr_dialog_answer;
extern void *dummy;
extern int dataIsReady;
extern int ImageInProgress;
extern int ExitMenuItemClicked;
extern int CurrentImageWindowCloseButtonClicked;
extern char CurrentImageFileName[160];
extern SCOPE ScopeList[5];

extern bool CurrentImageWindowExists;
extern bool GuideFrameWindowExists;
extern bool ProgressDialogExists;
extern bool GuidingProgressDialogExists;
extern bool SingleSettingsDialogExists;
extern bool SeriesSettingsDialogExists;
extern bool DarkFrameSettingsDialogExists;
extern bool FlatFrameSettingsDialogExists;
extern bool StackSettingsDialogExists;
extern bool PickAlignStarDialogExists;
extern bool OkayDialogExists;
extern bool YesNoDialogExists;
extern bool CameraSettingsDialogExists;
extern bool OverWriteDialogExists;
extern bool PlotWindowExists;
extern bool DefineListDialogExists;
extern bool PhotometrySettingsDialogExists;
extern bool PhotometryPlotWindowExists;
extern bool ObjectListDialogExists;
extern bool QueryrDialogExists;
extern bool ObservatorySettingsDialogExists;


/* GtkWidget *singleSettings_dialog=NULL;
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
GtkWidget *GuideFrameWindow=NULL;
GtkWidget *YesNoDialog=NULL;
GtkWidget *OkayDialog=NULL;
GtkWidget *ProgressDialog=NULL;
GtkWidget *GuidingProgressDialog=NULL;
GtkWidget *PhotometrySettingsDialog=NULL;
GtkWidget *DefineListDialog=NULL;
GtkWidget *GuidingSlitSettingsDialog=NULL;
GtkWidget *CameraSettingsDialog=NULL; */

extern int DownLoadCancel;
extern int ObjectListEditable;
extern int CancelSetAlignStar;
extern int CancelCurrentAcquire;
extern int CancelCurrentGuidingAcquire;
extern int AlignStarFound;
extern int ImagingDownloadInProgress;
extern int ImagingShutterClosed;
extern int DontShowImageProgress;
extern int DontShowGuidingProgress;
extern int queueID;
extern double ScopeRA;
extern double ScopeDEC;
extern int GetScopeRADEC;

extern SINGLESETTINGS singleSettings;
extern SINGLESETTINGS singleSettings_Save;
extern SINGLESETTINGS guideImageSettings;
extern SINGLESETTINGS guideImageSettings_Save;
extern SERIESSETTINGS seriesSettings;
extern SERIESSETTINGS seriesSettings_Save;
extern DARKFRAMESETTINGS darkFrameSettings;
extern DARKFRAMESETTINGS darkFrameSettings_Save;
extern FLATFRAMESETTINGS flatFrameSettings;
extern FLATFRAMESETTINGS flatFrameSettings_Save;
extern STACKSETTINGS stackSettings;
extern STACKSETTINGS stackSettings_Save;
extern OBSSETTINGS ObsSettings;
extern OBSSETTINGS ObsSettings_Save;
extern GUIDINGSLITSETTINGS GuidingSlitSettings;
extern GUIDINGSLITSETTINGS GuidingSlitSettings_save;
extern PHOTOMETRYSETTINGS photometrySettings;
extern PLATESOLU plateSolution;
extern PLATESOLU plateSolution_save;
extern PLATESTARS plateStars;

extern int UserStopBatch;
extern int DontUpdate;
extern int StartSeriesASAP;
extern int PauseSeries;
extern int StopSeries;
extern int SeriesStarted;
extern char binningString[3][4];

extern int SingleSaveEachDarkFrame;
extern int SeriesSaveEachDarkFrame;
extern int FlatSaveEachDarkFrame;
extern int DarkSaveEachDarkFrame;
extern int SaveEachFlatFrame;
extern int StackSaveEachDarkFrame;
extern int StackSaveEachLightFrame;
extern FLATNODE *FlatFrameHead;
extern STAR *CurrentStarList;
extern STAR *CurrentStarListSave;
extern STAR *baseStarList;
extern int CurrentStarListDefined;
extern int DoingAstrometry;

}
