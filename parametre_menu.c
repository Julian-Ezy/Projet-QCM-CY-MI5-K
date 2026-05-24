#include <stdio.h>
#include "projet.h"

Parametre parametre_menu(){
int confirmation, verif;
Parametre t;
do{
        printf("\n\n\n\n\n\n\n\n\n---------- PARAMETRES --------- \n");
    do{
        printf (" Paramètre 1 : Voulez vous ajoutez la possibilité de mettre des points négatifs\n");
        printf( " Si oui saisir 1 sinon 0\n");
        verif = scanf("%d",&t.choix1);
        while(getchar() != '\n');
    }while((t.choix1 != 0 && t.choix1 != 1) || verif != 1);

    do{
        printf (" Paramètre 2 : Voulez vous ajouter la possibilité de passer les questions\n");
        printf( " Si oui saisir 1 sinon 0\n");
        verif = scanf("%d",&t.choix2);
        while(getchar() != '\n');
    }while((t.choix2 != 0 && t.choix2 != 1) || verif != 1);

    do{
        printf (" Paramètre 3 : Voulez vous ajouter la possibilité de mettre plusieurs propositions\n");
        printf (" Il y aura 2 bonnes réponses sur 4");
        printf( " Si oui saisir 1 sinon 0\n");
        verif = scanf("%d",&t.choix3);
        while(getchar() != '\n');
    }while((t.choix3 != 0 && t.choix3 != 1) || verif != 1);

    do{
        printf("\n\n\n\n\n\n\n\n\n\nUn QCM contient 5 questions et 4 propositions chacune");
        printf("\n\nLes paramètres vous conviennent ils ?\n");
        printf("Si oui saisir 1, sinon 0\n");
        verif = scanf("%d",&confirmation);
        while(getchar() != '\n');
    } while((confirmation != 1 && confirmation != 0) || verif != 1);
}while(confirmation == 0 );
return t;
}