
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
unsigned short ImagingBiasFrame[MAXFRAMESIZE];
unsigned short ImagingFlatLightFrame[MAXFRAMESIZE];
unsigned short ImagingFlatDarkFrame[MAXFRAMESIZE];
unsigned short ImagingFlatBiasFrame[MAXFRAMESIZE];
unsigned short SpectroLightFrame[MAXFRAMESIZE];
unsigned short SpectroDarkFrame[MAXFRAMESIZE];
unsigned short SpectroBiasFrame[MAXFRAMESIZE];
unsigned short SpectroFlatLightFrame[MAXFRAMESIZE];
unsigned short SpectroFlatDarkFrame[MAXFRAMESIZE];
unsigned short SpectroFlatBiasFrame[MAXFRAMESIZE];
unsigned short TrackingLightFrame[MAXFRAMESIZE];
unsigned short TrackingDarkFrame[MAXFRAMESIZE];
unsigned short TrackingBiasFrame[MAXFRAMESIZE];
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

bool AAVSOPhotoDialogExists = false;
bool AstrometryWindowExists = false;
bool AutoFocusDialogExists = false;
bool BiasFrameSettingsDialogExists = false;
bool CameraSettingsDialogExists = false;
bool CurrentImageWindowExists=false;
bool DarkFrameSettingsDialogExists = false;
bool DefineListDialogExists = false;
bool FlatFrameSettingsDialogExists = false;
bool GuideFrameWindowExists=false;
bool GuidingProgressDialogExists = false;
bool HistogramWindowExists = false;
bool InitializeAstrometryDialogExists = false;
bool ObjectListDialogExists = false;
bool ObservatorySettingsDialogExists = false;
bool OkayDialogExists = false;
bool OpenCalDialogExists = false;
bool OrionFWExists = false;
bool OverWriteDialogExists = false;
bool PickAlignStarDialogExists = false;
bool PhotometryPlotWindowExists = false;
bool PhotometrySettingsDialogExists = false;
bool PlotWindowExists = false;
bool ProgressDialogExists=false;
bool QueryrDialogExists = false;
bool SeriesSettingsDialogExists = false;
bool SingleSettingsDialogExists = false;
bool SlitGuideSettingsDialogExists = false;
bool ssCameraExists = false;
bool StackSettingsDialogExists=false;
bool UpdateMX916KeywordsExists = false;
bool YesNoDialogExists=false;

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

AUTOFOCUSSETTINGS autoFocusSettings;
BIASFRAMESETTINGS biasFrameSettings;
BIASFRAMESETTINGS biasFrameSettings_Save;
DARKFRAMESETTINGS darkFrameSettings;
DARKFRAMESETTINGS darkFrameSettings_Save;
FLATFRAMESETTINGS flatFrameSettings;
FLATFRAMESETTINGS flatFrameSettings_Save;
GUIDINGSLITSETTINGS GuidingSlitSettings;
GUIDINGSLITSETTINGS GuidingSlitSettings_save;
OBSSETTINGS ObsSettings;
OBSSETTINGS ObsSettings_Save;
PHOTOMETRYSETTINGS photometrySettings;
PLATESOLU plateSolution;
PLATESOLU plateSolution_save;
PLATESTARS plateStars;
REFSTARS refStars;
SERIESSETTINGS seriesSettings;
SERIESSETTINGS seriesSettings_Save;
SINGLESETTINGS singleSettings;
SINGLESETTINGS singleSettings_Save;
SINGLESETTINGS guideImageSettings;
SINGLESETTINGS guideImageSettings_Save;
STACKSETTINGS stackSettings;
STACKSETTINGS stackSettings_Save;

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
bool BiasSaveEachBiasFrame = false;
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