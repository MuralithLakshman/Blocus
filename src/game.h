#ifndef GAME_H
#define GAME_H

#include "graph.h"
#include "player.h"
#include "grid.h"

#define ONE_PLAYER 1
#define TWO_PLAYERS 2       

struct game {
  unsigned int started; /* Partie débutée (booleen) */
  unsigned int ended; /* Partie terminée (booleen) */
  Grid grid;
  Player player1;
  Player player2;
  int turn; /* ID du joueur à qui c'est le tour */
};

typedef struct game Game;

/* Initialise une nouvelle partie */ 
Game NewGame(int number_players, Grid grid);

/* Renvoie le joueur à qui c'est le tour */ 
Player getPlayerTurn(Game game);

#endif /* GAME_H */ 
