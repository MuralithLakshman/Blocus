#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

struct grid {
  int originX;
  int originY;
  int width;
  int height; 
  int size;
  int** data;
  int*** boxes; 
};

/* Initialise une nouvelle grille vide */ 
grid NewGrid(int originX, int originY, int width, int height, int size) {
  int i, j, k;

  /*
    Utilisation de la fonction calloc() pour que tous les bits soient à 0.
    Signifie que toutes les cases sont vides.
  */
  int** data = (int**)calloc(size, sizeof(int*));
  int*** boxes = (int***)malloc(size * sizeof(int**));

  for(i = 0; i < size; i++) {
    for(j = 0; j < size; j++) {
      data[i] = (int*)calloc(size, sizeof(int));
    }
  }

  for(i = 0; i < size; i++) {
    for(j = 0; j < size; j++) {
      free(data[i]); 
    }
  }

  free(data);

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

  return struct grid g = {originX, originY, width, height, size, array};		        
}

/* Dessine une grille sur le graphique */ 
void drawGrid(grid g) {
  int i;
  int x = g.originX;
  int y = g.originY;
  int width = g.width;
  int heignt = g.height;
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

