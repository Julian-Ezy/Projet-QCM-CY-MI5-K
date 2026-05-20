#ifndef PROJET_H
#define PROJET_H

typedef struct {
int choix1;
int choix2;
int choix3;
}Parametre;


void choix_utilisateur(char *mdp_ptr);
void fonction_etudiant();
void fonction_enseignant(char *mdp_ptr);
void enseignant_mdp(char *mdp_ptr);
void modif_mdp(char *mdp_ptr);
void creer_qcm1();
void creer_qcm2();
Parametre parametre_menu();
void creer_qcm();


#endif