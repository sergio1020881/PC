/************************************************************************
Title:    PCLFSM
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PClfsm.h,v 0.1 2015/07/09 14:00:00 sergio Exp $
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
	int (*learn)(struct lfsm *r, int input, int next, int page);
	int (*quant)(struct lfsm *r);
	int (*remove)(struct lfsm *r, int input);
	int (*deleteall)(struct lfsm *r);
	int (*get)(struct lfsm *r);
	void (*set)(struct lfsm *r,int output);
	int (*lh)(int xi, int xf);
	int (*hl)(int xi, int xf);
	int (*outputcalc)(int feeddback, int hl,int lh);
	int (*diff)(int xi, int xf);
};
typedef struct lfsm LFSM;
/*
** procedure and function header
*/
LFSM LFSMenable(int *eeprom, int sizeeeprom, int prog);
#endif
/***EOF***/
/***
Sintax Semantic Pragmatic.
Sintax is a key principle able to follow a sintactical work flow that solves any problem,
having a concise structural work flow is very importante.
The method used is C object oriented aproach, do not know anybody using this type of aproach, 
but all the programs made here follow this type of paradigm, it is very very stable either in 
PC or Embeded MCU programs, making Main program very compact.
Discovered this method by experience since then never left it, altering prior programs to fit 
its syntax, making the program much more flexible and broader.
Ofcourse C++ and C#, etc, already follows this type of paradigm, but C is the oldest and 
the mother language, most well recognised.
***/
