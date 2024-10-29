#ifndef GRID_H
#define GRID_H

struct grid {
  int originX;
  int originY;
  int width;
  int height; 
  int size;
  int** data;
};

grid NewGrid(int originX, int originY, int width, int height, int size);

void drawgrid(grid g);

#endif GRID_H
