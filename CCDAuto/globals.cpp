
#include "stdafx.h"
//#include "Form1.h"
#include "doRoutines.h"
#include "defines.h"

namespace CCDAuto {

/* globals */

bool GlobalDebug=false;

int DoUpdate=false;
PIXCELL *pixpointer;
float FitPSFfwhm;
float FitPSFmax;
float FitPSFx;
float FitPSFy;

OBJNODE *ObjectListHead;
char objectListFileName[160];
CCD ImagingCCD;
CCD SpectroCCD;
CCD TrackingCCD;
CCD *ccd=&ImagingCCD;
unsigned short ImagingLightFrame[MAXFRAMESIZE];
unsigned short ImagingDarkFrame[MAXFRAMESIZE];
unsigned short ImagingFlatLightFrame[MAXFRAMESIZE];
unsigned short ImagingFlatDarkFrame[MAXFRAMESIZE];
unsigned short SpectroLightFrame[MAXFRAMESIZE];
unsigned short SpectroDarkFrame[MAXFRAMESIZE];
unsigned short SpectroFlatLightFrame[MAXFRAMESIZE];
unsigned short SpectroFlatDarkFrame[MAXFRAMESIZE];
unsigned short TrackingLightFrame[MAXFRAMESIZE];
unsigned short TrackingDarkFrame[MAXFRAMESIZE];
unsigned short TrackingFlatLightFrame[MAXFRAMESIZE];
unsigned short TrackingFlatDarkFrame[MAXFRAMESIZE];
CCDSETTINGS ccdSettings;
int MessageBoxAnswer = NOANSWER;
int OverWriteDialogAnswer=NOANSWER;
void (*queryr_dialog_ok_function)(CCD *ccd, int *status);
float queryr_dialog_answer;
void *dummy;
char CurrentImageFileName[160];
SCOPE ScopeList[5];

int dataIsReady = false;
int input_tag = 0;

char filterSet[NUMFILTERS] = {'B','V','R','I','G','H','C'};
bool DontAskSaveImage=false;
int DontShowImageProgress;
int DontShowGuidingProgress;
int ImagingShutterClosed=true;
int ImageInProgress=false;
int ExitMenuItemClicked=false;
bool CurrentImageWindowCloseButtonClicked=false;
bool AstrometryWindowCloseButtonClicked=false;

bool CurrentImageWindowExists=false;
bool GuideFrameWindowExists=false;
bool ProgressDialogExists=false;
bool GuidingProgressDialogExists=false;
bool DarkFrameSettingsDialogExists=false;
bool FlatFrameSettingsDialogExists=false;
bool StackSettingsDialogExists=false;
bool SingleSettingsDialogExists=false;
bool SeriesSettingsDialogExists=false;
bool PickAlignStarDialogExists=false;
bool OkayDialogExists=false;
bool YesNoDialogExists=false;
bool CameraSettingsDialogExists=false;
bool OverWriteDialogExists=false;
bool PlotWindowExists=false;
bool DefineListDialogExists=false;
bool PhotometrySettingsDialogExists=false;
bool PhotometryPlotWindowExists=false;
bool ObjectListDialogExists=false;
bool QueryrDialogExists=false;
bool ObservatorySettingsDialogExists=false;
bool AstrometryWindowExists=false;
bool InitializeAstrometryDialogExists=false;
bool HistogramWindowExists=false;
bool OpenCalDialogExists=false;
bool SlitGuideSettingsDialogExists=false;
bool AAVSOPhotoDialogExists=false;
bool ssCameraExists=false;
bool OrionFWExists=false;
bool UpdateMX916KeywordsExists=false;

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
REFSTARS refStars;

bool UserStopBatch=false;
bool DontUpdate=false;
bool StartSeriesASAP=false;
bool PauseSeries=false;
bool StopSeries=false;
bool SeriesStarted=false;
bool PleaseStartSeries=false;
char binningString[3][4]={"1x1","2x2","3x3"};

bool SingleSaveEachDarkFrame=false;
bool SeriesSaveEachDarkFrame=false;
bool FlatSaveEachDarkFrame=false;
bool DarkSaveEachDarkFrame=false;
bool SaveEachFlatFrame=false;
bool StackSaveEachDarkFrame=false;
bool StackSaveEachLightFrame=false;
FLATNODE *FlatFrameHead=NULL;
STAR *CurrentStarList=NULL;
STAR *CurrentStarListSave=NULL;
STAR *baseStarList=NULL;
bool CurrentStarListDefined=false;
bool DoingAstrometry=false;

}