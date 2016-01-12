Notes on the SXVIDEO application:

First, a bug-fixed version of SXVIO.sys needs to be copied into
the   C:\WINDOWS\SYSTEM32\DRIVERS   directory.  The  driver  is
backward  compatible  with  the one shipped with the camera. It
allows  multiple  cameras  to  be  opened  (for all of you with
multiple  SXVs)  and  makes  opening  one more robust. Copy the
sxvideo.exe   and   sxusbcam.dll   into  your  SXV  application
directory  (or any directory you want). Click on sxvideo.exe to
start the video application.

Just  what  is  it?  Well,  for  those of you familiar with the
low-light  video cameras that are all the rage, you can now use
your SXV the same way. This is a rather brain-dead application,
it  is  meant more as a test-bed for the SXV interface library,
sxusbcam.dll.  It  simply  takes  a steady stream of images and
displays  them.  The exposure duration is set by the F1 through
F10  keys.  It  is a semi-log scale from 0 ms to 4 seconds. The
space  bar  cycles  through  the  available color palettes. The
video  window  can  be stretched and scaled to any size. I just
maximize  mine  to  get the biggest image. Computer speed makes
all  the  difference here. The faster the better although I use
it  on  my 400 MHz Celeron laptop with reasonable results. This
is great for star parties when you want to show off your fancy,
expensive  toy  and don't want to say 'come back in an hour and
see  the  image'. You should get nice, deep images to show off.
Excessively  bright  objects  may  saturate the CCD so the moon
isn't  a  real good option unless you have a good filter or can
stop the aperature way down. This is also a handy way to locate
DSO's in real-time for long-exposure imaging.

How  does it work? Well, in order to give video type framerates
and  make  the camera sensitive enough for short exposures, the
image  is binned way down. The image is binned all the way down
to  a  320x240  image,  or as close as can be had given the ccd
dimensions.   The   binning   is  done  on-chip  for  increased
sensitivity.   Because   the   ccd  resolution  is  so  greatly
diminished, this mode is only good for coarse focus adjustment.

But  I  have the original USB interface, is there a version for
me?  Well, sort of. I have written a universal HEX file for the
original  USB interface that is uses the same command interface
as the SXV. You can then use the sxvideo application as is (and
even  the  shipping  SXV-H9  acquisition application) with your
camera.  All  the  cameras are supported. You will be presented
with  a  dialog  box asking you what camera model you have. You
can scroll through the list to select your model, and check the
'Don't  ask again' box if you never want to answer the question
again.  However,  this configuration is not compatible with the
applications  you currently have for your camera. You will need
to  back  up your current configuration before attempting this.
In  fact,  contact me directly at dschmenk@earthlink.net before
doing anything and I will help you through it.

Dave...

