#include <stdio.h>
#include "projet.h"

void fonction_enseignant(char *mdp_ptr) {
    int choix, i = 0;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\nQue voulez-vous faire ?\n\n");
    printf("1. Créer un QCM\n");
    printf("2. Changer le mot de passe\n");
    printf("3. Revenir en arrière\n\n");
    printf("Veuillez choisir \"1\" , \"2\" ou \"3\" : ");
    do{
        scanf("%d", &choix);
        if (choix == 1) { //création qcm
            creer_qcm();
            return;
        } else if (choix == 2) { //modification mdp
            modif_mdp(mdp_ptr);
            return;
        } else if (choix == 3) { //retour en arrière
            enseignant_mdp(mdp_ptr);
            return;
        } else {
            if (i == 0) {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nChoix invalide.\n");
            } 
            else {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nChoix invalide +%d.\n", i);
            }
            printf("\nVeuillez choisir \"1\" , \"2\" ou \"3\" : ");
            printf("1. Créer un QCM\n");
            printf("2. Changer le mot de passe\n");
            printf("3. Revenir en arrière\n\n");
            i++;
        }
    } while (choix != 1 && choix != 2 && choix != 3);
}