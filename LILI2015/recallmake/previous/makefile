###########################################################
#                                                         #
#                       MAKEFILE                          #
#                                                         #
###########################################################
INCLUDE_DIRS =
LIB-DIRS =
CC = gcc
CXX = gcc
CDEFS =
CFLAGS = -c -Wall
SFLAGS = -S -Wall
LIBS = -lm -lpthread -lrt
LDLIBS = -lefence -pthread
MODEL = s

TARGET = LFSM.exe

HFILES = $(wildcard *.h)
OBJS = $(patsubst %.c, %.o,$(wildcard *.c))

%.o: %.c $(HFILES)
	$(CXX) $(CFLAGS) $< -o $@

.PHONY: clean run

all: ${TARGET}

clean:
	-rm -vf *.o
	-rm -vf *.s
	-rm -vf $(TARGET)

run: $(TARGET)
	chmod 555 $(TARGET)
	./$(TARGET)

$(TARGET): $(HFILES) $(OBJS)
	$(CXX) $(OBJS) -Wall $(LIBS) -o $@
