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

Population CreerP()
{
	Population P = NULL;
	return P;
}

int VideP (Population A)
{
    if (A==NULL)
        return 1;
    else
        return 0;
}

int qualite_tete_pop (Population A)
{
    if (A==NULL)
        return 0;
    else
        return A->qualite;
}

Population ResteP(Population A)
{
    return(A->suivant);
}

void PrintPopQualite(Population A)
{
	while (VideP(A)==0){
		PrintList(A->Indiv);
		printf("   %.3f\n", A->qualite);
		A = ResteP(A);
	}
}

Population ajouter_queue_pop (Population A, ListeBit indiv)
{
    Population newel, p;
    newel = (Population) malloc(sizeof(element));
    newel->Indiv = indiv;
		newel->qualite=QualiteI(indiv);
    newel->suivant = NULL;
    if (VideP(A)){      // 1 a la place de 0
        A=newel;
    }
    else{
        p=A;
        while(p->suivant!=NULL){
            p=p->suivant;
        }
        p->suivant = newel;
    }
    return A;
}

void PrintPop(Population A)
{
	while (VideP(A)==0){
		PrintList(A->Indiv);
		A = ResteP(A);
	}
}

Population Dernier_Pop(Population p)
{
	if(VideP(ResteP(p))){
		return p;
	}
	else{
		p=Dernier_Pop(ResteP(p));
		return p;
	}
}

Population Avant_Dernier_Pop(Population p)
{
	if(VideP(ResteP(p)) || VideP(ResteP(ResteP(p)))){
		return p;
	}
	else{
		p=Avant_Dernier_Pop(ResteP(p));
		return p;
	}
}

#endif
