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
	char filename[128];
	char permision[32];
	// Function Pointers
	int (*close)(struct ficheiro *f);
	int (*colocarchar)(struct ficheiro *f, int c);
	int (*colocarstring)(struct ficheiro *f, const char* s);
	FILE* (*open)(struct ficheiro *f);
};
typedef struct ficheiro FICHEIRO;
/*
** procedure and function header
*/
FICHEIRO FICHEIROenable(char *filename);
#endif
/***EOF***/
