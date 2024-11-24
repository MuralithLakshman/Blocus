### VARIABLES ###

CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
SRC = src/
OFILES = $(SRC)main.o $(SRC)grid.o $(SRC)game.o $(SRC)utils.o $(SRC)home.o
LIBS = -lgraph -lm
EXE = exe

### DEFAULT GOAL ###

goal : ${EXE}

### ESSENTIAL RULES ### 

${EXE} : $(OFILES)
	$(CC) $(CFLAGS) -o $(EXE) $(OFILES) $(LIBS)

main.o : main.c grid.h game.h utils.h
	$(CC) $(CFLAGS) -c $(SRC)main.c $(LIBS) 

grid.o : grid.c grid.h
	$(CC) $(CFLAGS) -c $(SRC)grid.c $(LIBS) 

player.o : player.c
	$(CC) $(CFLAGS) -c $(SRC)player.c $(LIBS)

game.o : game.c game.h
	$(CC) $(CFLAGS) -c $(SRC)game.c $(LIBS)

utils.o : utils.c utils.h
	$(CC) $(CFLAGS) -c $(SRC)utils.c $(LIBS)

home.o: home.c home.h utils.h
	$(CC) $(CFLAGS) -c $(SRC)home.c $(LIBS)

### OPTIONAL RULES ###

run : goal
	./${EXE}

clean :
	rm -f $(SRC)/*.o

mrproper : clean goal

list :
	@echo make: run, clean, mrproper, list

### FACTIC GOAL ### 

.PHONY : goal clean mrproper list
