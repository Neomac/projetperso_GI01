#include "listebit.h"
#include<time.h>


/* Renvoie aleatoirement 1 ou 0 selon la probabilite choisie par l'utilisateur (valeur comprise entre 0 et 100) */
int random1(int prob);

/* Intervertie aleatoirement les valeurs de deux listes de bits 'a1' et 'a2' selon une probabilite choisie (entre
0 et 100) */
void croise( ListeBit a1, ListeBit a2, int pcroise);

/* Cree et remplie une liste de bits 'A' de 'taille' valeurs (0 ou 1) selon la probabilite choisie (entre 0 et 100) */
ListeBit initialiserIndivIteratif (int taille, int prob);
