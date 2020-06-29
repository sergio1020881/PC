/************************************************************************
Title:    PCLFSM
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PClfsm.h,v 0.1 2015/08/12 14:00:00 sergio Exp $
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
** library
*/
// fopen perror fread fwrite feof fseek ferror fclose rewind scanf sscanf getchar scanf fscanf
#include <stdio.h>
// calloc free realloc malloc
//#include <stdlib.h>
// strcpy strcmp strcat memcmp
//#include <string.h>
// termios tcflush
//#include <termios.h>
// nanosleep sleep
//#include <time.h>
// tcflsuh read write close
//#include <unistd.h>
// perror
//#include <errno.h>
// open
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <stdio_ext.h>
//#include <math.h>
/*
** constant and macro
*/
/*
** variable
*/
struct lfsmdata{
unsigned int page;
unsigned int feedback;
unsigned int input;
unsigned int inhl;
unsigned int inlh;
unsigned int outhl;
unsigned int outlh;
};
typedef struct lfsmdata LFSMDATA;
/******/
struct lfsm{
	//Local Variables
	LFSMDATA *mem;
	unsigned int sizeeeprom;
	unsigned int page;
	unsigned int input;
	unsigned int output;
	//Function Pointers
	unsigned int (*read)(struct lfsm *r, unsigned int input);
	unsigned int (*learn)(struct lfsm *r, unsigned int input, unsigned int next, unsigned int page);
	unsigned int (*quant)(struct lfsm *r);
	unsigned int (*remove)(struct lfsm *r, unsigned int input);
	unsigned int (*deleteall)(struct lfsm *r);
	unsigned int (*get)(struct lfsm *r);
	void (*set)(struct lfsm *r,unsigned int output);
	unsigned int (*lh)(unsigned int xi, unsigned int xf);
	unsigned int (*hl)(unsigned int xi, unsigned int xf);
	unsigned int (*outputcalc)(unsigned int feeddback, unsigned int hl,unsigned int lh);
	unsigned int (*diff)(unsigned int xi, unsigned int xf);
    unsigned int (*validate)(struct lfsm *r, unsigned int n);
};
typedef struct lfsm LFSM;
/*
** procedure and function header
*/
LFSM LFSMenable(LFSMDATA *eeprom, unsigned int sizeeeprom);
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
Of course C++ and C#, etc, already follows this type of paradigm, but C is the oldest and
the mother language, most well recognised.
***/
