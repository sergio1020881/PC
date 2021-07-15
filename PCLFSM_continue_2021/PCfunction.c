/**************************************************************************
Title:    PCFUNCTION
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PCfunction.c, v 0.1 2015/08/01 14:00:00 sergio Exp $
Software: GCC
Hardware: PC
License:  GNU General Public License
Description:
	PC emulation
Comment:
	Very Stable
*************************************************************************/
#include<inttypes.h>
#include"PCfunction.h"
/*
** constant and macro
*/
/*
** variable
*/
char FUNCstr[128];
char *value;
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
unsigned int FUNCmayia(unsigned int xi, unsigned int xf, unsigned int nbits);
unsigned int FUNCpinmatch(unsigned int match, unsigned int pin, unsigned int HL);
unsigned int FUNClh(unsigned int xi, unsigned int xf);
unsigned int FUNChl(unsigned int xi, unsigned int xf);
unsigned int FUNCdiff(unsigned int xi, unsigned int xf);
char* FUNCprint_binary(unsigned int n_bits, int number);
unsigned int FUNCdecimal_binary(unsigned int n);
unsigned int FUNCbinary_decimal(unsigned int n);
/*
** Object Inicialize
*/
FUNC FUNCenable( void )
{
	value=NULL;
	// struct object
	FUNC func;
	//func.value=NULL;
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
	func.print_binary=FUNCprint_binary;
	func.decimal_binary=FUNCdecimal_binary;
	func.binary_decimal=FUNCbinary_decimal;
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
	//made it a file variable so do not need to free it up all the time except on exitting program.
	//char* value=NULL;
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
	//made it a file variable so do not need to free it up all the time except on exiting program.
	//char* value=NULL;
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
unsigned int FUNCmayia(unsigned int xi, unsigned int xf, unsigned int nbits)
{
	unsigned int mask;
	unsigned int diff;
	unsigned int trans;
	mask=pow(2,nbits)-1;
	xi=xi&mask;
	xf=xf&mask;
	diff=xf^xi;
	trans=diff&xf;
	return (trans<<nbits)|diff;
}
/***pinmatch***/
unsigned int FUNCpinmatch(unsigned int match, unsigned int pin, unsigned int HL)
{
	unsigned int result;
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
unsigned int FUNClh(unsigned int xi, unsigned int xf)
{
	unsigned int i;
	i=xf^xi;
	i&=xf;
	return i;
}
/***hl***/
unsigned int FUNChl(unsigned int xi, unsigned int xf)
{
	unsigned int i;
	i=xf^xi;
	i&=xi;
	return i;
}
/***diff***/
unsigned int FUNCdiff(unsigned int xi, unsigned int xf)
{
	return xi^xf;
}
char* FUNCprint_binary(unsigned int n_bits, int number)
{
	int i,c;
    for(i=(1<<(n_bits-1)), c=0; i; i >>= 1, c++)
		(number & i) ? (FUNCstr[c]='1') : (FUNCstr[c]='0');
	FUNCstr[c]='\0';
	return FUNCstr;
}
/******/
unsigned int FUNCdecimal_binary(unsigned int n) /*Function to convert decimal to binary*/
{
    unsigned int rem, i=1, binary=0;
    while (n!=0)
    {
        rem=n%2;
        n/=2;
        binary+=rem*i;
        i*=10;
    }
    return binary;
}
/******/
unsigned int FUNCbinary_decimal(unsigned int n) /* Function to convert binary to decimal.*/
{
    unsigned int decimal=0, i=0, rem;
    while (n!=0)
    {
        rem = n%10;
        n/=10;
        decimal += rem*pow(2,i);
        ++i;
    }
    return decimal;
}
/*
** interrupt
*/
/***EOF***/
