//
//  population.h
//  LO44
//
//  Created by Antoine Galluet on 18/12/12.
//  Copyright (c) 2012 Antoine Galluet. All rights reserved.
//

#ifndef LO44_population_h
#define LO44_population_h

#include "listebit.h"


/***********************************/
/*    Definition Type Population   */
/***********************************/

typedef struct elemp{
    ListeBit Indiv;
    float qualite;
    struct elemp * suivant;
}element;

typedef element * Population;



/***********************************/
/*      Operateurs Population      */
/***********************************/

/* Cree une liste d'individus vide */
Population CreerP()
{
	Population P = NULL;
	return P;
}

/* Test si une liste d'individus est vide ou non */
/* Si la liste est vide on renvoie 1 sinon 0 */
int VideP (Population A)
{
    if (A==NULL)
        return 1;
    else
        return 0;
}

/* Renvoie la qualite de l'individu de tete d'une liste d'individus*/
/* Si la liste est vide on renvoie 0 */
float qualite_tete_pop (Population A)
{
    if (VideP(A)){
        return 0;
		}
    else{
        return A->qualite;
		}
}

/* Renvoie a l'individu suivant d'une liste d'individus */
Population ResteP(Population A)
{
    return(A->suivant);
}

/* Imprime les valeurs des individus d'une liste d'individus en colonne */
void PrintPop(Population A)
{
	if(VideP(A)){ /* Si la liste est vide on l'indique */
		printf("Population vide\n");
	}
	else{ /* Sinon on parcourt la liste en imprimant les valeurs des individus au fur et a mesure */
		while (VideP(A)==0){
			PrintList(A->Indiv);
			A = ResteP(A);
		}
	}
}

/* Imprime les valeurs des individus et leur qualite d'une liste d'individus en colonne */
void PrintPopQualite(Population A, int LongIndiv)
{
	if(VideP(A)){ /* Si la liste est vide on l'indique */
		printf("Population vide\n");
	}
	else{ /* Sinon on parcourt la liste en imprimant les valeurs et les qualites des individus au fur et a mesure */
		while (VideP(A)==0){
			PrintList(A->Indiv);
			printf("  %f\n", A->qualite);
			A = ResteP(A);
		}
	}
}

/* Ajoute a une liste d'individus un individu supplementaire en fin de liste */
/* Population A: liste d'individus a laquelle rajouter l'individu; ListeBit indiv: individu a rajouter */
Population ajouter_queue_pop (Population A, ListeBit indiv, int LongIndiv)
{
	Population newel, p;
	
	/* Creation et allocation memoire du nouvel individu selon les parametres */
	newel = (Population) malloc(sizeof(element));
	newel->Indiv = indiv;
	newel->qualite=QualiteI(indiv, LongIndiv); /* Calcul de la qualite de l'individu */
	newel->suivant = NULL;/* Le bit etant en fin de liste on le marque comme tel */
	
	
	if (VideP(A)){ /* Si la liste est vide alors assigne le pointeur au nouvel individu */
		A=newel;
	}
	else{ /* Sinon on parcourt la liste jusqu'a etre a la fin ou on le rajoute */
		p=A;
		while(VideP(ResteP(p))==0){
			p=ResteP(p);
		}
		p->suivant = newel;
	}
	return A;
}

/* Parcourt une liste d'individus et renvoie le dernier */
/* Algorithme recursif */
Population Dernier_Pop(Population p)
{
	if(VideP(p) || VideP(ResteP(p))){ /* Si on est au bout de la liste ou si la liste est vide on renvoie le dernier element */
		return p;
	}
	else{ /* Sinon on poursuit dans la liste */
		p=Dernier_Pop(ResteP(p));
		return p;
	}
}

/* Parcourt une liste d'individus et renvoie l'avant dernier */
/* Algorithme recursif */
Population Avant_Dernier_Pop(Population p)
{
	if(VideP(p) || VideP(ResteP(p)) || VideP(ResteP(ResteP(p)))){ /* Si on est au bout de la liste ou si la liste */
																																/* est vide on renvoie l'avant dernier element */
		return p;
	}
	else{ /* Sinon on poursuit dans la liste */
		p=Avant_Dernier_Pop(ResteP(p));
		return p;
	}
}

#endif
