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
    int rep1,rep2, erep, res = 0;

        snprintf(filename,sizeof(filename),"QCM1_%s.txt",nom_qcm);

printf("Lancement du quizz suivant : %s",filename);

int propj,prop,count = 0;
FILE* g;
int p1,p2,p3;
char h[100];
g = fopen(filename,"r");
    for(int o = 0; o<1;o++){
        fgets(s,100,g);
    }
    for(int v = 0; v < 3; v++){
        fscanf("%d",&p1);
    }
    for(int i = 0; i<5; i++){
        fgets(h,100,g);
        printf("%de question : %s", i+1,h);
            
        for(int j = 0; j<4 ; j++){
            fgets(h,100,g);
            printf("%de proposition : %s \n ",j,h);
        }
do{
    printf("Saisir la proposition correcte : ");
    scanf("%d",&erep);
}while( erep<1 || erep>4);
 
prop = fscanf("%d",&h);
if (erep)
}

 }
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