SQLite format 3   @     
                                                            
 -�#   � zA�                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  C_indexFilenameBrowseCREATE INDEX Filename ON Browse(Filename)4KindexTagBrowseCREATE INDEX Tag ON Browse(Tag)7OindexNameBrowseCREATE INDEX Name ON Browse(Name)��atableBrowseBrowseCREATE TABLE Browse (Kind INTEGER,Name TEXT,Tag TEXT,Filename TEXT,Lineno INTEGER,Text TEXT,Extra INTEGER)   	�    ���������/i��$w� O              5	KFSMgetlfs   R
TRUElfsm.c1
EMPTYlfsm.c0routinelfsm.c#memroutinelfsm.cint *mem;0!+sizeeepromroutinelfsm.cint sizeeeprom;$pageroutinelfsm.cint page;&!traceroutinelfsm.cint trace;*%presentroutinelfsm.cint present;E	#Sreadconsoleroutinelfsm.c char* (*readconsole)(FILE* stream);A
Sreadintroutinelfsm.c!int (*readint)(int nmin, int nmax);4;getnumroutinelfsm.c"int (*getnum)(char* x);8Cputstrroutinelfsm.c#char* (*putstr)(char* str);7Eftosroutinelfsm.c$char* (*ftos)(FILE* stream);9Gfltosroutinelfsm.c%char* (*fltos)(FILE* stream);Eareadroutinelfsm.c&int (*read)(struct routine *r, int input);Qwlearnroutinelfsm.c'int (*learn)(struct routine *r, int input, int data);<Mquantroutinelfsm.c(int (*quant)(struct routine *r);Ieremoveroutinelfs   �D   �,   �   z   _   O   	9         �    ���� ��1�� �gb�r1� �q!�W�g&�T��� ������wl  |;zJ��^��?\�) �� �LA6+������QF
�	�         nminO)FSMreadconsoleNsizeblockM	cellsLfsmstartK!sizeeepromJ
eepromI
systemHreadGsetF
getnumE	fltosD
printfC
strcmpB
strcmpA
remove@
getnum?	fltos>
printf=
strcmp<
strcmp;deleteall:
strcmp9
strcmp8	quant7
strcmp6
strcmp5	learn4
getnum3	fltos2
printf1
getnum0	fltos/
printf.
strcmp-
strcmp,
strcmp+
strcmp*
getnum)	fltos(
printf'
printf&viewpage%
printf$fsmstart#r"number2!number1 cmdmainargvargc
eepromFSMhllhviewpage
selectgetsetdeleteall
remove	quant	learnread	fltosftos
putstr
getnumreadint
#readconsole	present	tracepage!sizeeeprommem      r"   fsmstart#   �    �������������������zupkfa\WRMHC>94/*% ��������������������������{vqlgb]XSNID?:50+&! ����������znbVJ>2&���  zyxwvutsrqponmlkjihgfedcba`_^]\[ZYXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:9876543210/.-,+*)('&%$#"! routineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutine
routine	routineroutineroutineroutineroutine    �   �    ���������}rg\QF;0%������������uj_TI>3(������������xmbWLA6+ 
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
lfsm.c
lfsm.c
lfsm.c
lfsm.c
lfsm.c
   lfsm.c �   

lfsm.cF   2 2Iaz���K��E~�$w���������������Mg   s
TRUElfsm.c1
EMPTYlfsm.c0routinelfsm.c#memroutinelfsm.cint *mem;0!+sizeeepromroutinelfsm.cint sizeeeprom;$pageroutinelfsm.cint page;&!traceroutine
TRUElfsm.c1
EMPTYlfsm.c0routinelfsm.c#memroutinelfsm.cint *mem;0!+sizeeepromroutinelfsm.cint sizeeeprom;$pageroutinelfsm.cint page;&!traceroutinelfsm.cint trace;*%presentroutinelfsm.cint present;E	#Sreadconsoleroutinelfsm.c char* (*readconsole)(FILE* stream);A
Sreadintroutinelfsm.c!int (*readint)(int nmin, int nmax);4;getnumroutinelfsm.c"int (*getnum)(char* x);8Cputstrroutinelfsm.c#char* (*putstr)(char* str);7Eftosroutinelfsm.c$char* (*ftos)(FILE* stream);9Gfltosroutinelfsm.c%char* (*fltos)(FILE* stream);Eareadroutinelfsm.c&int (*read)(struct routine *r, int input);    �  �X��-g��8{��� � q L����\y���3T~� *%# %number1lfsm.c=int number1;!cmdlfsm.c<char *cmd;5	Qmainlfsm.c:int main(int argc, char *argv[]) {Qwlearnroutinelfsm.c'int (*learn)(struct routine *r, int input, int data);<Mquantroutinelfsm.c(int (*quant)(struct routine *r);Ieremoveroutinelfsm.c)int (*remove)(struct routine *r, int input);DUdeleteallroutinelfsm.c*int (*deleteall)(struct routine *r);B]setroutinelfsm.c+int (*set)(struct routine *r, int data);8Igetroutinelfsm.c,int (*get)(struct routine *r);Hcselectroutinelfsm.c-int (*select)(struct routine *r, int page);BSviewpageroutinelfsm.c.int (*viewpage)(struct routine *r);A]lhroutinelfsm.c/int (*lh)(struct routine *r, int input);A]hlroutinelfsm.c0int (*hl)(struct routine *r, int input);FSMroutinelfsm.c3%+eepromlfsm.c7int eeprom[83];argclfsm.c:int argc,!'argvlfsm.c:char *argv[])                                                        	   	    x c        5	Qmainlfsm.c:int main(int argc, char *argv[]) {!cmdlfsm.c<char *cmd;# %number1lfsm.c=int number1;#!%number2lfsm.c>int number2;"rlfsm.c?FSM r = #   7Qmainlfsm.c:int main(int argc, char *argv[]) {!cmdlfsm.c<char *cmd;# %number1lfsm.c=int number1;#!%number2lfsm.c>int number2;"rlfsm.c?FSM r = #fsmstartlfsm.c?$printflfsm.c@%viewpagelfsm.c@&printflfsm.cA'printflfsm.cD(fltoslfsm.cE)getnumlfsm.cF*strcmplfsm.cG+strcmplfsm.cG,strcmplfsm.cI-strcmplfsm.cI.printflfsm.cJ/fltoslfsm.cK0getnumlfsm.cL1printflfsm.cN2fltoslfsm.cO3getnumlfsm.cP4learnlfsm.cR5strcmplfsm.cT6strcmplfsm.cT7quantlfsm.cU8strcmplfsm.cW9strcmplfsm.cW    Ut����%=Ul������+CZr�����>Yq�����Cp5	Qmainlfsm.c:int main(int argc, char *argv[]) {!cmdlfsm.c<char *cmd;# %number1lfsm.c=int number1;#!%number2lfsm.c>int number2;"rlfsm.c?FSM r = #5	Qmainlfsm.c:int main(int argc, char *argv[]) {!cmdlfsm.c<char *cmd;# %number1lfsm.c=int number1;#!%number2lfsm.c>int number2;"rlfsm.c?FSM r = #fsmstartlfsm.c?$printflfsm.c@%viewpagelfsm.c@&printflfsm.cA'printflfsm.cD(fltoslfsm.cE)getnumlfsm.cF*strcmplfsm.cG+strcmplfsm.cG,strcmplfsm.cI-strcmplfsm.cI.printflfsm.cJ/fltoslfsm.cK0getnumlfsm.cL1printflfsm.cN2fltoslfsm.cO3getnumlfsm.cP4learnlfsm.cR5strcmplfsm.cT6strcmplfsm.cT7quantlfsm.cU8strcmplfsm.cW9strcmplfsm.cW
   E
 
*5@KValw������������'2=HS^it�����������$/:EP[fq|��������������������   		lfsm.c
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
lfsm.cE
   D	 	*5@KValw������������'2=HS^it�����������$/:EP[fq|������������������
lfsm.cP
lfsm.cQ
lfsm.cR
lfsm.cS
lfsm.cT
lfsm.cU
lfsm.cV
lfsm.cW
lfsm.cX
lf
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
lfsm.clfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �
   E �  1CP^jv ���� ���� �����/BQ`n} �� �� ����������#.9DQ_mw�������������������		EMPTYFS
FSMhl �
FSMlh �#FSMviewpage �FSMselect �FSMget �FSMset �	data �	EMPTYFSM%FSMdeleteallX%FSMdeleteall �FSMfltosSFSMfltos �FSMftosRFSMftos}
FSMgetZFSMgetnumPFSMgetnumr	FSMhl^FSMlearnUFSMlearn �	FSMlh]FSMputstrQFSMputstrvFSMquantVFSMquant �FSMreadTFSMread �)FSMreadconsoleN)FSMreadconsolea!FSMreadintO!FSMreadintlFSMremoveWFSMremove �FSMselect[
FSMsetY#FSMviewpage\
NBytesdNBytes �NBytes �	TRUEargcargv	blockc	block
block �
block �
block �
block �
block �
block �
callocycaracterecaracter �caracter �	cellsLcmd	data �deletealldeleteall:
eeprom
eepromIflagn	fltos	fltos(	fltos/	fltos2	fltos>	fltosD
   M � '4=ENXbny��������� �������  +6 AO]ky��������������(4@KValw����������� ������keyfound keyfound �i2 �i1 �r �printf �keyfouni �
input �i �
input �	page �fsmstartKftosgetgetcg	getc �	getc �getcharp
getnum
getnum)
getnum0
getnum3
getnum?
getnumEhlibiwi~i �i1 �i1 �i1 �i1 �i1 �i2 �i2 �i2 �i2 �i2 �
input �
input �
input �keyfound �keyfound �keyfound �keyfound �keyfound �	learn	learn4lhlh �lh �mainmemnmaxknminjnummnumsnumber1 number2!page
perrori
perror{perror �perror �present
printf$
printf&
printf'
printf.
printf1
printf=
printfCprintf �printf �printf �printf �printf �!programmed �ptrx
putstr	quant	quant7
   m� �������� %*/49>CHMRW\afkpuz�������������������������$).38=BGLQV[`ejoty~������������������������nbVJ>2&���Mvzyxwvutsrqponmlkjihgfedcba`_^]\[ZYXWVUTSRQPO	 !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~ � � � � �
   e ���������������� &,28>DJPV\bhntz�����������������������~xrlf`ZTNHB<60*$��(4@LXdp|����������p|����������tstr � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �routineroutineroutineroutineroutineroutine	routine
routineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutineroutine
   H � lx����������� ,8DP\ht�����������(4@LXdp|����������`TH<0$  � � � � � � � � �llfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �lfsm.c �    S ��}`J0	��tW:���wP � � � � S!'-39?EKQW+�,7blocklfsm.cTint block[sizeblock];)�++sizeblocklfsm.cSint sizeblock=4*�*!+programmedlfsm.cRint programmed;�)i2lfsm.cQint i2;�(i1lfsm.cPint i1;9�'	OFSMquantlfsm.cNint FSMquant(struct routine *r) {$�&1rlfsm.cNstruct routine *r)�%printflfsm.cJ#�$%statuslfsm.c,int status=0&�#'keyfoundlfsm.c+int keyfound;+�"7blocklfsm.c*int block[sizeblock];)�!+sizeblocklfsm.c)int sizeblock=4� i2lfsm.c(int i2;�i1lfsm.c'int i1;N�	yFSMlearnlfsm.c%int FSMlearn(struct routine *r, int input, int data) {�datalfsm.c%int data) �!inputlfsm.c%int input,$�1rlfsm.c%struct routine *r,�printflfsm.c!�lhlfsm.c�lhlfsm.cint lh;&�'keyfoundlfsm.cint keyfound;+�7blocklfsm.cint block[sizeblock];)�+sizeblocklfsm.cint sizeblock=4
   ?^ �������zsle^�������'1<DLZix����������&1<GR]hs~����������� E	cFSMreadlfsm.c	int FSMread(struct routine *r, int input) { �!inputlfsm.c	int input)$�1rlfsm.c	struct routine *r,�perrorlfsm.c ��realloclfsm.c ��getclfsm.cr �r �r �r �r �r �r_r �r �r �r �r �readreadG#readconsole	readint
reallochrealloc �realloc �
remove
remove@routine	scanfo
selectsetsetFsizeblockMsizeblock �sizeblock �sizeblock �sizeblock �sizeblock �!sizeeeprom!sizeeepromJ
sscanftstatus �status �status �stru
strcmp*
strcmp+
strcmp,
strcmp-
strcmp5
strcmp6
strcmp8
strcmp9
strcmp;
strcmp<
strcmpA
strcmpB
stream`
stream|stream �
strlenz
systemH	trace	valuef
value �
value �viewpageviewpage%xq   \ ��zY���^��w\wP � � � � S S S                           +�,7blocklfsm.cTint block[sizeblock];)�++sizeblocklfsm.cSint sizeblock=4*�*!+programmedlfsm.cRint programmed;�)i2lfsm.cQint i2;�(i1lfsm.cPint i1;t <	OFSMquantlfsm.cNint FSMquant(struct routine *r) {$�&1�Silfsm.c�int i;>�R	_FSMhllfsm.c�int FSMhl(struct routine *r, int input) { �Q!inputlfsm.c�int input)$�P1rlfsm.c�struct routine *r,�Oilfsm.c�int i;>�N	_FSMlhlfsm.c�int FSMlh(struct routine *r, int input) { �M!inputlfsm.c�int input)$�L1rlfsm.c�struct routine *r,?�K	#UFSMviewpagelfsm.c�int FSMviewpage(struct routine *r) {$�J1rlfsm.c�struct routine *r)E�I	eFSMselectlfsm.c�int FSMselect(struct routine *r, int page) {�Hpagelfsm.c�int page)$�G1rlfsm.c�struct routine *r,5�F	KFSMgetlfsm.c�int FSMget(struct routine *r) {$�E1rlfsm.c�struct routine *r)    ; ���s*���mG-���\. � � � } ;(?�D	_FSMsetlfsm.c�int FSMset(struct routine *r, int data) {�Cdatalfsm.c�int data)$�B1rlfsm.c�struct routine *r,�Aprintflfsm.c�#�@%statuslfsm.c�int status=0&�?'keyfoundlfsm.c�int keyfound;+�>7blocklfsm.cint block[sizeblock];)�=+sizeblocklfsm.c~int sizeblock=4�<i2lfsm.c}int i2;�;i1lfsm.c|int i1;A�:	%WFSMdeletealllfsm.czint FSMdeleteall(struct routine *r) {$�91rlfsm.czstruct routine *r)�8printflfsm.cu#�7%statuslfsm.ceint status=0&�6'keyfoundlfsm.cdint keyfound;+�57blocklfsm.ccint block[sizeblock];)�4+sizeblocklfsm.cbint sizeblock=4�3i2lfsm.caint i2;�2i1lfsm.c`int i1;F�1	gFSMremovelfsm.c^int FSMremove(struct routine *r, int input) { �0!inputlfsm.c^int input)$�/1rlfsm.c^struct routine *r,�.printflfsm.cZ&�-'keyfoundlfsm.cUint keyfound;    J ���qL�����Y ���`H- � � � g J��������i2lfsm.cint i2;�i1lfsm.cint i1;B�	cFSMreadlfsm.c	int FSMread(struct routine *r, int input) { �!inputlfsm.c	int input)$�1rlfsm.c	struct routine *r,�perrorlfsm.c ��realloclfsm.c ��getclfsm.c �#�'valuelfsm.c �char* value=N'�)caracterlfsm.c �char caracter;,�
7NByteslfsm.c �int i, block, NBytes;#�	'blocklfsm.c �int i, block,�ilfsm.c �int i,6�	IFSMfltoslfsm.c �char* FSMfltos(FILE* stream) {$�'streamlfsm.c �FILE* stream)�perrorlfsm.c ��realloclfsm.c ��getclfsm.c �#�'valuelfsm.c �char* value=N'�)caracterlfsm.c �char caracter;,� 7NByteslfsm.c �int i, block, NBytes;#'blocklfsm.c �int i, block,~ilfsm.c �int i,4}	GFSMftoslfsm.c �char* FSMftos(FILE* stream) {$|'streamlfsm.c �FILE* stream){perrorlfsm.c �   = =Xp������/F^s����3T~� ; ;   � B	_FSMsetlfsm.c�int FSMset(struct routine *r, int data) {�Cdatalfsm.c�int data)$�B1rlfsm.c�struct routine *r,�Aprintflfsm.c�#�@%statuslfsm.c�int status=0&�?'keyfoundlfsm.c�int keyfound;+�>7blo:deletealllfsm.cX;strcmplfsm.cZ<strcmplfsm.cZ=printflfsm.c[>fltoslfsm.c\?getnumlfsm.c]@removelfsm.c^Astrcmplfsm.c`Bstrcmplfsm.c`Cprintflfsm.caDfltoslfsm.cbEgetnumlfsm.ccFsetlfsm.cdGreadlfsm.cgHsystemlfsm.ck"I%eepromlfsm.cpint *eeprom,)J!+sizeeepromlfsm.cpint sizeeeprom)AK	afsmstartlfsm.cpFSM fsmstart(int *eeprom, int sizeeeprom){L!cellslfsm.cqint cells;(M+sizeblocklfsm.crint sizeblock=4AN)SFSMreadconsolelfsm.ctchar* FSMreadconsole(FILE* stream);=O!SFSMreadintlfsm.cuint FSMreadint(int nmin, int nmax);    X ��|W) ����qQ�����R4 � � � � q X                          zstrlenlfsm.c �ycalloclfsm.c �x!ptrlfsm.c �char* ptr;wilfsm.c �int i;5v	EFSMputstrlfsm.c �char* FSMputstr(char* str) {u!strlfsm.c �char* str)tsscanflfsm.c �snumlfsm.c �int num;1r	=FSMgetnumlfsm.c �int FSMgetnum(char* x) {qxlfsm.c �char* x)pgetcharlfsm.c �oscanflfsm.c �nflaglfsm.c �int flag;mnumlfsm.c �int num;>l	!UFSMreadintlfsm.c �int FSMreadint(int nmin, int nmax) {knmaxlfsm.c �int nmax)jnminlfsm.c �int nmin,iperrorlfsm.c �hrealloclfsm.c �ggetclfsm.c �#f'valuelfsm.c �char* value=N'e)caracterlfsm.c �char caracter;,d7NByteslfsm.c �int i, block, NBytes;#c'blocklfsm.c �int i, block,bilfsm.c �int i,Ba	)UFSMreadconsolelfsm.c �char* FSMreadconsole(FILE* stream) {$`'streamlfsm.c �FILE* stream)    3 K���0���` � � X 3��P�#_/rlfsm.c �struct routine r;>^]FSMhllfsm.c �int FSMhl(struct routine *r, int input);>]]FSMlhlfsm.c �int FSMlh(struct routine *r, int input);?\#SFSMviewpagelfsm.c �int FSMviewpage(struct routine *r);E[cFSMselectlfsm.c �int FSMselect(struct routine *r, int page);5ZIFSMgetlfsm.c �int FSMget(struct routine *r);>Y]FSMsetlfsm.cint FSMset(struct routine *r, int data);@X%UFSMdeletealllfsm.c~int FSMdeleteall(struct routine *r);0P;FSMgetnumlfsm.cvint FSMgetnum(char* x);4QCFSMputstrlfsm.cwchar* FSMputstr(char* str);3REFSMftoslfsm.cxchar* FSMftos(FILE* stream);5SGFSMfltoslfsm.cychar* FSMfltos(FILE* stream);ATaFSMreadlfsm.czint FSMread(struct routine *r, int input);MUwFSMlearnlfsm.c{int FSMlearn(struct routine *r, int input, int data);8VMFSMquantlfsm.c|int FSMquant(struct routine *r);EWeFSMremovelfsm.c}int FSMremove(struct routine *r, int input);