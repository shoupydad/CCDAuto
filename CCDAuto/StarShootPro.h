
#include "comutil.h"
#include "doRoutines.h"

using namespace STARSHOOTASCOMLib;

//using namespace 

//Camera ^ssCam; // Declare a smart pointer to the camera interface

namespace CCDAuto {

	public ref class ssCamera : System::Windows::Forms::Form {
		public:
			Camera ^ssCam;
			static ssCamera ^Ptr;
			ssCamera(void) {
				Ptr = this;
			}
			~ssCamera(void) {
			}
		static bool ssCam_EstablishLink(void) {
			ssCamera::Ptr->ssCam = gcnew Camera();
			ssCamera::Ptr->ssCam->Connected = true;
			if (! ssCamera::Ptr->ssCam->Connected) {
				MessageBox("*** Warnng - Can't connect to StarShoot Pro V2.0", OKAY, true);
				return false;
			}
			ssCamera::Ptr->ssCam->SetupDialog();
			return ssCamera::Ptr->ssCam->Connected;
			}
			
		static bool ssCam_Unlink(void) {
			ssCamera::Ptr->ssCam->Connected = false;
			return true;
		}
			
		static bool ssCam_GetCCDInfo(SSPRO_INFO *info) {

			int i;
			String ^buffer;

			info->CameraXSize = ssCamera::Ptr->ssCam->CameraXSize;
			info->CameraYSize = ssCamera::Ptr->ssCam->CameraYSize;
			info->CanPulseGuide = ssCamera::Ptr->ssCam->CanPulseGuide;
			info->CanSetCCDTemperature = ssCamera::Ptr->ssCam->CanSetCCDTemperature;
			buffer = gcnew String("");
			buffer = ssCamera::Ptr->ssCam->Description;
			for (i=0; (i<buffer->Length && i<sizeof(info->Description)); i++)
				info->Description[i] = (char) buffer[i];
			info->Description[i] = 0;
			delete buffer;
//			info->ElectronsPerADU = ssCamera::Ptr->ssCam->ElectronsPerADU;
//			info->FullWellCapacity = ssCamera::Ptr->ssCam->FullWellCapacity;
			info->MaxADU = ssCamera::Ptr->ssCam->MaxADU;
			info->MaxBinX = ssCamera::Ptr->ssCam->MaxBinX;
			info->MaxBinY = ssCamera::Ptr->ssCam->MaxBinY;
			info->PixelSizeX = ssCamera::Ptr->ssCam->PixelSizeX;
			info->PixelSizeY = ssCamera::Ptr->ssCam->PixelSizeY;
			
			return true;
		}

		static float ssCam_GetCCDTempterature(void) {

			return 999.0;
		}

		static bool ssCam_StartExposure(StartExposureParams *expose, StartReadoutParams *readout) {

			int timeout;
			bool success;
			double duration;

			ssCamera::Ptr->ssCam->StartX = readout->left;
			ssCamera::Ptr->ssCam->StartY = readout->top;
			ssCamera::Ptr->ssCam->NumX = readout->width;
			ssCamera::Ptr->ssCam->NumY = readout->height;
			duration = (double) expose->exposureTime/100.0;
			ssCamera::Ptr->ssCam->StartExposure(duration, (bool) expose->openShutter);
			timeout = 0;
			while ((ssCamera::Ptr->ssCam->CameraState != ASCOM_CAM_STATE_EXPOSING) && (timeout < 20)) {
				usleep(100000);
				timeout++;
			}
			success = ssCamera::Ptr->ssCam->CameraState == ASCOM_CAM_STATE_EXPOSING;
			return success;
		}

		static bool ssCam_ImageReady(void) {
			
			bool done;
			done = ssCamera::Ptr->ssCam->ImageReady;
			return done;
		}

		static bool ssCam_GetImage(unsigned short *image_data) {

			int nPixels, i, numx, numy;
			System::Object ^test;

			nPixels = ssCamera::Ptr->ssCam->NumX * ssCamera::Ptr->ssCam->NumY;
			numx = ssCamera::Ptr->ssCam->NumX;
			numy = ssCamera::Ptr->ssCam->NumY;

			//k = 0;
			//for (i=0; i<numx; i++) {
			//	for (j=0; j<numy; j++) {
			//		image_data[k++] = ssCamera::Ptr->ssCam->ImageArray[i][j];
			//	}
			//}
			i = 0;
			test = ssCamera::Ptr->ssCam->ImageArray::get();
			memcpy_s(image_data, MAXFRAMESIZE, &test, nPixels);
//			memcpy(image_data, &test, nPixels);
			return true;

		}
	};



}