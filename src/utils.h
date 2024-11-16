#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

struct button {
  int x;
  int y;
  int width;
  int height;
};

typedef struct button Button;

unsigned int isPressed(Button b);

#endif /* UTILS_H */
