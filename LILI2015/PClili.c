/*************************************************************************
Title:    PCLILI
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PClili.c, v 0.1 2015/08/12 14:00:00 sergio Exp $
Software: GCC
Hardware:  
License:  GNU General Public License        
DESCRIPTION:
	PC emulation
USAGE: 
NOTES:
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
	just beginning work
*************************************************************************/
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
/***/
#include"PClili.h"
/*
** constant and macro
*/
#define EMPTY 0
/*
** variable
*/
/*
** procedure and function header
*/
void* LILIplay(struct lili *l);
unsigned int LILIforward(struct lili *l);
unsigned int LILIreverse(struct lili *l);
unsigned int LILIrecord(struct lili *l);
unsigned int LILIremove(struct lili *l);
unsigned int LILIquant(struct lili *l);
/*
** Object Inicialize
*/
LILI LILIenable(void)
{
	/***Local Variable***/
	/***Local Function Header***/
	/***Create Object***/
	LILI l;
	//Inicialize variables
	l.target=NULL;
	//Function Vtable
	l.play=LILIplay;
	l.forward=LILIforward;
	l.reverse=LILIreverse;
	l.record=LILIrecord;
	l.remove=LILIremove;
	l.quant=LILIquant;
	/******/
	return l;
}
/*
** procedure and function
*/
/***lead***/
void* LILIplay(struct lili *l)
{
	return l->data;
}
/***learn***/ 
unsigned int LILIforward(struct lili *l)
{
	return 0;
}
/***quant***/
unsigned int LILIreverse(struct lili *l)
{
	return 0;
}
/***lemove***/
unsigned int LILIrecord(struct lili *l)
{
	return 0;
}
/***deleteall***/
unsigned int LILIremove(struct lili *l)
{
	return 0;
}
unsigned int LILIquant(struct lili *l)
{
	return 0;
}
/*
** interrupt
*/
/***EOF***/
