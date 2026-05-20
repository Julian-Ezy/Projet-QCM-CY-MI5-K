#include <stdio.h>
#include "projet.h"

Parametre parametre_menu(){
int confirmation;
Parametre t;
do{
        printf("---------- PARAMETRES --------- \n");
    do{
        printf (" Paramètre 1 : Voulez vous ajoutez la possibilité de mettre des points négatifs\n");
            printf( " Si oui saisir 1 sinon 0\n");
            scanf("%d",&t.choix1);
    }while(t.choix1 != 0 && t.choix1 != 1);

    do{
        printf (" Paramètre 2 : Voulez vous ajouter la possibilité de passer les questions\n");
            printf( " Si oui saisir 1 sinon 0\n");
            scanf("%d",&t.choix2);
    }while(t.choix2 != 0 && t.choix2 != 1);

    do{
        printf (" Paramètre 3 : Voulez vous ajouter la possibilité de mettre plusieurs propositions\n");
            printf( " Si oui saisir 1 sinon 0\n");
            scanf("%d",&t.choix3);
    }while(t.choix3 != 0 && t.choix3 != 1);

        printf("Les paramètres vous conviennent ils ?\n");
        printf(" Si oui saisir 1, sinon 0\n");
    scanf("%d",&confirmation);
}while(confirmation == 0);
return t;
}