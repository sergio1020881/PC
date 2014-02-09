/*
* Reseach
* Nome: sergio santos
* Contacto: 916919898; sergio.salazar.santos@gmail.com
* data: 01-12-2013 01:00
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
#include <unistd.h>
// perror
#include <errno.h>
// open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <stdio_ext.h>
#include <math.h>
#indef TRUE
  #define TRUE 1
#endif
/***CONSTRUCTOR OF OBJECT***/
file filecreate(char *filename)
{
	/***local variables***/
	/***Declare Functions***/
	char* FILEftos(FILE* stream);
	char* FILEfltos(FILE* stream);
	int FILEstrtotok(char* line,char* token[],const char* parser);
	int FILEclose(struct ficheiro *f);
	FILE* FILEopen(struct ficheiro *f);
	/******/
	struct ficheiro f;
	//Inicialize varibles
	strcpy(f.filename,filename);
	strcpy(f.permision,"rw");//setting as default
	//Functions pointers or Vtable to declared functions
	f.fltos=FILEfltos;
	f.ftos=FILEftos;
	f.strtotok=FILEstrtotok;
	f.open=FILEopen;
	f.close=FILEclose;
	//procedures
	f.fp=fopen(f.filename,f.permision);
	if(f.fp==NULL){
		printf("ficheiro at fopen");
	}
	//return result
	return f;
}
/***readconsole***/
char* FILEreadconsole(FILE* stream)
{
	int i, block, NBytes;
	char caracter;
	char* value=NULL;
	for(i=0, block=4, NBytes=0; (caracter=getc(stream)) != EOF; i++){
		if(i==NBytes){
			NBytes+=block;
			value=(char*)realloc(value, NBytes*sizeof(char));
			if(value==NULL)
				perror("ReadConsole at calloc");
		}
		*(value+i)=caracter;
		if(caracter=='\n'){
			*(value+i)='\0';
			break;
		}
	}
	return value;
}
/***readint***/
int FILEreadint(int nmin, int nmax)
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
/***getnum***/
int FILEgetnum(char* x)
{
	int num;
	if(!sscanf(x, "%d", &num))
		num=0;
	return num;
}
/*****putstr*******/
char* FILEputstr(char* str)
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
/***ftos***/
char* FILEftos(FILE* stream)
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
/***fltos***/
char* FILEfltos(FILE* stream)
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
/***magic***/
int FILEmayia(int xi, int xf, int nbits)
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
/***getnumv2***/
unsigned int FILEgetnumv2(char* x)
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
/*strtotok*/
int FILEstrtotok(char* line,char* token[],const char* parser)
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
/*close*/
int FILEclose(struct ficheiro *f)
{
	fclose(f->fp);
	return 0;
}
/***open***/
FILE* FILEopen(struct ficheiro *f)
{
	return f->fp;
}
/***EOF***/
