#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

#include "player.h"
#include "utils.h"

struct grid {
  int originX;
  int originY;
  int side;
  int size;
  int screen;
  int** data;
  Button** boxes; 
};

typedef struct grid Grid; 

/* Initialise une nouvelle grille vide */ 
Grid new_grid(int originX, int originY, int side, int size, int screen) {
  int i;
  Grid g;

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

  free(data);
  free(boxes);

  return g;		        
}

/* Dessine une grille sur le graphique */ 
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

/* Renvoie la position d'un joueur dans la grille sous la forme d'un tableau [x, y] */
/* Si le joueur n'est pas dans la grille, NULL est renvoyé. */ 
int* get_player_position(Player p, Grid g) {
  int i, j;
  int* coordinates = malloc(2 * sizeof(int));

  if(coordinates == NULL) return NULL;

  for(i = 0; i < g.side; i++) {
    for(j = 0; j < g.side; j++) {
      if(g.data[i][j] == p.id) {
	coordinates[0] = i;
	coordinates[1] = j;

	return coordinates;
      }
    }
  }

  free(coordinates);

  return NULL; 
}



