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
void* data;
};
typedef struct lilidata LILIDATA;
/******/
struct lili{
	//Local Variables
	LILIDATA* data;
	struct lilidata* target;
	unsigned int quant;
	//Function Pointers
	void* (*play)(struct lfsm *l);
	unsigned int (*forward)(struct lfsm *l);
	unsigned int (*reverse)(struct lfsm *l);
	unsigned int (*record)(struct lfsm *l);
	unsigned int (*remove)(struct lfsm *l);
	unsigned int (*quant)(struct lfsm *l);
};
typedef struct lili LILI;
/*
** procedure and function header
*/
LILI LILIenable();
#endif
/***EOF***/
