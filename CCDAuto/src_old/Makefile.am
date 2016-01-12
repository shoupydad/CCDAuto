## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@


bin_PROGRAMS = ccdauto

ccdauto_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	doRoutines.c doroutines.h \
	sbig.cpp csbigcam.cpp \
	apogee.cpp CameraIO_Linux.cpp CameraIO_LinuxPPI.cpp \
	apogee.h ApogeeLinux.h CameraIO_Linux.h CameraIO_PCI.h \
	ccd.h Apogee.h \
	sxpress.c sxpress.h

ccdauto_LDADD = @PACKAGE_LIBS@ $(INTLLIBS) -L/opt/cern/pro/lib -L/.

#ccdauto_LDADD = $(GNOME_LIBDIR) $(GNOMEUI_LIBS) -L/scratch/software/cern/pro/lib

ccdauto_LDFLAGS = -Xlinker -rpath -Xlinker /usr/lib 

CFLAGS = -g2 -Df2cFortran

LIBS = -lsbigudrv -lcfitsio -Imlib -lcpgplot -lpgplot -lpacklib

CXXLD = g77 -g2
