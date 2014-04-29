/*
* Reseach
* Nome: sergio santos
* Contacto: 916919898; sergio.salazar.santos@gmail.com
* data: 25-10-2013 15:00
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
#define TRUE 1
#define EMPTY 0 //on a pc vectores are at zero therfore empty is zero.

/***MY OBJECT***/
struct ficheiro{

//Local Variables
FILE *fp;
char filename[128];
char permision[8];

//Local Function pointers
char* (*ftos)(FILE* stream);
char* (*fltos)(FILE* stream);
int (*strtotok)(char* line,char* token[],const char* parser);
int (*close)(struct ficheiro *f);
FILE* (*open)(struct ficheiro *f);
};

typedef struct ficheiro file;
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

//Local Function pointers
char* (*readconsole)(FILE* stream);
int (*readint)(int nmin, int nmax);
int (*getnum)(char* x);
char* (*putstr)(char* str);
char* (*ftos)(FILE* stream);
char* (*fltos)(FILE* stream);
int (*read)(struct routine *r, int input, int feedback);
int (*learn)(struct routine *r, int input, int next, int feedback);
int (*quant)(struct routine *r);
int (*remove)(struct routine *r, int input, int present);
int (*deleteall)(struct routine *r);
int (*get)(struct routine *r);
int (*recal)(struct routine *r);
int (*lh)(int xi, int xf);
int (*hl)(int xi, int xf);
int (*diff)(int xi, int xf);
int (*mayic)(int xi, int xf, int nbits);
unsigned int (*getnumv2)(char* x);
int (*strtotok)(char* line,char* token[],const char* parser);
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
char* (*readconsole)(FILE* stream);
int (*readint)(int nmin, int nmax);
int (*getnum)(char* x);
char* (*putstr)(char* str);
char* (*ftos)(FILE* stream);
char* (*fltos)(FILE* stream);
int (*read)(struct logica *r, int input);
int (*learn)(struct logica *r, int input, int output);
int (*quant)(struct logica *r);
int (*remove)(struct logica *r, int input);
int (*deleteall)(struct logica *r);
int (*get)(struct logica *r);
int (*recal)(struct logica *r);
int (*lh)(int xi, int xf);
int (*hl)(int xi, int xf);
int (*diff)(int xi, int xf);
int (*mayic)(int xi, int xf, int nbits);
unsigned int (*getnumv2)(char* x);
int (*strtotok)(char* line,char* token[],const char* parser);
};
typedef struct logica LOGIC;

/***Constructor***/
LOGIC LogicCreate(int *eeprom, int sizeeeprom, int prog);

/******/
int eeprom1[83];
int eeprom2[83];

// Main
int main(int argc, char *argv[])
{
char *cmd;
int number3;
int number1;
int number2;
char* str=NULL;
char* token[10];

file f=filecreate("file.txt");
str=f.ftos(f.open(&f));
printf("%s\n\n",str);
f.strtotok(str,token," ");
free(str);
f.close(&f);

/****************************/
FSM r = fsmstart(eeprom1, 83, 1);
LOGIC l = LogicCreate(eeprom2, 83, 1);

/***************************/
printf("MAYIC\n");
number3=l.mayic(0,1,4);
printf("num1: %d num2: %d magic: %d\n",1,1,number3);

/***************************/
printf("quant %d ",l.quant(&l));
printf("sizeeeprom: %d \n", l.sizeeeprom);

// Cycle
while(TRUE){
printf("write string with number\n");
cmd=l.fltos(stdin);
number1=l.getnum(cmd);
if(!strcmp(cmd,"quit") || !strcmp(cmd,"q"))
goto end;
if(!strcmp(cmd,"learn") || !strcmp(cmd,"l")){
printf("enter input\n");
cmd=l.fltos(stdin);
number1=l.getnum(cmd);
//printf("number1:\n%d\n",number1);
printf("enter output data\n");
cmd=l.fltos(stdin);
number2=l.getnum(cmd);
//printf("number2:\n%d\n",number2);
l.learn(&l,number1,number2);
//r.learn(&r,number1,number2,r.get(&r));
}
if(!strcmp(cmd,"how many") || !strcmp(cmd,"h")){
l.quant(&l);
}
if(!strcmp(cmd,"delete all") || !strcmp(cmd,"d")){
l.deleteall(&l);
}
if(!strcmp(cmd,"remove") || !strcmp(cmd,"r")){
printf("enter input to remove\n");
cmd=l.fltos(stdin);
number1=l.getnum(cmd);
l.remove(&l,number1);
//r.remove(&r,number1,r.get(&r));
}
//printf("number:\n%d\n",number1);
l.read(&l,number1);
//r.read(&r,number1,r.get(&r));
}

/******/
end:
system("PAUSE");
return 0;
}

/****************************************************/

/***CONSTRUCTOR OF OBJECT***/
file filecreate(char *filename)
{

/***local variables***/

/***Declare Functions***/
char* FSMftos(FILE* stream);
char* FSMfltos(FILE* stream);
int FSMstrtotok(char* line,char* token[],const char* parser);
int FILEclose(struct ficheiro *f);
FILE* FILEopen(struct ficheiro *f);

/******/
struct ficheiro f;

//Inicialize varibles
strcpy(f.filename,filename);
strcpy(f.permision,"rw");//setting as default

//Functions pointers or Vtable to declared functions
f.fltos=FSMfltos;
f.ftos=FSMftos;
f.strtotok=FSMstrtotok;
f.open=FILEopen;
f.close=FILEclose;

//procedures
f.fp=fopen(f.filename,f.permision);
if(f.fp==NULL){
perror("special at fopen");
}

//return result
return f;
}

/***FSM***/
FSM fsmstart(int *eeprom, int sizeeeprom, int prog)
{
int cells;

/***Declare Functions***/
char* FSMreadconsole(FILE* stream);
int FSMreadint(int nmin, int nmax);
int FSMgetnum(char* x);
char* FSMputstr(char* str);
char* FSMftos(FILE* stream);
char* FSMfltos(FILE* stream);
int FSMread(struct routine *r, int input, int feedback);
int FSMlearn(struct routine *r, int input, int next, int feedback);
int FSMquant(struct routine *r);
int FSMremove(struct routine *r, int input, int present);
int FSMdeleteall(struct routine *r);
int FSMstate(struct routine *r);
int FSMlh(int xi, int xf);
int FSMhl(int xi, int xf);
int FSMmayic(int xi, int xf, int nbits);
int FSMdiff(int xi, int xf);
int FSMrecall(struct routine *r);
unsigned int FSMgetnumv2(char* x);
int FSMstrtotok(char* line,char* token[],const char* parser);

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
r.fltos=FSMfltos;
r.ftos=FSMftos;
r.getnum=FSMgetnum;
r.putstr=FSMputstr;
r.readconsole=FSMreadconsole;
r.readint=FSMreadint;
r.read=FSMread;
r.learn=FSMlearn;
r.quant=FSMquant;
r.remove=FSMremove;
r.deleteall=FSMdeleteall;
r.get=FSMstate;
r.recal=FSMrecall;
r.lh=FSMlh;
r.hl=FSMhl;
r.diff=FSMdiff;
r.mayic=FSMmayic;
r.getnumv2=FSMgetnumv2;
r.strtotok=FSMstrtotok;

/******/
return r;
}

/***FSM***/
LOGIC LogicCreate(int *eeprom, int sizeeeprom, int prog)
{
int cells;

/***Declare Functions***/
char* FSMreadconsole(FILE* stream);
int FSMreadint(int nmin, int nmax);
int FSMgetnum(char* x);
char* FSMputstr(char* str);
char* FSMftos(FILE* stream);
char* FSMfltos(FILE* stream);
int LOGICread(struct logica *r, int input);
int LOGIClearn(struct logica *r, int input, int output);
int FSMquant(struct logica *r);
int LOGICremove(struct logica *r, int input);
int FSMdeleteall(struct logica *r);
int FSMlh(int xi, int xf);
int FSMhl(int xi, int xf);
int FSMmayic(int xi, int xf, int nbits);
int FSMdiff(int xi, int xf);
int FSMrecall(struct logica *r);
unsigned int FSMgetnumv2(char* x);
int FSMstrtotok(char* line,char* token[],const char* parser);

/***Create Object***/
struct logica r;

//Inicialize varibles
r.mem=eeprom;
r.sizeblock=4;
cells=sizeeeprom/r.sizeblock;
r.sizeeeprom=cells*r.sizeblock;
r.page=prog;
r.recall=0;
r.output=0;

//Functions pointers or Vtable to declared functions
r.fltos=FSMfltos;
r.ftos=FSMftos;
r.getnum=FSMgetnum;
r.putstr=FSMputstr;
r.readconsole=FSMreadconsole;
r.readint=FSMreadint;
r.read=LOGICread;
r.learn=LOGIClearn;
r.quant=FSMquant;
r.remove=LOGICremove;
r.deleteall=FSMdeleteall;
r.recal=FSMrecall;
r.lh=FSMlh;
r.hl=FSMhl;
r.diff=FSMdiff;
r.mayic=FSMmayic;
r.getnumv2=FSMgetnumv2;
r.strtotok=FSMstrtotok;

/******/
return r;
}

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
diferenca=r->diff(r->recall,input);
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
int i2;
int programmed;
int block[r->sizeblock];
int keyfound;
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

/***readconsole***/
char* FSMreadconsole(FILE* stream)
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
int FSMreadint(int nmin, int nmax)
{
int num;
int flag;
for(flag=1; flag;){
for( num=0; !scanf("%d",&num); getchar());
//printf("num: %d nmin: %d nmax: %d\n",num, nmin, nmax);
if((num < nmin) || (num > nmax))
continue;
flag=0;
}
return num;
}

/***getnum***/
int FSMgetnum(char* x)
{
int num;
if(!sscanf(x, "%d", &num))
num=0;
return num;
}

/*****putstr*******/
char* FSMputstr(char* str)
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
char* FSMftos(FILE* stream)
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
char* FSMfltos(FILE* stream)
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

/***get***/
int FSMstate(struct routine *r)
{
//printf("FSMget: %d\n",r->present);
return r->present;
}

/***recal***/
int FSMrecall(struct routine *r)
{
return r->recall;
}

/***lh***/
int FSMlh(int xi, int xf)
{
int i;
i=xf^xi;
//if(!i)
//i=xf;
i&=xf;
return i;
}

/***hl***/
int FSMhl(int xi, int xf)
{
int i;
i=xf^xi;
if(!i)
i=xi;
i&=xi;
return i;
}

/***diff***/
int FSMdiff(int xi, int xf)
{
return xi^xf;
}

/***mayic***/
int FSMmayic(int xi, int xf, int nbits)
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
unsigned int FSMgetnumv2(char* x)
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
int FSMstrtotok(char* line,char* token[],const char* parser)
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

/**/
