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
//#ifdef linux
//#elif _WIN32
//#else
//#endif
/*****GLOBAL VARIABLES*****/
/*****Procedure and Function*****/
// Main Main Main Main Main Main Main Main Main Main Main Main Main Main
// Main Main Main Main Main Main Main Main Main Main Main Main Main Main
int main(int argc, char *argv[])
{
	/*
	*** Capture arguments
	*/
	printf("Running program - %s with - %d arguments\n\n", argv[0], argc);
	/*
	*** Local variables
	*/
	char* cmd;
	int i;
	int entry;
	int index;
	int number=0;
	//int number=1;
	printf("number: %d\n",number);
/*******************************************************/
	FUNC func=FUNCenable();
/*******************************************************************************************/
	// Cycle
	while(TRUE){
		printf("command\n");
		cmd=func.fltos(stdin);
		entry=func.getnum(cmd);

		if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
			free(cmd);			
			goto end;
		}
		//(n-1)*K+i=I
		//Excellent
		for(i=0;i<(6+1);i++){
			//index=(number-1)*6+i; //matrix starting at 1
			index=number*(6+1)+i; //matrix starting at 0
			if(entry==index){
				number=i;
				break;
			}
		}

		printf("number: %d\n",number);


	}
/******/
	end:
		//system("PAUSE");
		return 0;
}
/***EOF***/
