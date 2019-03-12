/*
* Research
* trial_2.c
* Nome: sergio santos
* Contacto: 916919898; sergio.salazar.santos@gmail.com
* data: 24-02-2018 11:00
*
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
//#include"ssfiledescriptor.h"
/***Definition and Macros***/
#define TRUE 1

//#ifdef linux
//#elif _WIN32
//#else
//#endif
/*****GLOBAL VARIABLES*****/

/*****Procedure and Function*****/

//uint8_t rotenc(uint8_t chApin, uint8_t chBpin);

/****/
int main(int argc, char *argv[])
{
    int i;
    int var1, var2;
	/*
	*** Capture arguments
	*/
    for(i=0;i<argc;i++){
	    printf("argumento: %d valor: %s\n", i+1, argv[i]);
    }
	/*
	*** Local variables
	*/
	char *cmd;
    unsigned int value, nvalue;
    nvalue=0;
    FUNC func=FUNCenable();
    
	// Cycle
	while(TRUE){
        
        while(TRUE){		
            printf("Input :\n");
		    cmd=func.fltos(stdin);
		    value=func.getnumv2(cmd);
            // exit status
            if(!strcmp(cmd,"on") || !strcmp(cmd,"ok")){
                continue;
            }  
            if(!strcmp(cmd,"off") || !strcmp(cmd,"nok")){
                continue;
            }
		    if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
			    free(cmd);
			    goto end;
		    }
            if(value<16)
                break;
        }
        if(value==nvalue){
            continue;
        }
        




        continue;
	/******/
	end:
		return 0;
    }
}
/*****Procedure and Function Definition*****/
//uint8_t rotenc(uint8_t chApin, uint8_t chBpin)
//{
//	uint8_t ret=0;
	
	
//	return ret;
//}
/*****Interrupt Request*****/
/***EOF***/
