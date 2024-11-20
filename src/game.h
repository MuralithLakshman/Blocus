#ifndef GAME_H
#define GAME_H

#include <graph.h>

#include "grid.h"

#define ONE_PLAYER 1
#define TWO_PLAYERS 2

typedef struct player {
  int id;
  unsigned short int bot;
  int next_move[2];
} Player; 

typedef struct game {
  unsigned int started; /* Partie débutée (booleen) */
  unsigned int ended; /* Partie terminée (booleen) */
  Grid grid;
  Player player1;
  Player player2;
  int turn; /* ID du joueur à qui c'est le tour */
} Game;

/* Initialise une nouvelle partie */ 
Game new_game(int number_players, Grid grid);

/* Renvoie le joueur à qui c'est le tour */ 
Player get_player_turn(Game game);

#endif /* GAME_H */ 
