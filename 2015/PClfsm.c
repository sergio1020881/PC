/*************************************************************************
Title:    PCLFSM
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PClfsm.c, v 0.1 2015/02/16 14:00:00 sergio Exp $
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
#define EMPTY 0
#define LFSM_page 0
#define LFSM_mask 1
#define LFSM_maskedinput 2
#define LFSM_feedback 3
#define LFSM_output 4
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
int LFSMdiff(int xi, int xf);
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
	/***Create Object***/
	LFSM r;
	//Inicialize varibles
	r.mem=eeprom;
	r.sizeblock=5;
	cells=sizeeeprom/r.sizeblock;
	r.sizeeeprom=cells*r.sizeblock;
	r.page=prog;//page
	r.input=0;//input
	r.output=0;//output
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
	int mask;
	FUNC func=FUNCenable();
	mask=LFSMdiff(r->input,input);
	printf("-%s-\n",func.print_binary(mask));
	if(mask){//in reality there is no repetition of closed contact or open [oneshot]
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==r->page){
				for(i2=0;i2<r->sizeblock;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				keyfound=(
					block[LFSM_mask]==mask && 
					block[LFSM_maskedinput]==(mask&input) && 
					block[LFSM_feedback]==feedback);//bool, block[1] is masked bits, block[1] is bits state
				if(keyfound){
					r->output=block[LFSM_output];
					printf("Found\n");
					printf("%s->%s->%s\n",func.print_binary(LFSM_mask),func.print_binary(block[LFSM_maskedinput]),func.print_binary(block[LFSM_feedback]));
					r->input=input;//detailed
					break;
				}else{
					//printf("Not found\n");
					//printf("%d -> %d -> %d -> %d\n",block[LFSM_mask],block[LFSM_maskedinput],block[LFSM_feedback],block[LFSM_output]);
				}
			}else{
			}
		}
			//r->input=input;//necessary
	}else{
		printf("Repeated input.\n");
	}
	//printf("->->->->->->-> %d\n",r->block[LFSM_output]);
	printf("->->->->->->->->->->->->->->-> %s ",func.print_binary(r->output));
	return r->output;
}
/***learn***/
int LFSMlearn(struct lfsm *r, int input, int next, int feedback)
{
	int i1;
	int i2;
	int block[r->sizeblock];
	int keyfound;
	int status=0;
	int mask;
	mask=LFSMdiff(r->input,input); // difference is the mask, diference is a filter.
	if(mask){
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==r->page){
				for(i2=0;i2<r->sizeblock;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				keyfound=(block[LFSM_mask]==mask && block[LFSM_maskedinput]==(mask&input) && block[LFSM_feedback]==feedback);//bool
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
				*(r->mem+i1+1)=mask;
				*(r->mem+i1+2)=(mask&input);
				*(r->mem+i1+3)=feedback;
				*(r->mem+i1+4)=next;
				status=2;//created
				break;
			}
			status=4;//not possible
		}
	}
	//r->input=input;
	switch (status){
		case 0:
			printf("repeated input not allowed.\n");
			break;
		case 1:
			printf("already existent.\n");
			break;
		case 2:
			printf("succesfully added.\n");
			break;
		case 3:
			printf("going to try add new program.\n");
			break;
		case 4:
			printf("memmory full.\n");
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
	int mask;
	mask=LFSMdiff(r->input,input);
	if(mask){
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==r->page){
				for(i2=0;i2<r->sizeblock;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				keyfound=(block[LFSM_mask]==mask && block[LFSM_maskedinput]==(mask&input) && block[LFSM_feedback]==present);//bool
				if(keyfound){
					*(r->mem+i1)=EMPTY;
					status=1;//removed
					break;
				}
			}
		}
		r->input=input;
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
	//printf("FSMget: %d\n",r->block[LFSM_output]);
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
