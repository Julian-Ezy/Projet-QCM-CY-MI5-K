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

        if (choix == 1) { // choix du menu étudiant
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            fonction_etudiant();
            return;
        } else if (choix == 2) { // choix du mode enseignant
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            enseignant_mdp(mdp_ptr); // envoie du mdp en paramètre 
            return;
        } else if (choix == 3) { // retour en arrière (fonction main)
            return;
        } else {    // si on ne tape pas 1 2 ou 3
            if (i == 0) {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nChoix invalide.\n");  // message d'erreur
            } 
            else {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nChoix invalide +%d.\n", i); // message d'erreur
            }
            if(i >= 50){
                printf("\nWow, ce type n'a rien d'autre à faire de sa journée\n"); // easter egg si l'utilisateur ne met pas de bon choix 50 fois minimum
            }
            printf("\nVeuillez choisir \"1\" , \"2\" ou \"3\" : \n"); // affichage des propositions apres le message d'erreur
            printf("\n1. Acceder au mode etudiant\n");
            printf("2. Acceder au mode enseignant\n");
            printf("3. Quitter\n");
            i++; // pour augmenter l'affichage du nombre d'erreur de la ligne 33
        }
        }
    } while ((choix != 1 && choix != 2 && choix != 3) || verif != 1);    // boucle tant que choix ou verif incorrect
}