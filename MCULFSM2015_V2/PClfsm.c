/*************************************************************************
Title:    PCLFSM
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PClfsm.c, v 0.1 2015/08/01 14:00:00 sergio Exp $
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
	working on it.
	working pretty good, trial more.
	page=1 is dedicated for logic, if page>1 is sequencial program.
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
/******/
#define LFSM_page 0
#define LFSM_feedback 1
#define LFSM_input 2
#define LFSM_inhl 3
#define LFSM_inlh 4
#define LFSM_output 5
#define LFSM_outhl 6
#define LFSM_outlh 7
#define BlockSize 8
/*
** variable
*/
/*
unsigned int mem[]=
{pin state, feedback, pin mask, output}
*/
/*
** procedure and function header
*/
unsigned int LFSMread(struct lfsm *r, unsigned int input);
unsigned int LFSMlearn(struct lfsm *r, unsigned int input, unsigned int next, unsigned int page);
unsigned int LFSMquant(struct lfsm *r);
unsigned int LFSMremove(struct lfsm *r, unsigned int input);
unsigned int LFSMdeleteall(struct lfsm *r);
/*
** Object Inicialize
*/
LFSM LFSMenable(unsigned int *eeprom, unsigned int sizeeeprom)
{
	/***Local Variable***/
	unsigned int cells;
	/***Local Function Header***/
	unsigned int LFSMgetoutput(struct lfsm *r);
	void LFSMsetoutput(struct lfsm *r, unsigned int output);
	unsigned int LFSMlh(unsigned int xi, unsigned int xf);
	unsigned int LFSMhl(unsigned int xi, unsigned int xf);
	unsigned int LFSMoutputcalc(unsigned int feedback, unsigned int hl, unsigned int lh);
	unsigned int LFSMdiff(unsigned int xi, unsigned int xf);
	/***Create Object***/
	LFSM r;
	//Inicialize varibles
	r.mem=eeprom;
	cells=sizeeeprom/BlockSize;
	r.sizeeeprom=cells*BlockSize;
	r.input=0;//input
	r.output=0;//output
	//Function Vtable
	r.read=LFSMread;
	r.learn=LFSMlearn;
	r.quant=LFSMquant;
	r.remove=LFSMremove;
	r.deleteall=LFSMdeleteall;
	r.get=LFSMgetoutput;
	r.set=LFSMsetoutput;
	r.lh=LFSMlh;
	r.hl=LFSMhl;
	r.outputcalc=LFSMoutputcalc;
	r.diff=LFSMdiff;
	/******/
	return r;
}
/*
** procedure and function
*/
/***read***/
unsigned int LFSMread(struct lfsm *r, unsigned int input)
{
	unsigned int i1;
	unsigned int i2;
	unsigned int status=0;
	unsigned int block[BlockSize];
	unsigned int keyfound;
	printf("LFSMread\n");
	//if(r->diff(r->input,input)){
		//in reality there is no repetition of readings [oneshot], use this condition in MCU aplications
		for(i1=0;i1<r->sizeeeprom;i1+=BlockSize){
			if(*(r->mem+i1)){
				/******/
				for(i2=0;i2<BlockSize;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				/******/
				switch(block[LFSM_page]){
					case 1:
						keyfound=(
							block[LFSM_inhl]==r->hl(r->input,input) && 
							block[LFSM_inlh]==r->lh(r->input,input)
							);//bool
						//it keeps track of previous input, not desired in logic
						break;
					case 2:
						keyfound=(
							block[LFSM_feedback]==r->output &&
							block[LFSM_inhl]==r->hl(r->input,input) && 
							block[LFSM_inlh]==r->lh(r->input,input)
							);//bool
						//it keeps track of previous input, not desired in logic
						break;
					default:
						keyfound=(
							block[LFSM_feedback]==r->output &&
							block[LFSM_input]==r->input &&
							block[LFSM_inhl]==r->hl(r->input,input) && 
							block[LFSM_inlh]==r->lh(r->input,input)
							);//bool
						break;
				};
				/******/
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
			r->page=block[LFSM_page];
			r->input=input;//detailed capture
			r->output=r->outputcalc(block[LFSM_feedback],block[LFSM_outhl],block[LFSM_outlh]);
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
	return r->output;
}
/***learn***/ 
unsigned int LFSMlearn(struct lfsm *r, unsigned int input, unsigned int next, unsigned int page)
{
	unsigned int i1;
	unsigned int i2;
	unsigned int block[BlockSize];
	unsigned int keyfound;
	unsigned int status=0;
	printf("LFSMlearn\n");
	if(page>0){
		//if(r->diff(r->input,input)){
			for(i1=0;i1<r->sizeeeprom;i1+=BlockSize){
				if(*(r->mem+i1)){
					/******/
					for(i2=0;i2<BlockSize;i2++){//get block from eeprom
						block[i2]=*(r->mem+i1+i2);
					}
					/******/
					printf("LFSMlearn_page %d\n",page);
					keyfound=(
						(
						block[LFSM_page]==1 &&
						block[LFSM_inhl]==r->hl(r->input,input) && 
						block[LFSM_inlh]==r->lh(r->input,input)
						)
							||
						(
						block[LFSM_page]==2 &&
						block[LFSM_feedback]==r->output &&
						block[LFSM_inhl]==r->hl(r->input,input) && 
						block[LFSM_inlh]==r->lh(r->input,input)
						)
							||
						(
						block[LFSM_feedback]==r->output &&
						block[LFSM_input]==r->input &&
						block[LFSM_inhl]==r->hl(r->input,input) && 
						block[LFSM_inlh]==r->lh(r->input,input)
						)
					);//bool
					//if there is any logic entry, that entry is taken out from lfsm input options
					/******/
					if(keyfound){
						status=1;//not permited
						break;
					}
				}
			status=2;//not existente
			}
		//}
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
					*(r->mem+i1)=page;
					*(r->mem+i1+LFSM_feedback)=r->output;
					*(r->mem+i1+LFSM_input)=r->input;
					*(r->mem+i1+LFSM_inhl)=r->hl(r->input,input);
					*(r->mem+i1+LFSM_inlh)=r->lh(r->input,input);
					*(r->mem+i1+LFSM_output)=next;
					*(r->mem+i1+LFSM_outhl)=r->hl(r->output,next);
					*(r->mem+i1+LFSM_outlh)=r->lh(r->output,next);
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
unsigned int LFSMquant(struct lfsm *r)
{
	unsigned int i1;
	unsigned int programmed;
	printf("LFSMquant\n");
	for(i1=0,programmed=0;i1<r->sizeeeprom;i1+=BlockSize){
		if(*(r->mem+i1)!=EMPTY){
			printf("page:%d feedback:%d input: %d inhl:%d inlh:%d output:%d outhl:%d outlh:%d\n",*(r->mem+i1+LFSM_page),*(r->mem+i1+LFSM_feedback),*(r->mem+i1+LFSM_input),*(r->mem+i1+LFSM_inhl),*(r->mem+i1+LFSM_inlh),*(r->mem+i1+LFSM_output),*(r->mem+i1+LFSM_outhl),*(r->mem+i1+LFSM_outlh));
			programmed++;
		}
	}
	return programmed;
}
/***remove***/
unsigned int LFSMremove(struct lfsm *r, unsigned int input)
{
	unsigned int i1;
	unsigned int i2;
	unsigned int block[BlockSize];
	unsigned int keyfound;
	unsigned int status=0;
	printf("LFSMremove\n");
	for(i1=0;i1<r->sizeeeprom;i1+=BlockSize){
		if(*(r->mem+i1)){
			printf("LFSMremove\n");
			for(i2=0;i2<BlockSize;i2++){//get block from eeprom
				block[i2]=*(r->mem+i1+i2);
			}
			/******/	
			switch(block[LFSM_page]){
				case 1:
					keyfound=(
						block[LFSM_inhl]==r->hl(r->input,input) && 
						block[LFSM_inlh]==r->lh(r->input,input)
						);//bool
					break;
				case 2:
					keyfound=(
						block[LFSM_feedback]==r->output &&
						block[LFSM_inhl]==r->hl(r->input,input) && 
						block[LFSM_inlh]==r->lh(r->input,input)
						);//bool
					break;
				default:
					keyfound=(
						block[LFSM_feedback]==r->output &&
						block[LFSM_input]==r->input &&
						block[LFSM_inhl]==r->hl(r->input,input) && 
						block[LFSM_inlh]==r->lh(r->input,input)
						);//bool
					break;
			};
			/******/
			if(keyfound){
				status=1;//remove
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
unsigned int LFSMdeleteall(struct lfsm *r)
{
	unsigned int i1;
	unsigned int status=0;
	if(!status){//not removed
		for(i1=0;i1<r->sizeeeprom;i1+=BlockSize){
			if(*(r->mem+i1)){
				*(r->mem+i1)=EMPTY;
				status=1;//all deleted
			}
		}
	}
	printf("LFSMdeleteall deleted\n");
	return status;
}
/***get***/
unsigned int LFSMgetoutput(struct lfsm *r)
{
	return r->output;
}
/***set***/
void LFSMsetoutput(struct lfsm *r, unsigned int output)
{
	r->output=output;
}
/***lh***/
unsigned int LFSMlh(unsigned int xi, unsigned int xf)
{
	unsigned int i;
	i=xf^xi;
	i&=xf;
	return i;
}
/***hl***/
unsigned int LFSMhl(unsigned int xi, unsigned int xf)
{
	unsigned int i;
	i=xf^xi;
	i&=xi;
	return i;
}
/***output***/
unsigned int LFSMoutputcalc(unsigned int feedback, unsigned int hl, unsigned int lh)
{
	feedback|=lh;
	feedback&=~hl;
	return feedback;
}
/***diff***/
unsigned int LFSMdiff(unsigned int xi, unsigned int xf)
{
	return xi^xf;
}
/*
** interrupt
*/
/***EOF***/
/***Comments**
Reality works like this:
keyfound=(
	block[LFSM_feedback]==r->output &&
	block[LFSM_mask]==mask && 
	block[LFSM_maskedinput]==(mask&input)
);//bool, block[1] is masked bits, block[1] is bits state				
**************
NOTES:
unsigned int vect[]=
{
mask,mask&pinstate,feedback,output,
};
**************
try to make more depth choice of database research or option selections.
*************/
