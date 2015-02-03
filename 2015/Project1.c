/*
* Reseach
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
//personal library
#include"PCfunction.h"
//#include"ssfiledescriptor.h"
/***Definition and Macros***/
#define TRUE 1
#define EMPTY 0 //on a pc vectores are at zero therfore empty is zero.
#define HIGH 1
#define high 1
#define LOW 0
#define low 0

/***OBJECTS***/
/***MY OBJECT***/
struct ficheiro{
	//Local Variables
	FILE *fp;
	char filename[128];
	char permision[8];
	// Function Pointers
	int (*close)(struct ficheiro *f);
	FILE* (*open)(struct ficheiro *f);
};
typedef struct ficheiro file;
/***Constructor***/
file filecreate(char *filename);

/***MY OBJECT***/
struct routine{
	//Local Variables
	int *mem;
	int sizeeeprom;
	int sizeblock;
	int page;
	int recall;
	int present;
	int (*read)(struct routine *r, int input, int feedback);
	int (*learn)(struct routine *r, int input, int next, int feedback);
	int (*quant)(struct routine *r);
	int (*remove)(struct routine *r, int input, int present);
	int (*deleteall)(struct routine *r);
	int (*get)(struct routine *r);
	int (*diff)(int xi, int xf);
};
typedef struct routine FSM;
/***Constructor***/
FSM fsmstart(int *eeprom, int sizeeeprom, int prog);

/***MY OBJECT***/
struct logica{
	//Local Variables
	int *mem;
	int sizeeeprom;
	int sizeblock;
	int page;
	int recall;
	int output;
	//Local Function pointers
	int (*read)(struct logica *r, int input);
	int (*learn)(struct logica *r, int input, int output);
	int (*quant)(struct logica *r);
	int (*remove)(struct logica *r, int input);
	int (*deleteall)(struct logica *r);
	int (*get)(struct logica *r);
	int (*diff)(int xi, int xf);
};
typedef struct logica LOGIC;
/***Constructor***/
LOGIC LogicCreate(int *eeprom, int sizeeeprom, int prog);

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
	//char* str=NULL;
	//char* token[10];

	//file f=filecreate("file.txt");
	//str=func.ftos(f.open(&f));
	//printf("%s\n\n",str);
	//func.strtotok(str,token," ");
	//free(str);
	//f.close(&f);

/*******************************************************/
	FUNC func=FUNCenable();
	FSM r = fsmstart(eeprom1, 83, 1);
	//LOGIC l = LogicCreate(eeprom2, 83, 1);

	/***************************/
	printf("MAYIA\n");
	number3=func.mayia(0,1,4);
	printf("num1: %d num2: %d magic: %d\n",1,1,number3);

	/***************************/
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

/****************************************************/

/***CONSTRUCTOR OF OBJECTS START***/
file filecreate(char *filename)
{
	/***local variables***/

	/***Declare Functions***/
	int FILEclose(struct ficheiro *f);
	FILE* FILEopen(struct ficheiro *f);

	/******/
	struct ficheiro f;

	//Inicialize varibles
	strcpy(f.filename,filename);
	strcpy(f.permision,"rw");//setting as default
	//Functions pointers or Vtable to declared functions
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

/***FSM***/
FSM fsmstart(int *eeprom, int sizeeeprom, int prog)
{
	int cells;

	/***Declare Functions***/
	int FSMread(struct routine *r, int input, int feedback);
	int FSMlearn(struct routine *r, int input, int next, int feedback);
	int FSMquant(struct routine *r);
	int FSMremove(struct routine *r, int input, int present);
	int FSMdeleteall(struct routine *r);
	int FSMstate(struct routine *r);
	int FSMdiff(int xi, int xf);
	/***Create Object***/
	struct routine r;
	//Inicialize varibles
	r.mem=eeprom;
	r.sizeblock=5;
	cells=sizeeeprom/r.sizeblock;
	r.sizeeeprom=cells*r.sizeblock;
	r.page=prog;
	r.recall=0;
	r.present=0;
	//Functions pointers or Vtable to declared functions
	r.read=FSMread;
	r.learn=FSMlearn;
	r.quant=FSMquant;
	r.remove=FSMremove;
	r.deleteall=FSMdeleteall;
	r.get=FSMstate;
	r.diff=FSMdiff;
	/******/
	return r;
}

/***FSM***/
LOGIC LogicCreate(int *eeprom, int sizeeeprom, int prog)
{
	int cells;
	/***Declare Functions***/
	int LOGICread(struct logica *r, int input);
	int LOGIClearn(struct logica *r, int input, int output);
	int FSMquant(struct logica *r);
	int LOGICremove(struct logica *r, int input);
	int FSMdeleteall(struct logica *r);
	int FSMdiff(int xi, int xf);

	/***Create Object***/
	struct logica l;

	//Inicialize varibles
	l.mem=eeprom;
	l.sizeblock=4;
	cells=sizeeeprom/l.sizeblock;
	l.sizeeeprom=cells*l.sizeblock;
	l.page=prog;
	l.recall=0;
	l.output=0;

	//Functions pointers or Vtable to declared functions
	l.read=LOGICread;
	l.learn=LOGIClearn;
	l.quant=FSMquant;
	l.remove=LOGICremove;
	l.deleteall=FSMdeleteall;
	l.diff=FSMdiff;

	/******/
	return l;
}
/***CONSTRUCTOR OF OBJECTS STOP***/

/***read***/
int FSMread(struct routine *r, int input, int feedback)
{
	int i1;
	int i2;
	int block[r->sizeblock];
	int keyfound;
	int diferenca;
	diferenca=r->diff(r->recall,input);
	if(diferenca){//in reality there is no repetition of closed contact or open
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==r->page){
				for(i2=0;i2<r->sizeblock;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				keyfound=(block[1]==(diferenca&input) && block[2]==feedback &&
				block[3]==diferenca);//bool
				printf("diferenca&input: %d diferenca: %d\n",block[1],diferenca);
				if(keyfound){
					r->present=block[4];
					printf("read found\n");
					break;
				}else{
					printf("read not found\n");
				}
			}
		}
		r->recall=input;
	}
	printf("Page %d Eoutput -> %d\n",r->page,r->present);
	return r->present;
}
/***read***/
int LOGICread(struct logica *r, int input)
{
	int i1;
	int i2;
	int block[r->sizeblock];
	int keyfound;
	int diferenca;
	diferenca=r->diff(r->recall,input); // previne redundancia
	if(diferenca){//in reality there is no repetition of closed contact or open
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==r->page){
				for(i2=0;i2<r->sizeblock;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				keyfound=(block[1]==(diferenca&input) && block[2]==diferenca);//bool
				printf("diferenca&input: %d diferenca: %d\n",block[1],diferenca);
				if(keyfound){
					r->output=block[3];
					printf("read found\n");
					break;
				}else{
					printf("read not found\n");
				}
			}
		}
		r->recall=input;
	}
	printf("Page %d Eoutput -> %d\n",r->page,r->output);
	return r->output;
}
/***learn***/
int FSMlearn(struct routine *r, int input, int next, int feedback)
{
	int i1;
	int i2;
	int block[r->sizeblock];
	int keyfound;
	int status=0;
	int diferenca;
	diferenca=r->diff(r->recall,input);
	if(diferenca){
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==r->page){
				for(i2=0;i2<r->sizeblock;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				keyfound=(block[1]==(diferenca&input) && block[2]==feedback &&
				block[3]==diferenca);//bool
				if(keyfound){
					status=1;//not permited
					break;
				}
			}
			status=3;//not existente
		}
	}
	if(status==3){
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==EMPTY){
				*(r->mem+i1)=r->page;
				*(r->mem+i1+1)=(diferenca&input);
				*(r->mem+i1+2)=feedback;
				*(r->mem+i1+3)=diferenca;
				*(r->mem+i1+4)=next;
				printf("diferenca&input: %d diferenca: %d\n",(diferenca&input),diferenca);
				status=2;//created
				break;
			}
			status=4;//not possible
		}
	}
	r->recall=input;
	printf("learn status: %d\n",status);
	return status;
}
/***learn***/
int LOGIClearn(struct logica *r, int input, int output)
{
	int i1;
	int i2;
	int block[r->sizeblock];
	int keyfound;
	int status=0;
	int diferenca;
	diferenca=r->diff(r->recall,input);
	if(diferenca){
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==r->page){
				for(i2=0;i2<r->sizeblock;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				keyfound=(block[1]==(diferenca&input) && block[3]==diferenca);//bool
				if(keyfound){
					status=1;//not permited
					break;
				}
			}
			status=3;//not existente
		}
	}
	if(status==3){
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==EMPTY){
				*(r->mem+i1)=r->page;
				*(r->mem+i1+1)=(diferenca&input);
				*(r->mem+i1+2)=diferenca;
				*(r->mem+i1+3)=output;
				printf("diferenca&input: %d diferenca: %d\n",(diferenca&input),diferenca);
				status=2;//created
				break;
			}
			status=4;//not possible
		}
	}
	r->recall=input;
	printf("learn status: %d\n",status);
	return status;
}
/***quant***/
int FSMquant(struct routine *r)
{
	int i1;
	int programmed;
	int block[r->sizeblock];
	for(i1=0,programmed=0;i1<r->sizeeeprom;i1+=r->sizeblock){
		if(*(r->mem+i1)!=EMPTY)
			programmed++;
	}
	//printf("there are %d programmed\n",programmed);
	return programmed;
}
/***remove***/
int FSMremove(struct routine *r, int input, int present)
{
	int i1;
	int i2;
	int block[r->sizeblock];
	int keyfound;
	int status=0;
	int diferenca;
	diferenca=r->diff(r->recall,input);
	if(diferenca){
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==r->page){
				for(i2=0;i2<r->sizeblock;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				keyfound=(block[1]==(diferenca&input) && block[2]==present &&
				block[3]==diferenca);//bool
				if(keyfound){
					*(r->mem+i1)=EMPTY;
					status=1;//removed
					break;
				}
			}
		}
		r->recall=input;
	}
	printf("remove status: %d\n",status);
	return status;
}
/***remove***/
int LOGICremove(struct logica *r, int input)
{
	int i1;
	int i2;
	int block[r->sizeblock];
	int keyfound;
	int status=0;
	int diferenca;
	diferenca=r->diff(r->recall,input);
	if(diferenca){
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)==r->page){
				for(i2=0;i2<r->sizeblock;i2++){//get block from eeprom
					block[i2]=*(r->mem+i1+i2);
				}
				keyfound=(block[1]==(diferenca&input) && block[2]==diferenca);//bool
				if(keyfound){
					*(r->mem+i1)=EMPTY;
					status=1;//removed
					break;
				}
			}
		}
		r->recall=input;
	}
	printf("remove status: %d\n",status);
	return status;
}
/***deleteall***/
int FSMdeleteall(struct routine *r)
{
	int i1;
	int status=0;
	if(!status){//not removed
		for(i1=0;i1<r->sizeeeprom;i1+=r->sizeblock){
			if(*(r->mem+i1)!=EMPTY){
				*(r->mem+i1)=EMPTY;
				status=1;//all deleted
			}
		}
	}
	printf("deleteall status: %d\n",status);
	return status;
}
/***get***/
int FSMstate(struct routine *r)
{
	//printf("FSMget: %d\n",r->present);
	return r->present;
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
/***diff***/
int FSMdiff(int xi, int xf)
{
	return xi^xf;
}
/***EOF***/
