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
/***/
#include"PClili.h"
/*
** constant and macro
*/
#define EMPTY 0
#define RMFR 1
#define INSFR 1
/*
** variable
*/
/*
** procedure and function header
*/
char* LILIplay(struct lili *l);
void LILIforward(struct lili *l);
void LILIreverse(struct lili *l);
void LILIrecord(struct lili *l, char* data);
void LILIremove(struct lili *l);
void LILIfree(struct lili *l);
unsigned int LILIquant(struct lili *l);
void LILIstatus(struct lili *l);
/***to be implemented***/
void LILIinsert(struct lili *l, char* data);
void LILIreplace(struct lili *l, char* data);
void LILIpush(struct lili *l, char* data);
char* LILIpop(struct lili *l);
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
	l.tail=NULL;
	l.head=NULL;
	l.data=NULL;
	l.total=0;
	//Function Vtable
	l.play=LILIplay;
	l.forward=LILIforward;
	l.reverse=LILIreverse;
	l.record=LILIrecord;
	l.remove=LILIremove;
	l.free=LILIfree;
	l.quant=LILIquant;
	l.status=LILIstatus;
	l.insert=LILIinsert;
	l.replace=LILIreplace;
	l.push=LILIpush;
	l.pop=LILIpop;
	/******/
	return l;
}
/*
** procedure and function
*/
/***play***/
char* LILIplay(struct lili *l)
{
	if(l->target==NULL){
		printf("Linked List EMPTY\n");
		return NULL;
	}else{
		return *l->data;
	}
}
/***forward***/ 
void LILIforward(struct lili *l)
{
	if(l->target==NULL)
		printf("Linked List EMPTY\n");
	else{	
		l->target=l->target->next;
		l->data=&l->target->data;
	}
}
/***reverse***/
void LILIreverse(struct lili *l)
{
	if(l->target==NULL)
		printf("Linked List EMPTY\n");
	else{	
		l->target=l->target->back;
		l->data=&l->target->data;
	}
}
/***record***/
void LILIrecord(struct lili *l, char* data)
{
	if(l->target==NULL){//INICIALIZE LIST
		l->target=(LILIDATA*)calloc(1,sizeof(LILIDATA));
		l->target->next=l->target->back=l->target;
		l->target->data=data;
		/***/
		l->tail=l->head=l->target;
		l->data=&l->target->data;
		l->total++;
	}else{
		if(l->target->next==l->target){
			l->target->next=(LILIDATA*)calloc(1,sizeof(LILIDATA));
			l->target->next->next=l->target->next;
			l->target->next->back=l->target;
			l->target->next->data=data;
			/****/
			l->target=l->target->next;
			l->head=l->target;
			l->data=&l->target->data;
			l->total++;	
		}else{
			printf("Record only permitted at end of list, append only\n");
		}
	}
}
/***remove***/
void LILIremove(struct lili *l)
{
	LILIDATA *ptr;
	if(l->target==NULL)
		printf("Linked List EMPTY\n");
	else{
		if(l->target->next==l->target->back){
			printf("troubleshoot: if((l->target->next==l->target->back) «ONLY ONE»\n");//ONLY ONE
			free(l->target->data);
			free(l->target);
			l->target=NULL;
			l->tail=NULL;
			l->head=NULL;
			l->data=NULL;
			l->total--;
		}else if(l->target->back==l->target){
			printf("troubleshoot: if((l->target->back==l->target) «FIRST IN LIST»\n");//FIRST IN LIST
			ptr=l->target;
			l->target->next->back=l->target->next;			
			/****/
			l->target=l->target->next;
			l->tail=l->target;
			l->data=&l->target->data;
			l->total--;
			free(ptr->data);
			free(ptr);
		}else if(l->target->next==l->target){
			printf("troubleshoot: if((l->target->next==l->target) «LAST IN LIST»\n");//LAST IN LIST
			ptr=l->target;			
			l->target->back->next=l->target->back;
			/****/
			l->target=l->target->back;
			l->head=l->target;
			l->data=&l->target->data;
			l->total--;
			free(ptr->data);
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
			l->data=&l->target->data;
			l->total--;
			free(ptr->data);
			free(ptr);
		}
	}
}
/***free***/
void LILIfree(struct lili *l)
{
	while(l->target)
		LILIremove(l);
}
/***quant***/
unsigned int LILIquant(struct lili *l)
{
	return l->total;
}
/***status***/
void LILIstatus(struct lili *l)
{
	if(l->target==NULL)
		printf("Linked List EMPTY\n");
	else{
		printf("TARGET ADDRESSES:\n");
		printf("(long int)l->target: %ld\n(long int)l->target->next: %ld\n(long int)l->target->back: %ld\n(long int)l->target->data: %ld\n",(long int)l->target,(long int)l->target->next,(long int)l->target->back,(long int)l->target->data);
		printf("DATA ADDRESS:\n");
		printf("&l->data: %ld\n",(long int)&l->data);
		printf("l->data: %ld\n",(long int)l->data);
		printf("(long int)*l->data: %ld\n",(long int)*l->data);
		printf("(long int)l->target->data: %ld\n",(long int)l->target->data);
		printf("DATA:\n");
		printf("**l->data: %c\n",**l->data);
		printf("*l->data: %s\n",*l->data);
	}
}
/***insert***/
void LILIinsert(struct lili *l, char* data)
{
	LILIDATA* ptr;
	ptr=(LILIDATA*)calloc(1,sizeof(LILIDATA));
	ptr->data=data;
	if(l->target==NULL){//INICIALIZE LIST
		l->target=ptr;
		l->target->next=l->target->back=l->target;
		l->target->data=ptr->data;
		/***/
		l->tail=l->head=l->target;
		l->data=&l->target->data;
		l->total++;
	}if(l->target->next==l->target->back){
		printf("troubleshoot: if((l->target->next==l->target->back) «ONLY ONE»\n");//ONLY ONE
		if(INSFR){
		
		
		
		
		}else{
		
		
		
		
		}
	}else if(l->target->back==l->target){
		printf("troubleshoot: if((l->target->back==l->target) «FIRST IN LIST»\n");//FIRST IN LIST
		if(INSFR){
		
		
		
		
		}else{
		
		
		
		
		}
	}else if(l->target->next==l->target){
		printf("troubleshoot: if((l->target->next==l->target) «LAST IN LIST»\n");//LAST IN LIST
		if(INSFR){
		
		
		
		
		}else{
		
		
		
		
		}
	}else{
		printf("troubleshoot: In between «IN BETWEEN»\n");//IN BETWEEN
		if(INSFR){
		
		
		
		
		}else{
		
		
		
		
		}
	}
}
/***replace***/
void LILIreplace(struct lili *l, char* data)
{
	if(l->target==NULL){
		printf("Linked List EMPTY\n");
	}else{
		free(l->target->data);
		l->target->data=data;
		/****/
		l->data=&l->target->data;	
	}
}
/***push***/
void LILIpush(struct lili *l, char* data)
{
	LILIDATA* ptr;
	if(l->target==NULL){//INICIALIZE LIST
		l->target=(LILIDATA*)calloc(1,sizeof(LILIDATA));
		l->target->next=l->target->back=l->target;
		l->target->data=data;
		/***/
		l->tail=l->head=l->target;
		l->data=&l->target->data;
		l->total++;
	}else{
		ptr=l->target;
		l->target=l->head;
		l->target->next=(LILIDATA*)calloc(1,sizeof(LILIDATA));
		l->target->next->next=l->target->next;
		l->target->next->back=l->target;
		l->target->next->data=data;
		/****/		
		l->head=l->target->next;
		l->target=ptr;
		l->total++;	
	}
}
/***pop***/
char* LILIpop(struct lili *l)
{
	char* data=NULL;
	LILIDATA* ptr;
	if(l->target==NULL){
		printf("Linked List EMPTY\n");
	}
	else{
		data=(char*)calloc(sizeof(l->head->data),sizeof(char));
		strcpy(data,l->head->data);
		if(l->target->next==l->target->back){
			printf("troubleshoot: if((l->target->next==l->target->back) «ONLY ONE»\n");//ONLY ONE			
			free(l->head->data);			
			free(l->head);
			l->target=NULL;
			l->tail=NULL;
			l->head=NULL;
			l->data=NULL;
			l->total--;
		}else if(l->target==l->head){
			printf("troubleshoot: if((l->target==l->head) «LAST IN LIST»\n");//LAST IN LIST
			l->target->back->next=l->target->back;
			/****/
			l->target=l->target->back;			
			free(l->head->data);
			free(l->head);
			l->head=l->target;
			l->data=&l->target->data;
			l->total--;
		}else{
			printf("troubleshoot: «IN BETWEEN»\n");
			ptr=l->target;
			l->target=l->head;
			l->target->back->next=l->target->back;
			/****/
			l->target=l->target->back;
			free(l->head->data);
			free(l->head);
			l->head=l->target;
			l->target=ptr;
			l->total--;
		}
	}
	return data;
}
/*
** interrupt
*/
/*
*** Comments
*/
//encapsulation mandates repetition of code.
/***EOF***/
