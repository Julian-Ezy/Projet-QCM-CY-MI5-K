# Projet QCM CY MI5-K 

Julian Clement Titouan

L'équipe de projet est constitué de Julian Pinto, Clement Touchart et Titouan Bonnet.

Le sujet choisis est celui du QCM.
Il doit y avoir 2 modes principaux : le mode étudiant et le mode enseignant.

Le mode enseignant permet, apres avoir rentré un mot de passe, la création d'un QCM ou la modification du mot de passe.
Les QCM ont 3 paramètres possibles : 
La possibilité de mettre des points négatif
La possibilité de passer une question
La possibilité d'avoir un choix multiple de réponse

Les QCM doivent être stockés dans un ficher portant leur nom.

Le mode étudiant permet de réaliser les différents QCM, plus précisément d'en choisir un parmis une liste.
La note est ensuite donnée à la fin du QCM.

3 QCM sont déjà présent, créer par nous.

Notre chargé de TD nous a donné plusieurs variables :
"Chaque QCM est stocké dans un fichier"
"La note de chaque QCM doit être sauvegardé dans un fichier"

Commandes et options pour compiler et faire fonctionner notre projet dans le makefile et le projet.h
Egalement les différentes bibliothèques ajoutées


Pour ce qui est de la conception du projet. 
Très tôt on avait déjà une idée de comment faire dans les grandes lignes. 

Les premières fonctions/voids non pas été très difficile à faire, bien qu'une évolution a été réaliser tout au long.
Avec par exemple les améliorations de sécurisation du codes.

Certaines parties étaient bien plus complexe, l'utilisation des fichiers pour les fonctions creer_qcm, ou bien les problèmes lié au buffer qui n'était pas vide à cause des scanf et fgets. 
L'utilisation des fichiers peu être également difficile car on manque de connaissance et d'experience avec.

La fonction_etudiant a été la plus longue et la plus complexe à réaliser. 
Les autres tâches les plus longues étaient surtout des doutes et changement dans les différents codes car inutile, mal optimisé, ou mal fait à premier coup d'oeil. 
Comme par exemple avec les voids creer_qcm qui ont été changé beaucoup de fois