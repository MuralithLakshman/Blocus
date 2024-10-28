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

void showMenuScreen(void) {
  ChoisirEcran(1);
  EffacerEcran(CouleurParNom("black"));
  
}

void drawGrid(int x, int y, int size) {
  int i;
  int gridW = WIDTH - 2 * x;
  int gridH = HEIGHT - 2 * y;
  int multiplierX = gridW / size;
  int multiplierY = gridH / size;
  printf("%d, %d, %d, %d", multiplierX, multiplierY, gridW, gridH);

  ChoisirEcran(0);
  DessinerRectangle(x, y, gridW, gridH);

  for(i = y + multiplierY; i < y + gridH; i += multiplierY) {
    DessinerSegment(x, i, x + gridW, i);
  }
}
  

int main(void) {
  int next;
  int screenX = (MAX_WIDTH - WIDTH) / 2;
  int screenY = (MAX_HEIGHT - HEIGHT) / 2;
  
  InitialiserGraphique();
  /* Créer un fenêtre toujours à peu près au milieu de l'écran */ 
  CreerFenetre(screenX, screenY, WIDTH, HEIGHT);

  drawGrid((WIDTH / 2) / 2, (HEIGHT / 2) / 2, 4);

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
