### VARIABLES ###

CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
SRC = src/
OFILES = $(SRC)main.o $(SRC)player.o $(SRC)grid.o $(SRC)game.o
LIBS = -lgraph -lm
EXE = exe

### DEFAULT GOAL ###

goal : ${EXE}

### ESSENTIAL RULES ### 

${EXE} : $(OFILES)
	$(CC) $(CFLAGS) -o $(EXE) $(OFILES) $(LIBS)

main.o : main.c grid.h player.h
	$(CC) $(CFLAGS) -c main.c $(LIBS) 

grid.o : grid.c grid.h
	$(CC) $(CFLAGS) -c grid.c $(LIBS) 

player.o : player.c player.h
	$(CC) $(CFLAGS) -c player.c $(LIBS)

game.o : game.c game.h player.h grid.h
	$(CC) $(CFLAGS) -c game.c $(LIBS) 

### OPTIONAL RULES ###

run : goal
	./${EXE}

clean :
	rm -f $(SRC)/*.o

mrproper : clean goal 

### FACTIC GOAL ### 

.PHONY : goal clean mrproper 
