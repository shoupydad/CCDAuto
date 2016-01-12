/*
 * GCCD - Gnome CCD Camera Controller
 * Copyright (C) 2001 David Schmenk
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */

#include <stdio.h>
#include "doRoutines.h"



/***************************************************************************\
*                                                                           *
*                     Low level CCD camera control                          *
*                                                                           *
\***************************************************************************/
/*
 * Connect to CCD camera.
 */
int spCam_EstablishLink(CCD *ccd)
{
  int  fd, msg_len, i;
  CCD_ELEM_TYPE msg[CCD_MSG_CCD_LEN/CCD_ELEM_SIZE];
  MX_SXV_INFO *info;

  info = &ccd->mx_sxv_info;
  info->fd = 0;
  if ((fd = open(info->filename, O_RDWR, 0)) < 0)
    return FALSE;

  /*
   * Request CCD parameters.
   */

  msg[CCD_MSG_HEADER_INDEX]    = CCD_MSG_HEADER;
  msg[CCD_MSG_LENGTH_LO_INDEX] = CCD_MSG_QUERY_LEN;
  msg[CCD_MSG_LENGTH_HI_INDEX] = 0;
  msg[CCD_MSG_INDEX]           = CCD_MSG_QUERY;
  write(fd, (char *)msg, CCD_MSG_QUERY_LEN);
  if ((msg_len = read(fd, (char *)msg, CCD_MSG_CCD_LEN)) != CCD_MSG_CCD_LEN) {
    fprintf(stderr, "CCD message length wrong: %d\n", msg_len);
    return FALSE;
  }

  /*
   * Response from CCD query.
   */

  if (msg[CCD_MSG_INDEX] != CCD_MSG_CCD) {
    fprintf(stderr, "Wrong message returned from query: 0x%04X", msg[CCD_MSG_INDEX]);
    return FALSE;
  }
  info->fd           = fd;
  info->width        = msg[CCD_CCD_WIDTH_INDEX];
  info->height       = msg[CCD_CCD_HEIGHT_INDEX];
  info->pixel_width  = (int)((msg[CCD_CCD_PIX_WIDTH_INDEX]  / 25.6) + 0.5) / 10.0;
  info->pixel_height = (int)((msg[CCD_CCD_PIX_HEIGHT_INDEX] / 25.6) + 0.5) / 10.0;
  info->fields       = msg[CCD_CCD_FIELDS_INDEX];
  info->depth        = msg[CCD_CCD_DEPTH_INDEX];
  info->dac_bits     = msg[CCD_CCD_DAC_INDEX];
  info->color        = msg[CCD_CCD_COLOR_INDEX];
  strncpy(info->camera, (char *)&msg[CCD_CCD_NAME_INDEX], CCD_CCD_NAME_LEN);
  info->camera[CCD_CCD_NAME_LEN] = '\0';
  for (i=CCD_CCD_NAME_LEN-1; i && (info->camera[i] == '\0' || info->camera[i] == ' ');
       i--)
    info->camera[i] = '\0'; // Strip off trailing spaces

  return TRUE;
}

int spCam_Unlink(CCD *ccd)
{
  int fd;

  if ((fd = ccd->mx_sxv_info.fd)) {
    ccd->mx_sxv_info.fd = 0;
    return (close(fd));
  }
  return (0);
}

/*
 * Get CCD information
 */

int spCam_GetCCDInfo(MX_SXV_INFO *info)
{
  int fd, msg_len, i;
  CCD_ELEM_TYPE msg[CCD_MSG_CCD_LEN/CCD_ELEM_SIZE];
  
  fd = info->fd;
  
  // Request CCD parameters.
  
  msg[CCD_MSG_HEADER_INDEX]    = CCD_MSG_HEADER;
  msg[CCD_MSG_LENGTH_LO_INDEX] = CCD_MSG_QUERY_LEN;
  msg[CCD_MSG_LENGTH_HI_INDEX] = 0;
  msg[CCD_MSG_INDEX]           = CCD_MSG_QUERY;
  write(fd, (char *)msg, CCD_MSG_QUERY_LEN);
  if ((msg_len = read(fd, (char *)msg, CCD_MSG_CCD_LEN)) != CCD_MSG_CCD_LEN) {
    fprintf(stderr, "CCD message length wrong: %d\n", msg_len);
    return FALSE;
  }

  // Response from CCD query.

  if (msg[CCD_MSG_INDEX] != CCD_MSG_CCD) {
    fprintf(stderr,
	    "Wrong message returned from query: 0x%04X", msg[CCD_MSG_INDEX]);
    return FALSE;
  }
  info->width        = msg[CCD_CCD_WIDTH_INDEX];
  info->height       = msg[CCD_CCD_HEIGHT_INDEX];
  info->pixel_width  = (int)((msg[CCD_CCD_PIX_WIDTH_INDEX]/25.6)+0.5)/10.0;
  info->pixel_height = (int)((msg[CCD_CCD_PIX_HEIGHT_INDEX]/25.6)+0.5)/10.0;
  info->fields       = msg[CCD_CCD_FIELDS_INDEX];
  info->depth        = msg[CCD_CCD_DEPTH_INDEX];
  info->dac_bits     = msg[CCD_CCD_DAC_INDEX];
  info->color        = msg[CCD_CCD_COLOR_INDEX];
  strncpy(info->camera, (char *)&msg[CCD_CCD_NAME_INDEX], CCD_CCD_NAME_LEN);
  info->camera[CCD_CCD_NAME_LEN] = '\0';
  for (i=CCD_CCD_NAME_LEN-1; i && 
	 (info->camera[i]=='\0' || info->camera[i]==' ');
       i--)
    info->camera[i] = '\0'; // Strip off trailing spaces

  return TRUE;
}

/*
 * Device control.
 */

void ccd_control(MX_SXV_INFO *ccd, int cmd, unsigned long param)
{
    CCD_ELEM_TYPE  msg[CCD_MSG_CTRL_LEN/CCD_ELEM_SIZE];
    /*
     * Send the control command.
     */
    msg[CCD_MSG_HEADER_INDEX]    = CCD_MSG_HEADER;
    msg[CCD_MSG_LENGTH_LO_INDEX] = CCD_MSG_CTRL_LEN;
    msg[CCD_MSG_LENGTH_HI_INDEX] = 0;
    msg[CCD_MSG_INDEX]           = CCD_MSG_CTRL;
    msg[CCD_CTRL_CMD_INDEX]      = cmd;
    msg[CCD_CTRL_PARM_LO_INDEX]  = param & 0xFFFF;
    msg[CCD_CTRL_PARM_HI_INDEX]  = param >> 16;
    write(ccd->fd, (char *)msg, CCD_MSG_CTRL_LEN);
}

/*
 * Request exposure.
 */

int spCam_StartExposure(CCD *ccd, StartExposureParams *expose,
			StartReadoutParams *readout)
{
  static int First=TRUE, ShutterOpen=FALSE;
  unsigned int msec;
  CCD_ELEM_TYPE  msg[CCD_MSG_EXP_LEN/CCD_ELEM_SIZE];

  msec = expose->exposureTime * 10;  // convert from 1/100 to 1/1000 s

  if (expose->openShutter == 2) { // dark frame
    if (ShutterOpen) {
      MessageBox("Close shutter, then click okay", OKAY);
      ShutterOpen = FALSE;
    }
  } else { // light frame
    if (! ShutterOpen) {
      MessageBox("Open shutter, then click okay", OKAY);
      ShutterOpen = TRUE;
    }
  }

  /*
   * Send the capture request.
   */

  msg[CCD_MSG_HEADER_INDEX]    = CCD_MSG_HEADER;
  msg[CCD_MSG_LENGTH_LO_INDEX] = CCD_MSG_EXP_LEN;
  msg[CCD_MSG_LENGTH_HI_INDEX] = 0;
  msg[CCD_MSG_INDEX]           = CCD_MSG_EXP;
  msg[CCD_EXP_WIDTH_INDEX]     = readout->width;
  msg[CCD_EXP_HEIGHT_INDEX]    = readout->height;
  msg[CCD_EXP_XOFFSET_INDEX]   = readout->left;
  msg[CCD_EXP_YOFFSET_INDEX]   = readout->top;
  msg[CCD_EXP_XBIN_INDEX]      = readout->readoutMode+1;
  msg[CCD_EXP_YBIN_INDEX]      = readout->readoutMode+1;
  msg[CCD_EXP_DAC_INDEX]       = ccd->mx_sxv_info.dac_bits;
  //  msg[CCD_EXP_FLAGS_INDEX]     = 0;
  msg[CCD_EXP_FLAGS_INDEX]     = 3; // do both fields (odd & even)
  msg[CCD_EXP_MSEC_LO_INDEX]   = msec & 0xFFFF;
  msg[CCD_EXP_MSEC_HI_INDEX]   = msec >> 16;
  write(ccd->mx_sxv_info.fd, (char *)msg, CCD_MSG_EXP_LEN);
    int i;
    printf("*** DEBUG - Wrote: ");
    for (i=0; i<14; i++) {
      printf("%04x ", msg[i]);
    }
    printf("\n");

  return TRUE;
}

/*
 * Abort current exposures.
 */

int spCam_EndExposure(CCD *ccd)
{
  CCD_ELEM_TYPE msg[CCD_MSG_ABORT_LEN/CCD_ELEM_SIZE];

  /*
   * Send the abort request.
   */

  msg[CCD_MSG_HEADER_INDEX]    = CCD_MSG_HEADER;
  msg[CCD_MSG_LENGTH_LO_INDEX] = CCD_MSG_ABORT_LEN;
  msg[CCD_MSG_LENGTH_HI_INDEX] = 0;
  msg[CCD_MSG_INDEX]           = CCD_MSG_ABORT;
  write(ccd->mx_sxv_info.fd, (char *)msg, CCD_MSG_ABORT_LEN);

  return;
}

/*
 * Load exposed image one row at a time.
 */

int spCam_ReadoutLine(CCD *ccd, StartReadoutParams *readout,
		      unsigned short *linePtr, unsigned short firstRow)
{
  int  msgLen;
  int  sizeOfPixel = (ccd->mx_sxv_info.depth + 7) / 8;
  int  binning = readout->readoutMode+1;
  int  bytesInRow = (readout->width / binning) * sizeOfPixel;
  int  bytesToRead;
  CCD_ELEM_TYPE *msg          = (CCD_ELEM_TYPE *) linePtr;

  if (firstRow) {  // Get header plus first scanline.
    bytesToRead = bytesInRow + CCD_MSG_IMAGE_LEN;
    msgLen = read(ccd->mx_sxv_info.fd, linePtr, bytesInRow+CCD_MSG_IMAGE_LEN);
    printf("*** DEBUG - msgLen = %d\n", msgLen);
    if (msgLen > 0) {
      if (msg[CCD_MSG_INDEX] == CCD_MSG_IMAGE) {  // Validate message length.
	if ((msg[CCD_MSG_LENGTH_LO_INDEX] +
	     (msg[CCD_MSG_LENGTH_HI_INDEX] << 16)) !=
	    (bytesInRow * (readout->height / binning) +
	     CCD_MSG_IMAGE_LEN)) {
	  fprintf(stderr, "Image size discrepency! Read %d, expected %d\n",
		  msg[CCD_MSG_LENGTH_LO_INDEX] +
		  (msg[CCD_MSG_LENGTH_HI_INDEX] << 16),
		  bytesInRow * (readout->height / binning) +
		  CCD_MSG_IMAGE_LEN);
	  return FALSE; // Failed
	}

	// Read rest of first scanline if it didn't make it
	// (should never happen).

	if (msgLen != bytesInRow + CCD_MSG_IMAGE_LEN)
	  read(ccd->mx_sxv_info.fd, linePtr,
	       bytesInRow - msgLen - CCD_MSG_IMAGE_LEN);

	// Move image data down to replace header.

	memcpy(linePtr, linePtr+CCD_MSG_IMAGE_LEN, bytesInRow);
      } else
	fprintf(stderr, "Error: wrong message 0x%04X\n", msg[CCD_MSG_INDEX]);
    } else {

      // Error reading pixels.  Bail out.

      fprintf(stderr, "Error reading exposure:%s\n", strerror(errno));
      return FALSE; // Failed
    }
  } else {
    read(ccd->mx_sxv_info.fd, linePtr, bytesInRow);
  }

  return TRUE;
}

/***************************************************************************\
*                                                                           *
*                     Low level telescope control                           *
*                                                                           *
\***************************************************************************/
/*
 * Starlight Xpress STAR 2000 paddle control.
 */
#define CMD_DELAY(d)    ((d)+0x100)
static unsigned int  star2000_baud_rate        = B9600;
static unsigned int  star2000_init[]           = {6, CMD_DELAY(0), 0x0F, 0x00, 0xF0, 0x00, CMD_DELAY(0)};
static unsigned int  star2000_open[]           = {6, CMD_DELAY(0), 0x0F, 0x00, 0xF0, 0x00, CMD_DELAY(0)};
//static unsigned int  star2000_open[]         = {1, 0x00};
static unsigned int  star2000_close[]          = {1, 0x00};
static unsigned int  star2000_move_stop[]      = {1, 0x00};
static unsigned int  star2000_move_left[]      = {2, 0x08, 0x18};
static unsigned int  star2000_move_right[]     = {2, 0x01, 0x11};
static unsigned int  star2000_move_up[]        = {2, 0x04, 0x14};
static unsigned int  star2000_move_down[]      = {2, 0x02, 0x12};
static unsigned int  star2000_slew_stop[]      = {1, 0x00};
static unsigned int  star2000_slew_left[]      = {4, 0x08, 0x18, CMD_DELAY(100), 0x19};
static unsigned int  star2000_slew_right[]     = {4, 0x01, 0x11, CMD_DELAY(100), 0x19};
static unsigned int  star2000_slew_up[]        = {4, 0x04, 0x14, CMD_DELAY(100), 0x16};
static unsigned int  star2000_slew_down[]      = {4, 0x02, 0x12, CMD_DELAY(100), 0x16};
static unsigned int  star2000_focus_stop[]     = {0};
static unsigned int  star2000_focus_in_slow[]  = {0};
static unsigned int  star2000_focus_out_slow[] = {0};
static unsigned int  star2000_focus_in_med[]   = {0};
static unsigned int  star2000_focus_out_med[]  = {0};
static unsigned int  star2000_focus_in_fast[]  = {0};
static unsigned int  star2000_focus_out_fast[] = {0};
static unsigned int *star2000_dir[]            = {star2000_move_stop,
                                                  star2000_move_left, star2000_move_right, star2000_move_up, star2000_move_down,
                                                  star2000_slew_stop,
                                                  star2000_slew_left, star2000_slew_right, star2000_slew_up, star2000_slew_down,
                                                  star2000_focus_stop,
                                                  star2000_focus_in_slow, star2000_focus_out_slow,
                                                  star2000_focus_in_med,  star2000_focus_out_med,
                                                  star2000_focus_in_fast, star2000_focus_out_fast};
/*
 * LX200 serial inteface commands.
 */
static unsigned int  lx200_baud_rate        = B9600;
static unsigned int  lx200_init[]           = {0};
static unsigned int  lx200_open[]           = {5, '#', ':', 'R', 'G', '#'};
static unsigned int  lx200_close[]          = {7, ':', 'Q', '#', ':', 'R', 'S', '#'};
static unsigned int  lx200_move_stop[]      = {3, ':', 'Q', '#'};
static unsigned int  lx200_move_left[]      = {4, ':', 'M', 'e', '#'};
static unsigned int  lx200_move_right[]     = {4, ':', 'M', 'w', '#'};
static unsigned int  lx200_move_up[]        = {4, ':', 'M', 'n', '#'};
static unsigned int  lx200_move_down[]      = {4, ':', 'M', 's', '#'};
static unsigned int  lx200_slew_stop[]      = {7, ':', 'Q', '#', ':', 'R', 'G', '#'};
static unsigned int  lx200_slew_left[]      = {8, ':', 'R', 'C', '#', ':', 'M', 'e', '#'};
static unsigned int  lx200_slew_right[]     = {8, ':', 'R', 'C', '#', ':', 'M', 'w', '#'};
static unsigned int  lx200_slew_up[]        = {8, ':', 'R', 'C', '#', ':', 'M', 'n', '#'};
static unsigned int  lx200_slew_down[]      = {8, ':', 'R', 'C', '#', ':', 'M', 's', '#'};
static unsigned int  lx200_focus_stop[]     = {4, ':', 'F', 'Q', '#'};
static unsigned int  lx200_focus_in_slow[]  = {8, ':', 'F', 'S', '#', ':', 'F', '+', '#'};
static unsigned int  lx200_focus_out_slow[] = {8, ':', 'F', 'S', '#', ':', 'F', '-', '#'};
static unsigned int  lx200_focus_in_med[]   = {8, ':', 'F', 'M', '#', ':', 'F', '+', '#'};
static unsigned int  lx200_focus_out_med[]  = {8, ':', 'F', 'M', '#', ':', 'F', '-', '#'};
static unsigned int  lx200_focus_in_fast[]  = {8, ':', 'F', 'F', '#', ':', 'F', '+', '#'};
static unsigned int  lx200_focus_out_fast[] = {8, ':', 'F', 'F', '#', ':', 'F', '-', '#'};
static unsigned int *lx200_dir[]            = {lx200_move_stop,
                                               lx200_move_left, lx200_move_right, lx200_move_up, lx200_move_down,
                                               lx200_slew_stop,
                                               lx200_slew_left, lx200_slew_right, lx200_slew_up, lx200_slew_down,
                                               lx200_focus_stop,
                                               lx200_focus_in_slow, lx200_focus_out_slow,
                                               lx200_focus_in_med,  lx200_focus_out_med,
                                               lx200_focus_in_fast, lx200_focus_out_fast};
/*
 * Scope command strings.
 */
static unsigned int  *scope_baud_rate[] = {&star2000_baud_rate, &lx200_baud_rate, 0};
static unsigned int  *scope_init[]      = {star2000_init,        lx200_init,      0};
static unsigned int  *scope_open[]      = {star2000_open,        lx200_open,      0};
static unsigned int  *scope_close[]     = {star2000_close,       lx200_close,     0};
static unsigned int **scope_dir[]       = {star2000_dir,         lx200_dir,       0};
/*
 * Write command string to scope with delays.
 */
static void scope_write(int fd, unsigned int *cmd)
{
    int           i;
    unsigned char c;

    for (i = 1; i <= cmd[0]; i++)
    {
        if (cmd[i] >= 0x100)
        {
            tcdrain(fd);
            usleep((cmd[i] - 0x100) * 1000);
        }
        else
        {
            c = cmd[i];
            write(fd, &c, 1);
        }
    }
}
/*
 * Connect to scope.
 */
int scope_connect(SCOPE_DEV *scope)
{
    static int prev_iface = -1;
    struct termios raw_term;
    int i;

    if (scope->iface > SCOPE_MANUAL)
    {
        if ((scope->fd = open(scope->filename, O_RDWR, 0)) < 0)
        {
            fprintf(stderr, "Error opening telescope communications port %s.\n", scope->filename);
            return (-1);
        }
        if (tcgetattr(scope->fd, &(scope->save_term)) < 0)
        {
            perror("Error getting scope port attributes");
            return (-1);
        }
        raw_term = scope->save_term;
        raw_term.c_lflag &= ~(ECHO | ICANON  | IEXTEN | ISIG);
        raw_term.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
        raw_term.c_cflag &= ~(CSIZE | PARENB);
        raw_term.c_cflag |=  CS8;
        raw_term.c_oflag &= ~OPOST;
        raw_term.c_cc[VMIN]  = 0;
        raw_term.c_cc[VTIME] = 0;
        cfsetispeed(&raw_term, *scope_baud_rate[scope->iface]);
        cfsetospeed(&raw_term, *scope_baud_rate[scope->iface]);
        if (tcsetattr(scope->fd, TCSAFLUSH, &raw_term) < 0)
        {
            perror("Error setting scope port attributes");
            return (-1);
        }
        if (prev_iface != scope->iface)
        {
            for (i = 1; i <= scope_init[scope->iface][0]; i++)
            {
                if (scope_init[scope->iface][i] >= 0x100)
                    scope_init[scope->iface][i] = scope->init_delay + 0x100;
            }
            scope_write(scope->fd, scope_init[scope->iface]);
            prev_iface = scope->iface;
        }
        for (i = 1; i <= scope_open[scope->iface][0]; i++)
        {
            if (scope_open[scope->iface][i] >= 0x100)
                scope_open[scope->iface][i] = scope->init_delay + 0x100;
        }
        scope_write(scope->fd, scope_open[scope->iface]);
    }
    else
        scope->fd = 0;
    return (0);
}
/*
 * Close scope connection.
 */
int scope_release(SCOPE_DEV *scope)
{
    int fd;

    if ((fd = scope->fd))
    {
        scope_write(fd, scope_close[scope->iface]);
        if (tcsetattr(fd, TCSAFLUSH, &(scope->save_term)) < 0)
        {
            perror("Error restoring scope port attributes");
            return (-1);
        }
        scope->fd = 0;
        return (close(fd));
    }
    return (0);
}
/*
 * Move scope.
 */
void scope_move(SCOPE_DEV *scope, unsigned int dir)
{
    if (scope->flags & SCOPE_SWAP_XY)
    {
        switch (dir)
        {
            case SCOPE_UP:
                dir = SCOPE_RIGHT;
                break;
            case SCOPE_DOWN:
                dir = SCOPE_LEFT;
                break;
            case SCOPE_LEFT:
                dir = SCOPE_UP;
                break;
            case SCOPE_RIGHT:
                dir = SCOPE_DOWN;
                break;
        }
    }
    switch (dir)
    {
        case SCOPE_UP:
            if (scope->flags & SCOPE_REV_DEC)
                dir = SCOPE_DOWN;
            break;
        case SCOPE_DOWN:
            if (scope->flags & SCOPE_REV_DEC)
                dir = SCOPE_UP;
            break;
        case SCOPE_LEFT:
            if (scope->flags & SCOPE_REV_RA)
                dir = SCOPE_RIGHT;
            break;
        case SCOPE_RIGHT:
            if (scope->flags & SCOPE_REV_RA)
                dir = SCOPE_LEFT;
            break;
        case SCOPE_FOCUS_IN:
        case SCOPE_FOCUS_OUT:
            if (scope->flags & SCOPE_FOCUS_FAST)
                dir += 4;
            else if (scope->flags & SCOPE_FOCUS_MED)
                dir += 2;
        case SCOPE_FOCUS_STOP:
            break;
        case SCOPE_STOP:
        default:
            dir   = SCOPE_STOP;
    }
    if (dir <= SCOPE_DOWN && scope->flags & SCOPE_SLEW)
        dir += SCOPE_DOWN + 1;
    if (scope->iface > SCOPE_MANUAL)
    {
        scope_write(scope->fd, scope_dir[scope->iface][dir]);
        tcdrain(scope->fd);
    }
}
/***************************************************************************\
*                                                                           *
*                   Low level filter wheel control                          *
*                                                                           *
\***************************************************************************/
int wheel_read(WHEEL_DEV *wheel)
{
    unsigned char cmd[4];

    read(wheel->fd, cmd, 4);
    switch (cmd[1])
    {
        case 129:
            wheel->current = cmd[2];
            wheel->status  = WHEEL_IDLE;
            break;
        case 130:
            wheel->current = cmd[2] - 48;
            wheel->status  = WHEEL_IDLE;
            break;
        case 131:
            wheel->num_filters = cmd[2] - 48;
            wheel->current     = 1;
            wheel->status      = WHEEL_IDLE;
            break;
    }
    return (wheel->status == WHEEL_IDLE);
}
/*
 * Connect to scope.
 */
int wheel_connect(WHEEL_DEV *wheel)
{
    struct termios raw_term;

    if ((wheel->fd = open(wheel->filename, O_RDWR, 0)) < 0)
    {
        fprintf(stderr, "Error opening filter wheel communications port %s.\n", wheel->filename);
        return (-1);
    }
    if (tcgetattr(wheel->fd, &(wheel->save_term)) < 0)
    {
        perror("Error getting filter wheel port attributes");
        return (-1);
    }
    raw_term = wheel->save_term;
    raw_term.c_lflag &= ~(ECHO | ICANON  | IEXTEN | ISIG);
    raw_term.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw_term.c_cflag &= ~(CSIZE | PARENB);
    raw_term.c_cflag |=  CS8;
    raw_term.c_oflag &= ~OPOST;
    raw_term.c_cc[VMIN]  = 0;
    raw_term.c_cc[VTIME] = 0;
    cfsetispeed(&raw_term, B9600);
    cfsetospeed(&raw_term, B9600);
    if (tcsetattr(wheel->fd, TCSAFLUSH, &raw_term) < 0)
    {
        perror("Error setting filter wheel port attributes");
        return (-1);
    }
    return (wheel_reset(wheel));
}
/*
 * Close filter wheel connection.
 */
int wheel_release(WHEEL_DEV *wheel)
{
    int fd;

    if ((fd = wheel->fd))
    {
        wheel->fd = 0;
        if (tcsetattr(fd, TCSAFLUSH, &(wheel->save_term)) < 0)
        {
            perror("Error restoring filter wheel port attributes");
            return (-1);
        }
        return (close(fd));
    }
    return (0);
}
int wheel_reset(WHEEL_DEV *wheel)
{
    unsigned char cmd[4];

    if (wheel->status != WHEEL_IDLE)
        return (-1);
    cmd[0] = 165;
    cmd[1] = 3;
    cmd[2] = 32;
    cmd[3] = 200;
    write(wheel->fd, cmd, 4);
    wheel->status = WHEEL_BUSY;
    return (0);
}
int wheel_query(WHEEL_DEV *wheel)
{
    unsigned char cmd[4];

    if (wheel->status != WHEEL_IDLE)
        return (-1);
    cmd[0] = 165;
    cmd[1] = 2;
    cmd[2] = 32;
    cmd[3] = 199;
    write(wheel->fd, cmd, 4);
    wheel->status = WHEEL_BUSY;
    return (0);
}
int wheel_goto(WHEEL_DEV *wheel, int pos)
{
    unsigned char cmd[4];

    if (wheel->status != WHEEL_IDLE)
        return (-1);
    if (pos >= 1 && pos <= wheel->num_filters)
    {
        cmd[0] = 165;
        cmd[1] = 1;
        cmd[2] = pos;
        cmd[3] = 166 + pos;
        write(wheel->fd, cmd, 4);
        wheel->status = WHEEL_BUSY;
    }
    return (0);
}
