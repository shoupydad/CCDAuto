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

#define RELEASE_VERSION 2.0

#define BASE_PATH "C:\\Users\\Public\\Observatory\\"

#define OBJECTLISTFILE "Objects.lst"  /* Text file of list of objects */
#define LONGITUDE 84.02741 /* longitude of OSUROB */
#define LATITUDE 40.73498 /* latitude of OSUROB */
#define MESSAGEFILENAME BASE_PATH "OSUrob\\MessageFile.txt"
#define RESPONSEFILENAME BASE_PATH "OSUrob\\ResponseFile.txt"
#define DEFAULT_IMAGE_DIRECTORY	BASE_PATH "ImageData"
#define OBJECT_LIST_FILE_NAME BASE_PATH "CCDAuto\\ObjectList.lst"
#define USNOB_CATALOG_PATH BASE_PATH "Catalogs\\USNO-B1.0\\"
#define DEFAULT_PHOTOMETRY_LOG_DIRECTORY BASE_PATH "ImageData"
#define DEFAULT_PHOTOMETRY_STANDARDS_DIRECTORY BASE_PATH "CCDAuto\\PhotometricStandards"
#define DEFAULT_AUTOFOCUS_SETTINGS_FILENAME BASE_PATH "CCDAuto\\AutoFocusSettings.txt"

	// Macros

#define XYtoPixel(f,x,y) y*f->w+x
#define MouseXYtoFrameXY(mx,my,f,fx,fy) fx = mx; fy = f->h - my;
#define FrameXYtoMouseXY(f,fx,fy,mx,my) mx = fx; my = f->h - fy;

	// Astrometry constants

#define MAX_MAG_REF_STARS 16.0

	// AAVSO photometry format constants

#define AAVSOTYPE "Extended"
#define AAVSOOBSCOD "SUY"
#define AAVSOSOFTWARE "CCDAuto 2.0"
#define AAVSODELIM ","
#define AAVSODATE "HJD"
#define AAVSOOBSTYPE "CCD"

#define RED 0
#define GREEN 1
#define BLUE 2
#define NUMFILTERS 7
#define BFILTERNUM 0
#define VFILTERNUM 1
#define RFILTERNUM 2	
#define IFILTERNUM 3
#define HFILTERNUM 4
#define GFILTERNUM 5
#define CFILTERNUM 6
#define MAXCOOLPOWER 255.0
//#define CCDGAIN 1.75
//#define READNOISE 18.6
#define DEFAULTU8300BIAS 1400     // ADC
#define DEFAULTU8300DARKNOISE 0.1 // e-'s per sec per pixel @ -25 C
#define DEFAULTU8300READNOISE 15.0 // e-'s RMS
#define DEFAULTU8300GAIN 1.5 // e-'s per ADC
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
#define TRACKINGPORT "lpiusb0"
#define APOGEE47PCCD "Apogee AP-47p"
#define APOGEEU8300CCD "Apogee U8300"
#define STARLIGHTXPRESSCCD "Starlight Xpress MX-916"
#define MEADECCD "Meade LPI #2"
#define CANONCCD "Canon 350D"
#define STARSHOOTPRO "Orion StarShoot Pro V2.0"
#define STARSHOOTAUTOGUIDER "Orion StarShoot Autoguider"
#define ON true
#define OFF false

#define SBIG_MAKE 0
#define APOGEE47P_MAKE 1
#define APOGEEU8300_MAKE 2
#define SXPRESS_MAKE 3
#define MEADE_MAKE 4
#define CANON_MAKE 5
#define SSPRO_MAKE 6
#define SSAG_MAKE 7

#define DEFAULTGUIDINGXPIXELSCALE 0.467
#define DEFAULTGUIDINGYPIXELSCALE 0.467
#define DEFAULTGUIDINGINTERVAL 20.0
#define DEFAULTGUIDINGEXPTIME 5.0
#define DEFAULTSLITX0 1
#define DEFAULTSLITY0 200
#define DEFAULTSLITX1 639
#define DEFAULTSLITY1 199

#define DEFAULTIMAGECCDTYPE APOGEEU8300CCD
#define DEFAULTIMAGECCDPORT "usb"
#define DEFAULTSPECTROCCDTYPE APOGEE47PCCD
#define DEFAULTSPECTROCCDPORT "LPT1"
#define DEFAULTTRACKINGCCDTYPE MEADECCD
#define DEFAULTTRACKINGCCDPORT "usb"

#define APOGEE_STATUS_IDLE 0
#define APOGEE_STATUS_WAITINGFORTRIGGER 1
#define APOGEE_STATUS_EXPOSING 2
#define APOGEE_STATUS_DOWNLOADING 3
#define APOGEE_STATUS_LINEREADY 4
#define APOGEE_STATUS_IMAGEREADY 5
#define APOGEE_STATUS_FLUSHINGBIR 6

// Apogee Alta Camera Defines

#define ALTA_STATUS_IDLE 0
#define ALTA_STATUS_EXPOSING 1
#define ALTA_STATUS_IMAGINGACTIVE 2
#define ALTA_STATUS_IMAGEREADY 3
#define ALTA_STATUS_FLUSHING 4
#define ALTA_STATUS_WAITINGONTRIGGER 5
#define ALTA_STATUS_CONNECTIONERROR -3
#define ALTA_STATUS_DATAERROR -2
#define ALTA_STATUS_PATTERNERROR -1

// Orion StarShoot Pro defines

#define ASCOM_CAM_STATE_IDLE 0
#define ASCOM_CAM_STATE_WAITING 1
#define ASCOM_CAM_STATE_EXPOSING 2
#define ASCOM_CAM_STATE_READING 3
#define ASCOM_CAM_STATE_DOWNLOAD 4
#define ASCOM_CAM_STATE_ERROR 5

//#define PI 3.141592654
#define HALFPI 1.570796327
#define DEG2RAD 0.0174533
#define RAD2DEG 57.29578

#define OKAY 5

	// Display window constants

#define CURRENTIMAGEWINDOW 0
#define GUIDEIMAGEWINDOW 1
#define ASTROMETRYWINDOW 2

	// TheSky6 Query Constants

#define THESKYQUERYFILE "c:\\Users\\shoup.31\\Documents\\Observatory\\CCDAuto\\GeneralQuery.DBQ"
#define TEMPQUERYFILE "c:\\Users\\shoup.31\\Documents\\Observatory\\CCDAuto\\TempQuery.DBQ"
#define THESKY6RA2000INDEX 56
#define THESKY6DEC2000INDEX 57
#define THESKY6MAGINDEX 65

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
  bool Running;
  bool Live;
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
  double pixelX[200];
  double pixelY[200];
  double RA[200];
  double DEC[200];
  double Mag[200];
} PLATESTARS;

typedef struct {
	int numStars;
	double RA[MAXNUMREFSTARS];
	double DEC[MAXNUMREFSTARS];
	double ProperMotionRA[MAXNUMREFSTARS];
	double ProperMotionDEC[MAXNUMREFSTARS];
	double Mag[MAXNUMREFSTARS];
	bool Marked[MAXNUMREFSTARS];
	int x[MAXNUMREFSTARS];
	int y[MAXNUMREFSTARS];
	double ChartXScale;
	double ChartYScale;
	double ChartMinRA;
	double ChartMinDEC;
} REFSTARS;

typedef struct {
  double coeffs[6];
  double InitFieldCenterRA;
  double InitFieldCenterDEC;
  double FieldCenterRA;
  double FieldCenterDEC;
  double PixelScale;
  double ErrorEst;
  int status;  // 0: Okay, else no solution
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
  float rawval;
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
  bool Use[NUMFILTERS];
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
  bool active;
  float temp;
  __time64_t time; // Should be redeclared as system time type
  char UT[20];
  char UTDATE[20];
  float exposure;
  unsigned short *frame;
//  unsigned short frame[1115136];
} FRAME;

typedef struct {
  char Filter[2];     /* UBVRI or A = H-alpha, G = Grating */
  char FileName[MAX_SIZE_PATH_CHARS];
  char ObjectName[21];
  PLATESOLU plateSolution;
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
	int MaxBinX;
	int MaxBinY;
	int CameraXSize;  // max # pixels in X
	int CameraYSize;  // max # pixels in Y
	double PixelSizeX;   // X size of pixels in microns
	double PixelSizeY;   // Y size of pixels in microns
	bool CanSetCCDTemperature;
	bool CanPulseGuide;
	int MaxADU;
	char Description[100];
	double ElectronsPerADU;
	double FullWellCapacity;  // in electrons
} SSPRO_INFO;

typedef struct {
	int binning;
	int MaxRows;
	int MaxColumns;
} MEADE_INFO;

typedef struct {
	int MaxRows;
	int MaxColumns;
} CANON_INFO;

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
  float gain;
  float readNoise;
  GetCCDInfoResults0 info;
  GetCCDInfoResults0 info1;
  GetCCDInfoResults2 info2;
  GetCCDInfoResults3 info3;
  MX_SXV_INFO mx_sxv_info;
  APOGEE_INFO apogee_info;
  MEADE_INFO meade_info;
  CANON_INFO canon_info;
  SSPRO_INFO sspro_info;
  IMAGE Image;
  IMAGE FlatImage;
} CCD;

typedef struct {
  char ImagingType[80];
  char ImagingPort[80];
  char SpectroType[80];
  char SpectroPort[80];
  char TrackingType[80];
  char TrackingPort[80];
} CCDSETTINGS;

typedef struct {
  char ObjectName[21];
  char ImageDir[81];
  char DarkDir[MAX_SIZE_PATH_CHARS];
  char FlatDir[MAX_SIZE_PATH_CHARS];
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
  char DarkDir[MAX_SIZE_PATH_CHARS];
  char FlatDir[MAX_SIZE_PATH_CHARS];
  int darkOption;
  int flatOption;
  int whichCCD;
  int binning;
  int x, y, h, w;
  int startSeqNum;
  int AutoBumpScope;
  float startHours, duration;
  float interval;
  bool StartSeriesASAP;
  bool SaveRawImages;
  bool CloseObservatoryWhenDone;
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
  char DarkDir[MAX_SIZE_PATH_CHARS];
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
  char DarkDir[MAX_SIZE_PATH_CHARS];
  char FlatDir[MAX_SIZE_PATH_CHARS];
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
  bool  AperatureScaledToFWHM;
  float ApFWHMScale;
  float averageFWHM;
  float zeroPoint;
  float findRadius;
  float minPeak;
  float maxPeak;
  float minFWHM;
  float maxFWHM;
  float minSeparation;
  bool   autoFind;
  bool  logCCDAutoFormat;
  bool  logAAVSOFormat;
  char  logDir[MAX_SIZE_PATH_CHARS];
  char  logBaseName[80];
  char  logCCDAutoFileName[MAX_SIZE_PATH_CHARS];
  char  logAAVSOFileName[MAX_SIZE_PATH_CHARS];
  FILE  *logCCDAutoFilePtr;
  FILE  *logAAVSOFilePtr;
  char  AAVSOCompStarID[15];
  char  AAVSOCheckStarID[15];
  char  AAVSOVarStarID[15];
  char  AAVSOChartDate[10];
  bool  AAVSOPrintHeading;
  bool  plotResults;
  char  plotHardcopyType[40];
  float skyInnerRadius;
  float skyOuterRadius;
  float skySigmaCut;
  bool  offsetSky;
  bool  CalibrateImages; // same as open + calibrate
  bool  Interactive;
} PHOTOMETRYSETTINGS;

typedef struct {
	int NumFramesPerPoint;
	int StartingVCurveSide;		// -1 means left, 0 means unknown, +1 means right
	int CalNumFramesPerPoint;
	int CalStarMaxMax;			// Range of allowable star maximum (saturation)
	int CalStarMinMax;
	int CalStartFocusPosition;	// Starting focus position
	int CalEndFocusPosition;	// Ending focus position
	int CalFocusStepSize;		// Step size in focus position values
	int CalFieldSize;			// Square field in pixels
	bool GotVCurveParams;		// True if auto focus calibrated
	double CurStarX;
	double CurStarY;
	int CurStarMax;
	double CurStarHFD;
	int CurStarFlux;
	double LeftVCurveSlope;
	double RightVCurveSlope;
} AUTOFOCUSSETTINGS;

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

bool AcquireGuideFrame(CCD *ccd, SINGLESETTINGS *settings);
bool AddObject(OBJECT *obj);
bool AddStar(void);
void AddToPhotPlot(int starNum, STAR *sptr, char *UT, double HJD, char filter);
void Anomaly(float MA, float S, float *NU, float *EA);
void ast_coord(double ao, double bo, double ap, double bp, double a1,
	       double b1, double *a2, double *b2);
void AutoBumpScope(STAR *starList);
bool autoGuider(void);
bool BumpScope(double delra, double deldec);
void CalcObsParms(float *AirMass, double *JD, double *HJD,
		  OBJECT *objectInfo, OBSSETTINGS *ObsSettings,
		  char *UTBuffer, char *UTDBuffer, float exposure);
bool CalibrateSlitEnd(int *x, int *y);
void CircleStar(System::Windows::Forms::PictureBox^ pictureBox, float x, float y);
void ClearMarkStarList(void);
void clearListStars(void);
bool ComputePlateSolution(PLATESOLU *solution);
void ConvertJDtoHJD(double ra, double dec, double jd, double *lt, double *hjd);
void ConvertRAtoHMS(double ra, int *hours, int *mins, float *secs);
void ConvertDECtoDMS(double dec, int *degs, int *mins, float *secs);
void ConvertDMStoDEC(int degs, int mins, float secs, double *dec);
void ConvertHMStoRA(int hours, int mins, float secs, double *ra);
void DecimalDay(int day, int hour, int minute, int second, int sec100, double *DecDay);
int  decrementRunMainIterationTimer(void *data);
bool DeleteObject(char *name);
void DeleteStar(void);
void DisplayPSF(PIXCELL *PixList, float fitMax, float fitFWHM);
bool DoCalibrations(char *DarkDir, int DarkOption, char *FlatDir, int FlatOption, CCD *ccd);

void DoDarkFrameSeries(void);
void doFilterWheel(CCD *ccd, int *status, int Position);
void doFinish(CCD *ccd, int *status);
void DoFlatFrameSeries(void);
void doLinkToCamera(CCD *ccd, int *status);
void DoMainEvents(void);
void doPhotometry(IMAGE *Image, short Window, float x, float y, int max, bool JustPSF, float *FWHM, float *SkyFlux,
				  float *StarFlux, float *Magnitude, float *MagErr);
void DoPhotPlot(DIFFPHOT *List, int whichOne);
void doSetTempOffCamera(CCD *ccd);
bool doSetTempOnCamera(CCD *ccd, double f);
void doShowStatus(CCD *ccd, int *status);
void doUnlinkToCamera(CCD *ccd, int *status);
void EndCCDExposure(CCD *ccd, StartExposureParams *expose, bool digitize);
bool Equatorial2Pixel(double ra, double dec, double *x, double *y);
bool establish_link(CCD *ccd, int Open);
bool ExposeSingleFrame(void);
bool  ExposeSeriesFrames(void);
void fcn( int *NPar, double *grad, double *fval, double *FitParms,
	  int *iflag, float (*futil)(float[] ) );
bool findAlignStar(FRAME *frame, float starX, float starY,
		  int *offsetX, int *offsetY);
bool FindStar(FRAME *frame, int x1, int y1, int x2, int y2,
	     float *starx, float *stary, int *starmax);
bool FitPSF(PIXCELL *PixList, float *fitMax, float *fitFWHM,
	   float *fitX, float *fitY);
void flattenFrame(FRAME *light, FRAME *flat);
void freeImageBuffers(CCD *ccd);
void freepix(PIXCELL *PixList);
void funcs(float x, float y, double a[4], double *zmod, double dzda[4]);
int gaussj(double a[4][4], double b[4][4]);
float gaussian(double fitMax, double fitFWHM, float r);
bool GetAFolder(char *description, char *folder);
float GetAveFWHM(float starX, float starY);
void GetCCDFrameSettings(CCD *ccd, int *x, int *y, int *w, int *h, int *b);
bool get_ccd_info(CCD *ccd);
bool GetCCDTemperature(CCD *ccd, double *ccd_temp);
bool  GetImage(CCD *ccd, StartReadoutParams *readout, int Light,
	     unsigned short *image_data);
bool GetObjectInfo(char *objectName, OBJECT *objectInfo);
bool GetOrionFWPosition(int *position);
void GetPhotometrySettings(void);
void GetPhotometrySettingsDialogValues(void);
bool GetRefStarsFromUSNOB1(double MinRA, double MaxRA, double MinDEC, double MaxDEC, double MaxMag, REFSTARS *refStars);
bool GetScopePosition(double *ScopeRA, double *ScopeDEC);
float HWHMPix(PIXCELL *PixList);
int imedian(int *data, int num);
bool  InitObjectList(char *fileName);
double JulDay(int IDay, float RFrac, int IMon, int IYear);
void JulianDay(int year, int month, int day, int hour, int minute, int second, int sec100, double *jd);
void loadImageImaging(unsigned short *frame, int x, int y, int width,
		      int height, int binning);
void loadImageTracking(unsigned short *frame, int x, int y, int width,
		      int height, int binning);
bool loadRefChartAstrometry(IMAGE *image);
float LocalSiderealTime(double JD, double longitude);
void lmst(double julian_date, double *lst);
void MainTimerCallback(Object ^dummy);
void MarkStar(System::Windows::Forms::PictureBox^ pictureBox, float x, float y);
bool measureListStars(IMAGE *Image, STAR *list);
int MessageBox(char *prompt, int buttons, bool Modal);
int mrqmin(float x[], float y[], float z[], float sig[], int ndata,
	    double a[4], double covar[4][4], double alpha[4][4],
	    double *chisq, double *alambda);
void mrqcof(float x[], float y[], float z[], float sig[], int ndata,
	    double a[4], double alpha[4][4], double beta[4], double *chisq);
bool  query(char *prompt);
bool  QueryCCDExposureStatus(CCD *ccd, StartExposureParams *expose);
void queryi(char *prefix, int *answer, char *suffix, int Min, int Max);
bool Queryr(char *prompt, float *answer);
void queryr(char *prefix, float *answer, char *suffix, float Min, float Max);
void querys(char *prompt, char *answer, int length);
bool Pixel2Equatorial(double x, double y, double *ra, double *dec);
void print_stats(unsigned short *b, int w, int h);
void putpix(float val, float x, float y, float r, PIXCELL *(*PixList));
void putpixval(float val, float rawval, float x, float y, float r, PIXCELL *(*PixList));
bool readDark(char *dir, IMAGE *Image);
bool readFlat(char *Dir, CCD *ccd);
bool readLight(char *fileName, IMAGE *Image);
void RefreshCurrentImageWindow(void);
void RefreshPhotometryPlotWindow(void);
void RefreshPhotometySettingsDialog(void);
void removeHotPixels(FRAME *light);
void RunMainIteration(double seconds);
bool SendOSUrobMessage(char Command, int *IntParms, double *DoubleParms);
bool setAlignStar(FRAME *frame, float *starX, float *starY);
bool SetOrionFWPosition(int position);
bool SetCFW6APosition(int position);
bool SetObjectInfo(char *objectName, OBJECT *objectInfo);
void SetScopePositionPolling(bool On);
void ShowDefineListDialog(void);
void ShowFitsError(void);
void ShowGuidingProgress(char *Label, int percent);
void ShowPhotometrySettingsDialog(void);
void SetPhotometrySettingsDialogValues(void);
void ShowObjectListDialog(void);
void ShowAstrometryWindow(void);
void ShowImageProgress(char *Label, int percent);
void ShowInitializeAstrometryDialog(void);
void ShowUpdateMX916Keywords(void);
void sla_FITXY(int ITYPE, int NP, double XYE[2][100], double XYM[2][100],
			   double COEFFS[6], int *J);
void sla_DMAT(int N, double A[4][4], double Y[4], double *D, int *JF, int IW[4]);
void sla_DMXV(double DM[4][4], double VA[3], double VB[3]);
bool slitGuider(void *data);
bool snap_callback(float percent);
bool snapImaging(CCD *ccd, StartExposureParams *expose, StartReadoutParams *readout,
		 IMAGE *image);
bool snapTracking(CCD *ccd, StartExposureParams *expose, StartReadoutParams *readout,
		  IMAGE *image);
bool StartExposure(CCD *ccd, StartExposureParams *expose,
		  StartReadoutParams *readout);
void stripTrailingBlanks(char *string);
void sumFrames(IMAGE *Image, IMAGE *workingImage, int offsetX, int offsetY);
void Sun(double JD, float *SunLong, float *RSN);
bool updateImageDisplay(void *dummy);
void updateStatusInfo(void);
bool updateListStars(IMAGE *Image, STAR *list);
void UpdatePlateSolution(CCD *ccd);
void usleep(int usecs);
void UpdateImage(void);
void UpdateGuideImage(void);
void UpdateSeriesSettings(void);
void UpdateDarkFrameSettings(void);
void UpdateFlatFrameSettings(void);
void UpdateStackSettings(void);
void writeFITS(IMAGE *Image, int WhichFrame, char *FileName, char *Object);
void WriteObjectList(void);
void WriteStatus(char *text);

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

bool apCam_EstablishLink(void);
bool apCam_Unlink(void);
bool apCam_GetCCDInfo(APOGEE_INFO *apogee_info);
double apCam_GetCCDTemperature(void);
bool apCam_QueryTemperatureStatus(double *temp, double *setpoint,
					    int *status);
bool apCam_GetImage(unsigned short *image_data, short x, short y,
		   short width, short height, short xbinning, short ybinning);
bool apCam_GetLine(unsigned short *image_data, short x, short y,
		   short width, short height, short xbinning, short ybinning);
int apCam_ReadStatus(void);
bool apCam_SetTemperatureRegulation(int enable, double setpoint);
bool apCam_StartExposure(StartExposureParams *expose);
bool apCam_Flush(short row);

bool altaCam_EstablishLink(void);
bool altaCam_Unlink(void);
bool altaCam_GetCCDInfo(APOGEE_INFO *apogee_info);
double altaCam_GetCCDTemperature(void);
bool altaCam_QueryTemperatureStatus(double *temp, double *setpoint,
					    int *status);
bool altaCam_GetImage(unsigned short *image_data, short x, short y,
		   short width, short height, short xbinning, short ybinning);
bool altaCam_GetLine(unsigned short *image_data, short x, short y,
		   short width, short height, short xbinning, short ybinning);
int altaCam_ReadStatus(void);
bool altaCam_SetTemperatureRegulation(int enable, double setpoint);
bool altaCam_StartExposure(StartExposureParams *expose, StartReadoutParams *readout);
bool altaCam_StopExposure(bool Digitize);
bool altaCam_Flush(short row);

// Starlight Xpress camera interface routines

void spCam_ClearVert(void);
bool spCam_EndExposure(CCD *ccd);
bool spCam_EstablishLink(CCD *ccd);
bool spCam_GetCCDInfo(MX_SXV_INFO *sxpress_info);
bool spCam_GetImage(StartReadoutParams *readout, unsigned short *image_data, unsigned int nBytesToRead);
bool spCam_ReadStatus(unsigned int *TimerValue);
bool spCam_Reset(void);
bool spCam_StartExposure(CCD *ccd, StartExposureParams *expose,
			StartReadoutParams *readout);
bool spCam_Unlink(CCD *ccd);

// Meade LPI camera interface routines

bool LPI_EstablishLink(CCD *ccd);
void LPI_Unlink(CCD *ccd);
bool LPI_GetCCDInfo(MEADE_INFO *meade_info);
bool LPI_StartExposure(StartExposureParams *expose);
int LPI_GetStatus(void);
bool LPI_GetImage(unsigned short *image_data);

// Canon camera interface routines

bool Canon_EstablishLink(CCD *ccd);
bool Canon_Unlink(CCD *ccd);
bool Canon_GetCCDInfo(CANON_INFO *canon_info);
bool Canon_StartExposure(StartExposureParams *expose);
int Canon_GetStatus(void);
bool Canon_GetImage(unsigned short *image_data);

// Orion StarShoot Pro V2.0 camera interface routines

bool ssCam_EstablishLink(void);
bool ssCam_Unlink(void);
bool ssCam_GetCCDInfo(SSPRO_INFO *info);
float ssCam_GetCCDTemperature(void);
bool ssCam_StartExposure(StartExposureParams *expose, StartReadoutParams *readout);
bool ssCam_ImageReady(void);
bool ssCam_GetImage(unsigned short *image_data);

/* externs */

extern bool GlobalDebug;
extern PIXCELL *pixpointer;
extern float FitPSFfwhm;
extern float FitPSFmax;
extern float FitPSFx;
extern float FitPSFy;
extern char filterSet[NUMFILTERS];
extern OBJNODE *ObjectListHead;
extern char objectListFileName[160];
extern CCD ImagingCCD;
extern CCD SpectroCCD;
extern CCD TrackingCCD;
extern CCD *ccd;
extern CCDSETTINGS ccdSettings;
extern int MessageBoxAnswer;
extern int OverWriteDialogAnswer;
extern float queryr_dialog_answer;
extern void *dummy;
extern int dataIsReady;
extern int ImageInProgress;
extern int ExitMenuItemClicked;
extern bool CurrentImageWindowCloseButtonClicked;
extern bool AstrometryWindowCloseButtonClicked;
extern char CurrentImageFileName[160];
extern SCOPE ScopeList[5];

extern bool AAVSOPhotoDialogExists;
extern bool AstrometryWindowExists;
extern bool AutoFocusDialogExists;
extern bool CameraSettingsDialogExists;
extern bool CurrentImageWindowExists;
extern bool DarkFrameSettingsDialogExists;
extern bool DefineListDialogExists;
extern bool FlatFrameSettingsDialogExists;
extern bool GuideFrameWindowExists;
extern bool GuidingProgressDialogExists;
extern bool HistogramWindowExists;
extern bool InitializeAstrometryDialogExists;
extern bool ObjectListDialogExists;
extern bool ObservatorySettingsDialogExists;
extern bool OkayDialogExists;
extern bool OpenCalDialogExists;
extern bool OrionFWExists;
extern bool OverWriteDialogExists;
extern bool PhotometryPlotWindowExists;
extern bool PhotometrySettingsDialogExists;
extern bool PickAlignStarDialogExists;
extern bool PlotWindowExists;
extern bool ProgressDialogExists;
extern bool QueryrDialogExists;
extern bool SeriesSettingsDialogExists;
extern bool SingleSettingsDialogExists;
extern bool SlitGuideSettingsDialogExists;
extern bool ssCameraExists;
extern bool StackSettingsDialogExists;
extern bool UpdateMX916KeywordsExists;
extern bool YesNoDialogExists;

extern int DownLoadCancel;
extern int ObjectListEditable;
extern int CancelSetAlignStar;
extern int CancelCurrentAcquire;
extern int CancelCurrentGuidingAcquire;
extern int AlignStarFound;
extern int ImagingDownloadInProgress;
extern int ImagingShutterClosed;
extern bool DontAskSaveImage;
extern int DontShowImageProgress;
extern int DontShowGuidingProgress;
extern int queueID;
extern double ScopeRA;
extern double ScopeDEC;
extern int GetScopeRADEC;

extern AUTOFOCUSSETTINGS autoFocusSettings;
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
extern REFSTARS refStars;

extern bool UserStopBatch;
extern bool DontUpdate;
extern bool StartSeriesASAP;
extern bool PauseSeries;
extern bool StopSeries;
extern bool SeriesStarted;
extern bool PleaseStartSeries;
extern char binningString[3][4];

extern bool SingleSaveEachDarkFrame;
extern bool SeriesSaveEachDarkFrame;
extern bool FlatSaveEachDarkFrame;
extern bool DarkSaveEachDarkFrame;
extern bool SaveEachFlatFrame;
extern bool StackSaveEachDarkFrame;
extern bool StackSaveEachLightFrame;
extern FLATNODE *FlatFrameHead;
extern STAR *CurrentStarList;
extern STAR *CurrentStarListSave;
extern STAR *baseStarList;
extern bool CurrentStarListDefined;
extern bool DoingAstrometry;
extern unsigned short ImagingLightFrame[MAXFRAMESIZE];
extern unsigned short ImagingDarkFrame[MAXFRAMESIZE];
extern unsigned short ImagingFlatLightFrame[MAXFRAMESIZE];
extern unsigned short ImagingFlatDarkFrame[MAXFRAMESIZE];
extern unsigned short SpectroLightFrame[MAXFRAMESIZE];
extern unsigned short SpectroDarkFrame[MAXFRAMESIZE];
extern unsigned short SpectroFlatLightFrame[MAXFRAMESIZE];
extern unsigned short SpectroFlatDarkFrame[MAXFRAMESIZE];
extern unsigned short TrackingLightFrame[MAXFRAMESIZE];
extern unsigned short TrackingDarkFrame[MAXFRAMESIZE];
extern unsigned short TrackingFlatLightFrame[MAXFRAMESIZE];
extern unsigned short TrackingFlatDarkFrame[MAXFRAMESIZE];

}
