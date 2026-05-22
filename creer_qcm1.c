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

// structure des 5 questions qui sont composés 
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

    while ((c = getchar()) != '\n' && c != EOF);

    printf("Saisir le nom du qcm : ");
    fgets(var,100,stdin);
    var[strcspn(var, "\n")] = '\0';

    snprintf(filename, sizeof(filename), "QCM1_%s.txt", var);

    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        perror(filename);
        return;
    }
    fprintf(f, "%s\n", var);
    fclose(f);

    f = fopen(filename, "a");
    if (f != NULL) {
        fprintf(f, "%d\n", t.choix1);
        fprintf(f, "%d\n", t.choix2);
        fprintf(f, "%d\n", t.choix3);
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
        
    //question
        f = fopen(filename, "a");
        if (f != NULL) {
            printf("Saisir la question %d : ", i + 1);
            fgets(questions[i].qst, 500, stdin);
            fputs(questions[i].qst, f);

            //boucle proposition
            for (int j = 0; j < 4; j++) {
                printf("Saisir la proposition %d pour la question %d : ", j + 1, i + 1);
                // On utilise questions[i].propositions[j] grâce au tableau de tableaux
                fgets(questions[i].propositions[j],500,stdin);
                fputs(questions[i].propositions[j], f);
            } 
            

        //reponse
            do {
            printf("Saisir la réponse pour la question %d : ", i + 1);
            scanf("%d", &questions[i].reponse);
            } while( questions[i].reponse < 1 || questions[i].reponse > 4);
            if (i != 4){
                fprintf(f, "%d\n", questions[i].reponse);
                while ((c = getchar()) != '\n' && c != EOF);
            }
            else {
                fprintf(f, "%d", questions[i].reponse);
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