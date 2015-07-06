/*************************************************************************
Title:    PCLFSM
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PClfsm.c, v 0.1 2015/07/03 14:00:00 sergio Exp $
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
	review
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
#include"PCfunction.h"
/*
** constant and macro
*/
#define LFSM_page 0
#define LFSM_feedback 1
#define LFSM_input 2
#define LFSM_output 3
#define BlockSize 4
#define EMPTY 0
/*
** variable
*/
/*int mem[]=
{pin state, feedback, pin mask, output}
*/
/*
** procedure and function header
*/
int LFSMread(struct lfsm *r, int input);
int LFSMlearn(struct lfsm *r, int input, int next);
int LFSMquant(struct lfsm *r);
int LFSMremove(struct lfsm *r, int input);
int LFSMdeleteall(struct lfsm *r);
int LFSMoutput(struct lfsm *r);
int LFSMdiff(int xi, int xf);
/*
** Object Inicialize
*/
LFSM LFSMenable(int *eeprom, int sizeeeprom, int prog)
{
	/***Local Variable***/
	int cells;
	/***Create Object***/
	LFSM r;
	//Inicialize varibles
	r.mem=eeprom;
	cells=sizeeeprom/BlockSize;
	r.sizeeeprom=cells*BlockSize;
	r.page=prog;//page
	r.input=0;//input
	r.output=0;//output
	//Function Vtable
	r.read=LFSMread;
	r.learn=LFSMlearn;
	r.quant=LFSMquant;
	r.remove=LFSMremove;
	r.deleteall=LFSMdeleteall;
	r.get=LFSMoutput;
	r.diff=LFSMdiff;
	/******/
	return r;
}
/*
** procedure and function
*/
/***read***/
int LFSMread(struct lfsm *r, int input)
{
	int i1;
	int i2;
	int status=0;
	int block[BlockSize];
	int keyfound;
	int mask;
	FUNC func=FUNCenable();
	mask=LFSMdiff(r->input,input);
	//if(mask){
	//in reality there is no repetition of readings [oneshot], use this condition in MCU aplications
		for(i1=0;i1<r->sizeeeprom;i1+=BlockSize){
			if(*(r->mem+i1)==r->page){
				for(i2=0;i2<BlockSize;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				if(r->page<128){
					keyfound=(
						block[LFSM_feedback]==r->page &&
						block[LFSM_input]==input
						);//bool
				}else{
					keyfound=(
						block[LFSM_feedback]==r->output &&
						block[LFSM_input]==input
						);//bool
				}
				if(keyfound){
					status=1;
					break;
				}else status=2;
			}
		}
	//}else status=3;
	switch (status){
		case 0:
			printf("LFSMread -> No operation\n");
			break;
		case 1:
			printf("LFSMread updated: %d\n",status);
			r->output=block[LFSM_output];
			r->input=input;//detailed capture
			break;
		case 2:
			printf("LFSMread not existent: %d\n",status);
			break;
		case 3:
			printf("LFSMread repeated reading: %d\n",status);
			break;
		default:
			break;
	}
	printf("->->->->->->->->->->->->->->-> %s \n",func.print_binary(r->output));
	return r->output;
}
/***learn***/ 
int LFSMlearn(struct lfsm *r, int input, int next)
{
	int i1;
	int i2;
	int block[BlockSize];
	int keyfound;
	int status=0;
	for(i1=0;i1<r->sizeeeprom;i1+=BlockSize){
		if(*(r->mem+i1)==r->page){
			for(i2=0;i2<BlockSize;i2++){//get block from eeprom
				block[i2]=*(r->mem+i1+i2);
			}
			keyfound=(
				block[LFSM_feedback]==r->output &&
				block[LFSM_input]==input
				);//bool
			if(keyfound){
				status=1;//not permited
				break;
			}
		}
		status=2;//not existente
	}
	switch (status){
		case 0:
			printf("LFSMlearn No Operation.\n");
			break;
		case 1:
			printf("LFSMlearn already existent.\n");
			break;
		case 2:
			printf("LFSMlearn going to try add new program.\n");
			for(i1=0;i1<r->sizeeeprom;i1+=BlockSize){
				if(*(r->mem+i1)==EMPTY){
					*(r->mem+i1)=r->page;
					if(r->page<128){
						r->output=r->page;
						*(r->mem+i1+LFSM_feedback)=r->page;
					}else
						*(r->mem+i1+LFSM_feedback)=r->output;
					*(r->mem+i1+LFSM_input)=input;
					*(r->mem+i1+LFSM_output)=next;
					status=3;//created
					break;
				}
				status=4;//not possible
			}
		case 3:
			printf("LFSMlearn succesfully added.\n");
			break;
		case 4:
			printf("LFSMlearn memmory full.\n");
			break;
		default:
			break;
	}
	return status;
}
/***quant***/
int LFSMquant(struct lfsm *r)
{
	int i1;
	int programmed;
	printf("LFSMquant\n");
	for(i1=0,programmed=0;i1<r->sizeeeprom;i1+=BlockSize){
		if(*(r->mem+i1)!=EMPTY){
			printf("%d-%d-%d\n",*(r->mem+i1+LFSM_feedback),*(r->mem+i1+LFSM_input),*(r->mem+i1+LFSM_output));
			programmed++;
		}
	}
	return programmed;
}
/***remove***/
int LFSMremove(struct lfsm *r, int input)
{
	int i1;
	int i2;
	int block[BlockSize];
	int keyfound;
	int status=0;
	for(i1=0;i1<r->sizeeeprom;i1+=BlockSize){
		if(*(r->mem+i1)==r->page){
			for(i2=0;i2<BlockSize;i2++){//get block from eeprom
				block[i2]=*(r->mem+i1+i2);
			}
			keyfound=(
				block[LFSM_feedback]==r->output &&
				block[LFSM_input]==input
				);//bool
			if(keyfound){
				status=1;//removed
				break;
			}
		}
		status=2;//does not exist
	}
	switch (status){
		case 0:
			printf("LFSMremove -> No operation\n");
			break;
		case 1:
			printf("LFSMremove removed: %d\n",status);
			*(r->mem+i1)=EMPTY;
			break;
		case 2:
			printf("LFSMremove not existent: %d\n",status);
			break;
		default:
			break;
	}
	return status;
}
/***deleteall***/
int LFSMdeleteall(struct lfsm *r)
{
	int i1;
	int status=0;
	if(!status){//not removed
		for(i1=0;i1<r->sizeeeprom;i1+=BlockSize){
			if(*(r->mem+i1)!=EMPTY){
				*(r->mem+i1)=EMPTY;
				status=1;//all deleted
			}
		}
	}
	printf("LFSMdeleteall deleted\n");
	return status;
}
/***get***/
int LFSMoutput(struct lfsm *r)
{
	return r->output;
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
/***Comments**
Reality works like this:
keyfound=(
	block[LFSM_feedback]==r->output &&
	block[LFSM_mask]==mask && 
	block[LFSM_maskedinput]==(mask&input)
);//bool, block[1] is masked bits, block[1] is bits state
				**************



*************/
