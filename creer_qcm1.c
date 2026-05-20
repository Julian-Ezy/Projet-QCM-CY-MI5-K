#include <stdio.h>
#include <stdlib.h>
#include "projet.h"

typedef struct {
    char qst[500];
    char proposition1[500];
    char proposition2[500];
    char proposition3[500];
    char proposition4[500];
    int reponse;
} Question;

typedef struct {
    Question q1[5];
    Question q2[5];
    Question q3[5];
    Question q4[5];
    Question q5[5];
} QCM;

void creer_qcm1() {
    char nom_qcm[100];
    printf("Saisir le nom du qcm : ");
    scanf("%99s", nom_qcm);
    char filename[200];
    snprintf(filename, sizeof(filename), "QCM1_%s.txt", nom_qcm);
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
            printf("Saisir la question %d : ", i + 1);
            scanf("%499s", questions[i].qst);
            fputs(questions[i].qst, f);
            fclose(f);
        } else {
            perror(filename);
        }

        snprintf(filename, sizeof(filename), "QCM1_%s_Q%d_prop1.txt", nom_qcm, i + 1);
        f = fopen(filename, "w");
        if (f != NULL) {
            printf("Saisir la proposition 1 pour la question %d : ", i + 1);
            scanf("%499s", questions[i].proposition1);
            fputs(questions[i].proposition1, f);
            fclose(f);
        } else {
            perror(filename);
        }

        snprintf(filename, sizeof(filename), "QCM1_%s_Q%d_prop2.txt", nom_qcm, i + 1);
        f = fopen(filename, "w");
        if (f != NULL) {
            printf("Saisir la proposition 2 pour la question %d : ", i + 1);
            scanf("%499s", questions[i].proposition2);
            fputs(questions[i].proposition2, f);
            fclose(f);
        } else {
            perror(filename);
        }

        snprintf(filename, sizeof(filename), "QCM1_%s_Q%d_prop3.txt", nom_qcm, i + 1);
        f = fopen(filename, "w");
        if (f != NULL) {
            printf("Saisir la proposition 3 pour la question %d : ", i + 1);
            scanf("%499s", questions[i].proposition3);
            fputs(questions[i].proposition3, f);
            fclose(f);
        } else {
            perror(filename);
        }

        snprintf(filename, sizeof(filename), "QCM1_%s_Q%d_prop4.txt", nom_qcm, i + 1);
        f = fopen(filename, "w");
        if (f != NULL) {
            printf("Saisir la proposition 4 pour la question %d : ", i + 1);
            scanf("%499s", questions[i].proposition4);
            fputs(questions[i].proposition4, f);
            fclose(f);
        } else {
            perror(filename);
        }

        snprintf(filename, sizeof(filename), "QCM1_%s_Q%d_reponse.txt", nom_qcm, i + 1);
        f = fopen(filename, "w");
        if (f != NULL) {
            printf("Saisir la réponse pour la question %d : ", i + 1);
            scanf("%d", &questions[i].reponse);
            fprintf(f, "%d", questions[i].reponse); // rajouter la rep de 1 à 4
            fclose(f);
        } else {
            perror(filename);
        }
    }

    free(questions);
}