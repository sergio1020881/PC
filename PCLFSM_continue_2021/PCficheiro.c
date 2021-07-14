/*************************************************************************
Title:    PCFICHEIRO
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PCficheiro.c, v 0.1 2015/08/12 14:00:00 sergio Exp $
Software: GCC
Hardware: PC
License:  GNU General Public License
Description:  PC emulation
Comment:
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
FICHEIRO FICHEIROenable(char *filename)
{
	/***local variables***/
	errno=0;
	/***Declare Functions***/
	int FICHEIROclose(struct ficheiro *f);
	int FICHEIROputc(struct ficheiro *f, int c);
	int FICHEIROputs(struct ficheiro *f, const char* s);
	FILE* FICHEIROopen(struct ficheiro *f);
	/******/
	FICHEIRO f;
	//Inicialize varibles
	strcpy(f.filename,filename);
	//do a checkup if exists first !
	strcpy(f.permision,"a+");//setting as default
	//Functions pointers or Vtable to declared functions
	f.open=FICHEIROopen;
	f.colocarchar=FICHEIROputc;
	f.colocarstring=FICHEIROputs;
	f.close=FICHEIROclose;
	//procedures
	f.fp=fopen(f.filename,f.permision);
	if(f.fp!=NULL){
		printf("Opening file %s\n",f.filename);
	}else{
		perror("Ficheiro at fopen\n");
		printf("Creating file %s\n",f.filename);
		f.fp=fopen(f.filename,"a+");
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
	r=fputc(c,(FILE*)f->fp);
	return r;
}
/*colocarstring*/
int FICHEIROputs(struct ficheiro *f, const char* s)
{
	int r;
	r=fputs(s, f->fp);
	return r;
}
/***open***/
FILE* FICHEIROopen(struct ficheiro *f)
{
	return f->fp;
}
/*
** interrupt
*/
/***Comment
Need to add more funtionality to file library, such has rewind, etc.
Also make it more readeable.

***/
/***EOF***/

