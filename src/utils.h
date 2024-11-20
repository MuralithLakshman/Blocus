#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

typedef struct button {
  int x;
  int y;
  int width;
  int height;
} Button;

Button new_button(int x, int y, int width, int height);

unsigned int is_pressed_button(Button b);

int show_screen(int screen, int width, int height); 

#endif /* UTILS_H */
