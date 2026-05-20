#include <stdio.h>
#include "projet.h"

void fonction_enseignant(char *mdp_ptr) {
    int choix;
    printf("Que voulez-vous faire ?\n");
    printf("1. Créer un QCM\n");
    printf("2. Changer le mot de passe\n");
    printf("3. Revenir en arrière\n");
    printf("Veuillez choisir \"1\" , \"2\" ou \"3\" : ");
    do{
        scanf("%d", &choix);
        if (choix == 1) {
            creer_qcm();
            return;
        } else if (choix == 2) {
            modif_mdp(mdp_ptr);
            return;
        } else if (choix == 3) {
            enseignant_mdp(mdp_ptr);
            return;
        } else {
            printf("Choix invalide. Veuillez choisir \"1\" , \"2\" ou \"3\" : ");
        }
    } while (choix != 1 && choix != 2 && choix != 3);
}