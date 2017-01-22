/************************************************************************
Title:    PCROUTINE
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PCroutine.h,v 0.1 2017/01/22 15:48:00 sergio Exp $
Software: GCC
Hardware: 
License:  GNU General Public License 
Usage:    
LICENSE:
    Copyright (C) 2017
    This program is free software; you can redistribute it and/or modify
    it under the consent of the code developer, in case of commercial use
    need licence.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
COMMENT:
	improve
************************************************************************/
#ifndef _PCROUTINE_H_
	#define _PCROUTINE_H_
/*
** constant and macro
*/
/*
** variable
*/
struct routine{
	//Local Variables
	unsigned int matrix_XY;
	unsigned int numero;
	//Function Pointers
	unsigned int (*routine)(struct routine* this, unsigned int entry);
	void (*search)(struct routine* this, unsigned int value, unsigned int data[], unsigned int size);
	unsigned int (*number)(struct routine* this);
};
typedef struct routine ROUTINE;
/*
** procedure and function header
*/
ROUTINE ROUTINEenable(unsigned int XY);
#endif
/***EOF***/
/***
Sintax Semantic Pragmatic.
Sintax is a key principle able to follow a sintactical work flow that solves any problem,
having a concise structural work flow is very importante.
The method used is C object oriented aproach, do not know anybody using this type of aproach, 
but all the programs made here follow this type of paradigm, it is very very stable either in 
PC or Embeded MCU programs, making Main program very compact.
Discovered this method by experience since then never left it, altering prior programs to fit 
its syntax, making the program much more flexible and broader.
Ofcourse C++ and C#, etc, already follows this type of paradigm, but C is the oldest and 
the mother language, most well recognised.
***/

