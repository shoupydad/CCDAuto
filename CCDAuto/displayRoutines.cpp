
#include "stdafx.h"
#include <sys/stat.h>
#include <time.h>
#include "Form1.h"
#include "apogee.h"

using namespace System;
using namespace System::Threading;


namespace CCDAuto {


void updateStatusInfo(void) {

	MY_LOGICAL enabled;
	char Message[80], buffer[80], *cptr;
	int success;
	double ccd_temp, air_temp, setpointTemp, percentTE;
	int cooler_status;
	static bool UpdateBusy=false;
	struct tm LocalTime, UTTime;
	__time64_t CurrentSeconds;
	double JDate, lst;
	int lsthrs, lstmin, lstsec;
	static char AltaTempStatus[4][20]={"Off", "RampDown", "AtSetPoint", "Revision"};
	static char ApTempStatus[8][20]={"Off", "RampDown", "Correcting", "RampUp", "AtAmbient",
		"AtMax", "AtMin", "AtSetPoint"};
	
	/* Don't update if exposure, download or getting ccd status in progress */
	
	if (DontUpdate) return;
	
	if (ccd->Linked) {
		
		/* Show current status of ccd */
		
		Form1::SetCCDStatusTextBox("Linked");
		
		/* Get temperature status of ccd */
		
		switch (ccd->make) {
		   case SBIG_MAKE:
			   success = pCam_QueryTemperatureStatus(&enabled, &ccd_temp, &air_temp, &setpointTemp, &percentTE);
			   if (success) {
				   sprintf_s(Message, sizeof(Message), "%4.1f C (%4.1f)", ccd_temp, setpointTemp);
				   Form1::CCDAutoForm->SetCCDTempTextBox(Message);
				   sprintf_s(Message, sizeof(Message), "%5.1f %%", ((float) (percentTE*100.0)));
				   Form1::CCDAutoForm->SetCCDCoolingTextBox(Message);
			   } else {
				   Form1::StatusPrint("*** WARNING - Can't get ccd temperature status...\n");
				   Form1::CCDAutoForm->SetCCDCoolingTextBox("Unknown");
			   }
			   break;
		   case APOGEE47P_MAKE:
		   case APOGEEU8300_MAKE:
			   if (ccd->make == APOGEE47P_MAKE) {
				   success = apCam_QueryTemperatureStatus(&ccd_temp, &setpointTemp, &cooler_status);
				   if (success) {
					   Form1::CCDAutoForm->SetCCDCoolingTextBox(ApTempStatus[cooler_status]);
					   sprintf_s(Message, sizeof(Message), "%4.1f C (%4.1f)", ccd_temp, setpointTemp);
					   Form1::CCDAutoForm->SetCCDTempTextBox(Message);
				   } else {
					   Form1::StatusPrint("*** WARNING - Can't get ccd temperature status...\n");
					   Form1::CCDAutoForm->SetCCDCoolingTextBox("Unknown");
				   }
			   } else  {
				   success = altaCam_QueryTemperatureStatus(&ccd_temp, &setpointTemp, &cooler_status);
				   if (success) {
					   Form1::CCDAutoForm->SetCCDCoolingTextBox(AltaTempStatus[cooler_status]);
					   sprintf_s(Message, sizeof(Message), "%4.1f C (%4.1f)", ccd_temp, setpointTemp);
					   Form1::CCDAutoForm->SetCCDTempTextBox(Message);
				   } else {
					   Form1::StatusPrint("*** WARNING - Can't get ccd temperature status...\n");
					   Form1::CCDAutoForm->SetCCDCoolingTextBox("Unknown");
				   }
			   }
			   break;
		   case SXPRESS_MAKE:
			   Form1::CCDAutoForm->SetCCDCoolingTextBox("Cooling...");
			   break;
		}
	
	} else {   /* Not Linked */
		
		Form1::CCDAutoForm->SetCCDStatusTextBox("Unlinked");
	}
	
	if (ccd->filterPosition <= 0) {
		Form1::CCDAutoForm->SetCCDFilterTextBox("Unknown");
	} else {
		sprintf_s(Message, sizeof(Message), "%c", filterSet[ccd->filterPosition-1]);
		Form1::CCDAutoForm->SetCCDFilterTextBox(Message);
	}
	
	// Update time displays
	
		// UT

	_time64(&CurrentSeconds);
	_gmtime64_s(&UTTime, &CurrentSeconds);
	strftime(buffer, sizeof(buffer), "%X", &UTTime);
	Form1::CCDAutoForm->SetUTTextBox(buffer);
	
		// Local

	_localtime64_s(&LocalTime, &CurrentSeconds);
	strftime(buffer, sizeof(buffer), "%X", &LocalTime);
	Form1::CCDAutoForm->SetLocalTextBox(buffer);

	   // Julian Date
			
	JulianDay(UTTime.tm_year+1900, UTTime.tm_mon, 
			  UTTime.tm_mday, UTTime.tm_hour,
			  UTTime.tm_min, UTTime.tm_sec, 0,&JDate);
	sprintf_s(buffer, sizeof(buffer), "%lf13.5", JDate-2450000.0);
	Form1::CCDAutoForm->SetJDTextBox(buffer);

	   // Local Sidereal Time

	lmst(JDate,&lst);
	lsthrs = (int) floor(lst);
	lstmin = (int) floor((lst-lsthrs)*60.0);
	lstsec = (int) floor((lst-lsthrs-lstmin/60.0)*3600.0);
	sprintf_s(buffer, sizeof(buffer), "%02i:%02i:%02i", lsthrs, lstmin, lstsec);
	Form1::CCDAutoForm->SetLSTTextBox(buffer);
	
	/* If Image active, show its status */
	
	if (ccd->Image.light_frame.active) {
		sprintf_s(Message, sizeof(Message),"%6.2f", ccd->Image.light_frame.exposure);
		Form1::CCDAutoForm->SetCurrentImageExposeTextBox(Message);
		if (ccd->Image.light_frame.whichCCD == 0) {
			Form1::CCDAutoForm->SetCurrentImageWhichCCDTextBox("Imaging");
		} else {
			Form1::CCDAutoForm->SetCurrentImageWhichCCDTextBox("Tracking");
		}
		if (ccd->Image.light_frame.binning == 0) {
			Form1::CCDAutoForm->SetCurrentImageBinningTextBox("1x1");
		} else if (singleSettings.binning == 1) {
			Form1::CCDAutoForm->SetCurrentImageBinningTextBox("2x2");
		} else {
			Form1::CCDAutoForm->SetCurrentImageBinningTextBox("3x3");
		}
		sprintf_s(Message, sizeof(Message),"%d, %d, %d, %d", ccd->Image.light_frame.x, ccd->Image.light_frame.y,
			ccd->Image.light_frame.h, ccd->Image.light_frame.w);
		Form1::CCDAutoForm->SetCurrentImageFrameSizeTextBox(Message);
		if (strlen(ccd->Image.FileName) > 0) {
			cptr = strrchr(ccd->Image.FileName,'\\') + 1;
			if (cptr == NULL) {
				Form1::CCDAutoForm->SetCurrentImageFileNameTextBox(ccd->Image.FileName);
			} else {
				Form1::CCDAutoForm->SetCurrentImageFileNameTextBox(cptr);
			}
		}
		Form1::CCDAutoForm->SetCurrentImageObjectNameTextBox(ccd->Image.ObjectName);
	} else {
		sprintf_s(Message, sizeof(Message),"%6.2f", singleSettings.exposureTime);
		Form1::CCDAutoForm->SetCurrentImageExposeTextBox(Message);
		if (singleSettings.whichCCD == 0) {
			Form1::CCDAutoForm->SetCurrentImageWhichCCDTextBox("Imaging");
		} else {
			Form1::CCDAutoForm->SetCurrentImageWhichCCDTextBox("Tracking");
		}
		if (singleSettings.binning == 0) {
			Form1::CCDAutoForm->SetCurrentImageBinningTextBox("1x1");
		} else if (singleSettings.binning == 1) {
			Form1::CCDAutoForm->SetCurrentImageBinningTextBox("2x2");
		} else {
			Form1::CCDAutoForm->SetCurrentImageBinningTextBox("3x3");
		}
		sprintf_s(Message, sizeof(Message),"%d, %d, %d, %d", singleSettings.x, singleSettings.y,
			singleSettings.h, singleSettings.w);
		Form1::CCDAutoForm->SetCurrentImageFrameSizeTextBox(Message);
		Form1::CCDAutoForm->SetCurrentImageObjectNameTextBox(singleSettings.ObjectName);
		Form1::CCDAutoForm->SetCurrentImageDirectoryTextBox(singleSettings.ImageDir);
	}
	
	if (SeriesStarted) {
		if (PauseSeries) {
			Form1::CCDAutoForm->SetCurrentSeriesStatusTextBox("Paused");
		} else {
			Form1::CCDAutoForm->SetCurrentSeriesStatusTextBox("Running");
		}
	} else {
		Form1::CCDAutoForm->SetCurrentSeriesStatusTextBox("Not Active");
	}
	
	return;
}

}