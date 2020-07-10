/************************************************************************
Title:    PCFICHEIRO
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PCficheiro.h,v 0.1 2015/08/12 14:00:00 sergio Exp $
Software: GCC
Hardware:
License:  GNU General Public License
Usage: 
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
************************************************************************/
#ifndef _PCFICHEIRO_H_
	#define _PCFICHEIRO_H_
/*
** library
*/
// fopen perror fread fwrite feof fseek ferror fclose rewind scanf sscanf getchar scanf fscanf
#include <stdio.h>
// calloc free realloc malloc
#include <stdlib.h>
// strcpy strcmp strcat memcmp
#include <string.h>
//
#include <errno.h>
/*
** constant and macro
*/
/*
** variable
*/
struct ficheiro{
	//Local Variables
	FILE *fp;
	int fd;
	int errcode;
	char filepathname[128];
	char filemode[32];
	// Function Pointers
	int (*close)(struct ficheiro *f); //private
    void (*mode)(struct ficheiro *f, const char *mode);
	int (*colocarchar)(struct ficheiro *f, int c);
	int (*colocarstring)(struct ficheiro *f, const char* s);
    int (*read)(struct ficheiro *f, void *ptr, size_t size, size_t nmemb);
	int (*write)(struct ficheiro *f, const void *ptr, size_t size, size_t nmemb);
    int (*seek)(struct ficheiro *f, long offset, int whence);
	FILE* (*open)(struct ficheiro *f); //private
};
typedef struct ficheiro FICHEIRO;
/*
** procedure and function header
*/
FICHEIRO FICHEIROenable(char *pathname);
#endif
/***EOF***/
/****
The problem with function oriented programming is that the variables of header files become global, and one making a program can face with a bug if creates a name with a pre existing on one of the libraries being used, this also applies for constantes and macros, leaving little space o freedom of the programmer, especially if working in specific area where variable names are constante. This is where encapsulation is usefull, the same variable name can be used has many times you want for diferent functions. The naming always belongs to a class. It would be nice if physical componentes could be virtually represented by an virtual object, and plug and play would be seamless having no conflicts or crashes.

Also there should be a separation from program and interface using a communication protocal, so they would be independent of each other and work together easily, and one without the other would be static ignoring all interferences. three parts program, interface, communication, being plug and play with each other.

Programming and technology has still centuries to achieve this.
***/

