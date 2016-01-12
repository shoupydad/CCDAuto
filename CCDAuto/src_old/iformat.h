//=============================================================================
// Module name : iformat.h
// Copyright (C) 1999 - 2002 Jan Soldan
//               251 65 Ondrejov - 236
//               Czech Republic
//=============================================================================
#ifndef _IFORMAT_H_
#define _IFORMAT_H_

#include <vector>
#include <stdio.h>
#include "dtypes.h"
using namespace std;
//=============================================================================
typedef enum{
 IFORMAT_OK,
 IFORMAT_BAD_PARAMETER,
 IFORMAT_NOTE_TRUNCATED,
 IFORMAT_STRING_TRUNCATED,
 IFORMAT_COMMENT_TRUNCATED,
 IFORMAT_UNKNOWN_DATA_TYPE,
 IFORMAT_MISSING_DATA,
 IFORMAT_BAD_KEYWORD,
 IFORMAT_UNKNOWN_VALUE,
 IFORMAT_FUNCTION_NOT_IMPLEMENTED,
 IFORMAT_NO_HDU,
 IFORMAT_FOPEN_ERROR

}IFORMAT_ERROR;
//=============================================================================
class IFormat{
protected:

public:
 IFormat();
 virtual ~IFormat();

 virtual int Load(const char *pathName) = 0;
 virtual int Save(const char *pathName) = 0;
};
//=============================================================================
#endif //_IFORMAT_H_
