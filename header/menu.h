#ifndef MENU_H
#define MENU_H

// Définition des différents états possibles du jeu
typedef enum {
    ETAT_MENU,
    ETAT_JEU,
    ETAT_SCORES,
    ETAT_QUITTER
} EtatJeu;

// Structure des données nécessaires au fonctionnement du menu
typedef struct {
    int option_selectionnee; // L'index de l'option actuellement choisi
    int nb_options;          // Le nombre total d'options dans le menu
} Menu;

// Les fonctions du menu
void initialiser_menu(Menu *m);
void afficher_menu(const Menu *m);
EtatJeu gerer_menu(Menu *m);

#endif
