#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"


void fonction_etudiant() {
    char s[100];
    int i = 1;
    int choix = 0, e, verif;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nChoisir le quizz voulant etre fait : \n");
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
        printf("\n");
        do{
        verif = scanf("%d", &choix);
        while(getchar() != '\n');

        if (choix <1 || choix > i-1 || verif != 1){
            printf("\nChoisir le quizz voulant être fait : \n");
        }
        }while(choix <1 || choix > i-1 || verif != 1);

        char nom_qcm[100];

        strcpy(nom_qcm, tabq[choix - 1]);
        

        char filename[200];
        int rep1,rep2, erep1 = -1,erep2 = -1, res = 0;
        
            snprintf(filename,sizeof(filename),"QCM_%s.txt",nom_qcm);

        printf("\n\n\n\n\n\n\n\n\n\n\n\nLancement du quizz suivant : \"%s\"\n",filename);

        FILE* g;
        int p1,p2,p3;
        char h[500];
        g = fopen(filename,"r");

        if (g == NULL){
            printf("erreur fichier");
        }
        else{
        for(int o = 0; o<1;o++){
            fgets(h,500,g);
        }
        fscanf(g,"%d",&p1);
        fscanf(g,"%d",&p2);
        fscanf(g,"%d",&p3);

        printf("\n-----ATTENTION-----\n");
        if (p3 == 1){
            printf("\nLa note est sur 10 et sera remise sur 20");
        }
        else if(p3 == 0){
            printf("\nLa note est sur 5 et sera remise sur 20");
        }
        printf("\nUne réponse bonne vous donnera 1 point");
        if(p1 == 1){
            printf("\nUne réponse négative vous retirera 1 point");
            printf("\nSi la note est inférieur à 0 elle vaudra un 0/20");
        }
        if(p2 == 1){
            printf("\nVous pourrez choisir \"0\" si vous voulez passez la question et ne pas perdre de points");
        }
        do{
            printf("\n\nPour commencer le QCM tapez \"1\" ou \"2\" sinon : ");
            verif = scanf("%d",&e);
            while(getchar() != '\n');
        }while((e != 1 && e != 2) || verif != 1);
        if (e == 2){
            fclose(g);
            return;
        }

        for(int i = 0; i<5; i++){
            fgetc(g);
            fgets(h,500,g);
            printf("\n\n\n\n\n\n\n\n\n\nQuestion n°%d : %s\n", i+1,h);
            
            for(int j = 0; j<4 ; j++){
                fgets(h,500,g);
                printf("Proposition n°%d : %s \n",j+1,h);
            }
            if(p3 == 0){
                fscanf(g,"%d",&rep1);
            }
            else if (p3 == 1){
                fscanf(g,"%d",&rep1);
                fscanf(g,"%d",&rep2);
            }
            if(p2 == 1){
            
                if(p3 == 0){
                    printf("Saisir 0 si vous voulez passez la question\n\n");
                    do{
                        printf("Saisir votre réponse : ");
                        verif = scanf("%d",&erep1);
                        while(getchar() != '\n');
                        printf("\n\n\n\n\n");
                    }while( erep1<0 || erep1>4 || verif != 1);
                    if(erep1 == rep1){
                        res++;
                    }
                    else if(p1 == 1){
                        if(erep1 != rep1){
                            if(erep1 == 0){
                                res = res;
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
                        verif = scanf("%d",&erep1);
                        while(getchar() != '\n');
                    }while( erep1<0 || erep1>4 || verif != 1);
                    do{ 
                        printf("Saisir votre deuxième réponse : ");
                        verif = scanf("%d",&erep2);
                        while(getchar() != '\n');
                    }while((erep2<0 || erep2>4) || ((erep2 == erep1) && (erep1 != 0)) || verif !=1);
                    if((erep1 == rep1) || (erep1 == rep2)){
                        res++;
                    }
                    else if(p1 == 1){
                        if((erep1 != rep1) && (erep1 != rep2)){
                            if(erep1 == 0){
                                res = res;
                            }
                            else{
                                res--;
                            }
                        }
                    }
                    if((erep2 == rep1) || (erep2 == rep2)){
                        res++;
                    }
                    else if(p1 == 1){
                        if((erep2 != rep1) && (erep2 != rep2)){
                            if(erep2 == 0){
                                res = res;
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
                        verif = scanf("%d",&erep1);
                        while(getchar() != '\n');
                    }while( erep1<1 || erep1>4 || verif != 1);
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
                        verif = scanf("%d",&erep1);
                        while(getchar() != '\n');
                    }while( erep1<1 || erep1>4 || verif != 1);
                    do{ 
                        printf("Saisir votre deuxième réponse : ");
                        verif = scanf("%d",&erep2);
                        while(getchar() != '\n');
                    }while( (erep2<1 || erep2>4) || (erep1 == erep2) || verif != 1);
                    if((erep1 == rep1) || (erep1 == rep2)){
                        res++;
                    }
                    else if(p1 == 1){
                        if((erep1 != rep1) && (erep1 != rep2)){
                            res--;
                        }
                    }
                    if((erep2 == rep1) || (erep2 == rep2)){
                        res++;
                    }
                    else if(p1 == 1){
                        if((erep2 != rep1) && (erep2 != rep2)){
                            res--;
                        }
                    }
                
                }
            
            }
        }
        fclose(g);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nLe QCM est terminée !\n");
        if(p3 == 1){
            res = res * 2;
        }
        else if(p3 == 0){
            res = res * 4;
        }
        if (res < 0){
            res = 0;
        }
        printf("\nVotre note est de %d/20 \n", res);
        snprintf(h, sizeof(h), "%s\n%d/20",nom_qcm, res);
        FILE* k = fopen("Note.txt","a");
        if (k != NULL){
        fprintf(k,"%s\n",h);
        fclose(k);
        }
        } // fin du else (si le fichier du QCM s'ouvre)

        } // fin du else (si le fichier des titres s'ouvre)
    // si le fichier s'ouvre pas ou qu'il est vide alors on arrive ici directement)
    if (i == 1) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nAucun quizz disponible.\n");
    }
        
    int n, j = 0;
    do {
        printf("\nChoisissez :\n\n \"1\" pour revenir au menu etudiant \n\"2\" sinon\n\n");
        verif = scanf("%d", &n);
        while(getchar() != '\n');

        if (n == 1 && verif == 1) {
            fonction_etudiant();
            return;
        } else if (n == 2 && verif == 1) {
            return;
        } else {
            if (j == 0) {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nChoix invalide.\n");
            } 
            else {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nChoix invalide +%d.\n", j);
            }
            if(j >= 50){
                printf("\nWow, ce type n'a rien d'autre à faire de sa journée\n");
            }
            j++;
        }
    } while ((n != 1 && n != 2) || verif != 1);
}