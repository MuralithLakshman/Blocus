#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

struct Grid {
  int originX;
  int originY;
  int width;
  int height; 
  int size;
  int** data;
  int*** boxes; 
};

typedef struct  Grid Grid; 

/* Initialise une nouvelle grille vide */ 
Grid NewGrid(int originX, int originY, int width, int height, int size) {
  int i, j;
  Grid g; 

  /*
    Utilisation de la fonction calloc() pour que tous les bits soient à 0.
    Signifie que toutes les cases sont vides.
  */
  int** data = (int**)calloc(size, sizeof(int*));

  /*
    [
      [ [x, y], [x', y'] ... ],
      [ [...], ...],
      ...
    ]
   */ 
  int*** boxes = (int***)malloc(size * sizeof(int**));

  for(i = 0; i < size; i++) {
    data[i] = (int*)calloc(size, sizeof(int));
    boxes[i] = (int**)malloc(size * sizeof(int*));
    
    for(j = 0; j < size; j++) {
      boxes[i][j] = (int*)malloc(2 * sizeof(int));
    }
  }

  /*
    Pour être le plus précis possible lors de l'affichage de la grille,
    on cherche à avoir une largeur et une hauteur divisible par sa taille.
  */
  while(width % size != 0) {
    width++;
  }

  while(height % size != 0) {
    height++;
  }

  g.originX = originX;
  g.originY = originY;
  g.width = width;
  g.height = height;
  g.size = size;
  g.data = data;
  g.boxes = boxes;

  for(i = 0; i < size; i++) {
    free(data[i]);
    free(boxes[i]);

    for(j = 0; j < size; j++) {
      free(boxes[i][j]);
    }
  }

  free(data);
  free(boxes);

  return g;		        
}

/* Dessine une grille sur le graphique */ 
void drawGrid(Grid g) {
  int i;
  int x = g.originX;
  int y = g.originY;
  int width = g.width;
  int height = g.height;
  int boxX = g.width / g.size;
  int boxY = g.height / g.size;

  ChoisirEcran(2);
  EffacerEcran(CouleurParNom("white"));
  
  DessinerRectangle(x, y, width, height);

  for(i = y + boxY; i < y + height; i += boxY) {
    DessinerSegment(x, i, x + width, i);
  }

  for(i = x + boxX; i < x + width; i += boxX) {
    DessinerSegment(i, y, i, y + height); 
  }
}

