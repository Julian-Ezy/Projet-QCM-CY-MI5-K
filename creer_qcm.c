#include <stdio.h>
#include <stdlib.h>
#include "projet.h"

void creer_qcm() {
    if (parametre_menu().choix3 == 1) {
        creer_qcm1();
    } else {
        creer_qcm2();
    }
}