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
#define EMPTY 0

/***MY OBJECT***/
struct routine{
//Local Variables
int *mem;
int sizeeeprom;
int page;
int trace;
int present;

//Local Function pointers
char* (*readconsole)(FILE* stream);
int (*readint)(int nmin, int nmax);
int (*getnum)(char* x);
char* (*putstr)(char* str);
char* (*ftos)(FILE* stream);
char* (*fltos)(FILE* stream);
int (*read)(struct routine *r, int input);
int (*learn)(struct routine *r, int input, int data);
int (*quant)(struct routine *r);
int (*remove)(struct routine *r, int input);
int (*deleteall)(struct routine *r);
int (*set)(struct routine *r, int data);
int (*get)(struct routine *r);
int (*select)(struct routine *r, int page);
int (*viewpage)(struct routine *r);
int (*lh)(struct routine *r, int input);
int (*hl)(struct routine *r, int input);
};

typedef struct routine FSM;
FSM fsmstart(int *eeprom, int sizeeeprom);

/******/
int eeprom[83];

// Main
int main(int argc, char *argv[])
{
char *cmd;
int number1;
int number2;
FSM r = fsmstart(eeprom, 83);
printf("viewpage %d ",r.viewpage(&r));
printf("sizeeeprom: %d \n", r.sizeeeprom);

// Cycle
while(TRUE){
printf("write string with number\n");
cmd=r.fltos(stdin);
number1=r.getnum(cmd);
if(!strcmp(cmd,"quit") || !strcmp(cmd,"q"))
goto end;
if(!strcmp(cmd,"learn") || !strcmp(cmd,"l")){
printf("enter input\n");
cmd=r.fltos(stdin);
number1=r.getnum(cmd);
//printf("number1:\n%d\n",number1);
printf("enter output data\n");
cmd=r.fltos(stdin);
number2=r.getnum(cmd);
//printf("number2:\n%d\n",number2);
r.learn(&r,number1,number2);
}
if(!strcmp(cmd,"how many") || !strcmp(cmd,"h")){
r.quant(&r);
}
if(!strcmp(cmd,"delete all") || !strcmp(cmd,"d")){
r.deleteall(&r);
}
if(!strcmp(cmd,"remove") || !strcmp(cmd,"r")){
printf("enter input to remove\n");
cmd=r.fltos(stdin);
number1=r.getnum(cmd);
r.remove(&r,number1);
}
if(!strcmp(cmd,"set") || !strcmp(cmd,"s")){
printf("insert data\n");
cmd=r.fltos(stdin);
number1=r.getnum(cmd);
r.set(&r,number1);
}
//printf("number:\n%d\n",number1);
r.read(&r,number1);
}
/******/
end:
system("PAUSE");
return 0;
}

/****************************************************/

/***CONSTRUCTOR OF OBJECT***/
FSM fsmstart(int *eeprom, int sizeeeprom){
int cells;
int sizeblock=4;

/***Declare Functions***/
char* FSMreadconsole(FILE* stream);
int FSMreadint(int nmin, int nmax);
int FSMgetnum(char* x);
char* FSMputstr(char* str);
char* FSMftos(FILE* stream);
char* FSMfltos(FILE* stream);
int FSMread(struct routine *r, int input);
int FSMlearn(struct routine *r, int input, int data);
int FSMquant(struct routine *r);
int FSMremove(struct routine *r, int input);
int FSMdeleteall(struct routine *r);
int FSMset(struct routine *r, int data);
int FSMget(struct routine *r);
int FSMselect(struct routine *r, int page);
int FSMviewpage(struct routine *r);
int FSMlh(struct routine *r, int input);
int FSMhl(struct routine *r, int input);

/***Create Object***/
struct routine r;

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
r.set=FSMset;
r.get=FSMget;
r.select=FSMselect;
r.viewpage=FSMviewpage;
r.lh=FSMlh;
r.hl=FSMhl;

//Inicialize varibles
r.mem=eeprom;
r.sizeeeprom=sizeeeprom;
cells=r.sizeeeprom/sizeblock;
r.sizeeeprom=cells*sizeblock;
r.page=1;
r.present=0;
r.trace=255;

/******/
return r;
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

/***read***/
int FSMread(struct routine *r, int input)
{
int i1;
int i2;
int sizeblock=4;
int block[sizeblock];
int keyfound;
int lh;
if(r->trace!=input){
lh=r->lh(r,input);
for(i1=0;i1<r->sizeeeprom;i1+=sizeblock){
if(*(r->mem+i1)==r->page){
for(i2=0;i2<sizeblock;i2++){//get block from eeprom
block[i2]=*(r->mem+i1+i2);
}
keyfound=(block[1]==lh && block[2]==r->present);//bool
if(keyfound){
r->present=block[3];
break;
}
}
}
r->trace=input;
}
printf("Eoutput -> %d\n",r->present);
return r->present;
}

/***learn***/
int FSMlearn(struct routine *r, int input, int data)
{
int i1;
int i2;
int sizeblock=4;
int block[sizeblock];
int keyfound;
int status=0;
if(status==0){
for(i1=0;i1<r->sizeeeprom;i1+=sizeblock){
if(*(r->mem+i1)==r->page){
for(i2=0;i2<sizeblock;i2++){//get block from eeprom
block[i2]=*(r->mem+i1+i2);
}
keyfound=(block[1]==input && block[2]==r->present);//bool
if(keyfound){
status=1;//not permited
break;
}
}
status=3;//not existente
}
}
if(status==3){
for(i1=0;i1<r->sizeeeprom;i1+=sizeblock){
if(*(r->mem+i1)==EMPTY){
*(r->mem+i1)=r->page;
*(r->mem+i1+1)=input;
*(r->mem+i1+2)=r->present;
*(r->mem+i1+3)=data;
status=2;//created
break;
}
status=4;//not possible
}
}

printf("learn status: %d\n",status);
return status;
}

/***quant***/
int FSMquant(struct routine *r)
{
int i1;
int i2;
int programmed;
int sizeblock=4;
int block[sizeblock];
int keyfound;
for(i1=0,programmed=0;i1<r->sizeeeprom;i1+=sizeblock){
if(*(r->mem+i1)!=EMPTY)
programmed++;
}
printf("there are %d programmed\n",programmed);
return programmed;
}

/***remove***/
int FSMremove(struct routine *r, int input)
{
int i1;
int i2;
int sizeblock=4;
int block[sizeblock];
int keyfound;
int status=0;
if(status==0){
for(i1=0;i1<r->sizeeeprom;i1+=sizeblock){
if(*(r->mem+i1)==r->page){
for(i2=0;i2<sizeblock;i2++){//get block from eeprom
block[i2]=*(r->mem+i1+i2);
}
keyfound=(block[1]==input && block[2]==r->present);//bool
if(keyfound){
*(r->mem+i1)=EMPTY;
status=1;//removed
break;
}
}
}
}
printf("remove status: %d\n",status);
return status;
}

/***deleteall***/
int FSMdeleteall(struct routine *r)
{
int i1;
int i2;
int sizeblock=4;
int block[sizeblock];
int keyfound;
int status=0;
if(status==0){//not removed
for(i1=0;i1<r->sizeeeprom;i1+=sizeblock){
if(*(r->mem+i1)!=EMPTY){
*(r->mem+i1)=EMPTY;
status=1;//all deleted
}
}
}
printf("deleteall status: %d\n",status);
return status;
}

/***set***/
int FSMset(struct routine *r, int data)
{
r->present=data;
//printf("FSMset: %d\n",r->present);
return r->present;
}

/***get***/
int FSMget(struct routine *r)
{
//printf("FSMget: %d\n",r->present);
return r->present;
}

/***select***/
int FSMselect(struct routine *r, int page)
{
r->page=page;
//printf("FSMselect: %d\n",r->page);
return r->page;
}

/***viewpage***/
int FSMviewpage(struct routine *r)
{
//printf("FSMviewpage: %d\n",r->page);
return r->page;
}

/***lh***/
int FSMlh(struct routine *r, int input)
{
int i;
i=r->trace^input;
i&=input;
return i;
}

/***hl***/
int FSMhl(struct routine *r, int input)
{
int i;
i=r->trace^input;
i&=r->trace;
return i;
}
