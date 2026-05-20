#include <stdio.h>
#include "projet.h"

void choix_utilisateur(char *mdp_ptr) {
    int choix, i = 0;

    printf("\n\n\n\n\n\n\n\n\n\n\n\nChoisissez une option :\n");
    printf("\n1. Acceder au mode etudiant\n");
    printf("2. Acceder au mode enseignant\n");
    printf("3. Quitter\n");
    printf("\nVous choisissez \"1\" , \"2\" ou \"3\" ? : ");
    do {
        scanf("%d", &choix);
        if (choix == 1) {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            fonction_etudiant();
        } else if (choix == 2) {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            enseignant_mdp(mdp_ptr);
        } else if (choix == 3) {
            return;
        } else {
            if (i == 0) {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nChoix invalide.\n");
            } 
            else {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nChoix invalide +%d.\n", i);
            }
            if(i >= 50){
                printf("\nWow, ce type n'a rien d'autre à faire de sa journée\n");
            }
            printf("\n Veuillez choisir \"1\" , \"2\" ou \"3\" : ");
            printf("\n1. Acceder au mode etudiant\n");
            printf("2. Acceder au mode enseignant\n");
            printf("3. Quitter\n");
            i++;
        }
    } while (choix != 1 && choix != 2 && choix != 3);
}