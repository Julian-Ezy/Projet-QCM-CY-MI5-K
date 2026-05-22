#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    else {
    do{
        if (fgets(s,100,f) != NULL) {
           printf("%d)  %s\n",i,s);
            
        i++; 
        }
        else{
    break;
        }

    }while(1); 
    fclose(f);
    char tabq[i-1][100];
    f = fopen("quizz.txt","r");

    if (f == NULL){
         printf("erreur fichier");

        }
    else{
        char tabq[i-1][100];
        int x = 0;
        do{
            if (fgets(s,100,f) != NULL) {
                strcpy(tabq[x], s);
            
                x++; 
            }
            else{
            break;
            }

        }while(1); 
    fclose(f);
    }

    char nom_qcm[100];
    for(int y = 0; y<i-1 ; y++){
     if ( y == choix){
           strcpy(nom_qcm, tabq[choix]);
        }
    }
    char filename[200];
    char w[100];
    int rep, erep, res = 0;

        for (int u = 0; u < 5; u++) {
        
            snprintf(filename, sizeof(filename), "QCM1_%s_Q%d_qst.txt", nom_qcm, u + 1);
            f = fopen(filename, "r");
            if (f != NULL) {
            fgets(w,100,f);
            printf("\n\nQuestion %d : %s \n",u+1,w);
            fclose(f);
        } 
        else {
            perror(filename);
        }

        for (int t = 0; t < 4; t++) {
            snprintf(filename, sizeof(filename), "QCM1_%s_Q%d_prop%d.txt", nom_qcm, u + 1, t + 1);
            f = fopen(filename, "r");
            if (f != NULL) {
                fgets(w,100,f);
                printf("Proposition %d : %s", t , w);
                fclose(f);
            } else {
                perror(filename);
            }
        }

        snprintf(filename, sizeof(filename), "QCM1_%s_Q%d_reponse.txt", nom_qcm, u + 1);
        f = fopen(filename, "r");
        if (f != NULL) {
          rep = fgetc (f);
        printf(" Veuillez choisir la reponse : ");
        scanf("%d",&erep);
        if(erep == rep){
                res++;
        }
        else if(erep == 0){   
        }
        
            fclose(f);
        } else {
            perror(filename);
        }
    }


   




















    }
    if (i == 1) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nAucun quizz disponible.\n");
        fclose(f);
        printf("\nChoisissez :\n\n \"1\" pour revenir au menu etudiant \n \"2\" sinon\n\n");
    int n, j = 0;
    do {
        scanf("%d", &n);
        if (n == 1) {
            fonction_etudiant();
            return;
        } else if (n == 2) {
            return;
        } else {
            if (j == 0) {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nChoix invalide.\n");
            } 
            else {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nChoix invalide +%d.\n", i);
            }
            if(i >= 50){
                printf("\nWow, ce type n'a rien d'autre à faire de sa journée\n");
            }
            printf("\nVeuillez choisir :\n\n \"1\" pour revenir au menu etudiant \n \"2\" sinon\n\n");
            j++;
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