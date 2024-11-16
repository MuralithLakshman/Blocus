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

unsigned int isPressed(Button b) {
  if(SourisCliquee()) return _X >= b.x && _X <= b.x + b.width && _Y >= b.y && _Y <= b.y + b.height;

  return 0; 
}
