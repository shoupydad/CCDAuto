// CCDAuto.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include "DownLoadingDialog.h"
#include "doRoutines.h"

using namespace System;
using namespace System::IO;
using namespace CCDAuto;

static void OnUnhandled(Object^ sender, ThreadExceptionEventArgs^ e)
   {
      MessageBox::Show(e->Exception->Message, "Global Exeception");
	  return;
   }



[STAThreadAttribute]
int main(array<System::String ^> ^args)
{

	String^ DefaultDir = DEFAULT_IMAGE_DIRECTORY;

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Set default current directory

	Directory::SetCurrentDirectory(DefaultDir);

  /* Init photometry settings */

  photometrySettings.aperatureRadius = 10.0;
  photometrySettings.AperatureScaledToFWHM = false;
  photometrySettings.ApFWHMScale = (float) 1.4;
  photometrySettings.zeroPoint = 25.0;
  photometrySettings.findRadius = 10.0;
  photometrySettings.minPeak = 500.0;
  photometrySettings.maxPeak = 60000.0;
  photometrySettings.minFWHM = 2.0;
  photometrySettings.maxFWHM = 10.0;
  photometrySettings.autoFind = false;
  photometrySettings.logCCDAutoFormat = false;
  photometrySettings.logAAVSOFormat = false;
  photometrySettings.Interactive = false;
  photometrySettings.skyInnerRadius = 15.0;
  photometrySettings.skyOuterRadius = 20.0;
  photometrySettings.skySigmaCut = 3.0;
  photometrySettings.offsetSky = false;
  photometrySettings.CalibrateImages = false;
  strcpy_s(photometrySettings.logBaseName,"Target");
  strcpy_s(photometrySettings.logDir, DEFAULT_PHOTOMETRY_LOG_DIRECTORY);
  photometrySettings.logCCDAutoFilePtr = NULL;
  photometrySettings.logAAVSOFilePtr = NULL;
  photometrySettings.AAVSOPrintHeading = false;
  photometrySettings.plotResults = false;
  strcpy_s(photometrySettings.plotHardcopyType,"none");
  strcpy_s(CurrentImageFileName, "");

  /* Init Slit spectrograph guiding */

  GuidingSlitSettings.slitX0 = DEFAULTSLITX0;
  GuidingSlitSettings.slitY0 = DEFAULTSLITY0;
  GuidingSlitSettings.slitX1 = DEFAULTSLITX1;
  GuidingSlitSettings.slitY1 = DEFAULTSLITY1;
  GuidingSlitSettings.interval = 20.0;
  GuidingSlitSettings.exposure = 5.0;
  GuidingSlitSettings.XScale = ((float) DEFAULTGUIDINGXPIXELSCALE);
  GuidingSlitSettings.YScale = ((float) DEFAULTGUIDINGYPIXELSCALE);

  /* Init CCD Settings (type & port) */

  strcpy_s(ccdSettings.ImagingType,DEFAULTIMAGECCDTYPE);
  strcpy_s(ccdSettings.ImagingPort,DEFAULTIMAGECCDPORT);
  strcpy_s(ccdSettings.SpectroType,DEFAULTSPECTROCCDTYPE);
  strcpy_s(ccdSettings.SpectroPort,DEFAULTSPECTROCCDPORT);
  strcpy_s(ccdSettings.TrackingType,DEFAULTTRACKINGCCDTYPE);
  strcpy_s(ccdSettings.TrackingPort,DEFAULTTRACKINGCCDPORT);

  /* Init imaging ccd info structure */

  strcpy_s(ImagingCCD.port,DEFAULTIMAGECCDPORT);
  strcpy_s(ImagingCCD.name,DEFAULTIMAGECCDTYPE);
  ImagingCCD.make = APOGEEU8300_MAKE;
  ImagingCCD.Linked = false;
  ImagingCCD.filterPosition = -1;
  ImagingCCD.Temp = 0.0;
  ImagingCCD.TempOn = false;
  ImagingCCD.FanOn = false;
  ImagingCCD.Image.saved = false;
  ImagingCCD.Image.light_frame.active = false;
  ImagingCCD.Image.dark_frame.active = false;
  strcpy_s(ImagingCCD.Image.FileName,"");
  ImagingCCD.FlatImage.saved = false;
  ImagingCCD.FlatImage.light_frame.active = false;
  ImagingCCD.FlatImage.dark_frame.active = false;
  strcpy_s(ImagingCCD.FlatImage.FileName,"");
  ImagingCCD.Image.plateSolution.status = -4;
  ImagingCCD.Image.plateSolution.PixelScale = 0.75; // "/pixel

  /* Init spectro ccd info structure */

  strcpy_s(SpectroCCD.port,DEFAULTSPECTROCCDPORT);
  strcpy_s(SpectroCCD.name,DEFAULTSPECTROCCDTYPE);
  SpectroCCD.make = APOGEE47P_MAKE;
  SpectroCCD.Linked = false;
  SpectroCCD.filterPosition = 1;
  SpectroCCD.Temp = 0.0;
  SpectroCCD.TempOn = false;
  SpectroCCD.FanOn = false;
  SpectroCCD.Image.saved = false;
  SpectroCCD.Image.light_frame.active = false;
  SpectroCCD.Image.dark_frame.active = false;
  strcpy_s(SpectroCCD.Image.FileName,"");
  SpectroCCD.FlatImage.saved = false;
  SpectroCCD.FlatImage.light_frame.active = false;
  SpectroCCD.FlatImage.dark_frame.active = false;
  strcpy_s(SpectroCCD.FlatImage.FileName,"");

  /* Init tracking ccd info structure */

  strcpy_s(TrackingCCD.port,DEFAULTTRACKINGCCDPORT);
  strcpy_s(TrackingCCD.name,DEFAULTTRACKINGCCDTYPE);
  TrackingCCD.make = MEADE_MAKE;
  TrackingCCD.Linked = false;
  TrackingCCD.filterPosition = 1;
  TrackingCCD.Temp = 0.0;
  TrackingCCD.TempOn = false;
  TrackingCCD.FanOn = false;
  TrackingCCD.Image.saved = false;
  TrackingCCD.Image.light_frame.active = false;
  TrackingCCD.Image.dark_frame.active = false;
  strcpy_s(TrackingCCD.Image.FileName,"");
  TrackingCCD.FlatImage.saved = false;
  TrackingCCD.FlatImage.light_frame.active = false;
  TrackingCCD.FlatImage.dark_frame.active = false;
  strcpy_s(TrackingCCD.FlatImage.FileName,"");

  // Set ccd to be imaging as default

//  ccd = &ImagingCCD;

  singleSettings.exposureTime = 1.0;
  singleSettings.whichCCD = 0;   /* 0 = imaging, 1 = tracking */
  singleSettings.binning = 1;  /* 0 = 1x1, 1 = 2x2, 2 = 3x3 */
  singleSettings.x = 0;
  singleSettings.y = 0;
  singleSettings.h = 0;
  singleSettings.w = 0;
  singleSettings.darkOption = 1;  /* Reuse dark frames */
  singleSettings.flatOption = 1;  /* Do not do flat fielding */
  strcpy_s(singleSettings.ObjectName,"");
  strcpy_s(singleSettings.ImageDir, DEFAULT_IMAGE_DIRECTORY);
  strcpy_s(singleSettings.DarkDir, DEFAULT_IMAGE_DIRECTORY);
  strcpy_s(singleSettings.FlatDir, DEFAULT_IMAGE_DIRECTORY);

  guideImageSettings.exposureTime = 5.0;
  guideImageSettings.whichCCD = 0;   /* 0 = imaging, 1 = tracking */
  guideImageSettings.binning = 0;  /* 0 = 1x1, 1 = 2x2, 2 = 3x3 */
  guideImageSettings.x = 0;
  guideImageSettings.y = 0;
  guideImageSettings.w = 640;
  guideImageSettings.h = 480;
  guideImageSettings.darkOption = 4;  /* Don't do darks */
  guideImageSettings.flatOption = 1;  /* Do not do flat fielding */
  strcpy_s(guideImageSettings.ObjectName,"");
  strcpy_s(guideImageSettings.ImageDir, DEFAULT_IMAGE_DIRECTORY);
  strcpy_s(guideImageSettings.DarkDir, DEFAULT_IMAGE_DIRECTORY);
  strcpy_s(guideImageSettings.FlatDir, DEFAULT_IMAGE_DIRECTORY);

  seriesSettings.startHours = 19.0;
  seriesSettings.duration   = 1.0;
  seriesSettings.interval   = 0.0;
  seriesSettings.startSeqNum = 0;
  strcpy_s(seriesSettings.objectName,"");
  strcpy_s(seriesSettings.imageDir, DEFAULT_IMAGE_DIRECTORY);
  strcpy_s(seriesSettings.DarkDir, DEFAULT_IMAGE_DIRECTORY);
  strcpy_s(seriesSettings.FlatDir, DEFAULT_IMAGE_DIRECTORY);
  seriesSettings.filterSeq.Use[0] = false; /* U */
  seriesSettings.filterSeq.Use[1] = false; /* B */
  seriesSettings.filterSeq.Use[2] = false; /* V */
  seriesSettings.filterSeq.Use[3] = false; /* R */
  seriesSettings.filterSeq.Use[4] = false; /* I */
  seriesSettings.filterSeq.Use[5] = false; /* C unfiltered */
  seriesSettings.filterSeq.exposures[0] = 0.0;
  seriesSettings.filterSeq.exposures[1] = 0.0;
  seriesSettings.filterSeq.exposures[2] = 0.0;
  seriesSettings.filterSeq.exposures[3] = 0.0;
  seriesSettings.filterSeq.exposures[4] = 0.0;
  seriesSettings.filterSeq.exposures[5] = 0.0;
  seriesSettings.whichCCD = 0;   /* 0 = imaging, 1 = tracking */
  seriesSettings.binning = 1;  /* 0 = 1x1, 1 = 2x2, 2 = 3x3 */
  seriesSettings.x = 0;
  seriesSettings.y = 0;
  seriesSettings.h = 0;
  seriesSettings.w = 0;
  seriesSettings.darkOption = 1;  /* Reuse dark frames */
  seriesSettings.flatOption = 1;  /* Do not do flat fielding */
  seriesSettings.AutoBumpScope = false;

  darkFrameSettings.numFrames = 5;
  darkFrameSettings.combineMethod = 1;  /* 1=median, 2=mean */
  darkFrameSettings.x = 0;
  darkFrameSettings.y = 0;
  darkFrameSettings.h = 0;
  darkFrameSettings.w = 0;
  darkFrameSettings.binning=1;       /* 0 = 1x1, 1 = 2x2, 2 = 3x3 */
  darkFrameSettings.whichCCD = 0;    /* 0 = imaging, 1 = tracking */
  darkFrameSettings.exposureTime = 1.0;
  strcpy_s(darkFrameSettings.imageDir, DEFAULT_IMAGE_DIRECTORY);

  flatFrameSettings.numFrames = 5;
  flatFrameSettings.combineMethod = 1;  /* 1=median, 2=mean */
  flatFrameSettings.x = 0;
  flatFrameSettings.y = 0;
  flatFrameSettings.h = 0;
  flatFrameSettings.w = 0;
  flatFrameSettings.binning=1;       /* 0 = 1x1, 1 = 2x2, 2 = 3x3 */
  flatFrameSettings.whichCCD = 0;    /* 0 = imaging, 1 = tracking */
  flatFrameSettings.exposureTime = 1.0;
  flatFrameSettings.darkOption = 1;  /* Reuse dark frames */
  strcpy_s(flatFrameSettings.imageDir, DEFAULT_IMAGE_DIRECTORY);
  strcpy_s(flatFrameSettings.DarkDir, DEFAULT_IMAGE_DIRECTORY);
  flatFrameSettings.filterSeq.Use[0] = false; /* U */
  flatFrameSettings.filterSeq.Use[1] = false; /* B */
  flatFrameSettings.filterSeq.Use[2] = true; /* V */
  flatFrameSettings.filterSeq.Use[3] = false; /* R */
  flatFrameSettings.filterSeq.Use[4] = false; /* I */
  flatFrameSettings.filterSeq.Use[5] = false;  /* C unfiltered */
  flatFrameSettings.filterSeq.exposures[0] = 0.0;
  flatFrameSettings.filterSeq.exposures[1] = 0.0;
  flatFrameSettings.filterSeq.exposures[2] = 1.0;
  flatFrameSettings.filterSeq.exposures[3] = 0.0;
  flatFrameSettings.filterSeq.exposures[4] = 0.0;
  flatFrameSettings.filterSeq.exposures[4] = 0.0;

  stackSettings.numFrames = 5;
  stackSettings.x = 0;
  stackSettings.y = 0;
  stackSettings.h = 0;
  stackSettings.w = 0;
  stackSettings.binning=1;       /* 0 = 1x1, 1 = 2x2, 2 = 3x3 */
  stackSettings.whichCCD = 0;    /* 0 = imaging, 1 = tracking */
  stackSettings.exposureTime = 60.0;
  strcpy_s(stackSettings.imageDir, DEFAULT_IMAGE_DIRECTORY);
  strcpy_s(stackSettings.DarkDir, DEFAULT_IMAGE_DIRECTORY);
  strcpy_s(stackSettings.FlatDir, DEFAULT_IMAGE_DIRECTORY);

  /* Init the Observatory settings */

  strcpy_s(ObsSettings.name, sizeof(ObsSettings.name), "OSU-Lima Student Observatory");
  ObsSettings.longitude = ((float) LONGITUDE);
  ObsSettings.latitude = ((float) LATITUDE);
  ObsSettings.elevation = 900.0;
  ObsSettings.TimeZone = -5;
  strcpy_s(ObsSettings.Observer, sizeof(ObsSettings.Observer), "A. Shoup");
  strcpy_s(ObsSettings.Project, sizeof(ObsSettings.Project), "Eclipsing Binary");
  ObsSettings.ScopeNumber = 0;

  // Init the list of available scopes

  strcpy_s(ScopeList[0].name, sizeof(ScopeList[0].name), "16\" LX-200 GPS");
  strcpy_s(ScopeList[0].type, sizeof(ScopeList[0].type), "Schmidt-Cassegrain");
  ScopeList[0].FocalLength = (float) 4.064; // m
  ScopeList[0].FocalRatio = (float) 10.0;
  ScopeList[0].PrimaryDia = (float) 0.4064; // m
  strcpy_s(ScopeList[1].name, sizeof(ScopeList[1].name), "10\" LXD-55");
  strcpy_s(ScopeList[1].type, sizeof(ScopeList[1].type), "Schmidt-Newtonian");
  ScopeList[1].FocalLength = (float) 1.016; // m
  ScopeList[1].FocalRatio = (float) 4.0;
  ScopeList[1].PrimaryDia = (float) 0.254; // m
  strcpy_s(ScopeList[2].name, sizeof(ScopeList[2].name), "10\" RCX-400");
  strcpy_s(ScopeList[2].type, sizeof(ScopeList[2].type), "Ritchey-Chretien");
  ScopeList[2].FocalLength = (float) 2.032; // m
  ScopeList[2].FocalRatio = (float) 8.0;
  ScopeList[2].PrimaryDia = (float) 0.254; // m
  strcpy_s(ScopeList[3].name, sizeof(ScopeList[3].name), "5.5\" Schmidt Camera");
  strcpy_s(ScopeList[3].type, sizeof(ScopeList[3].type), "Schmidt");
  ScopeList[3].FocalLength = (float) 0.231; // m
  ScopeList[3].FocalRatio = (float) 1.65;
  ScopeList[3].PrimaryDia = (float) 0.1397; // m
  strcpy_s(ScopeList[4].name, sizeof(ScopeList[4].name), "80mm Refractor");
  strcpy_s(ScopeList[4].type, sizeof(ScopeList[4].type), "Refractor");
  ScopeList[4].FocalLength = (float) 0.912; // m
  ScopeList[4].FocalRatio = (float) 11.4;
  ScopeList[4].PrimaryDia = (float) 0.080; // m

  // Initial plate solution (astrometry)

  plateSolution.status = -4;  // none
  plateSolution.InitFieldCenterDEC = 0.0;  // deg.
  plateSolution.InitFieldCenterRA = 0.0;   // hours.
  plateSolution.PixelScale = 0.74;  // "/pixel

	// Create the main window and run it

	gcnew Form1();

  /* Init the object list */

	InitObjectList(OBJECT_LIST_FILE_NAME);

  Application::ThreadException += gcnew 
      ThreadExceptionEventHandler(OnUnhandled);

 Application::Run(Form1::CCDAutoForm);

	return 0;
}