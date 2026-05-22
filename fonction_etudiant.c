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
    else{
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
        int rep1,rep2, erep1,erep2, res = 0;

        snprintf(filename,sizeof(filename),"QCM1_%s.txt",nom_qcm);

        printf("Lancement du quizz suivant : %s",filename);

        FILE* g;
        int p1,p2,p3;
        char h[500];
        g = fopen(filename,"r");
        for(int o = 0; o<1;o++){
            fgets(h,500,g);
        }
        fscanf(g,"%d",&p1);
        fscanf(g,"%d",&p2);
        fscanf(g,"%d",&p3);

        for(int i = 0; i<5; i++){
            fgets(h,500,g);
            printf("%de question : %s", i+1,h);
            
            for(int j = 0; j<4 ; j++){
                fgets(h,500,g);
                printf("%de proposition : %s \n ",j,h);
            }
            if(p3 == 0){
                fscanf("%d",&rep1);
            }
            else if (p3 == 1){
                fscanf(g,"%d",&rep1);
                fscanf(g,"%d",&rep2);
            }
            if(p2 == 1){
            
                if(p3 == 0){
                    printf("Saisir 0 si vous voulez passez la question");
                    do{
                        printf("Saisir votre réponse : ");
                        scanf("%d",&erep1);
                    }while( erep1<0 || erep1>4);
                    if(erep1 == rep1){
                        res++;
                    }
                    else if(p1 == 1){
                        if(erep1 != rep1){
                            if(erep1 == 0){
                                res == res;
                            }
                            else{
                                res--;
                            }
                        }
                    }
                }
                else if(p3 == 1){
                    printf("Saisir deux fois 0 si vous voulez passez la question");
                    do{
                        printf("Saisir votre première réponse : ");
                        scanf("%d",&erep1);
                    }while( erep1<0 || erep1>4);
                    do{ 
                        printf("Saisir votre deuxième réponse : ");
                        scanf("%d",&erep2);
                    }while((erep2<0 || erep2>4) || ((erep2 == erep1) && (erep1 != 0)));
                    if((erep1 == rep1) || erep1 == rep2){
                        res++;
                    }
                    else if(p1 == 1){
                        if(erep1 != rep1 && erep1 != rep2){
                            if(erep1 == 0){
                                res == res;
                            }
                            else{
                                res--;
                            }
                        }
                    }
                    if((erep2 == rep1) || erep2 == rep2){
                        res++;
                    }
                    else if(p1 == 1){
                        if(erep2 != rep1 && erep2 != rep2){
                            if(erep2 == 0){
                                res == res;
                            }
                            else{
                                res--;
                            }
                        }
                    }
                }
            }
            else if (p2 == 0){

                if(p3 == 0){
                    do{
                        printf("Saisir votre réponse : ");
                        scanf("%d",&erep1);
                    }while( erep1<1 || erep1>4);
                        if(erep1 == rep1){
                            res++;
                        }
                    else if(p1 == 1){
                        if(erep1 != rep1){
                                res--;
                        }
                    }
                }
                else if(p3 == 1){
                    do{
                        printf("Saisir votre première réponse : ");
                        scanf("%d",&erep1);
                    }while( erep1<1 || erep1>4);
                    do{ 
                        printf("Saisir votre deuxième réponse : ");
                        scanf("%d",&erep2);
                    }while( (erep2<1 || erep2>4) || (erep1 == erep2));
                    if((erep1 == rep1) || erep1 == rep2){
                        res++;
                    }
                    else if(p1 == 1){
                        if(erep1 != rep1 && erep1 != rep2){
                            res--;
                        }
                    }
                    if((erep2 == rep1) || erep2 == rep2){
                        res++;
                    }
                    else if(p1 == 1){
                        if(erep2 != rep1 && erep2 != rep2){
                            res--;
                        }
                    }
                
                }
            
            }
        }
        fclose(g);
        printf("Le QCM est terminée !");
        if(p3 == 1){
            res = res * 2;
        }
        else if(p3 == 0){
            res = res * 4;
        }
        if (res < 0){
            res = 0;
        }
        FILE* k = fopen("Note.txt","a");
        fprintf(k,"%d\n",res);
        fclose(k);

        } // fin du else (si le fichier des titres souvre)
    fclose(f)
    // si le fichier s'ouvre pas ou qu'il est vide alors on arrive ici directement)
    if (i == 1) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nAucun quizz disponible.\n");
        fclose(f);
        
    int n, j = 0;
    do {
        printf("\nChoisissez :\n\n \"1\" pour revenir au menu etudiant \n \"2\" sinon\n\n");
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