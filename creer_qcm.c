#include <stdio.h>
#include <stdlib.h>
#include "projet.h"

void creer_qcm() {
   Parametre t = parametre_menu();

    if (t.choix3 == 1) {
        creer_qcm2(t);
    } else {
        creer_qcm1(t);
    }
}