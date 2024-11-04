### VARIABLES ###

CC = gcc
CFLAGS = -Wall -ansi -pedantic
SRC = src/
FILES = $(SRC)main.c $(SRC)player.c $(SRC)grid.c
EXE = exe

### DEPENDANCES ###

exe : $(OFILES)
	$(CC) $(CFLAGS) $(EXE) -o $(FILES)

### CLEAN ###

clean :
	rm -f $(SRC)/*.o

### FACTICE ### 

.PHONY : clean 
