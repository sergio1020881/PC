/************************************************************************
Title:    PCLFSM
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PClfsm.h,v 0.1 2015/02/16 14:00:00 sergio Exp $
Software: GCC
Hardware: 
License:  GNU General Public License 
Usage:    
LICENSE:
    Copyright (C) 2015
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
COMMENT:
	review
************************************************************************/
#ifndef _PCLFSM_H_
	#define _PCLFSM_H_
/*
** constant and macro
*/
/*
** variable
*/
struct lfsm{
	//Local Variables
	int *mem;
	int sizeeeprom;
	int sizeblock;
	int page;
	int block[5];
	int input;
	//Function Pointers
	int (*read)(struct lfsm *r, int input, int feedback);
	int (*learn)(struct lfsm *r, int input, int next, int feedback);
	int (*quant)(struct lfsm *r);
	int (*remove)(struct lfsm *r, int input, int present);
	int (*deleteall)(struct lfsm *r);
	int (*get)(struct lfsm *r);
	int (*diff)(int xi, int xf);
};
typedef struct lfsm LFSM;
/*
** procedure and function header
*/
LFSM LFSMenable(int *eeprom, int sizeeeprom, int prog);
#endif
/***EOF***/
