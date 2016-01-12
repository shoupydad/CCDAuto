'-------------------------------------------------------------------------------
'
'   MX PROCESS.BAS  For PB/DLL
'   Copyright (c) 2004 TERRY PLATT
'
'-------------------------------------------------------------------------------

$COMPILE DLL "MXPROC.DLL"
$INCLUDE "win32api.inc"
GLOBAL zcomms$, comms$, hcomm&, nrofbytes&, nrofbytesout&, ztext AS ASCIIZ*255, k AS STRING*1
GLOBAL hsize&, vsize&, Framesize&, imsize&, linelength%, linecount%, pxcount%, pxcount2%

SUB define
 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount% = hsize&*2
 pxcount2% = hsize&*2+2
END SUB

'*************************************************************************************
SUB stretcher ( BYVAL stretchtype%, BYVAL Powr!, BYVAL Blacklev&, BYVAL Whitelev&, BYVAL Imptr1&, BYVAL Imptr2&, BYVAL hsize&, BYVAL vsize&, BYVAL HR%) EXPORT
 DIM Table%(-32768 TO 32767)
 DIM Databyte%
 DIM Datapoint AS INTEGER PTR
 DIM Impoint AS INTEGER PTR

 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount%=hsize&*2
 pxcount2%=hsize*2+2

 Datapoint=VARPTR(Databyte%)
 Impoint=Imptr1&

 Im1&=Imptr1&
 Im2&=Imptr2&

 'POKE$ Imptr2&, PEEK$ (Imptr1&,12225024)                              'copy image to buffer

 IF stretchtype%=1 THEN GOSUB Linear: GOTO stretchdone
 IF stretchtype%=2 THEN GOSUB Power: GOTO stretchdone
 IF stretchtype%=3 THEN GOSUB Negative: GOTO stretchdone
 IF stretchtype%=4 THEN GOSUB Sine: GOTO stretchdone

 Linear:
 Range!= 65535/(Whitelev& - Blacklev&)                              'Generate lookup table
 FOR x&=0 TO Blacklev&
 IF x&>32767 THEN y&=x&-65536 ELSE y&=x&: Table%(y&)=0: NEXT x&
 FOR x&= Blacklev& TO Whitelev&
 IF x&>32767 THEN y&=x&-65536 ELSE y&=x&
 a&=(x&-Blacklev&)*Range!
 IF a& >32767 THEN Table%(y&)= (a&-65536) ELSE Table%(y&)=a&
 NEXT x&
 FOR x&= Whitelev& TO 65535
 IF x&>32767 THEN y&=x&-65536 ELSE y&=x&
 Table%(y&)= -1: NEXT x&

 imagend& = Framesize&
 FOR x&=1 TO imagend&                                               'Modify image
 @Datapoint=@Impoint
 Databyte%= Table%(Databyte%)
 @Impoint=@Datapoint
 INCR Impoint
 NEXT x&
 RETURN

 Power:
 Ratio!=1/(65535^(Powr!-1))
 FOR x&=0 TO 65535: a&=INT((x&^Powr!)*Ratio!)
 IF a&>65535 THEN a&=65535
 IF x&>32767 THEN y&=x&-65536 ELSE y&=x&
 IF a&>32767 THEN Table%(y&)= a&-65536 ELSE Table%(y&)=a&
 NEXT x&

 imagend&=Framesize&
 FOR x&=1 TO imagend&                                               'Modify image
 @Datapoint=@Impoint
 Databyte%= Table%(Databyte%)
 @Impoint=@Datapoint
 INCR Impoint
 NEXT x&
 RETURN

 Sine:
 FOR x&=0 TO 65535
     a&=((SIN((x&-32678)/32678)*1.57)+1)*65535
     IF a&>65535 THEN a&=65535
     IF a&<0 THEN a&=0
     IF x&>32767 THEN y&=x&-65536 ELSE y&=x&
     IF a&>32767 THEN Table%(y&)=a&-65536 ELSE Table%(y&)=a&
 NEXT x&

 imagend& = Framesize&
 FOR x&=1 TO imagend&                                               'Modify image
 @Datapoint=@Impoint
 Databyte%= Table%(Databyte%)
 @Impoint=@Datapoint
 INCR Impoint
 NEXT x&
 RETURN

 Negative:
 FOR x&=0 TO 65535: a&= 66535 - x&
 IF x&>32767 THEN y&=x&-65536 ELSE y&=x&
 IF a&>32767 THEN Table%(y&)=a&-65536 ELSE Table%(y&)=a&
 NEXT x&

 imagend& = Framesize&
 FOR x&=1 TO imagend&                                               'Modify image
 @Datapoint=@Impoint
 Databyte%= Table%(Databyte%)
 @Impoint=@Datapoint
 INCR Impoint
 NEXT x&
 RETURN

 stretchdone:
 END SUB

SUB unsharpmask (BYVAL Radius%, BYVAL Pwr%, BYVAL Imptr1&, BYVAL Imptr2&, BYVAL hsize&, BYVAL vsize&, BYVAL HR%) EXPORT
 DIM Pointer1 AS INTEGER PTR
 DIM Pointer2 AS INTEGER PTR
 DIM Startpointer AS INTEGER PTR
 DIM Winpointer AS INTEGER PTR
 DIM Winstartpointer AS INTEGER PTR
 DIM Outstartpointer AS INTEGER PTR

 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount%=hsize&*2
 pxcount2%=hsize*2+2

 'msgbox "imsize&="+str$(imsize&)+", Imptr1&="+str$(Imptr1&)+", Imptr2&="+Str$(Imptr2&)

 POKE$ Imptr2&, PEEK$ (Imptr1&,imsize&)                         'copy image to buffer

 Startrow% = Radius%                                            'first pixel in line
 Endrow% = linelength% - Radius%                                'last pixel in line
 Startline% = Radius%                                           'first line
 Endline% = linecount% - Radius%                                'last line
 Kerncount% = 2*Radius% + 1                                     'window width / height
 Kernarea% = Kerncount% ^2                                      'number of pixels in window

 Winstartpointer = Imptr2&                                      'top left corner of window
 Pointer1 = Imptr1& + Radius%*pxcount% + Radius%*2              'location of first pixel for processing
 Pointer2 = Imptr2& + Radius%*pxcount% + Radius%*2              'first pixel in input array
 Startpointer = Pointer2                                        'central pixel of input window
 Outstartpointer = Pointer1                                     'central pixel of output window

 FOR z% = Startline% TO Endline%
 FOR w% = Startrow% TO Endrow%

 Kernel:
 Kernsum& = 0
 Centre% = @Pointer2
 IF Centre%<0 THEN Cen& = Centre% + 65536 ELSE Cen& = Centre%    'central pixel value
 Winpointer = Winstartpointer                                    'start at top left corner of window
 FOR y% = 1 TO Kerncount%                                        'sum columns of pixels
 FOR x% = 1 TO Kerncount%                                        'sum rows of pixels
 PV% = @Winpointer                                             'get pixel value
 IF PV%<0 THEN P1& = PV% + 65536 ELSE P1& = PV%          'normalise to unsigned
 Kernsum& = Kernsum& + P1&                                      'add to total
 INCR Winpointer                                                 'next pixel in row
 NEXT x%
 Winpointer = Winstartpointer + y%*pxcount%                  'next row of window
 NEXT y%
 Kernsum& = Kernsum& \ Kernarea%

 Offset& = Cen& - Kernsum&
 Offset& = Offset& * Pwr%
 Newpix& = Cen& + Offset&
 IF Newpix&>65535 THEN Newpix& = 65535
 IF Newpix&<0 THEN Newpix& = 0
 IF Newpix&>32767 THEN Newpx% = Newpix& - 65536 ELSE Newpx% = Newpix&   'revert to signed
 @Pointer1 = Newpx%
 INCR Pointer1                                                  'next pixel in output image
 INCR Pointer2                                                  'next pixel in source image
 INCR Winstartpointer
 NEXT w%

 Outstartpointer = Outstartpointer + pxcount%
 Startpointer = Startpointer + pxcount%
 Winstartpointer = Startpointer - Radius%*pxcount2%
 Pointer1 = Outstartpointer                                     'central pixel address in output image
 Pointer2 = Startpointer                                        'central pixel address in input image
 NEXT z%

END SUB

SUB median (BYVAL Radius%, BYVAL Pwr%, BYVAL Imptr1&, BYVAL Imptr2&, BYVAL hsize&, BYVAL vsize&, BYVAL HR%) EXPORT
 DIM Pointer1 AS INTEGER PTR
 DIM Pointer2 AS INTEGER PTR
 DIM Startpointer AS INTEGER PTR
 DIM Winpointer AS INTEGER PTR
 DIM Winstartpointer AS INTEGER PTR
 DIM Outstartpointer AS INTEGER PTR
 DIM Med&(100)

 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount%=hsize&*2
 pxcount2%=hsize*2+2

  POKE$ Imptr2&, PEEK$ (Imptr1&,imsize&)                         'copy image to buffer

 Startrow% = Radius%                                            'first pixel in line
 Endrow% = linelength% - Radius%                                'last pixel in line
 Startline% = Radius%                                        'first line
 Endline% = linecount% - Radius%                                'last line
 Kerncount% = 2*Radius% + 1                                     'window width / height
 Kernarea% = Kerncount% ^2                                      'number of pixels in window

 Winstartpointer = Imptr2&                                      'top left corner of window
 Pointer1 = Imptr1& + Radius%*pxcount% + Radius%*2              'location of first pixel for processing
 Pointer2 = Imptr2& + Radius%*pxcount% + Radius%*2              'first pixel in input array
 Startpointer = Pointer2                                        'central pixel of input window
 Outstartpointer = Pointer1                                     'central pixel of output window

 FOR z% = Startline% TO Endline%
 FOR w% = Startrow% TO Endrow%

 Kernel:
 n% = 0
 Centre% = @Pointer2
 IF Centre%<0 THEN Cen& = Centre% + 65536 ELSE Cen& = Centre%    'central pixel value
 Winpointer = Winstartpointer                                    'start at top left corner of window
 FOR y% = 1 TO Kerncount%                                        'sum columns of pixels
 FOR x% = 1 TO Kerncount%                                        'sum rows of pixels
 PV% = @Winpointer                                               'get pixel value
 IF PV%<0 THEN P1& = PV% + 65536 ELSE P1& = PV%                  'normalise to unsigned
 Med&(n%)= P1&                                                   'add to total
 INCR Winpointer                                                 'next pixel in row
 INCR n%
 NEXT x%
 Winpointer = Winstartpointer + y%*pxcount%                  'next row of window
 NEXT y%

 ARRAY SORT Med&(0) FOR n%

 midval& = Med&(n%\2 -1)

 Newpix& = midval&
 IF Newpix&>65535 THEN Newpix& = 65535
 IF Newpix&<0 THEN Newpix& = 0
 IF Newpix&>32767 THEN Newpx% = Newpix& - 65536 ELSE Newpx% = Newpix&   'revert to signed
 @Pointer1 = Newpx%
 INCR Pointer1                                                  'next pixel in output image
 INCR Pointer2                                                  'next pixel in source image
 INCR Winstartpointer
 NEXT w%

 Outstartpointer = Outstartpointer + pxcount%
 Startpointer = Startpointer + pxcount%
 Winstartpointer = Startpointer - Radius%*pxcount2%
 Pointer1 = Outstartpointer                                     'central pixel address in output image
 Pointer2 = Startpointer                                        'central pixel address in input image
 NEXT z%

END SUB

SUB Highlow (BYVAL Imptr1&, BYVAL Imptr2&, BYVAL hsize&, BYVAL vsize&, BYVAL HR%) EXPORT

 DIM Pointer1 AS INTEGER PTR
 DIM Pointer2 AS INTEGER PTR
 DIM Startpointer AS INTEGER PTR
 DIM Winpointer AS INTEGER PTR
 DIM Winstartpointer AS INTEGER PTR
 DIM Outstartpointer AS INTEGER PTR

 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount%=hsize&*2
 pxcount2%=hsize*2+2


 DIM Table%(3,3)
 q%=1
 FOR n% = 1 TO 3
 FOR m% = 1 TO 3
 Table%(m%,n%) = VAL(READ$(q%))                                 'read coefficient
 INCR q%
 NEXT m%
 NEXT n%

 POKE$ Imptr2&, PEEK$ (Imptr1&,imsize&)                          'copy image to buffer

 Radius% = 1
 Startrow% = Radius%                                            'first pixel in line
 Endrow% = linelength% - Radius%                                'last pixel in line
 Startline% = Radius%                                        'first line
 Endline% = linecount% - Radius%                                'last line
 Kerncount% = 3                                                 'window width / height
 Kernarea% = 6                                                  'sum of coefficients in window

 Winstartpointer = Imptr2&                                      'top left corner of window
 Pointer1 = Imptr1& + (Radius%)*pxcount% + Radius%*2            'location of first pixel in output image
 Pointer2 = Imptr2& + (Radius%)*pxcount% + Radius%*2            'location of first pixel for processing
 Startpointer = Pointer2                                        'central pixel of input window
 Outstartpointer = Pointer1                           'central pixel of output window

 FOR z% = Startline% TO Endline%
 FOR w% = Startrow% TO Endrow%
 GOSUB Kernel2
 Newpix& = Kernsum&
 IF Newpix&>65535 THEN Newpix& = 65535
 IF Newpix&<0 THEN Newpix& = 0
 IF Newpix&>32767 THEN Newpx% = Newpix& - 65536 ELSE Newpx% = Newpix&                'revert to signed

 @Pointer1 = Newpx%
 INCR Pointer1                                                  'next pixel in output image
 INCR Pointer2                                                  'next pixel in source image
 INCR Winstartpointer
 NEXT w%
 Outstartpointer = Outstartpointer + pxcount%
 Startpointer = Startpointer + pxcount%
 Winstartpointer = Startpointer - Radius%*pxcount2%
 Pointer1 = Outstartpointer                                     'central pixel address in output image
 Pointer2 = Startpointer                                        'central pixel address in input image
 NEXT z%
 GOTO Endfilter2

 Kernel2:
 Kernsum& = 0
 Winpointer = Winstartpointer                                   'start at top left corner of window

 FOR y% = 1 TO 3                                                'sum columns of pixels
 FOR x% = 1 TO 3                                                'sum rows of pixels
 p% = Table%(x%,y%)
 PV% = @Winpointer                                            'get pixel value
 IF PV%<0 THEN Pix& = PV% + 65536 ELSE Pix& = PV%         'normalise to unsigned
 Pix& = Pix& * p%                                               'multiply by coefficient
 Kernsum& = Kernsum& + Pix&                                     'add to total
 INCR Winpointer                                                'next pixel in row
 NEXT x%
 Winpointer = Winstartpointer + y%*pxcount%                 'next row of window
 NEXT y%
 Kernsum& = Kernsum&\Kernarea%
 RETURN

 DATA 0,-1,0,-1,10,-1,0,-1,0
 Endfilter2:
END SUB

SUB Highhigh (BYVAL Imptr1&, BYVAL Imptr2&, BYVAL hsize&, BYVAL vsize&, BYVAL HR%) EXPORT

 DIM Pointer1 AS INTEGER PTR
 DIM Pointer2 AS INTEGER PTR
 DIM Startpointer AS INTEGER PTR
 DIM Winpointer AS INTEGER PTR
 DIM Winstartpointer AS INTEGER PTR
 DIM Outstartpointer AS INTEGER PTR

 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount%=hsize&*2
 pxcount2%=hsize*2+2

 DIM Table%(3,3)
 q%=1
 FOR n% = 1 TO 3
 FOR m% = 1 TO 3
 Table%(m%,n%) = VAL(READ$(q%))                                          'read coefficient
 INCR q%
 NEXT m%
 NEXT n%

 POKE$ Imptr2&, PEEK$ (Imptr1&,imsize&)                                  'copy image to buffer

 Radius% = 1
 Startrow% = Radius%                                                    'first pixel in line
 Endrow% = linelength% - Radius%                                        'last pixel in line
 Startline% = Radius%                                                'first line
 Endline% = linecount% - Radius%                                        'last line
 Kerncount% = 3                                                         'window width / height
 Kernarea% = 8                                                          'sum of coefficients in window

 Winstartpointer = Imptr2&                                              'top left corner of window
 Pointer1 = Imptr1& + Radius%*pxcount% + Radius%*2                      'location of first pixel for processing
 Pointer2 = Imptr2& + Radius%*pxcount% + Radius%*2
 Startpointer = Pointer2                                                'central pixel of input window
 Outstartpointer = Pointer1                                   'central pixel of output window


 FOR z% = Startline% TO Endline%
 FOR w% = Startrow% TO Endrow%
 GOSUB Kernel3
 Newpix& = Kernsum&
 IF Newpix&>65535 THEN Newpix& = 65535
 IF Newpix&<0 THEN Newpix& = 0
 IF Newpix&>32767 THEN Newpx% = Newpix& - 65536 ELSE Newpx% = Newpix&  'revert to signed

 @Pointer1 = Newpx%
 INCR Pointer1                                                  'next pixel in output image
 INCR Pointer2                                                  'next pixel in source image
 INCR Winstartpointer
 NEXT w%
 Outstartpointer = Outstartpointer + pxcount%
 Startpointer = Startpointer + pxcount%
 Winstartpointer = Startpointer - Radius%*pxcount2%
 Pointer1 = Outstartpointer                                     'central pixel address in output image
 Pointer2 = Startpointer                                        'central pixel address in input image
 NEXT z%
 GOTO Endfilter3

 Kernel3:
 Kernsum& = 0
 Winpointer = Winstartpointer                                   'start at top left corner of window

 FOR y% = 1 TO 3                                                'sum columns of pixels
 FOR x% = 1 TO 3                                                'sum rows of pixels
 p% = Table%(x%,y%)
 PV% = @Winpointer                                            'get pixel value
 IF PV%<0 THEN Pix& = PV% + 65536 ELSE Pix& = PV%         'normalise to unsigned
 Pix& = Pix& * p%                                               'multiply by coefficient
 Kernsum& = Kernsum& + Pix&                                     'add to total
 INCR Winpointer                                                'next pixel in row
 NEXT x%
 Winpointer = Winstartpointer + y%*pxcount%                     'next row of window
 NEXT y%
 Kernsum& = Kernsum&\Kernarea%
 RETURN

 DATA -1,-1,-1,-1,16,-1,-1,-1,-1
 Endfilter3:

END SUB

SUB Lowmean (BYVAL Imptr1&, BYVAL Imptr2&, BYVAL hsize&, BYVAL vsize&, BYVAL HR%) EXPORT

 DIM Pointer1 AS INTEGER PTR
 DIM Pointer2 AS INTEGER PTR
 DIM Startpointer AS INTEGER PTR
 DIM Winpointer AS INTEGER PTR
 DIM Winstartpointer AS INTEGER PTR
 DIM Outstartpointer AS INTEGER PTR

 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount%=hsize&*2
 pxcount2%=hsize*2+2

 DIM Table%(3,3)
 q%=1
 FOR n% = 1 TO 3
 FOR m% = 1 TO 3
 Table%(m%,n%) = VAL(READ$(q%))                                          'read coefficient
 INCR q%
 NEXT m%
 NEXT n%

 POKE$ Imptr2&, PEEK$ (Imptr1&,imsize&)                                  'copy image to buffer

 Radius% = 1
 Startrow% = Radius%                                                    'first pixel in line
 Endrow% = linelength% - Radius%                                        'last pixel in line
 Startline% = Radius%                                                'first line
 Endline% = linecount% - Radius%                                        'last line
 Kerncount% = 3                                                         'window width / height
 Kernarea% = 16                                                          'sum of coefficients in window

 Winstartpointer = Imptr2&                                              'top left corner of window
 Pointer1 = Imptr1& + Radius%*pxcount% + Radius%*2                      'location of first pixel for processing
 Pointer2 = Imptr2& + Radius%*pxcount% + Radius%*2
 Startpointer = Pointer2                                                'central pixel of input window
 Outstartpointer = Pointer1                                   'central pixel of output window


 FOR z% = Startline% TO Endline%
 FOR w% = Startrow% TO Endrow%

 Kernel3:
 Kernsum& = 0
 Winpointer = Winstartpointer                                   'start at top left corner of window

 FOR y% = 1 TO 3                                                'sum columns of pixels
 FOR x% = 1 TO 3                                                'sum rows of pixels
 p% = Table%(x%,y%)
 PV% = @Winpointer                                              'get pixel value
 IF PV%<0 THEN Pix& = PV% + 65536 ELSE Pix& = PV%               'normalise to unsigned
 Pix& = Pix& * p%                                               'multiply by coefficient
 Kernsum& = Kernsum& + Pix&                                     'add to total
 INCR Winpointer                                                'next pixel in row
 NEXT x%
 Winpointer = Winstartpointer + y%*pxcount%                 'next row of window
 NEXT y%
 Newpix& =  Kernsum&\Kernarea%
 IF Newpix&>65535 THEN Newpix& = 65535
 IF Newpix&<0 THEN Newpix& = 0
 IF Newpix&>32767 THEN Newpx% = Newpix& - 65536 ELSE Newpx% = Newpix&  'revert to signed

 @Pointer1 = Newpx%
 INCR Pointer1                                                  'next pixel in output image
 INCR Pointer2                                                  'next pixel in source image
 INCR Winstartpointer
 NEXT w%
 Outstartpointer = Outstartpointer + pxcount%
 Startpointer = Startpointer + pxcount%
 Winstartpointer = Startpointer - Radius%*pxcount2%
 Pointer1 = Outstartpointer                                     'central pixel address in output image
 Pointer2 = Startpointer                                        'central pixel address in input image
 NEXT z%

 DATA 1,2,1,2,4,2,1,2,1

END SUB

SUB Basrelief (BYVAL Imptr1&, BYVAL Imptr2&, BYVAL hsize&, BYVAL vsize&, BYVAL HR%) EXPORT

 DIM Pointer1 AS INTEGER PTR
 DIM Pointer2 AS INTEGER PTR
 DIM Startpointer AS INTEGER PTR
 DIM Winpointer AS INTEGER PTR
 DIM Winstartpointer AS INTEGER PTR
 DIM Outstartpointer AS INTEGER PTR

 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount%=hsize&*2
 pxcount2%=hsize*2+2

 DIM Table%(5,5)
 q%=1
 FOR n% = 1 TO 5
 FOR m% = 1 TO 5
 Table%(m%,n%) = VAL(READ$(q%))                                         'read coefficient
 INCR q%
 NEXT m%
 NEXT n%

 POKE$ Imptr2&, PEEK$ (Imptr1&,imsize&)                                  'copy image to buffer

 Radius% = 1
 Startrow% = Radius%                                                    'first pixel in line
 Endrow% = linelength% - Radius%                                        'last pixel in line
 Startline% = Radius%                                                'first line
 Endline% = linecount% - Radius%                                        'last line
 Kerncount% = 5                                                         'window width / height
 Kernarea% = 1                                                          'sum of coefficients in window

 Winstartpointer = Imptr2&                                              'top left corner of window
 Pointer1 = Imptr1& + Radius%*pxcount% + Radius%*2                      'location of first pixel for processing
 Pointer2 = Imptr2& + Radius%*pxcount% + Radius%*2
 Startpointer = Pointer2                                                'central pixel of input window
 Outstartpointer = Pointer1                                    'central pixel of output window


 FOR z% = Startline% TO Endline%
 FOR w% = Startrow% TO Endrow%

 Kernel3:
 Kernsum& = 0
 Winpointer = Winstartpointer                                   'start at top left corner of window

 FOR y% = 1 TO 5                                                'sum columns of pixels
 FOR x% = 1 TO 5                                                'sum rows of pixels
 p% = Table%(x%,y%)
 PV% = @Winpointer                                              'get pixel value
 IF PV%<0 THEN Pix& = PV% + 65536 ELSE Pix& = PV%               'normalise to unsigned
 Pix& = Pix& * p%                                               'multiply by coefficient
 Kernsum& = Kernsum& + Pix&                                     'add to total
 INCR Winpointer                                                'next pixel in row
 NEXT x%
 Winpointer = Winstartpointer + y%*pxcount%                     'next row of window
 NEXT y%
 Newpix& =  Kernsum&\Kernarea%
 IF Newpix&>65535 THEN Newpix& = 65535
 IF Newpix&<0 THEN Newpix& = 0
 IF Newpix&>32767 THEN Newpx% = Newpix& - 65536 ELSE Newpx% = Newpix&  'revert to signed

 @Pointer1 = Newpx%
 INCR Pointer1                                                  'next pixel in output image
 INCR Pointer2                                                  'next pixel in source image
 INCR Winstartpointer
 NEXT w%
 Outstartpointer = Outstartpointer + pxcount%
 Startpointer = Startpointer + pxcount%
 Winstartpointer = Startpointer - Radius%*pxcount2%
 Pointer1 = Outstartpointer                                     'central pixel address in output image
 Pointer2 = Startpointer                                        'central pixel address in input image
 NEXT z%

DATA 0,0,-1,0,0,0,-1,-1,-1,0,-1,-1,1,1,1,0,1,1,1,0,0,0,1,0,0

END SUB

'************************************************

SUB Gradientfind(BYVAL Imptr1&, BYVAL hsize&, BYVAL vsize&, BYVAL Bin%)EXPORT
 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount%=hsize&*2
 pxcount2%=hsize*2+2

DIM Linestore&(hsize&*2)
DIM linptr AS INTEGER PTR

 IF Bin%=1 THEN Imsize& = Framesize&/4
 IF Bin%=1 THEN linelength% = linelength%/2
 IF Bin%=1 THEN linecount% = linecount%/2
 IF Bin%=1 THEN pxcount% = pxcount%/2
 IF Bin%=1 THEN pxcount2% = pxcount2%/2

 lineend%=linelength%-20

linptr=Imptr1&+(linelength%*20)+20                    '10 lines down, 10 pixels in
FOR x%=0 TO lineend%
lum%=@linptr
IF lum%<0 THEN Lumval&=Lum%+65536 ELSE Lumval&=Lum%
Linestore&(x%)=Lumval&                 'store luminance values for line
INCR linptr
NEXT x%

Regress1:
xsum&=0: xtot&=0: ytot&=0: ysum!=0

FOR x%=0 TO lineend%                         'search Linestore for brightness values
    lineval!=Linestore&(x%)
    ysum!=ysum!+lineval!
    xsum&=xsum&+x%
    INCR xtot&
    INCR ytot&
NEXT x%

xav!=xsum&/xtot&                         'sample mean
yav!=ysum!/ytot&                         'brightness mean

sxxsum!=0: sxysum!=0: sxtotal%=0
FOR x%=0 TO lineend%
    xv!=x%
    ls!=Linestore&(x%)
    sxx!=(xv!-xav!)^2
    sxy!=(xv!-xav!)*(ls!-yav!)
    sxxsum!=sxxsum!+sxx!
    sxysum!=sxysum!+sxy!
    INCR sxtotal%
NEXT x%

    sxx!=sxxsum!/sxtotal%
    sxy!=sxysum!/sxtotal%

    m!=sxy!/sxx!                        'best fit gradient
    b!=yav!-(m!*xav!)                   'y axis intercept point

'MSGBOX "Slope = "+STR$(m!)+", Intercept = "+STR$(b!)+", xav! = "+STR$(xav!)+ ", yav! = "+STR$(yav!)+", sxx! = "+STR$(sxx!)+", sxy! = "+STR$(sxy!)

   midline%=linelength%/2
   linptr=Imptr1&
   FOR y%=1 TO linecount%
   FOR x%=1 TO linelength%
   Lum%=@linptr
   IF Lum%<0 THEN Lumval&=Lum%+65536 ELSE Lumval&=Lum%
   deltay&=(x%-midline%)*m!
   Lumval&=Lumval&-deltay&
   IF Lumval&<0 THEN Lumval&=0
   IF Lumval&>65535 THEN Lumval&=65535
   IF Lumval&>32767 THEN Lum%=Lumval&-65536 ELSE Lum%=Lumval&
   @linptr=Lum%
   INCR linptr
   NEXT x%
   NEXT y%

'find vertical gradient

    colend%=linecount%-20
    linptr=Imptr1&+(linelength%)*2-30                   'top line, 15 pixels in from right hand side
    FOR y%=0 TO colend%
    lum%=@linptr
    IF lum%<0 THEN Lumval&=Lum%+65536 ELSE Lumval&=Lum%
    Linestore&(y%,0)=Lumval&              'store luminance values for column
    linptr=linptr+pxcount%
NEXT x%


Regress2:
xsum&=0: xtot&=0: ytot&=0: ysum!=0

FOR x%=0 TO colend%                          'search Linestore for brightness values
    lineval!=Linestore&(x%)
    ysum!=ysum!+lineval!
    xsum&=xsum&+x%
    INCR xtot&
    INCR ytot&
NEXT x%

xav!=xsum&/xtot&                        'sample mean
yav!=ysum!/ytot&                        'brightness mean

sxxsum!=0: sxysum!=0: sxtotal%=0
FOR x%=0 TO colend%
    xv!=x%
    ls!=Linestore&(x%)
    sxx!=(xv!-xav!)^2
    sxy!=(xv!-xav!)*(ls!-yav!)
    sxxsum!=sxxsum!+sxx!
    sxysum!=sxysum!+sxy!
    INCR sxtotal%
NEXT x%

    sxx!=sxxsum!/sxtotal%
    sxy!=sxysum!/sxtotal%

    m!=sxy!/sxx!                        'best fit gradient
    b!=yav!-(m!*xav!)                   'y axis intercept point

'MSGBOX "Slope = "+STR$(m!)+", Intercept = "+STR$(b!)+", xav! = "+STR$(xav!)+ ", yav! = "+STR$(yav!)+", sxx! = "+STR$(sxx!)+", sxy! = "+STR$(sxy!)

   linptr=Imptr1&
   midcol%=linecount%/2
   FOR y%=1 TO linecount%
   deltay&=(y%-midcol%)*m!
   FOR x%=1 TO linelength%
   Lum%=@linptr
   IF Lum%<0 THEN Lumval&=Lum%+65536 ELSE Lumval&=Lum%
   Lumval&=Lumval&-deltay&
   IF Lumval&<0 THEN Lumval&=0
   IF Lumval&>65535 THEN Lumval&=65535
   IF Lumval&>32767 THEN Lum%=Lumval&-65536 ELSE Lum%=Lumval&
   @linptr=Lum%
   INCR linptr
   NEXT x%
   NEXT y%

END SUB

'*****************************************

SUB ColGradientfind(BYVAL Imptr1&, BYVAL hsize&, BYVAL vsize&)EXPORT

 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount% = hsize&*2
 pxcount2% = hsize&*2+2

 DIM Linestore&(hsize&)
 DIM linptr AS BYTE PTR

 pxcount% = hsize&
 pxcount2% = hsize&+1

 lineend%=linelength%-20

linptr=Imptr1&+(linelength%*20)+20                    '10 lines down, 10 pixels in
FOR x%=0 TO lineend%
Lumval&=@linptr
Linestore&(x%)=Lumval&                 'store luminance values for line
INCR linptr
NEXT x%

Regress1:
xsum&=0: xtot&=0: ytot&=0: ysum!=0

FOR x%=0 TO lineend%                         'search Linestore for brightness values
    lineval!=Linestore&(x%)
    ysum!=ysum!+lineval!
    xsum&=xsum&+x%
    INCR xtot&
    INCR ytot&
NEXT x%

xav!=xsum&/xtot&                         'sample mean
yav!=ysum!/ytot&                         'brightness mean

sxxsum!=0: sxysum!=0: sxtotal%=0
FOR x%=0 TO lineend%
    xv!=x%
    ls!=Linestore&(x%)
    sxx!=(xv!-xav!)^2
    sxy!=(xv!-xav!)*(ls!-yav!)
    sxxsum!=sxxsum!+sxx!
    sxysum!=sxysum!+sxy!
    INCR sxtotal%
NEXT x%

    sxx!=sxxsum!/sxtotal%
    sxy!=sxysum!/sxtotal%

    m!=sxy!/sxx!                        'best fit gradient
    b!=yav!-(m!*xav!)                   'y axis intercept point

'MSGBOX "Slope = "+STR$(m!)+", Intercept = "+STR$(b!)+", xav! = "+STR$(xav!)+ ", yav! = "+STR$(yav!)+", sxx! = "+STR$(sxx!)+", sxy! = "+STR$(sxy!)

   midline%=linelength%/2
   linptr=Imptr1&
   FOR y%=1 TO linecount%
   FOR x%=1 TO linelength%
   Lum?=@linptr
   Lumval&=Lum?
   deltay&=(x%-midline%)*m!
   Lumval&=Lumval&-deltay&
   IF Lumval&<0 THEN Lumval&=0
   IF Lumval&>255 THEN Lumval&=255
   Lum?=Lumval&
   @linptr=Lum?
   INCR linptr
   NEXT x%
   NEXT y%

'find vertical gradient

    colend%=linecount%-20
    linptr=Imptr1&+(linelength%)*2-30                   'top line, 15 pixels in from right hand side
    FOR y%=0 TO colend%
    Lum?=@linptr
    Lumval&=Lum?
    Linestore&(y%,0)=Lumval&              'store luminance values for column
    linptr=linptr+pxcount%
NEXT x%


Regress2:
xsum&=0: xtot&=0: ytot&=0: ysum!=0

FOR x%=0 TO colend%                          'search Linestore for brightness values
    lineval!=Linestore&(x%)
    ysum!=ysum!+lineval!
    xsum&=xsum&+x%
    INCR xtot&
    INCR ytot&
NEXT x%

xav!=xsum&/xtot&                        'sample mean
yav!=ysum!/ytot&                        'brightness mean

sxxsum!=0: sxysum!=0: sxtotal%=0
FOR x%=0 TO colend%
    xv!=x%
    ls!=Linestore&(x%)
    sxx!=(xv!-xav!)^2
    sxy!=(xv!-xav!)*(ls!-yav!)
    sxxsum!=sxxsum!+sxx!
    sxysum!=sxysum!+sxy!
    INCR sxtotal%
NEXT x%

    sxx!=sxxsum!/sxtotal%
    sxy!=sxysum!/sxtotal%

    m!=sxy!/sxx!                        'best fit gradient
    b!=yav!-(m!*xav!)                   'y axis intercept point

'MSGBOX "Slope = "+STR$(m!)+", Intercept = "+STR$(b!)+", xav! = "+STR$(xav!)+ ", yav! = "+STR$(yav!)+", sxx! = "+STR$(sxx!)+", sxy! = "+STR$(sxy!)

   linptr=Imptr1&
   midcol%=linecount%/2
   FOR y%=1 TO linecount%
   deltay&=(y%-midcol%)*m!
   FOR x%=1 TO linelength%
   Lum?=@linptr
   Lumval&=Lum?
   Lumval&=Lumval&-deltay&
   IF Lumval&<0 THEN Lumval&=0
   IF Lumval&>255 THEN Lumval&=255
   Lum?=Lumval&
   @linptr=Lum?
   INCR linptr
   NEXT x%
   NEXT y%

END SUB

'*****************************************

SUB Vignette(BYVAL Imptr1&, BYVAL Imptr5&, BYVAL hsize&, BYVAL vsize&, BYVAL Bf%)EXPORT

DIM Imptr AS INTEGER PTR
DIM Outptr AS INTEGER PTR

Imstart& = Imptr5& + (hsize&+vsize&*hsize&)   '6003000       'centre of image
Lum%=32767                         'centre brightness

vstart&=-vsize&/2+1
vend&=vsize&/2
hstart&=-hsize&/2+1
hend&=hsize&/2
cornerval&=SQR(vend&*vend&+hend&*hend&)
FOR Ver&= vstart& TO vend&                              'store vignette pattern in Imagearray5
    FOR Hor&= hstart& TO hend&
        Rad&= SQR(Ver&*Ver& + Hor&*Hor&)
        Imptr = Imstart& + (Ver& * hsize&*2) + Hor&*2
        Rb& = ABS((cornerval& - Rad&)/20)       'gradient roll-off is to zero at image corners
        Lumval& = 5000 - Rb&*Bf%
        IF Lumval&<0 THEN Lumval&=0
        IF Lumval&>32767 THEN Lumval&=32767
        @Imptr = Lumval&
    NEXT Hor&
NEXT Ver&

Imptr = Imptr5&
Outptr = Imptr1&
Framesize&=vsize&*hsize&
FOR P&=1 TO Framesize&
    Impt&=@Imptr
    Outpt&=@Outptr
    IF Outpt&<0 THEN Outpt&=Outpt&+65536
Outpt& = Outpt& + Impt&
IF Outpt&>65535 THEN Outpt&=65535
IF Outpt&>32767 THEN Outpt&=Outpt&-65536

@Outptr=Outpt&
INCR Outptr
INCR Imptr
NEXT P&
END SUB

SUB dkload (filestring$, BYVAL Imptr3&, BYVAL hsize&, BYVAL vsize&) EXPORT
 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount% = hsize&*2
 pxcount2% = hsize&*2+2
 DIM Linestring AS STRING*21808
 OPEN filestring$ FOR BINARY AS #1
 FOR y%=1 TO 10
 GET$ #1, 21808, Linestring$
 POKE$ (Imptr3&), Linestring$
 Imptr3&= Imptr3& + 21808
 NEXT y%
 CLOSE #1
END SUB

SUB hidkload (filestring$, BYVAL Imptr3&, BYVAL hsize&, BYVAL vsize&) EXPORT
 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount% = hsize&*2
 pxcount2% = hsize&*2+2
 DIM Linestring AS STRING*21808
 OPEN filestring$ FOR BINARY AS #1
 FOR y%=1 TO 40
 GET$ #1, 21808, Linestring$
 POKE$ (Imptr3&), Linestring$
 Imptr3&= Imptr3& + 21808
 NEXT y%
 CLOSE #1
END SUB

SUB darksubtract(BYVAL Imptr1&, BYVAL Imptr3&, BYVAL hsize&, BYVAL vsize&) EXPORT
 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount% = hsize&*2
 pxcount2% = hsize&*2+2
 DIM Impt1 AS INTEGER PTR
 DIM Impt2 AS INTEGER PTR
 Impt1 = Imptr1&
 Impt2 = Imptr3&
 FOR G& = 1 TO framesize&
 Pix1% = @Impt1
 Pix2% = @Impt2

 IF Pix1%<0 THEN P1& = Pix1% + 65536 ELSE P1& = Pix1%         'normalise to unsigned
 IF Pix2%<0 THEN P2& = Pix2% + 65536 ELSE P2& = Pix2%         'normalise to unsigned
 Newpix& = P1& - P2&
 IF Newpix& < 0 THEN Newpix& = 0
 IF Newpix& > 32767 THEN Newpx% = Newpix& - 65536 ELSE Newpx% = Newpix&     'revert to signed
 @Impt1 = Newpx%
 INCR Impt1
 INCR Impt2
 NEXT G&
END SUB

SUB sendfile (BYVAL Imptr1&, BYVAL Imptr2&, BYVAL hsize&, BYVAL vsize&, BYVAL colourfile%) EXPORT
 IF colourfile%=0 THEN
     imsize& = hsize&*vsize&*2
     ELSE
     imsize&=hsize&*vsize&*5
 END IF
     POKE$ Imptr2&, PEEK$(Imptr1&,imsize&)
END SUB

SUB returnfile (BYVAL Imptr1&, BYVAL Imptr2&, BYVAL hsize&, BYVAL vsize&, BYVAL colourfile%) EXPORT
 IF colourfile%=0 THEN
     imsize& = hsize&*vsize&*2
     ELSE
     imsize&=hsize&*vsize&*5
 END IF
    POKE$ Imptr1&, PEEK$(Imptr2&,imsize&)
END SUB

SUB restoreimge (BYVAL Imptr1&, BYVAL Imptr4&, BYVAL hsize&, BYVAL vsize&) EXPORT
 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount% = hsize&*2
 pxcount2% = hsize&*2+2
 DIM img1 AS INTEGER PTR
 DIM img2 AS INTEGER PTR
 img1 = Imptr1&
 img2 = Imptr4&
 FOR z& = 1 TO framesize&
 @img1 = @img2
 INCR img1
 INCR img2
 NEXT z&
END SUB

SUB copyimge (BYVAL Imptr1&, BYVAL Imptr4&, BYVAL hsize&, BYVAL vsize&) EXPORT
 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount% = hsize&*2
 pxcount2% = hsize&*2+2
 DIM img1 AS INTEGER PTR
 DIM img2 AS INTEGER PTR
 img1 = Imptr1&
 img2 = Imptr4&
 FOR z& = 1 TO framesize&
 @img2 = @img1
 INCR img1
 INCR img2
 NEXT z&
END SUB

'SUB copyfile (BYVAL Imptr1&, BYVAL Imptr2&) EXPORT
' POKE$ Imptr1&, PEEK$(Imptr2&,872320)
'END SUB



SUB Intconvert(BYVAL filestring$, BYVAL A%, BYVAL datptr1&, BYVAL datptr2&, BYVAL hsize&, BYVAL vsize&) EXPORT
 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount% = hsize&*2
 pxcount2% = hsize&*2+2
DIM dptr1 AS INTEGER PTR
DIM dptr2 AS INTEGER PTR
 dptr1 = datptr1&
 dptr2 = datptr2&

 IF A%<0 THEN P1& = A% + 65536  ELSE P1& = A%       'normalise to unsigned
 Newpix& = P1&
 IF Newpix& < 0 THEN Newpix& = 0
 IF Newpix& > 32767 THEN Newpx% = Newpix& - 65536 ELSE Newpx% = Newpix&     'revert to signed
 @dptr1 = P1&
 @dptr2 = Newpx%

END SUB



 SUB guidesmooth2 (BYVAL Imptr1&, BYVAL Imptr2&) EXPORT
 DIM Pointer1 AS BYTE PTR
 DIM Pointer2 AS BYTE PTR
 DIM Startpointer AS BYTE PTR
 DIM Winpointer AS BYTE PTR
 DIM Winstartpointer AS BYTE PTR
 DIM Outstartpointer AS BYTE PTR
 DIM Med&(100)

 Radius%=1

 imsize& = 145000
 linelength% = 500
 linecount% = 290
 pxcount% = 500
 pxcount2% = 500

  POKE$ Imptr2&, PEEK$ (Imptr1&,imsize&)                         'copy image to buffer

 Startrow% = Radius%                                            'first pixel in line
 Endrow% = linelength% - Radius%                                'last pixel in line
 Startline% = Radius%                                           'first line
 Endline% = linecount% - Radius%                                'last line
 Kerncount% = 2*Radius% + 1                                     'window width / height
 Kernarea% = Kerncount% ^2                                      'number of pixels in window

 Winstartpointer = Imptr2&                                      'top left corner of window
 Pointer1 = Imptr1& + Radius%*pxcount% + Radius%              'location of first pixel for processing
 Pointer2 = Imptr2& + Radius%*pxcount% + Radius%              'first pixel in input array
 Startpointer = Pointer2                                        'central pixel of input window
 Outstartpointer = Pointer1                                     'central pixel of output window

 FOR z% = Startline% TO Endline%
 FOR w% = Startrow% TO Endrow%

 Kernel:
 n% = 0
 Centre? = @Pointer2
 Cen& = Centre?                                                 'central pixel value
 Winpointer = Winstartpointer                                    'start at top left corner of window
 FOR y% = 1 TO Kerncount%                                        'sum columns of pixels
 FOR x% = 1 TO Kerncount%                                        'sum rows of pixels
 PV? = @Winpointer                                               'get pixel value
 P1& = PV?
 Med&(n%)= P1&                                                   'add to total
 INCR Winpointer                                                 'next pixel in row
 INCR n%
 NEXT x%
 Winpointer = Winstartpointer + y%*pxcount%                  'next row of window
 NEXT y%

 ARRAY SORT Med&(0) FOR n%

 midval& = Med&(n%\2 -1)

 Newpix& = midval&
 IF Newpix&>255 THEN Newpix& = 255
 IF Newpix&<0 THEN Newpix& = 0
 Newpx? = Newpix&
 @Pointer1 = Newpx?
 INCR Pointer1                                                  'next pixel in output image
 INCR Pointer2                                                  'next pixel in source image
 INCR Winstartpointer
 NEXT w%

 Outstartpointer = Outstartpointer + pxcount%
 Startpointer = Startpointer + pxcount%
 Winstartpointer = Startpointer - Radius%*pxcount2%
 Pointer1 = Outstartpointer                                     'central pixel address in output image
 Pointer2 = Startpointer                                        'central pixel address in input image
 NEXT z%

END SUB

SUB himgsave (filestring$, BYVAL Imptr1&, BYVAL hsize&, BYVAL vsize&) EXPORT
 imsize& = hsize&*vsize&

 Bcount&=FIX(imsize&/32000)
 Excess&=imsize&-(Bcount&*32000)
 DIM Linestring AS STRING*32000
 OPEN filestring$ FOR BINARY AS #1
 FOR y%=1 TO Bcount&
 Linestring$= PEEK$ (Imptr1&,32000)
 PUT$ #1,Linestring$
 Imptr1&= Imptr1& + 32000
 NEXT y%
 FOR y%=1 TO Excess&
     PUT$ #1,PEEK$(Imptr1&,1)
 INCR Imptr1&
 NEXT y%
 CLOSE #1
END SUB

SUB imgsave (filestring$, BYVAL Imptr1&, BYVAL hsize&, BYVAL vsize&) EXPORT
 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount% = hsize&*2
 pxcount2% = hsize&*2+2
 Bcount&=FIX(imsize&/32000)
 Excess&=imsize&-(Bcount&*32000)
 DIM Linestring AS STRING*32000
 OPEN filestring$ FOR BINARY AS #1
 FOR y%=1 TO Bcount&
 Linestring$= PEEK$ (Imptr1&,32000)
 PUT$ #1,Linestring$
 Imptr1&= Imptr1& + 32000
 NEXT y%
 FOR y%=1 TO Excess&
     PUT$ #1,PEEK$(Imptr1&,1)
 INCR Imptr1&
 NEXT y%
 CLOSE #1
END SUB

SUB colimgsave (filestring$, BYVAL Imptr1&, BYVAL hsize&, BYVAL vsize&) EXPORT
 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount% = hsize&*2
 pxcount2% = hsize&*2+2
 Bcount&=FIX((Framesize&*5)/32000)
 Excess&=Framesize&*5-(Bcount&*32000)
 DIM Linestring AS STRING*32000
 OPEN filestring$ FOR BINARY AS #1
 FOR y%=1 TO Bcount&
 Linestring$= PEEK$ (Imptr1&,32000)
 PUT$ #1,Linestring$
 Imptr1&= Imptr1& + 32000
 NEXT y%
 FOR y%=1 TO Excess&
     PUT$ #1,PEEK$(Imptr1&,1)
 INCR Imptr1&
 NEXT y%
 CLOSE #1
END SUB

SUB imgload (filestring$, BYVAL Imptr1&, BYVAL hsize&, BYVAL vsize&) EXPORT
     'MSGBOX "imsize&="+STR$(imsize&)+", hsize&="+STR$(hsize&)+", vsize&="+STR$(vsize&)
 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount% = hsize&*2
 pxcount2% = hsize&*2+2
 Bcount&=FIX(imsize&/32000)
 Excess&=imsize&-(Bcount&*32000)
 DIM Linestring AS STRING*32000
 DIM Bitstring AS STRING*1
 OPEN filestring$ FOR BINARY AS #1
 FOR y%=1 TO Bcount&
 GET$ #1, 32000, Linestring$
 POKE$ (Imptr1&), Linestring$
 Imptr1&= Imptr1& + 32000
 NEXT y%
 FOR y%=1 TO Excess&
 GET$ #1,1, Bitstring$
 POKE$(Imptr1&),Bitstring$
 INCR Imptr1&
 NEXT y%
 CLOSE #1
 'msgbox "Bcount&="+str$(Bcount&)+", Excess&="+Str$(Excess&)
END SUB

SUB colimgload (filestring$, BYVAL Imptr1&, BYVAL hsize&, BYVAL vsize&) EXPORT
 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2
 linelength% = hsize&
 linecount% = vsize&
 pxcount% = hsize&*2
 pxcount2% = hsize&*2+2
 Bcount&=FIX((Framesize&*5)/32000)
 Excess&=Framesize&*5-(Bcount&*32000)
 DIM Linestring AS STRING*32000
 DIM Bitstring AS STRING*1
 OPEN filestring$ FOR BINARY AS #1
 FOR y%=1 TO Bcount&
 GET$ #1, 32000, Linestring$
 POKE$ (Imptr1&), Linestring$
 Imptr1&= Imptr1& + 32000
 NEXT y%
 FOR y%=1 TO Excess&
 GET$ #1,1, Bitstring$
 POKE$(Imptr1&),Bitstring$
 INCR Imptr1&
 NEXT y%
 CLOSE #1
END SUB

SUB AFgenerate (BYVAL Imptr1&, BYVAL Imptr2&, BYVAL backsignal&, BYVAL hsize&, BYVAL vsize&) EXPORT
 DIM Impoint AS INTEGER PTR

 Framesize&=hsize&*vsize&
 imsize& = hsize&*vsize&*2

 Impoint=Imptr1&

 imagend& = Framesize&
 FOR x&=1 TO imagend&    'Modify image
 Imdata&=@Impoint
 IF Imdata&<0 THEN Imdata&=Imdata&+65536
 IF Imdata&>backsignal& THEN Imdata&=backsignal&
 IF Imdata&>32767 THEN Imdata&=Imdata&-65536
 @Impoint=Imdata&
 INCR Impoint
 NEXT x&

END SUB
