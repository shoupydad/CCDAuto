/*
 * a "main" program for running/testing an SBIG ccd camera
 * from the Linux command line.
 *
 * -Steve Ashe
 */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "sbigudrv.h"

static int  interrupt;  /* CTRL-C caught */
static short ccd_temp[4096];
static short amb_temp[4096];
static char *camera_names[] =
    {"ST-4", "ST-4X", "ST-5", "ST-6", "ST-7",
	"ST-8", "ST-5C", "TCE", "ST-237", "ST-K", "ST-9", "STV", "ST-10",
	"ST-1K"
    };


static CAMERA_TYPE  camera_type;
static GetCCDInfoResults0  info0;
static GetCCDInfoResults0  info1;
static GetCCDInfoResults2  info2;
static GetCCDInfoResults3  info3;
static int image_in_progress, tracking_in_progress;
static int st237_filter_target = 1;
static int write_fits(char *filename, int w, int h, unsigned short *data);


char *get_error(PAR_ERROR error)
{
    char *s = "";

    switch(error) {
    case CE_NO_ERROR: return s;
    case CE_CAMERA_NOT_FOUND: s = "CE_CAMERA_NOT_FOUND"; break;
    case CE_EXPOSURE_IN_PROGRESS: s = "CE_EXPOSURE_IN_PROGRESS"; break;
    case CE_NO_EXPOSURE_IN_PROGRESS: s = "CE_NO_EXPOSURE_IN_PROGRESS"; break;
    case CE_UNKNOWN_COMMAND: s = "CE_UNKNOWN_COMMAND"; break;
    case CE_BAD_CAMERA_COMMAND: s = "CE_BAD_CAMERA_COMMAND"; break;
    case CE_BAD_PARAMETER: s = "CE_BAD_PARAMETER"; break;
    case CE_TX_TIMEOUT: s = "CE_TX_TIMEOUT"; break;
    case CE_RX_TIMEOUT: s = "CE_RX_TIMEOUT"; break;
    case CE_NAK_RECEIVED: s = "CE_NAK_RESBIGIVED"; break;
    case CE_CAN_RECEIVED: s = "CE_CAN_RESBIGIVED"; break;
    case CE_UNKNOWN_RESPONSE: s = "CE_UNKNOWN_RESPONSE"; break;
    case CE_BAD_LENGTH: s = "CE_BAD_LENGTH"; break;
    case CE_AD_TIMEOUT: s = "CE_AD_TIMEOUT"; break;
    case CE_KBD_ESC: s = "CE_KBD_ESC"; break;
    case CE_CHECKSUM_ERROR: s = "CE_CHECKSUM_ERROR"; break;
    case CE_EEPROM_ERROR: s = "CE_EEPROM_ERROR"; break;
    case CE_SHUTTER_ERROR: s = "CE_SHUTTER_ERROR"; break;
    case CE_UNKNOWN_CAMERA: s = "CE_UNKNOWN_CAMERA"; break;
    case CE_DRIVER_NOT_FOUND: s = "CE_DRIVER_NOT_FOUND"; break;
    case CE_DRIVER_NOT_OPEN: s = "CE_DRIVER_NOT_OPEN"; break;
    case CE_DRIVER_NOT_CLOSED: s = "CE_DRIVER_NOT_CLOSED"; break;
    case CE_SHARE_ERROR: s = "CE_SHARE_ERROR"; break;
    case CE_TCE_NOT_FOUND: s = "CE_TCE_NOT_FOUND"; break;
    case CE_AO_ERROR: s = "CE_AO_ERROR"; break;
    case CE_ECP_ERROR: s = "CE_ECP_ERROR"; break;
    case CE_MEMORY_ERROR: s = "CE_MEMORY_ERROR"; break;
    case CE_DEVICE_NOT_FOUND: s = "CE_DEVICE_NOT_FOUND"; break;
    case CE_DEVICE_NOT_OPEN: s = "CE_DEVICE_NOT_OPEN"; break;
    case CE_DEVICE_NOT_CLOSED: s = "CE_DEVICE_NOT_CLOSED"; break;
    case CE_DEVICE_NOT_IMPLEMENTED: s = "CE_DEVICE_NOT_IMPLEMENTED"; break;
    case CE_DEVICE_DISABLED: s = "CE_DEVICE_DISABLED"; break;
    case CE_OS_ERROR: s = "CE_OS_ERROR"; break;
    case CE_SOCK_ERROR: s = "CE_SOCK_ERROR"; break;
    case CE_SERVER_NOT_FOUND: s = "CE_SERVER_NOT_FOUND"; break;
    case CE_NEXT_ERROR: s = "CE_NEXT_ERROR"; break;
    }
    return s;
}

void show_error(char *s, int err)
{
    printf("ERROR: %s: %d\n", s, err);
}


static double getf(char *s, float default_value)
{
    char buffer[80];

    printf(s);
    fflush(stdout);
    if (fgets(buffer, 79, stdin) == NULL)
	exit(0);
    if (buffer[0] == '\n')
	return default_value;
    return atof(buffer);
}

static int geti(char *s, int default_value)
{
    char buffer[80];

    printf(s);
    fflush(stdout);
    if (fgets(buffer, 79, stdin) == NULL)
	exit(0);
    if (buffer[0] == '\n')
	return default_value;
    return atoi(buffer);
}


/*
 *  Start an exposure, wait for it, then download from the camera
 *  in bands.  This is somewhat complex, since it handles any size
 *  subimage of the CCD, and bands too.
 */
static void snap(void)
{
    int  result, i, ccd, is_dark, err, status;
    int  inner_exposure_time = 0, outer_exposure_time;
    double  f;
    unsigned short  *image_data;
    StartExposureParams  start_exposure_params;
    StartReadoutParams  start_readout_params;
    EndExposureParams  end_exposure_params;
    ReadoutLineParams  readout_line_params;
    QueryCommandStatusParams  query_command_status_params;
    QueryCommandStatusResults  query_command_status_results;
    int  readout_x, readout_y, readout_width, readout_height;
    int  readout_binning;

    is_dark = geti("is this a dark frame? [*0 = no, 1 = yes] ", 0);

    /* loop until we get good input */

    if (info1.readoutModes > 0) {
	while (1) {
	    if (interrupt) {
		interrupt = 0;
		return;
	    }
	    if (is_dark) {
		ccd = geti("ccd? [*0=imaging, 1=tracking] ", 0);
		if (ccd < 0 || ccd > 1)
		    continue;
	    } else {
		ccd = geti("ccd? [*0=imaging, 1=tracking, 2=both] ", 0);
		if (ccd < 0 || ccd > 2)
		    continue;
	    }
	    break;
	}
    } else
	ccd = 0;

    while (1) {
	if (interrupt) {
	    interrupt = 0;
	    return;
	}
	f = getf("Enter image exposure time (sec) [default 5.0]: ", 5.0);
	i = (int)(100.0*f + 0.5);
	if (ccd == 1) {
	    if (i < 12 || i > 65500) {
		printf("exposure time must be between 0.12 sec and 655 sec\n");
		continue;
	    }
	} else {
	    if (i < 12 || i > 167000) {
		printf("exposure time must be between 0.12 sec and 1670 sec\n");
		continue;
	    }
	}
	outer_exposure_time = i;
	break;
    }
    if (ccd == 2) {
	while (1) {
	    if (interrupt) {
		interrupt = 0;
		return;
	    }
	    f = getf("Enter tracking exposure time (sec) [default 1.0]: ", 1.0);
	    i = (int)(100.0*f);
	    if (i > outer_exposure_time) {
		printf("tracking ccd exposure time must be less than "
		  "imaging ccd exposure time\n");
		continue;
	    }
	    if (i < 12 || i > 167000) {
		printf("exposure time must be between 0.12 sec and 1670 sec\n");
		continue;
	    }
	    inner_exposure_time = i;
	    break;
	}
    }

    if (camera_type == ST5C_CAMERA) {
	int  abg_state;
	while (1) {
	    if (interrupt) {
		interrupt = 0;
		return;
	    }
	    i = geti("Enter ABG state [0 Off, 1 low, *2 medium, 3 high] ", 2);
	    switch(i) {
	    case 0: abg_state = ABG_LOW7; break;
	    case 1: abg_state = ABG_CLK_LOW7; break;
	    case 2: abg_state = ABG_CLK_MED7; break;
	    case 3: abg_state = ABG_CLK_HI7; break;
	    default:
		printf("invalid ABG state %d\n", i);
		continue;
	    }
	    break;
	}
    }

    /*
     * Set up the outer exposure
     */
    start_exposure_params.ccd = ccd&1;
    start_exposure_params.exposureTime = outer_exposure_time;
    start_exposure_params.abgState = ABG_CLK_MED7;
    start_exposure_params.openShutter = (is_dark? 2 : 1);

    /* deal with vane cameras */
    if (camera_type == ST5C_CAMERA || camera_type == ST237_CAMERA) {
	PulseOutParams  pulse_out_params;
	if (is_dark) {
	    pulse_out_params.numberPulses = 1;
	    pulse_out_params.pulseWidth = 0;
	    pulse_out_params.pulsePeriod = 2;  /* opaque vane */
	    SBIGUnivDrvCommand(CC_PULSE_OUT, &pulse_out_params, NULL);
	} else {
	    /* if it has a filter wheel, position it, otherwise Open */
	    if (info3.filterType == 3) {
		pulse_out_params.numberPulses = 1;
		pulse_out_params.pulseWidth = 0;
		pulse_out_params.pulsePeriod = st237_filter_target;
	    } else {
		pulse_out_params.numberPulses = 1;
		pulse_out_params.pulseWidth = 0;
		pulse_out_params.pulsePeriod = 1;
	    }
	    SBIGUnivDrvCommand(CC_PULSE_OUT, &pulse_out_params, NULL);
	}
	start_exposure_params.openShutter = 0;
    }

    result = SBIGUnivDrvCommand(CC_START_EXPOSURE,
				    &start_exposure_params, NULL);
    if (result != CE_NO_ERROR) {
	show_error("CC_START_EXPOSURE", result);
	return;
    }

    printf("exposure started; enter ^C to abort\n");

    /*
     *  Wait for the exposure to finish
     */

    while (TRUE) {
	/*
	 * Check for user asychronous abort
	 */
	if (interrupt) {
 interrupted:
	    interrupt = FALSE;
	    end_exposure_params.ccd = 0;
	    SBIGUnivDrvCommand(CC_END_EXPOSURE, &end_exposure_params, NULL);
	    end_exposure_params.ccd = 1;
	    SBIGUnivDrvCommand(CC_END_EXPOSURE, &end_exposure_params, NULL);
	    return;
	}

	/*
	 *  See if the outer exposure is done
	 */
	query_command_status_params.command = CC_START_EXPOSURE;
	err = SBIGUnivDrvCommand(CC_QUERY_COMMAND_STATUS,
	  &query_command_status_params, &query_command_status_results);
	if ((ccd&1) == 0)
	    status = query_command_status_results.status & 3;
	else
	    status = (query_command_status_results.status >> 2) & 3;
	if (status == CS_INTEGRATION_COMPLETE) {
	    end_exposure_params.ccd = ccd&1;
	    SBIGUnivDrvCommand(CC_END_EXPOSURE, &end_exposure_params, NULL);
	    break;
	}

	/*
	 * Take an "inner" (nested) exposure
	 */
	if (ccd == 2) {
	    unsigned short  *tracking_data;
	    char  filename[128];
	    int  tracking_nmbr = 0;
	    int  width, height;

	    width = info1.readoutInfo[0].width;
	    height = info1.readoutInfo[0].height;
	    tracking_data = malloc(width*height*sizeof(unsigned short));
	    start_exposure_params.ccd = 1;
	    start_exposure_params.exposureTime = inner_exposure_time;
	    start_exposure_params.abgState = 2;
	    start_exposure_params.openShutter = 0;  /* leave shutter */

	    result = SBIGUnivDrvCommand(CC_START_EXPOSURE,
				    &start_exposure_params, NULL);
	    if (result != CE_NO_ERROR) {
		show_error("CC_START_EXPOSURE", result);
		/* end outer exposure ... */
		end_exposure_params.ccd = 0;
		SBIGUnivDrvCommand(CC_END_EXPOSURE, &end_exposure_params, NULL);
		free(tracking_data);
		return;
	    }
	    /* wait for it */
	    while (TRUE) {
		if (interrupt)
		    goto interrupted;
		query_command_status_params.command = CC_START_EXPOSURE;
		SBIGUnivDrvCommand(CC_QUERY_COMMAND_STATUS,
		  &query_command_status_params, &query_command_status_results);
		status = (query_command_status_results.status >> 2) & 3;
		if (status == CS_INTEGRATION_COMPLETE)
		    break;
	    }
	    end_exposure_params.ccd = 1;
	    SBIGUnivDrvCommand(CC_END_EXPOSURE, &end_exposure_params, NULL);
	    /* read out */
	    start_readout_params.ccd = 1;
	    start_readout_params.readoutMode = 0;
	    start_readout_params.top = 0;
	    start_readout_params.left = 0;
	    start_readout_params.width = width;
	    start_readout_params.height = height;
	    SBIGUnivDrvCommand(CC_START_READOUT, &start_readout_params, NULL);
	    for (i = 0; i < start_readout_params.height; ++i) {
		readout_line_params.ccd = 1;
		readout_line_params.readoutMode = 0;
		readout_line_params.pixelStart = 0;
		readout_line_params.pixelLength = width;
		err = SBIGUnivDrvCommand(CC_READOUT_LINE,
			      &readout_line_params, tracking_data + i*width);
		if (err != CE_NO_ERROR) {
		    show_error("CC_READOUT_LINE on tracking CCD", err);
		    free(tracking_data);
		    return;
		}
	    }
	    sprintf(filename, "track%d.fits", tracking_nmbr++);
	    write_fits(filename, width, height, tracking_data);
	    free(tracking_data);
	} else {
	    /* show user elapsed time */
	    printf(".");
	    fflush(stdout);
	    sleep(1);
	}

    }

    /*
     * Exposure Complete
     */
    printf("Exposure complete\n");
    ccd &= 1;
    end_exposure_params.ccd = ccd;
    SBIGUnivDrvCommand(CC_END_EXPOSURE, &end_exposure_params, NULL);


    /* readout the image of the imaging ccd */
    while (TRUE) {
	i = geti("binning? [*1=1x1, 2=2x2] ", 1);
	if (interrupt) {
	    interrupt = FALSE;
	    return;
	}
	if (i == 1 || i == 2) {
	    readout_binning = i - 1;
	    break;
	}
    }
    sync();

    /* loop until we get good input */
    while (1) {
	char  input[80];
	GetCCDInfoResults0  *infop;

	if (interrupt) {
	    interrupt = FALSE;
	    return;
	}
	printf("Enter x, y, w, h for FITS image [<Enter> for default]: ");
	fflush(stdout);
	if (fgets(input, 79, stdin) == NULL)
	    exit(0);
	infop = (ccd == 0)? &info0 : &info1;
	if (input[0] == '\n') {
	    readout_x = readout_y = 0;
	    readout_width =
	      infop->readoutInfo[readout_binning].width;
	    readout_height =
	      infop->readoutInfo[readout_binning].height;
	    printf("image size is %d x %d\n", readout_width, readout_height);
	} else
	    sscanf(input, "%d %d %d %d", &readout_x, &readout_y,
		   &readout_width, &readout_height);
	if (readout_x < 0 || readout_y < 0) {
	    printf("invalid starting coordinate %d,%d\n",
		    readout_x, readout_y);
	    continue;
	}
	if (readout_width <= 0 || readout_height <= 0) {
	    printf("invalid width or height %dx%d\n", readout_width, readout_height);
	    continue;
	}
	break;
    }


    /* read out */
    start_readout_params.ccd = ccd;
    start_readout_params.readoutMode = 0;
    start_readout_params.top = readout_y;
    start_readout_params.left = readout_x;
    start_readout_params.width = readout_width;
    start_readout_params.height = readout_height;
    SBIGUnivDrvCommand(CC_START_READOUT, &start_readout_params, NULL);

    image_data = malloc(readout_width*readout_height*sizeof(unsigned short));
    for (i = 0; i < start_readout_params.height; ++i) {
	readout_line_params.ccd = ccd;
	readout_line_params.readoutMode = 0;
	readout_line_params.pixelStart = 0;
	readout_line_params.pixelLength = readout_width;
	err = SBIGUnivDrvCommand(CC_READOUT_LINE,
			      &readout_line_params,
			     image_data + i*readout_width);
	if (err != CE_NO_ERROR) {
	    show_error("CC_READOUT_LINE on CCD", err);
	    free(image_data);
	    return;
	}
    }
    write_fits("image.fits", readout_width, readout_height, image_data);
    printf("\nimage.fits\n");
    free(image_data);
    printf(" -- Done\n");
}

static void write_fits_record(int fd, char *s)
{
    register int  i;
    char  b[80];

    for (i = 0; i < 80; ++i)
	b[i] = (*s)? *s++ : ' ';
    write(fd, b, 80);
}

static int write_fits(char *filename, int w, int h, unsigned short *data)
{
#define W(x) write_fits_record(fd, x)
    register int i;
    int  min, max;
    int fd;
    char b[128];
    unsigned short u;

    if ((fd = open(filename, O_CREAT|O_WRONLY, 0666)) < 0) {
	printf("Cannot open '%s' for writing", filename);
	return -1;
    }
	    /*           1         2         3 */
	    /*  123456789012345678901234567890 */
    W(         "SIMPLE  =                    T  / conforms to FITS");
    W(         "BITPIX  =                   16  / 16-bit twos comp integer");
    W(         "NAXIS   =                    2  / two axes");
    sprintf(b, "NAXIS1  =                  %03d", w); W(b);
    sprintf(b, "NAXIS2  =                  %03d", h); W(b);
    W("END"); 
    for (i = 6; i < 36; ++i)
	W(" ");
    /* shouldn't we scale this to fit, first? */
    min = 10000000;
    max = -10000000;
    for (i = w*h; --i >= 0; ) {
	u = data[i];
	if (u > max)
	    max = u;
	if (u < min)
	    min = u;
	data[i] = (u<<8)|(u>>8);
    }
    printf("Wrote %d bytes of data, min=%d, max=%d\n", w*h*2, min, max);
    write(fd, data, w*h*sizeof(unsigned short));
    close(fd);
    sync();
    return 0;
#undef W
}

void establish_link(int parallel_port_address)
{
    int  lptAddress, deviceType, err;
    OpenDeviceParams odp;
    EstablishLinkParams  in;
    EstablishLinkResults  out;

    switch (parallel_port_address) {
	case 0:
	case 0x378:
	    lptAddress = 0x378;
	    deviceType = DEV_LPT1;
	    break;
	case 0x3BC:
	    lptAddress = 0x3bc;
	    deviceType = DEV_LPT1 + 1;
	    break;
	case 0x278:
	    lptAddress = 0x278;
	    deviceType = DEV_LPT1 + 2;
	    break;
	default:
	    fprintf(stderr, "unsupported parallel port address 0x%x\n",
	      parallel_port_address);
	    exit(1);
    }
    odp.deviceType = deviceType;
    odp.lptBaseAddress = lptAddress;

    err = SBIGUnivDrvCommand(CC_OPEN_DEVICE, &odp, NULL);
    if (err == CE_NO_ERROR)
	printf("Device Open OK\n");
    else {
	GetErrorStringParams  gesp;
	GetErrorStringResults  gesr;

	gesp.errorNo = err;
	SBIGUnivDrvCommand(CC_GET_ERROR_STRING, &gesp, &gesr);
	printf("CC_OPEN_DEVICE command failed:\n");
	printf("%s\n", gesr.errorString);
    }

#if 0
    in.port = 2;
    result = SBIGUnivDrvCommand(CC_ESTABLISH_LINK, &in, &out);
#else
    err = SBIGUnivDrvCommand(CC_ESTABLISH_LINK, &in, &out);
    if ( err == CE_NO_ERROR ) {
	camera_type = out.cameraType;
	printf("Link Established to %s\n", camera_names[out.cameraType]);
    } else
	show_error("Error in Establishing Link - ", err);
#endif

#if 0
    if (result == 0) {
	camera_type = (CAMERA_TYPE)out.cameraType;
	printf("link established, camera type is ");
	switch(camera_type) {
	case ST7_CAMERA: printf("ST7\n"); break;
	case ST8_CAMERA: printf("ST8\n"); break;
	case ST5C_CAMERA: printf("ST5C\n"); break;
	case TCE_CONTROLLER: printf("TCE\n"); break;
	case ST237_CAMERA: printf("ST237\n"); break;
	case STK_CAMERA: printf("STK\n"); break;
	case ST9_CAMERA: printf("ST9\n"); break;
	case STV_CAMERA: printf("STV\n"); break;
	default:
	    printf("unknown camera type %d\n", out.cameraType);
	}
	camera_type = out.cameraType;
    } else
	show_error("Establish link", result);
#endif
}

void  get_info(int type)
{
    int  result, i;
    GetCCDInfoParams  in;

    in.request = type;
    if (type == 0)
	result = SBIGUnivDrvCommand(CC_GET_CCD_INFO, &in, &info0);
    else if (type == 1)
	result = SBIGUnivDrvCommand(CC_GET_CCD_INFO, &in, &info1);
    else if (type == 2)
	result = SBIGUnivDrvCommand(CC_GET_CCD_INFO, &in, &info2);
    else if (type == 3)
	result = SBIGUnivDrvCommand(CC_GET_CCD_INFO, &in, &info3);
    else {
	printf("invalid CC_GET_CCD_INFO request type %d\n", type);
	return;
    }
    if (result != 0) {
	printf("CC_GET_CCD_INFO request of type %d failed\n"
	  "with error '%s'\n"
	  "This is probably normal, since not all cameras support all "
	  "CCD_INFO request types\n", type, get_error(result));
	return;
    }

    if (type == 0 || type == 1) {
	GetCCDInfoResults0  *info = (type == 0? &info0 : &info1);
	printf("Info for CCD %d...\n", type);
	printf(" firmwareVersion=%d\n", info->firmwareVersion);
	printf(" cameraType=%d\n", info->cameraType);
	printf(" name=\"%s\"\n", info->name);
	for (i = 0; i < info->readoutModes; ++i) {
	    int  k;

	    printf(" mode %d: %dx%d ", info->readoutInfo[i].mode,
	      info->readoutInfo[i].width, info->readoutInfo[i].height);
	    k = info->readoutInfo[i].gain;
	    k = 1000*((k>>12)&0xF) + 100*((k>>8)&0xF)
	      + 10*((k>>4)&0xF) + (k&0xF);
	    printf("gain %.2f ", 0.001*k);
	    k = info->readoutInfo[i].pixelWidth;
	    k = 10000*((k>>12)&0xF) + 1000*((k>>8)&0xF)
	      + 100*((k>>4)&0xF) + 10*(k&0xF);
	    printf(" %.2fx", 0.001*k);
	    k = info->readoutInfo[i].pixelHeight;
	    k = 10000*((k>>12)&0xF) + 1000*((k>>8)&0xF)
	      + 100*((k>>4)&0xF) + 10*(k&0xF);
	    printf("%.2f microns\n", 0.001*k);
	}
    } else if (type == 2) {
	printf("Extended Info...\n");
	printf(" badColumns=%d ", info2.badColumns);
	for (i = 0; i < info2.badColumns; ++i)
	    printf(" %d ", info2.columns[i]);
	printf("\n imagingABG=%d (%s)\n", info2.imagingABG,
	  (info2.imagingABG != 0? "present" : "none"));
	printf(" serialNumber=\"%s\"\n", info2.serialNumber);
    } else {
	printf("Extended info for ST237 and similar cameras...\n");
	printf("adSize=%d ", info3.adSize);
	switch(info3.filterType) {
	    case AD_UNKNOWN: printf("(unknown)\n"); break;
	    case AD_12_BITS: printf("(12 bits)\n"); break;
	    case AD_16_BITS: printf("(16 bits)\n"); break;
	}
	printf("filterType=%d ", info3.filterType);
	switch(info3.filterType) {
	    case FW_UNKNOWN: printf("(unknown)\n"); break;
	    case FW_EXTERNAL: printf("(external)\n"); break;
	    case FW_VANE: printf("(vane)\n"); break;
	    case FW_FILTER_WHEEL: printf("(filter wheel)\n"); break;
	}
    }
}

void  get_ccd_info(void)
{
    if (camera_type == 0) {
	printf("no link established, camera type is unknown at this time\n");
	return;
    }
    get_info(0);
    get_info(1);
    get_info(2);
    get_info(3);
}

static void show_ccd_status(int imaging_ccd_status, int tracking_ccd_status)
{
    if (imaging_ccd_status == 2)
	image_in_progress = 1;
    else if (imaging_ccd_status == 3)
	image_in_progress = 2;
    else
	image_in_progress = 0;
    if (tracking_ccd_status == 2)
	tracking_in_progress = 1;
    else if (tracking_ccd_status == 3)
	tracking_in_progress = 2;
    else
	tracking_in_progress = 0;

    if (image_in_progress != 0) {
	if (image_in_progress == 1)
	    printf("Imaging CCD exposing\n");
	else
	    printf("Imaging CCD exposed, ready for readout\n");
    }
    if (tracking_in_progress != 0) {
	if (tracking_in_progress == 1)
	    printf("Tracking CCD exposing\n");
	else
	    printf("Tracking CCD exposed, ready for readout\n");
    }
}

void catch(int sig)
{
    fprintf(stderr, "Caught signal %d\n", sig);
    interrupt = TRUE;
    signal(SIGINT, catch);
}

int main(int argc, char *argv[])
{
    int  i, result;
    GetDriverInfoParams  in;
    GetDriverInfoResults0 out;
    char buffer[80];
    int  port = 0x378;
    int  imaging_ccd_status, tracking_ccd_status;

    signal(SIGINT, catch);
    SBIGUnivDrvCommand(CC_OPEN_DRIVER, NULL, NULL);
    in.request = 0;
    result = SBIGUnivDrvCommand(CC_GET_DRIVER_INFO, &in, &out);
    printf("result=%d\n", result);
    if (result == CE_NO_ERROR) {
	printf("version=%d\n", out.version);
	printf("name=%s\n", out.name);
	printf("max_request=%d\n", out.maxRequest);
    }

    establish_link(port);
    get_ccd_info();
    if (camera_type == ST237_CAMERA || camera_type == ST5C_CAMERA) {
	/* initialize wheel/vane */
	PulseOutParams p;
	p.numberPulses = 1;
	p.pulseWidth = 0;
	p.pulsePeriod = SC_INITIALIZE_SHUTTER;
	result = SBIGUnivDrvCommand(CC_PULSE_OUT, &in, NULL);
	if (result != CE_NO_ERROR)
	    show_error("Initialization of vane/wheel", result);
    }

    while (1) {
	/* BLOCK */ {
	    QueryCommandStatusParams  s_in;
	    QueryCommandStatusResults  s_out;
	    int  imaging_ccd_status, tracking_ccd_status;

	    s_in.command = CC_START_EXPOSURE;
	    SBIGUnivDrvCommand(CC_QUERY_COMMAND_STATUS, &s_in, &s_out);
	    imaging_ccd_status = s_out.status&3;
	    tracking_ccd_status = (s_out.status>>2)&3;
	    show_ccd_status(imaging_ccd_status, tracking_ccd_status);
	}

	printf("> ");
	fflush(stdout);
	if (fgets(buffer, 79, stdin) == NULL)
	    exit(0);
	if (interrupt) {
	    interrupt = FALSE;
	    printf("^C: Quit program? ");
	    fflush(stdout);
	    fgets(buffer, 79, stdin);
	    if (buffer[0] == 'y' || buffer[0] == 'Y')
		exit(0);
	}
	if (buffer[0] == 'q')
	    break;
	if (buffer[0] == '?') {
	    printf("info\n");
	    printf("status\n");
	    printf("quit\n");
	    printf("filter\n");
	    printf("misc\n");
	    printf("relay\n");
	    printf("cool\n");
	    printf("expose\n");
	    continue;
	}

	if (strcmp(buffer, "info\n") == 0) {
	    get_ccd_info();
	    continue;
	}
	if (strcmp(buffer, "status\n") == 0) {
	    QueryCommandStatusParams  in;
	    QueryCommandStatusResults  out;
	    QueryTemperatureStatusResults  t_out;

	    in.command = CC_START_EXPOSURE;
	    if ((result = SBIGUnivDrvCommand(CC_QUERY_COMMAND_STATUS, &in, &out)) != 0) {
		show_error("status query CC_START_EXPOSURE", result);
	    } else {
		imaging_ccd_status = out.status&3;
		tracking_ccd_status = (out.status>>2)&3;
		show_ccd_status(imaging_ccd_status, tracking_ccd_status);
	    }
	    in.command = CC_MISCELLANEOUS_CONTROL;
	    if ((result = SBIGUnivDrvCommand(CC_QUERY_COMMAND_STATUS, &in, &out)) != 0) {
		show_error("status query CC_MISCELLANEOUS_CONTROL", result);
	    } else {
		printf("fan:%s ", ((out.status>>8)&1) != 0? "On":"Off");
		switch((out.status>>9)&3) {
		case 0: printf("shutter:Open "); break;
		case 1: printf("shutter:Closed "); break;
		case 2: printf("shutter:Opening "); break;
		case 3: printf("shutter:Closing ");
		}
		switch((out.status>>11)&3) {
		case 0: printf("LED:Off "); break;
		case 1: printf("LED:On "); break;
		case 2: printf("LED:BlinkSlow "); break;
		case 3: printf("LED:BlinkFast ");
		}
		out.status &= 0xFF;
		printf("shutterEdge=%d", out.status);
		if (out.status >= 7 && out.status <= 9)
		    printf("(OK)\n");
		else
		    printf("(ShutterFailure)\n");
	    }
	    in.command = CC_ACTIVATE_RELAY;
	    if ((result = SBIGUnivDrvCommand(CC_QUERY_COMMAND_STATUS, &in, &out)) != 0) {
		show_error("status query CC_ACTIVATE_RELAY", result);
	    } else {
		printf("relays -x:%d +x:%d +y:%d -y:%d\n",
		  out.status&1, (out.status>>1)&1,
		  (out.status>>2)&1, (out.status>>3)&1);
	    }
	    in.command = CC_PULSE_OUT;
	    if ((result = SBIGUnivDrvCommand(CC_QUERY_COMMAND_STATUS, &in, &out)) != 0) {
		show_error("status query CC_PULSE_OUT", result);
	    } else {
		printf("pulseActive=%s\n", ((out.status&1) != 0)? "TRUE":"FALSE");
	    }
	    if ((result = SBIGUnivDrvCommand(CC_QUERY_TEMPERATURE_STATUS, NULL,
			&t_out)) != 0) {
		show_error("status query CC_QUERY_TEMPERATURE_STATUS", result);
	    } else {
		printf("Temperature: enabled=%s ",
		  (t_out.enabled? "TRUE":"FALSE"));
		printf(" setpoint:%4.1fC ", 0.1*ccd_temp[t_out.ccdSetpoint]);
		printf("power=%d ", t_out.power);
		printf("ambient=%4.1fC ccd=%4.1fC\n",
		  0.1*amb_temp[t_out.ambientThermistor],
		  0.1*ccd_temp[t_out.ccdThermistor]);
	    }
	    continue;
	}

	if (strcmp(buffer, "expose\n") == 0) {
	    snap();
	    continue;
	}

	if (strcmp(buffer, "misc\n") == 0) {
	    MiscellaneousControlParams  in;

	    i = geti("fan? [0 OFF, *ON 1]: ", 1);
	    in.fanEnable = (i != 0);
	    i = geti("shutter [0 *LEAVE_SHUTTER, 1 OPEN_SHUTTER, "
		"2 CLOSE_SHUTTER, 3 INITIALIZE_SHUTTER] ", 0);
	    switch(i) {
	    case 0: in.shutterCommand = SC_LEAVE_SHUTTER; break;
	    case 1: in.shutterCommand = SC_OPEN_SHUTTER; break;
	    case 2: in.shutterCommand = SC_CLOSE_SHUTTER; break;
	    case 3: in.shutterCommand = SC_INITIALIZE_SHUTTER; break;
	    default:
		printf("invalid shutter command %d\n", i);
		continue;
	    }
	    i = geti("LED [0 OFF, 1 *ON, 2 SLOW, 3 FAST]: ", 1);
	    switch(i) {
	    case 0: in.ledState = LED_OFF; break;
	    case 1: in.ledState = LED_ON; break;
	    case 2: in.ledState = LED_BLINK_LOW; break;
	    case 3: in.ledState = LED_BLINK_HIGH; break;
	    default:
		printf("invalid LED state %d\n", i);
		continue;
	    }
	    sync();
	    result = SBIGUnivDrvCommand(CC_MISCELLANEOUS_CONTROL, &in, NULL);
	    if (result < 0)
		show_error("CC_MICELLANEOUS_CONTROL", result);
	    continue;
	}

	if (!strcmp(buffer, "relay\n")) {
#if 0
	    struct sbig_relay  relay;
	    i = geti("X time? [+- 0.1 s] ", 0);
	    if (i < 0) {
		relay.x_plus_time = 0;
		relay.x_minus_time = -i;
	    } else {
		relay.x_plus_time = i;
		relay.x_minus_time = 0;
	    }
	    i = geti("Y time? [+- 0.1 s] ", 0);
	    if (i < 0) {
		relay.y_plus_time = 0;
		relay.y_minus_time = -i;
	    } else {
		relay.y_plus_time = i;
		relay.y_minus_time = 0;
	    }
	    sync();
	    result = sbig_activate_relay(&relay);
	    printf("sbig_activate_relay() returned %d\n", result);
	    if (result < 0)
		printf("sbig error: %s\n", sbig_show_error(result));
	    continue;
#endif
	}

	if (strcmp(buffer, "filter\n") == 0) {
	    while (1) {
		if (camera_type == ST5C_CAMERA || camera_type == ST237_CAMERA) {
		    i = geti("filter 0 [*none], 1 [R], 1 [G], 2 [B] ", 0);
		    if (i < 0 || i > 2) {
			printf("Invalid filter value, must be 0 to 2\n");
			continue;
		    }
		    if (i == 0)
			st237_filter_target = 1;
		    else
			st237_filter_target = i+1;
		    printf("Filter %d will be active during exposure\n", i+1);
		} else {
		    PulseOutParams p;
		    i = geti("CFW8 position [1 to 5]: ", 0);
		    if (i < 1 || i > 5) {
			printf("Invalid CFW-8 value, must be 1 to 5\n");
			continue;
		    }
		    p.pulsePeriod = 18270;
		    p.numberPulses = 60;
		    p.pulseWidth = 500 + 300*(i-1);

		    result = SBIGUnivDrvCommand(CC_PULSE_OUT, &p, NULL);
		    if (result != CE_NO_ERROR)
			show_error("CC_PULSE_OUT", result);
		}
		break;
	    }
	}

	if (strcmp(buffer, "cool\n") == 0) {
	    SetTemperatureRegulationParams  in;
	    double  f;
	    int  t;

	    i = geti("Cooling [0 Off, 1 *On, 2 DirectDrive]: ", 1);
	    if (i == 2) {
		i = geti("Power [0..255, default 200]: ", 200);
		if (i < 0)
		    i = 0;
		else if (i > 255)
		    i = 255;
		in.regulation = 2;
		in.ccdSetpoint = i;
	    } else if (i == 1) {
		f = getf("Enter temperature in deg C [default 0.0]: ", 0.0);
		t = 10.0*f + 0.5;
		/* clamp temp to -/+150 degC */
		if (t > 1500)
		    t = 1500;
		else if (t < -1500)
		    t = -1500;
		/* could do a binary search here... */
		for (i = 0; i < 4096; ++i)
		    if (ccd_temp[i] <= t)
			break;
		in.regulation = 1;
		in.ccdSetpoint = i;
	    } else {
		in.regulation = 0;
		in.ccdSetpoint = 0;
	    }
	    result = SBIGUnivDrvCommand(CC_SET_TEMPERATURE_REGULATION, &in, NULL);
	    if (result != CE_NO_ERROR)
		show_error("CC_SET_TEMPERATURE_REGULATION", result);
	}
    }
    exit(0);
}


static short ccd_temp[4096] = {
10000,2134,1950,1842,1766,1707,1659,1618,1582,1551,1523,1498,
1475,1453,1434,1415,1398,1382,1367,1353,1339,1326,1314,1302,
1290,1279,1269,1259,1249,1240,1231,1222,1214,1205,1197,1190,
1182,1175,1168,1161,1154,1147,1141,1135,1129,1122,1117,1111,
1105,1100,1094,1089,1084,1079,1074,1069,1064,1059,1054,1050,
1045,1041,1036,1032,1028,1024,1020,1016,1012,1008,1004,1000,
996,993,989,985,982,978,975,971,968,964,961,958,
955,951,948,945,942,939,936,933,930,927,924,921,
918,916,913,910,907,905,902,899,897,894,892,889,
886,884,881,879,877,874,872,869,867,865,862,860,
858,855,853,851,849,847,844,842,840,838,836,834,
832,830,828,826,824,822,820,818,816,814,812,810,
808,806,804,802,800,798,797,795,793,791,789,788,
786,784,782,781,779,777,775,774,772,770,769,767,
765,764,762,761,759,757,756,754,753,751,749,748,
746,745,743,742,740,739,737,736,734,733,731,730,
728,727,726,724,723,721,720,718,717,716,714,713,
712,710,709,707,706,705,703,702,701,700,698,697,
696,694,693,692,690,689,688,687,685,684,683,682,
680,679,678,677,676,674,673,672,671,670,668,667,
666,665,664,663,661,660,659,658,657,656,655,653,
652,651,650,649,648,647,646,645,643,642,641,640,
639,638,637,636,635,634,633,632,631,630,629,628,
627,626,625,623,622,621,620,619,618,617,616,615,
614,613,612,611,611,610,609,608,607,606,605,604,
603,602,601,600,599,598,597,596,595,594,593,592,
592,591,590,589,588,587,586,585,584,583,583,582,
581,580,579,578,577,576,575,575,574,573,572,571,
570,569,569,568,567,566,565,564,563,563,562,561,
560,559,558,558,557,556,555,554,554,553,552,551,
550,549,549,548,547,546,545,545,544,543,542,542,
541,540,539,538,538,537,536,535,535,534,533,532,
531,531,530,529,528,528,527,526,525,525,524,523,
522,522,521,520,520,519,518,517,517,516,515,514,
514,513,512,512,511,510,509,509,508,507,507,506,
505,504,504,503,502,502,501,500,500,499,498,498,
497,496,495,495,494,493,493,492,491,491,490,489,
489,488,487,487,486,485,485,484,483,483,482,481,
481,480,479,479,478,478,477,476,476,475,474,474,
473,472,472,471,470,470,469,469,468,467,467,466,
465,465,464,464,463,462,462,461,460,460,459,459,
458,457,457,456,456,455,454,454,453,453,452,451,
451,450,450,449,448,448,447,447,446,445,445,444,
444,443,442,442,441,441,440,440,439,438,438,437,
437,436,436,435,434,434,433,433,432,432,431,430,
430,429,429,428,428,427,426,426,425,425,424,424,
423,423,422,421,421,420,420,419,419,418,418,417,
417,416,415,415,414,414,413,413,412,412,411,411,
410,410,409,408,408,407,407,406,406,405,405,404,
404,403,403,402,402,401,401,400,399,399,398,398,
397,397,396,396,395,395,394,394,393,393,392,392,
391,391,390,390,389,389,388,388,387,387,386,386,
385,385,384,384,383,383,382,382,381,381,380,380,
379,379,378,378,377,377,376,376,375,375,374,374,
373,373,372,372,371,371,370,370,370,369,369,368,
368,367,367,366,366,365,365,364,364,363,363,362,
362,361,361,360,360,360,359,359,358,358,357,357,
356,356,355,355,354,354,353,353,353,352,352,351,
351,350,350,349,349,348,348,348,347,347,346,346,
345,345,344,344,343,343,343,342,342,341,341,340,
340,339,339,339,338,338,337,337,336,336,335,335,
335,334,334,333,333,332,332,331,331,331,330,330,
329,329,328,328,328,327,327,326,326,325,325,325,
324,324,323,323,322,322,322,321,321,320,320,319,
319,319,318,318,317,317,316,316,316,315,315,314,
314,314,313,313,312,312,311,311,311,310,310,309,
309,309,308,308,307,307,306,306,306,305,305,304,
304,304,303,303,302,302,302,301,301,300,300,299,
299,299,298,298,297,297,297,296,296,295,295,295,
294,294,293,293,293,292,292,291,291,291,290,290,
289,289,289,288,288,287,287,287,286,286,286,285,
285,284,284,284,283,283,282,282,282,281,281,280,
280,280,279,279,278,278,278,277,277,277,276,276,
275,275,275,274,274,273,273,273,272,272,272,271,
271,270,270,270,269,269,269,268,268,267,267,267,
266,266,266,265,265,264,264,264,263,263,263,262,
262,261,261,261,260,260,260,259,259,258,258,258,
257,257,257,256,256,255,255,255,254,254,254,253,
253,253,252,252,251,251,251,250,250,250,249,249,
248,248,248,247,247,247,246,246,246,245,245,245,
244,244,243,243,243,242,242,242,241,241,241,240,
240,239,239,239,238,238,238,237,237,237,236,236,
236,235,235,235,234,234,233,233,233,232,232,232,
231,231,231,230,230,230,229,229,229,228,228,227,
227,227,226,226,226,225,225,225,224,224,224,223,
223,223,222,222,222,221,221,221,220,220,220,219,
219,218,218,218,217,217,217,216,216,216,215,215,
215,214,214,214,213,213,213,212,212,212,211,211,
211,210,210,210,209,209,209,208,208,208,207,207,
207,206,206,206,205,205,205,204,204,204,203,203,
203,202,202,202,201,201,201,200,200,200,199,199,
199,198,198,198,197,197,197,196,196,196,195,195,
195,194,194,194,193,193,193,192,192,192,191,191,
191,190,190,190,189,189,189,188,188,188,188,187,
187,187,186,186,186,185,185,185,184,184,184,183,
183,183,182,182,182,181,181,181,180,180,180,179,
179,179,178,178,178,178,177,177,177,176,176,176,
175,175,175,174,174,174,173,173,173,172,172,172,
171,171,171,171,170,170,170,169,169,169,168,168,
168,167,167,167,166,166,166,166,165,165,165,164,
164,164,163,163,163,162,162,162,161,161,161,161,
160,160,160,159,159,159,158,158,158,157,157,157,
157,156,156,156,155,155,155,154,154,154,153,153,
153,153,152,152,152,151,151,151,150,150,150,149,
149,149,149,148,148,148,147,147,147,146,146,146,
145,145,145,145,144,144,144,143,143,143,142,142,
142,142,141,141,141,140,140,140,139,139,139,139,
138,138,138,137,137,137,136,136,136,136,135,135,
135,134,134,134,133,133,133,133,132,132,132,131,
131,131,130,130,130,130,129,129,129,128,128,128,
128,127,127,127,126,126,126,125,125,125,125,124,
124,124,123,123,123,122,122,122,122,121,121,121,
120,120,120,120,119,119,119,118,118,118,118,117,
117,117,116,116,116,115,115,115,115,114,114,114,
113,113,113,113,112,112,112,111,111,111,111,110,
110,110,109,109,109,109,108,108,108,107,107,107,
106,106,106,106,105,105,105,104,104,104,104,103,
103,103,102,102,102,102,101,101,101,100,100,100,
100,99,99,99,98,98,98,98,97,97,97,96,
96,96,96,95,95,95,94,94,94,94,93,93,
93,92,92,92,92,91,91,91,90,90,90,90,
89,89,89,89,88,88,88,87,87,87,87,86,
86,86,85,85,85,85,84,84,84,83,83,83,
83,82,82,82,81,81,81,81,80,80,80,80,
79,79,79,78,78,78,78,77,77,77,76,76,
76,76,75,75,75,75,74,74,74,73,73,73,
73,72,72,72,71,71,71,71,70,70,70,70,
69,69,69,68,68,68,68,67,67,67,66,66,
66,66,65,65,65,65,64,64,64,63,63,63,
63,62,62,62,62,61,61,61,60,60,60,60,
59,59,59,58,58,58,58,57,57,57,57,56,
56,56,55,55,55,55,54,54,54,54,53,53,
53,52,52,52,52,51,51,51,51,50,50,50,
49,49,49,49,48,48,48,48,47,47,47,46,
46,46,46,45,45,45,45,44,44,44,44,43,
43,43,42,42,42,42,41,41,41,41,40,40,
40,39,39,39,39,38,38,38,38,37,37,37,
37,36,36,36,35,35,35,35,34,34,34,34,
33,33,33,32,32,32,32,31,31,31,31,30,
30,30,30,29,29,29,28,28,28,28,27,27,
27,27,26,26,26,26,25,25,25,24,24,24,
24,23,23,23,23,22,22,22,22,21,21,21,
20,20,20,20,19,19,19,19,18,18,18,18,
17,17,17,16,16,16,16,15,15,15,15,14,
14,14,14,13,13,13,12,12,12,12,11,11,
11,11,10,10,10,10,9,9,9,9,8,8,
8,7,7,7,7,6,6,6,6,5,5,5,
5,4,4,4,3,3,3,3,2,2,2,2,
1,1,1,1,0,0,0,0,0,0,0,-1,
-1,-1,-1,-2,-2,-2,-2,-3,-3,-3,-3,-4,
-4,-4,-4,-5,-5,-5,-5,-6,-6,-6,-7,-7,
-7,-7,-8,-8,-8,-8,-9,-9,-9,-9,-10,-10,
-10,-10,-11,-11,-11,-12,-12,-12,-12,-13,-13,-13,
-13,-14,-14,-14,-14,-15,-15,-15,-15,-16,-16,-16,
-16,-17,-17,-17,-18,-18,-18,-18,-19,-19,-19,-19,
-20,-20,-20,-20,-21,-21,-21,-21,-22,-22,-22,-22,
-23,-23,-23,-24,-24,-24,-24,-25,-25,-25,-25,-26,
-26,-26,-26,-27,-27,-27,-27,-28,-28,-28,-28,-29,
-29,-29,-30,-30,-30,-30,-31,-31,-31,-31,-32,-32,
-32,-32,-33,-33,-33,-33,-34,-34,-34,-34,-35,-35,
-35,-35,-36,-36,-36,-37,-37,-37,-37,-38,-38,-38,
-38,-39,-39,-39,-39,-40,-40,-40,-40,-41,-41,-41,
-41,-42,-42,-42,-42,-43,-43,-43,-44,-44,-44,-44,
-45,-45,-45,-45,-46,-46,-46,-46,-47,-47,-47,-47,
-48,-48,-48,-48,-49,-49,-49,-49,-50,-50,-50,-51,
-51,-51,-51,-52,-52,-52,-52,-53,-53,-53,-53,-54,
-54,-54,-54,-55,-55,-55,-55,-56,-56,-56,-56,-57,
-57,-57,-58,-58,-58,-58,-59,-59,-59,-59,-60,-60,
-60,-60,-61,-61,-61,-61,-62,-62,-62,-62,-63,-63,
-63,-63,-64,-64,-64,-65,-65,-65,-65,-66,-66,-66,
-66,-67,-67,-67,-67,-68,-68,-68,-68,-69,-69,-69,
-69,-70,-70,-70,-70,-71,-71,-71,-71,-72,-72,-72,
-73,-73,-73,-73,-74,-74,-74,-74,-75,-75,-75,-75,
-76,-76,-76,-76,-77,-77,-77,-77,-78,-78,-78,-78,
-79,-79,-79,-80,-80,-80,-80,-81,-81,-81,-81,-82,
-82,-82,-82,-83,-83,-83,-83,-84,-84,-84,-84,-85,
-85,-85,-85,-86,-86,-86,-86,-87,-87,-87,-88,-88,
-88,-88,-89,-89,-89,-89,-90,-90,-90,-90,-91,-91,
-91,-91,-92,-92,-92,-92,-93,-93,-93,-93,-94,-94,
-94,-95,-95,-95,-95,-96,-96,-96,-96,-97,-97,-97,
-97,-98,-98,-98,-98,-99,-99,-99,-99,-100,-100,-100,
-100,-101,-101,-101,-102,-102,-102,-102,-103,-103,-103,-103,
-104,-104,-104,-104,-105,-105,-105,-105,-106,-106,-106,-106,
-107,-107,-107,-108,-108,-108,-108,-109,-109,-109,-109,-110,
-110,-110,-110,-111,-111,-111,-111,-112,-112,-112,-112,-113,
-113,-113,-113,-114,-114,-114,-115,-115,-115,-115,-116,-116,
-116,-116,-117,-117,-117,-117,-118,-118,-118,-118,-119,-119,
-119,-119,-120,-120,-120,-121,-121,-121,-121,-122,-122,-122,
-122,-123,-123,-123,-123,-124,-124,-124,-124,-125,-125,-125,
-126,-126,-126,-126,-127,-127,-127,-127,-128,-128,-128,-128,
-129,-129,-129,-129,-130,-130,-130,-130,-131,-131,-131,-132,
-132,-132,-132,-133,-133,-133,-133,-134,-134,-134,-134,-135,
-135,-135,-135,-136,-136,-136,-137,-137,-137,-137,-138,-138,
-138,-138,-139,-139,-139,-139,-140,-140,-140,-140,-141,-141,
-141,-142,-142,-142,-142,-143,-143,-143,-143,-144,-144,-144,
-144,-145,-145,-145,-145,-146,-146,-146,-147,-147,-147,-147,
-148,-148,-148,-148,-149,-149,-149,-149,-150,-150,-150,-151,
-151,-151,-151,-152,-152,-152,-152,-153,-153,-153,-153,-154,
-154,-154,-154,-155,-155,-155,-156,-156,-156,-156,-157,-157,
-157,-157,-158,-158,-158,-158,-159,-159,-159,-160,-160,-160,
-160,-161,-161,-161,-161,-162,-162,-162,-162,-163,-163,-163,
-164,-164,-164,-164,-165,-165,-165,-165,-166,-166,-166,-166,
-167,-167,-167,-168,-168,-168,-168,-169,-169,-169,-169,-170,
-170,-170,-171,-171,-171,-171,-172,-172,-172,-172,-173,-173,
-173,-173,-174,-174,-174,-175,-175,-175,-175,-176,-176,-176,
-176,-177,-177,-177,-177,-178,-178,-178,-179,-179,-179,-179,
-180,-180,-180,-180,-181,-181,-181,-182,-182,-182,-182,-183,
-183,-183,-183,-184,-184,-184,-185,-185,-185,-185,-186,-186,
-186,-186,-187,-187,-187,-188,-188,-188,-188,-189,-189,-189,
-189,-190,-190,-190,-191,-191,-191,-191,-192,-192,-192,-192,
-193,-193,-193,-194,-194,-194,-194,-195,-195,-195,-195,-196,
-196,-196,-197,-197,-197,-197,-198,-198,-198,-198,-199,-199,
-199,-200,-200,-200,-200,-201,-201,-201,-201,-202,-202,-202,
-203,-203,-203,-203,-204,-204,-204,-205,-205,-205,-205,-206,
-206,-206,-206,-207,-207,-207,-208,-208,-208,-208,-209,-209,
-209,-209,-210,-210,-210,-211,-211,-211,-211,-212,-212,-212,
-213,-213,-213,-213,-214,-214,-214,-214,-215,-215,-215,-216,
-216,-216,-216,-217,-217,-217,-218,-218,-218,-218,-219,-219,
-219,-220,-220,-220,-220,-221,-221,-221,-221,-222,-222,-222,
-223,-223,-223,-223,-224,-224,-224,-225,-225,-225,-225,-226,
-226,-226,-227,-227,-227,-227,-228,-228,-228,-229,-229,-229,
-229,-230,-230,-230,-231,-231,-231,-231,-232,-232,-232,-233,
-233,-233,-233,-234,-234,-234,-235,-235,-235,-235,-236,-236,
-236,-236,-237,-237,-237,-238,-238,-238,-238,-239,-239,-239,
-240,-240,-240,-241,-241,-241,-241,-242,-242,-242,-243,-243,
-243,-243,-244,-244,-244,-245,-245,-245,-245,-246,-246,-246,
-247,-247,-247,-247,-248,-248,-248,-249,-249,-249,-249,-250,
-250,-250,-251,-251,-251,-251,-252,-252,-252,-253,-253,-253,
-254,-254,-254,-254,-255,-255,-255,-256,-256,-256,-256,-257,
-257,-257,-258,-258,-258,-258,-259,-259,-259,-260,-260,-260,
-261,-261,-261,-261,-262,-262,-262,-263,-263,-263,-263,-264,
-264,-264,-265,-265,-265,-266,-266,-266,-266,-267,-267,-267,
-268,-268,-268,-269,-269,-269,-269,-270,-270,-270,-271,-271,
-271,-272,-272,-272,-272,-273,-273,-273,-274,-274,-274,-275,
-275,-275,-275,-276,-276,-276,-277,-277,-277,-278,-278,-278,
-278,-279,-279,-279,-280,-280,-280,-281,-281,-281,-281,-282,
-282,-282,-283,-283,-283,-284,-284,-284,-284,-285,-285,-285,
-286,-286,-286,-287,-287,-287,-288,-288,-288,-288,-289,-289,
-289,-290,-290,-290,-291,-291,-291,-292,-292,-292,-292,-293,
-293,-293,-294,-294,-294,-295,-295,-295,-296,-296,-296,-296,
-297,-297,-297,-298,-298,-298,-299,-299,-299,-300,-300,-300,
-300,-301,-301,-301,-302,-302,-302,-303,-303,-303,-304,-304,
-304,-305,-305,-305,-305,-306,-306,-306,-307,-307,-307,-308,
-308,-308,-309,-309,-309,-310,-310,-310,-311,-311,-311,-311,
-312,-312,-312,-313,-313,-313,-314,-314,-314,-315,-315,-315,
-316,-316,-316,-317,-317,-317,-318,-318,-318,-318,-319,-319,
-319,-320,-320,-320,-321,-321,-321,-322,-322,-322,-323,-323,
-323,-324,-324,-324,-325,-325,-325,-326,-326,-326,-327,-327,
-327,-328,-328,-328,-329,-329,-329,-329,-330,-330,-330,-331,
-331,-331,-332,-332,-332,-333,-333,-333,-334,-334,-334,-335,
-335,-335,-336,-336,-336,-337,-337,-337,-338,-338,-338,-339,
-339,-339,-340,-340,-340,-341,-341,-341,-342,-342,-342,-343,
-343,-343,-344,-344,-344,-345,-345,-345,-346,-346,-346,-347,
-347,-347,-348,-348,-348,-349,-349,-349,-350,-350,-350,-351,
-351,-351,-352,-352,-353,-353,-353,-354,-354,-354,-355,-355,
-355,-356,-356,-356,-357,-357,-357,-358,-358,-358,-359,-359,
-359,-360,-360,-360,-361,-361,-361,-362,-362,-362,-363,-363,
-364,-364,-364,-365,-365,-365,-366,-366,-366,-367,-367,-367,
-368,-368,-368,-369,-369,-369,-370,-370,-371,-371,-371,-372,
-372,-372,-373,-373,-373,-374,-374,-374,-375,-375,-375,-376,
-376,-377,-377,-377,-378,-378,-378,-379,-379,-379,-380,-380,
-380,-381,-381,-382,-382,-382,-383,-383,-383,-384,-384,-384,
-385,-385,-386,-386,-386,-387,-387,-387,-388,-388,-388,-389,
-389,-390,-390,-390,-391,-391,-391,-392,-392,-392,-393,-393,
-394,-394,-394,-395,-395,-395,-396,-396,-397,-397,-397,-398,
-398,-398,-399,-399,-400,-400,-400,-401,-401,-401,-402,-402,
-403,-403,-403,-404,-404,-404,-405,-405,-406,-406,-406,-407,
-407,-407,-408,-408,-409,-409,-409,-410,-410,-410,-411,-411,
-412,-412,-412,-413,-413,-414,-414,-414,-415,-415,-415,-416,
-416,-417,-417,-417,-418,-418,-419,-419,-419,-420,-420,-421,
-421,-421,-422,-422,-422,-423,-423,-424,-424,-424,-425,-425,
-426,-426,-426,-427,-427,-428,-428,-428,-429,-429,-430,-430,
-430,-431,-431,-432,-432,-432,-433,-433,-434,-434,-434,-435,
-435,-436,-436,-436,-437,-437,-438,-438,-438,-439,-439,-440,
-440,-441,-441,-441,-442,-442,-443,-443,-443,-444,-444,-445,
-445,-445,-446,-446,-447,-447,-448,-448,-448,-449,-449,-450,
-450,-450,-451,-451,-452,-452,-453,-453,-453,-454,-454,-455,
-455,-455,-456,-456,-457,-457,-458,-458,-458,-459,-459,-460,
-460,-461,-461,-461,-462,-462,-463,-463,-464,-464,-464,-465,
-465,-466,-466,-467,-467,-467,-468,-468,-469,-469,-470,-470,
-471,-471,-471,-472,-472,-473,-473,-474,-474,-475,-475,-475,
-476,-476,-477,-477,-478,-478,-479,-479,-479,-480,-480,-481,
-481,-482,-482,-483,-483,-483,-484,-484,-485,-485,-486,-486,
-487,-487,-488,-488,-488,-489,-489,-490,-490,-491,-491,-492,
-492,-493,-493,-494,-494,-494,-495,-495,-496,-496,-497,-497,
-498,-498,-499,-499,-500,-500,-501,-501,-502,-502,-502,-503,
-503,-504,-504,-505,-505,-506,-506,-507,-507,-508,-508,-509,
-509,-510,-510,-511,-511,-512,-512,-513,-513,-514,-514,-515,
-515,-516,-516,-517,-517,-517,-518,-518,-519,-519,-520,-520,
-521,-521,-522,-522,-523,-523,-524,-524,-525,-525,-526,-526,
-527,-527,-528,-529,-529,-530,-530,-531,-531,-532,-532,-533,
-533,-534,-534,-535,-535,-536,-536,-537,-537,-538,-538,-539,
-539,-540,-540,-541,-541,-542,-542,-543,-544,-544,-545,-545,
-546,-546,-547,-547,-548,-548,-549,-549,-550,-550,-551,-552,
-552,-553,-553,-554,-554,-555,-555,-556,-556,-557,-558,-558,
-559,-559,-560,-560,-561,-561,-562,-563,-563,-564,-564,-565,
-565,-566,-566,-567,-568,-568,-569,-569,-570,-570,-571,-572,
-572,-573,-573,-574,-574,-575,-576,-576,-577,-577,-578,-578,
-579,-580,-580,-581,-581,-582,-583,-583,-584,-584,-585,-586,
-586,-587,-587,-588,-589,-589,-590,-590,-591,-592,-592,-593,
-593,-594,-595,-595,-596,-596,-597,-598,-598,-599,-599,-600,
-601,-601,-602,-603,-603,-604,-604,-605,-606,-606,-607,-608,
-608,-609,-610,-610,-611,-611,-612,-613,-613,-614,-615,-615,
-616,-617,-617,-618,-619,-619,-620,-621,-621,-622,-622,-623,
-624,-624,-625,-626,-626,-627,-628,-629,-629,-630,-631,-631,
-632,-633,-633,-634,-635,-635,-636,-637,-637,-638,-639,-639,
-640,-641,-642,-642,-643,-644,-644,-645,-646,-646,-647,-648,
-649,-649,-650,-651,-651,-652,-653,-654,-654,-655,-656,-657,
-657,-658,-659,-660,-660,-661,-662,-662,-663,-664,-665,-665,
-666,-667,-668,-668,-669,-670,-671,-672,-672,-673,-674,-675,
-675,-676,-677,-678,-679,-679,-680,-681,-682,-682,-683,-684,
-685,-686,-686,-687,-688,-689,-690,-690,-691,-692,-693,-694,
-695,-695,-696,-697,-698,-699,-700,-700,-701,-702,-703,-704,
-705,-705,-706,-707,-708,-709,-710,-711,-711,-712,-713,-714,
-715,-716,-717,-718,-719,-719,-720,-721,-722,-723,-724,-725,
-726,-727,-728,-728,-729,-730,-731,-732,-733,-734,-735,-736,
-737,-738,-739,-740,-741,-742,-742,-743,-744,-745,-746,-747,
-748,-749,-750,-751,-752,-753,-754,-755,-756,-757,-758,-759,
-760,-761,-762,-763,-764,-765,-766,-767,-768,-770,-771,-772,
-773,-774,-775,-776,-777,-778,-779,-780,-781,-782,-783,-785,
-786,-787,-788,-789,-790,-791,-792,-793,-795,-796,-797,-798,
-799,-800,-801,-803,-804,-805,-806,-807,-809,-810,-811,-812,
-813,-815,-816,-817,-818,-819,-821,-822,-823,-824,-826,-827,
-828,-830,-831,-832,-833,-835,-836,-837,-839,-840,-841,-843,
-844,-845,-847,-848,-849,-851,-852,-853,-855,-856,-858,-859,
-860,-862,-863,-865,-866,-868,-869,-871,-872,-874,-875,-877,
-878,-880,-881,-883,-884,-886,-887,-889,-890,-892,-893,-895,
-897,-898,-900,-902,-903,-905,-906,-908,-910,-912,-913,-915,
-917,-918,-920,-922,-924,-925,-927,-929,-931,-933,-934,-936,
-938,-940,-942,-944,-946,-948,-949,-951,-953,-955,-957,-959,
-961,-963,-965,-967,-969,-972,-974,-976,-978,-980,-982,-984,
-987,-989,-991,-993,-996,-998,-1000,-1002,-1005,-1007,-1010,-1012,
-1014,-1017,-1019,-1022,-1024,-1027,-1029,-1032,-1034,-1037,-1040,-1042,
-1045,-1048,-1051,-1053,-1056,-1059,-1062,-1065,-1068,-1071,-1074,-1077,
-1080,-1083,-1086,-1089,-1092,-1096,-1099,-1102,-1106,-1109,-1112,-1116,
-1119,-1123,-1127,-1130,-1134,-1138,-1142,-1145,-1149,-1153,-1157,-1162,
-1166,-1170,-1174,-1179,-1183,-1188,-1192,-1197,-1202,-1206,-1211,-1216,
-1222,-1227,-1232,-1237,-1243,-1249,-1254,-1260,-1266,-1272,-1279,-1285,
-1292,-1299,-1305,-1313,-1320,-1327,-1335,-1343,-1351,-1360,-1369,-1378,
-1387,-1397,-1407,-1417,-1428,-1439,-1451,-1464,-1477,-1490,-1505,-1520,
-1536,-1553,-1572,-1591,-1612,-1636,-1661,-1689,-1720,-1756,-1796,-1845,
-1904,-1980,-2088,-2271 };
static short amb_temp[4096] = {
10000,2073,1921,1832,1769,1720,1680,1646,
1616,1591,1567,1547,1527,1510,1493,1478,1464,1451,1438,1426,
1415,1404,1394,1384,1375,1366,1357,1349,1341,1333,1326,1318,
1311,1305,1298,1292,1285,1279,1273,1268,1262,1257,1251,1246,
1241,1236,1231,1226,1222,1217,1213,1208,1204,1200,1195,1191,
1187,1183,1180,1176,1172,1168,1165,1161,1158,1154,1151,1147,
1144,1141,1138,1135,1131,1128,1125,1122,1119,1116,1114,1111,
1108,1105,1102,1100,1097,1094,1092,1089,1087,1084,1082,1079,
1077,1074,1072,1069,1067,1065,1062,1060,1058,1056,1053,1051,
1049,1047,1045,1043,1041,1038,1036,1034,1032,1030,1028,1026,
1024,1023,1021,1019,1017,1015,1013,1011,1009,1008,1006,1004,
1002,1000,999,997,995,994,992,990,988,987,985,984,
982,980,979,977,976,974,972,971,969,968,966,965,
963,962,960,959,957,956,954,953,952,950,949,947,
946,945,943,942,940,939,938,936,935,934,932,931,
930,928,927,926,925,923,922,921,920,918,917,916,
915,913,912,911,910,909,907,906,905,904,903,902,
900,899,898,897,896,895,894,892,891,890,889,888,
887,886,885,884,883,882,880,879,878,877,876,875,
874,873,872,871,870,869,868,867,866,865,864,863,
862,861,860,859,858,857,856,855,854,853,852,851,
851,850,849,848,847,846,845,844,843,842,841,840,
839,839,838,837,836,835,834,833,832,831,831,830,
829,828,827,826,825,825,824,823,822,821,820,820,
819,818,817,816,815,815,814,813,812,811,811,810,
809,808,807,807,806,805,804,803,803,802,801,800,
800,799,798,797,797,796,795,794,793,793,792,791,
790,790,789,788,788,787,786,785,785,784,783,782,
782,781,780,780,779,778,777,777,776,775,775,774,
773,773,772,771,770,770,769,768,768,767,766,766,
765,764,764,763,762,762,761,760,760,759,758,758,
757,756,756,755,754,754,753,753,752,751,751,750,
749,749,748,747,747,746,746,745,744,744,743,742,
742,741,741,740,739,739,738,737,737,736,736,735,
734,734,733,733,732,731,731,730,730,729,729,728,
727,727,726,726,725,724,724,723,723,722,722,721,
720,720,719,719,718,718,717,716,716,715,715,714,
714,713,712,712,711,711,710,710,709,709,708,708,
707,706,706,705,705,704,704,703,703,702,702,701,
701,700,699,699,698,698,697,697,696,696,695,695,
694,694,693,693,692,692,691,691,690,690,689,689,
688,688,687,686,686,685,685,684,684,683,683,682,
682,681,681,680,680,679,679,678,678,678,677,677,
676,676,675,675,674,674,673,673,672,672,671,671,
670,670,669,669,668,668,667,667,666,666,665,665,
665,664,664,663,663,662,662,661,661,660,660,659,
659,658,658,658,657,657,656,656,655,655,654,654,
653,653,653,652,652,651,651,650,650,649,649,648,
648,648,647,647,646,646,645,645,645,644,644,643,
643,642,642,641,641,641,640,640,639,639,638,638,
638,637,637,636,636,635,635,635,634,634,633,633,
632,632,632,631,631,630,630,629,629,629,628,628,
627,627,627,626,626,625,625,624,624,624,623,623,
622,622,622,621,621,620,620,620,619,619,618,618,
618,617,617,616,616,616,615,615,614,614,614,613,
613,612,612,612,611,611,610,610,610,609,609,608,
608,608,607,607,606,606,606,605,605,604,604,604,
603,603,603,602,602,601,601,601,600,600,599,599,
599,598,598,598,597,597,596,596,596,595,595,595,
594,594,593,593,593,592,592,592,591,591,590,590,
590,589,589,589,588,588,587,587,587,586,586,586,
585,585,585,584,584,583,583,583,582,582,582,581,
581,581,580,580,579,579,579,578,578,578,577,577,
577,576,576,576,575,575,574,574,574,573,573,573,
572,572,572,571,571,571,570,570,570,569,569,568,
568,568,567,567,567,566,566,566,565,565,565,564,
564,564,563,563,563,562,562,562,561,561,561,560,
560,560,559,559,558,558,558,557,557,557,556,556,
556,555,555,555,554,554,554,553,553,553,552,552,
552,551,551,551,550,550,550,549,549,549,548,548,
548,547,547,547,546,546,546,545,545,545,545,544,
544,544,543,543,543,542,542,542,541,541,541,540,
540,540,539,539,539,538,538,538,537,537,537,536,
536,536,535,535,535,535,534,534,534,533,533,533,
532,532,532,531,531,531,530,530,530,529,529,529,
529,528,528,528,527,527,527,526,526,526,525,525,
525,524,524,524,524,523,523,523,522,522,522,521,
521,521,520,520,520,520,519,519,519,518,518,518,
517,517,517,517,516,516,516,515,515,515,514,514,
514,513,513,513,513,512,512,512,511,511,511,510,
510,510,510,509,509,509,508,508,508,507,507,507,
507,506,506,506,505,505,505,505,504,504,504,503,
503,503,502,502,502,502,501,501,501,500,500,500,
500,499,499,499,498,498,498,498,497,497,497,496,
496,496,495,495,495,495,494,494,494,493,493,493,
493,492,492,492,491,491,491,491,490,490,490,489,
489,489,489,488,488,488,487,487,487,487,486,486,
486,485,485,485,485,484,484,484,484,483,483,483,
482,482,482,482,481,481,481,480,480,480,480,479,
479,479,478,478,478,478,477,477,477,477,476,476,
476,475,475,475,475,474,474,474,474,473,473,473,
472,472,472,472,471,471,471,470,470,470,470,469,
469,469,469,468,468,468,467,467,467,467,466,466,
466,466,465,465,465,465,464,464,464,463,463,463,
463,462,462,462,462,461,461,461,460,460,460,460,
459,459,459,459,458,458,458,458,457,457,457,456,
456,456,456,455,455,455,455,454,454,454,454,453,
453,453,453,452,452,452,451,451,451,451,450,450,
450,450,449,449,449,449,448,448,448,448,447,447,
447,447,446,446,446,445,445,445,445,444,444,444,
444,443,443,443,443,442,442,442,442,441,441,441,
441,440,440,440,440,439,439,439,438,438,438,438,
437,437,437,437,436,436,436,436,435,435,435,435,
434,434,434,434,433,433,433,433,432,432,432,432,
431,431,431,431,430,430,430,430,429,429,429,429,
428,428,428,428,427,427,427,427,426,426,426,426,
425,425,425,425,424,424,424,424,423,423,423,423,
422,422,422,422,421,421,421,421,420,420,420,420,
419,419,419,419,418,418,418,418,417,417,417,417,
416,416,416,416,415,415,415,415,414,414,414,414,
413,413,413,413,412,412,412,412,411,411,411,411,
410,410,410,410,410,409,409,409,409,408,408,408,
408,407,407,407,407,406,406,406,406,405,405,405,
405,404,404,404,404,403,403,403,403,402,402,402,
402,402,401,401,401,401,400,400,400,400,399,399,
399,399,398,398,398,398,397,397,397,397,396,396,
396,396,396,395,395,395,395,394,394,394,394,393,
393,393,393,392,392,392,392,391,391,391,391,391,
390,390,390,390,389,389,389,389,388,388,388,388,
387,387,387,387,387,386,386,386,386,385,385,385,
385,384,384,384,384,383,383,383,383,383,382,382,
382,382,381,381,381,381,380,380,380,380,379,379,
379,379,379,378,378,378,378,377,377,377,377,376,
376,376,376,376,375,375,375,375,374,374,374,374,
373,373,373,373,373,372,372,372,372,371,371,371,
371,370,370,370,370,369,369,369,369,369,368,368,
368,368,367,367,367,367,367,366,366,366,366,365,
365,365,365,364,364,364,364,364,363,363,363,363,
362,362,362,362,361,361,361,361,361,360,360,360,
360,359,359,359,359,359,358,358,358,358,357,357,
357,357,356,356,356,356,356,355,355,355,355,354,
354,354,354,354,353,353,353,353,352,352,352,352,
351,351,351,351,351,350,350,350,350,349,349,349,
349,349,348,348,348,348,347,347,347,347,347,346,
346,346,346,345,345,345,345,345,344,344,344,344,
343,343,343,343,342,342,342,342,342,341,341,341,
341,340,340,340,340,340,339,339,339,339,338,338,
338,338,338,337,337,337,337,336,336,336,336,336,
335,335,335,335,334,334,334,334,334,333,333,333,
333,332,332,332,332,332,331,331,331,331,330,330,
330,330,330,329,329,329,329,328,328,328,328,328,
327,327,327,327,326,326,326,326,326,325,325,325,
325,325,324,324,324,324,323,323,323,323,323,322,
322,322,322,321,321,321,321,321,320,320,320,320,
319,319,319,319,319,318,318,318,318,317,317,317,
317,317,316,316,316,316,315,315,315,315,315,314,
314,314,314,314,313,313,313,313,312,312,312,312,
312,311,311,311,311,310,310,310,310,310,309,309,
309,309,309,308,308,308,308,307,307,307,307,307,
306,306,306,306,305,305,305,305,305,304,304,304,
304,303,303,303,303,303,302,302,302,302,302,301,
301,301,301,300,300,300,300,300,299,299,299,299,
299,298,298,298,298,297,297,297,297,297,296,296,
296,296,295,295,295,295,295,294,294,294,294,294,
293,293,293,293,292,292,292,292,292,291,291,291,
291,291,290,290,290,290,289,289,289,289,289,288,
288,288,288,287,287,287,287,287,286,286,286,286,
286,285,285,285,285,284,284,284,284,284,283,283,
283,283,283,282,282,282,282,281,281,281,281,281,
280,280,280,280,280,279,279,279,279,278,278,278,
278,278,277,277,277,277,277,276,276,276,276,275,
275,275,275,275,274,274,274,274,273,273,273,273,
273,272,272,272,272,272,271,271,271,271,270,270,
270,270,270,269,269,269,269,269,268,268,268,268,
267,267,267,267,267,266,266,266,266,266,265,265,
265,265,264,264,264,264,264,263,263,263,263,263,
262,262,262,262,261,261,261,261,261,260,260,260,
260,260,259,259,259,259,258,258,258,258,258,257,
257,257,257,257,256,256,256,256,255,255,255,255,
255,254,254,254,254,254,253,253,253,253,252,252,
252,252,252,251,251,251,251,251,250,250,250,250,
250,249,249,249,249,248,248,248,248,248,247,247,
247,247,247,246,246,246,246,245,245,245,245,245,
244,244,244,244,244,243,243,243,243,242,242,242,
242,242,241,241,241,241,241,240,240,240,240,239,
239,239,239,239,238,238,238,238,238,237,237,237,
237,236,236,236,236,236,235,235,235,235,235,234,
234,234,234,233,233,233,233,233,232,232,232,232,
232,231,231,231,231,230,230,230,230,230,229,229,
229,229,229,228,228,228,228,227,227,227,227,227,
226,226,226,226,226,225,225,225,225,224,224,224,
224,224,223,223,223,223,222,222,222,222,222,221,
221,221,221,221,220,220,220,220,219,219,219,219,
219,218,218,218,218,218,217,217,217,217,216,216,
216,216,216,215,215,215,215,215,214,214,214,214,
213,213,213,213,213,212,212,212,212,212,211,211,
211,211,210,210,210,210,210,209,209,209,209,208,
208,208,208,208,207,207,207,207,207,206,206,206,
206,205,205,205,205,205,204,204,204,204,204,203,
203,203,203,202,202,202,202,202,201,201,201,201,
200,200,200,200,200,199,199,199,199,199,198,198,
198,198,197,197,197,197,197,196,196,196,196,196,
195,195,195,195,194,194,194,194,194,193,193,193,
193,192,192,192,192,192,191,191,191,191,190,190,
190,190,190,189,189,189,189,189,188,188,188,188,
187,187,187,187,187,186,186,186,186,185,185,185,
185,185,184,184,184,184,184,183,183,183,183,182,
182,182,182,182,181,181,181,181,180,180,180,180,
180,179,179,179,179,178,178,178,178,178,177,177,
177,177,176,176,176,176,176,175,175,175,175,174,
174,174,174,174,173,173,173,173,173,172,172,172,
172,171,171,171,171,171,170,170,170,170,169,169,
169,169,169,168,168,168,168,167,167,167,167,167,
166,166,166,166,165,165,165,165,165,164,164,164,
164,163,163,163,163,163,162,162,162,162,161,161,
161,161,161,160,160,160,160,159,159,159,159,159,
158,158,158,158,157,157,157,157,157,156,156,156,
156,155,155,155,155,154,154,154,154,154,153,153,
153,153,152,152,152,152,152,151,151,151,151,150,
150,150,150,150,149,149,149,149,148,148,148,148,
148,147,147,147,147,146,146,146,146,145,145,145,
145,145,144,144,144,144,143,143,143,143,143,142,
142,142,142,141,141,141,141,140,140,140,140,140,
139,139,139,139,138,138,138,138,138,137,137,137,
137,136,136,136,136,135,135,135,135,135,134,134,
134,134,133,133,133,133,132,132,132,132,132,131,
131,131,131,130,130,130,130,130,129,129,129,129,
128,128,128,128,127,127,127,127,126,126,126,126,
126,125,125,125,125,124,124,124,124,123,123,123,
123,123,122,122,122,122,121,121,121,121,120,120,
120,120,120,119,119,119,119,118,118,118,118,117,
117,117,117,116,116,116,116,116,115,115,115,115,
114,114,114,114,113,113,113,113,112,112,112,112,
112,111,111,111,111,110,110,110,110,109,109,109,
109,108,108,108,108,108,107,107,107,107,106,106,
106,106,105,105,105,105,104,104,104,104,103,103,
103,103,103,102,102,102,102,101,101,101,101,100,
100,100,100,99,99,99,99,98,98,98,98,97,
97,97,97,97,96,96,96,96,95,95,95,95,
94,94,94,94,93,93,93,93,92,92,92,92,
91,91,91,91,90,90,90,90,89,89,89,89,
89,88,88,88,88,87,87,87,87,86,86,86,
86,85,85,85,85,84,84,84,84,83,83,83,
83,82,82,82,82,81,81,81,81,80,80,80,
80,79,79,79,79,78,78,78,78,77,77,77,
77,76,76,76,76,75,75,75,75,74,74,74,
74,73,73,73,73,72,72,72,72,71,71,71,
71,70,70,70,70,69,69,69,69,68,68,68,
68,67,67,67,67,66,66,66,66,65,65,65,
65,64,64,64,64,63,63,63,63,62,62,62,
62,61,61,61,61,60,60,60,59,59,59,59,
58,58,58,58,57,57,57,57,56,56,56,56,
55,55,55,55,54,54,54,54,53,53,53,52,
52,52,52,51,51,51,51,50,50,50,50,49,
49,49,49,48,48,48,48,47,47,47,46,46,
46,46,45,45,45,45,44,44,44,44,43,43,
43,43,42,42,42,41,41,41,41,40,40,40,
40,39,39,39,39,38,38,38,37,37,37,37,
36,36,36,36,35,35,35,34,34,34,34,33,
33,33,33,32,32,32,32,31,31,31,30,30,
30,30,29,29,29,29,28,28,28,27,27,27,
27,26,26,26,25,25,25,25,24,24,24,24,
23,23,23,22,22,22,22,21,21,21,21,20,
20,20,19,19,19,19,18,18,18,17,17,17,
17,16,16,16,15,15,15,15,14,14,14,14,
13,13,13,12,12,12,12,11,11,11,10,10,
10,10,9,9,9,8,8,8,8,7,7,7,
6,6,6,6,5,5,5,4,4,4,4,3,
3,3,2,2,2,1,1,1,1,0,0,0,
0,0,0,0,-1,-1,-1,-2,-2,-2,-2,-3,
-3,-3,-4,-4,-4,-5,-5,-5,-5,-6,-6,-6,
-7,-7,-7,-7,-8,-8,-8,-9,-9,-9,-10,-10,
-10,-10,-11,-11,-11,-12,-12,-12,-13,-13,-13,-13,
-14,-14,-14,-15,-15,-15,-16,-16,-16,-17,-17,-17,
-17,-18,-18,-18,-19,-19,-19,-20,-20,-20,-20,-21,
-21,-21,-22,-22,-22,-23,-23,-23,-24,-24,-24,-24,
-25,-25,-25,-26,-26,-26,-27,-27,-27,-28,-28,-28,
-29,-29,-29,-29,-30,-30,-30,-31,-31,-31,-32,-32,
-32,-33,-33,-33,-34,-34,-34,-35,-35,-35,-35,-36,
-36,-36,-37,-37,-37,-38,-38,-38,-39,-39,-39,-40,
-40,-40,-41,-41,-41,-42,-42,-42,-43,-43,-43,-44,
-44,-44,-45,-45,-45,-45,-46,-46,-46,-47,-47,-47,
-48,-48,-48,-49,-49,-49,-50,-50,-50,-51,-51,-51,
-52,-52,-52,-53,-53,-53,-54,-54,-54,-55,-55,-55,
-56,-56,-56,-57,-57,-57,-58,-58,-58,-59,-59,-60,
-60,-60,-61,-61,-61,-62,-62,-62,-63,-63,-63,-64,
-64,-64,-65,-65,-65,-66,-66,-66,-67,-67,-67,-68,
-68,-68,-69,-69,-70,-70,-70,-71,-71,-71,-72,-72,
-72,-73,-73,-73,-74,-74,-74,-75,-75,-76,-76,-76,
-77,-77,-77,-78,-78,-78,-79,-79,-79,-80,-80,-81,
-81,-81,-82,-82,-82,-83,-83,-83,-84,-84,-85,-85,
-85,-86,-86,-86,-87,-87,-87,-88,-88,-89,-89,-89,
-90,-90,-90,-91,-91,-92,-92,-92,-93,-93,-93,-94,
-94,-95,-95,-95,-96,-96,-96,-97,-97,-98,-98,-98,
-99,-99,-99,-100,-100,-101,-101,-101,-102,-102,-103,-103,
-103,-104,-104,-104,-105,-105,-106,-106,-106,-107,-107,-108,
-108,-108,-109,-109,-110,-110,-110,-111,-111,-112,-112,-112,
-113,-113,-114,-114,-114,-115,-115,-116,-116,-116,-117,-117,
-118,-118,-118,-119,-119,-120,-120,-120,-121,-121,-122,-122,
-122,-123,-123,-124,-124,-124,-125,-125,-126,-126,-127,-127,
-127,-128,-128,-129,-129,-129,-130,-130,-131,-131,-132,-132,
-132,-133,-133,-134,-134,-135,-135,-135,-136,-136,-137,-137,
-138,-138,-138,-139,-139,-140,-140,-141,-141,-141,-142,-142,
-143,-143,-144,-144,-145,-145,-145,-146,-146,-147,-147,-148,
-148,-148,-149,-149,-150,-150,-151,-151,-152,-152,-153,-153,
-153,-154,-154,-155,-155,-156,-156,-157,-157,-158,-158,-158,
-159,-159,-160,-160,-161,-161,-162,-162,-163,-163,-164,-164,
-165,-165,-165,-166,-166,-167,-167,-168,-168,-169,-169,-170,
-170,-171,-171,-172,-172,-173,-173,-174,-174,-175,-175,-176,
-176,-177,-177,-178,-178,-178,-179,-179,-180,-180,-181,-181,
-182,-182,-183,-183,-184,-184,-185,-185,-186,-186,-187,-188,
-188,-189,-189,-190,-190,-191,-191,-192,-192,-193,-193,-194,
-194,-195,-195,-196,-196,-197,-197,-198,-198,-199,-199,-200,
-201,-201,-202,-202,-203,-203,-204,-204,-205,-205,-206,-206,
-207,-208,-208,-209,-209,-210,-210,-211,-211,-212,-212,-213,
-214,-214,-215,-215,-216,-216,-217,-218,-218,-219,-219,-220,
-220,-221,-222,-222,-223,-223,-224,-224,-225,-226,-226,-227,
-227,-228,-229,-229,-230,-230,-231,-231,-232,-233,-233,-234,
-234,-235,-236,-236,-237,-237,-238,-239,-239,-240,-241,-241,
-242,-242,-243,-244,-244,-245,-246,-246,-247,-247,-248,-249,
-249,-250,-251,-251,-252,-253,-253,-254,-254,-255,-256,-256,
-257,-258,-258,-259,-260,-260,-261,-262,-262,-263,-264,-264,
-265,-266,-266,-267,-268,-268,-269,-270,-270,-271,-272,-273,
-273,-274,-275,-275,-276,-277,-277,-278,-279,-280,-280,-281,
-282,-282,-283,-284,-285,-285,-286,-287,-288,-288,-289,-290,
-290,-291,-292,-293,-293,-294,-295,-296,-297,-297,-298,-299,
-300,-300,-301,-302,-303,-303,-304,-305,-306,-307,-307,-308,
-309,-310,-311,-311,-312,-313,-314,-315,-315,-316,-317,-318,
-319,-320,-320,-321,-322,-323,-324,-325,-325,-326,-327,-328,
-329,-330,-331,-331,-332,-333,-334,-335,-336,-337,-338,-339,
-339,-340,-341,-342,-343,-344,-345,-346,-347,-348,-349,-350,
-351,-351,-352,-353,-354,-355,-356,-357,-358,-359,-360,-361,
-362,-363,-364,-365,-366,-367,-368,-369,-370,-371,-372,-373,
-374,-375,-376,-377,-378,-379,-380,-382,-383,-384,-385,-386,
-387,-388,-389,-390,-391,-392,-394,-395,-396,-397,-398,-399,
-400,-402,-403,-404,-405,-406,-407,-409,-410,-411,-412,-413,
-415,-416,-417,-418,-420,-421,-422,-423,-425,-426,-427,-428,
-430,-431,-432,-434,-435,-436,-438,-439,-440,-442,-443,-445,
-446,-447,-449,-450,-452,-453,-454,-456,-457,-459,-460,-462,
-463,-465,-466,-468,-469,-471,-472,-474,-476,-477,-479,-480,
-482,-484,-485,-487,-488,-490,-492,-494,-495,-497,-499,-500,
-502,-504,-506,-508,-509,-511,-513,-515,-517,-519,-521,-523,
-524,-526,-528,-530,-532,-534,-536,-538,-541,-543,-545,-547,
-549,-551,-553,-556,-558,-560,-562,-565,-567,-569,-572,-574,
-577,-579,-582,-584,-587,-589,-592,-594,-597,-600,-602,-605,
-608,-611,-614,-616,-619,-622,-625,-628,-631,-635,-638,-641,
-644,-647,-651,-654,-658,-661,-665,-668,-672,-676,-680,-683,
-687,-691,-695,-700,-704,-708,-713,-717,-722,-726,-731,-736,
-741,-746,-751,-757,-762,-768,-773,-779,-785,-792,-798,-805,
-811,-818,-826,-833,-841,-849,-857,-866,-875,-884,-894,-904,
-915,-926,-938,-951,-964,-978,-993,-1010,-1027,-1047,-1067,-1091,
-1116,-1146,-1180,-1220,-1269,-1332,-1421,-1573 };
