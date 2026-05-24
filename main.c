#include <stdio.h>
#include <string.h>
#include "projet.h"

int main() {
    char mdp[20] = "1234";
    int n = 0, verif;
    FILE *f = fopen("mdp.txt", "r");  
    if (f != NULL) { // Si le fichier existe
        if (fgets(mdp, sizeof(mdp), f) == NULL) { // si le fgets est null 
            strcpy(mdp, "1234");                  // le fichier existe et ne possède aucun mdp alors "1234" est mis par defaut 
        }
        fclose(f);
    
    
    choix_utilisateur(mdp); // lance la fonction pour choisir quoi faire + mdp en paramètre au cas où il aurait changé
    } // fin du if le fichier s'ouvre
    else if (f == NULL){ // si le fichier est NULL
        perror("Impossible d'ouvrir mdp.txt"); // message d'erreur 
    }

    do{ // si il y a un return a n'importe qu'elle moment, on arrive dans cette boucle
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nVoulez vous quitter le programme ?\n");
        printf("\nTapez \"1\" si oui et \"2\" sinon : "); //choix de l'utilisateur permettant de quitter ou non le programme
        verif = scanf("%d",&n); // récupération du choix + sécurité avec le verif qui récupère si le scanf a bien pris un int
        while(getchar() != '\n'); // permet de vider les lettres, si tapées par l'utilisateur 

        if ( n == 2  && verif == 1){ // si la vérif est correcte et que l'utilisateur ne veut pas quitter on lance la fonction des choix
            choix_utilisateur(mdp);
        }
    
        
    }while( (n != 1 ) || verif != 1); // la boucle continue tant qu'on ne tape pas 1 ou que la vérif est bonne

    

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAu revoir !\n\n");
    return 0;
}