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
    int verif;

     // permet de retirer les sauts de lignes des scanf précédents de la fonction paramètre_menu
                                                 // obligatoire quand on alterne entre les scanf et les fgets car il ne récupère pas de la meme manière ce que tape l'utilisateur
                                                 // le scanf récupère les infos mais laisse le /n en attente (ne gêne pas car scanf ne prend pas les /n)
                                                 // le fgets récupère tout même le /n 
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSaisir le nom du qcm : ");
    fgets(var,100,stdin); // ecrit dans la chaine de caractere ce que l'utilisateur va saisir
    var[strcspn(var, "\n")] = '\0'; //remplace le saut de ligne par \0 (fin), car le fgets récupère le \n (entrée) et on n'en veux pas pour le nom du qcm par la suite

    snprintf(filename, sizeof(filename), "QCM_%s.txt", var); // permet de mettre dans la chaine filename le nom du qcm

    FILE *f = fopen(filename, "w"); // ouverture d'un nouveau fichier "QCM_---.txt" + écrire en vidant le fichier si il existe déjà

    if (f == NULL) {
        perror(filename);
        return;
    }
    fprintf(f, "%s\n", var); //première ligne du fichier portant le qcm  est le nom de celui-ci
    fclose(f);

    FILE *k = fopen("quizz.txt", "a");
    if (k == NULL) {
        perror(filename);
        remove(filename);
        return;
    }
    fprintf(k, "\n%s", var); // on ajoute le nom du qcm à la liste des noms qcm se trouvant dans le fichier "quizz.txt"
    fclose(k);

    f = fopen(filename, "a");
    if (f != NULL) {
        fprintf(f, "%d\n", t.choix1); //ecriture des paramètres dans les lignes 2,3,4 du fichier
        fprintf(f, "%d\n", t.choix2);
        fprintf(f, "%d\n", t.choix3);
        fclose(f);
    }
    else {
            perror(filename);
            remove(filename); // effacement du fichier car sans suite
            return;
        }


    
// creation du tableau des questions 
    Question *questions = malloc(5 * sizeof(Question)); // allocation de l'espace nécessaire 

    if (questions == NULL) { // si jamais ça échoue 
        perror("Impossible d'allouer la mémoire"); // message d'erreur 
        remove(filename); // effacement du fichier car sans suite
        return; // fin de la fonction ( retour dans le main)
    }

    // Boucle 5 questions
    for (int i = 0; i < 5; i++) {
        
    
        f = fopen(filename, "a");
        if (f != NULL) {
            printf("Saisir la question %d : ", i + 1);
            fgets(questions[i].qst, 500, stdin); // permet de recupérer la phrase avec les espaces
            fputs(questions[i].qst, f); // ecriture de la question directement dans le fichier

            //boucle 4 propositions
            for (int j = 0; j < 4; j++) {
                printf("Saisir la proposition %d pour la question %d : ", j + 1, i + 1);
                fgets(questions[i].propositions[j],500,stdin); 
                fputs(questions[i].propositions[j], f); // ecriture des propositions
            } 
            

        
            do {
            printf("Saisir la réponse pour la question %d : ", i + 1);
            verif = scanf("%d", &questions[i].reponse); // recupération de la réponse
            while(getchar() != '\n');

            } while( questions[i].reponse < 1 || questions[i].reponse > 4 || verif != 1);

            if (i != 4){
                fprintf(f, "%d\n", questions[i].reponse); //ecrit la reponse i dans le fichier et saute une ligne
            }
            else {
                fprintf(f, "%d", questions[i].reponse); //ecrit la dernière reponse sans saut de ligne pour ne pas avoir de ligne vide
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