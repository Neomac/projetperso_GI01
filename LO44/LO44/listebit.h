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

ListeBit CreerI (){
    ListeBit A = NULL;
    return(A);
}

int VideI (ListeBit A){
    if (A==NULL)
        return 1;
    else
        return 0;
}

int Valeur_Tete_Indiv (ListeBit A){
    if (A==NULL)
        return 0;
    else
        return A->valeur;
}

ListeBit ResteI (ListeBit A){
    return(A->suivant);
}

ListeBit Ajouter_Queue_Indiv (ListeBit A, int v){
    ListeBit newel, p;
    newel = (ListeBit) malloc(sizeof(Bit));
    newel->valeur = v;
    newel->suivant = NULL;
    if (VideI(A)==1){      // 1 a la place de 0
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

void PrintList(ListeBit A){
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
        printf("\n");
    }
    
}



#endif
