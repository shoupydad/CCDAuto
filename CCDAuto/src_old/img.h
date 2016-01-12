//=============================================================================
// Module name : img.h
// Image Class Library.
// Copyright (C) 1999 - 2003 Jan Soldan
//               251 65 Ondrejov - 236
//               Czech Republic
//=============================================================================
#ifndef _IMG_H_
#define _IMG_H_

#include <string.h>  // memset, memcpy
#include "dtypes.h"
#include "math.h"
//=============================================================================
const int MAX_WIDTH  = 32768;
const int MAX_HEIGHT = 32768;
//=============================================================================
typedef enum
{
        OP_ALLOCATE
}OPERATION;
//=============================================================================
typedef enum
{									 
        S_NO_ERROR,
	S_UNDEFINED,
        S_BAD_PARAMETER,
        S_BAD_OPERATION,
        S_DIFF_SIZE,
        S_BUFF_NOT_DEFINED,
        S_BUFF_ALLOCATION_ERROR,
        S_BUFF_COPY_ERROR,
        S_KSC_MAX_ITERATIONS

}STATUS_CODE;
//=============================================================================
typedef struct
{
        int        x;
        int        y;
        int        size_x;
        int        size_y;
        double     min;	    // minimum flux value inside the area
        double     max;	    // maximum flux value inside the area	  
        double     mean;    // mean flux inside the box
        double     stdev;   // standard deviation
}Area;
//=============================================================================
typedef struct
{
        double     kscKappa; 
        double     kscNumSigma;
        int        kscMaxIters;
        double     kscMaxErr;
}KscParams;
//=============================================================================
typedef struct
{
	double     kscBackground;
        double     kscMean;
        double     kscStdev; 
        int        kscIters;
        double     kscErr;
}KscResults;
//=============================================================================
// Box class
//=============================================================================
class Box
{
protected:
 int           m_status;
 int           m_x;         // x - center of the box 
 int           m_y;	    // y - center of the box
 int           m_size_x;    // x - size of the box
 int           m_size_y;    // y - size of the box
 double        m_value;	    // raw value at position [y][x]
 double        m_min;	    // minimum flux value inside the box
 double        m_max;	    // maximum flux value inside the box	  
 double        m_mean;	    // mean flux inside the box
 double        m_stdev;	    // standard deviation
 double        m_fwhmx;	    // full width at half maximum in x direction
 double        m_fwhmy;	    // full width at half maximum in y direction
 double        m_fwhmxy;    // avreage value of the fwhmx & fwhmy

public:
               Box(int x, int y, int size_x, int size_y);
              ~Box(){};

 void          InitVariables(int x, int y, int size_x, int size_y);

 inline void   SetStatus (int    val) {m_status = val;}
 inline void   SetValue  (double val) {m_value  = val;}
 inline void   SetMin    (double val) {m_min    = val;}
 inline void   SetMax    (double val) {m_max    = val;}
 inline void   SetMean   (double val) {m_mean   = val;}
 inline void   SetStdev  (double val) {m_stdev  = val;}
 inline void   SetFwhmX  (double val) {m_fwhmx  = val;}
 inline void   SetFwhmY  (double val) {m_fwhmy  = val;}
 inline void   SetFwhmXY (double val) {m_fwhmxy = val;}

 inline int    GetStatus() const {return(m_status);}
 inline int    GetX()      const {return(m_x);     }
 inline int    GetY()      const {return(m_y);     }
 inline int    GetSizeX()  const {return(m_size_x);}
 inline int    GetSizeY()  const {return(m_size_y);}
 inline double GetValue()  const {return(m_value); }
 inline double GetMin()    const {return(m_min);   }
 inline double GetMax()    const {return(m_max);   }
 inline double GetMean()   const {return(m_mean);  }
 inline double GetStdev()  const {return(m_stdev); }
 inline double GetFwhmX()  const {return(m_fwhmx); }
 inline double GetFwhmY()  const {return(m_fwhmy); }
 inline double GetFwhmXY() const {return(m_fwhmxy);}
};
//=============================================================================
// Img class
//=============================================================================
class Img
{
protected:
 int                    m_status;
 int                    m_width;
 int                    m_height;
 double                 m_background;
 IMG_DATA_TYPE        **m_buff;

public:
                        Img();
                        Img(int width, int height);
                        Img(Img&);
                       ~Img();

 int                    AllocateBuffer(int width, int height);
 int                    SetBuffer(IMG_DATA_TYPE value);
 int                    CopyBuffer(Img &destImage,
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

 int                    HFlip();
 int                    VFlip();

 int                    CalcBoxStat(Box&);
 int                    CalcAreaStat(Area&);
 int                    CalcKscBackground(KscParams&, KscResults&);
 int                    CalcHistogram();
 Img                    &operator<< (Img&);
 Img                    &operator+= (Img&);

 inline IMG_DATA_TYPE **GetBuffer()     const {return(m_buff);       }
 inline int             GetWidth()      const {return(m_width);      }
 inline int             GetHeight()     const {return(m_height);     }
 inline double          GetBackground() const {return(m_background); }
 inline void            SetBackground(double bgr){m_background = bgr;}

 inline int             GetStatus()     const {return(m_status);     }
 char                  *GetStatusString();

protected:
 void                   InitVars();
 int                    FreeBuffer();
};
//=============================================================================
#endif //_IMG_H_
