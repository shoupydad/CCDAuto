//=============================================================================
// Module name : fits.h
// Copyright (C) 1999 - 2003 Jan Soldan
//               251 65 Ondrejov - 236
//               Czech Republic
//=============================================================================
#ifndef _FITS_H_
#define _FITS_H_

#include <string.h>  // memset, memcpy
#include <stdlib.h>  // atoi
#include "dtypes.h"
#include "iformat.h"
//=============================================================================
#define FITS_SIGNATURE       "SIMPLE  =                    T"
#define FITS_RECORD_LENGTH   2880
#define CARD_LENGTH          80

#define BZERO16              32768.0
#define BZERO32              2147483648.0

#define BLANK16             -32768
#define BLANK32             -2147483648L

#define SIMPLE               "SIMPLE"
#define BITPIX               "BITPIX"
#define NAXIS                "NAXIS"
#define NAXIS1               "NAXIS1"
#define NAXIS2               "NAXIS2"
#define NAXIS3               "NAXIS3"
#define END                  "END"

#define BSCALE               "BSCALE"
#define BZERO                "BZERO"
#define BUNIT                "BUNIT"
#define BLANK                "BLANK"
#define COMMENT              "COMMENT"
#define HISTORY              "HISTORY"

#define OBJECT               "OBJECT"
#define TELESCOP             "TELESCOP"
#define INSTRUME             "INSTRUME"
#define OBSERVER             "OBSERVER"
#define DATE_OBS             "DATE-OBS"
#define DATE                 "DATE"
#define EQUINOX              "EQUINOX"
#define EPOCH                "EPOCH"

#define ORIGIN               "ORIGIN"
#define AUTHOR               "AUTHOR"

//=============================================================================
class Card{
protected:
 char                   m_card[CARD_LENGTH];

public:
                        Card();
                       ~Card();
 inline void            Init(){memset(m_card, ' ', CARD_LENGTH);}
 int                    SetKeyword(char*);
 int                    SetValDelimiter();
 int                    SetLogical(char);
 int                    SetInteger(int);
 int                    SetReal   (double);
 int                    SetComplex(double re, double im);
 int                    SetString (char*);
 int                    SetNote   (char*);
 int                    SetComment(char*);
 inline char           *GetCard(){return(m_card);}
 int                    GetKeyword(char*);
 int                    GetLogical(int&);
 int                    GetInteger(int&);
 int                    GetReal   (double&);
 int                    GetComplex(double &re, double &im);
 int                    GetString (char*);
 int                    GetNote   (char*);
 int                    GetComment(char*);
};
//=============================================================================
class Hdu{
protected:
 vector<Card>           m_vcard;
 Card                   m_card;
 IMG_DATA_TYPE        **m_buff;

public:
                        Hdu();
                       ~Hdu();
 vector<Card>          *GetCardVector(){return(&m_vcard);}
 inline void            Init(){m_vcard.erase(m_vcard.begin(), m_vcard.end());}
 inline void            InitAuxCard(){m_card.Init();}
 inline Card           *GetAuxCard() {return(&m_card);}
 int                    FindCard(char *keyword, Card &card);
 inline void            SetBuffer(IMG_DATA_TYPE **buff){m_buff = buff;}
 inline IMG_DATA_TYPE **GetBuffer(){return(m_buff);}
 // Basic keywords
 int                    SetSimple(char value = 'T', char *note = NULL);
 int                    SetBitpix(int  value = 16,  char *note = NULL);
 int                    SetNaxis (int  value =  0,  char *note = NULL);
 int                    SetNaxis1(int  value =  0,  char *note = NULL);
 int                    SetNaxis2(int  value =  0,  char *note = NULL);
 int                    SetNaxis3(int  value =  0,  char *note = NULL);
 int                    SetEnd();
 int                    GetSimple(int &value);
 int                    GetBitpix(int &value);
 int                    GetNaxis (int &value);
 int                    GetNaxis1(int &value);
 int                    GetNaxis2(int &value);
 int                    GetNaxis3(int &value);
 // Reserved keywords
 int                    SetBscale(double value = 1.0, char *note = NULL);
 int                    SetBzero (double value,       char *note = NULL);
 int                    SetBlank (int    value,       char *note = NULL);
 int                    SetBunit (char  *value,       char *note = NULL);
 // Other keywords
 int                    SetComment   (char *comment = NULL);
 int                    SetHistory   (char *history = NULL);
 int                    SetOrigin    (char *value, char *note = NULL);
 int                    SetTelescope (char *value, char *note = NULL);
 int                    SetInstrument(char *value, char *note = NULL);
 int                    SetObserver  (char *value, char *note = NULL);
 int                    SetObject    (char *value, char *note = NULL);
 int                    SetAuthor    (char *value, char *note = NULL);
 int                    SetDate      (char *value, char *note = NULL);
 int                    SetDateObs   (char *value, char *note = NULL);
 // Extension keywords
 int                    SetExtend    (char  value = 'T', char *note = NULL);
 int                    SetXtension  (char *value,       char *note = NULL);
 int                    SetPcount    (int   value = 0,   char *note = NULL);
 int                    SetGcount    (int   value = 1,   char *note = NULL);
};
//=============================================================================
class Fits : public IFormat{
protected:
 vector<Hdu>            m_hdu;
public:
                        Fits();
                       ~Fits();

 vector<Hdu>           *GetHduVector(){return(&m_hdu);}
 void                   Push(Hdu &hdu){m_hdu.push_back(hdu);}
 void                   Init(){m_hdu.erase(m_hdu.begin(), m_hdu.end());}

 int                    Insert(int position, Hdu &hdu);
 int                    Pop();
 int                    Erase(int pos);
 int                    Erase(int first, int last);
 inline int             Size(){return(m_hdu.size());}

 int                    Load(const char *pathName);
 int                    Save(const char *pathName);

 protected:
 int                    SavePrimaryHdu(FILE*);
 int                    SaveExtensions(FILE*);

 int                    SaveI8 (FILE*, Hdu*);
 int                    SaveI16(FILE*, Hdu*);
 int                    SaveI32(FILE*, Hdu*);
 int                    SaveF32(FILE*, Hdu*);
 int                    SaveF64(FILE*, Hdu*);
};
//=============================================================================
#endif // _FITS_H
