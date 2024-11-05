#ifndef GRID_H
#define GRID_H

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

Grid NewGrid(int originX, int originY, int side, int size, int screen);

void drawGrid(Grid g);

#endif /* GRID_H */ 
