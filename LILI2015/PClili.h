/************************************************************************
Title:    PCLILI
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PClili.h,v 0.1 2015/08/12 14:00:00 sergio Exp $
Software: GCC
Hardware: 
License:  GNU General Public License 
Usage:    
LICENSE:
    Copyright (C) 2015
    This program is free software; you can redistribute it and/or modify
    it under the consent of the code developer, in case of commercial use
    need licence.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
COMMENT:
	review
************************************************************************/
#ifndef _PCLILI_H_
	#define _PCLILI_H_
/*
** constant and macro
*/
/*
** variable
*/
struct lilidata{
struct lilidata* next;
struct lilidata* back;
char* data;
};
typedef struct lilidata LILIDATA;
/******/
struct lili{
	//Local Variables
	LILIDATA* target;
	char* data;
	unsigned int total;
	//Function Pointers
	char* (*play)(struct lili *l);
	unsigned int (*forward)(struct lili *l);
	unsigned int (*reverse)(struct lili *l);
	unsigned int (*record)(struct lili *l, char* data);
	unsigned int (*remove)(struct lili *l);
	unsigned int (*quant)(struct lili *l);
};
typedef struct lili LILI;
/*
** procedure and function header
*/
LILI LILIenable(void);
#endif
/***EOF***/
