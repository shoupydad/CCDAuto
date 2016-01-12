#include "stdafx.h"

// Import the type library to create an easy to use wrapper class
//#import "c:\Program Files\Common Files\System\Apogee.dll" no_namespace

#include "StarShootPro.h"

namespace CCDAuto {

bool ssCam_EstablishLink(void) {

	bool success;
	if (! ssCameraExists) {
		gcnew ssCamera();
		ssCameraExists = true;
	}
	success = ssCamera::ssCam_EstablishLink();
	return success;

}
			
bool ssCam_Unlink(void) {

	bool success;
	success = ssCamera::ssCam_Unlink();
	return success;
}
			
bool ssCam_GetCCDInfo(SSPRO_INFO *info) {

	bool success;
	success = ssCamera::ssCam_GetCCDInfo(info);
	return success;
}

float ssCam_GetCCDTemperature(void) {

	return ssCamera::ssCam_GetCCDTempterature();
}

bool ssCam_StartExposure(StartExposureParams *expose, StartReadoutParams *readout) {

	bool success;

	success = ssCamera::ssCam_StartExposure(expose, readout);
	return success;
}

bool ssCam_ImageReady(void) {

	return ssCamera::Ptr->ssCam_ImageReady();
}

bool ssCam_GetImage(unsigned short *image_data) {

	bool success;
	success = ssCamera::Ptr->ssCam_GetImage(image_data);

	return success;
}
}