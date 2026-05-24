#include <stdio.h>
#include <string.h>
#include "projet.h"

void enseignant_mdp(char *mdp_ptr) {
    char rep[20];
    int i = 0;
        printf("\nRentrez le mot de passe pour pouvoir continuer\n");
        printf("Ou bien taper 0 pour revenir en arriere : ");
        do {
        scanf("%19s", rep); // recupération de la reponse 
        if (strcmp(rep, mdp_ptr) == 0) { // comparaison de la chaine de caractère du vrai mdp et de celui saisi par l'utilisateur
            fonction_enseignant(mdp_ptr); // si les deux chaines sont les mêmes alors on entre dans la fonction enseignant
            return;
        } else if (strcmp(rep, "0") == 0) { // comparaison de "0" et de la saisi de l'utilisateur
            choix_utilisateur(mdp_ptr); //retour en arriere 
            return;
        } else { // Si le mdp n'est pas le bon ou que on a pas "0"
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
    } while (strcmp(rep, mdp_ptr) != 0 && strcmp(rep, "0") != 0); // pareil que pour les autres + pas besoin de vérif car on a une chaine de caractère
}