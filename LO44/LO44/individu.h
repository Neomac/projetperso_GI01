#include "listebit.h"
#include<time.h>


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
void CroiseI( ListeBit a1, ListeBit a2, int pcroise)
{
	int tampon;
	if(VideI(a1)){ /* Cas trivial, rien ne se fait et on resort du sous-programme */
		
	}
	else{																			/* Cas general */
		if(random1(pcroise)){										/* Si la valeur retournee est 1 on intervertie les bits des deux listes */
			tampon = Valeur_Tete_Indiv(a1);
			a1->valeur = Valeur_Tete_Indiv(a2);
			a2->valeur = tampon;
		}
		CroiseI(ResteI(a1), ResteI(a2), pcroise);	/* Dans tous les cas, on fait un appel recursif pour passer aux deux bits suivants */
	}
}


/* Cree et remplie une liste de bits 'A' de 'taille' valeurs (0 ou 1) selon la probabilite choisie (entre 0 et 100) */
/* Algorithme iteratif */
ListeBit InitialiserIndivIteratif (int taille, int prob)
{
	ListeBit A;
	int i;
	for (i=0; i<=taille; ++i){					/* On ajoute en queue de la liste A des bits 0 ou 1 jusqu'a avoir la taille souhaitee */
		Ajouter_Queue_Indiv(A, random1(prob));
	}
	return A;
}

/* Cree et remplie une liste de bits 'A' de 'taille' valeurs (0 ou 1) selon la probabilite choisie (entre 0 et 100) */
/* Algorithme recursif */
ListeBit InitialiserIndivRecursif(int taille, int prob){
    ListeBit A;
    if (taille==0)					/* Cas trivial, taille sert a la fois a donner le nombre de bits de la liste et de compteur */
        return (A =NULL);		/* Une fois le compteur vide on indique la fin de la liste de bits */
    else{										/* Appel recursif, d'ou la necessite d'avoir un compteur dans les parametres de la fonction */
        return (Ajouter_Queue_Indiv(InitialiserIndivRecursif(taille-1, prob), random1(prob)));	/* ajout aleatoire en bout de la liste d'un bit */
    }
}


/* Convertie les bits d'une liste en de bit en son entier correspondant dans la base decimale */
/* L'entier 'i' est un compteur indiquant la puissance correspondante du bit */
/* Algorithme recursif */
float conversionbinnum (ListeBit A, int i){ //Initialiser i a 0 pour utiliser
    
    if (A==NULL){		/* Cas trivial */
        return 0;		/* Une fois arrivee a la fin on retourne 0 car on fait une somme dans le cas general */
    }
    else{						/* Cas general */
        return ((Valeur_Tete_Indiv(A))*(pow(2, i)) + conversionbinnum(ResteI(A), ++i));		/* Calcul de la valeur en decimale selon */
																																													/* la position du bit grace au compteur i */
    }
}

/* Calcule la qualite d'une liste de bits 'A' a partir de sa valeur en base decimale selon la fonction reelle f1 */
float QualiteI (ListeBit A){
    return (-pow( ( (conversionbinnum (A, 0) /pow(2, 3) ) *(2) -1), 2));
}

void PrintListQualite(ListeBit A)
{
	ListeBit I;
	if (A==NULL) {
		printf("Liste vide\n");
	}
	else{
		I=A;
		while (I!=NULL) {
			printf("%d", I->valeur);
			I=I->suivant;
		}
	}
	printf("  %f", QualiteI(A));
}



