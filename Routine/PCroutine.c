/*************************************************************************
Title:    PCROUTINE
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PCroutine.c, v 0.1 2017/01/22 15:00:00 sergio Exp $
Software: GCC
Hardware:  
License:  GNU General Public License        
DESCRIPTION:
	PC emulation
USAGE: 
NOTES:
LICENSE:
    Copyright (C) 2017
    This program is free software; you can redistribute it and/or modify
    it under the consent of the code developer, in case of commercial use
    need licence.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
COMMENT:
	improve
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
#include"PCroutine.h"
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
unsigned int ROUTINEroutine(struct routine* this, unsigned int entry);
void ROUTINEsearch(struct routine* this, unsigned int value, unsigned int data[], unsigned int size);
unsigned int ROUTINEnumber(struct routine* this);
/*
** Object Inicialize
*/
ROUTINE ROUTINEenable(unsigned int XY)
{
	/***Local Variable***/
	/***Local Function Header***/
	/***Create Object***/
	ROUTINE r;
	//Inicialize variables
	r.matrix_XY=XY;
	r.numero=0;
	//Function Vtable
	r.routine=ROUTINEroutine;
	r.search=ROUTINEsearch;
	r.number=ROUTINEnumber;
	/******/
	return r;
}
/*
** procedure and function
*/
//routine
unsigned int ROUTINEroutine(struct routine* this, unsigned int entry)
{
	unsigned int i;
	unsigned int index;
	unsigned int found=0;
	for(i=0;i<(this->matrix_XY+1);i++){
		//index=(number-1)*6+i; //matrix starting at 1
		index=this->numero*(this->matrix_XY+1)+i; //matrix starting at 0
		if(entry==index){
			this->numero=i;
			found=1;
			break;
		}
	}
	return found;
}
//search
void ROUTINEsearch(struct routine* this, unsigned int value, unsigned int data[], unsigned int size)
{
	unsigned int i;
	for(i=0;i<size;i++){
		if(value==data[i]){
			i++;
			if(ROUTINEroutine(this, data[i]))
				break;
		}
	}
}
//number
unsigned int ROUTINEnumber(struct routine* this)
{
	return this->numero;
}
/*
** interrupt
*/
/***EOF***/
/***Comments***/

