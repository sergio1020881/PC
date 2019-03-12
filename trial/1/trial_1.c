/*
* Research
* MATRIX2018.c
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
//#include"PCficheiro.h"
//#include"ssfiledescriptor.h"
/***Definition and Macros***/
#define TRUE 1
#define lines 16
#define columns 16
#define blocks 16

//#ifdef linux
//#elif _WIN32
//#else
//#endif
/*****GLOBAL VARIABLES*****/
uint mem[4096];
/*={
{},
{}
};
*/

/*****Procedure and Function*****/


int main(int argc, char *argv[])
{
	/*
	*** Capture arguments
	*/
	printf("Running program - %s with - %d arguments\n", argv[0], argc);
	/*
	*** Local variables
	*/
	char *cmd;
    unsigned int learn;
    unsigned int block;
	unsigned int line;
	unsigned int column;
    unsigned int value, nvalue;
    unsigned int address;
    uint i;
    block=0; //preset
    line=0; //preset
    column=0; //preset
    nvalue=value=16; //preset
    learn=0;
    for(i=0;i<4096;mem[i]=15,i++); //preset vector
    
    FUNC func=FUNCenable();
    
	// Cycle
	while(TRUE){
        
        while(TRUE){		
            printf("Input number between 0 and 15 :\n");
		    cmd=func.fltos(stdin);
		    value=func.getnumv2(cmd);
            // exit status
            if(!strcmp(cmd,"on") || !strcmp(cmd,"ok")){
                learn=1;
                continue;
            }  
            if(!strcmp(cmd,"off") || !strcmp(cmd,"nok")){
                learn=0;
                continue;
            }
		    if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
			    free(cmd);
			    goto end;
		    }
            if(value<16)
                break;
            printf("------ %d ------\n",block);
        }
        
        if(value==nvalue){
            printf("------ %d ------\n",block);
            continue;
        }
        
        line=func.lh(nvalue,value);
        column=func.hl(nvalue,value);
        
        nvalue=value;
        
        
        address=block*lines*columns+lines*line+column;
        
		
        if(learn>0 && mem[address]==15){
            while(TRUE){
			    printf("enter output data :\n");
			    free(cmd);
			    cmd=func.fltos(stdin);
			    value=func.getnum(cmd);
                // exit status
		        if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
			        free(cmd);
			        goto end;
                }
                if(value<16)
                    break;
            }
            mem[address]=value;
		}
        
        if(mem[address]==15)
            printf("------ %d ------\n",block);
        else{
            block=mem[address];
            printf("------ %d ------\n",block);
        }
        
        continue;
	/******/
	end:
		//system("PAUSE");
		return 0;
    }
}
/***EOF***/
