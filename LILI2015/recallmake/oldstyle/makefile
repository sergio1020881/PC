CC = gcc
CXX = gcc
#g++
CFLAGS=-c -Wall
SFLAGS=-S -Wall
LIBS=-lm
LDFLAGS =
PROJECT=LILI.exe
SOURCE_1=LILI2015.c
SOURCE_2=PClili.c
SOURCE_3=PCfunction.c
#SOURCE_4 = 
OBJECT_1=obj_1.o
OBJECT_2=obj_2.o
OBJECT_3=obj_3.o
#OBJECT_4 = 
ASM_1=asm_1.s
ASM_2=asm_2.s
ASM_3=asm_3.s
#ASM_4 = 
MODEL=s


$(PROJECT) : $(OBJECT_1) $(OBJECT_2) $(OBJECT_3) $(OBJECT_4)
	$(CXX) $(OBJECT_1) $(OBJECT_2) $(OBJECT_3) $(OBJECT_4) -o $(PROJECT) $(LIBS)
$(OBJECT_1) : $(ASM_1)
	$(CXX) $(CFLAGS) $(ASM_1) -o $(OBJECT_1)
$(OBJECT_2) : $(ASM_2)
	$(CXX) $(CFLAGS) $(ASM_2) -o $(OBJECT_2)
$(OBJECT_3) : $(ASM_3)
	$(CXX) $(CFLAGS) $(ASM_3) -o $(OBJECT_3)
$(OBJECT_4) : $(ASM_4)
	$(CXX) $(CFLAGS) $(ASM_4) -o $(OBJECT_4)
$(ASM_1) : $(SOURCE_1)
	$(CXX) $(SFLAGS) $(SOURCE_1) -o $(ASM_1)
$(ASM_2) : $(SOURCE_2)
	$(CXX) $(SFLAGS) $(SOURCE_2) -o $(ASM_2)
$(ASM_3) : $(SOURCE_3)
	$(CXX) $(SFLAGS) $(SOURCE_3) -o $(ASM_3)
$(ASM_4) : $(SOURCE_4)
	$(CXX) $(SFLAGS) $(SOURCE_4) -o $(ASM_4)
clean :
	rm -rf *o *s $(PROJECT)
