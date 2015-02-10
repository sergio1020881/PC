/*************************************************************************
Title:    PCLFSM
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PClfsm.c, v 0.1 2015/02/06 14:00:00 sergio Exp $
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
#include"PClfsm.h"
/*
** constant and macro
*/
#define EMPTY 0
#define TRUE 1
#define EMPTY 0 //on a pc vectores are at zero therefore empty is zero.
#define HIGH 1
#define high 1
#define LOW 0
#define low 0
/*
** variable
*/
char LFSMstr[16];
/*int mem[]=
{pin state, feedback, pin mask, output}
*/
/*
** procedure and function header
*/
/*
** Object Inicialize
*/
LFSM LFSMenable(int *eeprom, int sizeeeprom, int prog)
{
	int cells;
	/***Declare Functions***/
	int LFSMread(struct lfsm *r, int input, int feedback);
	int LFSMlearn(struct lfsm *r, int input, int next, int feedback);
	int LFSMquant(struct lfsm *r);
	int LFSMremove(struct lfsm *r, int input, int present);
	int LFSMdeleteall(struct lfsm *r);
	int LFSMstate(struct lfsm *r);
	int LFSMdiff(int xi, int xf);
	/***Create Object***/
	LFSM r;
	//Inicialize varibles
	r.mem=eeprom;
	r.sizeblock=5;
	cells=sizeeeprom/r.sizeblock;
	r.sizeeeprom=cells*r.sizeblock;
	r.page=prog;
	r.recall=0;
	r.present=0;
	//Function Vtable
	r.read=LFSMread;
	r.learn=LFSMlearn;
	r.quant=LFSMquant;
	r.remove=LFSMremove;
	r.deleteall=LFSMdeleteall;
	r.get=LFSMstate;
	r.diff=LFSMdiff;
	/******/
	return r;
}
/*
** procedure and function
*/
/***read***/
int LFSMread(struct lfsm *r, int input, int feedback)
{
	int i1;
	int i2;
	int block[r->sizeblock];
	int keyfound;
	int diferenca;
	diferenca=r->diff(r->recall,input); // diferenca igual a mask
	if(diferenca){//in reality there is no repetition of closed contact or open
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==r->page){
				for(i2=0;i2<r->sizeblock;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				keyfound=(block[1]==(diferenca&input) && block[2]==feedback &&
				block[3]==diferenca);//bool, block[3] is masked bits, block[1] is bits state
				printf("diferenca&input: %d diferenca: %d\n",block[1],diferenca);
				if(keyfound){
					r->present=block[4];
					printf("read found\n");
					break;
				}else{
					printf("read not found\n");
				}
			}
		}
		r->recall=input;
	}
	printf("Page %d Eoutput -> %d\n",r->page,r->present);
	return r->present;
}
/***learn***/
int LFSMlearn(struct lfsm *r, int input, int next, int feedback)
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
				keyfound=(block[1]==(diferenca&input) && block[2]==feedback &&
				block[3]==diferenca);//bool
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
				*(r->mem+i1+2)=feedback;
				*(r->mem+i1+3)=diferenca;
				*(r->mem+i1+4)=next;
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
int LFSMquant(struct lfsm *r)
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
int LFSMremove(struct lfsm *r, int input, int present)
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
				keyfound=(block[1]==(diferenca&input) && block[2]==present &&
				block[3]==diferenca);//bool
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
int LFSMdeleteall(struct lfsm *r)
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
/***get***/
int LFSMstate(struct lfsm *r)
{
	//printf("FSMget: %d\n",r->present);
	return r->present;
}
/***diff***/
int LFSMdiff(int xi, int xf)
{
	return xi^xf;
}
/*
** interrupt
*/
/***EOF***/
/**
NOTES:
int vect[]=
{
mask,mask&pinstate,feedback,output,
};
**/
