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
    void FICHEIROmode(struct ficheiro *f, const char *mode);
	int FICHEIROputc(struct ficheiro *f, int c);
	int FICHEIROputs(struct ficheiro *f, const char *s);
    int FICHEIROread(struct ficheiro *f, void *ptr, size_t size, size_t nmemb);
	int FICHEIROwrite(struct ficheiro *f, const void *ptr, size_t size, size_t nmemb);
	FILE* FICHEIROopen(struct ficheiro *f);
	/******/
	FICHEIRO f;
	//Inicialize varibles
	strcpy(f.filepathname,pathname);
	//do a checkup if exists first !
	strcpy(f.filemode,"a+");//setting as default
	//Functions pointers or Vtable to declared functions
	f.open=FICHEIROopen;
    f.mode=FICHEIROmode;
	f.colocarchar=FICHEIROputc;
	f.colocarstring=FICHEIROputs;
    f.read=FICHEIROread;
    f.write=FICHEIROwrite;
	f.close=FICHEIROclose;
	//procedures
    f.open((FICHEIRO*)&f);
	//return result
    f.close((FICHEIRO*)&f);
	return f;
}
/*
** procedure and function
*/
/*close*/
int FICHEIROclose(struct ficheiro *f)
{
    printf("Closing file %s\n",f->filepathname);
	fclose(f->fp);
	return 0;
}
/*mode*/
void FICHEIROmode(struct ficheiro *f, const char *mode)
{
	strcpy(f->filemode,mode);
}
/*colocarchar*/
int FICHEIROputc(struct ficheiro *f, int c)
{
	int r;
    f->open(f);
	r=fputc(c,f->fp);
    f->close(f);
	return r;
}
/*colocarstring*/
int FICHEIROputs(struct ficheiro *f, const char* s)
{
	int r;
    f->open(f);
	r=fputs(s,f->fp);
    f->close(f);
	return r;
}
/***read***/
int FICHEIROread(struct ficheiro *f, void *ptr, size_t size, size_t nmemb)
{
	int r;
    f->open(f);
	r=fread(ptr,size,nmemb,f->fp);
    f->close(f);
	return r;
}
/***write***/
int FICHEIROwrite(struct ficheiro *f, const void *ptr, size_t size, size_t nmemb)
{
	int r;
    f->open(f);
	r=fwrite(ptr,size,nmemb,f->fp);
    f->close(f);
	return r;
}
/***open***/
FILE* FICHEIROopen(struct ficheiro *f)
{
    f->fp=fopen(f->filepathname,f->filemode);
	if(f->fp!=NULL){
		printf("Opening file %s\n",f->filepathname);
	}else{
		perror("Ficheiro at fopen\n");
		printf("Creating file %s\n",f->filepathname);
		f->fp=fopen(f->filepathname,f->filemode);
	}
	#ifdef linux
		f->fd=fileno(f->fp);
	#elif _WIN32
		f->fd=_fileno(f->fp);
	#else
	#endif
	if(f->fd<0){
		perror("Ficheiro filedescriptor not existent\n");
		printf("None errno: %d\n", errno);
        f->errcode=errno;
	}
	return f->fp;
}
/*
** interrupt
*/
/***EOF***/
