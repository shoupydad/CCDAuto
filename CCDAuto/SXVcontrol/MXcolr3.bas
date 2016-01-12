'-------------------------------------------------------------------------------
'
'   MXCOLR.BAS  For PB/DLL
'   Copyright (c) 2004 TERRY PLATT
'
'-------------------------------------------------------------------------------

 $COMPILE DLL "MXCOLR.DLL"

 GLOBAL Linesize&, Framesize&, Framesize2&, Framesize3&, Framesize4&, Frameheight&
 GLOBAL Linesize2&, Linesize4&

 SUB Define
  Linesize&=hsize&
  Frameheight&=vsize&
  Framesize&=Linesize&*Frameheight&
  Framesize2&=Framesize&*2
  Framesize3&=Framesize&*3
  Framesize4&=Framesize&*4
  Linesize2&=Linesize&*2
  Linesize4&=Linesize&*4
 END SUB

 '***************************************************************************** CMYG synthesis

 SUB colsynth (BYVAL Colourptr&, BYVAL Imptr1&, BYVAL hsize&, BYVAL vsize&, BYVAL cs&, BYVAL colourbal%, Dirpath$) EXPORT

 DIM Lumval&                                     'luminance value storage variable
 DIM Lumptr AS INTEGER PTR
 DIM Redptr AS BYTE PTR
 DIM Grnptr AS BYTE PTR
 DIM Bluptr AS BYTE PTR
 DIM Imageptr1 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr2 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr3 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr4 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr5 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr6 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr7 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr8 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr9 AS INTEGER PTR                    'pointer to source image

 B%=1
 C%=1

  Linesize&=hsize&
  Frameheight&=vsize&
  Framesize&=Linesize&*Frameheight&
  Framesize2&=Framesize&*2
  Framesize3&=Framesize&*3
  Framesize4&=Framesize&*4
  Linesize2&=Linesize&*2
  Linesize4&=Linesize&*4

 'CALL Define

 Lumptr=Colourptr&                               'pointers to colour array
 Redptr=Colourptr&+Framesize2&                   'start of red file
 Grnptr=Colourptr&+Framesize3&                   'start of green file
 Bluptr=Colourptr&+Framesize4&                   'start of blue file

 Imptrstart& = Imptr1&+Linesize4&                'start at 2 lines down

 Imageptr1=Imptrstart&-2                         'pointers to box-shaped window around pixel
 Imageptr2=Imptrstart&
 Imageptr3=Imptrstart&+2
 Imageptr4=Imptrstart&-Linesize4&
 Imageptr5=Imptrstart&+Linesize4&
 Imageptr6=Imptrstart&-Linesize4&-2
 Imageptr7=Imptrstart&-Linesize4&+2
 Imageptr8=Imptrstart&+Linesize4&-2
 Imageptr9=Imptrstart&+Linesize4&+2

 'msgbox Str$(Linesize&)


 FOR y%=1 TO (Frameheight&/2)-2

 FOR x%=1 TO Linesize&

 IF x%=1 THEN GOTO misspixel
 IF x%=Linesize& THEN GOTO misspixel
                                                 'get pixel values as signed integers
 G%= @Imageptr1                                  'first pixel
 H%= @Imageptr2                                  'mainpixel
 I%= @Imageptr3                                  'lastpixel
 J%= @Imageptr4                                  'toppixel
 K%= @Imageptr5                                  'bottompixel
 Q%= @Imageptr6                                  'topleftpixel
 R%= @Imageptr7                                  'toprightpixel
 S%= @Imageptr8                                  'bottomleftpixel
 T%= @Imageptr9                                  'bottomrightpixel

 IF G%<0 THEN L&=G%+65536 ELSE L&=G%             'normalise to long integers
 IF H%<0 THEN M&=H%+65536 ELSE M&=H%
 IF I%<0 THEN N&=I%+65536 ELSE N&=I%
 IF J%<0 THEN O&=J%+65536 ELSE O&=J%
 IF K%<0 THEN P&=K%+65536 ELSE P&=K%
 IF Q%<0 THEN C1&=Q%+65536 ELSE C1&=Q%
 IF R%<0 THEN C2&=R%+65536 ELSE C2&=R%
 IF S%<0 THEN C3&=S%+65536 ELSE C3&=S%
 IF T%<0 THEN C4&=T%+65536 ELSE C4&=T%

 sat%=0
 Lumval&=(L&+M&)/2                               'synthesise 16 bit luminance value

 Lumval&=Lumval&*1.4
 IF Lumval&>65535 THEN Lumval&=65535
 satfactor&=0
 IF Lumval&>50000 THEN satfactor&=100
 IF Lumval&>53000 THEN satfactor&=1000
 IF Lumval&>55000 THEN satfactor&=30000
 IF Lumval&>60000 THEN satfactor&=200000
 IF Lumval&>65000 THEN satfactor&=500000

                            'saturate uneven luminance values
 IF Lumval&>65535 THEN Lumval&=65535
 IF Lumval&>65500 THEN sat%=1

 corners&=C1&+C2&+C3&+C4&
 tbfl&=L&+N&+O&+P&
 allsum&=tbfl&+corners&+M&
                                                 'synthesise colour values
 IF B%=1 THEN
    IF C%=1 THEN
       V1& = corners& - 2*M&
       V2& = tbfl& - M&

       RD& = (7*V1& - 2*V2&)/40
       GR& = (6*V2& - V1&)/40
       BL& = (allsum& - 11*RD& - 13*GR&)/8

       'RD&=0: GR&=0: BL&=0
    END IF

    IF C%=2 THEN
       V1& = 5*tbfl& - 2*(corners& + M&)
       V2& = tbfl& - 2*M&

       BL& = (3*V1& - 11*V2&)/40
       RD& = (7*V2& - V1&)/20
       GR& = (allsum& - 7*BL& - 10*RD&)/14

       'RD&=0: GR&=0: BL&=0
    END IF
 END IF

 IF B%=2 THEN
    IF C%=1 THEN
       V1& = 5*tbfl& - 2*(corners& + M&)
       V2& = tbfl& - 2*M&

       RD& = (3*V1& - 11*V2&)/40
       BL& = (7*V2& - V1&)/20
       GR& = (allsum& - 10*BL& - 7*RD&)/14

      'RD&=0: GR&=0: BL&=0
    END IF

    IF C%=2 THEN
       V1& = corners& - 2*M&
       V2& = tbfl& - M&

       BL& = (7*V1& - 2*V2&)/40
       GR& = (6*V2& - V1&)/40
       RD& = (allsum& - 11*BL& - 13*GR&)/8

      'RD&=0: GR&=0: BL&=0
    END IF
 END IF

 LIMIT:
 RD&=RD&*300/75                             'ADJUST COLOUR FOR PRESET BALANCE
 GR&=GR&*300/45
 BL&=BL&*9

 RD&=RD&+satfactor&                         'ADJUST SATURATION ACCORDING TO LUMINANCE LEVEL
 GR&=GR&+satfactor&
 BL&=BL&+satfactor&

 IF RD&<0 THEN RD&=0: sat%=1
 IF GR&<0 THEN GR&=0: sat%=1
 IF BL&<0 THEN BL&=0: sat%=1

 scalefactor%=300                           'adjust to give colour saturation at luminance saturation

 BL&=BL&/scalefactor%
 GR&=GR&/scalefactor%
 RD&=RD&/scalefactor%

 IF RD&>255 THEN Red?=255 ELSE Red?=RD&
 IF GR&>255 THEN Grn?=255 ELSE Grn?=GR&
 IF BL&>255 THEN Blu?=255 ELSE Blu?=BL&

 MG&=(Red?+Grn?+Blu?)/3
 meangrey?= 255 'MG&

 misspixel:
 IF x%=1 THEN Lumval&=0: Red?=0: Grn?=0: Blu?=0
 IF x%=Linesize& THEN Lumval&=0: Red?=0: Grn?=0: Blu?=0

 IF sat%=1 THEN Red?=meangrey?: Grn?=meangrey?: Blu?=meangrey?
 IF Lumval&>32767 THEN luminance%=Lumval&-65536 ELSE luminance%=Lumval&      'convert luminance back to signed integers

 'IF y%>100 AND y%<105 THEN
 '   IF x%>300 AND x%<305 THEN
 '   MSGBOX "x% = "+STR$(x%)+", y% = "+STR$(y%)+", b% = "+STR$(b%)+", c% = "+STR$(c%)+", Red = "+STR$(RD&)+", Green = "+STR$(GR&)+", Blue = "+STR$(BL&)+", Red? = "+STR$(Red?)+", Grn? = "+STR$(Grn?)+", Blu? = "+STR$(Blu?)
 '   END IF
 ' END IF

 @Lumptr=luminance%
 INCR Lumptr
 @Redptr= Red?
 INCR Redptr
 @Grnptr= Grn?
 INCR Grnptr
 @Bluptr= Blu?
 INCR Bluptr

 INCR Imageptr1
 INCR Imageptr2
 INCR Imageptr3
 INCR Imageptr4
 INCR Imageptr5
 INCR Imageptr6
 INCR Imageptr7
 INCR Imageptr8
 INCR Imageptr9


 INCR B%: IF B%=3 THEN B%=1           'NEXT PIXEL
 NEXT x%

Lumptr=Lumptr+Linesize2&
Redptr=Redptr+Linesize&
Grnptr=Grnptr+Linesize&
Bluptr=Bluptr+Linesize&

Imageptr1 = Imageptr1+(Linesize2&)
Imageptr2 = Imageptr2+(Linesize2&)
Imageptr3 = Imageptr3+(Linesize2&)
Imageptr4 = Imageptr4+(Linesize2&)
Imageptr5 = Imageptr5+(Linesize2&)
Imageptr6 = Imageptr6+(Linesize2&)
Imageptr7 = Imageptr7+(Linesize2&)
Imageptr8 = Imageptr8+(Linesize2&)
Imageptr9 = Imageptr9+(Linesize2&)

INCR C%: IF C%=3 THEN C%=1          'NEXT LINE
NEXT y%
'MSGBOX "Colourptr&="+str$(Colourptr&)+", Lumptr="+STR$(Lumptr)+", Bluptr="+STR$(Bluptr)
'msgbox str$(Linesize2&)
'GOTO endsynth

'******************************** Generate odd lines:

DIM Lumptr2 AS INTEGER PTR
DIM Lumptr3 AS INTEGER PTR
DIM Lumptr4 AS INTEGER PTR
DIM Lumptr5 AS INTEGER PTR
DIM Redptr2 AS BYTE PTR
DIM Grnptr2 AS BYTE PTR
DIM Bluptr2 AS BYTE PTR
DIM Redptr3 AS BYTE PTR
DIM Grnptr3 AS BYTE PTR
DIM Bluptr3 AS BYTE PTR

Offset&=Linesize2&
Lumptr=Colourptr&                               'pointers to colour array
Lumptr2=Colourptr&+Offset&
Lumptr3=Colourptr&+Offset&*2
Lumptr4=Colourptr&+Offset&*3
Lumptr5=Colourptr&+Offset&*4
Redptr=Colourptr&+Framesize2&
Grnptr=Colourptr&+Framesize3&
Bluptr=Colourptr&+Framesize4&
Redptr2=Redptr+Linesize&
Redptr3=Redptr+Linesize2&
Grnptr2=Grnptr+Linesize&
Grnptr3=Grnptr+Linesize2&
Bluptr2=Bluptr+Linesize&
Bluptr3=Bluptr+Linesize2&

GOTO Linegen

FOR y%=1 TO Frameheight&/4                     'scan file for saturated luminance areas and average out
FOR x%=1 TO Linesize&
Lum1%=@Lumptr
Lum3%=@Lumptr3
Lum5%=@Lumptr5

IF Lum1%<0 THEN Lumval1&=Lum1%+65536 ELSE Lumval1&=Lum1%
IF Lum3%<0 THEN Lumval3&=Lum3%+65536 ELSE Lumval3&=Lum3%
IF Lum5%<0 THEN Lumval5&=Lum5%+65536 ELSE Lumval5&=Lum5%

IF Lumval1&>45000 THEN
   IF Lumval5&>45000 THEN Lumval3&=(Lumval1&+Lumval5&)/2
   GOTO Lumsat
END IF

'IF Lumval2&>50000 THEN
   'IF Lumval4&>50000 THEN Lumval3&=(Lumval2&+Lumval4&)/2
'END IF

Lumsat:
'IF Lumval1&>32767 THEN Lum1%=Lumval1&-65536 ELSE Lum1%=Lumval1&
'IF Lumval2&>32767 THEN Lum3%=Lumval2&-65536 ELSE Lum3%=Lumval2&
IF Lumval3&>32767 THEN Lum3%=Lumval3&-65536 ELSE Lum3%=Lumval3&

@Lumptr3= Lum3%
'@Lumptr= Lum1%

INCR Lumptr
INCR Lumptr3
INCR Lumptr5

NEXT x%

Lumptr=Lumptr+Linesize&*6
Lumptr3=Lumptr3+Linesize&*6
Lumptr5=Lumptr5+Linesize&*6

NEXT y%

Linegen:

Lumptr=Colourptr&
Lumptr2=Colourptr&+Linesize2&
Lumptr3=Colourptr&+Linesize4&

FOR y%=1 TO Frameheight&/2
FOR x%=1 TO Linesize&
Lum1%=@Lumptr
Lum2%=@Lumptr3
IF Lum1%<0 THEN Lumval1&=Lum1%+65536 ELSE Lumval1&=Lum1%
IF Lum2%<0 THEN Lumval2&=Lum2%+65536 ELSE Lumval2&=Lum2%


Lumval3&=Lumval1&\2 + Lumval2&\2
IF Lumval3&>32767 THEN Lum3%=Lumval3&-65536 ELSE Lum3%=Lumval3&
IF Lumval1&>32767 THEN Lum1%=Lumval1&-65536 ELSE Lum1%=Lumval1&
IF Lumval2&>32767 THEN Lum2%=Lumval2&-65536 ELSE Lum2%=Lumval2&

@Lumptr2= Lum3%
@Lumptr3= Lum2%
@Lumptr= Lum1%

Red1?=@Redptr: INCR Redptr: Red2?=@Redptr: DECR Redptr
Red3?=@Redptr3: INCR Redptr3: Red4?=@Redptr3: DECR Redptr3
Red1?=Red1?\2+Red2?\2
Red3?=Red3?\2+Red4?\2
Red5?=Red1?\2+Red3?\2
@Redptr2=Red5?
@Redptr=Red1?
@Redptr3=Red3?

Grn1?=@Grnptr: INCR Grnptr: Grn2?=@Grnptr: DECR Grnptr
Grn3?=@Grnptr3: INCR Grnptr3: Grn4?=@Grnptr3: DECR Grnptr3
Grn1?=Grn1?\2+Grn2?\2
Grn3?=Grn3?\2+Grn4?\2
Grn5?=Grn1?\2+Grn3?\2
@Grnptr2=Grn5?
@Grnptr=Grn1?
@Grnptr3=Grn3?

Blu1?=@Bluptr: INCR Bluptr: Blu2?=@Bluptr: DECR Bluptr
Blu3?=@Bluptr3: INCR Bluptr3: Blu4?=@Bluptr3: DECR Bluptr3
Blu1?=Blu1?\2+Blu2?\2
Blu3?=Blu3?\2+Blu4?\2
Blu5?=Blu1?\2+Blu3?\2
@Bluptr2=Blu5?
@Bluptr=Blu1?
@Bluptr3=Blu3?

INCR Lumptr
INCR Lumptr2
INCR Lumptr3
INCR Redptr
INCR Redptr2
INCR Redptr3
INCR Grnptr
INCR Grnptr2
INCR Grnptr3
INCR Bluptr
INCR Bluptr2
INCR Bluptr3

NEXT x%

Lumptr=Lumptr+Linesize2&
Lumptr2=Lumptr2+Linesize2&
Lumptr3=Lumptr3+Linesize2&
Redptr=Redptr+Linesize&
Redptr2=Redptr2+Linesize&
Redptr3=Redptr3+Linesize&
Grnptr=Grnptr+Linesize&
Grnptr2=Grnptr2+Linesize&
Grnptr3=Grnptr3+Linesize&
Bluptr=Bluptr+Linesize&
Bluptr2=Bluptr2+Linesize&
Bluptr3=Bluptr3+Linesize&

NEXT y%

endsynth:
END SUB

'******************************************************************************************








 SUB intcolsynth (BYVAL Colourptr&, BYVAL Imptr1&, BYVAL hsize&, BYVAL vsize&, BYVAL cs%, BYVAL colourbal%, Dirpath$) EXPORT

 DIM Lumval&                                     'luminance value storage variable
 DIM Lumptr AS INTEGER PTR
 DIM Redptr AS BYTE PTR
 DIM Grnptr AS BYTE PTR
 DIM Bluptr AS BYTE PTR
 DIM Imageptr1 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr2 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr3 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr4 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr5 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr6 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr7 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr8 AS INTEGER PTR                    'pointer to source image
 DIM Imageptr9 AS INTEGER PTR                    'pointer to source image

  Linesize&=hsize&
  Frameheight&=vsize&
  Framesize&=Linesize&*Frameheight&
  Framesize2&=Framesize&*2
  Framesize3&=Framesize&*3
  Framesize4&=Framesize&*4
  Linesize2&=Linesize&*2
  Linesize4&=Linesize&*4

  'CALL Define

 B%=1
 C%=2

 B2%=B% 'Save pixel offset
 C2%=C% 'Save line offset

Pass1:
 Lumptr=Colourptr&                               'pointers to colour array
 Redptr=Colourptr&+Framesize2&                        'start of red file
 Grnptr=Colourptr&+Framesize3&                       'start of green file
 Bluptr=Colourptr&+Framesize4&                       'start of blue file

 Imptrstart& = Imptr1&+Linesize4&                      'start at 1 line down

 Imageptr1=Imptrstart&-2                         'pointers to box-shaped window around pixel
 Imageptr2=Imptrstart&
 Imageptr3=Imptrstart&+2
 Imageptr4=Imptrstart&-Linesize2&
 Imageptr5=Imptrstart&+Linesize2&
 Imageptr6=Imptrstart&-(Linesize2&)-2
 Imageptr7=Imptrstart&-(Linesize2&)+2
 Imageptr8=Imptrstart&+(Linesize2&)-2
 Imageptr9=Imptrstart&+(Linesize2&)+2

 'First pass (even lines)

 FOR y%=1 TO (Frameheight&-4)

 FOR x%=1 TO Linesize&

 IF x%=1 THEN GOTO misspixel
 IF x%=Linesize& THEN GOTO misspixel
                                                 'get pixel values as signed integers
 G%= @Imageptr1                                  'first pixel
 H%= @Imageptr2                                  'mainpixel
 I%= @Imageptr3                                  'lastpixel
 J%= @Imageptr4                                  'toppixel
 K%= @Imageptr5                                  'bottompixel
 Q%= @Imageptr6                                  'topleftpixel
 R%= @Imageptr7                                  'toprightpixel
 S%= @Imageptr8                                  'bottomleftpixel
 T%= @Imageptr9                                  'bottomrightpixel

 IF G%<0 THEN L&=G%+65536 ELSE L&=G%             'normalise to long integers
 IF H%<0 THEN M&=H%+65536 ELSE M&=H%
 IF I%<0 THEN N&=I%+65536 ELSE N&=I%
 IF J%<0 THEN O&=J%+65536 ELSE O&=J%
 IF K%<0 THEN P&=K%+65536 ELSE P&=K%
 IF Q%<0 THEN C1&=Q%+65536 ELSE C1&=Q%
 IF R%<0 THEN C2&=R%+65536 ELSE C2&=R%
 IF S%<0 THEN C3&=S%+65536 ELSE C3&=S%
 IF T%<0 THEN C4&=T%+65536 ELSE C4&=T%

     IF C%=1 THEN
     Lumval&=(L&+M&)/2              'Y/C line synthesise 16 bit luminance value
     ELSE
     IF B%=1 THEN Lumval&=L&+M&/2 ELSE Lumval&=M&+L&/2      'G/M luminance
     Lumval&=Lumval&/2
     END IF

 IF Lumval&>65535 THEN Lumval&=65535
 satfactor&=20
 'IF Lumval&>50000 THEN satfactor&=1000
 'IF Lumval&>55000 THEN satfactor&=10000
 'IF Lumval&>60000 THEN satfactor&=100000
 'IF Lumval&>65000 THEN satfactor&=500000

 'Lumval&=Lumval&*1.4
 IF Lumval&>65535 THEN Lumval&=65535

 corners&=C1&+C2&+C3&+C4&
                                                  'synthesise colour values
 IF B%=1 THEN
    IF C%=1 THEN                                  'magenta in centre
       RD& = (corners&-2*(L&+N&))/4
       GR& = (L&+N&)/2
       BL& = ((O&+P&)-(L&+N&))/2

       'RD&=100: GR&=100: BL&=100
    END IF

    IF C%=2 THEN                                  'cyan in centre
       RD& = ((L&+N&)-(corners&/2))/2
       GR& = (corners&)/4
       BL& = M&-corners&/4

       'RD&=100: GR&=100: BL&=100
    END IF
 END IF

 IF B%=2 THEN
    IF C%=1 THEN                                  'green in centre
       RD& = (O&+P&-2*M&)/2
       GR& = M&
       BL& = (corners&-4*M&)/4

      'RD&=100: GR&=100: BL&=100
    END IF

    IF C%=2 THEN                                  'yellow in centre
       RD& = M&-(O&+P&)/2
       GR& = (O&+P&)/2
       BL& = ((L&+N&)-(O&+P&))/2

      'RD&=100: GR&=100: BL&=100
    END IF
 END IF

 LIMIT:
 RD&=RD&*30/400                             'ADJUST COLOUR FOR PRESET BALANCE
 GR&=GR&*30/700
 BL&=BL&/11

'GR&=0
'RD&=0
'BL&=0
 RD&=RD&+satfactor&             'ADJUST SATURATION ACCORDING TO LUMINANCE LEVEL
 GR&=GR&+satfactor&
 BL&=BL&+satfactor&

 sat%=0
 IF RD&<0 THEN RD&=0: sat%=1
 IF GR&<0 THEN GR&=0: sat%=1
 IF BL&<0 THEN BL&=0: sat%=1

 scalefactor%=300               'adjust to give colour saturation at luminance saturation
 scalefactor%=1

 BL&=BL&/scalefactor%
 GR&=GR&/scalefactor%
 RD&=RD&/scalefactor%

 IF RD&>255 THEN Red?=255 ELSE Red?=RD&
 IF GR&>255 THEN Grn?=255 ELSE Grn?=GR&
 IF BL&>255 THEN Blu?=255 ELSE Blu?=BL&

 MG&=(Red?+Grn?+Blu?)/3
 meangrey?=MG&

 misspixel:
 IF x%=1 THEN Lumval&=0: Red?=0: Grn?=0: Blu?=0
 IF x%=Linesize& THEN Lumval&=0: Red?=0: Grn?=0: Blu?=0

 IF sat%=1 THEN Red?=meangrey?: Grn?=meangrey?: Blu?=meangrey?
 IF Lumval&>32767 THEN luminance%=Lumval&-65536 ELSE luminance%=Lumval&      'convert luminance back to signed integers

 'IF y%>100 AND y%<105 THEN
 '   IF x%>300 AND x%<305 THEN
 '   MSGBOX "x% = "+STR$(x%)+", y% = "+STR$(y%)+", b% = "+STR$(b%)+", c% = "+STR$(c%)+", Red = "+STR$(RD&)+", Green = "+STR$(GR&)+", Blue = "+STR$(BL&)+", Red? = "+STR$(Red?)+", Grn? = "+STR$(Grn?)+", Blu? = "+STR$(Blu?)
 '   END IF
 ' END IF

 @Lumptr=luminance%
 INCR Lumptr
 @Redptr= Red?
 INCR Redptr
 @Grnptr= Grn?
 INCR Grnptr
 @Bluptr= Blu?
 INCR Bluptr

 INCR Imageptr1
 INCR Imageptr2
 INCR Imageptr3
 INCR Imageptr4
 INCR Imageptr5
 INCR Imageptr6
 INCR Imageptr7
 INCR Imageptr8
 INCR Imageptr9


 INCR B%: IF B%=3 THEN B%=1           'NEXT PIXEL
 NEXT x%

 INCR C%: IF C%=3 THEN C%=1          'NEXT LINE
 NEXT y%

EXIT SUB



 '*********************

'Smooth luminance file

 DIM Lumptr2 AS INTEGER PTR
 DIM Lumptr3 AS INTEGER PTR
 DIM Lumptr4 AS INTEGER PTR
 DIM Lumptr5 AS INTEGER PTR

 Lumptr=Colourptr&                               'pointers to colour array
 Lumptr2=Colourptr&+Linesize2&
 Lumptr3=Colourptr&+Linesize4&
 Lumptr4=Colourptr&+Linesize&*6
 Lumptr5=Colourptr&+Linesize&*8

 FOR y%=1 TO (Frameheight&/2)-2                  'scan file for saturated luminance areas and average out
 FOR x%=1 TO Linesize&

 Lum1%=@Lumptr
 Lum2%=@Lumptr2
 Lum3%=@Lumptr3
 Lum4%=@Lumptr4
 Lum5%=@Lumptr5

 IF Lum1%<0 THEN Lumval1&=Lum1%+65536 ELSE Lumval1&=Lum1%
 IF Lum2%<0 THEN Lumval2&=Lum2%+65536 ELSE Lumval2&=Lum2%
 IF Lum3%<0 THEN Lumval3&=Lum3%+65536 ELSE Lumval3&=Lum3%
 IF Lum4%<0 THEN Lumval4&=Lum4%+65536 ELSE Lumval4&=Lum4%
 IF Lum5%<0 THEN Lumval5&=Lum5%+65536 ELSE Lumval5&=Lum5%

 IF Lumval5&>45000 THEN
    IF Lumval5&>32767 THEN Lum1%=Lumval5&-65536 ELSE Lum1%=Lumval5&
    @Lumptr = Lum1%
    @Lumptr2= Lum1%
    @Lumptr3= Lum1%
    @Lumptr4= Lum1%
 END IF

Lumsat:

INCR Lumptr
INCR Lumptr2
INCR Lumptr3
INCR Lumptr4
INCR Lumptr5

NEXT x%

Lumptr=Lumptr+Linesize&*6
Lumptr2=Lumptr2+Linesize&*6
Lumptr3=Lumptr3+Linesize&*6
Lumptr4=Lumptr4+Linesize&*6
Lumptr5=Lumptr5+Linesize&*6

NEXT y%
END SUB

'*************************************************************************************

SUB colourstretcher(BYVAL Minimum%, BYVAL Maximum%, BYVAL Colptr&, BYVAL Colourptr&, BYVAL hsize&, BYVAL vsize&) EXPORT
 DIM Table?(0 TO 300)
 DIM Lumptr AS INTEGER PTR
 DIM Databyte?

  Linesize&=hsize&
  Frameheight&=vsize&
  Framesize&=Linesize&*Frameheight&
  Framesize2&=Framesize&*2
  Framesize3&=Framesize&*3
  Framesize4&=Framesize&*4
  Linesize2&=Linesize&*2
  Linesize4&=Linesize&*4

 'CALL Define

 Dataptr&=VARPTR(Databyte?)
 Lumptr=Colourptr&
 Outptr&=Colptr&

 Range!= 255/(Maximum%)          'Generate lookup table
 FOR x%= 0 TO Maximum%
 a&=x%*Range!
 IF a&>255 THEN a&=255
 IF a&<0 THEN a&=0
 b?=a&
 Table?(x%)=b?
 NEXT x%

 FOR x%= Maximum% TO 300: Table?(x%)=255: NEXT x%

 FOR y&=1 TO Framesize&                        'Modify image
 Lumval%=@Lumptr
 IF Lumval%<0 THEN Lum&=Lumval%+65536 ELSE Lum&=Lumval%
 IF Lum& > 50000 THEN GOTO Nochange

 POKE Dataptr&, PEEK (Outptr&)
 Databyte?= Table?(Databyte?)
 POKE Outptr&, PEEK (Dataptr&)
 Nochange:
 INCR Outptr&
 INCR Lumptr
 NEXT y&

 IF Minimum%>0 THEN
 Outptr&=Colptr&
 FOR y&=1 TO Framesize&                        'Modify image
 Da%=PEEK (Outptr&)
 Da%= Da%-Minimum%
 IF Da%<0 THEN Da%=0
 Databyte?=Da%
 POKE Outptr&,Databyte?
 INCR Outptr&
 NEXT y&
 END IF

END SUB

SUB getvalues (BYVAL x%, BYVAL y%, BYVAL Colourptr&) EXPORT

 DIM Lumptr AS INTEGER PTR
 CALL Define

 z&=x%*y%
 Lumptr=Colourptr&+(2*z&)
 rd&=Colourptr&+Framesize2&+z&
 gn&=Colourptr&+Framesize3&+z&
 bl&=Colourptr&+Framesize4&+z&

 Lumval% = @Lumptr
 IF Lumval%<0 THEN Lum&=Lumval%+65536 ELSE Lum&=Lumval%
 '@Lumptr = -1
 red? = PEEK(rd&)
 green?=PEEK(gn&)
 blue?= PEEK(bl&)

 'MSGBOX STR$(x%)+STR$(y%)+" Luminance="+STR$(Lum&)+" red="+STR$(red?)+" green="+STR$(green?)+" blue="+STR$(blue?)

END SUB

SUB antialias (BYVAL Colourptr&, BYVAL hsize&, BYVAL vsize&) EXPORT

 Radius%=2

 CALL Define

 DIM Redbuffer(Framesize&) AS BYTE
 DIM Greenbuffer(Framesize&) AS BYTE
 DIM Bluebuffer(Framesize&) AS BYTE

 DIM Redbufferptr AS BYTE PTR
 DIM Greenbufferptr AS BYTE PTR
 DIM Bluebufferptr AS BYTE PTR

 DIM Redptr1 AS BYTE PTR
 DIM Greenptr1 AS BYTE PTR
 DIM Blueptr1 AS BYTE PTR
 DIM Redptr2 AS BYTE PTR
 DIM Greenptr2 AS BYTE PTR
 DIM Blueptr2 AS BYTE PTR


 DIM Redstartpointer AS BYTE PTR
 DIM Redwinpointer AS BYTE PTR
 DIM Redwinstartpointer AS BYTE PTR
 DIM Redoutstartpointer AS BYTE PTR

 DIM Greenstartpointer AS BYTE PTR
 DIM Greenwinpointer AS BYTE PTR
 DIM Greenwinstartpointer AS BYTE PTR
 DIM Greenoutstartpointer AS BYTE PTR

 DIM Bluestartpointer AS BYTE PTR
 DIM Bluewinpointer AS BYTE PTR
 DIM Bluewinstartpointer AS BYTE PTR
 DIM Blueoutstartpointer AS BYTE PTR

 Redbufferptr=VARPTR(Redbuffer(0))
 Greenbufferptr=VARPTR(Greenbuffer(0))
 Bluebufferptr=VARPTR(Bluebuffer(0))

   imsize& = Framesize&
   linelength% = Linesize&
   linecount% = 580
   pxcount% = Linesize&
   pxcount2% = 753

 POKE$ Redbufferptr, PEEK$ (Colourptr&+Framesize2&,imsize&)         'copy red image to buffer
 POKE$ Greenbufferptr, PEEK$ (Colourptr&+Framesize3&,imsize&)      'copy green image to buffer
 POKE$ Bluebufferptr, PEEK$ (Colourptr&+Framesize4&,imsize&)       'copy blue image to buffer

 Startrow% = Radius%                                            'first pixel in line
 Endrow% = linelength% - Radius%                                'last pixel in line
 Startline% = Radius% + 9                                       'first line
 Endline% = linecount% - Radius%                                'last line
 Kerncount% = 2*Radius% + 1                                     'window width / height
 Kernarea% = Kerncount% ^2                                      'number of pixels in window

 Redwinstartpointer = Redbufferptr                                'top left corner of window
 Redptr1 = Colourptr&+Framesize2& + Radius%*pxcount% + Radius%*2       'location of first pixel for processing
 Redptr2 = Redbufferptr + Radius%*pxcount% + Radius%*2            'first pixel in input array
 Redstartpointer = Redptr2                                        'central pixel of input window
 Redoutstartpointer = Redptr1                                     'central pixel of output window

 Greenwinstartpointer = Greenbufferptr                              'top left corner of window
 Greenptr1 = Colourptr&+Framesize3& + Radius%*pxcount% + Radius%*2       'location of first pixel for processing
 Greenptr2 = Greenbufferptr + Radius%*pxcount% + Radius%*2            'first pixel in input array
 Greenstartpointer = Greenptr2                                        'central pixel of input window
 Greenoutstartpointer = Greenptr1                                     'central pixel of output window

 Bluewinstartpointer = Bluebufferptr                                'top left corner of window
 Blueptr1 = Colourptr&+Framesize4& + Radius%*pxcount% + Radius%*2        'location of first pixel for processing
 Blueptr2 = Bluebufferptr + Radius%*pxcount% + Radius%*2            'first pixel in input array
 Bluestartpointer = Blueptr2                                        'central pixel of input window
 Blueoutstartpointer = Blueptr1                                     'central pixel of output window

 FOR z% = Startline% TO Endline%
 FOR w% = Startrow% TO Endrow%

 RedKernel:
 Redkernsum& = 0
 Redcentre? = @Redptr2                                              'central pixel value
 Redwinpointer = Redwinstartpointer                                 'start at top left corner of window
 FOR y% = 1 TO Kerncount%                                           'sum columns of pixels
 FOR x% = 1 TO Kerncount%                                           'sum rows of pixels
 RPV? = @Redwinpointer                                              'get pixel value
 Redkernsum& = Redkernsum& + RPV?                                   'add to total
 INCR Redwinpointer                                                 'next pixel in row
 NEXT x%
 Redwinpointer = Redwinstartpointer + (y%-1)*pxcount%               'next row of window
 NEXT y%
 Redkernsum& = Redkernsum& / Kernarea%
 Redoffset& = Redcentre? - Redkernsum&


 GreenKernel:
 Greenkernsum& = 0
 Greencentre? = @Greenptr2                                         'central pixel value
 Greenwinpointer = Greenwinstartpointer                            'start at top left corner of window
 FOR y% = 1 TO Kerncount%                                          'sum columns of pixels
 FOR x% = 1 TO Kerncount%                                          'sum rows of pixels
 GPV? = @Greenwinpointer                                           'get pixel value
 Greenkernsum& = Greenkernsum& + GPV?                              'add to total
 INCR Greenwinpointer                                              'next pixel in row
 NEXT x%
 Greenwinpointer = Greenwinstartpointer + (y%-1)*pxcount%          'next row of window
 NEXT y%
 Greenkernsum& = Greenkernsum& / Kernarea%
 Greenoffset& = Greencentre? - Greenkernsum&

 BlueKernel:
 Bluekernsum& = 0
 Bluecentre? = @Blueptr2                                          'central pixel value
 Bluewinpointer = Bluewinstartpointer                             'start at top left corner of window
 FOR y% = 1 TO Kerncount%                                         'sum columns of pixels
 FOR x% = 1 TO Kerncount%                                         'sum rows of pixels
 BPV? = @Bluewinpointer                                           'get pixel value
 Bluekernsum& = Bluekernsum& + BPV?                               'add to total
 INCR Bluewinpointer                                              'next pixel in row
 NEXT x%
 Bluewinpointer = Bluewinstartpointer + (y%-1)*pxcount%           'next row of window
 NEXT y%
 Bluekernsum& = Bluekernsum& / Kernarea%
 Blueoffset& = Bluecentre? - Bluekernsum&

  RG!=Redcentre?/Redoffset&
  BG!=Bluecentre?/Blueoffset&

 IF ABS(RG!) < 4 THEN Redcentre?=128: Greencentre?=128: Bluecentre?=128
 IF ABS(BG!) < 4 THEN Redcentre?=128: Greencentre?=128: Bluecentre?=128
 @Redptr1 = Redcentre?
 @Greenptr1 = Greencentre?
 @Blueptr1 = Bluecentre?

 INCR Redptr1                                                   'next pixel in output image
 INCR Redptr2                                                   'next pixel in source image
 INCR Redwinstartpointer
 INCR Greenptr1                                                 'next pixel in output image
 INCR Greenptr2                                                 'next pixel in source image
 INCR Greenwinstartpointer
 INCR Blueptr1                                                  'next pixel in output image
 INCR Blueptr2                                                  'next pixel in source image
 INCR Bluewinstartpointer
 NEXT w%

 Redoutstartpointer = Redoutstartpointer + pxcount%
 Redstartpointer = Redstartpointer + pxcount%
 Redwinstartpointer = Redstartpointer - Radius%*pxcount2%
 Redptr1 = Redoutstartpointer                                     'central pixel address in output image
 Redptr2 = Redstartpointer

 Greenoutstartpointer = Greenoutstartpointer + pxcount%
 Greenstartpointer = Greenstartpointer + pxcount%
 Greenwinstartpointer = Greenstartpointer - Radius%*pxcount2%
 Greenptr1 = Greenoutstartpointer                                 'central pixel address in output image
 Greenptr2 = Greenstartpointer

 Blueoutstartpointer = Blueoutstartpointer + pxcount%
 Bluestartpointer = Bluestartpointer + pxcount%
 Bluewinstartpointer = Bluestartpointer - Radius%*pxcount2%
 Blueptr1 = Blueoutstartpointer                                   'central pixel address in output image
 Blueptr2 = Bluestartpointer                                      'central pixel address in input image
 NEXT z%

END SUB


SUB colourimagesave(filestring$, BYVAL Colourptr&) EXPORT
OPEN filestring$ FOR BINARY AS #1
PUT$ #1,PEEK$(Colourptr&,2180810)
CLOSE #1
END SUB

SUB colourimageload(filestring$, BYVAL Colourptr&) EXPORT
DIM Temp AS STRING
OPEN filestring$ FOR BINARY AS #1
FOR x%=1 TO 100
GET$ #1, 21808, Temp$
POKE$ Colourptr&, Temp$
Colourptr&=Colourptr&+21808
NEXT x%
CLOSE #1
END SUB

SUB Merge (BYVAL Colourptr&, BYVAL Colourptr2&, BYVAL Average%, BYVAL xshift%, BYVAL yshift%) EXPORT
  DIM Imp1 AS INTEGER PTR
  DIM Imp2 AS INTEGER PTR
  DIM Imp3 AS BYTE PTR
  DIM Imp4 AS BYTE PTR

  CALL Define

  Imp1=Colourptr&
  Imp2=Colourptr2&
  x2%=xshift%
  y2%=yshift%
  FOR y%=1 TO 580
      FOR x%=1 TO Linesize&
          pix1%=@Imp1
          Imp2=Colourptr2&+(x2%*2)+(y2%*Linesize2&)
          IF x2%>Linesize& THEN GOTO noadd
          IF y2%>580 THEN GOTO noadd
          IF x2%<1 THEN GOTO noadd
          IF y2%<1 THEN GOTO noadd
          pix2%=@Imp2
          IF pix1%<0 THEN p1&=pix1%+65536 ELSE p1&=pix1%
          IF pix2%<0 THEN p2&=pix2%+65536 ELSE p2&=pix2%
          IF Average%=1 THEN p3&=(p1&+p2&)/2 ELSE p3&=p1&+p2&
          IF p3&>65535 THEN p3&=65535
          IF p3&>32676 THEN pix1%=p3&-65536 ELSE pix1%=p3&
          @Imp1=pix1%
noadd:
          INCR Imp1
          INCR x2%
      NEXT x%
      x2%=xshift%
      INCR y2%
  NEXT y%

  Imp3=Colourptr&+Framesize2&
  Imptr4&=Colourptr2&+Framesize2&
  FOR z%=0 TO 2
      Imp3=Colourptr&+Framesize2&+(z%*Framesize&)
      Imptr4&=Colourptr2&+Framesize2&+(z%*Framesize&)
        x2%=xshift%
        y2%=yshift%
  FOR y%=1 TO 580
      FOR x%=1 TO Linesize&
          pix3?=@Imp3
          Imp4=Imptr4&+x2%+(y2%*Linesize&)
          IF x2%>Linesize& THEN GOTO noadd2
          IF y2%>580 THEN GOTO noadd2
          IF x2%<1 THEN GOTO noadd2
          IF y2%<1 THEN GOTO noadd2
          pix4?=@Imp4
          IF Average%=1 THEN p3&=(p1&+p2&)/2 ELSE p3&=p1&+p2&
          IF p3&>255 THEN p3&=255
          pix3?=p3&
          @Imp3=pix3?
          pix4?=@Imp4
          p3&=(pix3?+pix4?)/2
          IF p3&>255 THEN p3&=255
          pix3?=p3&
          @Imp3=pix3?
noadd2:
          INCR Imp3
          INCR x2%
      NEXT x%
      x2%=xshift%
      INCR y2%
  NEXT y%
NEXT z%

END SUB

'************************************************************************************* RGB synthesis

SUB intcolsynth2 (BYVAL Colourptr&, BYVAL Imptr&, BYVAL hsize&, BYVAL vsize&, BYVAL cs&, BYVAL colourbal%, Dirpath$) EXPORT

Imptr1&=Imptr&

DIM Lumval&                                     'luminance value storage variable
DIM Lumptr AS INTEGER PTR
DIM Redptr AS BYTE PTR
DIM Grnptr AS BYTE PTR
DIM Bluptr AS BYTE PTR
DIM Imageptr1 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr2 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr3 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr4 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr5 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr6 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr7 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr8 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr9 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr10 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr11 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr12 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr13 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr14 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr15 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr16 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr17 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr18 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr19 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr20 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr21 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr22 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr23 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr24 AS INTEGER PTR                                                     'pointer to source image
DIM Imageptr25 AS INTEGER PTR                                                     'pointer to source image

Lumptr=Colourptr&+hsize&*4+2                                                      'pointers to colour array
Redptr=Colourptr&+hsize&*vsize&*2+hsize&*2+2
Grnptr=Colourptr&+hsize&*vsize&*3+hsize&*2+2
Bluptr=Colourptr&+hsize&*vsize&*4+hsize&*2+2
Imageptr1=Imptr1&
Imageptr2=Imptr1&+2
Imageptr3=Imptr1&+4
Imageptr4=Imptr1&+6
Imageptr5=Imptr1&+8
Imageptr6=Imptr1&+hsize&*2
Imageptr7=Imptr1&+hsize&*2+2
Imageptr8=Imptr1&+hsize&*2+4
Imageptr9=Imptr1&+hsize&*2+6
Imageptr10=Imptr1&+hsize&*2+8
Imageptr11=Imptr1&+hsize&*4
Imageptr12=Imptr1&+hsize&*4+2
Imageptr13=Imptr1&+hsize&*4+4
Imageptr14=Imptr1&+hsize&*4+6
Imageptr15=Imptr1&+hsize&*4+8
Imageptr16=Imptr1&+hsize&*6
Imageptr17=Imptr1&+hsize&*6+2
Imageptr18=Imptr1&+hsize&*6+4
Imageptr19=Imptr1&+hsize&*6+6
Imageptr20=Imptr1&+hsize&*6+8
Imageptr21=Imptr1&+hsize&*8
Imageptr22=Imptr1&+hsize&*8+2
Imageptr23=Imptr1&+hsize&*8+4
Imageptr24=Imptr1&+hsize&*8+6
Imageptr25=Imptr1&+hsize&*8+8


BB%=0: CC%=1                                  'pixel and line offsets

FOR y&=2 TO vsize&-3

FOR x&=1 TO hsize&

A%= @Imageptr1                                  'get pixel values as signed integers
B%= @Imageptr2
C%= @Imageptr3
D%= @Imageptr4
E%= @Imageptr5
F%= @Imageptr6
G%= @Imageptr7
H%= @Imageptr8
I%= @Imageptr9
J%= @Imageptr10
K%= @Imageptr11
L%= @Imageptr12
M%= @Imageptr13
N%= @Imageptr14
O%= @Imageptr15
P%= @Imageptr16
Q%= @Imageptr17
R%= @Imageptr18
S%= @Imageptr19
T%= @Imageptr20
U%= @Imageptr21
V%= @Imageptr22
W%= @Imageptr23
X%= @Imageptr24
Y%= @Imageptr25

INCR Imageptr1
INCR Imageptr2
INCR Imageptr3
INCR Imageptr4
INCR Imageptr5
INCR Imageptr6
INCR Imageptr7
INCR Imageptr8
INCR Imageptr9
INCR Imageptr10
INCR Imageptr11
INCR Imageptr12
INCR Imageptr13
INCR Imageptr14
INCR Imageptr15
INCR Imageptr16
INCR Imageptr17
INCR Imageptr18
INCR Imageptr19
INCR Imageptr20
INCR Imageptr21
INCR Imageptr22
INCR Imageptr23
INCR Imageptr24
INCR Imageptr25

IF A%<0 THEN P1&=A%+65536 ELSE P1&=A%                           'normalise to long integers
IF B%<0 THEN P2&=B%+65536 ELSE P2&=B%
IF C%<0 THEN P3&=C%+65536 ELSE P3&=C%
IF D%<0 THEN P4&=D%+65536 ELSE P4&=D%
IF E%<0 THEN P5&=E%+65536 ELSE P5&=E%
IF F%<0 THEN P6&=F%+65536 ELSE P6&=F%
IF G%<0 THEN P7&=G%+65536 ELSE P7&=G%
IF H%<0 THEN P8&=H%+65536 ELSE P8&=H%
IF I%<0 THEN P9&=I%+65536 ELSE P9&=I%
IF J%<0 THEN P10&=J%+65536 ELSE P10&=J%
IF K%<0 THEN P11&=K%+65536 ELSE P11&=K%
IF L%<0 THEN P12&=L%+65536 ELSE P12&=L%
IF M%<0 THEN P13&=M%+65536 ELSE P13&=M%                         'Centre pixel
IF N%<0 THEN P14&=N%+65536 ELSE P14&=N%
IF O%<0 THEN P15&=O%+65536 ELSE P15&=O%
IF P%<0 THEN P16&=P%+65536 ELSE P16&=P%
IF Q%<0 THEN P17&=Q%+65536 ELSE P17&=Q%
IF R%<0 THEN P18&=R%+65536 ELSE P18&=R%
IF S%<0 THEN P19&=S%+65536 ELSE P19&=S%
IF T%<0 THEN P20&=T%+65536 ELSE P20&=T%
IF U%<0 THEN P21&=U%+65536 ELSE P21&=U%
IF V%<0 THEN P22&=V%+65536 ELSE P22&=V%
IF W%<0 THEN P23&=W%+65536 ELSE P23&=W%
IF X%<0 THEN P24&=X%+65536 ELSE P24&=X%
IF Y%<0 THEN P25&=Y%+65536 ELSE P25&=Y%

'Luminance calculations:

IF CC%=0 THEN                                                              'CC% is line switch
IF BB%=0 THEN Lumval&=((P7&+P8&+P9&+P12&+P14&+P17&+P18&+P19&)/4) + P13&      'synthesise 16 bit luminance value for red pixel
IF BB%=1 THEN Lumval&=((P8&+P12&+P14&+P18&)/2) + P13&                        'Green pixel - BB% is pixel switch
END IF

IF CC%=1 THEN
IF BB%=0 THEN Lumval&=((P8&+P12&+P14&+P18&)/2) + P13&                         'Green pixel
IF BB%=1 THEN Lumval&=((P7&+P8&+P9&+P12&+P14&+P17&+P18&+P19&)/4) + P13&      'synthesise 16 bit luminance value for blue pixel
END IF

Lumval&=Lumval&/3                                                 'correct for gain error
IF Lumval&>65535 THEN Lumval&=65535

'Chrominance calculations:
'synthesise colour values
IF CC%=0 THEN
IF BB%=0 THEN RD&=((P3&+P11&+P15&+P23&)/8)+(P13&/2): GR&=(P8&+P12&+P14&+P18&)/4: BL&=(P7&+P9&+P17&+P19&)/4  'red in centre
IF BB%=1 THEN RD&=(P2&+P4&+P12&+P14&+P22&+P24&)/6: GR&=((P7&+P9&+P17&+P19&)/8)+(P13&/2): BL&=(P6&+P8&+P10&+P16&+P18&+P20&)/6 'green in centre, red row
END IF

IF CC%=1 THEN
IF BB%=0 THEN BL&=(P2&+P4&+P12&+P14&+P22&+P24&)/6: GR&=((P7&+P9&+P17&+P19&)/8)+(P13&/2): RD&=(P6&+P8&+P10&+P16&+P18&+P20&)/6 'green in centre, blue row
IF BB%=1 THEN BL&=((P3&+P11&+P15&+P23&)/8)+(P13&/2): GR&=(P8&+P12&+P14&+P18&)/4: RD&=(P7&+P9&+P17&+P19&)/4  'blue in centre, blue row
END IF


'if y&=500 then
'if x&=500 then msgbox "RD&="+str$(RD&)+", GR&="+str$(GR&)+", BL&="+str$(BL&)
'end if
Rdiv%=40: Gdiv%=44: Bdiv%=35
IF colourbal%=2 THEN Rdiv%=42: Gdiv%=44: Bdiv%=27
IF colourbal%=7 THEN Rdiv%=40: Gdiv%=44: Bdiv%=33
RED&=RD&\Rdiv%                                  'adjust colour results for preset balance
'RED&=RED&*30
GRN&=GR&\Gdiv%
'GRN&=GRN&*30
BLU&=BL&\Bdiv%
'BLU&=BLU&*30

IF RED&>65535 THEN RED&=65535
IF GRN&>65535 THEN GRN&=65535
IF BLU&>65535 THEN BLU&=65535


BLU&=BLU&\cs&
GRN&=GRN&\cs&
RED&=RED&\cs&

IF BLU&>GRN& THEN IF BLU&>RED& THEN cm&=1   'blue is max.
IF GRN&>BLU& THEN IF GRN&>RED& THEN cm&=2   'green is max.
IF RED&>GRN& THEN IF RED&>BLU& THEN cm&=3   'red is max.
IF GRN&>RED& THEN IF GRN&>BLU& THEN cm&=2   'green is max.
IF BLU&>RED& THEN IF BLU&>GRN& THEN cm&=1   'blue is max.
IF RED&>BLU& THEN IF RED&>GRN& THEN cm&=3   'red is max.

'IF cm&=1 THEN ct&=BLU&/254: IF BLU&>254 THEN BLU&=BLU&/ct&:GRN&=GRN&/ct&:RED&=RED&/ct&
'IF cm&=2 THEN ct&=GRN&/254: IF GRN&>254 THEN BLU&=BLU&/ct&:GRN&=GRN&/ct&:RED&=RED&/ct&
'IF cm&=3 THEN ct&=RED&/254: IF RED&>254 THEN BLU&=BLU&/ct&:GRN&=GRN&/ct&:RED&=RED&/ct&

IF BLU&<255 THEN Blu?=BLU& ELSE Blu?=255
IF GRN&<255 THEN Grn?=GRN& ELSE Grn?=255
IF RED&<255 THEN Red?=RED& ELSE Red?=255

'IF Red?=254 THEN Gx?=Grn?: Bx?=Blu?
'IF Grn?=254 THEN Bx?=Blu?: Rx?=Red?
'IF Blu?=254 THEN Gx?=Grn?: Rx?=Red?

'IF Red?=255 THEN Grn?=Gx?: Blu?=Bx?
'IF Grn?=255 THEN Red?=Rx?: Blu?=Bx?
'IF Blu?=255 THEN Red?=Rx?: Grn?=Gx?

meangrey&=(Red?+Grn?+Blu?)\3
'IF Lumval&>64000 THEN Red?=meangrey&: Grn?=meangrey&: Blu?=meangrey&        'greyscale if saturated
IF Lumval&>32767 THEN luminance%=Lumval&-65536 ELSE luminance%=Lumval&      'convert luminance back to signed integers

'IF y&=500 THEN
'IF x&=500 THEN MSGBOX "RED?="+STR$(RED?)+", Grn?="+STR$(Grn?)+", Blu?="+STR$(Blu?)
'END IF

'Lumval&=Lumval&\255
'if Lumval&>255 then Lumval&=255
'Lm?=Lumval&
@Lumptr=luminance%
INCR Lumptr
@Redptr= Red?
INCR Redptr
@Grnptr= Grn?
INCR Grnptr
@Bluptr= Blu?
INCR Bluptr

INCR BB%: IF BB%=2 THEN BB%=0
NEXT x&

INCR CC%: IF CC%=2 THEN CC%=0
NEXT y&

END SUB

SUB colourstretcher2(BYVAL Minimum%, BYVAL Maximum%, BYVAL Colptr&, BYVAL hsize&, BYVAL vsize&) EXPORT
 DIM Table?(0 TO 255)
 DIM Databyte?
 Dataptr&=VARPTR(Databyte?)

 Range!= 255/(Maximum% - Minimum%)          'Generate lookup table
 FOR x&=0 TO Minimum%: Table?(x&)=0: NEXT x&
 FOR x&= Minimum% TO 255 'Maximum%
 a&=x&-Minimum%
 'a&=(x&-Minimum%)*Range!
 Table?(x&)=a&
 NEXT x&
 'FOR x&= Maximum% TO 255
 'Table?(x&)=255: NEXT x&

 FOR x&=1 TO hsize&*vsize&                              'Modify image
 POKE Dataptr&, PEEK (Colptr&)
 Databyte?= Table?(Databyte?)
 POKE Colptr&, PEEK (Dataptr&)
 INCR Colptr&
 NEXT x&

END SUB

SUB Coloursmooth (BYVAL Imptr1&, BYVAL Imptr2&, BYVAL hsize&, BYVAL vsize&) EXPORT

 DIM Pointer1 AS BYTE PTR
 DIM Pointer2 AS BYTE PTR
 DIM Startpointer AS BYTE PTR
 DIM Winpointer AS BYTE PTR
 DIM Winstartpointer AS BYTE PTR
 DIM Outstartpointer AS BYTE PTR
 DIM Med&(25)

   imsize& = hsize&*vsize&
   linelength% = hsize&
   linecount% = vsize&
   pxcount% = hsize&
   pxcount2% = hsize&+1
   Radius% = 3

 POKE$ Imptr2&, PEEK$ (Imptr1&,imsize&)                         'copy image to buffer

 Startrow% = Radius%                                            'first pixel in line
 Endrow% = linelength% - Radius%                                'last pixel in line
 Startline% = Radius% + 9                                       'first line
 Endline% = linecount% - Radius%                                'last line
 Kerncount% = 2*Radius% + 1                                     'window width / height
 Kernarea% = Kerncount% ^2                                      'number of pixels in window

 Winstartpointer = Imptr2&                                      'top left corner of window
 Pointer1 = Imptr1& + Radius%*pxcount% + Radius%                'location of first pixel for processing
 Pointer2 = Imptr2& + Radius%*pxcount% + Radius%
 Startpointer = Pointer2                                        'central pixel of input window
 Outstartpointer = Pointer1-pxcount%                            'central pixel of output window


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
