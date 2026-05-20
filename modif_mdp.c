#include <stdio.h>
#include <string.h>
#include "projet.h"

void modif_mdp(char *mdp_ptr) {
    FILE *f;
    f = fopen("mdp.txt", "w");
    if (f == NULL) {
        perror("Impossible d'ouvrir mdp.txt");
        return;
    }

    char nv_mdp[20];
    do {
        printf("Rentrez le nouveau mot de passe : ");
        scanf("%19s", nv_mdp);
        if (strcmp(nv_mdp, "0") == 0) {
            printf("Le mot de passe ne peut pas être '0'. Veuillez en choisir un autre.\n");
        } else if (nv_mdp[0] == '\0') {
            printf("Le mot de passe ne peut pas être vide. Veuillez en choisir un autre.\n");
        }
    } while (strcmp(nv_mdp, "0") == 0 || nv_mdp[0] == '\0');

    strcpy(mdp_ptr, nv_mdp);
    printf("Mot de passe changé avec succès! Nouveau mot de passe : %s\n", mdp_ptr);
    fprintf(f, "%s", mdp_ptr);
    fclose(f);
    fonction_enseignant(mdp_ptr);
}