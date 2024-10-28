#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <stdbool.h>
#include "/usr/include/X11/keysymdef.h"

/* Valeur d'une micro secondes */
#define MICRO 1000000L 

/* Taille de la fenêtre */ 
#define WIDTH 900 /* Largeur */ 
#define HEIGHT 600 /* Hauteur */
/* Valeurs approximatives que nous avons trouvé en faisant des tests */ 
#define MAX_WIDTH 1270
#define MAX_HEIGHT 740  

int main(void) {
  int next;
  int screenX = (MAX_WIDTH - WIDTH) / 2;
  int screenY = (MAX_HEIGHT - HEIGHT) / 2;
  int gridX = ((WIDTH / 2) / 2) / 2;
  int gridY = ((HEIGHT / 2) / 2) / 2;
  
  InitialiserGraphique();
  /* Créer un fenêtre toujours à peu près au milieu de l'écran */ 
  CreerFenetre(screenX, screenY, WIDTH, HEIGHT);

  /*grid = NewGrid(gridX, gridY, WIDTH - 2 * gridX, HEIGHT - 2 * gridY, 6);*/

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
	      

  FermerGraphique();
  return EXIT_SUCCESS;
}
