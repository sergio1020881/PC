###########################################################
#                                                         #
#                       MAKEFILE                          #
#                                                         #
###########################################################
PWD = -I.
INCLUDE_DIR = ../include
LIB_DIR =
CC = gcc
CXX = g++
AS = as
CDEFS =
COMPILE = -c
WARNING = -Wall
ASSEMBLY = -S -O2
LIBS = -lpthread -lrt
LIBMATH = -lm
LDLIBS = -lefence -pthread
MODEL = s
##VARIABLES AND LISTS
TARGET = LILI
HFILES = $(wildcard *.h)
CFILES = $(wildcard *.c)
#ASMFILES = $(patsubst %.c, %.S,$(CFILES))
#.S.o: $(CFILES)
#	$(AS) $(ASSEMBLY) $< -o $@
OFILES = $(patsubst %.c, %.o,$(CFILES))
.c.o: $(CFILES)
	$(CC) $(COMPILE) $< -o $@
##COMPILATION
all: ${TARGET}
$(TARGET): $(OFILES)
	$(CC) $(COMPILE) $(WARNING) $(OFILES) -o $@ $(LIBMATH)
##PROCEDURES
.PHONY: clean run message
clean:
	-rm -vf *.o
	-rm -vf *.s
	-rm -vf $(TARGET)
run: $(TARGET)
	chmod 775 $(TARGET)
	./$(TARGET)
message:
	@echo "$(ASMFILES) -- $(OFILES) -- $(HFILES) -- $(CFILES)"
##EOF
