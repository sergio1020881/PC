/*
* Research
* Nome: sergio santos
* Contacto: 916919898; sergio.salazar.santos@gmail.com
* data: 25-01-2015 14:30
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
#include"PClogic.h"
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
int eeprom1[83];
int eeprom2[83];
/*****Procedure and Function*****/
// Main Main Main Main Main Main Main Main Main Main Main Main Main Main
// Main Main Main Main Main Main Main Main Main Main Main Main Main Main
int main(int argc, char *argv[])
{
	char *cmd;
	int number3;
	int number1;
	int number2;
	char* str=NULL;
	//char* token[10];
/*******************************************************/
	FUNC func=FUNCenable();
	LFSM r = LFSMenable(eeprom1, 83, 1);
	//LOGIC l = LOGICenable(eeprom2, 83, 1);
	/***************************/
	FICHEIRO f=FICHEIROenable("file.txt");
	str=func.ftos(f.open(&f));
	printf("%s\n\n",str);
	//func.strtotok(str,token," ");
	free(str);
	f.close(&f);
/********************************************************/
	printf("MAYIA\n");
	number3=func.mayia(0,1,4);
	printf("num1: %d num2: %d magic: %d\n",1,1,number3);
	//
	printf("quant %d ",r.quant(&r));
	printf("sizeeeprom: %d \n", r.sizeeeprom);
	// Cycle
	while(TRUE){
		printf("write string with number\n");
		cmd=func.fltos(stdin);
		number1=func.getnum(cmd);
		printf("number: %d  match: %d\n", number1,func.pinmatch(3,number1,1));
		if(!strcmp(cmd,"quit") || !strcmp(cmd,"q"))
			goto end;
		if(!strcmp(cmd,"learn") || !strcmp(cmd,"l")){
			printf("enter input\n");
			cmd=func.fltos(stdin);
			number1=func.getnum(cmd);
			//printf("number1:\n%d\n",number1);
			printf("enter output data\n");
			cmd=func.fltos(stdin);
			number2=func.getnum(cmd);
			//printf("number2:\n%d\n",number2);
			//l.learn(&l,number1,number2);
			r.learn(&r,number1,number2,r.get(&r));
		}
		if(!strcmp(cmd,"how many") || !strcmp(cmd,"h")){
			r.quant(&r);
		}
		if(!strcmp(cmd,"delete all") || !strcmp(cmd,"d")){
			r.deleteall(&r);
		}
		if(!strcmp(cmd,"remove") || !strcmp(cmd,"r")){
			printf("enter input to remove\n");
			cmd=func.fltos(stdin);
			number1=func.getnum(cmd);
			//l.remove(&l,number1);
			r.remove(&r,number1,r.get(&r));
		}
		//printf("number:\n%d\n",number1);
		//l.read(&l,number1);
		r.read(&r,number1,r.get(&r));
	}
	/******/
	end:
		//system("PAUSE");
		return 0;
}
/***EOF***/
