/************************************************************************
Title:    PCLOGIC
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PClogic.h,v 0.1 2015/02/06 14:00:00 sergio Exp $
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
#ifndef _PCLOGIC_H_
	#define _PCLOGIC_H_
/*
** constant and macro
*/
/*
** variable
*/
struct LOGIC{
	//Local Variables
	int *mem;
	int sizeeeprom;
	int sizeblock;
	int page;
	int recall;
	int output;
	//Local Function pointers
	int (*read)(struct LOGIC *r, int input);
	int (*learn)(struct LOGIC *r, int input, int output);
	int (*quant)(struct LOGIC *r);
	int (*remove)(struct LOGIC *r, int input);
	int (*deleteall)(struct LOGIC *r);
	int (*get)(struct LOGIC *r);
	int (*diff)(int xi, int xf);
};
typedef struct LOGIC LOGIC;
/*
** procedure and function header
*/
LOGIC LOGICenable(int *eeprom, int sizeeeprom, int prog);
#endif
/***EOF***/
