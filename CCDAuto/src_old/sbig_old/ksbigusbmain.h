//=============================================================================
// File name  : ksbigusbmain.h                                                   
// Description: The main header file of the USB kernel driver.			     
// Author     : Jan Soldan    - Linux USB driver developer                   
// Author     : Matt Longmire - SBIG, Windows USB driver developer	     
// Copyright (C) 2002 Jan Soldan, Matt Longmire, SBIG			     
// All rights reserved.							     
//=============================================================================
#ifndef _KSBIGUSBMAIN_H_
#define _KSBIGUSBMAIN_H_
//=============================================================================
#include <linux/config.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/signal.h>
#include <linux/errno.h>
#include <linux/poll.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/fcntl.h>
#include <linux/module.h>
#include <linux/spinlock.h>
#include <linux/list.h>
#include <linux/smp_lock.h>
#include <linux/devfs_fs_kernel.h>
#include <linux/usb.h>
#include "sbigdef.h"
#include "ksbigictl.h"
//=============================================================================
//#define _USB_CHATTY_

#define SBIG_USB_DEVICE_NAME		"sbigusb"
#define DRV_VERSION                     "V1.06"
#define DRV_AUTHOR                      "Jan Soldan, jsoldan@asu.cas.cz"
#define DRV_DESCRIPTION                 "SBIG USB Linux Kernel Driver"

// SBIG USB CCD Camera 
#define SBIG_USB_VENDOR_ID		0x0D97
#define SBIG_USB_UNBOOTED_PRODUCT_ID	0x0001
#define SBIG_USB_BOOTED_PRODUCT_ID	0x0101

#define SBIG_USB_MINOR_BASE		192
#define SBIG_USB_MAX_DEVICES		8
//=============================================================================
struct device_private_data{
// unsigned long          flags;
// unsigned long          value;
// unsigned char          control_out;
// unsigned char          imaging_clocks_out;
// unsigned char          noBytesRd;
// unsigned char          noBytesWr;
// unsigned short         state;

 struct usb_device     *device;		  
 struct usb_interface  *interface;	  
 devfs_handle_t		devfs;	  
 unsigned char		subminor;	  
 int			open_count;	 
 struct semaphore	semaphore; 	 

 struct urb            *in_urb;		  
 unsigned char         *in_buffer;	   
 int			in_size;	  
 __u8			in_endpointAddr;  
					 
 struct urb            *out_urb;	   
 unsigned char         *out_buffer;	   
 int			out_size;	   
 __u8			out_endpointAddr;  
};
//=============================================================================
int   KSbigUsbModuleInit(void);
void  KSbigUsbModuleExit(void);

void *KSbigUsbProbeDevice(
      struct usb_device          *usbDevice,
      unsigned int                interfaceNumber,
      const struct usb_device_id *usbDeviceIdTable);

void  KSbigUsbDisconnectDevice(
      struct usb_device          *usbDevice,
      void                       *drvContext);

void  KSbigUsbDeviceDelete(struct device_private_data *dpd);
 
void  KSbigUsbGetDeviceInfo(
      struct usb_device          *usbDevice,
      unsigned int                interfaceNumber,
      const struct usb_device_id *usbDeviceIdTable);

int   KSbigUsbOpen(
      struct inode               *inode,
      struct file                *filp);

int   KSbigUsbRelease(
      struct inode               *inode,
      struct file                *filp);

int   KSbigUsbIoctl(
      struct inode	         *inode,
      struct file		 *filp,
      unsigned int	          cmd,
      unsigned long	          arg);

void  KSbigUsbOutBulkCallback(
      struct urb                 *urb);

void  KSbigUsbInBulkCallback(
      struct urb                 *urb);

int   KSbigUsbTestCommand(void);

int   KSbigUsbGetDriverInfo(
      GetDriverInfoResults0      *results);

int   KSbigUsbSendMicroBlock(     
      struct device_private_data *dpd,
      LinuxMicroblock            *arg);

int   KSbigUsbGetMicroBlock(
      struct device_private_data *dpd, 
      LinuxMicroblock            *arg);

int   KSbigUsbSubmitInUrb(
      struct device_private_data *dpd, 
      LinuxMicroblock            *arg);

int   KSbigUsbGetInUrb(
      struct device_private_data *dpd, 
      LinuxMicroblock            *arg);

int   KSbigUsbGetJiffies(
      unsigned long              *arg);

//=============================================================================
#endif // _KSBIGUSBMAIN_H_




