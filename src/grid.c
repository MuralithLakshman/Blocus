#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

#include "grid.h"
#include "utils.h"

#define PLAYER_1 1
#define PLAYER_2 2

/* Initialise une nouvelle grille vide */ 
Grid new_grid(int originX, int originY, int side, int size, int screen) {
  int i, j;
  int x, y;
  
  Grid g;
  Button b;

  /*
    Utilisation de la fonction calloc() pour que tous les bits soient à 0.
    Signifie que toutes les cases sont vides.
  */
  int** data = (int**)calloc(size, sizeof(int*));
  Button** boxes = (Button**)malloc(size * sizeof(Button*));

  for(i = 0; i < size; i++) {
    data[i] = (int*)calloc(size, sizeof(int));
    boxes[i] = (Button*)malloc(size * sizeof(Button));
    
  }

  /*
    Pour être le plus précis possible lors de l'affichage de la grille,
    on cherche à avoir le côté de la grille divisible par le nombre de case.
  */
  while(side % size != 0) {
    side++;
  }

  x = originX;
  y = originY;
  b = new_button(x, y, side / size, side / size);

  for(i = 0; i < size; i++) {
    for(j = 0; j < size; j++) {
      boxes[i][j] = b;
      
      x += side / size; 
    }

    y += side / size; 
  }

  g.originX = originX;
  g.originY = originY;
  g.side = side;
  g.size = size;
  g.screen = screen;
  g.data = data;
  g.boxes = boxes;

  for(i = 0; i < size; i++) {
    free(data[i]);
    free(boxes[i]);
  }

  return g;		        
}

/* Dessine une grille vide sur le graphique */ 
void draw_grid(Grid g) {
  int i, j;
  int x = g.originX;
  int y = g.originY;
  int side = g.side; 
  int box = side / g.size;
  int sprite;

  ChoisirEcran(2);
  EffacerEcran(CouleurParNom("white"));
  
  DessinerRectangle(x, y, side, side);

  for(i = y + box; i < y + side; i += box) {
    DessinerSegment(x, i, x + side, i);
  }

  for(i = x + box; i < x + side; i += box) {
    DessinerSegment(i, y, i, y + side); 
  }

  
  for(i = x; i < x + side; i += box) {
    for(j = y; j < y + side; j += box) {
      sprite = ChargerSprite("assets/orange-cross-6.png");

      if(sprite == -1) {
	printf("Erreur lors d'un chargement du sprite.\n");
	FermerGraphique();
	return;
      }

      AfficherSprite(sprite, i + 10, j + 10);
      LibererSprite(sprite);
    }
  }
}

int* get_box_clicked(Grid grid) {
  int i, j;
  int* index = NULL;

  for(i = 0; i < grid.side; i++) {
    for(j = 0; j < grid.side; j++) {

      /*printf("%d\n", grid.boxes[i][j].height);*/
      /*
      if(is_pressed_button(grid.boxes[i][j])) {
	index = (int*) malloc(2 * sizeof(int));
	index[0] = i;
	index[1] = j;
	break;
      }
      */
    }
  }

  return index;
}


