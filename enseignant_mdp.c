#include <stdio.h>
#include <string.h>
#include "projet.h"

void enseignant_mdp(char *mdp_ptr) {
    char rep[20];
    int i = 0;
        printf("\nRentrez le mot de passe pour pouvoir continuer\n");
        printf("Ou bien taper 0 pour revenir en arriere : ");
        do {
        scanf("%19s", rep);
        if (strcmp(rep, mdp_ptr) == 0) { // comparaison de la chaine de caractère du vrai mdp et de celui saisi par l'utilisateur
            fonction_enseignant(mdp_ptr);
            return;
        } else if (strcmp(rep, "0") == 0) {//retour en arriere 
            choix_utilisateur(mdp_ptr);
            return;
        } else {
            if (i == 0) {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nMot de passe incorrect.\n");
            } 
            else {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nMot de passe incorrect.  +%d\n", i);
            }
            if(i >= 50){
                printf("\nWow, ce type n'a rien d'autre à faire de sa journée\n");
            }
            printf("\nRentrez le mot de passe pour pouvoir continuer\n");
            printf("Ou bien taper 0 pour revenir en arriere : ");
            i++;
        }
    } while (strcmp(rep, mdp_ptr) != 0 && strcmp(rep, "0") != 0);
}