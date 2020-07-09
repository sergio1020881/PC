/*************************************************************************
Title:    PCFICHEIRO
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PCficheiro.c, v 0.1 2015/08/12 14:00:00 sergio Exp $
Software: GCC
Hardware:
License:  GNU General Public License
DESCRIPTION:  PC emulation
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
#include"PCficheiro.h"
/*
** constant and macro
*/
/*
** variable
*/
int errno;
/*
** procedure and function header
*/
/*
** Object Inicialize
*/
FICHEIRO FICHEIROenable(char *pathname)
{
	/***local variables***/
	errno=0;
	/***Declare Functions***/
	int FICHEIROclose(struct ficheiro *f);
	int FICHEIROputc(struct ficheiro *f, int c);
	int FICHEIROputs(struct ficheiro *f, const char *s);
	FILE* FICHEIROopen(struct ficheiro *f);
	/******/
	FICHEIRO f;
	//Inicialize varibles
	strcpy(f.pathname,pathname);
	//do a checkup if exists first !
	strcpy(f.mode,"a+");//setting as default
	//Functions pointers or Vtable to declared functions
	f.open=FICHEIROopen;
	f.colocarchar=FICHEIROputc;
	f.colocarstring=FICHEIROputs;
	f.close=FICHEIROclose;
	//procedures
	f.fp=fopen(f.pathname,f.mode);
	if(f.fp!=NULL){
		printf("Opening file %s\n",f.pathname);
	}else{
		perror("Ficheiro at fopen\n");
		printf("Creating file %s\n",f.pathname);
		f.fp=fopen(f.pathname,f.mode);
	}
	#ifdef linux
		f.fd=fileno(f.fp);
	#elif _WIN32
		f.fd=_fileno(f.fp);
	#else
	#endif
	if(f.fd<0){
		perror("Ficheiro filedescriptor not existent\n");
		//sprintf(f.errcode,"None errno: %d\n", errno);
	}
	//return result
    f.close(&f);
	return f;
}
/*
** procedure and function
*/
/*close*/
int FICHEIROclose(struct ficheiro *f)
{
	fclose(f->fp);
	return 0;
}
/*colocarchar*/
int FICHEIROputc(struct ficheiro *f, int c)
{
	int r;
    f->fp=fopen(f->pathname,f->mode);
	if(f->fp!=NULL){
		printf("Opening file %s\n",f->pathname);
	}else{
		perror("Ficheiro at fopen\n");
		printf("Creating file %s\n",f->pathname);
		f->fp=fopen(f->pathname,f->mode);
	}
	#ifdef linux
		f->fd=fileno(f->fp);
	#elif _WIN32
		f->fd=_fileno(f->fp);
	#else
	#endif
	if(f->fd<0){
		perror("Ficheiro filedescriptor not existent\n");
		//sprintf(f->errcode,"None errno: %d\n", errno);
	}
	r=fputc(c,f->fp);
    f->close(f);
	return r;
}
/*colocarstring*/
int FICHEIROputs(struct ficheiro *f, const char* s)
{
	int r;
    f->fp=fopen(f->pathname,f->mode);
	if(f->fp!=NULL){
		printf("Opening file %s\n",f->pathname);
	}else{
		perror("Ficheiro at fopen\n");
		printf("Creating file %s\n",f->pathname);
		f->fp=fopen(f->pathname,f->mode);
	}
	#ifdef linux
		f->fd=fileno(f->fp);
	#elif _WIN32
		f->fd=_fileno(f->fp);
	#else
	#endif
	if(f->fd<0){
		perror("Ficheiro filedescriptor not existent\n");
		//sprintf(f->errcode,"None errno: %d\n", errno);
	}
	r=fputs(s,f->fp);
    f->close(f);
	return r;
}
/***read***/
/***write***/
/***open***/
FILE* FICHEIROopen(struct ficheiro *f)
{
	return f->fp;
}
/*
** interrupt
*/
/***EOF***/
