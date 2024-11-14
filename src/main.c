#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

#include "/usr/include/X11/keysymdef.h"

#include "grid.h"
#include "player.h"
#include "game.h"

/* Fréquence de rafraichissement en milisecondes */
#define MICRO 1000000L

/* Taille de la fenêtre graphique */ 
#define WIDTH 900 /* Largeur */ 
#define HEIGHT 700 /* Hauteur */

/* Dimensions de l'écran */ 
#define MAX_WIDTH 1920
#define MAX_HEIGHT 1080

struct button {
  int x;
  int y;
  int width;
  int height;
};

typedef struct button Button;

unsigned int isPressed(Button b) {
  if(SourisCliquee()) return _X >= b.x && _X <= b.x + b.width && _Y >= b.y && _Y <= b.y + b.height;

  return 0; 
}
  

/* Renvoie l'écran affiché ou 0 si un problème est intervenu pendant l'exécution du programme */ 
unsigned int showScreen(int screen) {
  if(screen <= 0 || screen > 10) return 0;
  
  ChoisirEcran(0);
  EffacerEcran(CouleurParNom("white"));
  CopierZone(screen, 0, 0, 0, WIDTH, HEIGHT, 0, 0);

  return screen;
}

int main(void) {
  Grid grid;
  Game game; 
  unsigned long next;

  /* NE PAS TOUCHER AUX VARIABLES QUI SUIVENT ! */ 
  int screenX = (MAX_WIDTH - WIDTH) / 2;
  int screenY = (MAX_HEIGHT - HEIGHT) / 2;
  int side = 500;
  int gridX = (WIDTH - side) / 2;
  int gridY = (HEIGHT - side) / 2;

  /* Test si la taille de la fenêtre renseignée est capable de prendre en charge l'affichage de la grille avec une marge pour divers affichages */
  if(WIDTH <= (side + 100) || HEIGHT <= (side + 100)) {
    printf("Taille de la fenêtre trop petite. La largeur et la hauteur de la fenêtre doivent être strictement supérieur à 600.\n");
    return EXIT_FAILURE;
  }
  
  InitialiserGraphique();
  
  /* Créer un fenêtre toujours à peu près au milieu de l'écran */ 
  CreerFenetre(screenX, screenY, WIDTH, HEIGHT);

  /* Initialisation d'une nouvelle grille */ 

  game = NewGame(2, NewGrid(gridX, gridY, side, 6, 2));
  drawGrid(game.grid);

  next = Microsecondes() + MICRO;
  
  while(1) {
    /* SI la touche escape est pressée, cela arrête le programme. */ 
    if(ToucheEnAttente() == 1) {
      if(Touche() == XK_Escape) break;
    }
    
    if(Microsecondes() > next) {
      next = Microsecondes() + MICRO;

      if(game.started) {
	player = getPlayerTurn(game);

	
	 
      }
    }
  }

  FermerGraphique();
  
  return EXIT_SUCCESS;
}
