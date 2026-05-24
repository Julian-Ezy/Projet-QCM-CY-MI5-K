#include <stdio.h>
#include "projet.h"

void choix_utilisateur(char *mdp_ptr) {
    int choix = 0,verif, i = 0;

    printf("\n\n\n\n\n\n\n\n\n\n\n\nChoisissez une option :\n");
    printf("\n1. Acceder au mode etudiant\n");
    printf("2. Acceder au mode enseignant\n");
    printf("3. Quitter\n");
    printf("\nVous choisissez \"1\" , \"2\" ou \"3\" ? : ");
    do {
        verif = scanf("%d", &choix);
        while(getchar() != '\n');
        
        if ( verif == 1){

        if (choix == 1) { // selection par l'etudiant pour faire le quizz
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            fonction_etudiant();
            return;
        } else if (choix == 2) { //selection du mode enseignant
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            enseignant_mdp(mdp_ptr);
            return;
        } else if (choix == 3) { //retour en arrière (fonction main)
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
            printf("\nVeuillez choisir \"1\" , \"2\" ou \"3\" : \n");
            printf("\n1. Acceder au mode etudiant\n");
            printf("2. Acceder au mode enseignant\n");
            printf("3. Quitter\n");
            i++;
        }
        }
    } while ((choix != 1 && choix != 2 && choix != 3) || verif != 1);    
}