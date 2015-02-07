/*************************************************************************
Title:    PCLOGIC
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PClogic.c,v 0.1 2015/02/06 14:00:00 sergio Exp $
Software: GCC
Hardware:  
License:  GNU General Public License        
DESCRIPTION:
	PC emulation
USAGE:
    Refere to the header file function.h for a description of the routines. 
NOTES:
    Based on Atmel Application Note AVR306
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
	Very Stable
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
#include"PClogic.h"
/*
** constant and macro
*/
#define EMPTY 0
/*
** variable
*/
char LOGICstr[16];
/*
** procedure and function header
*/
int LOGICread(struct LOGIC *r, int input);
int LOGIClearn(struct LOGIC *r, int input, int output);
int LOGICquant(struct LOGIC *r);
int LOGICremove(struct LOGIC *r, int input);
int LOGICdeleteall(struct LOGIC *r);
int LOGICdiff(int xi, int xf);	
/*
** Object Inicialize
*/
LOGIC LOGICenable(int *eeprom, int sizeeeprom, int prog)
{
	int cells;
	/***Declare Functions***/
	/***Create Object***/
	struct LOGIC l;
	//Inicialize variables
	l.mem=eeprom;
	l.sizeblock=4;
	cells=sizeeeprom/l.sizeblock;
	l.sizeeeprom=cells*l.sizeblock;
	l.page=prog;
	l.recall=0;
	l.output=0;
	//Functions pointers or Vtable to declared functions
	l.read=LOGICread;
	l.learn=LOGIClearn;
	l.quant=LOGICquant;
	l.remove=LOGICremove;
	l.deleteall=LOGICdeleteall;
	l.diff=LOGICdiff;
	/******/
	return l;
}
/*
** procedure and function
*/
/***read***/
int LOGICread(struct LOGIC *r, int input)
{
	int i1;
	int i2;
	int block[r->sizeblock];
	int keyfound;
	int diferenca;
	diferenca=r->diff(r->recall,input); // previne redundancia
	if(diferenca){//in reality there is no repetition of closed contact or open
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==r->page){
				for(i2=0;i2<r->sizeblock;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				keyfound=(block[1]==(diferenca&input) && block[2]==diferenca);//bool
				printf("diferenca&input: %d diferenca: %d\n",block[1],diferenca);
				if(keyfound){
					r->output=block[3];
					printf("read found\n");
					break;
				}else{
					printf("read not found\n");
				}
			}
		}
		r->recall=input;
	}
	printf("Page %d Eoutput -> %d\n",r->page,r->output);
	return r->output;
}
/***learn***/
int LOGIClearn(struct LOGIC *r, int input, int output)
{
	int i1;
	int i2;
	int block[r->sizeblock];
	int keyfound;
	int status=0;
	int diferenca;
	diferenca=r->diff(r->recall,input);
	if(diferenca){
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==r->page){
				for(i2=0;i2<r->sizeblock;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				keyfound=(block[1]==(diferenca&input) && block[3]==diferenca);//bool
				if(keyfound){
					status=1;//not permited
					break;
				}
			}
			status=3;//not existente
		}
	}
	if(status==3){
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==EMPTY){
				*(r->mem+i1)=r->page;
				*(r->mem+i1+1)=(diferenca&input);
				*(r->mem+i1+2)=diferenca;
				*(r->mem+i1+3)=output;
				printf("diferenca&input: %d diferenca: %d\n",(diferenca&input),diferenca);
				status=2;//created
				break;
			}
			status=4;//not possible
		}
	}
	r->recall=input;
	printf("learn status: %d\n",status);
	return status;
}
/***quant***/
int LOGICquant(struct LOGIC *r)
{
	int i1;
	int programmed;
	int block[r->sizeblock];
	for(i1=0,programmed=0;i1<r->sizeeeprom;i1+=r->sizeblock){
		if(*(r->mem+i1)!=EMPTY)
			programmed++;
	}
	//printf("there are %d programmed\n",programmed);
	return programmed;
}
/***remove***/
int LOGICremove(struct LOGIC *r, int input)
{
	int i1;
	int i2;
	int block[r->sizeblock];
	int keyfound;
	int status=0;
	int diferenca;
	diferenca=r->diff(r->recall,input);
	if(diferenca){
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==r->page){
				for(i2=0;i2<r->sizeblock;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				keyfound=(block[1]==(diferenca&input) && block[2]==diferenca);//bool
				if(keyfound){
					*(r->mem+i1)=EMPTY;
					status=1;//removed
					break;
				}
			}
		}
		r->recall=input;
	}
	printf("remove status: %d\n",status);
	return status;
}
/***deleteall***/
int LOGICdeleteall(struct LOGIC *r)
{
	int i1;
	int status=0;
	if(!status){//not removed
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)!=EMPTY){
				*(r->mem+i1)=EMPTY;
				status=1;//all deleted
			}
		}
	}
	printf("deleteall status: %d\n",status);
	return status;
}
/***diff***/
int LOGICdiff(int xi, int xf)
{
	return xi^xf;
}
/*
** interrupt
*/
/***EOF***/
