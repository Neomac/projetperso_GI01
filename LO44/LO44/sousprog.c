#include "sousprog.h"


/* Le sous-programme retournera aleatoirement 1 selon la probabilité choisie, sinon il retournera 0 */
/* (prob est un entier compris entre 0 et 100) */
int random1(int prob)
{
	srand(time(NULL) + rand()); //Initialise aléatoirement la fonction rand()
	
	if ( (rand() % 100 + 1) <= prob ){ 	//Tire aleatoirement un entier entre 1 et 100 et le compare a prob
		return 1;													//Si c'est inferieure il renvoie 1
	}
	else{
		return 0;													//Sinon il renvoie 0
	}
}


/* Intervertie aleatoirement les valeurs de deux listes de bits 'a1' et 'a2' selon une probabilite choisie (entre 0 et 100) */
/* Algorithme recursif */
void croise( ListeBit a1, ListeBit a2, int pcroise)
{
	int tampon;
	
	if(vide(a1)){ /* Cas trivial, rien ne se fait et on resort du sous-programme */
		
	}
	else{																			/* Cas general */
		if(random1(pcroise)){										/* Si la valeur retournee est 1 on intervertie les bits de deux listes */
			tampon = valeur_tete(a1);
			a1->valeur = valeur_tete(a2);
			a2->valeur = tampon;
		}
		croise(reste(a1), reste(a2), pcroise);	/* Dans tous les cas, on fait un appel recursif pour passer aux deux bits suivants */
	}
}
