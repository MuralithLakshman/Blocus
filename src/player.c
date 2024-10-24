#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <stdbool.h>

#define move int

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define UP_LEFT 4
#define UP_RIGHT 5
#define DOWN_LEFT 6
#define DOWN_RIGHT 7 

struct player {
  char* username; 
  bool bot;
  int points;
};

/*
  Return :
   false, if the box is condemned
   true, if the box is free
   -1, if the move is not correct
*/
bool movePlayer(struct player p, move m) {
  switch(m) {
    case LEFT:
      break;
      
    case RIGHT:
      break;

    case UP:
      break;

    case DOWN:
      break;

    case UP_LEFT:
      break;

    case UP_RIGHT:
      break;

    case DOWN_LEFT:
      break;

    case DOWN_RIGHT:
      break;
  }
}
  
