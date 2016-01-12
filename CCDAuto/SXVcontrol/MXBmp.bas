
'---------------------------------------
'
'   Universal MXBmp.BAS  For PB/DLL
'   Copyright (c) 2004 TERRY PLATT
'
'---------------------------------------

$COMPILE DLL "MXBMP.DLL"

GLOBAL Table&()

SUB Finderbmpgen(BYVAL Imptr1&, BYVAL Bmpptr&, BYVAL hsize&, BYVAL vsize&, BYVAL St%, Buffer$) EXPORT         'bin 4x4 screen view
DIM Impt AS INTEGER PTR
DIM Impt2 AS INTEGER PTR
DIM Bmpt AS BYTE PTR
DIM Table2&(65535)
Bmpt=Bmpptr&
Impt=Imptr1&
hsize&=hsize&/4
hd!=hsize&/4
hf&=FIX(hsize&/4)
hpad%=4-INT((hd!-hf&)*4)

vsize&=FIX(vsize&/4)

IF St%=1 THEN
FOR y%=1 TO vsize&
FOR x%=1 TO hsize&
imdata%=@Impt
IF imdata%<0 THEN dat&=imdata%+65536 ELSE dat&=imdata%          'scan image for pixel values
Table2&(dat&)= Table2&(dat&)+1
INCR Impt
NEXT x%
NEXT y%
maxval&=0
FOR z&=1 TO 40000
dat&=Table2&(z&)
IF dat&>maxval& THEN maxval&=dat&: q&=z&                       'find most common value
NEXT z&
maxval&=q& * 0.97
b%=32
ELSE
maxval&=0: b%=1
END IF

Bmpt=Bmpptr&
Impt2=Imptr1&+((vsize&-1)*hsize&*2)
OPEN Buffer$ FOR BINARY AS #1
Seek#1,0
@Bmpt=66: INCR Bmpt: @Bmpt=77: INCR Bmpt
sizebytes&=vsize&*hsize&+1078                                                             'get file size in bytes
b4&=FIX(sizebytes&/16777216)
sizebytes&=sizebytes&-b4&*16777216
b3&=FIX(sizebytes&/65536)
sizebytes&=sizebytes&-b3&*65536
b2&=FIX(sizebytes&/256)
sizebytes&=sizebytes&-b2&*256
b1&=sizebytes&
@Bmpt=b1&: INCR Bmpt: @Bmpt=b2&: INCR Bmpt: @Bmpt=b3&: INCR Bmpt: @Bmpt=b4&: INCR Bmpt    'file size
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt
@Bmpt=54: INCR Bmpt: @Bmpt=4: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt           'header size (1078)
@Bmpt=40: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt           'BITMAPINFOHEADER size
widthpix&=hsize&
w4&=FIX(widthpix&/16777216)
widthpix&=widthpix&-w4&*16777216
w3&=FIX(widthpix&/65536)
widthpix&=widthpix&-w3&*65536
w2&=FIX(widthpix&/256)
widthpix&=widthpix&-w2&*256
w1&=widthpix&
@Bmpt=w1&: INCR Bmpt: @Bmpt=w2&: INCR Bmpt: @Bmpt=w3&: INCR Bmpt: @Bmpt=w4&: INCR Bmpt    'image width in pixels
heightpix&=vsize&
h4&=FIX(heightpix&/16777216)
heightpix&=heightpix&-h4&*16777216
h3&=FIX(heightpix&/65536)
heightpix&=heightpix&-h3&*65536
h2&=FIX(heightpix&/256)
heightpix&=heightpix&-h2&*256
h1&=heightpix&
@Bmpt=h1&: INCR Bmpt: @Bmpt=h2&: INCR Bmpt: @Bmpt=h3&: INCR Bmpt: @Bmpt=h4&: INCR Bmpt    'image height in pixels
@Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt                                                    'image planes
@Bmpt=8: INCR Bmpt: @Bmpt=0: INCR Bmpt                                                    'bits per pixel
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'compression type
sizebytes&=vsize&*hsize&                                                                  'get image size in bytes
b4&=FIX(sizebytes&/16777216)
sizebytes&=sizebytes&-b4&*16777216
b3&=FIX(sizebytes&/65536)
sizebytes&=sizebytes&-b3&*65536
b2&=FIX(sizebytes&/256)
sizebytes&=sizebytes&-b2&*256
b1&=sizebytes&
@Bmpt=b1&: INCR Bmpt: @Bmpt=b2&: INCR Bmpt: @Bmpt=b3&: INCR Bmpt: @Bmpt=b4&: INCR Bmpt    'image size
@Bmpt=19: INCR Bmpt: @Bmpt=11: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt          'horizontal pixels per metre
@Bmpt=19: INCR Bmpt: @Bmpt=11: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt          'vertical pixels per metre
@Bmpt=0: INCR Bmpt: @Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'number of colours
@Bmpt=0: INCR Bmpt: @Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'number of important colours
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt

FOR x&=1 TO 1020
d%=VAL(READ$(x&))
@Bmpt=d%
INCR Bmpt
NEXT x&
FOR y&=1 TO vsize&
FOR x&=1 TO hsize&
dat&=@Impt2
IF dat&<0 THEN dat&=dat&+65536
dat&=(dat&-maxval&)*b%                                            'remove background level
IF dat&<0 THEN dat&=0
IF dat&>65535 THEN dat&=65535                                      'multiply by 256
dat&=dat&/257
dt?=dat&
@Bmpt=dt?
INCR Bmpt
INCR Impt2
NEXT x&
IF hpad%=1 THEN @Bmpt=0: INCR Bmpt
IF hpad%=2 THEN @Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt
IF hpad%=3 THEN @Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt
'for n%=0 to hpad%: @Bmpt=0: INCR Bmpt: next n%

Impt2=Impt2-(hsize&*4)
NEXT y&

PUT$ #1, PEEK$(Bmpptr&,(hsize&+2)*vsize&+1078)
CLOSE #1


DATA 1,1,1,0,2,2,2,0,3,3,3,0,4,4,4,0,5,5,5,0,6,6,6,0,7,7,7,0,8,8,8,0,9,9,9,0
DATA 10,10,10,0,11,11,11,0,12,12,12,0,13,13,13,0,14,14,14,0,15,15,15,0,16,16,16,0,17,17,17,0
DATA 18,18,18,0,19,19,19,0,20,20,20,0,21,21,21,0,22,22,22,0,23,23,23,0,24,24,24,0,25,25,25,0
DATA 26,26,26,0,27,27,27,0,28,28,28,0,29,29,29,0,30,30,30,0,31,31,31,0,32,32,32,0,33,33,33,0
DATA 34,34,34,0,35,35,35,0,36,36,36,0,37,37,37,0,38,38,38,0,39,39,39,0,40,40,40,0,41,41,41,0
DATA 42,42,42,0,43,43,43,0,44,44,44,0,45,45,45,0,46,46,46,0,47,47,47,0,48,48,48,0,49,49,49,0
DATA 50,50,50,0,51,51,51,0,52,52,52,0,53,53,53,0,54,54,54,0,55,55,55,0,56,56,56,0,57,57,57,0
DATA 58,58,58,0,59,59,59,0,60,60,60,0,61,61,61,0,62,62,62,0,63,63,63,0,64,64,64,0,65,65,65,0
DATA 66,66,66,0,67,67,67,0,68,68,68,0,69,69,69,0,70,70,70,0,71,71,71,0,72,72,72,0,73,73,73,0
DATA 74,74,74,0,75,75,75,0,76,76,76,0,77,77,77,0,78,78,78,0,79,79,79,0,80,80,80,0,81,81,81,0
DATA 82,82,82,0,83,83,83,0,84,84,84,0,85,85,85,0,86,86,86,0,87,87,87,0,88,88,88,0,89,89,89,0
DATA 90,90,90,0,91,91,91,0,92,92,92,0,93,93,93,0,94,94,94,0,95,95,95,0,96,96,96,0,97,97,97,0
DATA 98,98,98,0,99,99,99,0,100,100,100,0,101,101,101,0,102,102,102,0,103,103,103,0,104,104,104,0
DATA 105,105,105,0,106,106,106,0,107,107,107,0,108,108,108,0,109,109,109,0,110,110,110,0
DATA 111,111,111,0,112,112,112,0,113,113,113,0,114,114,114,0,115,115,115,0,116,116,116,0
DATA 117,117,117,0,118,118,118,0,119,119,119,0,120,120,120,0,121,121,121,0,122,122,122,0
DATA 123,123,123,0,124,124,124,0,125,125,125,0,126,126,126,0,127,127,127,0,128,128,128,0
DATA 129,129,129,0,130,130,130,0,131,131,131,0,132,132,132,0,133,133,133,0,134,134,134,0
DATA 135,135,135,0,136,136,136,0,137,137,137,0,138,138,138,0,139,139,139,0,140,140,140,0
DATA 141,141,141,0,142,142,142,0,143,143,143,0,144,144,144,0,145,145,145,0,146,146,146,0
DATA 147,147,147,0,148,148,148,0,149,149,149,0,150,150,150,0,151,151,151,0,152,152,152,0
DATA 153,153,153,0,154,154,154,0,155,155,155,0,156,156,156,0,157,157,157,0,158,158,158,0
DATA 159,159,159,0,160,160,160,0,161,161,161,0,162,162,162,0,163,163,163,0,164,164,164,0
DATA 165,165,165,0,166,166,166,0,167,167,167,0,168,168,168,0,169,169,169,0,170,170,170,0
DATA 171,171,171,0,172,172,172,0,173,173,173,0,174,174,174,0,175,175,175,0,176,176,176,0
DATA 177,177,177,0,178,178,178,0,179,179,179,0,180,180,180,0,181,181,181,0,182,182,182,0
DATA 183,183,183,0,184,184,184,0,185,185,185,0,186,186,186,0,187,187,187,0,188,188,188,0
DATA 189,189,189,0,190,190,190,0,191,191,191,0,192,192,192,0,193,193,193,0,194,194,194,0
DATA 195,195,195,0,196,196,196,0,197,197,197,0,198,198,198,0,199,199,199,0,200,200,200,0
DATA 201,201,201,0,202,202,202,0,203,203,203,0,204,204,204,0,205,205,205,0,206,206,206,0
DATA 207,207,207,0,208,208,208,0,209,209,209,0,210,210,210,0,211,211,211,0,212,212,212,0
DATA 213,213,213,0,214,214,214,0,215,215,215,0,216,216,216,0,217,217,217,0,218,218,218,0
DATA 219,219,219,0,220,220,220,0,221,221,221,0,222,222,222,0,223,223,223,0,224,224,224,0
DATA 225,225,225,0,226,226,226,0,227,227,227,0,228,228,228,0,229,229,229,0,230,230,230,0
DATA 231,231,231,0,232,232,232,0,233,233,233,0,234,234,234,0,235,235,235,0,236,236,236,0
DATA 237,237,237,0,238,238,238,0,239,239,239,0,240,240,240,0,241,241,241,0,242,242,242,0
DATA 243,243,243,0,244,244,244,0,245,245,245,0,246,246,246,0,247,247,247,0,248,248,248,0
DATA 249,249,249,0,250,250,250,0,251,251,251,0,252,252,252,0,253,253,253,0,254,254,254,0
DATA 255,255,255,0

END SUB

SUB zoombmpgen(BYVAL Imptr1&, BYVAL Bmpptr&, BYVAL hsize&, BYVAL vsize&, BYVAL St%, Buffer$) EXPORT
DIM Impt AS INTEGER PTR
DIM Impt2 AS INTEGER PTR
DIM Bmpt AS BYTE PTR
DIM Table2&(65535)
Bmpt=Bmpptr&
Impt=Imptr1&
hsize&=hsize&/4
hd!=hsize&/4
hf&=FIX(hsize&/4)
hpad%=INT((hd!-hf&)*4)

vsize&=FIX(vsize&/4)

IF St%=1 THEN
FOR y%=1 TO vsize&*2+1
FOR x%=1 TO hsize&*4
imdata%=@Impt
IF imdata%<0 THEN dat&=imdata%+65536 ELSE dat&=imdata%          'scan image for pixel values
Table2&(dat&)= Table2&(dat&)+1
INCR Impt
NEXT x%
NEXT y%
maxval&=0
FOR z&=1 TO 40000
dat&=Table2&(z&)
IF dat&>maxval& THEN maxval&=dat&: q&=z&                       'find most common value
NEXT z&
maxval&=q& * 0.97
b%=32
ELSE
maxval&=0: b%=1
END IF

Bmpt=Bmpptr&
Impt2=Imptr1&+(((vsize&*4+2)-1)*hsize&*4*2)
OPEN Buffer$ FOR BINARY AS #1
Seek#1,0
@Bmpt=66: INCR Bmpt: @Bmpt=77: INCR Bmpt
sizebytes&=vsize&*hsize&+1078                                                             'get file size in bytes
b4&=FIX(sizebytes&/16777216)
sizebytes&=sizebytes&-b4&*16777216
b3&=FIX(sizebytes&/65536)
sizebytes&=sizebytes&-b3&*65536
b2&=FIX(sizebytes&/256)
sizebytes&=sizebytes&-b2&*256
b1&=sizebytes&
@Bmpt=b1&: INCR Bmpt: @Bmpt=b2&: INCR Bmpt: @Bmpt=b3&: INCR Bmpt: @Bmpt=b4&: INCR Bmpt    'file size
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt
@Bmpt=54: INCR Bmpt: @Bmpt=4: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt           'header size (1078)
@Bmpt=40: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt           'BITMAPINFOHEADER size
widthpix&=hsize&
w4&=FIX(widthpix&/16777216)
widthpix&=widthpix&-w4&*16777216
w3&=FIX(widthpix&/65536)
widthpix&=widthpix&-w3&*65536
w2&=FIX(widthpix&/256)
widthpix&=widthpix&-w2&*256
w1&=widthpix&
@Bmpt=w1&: INCR Bmpt: @Bmpt=w2&: INCR Bmpt: @Bmpt=w3&: INCR Bmpt: @Bmpt=w4&: INCR Bmpt    'image width in pixels
heightpix&=vsize&
h4&=FIX(heightpix&/16777216)
heightpix&=heightpix&-h4&*16777216
h3&=FIX(heightpix&/65536)
heightpix&=heightpix&-h3&*65536
h2&=FIX(heightpix&/256)
heightpix&=heightpix&-h2&*256
h1&=heightpix&
@Bmpt=h1&: INCR Bmpt: @Bmpt=h2&: INCR Bmpt: @Bmpt=h3&: INCR Bmpt: @Bmpt=h4&: INCR Bmpt    'image height in pixels
@Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt                                                    'image planes
@Bmpt=8: INCR Bmpt: @Bmpt=0: INCR Bmpt                                                    'bits per pixel
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'compression type
sizebytes&=vsize&*hsize&                                                                  'get image size in bytes
b4&=FIX(sizebytes&/16777216)
sizebytes&=sizebytes&-b4&*16777216
b3&=FIX(sizebytes&/65536)
sizebytes&=sizebytes&-b3&*65536
b2&=FIX(sizebytes&/256)
sizebytes&=sizebytes&-b2&*256
b1&=sizebytes&
@Bmpt=b1&: INCR Bmpt: @Bmpt=b2&: INCR Bmpt: @Bmpt=b3&: INCR Bmpt: @Bmpt=b4&: INCR Bmpt    'image size
@Bmpt=19: INCR Bmpt: @Bmpt=11: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt          'horizontal pixels per metre
@Bmpt=19: INCR Bmpt: @Bmpt=11: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt          'vertical pixels per metre
@Bmpt=0: INCR Bmpt: @Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'number of colours
@Bmpt=0: INCR Bmpt: @Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'number of important colours
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt

FOR x&=1 TO 1020
d%=VAL(READ$(x&))
@Bmpt=d%
INCR Bmpt
NEXT x&
FOR y&=1 TO vsize&
FOR x&=1 TO hsize&
dat&=@Impt2
IF dat&<0 THEN dat&=dat&+65536
dat&=(dat&-maxval&)*b%                                            'remove background level
IF dat&<0 THEN dat&=0
IF dat&>65535 THEN dat&=65535                                      'multiply by 256
dat&=dat&/257
dt?=dat&
@Bmpt=dt?
INCR Bmpt
Impt2=Impt2+8
NEXT x&
IF hpad%=1 THEN @Bmpt=0: INCR Bmpt
IF hpad%=2 THEN @Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt
IF hpad%=3 THEN @Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt
'FOR n%=0 TO hpad%: INCR Bmpt: NEXT n%

Impt2=Impt2-(hsize&*4*10)
NEXT y&

PUT$ #1, PEEK$(Bmpptr&,(hsize&+2)*vsize&+1078)
CLOSE #1


DATA 1,1,1,0,2,2,2,0,3,3,3,0,4,4,4,0,5,5,5,0,6,6,6,0,7,7,7,0,8,8,8,0,9,9,9,0
DATA 10,10,10,0,11,11,11,0,12,12,12,0,13,13,13,0,14,14,14,0,15,15,15,0,16,16,16,0,17,17,17,0
DATA 18,18,18,0,19,19,19,0,20,20,20,0,21,21,21,0,22,22,22,0,23,23,23,0,24,24,24,0,25,25,25,0
DATA 26,26,26,0,27,27,27,0,28,28,28,0,29,29,29,0,30,30,30,0,31,31,31,0,32,32,32,0,33,33,33,0
DATA 34,34,34,0,35,35,35,0,36,36,36,0,37,37,37,0,38,38,38,0,39,39,39,0,40,40,40,0,41,41,41,0
DATA 42,42,42,0,43,43,43,0,44,44,44,0,45,45,45,0,46,46,46,0,47,47,47,0,48,48,48,0,49,49,49,0
DATA 50,50,50,0,51,51,51,0,52,52,52,0,53,53,53,0,54,54,54,0,55,55,55,0,56,56,56,0,57,57,57,0
DATA 58,58,58,0,59,59,59,0,60,60,60,0,61,61,61,0,62,62,62,0,63,63,63,0,64,64,64,0,65,65,65,0
DATA 66,66,66,0,67,67,67,0,68,68,68,0,69,69,69,0,70,70,70,0,71,71,71,0,72,72,72,0,73,73,73,0
DATA 74,74,74,0,75,75,75,0,76,76,76,0,77,77,77,0,78,78,78,0,79,79,79,0,80,80,80,0,81,81,81,0
DATA 82,82,82,0,83,83,83,0,84,84,84,0,85,85,85,0,86,86,86,0,87,87,87,0,88,88,88,0,89,89,89,0
DATA 90,90,90,0,91,91,91,0,92,92,92,0,93,93,93,0,94,94,94,0,95,95,95,0,96,96,96,0,97,97,97,0
DATA 98,98,98,0,99,99,99,0,100,100,100,0,101,101,101,0,102,102,102,0,103,103,103,0,104,104,104,0
DATA 105,105,105,0,106,106,106,0,107,107,107,0,108,108,108,0,109,109,109,0,110,110,110,0
DATA 111,111,111,0,112,112,112,0,113,113,113,0,114,114,114,0,115,115,115,0,116,116,116,0
DATA 117,117,117,0,118,118,118,0,119,119,119,0,120,120,120,0,121,121,121,0,122,122,122,0
DATA 123,123,123,0,124,124,124,0,125,125,125,0,126,126,126,0,127,127,127,0,128,128,128,0
DATA 129,129,129,0,130,130,130,0,131,131,131,0,132,132,132,0,133,133,133,0,134,134,134,0
DATA 135,135,135,0,136,136,136,0,137,137,137,0,138,138,138,0,139,139,139,0,140,140,140,0
DATA 141,141,141,0,142,142,142,0,143,143,143,0,144,144,144,0,145,145,145,0,146,146,146,0
DATA 147,147,147,0,148,148,148,0,149,149,149,0,150,150,150,0,151,151,151,0,152,152,152,0
DATA 153,153,153,0,154,154,154,0,155,155,155,0,156,156,156,0,157,157,157,0,158,158,158,0
DATA 159,159,159,0,160,160,160,0,161,161,161,0,162,162,162,0,163,163,163,0,164,164,164,0
DATA 165,165,165,0,166,166,166,0,167,167,167,0,168,168,168,0,169,169,169,0,170,170,170,0
DATA 171,171,171,0,172,172,172,0,173,173,173,0,174,174,174,0,175,175,175,0,176,176,176,0
DATA 177,177,177,0,178,178,178,0,179,179,179,0,180,180,180,0,181,181,181,0,182,182,182,0
DATA 183,183,183,0,184,184,184,0,185,185,185,0,186,186,186,0,187,187,187,0,188,188,188,0
DATA 189,189,189,0,190,190,190,0,191,191,191,0,192,192,192,0,193,193,193,0,194,194,194,0
DATA 195,195,195,0,196,196,196,0,197,197,197,0,198,198,198,0,199,199,199,0,200,200,200,0
DATA 201,201,201,0,202,202,202,0,203,203,203,0,204,204,204,0,205,205,205,0,206,206,206,0
DATA 207,207,207,0,208,208,208,0,209,209,209,0,210,210,210,0,211,211,211,0,212,212,212,0
DATA 213,213,213,0,214,214,214,0,215,215,215,0,216,216,216,0,217,217,217,0,218,218,218,0
DATA 219,219,219,0,220,220,220,0,221,221,221,0,222,222,222,0,223,223,223,0,224,224,224,0
DATA 225,225,225,0,226,226,226,0,227,227,227,0,228,228,228,0,229,229,229,0,230,230,230,0
DATA 231,231,231,0,232,232,232,0,233,233,233,0,234,234,234,0,235,235,235,0,236,236,236,0
DATA 237,237,237,0,238,238,238,0,239,239,239,0,240,240,240,0,241,241,241,0,242,242,242,0
DATA 243,243,243,0,244,244,244,0,245,245,245,0,246,246,246,0,247,247,247,0,248,248,248,0
DATA 249,249,249,0,250,250,250,0,251,251,251,0,252,252,252,0,253,253,253,0,254,254,254,0
DATA 255,255,255,0

END SUB

SUB zoombinbmpgen(BYVAL Imptr1&, BYVAL Bmpptr&, BYVAL hsize&, BYVAL vsize&, BYVAL St%, Buffer$) EXPORT
DIM Impt AS INTEGER PTR
DIM Impt2 AS INTEGER PTR
DIM Bmpt AS BYTE PTR
DIM Table2&(65535)
Bmpt=Bmpptr&
Impt=Imptr1&
hsize&=hsize&/4
hd!=hsize&/4
hf&=FIX(hsize&/4)
hpad%=INT((hd!-hf&)*4)

vsize&=vsize&/4

IF St%=1 THEN
FOR y%=1 TO vsize&*2
FOR x%=1 TO hsize&*4
imdata%=@Impt
IF imdata%<0 THEN dat&=imdata%+65536 ELSE dat&=imdata%          'scan image for pixel values
Table2&(dat&)= Table2&(dat&)+1
INCR Impt
NEXT x%
NEXT y%
maxval&=0
FOR z&=1 TO 40000
dat&=Table2&(z&)
IF dat&>maxval& THEN maxval&=dat&: q&=z&                       'find most common value
NEXT z&
maxval&=q& * 0.97
b%=64
ELSE
maxval&=0: b%=1
END IF

Bmpt=Bmpptr&
Impt2=Imptr1&+((vsize&-1)*hsize&*2)
OPEN Buffer$ FOR BINARY AS #1
Seek#1,0
@Bmpt=66: INCR Bmpt: @Bmpt=77: INCR Bmpt
sizebytes&=vsize&*hsize&+1078                                                             'get file size in bytes
b4&=FIX(sizebytes&/16777216)
sizebytes&=sizebytes&-b4&*16777216
b3&=FIX(sizebytes&/65536)
sizebytes&=sizebytes&-b3&*65536
b2&=FIX(sizebytes&/256)
sizebytes&=sizebytes&-b2&*256
b1&=sizebytes&
@Bmpt=b1&: INCR Bmpt: @Bmpt=b2&: INCR Bmpt: @Bmpt=b3&: INCR Bmpt: @Bmpt=b4&: INCR Bmpt    'file size
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt
@Bmpt=54: INCR Bmpt: @Bmpt=4: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt           'header size (1078)
@Bmpt=40: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt           'BITMAPINFOHEADER size
widthpix&=hsize&
w4&=FIX(widthpix&/16777216)
widthpix&=widthpix&-w4&*16777216
w3&=FIX(widthpix&/65536)
widthpix&=widthpix&-w3&*65536
w2&=FIX(widthpix&/256)
widthpix&=widthpix&-w2&*256
w1&=widthpix&
@Bmpt=w1&: INCR Bmpt: @Bmpt=w2&: INCR Bmpt: @Bmpt=w3&: INCR Bmpt: @Bmpt=w4&: INCR Bmpt    'image width in pixels
heightpix&=vsize&
h4&=FIX(heightpix&/16777216)
heightpix&=heightpix&-h4&*16777216
h3&=FIX(heightpix&/65536)
heightpix&=heightpix&-h3&*65536
h2&=FIX(heightpix&/256)
heightpix&=heightpix&-h2&*256
h1&=heightpix&
@Bmpt=h1&: INCR Bmpt: @Bmpt=h2&: INCR Bmpt: @Bmpt=h3&: INCR Bmpt: @Bmpt=h4&: INCR Bmpt    'image height in pixels
@Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt                                                    'image planes
@Bmpt=8: INCR Bmpt: @Bmpt=0: INCR Bmpt                                                    'bits per pixel
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'compression type
sizebytes&=vsize&*hsize&                                                                  'get image size in bytes
b4&=FIX(sizebytes&/16777216)
sizebytes&=sizebytes&-b4&*16777216
b3&=FIX(sizebytes&/65536)
sizebytes&=sizebytes&-b3&*65536
b2&=FIX(sizebytes&/256)
sizebytes&=sizebytes&-b2&*256
b1&=sizebytes&
@Bmpt=b1&: INCR Bmpt: @Bmpt=b2&: INCR Bmpt: @Bmpt=b3&: INCR Bmpt: @Bmpt=b4&: INCR Bmpt    'image size
@Bmpt=19: INCR Bmpt: @Bmpt=11: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt          'horizontal pixels per metre
@Bmpt=19: INCR Bmpt: @Bmpt=11: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt          'vertical pixels per metre
@Bmpt=0: INCR Bmpt: @Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'number of colours
@Bmpt=0: INCR Bmpt: @Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'number of important colours
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt

FOR x&=1 TO 1020
d%=VAL(READ$(x&))
@Bmpt=d%
INCR Bmpt
NEXT x&
FOR y&=1 TO vsize&
FOR x&=1 TO hsize&
dat&=@Impt2
IF dat&<0 THEN dat&=dat&+65536
dat&=(dat&-maxval&)*b%                                            'remove background level
IF dat&<0 THEN dat&=0
IF dat&>65535 THEN dat&=65535                                      'multiply by 256
dat&=dat&/257
dt?=dat&
@Bmpt=dt?
INCR Bmpt
Impt2=Impt2+2
NEXT x&
IF hpad%=1 THEN @Bmpt=0: INCR Bmpt
IF hpad%=2 THEN @Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt
IF hpad%=3 THEN @Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt
'FOR n%=0 TO hpad%: INCR Bmpt: NEXT n%

Impt2=Impt2-(hsize&*4)
NEXT y&

PUT$ #1, PEEK$(Bmpptr&,(hsize&+2)*vsize&+1078)
CLOSE #1


DATA 1,1,1,0,2,2,2,0,3,3,3,0,4,4,4,0,5,5,5,0,6,6,6,0,7,7,7,0,8,8,8,0,9,9,9,0
DATA 10,10,10,0,11,11,11,0,12,12,12,0,13,13,13,0,14,14,14,0,15,15,15,0,16,16,16,0,17,17,17,0
DATA 18,18,18,0,19,19,19,0,20,20,20,0,21,21,21,0,22,22,22,0,23,23,23,0,24,24,24,0,25,25,25,0
DATA 26,26,26,0,27,27,27,0,28,28,28,0,29,29,29,0,30,30,30,0,31,31,31,0,32,32,32,0,33,33,33,0
DATA 34,34,34,0,35,35,35,0,36,36,36,0,37,37,37,0,38,38,38,0,39,39,39,0,40,40,40,0,41,41,41,0
DATA 42,42,42,0,43,43,43,0,44,44,44,0,45,45,45,0,46,46,46,0,47,47,47,0,48,48,48,0,49,49,49,0
DATA 50,50,50,0,51,51,51,0,52,52,52,0,53,53,53,0,54,54,54,0,55,55,55,0,56,56,56,0,57,57,57,0
DATA 58,58,58,0,59,59,59,0,60,60,60,0,61,61,61,0,62,62,62,0,63,63,63,0,64,64,64,0,65,65,65,0
DATA 66,66,66,0,67,67,67,0,68,68,68,0,69,69,69,0,70,70,70,0,71,71,71,0,72,72,72,0,73,73,73,0
DATA 74,74,74,0,75,75,75,0,76,76,76,0,77,77,77,0,78,78,78,0,79,79,79,0,80,80,80,0,81,81,81,0
DATA 82,82,82,0,83,83,83,0,84,84,84,0,85,85,85,0,86,86,86,0,87,87,87,0,88,88,88,0,89,89,89,0
DATA 90,90,90,0,91,91,91,0,92,92,92,0,93,93,93,0,94,94,94,0,95,95,95,0,96,96,96,0,97,97,97,0
DATA 98,98,98,0,99,99,99,0,100,100,100,0,101,101,101,0,102,102,102,0,103,103,103,0,104,104,104,0
DATA 105,105,105,0,106,106,106,0,107,107,107,0,108,108,108,0,109,109,109,0,110,110,110,0
DATA 111,111,111,0,112,112,112,0,113,113,113,0,114,114,114,0,115,115,115,0,116,116,116,0
DATA 117,117,117,0,118,118,118,0,119,119,119,0,120,120,120,0,121,121,121,0,122,122,122,0
DATA 123,123,123,0,124,124,124,0,125,125,125,0,126,126,126,0,127,127,127,0,128,128,128,0
DATA 129,129,129,0,130,130,130,0,131,131,131,0,132,132,132,0,133,133,133,0,134,134,134,0
DATA 135,135,135,0,136,136,136,0,137,137,137,0,138,138,138,0,139,139,139,0,140,140,140,0
DATA 141,141,141,0,142,142,142,0,143,143,143,0,144,144,144,0,145,145,145,0,146,146,146,0
DATA 147,147,147,0,148,148,148,0,149,149,149,0,150,150,150,0,151,151,151,0,152,152,152,0
DATA 153,153,153,0,154,154,154,0,155,155,155,0,156,156,156,0,157,157,157,0,158,158,158,0
DATA 159,159,159,0,160,160,160,0,161,161,161,0,162,162,162,0,163,163,163,0,164,164,164,0
DATA 165,165,165,0,166,166,166,0,167,167,167,0,168,168,168,0,169,169,169,0,170,170,170,0
DATA 171,171,171,0,172,172,172,0,173,173,173,0,174,174,174,0,175,175,175,0,176,176,176,0
DATA 177,177,177,0,178,178,178,0,179,179,179,0,180,180,180,0,181,181,181,0,182,182,182,0
DATA 183,183,183,0,184,184,184,0,185,185,185,0,186,186,186,0,187,187,187,0,188,188,188,0
DATA 189,189,189,0,190,190,190,0,191,191,191,0,192,192,192,0,193,193,193,0,194,194,194,0
DATA 195,195,195,0,196,196,196,0,197,197,197,0,198,198,198,0,199,199,199,0,200,200,200,0
DATA 201,201,201,0,202,202,202,0,203,203,203,0,204,204,204,0,205,205,205,0,206,206,206,0
DATA 207,207,207,0,208,208,208,0,209,209,209,0,210,210,210,0,211,211,211,0,212,212,212,0
DATA 213,213,213,0,214,214,214,0,215,215,215,0,216,216,216,0,217,217,217,0,218,218,218,0
DATA 219,219,219,0,220,220,220,0,221,221,221,0,222,222,222,0,223,223,223,0,224,224,224,0
DATA 225,225,225,0,226,226,226,0,227,227,227,0,228,228,228,0,229,229,229,0,230,230,230,0
DATA 231,231,231,0,232,232,232,0,233,233,233,0,234,234,234,0,235,235,235,0,236,236,236,0
DATA 237,237,237,0,238,238,238,0,239,239,239,0,240,240,240,0,241,241,241,0,242,242,242,0
DATA 243,243,243,0,244,244,244,0,245,245,245,0,246,246,246,0,247,247,247,0,248,248,248,0
DATA 249,249,249,0,250,250,250,0,251,251,251,0,252,252,252,0,253,253,253,0,254,254,254,0
DATA 255,255,255,0

END SUB

SUB bmpgen(BYVAL Imptr1&, BYVAL Bmpptr&, BYVAL hsize&, BYVAL vsize&, BYVAL St%, Buffer$) EXPORT
DIM Impt AS INTEGER PTR
DIM Impt2 AS INTEGER PTR
DIM Bmpt AS BYTE PTR
DIM Table2&(65535)
Bmpt=Bmpptr&
Impt=Imptr1&
hsize&=hsize&/2
vsize&=vsize&/2

hd!=hsize&/4
hf&=FIX(hsize&/4)
hpad%=4-INT((hd!-hf&)*4)

IF St%=1 THEN
FOR y%=1 TO vsize&
FOR x%=1 TO hsize&
imdata%=@Impt
IF imdata%<0 THEN dat&=imdata%+65536 ELSE dat&=imdata%          'scan image for pixel values
Table2&(dat&)= Table2&(dat&)+1
INCR Impt
NEXT x%
NEXT y%
maxval&=0
FOR z&=1 TO 40000
dat&=Table2&(z&)
IF dat&>maxval& THEN maxval&=dat&: q&=z&                       'find most common value
NEXT z&
maxval&=q& * 0.99 '0.97
b%=256 '64
ELSE
maxval&=0: b%=1
END IF

Bmpt=Bmpptr&
Impt2=Imptr1&+((vsize&-1)*hsize&*2)
OPEN Buffer$ FOR BINARY AS #1
Seek#1,0
@Bmpt=66: INCR Bmpt: @Bmpt=77: INCR Bmpt
sizebytes&=vsize&*hsize&+1078                                                             'get file size in bytes
b4&=FIX(sizebytes&/16777216)
sizebytes&=sizebytes&-b4&*16777216
b3&=FIX(sizebytes&/65536)
sizebytes&=sizebytes&-b3&*65536
b2&=FIX(sizebytes&/256)
sizebytes&=sizebytes&-b2&*256
b1&=sizebytes&
@Bmpt=b1&: INCR Bmpt: @Bmpt=b2&: INCR Bmpt: @Bmpt=b3&: INCR Bmpt: @Bmpt=b4&: INCR Bmpt    'file size
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt
@Bmpt=54: INCR Bmpt: @Bmpt=4: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt           'header size (1078)
@Bmpt=40: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt           'BITMAPINFOHEADER size
widthpix&=hsize&
w4&=FIX(widthpix&/16777216)
widthpix&=widthpix&-w4&*16777216
w3&=FIX(widthpix&/65536)
widthpix&=widthpix&-w3&*65536
w2&=FIX(widthpix&/256)
widthpix&=widthpix&-w2&*256
w1&=widthpix&
@Bmpt=w1&: INCR Bmpt: @Bmpt=w2&: INCR Bmpt: @Bmpt=w3&: INCR Bmpt: @Bmpt=w4&: INCR Bmpt    'image width in pixels
heightpix&=vsize&
h4&=FIX(heightpix&/16777216)
heightpix&=heightpix&-h4&*16777216
h3&=FIX(heightpix&/65536)
heightpix&=heightpix&-h3&*65536
h2&=FIX(heightpix&/256)
heightpix&=heightpix&-h2&*256
h1&=heightpix&
@Bmpt=h1&: INCR Bmpt: @Bmpt=h2&: INCR Bmpt: @Bmpt=h3&: INCR Bmpt: @Bmpt=h4&: INCR Bmpt    'image height in pixels
@Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt                                                    'image planes
@Bmpt=8: INCR Bmpt: @Bmpt=0: INCR Bmpt                                                    'bits per pixel
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'compression type
sizebytes&=vsize&*hsize&                                                                  'get image size in bytes
b4&=FIX(sizebytes&/16777216)
sizebytes&=sizebytes&-b4&*16777216
b3&=FIX(sizebytes&/65536)
sizebytes&=sizebytes&-b3&*65536
b2&=FIX(sizebytes&/256)
sizebytes&=sizebytes&-b2&*256
b1&=sizebytes&
@Bmpt=b1&: INCR Bmpt: @Bmpt=b2&: INCR Bmpt: @Bmpt=b3&: INCR Bmpt: @Bmpt=b4&: INCR Bmpt    'image size
@Bmpt=19: INCR Bmpt: @Bmpt=11: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt          'horizontal pixels per metre
@Bmpt=19: INCR Bmpt: @Bmpt=11: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt          'vertical pixels per metre
@Bmpt=0: INCR Bmpt: @Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'number of colours
@Bmpt=0: INCR Bmpt: @Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'number of important colours
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt

FOR x&=1 TO 1020
d%=VAL(READ$(x&))
@Bmpt=d%
INCR Bmpt
NEXT x&
FOR y&=1 TO vsize&
FOR x&=1 TO hsize&
dat&=@Impt2
IF dat&<0 THEN dat&=dat&+65536
dat&=(dat&-maxval&)*b%                                            'remove background level
IF dat&<0 THEN dat&=0
IF dat&>65535 THEN dat&=65535                                      'multiply by 256
dat&=dat&/257
dt?=dat&
@Bmpt=dt?
INCR Bmpt
INCR Impt2
NEXT x&
IF hpad%=1 THEN @Bmpt=0: INCR Bmpt
IF hpad%=2 THEN @Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt
IF hpad%=3 THEN @Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt
'FOR n%=0 TO hpad%: @Bmpt=0: INCR Bmpt: NEXT n%

Impt2=Impt2-(hsize&*4)
NEXT y&

PUT$ #1, PEEK$(Bmpptr&,hsize&*vsize&+1078)
CLOSE #1

DATA 1,1,1,0,2,2,2,0,3,3,3,0,4,4,4,0,5,5,5,0,6,6,6,0,7,7,7,0,8,8,8,0,9,9,9,0
DATA 10,10,10,0,11,11,11,0,12,12,12,0,13,13,13,0,14,14,14,0,15,15,15,0,16,16,16,0,17,17,17,0
DATA 18,18,18,0,19,19,19,0,20,20,20,0,21,21,21,0,22,22,22,0,23,23,23,0,24,24,24,0,25,25,25,0
DATA 26,26,26,0,27,27,27,0,28,28,28,0,29,29,29,0,30,30,30,0,31,31,31,0,32,32,32,0,33,33,33,0
DATA 34,34,34,0,35,35,35,0,36,36,36,0,37,37,37,0,38,38,38,0,39,39,39,0,40,40,40,0,41,41,41,0
DATA 42,42,42,0,43,43,43,0,44,44,44,0,45,45,45,0,46,46,46,0,47,47,47,0,48,48,48,0,49,49,49,0
DATA 50,50,50,0,51,51,51,0,52,52,52,0,53,53,53,0,54,54,54,0,55,55,55,0,56,56,56,0,57,57,57,0
DATA 58,58,58,0,59,59,59,0,60,60,60,0,61,61,61,0,62,62,62,0,63,63,63,0,64,64,64,0,65,65,65,0
DATA 66,66,66,0,67,67,67,0,68,68,68,0,69,69,69,0,70,70,70,0,71,71,71,0,72,72,72,0,73,73,73,0
DATA 74,74,74,0,75,75,75,0,76,76,76,0,77,77,77,0,78,78,78,0,79,79,79,0,80,80,80,0,81,81,81,0
DATA 82,82,82,0,83,83,83,0,84,84,84,0,85,85,85,0,86,86,86,0,87,87,87,0,88,88,88,0,89,89,89,0
DATA 90,90,90,0,91,91,91,0,92,92,92,0,93,93,93,0,94,94,94,0,95,95,95,0,96,96,96,0,97,97,97,0
DATA 98,98,98,0,99,99,99,0,100,100,100,0,101,101,101,0,102,102,102,0,103,103,103,0,104,104,104,0
DATA 105,105,105,0,106,106,106,0,107,107,107,0,108,108,108,0,109,109,109,0,110,110,110,0
DATA 111,111,111,0,112,112,112,0,113,113,113,0,114,114,114,0,115,115,115,0,116,116,116,0
DATA 117,117,117,0,118,118,118,0,119,119,119,0,120,120,120,0,121,121,121,0,122,122,122,0
DATA 123,123,123,0,124,124,124,0,125,125,125,0,126,126,126,0,127,127,127,0,128,128,128,0
DATA 129,129,129,0,130,130,130,0,131,131,131,0,132,132,132,0,133,133,133,0,134,134,134,0
DATA 135,135,135,0,136,136,136,0,137,137,137,0,138,138,138,0,139,139,139,0,140,140,140,0
DATA 141,141,141,0,142,142,142,0,143,143,143,0,144,144,144,0,145,145,145,0,146,146,146,0
DATA 147,147,147,0,148,148,148,0,149,149,149,0,150,150,150,0,151,151,151,0,152,152,152,0
DATA 153,153,153,0,154,154,154,0,155,155,155,0,156,156,156,0,157,157,157,0,158,158,158,0
DATA 159,159,159,0,160,160,160,0,161,161,161,0,162,162,162,0,163,163,163,0,164,164,164,0
DATA 165,165,165,0,166,166,166,0,167,167,167,0,168,168,168,0,169,169,169,0,170,170,170,0
DATA 171,171,171,0,172,172,172,0,173,173,173,0,174,174,174,0,175,175,175,0,176,176,176,0
DATA 177,177,177,0,178,178,178,0,179,179,179,0,180,180,180,0,181,181,181,0,182,182,182,0
DATA 183,183,183,0,184,184,184,0,185,185,185,0,186,186,186,0,187,187,187,0,188,188,188,0
DATA 189,189,189,0,190,190,190,0,191,191,191,0,192,192,192,0,193,193,193,0,194,194,194,0
DATA 195,195,195,0,196,196,196,0,197,197,197,0,198,198,198,0,199,199,199,0,200,200,200,0
DATA 201,201,201,0,202,202,202,0,203,203,203,0,204,204,204,0,205,205,205,0,206,206,206,0
DATA 207,207,207,0,208,208,208,0,209,209,209,0,210,210,210,0,211,211,211,0,212,212,212,0
DATA 213,213,213,0,214,214,214,0,215,215,215,0,216,216,216,0,217,217,217,0,218,218,218,0
DATA 219,219,219,0,220,220,220,0,221,221,221,0,222,222,222,0,223,223,223,0,224,224,224,0
DATA 225,225,225,0,226,226,226,0,227,227,227,0,228,228,228,0,229,229,229,0,230,230,230,0
DATA 231,231,231,0,232,232,232,0,233,233,233,0,234,234,234,0,235,235,235,0,236,236,236,0
DATA 237,237,237,0,238,238,238,0,239,239,239,0,240,240,240,0,241,241,241,0,242,242,242,0
DATA 243,243,243,0,244,244,244,0,245,245,245,0,246,246,246,0,247,247,247,0,248,248,248,0
DATA 249,249,249,0,250,250,250,0,251,251,251,0,252,252,252,0,253,253,253,0,254,254,254,0
DATA 255,255,255,0

END SUB

SUB Interlacedbmpgen(BYVAL Imptr1&, BYVAL Bmpptr&, BYVAL hsize&, BYVAL vsize&, BYVAL St%, Buffer$) EXPORT
DIM Impt AS INTEGER PTR
DIM Impt2 AS INTEGER PTR
DIM Bmpt AS BYTE PTR
DIM Table2&(65535)
Bmpt=Bmpptr&
Impt=Imptr1&

hd!=hsize&/4
hf&=FIX(hsize&/4)
hpad%=INT((hd!-hf&)*4)

IF St%=1 THEN
FOR y%=1 TO vsize&
FOR x%=1 TO hsize&
dat&=@Impt
IF dat&<0 THEN dat&=dat&+65536
Table2&(dat&)= Table2&(dat&)+1
INCR Impt
NEXT x%
NEXT y%
maxval&=0
FOR z&=1 TO 40000
dat&=Table2&(z&)
IF dat&>maxval& THEN maxval&=dat&: q&=z&                       'find most common value
NEXT z&
maxval&=q& * 0.97
b%=64
ELSE
maxval&=0: b%=1
END IF

Bmpt=Bmpptr&
Impt2=Imptr1&+((vsize&-1)*hsize&*2)
OPEN Buffer$ FOR BINARY AS #1
Seek#1,0
@Bmpt=66: INCR Bmpt: @Bmpt=77: INCR Bmpt
sizebytes&=vsize&*hsize&+1078                                                             'get file size in bytes
b4&=FIX(sizebytes&/16777216)
sizebytes&=sizebytes&-b4&*16777216
b3&=FIX(sizebytes&/65536)
sizebytes&=sizebytes&-b3&*65536
b2&=FIX(sizebytes&/256)
sizebytes&=sizebytes&-b2&*256
b1&=sizebytes&
@Bmpt=b1&: INCR Bmpt: @Bmpt=b2&: INCR Bmpt: @Bmpt=b3&: INCR Bmpt: @Bmpt=b4&: INCR Bmpt    'file size
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt
@Bmpt=54: INCR Bmpt: @Bmpt=4: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt           'header size (1078)
@Bmpt=40: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt           'BITMAPINFOHEADER size
widthpix&=hsize&
w4&=FIX(widthpix&/16777216)
widthpix&=widthpix&-w4&*16777216
w3&=FIX(widthpix&/65536)
widthpix&=widthpix&-w3&*65536
w2&=FIX(widthpix&/256)
widthpix&=widthpix&-w2&*256
w1&=widthpix&
@Bmpt=w1&: INCR Bmpt: @Bmpt=w2&: INCR Bmpt: @Bmpt=w3&: INCR Bmpt: @Bmpt=w4&: INCR Bmpt    'image width in pixels
heightpix&=vsize&
h4&=FIX(heightpix&/16777216)
heightpix&=heightpix&-h4&*16777216
h3&=FIX(heightpix&/65536)
heightpix&=heightpix&-h3&*65536
h2&=FIX(heightpix&/256)
heightpix&=heightpix&-h2&*256
h1&=heightpix&
@Bmpt=h1&: INCR Bmpt: @Bmpt=h2&: INCR Bmpt: @Bmpt=h3&: INCR Bmpt: @Bmpt=h4&: INCR Bmpt    'image height in pixels
@Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt                                                    'image planes
@Bmpt=8: INCR Bmpt: @Bmpt=0: INCR Bmpt                                                    'bits per pixel
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'compression type
sizebytes&=vsize&*hsize&                                                                  'get image size in bytes
b4&=FIX(sizebytes&/16777216)
sizebytes&=sizebytes&-b4&*16777216
b3&=FIX(sizebytes&/65536)
sizebytes&=sizebytes&-b3&*65536
b2&=FIX(sizebytes&/256)
sizebytes&=sizebytes&-b2&*256
b1&=sizebytes&
@Bmpt=b1&: INCR Bmpt: @Bmpt=b2&: INCR Bmpt: @Bmpt=b3&: INCR Bmpt: @Bmpt=b4&: INCR Bmpt    'image size
@Bmpt=19: INCR Bmpt: @Bmpt=11: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt          'horizontal pixels per metre
@Bmpt=19: INCR Bmpt: @Bmpt=11: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt          'vertical pixels per metre
@Bmpt=0: INCR Bmpt: @Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'number of colours
@Bmpt=0: INCR Bmpt: @Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'number of important colours
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt

FOR x&=1 TO 1020
d%=VAL(READ$(x&))
@Bmpt=d%
INCR Bmpt
NEXT x&
FOR y&=1 TO vsize&
FOR x&=1 TO hsize&
dat&=@Impt2
IF dat&<0 THEN dat&=dat&+65536
dat&=(dat&-maxval&)*b%                                            'remove background level
IF dat&<0 THEN dat&=0
IF dat&>65535 THEN dat&=65535
dat&=dat&/257
dt?=dat&
@Bmpt=dt?
INCR Bmpt
INCR Impt2
NEXT x&
IF hpad%=1 THEN @Bmpt=0: INCR Bmpt
IF hpad%=2 THEN @Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt
IF hpad%=3 THEN @Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt
'FOR n%=0 TO hpad%: INCR Bmpt: NEXT n%
Impt2=Impt2-(hsize&*4)
NEXT y&

PUT$ #1, PEEK$(Bmpptr&,hsize&*vsize&+1078)
CLOSE #1

'DATA 66,77,102,102,49,0,0,0,0,0,54,4,0,0,40,0,0,0,40,8,0,0,14,6,0,0,1,0,8        '58 bytes
'DATA 0,0,0,0,0,48,98,49,0,19,11,0,0,19,11,0,0,0,1,0,0,0,1,0,0,0,0,0,0

DATA 1,1,1,0,2,2,2,0,3,3,3,0,4,4,4,0,5,5,5,0,6,6,6,0,7,7,7,0,8,8,8,0,9,9,9,0
DATA 10,10,10,0,11,11,11,0,12,12,12,0,13,13,13,0,14,14,14,0,15,15,15,0,16,16,16,0,17,17,17,0
DATA 18,18,18,0,19,19,19,0,20,20,20,0,21,21,21,0,22,22,22,0,23,23,23,0,24,24,24,0,25,25,25,0
DATA 26,26,26,0,27,27,27,0,28,28,28,0,29,29,29,0,30,30,30,0,31,31,31,0,32,32,32,0,33,33,33,0
DATA 34,34,34,0,35,35,35,0,36,36,36,0,37,37,37,0,38,38,38,0,39,39,39,0,40,40,40,0,41,41,41,0
DATA 42,42,42,0,43,43,43,0,44,44,44,0,45,45,45,0,46,46,46,0,47,47,47,0,48,48,48,0,49,49,49,0
DATA 50,50,50,0,51,51,51,0,52,52,52,0,53,53,53,0,54,54,54,0,55,55,55,0,56,56,56,0,57,57,57,0
DATA 58,58,58,0,59,59,59,0,60,60,60,0,61,61,61,0,62,62,62,0,63,63,63,0,64,64,64,0,65,65,65,0
DATA 66,66,66,0,67,67,67,0,68,68,68,0,69,69,69,0,70,70,70,0,71,71,71,0,72,72,72,0,73,73,73,0
DATA 74,74,74,0,75,75,75,0,76,76,76,0,77,77,77,0,78,78,78,0,79,79,79,0,80,80,80,0,81,81,81,0
DATA 82,82,82,0,83,83,83,0,84,84,84,0,85,85,85,0,86,86,86,0,87,87,87,0,88,88,88,0,89,89,89,0
DATA 90,90,90,0,91,91,91,0,92,92,92,0,93,93,93,0,94,94,94,0,95,95,95,0,96,96,96,0,97,97,97,0
DATA 98,98,98,0,99,99,99,0,100,100,100,0,101,101,101,0,102,102,102,0,103,103,103,0,104,104,104,0
DATA 105,105,105,0,106,106,106,0,107,107,107,0,108,108,108,0,109,109,109,0,110,110,110,0
DATA 111,111,111,0,112,112,112,0,113,113,113,0,114,114,114,0,115,115,115,0,116,116,116,0
DATA 117,117,117,0,118,118,118,0,119,119,119,0,120,120,120,0,121,121,121,0,122,122,122,0
DATA 123,123,123,0,124,124,124,0,125,125,125,0,126,126,126,0,127,127,127,0,128,128,128,0
DATA 129,129,129,0,130,130,130,0,131,131,131,0,132,132,132,0,133,133,133,0,134,134,134,0
DATA 135,135,135,0,136,136,136,0,137,137,137,0,138,138,138,0,139,139,139,0,140,140,140,0
DATA 141,141,141,0,142,142,142,0,143,143,143,0,144,144,144,0,145,145,145,0,146,146,146,0
DATA 147,147,147,0,148,148,148,0,149,149,149,0,150,150,150,0,151,151,151,0,152,152,152,0
DATA 153,153,153,0,154,154,154,0,155,155,155,0,156,156,156,0,157,157,157,0,158,158,158,0
DATA 159,159,159,0,160,160,160,0,161,161,161,0,162,162,162,0,163,163,163,0,164,164,164,0
DATA 165,165,165,0,166,166,166,0,167,167,167,0,168,168,168,0,169,169,169,0,170,170,170,0
DATA 171,171,171,0,172,172,172,0,173,173,173,0,174,174,174,0,175,175,175,0,176,176,176,0
DATA 177,177,177,0,178,178,178,0,179,179,179,0,180,180,180,0,181,181,181,0,182,182,182,0
DATA 183,183,183,0,184,184,184,0,185,185,185,0,186,186,186,0,187,187,187,0,188,188,188,0
DATA 189,189,189,0,190,190,190,0,191,191,191,0,192,192,192,0,193,193,193,0,194,194,194,0
DATA 195,195,195,0,196,196,196,0,197,197,197,0,198,198,198,0,199,199,199,0,200,200,200,0
DATA 201,201,201,0,202,202,202,0,203,203,203,0,204,204,204,0,205,205,205,0,206,206,206,0
DATA 207,207,207,0,208,208,208,0,209,209,209,0,210,210,210,0,211,211,211,0,212,212,212,0
DATA 213,213,213,0,214,214,214,0,215,215,215,0,216,216,216,0,217,217,217,0,218,218,218,0
DATA 219,219,219,0,220,220,220,0,221,221,221,0,222,222,222,0,223,223,223,0,224,224,224,0
DATA 225,225,225,0,226,226,226,0,227,227,227,0,228,228,228,0,229,229,229,0,230,230,230,0
DATA 231,231,231,0,232,232,232,0,233,233,233,0,234,234,234,0,235,235,235,0,236,236,236,0
DATA 237,237,237,0,238,238,238,0,239,239,239,0,240,240,240,0,241,241,241,0,242,242,242,0
DATA 243,243,243,0,244,244,244,0,245,245,245,0,246,246,246,0,247,247,247,0,248,248,248,0
DATA 249,249,249,0,250,250,250,0,251,251,251,0,252,252,252,0,253,253,253,0,254,254,254,0
DATA 255,255,255,0

END SUB

SUB hibmpgen(BYVAL Imptr1&, BYVAL Bmpptr&, BYVAL hsize&, BYVAL vsize&, BYVAL St%, Buffer$) EXPORT
DIM Impt AS INTEGER PTR
DIM Impt2 AS INTEGER PTR
DIM Bmpt AS BYTE PTR
DIM Bmpt2 AS BYTE PTR
DIM Table2&(65535)
Bmpt=Bmpptr&
Impt=Imptr1&

hd!=hsize&/4
hf&=FIX(hsize&/4)
hpad%=INT((hd!-hf&)*4)

IF St%=1 THEN
FOR y%=1 TO vsize&/2
FOR x%=1 TO hsize&
imdata%=@Impt
IF imdata%<0 THEN dat&=imdata%+65536 ELSE dat&=imdata%          'scan image for pixel values
Table2&(dat&)= Table2&(dat&)+1
INCR Impt
NEXT x%
NEXT y%
maxval&=0
FOR z&=1 TO 40000
dat&=Table2&(z&)
IF dat&>maxval& THEN maxval&=dat&: q&=z&                       'find most common value
NEXT z&
maxval&=q& * 0.99
b%=2048 '64
ELSE
maxval&=0: b%=1
END IF

Bmpt=Bmpptr&
Bmpt2=Bmpptr&+hsize&+1078
Impt2=Imptr1&+((vsize&/2-1)*hsize&*2)
OPEN Buffer$ FOR BINARY AS #1
Seek#1,0
@Bmpt=66: INCR Bmpt: @Bmpt=77: INCR Bmpt
sizebytes&=vsize&*hsize&+1078                                                             'get file size in bytes
b4&=FIX(sizebytes&/16777216)
sizebytes&=sizebytes&-b4&*16777216
b3&=FIX(sizebytes&/65536)
sizebytes&=sizebytes&-b3&*65536
b2&=FIX(sizebytes&/256)
sizebytes&=sizebytes&-b2&*256
b1&=sizebytes&
@Bmpt=b1&: INCR Bmpt: @Bmpt=b2&: INCR Bmpt: @Bmpt=b3&: INCR Bmpt: @Bmpt=b4&: INCR Bmpt    'file size
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt
@Bmpt=54: INCR Bmpt: @Bmpt=4: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt           'header size (1078)
@Bmpt=40: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt           'BITMAPINFOHEADER size
widthpix&=hsize&
w4&=FIX(widthpix&/16777216)
widthpix&=widthpix&-w4&*16777216
w3&=FIX(widthpix&/65536)
widthpix&=widthpix&-w3&*65536
w2&=FIX(widthpix&/256)
widthpix&=widthpix&-w2&*256
w1&=widthpix&
@Bmpt=w1&: INCR Bmpt: @Bmpt=w2&: INCR Bmpt: @Bmpt=w3&: INCR Bmpt: @Bmpt=w4&: INCR Bmpt    'image width in pixels
heightpix&=vsize&
h4&=FIX(heightpix&/16777216)
heightpix&=heightpix&-h4&*16777216
h3&=FIX(heightpix&/65536)
heightpix&=heightpix&-h3&*65536
h2&=FIX(heightpix&/256)
heightpix&=heightpix&-h2&*256
h1&=heightpix&
@Bmpt=h1&: INCR Bmpt: @Bmpt=h2&: INCR Bmpt: @Bmpt=h3&: INCR Bmpt: @Bmpt=h4&: INCR Bmpt    'image height in pixels
@Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt                                                    'image planes
@Bmpt=8: INCR Bmpt: @Bmpt=0: INCR Bmpt                                                    'bits per pixel
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'compression type
sizebytes&=vsize&*hsize&                                                                  'get image size in bytes
b4&=FIX(sizebytes&/16777216)
sizebytes&=sizebytes&-b4&*16777216
b3&=FIX(sizebytes&/65536)
sizebytes&=sizebytes&-b3&*65536
b2&=FIX(sizebytes&/256)
sizebytes&=sizebytes&-b2&*256
b1&=sizebytes&
@Bmpt=b1&: INCR Bmpt: @Bmpt=b2&: INCR Bmpt: @Bmpt=b3&: INCR Bmpt: @Bmpt=b4&: INCR Bmpt    'image size
@Bmpt=19: INCR Bmpt: @Bmpt=11: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt          'horizontal pixels per metre
@Bmpt=19: INCR Bmpt: @Bmpt=11: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt          'vertical pixels per metre
@Bmpt=0: INCR Bmpt: @Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'number of colours
@Bmpt=0: INCR Bmpt: @Bmpt=1: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt            'number of important colours
@Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt: @Bmpt=0: INCR Bmpt

FOR x&=1 TO 1020
d%=VAL(READ$(x&))
@Bmpt=d%
INCR Bmpt
NEXT x&

FOR y&=1 TO vsize&/2
FOR x&=1 TO hsize&
dat&=@Impt2
IF dat&<0 THEN dat&=dat&+65536
dat&=(dat&-maxval&)*b%                                            'remove background level
IF dat&<0 THEN dat&=0
IF dat&>65535 THEN dat&=65535                                      'multiply by 256
dat&=dat&/257
dt?=dat&
@Bmpt=dt?
@Bmpt2=dt?
INCR Bmpt
INCR Bmpt2
INCR Impt2
NEXT x&
IF hpad%=1 THEN @Bmpt=0: INCR Bmpt
IF hpad%=2 THEN @Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt
IF hpad%=3 THEN @Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt:@Bmpt=0: INCR Bmpt
'FOR n%=0 TO hpad%: INCR Bmpt: NEXT n%
Bmpt=Bmpt+hsize&
Bmpt2=Bmpt2+hsize&
Impt2=Impt2-(hsize&*4)
NEXT y&

PUT$ #1, PEEK$(Bmpptr&,hsize&*vsize&+1078)
CLOSE #1


DATA 1,1,1,0,2,2,2,0,3,3,3,0,4,4,4,0,5,5,5,0,6,6,6,0,7,7,7,0,8,8,8,0,9,9,9,0
DATA 10,10,10,0,11,11,11,0,12,12,12,0,13,13,13,0,14,14,14,0,15,15,15,0,16,16,16,0,17,17,17,0
DATA 18,18,18,0,19,19,19,0,20,20,20,0,21,21,21,0,22,22,22,0,23,23,23,0,24,24,24,0,25,25,25,0
DATA 26,26,26,0,27,27,27,0,28,28,28,0,29,29,29,0,30,30,30,0,31,31,31,0,32,32,32,0,33,33,33,0
DATA 34,34,34,0,35,35,35,0,36,36,36,0,37,37,37,0,38,38,38,0,39,39,39,0,40,40,40,0,41,41,41,0
DATA 42,42,42,0,43,43,43,0,44,44,44,0,45,45,45,0,46,46,46,0,47,47,47,0,48,48,48,0,49,49,49,0
DATA 50,50,50,0,51,51,51,0,52,52,52,0,53,53,53,0,54,54,54,0,55,55,55,0,56,56,56,0,57,57,57,0
DATA 58,58,58,0,59,59,59,0,60,60,60,0,61,61,61,0,62,62,62,0,63,63,63,0,64,64,64,0,65,65,65,0
DATA 66,66,66,0,67,67,67,0,68,68,68,0,69,69,69,0,70,70,70,0,71,71,71,0,72,72,72,0,73,73,73,0
DATA 74,74,74,0,75,75,75,0,76,76,76,0,77,77,77,0,78,78,78,0,79,79,79,0,80,80,80,0,81,81,81,0
DATA 82,82,82,0,83,83,83,0,84,84,84,0,85,85,85,0,86,86,86,0,87,87,87,0,88,88,88,0,89,89,89,0
DATA 90,90,90,0,91,91,91,0,92,92,92,0,93,93,93,0,94,94,94,0,95,95,95,0,96,96,96,0,97,97,97,0
DATA 98,98,98,0,99,99,99,0,100,100,100,0,101,101,101,0,102,102,102,0,103,103,103,0,104,104,104,0
DATA 105,105,105,0,106,106,106,0,107,107,107,0,108,108,108,0,109,109,109,0,110,110,110,0
DATA 111,111,111,0,112,112,112,0,113,113,113,0,114,114,114,0,115,115,115,0,116,116,116,0
DATA 117,117,117,0,118,118,118,0,119,119,119,0,120,120,120,0,121,121,121,0,122,122,122,0
DATA 123,123,123,0,124,124,124,0,125,125,125,0,126,126,126,0,127,127,127,0,128,128,128,0
DATA 129,129,129,0,130,130,130,0,131,131,131,0,132,132,132,0,133,133,133,0,134,134,134,0
DATA 135,135,135,0,136,136,136,0,137,137,137,0,138,138,138,0,139,139,139,0,140,140,140,0
DATA 141,141,141,0,142,142,142,0,143,143,143,0,144,144,144,0,145,145,145,0,146,146,146,0
DATA 147,147,147,0,148,148,148,0,149,149,149,0,150,150,150,0,151,151,151,0,152,152,152,0
DATA 153,153,153,0,154,154,154,0,155,155,155,0,156,156,156,0,157,157,157,0,158,158,158,0
DATA 159,159,159,0,160,160,160,0,161,161,161,0,162,162,162,0,163,163,163,0,164,164,164,0
DATA 165,165,165,0,166,166,166,0,167,167,167,0,168,168,168,0,169,169,169,0,170,170,170,0
DATA 171,171,171,0,172,172,172,0,173,173,173,0,174,174,174,0,175,175,175,0,176,176,176,0
DATA 177,177,177,0,178,178,178,0,179,179,179,0,180,180,180,0,181,181,181,0,182,182,182,0
DATA 183,183,183,0,184,184,184,0,185,185,185,0,186,186,186,0,187,187,187,0,188,188,188,0
DATA 189,189,189,0,190,190,190,0,191,191,191,0,192,192,192,0,193,193,193,0,194,194,194,0
DATA 195,195,195,0,196,196,196,0,197,197,197,0,198,198,198,0,199,199,199,0,200,200,200,0
DATA 201,201,201,0,202,202,202,0,203,203,203,0,204,204,204,0,205,205,205,0,206,206,206,0
DATA 207,207,207,0,208,208,208,0,209,209,209,0,210,210,210,0,211,211,211,0,212,212,212,0
DATA 213,213,213,0,214,214,214,0,215,215,215,0,216,216,216,0,217,217,217,0,218,218,218,0
DATA 219,219,219,0,220,220,220,0,221,221,221,0,222,222,222,0,223,223,223,0,224,224,224,0
DATA 225,225,225,0,226,226,226,0,227,227,227,0,228,228,228,0,229,229,229,0,230,230,230,0
DATA 231,231,231,0,232,232,232,0,233,233,233,0,234,234,234,0,235,235,235,0,236,236,236,0
DATA 237,237,237,0,238,238,238,0,239,239,239,0,240,240,240,0,241,241,241,0,242,242,242,0
DATA 243,243,243,0,244,244,244,0,245,245,245,0,246,246,246,0,247,247,247,0,248,248,248,0
DATA 249,249,249,0,250,250,250,0,251,251,251,0,252,252,252,0,253,253,253,0,254,254,254,0
DATA 255,255,255,0

END SUB



SUB Autoview() EXPORT                                                'applies 0.2 power law to focus window
 DIM Table&(65535)
 Ratio!=1/(65535^(-0.8))
 FOR x&=0 TO 65535
 a&=INT((x&^0.2)*Ratio!)
 IF a&>65535 THEN a&=65535
 Table&(x&)=a&
 NEXT x&
END SUB



SUB fitscopy (BYVAL Imptr1&, BYVAL Imptr2&, filestring$) EXPORT              '376 x 290 files
DIM x AS LONG
DIM Impt1 AS BYTE PTR
DIM Impt2 AS BYTE PTR
DIM Impt3 AS BYTE PTR
DIM Impt4 AS BYTE PTR
DIM Impt5 AS INTEGER PTR
DIM Impt6 AS WORD PTR
Impt1=Imptr1&
Impt2=Imptr1&+1
Impt3=Imptr2&
Impt4=Imptr2&+1
Impt5 = Imptr1&
Impt6 = Imptr1&
'
FOR x&=1 TO 109040
Dat1%=@Impt5                            'read camera data
d&=Dat1%
IF d&<0 THEN d2&=d&+65536 ELSE d2&=d&   'convert to unsigned

Dat2%=d&-32767                          'convert to signed
@Impt5=Dat2%
bytea?=@Impt1                           'reverse byte order
byteb?=@Impt2
@Impt3=byteb?
@Impt4=bytea?
Impt1=Impt1+2
Impt2=Impt2+2
Impt3=Impt3+2
Impt4=Impt4+2
INCR Impt5
INCR Impt6
NEXT x&

OPEN filestring$ FOR BINARY AS #1
SEEK #1, 2879
PUT$ #1,PEEK$(Imptr2&,218080)
c?=32
FOR n&=1 TO 160
Put#1,,c?
NEXT n&
CLOSE #1
END SUB



SUB fitscopy2 (BYVAL Imptr1&, BYVAL Imptr2&, filestring$) EXPORT             '752 x 580 files
DIM x AS LONG
DIM Impt1 AS BYTE PTR
DIM Impt2 AS BYTE PTR
DIM Impt3 AS BYTE PTR
DIM Impt4 AS BYTE PTR
DIM Impt5 AS INTEGER PTR
DIM Impt6 AS WORD PTR
Impt1=Imptr1&
Impt2=Imptr1&+1
Impt3=Imptr2&
Impt4=Imptr2&+1
Impt5 = Imptr1&
Impt6 = Imptr1&
'
FOR x&=1 TO 436160
Dat1%=@Impt5                            'read camera data
d&=Dat1%
IF d&<0 THEN d2&=d&+65536 ELSE d2&=d&   'convert to unsigned

Dat2%=d&-32767                          'convert to signed
@Impt5=Dat2%
bytea?=@Impt1                           'reverse byte order
byteb?=@Impt2
@Impt3=byteb?
@Impt4=bytea?
Impt1=Impt1+2
Impt2=Impt2+2
Impt3=Impt3+2
Impt4=Impt4+2
INCR Impt5
INCR Impt6
NEXT x&

OPEN filestring$ FOR BINARY AS #1
SEEK #1, 2879
PUT$ #1,PEEK$(Imptr2&,872320)
c?=32
FOR n&=1 TO 160
Put#1,,c?
NEXT n&
CLOSE #1
END SUB

SUB Arrayswap (BYVAL Imptr1&, BYVAL Imptr2&) EXPORT
DIM Impt1 AS INTEGER PTR
DIM Impt2 AS INTEGER PTR
DIM Impt3 AS INTEGER PTR
DIM Impt4 AS INTEGER PTR
DIM Impt5 AS INTEGER PTR
DIM Impt6 AS INTEGER PTR
DIM Impt7 AS INTEGER PTR
DIM Impt8 AS INTEGER PTR

Impt1=Imptr1&
Impt2=Imptr1&+6000
Impt3=Imptr1&+6002
Impt4=Imptr1&+2

Impt5=Imptr2&
Impt6=Imptr2&+2
Impt7=Imptr2&+4
Impt8=Imptr2&+6

FOR y&=1 TO 1000
FOR z&=1 TO 1500
    @Impt1=@Impt5
    @Impt2=@Impt6
    @Impt3=@Impt7
    @Impt4=@Impt8

    Impt1=Impt1+4
    Impt2=Impt2+4
    Impt3=Impt3+4
    Impt4=Impt4+4
    Impt5=Impt5+8
    Impt6=Impt6+8
    Impt7=Impt7+8
    Impt8=Impt8+8
NEXT Z&
    Impt1=Impt1+6000
    Impt2=Impt2+6000
    Impt3=Impt3+6000
    Impt4=Impt4+6000
NEXT y&


END SUB
