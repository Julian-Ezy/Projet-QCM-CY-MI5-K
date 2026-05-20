#include <stdio.h>
#include "projet.h"

void fonction_etudiant() {
    char s[100];
    int i = 1;
    int choix;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nChoisir le quizz voulant etre fait\n");
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

    if (i == 1) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nAucun quizz disponible.\n");
        fclose(f);
        printf("\nChoisissez :\n\n \"1\" pour revenir au menu etudiant \n \"2\" sinon\n\n");
    int n, i = 0;
    do {
        scanf("%d", &n);
        if (n == 1) {
            fonction_etudiant();
            return;
        } else if (n == 2) {
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
            printf("\nVeuillez choisir :\n\n \"1\" pour revenir au menu etudiant \n \"2\" sinon\n\n");
            i++;
        }
    } while (n != 1 && n != 2);
        return;
    }
    do{ 
        printf("Saisir le choix : ");
            scanf ("%d",&choix);
    }while(choix < 1 || choix >= i);
    
 fclose(f);
}