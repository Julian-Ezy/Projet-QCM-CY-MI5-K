#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"

typedef struct {
    char qst[500];
    char propositions[4][500]; 
    int reponses[2]; 
} Question;
//structure regroupant les données de l'utilisateur

typedef struct {
    Question q1[5];
    Question q2[5];
    Question q3[5];
    Question q4[5];
    Question q5[5];
} QCM;
//structure des 5 questions qui vont être composées

void creer_qcm2(Parametre t) {
    char var[100];
    char filename[200];
    int c;

    while ((c = getchar()) != '\n' && c != EOF);//permet de retirer les sauts de lignes des scanf précédents de la fonction paramètre_menu

    printf("Saisir le nom du qcm : ");
    fgets(var,100,stdin);//permet de retirer les sauts de lignes des scanf précédents de la fonction paramètre_menu
    var[strcspn(var, "\n")] = '\0';//remplace le saut de ligne par \0 (fin)


    snprintf(filename, sizeof(filename), "QCM_%s.txt", var);//ecrit dans la chaine filename le nom complet du qcm                                                           

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
    fprintf(k, "%s\n", var);
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
            

        //ecriture des  différentes réponses
            do {
            printf("Saisir la réponse 1 pour la question %d : ", i + 1);
            scanf("%d", &questions[i].reponses[0]);
            } while( questions[i].reponses[0] < 1 || questions[i].reponses[0] > 4);
            fprintf(f, "%d\n", questions[i].reponses[0]);
            while ((c = getchar()) != '\n' && c != EOF);
            //l'utilisateur saisit la première réponse 
            //cette réponse sera par la suite ecrit dans le fichier correspondant
            do {
            printf("Saisir la réponse 2 pour la question %d : ", i + 1);
            scanf("%d", &questions[i].reponses[1]);
            } while( (questions[i].reponses[1] < 1 || questions[i].reponses[1] > 4) || (questions[i].reponses[1] == questions[i].reponses[0]));
            //l'utilisateur saisit la seconde réponse
            if (i != 4){
                fprintf(f, "%d\n", questions[i].reponses[1]);//ecriture de la réponse dans le fichier + saut de ligne
                while ((c = getchar()) != '\n' && c != EOF);
            }
            else {
                fprintf(f, "%d", questions[i].reponses[1]);//si dernière question alors aucun saut de ligne pour ne pas la laissez vide
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