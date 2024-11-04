#ifndef GRID_H
#define GRID_H

struct grid {
  int originX;
  int originY;
  int width;
  int height; 
  int size;
  int** data;
  int*** boxes; 
};

typedef struct grid Grid; 

Grid NewGrid(int originX, int originY, int width, int height, int size);

void drawgrid(Grid g);

#endif GRID_H
