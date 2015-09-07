/*
* Research
* PCLFSM2015.c
* Nome: sergio santos
* Contacto: 916919898; sergio.salazar.santos@gmail.com
* data: 12-08-2015 14:00
* working on it.
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
//#include <unistd.h>
// perror
#include <errno.h>
// open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <stdio_ext.h>
#include <math.h>
// personal library
#include"PCfunction.h"
#include"PClfsm.h"
#include"PCficheiro.h"
//#include"ssfiledescriptor.h"
/***Definition and Macros***/
#define TRUE 1
#define EMPTY 0 //on a pc vectores are at zero therefore empty is zero.
#define HIGH 1
#define high 1
#define LOW 0
#define low 0
/*****GLOBAL VARIABLES*****/
LFSMDATA MEM[128];
/*****Procedure and Function*****/
void* this(void* address){
	return address;
}
// Main Main Main Main Main Main Main Main Main Main Main Main Main Main
// Main Main Main Main Main Main Main Main Main Main Main Main Main Main
int main(int argc, char *argv[])
{
	char *cmd;
	unsigned int number3;
	unsigned int number1;
	unsigned int number2;
	char* str=NULL;
	//char* token[10];
/*******************************************************/
	FUNC func=FUNCenable();
	LFSM r = LFSMenable(MEM, 128);
	/***************************/
	FICHEIRO f=FICHEIROenable("file.txt");
	f.rewind(this(&f));
	f.colocarchar(this(&f),'A');
	f.colocarstring(this(&f),"qualquer coisa");
	str=func.fltos(f.open(this(&f)));
	printf("%s\n\n",str);
	//func.strtotok(str,token," ");
	free(str);
	f.close(this(&f));
	printf("putstringtest: %s\n", func.putstr("hello world"));
	printf("lfsmdata size: %ld\n",sizeof(LFSMDATA));
/********************************************************/
	printf("MAYIA\n");
	number3=func.mayia(0,1,4);
	printf("num1: %d num2: %d magic: %d\n",1,1,number3);
	//
	printf("sizeeeprom: %d\n", r.sizeeeprom);
	printf("randomize %d\n", rand());
	/*******************************************************************************************/
	// Cycle
	while(TRUE){
		printf("write string with number\nor instruction\n");
		cmd=func.fltos(stdin);
		number1=func.getnum(cmd);
		if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
			free(cmd);			
			goto end;
		}
		if(!strcmp(cmd,"learn") || !strcmp(cmd,"l")){
			printf("enter input\n");
			free(cmd);
			cmd=func.fltos(stdin);
			//number1=func.binary_decimal(func.getnum(cmd));
			number1=func.getnum(cmd);
			printf("enter output data\n");
			free(cmd);
			cmd=func.fltos(stdin);
			number2=func.binary_decimal(func.getnum(cmd));
			printf("enter page\n");
			free(cmd);
			cmd=func.fltos(stdin);
			number3=func.getnum(cmd);
			r.learn(this(&r),number1,number2,number3);
		}
		if(!strcmp(cmd,"how many") || !strcmp(cmd,"h")){
			printf("there are %d programmed.\n",r.quant(this(&r)));
		}
		if(!strcmp(cmd,"delete all") || !strcmp(cmd,"d")){
			r.deleteall(this(&r));
		}
		if(!strcmp(cmd,"remove") || !strcmp(cmd,"r")){
			printf("enter input to remove\n");
			free(cmd);
			cmd=func.fltos(stdin);
			number1=func.getnum(cmd);
			//l.remove(&l,number1);
			r.remove(this(&r),number1);
		}
		printf("->->->->->->->->->->->->->->-> %s \n",func.print_binary(r.read(this(&r),number1)));
	free(cmd);
	}
	/******/
	end:
		//system("PAUSE");
		return 0;
}
/***EOF***/
