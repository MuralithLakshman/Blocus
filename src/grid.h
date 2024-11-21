#ifndef GRID_H
#define GRID_H

#include "utils.h"

typedef struct grid {
  int originX;
  int originY;
  int side;
  int size;
  int screen;
  int** data;
  Button** boxes; 
} Grid;

Grid new_grid(int originX, int originY, int side, int size, int screen);

void draw_grid(Grid g);

int* get_box_clicked(Grid grid);

#endif /* GRID_H */ 
