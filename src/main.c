#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <stdbool.h>

#include "/usr/include/X11/keysymdef.h"
#include "grid.h"
#include "player.h"

/* Fréquence de rafraichissement en milisecondes */
#define MICRO 1000000L 

/* Taille de la fenêtre */ 
#define WIDTH 900 /* Largeur */ 
#define HEIGHT 600 /* Hauteur */

/* Dimensions de son écran */ 
#define MAX_WIDTH 1270
#define MAX_HEIGHT 740

struct button {
  int x;
  int y;
  int width;
  int height;
};

typedef struct button Button;

bool isPressed(int x, int y, Button b) {
  return x >= b.x && x <= b.x + b.width && y >= b.y && y <= b.y + b.height;
}
  

/* Renvoie l'écran affiché ou 0 si un problème est intervenu pendant l'exécution du programme */ 
int showScreen(int screen) {
  if(screen <= 0 || screen > 10) return 0;
  
  ChoisirEcran(0);
  EffacerEcran(CouleurParNom("white"));
  CopierZone(screen, 0, 0, 0, WIDTH, HEIGHT, 0, 0);

  return screen;
}

int main(void) {
  Grid g;
  int sprite; 
  int next;
  int screenX = (MAX_WIDTH - WIDTH) / 2;
  int screenY = (MAX_HEIGHT - HEIGHT) / 2;
  int gridY = ((HEIGHT / 2) / 2) / 2;
  int side = HEIGHT - 2 * gridY;
  int gridX = (WIDTH - side) / 2;
  
  InitialiserGraphique();
  /* Créer un fenêtre toujours à peu près au milieu de l'écran */ 
  CreerFenetre(screenX, screenY, WIDTH, HEIGHT);

  g = NewGrid(gridX, gridY, side, 3, 2);
  drawGrid(g);
  /*showScreen(g.screen);*/

  ChoisirEcran(0);
  sprite = ChargerSprite("assets/blue-cross.png");
  AfficherSprite(sprite, gridX, gridY);
  printf("%d", sprite);

  next = Microsecondes() + MICRO; 
  while(true) {
    /* SI la touche escape est pressée, cela arrête le programme. */ 
    if(ToucheEnAttente() == 1) {
      if(Touche() == XK_Escape) break;
    }
    
    if(Microsecondes() > next) {
      next = Microsecondes() + MICRO;
      
    }
  }
	      

  LibererSprite(sprite);
  FermerGraphique();
  
  return EXIT_SUCCESS;
}
