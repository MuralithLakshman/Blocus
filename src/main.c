#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <stdbool.h>
#include "/usr/include/X11/keysymdef.h"

#define MICRO 1000000L 

#define WIDTH 1920
#define HEIGHT 1080

int main(void) {
  int next;
  
  InitialiserGraphique();
  CreerFenetre(10, 10, 900, 900);
  EcrireTexte(10, 10, "JEUX", 12);

  next = Microsecondes() + MICRO; 
  while(true) {
    if(Touche() == XK_Escape) break;
    
    if(Microsecondes() > next) {
      
    }
  }
	      

  FermerGraphique();
  return EXIT_SUCCESS;
}
