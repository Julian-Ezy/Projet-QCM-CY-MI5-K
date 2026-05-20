#include <stdio.h>
#include <string.h>
#include "projet.h"

void enseignant_mdp(char *mdp_ptr) {
    char rep[20];
    do {
        printf("\nRentrez le mot de passe pour pouvoir continuer\n");
        printf("Ou bien taper 0 pour revenir en arriere : \n");
        scanf("%19s", rep);
        if (strcmp(rep, mdp_ptr) == 0) {
            fonction_enseignant(mdp_ptr);
            return;
        } else if (strcmp(rep, "0") == 0) {
            choix_utilisateur(mdp_ptr);
            return;
        } else {
            printf("Mot de passe incorrect.\n");
        }
    } while (strcmp(rep, mdp_ptr) != 0 && strcmp(rep, "0") != 0);
}