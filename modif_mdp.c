#include <stdio.h>
#include <string.h>
#include "projet.h"

void modif_mdp(char *mdp_ptr) {
    FILE *f;
    f = fopen("mdp.txt", "w");//création fichier mdp
    if (f == NULL) {
        perror("Impossible d'ouvrir mdp.txt");
        return;
    }

    char nv_mdp[20];
    do {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nRentrez le nouveau mot de passe : ");
        scanf("%19s", nv_mdp); //recupération du nouveaux mdp
        if (strcmp(nv_mdp, "0") == 0) {
            printf("Le mot de passe ne peut pas être '0'. Veuillez en choisir un autre.\n");
            //le mdp ne peut pas être '0' car celui ci permet de revenir en arrière dans la fonction enseignant_mdp
        } else if (nv_mdp[0] == '\0') {
            printf("Le mot de passe ne peut pas être vide. Veuillez en choisir un autre.\n");
        }
    } while (strcmp(nv_mdp, "0") == 0 || nv_mdp[0] == '\0');

    strcpy(mdp_ptr, nv_mdp);    //échange de l'ancien mdp par le nouveau dans la variable mdp_ptr
    printf("\n\n\n\n\n\n\n\n\n\nMot de passe changé avec succès! Nouveau mot de passe : %s\n", mdp_ptr);
    fprintf(f, "%s", mdp_ptr);  // nouveau mdp écrit dans le fichier pour pouvoir le récupérer la prochaine fois
    fclose(f);
    printf("\nChoisissez :\n\n \"1\" pour revenir au menu enseignant \n \"2\" pour revenir au menu principal\n\n");
    int n, i = 0;
    do {
        scanf("%d", &n);
        if (n == 1) {
            fonction_enseignant(mdp_ptr);
            return;
        } else if (n == 2) {
            choix_utilisateur(mdp_ptr);
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
            printf("\nVeuillez choisir :\n\n \"1\" pour revenir au menu enseignant \n \"2\" pour revenir au menu principal\n\n");
            i++;
        }
    } while (n != 1 && n != 2);
}