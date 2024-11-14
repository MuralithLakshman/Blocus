#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <string.h>
#include "/usr/include/X11/keysymdef.h"

#define MICRO 1000000L
#define WIDTH 900
#define HEIGHT 600
#define MAX_WIDTH 1270
#define MAX_HEIGHT 740

struct button {
  int x;
  int y;
  int width;
  int height;
};

typedef struct button Button;

unsigned int isPressed(Button b, int x, int y) {
  return x >= b.x && x <= b.x + b.width && y >= b.y && y <= b.y + b.height;
}

void printText(int x, int y, int size, char* color, char* text) {
  ChoisirCouleurDessin(CouleurParNom(color));
  EcrireTexte(x, y, text, size);
}

void dessinerBouton(Button b, char* color) {
  ChoisirCouleurDessin(CouleurParNom(color));
  DessinerRectangle(b.x, b.y, b.width, b.height);
}

unsigned int showScreen(int screen) {
  if(screen <= 0 || screen > 10) return 0;
  
  ChoisirEcran(0);
  EffacerEcran(CouleurParNom("white"));
  CopierZone(screen, 0, 0, 0, WIDTH, HEIGHT, 0, 0);

  return screen;
}

int main(void) {
  Button b_montrer, b_descendre;
  unsigned long next;
  int tailleGrille = 3; 
  char texte[20];

  InitialiserGraphique();
  CreerFenetre(100, 100, 900, 600);

  b_montrer.x = 600; 
  b_montrer.y = 300; 
  b_montrer.width = 30;
  b_montrer.height = 30;

  b_descendre.x = 300;
  b_descendre.y = 300;
  b_descendre.width = 30;
  b_descendre.height = 30;

  next = Microsecondes() + MICRO;

  while (1) {
    if (Microsecondes() > next) {
      next = Microsecondes() + MICRO;

      EffacerEcran(CouleurParNom("white"));  

      dessinerBouton(b_montrer, "blue");
      dessinerBouton(b_descendre, "red");

      sprintf(texte, "Taille %dx%d", tailleGrille, tailleGrille);
      printText(50, 100, 2, "black", texte);

      if (SourisCliquee()) {
        int x = _X, y = _Y; 

        if (isPressed(b_montrer, x, y)) {
          if (tailleGrille < 9) {
            tailleGrille++; 
          }
        }

        if (isPressed(b_descendre, x, y)) {
          if (tailleGrille > 3) {
            tailleGrille--;  
          }
        }
      }
    }

    if (ToucheEnAttente() == 1) {
      if (Touche() == XK_Escape) break;
    }
  }

  FermerGraphique();
  return 0;
}
