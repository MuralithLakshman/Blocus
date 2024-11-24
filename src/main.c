#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

#include "/usr/include/X11/keysymdef.h"

#include "grid.h"
#include "game.h"
#include "utils.h"
#include "home.h"

/* Fréquence de rafraichissement en milisecondes */
#define MICRO 1000000L

/* Taille de la fenêtre graphique */ 
#define WIDTH 900 /* Largeur */ 
#define HEIGHT 700 /* Hauteur */

/* Dimensions de l'écran */ 
#define MAX_WIDTH 1920
#define MAX_HEIGHT 1080

int main(void) {
  unsigned long next;
  Game game;
  Home* home;
  Sprites sprites_manager;

  /* NE PAS TOUCHER AUX VARIABLES QUI SUIVENT ! */ 
  int screenX = (MAX_WIDTH - WIDTH) / 2;
  int screenY = (MAX_HEIGHT - HEIGHT) / 2;
  int side = 500;
  int gridX = (WIDTH - side) / 2;
  int gridY = (HEIGHT - side) / 2;

  sprites_manager.count = 0;

  /* Test si la taille de la fenêtre renseignée est capable de prendre en charge l'affichage de la grille avec une marge pour divers affichages */
  if(WIDTH < (side + 100) || HEIGHT < (side + 100)) {
    printf("Taille de la fenêtre trop petite. La largeur et la hauteur de la fenêtre doivent être supérieur ou égal à 600.\n");
    return EXIT_FAILURE;
  }
  
  InitialiserGraphique();
  
  /* Créer une fenêtre toujours à peu près au milieu de l'écran */ 
  CreerFenetre(screenX, screenY, WIDTH, HEIGHT);

  game = new_game(2, new_grid(gridX, gridY, side, 6, 2));
  home = new_home(&sprites_manager);

  draw_home(home);
  draw_grid(game.grid);
  
  show_screen(home->screen, WIDTH, HEIGHT);
  
  ChoisirEcran(0);
  
  next = Microsecondes() + MICRO;
  while(1) {
    /* SI la touche escape est pressée, cela arrête le programme. */ 
    if(ToucheEnAttente() == 1) {
      if(Touche() == XK_Escape) break;
    }
    
    if(Microsecondes() > next) {
      next = Microsecondes() + MICRO;

      if(mouse_click_home(home)) {
	update_home(home);
      }

      if(game.started == 0) {
      } else if(game.started) {
      } else if(game.ended) {
	/* Code pour l'écran de fin */ 
      }
    }
  }

  FermerGraphique();
  
  return EXIT_SUCCESS;
}
