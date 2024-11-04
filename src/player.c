#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define UP_LEFT 4
#define UP_RIGHT 5
#define DOWN_LEFT 6
#define DOWN_RIGHT 7

typedef int move; 

struct player {
  int id; 
  bool bot;
  int points;
};

/*
  Renvoie :
   false, si la case est condamnée
   true, si la case est libre 
   -1, si le mouvement passé en argument n'est pas correct
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

  return true;
}
  
