/*
* Research
* PCLFSM2018.c
* Nome: sergio santos
* Contacto: 916919898; sergio.salazar.santos@gmail.com
* data: 29-06-2020 16:30
*
*/
/*
** library private
*/
#include"PCfunction.h"
#include"PCficheiro.h"
/*
** library
*/
#include <time.h>
/***Definition and Macros***/
#define TRUE 1
#define ZERO 0
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
int main(int argc, char *argv[])
{
	/*
	*** Capture arguments
	*/
	printf("Running program - %s with - %d arguments\n", argv[0], argc);
	/*
	*** Local variables
	*/
    char memory[1024];
	char *cmd;
	char* str;
/*******************************************************/
	FUNC func=FUNCenable();
	/***************************/
	FICHEIRO f=FICHEIROenable("file.txt");
	printf("putstringtest: %s\n", func.putstr("hello world"));
    printf("%ld\n",fread(memory,sizeof(char),128,(FILE*)f.fp));
    printf("%s\n",memory);


/********************************************************/
	while(TRUE){
        
		printf("write string with instruction : ");
		cmd=func.fltos(stdin);
        
		if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
            printf("Exiting program!\n");	
			goto end;
		}

		if(!strcmp(cmd,"insert") || !strcmp(cmd,"i")){
			printf("enter input\n");
			str=func.fltos(stdin);
			f.colocarstring(&f,str);
            free(str);
            continue;
		}

		if(!strcmp(cmd,"how many") || !strcmp(cmd,"n")){
			printf("----------------\n");
            free(cmd);
            continue;
		}

		if(!strcmp(cmd,"help") || !strcmp(cmd,"h")){
			printf("Possible commands:\n");
                    printf("\thelp - h\n");           		
                    printf("\tinsert - i\n");
            		printf("\tquit - q\n");	
			free(cmd);
			continue;
		}
	}
	/******/
	end:
		//system("PAUSE");
		return 0;
}
/***EOF***/
