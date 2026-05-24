#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"

// structure pour enregistrer les données de l'utilisateur
typedef struct {
    char qst[500];
    char propositions[4][500]; 
    int reponse;
} Question;

// structure des 5 questions qui sont composées 
typedef struct {
    Question q1[5];
    Question q2[5];
    Question q3[5];
    Question q4[5];
    Question q5[5];
} QCM;

void creer_qcm1(Parametre t) {

    char var[100];
    char filename[200];
    int c;

    while ((c = getchar()) != '\n' && c != EOF);//permet de retirer les sauts de lignes des scanf précédents de la fonction paramètre_menu

    printf("Saisir le nom du qcm : ");
    fgets(var,100,stdin); //ecrit dans la chaine de caractere ce que l'utilisateur a saisi
    var[strcspn(var, "\n")] = '\0'; //remplace le saut de ligne par \0 (fin)

    snprintf(filename, sizeof(filename), "QCM_%s.txt", var);//permet de mettre dans la chaine filename le nom du qcm

    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        perror(filename);
        return;
    }
    fprintf(f, "%s\n", var);//première ligne du fichier portant le qcm  est le nom de celui-ci
    fclose(f);

    FILE *k = fopen("quizz.txt", "a");
    if (k == NULL) {
        perror(filename);
        return;
    }
    fprintf(k, "\n%s", var);
    fclose(k);

    f = fopen(filename, "a");
    if (f != NULL) {
        fprintf(f, "%d\n", t.choix1);
        fprintf(f, "%d\n", t.choix2);
        fprintf(f, "%d\n", t.choix3);//ecriture des paramètres dans les lignes 2,3,4 du fichier
        fclose(f);
    }
    else {
            perror(filename);
        }


    
// creation du tableau des questions 
    Question *questions = malloc(5 * sizeof(Question));
    if (questions == NULL) {
        perror("Impossible d'allouer la mémoire");
        return;
    }

    // Boucle 5 questions
    for (int i = 0; i < 5; i++) {
        
    //remplir par les questions de l'utilisateur
        f = fopen(filename, "a");
        if (f != NULL) {
            printf("Saisir la question %d : ", i + 1);
            fgets(questions[i].qst, 500, stdin);//permet de recupérer la phrase avec les espaces
            fputs(questions[i].qst, f);//ecriture de la question directement dans le fichier

            //boucle proposition
            for (int j = 0; j < 4; j++) {
                printf("Saisir la proposition %d pour la question %d : ", j + 1, i + 1);
                //on remplit grâce au tableau de tableau questions[i].propositions[j]
                fgets(questions[i].propositions[j],500,stdin);
                fputs(questions[i].propositions[j], f);
            } 
            

        //ecriture de la réponse 
            do {
            printf("Saisir la réponse pour la question %d : ", i + 1);
            scanf("%d", &questions[i].reponse);
            } while( questions[i].reponse < 1 || questions[i].reponse > 4);
            if (i != 4){
                fprintf(f, "%d\n", questions[i].reponse); //ecrit la reponse i dans le fichier et saute une ligne
                while ((c = getchar()) != '\n' && c != EOF);//
            }
            else {
                fprintf(f, "%d", questions[i].reponse); //ecrit la dernière reponse sans saut de ligne pour ne pas avoir de ligne vide
                while ((c = getchar()) != '\n' && c != EOF);
            }
            fclose(f);
        } 

        else {
            perror(filename);
        }

    
    }

    free(questions);
}