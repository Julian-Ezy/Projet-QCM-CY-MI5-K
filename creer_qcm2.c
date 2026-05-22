#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"

typedef struct {
    char qst[200];
    char propositions[4][500]; 
    int reponses[2]; 
} Question;

typedef struct {
    Question q1[5];
    Question q2[5];
    Question q3[5];
    Question q4[5];
    Question q5[5];
} QCM;

void creer_qcm2() {
    char nom_qcm[100];
    printf("Saisir le nom du qcm : ");
    scanf("%99s", nom_qcm);

    char filename[200];
    snprintf(filename, sizeof(filename), "QCM2_%s.txt", nom_qcm);
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        perror(filename);
        return;
    }
    fprintf(f, "%s\n", nom_qcm);
    fclose(f);

    Question *questions = malloc(5 * sizeof(Question));
    if (questions == NULL) {
        perror("Impossible d'allouer la mémoire");
        return;
    }

    
    for (int i = 0; i < 5; i++) {
        
       
        snprintf(filename, sizeof(filename), "QCM1_%s_Q%d_qst.txt", nom_qcm, i + 1);
        f = fopen(filename, "w");
        if (f != NULL) {
            printf("\nSaisir la question %d : ", i + 1);
            scanf("%499s", questions[i].qst);
            fputs(questions[i].qst, f);
            fclose(f);
        } else {
            perror(filename);
        }

      
        for (int j = 0; j < 4; j++) {
            snprintf(filename, sizeof(filename), "QCM1_%s_Q%d_prop%d.txt", nom_qcm, i + 1, j + 1);
            f = fopen(filename, "w");
            if (f != NULL) {
                printf("Saisir la proposition %d pour la question %d : ", j + 1, i + 1);
                scanf("%499s", questions[i].propositions[j]);
                fputs(questions[i].propositions[j], f);
                fclose(f);
            } else {
                perror(filename);
            }
        }

      
        snprintf(filename, sizeof(filename), "QCM1_%s_Q%d_reponse.txt", nom_qcm, i + 1);
        f = fopen(filename, "w");
        if (f != NULL) {
            // Saisie de la première réponse
            printf("Saisir la première bonne réponse pour la question %d : ", i + 1);
            scanf("%d", &questions[i].reponses[0]);

            
            printf("Saisir la deuxième bonne réponse pour la question %d : ", i + 1);
            scanf("%d", &questions[i].reponses[1]);

            fprintf(f, "%d %d", questions[i].reponses[0], questions[i].reponses[1]);
            fclose(f);
        } else {
            perror(filename);
        }
    }

    free(questions);
}