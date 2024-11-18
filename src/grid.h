#ifndef GRID_H
#define GRID_H

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

Grid new_grid(int originX, int originY, int side, int size, int screen);

void draw_grid(Grid g);

#endif /* GRID_H */ 
