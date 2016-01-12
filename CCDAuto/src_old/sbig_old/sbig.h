#ifndef _SBIG_H
#define _SBIG_H

#define VERSION_SBIG  2.0

typedef struct sbig_init {
    float linux_version;
    int	 nmbr_bad_columns;	/* bad columns in imaging CCD */
    int  bad_columns[4];
    int  imaging_abg_type;	/* 0 no ABG, 1 ABG present */
    char serial_number[10];
    unsigned firmware_version;
    char  camera_name[64];
    struct camera_info {
	int  nmbr_readout_modes;
	struct readout_mode {
	    int  mode;
	    int  width;			/* pixels */
	    int  height;		/* height */
	    int  gain;			/* in 0.01 e-/ADU */
	    unsigned pixel_width;	/* in nanometers */
	    unsigned pixel_height;	/* in nanometers */
	} readout_mode[12];
    } camera_info[2];
    int ST5_AD_size;
    int ST5_filter_type;
} SBIG_INIT;

extern int  sbig_init(int port, int options, SBIG_INIT *);

#define SBIG_IMAGING_CCD 0
#define SBIG_TRACKING_CCD 1

#define SBIG_CCD_STATUS_IDLE  0
#define SBIG_CCD_STATUS_IN_PROGRESS  2
#define SBIG_CCD_STATUS_COMPLETE  3

#define SBIG_CCD_SHUTTER_OPENED  0
#define SBIG_CCD_SHUTTER_CLOSED  1
#define SBIG_CCD_SHUTTER_OPENING  2
#define SBIG_CCD_SHUTTER_CLOSING  3

typedef struct sbig_status {
    int  imaging_ccd_status;
    int  tracking_ccd_status;
    int  fan_on;
    int  shutter_state;
    int  led_state;
    int  shutter_edge;
    int  plus_x_relay;
    int  minus_x_relay;
    int  plus_y_relay;
    int  minus_y_relay;
    int  pulse_active;
    int  temperature_regulation;
    int  temperature_setpoint;
    int  cooling_power;
    int  air_temperature;
    int  ccd_temperature;
} SBIG_STATUS;

extern int  sbig_get_status(SBIG_STATUS *);


#define SBIG_LEAVE_SHUTTER  0
#define SBIG_OPEN_SHUTTER  1
#define SBIG_CLOSE_SHUTTER  2
#define SBIG_INITIALIZE_SHUTTER  3

#define SBIG_LED_OFF  0
#define SBIG_LED_ON  1
#define SBIG_LED_BLINK_SLOW 2
#define SBIG_LED_BLINK_FAST 3

typedef struct sbig_control {
    int  fan_on;
    int  shutter;
    int  led;
} SBIG_CONTROL;

extern int  sbig_control(SBIG_CONTROL *);

typedef struct sbig_pulse {
    int nmbr_pulses;		/* 0 to 255 */
    int pulse_width;		/* microsec, min 9 */
    int pulse_interval;		/* microsec, min 27+pulse_width */
} SBIG_PULSE;

extern int  sbig_pulse(SBIG_PULSE *);

typedef struct sbig_relay {
    int x_plus_time;
    int x_minus_time;
    int y_plus_time;
    int y_minus_time;
} SBIG_RELAY;

extern int  sbig_activate_relay(SBIG_RELAY *);


/*
 * Shutter control.  0 for no change in shutter (i.e. control of shutter
 * using SBigControl class), 1 normal shutter (open during exposure,
 * closed otherwise), 2 shutter closed (for taking dark frames).
 */

#define SBIG_EXPOSE_SHUTTER_UNCHANGED  0
#define SBIG_EXPOSE_SHUTTER_NORMAL  1
#define SBIG_EXPOSE_SHUTTER_CLOSED  2

typedef struct sbig_expose {
    int ccd;
    int exposure_time;
    int abg_state;
    int shutter;
} SBIG_EXPOSE;

extern int  sbig_expose(SBIG_EXPOSE *);

/*
 *  Terminate the image and read it out.
 *  Use width == 0 and height == 0 to abort an image with no readout (all
 *   params other than ccd ignored)
 */

#define SBIG_BIN_1X1  0
#define SBIG_BIN_2X2  1
#define SBIG_BIN_3X3  2

typedef struct sbig_readout {
    int ccd;
    int binning;
    int x, y;
    int width, height;
    unsigned short *data;
    int data_size_in_bytes;
    int (*callback)(float percent_complete);
} SBIG_READOUT;

extern int  sbig_readout(SBIG_READOUT *);

#define SBIG_NO_SHUTTER_DELAY  0x0001	/* don't wait for shutter to close */

typedef struct sbig_readout2 {
    int flags;				/* see immediately above */
    int ccd;
    int binning;
    int x, y;
    int width, height;
    unsigned short *data;
    int data_size_in_bytes;
    int (*callback)(float percent_complete);
} SBIG_READOUT2;

extern int  sbig_readout2(SBIG_READOUT2 *);


#define SBIG_TEMP_REGULATION_OFF  0
#define SBIG_TEMP_REGULATION_ON  1
#define SBIG_TEMP_REGULATION_DIRECT_DRIVE  2

/*
 * Antiblooming gate control values
 */

#define SBIG_ABG_OFF  0
#define SBIG_ABG_LOW  1
#define SBIG_ABG_MEDIUM  2
#define SBIG_ABG_HIGH  3

typedef struct sbig_cool {
    int regulation;		/* 0 off, 1 on, 2 direct_drive */
    int temperature;		/* in 0.1 deg C, if 'on' */
    int direct_drive;		/* power [0..255], direct_drive */
} SBIG_COOL;

extern int  sbig_set_cooling(SBIG_COOL *);

extern int  sbig_set_ao7_deflection(int x_deflection, int y_deflection);

extern int  sbig_set_ao7_focus(int type);

#define SBIG_AO7_FOCUS_SOFT_CENTER 4
#define SBIG_AO7_FOCUS_HARD_CENTER  3
#define SBIG_AO7_FOCUS_STEP_TOWARD_SCOPE 2
#define SBIG_AO7_FOCUS_STEP_FROM_SCOPE 1

/*
 *	Return Error Codes
 *
 *	These are the error codes returned by the driver
 *	function.  They are prefixed with CE_ to designate
 *	them as camera errors.
 *
 *      The return codes from the sbig_xxx() routines will
 *      be the NEGATIVE of these on an error.
 *
 */

#define SBIG_CAMERA_NOT_FOUND	-1
#define SBIG_EXPOSURE_IN_PROGRESS -2
#define SBIG_NO_EXPOSURE_IN_PROGRESS -3
#define SBIG_UNKNOWN_COMMAND	-4
#define SBIG_BAD_CAMERA_COMMAND	-5
#define SBIG_BAD_PARAMETER	-6
#define SBIG_TX_TIMEOUT		-7
#define SBIG_RX_TIMEOUT		-8
#define SBIG_NAK_RESBIGIVED	-9
#define SBIG_CAN_RESBIGIVED	-10
#define SBIG_UNKNOWN_RESPONSE	-11
#define SBIG_BAD_LENGTH		-12
#define SBIG_AD_TIMEOUT		-13
#define SBIG_CHECKSUM_ERROR	-14
#define SBIG_EEPROM_ERROR	-15
#define SBIG_SHUTTER_ERROR	-16
#define SBIG_UNKNOWN_CAMERA	-17
#define SBIG_DRIVER_NOT_FOUND	-18
#define SBIG_DRIVER_NOT_OPEN	-19
#define SBIG_DRIVER_NOT_CLOSED	-20
#define SBIG_SHARE_ERROR	-21
#define SBIG_TSBIG_NOT_FOUND	-22
#define SBIG_NEXT_ERROR		-23
#define SBIG_NOT_ROOT		-24
char *sbig_show_error(int);

/*
 * IO strategy flags
 */
#define SBIG_DISABLE_INTERRUPTS 0x001
#define SBIG_LOCK_ALL	0x002
#define SBIG_SHORT_DELAYS 0x004
#define SBIG_DEFAULT_STRATEGY (SBIG_DISABLE_INTERRUPTS|SBIG_LOCK_ALL)

void sbig_set_linux_strategy(int);

#endif /* S_BIG_H */
