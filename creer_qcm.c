#include <stdio.h>
#include <stdlib.h>
#include "projet.h"

void creer_qcm() {
   Parametre t = parametre_menu(); // création des paramètres dans le quizz voulant être créé + récupération de ses derniers

    if (t.choix3 == 1) {
        creer_qcm2(t); // qcm avec le paramètres "choix multiple" + paramètre données dans la fonction qui suit pour la garder en memoire
    } else {
        creer_qcm1(t);//qcm classique + paramètre données dans la fonction qui suit pour la garder en memoire
    }
}