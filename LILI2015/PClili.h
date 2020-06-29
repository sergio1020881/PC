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
** library
*/
// fopen perror fread fwrite feof fseek ferror fclose rewind scanf sscanf getchar scanf fscanf
#include <stdio.h>
// calloc free realloc malloc
#include <stdlib.h>
// strcpy strcmp strcat memcmp
#include <string.h>
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
*** library
*/
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
	LILIDATA* tail;
	LILIDATA* head;
	char** data;
	unsigned int total;
	//Function Pointers
	char* (*play)(struct lili *l);
	void (*forward)(struct lili *l);
	void (*reverse)(struct lili *l);
	void (*record)(struct lili *l, char* data);
	void (*remove)(struct lili *l);
	void (*free)(struct lili *l);
	unsigned int (*quant)(struct lili *l);
	void (*status)(struct lili *l);
	void (*insert)(struct lili *l, char* data);
	void (*replace)(struct lili *l, char* data);
	void (*push)(struct lili *l, char* data);
	char* (*pop)(struct lili *l);
};
typedef struct lili LILI;
/*
** procedure and function header
*/
LILI LILIenable(void);
#endif
/***EOF***/

