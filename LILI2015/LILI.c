/*:
* Research
* LILI2015.c
* Nome: sergio santos
* Contacto: 916919898; sergio.salazar.santos@gmail.com
* data: 12-08-2015 14:00
* just beginning
*/
/*
*** Library
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
/*
** Personal library
*/
#include"PClili.h"
#include"PCfunction.h"
/*
*** Definition and Macros
*/
#define TRUE 1
/*
*** GLOBAL VARIABLES
*/
/***
*** Procedure and Function
*/
//void* this(void* address){
//	return address;
//}
/*
*** Main Algorithm
*/
// Main Main Main Main Main Main Main Main Main Main Main Main Main Main
// Main Main Main Main Main Main Main Main Main Main Main Main Main Main
int main(int argc, char *argv[])
{
/*
*** Local variables
*/
	char *cmd=NULL;
	char *data=NULL;
	LILI l=LILIenable();
	FUNC func=FUNCenable();
/*
*** CYCLE ROUTINES
*/
	while(TRUE){
		printf("->->	write string:\n");
		cmd=func.fltos(stdin);
		if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
			goto end;
		}		
		if(!strcmp(cmd,"play") || !strcmp(cmd,"p")){
			printf("data= %s\n", l.play(&l));
		}
		if(!strcmp(cmd,"forward") || !strcmp(cmd,"for")){
			l.forward(&l);
		}
		if(!strcmp(cmd,"reverse") || !strcmp(cmd,"rev")){
			l.reverse(&l);

		}
		if(!strcmp(cmd,"record") || !strcmp(cmd,"rec")){
			printf("enter input to record\n");			
			cmd=func.fltos(stdin);
			l.record(&l, cmd);
		}
		if(!strcmp(cmd,"remove") || !strcmp(cmd,"rem")){
		}
	}
/*
*** EXIT
*/
	end:
		//system("PAUSE");
		return 0;
}
/*
*** Function and procedure
*/
/*
*** Interrupt requestes
*/
/***EOF***/
