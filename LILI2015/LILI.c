/*
* Research
* LILI2015.c
* Nome: sergio santos
* Contacto: 916919898; sergio.salazar.santos@gmail.com
* data: 12-08-2015 14:00
* just beginning
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
#include"PClili.h"
#include"PCfunction.h"
/***Definition and Macros***/
#define TRUE 1
/*****GLOBAL VARIABLES*****/
/*****Procedure and Function*****/
//void* this(void* address){
//	return address;
//}
// Main Main Main Main Main Main Main Main Main Main Main Main Main Main
// Main Main Main Main Main Main Main Main Main Main Main Main Main Main
int main(int argc, char *argv[])
{
	char *cmd;
	LILI l=LILIenable();
	FUNC func=FUNCenable();
	/*******************************************************************************************/
	// Cycle
	while(TRUE){
		printf("write string\n");
		cmd=func.fltos(stdin);
		if(!strcmp(cmd,"quit") || !strcmp(cmd,"q"))
			free(cmd);
			goto end;
		if(!strcmp(cmd,"play") || !strcmp(cmd,"p")){
			printf("play\n");
			//info=func.fltos(stdin);
			printf("data= %s", l.target->data);
			free(cmd);
		}
		if(!strcmp(cmd,"forward") || !strcmp(cmd,"f")){
			//printf("there are %d programmed.\n",l.quant(this(&l)));
			free(cmd);
		}
		if(!strcmp(cmd,"reverse") || !strcmp(cmd,"rev")){
			//r.deleteall(this(&r));
			free(cmd);

		}
		if(!strcmp(cmd,"record") || !strcmp(cmd,"rec")){
			printf("enter input to record\n");
			//cmd=func.fltos(stdin);
			//number1=func.getnum(cmd);
			//l.remove(&l,number1);
			//r.remove(this(&r),number1);
			free(cmd);
		}
		if(!strcmp(cmd,"remove") || !strcmp(cmd,"rem")){
			//printf("enter input to remove\n");
			//cmd=func.fltos(stdin);
			//number1=func.getnum(cmd);
			//l.remove(&l,number1);
			//r.remove(this(&r),number1);
			free(cmd);
		}
		//printf("->->->->->->->->->->->->->->-> %s \n",func.print_binary(r.read(this(&r),number1)));
		//free(cmd);	
	}
	/******/
	end:
		//system("PAUSE");
		return 0;
}
/***EOF***/
