//=============================================================================
// Module name : qjsimg.h
// QT JS Image Class Library.
// Copyright (C) 2003 Jan Soldan
//               251 65 Ondrejov - 236
//               Czech Republic
//=============================================================================
#ifndef _QJSIMG_H_
#define _QJSIMG_H_

#include "img.h"
//=============================================================================
// QjsImg class
//=============================================================================
class QjsImg
{
protected:
 Img	m_red;
 Img    m_green;
 Img    m_blue;

public:
	QjsImg();
	QjsImg(int width, int height);
	QjsImg(QjsImg&);
       ~QjsImg();
protected:

};
//=============================================================================
#endif //_QJSIMG_H_
