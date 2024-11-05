#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

struct grid {
  int originX;
  int originY;
  int side;
  int size;
  int screen;
  int** data;
  int*** boxes; 
};

typedef struct grid Grid; 

/* Initialise une nouvelle grille vide */ 
Grid NewGrid(int originX, int originY, int side, int size, int screen) {
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
    for(j = 0; j < size; j++) {
      free(boxes[i][j]);
    }

    free(data[i]);
    free(boxes[i]);
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
  int side = g.side; 
  int box = side / g.size;

  ChoisirEcran(2);
  EffacerEcran(CouleurParNom("white"));
  
  DessinerRectangle(x, y, side, side);

  for(i = y + box; i < y + side; i += box) {
    DessinerSegment(x, i, x + side, i);
  }

  for(i = x + box; i < x + side; i += box) {
    DessinerSegment(i, y, i, y + side); 
  }
}



