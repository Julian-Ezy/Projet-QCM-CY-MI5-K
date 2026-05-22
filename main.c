#include <stdio.h>
#include <string.h>
#include "projet.h"

int main() {
    char mdp[20] = "1234";
    int n;
    FILE *f = fopen("mdp.txt", "r");
    if (f != NULL) { // Si le fichier existe
        if (fgets(mdp, sizeof(mdp), f) == NULL) { // mdp prend le dernier mdp du fichier.
            strcpy(mdp, "1234");                  // Si le fichier existe et ne possède aucun mdp alors "1234" est mis par defaut 
        }
        fclose(f);
    }
    
    choix_utilisateur(mdp);
    do{
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nVoulez vous quitter le programme ?\n");
        printf("\nTapez \"1\" si oui et \"2\" sinon : "); //choix de l'utilisateur permettant de quitter ou non le programme
        scanf("%d",&n);
        if ( n == 2 ){
            choix_utilisateur(mdp);
        }
    }while( n != 1 );
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAu revoir !\n\n");
    return 0;
}