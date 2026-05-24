#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"

// explication dans la fonction creer_qcm1
// uniquement les changements seront expliqués

typedef struct {
    char qst[500];
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

void creer_qcm2(Parametre t) {
    char var[100];
    char filename[200];
    int  verif;


    printf("Saisir le nom du qcm : ");
    fgets(var,100,stdin);
    var[strcspn(var, "\n")] = '\0';


    snprintf(filename, sizeof(filename), "QCM_%s.txt", var);                                                         

    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        perror(filename);
        return;
    }
    fprintf(f, "%s\n", var);
    fclose(f);
     
    FILE *k = fopen("quizz.txt", "a");
    if (k == NULL) {
        perror(filename);
        remove(filename);
        return;
    }
    fprintf(k, "\n%s", var);
    fclose(k);

    f = fopen(filename, "a");
    if (f != NULL) {
        fprintf(f, "%d\n", t.choix1);
        fprintf(f, "%d\n", t.choix2);
        fprintf(f, "%d\n", t.choix3);
        fclose(f);
    }
    else {
            perror(filename);
            remove(filename);
            return;
        }


    

    Question *questions = malloc(5 * sizeof(Question));
    if (questions == NULL) {
        perror("Impossible d'allouer la mémoire");
        remove(filename);
        return;
    }

    
    for (int i = 0; i < 5; i++) {
        
    
        f = fopen(filename, "a");
        if (f != NULL) {
            printf("Saisir la question %d : ", i + 1);
            fgets(questions[i].qst, 500, stdin);
            fputs(questions[i].qst, f);

            
            for (int j = 0; j < 4; j++) {
                printf("Saisir la proposition %d pour la question %d : ", j + 1, i + 1);
                fgets(questions[i].propositions[j],500,stdin);
                fputs(questions[i].propositions[j], f);
            } 
            

            do {
            printf("Saisir la réponse 1 pour la question %d : ", i + 1);
            verif = scanf("%d", &questions[i].reponses[0]); // recupération de la réponse 1
            while(getchar() != '\n');

            } while( questions[i].reponses[0] < 1 || questions[i].reponses[0] > 4 || verif !=1 );
            fprintf(f, "%d\n", questions[i].reponses[0]);

            do {
            printf("Saisir la réponse 2 pour la question %d : ", i + 1);
            verif = scanf("%d", &questions[i].reponses[1]); // recupération de la réponse 2
            while(getchar() != '\n');

            } while( (questions[i].reponses[1] < 1 || questions[i].reponses[1] > 4) || (questions[i].reponses[1] == questions[i].reponses[0]) || verif != 1);
            
            if (i != 4){
                fprintf(f, "%d\n", questions[i].reponses[1]);//ecriture de la réponse dans le fichier + saut de ligne
            }
            else {
                fprintf(f, "%d", questions[i].reponses[1]);//si dernière question alors aucun saut de ligne pour ne pas la laissez vide
            }
            fclose(f);
        } 

        else {
            perror(filename);
            remove(filename);
        }

    
    }

    free(questions);
}