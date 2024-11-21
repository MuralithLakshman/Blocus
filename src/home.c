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

typedef struct home {
  Button b_monter, b_descendre, b_select, b_1player, b_2player;
  int tailleGrille;
  int spriteRight;
  int spriteLeft;
  int spriteSelect;
  int sprite1player;
  int sprite2player;
  int sprite1playergreen;
  int sprite2playergreen;
} Home;

unsigned int is_pressed_button(Button b, int x, int y) {
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
  Button b;
  home->tailleGrille = 3;
  home->b_monter = b;
  home->b_monter.x = 600;
  home->b_monter.y = 300;
  home->b_monter.width = 30;
  home->b_monter.height = 30;

  home->b_descendre.x = 300;
  home->b_descendre.y = 300;
  home->b_descendre.width = 30;
  home->b_descendre.height = 30;

  home->b_select.x =400;
  home->b_select.y = 500;
  home->b_select.width = 280;
  home->b_select.height = 60;

  home->b_1player = b;
  home->b_1player.x = 50;
  home->b_1player.y = 400;
  home->b_1player.width = 280;
  home->b_1player.height = 60;

  home->b_2player.x = 50;
  home->b_2player.y = 450;
  home->b_2player.width = 280;
  home->b_2player.height = 60;
  
  
  home->spriteRight = ChargerSprite("assets/right-arrow.png");
  if (home->spriteRight == -1) {
    printf("Erreur de chargement de fleche_droite.png\n");
  }
 home->spriteLeft = ChargerSprite("assets/left-arrow.png");
  if (home->spriteLeft == -1) {
    printf("Erreur de chargement de fleche_gauche.png\n");
  }

 home->spriteSelect = ChargerSprite("assets/Select.png");
  if (home->spriteSelect == -1) {
    printf("Erreur de chargement de Select.png\n");
  }
  home->sprite1player = ChargerSprite("assets/1-Player.png");
  if (home->sprite1player == -1) {
    printf("Erreur de chargement de 1-Player.png\n");
  }
  home->sprite2player = ChargerSprite("assets/2-Players.png");
  if (home->sprite2player == -1) {
    printf("Erreur de chargement de 2-Player.png\n");
  }
  home->sprite1playergreen = ChargerSprite("assets/1-Player-green.png");
  if (home->sprite1playergreen == -1) {
    printf("Erreur de chargement de 1-Player-green.png\n");
  }
  home->sprite2playergreen = ChargerSprite("assets/2-Players-green.png");
  if (home->sprite2playergreen == -1) {
    printf("Erreur de chargement de 2-Player-green.png\n");
  }
}


void show_player(Home* home) {
  
  AfficherSprite(home->sprite1player, home->b_1player.x, home->b_1player.y);
  AfficherSprite(home->sprite2player, home->b_2player.x, home->b_2player.y);
}

void update_screen(Home* home) {
   char texte[20];
   
   EffacerEcran(CouleurParNom("white"));  

   AfficherSprite(home->spriteRight, home->b_monter.x, home->b_monter.y);
   AfficherSprite(home->spriteLeft, home->b_descendre.x, home->b_descendre.y);
   AfficherSprite(home->spriteSelect, home->b_select.x, home->b_select.y);
   
  AfficherSprite(home->sprite1player, home->b_1player.x, home->b_1player.y);
  AfficherSprite(home->sprite2player, home->b_2player.x, home->b_2player.y);
 
   sprintf(texte, "Taille %dx%d", home->tailleGrille, home->tailleGrille);
   print_text(50, 100, 2, "black", texte);
}



int mouse_click(Home* home) {
    
  if(SourisCliquee()) {
    int x = _X, y = _Y;
    
    if(is_pressed_button(home->b_monter, x, y)) {
      if(home->tailleGrille < 9) {
        home->tailleGrille++;
        return 1;
      }
    }

    if(is_pressed_button(home->b_descendre, x, y)) {
      if(home->tailleGrille > 3) {
        home->tailleGrille--;
        return 1;
      }
    }
    
    if(is_pressed_button(home->b_select, x, y)) {
      EffacerEcran(CouleurParNom("white"));
    }

    if(is_pressed_button(home->b_1player, x, y)) {
      init_game(home);
      /* EffacerEcran(CouleurParNom("white")); */
      AfficherSprite(home->sprite1playergreen, home->b_1player.x, home->b_1player.y);
      AfficherSprite(home->sprite2player, home->b_2player.x, home->b_2player.y);
    }

    if (is_pressed_button(home->b_2player, x, y)) {
      AfficherSprite(home->sprite1player, home->b_1player.x, home->b_1player.y);
      AfficherSprite(home->sprite2playergreen, home->b_2player.x, home->b_2player.y);
    } 
   
  }

  return 0;
}

  

unsigned int show_screen(int screen) {
  if(screen <= 0 || screen > 10) return 0;
  
  ChoisirEcran(0);
  EffacerEcran(CouleurParNom("white"));
  CopierZone(screen, 0, 0, 0, WIDTH, HEIGHT, 0, 0);

  return screen;
} 

int main(void) {
  unsigned long next; 
  Home h;

  InitialiserGraphique();
  CreerFenetre(100, 100, 900, 600);

  init_game(&h);

  next = Microsecondes() + MICRO;
  update_screen(&h);
  while (1) {
    if (Microsecondes() > next) {
      /*  printf("p"); */
      next = Microsecondes() + MICRO;

      if(mouse_click(&h)) {
	update_screen(&h);
      }
    }

    if (ToucheEnAttente() == 1) {
      if (Touche() == XK_Escape) break;
    }
    }

  FermerGraphique();
  return 0;
}
