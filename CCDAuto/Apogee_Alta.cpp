

#include "stdafx.h"

// Import the type library to create an easy to use wrapper class
#import "c:\Program Files\Common Files\System\Apogee.dll" no_namespace

#include "comutil.h"
#include "Form1.h"


ICamera2Ptr altaCam;  // Delcare a smart pointer to the camera interface
HRESULT hr_alta;		 // Return code from ActiveX methods

namespace CCDAuto {


bool altaCam_EstablishLink(void) {
	
	ICamDiscoverPtr Discover;		// Discovery interface
	
	CoInitialize(NULL);  // Initialize the COM library
	
	// Create the ActiveX object from the universally unique identifier
	
	hr_alta = altaCam.CreateInstance(__uuidof(Camera2));
	if (FAILED(hr_alta)) {
		Form1::StatusPrint("*** Warning - CreateInstance Failed (altaCam_EstablishLink)...\n");
		CoUninitialize();  // Close the COM library
		return false;
	}

	// Create the ICamDiscover object

	hr_alta = Discover.CreateInstance(__uuidof(CamDiscover));
	if (FAILED(hr_alta))	{
		Form1::StatusPrint("*** Warning - Failed to create the ICamDiscover object (altaCam_EstablishLink)\n" );
		altaCam = NULL;		// Release ICamera2 COM object
		CoUninitialize();		// Close the COM library
		return false;
	}

	// Set the checkboxes to default to searching both USB and 
	// ethernet interfaces for Alta cameras

	Discover->DlgCheckEthernet	= false;
	Discover->DlgCheckUsb		= true;
	Discover->DlgShowEthernet   = false;
	Discover->DlgShowUsb        = true;

	// Display the dialog box for finding an Alta camera

	Discover->ShowDialog(true);

	// If a camera was not selected, then release objects and exit

	if (! Discover->ValidSelection) {
		Form1::StatusPrint( "No valid camera selection made\n" );
		Discover	= NULL;		// Release ICamDiscover COM object
		altaCam	= NULL;		// Release ICamera2 COM object
		CoUninitialize();		// Close the COM library
		return false;
	}

	// Initialize camera using the ICamDiscover properties

	hr_alta = altaCam->Init(Discover->SelectedInterface, Discover->SelectedCamIdOne, Discover->SelectedCamIdTwo, 0x0);

	if (FAILED(hr_alta)) {
		Form1::StatusPrint("*** Warning - Failed to connect to camera (altaCam_EstablishLink)");
		Discover	= NULL;		// Release Discover COM object
		altaCam	= NULL;		// Release ICamera2 COM object
		CoUninitialize();		// Close the COM library
		return false;
	}

	// Tell user some info on camera connected

	//sprintf_s(Message, sizeof(Message), "*** Info - Camera model: %s\n", (char *) altaCam->GetCameraModel());
	//Form1::StatusPrint(Message);

	// Set initial states just to be sure

	altaCam->PutDigitizeOverscan(false);
	altaCam->PutDataAveraging(false);

  return true;

}

bool altaCam_Unlink(void) {
	
	altaCam->Close();
	altaCam = NULL;
	CoUninitialize();
	
	return true;
}

bool altaCam_GetCCDInfo(APOGEE_INFO *info) {

	long value;
	double valdouble;

	altaCam->get_ImagingColumns(&value);
	info->ImgColumns = info->MaxColumns = (int) value;
	altaCam->get_ImagingRows(&value);
	info->ImgRows = info->MaxRows = (int) value;
	altaCam->get_MaxBinningH(&value);
	info->MaxBinX = (int) value;
	altaCam->get_MaxBinningV(&value);
	info->MaxBinY = (int) value;
	altaCam->get_GainSixteenBit(&valdouble);
	info->Gain = (float) valdouble;
	info->PixelXSize = (float) altaCam->GetPixelSizeX();
	info->PixelYSize = (float) altaCam->GetPixelSizeY();
	info->TempCal       = (float) 0.0;
	info->TempScale     = (float) 0.0;
	info->Noise         = (float) DEFAULTU8300READNOISE; // e-'s RMS
	info->MinExposeTime = (float) altaCam->GetMinExposure();
	info->MaxExposeTime = (float) altaCam->GetMaxExposure();
	
	return true;
}

double altaCam_GetCCDTemperature() {

  double ccd_temp=0.0;

  ccd_temp = altaCam->GetTempCCD();

  return ccd_temp;
}

bool altaCam_QueryTemperatureStatus(double *temp, double *setpoint, int *status) {

	*temp = altaCam->GetTempCCD();
	*setpoint = altaCam->GetCoolerSetPoint();
	*status = altaCam->GetCoolerStatus();
	return true;
}

bool altaCam_SetTemperatureRegulation(int enable, double setpoint) {

	if (enable)
		altaCam->PutCoolerSetPoint(setpoint);
	altaCam->PutCoolerEnable((VARIANT_BOOL) enable);
	
	return true;
}

bool altaCam_StartExposure(StartExposureParams *expose, StartReadoutParams *readout) {

	bool success, Light;
	double duration;
	int stat;
	long hbin, vbin;
	
	//stat = (int) altaCam->GetImagingStatus();
	altaCam->PutRoiStartX((long) readout->left);
	altaCam->PutRoiStartY((long) readout->top);
	altaCam->PutRoiPixelsH((long) readout->width);
	altaCam->PutRoiPixelsV((long) readout->height);
	hbin = vbin = readout->readoutMode+1;
	altaCam->PutRoiBinningH(hbin);
	altaCam->PutRoiBinningV(vbin);
	duration = ((double) expose->exposureTime)/100.0;
	Light = (expose->openShutter == 1);
	altaCam->Expose(duration, Light);
	stat = (int) altaCam->GetImagingStatus();
	success = (stat == ALTA_STATUS_EXPOSING) || (stat == ALTA_STATUS_IMAGEREADY);
	
	return success;
}

bool altaCam_StopExposure(bool Digitize) {

	bool success;

	altaCam->StopExposure(Digitize);
	success = true;
	return success;
}

bool altaCam_GetLine(unsigned short *image_data, short x, short y,
				  short w, short h, short xbinning, short ybinning) {
  bool success;

  //apCam->StartX = x;
  //apCam->StartY = y;
  //apCam->NumX = w;
  //apCam->NumY = h;
  //apCam->BinX = xbinning;
  //apCam->BinY = ybinning;
  //hr_asc = apCam->GetLine((long) image_data);
  //success = ! FAILED(hr_asc);

  success = false;

  return success;
}

bool altaCam_Flush(short row) {

//	apCam->Flush(row);
	return true;
}

bool altaCam_GetImage(unsigned short *image_data, short x, short y,
			      short w, short h, short xbinning,
			      short ybinning) {

	altaCam->PutRoiStartX((long) x);
	altaCam->PutRoiStartY((long) y);
	altaCam->PutRoiPixelsH((long) w);
	altaCam->PutRoiPixelsV((long) h);
	altaCam->PutRoiBinningH((long) xbinning);
	altaCam->PutRoiBinningV((long) ybinning);
	altaCam->GetImage((long) image_data);
	
	return true;
}

int altaCam_ReadStatus() {

  return (int) altaCam->GetImagingStatus();
}
}