### VARIABLES ###

CC = gcc
CFLAGS = -Wall -ansi -pedantic
SRC = src/
OFILES = $(SRC)main.o $(SRC)player.o $(SRC)grid.o
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

### OPTIONAL RULES ###

run : goal
	./${EXE}

clean :
	rm -f $(SRC)/*.o

mrproper : clean goal 

### FACTIC GOAL ### 

.PHONY : goal clean mrproper 
