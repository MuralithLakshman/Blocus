#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <string.h>
#include "/usr/include/X11/keysymdef.h"

#include "utils.h"

#define MICRO 1000000L
#define WIDTH 900
#define HEIGHT 600
#define MAX_WIDTH 1270
#define MAX_HEIGHT 740

typedef struct home {
  int screen;
  Button up_button, down_button, select_button, one_player_button, two_players_button;
  int grid_size;
  int right_arrow_sprite;
  int left_arrow_sprite;
  int select_sprite;
  int one_player_sprite;
  int two_players_sprite;
  int one_player_selected_sprite;
  int two_players_selected_sprite;
} Home;

Home* new_home() {
  Home* home;
  
  home->grid_size = 3;
  home->up_button = new_button(600, 300, 30, 30);
  home->down_button = new_button(300, 300, 30, 30);
  home->select_button = new_button(400, 500, 280, 60);
  home->one_player_button = new_button(50, 400, 280 60);
  home->two_player_button = new_button(50, 450, 280, 60);
  
  home->right_arrow_sprite = load_sprite("assets/right-arrow.png");
  home->left_arrow_sprite = load_sprite("assets/left-arrow.png");
  home->select_sprite = load_sprite("assets/Select.png");
  home->one_player_sprite = load_sprite("assets/1-Player.png");
  home->two_players_sprite = load_sprite("assets/2-Players.png");
  home->one_player_selected = load_sprite("assets/1-Player-green.png");
  home->two_players_selected_sprite = load_sprite("assets/2-Players-green.png");

  return home; 
}

void update_screen(Home* home) {
   char text[20];
   
   EffacerEcran(CouleurParNom("white"));  

   AfficherSprite(home->right_arrow_sprite, home->up_button.x, home->up_button.y);
   AfficherSprite(home->left_arrow_sprite, home->down_button.x, home->down_button.y);
   AfficherSprite(home->select_sprite, home->select_button.x, home->select_button.y);
   
   AfficherSprite(home->one_player_sprite, home->one_player_button.x, home->one_player_button.y);
   AfficherSprite(home->two_players_sprite, home->two_players_button.x, home->two_players_button.y);
 
   sprintf(texte, "Taille %dx%d", home->grid_size, home->grid_size);
   print_text(50, 100, 2, "black", text);
}



int mouse_click_home(Home* home) {
    
  if(SourisCliquee()) {
    int x = _X, y = _Y;
    
    if(is_pressed_button(home->up_button, x, y)) {
      if(home->grid_size < 9) {
        home->grid_size++;
        return 1;
      }
    }

    if(is_pressed_button(home->down_button, x, y)) {
      if(home->grid_size > 3) {
        home->grid_size--;
        return 1;
      }
    }
    
    if(is_pressed_button(home->select_button, x, y)) {
      EffacerEcran(CouleurParNom("white"));
    }

    if(is_pressed_button(home->one_player_button, x, y)) {
      init_game(home);
      AfficherSprite(home->, home->one_player_button.x, home->one_player_button.y);
      AfficherSprite(home->two_players_selected, home->two_players_button.x, home->two_players_button.y);
    }

    if (is_pressed_button(home->two_players_button, x, y)) {
      AfficherSprite(home->one_player_sprite, home->one_player_button.x, home->one_player_button.y);
      AfficherSprite(home->two_players_selected_sprite, home->two_players_button.x, home->two_players_button.y);
    } 
   
  }

  return 0;
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
