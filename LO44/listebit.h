//
//  stcuture.h
//  LO44
//
//  Created by Antoine Galluet on 11/12/12.
//  Copyright (c) 2012 Antoine Galluet. All rights reserved.
//
//
//  ListeBit.h
//  LO44
//
//  Created by Antoine Galluet on 12/12/12.
//  Copyright (c) 2012 Antoine Galluet. All rights reserved.
//

#ifndef LO44_ListeBit_h
#define LO44_ListeBit_h


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/***********************************/
/*     Definition Type ListeBit    */
/***********************************/

typedef struct elem{
	int valeur;
	struct elem * suivant;
}Bit;

typedef Bit * ListeBit;


/***********************************/
/*       Operateurs ListeBit       */
/***********************************/

/* Cree une liste de bits vide */
ListeBit CreerI (){
	ListeBit A = NULL;
	return(A);
}

/* Test si une liste de bits est vide ou non */
/* Si la liste est vide on renvoie 1 sinon 0 */
int VideI (ListeBit A){
	if (A==NULL){
		return 1;
	}
	else{
		return 0;
	}
}

/* Renvoie le bit de tete d'une liste de bits*/
/* Si la liste est vide on renvoie 0 */
int Valeur_Tete_Indiv (ListeBit A){
	if (VideI(A)){
		return 0;
	}
	else{
		return A->valeur;
	}
}

/* Renvoie au bit suivant d'une liste de bits */
ListeBit ResteI (ListeBit A){
	return(A->suivant);
}

/* Ajoute a une liste de bits un bit supplementaire en fin de liste */
/* ListeBit A: liste de bits a laquelle rajouter le bit; int v: valeur du bit a rajouter */
ListeBit Ajouter_Queue_Indiv (ListeBit A, int v){
	
	ListeBit newel, p;
	
	/* Creation et allocation memoire du nouveau bit selon les parametres */
	newel = (ListeBit) malloc(sizeof(Bit));
	newel->valeur = v;
	newel->suivant = NULL;	/* Le bit etant en fin de liste on le marque comme tel */
	
	if (VideI(A)){ /* Si la liste est vide alors assigne le pointeur au nouveau bit */
		A=newel;
	}
	else{ /* Sinon on parcourt la liste jusqu'a etre a la fin ou on le rajoute */
		p=A;
		while(VideI(ResteI(p))==0){
			p=ResteI(p);
		}
		p->suivant = newel;
	}
	return A;
}

/* Imprime les valeurs d'une liste de bits en ligne */
void PrintList(ListeBit A){
	ListeBit I;
	if (VideI(A)) { /* Si la liste est vide on l'indique */
		printf("Liste vide\n");
	}
	else{ /* Sinon on parcourt la liste en imprimant les valeurs des bits au fur et a mesure */
		I=A;
		while (VideI(I)==0) { 
			printf("%d", I->valeur);
			I=ResteI(I);
		}
	}
}



#endif
