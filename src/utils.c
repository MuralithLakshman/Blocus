#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

typedef struct button {
  int x;
  int y;
  int width;
  int height;
} Button;

Button new_button(int x, int y, int width, int height) {
  Button button;

<<<<<<< HEAD
  button.x = x;
  button.y = y;
  button.width = width;
  button.height = height;

  return button; 
}

int is_pressed_button(Button b) {
  if(SourisCliquee()) return _X >= b.x && _X <= b.x + b.width && _Y >= b.y && _Y <= b.y + b.height;

  return 0; 
}

/* Renvoie l'écran affiché ou 0 si un problème est intervenu pendant l'exécution du programme */
int show_screen(int screen, int width, int height) {
  if(screen <= 0 || screen > 10) return 0;
  
  ChoisirEcran(0);
  EffacerEcran(CouleurParNom("white"));
  CopierZone(screen, 0, 0, 0, width, height, 0, 0);

  return screen;
}


