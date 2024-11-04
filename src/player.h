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

struct player {
  int id;
  bool bot;
  int points;
}; 
  
typedef int move;

typedef struct player Player;

bool movePlayer(Player p, move m); 
