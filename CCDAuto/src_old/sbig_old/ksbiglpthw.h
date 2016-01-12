//========================================================================
// File name  : ksbiglpthw.h
// Description: The header of the hardware file of the driver.
// Author     : Jan Soldan
//========================================================================
#ifndef _KSBIGLPTHW_H_
#define _KSBIGLPTHW_H_

#include "sbigdef.h"
//========================================================================
// function prototypes
int   KAllocateLptPorts    (struct file *filp);

int   KReleaseLptPorts     (struct file *filp);

int   KReallocateLptPorts  (struct file *filp, LptPortParams *);

int   KAllocatePrivateData (struct file *filp,
                            int          port_base, 
			    int          port_span, 
			    int          buffer_size);

int   KReleasePrivateData  (struct file *filp);

void  KDumpPrivateData     (struct file *filp);
//========================================================================
#endif // _KSBIGLPTHW_H_












