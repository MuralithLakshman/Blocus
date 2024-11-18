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

typedef struct button {
  int x;
  int y;
  int width;
  int height;
} Button;

typedef struct Home {
  Button b_monter, b_descendre;
  unsigned long next;
  int tailleGrille;
  unsigned int spriteRight;
  unsigned int spriteLeft;
} Home;

unsigned int is_pressed(Button b, int x, int y) {
  return x >= b.x && x <= b.x + b.width && y >= b.y && y <= b.y + b.height;
}

void print_text(int x, int y, int size, char* color, char* text) {
  ChoisirCouleurDessin(CouleurParNom(color));
  EcrireTexte(x, y, text, size);
}

void dessiner_bouton(Button b, char* color) {
  ChoisirCouleurDessin(CouleurParNom(color));
  DessinerRectangle(b.x, b.y, b.width, b.height);
}

void init_game(Home* home) {
  Home h;
  Button b;
  h.tailleGrille = 3;
  h.b_monter = b;
  h.b_monter.x = 600;
  h.b_monter.y = 300;
  h.b_monter.width = 30;
  h.b_monter.height = 30;

  h.b_descendre.x = 300;
  h.b_descendre.y = 300;
  h.b_descendre.width = 30;
  h.b_descendre.height = 30;
  h.next = Microsecondes() + MICRO;

}

int show_sprite(Home* home) {
 Home h;
 h.spriteRight = ChargerSprite("assets/right-arrow.png");
  if (h.spriteRight == -1) {
    printf("Erreur de chargement de fleche_droite.png\n");
  }
 h.spriteLeft = ChargerSprite("assets/left-arrow.png");
  if (h.spriteLeft == -1) {
    printf("Erreur de chargement de fleche_gauche.png\n");
  }
}

void update_screen(Home* home) {
   Home h;
   char texte[20];
   
   EffacerEcran(CouleurParNom("white"));  

  AfficherSprite(h.spriteRight,h.b_monter.x, h.b_monter.y);
  AfficherSprite(h.spriteLeft, h.b_descendre.x, h.b_descendre.y);

  sprintf(texte, "Taille %dx%d", h.tailleGrille, h.tailleGrille);
  print_text(50, 100, 2, "black", texte);

}

void mouse_click(Home* home) {
    Home h;
    
  if (SourisCliquee()) {
        int x = _X, y = _Y; 

        if (is_pressed(h.b_monter, x, y)) {
          if (h.tailleGrille < 9) {
            h.tailleGrille++; 
          }
        }

        if (is_pressed(h.b_descendre, x, y)) {
          if (h.tailleGrille > 3) {
            h.tailleGrille--;  
          }
        }
      }
}
  

unsigned int show_screen(int screen) {
  if(screen <= 0 || screen > 10) return 0;
  
  ChoisirEcran(0);
  EffacerEcran(CouleurParNom("white"));
  CopierZone(screen, 0, 0, 0, WIDTH, HEIGHT, 0, 0);

  return screen;
}

int main(void) {
  Home h;

  InitialiserGraphique();
  CreerFenetre(100, 100, 900, 600);

  init_game(&h);

  show_sprite(&h);
 

  while (1) {
    if (Microsecondes() > h.next) {
     h.next = Microsecondes() + MICRO;
    }

    update_screen(&h);
    mouse_click(&h);

    if (ToucheEnAttente() == 1) {
      if (Touche() == XK_Escape) break;
    }
  }

  FermerGraphique();
  return 0;
}
