# Makefile
CC= gcc 
FLAGS= -Wall -Wextra -Wswtich-enum -linclude
.PHONY: all clean 
EXE= mypro
OBJC= main.o 
all: $(EXE) 
EXE: $(OBJC)
	$(CC) -o $(EXE) $(OBJC) $(FLAGS)

OBJC: main.c
	$(CC) -c main.c -o $(OBJC) -(FLAGS)

clean:
	rm $(OBJC) $(EXE)