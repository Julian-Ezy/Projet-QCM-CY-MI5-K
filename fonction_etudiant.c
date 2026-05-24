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
           if (fgets(s,100,f) != NULL) { // Si le fgets n'est pas NULL
                printf("%d)  %s\n",i,s); // on affiche la liste des QCM ( leur nom )
            
                i++; // boucle pour parcourir tout le fichier
            }
            else{
                break; // fin du while si le fgets est NULL
            }

        }while(1); // boucle qui ne s'arrete que avec le break

        fclose(f);

        char tabq[i-1][100]; // on créer un tableau qui peut contenir i-1 nom de 100 caractères
        
        f = fopen("quizz.txt","r");

        if (f == NULL){
            printf("erreur fichier");
        }
        else{ // else qui prend toute la fonction sauf le choix de fin pour rediriger l'utilisateur
            int x = 0;
            do{
                if (fgets(s,100,f) != NULL) {  // boucle qui prend chaque nom 1 par 1 avec le fgets et l'attribut à une case du tabq dans l'ordre
                    strcpy(tabq[x], s);
            
                    x++; 
                }
                else{
                    break; // fin si fgets vide
                }

            }while(1); 

            fclose(f);
        }
        printf("\n"); // saut de ligne dans le terminal

        do{
        verif = scanf("%d", &choix); // récupèration du choix du QCM
        while(getchar() != '\n');

        if (choix <1 || choix > i-1 || verif != 1){
            printf("\nChoisir le quizz voulant être fait : \n");
        }
        }while(choix <1 || choix > i-1 || verif != 1);

        char nom_qcm[100];

        strcpy(nom_qcm, tabq[choix - 1]); // variable nom_qcm prend le nom du qcm choisis
        

        char filename[200];
        int rep1,rep2, erep1 = -1,erep2 = -1, res = 0;
        
            snprintf(filename,sizeof(filename),"QCM_%s.txt",nom_qcm); // filename devient "QCM_---.txt"

        printf("\n\n\n\n\n\n\n\n\n\n\n\nLancement du quizz suivant : \"%s\"\n",filename);

        FILE* g;
        int p1,p2,p3;
        char h[500];
        g = fopen(filename,"r"); // ouverture du bon fichier 

        if (g == NULL){
            printf("erreur fichier");
        }
        else{
        for(int o = 0; o<1;o++){ 
            fgets(h,500,g); // sauter la première ligne du fichier
        }
        fscanf(g,"%d",&p1); // on récupère les 3 paramètres
        fscanf(g,"%d",&p2);
        fscanf(g,"%d",&p3);

        printf("\n-----ATTENTION-----\n"); // présentation des règles en fonction des paramètres
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
            printf("\n\nPour commencer le QCM tapez \"1\" ou \"2\" sinon : "); // validation pour lancer le qcm pour pouvoir lire les règles
            verif = scanf("%d",&e);
            while(getchar() != '\n');
        }while((e != 1 && e != 2) || verif != 1);

        if (e == 2){
            fclose(g); // si refus de continuer alors on ferme le fichier et on reviens dans la boucle du main
            return;
        }

        for(int i = 0; i<5; i++){ // boucle pour les 5 questions
            fgetc(g); // juste avant on a les fscanf qui esquive les "\n" donc le curseur ne se trouve pas à la question mais juste apres le paramètre 3 sur la ligne de ce dernier ( quand la boucle recommence le curseur fait pareil mais pour les réponses récupérées à la fin de la boucle) 
            fgets(h,500,g); // on récupère la question
            printf("\n\n\n\n\n\n\n\n\n\nQuestion n°%d : %s\n", i+1,h); // on l'affiche
            
            for(int j = 0; j<4 ; j++){
                fgets(h,500,g); // on récupère les props
                printf("Proposition n°%d : %s \n",j+1,h); // affichage
            }
            if(p3 == 0){
                fscanf(g,"%d",&rep1); // on récupère la réponse si p3 = 0
            }
            else if (p3 == 1){
                fscanf(g,"%d",&rep1); // on récupère les réponses si p3 = 1
                fscanf(g,"%d",&rep2);
            }
            if(p2 == 1){ // si p2 = 0, if qui rajoute le printf pour passer la question
            
                if(p3 == 0){ // cas avec 1 réponse
                    printf("Saisir 0 si vous voulez passez la question\n\n");
                    do{
                        printf("Saisir votre réponse : ");
                        verif = scanf("%d",&erep1);
                        while(getchar() != '\n');
                        printf("\n\n\n\n\n");
                    }while( erep1<0 || erep1>4 || verif != 1);
                    if(erep1 == rep1){ // +1 si bonne réponse
                        res++;
                    }
                    else if(p1 == 1){ // si p1 = 1
                        if(erep1 != rep1) // -1 si mauvaise
                            if(erep1 == 0){ // sauf si 0
                                res = res;
                            }
                            else{
                                res--;
                            }
                        }
                    }
                }
                else if(p3 == 1){ // si 2 réponses
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
                    if((erep1 == rep1) || (erep1 == rep2)){ // cas pour le 1er choix de l'utilisateur
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
                    if((erep2 == rep1) || (erep2 == rep2)){ // cas pour le 2ième choix
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
            else if (p2 == 0){ // pareil mais sans l'option pour passer une question

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
        fclose(g); // on ferme le fichier une fois finis
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nLe QCM est terminée !\n");
        if(p3 == 1){ // note sur 10 ramené sur 20
            res = res * 2;
        }
        else if(p3 == 0){ // note sur 5 ramené sur 20
            res = res * 4;
        }
        if (res < 0){ // si la note est négative à cause du 1er paramètre
            res = 0; // la note deviens juste 0
        }
        printf("\nVotre note est de %d/20 \n", res); // affichage de la note
        snprintf(h, sizeof(h), "%s\n%d/20",nom_qcm, res); 
        // h deviens :
        //"nom_qcm
        //?/20"
        //
        FILE* k = fopen("Note.txt","a");
        if (k != NULL){
        fprintf(k,"%s\n",h); // écriture de h dans le fichier "Note.txt"
        fclose(k);
        }
        } // fin du else (si le fichier du QCM s'ouvre)

        } // fin du else (si le fichier des titres s'ouvre)
    // (si le fichier s'ouvre pas ou qu'il est vide alors on arrive ici directement)
    if (i == 1) { // si le i ne fait jamais i++, alors il n'y a pas de quizz
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nAucun quizz disponible.\n");
    }
        
    int n, j = 0;
    do {
        printf("\nChoisissez :\n\n \"1\" pour revenir au menu etudiant \n\"2\" sinon\n\n"); // choix de quoi faire une fois le qcm fini ou bien si il y a eu un problème
        verif = scanf("%d", &n);
        while(getchar() != '\n');

        if (n == 1 && verif == 1) {
            fonction_etudiant(); // si choix 1 
            return;
        } else if (n == 2 && verif == 1) {
            return; // si choix 2 retour dans le main
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