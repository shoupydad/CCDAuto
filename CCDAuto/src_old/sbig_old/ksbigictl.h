//========================================================================
// File name  : ksbigictl.h
// Description: The ictl header file.
// Author     : Jan Soldan
//========================================================================
#ifndef _KSBIGICTL_H_
#define _KSBIGICTL_H_
//========================================================================
// Definition of IOCTL:
//
// type - The magic number. Just choose one number ioctl-number.txt
// and use it throughout the driver. This field is eight bits wide.
//
// nr - The ordinal (sequential) number. It's eight bits wide.
//
// direction - The direction of data transfer, if the particular
// command involves a data transfer.
//
// size - The size of user data involved. The width of this field is
// architecture dependent and currently ranges from 8-14 bits, see
// _IOC_SIZEBITS macro. It is not mandatory that we use this field.
// If we need larger data structures, we can just ignore it.
//------------------------------------------------------------------------
// _IO(type, nr)
// #define IOCTL_1		_IO(DEV_IOCTL_BASE, 1)
//
// Define the selected command. No data is transfered to or from the
// application issuing the ioctl. An _IO ioctl can still return and
// integer as long as it is positive and thus not interpreted as an
// error.
//------------------------------------------------------------------------
// _IOR(type, nr, dataitem)
// #define IOCTL_2		_IOR(DEV_IOCTL_BASE, 2, unsigned long)
//
// A is reading ioctl, as seen from the application, size is the size
// of the argument to be transferred back.
//------------------------------------------------------------------------
// _IOW(type, nr, dataitem)
// #define IOCTL_3		_IOW(DEV_IOCTL_BASE, 3, unsigned long)
//
// A writing ioctl, as seen from the application, size is the size
// of the argument to be transferred from user space.
//------------------------------------------------------------------------
// _IOWR(type, nr, dataitem).
// #define IOCTL_4		_IOWR(DEV_IOCTL_BASE, 4, unsigned long)
//
// A reading and writing ioctl. The size indicates the size of the
// argument to be transferred back and forth.
//------------------------------------------------------------------------
// _IOC_DIR (command) - The direction - _IOC_NONE, IOC_WRITE, IOC_READ
// _IOC_TYPE(command) - The ioctl base number of the field.
// _IOC_NR  (command) - The command part of the field.
// _IOC_SIZE(command) - The size of the argument, if any.
// -----------------------------------------------------------------------
#define IOCTL_BASE   0xbb

#define IOCTL_GET_JIFFIES      _IOWR (IOCTL_BASE, 1,  char *)
#define IOCTL_GET_DRIVER_INFO  _IOWR (IOCTL_BASE, 2,  char *)
#define IOCTL_SET_VDD          _IOWR (IOCTL_BASE, 3,  char *)

#define IOCTL_SEND_MICRO_BLOCK _IOWR (IOCTL_BASE, 10, char *)
#define IOCTL_GET_MICRO_BLOCK  _IOWR (IOCTL_BASE, 11, char *)
#define IOCTL_SUBMIT_IN_URB    _IOWR (IOCTL_BASE, 12, char *)
#define IOCTL_GET_IN_URB       _IOWR (IOCTL_BASE, 13, char *)


#define IOCTL_INIT_PORT        _IO   (IOCTL_BASE, 20)
#define IOCTL_CAMERA_OUT       _IOWR (IOCTL_BASE, 21, char *)
#define IOCTL_CLEAR_IMAG_CCD   _IOWR (IOCTL_BASE, 22, char *)
#define IOCTL_CLEAR_TRAC_CCD   _IOWR (IOCTL_BASE, 23, char *)
#define IOCTL_GET_PIXELS       _IOWR (IOCTL_BASE, 24, char *)
#define IOCTL_GET_AREA         _IOWR (IOCTL_BASE, 25, char *)
#define IOCTL_DUMP_ILINES      _IOWR (IOCTL_BASE, 26, char *)
#define IOCTL_DUMP_TLINES      _IOWR (IOCTL_BASE, 27, char *)
#define IOCTL_DUMP_5LINES      _IOWR (IOCTL_BASE, 28, char *)
#define IOCTL_CLOCK_AD         _IOWR (IOCTL_BASE, 29, char *)
#define IOCTL_REALLOCATE_PORTS _IOWR (IOCTL_BASE, 30, char *)
#define IOCTL_SET_BUFFER_SIZE  _IOW  (IOCTL_BASE, 31, unsigned short)
#define IOCTL_GET_BUFFER_SIZE  _IO   (IOCTL_BASE, 32)
#define IOCTL_TEST_COMMAND     _IO   (IOCTL_BASE, 33)
//========================================================================
#endif // _KSBIGICTL_H_
