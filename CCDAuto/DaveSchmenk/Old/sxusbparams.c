#include <windows.h>
#include <stdio.h>
#define SXCCD_DANGEROUS     // Add prototypes to dangerous functions
#include "sxusbcam.h"

/***************************************************************************\
*                                                                           *
*                              CCD characteristics                          *
*                                                                           *
\***************************************************************************/

#define H9_INDEX            0
#define H9_MODEL            0x09
#define H9_WIDTH            1392
#define H9_HEIGHT           1040
#define H9_PIX_WIDTH        (int)(6.45*256)
#define H9_PIX_HEIGHT       (int)(6.45*256)
#define H9_HFRONT_PORCH     23
#define H9_HBACK_PORCH      40
#define H9_VFRONT_PORCH     11
#define H9_VBACK_PORCH      2
#define H9_VCLK_DELAY      -5  // VCLK delays are expressed in negative values for neg_udelay() function
#define HX_IMAGE_FIELDS     1
#define MX5_INDEX           1
#define MX5_MODEL           0x45
#define MX5_WIDTH           500
#define MX5_HEIGHT          290
#define MX5_PIX_WIDTH       (int)(9.8*256)
#define MX5_PIX_HEIGHT      (int)(12.6*256)
#define MX5_HFRONT_PORCH    23
#define MX5_HBACK_PORCH     30
#define MX5_VFRONT_PORCH    8
#define MX5_VBACK_PORCH     1
#define MX5_VCLK_DELAY      -2
#define MX7_INDEX           2
#define MX7_MODEL           0x47
#define MX7_WIDTH           752
#define MX7_HEIGHT          290
#define MX7_PIX_WIDTH       (int)(8.6*256)
#define MX7_PIX_HEIGHT      (int)(16.6*256)
#define MX7_HFRONT_PORCH    25
#define MX7_HBACK_PORCH     40
#define MX7_VFRONT_PORCH    7
#define MX7_VBACK_PORCH     1
#define MX7_VCLK_DELAY      -2
#define MX9_INDEX           3
#define MX9_MODEL           0x49
#define MX9_WIDTH           752
#define MX9_HEIGHT          290
#define MX9_PIX_WIDTH       (int)(11.6*256)
#define MX9_PIX_HEIGHT      (int)(22.4*256)
#define MX9_HFRONT_PORCH    25
#define MX9_HBACK_PORCH     40
#define MX9_VFRONT_PORCH    7
#define MX9_VBACK_PORCH     1
#define MX9_VCLK_DELAY      -2
#define MX25_INDEX          4
#define MX25_MODEL          0x59
#define MX25_WIDTH          3032
#define MX25_HEIGHT         2016
#define MX25_PIX_WIDTH      (int)(7.8*256)
#define MX25_PIX_HEIGHT     (int)(7.8*256)
#define MX25_HFRONT_PORCH   51
#define MX25_HBACK_PORCH    50
#define MX25_VFRONT_PORCH   4
#define MX25_VBACK_PORCH    2
#define MX25_VCLK_DELAY     -15
#define MX_IMAGE_FIELDS     2

int sx_ccd_hfront_porch[]   = {H9_HFRONT_PORCH,   MX5_HFRONT_PORCH,   MX7_HFRONT_PORCH,   MX9_HFRONT_PORCH, MX25_HFRONT_PORCH};
int sx_ccd_hback_porch[]    = {H9_HBACK_PORCH,    MX5_HBACK_PORCH,    MX7_HBACK_PORCH,    MX9_HBACK_PORCH,  MX25_HBACK_PORCH };
int sx_ccd_vfront_porch[]   = {H9_VFRONT_PORCH,   MX5_VFRONT_PORCH,   MX7_VFRONT_PORCH,   MX9_VFRONT_PORCH, MX25_VFRONT_PORCH};
int sx_ccd_vback_porch[]    = {H9_VBACK_PORCH,    MX5_VBACK_PORCH,    MX7_VBACK_PORCH,    MX9_VBACK_PORCH,  MX25_VBACK_PORCH };
int sx_ccd_width[]          = {H9_WIDTH,          MX5_WIDTH,          MX7_WIDTH,          MX9_WIDTH,        MX25_WIDTH       };
int sx_ccd_height[]         = {H9_HEIGHT,         MX5_HEIGHT,         MX7_HEIGHT,         MX9_HEIGHT,       MX25_HEIGHT      };
int sx_ccd_pix_width[]      = {H9_PIX_WIDTH,      MX5_PIX_WIDTH,      MX7_PIX_WIDTH,      MX9_PIX_WIDTH,    MX25_PIX_WIDTH   };
int sx_ccd_pix_height[]     = {H9_PIX_HEIGHT,     MX5_PIX_HEIGHT,     MX7_PIX_HEIGHT,     MX9_PIX_HEIGHT,   MX25_PIX_HEIGHT  };
int sx_ccd_vclk_delay[]     = {H9_VCLK_DELAY,     MX5_VCLK_DELAY,     MX7_VCLK_DELAY,     MX9_VCLK_DELAY,   MX25_VCLK_DELAY  };

int main(int argc, char **argv)
{

    HANDLE hCams[SXCCD_MAX_CAMS];
    int nCams, model, pcb, fw, i;
    struct t_sxccd_params ccd_params;
    unsigned char data[32];

    nCams = sxOpen(hCams);
    while (nCams--)
    {
    	if (argc == 1)
        {
        	/*
        	 * If no model passed in, just return the current settings.
        	 */
            model = sxGetCameraModel(hCams[nCams]);
            fw    = sxGetFirmwareVersion(hCams[nCams]);
            sxGetCameraParams(hCams[nCams], 0, &ccd_params);
            printf("Camera model SX-%c%d%c found ", model & 0x40 ? 'M' : 'H', model & 0x1F, model & 0x80 ? 'C' : ' ');
            printf("with F/W version %d-%d\n", fw >> 16, fw & 0xFFFF);
            printf("\tImage array dimensions: %d x %d pixels\n", ccd_params.width, ccd_params.height);
            printf("\tImage array horizontal front porch: %d pixels, back porch: %d pixels\n", ccd_params.hfront_porch, ccd_params.hback_porch);
            printf("\tImage array vertical   front porch: %d pixels, back porch: %d pixels\n", ccd_params.vfront_porch, ccd_params.vback_porch);
            printf("\tPixel dimensions: %.1f x %.1f microns\n", ccd_params.pix_width, ccd_params.pix_height);
            printf("\tSerial ports: %d\n", ccd_params.num_serial_ports);
            if (ccd_params.extra_caps & SXCCD_CAPS_STAR2K) printf("\tIntegrated STAR2000 port\n");
            if (ccd_params.extra_caps & SXCCD_CAPS_EEPROM) printf("\tOn-camera EEPROM\n");
            if (ccd_params.extra_caps & SXCCD_CAPS_GUIDER)
            {
                printf("\tAttached guider camera\n");
                sxGetCameraParams(hCams[nCams], 1, &ccd_params);
                printf("\t\tGuider image array dimensions: (%d, %d)\n", ccd_params.width, ccd_params.height);
                printf("\t\tGuider pixel dimensions: (%.1f, %.1f) microns\n", ccd_params.pix_width, ccd_params.pix_height);
            }
        }
        else
        {
        	/*
        	 * Set model and parameters.
        	 */
        	for (i = 0; i < strlen(argv[1]); i++)
                argv[1][i] = toupper(argv[1][i]);
        	if (strcmp("H9", argv[1]) == 0)
        	{
        		printf("Setting SXV H9\n");
        		model = H9_MODEL;
        		i     = H9_INDEX;
        		pcb   = 1;
        	}
            else if (strcmp("MX9", argv[1]) == 0)
            {
            	/*
            	 * This is special for my prototype camera :-)
            	 */
        		printf("Setting SX MX9\n");
        		model = MX9_MODEL;
        		i     = MX9_INDEX;
        		pcb   = 0;
            }
            else if (strcmp("M25", argv[1]) == 0)
            {
        		printf("Setting SXV M25\n");
        		model = MX25_MODEL;
        		i     = MX25_INDEX;
        		pcb   = 1;
            }
            else
            {
            	printf("Unknown camera.\n");
            	exit(1);
            }
            /*
             * Set model & PCB version.
             */
            memset(data, 0, 32);
            data[0]  = 0x69;
            data[1]  = sx_ccd_hfront_porch[i];
            data[2]  = sx_ccd_hback_porch[i];
            data[3]  = sx_ccd_width[i] & 0xFF;
            data[4]  = sx_ccd_width[i] >> 8;
            data[5]  = sx_ccd_vfront_porch[i];
            data[6]  = sx_ccd_vback_porch[i];
            data[7]  = sx_ccd_height[i] & 0xFF;
            data[8]  = sx_ccd_height[i] >> 8;
            data[9]  = sx_ccd_pix_width[i] & 0xFF;
            data[10] = sx_ccd_pix_width[i] >> 8;
            data[11] = sx_ccd_pix_height[i] & 0xFF;
            data[12] = sx_ccd_pix_height[i] >> 8;
            data[13] = sx_ccd_vclk_delay[1];
            data[16] = 0x66;
            data[17] = model;
            data[18] = pcb;
            sxWriteEEPROM(hCams[nCams], 0x1FE0, 32, data);
        }
        sxClose(hCams[nCams]);
    }
    return (0);
}

