#include "stdafx.h"

// Import the type library to create an easy to use wrapper class
//#import "C:\Program Files\Meade\AutostarSuite\LPI\ImagerLibrary.dll"


#include "doRoutines.h"

using namespace Meade::Imager;
using namespace Meade::Imaging;


namespace CCDAuto {

	public ref class LPI : Meade::Imager::CMos {
	public:
		static LPI^ LPIptr;
		Meade::Imager::CMos ^cmos;
		Meade::Imager::CMos::ErrorCode errCode;
		String ^CameraName;
		Meade::Imaging::MeadeImage ^Image;
		LPI(void) {
			cmos = gcnew Meade::Imager::CMos();
			LPIptr = this;
		}
    private:
		~LPI(void) {
			delete CameraName;
			delete cmos;
		}
	public:
		bool InitImager(char *name) {

			bool success;
			char Message[80];

			CameraName = gcnew String(name);
			errCode = cmos->InitImager(CameraName);
			if (errCode != Meade::Imager::CMos::ErrorCode::NoError) {
				sprintf_s(Message, sizeof(Message), "Can't link to LPI, Got error code: %d", errCode);
				MessageBox(Message, OKAY, true);
				success = false;
			} else {
				success = true;
			}
			return success;
		}
		bool Disconnect(void) {

			cmos->StopImaging();
			cmos->disconnect();
			cmos->~CMos();
			return true;
		}
		bool BeginImage(float time, bool light) {

			bool success;
			char Message[80];
			
			cmos->ExposureSetting = Meade::Imager::CMos::ExposureType::Timed;
			cmos->ExposureTime = time;
//			cmos->Mono = true;
			errCode = cmos->BeginImaging(false);
			if (errCode != Meade::Imager::CMos::ErrorCode::NoError) {
				sprintf_s(Message, sizeof(Message), "Can't start single image on LPI, got error code: %d", errCode);
				MessageBox(Message, OKAY, true);
				success = false;
			} else
				success = true;
			return success;
		}
		bool GetImage(unsigned short *data) {
			
			int height, width, x, y, argb;
			System::Drawing::Color pixel;
			unsigned char *ImageDataBlue;

			Image = cmos->CurrentImage;
			width  = Image->TheBitmap->Width;
			height = Image->TheBitmap->Height;
			height = 10;
			ImageDataBlue = (unsigned char *) Image->ImageData.ToPointer();
			pixel = System::Drawing::Color::FromArgb(55);
			for (y=1; y<height; y++) {
				for (x=1; x<width; x++) {
					pixel = Image->TheBitmap->GetPixel(x,y);
					argb = pixel.ToArgb();
					*data++ = (argb&0xff) + ((argb>>8)&0xff) + ((argb>>16)&0xff);
				}
			}
			return true;
		}
		Meade::Imager::AImager::ImagerStatusType GetStatus(void) {

			return cmos->ImagerStatus;
		}

};

bool LPI_EstablishLink(CCD *ccd) {

	bool success;

	//Meade::Imager::CMos ^lpiptr;
	//Meade::Imaging::MeadeImage ^CurrentImage;
	//System::Drawing::Bitmap ^CurrentBitmap;
	
	//CurrentBitmap = gcnew System::Drawing::Bitmap(640,480);
	//CurrentImage = gcnew Meade::Imaging::MeadeImage(CurrentBitmap);
	//errCode = lpiptr->BeginImaging(false);
	//usleep(5000000);

	gcnew LPI();
	success = LPI::LPIptr->InitImager(ccd->name);

	return success;
}

void LPI_Unlink(CCD *ccd) {

	bool success;

	success = LPI::LPIptr->Disconnect();
	delete LPI::LPIptr;

	return;
}
bool LPI_GetCCDInfo(MEADE_INFO *meade_info) {

	meade_info->MaxColumns = 640;
	meade_info->MaxRows = 480;
	meade_info->binning = 0;
	return true;
}

bool LPI_StartExposure(StartExposureParams *expose) {

	float exposureTime;
	bool  Light;
	bool  success;

	exposureTime = (float) (expose->exposureTime/100.0);
	Light = (expose->openShutter == 1);
	success = LPI::LPIptr->BeginImage(exposureTime, Light);

	return success;
}

int LPI_GetStatus(void) {

	int status;

	status = (int) LPI::LPIptr->GetStatus();
	return status;
}

bool LPI_GetImage(unsigned short *image_data) {

	bool success;

	success = LPI::LPIptr->GetImage(image_data);

	return success;

}
};
