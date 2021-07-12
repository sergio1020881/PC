/*************************************************************************
Title:    PCLFSM
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PClfsm.c, v 0.1 2018/08/16 11:00:00 sergio Exp $
Software: GCC
Hardware: PC
License:  GNU General Public License
Description:
	PC emulation
Comment:
	working pretty good, trial more.
	page=1 is dedicated for Global logic, page>=2 Local logic.
*************************************************************************/
#include"PClfsm.h"
/*
** constant and macro
*/
#define EMPTY 0
/*
** variable
*/
LFSMDATA data;
unsigned int x;
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
unsigned int LFSMvalidate(struct lfsm *r, unsigned int n);
/*
** Object Inicialize
*/
LFSM LFSMenable(LFSMDATA *eeprom, unsigned int sizeeeprom)
{
	/***Local Variable***/
	printf("-\tLFSMenable\n");
	/***Local Function Header***/
	unsigned int LFSMgetoutput(struct lfsm *r);
	void LFSMsetoutput(struct lfsm *r, unsigned int output);
	unsigned int LFSMlh(unsigned int xi, unsigned int xf);
	unsigned int LFSMhl(unsigned int xi, unsigned int xf);
	unsigned int LFSMoutputcalc(unsigned int feedback, unsigned int hl, unsigned int lh);
	unsigned int LFSMdiff(unsigned int xi, unsigned int xf);
	/***Create Object***/
	LFSM r;
	//Inicialize variables
	r.mem=eeprom;
	r.sizeeeprom=sizeeeprom;
    x=0;
	r.page=0;//page
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
    r.validate=LFSMvalidate;
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
	unsigned int status=0;
	unsigned int HL,LH;
	printf("-\tLFSMread\n");
	HL=r->hl(r->input,input);
	LH=r->lh(r->input,input);
	if(HL || LH){
        status=3;
		for(i1=0;i1<r->sizeeeprom;i1++){
            data=r->mem[i1];//upload eeprom data
            switch(data.page){
                case 0:
                    //status=3;
                    break;
			    case 1:
			        if( data.inhl==HL && data.inlh==LH ){
                        //Global logic
                        i1=r->sizeeeprom;
                        status=1;
                    }//else
                        //status=4;
				    break;
				default:
					if( data.feedback==r->output && data.inhl==HL && data.inlh==LH ){
						//Local logic
                        i1=r->sizeeeprom;
                        status=2;
                    }//else
                        //status=5;
				    break;
			};
		}
	}
	switch (status){
		case 0:
			printf("LFSMread: [0] No entry\n");
			//r->input=input;//detailed capture
			break;
		case 1:
            printf("LFSMread: [1] Global logic\n");
			r->page=data.page;
			r->input=input;//detailed capture
			r->output=r->outputcalc(data.feedback,data.outhl,data.outlh);
			break;
		case 2:
			printf("LFSMread: [2] Local logic\n");
			r->page=data.page;
			r->input=input;//detailed capture
			r->output=r->outputcalc(data.feedback,data.outhl,data.outlh);
			break;
		case 3:
			printf("LFSMread: [3] Entry Not recognized\n");
			r->input=input;//detailed capture
			break;
        //case 4:
			//printf("LFSMread: [4] Entry Not recognized\n");
            //Give warning or block waiting for instructions
			//r->input=input;//detailed capture
			//break;
        //case 5:
			//printf("LFSMread: [5] Entry Not recognized\n");
            //Give warning or block waiting for instructions
			//r->input=input;//detailed capture
			//break;
		default:
			//impossible situation
			break;
	}
	//printf("input: %d\n",r->input);
	return r->output;
}
/***learn***/
unsigned int LFSMlearn(struct lfsm *r, unsigned int input, unsigned int next, unsigned int page)
{
	unsigned int i1;
	unsigned int status=0;
	unsigned int HL,LH;
	printf("-\tLFSMlearn\n");
	HL=r->hl(r->input,input);
	LH=r->lh(r->input,input);
	if(page>0){
		if(HL || LH){
			for(i1=0;i1<r->sizeeeprom;i1++){
				data=r->mem[i1];
				if(data.page){
					if((data.page==1 && data.inhl==HL && data.inlh==LH) || (data.feedback==r->output && data.inhl==HL && data.inlh==LH)){
						status=1;
						break;
					}
				}
			    status=2;
			}
		}
	}
	switch (status){
		case 0:
			printf("LFSMlearn: [0] No Operation.\n");
			break;
		case 1:
			printf("LFSMlearn: [1] Not permitted.\n");
			break;
		case 2:
			printf("LFSMlearn: [2] Going to try add new program.\n");
			//prepare data to write to eeprom
			data.page=page;
			data.feedback=r->output;
			//data.input=r->input;
			data.inhl=HL;
			data.inlh=LH;
			data.outhl=r->hl(r->output,next);
			data.outlh=r->lh(r->output,next);
			printf("%d  %d  %d  %d  %d  %d\n",data.page,data.feedback,data.inhl,data.inlh,data.outhl,data.outlh);
			for(i1=0;i1<r->sizeeeprom;i1++){
				//search empty space in memory
				if(r->mem[i1].page==EMPTY){
					//write data to eeprom
					r->mem[i1]=data;
					status=3;
					break;
				}
				status=4;
			}
		case 3:
			printf("LFSMlearn: [3] succesfully added.\n");
			break;
		case 4:
			printf("LFSMlearn: [4] Memmory full.\n");
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
	printf("-\tLFSMquant\n");
	for(i1=0,programmed=0;i1<r->sizeeeprom;i1++){
		data=r->mem[i1];//upload data from eeprom
		if(data.page!=EMPTY){
			printf("page:%d feedback:%d : [ inhl:%d inlh:%d ] -- [ outhl:%d  outlh:%d ]\n",data.page,data.feedback,data.inhl,data.inlh,data.outhl,data.outlh);
			programmed++;
		}
	}
	return programmed;
}
/***remove***/
unsigned int LFSMremove(struct lfsm *r, unsigned int input)
{
	unsigned int k,i1;
	unsigned int status=0;
	unsigned int HL,LH;
	printf("-\tLFSMremove\n");
	HL=r->hl(r->input,input);
	LH=r->lh(r->input,input);
	for(i1=0;i1<r->sizeeeprom;i1++){
		data=r->mem[i1];//upload data from eeprom
		switch(data.page){
            case 0:
                status=2;
                break;
	        case 1:
			    if(data.inhl==HL && data.inlh==LH){
                    status=1;
                    k=i1;
                    i1=r->sizeeeprom;
                }
                break;
		    default:
				if(data.feedback==r->output && data.inhl==HL && data.inlh==LH){
                    status=1;
                    k=i1;
                    i1=r->sizeeeprom;
                }
				break;
		};
	}
	switch (status){
		case 0:
			printf("LFSMremove: [0] No operation\n");
			break;
		case 1:
			printf("LFSMremove: [1] Removed: %d\n",status);
			//descativate memory space, write to eeprom empty space.
			r->mem[k].page=EMPTY;
			break;
		case 2:
			printf("LFSMremove: [2] Not existent: %d\n",status);
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
	printf("-\tLFSMdeleteall\n");
	if(!status){//not removed
		for(i1=0;i1<r->sizeeeprom;i1++){
			//read eeprom check if memory space has data
			if(r->mem[i1].page){
				//desactivate memory space to empty
				r->mem[i1].page=EMPTY;
				status=1;//all deleted
			}
		}
	}
	r->output=0;
	printf("LFSMdeleteall: Done\n");
	return status;
}
/***get***/
unsigned int LFSMgetoutput(struct lfsm *r)
{
	//printf("-\tLFSMgetoutput\n");
	return r->output;
}
/***set***/
void LFSMsetoutput(struct lfsm *r, unsigned int output)
{
	//printf("-\tLFSMsetoutput\n");
	r->output=output;
}
/***lh***/
unsigned int LFSMlh(unsigned int xi, unsigned int xf)
{
	unsigned int i;
	//printf("-\tLFSMlh\n");
	i=xf^xi;
	i&=xf;
	return i;
}
/***hl***/
unsigned int LFSMhl(unsigned int xi, unsigned int xf)
{
	unsigned int i;
	//printf("-\tLFSMhl\n");
	i=xf^xi;
	i&=xi;
	return i;
}
/***output***/
unsigned int LFSMoutputcalc(unsigned int feedback, unsigned int hl, unsigned int lh)
{
	//printf("-\tLFSMoutputcalc\n");
	feedback|=lh;
	feedback&=~hl;
	return feedback;
}
/***diff***/
unsigned int LFSMdiff(unsigned int xi, unsigned int xf)
{
	//printf("-\tLFSMdiff\n");
	return xi^xf;
}
unsigned int LFSMvalidate(struct lfsm *r, unsigned int n)
{
    unsigned int k;
    k=r->input | (n & (1<<x));
    if(x>7)
        x=0;
    x++;
    return k;
}
/*
** interrupt
*/
/**Comment**
If one can not see what is in front of them, let them stay in ignorance.

************/
/***EOF***/
