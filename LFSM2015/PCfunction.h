/************************************************************************
Title:    PCFUNCTION
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PCfunction.h,v 0.1 2015/07/03 14:00:00 sergio Exp $
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
#ifndef _PCFUNCTION_H_
	#define _PCFUNCTION_H_
/*
** constant and macro
*/
/*
** variable
*/
struct func{
	/***PROTOTYPES VTABLE***/
	int (*stringlength)(const char string[]);
	void (*reverse)(char s[]);
	/***/
	char* (*fltos)(FILE* stream);
	char* (*ftos)(FILE* stream);
	int (*strtotok)(char* line,char* token[],const char* parser);
	char* (*putstr)(char* str);
	int (*getnum)(char* x);
	unsigned int (*getnumv2)(char* x);
	int (*readint)(int nmin, int nmax);
	int (*mayia)(int xi, int xf, int nbits);
	int (*pinmatch)(int match, int pin, int HL);
	int (*lh)(int xi, int xf);
	int (*hl)(int xi, int xf);
	int (*diff)(int xi, int xf);
	char* (*print_binary)(int number);
	//char (*mm74c923_read)(char c);
};
typedef struct func FUNC;
/*
** procedure and function header
*/
FUNC FUNCenable(void);
#endif
/***EOF***/
