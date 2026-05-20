#include <stdio.h>
#include <string.h>
#include "projet.h"

int main() {
    char mdp[20] = "1234";
    int n;
    FILE *f = fopen("mdp.txt", "r");
    if (f != NULL) {
        if (fgets(mdp, sizeof(mdp), f) == NULL) {
            strcpy(mdp, "1234");
        }
        fclose(f);
    }
    choix_utilisateur(mdp);
    do{
        printf("\nVoulez vous quitter le programme ?");
        printf("\nTapez \"1\" si oui et \"2\" sinon");
        scanf("%d",&n);
        if ( n == 2 ){
            choix_utilisateur(mdp);
        }
    }while( n != 1 && n != 2);
    return 0;
}