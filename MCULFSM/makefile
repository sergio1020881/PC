###########################################################
#                                                         #
#                       MAKEFILE                          #
#                                                         #
###########################################################
PWD=-I.
CC=gcc
CXX=g++
AS=as
COMPILE=-c
WARNING=-g -Wall -Wextra
ASSEMBLY=-S
#LIBS=-lpthread -lrt
LIBMATH=-lm
#LDLIBS=-lefence -pthread
##VARIABLES AND LISTS
PROJECT=out
HFILES=$(wildcard *.h)
CFILES=$(wildcard *.c)

OFILES=$(patsubst %.c, %.o,$(CFILES))
ASMFILES=$(patsubst %.c, %.S,$(CFILES))
##PROCEDURES HEADER
.PHONY: clean run message

##PROJECT
$(PROJECT): $(HFILES) $(OFILES)
	@echo "PROJECT"
	$(CC) $(WARNING) $(OFILES) $(LIBMATH) -o $@

##COMPILER
%.o:%.c  $(HFILES) $(CFILES)
	@echo "COMPILER"
	$(CC) $(COMPILE) $(WARNING) $< -o $@

##PROCEDURES
clean:
	-rm -vf *.o *.s $(PROJECT)
run: $(PROJECT)
	chmod 775 $(PROJECT)
	./$(PROJECT)
message:
	@echo "$(ASMFILES) -- $(OFILES) -- $(HFILES) -- $(CFILES)"
##EOF
