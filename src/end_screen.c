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

typedef struct end {
  Button b_quit, b_again;
  int spriteagain;
  int spritequit;
} End;

void init_end(End* end) {
  Button b;
  end->b_again = b;
  end->b_again.x = 600;
  end->b_again.y = 300;
  end->b_again.width = 280;
  end->b_again.height = 60;

  end->b_quit.x = 300;
  end->b_quit.y = 300;
  end->b_quit.width = 280;
  end->b_quit.height = 60;

  /*  end->b_select.x =400;
  end->b_select.y = 500;
  end->b_select.width = 280;
  end->b_select.height = 60; */

  /* Mettre sprite charger de toutes les images */
  end->spriteagain = ChargerSprite("assets/again.png");
  if (end->spriteagain == -1) {
    printf("Erreur de chargement de again.png\n");
  }
  end->spritequit = ChargerSprite("assets/quit.png");
  if (end->spritequit == -1) {
    printf("Erreur de chargement de quit.png\n");
  }
}
unsigned int is_pressed_button(Button b, int x, int y) {
  return x >= b.x && x <= b.x + b.width && y >= b.y && y <= b.y + b.height;
}
int show_pic(End* end) {
   AfficherSprite(end->spriteagain, end->b_again.x, end->b_again.y);
   AfficherSprite(end->spritequit, end->b_quit.x, end->b_quit.y);
}

int mouse_click(End* end) {
    
  if(SourisCliquee()) {
    int x = _X, y = _Y;
  
    /*  if(is_pressed_button(end->b_select, x, y)) {
      EffacerEcran(CouleurParNom("white"));
      } */

    if(is_pressed_button(end->b_quit, x, y)) {
      FermerGraphique();
      /* EffacerEcran(CouleurParNom("white")); */    
    }

    if (is_pressed_button(end->b_again, x, y)){
      ChoisirEcran(1);
    } 
   
  }

  return 0;
}

int main (void) {
  unsigned long next; 
  End  e;

  
  InitialiserGraphique();
  CreerFenetre(100, 100, 900, 600);

  init_end(&e);

  next = Microsecondes() + MICRO;

   while (1) {
    if (Microsecondes() > next) {
      /*  printf("p"); */
      next = Microsecondes() + MICRO;
      show_pic(&e);
      if(mouse_click(&e)) {

      }
    }

    if (ToucheEnAttente() == 1) {
      if (Touche() == XK_Escape) break;
    }
    }

  FermerGraphique();
  return 0;
}


