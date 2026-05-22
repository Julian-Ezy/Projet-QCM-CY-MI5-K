#include <stdio.h>
#include <stdlib.h>
#include "projet.h"

void creer_qcm() {
   Parametre t = parametre_menu(); //création des paramètres dans le quizz voulant être créé

    if (t.choix3 == 1) {
        creer_qcm2(t); //qcm avec paramètres plusieurs propositions
    } else {
        creer_qcm1(t);//qcm classique
    }
}