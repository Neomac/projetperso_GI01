//
//	main.c
//	LO44
//
//	Created by Antoine Galluet on 12/12/12.
//	Copyright (c) 2012 Antoine Galluet. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include </Users/HP-Touchpad/projetperso_GI01/LO44/LO44/listebit.c>
//#include </Users/HP-Touchpad/projetperso_GI01/LO44/LO44/random1.c>
//#include </users/arnaudv/documents/travail/utbm/lo44/lo44_projet/projetperso_GI01/LO44/LO44/random1.c>
//#include </users/arnaudv/documents/travail/utbm/lo44/lo44_projet/projetperso_GI01/LO44/LO44/listebit.c>


typedef struct elem{
    int valeur;
    struct elem *suivant;
}Bit;

typedef Bit *ListeBit;


int main (){
		
		/*printf("Salut tout le monde !!!\n");
		printf("Top est trop fort !!!\n");*/
		
		printf("Test 1\n");
		
		int i, Z;
		
		printf("Test 2\n");
		
		ListeBit Indiv = NULL;
		
		printf("Test 3\n");
		
		for (i=1; i<11; i++){
			
			printf("Test 1%d\n", i);
			
			Indiv = ajouter_queue(Indiv,1);
			
		}
		Z=compt(Indiv);
		printf("Z = %d\n\n", Z);
		//random1(20);
		
}



int compt(ListeBit A){
    int n;
    if (A->valeur==0){
        n=0;
        return(0);
    }
    else if (A->valeur==1){
        n=1;
        return(1);
    }
    else{
        if (A->valeur%2==1){
            return(2^(n)+ compt((reste(A))));
            n++;
        }
        else{
            return(compt(reste(A)));
            n++;
        }
    }
}

ListeBit ajouter_queue(ListeBit A, int v){
    ListeBit T = A;
    while (T->suivant!=NULL){
        T=T->suivant;
    }
    ListeBit new = (ListeBit*) malloc (sizeof (ListeBit));
    new -> valeur = v;
    new -> suivant = NULL;
    return(T->suivant = new);
}

ListeBit creer(){
    ListeBit A = NULL;
    return(A);
}

ListeBit reste(ListeBit A){
    return(A=A->suivant);
}
