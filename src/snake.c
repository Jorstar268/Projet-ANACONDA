#include <stdio.h>
#include "snake.h"

/* snake.c */

void affich_snake(snake *tete, /*matrice*/){
  int anc_ligne_queue;
  int anc_colonne_queue;

  if (tete == NULL){
    return;
  }

  snake *courant = tete;

  while(courant != NULL){
    matrice[courant->ligne][courant->colonne] = 'z';
    courant->ligne = anc_ligne_queue;
    courant->colonne = anc_colonne_queue;
    courant = courant->suivant;
  }
  if(courant == NULL){
    matrice[anc_ligne_queue][anc_colonne_queue] = ' ';/*remettre l'ancienne valeur pas juste la remplacer par un espace*/
  }
}



void  moov_snake(snake *tete, int direction){
  int ligne_temp, colonne_temp;
  int ligne_ancienne = tete->ligne;
  int colonne_ancienne = tete->colonne;
  snake *courant = tete->suivant;

  if(tete == NULL){
    return;
  }


  switch (direction) {
    case HAUT :
        tête->ligne = tete->ligne - 1;
        break;

    case BAS :
        tête->ligne = tete->ligne + 1;
        break;

    case GAUCHE :
        tête->colonne = tete->colonne - 1;
        break;

    case DROITE :
        tête->colonne = tete->colonne + 1;
        break;
  }

 while(courant != NULL){
    ligne_temp = courant->ligne, colonne_temp = courant->colonne;
    courant->ligne = ligne_ancienne, courant->colonne = colonne_ancienne;
    ligne_ancienne = ligne_temp, colonne_ancienne = colonne_temp;
    courant = courant->suivant;
  }
}


int plus_snake(snake *tete){
  snake *courant = tete;
  char bonus;

  while(tete[ligne][colonne] != courant[ligne][colonne]){

    if(courant[ligne][colonne] == bonus){
    while(courant->suivant != NULL){
      courant = courant->suivant;
    }
    courant[ligne-1][colonne-1] = "z";
    }
  }

}
