###########################################################
#                                                         #
#                       MAKEFILE                          #
#                                                         #
###########################################################
CC = gcc
CXX = gcc
#project name
TARGET = LFSM.exe
CFLAGS = -c -Wall
SFLAGS = -S -Wall
LIBS = -lm
MODEL = s

HEADERS = $(wildcard *.h)

OBJECTS = $(patsubst %.c, %.o,$(wildcard *.c))

%.o: %.c
	$(CXX) $(CFLAGS) $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f *.s
	-rm -f $(TARGET)

run : $(TARGET)
	./$(TARGET)
