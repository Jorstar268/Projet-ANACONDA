#ifndef SNAKE_H
#define SNAKE_H

/*snake.h                                                                                                                                                                                                      
 *Déclaration de la structure snake                                                                                                                                                                            
 */

typedef struct snake{
  int colonne;
  int ligne;
  struct snake *suivant;
    }snake;

typedef enum commande{
  HAUT,
  BAS,
  GAUCHE,
  DROITE,
}commande;

void affich_snake(snake *tete,/*matrice*/);
int moov_snake(snake *tete, commande direction);
int plus_snake(snake *tete);

#endif
