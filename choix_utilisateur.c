#include <stdio.h>
#include "projet.h"

void choix_utilisateur(char *mdp_ptr) {
    int choix;

    printf("\nChoisissez une option :\n");
    printf("1. Acceder au mode etudiant\n");
    printf("2. Acceder au mode enseignant\n");
    printf("3. Quitter\n");
    printf("Vous choisissez \"1\" , \"2\" ou \"3\" ? : ");
    do {
        scanf("%d", &choix);
        if (choix == 1) {
            fonction_etudiant();
        } else if (choix == 2) {
            enseignant_mdp(mdp_ptr);
        } else if (choix == 3) {
            printf("Au revoir !\n");
            return;
        } else {
            printf("Choix invalide. Veuillez choisir \"1\" , \"2\" ou \"3\".\n");
        }
    } while (choix != 1 && choix != 2 && choix != 3);
}