#ifndef PLAYER_H
#define PLAYER_H

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
  unsigned int bot;
  int points;
}; 
  
typedef int move;

typedef struct player Player;

unsigned int movePlayer(Player p, move m); 

#endif /* PLAYER_H */ 
