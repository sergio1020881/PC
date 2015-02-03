/*************************************************************************
Title:    FUNCTION
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PCfunction.c,v 0.1 2013/12/30 15:00:00 sergio Exp $
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
    Copyright (C) 2013
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
#include <stdlib.h>
// strcpy strcmp strcat memcmp
#include <string.h>
// termios tcflush
//#include <termios.h>
// nanosleep sleep
#include <time.h>
// tcflsuh read write close
//#include <unistd.h>
// perror
#include <errno.h>
// open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <stdio_ext.h>
#include <math.h>
/***/
#include"PCfunction.h"
/*
** constant and macro
*/
/*
** variable
*/
char FUNCstr[16];
/*
** procedure and function header
*/
int StringLength (const char string[]);
void Reverse(char s[]);
char* FUNCfltos(FILE* stream);
char* FUNCftos(FILE* stream);
int FUNCstrtotok(char* line,char* token[],const char* parser);
char* FUNCputstr(char* str);
int FUNCgetnum(char* x);
unsigned int FUNCgetnumv2(char* x);
int FUNCreadint(int nmin, int nmax);
int FUNCmayia(int xi, int xf, int nbits);
int FUNCpinmatch(int match, int pin, int HL);
int FUNClh(int xi, int xf);
int FUNChl(int xi, int xf);
int FUNCdiff(int xi, int xf);
/*
** Object Inicialize
*/
FUNC FUNCenable( void )
{
	// struct object
	FUNC func;
	func.stringlength=StringLength;
	func.reverse=Reverse;
	func.fltos=FUNCfltos;
	func.ftos=FUNCftos;
	func.strtotok=FUNCstrtotok;
	func.putstr=FUNCputstr;
	func.getnum=FUNCgetnum;
	func.getnumv2=FUNCgetnumv2;
	func.readint=FUNCreadint;
	func.mayia=FUNCmayia;
	func.pinmatch=FUNCpinmatch;
	func.lh=FUNClh;
	func.hl=FUNChl;
	func.diff=FUNCdiff;
	return func;
}
/*
** procedure and function
*/
// StringLength: count chars in string
int StringLength (const char string[])
{
	int count = 0;
	while ( string[count] != '\0' )
		++count;
	return count;
}
// Reverse: reverse string s in place
void Reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = StringLength(s)-1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
// FUNCfltos
char* FUNCfltos(FILE* stream)
{
	int i, block, NBytes;
	char caracter;
	char* value=NULL;
	for(i=0, block=4, NBytes=0; (caracter=getc(stream)) != EOF; i++){
		if(i==NBytes){
			NBytes+=block;
			value=(char*)realloc(value, NBytes*sizeof(char));
			if(value==NULL){
				perror("fltos at calloc");
				break;
			}
		}
		*(value+i)=caracter;
		if(caracter=='\n'){
			*(value+i)='\0';
			break;
		}
	}
	return value;
}
// FUNCftos
char* FUNCftos(FILE* stream)
{
	int i, block, NBytes;
	char caracter;
	char* value=NULL;
	for(i=0, block=8, NBytes=0; (caracter=getc(stream)) != EOF; i++){
		if(i==NBytes){
			NBytes+=block;
			value=(char*)realloc(value, NBytes*sizeof(char));
			if(value==NULL){
				perror("ftos at calloc");
				break;
			}
		}
		*(value+i)=caracter;
	}
	return value;
}
// FUNCstrtotok
int FUNCstrtotok(char* line,char* token[],const char* parser)
{
	int i;
	char *str;
	str=(char*)calloc(strlen(line),sizeof(char));
	for (i = 0, strcpy(str,line); ; i++, str = NULL) {
		token[i] = strtok(str, parser);
		if (token[i] == NULL)
			break;
		printf("%d: %s\n", i, token[i]);
	}
	free(str);
	return i;
}
// FUNCputstr
char* FUNCputstr(char* str)
{
	int i; char* ptr;
	ptr = (char*)calloc(strlen(str), sizeof(char));
	if(ptr == NULL){
		perror("NULL!\n");
		return NULL;
	}
	for(i=0; (ptr[i] = str[i]); i++){
		if(ptr[i] == '\0')
			break;
	}
	return (ptr);
}
// FUNCgetnum
int FUNCgetnum(char* x)
{
	int num;
	if(!sscanf(x, "%d", &num))
		num=0;
	return num;
}
// FUNCgetnumv2
unsigned int FUNCgetnumv2(char* x)
{
	unsigned int RETURN;
	unsigned int value;
	unsigned int n;
	errno=0;
	n=sscanf(x,"%d",&value);
	if(n==1){
		RETURN=value;
	}else if(errno != 0){
		perror("getnum at sscanf");
		RETURN=0;
	}else{
		RETURN=0;
	}
	return RETURN;
}
// FUNCreadint
int FUNCreadint(int nmin, int nmax)
{
	int num;
	int flag;
	for(flag=1; flag;){
		for( num=0; !scanf("%d",&num);getchar())
			;
		//printf("num: %d nmin: %d nmax: %d\n",num, nmin, nmax);
		if((num < nmin) || (num > nmax))
			continue;
		flag=0;
	}
		return num;
}
/***magic***/
int FUNCmayia(int xi, int xf, int nbits)
{
	int mask;
	int diff;
	int trans;
	mask=pow(2,nbits)-1;
	xi=xi&mask;
	xf=xf&mask;
	diff=xf^xi;
	trans=diff&xf;
	return (trans<<nbits)|diff;
}
/***pinmatch***/
int FUNCpinmatch(int match, int pin, int HL)
{
	int result;
	result=match&pin;
	if(HL){
		if(result==match);
		else
			result=0;
	}else{
		if(result)
			result=0;
		else
			result=match;
	}
	return result;
}
/***lh***/
int FUNClh(int xi, int xf)
{
	int i;
	i=xf^xi;
	//if(!i)
	//i=xf;
	i&=xf;
	return i;
}
/***hl***/
int FUNChl(int xi, int xf)
{
	int i;
	i=xf^xi;
	if(!i)
	i=xi;
	i&=xi;
	return i;
}
/***diff***/
int FUNCdiff(int xi, int xf)
{
	return xi^xf;
}
/*
** interrupt
*/
/***EOF***/
