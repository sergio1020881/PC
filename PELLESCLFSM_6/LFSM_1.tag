SQLite format 3   @     �   )   	                                                      � -�#   � zA�                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  C_indexFilenameBrowseCREATE INDEX Filename ON Browse(Filename)4KindexTagBrowseCREATE INDEX Tag ON Browse(Tag)7OindexNameBrowseCREATE INDEX Name ON Browse(Name)��atableBrowseBrowseCREATE TABLE Browse (Kind INTEGER,Name TEXT,Tag TEXT,Filename TEXT,Lineno INTEGER,Text TEXT,Extra INTEGER)   �    $�����������������������                E#Sreadconsoleroutinelfsm.c>char* (*readconsole)(FILE* stream);*%presentroutinelfsm.c;int present;(#recallroutinelfsm.c:int recall;$pageroutinelfsm.c9int page;.)sizeblockroutinelfsm.c8int sizeblock;0!+sizeeepromroutinelfsm.c7int sizeeeprom;#memroutinelfsm.c6int *mem;routinelfsm.c3fileficheirolfsm.c/>Qopenficheirolfsm.c,FILE* (*open)(struct ficheiro *f);>
Ocloseficheirolfsm.c+int (*close)(struct ficheiro *f);^		�strtotokficheirolfsm.c*int (*strtotok)(char* line,char* token[],const char* parser);:Gfltosficheirolfsm.c)char* (*fltos)(FILE* stream);8Eftosficheirolfsm.c(char* (*ftos)(FILE* stream);31permisionficheirolfsm.c%char permision[8];33filenameficheirolfsm.c$char filename[128];#   �f   '�M   �3   �   �   �h   �P   )�6   &�&   %�   �   !}   (e   I   "8    ,      � �   ���������I= ��� ��������� �����l������a"�yoY �� �I3�2 � �����">(��wR<`J ��t_ �          
printfPopenOftosN!filecreateMfL	tokenKstrJnumber2Inumber1Hnumber3GcmdFmainEargvDargcCeeprom2Beeprom1A	LOGIC@strtotok?getnumv2>	mayia=diff<hl;lh:get9deleteall8
remove7	quant6	learn5read4	fltos3ftos2
putstr1
getnum0readint/#readconsole.
output-
recall,page+sizeblock*!sizeeeprom)mem(
logica'FSM&strtotok%getnumv2$	mayia#diff"hl!lh getdeleteall
remove	quant	learnread	fltosftos
putstr
getnumreadint#readconsolepresent
recallpagesizeblock!sizeeeprommemroutinefileopen	close
strt   	fltosf   number3G�� fp   readx         
    !LOGIClearn �   �    ���/*%  � � � � � � � � � � � � � ���������}<1&������������vk`UJ?4l`TH<0$ ����������|pdXL��XWVUTSRQPONMLKJIHGFEDCBA
logica@
logica?
logica>
logica=
logica<
logica;
logica:
logica9
logica8
logica7
logica6
logica5
logica4
logica3
logica2
logica1
logica0
logica/
logica.
logica-
logica,
logica+
logica*
logica)
logica('routine&routine%routine$routine#routine"routine!routine routineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineficheiroficheiroficheiro
ficheiro	ficheiroficheiroficheirof   
logica5   $    �   �    ���������}rg\QF;0%������������uj_TI>3(������������xmbWLA6+ 
 � � � � � � � � �   
lfsm.cN
lfsm.cM
lfsm.cL
lfsm.cK
lfsm.cJ
lfsm.cI
lfsm.cH
lfsm.cG
lfsm.cF
lfsm.cE
lfsm.cD
lfsm.cC
lfsm.cB
lfsm.cA
lfsm.c@
lfsm.c?
lfsm.c>
lfsm.c=
lfsm.c<
lfsm.c;
lfsm.c:
lfsm.c9
lfsm.c8
lfsm.c7
lfsm.c6
lfsm.c5
lfsm.c4
lfsm.c3
lfsm.c2
lfsm.c1
lfsm.c0
lfsm.c/
lfsm.c.
lfsm.c-
lfsm.c,
lfsm.c+
lfsm.c*
lfsm.c)
lfsm.c(
lfsm.c'
lfsm.c&
lfsm.c%
lfsm.c$
lfsm.c#
lfsm.c"
lfsm.c!
lfsm.c 
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c

lfsm.c	
lfsm   lfsm.cB   lfsm.c   lfsm.c �   
lfsm.c �   
lfsm.cF    ,C]���&b�B`y��=c��������   4;FSMgetnum
TRUElfsm.c1
EMPTYlfsm.cficheirolfsm.c #fpficheirolfsm.c#FILE *fp;33filenameficheirolfsm.c$char filename[128];31permisionficheirolfsm.
TRUElfsm.c1
EMPTYlfsm.cficheirolfsm.c #fpficheirolfsm.c#FILE *fp;33filenameficheirolfsm.c$char filename[128];31permisionficheirolfsm.c%char permision[8];8Eftosficheirolfsm.c(char* (*ftos)(FILE* stream);:Gfltosficheirolfsm.c)char* (*fltos)(FILE* stream);^		�strtotokficheirolfsm.c*int (*strtotok)(char* line,char* token[],const char* parser);>
Ocloseficheirolfsm.c+int (*close)(struct ficheiro *f);>Qopenficheirolfsm.c,FILE* (*open)(struct ficheiro *f);fileficheirolfsm.c/routinelfsm.c3#memroutinelfsm.c6int *mem;0!+sizeeepromroutinelfsm.c7int sizeeeprom;.)sizeblockroutinelfsm.c8int sizeblock;    �  � �E��?x�j����T����������!S$pageroutinelfsm.c9int page;(#recallroutinelfsm.c:int recall;*%presentroutinelfsm.c;int present;E$pageroutinelfsm.c9int page;(#recallroutinelfsm.c:int recall;*%presentroutinelfsm.c;int present;E#Sreadconsoleroutinelfsm.c>char* (*readconsole)(FILE* stream);ASreadintroutinelfsm.c?int (*readint)(int nmin, int nmax);4;getnumroutinelfsm.c@int (*getnum)(char* x);8Cputstrroutinelfsm.cAchar* (*putstr)(char* str);7Eftosroutinelfsm.cBchar* (*ftos)(FILE* stream);9Gfltosroutinelfsm.cCchar* (*fltos)(FILE* stream);S}readroutinelfsm.cDint (*read)(struct routine *r, int input, int feedback);`	�learnroutinelfsm.cEint (*learn)(struct routine *r, int input, int next, int feedback);<Mquantroutinelfsm.cFint (*quant)(struct routine *r);Vremoveroutinelfsm.cGint (*remove)(struct routine *r, int input, int present);
   E
 
*5@KValw������������'2=HS^it�����������$/:EP[fq|��������������������fsm		lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c	
		lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c	
lfsm.c

lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c 
lfsm.c!
lfsm.c"
lfsm.c#
lfsm.c$
lfsm.c%
lfsm.c&
lfsm.c'
lfsm.c(
lfsm.c)
lfsm.c*
lfsm.c+
lfsm.c,
lfsm.c-
lfsm.c.
lfsm.c/
lfsm.c0
lfsm.c1
lfsm.c2
lfsm.c3
lfsm.c4
lfsm.c5
lfsm.c6
lfsm.c7
lfsm.c8
lfsm.c9
lfsm.c:
lfsm.c;
lfsm.c<
lfsm.c=
lfsm.c>
lfsm.c?
lfsm.c@
lfsm.cA
lfsm.cB
lfsm.cC
lfsm.cD
lfsm.cE          #   #   #      $         '            '   '               &   &            %      %      (   (   (         )   )      eleteallroutinelfsm.cHint (*deleteall)(struct routine *r);8Vremoveroutinelfsm.cGint (*remove)(struct routine *r, int input, int present);DUdeleteallroutinelfsm.cHint (*deleteall)(struct routine *r);8Igetroutinelfsm.cIint (*get)(struct routine *r);> Orecallroutinelfsm.cJint (*recall)(struct routine *r);3!Alhroutinelfsm.cKint (*lh)(int xi, int xf);3"Ahlroutinelfsm.cLint (*hl)(int xi, int xf);7#Ediffroutinelfsm.cMint (*diff)(int xi, int xf);D$]mayiaroutinelfsm.cNint (*mayia)(int xi, int xf, int nbits);A%Qgetnumv2routinelfsm.cOunsigned int (*getnumv2)(char* x);]&	�strtotokroutinelfsm.cPint (*strtotok)(char* line,char* token[],const char* parser);   FSMroutinelfsm.cS(logicalfsm.cY")memlogicalfsm.c\int *mem;/*!+sizeeepromlogicalfsm.c]int sizeeeprom;
   D	 	*5@KValw������������'2=HS^it�����������$/:EP[fq|������������������
lfsm.
lfsm.cG
lfsm.cH
lfsm.cI
lfsm.cJ
lfsm.cK
lfsm.cL
lfsm.cM
lfsm.cN
lfsm
lfsm.cG
lfsm.cH
lfsm.cI
lfsm.cJ
lfsm.cK
lfsm.cL
lfsm.cM
lfsm.cN
lfsm.cO
lfsm.cP
lfsm.cQ
lfsm.cR
lfsm.cS
lfsm.cT
lfsm.cU
lfsm.cV
lfsm.cW
lfsm.cX
lfsm.cY
lfsm.cZ
lfsm.c[
lfsm.c\
lfsm.c]
lfsm.c^
lfsm.c_
lfsm.c`
lfsm.ca
lfsm.cb
lfsm.cc
lfsm.cd
lfsm.ce
lfsm.cf
lfsm.cg
lfsm.ch
lfsm.ci
lfsm.cj
lfsm.ck
lfsm.cl
lfsm.cm
lfsm.cn
lfsm.co
lfsm.cp
lfsm.cq
lfsm.cr
lfsm.cs
lfsm.ct
lfsm.cu
lfsm.cv
lfsm.cw
lfsm.cx
lfsm.cy
lfsm.cz
lfsm.c{
lfsm.c|
lfsm.c}
lfsm.c~
lfsm.clfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �    �  � �2f��%����6n���7�����pW?& � � � � � v ]",6@rstrcmplfsm.c �qdeletealllfsm.c �pstrcmplfsm.c �ostrcmplfsm.c �n69Ggetlogicalfsm.cnint (*get)(struct logica *r);2:Alhlogicalfsm.coint (*lh)(int xi, int xf);2;Ahllogicalfsm.cpint (*hl)(int xi, int xf);6<Edifflogicalfsm.cqint (*diff)(int xi, int xf);C=]mayialogicalfsm.crint (*mayia)(int xi, int xf, int nbits);@>Qgetnumv2logicalfsm.csunsigned int (*getnumv2)(char* x);\?	�strtotoklogicalfsm.ctint (*strtotok)(char* line,char* token[],const char* parser);@LOGIClogicalfsm.cw'A-eeprom1lfsm.c}int eeprom1[83];'B-eeprom2lfsm.c~int eeprom2[83];Cargclfsm.c �int argc,"D'argvlfsm.c �char *argv[])6E	Qmainlfsm.c �int main(int argc, char *argv[]) {F!cmdlfsm.c �char *cmd;$G%number3lfsm.c �int number3;$H%number1lfsm.c �int number1;$I%number2lfsm.c �int number2;
   = �  � � � � � � � � -:GUcq}��������%3ALWbp~���������%9IYix����������	EM				EMPTYFILEclose~FILEclosedFILEopenFILEopengFSM&%FSMdeleteall �%FSMdeleteall �%FSMdeleteallFSMdiff �FSMdiff �FSMdiffGFSMfltos|FSMfltos �FSMfltos �FSMfltos2FSMftos{FSMftos �FSMftos �FSMftos(FSMgetnum �FSMgetnum �FSMgetnum#FSMgetnumv2 �#FSMgetnumv2 �#FSMgetnumv2Q
FSMhl �
FSMhl �
FSMhlCFSMlearn �FSMlearn �
FSMlh �
FSMlh �
FSMlh?FSMmayia �FSMmayia �FSMmayiaKFSMputstr �FSMputstr �FSMputstr!FSMquant �FSMquant �FSMquant �FSMread �FSMread �)FSMreadconsole �)FSMreadconsole �)FSMreadconsole!FSMreadint �!FSMreadint �!FSMreadintFSMremove �FSMremove �FSMstate �FSMstate<#FSMstrtotok}#FSMstrtotok �#FSMstrtotok �#FSMstrtotokZ	LOGIC@!LOGIClearn �
   I �  � � � � � �)5=FOZep{�����������
)1?M[jy�����������%1=CJQXdr�������������fLOGICread �LOGICread �#LOGICremove �#LOGICremove �#LogicCreateW#LogicCreate �NBytesNBytes+NBytes5RETURNR	TRUEargcCargvD
block �
block �
block �
block �
block �
block �
block 
block
block*
block4calloc$calloc]caractercaracter,caracter6
cells �
cells �	close
	closeScmdFdeletealldeleteall8deleteallqdiferenca �diferenca �diferenca �diferenca �diferenca �diferencadiff"diff<	diff �	diff �	diff �	diff �	diff �	diff	diffMeeprom �eeprom �eeprom1Aeeprom2BfLf �fcfffcloseefeedback �feedback �ficheirofile!filecreateM!filecreatezfilenamefilenamey	flag	fltos	fltos	fltos3	fltos_
   xu uy~������������������������� 
#(-27<AFKPUZ_dinsx}������������������������
"(.4:@FLRX^djpv|�������������������������������������	'ABCDEFGHIJKLM	'ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~ � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �
   of flrx~��������������������� &,28>DJPV\bhntz����������������������
"(.4:@FLRX^djpv|������������������������������������� � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � 	
 !"#
   V �  � � � � � � �	 )2;CKU_iv��������������
!)19AIQYaiqy�����������	$.8BIPZenx�������������nput	getc.		fltosi	fltosu
fopen �fpfreeR	freebfsmstartUfsmstart �ftosftosftos2ftosNgetget9	getc	getc.	getc8getchar
getnum
getnum0
getnum`
getnumg
getnumj
getnumvgetnumv2$getnumv2>hl!hl;ii"i)i3i@iDi[i1 �i1 �i1 �i1 �i1 �i1 �i1 �i1i2 �i2 �i2 �i2 �i2 �i2 �
input �
input �
input �
input �
input �
input �keyfound �keyfound �keyfound �keyfound �keyfound �keyfoundlVl �	learn	learn5	learnklh lh:	lineW
logica'mainE	maskL	mayia#	mayia=	mayiaYmemmem(nT
nbitsJ	next �	nmax	nminnumnumnumber1Hnumber2I
   ? $0<HT`lx����������� ,8DP\ht�����������(4@LXdp|������������������� �llfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �
   Yj ��������������� $*06<BHNTZ`flrx~��������������������������|vpj�	#0=JWdq|�����������DEFGHIJKLMNOPQRSTUVWXYZ[\ficheiroficheirogfedcba`_^%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]ficheiroficheiroficheiroficheiroficheiroficheiro	ficheiro
ficheiroficheiro
logica(
logica)
logica*
logica+
logica,
logica-
logica.
logica/
logica0
logica1
logica2
logica3
logica4
   F � Scs���������������(G;/#4�<GR]hs~����� ���� � ������9��'�2tdTD|l\L�����������������������������������Jstrtok`strcpy_strlen^str\
tokenXsscanfU
valueSxP
transNxfIxiHxfFxiExfBxiAxf>xi=realloc9
value7stream1realloc/
value-stream'strlen%str sscanfx
scanfrealloc
valuestreamstatus	statusstatus �status �#readconsole#readconsole.readintreadint/
recall
recall,
remove
remove7
removewroutinesizeblocksizeblock*!sizeeeprom!sizeeeprom)!sizeeeprom �!sizeeeprom �status �strJ
strcmpa
strcmpb
strcmpc
strcmpd
strcmpl
strcmpm
strcmpo
strcmpp
strcmpr
strcmpsstrcpy �strcpy �strtotok	strtotok%strtotok?strtotokQ	tokenK    [����'Mz��S���� � �9��'�2tdTD|l\LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLg=blocklfsm.c�int block[r->sizeblock];�fi2lfsm.c�int i2;�estrtok`strcpy_strlen^str\
tokenX<~QFILEcloselfsm.c �int FILEclose(struct ficheiro *f);<SFILEopenlfsm.c �FILE* FILEopen(struct ficheiro *f);$� 1flfsm.c �struct ficheiro f;�strcpylfsm.c ��strcpylfsm.c ��fopenlfsm.c ��printflfsm.c �#�%eepromlfsm.c �int *eeprom,*�!+sizeeepromlfsm.c �int sizeeeprom,�proglfsm.c �int prog)M�	wfsmstartlfsm.c �FSM fsmstart(int *eeprom, int sizeeeprom, int prog) { �	!cellslfsm.c �int cells;B�
)SFSMreadconsolelfsm.c �char* FSMreadconsole(FILE* stream);>�!SFSMreadintlfsm.c �int FSMreadint(int nmin, int nmax);1�;FSMgetnumlfsm.c �int FSMgetnum(char* x);5�CFSMputstrlfsm.c �char* FSMputstr(char* str);
   ? $0<HT`lx����������� ,8DP\ht�����������(4@LXdp|��������������������int diflfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c lfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.c	lfsm.c

   AU ������a�����my�*5@KValw�����������+U7AK[doz�����������������������=bllfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �printfaparserYperrorVpowOopenopenO
output-output �pagepage+permisionperrorperror&perror0perror:presentpresent �
printfP
printfX
printfZ
printf[
printf]
printf^
printfe
printfh
printftprintf �printf �printf �printf �printf �printf �printf �printf �printf �printf �printf �printf �printf �printf �printfprintf
	prog �	prog �!programmed �ptr#
putstr
putstr1	quant	quant6	quant\	quantnrTr �r �r �r �r �r �r �r �rr;readread4
   6x x����������� ,8DP\ht�����������(4@LXdp|����������4@LXdp|���������� �ltos(FILlfsm.celfsm.clfsm.clfsm.c lfsm.c!lfsm.c"lfsm.c#lfsm.c$lfsm.c%lfsm.c&lfsm.c'lfsm.c(lfsm.c)lfsm.c*lfsm.c+lfsm.c,lfsm.c-lfsm.c.lfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.clfsm.c lfsm.c!lfsm.c"lfsm.c#lfsm.c$lfsm.c%lfsm.c&lfsm.c'lfsm.c(lfsm.c)lfsm.c*lfsm.c+lfsm.c,lfsm.c-lfsm.c.lfsm.c/lfsm.c0lfsm.c1lfsm.c2lfsm.c3lfsm.c4lfsm.c5lfsm.c6lfsm.c7lfsm.c8lfsm.c9lfsm.c:lfsm.c;lfsm.c<lfsm.c=lfsm.c>lfsm.c?lfsm.c@lfsm.cA    J ��V9���qY?%���aD' � � � | d J E E�����Q�hprintflfsm.c��gdifflfsm.c�(�f)diferencalfsm.c�int diferenca;#�e%statuslfsm.c�int status=0&�d'keyfoundlfsm.c�int keyfound;.�c=blocklfsm.c�int block[r->sizeblock];�bi2lfsm.c�int i2;�ai1lfsm.c�int i1;S�`	!LOGIClearnlfsm.c�int LOGIClearn(struct logica *r, int input, int output) {"�_#outputlfsm.c�int output) �^!inputlfsm.c�int input,#�]/rlfsm.c�struct logica *r,�\printflfsm.c��[printflfsm.c��Zdifflfsm.c�(�Y)diferencalfsm.c�int diferenca;#�X%statuslfsm.c�int status=0&�W'keyfoundlfsm.c�int keyfound;.�V=blocklfsm.c�int block[r->sizeblock];�Ui2lfsm.c�int i2;�Ti1lfsm.c�int i1;]�S		�FSMlearnlfsm.c�int FSMlearn(struct routine *r, int input, int next, int feedback) {&�R'feedbacklfsm.c�int feedback)�Qnextlfsm.c�int next,
   $[ [fq|�����������(4@LXdp|����������O �P!inputlfsm.c�int input,$�O1rlfsm.c�struct routine *r,�Nprintflfsm.c��Mprintflfsm.c��Lprintflfsm.c��Kprintflfsm.c��Jdifflfsm.c�(�I)diferencalfsm.c�int diferenca;&�H'keyfoundlfsm.c�int keyfound;.�G=blocklfsm.c�int block[r->sizeblock];�Fi2lfsm.c�int i2;�Ei1lfsm.c�int i1;� H	eLOGICreadlfsm.c�int LOGICread(struct logica *r, int input) { �C!inputlfsm.c�int input)#�B   {pend}f
logica6
logica7
logica8
logica9
logica:
logica;
logica<
logica=
logica>
logica?
logica@routineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutine routine!routine"routine#routine$routine%routine&    Z ���f9���@#���[C) � � w Z�����(4LXdp|����i2lfsm.c3int i2;�~i1lfsm.c2int i1;I�}	#iLOGICremovelfsm.c0int LOGICremove(struct logica *r, int input) { �|!inputlfsm.c0int input)#�{/rlfsm.c0struct logica *r,�zprintflfsm.c+�ydifflfsm.c(�x)diferencalfsm.cint diferenca;#�w%statuslfsm.cint status=0&�v'keyfoundlfsm.cint keyfound;.�u=blocklfsm.cint block[r->sizeblock];�ti2lfsm.cint i2;�si1lfsm.cint i1;T�r		�FSMremovelfsm.cint FSMremove(struct routine *r, int input, int present) {$�q%presentlfsm.cint present) �p!inputlfsm.cint input,$�o1rlfsm.cstruct routine *r,.�n=blocklfsm.cint block[r->sizeblock];*�m!+programmedlfsm.cint programmed;�li1lfsm.cint i1;9�k	OFSMquantlfsm.cint FSMquant(struct routine *r) {$�j1rlfsm.cstruct routine *r)�iprintflfsm.c�    X ����Z;! ���rX>���pF  � � � s X��numlfsm.cwi�3ilfsm.c�int i,6�2	IFSMfltoslfsm.c�char* FSMfltos(FILE* stream) {$�1'streamlfsm.c�FILE* stream)�0perrorlfsm.c��/realloclfsm.c��.getclfsm.c�#�-'valuelfsm.c�char* value=N'�,)caracterlfsm.c�char caracter;,�+7NByteslfsm.c�int i, block, NBytes;#�*'blocklfsm.c�int i, block,�)ilfsm.c�int i,4�(	GFSMftoslfsm.c�char* FSMftos(FILE* stream) {$�''streamlfsm.c�FILE* stream)�&perrorlfsm.c��%strlenlfsm.c��$calloclfsm.c��#!ptrlfsm.c�char* ptr;�"ilfsm.c�int i;5�!	EFSMputstrlfsm.c�char* FSMputstr(char* str) {� !strlfsm.c�char* str)�sscanflfsm.c��numlfsm.c�int num;1�	=FSMgetnumlfsm.c�int FSMgetnum(char* x) {�xlfsm.c�char* x)�getcharlfsm.cz�scanflfsm.cz�flaglfsm.cxint flag;
   %D P\ht�����������(4@LXdp|����������Ductffltoslfsm.c �ggetnumlfsm.c �hprintflfsm.c �ifltoslfsm.c �jgetnumlfsm.c �klearnlfsm.c �lstrcmffltoslfsm.c �ggetnumlfsm.c �hprintflfsm.c �ifltoslfsm.c �jgetnumlfsm.c �klearnlfsm.c �lstrcmplfsm.c �mstrcmplfsm.c �nquantlfsm.c �ostrcmplfsm.c �pstrcmplfsm.c �qdeletealllfsm.c �rstrcmplfsm.c �slfsm.cglfsm.cClfsm.cDlfsm.cElfsm.cFlfsm.cGlfsm.cHlfsm.cIlfsm.cJlfsm.cKlfsm.cLlfsm.cMlfsm.cNlfsm.cOlfsm.cPlfsm.cQlfsm.cRlfsm.cSlfsm.cTlfsm.cUlfsm.cVlfsm.cWlfsm.cXlfsm.cYlfsm.cZlfsm.c[lfsm.c\lfsm.c]lfsm.c^lfsm.c_lfsm.c`lfsm.calfsm.cblfsm.cclfsm.cdlfsm.celfsm.cf    @ ���U=#���u[4���U/ � � � � _ @|���numlfsm.cwint num;>�	!UFSMreadintlfsm.cuint FSMreadint(int nmin, int nmax) {�nmaxlfsm.cuint nmax)�nminlfsm.cuint nmin,�perrorlfsm.ci�realloclfsm.cg�getclfsm.cd#�'valuelfsm.ccchar* value=N'�)caracterlfsm.cbchar caracter;,�7NByteslfsm.caint i, block, NBytes;#�'blocklfsm.caint i, block,�ilfsm.caint i,B�	)UFSMreadconsolelfsm.c_char* FSMreadconsole(FILE* stream) {$�'streamlfsm.c_FILE* stream)�
printflfsm.cZ#�	%statuslfsm.cQint status=0�i1lfsm.cPint i1;A�	%WFSMdeletealllfsm.cNint FSMdeleteall(struct routine *r) {$�1rlfsm.cNstruct routine *r)�printflfsm.cI�difflfsm.c8(�)diferencalfsm.c7int diferenca;#�%statuslfsm.c6int status=0&�'keyfoundlfsm.c5int keyfound;.� =blocklfsm.c4int block[r->sizeblock];    T ��sB�����nH%���rI � � � � w T���#�i   /! �P!inputlfsm.c�int input,$�O1rlfsm.c�struct routine *r,�Nprintflfsm.c��Mprintflfsm.c��Lprintflfsm.c��Kprintflfsm.c��Jdifflfsm.c�(�I)diferencalfsm.c�int diferenca;&�H'keyfoundlfsm.c�int keyfound;.�G=blocklfsm.c�int block[r->sizeblock];�Fi2lfsm.c�int i2;�Ei1lfsm.c�int i1;E�D	eLOGICreadlfsm.c�int LOGICread(struct logica *r, int input) { �C!inputlfsm.c�int input)#�B/rlfsm.c�struct logica *r,�Aprintflfsm.c��@printflfsm.c~�?printflfsm.c{�>printflfsm.cx�=difflfsm.co(�<)diferencalfsm.cnint diferenca;&�;'keyfoundlfsm.cmint keyfound;.�:=blocklfsm.clint block[r->sizeblock];�9i2lfsm.ckint i2;�8i1lfsm.cjint i1;P�7	FSMreadlfsm.chint FSMread(struct routine *r, int input, int feedback) {    c ���h:����l?����rX>$ � � � c X X��#�6��3r�3   .%�f3flfsm.c%struct ficheiro *f)�efcloselfsm.c <�d	SFILEcloselfsm.cint FILEclose(struct ficheiro *f) {%�c3flfsm.cstruct ficheiro *f)�bfreelfsm.c�aprintflfsm.c�`strtoklfsm.c�_strcpylfsm.c�^strlenlfsm.c�]calloclfsm.c�\!strlfsm.cchar *str;�[ilfsm.cint i;Z�Z		#�	FSMstrtotoklfsm.cint FSMstrtotok(char* line,char* token[],const char* parser) {*�Y3parserlfsm.cconst char* parser)$�X)tokenlfsm.cchar* token[], �W#linelfsm.cchar* line,�Vperrorlfsm.c�Usscanflfsm.c!�T+nlfsm.c�unsigned int n;)�S3valuelfsm.c�unsigned int value;+�R5RETURNlfsm.c�unsigned int RETURN;>�Q	#SFSMgetnumv2lfsm.c�unsigned int FSMgetnumv2(char* x) {�Pxlfsm.c�char* x)�Opowlfsm.c� �N!translfsm.c�int trans;    �  �5o��X��.R������                                   33 Alhroutinelfsm.cJint (*lh)(int xi, intDUdeleteallroutinelfsm.cHint (*deleteall)(struct routine *r);8Igetroutinelfsm.cIint (*get)(stDUdeleteallroutinelfsm.cHint (*deleteall)(struct routine *r);8Igetroutinelfsm.cIint (*get)(struct routine *r);3 Alhroutinelfsm.cJint (*lh)(int xi, int xf);3!Ahlroutinelfsm.cKint (*hl)(int xi, int xf);7"Ediffroutinelfsm.cLint (*diff)(int xi, int xf);D#]mayiaroutinelfsm.cMint (*mayia)(int xi, int xf, int nbits);A$Qgetnumv2routinelfsm.cNunsigned int (*getnumv2)(char* x);]%	�strtotokroutinelfsm.cOint (*strtotok)(char* line,char* token[],const char* parser);&FSMroutinelfsm.cR'logicalfsm.cX"(memlogicalfsm.c[int *mem;/)!+sizeeepromlogicalfsm.c\int sizeeeprom;-*)sizeblocklogicalfsm.c]int sizeblock;#+pagelogicalfsm.c^int page;',#recalllogicalfsm.c_int recall;    �  �)BZs�����#<Un�����6l�@LXdp|���������������������xl`TH<0DUdeleteallroutinelfsm.cHint (*deleteall)(struct routine *r);8Igetroutinelfsm.cIint (*get)(struct routffltoslfsm.c �ggetnumlfsm.c �hprintflfsm.c �ifltoslfsm.c �jgetnumlfsm.c �klearnlfsm.c �lstrcmplfsm.c �mstrcmplfsm.c �nquantlfsm.c �ostrcmplfsm.c �pstrcmplfsm.c �qdeletealllfsm.c �rstrcmplfsm.c �sstrcmplfsm.c �tprintflfsm.c �ufltoslfsm.c �vgetnumlfsm.c �wremovelfsm.c �xreadlfsm.c �(y+filenamelfsm.c �char *filename);z	!Ofilecreatelfsm.c �file filecreate(char *filename) {4{EFSMftoslfsm.c �char* FSMftos(FILE* stream);6|GFSMfltoslfsm.c �char* FSMfltos(FILE* stream);Z}	#�FSMstrtotoklfsm.c �int FSMstrtotok(char* line,char* token[],const char* parser);    7}��-e��7s�m� 9� 8 � � � � � � y C=]mayialogicalfsm.crint (*mayia)(int xi, int xf, int nbits);@/Sreadintlogicalfsm.cdint (*readint)(int nmin, int nmax);30;getnumlogicalfsm.ceint (*getnum)(char* x);71Cputstrlogicalf'-#outputlogicalfsm.c`int output;D.#Sreadconsolelogicalfsm.ccchar* (*readconsole)(FILE* stream);@/Sreadintlogicalfsm.cdint (*readint)(int nmin, int nmax);30;getnumlogicalfsm.ceint (*getnum)(char* x);71Cputstrlogicalfsm.cfchar* (*putstr)(char* str);62Eftoslogicalfsm.cgchar* (*ftos)(FILE* stream);83Gfltoslogicalfsm.chchar* (*fltos)(FILE* stream);C4_readlogicalfsm.ciint (*read)(struct logica *r, int input);Q5ylearnlogicalfsm.cjint (*learn)(struct logica *r, int input, int output);:6Kquantlogicalfsm.ckint (*quant)(struct logica *r);G7cremovelogicalfsm.clint (*remove)(struct logica *r, int input);B8Sdeletealllogicalfsm.cmint (*deleteall)(struct logica *r);    7}��-e��7s�m� 9� 8�             C=]mayialogicalfsm.crint (*mayia)(int xi, int xf, int nbits);@/Sreadintlogicalfsm.cdint (*readint)(int nmin, int nmax);30;getnumlogicalfsm.ceint (*getnum)(char* x);71Cputstrlogicalf'-#outputlogicalfsm.c`int output;D.#Sreadconsolelogicalfsm.ccchar* (*readconsole)(FILE* stream);@/Sreadintlogicalfsm.cdint (*readint)(int nmin, int nmax);30;getnumlogicalfsm.ceint (*getnum)(char* x);71Cputstrlogicalfsm.cfchar* (*putstr)(char* str);62Eftoslogicalfsm.cgchar* (*ftos)(FILE* stream);83Gfltoslogicalfsm.chchar* (*fltos)(FILE* stream);C4_readlogicalfsm.ciint (*read)(struct logica *r, int input);Q5ylearnlogicalfsm.cjint (*learn)(struct logica *r, int input, int output);:6Kquantlogicalfsm.ckint (*quant)(struct logica *r);G7cremovelogicalfsm.clint (*remove)(struct logica *r, int input);B8Sdeletealllogicalfsm.cmint (*deleteall)(struct logica *r);   � �@h�����2Ni����� 9Rj�����    M!filecreatelfsm.c �Lflfsm.c �file f=f&K-tokenlfsm.c �char* token[10];J#strlfsm.c �char* str=N$I%number2lfsm.c �int number2;$H%number1lfsm.c �int number1;$G%nuJ#strlfsm.c �char* str=N&K-tokenlfsm.c �char* token[10];Lflfsm.c �file f=fM!filecreatelfsm.c �Nftoslfsm.c �Oopenlfsm.c �Pprintflfsm.c �Qstrtotoklfsm.c �Rfreelfsm.c �Scloselfsm.c �Trlfsm.c �FSM r = Ufsmstartlfsm.c �V!llfsm.c �LOGIC l = W#LogicCreatelfsm.c �Xprintflfsm.c �Ymayialfsm.c �Zprintflfsm.c �[printflfsm.c �\quantlfsm.c �]printflfsm.c �^printflfsm.c �_fltoslfsm.c �`getnumlfsm.c �astrcmplfsm.c �bstrcmplfsm.c �cs<�g	UFILEopenlfsm.c%FILE* FILEopen(struct ficheiro *f) {    �  �!Z�I��R��b�$X��,V��]��r{pend}lfsm.4�EFSMftoslfsm.c �char* FSMftos(FILE* stream);6�GFSMfltoslfsm.c �char* FSMfltos(FILE* stream);P�}FSMreadlfsm.c �int FSMread(struct 4�EFSMftoslfsm.c �char* FSMftos(FILE* stream);6�GFSMfltoslfsm.c �char* FSMfltos(FILE* stream);P�}FSMreadlfsm.c �int FSMread(struct routine *r, int input, int feedback);]�	�FSMlearnlfsm.c �int FSMlearn(struct routine *r, int input, int next, int feedback);9�MFSMquantlfsm.c �int FSMquant(struct routine *r);S�FSMremovelfsm.c �int FSMremove(struct routine *r, int input, int present);A�%UFSMdeletealllfsm.c �int FSMdeleteall(struct routine *r);9�MFSMstatelfsm.c int FSMstate(struct routine *r);0�AFSMlhlfsm.cint FSMlh(int xi, int xf);0�AFSMhllfsm.cint FSMhl(int xi, int xf);A�]FSMmayialfsm.cint FSMmayia(int xi, int xf, int nbits);4�EFSMdifflfsm.cint FSMdiff(int xi, int xf);   # #d��:[��]���U/ � � � � @ @ @ @4@L�numlfsm.cwint num;� A	!UFSMreadintlfsm.cuint FSMreadint(int nmin, int nmax) {�nmaxlfsm.cuint nmax)�nminlfsm.cuint nmin,�perrorlfsm.ci�realloclfsm.cg�>�#QFSMgetnumv2lfsm.cunsigned int FSMgetnumv2(char* x);Z�	#�FSMstrtotoklfsm.cint FSMstrtotok(char* line,char* token[],const char* parser);#�/rlfsm.c	struct routine r;#�%eepromlfsm.c-int *eeprom,*�!+sizeeepromlfsm.c-int sizeeeprom,�proglfsm.c-int prog)V� 		#�LogicCreatelfsm.c-LOGIC LogicCreate(int *eeprom, int sizeeeprom, int prog) { �!!cellslfsm.c/int cells;B�")SFSMreadconsolelfsm.c2char* FSMreadconsole(FILE* stream);>�#!SFSMreadintlfsm.c3int FSMreadint(int nmin, int nmax);1�$;FSMgetnumlfsm.c4int FSMgetnum(char* x);5�%CFSMputstrlfsm.c5char* FSMputstr(char* str);4�&EFSMftoslfsm.c6char* FSMftos(FILE* stream);    G ���[C(���q>#���~a* � � � h G'feedb�Mdifflfsm.c�int diff;�Lmasklfsm.c�int mask;A�K	_FSMmayialfsm.c�int FSMmayia(int xi, int xf, int nbits) { �J!nbitslfsm.c�int nbits)�Ixflfsm.c�int xf,�Hxilfsm.c�int xi,4�G	GFSMdifflfsm.c�int FSMdiff(int xi, int xf) {�Fxflfsm.c�int xf)�Exilfsm.c�int xi,�Dilfsm.c�int i;0�C	CFSMhllfsm.c�int FSMhl(int xi, int xf) {�Bxflfsm.c�int xf)�Axilfsm.c�int xi,�@ilfsm.c�int i;0�?	CFSMlhlfsm.c�int FSMlh(int xi, int xf) {�>xflfsm.c�int xf)�=xilfsm.c�int xi,9�<	OFSMstatelfsm.c�int FSMstate(struct routine *r) {$�;1rlfsm.c�struct routine *r)�:perrorlfsm.c��9realloclfsm.c��8getclfsm.c�#�7'valuelfsm.c�char* value=N'�6)caracterlfsm.c�char caracter;,�57NByteslfsm.c�int i, block, NBytes;#�4'blocklfsm.c�int i, block,    @h�����2Ni����� 9Rj��������V�m		#�LogicCreatelfsm.c-LOGIC LogicCreate(int *eeprom, int sizeeeprom, int prog) {�Usscanflfsm.c�Vperrorlfsm.c �W#linelfsm.cchar* line,$�X)tokenlfsm.cchar* token[],*�J#strlfsm.c �char* str=N&K-tokenlfsm.c �char* token[10];Lflfsm.c �file f=fM!filecreatelfsm.c �Nftoslfsm.c �Oopenlfsm.c �Pprintflfsm.c �Qstrtotoklfsm.c �Rfreelfsm.c �Scloselfsm.c �Trlfsm.c �FSM r = Ufsmstartlfsm.c �V!llfsm.c �LOGIC l = W#LogicCreatelfsm.c �Xprintflfsm.c �Ymayialfsm.c �Zprintflfsm.c �[printflfsm.c �\quantlfsm.c �]printflfsm.c �^printflfsm.c �_fltoslfsm.c �`getnumlfsm.c �astrcmplfsm.c �bstrcmplfsm.c �cstrcmplfsm.c �dstrcmplfsm.c �eprintflfsm.c �    H �)��_,��~= � � � q H                 ;'feedba&�6'feedbacklfsm.chint feedback) �5!inputlfsm.chint input,$�41rlfsm.chstruct routine *r,"�3-llfsm.cEstruct logica l;Z�2	#�FSMstrtotoklfsm.cBint FSMstrtotok(char* line,char* token[],const char* parser);>�1#QFSMgetnumv2lfsm.cAunsigned int FSMgetnumv2(char* x);4�0EFSMdifflfsm.c@int FSMdiff(int xi, int xf);A�/]FSMmayialfsm.c?int FSMmayia(int xi, int xf, int nbits);0�.AFSMhllfsm.c>int FSMhl(int xi, int xf);0�-AFSMlhlfsm.c=int FSMlh(int xi, int xf);@�,%SFSMdeletealllfsm.c<int FSMdeleteall(struct logica *r);I�+#gLOGICremovelfsm.c;int LOGICremove(struct logica *r, int input);8�*KFSMquantlfsm.c:int FSMquant(struct logica *r);S�)!}LOGIClearnlfsm.c9int LOGIClearn(struct logica *r, int input, int output);E�(cLOGICreadlfsm.c8int LOGICread(struct logica *r, int input);6�'GFSMfltoslfsm.c7char* FSMfltos(FILE* stream);