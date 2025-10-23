# Makefile
CC= gcc 
FLAGS= -Wall -Wextra -Wswitch-enum -Iinclude
EXE= pro
OBJC= main.o 
.PHONY: all clean

all:$(EXE)

$(EXE):$(OBJC)
	$(CC) -o $(EXE) $(OBJC) $(FLAGS)

$(OBJC): main.c
	$(CC) -c main.c -o $(OBJC) $(FLAGS)

clean:
	del  -f $(OBJC) $(EXE)