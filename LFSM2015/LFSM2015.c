/************************************************************************
Title:    PCLFSM
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PClfsm.h,v 0.1 2015/07/03 14:00:00 sergio Exp $
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
	int page;
	int input;
	int output;
	//Function Pointers
	int (*read)(struct lfsm *r, int input);
	int (*learn)(struct lfsm *r, int input, int next);
	int (*quant)(struct lfsm *r);
	int (*remove)(struct lfsm *r, int input);
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
