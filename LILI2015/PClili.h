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
unsigned int* next;
unsigned int* back;
void* data;
};
typedef struct lilidata LILIDATA;
/******/
struct lili{
	//Local Variables
	LILIDATA* data;
	unsigned int* first;
	unsigned int* last;
	unsigned int quant;
	//Function Pointers
	unsigned int (*play)(struct lfsm *r, unsigned int input);
	unsigned int (*forward)(struct lfsm *r, unsigned int input, unsigned int next, unsigned int page);
	unsigned int (*reverse)(struct lfsm *r);
	unsigned int (*record)(struct lfsm *r);
	unsigned int (*remove)(struct lfsm *r);
	unsigned int (*quant)(struct lfsm *r, unsigned int input);
};
typedef struct lili LILI;
/*
** procedure and function header
*/
LILI LILIenable();
#endif
/***EOF***/
