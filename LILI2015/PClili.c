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
	perfect
*************************************************************************/
/*
** library
*/
// fopen perror fread fwrite feof fseek ferror fclose rewind scanf sscanf getchar scanf fscanf
#include <stdio.h>
// calloc free realloc malloc
#include <stdlib.h>
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
#define RMFR 0
/*
** variable
*/
/*
** procedure and function header
*/
char* LILIplay(struct lili *l);
unsigned int LILIforward(struct lili *l);
unsigned int LILIreverse(struct lili *l);
unsigned int LILIrecord(struct lili *l, char* data);
unsigned int LILIremove(struct lili *l);
unsigned int LILIquant(struct lili *l);
unsigned int LILIstatus(struct lili *l);
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
	l.data=NULL;
	l.total=0;
	//Function Vtable
	l.play=LILIplay;
	l.forward=LILIforward;
	l.reverse=LILIreverse;
	l.record=LILIrecord;
	l.remove=LILIremove;
	l.quant=LILIquant;
	l.status=LILIstatus;
	/******/
	return l;
}
/*
** procedure and function
*/
/***lead***/
char* LILIplay(struct lili *l)
{
	if(l->target==NULL)
		printf("Linked List EMPTY\n");
<<<<<<< HEAD
	else
		return l->data;
=======
	return l->data;
>>>>>>> origin/master
}
/***learn***/ 
unsigned int LILIforward(struct lili *l)
{
	if(l->target==NULL)
		printf("Linked List EMPTY\n");
	else{	
		l->target=l->target->next;
		l->data=l->target->data;
	}
	return 0;
}
/***quant***/
unsigned int LILIreverse(struct lili *l)
{
	if(l->target==NULL)
		printf("Linked List EMPTY\n");
	else{	
		l->target=l->target->back;
		l->data=l->target->data;
	}
	return 0;
}
/***lemove***/
unsigned int LILIrecord(struct lili *l, char* data)
{
	if(l->target==NULL){//INICIALIZE LIST
		l->target=(LILIDATA*)calloc(1,sizeof(LILIDATA));
		l->target->next=l->target->back=l->target;
		l->data=l->target->data=data;
		l->total++;
	}else{
		if(l->target->next==l->target){
			l->target->next=(LILIDATA*)calloc(1,sizeof(LILIDATA));
			l->target->next->next=l->target->next;
			l->target->next->back=l->target;
			l->target->next->data=data;
			/****/
			l->target=l->target->next;
			l->data=l->target->data;
			l->total++;	
		}else{
			printf("Record only permitted at end of list, append only\n");
		}
	}
	return 0;
}
/***deleteall***/
unsigned int LILIremove(struct lili *l)
{
<<<<<<< HEAD
	struct lili *ptr;
=======
	LILIDATA *ptr;
>>>>>>> origin/master
	if(l->target==NULL)
		printf("Linked List EMPTY\n");
	else{
		if(l->target->next==l->target->back){
			printf("troubleshoot: if((l->target->next==l->target->back) «ONLY ONE»\n");//ONLY ONE			
			free(l->target);
			l->target=NULL;
			l->data=NULL;
			l->total--;
		}else if(l->target->back==l->target){
			printf("troubleshoot: if((l->target->back==l->target) «FIRST IN LIST»\n");//FIRST IN LIST
			ptr=l->target;
			l->target->next->back=l->target->next;			
			/****/
			l->target=l->target->next;
			l->data=l->target->data;
			l->total--;
			free(ptr);
		}else if(l->target->next==l->target){
			printf("troubleshoot: if((l->target->next==l->target) «LAST IN LIST»\n");//LAST IN LIST
			ptr=l->target;			
			l->target->back->next=l->target->back;
			/****/
			l->target=l->target->back;
			l->data=l->target->data;
			l->total--;
			free(ptr);
		}else{
			printf("troubleshoot: In between «IN BETWEEN»\n");//IN BETWEEN
			ptr=l->target;
			l->target->next->back=l->target->back;
			l->target->back->next=l->target->next;
			/***choice**/
			if(RMFR){
				l->target=l->target->back;
			}else{
				l->target=l->target->next;
			}
			l->data=l->target->data;
			l->total--;
			free(ptr);
		}
	}
	return 0;
}
unsigned int LILIquant(struct lili *l)
{
	return l->total;
}
unsigned int LILIstatus(struct lili *l)
{
	if(l->target==NULL)
		printf("Linked List EMPTY\n");
	else{
		printf("ADDRESSES:\n");
		printf("l->target: %ld\nl->target->next: %ld\nl->target->back: %ld\nl->target->data: %ld\n",(long int)l->target,(long int)l->target->next,(long int)l->target->back,(long int)l->target->data);
		printf("target data: %s\n",l->target->data);
	}
	return 0;
}

/*
** interrupt
*/
/***EOF***/
