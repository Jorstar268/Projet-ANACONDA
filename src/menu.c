#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../header/menu.h"

void initialiser_menu(Menu *m) {
    m->option_selectionnee = 0; // Positionne le curseur sur la première option
    m->nb_options = 3;// Nombre total d'options (Jouer, Scores, Quitter)
}

void afficher_menu(const Menu *m) {
    // Efface l'écran du terminal.
    clear();

    printw("========================================\n");
    printw("              SNAKE - MENU              \n");
    printw("========================================\n\n");

    // Affiche un indicateur (>) sur l'option active
    if (m->option_selectionnee == 0)
	printw("  > 1. Jouer\n");
    else
	printw("    1. Jouer\n");

    if (m->option_selectionnee == 1)
	printw("  > 2. Meilleurs Scores\n");
    else
	printw("    2. Meilleurs Scores\n");

    if (m->option_selectionnee == 2)
	printw("  > 3. Quitter\n");
    else
	printw("    3. Quitter\n");

    printw("\nUtilise z (haut), s (bas) puis v pour valider.\n");
}

EtatJeu gerer_menu(Menu *m) {
    char choix;

    while (1) {
        afficher_menu(m);

	// getch() lit la touche instantanément sans appuyer sur Entrée
        choix = getch();

        // Gestion de la navigation
        if (choix == 'z' || choix == 'Z') {
            m->option_selectionnee--;
            if (m->option_selectionnee < 0) {
                m->option_selectionnee = m->nb_options - 1; // Revient tout en bas
            }
        }
        else if (choix == 's' || choix == 'S') {
            m->option_selectionnee++;
            if (m->option_selectionnee >= m->nb_options) {
                m->option_selectionnee = 0; // Revient tout en haut
            }
        }
        else if (choix == 'v' || choix == 'V') {
            // Renvoie l'état correspondant au choix validé
            switch (m->option_selectionnee) {
                case 0: return ETAT_JEU;
                case 1: return ETAT_SCORES;
                case 2: return ETAT_QUITTER;
            }
        }
    }
}
