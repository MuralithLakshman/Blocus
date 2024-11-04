#ifndef GRID_H
#define GRID_H

struct Grid {
  int originX;
  int originY;
  int width;
  int height; 
  int size;
  int** data;
};

typedef struct Grid Grid; 

Grid NewGrid(int originX, int originY, int width, int height, int size);

void drawgrid(Grid g);

#endif GRID_H
