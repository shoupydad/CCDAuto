//=============================================================================
// Module name : qjsimg.h
// QJS Image Class Library.
// Copyright (C) 2003 Jan Soldan
//               251 65 Ondrejov - 236
//               Czech Republic
//=============================================================================
#ifndef _QJSIMG_H_
#define _QJSIMG_H_

#include <qimage.h> 
#include "dtypes.h"
//=============================================================================
const int QJS_WIDTH_MAX  = 32767;
const int QJS_HEIGHT_MAX = 32767;
const int QJS_DEPTH      = 32;
//=============================================================================
typedef enum
{									 
 S_NO_ERROR,
 S_UNDEFINED,
 S_BAD_PARAM,
 S_BAD_ALLOC,
 S_BAD_OPER,
 S_DIFF_SIZE,
 S_BUFF_COPY,
 S_MAX_ITER
}STATUS_CODE;
//-----------------------------------------------------------------------------
typedef enum
{
 OP_ALLOCATE
}OPERATION;
//-----------------------------------------------------------------------------
typedef enum
{
 QJS_LIN_LUT,
 QJS_LOG_LUT,
 QJS_GAMMA_LUT,
 QJS_GAMMALOG_LUT,
 QJS_SAWTOOTH_LUT,
 QJS_NEG_LUT
}QJS_LUT;
//-----------------------------------------------------------------------------
typedef enum
{
 QJS_RGB_BUF,
 QJS_RED_BUF,
 QJS_GREEN_BUF,
 QJS_BLUE_BUF
}QJS_COLOR_BUF;
//=============================================================================
typedef struct
{
 int        x;
 int        y;
 int        size_x;
 int        size_y;
 double     min;     // minimum flux value inside the area
 double     max;     // maximum flux value inside the area	  
 double     mean;    // mean flux inside the box
 double     stdev;   // standard deviation
}Area;
//-----------------------------------------------------------------------------
typedef struct
{
 double     kscKappa; 
 double     kscNumSigma;
 int        kscMaxIters;
 double     kscMaxErr;
}KscParams;
//-----------------------------------------------------------------------------
typedef struct
{
 double     kscBackground;
 double     kscMean;
 double     kscStdev; 
 int        kscIters;
 double     kscErr;
}KscResults;
//=============================================================================
// QjsImg class
//=============================================================================
class QjsImg : public QImage
{
protected:
 int               m_status;
 int               m_width;
 int               m_height;
 IMG_DATA_TYPE   **m_buffer;

public:
	 QjsImg();
	 QjsImg(int width, int height);
	 QjsImg(QjsImg&);
	~QjsImg();

 int     AllocateBuffers(int width, int height);
 int     FillBuffer(IMG_DATA_TYPE value);
 int     ConvertToColor(QJS_COLOR_BUF buffer, 
                        QJS_LUT       lut = QJS_LIN_LUT, 
		        int           black  = 0, 
		        int           white  = 255);
 int     HFlip();
 int     VFlip();
 
 int     CreateFakeImage();      

 /*
 int     CopyBuffer(Img &destImage,
                                   int  xSrc,
                                   int  ySrc,
                                   int  width,
                                   int  height);
 int                    CopyBuffer(Img &destImage,
                                   int  xDest,
                                   int  yDest,
                                   int  xSrc,
                                   int  ySrc,
                                   int  width,
                                   int  height);
 int                    SetValue(int x, int y, IMG_DATA_TYPE value);
 int                    GetValue(int x, int y, IMG_DATA_TYPE &value);


 int                    CalcBoxStat(Box&);
 int                    CalcAreaStat(Area&);
 int                    CalcKscBackground(KscParams&, KscResults&);
 int                    CalcHistogram();
 Img                    &operator<< (Img&);
 Img                    &operator+= (Img&);

 inline double          GetBackground() const {return(m_background);}
 inline void            SetBackground(double bgr){m_background = bgr;}
 */

 inline void            SetWidth(int  w) {m_width  = w;}
 inline void            SetHeight(int h) {m_height = h;}       
 inline int             GetWidth()     const {return(m_width);}
 inline int             GetHeight()    const {return(m_height);}
 inline IMG_DATA_TYPE **GetBuffer()    const {return(m_buffer);}
 inline bool            IsBufferNull() const {return(m_buffer ? false : true);}
 inline int             GetStatus()    const {return(m_status);}
 char                  *GetStatusString();

protected:
 void                   InitVars();
 void                   CreateBuffer(int width, int height);
 void                   ResetBuffer();
};
//=============================================================================
#endif //_QJSIMG_H_





