#include <ncurses.h>
#include "../header/menu.h"

int main() {
    // Initialisation de ncurses
    initscr();
    noecho();
    cbreak();

    Menu mon_menu;
    EtatJeu etat_actuel = ETAT_MENU;

    initialiser_menu(&mon_menu);

    while (etat_actuel != ETAT_QUITTER) {
        if (etat_actuel == ETAT_MENU) {
            etat_actuel = gerer_menu(&mon_menu);
        }
        else if (etat_actuel == ETAT_JEU) {
            clear();
            printw("\n>>> Lancement de la partie ! (Appuie sur une touche pour revenir)\n");
            refresh();
            getch();
            etat_actuel = ETAT_MENU;
        }
        else if (etat_actuel == ETAT_SCORES) {
            clear();
            printw("\n>>> Affichage des scores ! (Appuie sur une touche pour revenir)\n");
            refresh();
            getch();
            etat_actuel = ETAT_MENU;
        }
    }

    // Fermeture propre de ncurses avant de quitter
    endwin();
    return 0;
}
