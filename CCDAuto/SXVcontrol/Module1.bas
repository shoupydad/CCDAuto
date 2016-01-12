Attribute VB_Name = "Declarevars"
Global hsize&, vsize&, binsize&, bin1size&, bin2size&, bin4size&, binread&, bin1read&, bin2read&, bin4read&
Global coloursize&, copysize&, colourbal%, camtype%
Global redstart&, greenstart&, bluestart&, ready%, Readtype%, RGBtype%
Global Imagearray1%()
Global Imagearray2%()
Global Imagearray3%()
Global Imagearray4%()
Global Imagearray5%()
Global Imagearray6(127, 128) As Byte
Global Imagearray7(500, 292) As Byte
Global Imagearray8(500, 292) As Byte
Global Imagearray9(500, 292) As Byte
Global Tiffarray(1500000) As Byte
Global Colourarray%()
Global Bmparray(18100000) As Byte
Global CommandBlock(64) As Byte
Global Window&(10)
Global Fitsarray(2880) As Byte

Global Imptr&, Imptr1&, Imptr2&, Imptr3&, Imptr4&, Imptr5&, Imptr6&, Imptr7&, Imptr9&, Colourptr&, Bmpptr&, Reportptr&, Tiffptr&, pointr1&, pointr2&
Global port%, gtime%, fast%, factor!, Bin%, HR%, viewmode%, model%
Global Powr!
Global Imagepresent%, Table&(65535), Imtable(255) As Byte
Global Dirpath$, Autoimage$, Buffer$
Global Colourfile%, SF!, MRd!, MGn!, MBl!, Bf%, cs&
Global Radius%, Pwr%, gflag%, Time%, Focusflag%, Sizeflag%
Global Guideflag%, Guiderun%, pickstar%, px%, qx%, py%, qy%, autosave%, img%, peak%, RAsum&, Decsum&
Global Camdata(8) As Byte
Global pict() As Byte
Global Buffer1(65535) As Byte, BufferPtr&, BytesReturned&, BytesWritten&, Clearcount%, Remainder&
Global ReportBuffer() As Byte
Global keyvalue%, AF%, backsignal&, backcount&
Global xoffset_L, xoffset_H, yoffset_L, yoffset_H, LSwidth&, MSwidth&, LSheight&, MSheight&, Readcount&
Global FXloc%, FYloc%, setfocuscentre%, mclick%, mono%

Global ByteCount&, mp%, selectcentre%, Xloc%, Yloc%, Xend%, Yend%, hcentre%, vcentre%, S2K%, s1#, s2&, s3&
Global RAdirection%, DECdirection%, RAerror!, DECerror!, RAtime&, DECtime&, RAcentre!, DECcentre!
Global horwidth%, vertwidth%, horcentre%, vertcentre%, background&, Field%, Mainexpose%, ExposureEnd&, Endcount&
Global Exbyte1%, Exbyte2%, Exbyte3%, Exbyte4%, Ex1$, Ex2$, Ex3$, Ex4$, Expinterval&, Terminate%
Global hdump%, vdump%, hdump2%, vdump2%, hwidth%, vwidth%, subframe%, mode%, Exmsb%, Exlsb%
Global Handle(2) As Long, HID As Long, BlockIO As Long, HidHandle&, BlockIOHandle&
Global Ch1%, Ch2%, Ch3%, Ch4%, Le%, Minimum%, Maximum%, Colptr&, St%, maxval&
Global pixeloffset%, lineoffset%
