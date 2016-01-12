//========================================================================
// File name  : ksbiglptd.h
// Description: The devices of the driver.
// Author     : Jan Soldan
//========================================================================
#ifndef _KSBIGLPTD_H_
#define _KSBIGLPTD_H_
//========================================================================
int KDev0Open(
    struct inode	*inode,
    struct file		*filp
);

int KDev0Release(
    struct inode	*inode,
    struct file		*filp
);

int KDev0Ioctl(
    struct inode	*inode,
    struct file		*filp,
    unsigned int	cmd,
    unsigned long	arg
);
//========================================================================
int KDev1Open(
    struct inode	*inode,
    struct file		*filp
);

int KDev1Release(
    struct inode	*inode,
    struct file		*filp
);

int KDev1Ioctl(
    struct inode	*inode,
    struct file		*filp,
    unsigned int	cmd,
    unsigned long	arg
);
//========================================================================
int KDev2Open(
    struct inode	*inode,
    struct file		*filp
);

int KDev2Release(
    struct inode	*inode,
    struct file		*filp
);

int KDev2Ioctl(
    struct inode	*inode,
    struct file		*filp,
    unsigned int	cmd,
    unsigned long	arg
);
//========================================================================
#endif // _KSBIGLPTD_H_


