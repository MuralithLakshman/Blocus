#include <stdlib.h>
#include <stdio.h>

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

Game new_game(int number_players, Grid grid) {
  Game game;
  Player player1, player2;

  player1.id = 1;
  player1.bot = 0;

  player2.id = 2;
  player2.bot = number_players == ONE_PLAYER ? 1 : 0; /* S'il n'y a un qu'un vrai joueur, le J2 sera donc un bot */ 

  game.started = 0;
  game.ended = 0;
  game.grid = grid;
  game.player1 = player1;
  game.player2 = player2;
  game.turn = player1.id;

  return game; 
}

Player get_player_turn(Game game) {
  return game.turn == game.player1.id ? game.player1 : game.player2;
}


