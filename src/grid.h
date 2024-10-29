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

struct grid NewGrid(int originX, int originY, int width, int height, int size);

void drawgrid(struct grid g);

#endif GRID_H
