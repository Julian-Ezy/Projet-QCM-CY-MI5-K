#include <stdio.h>
#include "projet.h"

void fonction_etudiant() {
    char s[100];
    int i = 1;
    int choix;
    printf("Choisir le quizz voulant etre fait");
    FILE* f = fopen ("quizz.txt","r");
    
    if (f == NULL){
        printf("erreur fichier");
        
    }
do {
    if (fgets(s,100,f) == NULL) {
        break;
    }
    printf("%d)  %s\n",i,s);
    i++;
} while(1);

    do{ 
        printf("Saisir le choix");
            scanf ("%d",&choix);
    }while(choix > 1 && choix < i);
    
 fclose(f);
}