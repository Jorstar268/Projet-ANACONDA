#include<stdio.h>
#include"snake.h"

int main(){
  char touche = '\0';
  commande direction = DROITE;

    switch (touche) {
    case 'o':
        direction = HAUT;
        break;

    case 'l':
        direction = BAS;
        break;

    case 'k':
        direction = GAUCHE;
        break;

    case 'm':
        direction = DROITE;
        break;

    case 'q':
        quitter();
        break;
    }


}
