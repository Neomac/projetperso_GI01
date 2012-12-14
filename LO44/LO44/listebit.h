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


typedef struct elem{
    int valeur;
    struct elem * suivant;
}Bit;

typedef Bit * ListeBit;

ListeBit creer (){
    ListeBit A = NULL;
    return(A);
}

int vide (ListeBit A){
    if (A==NULL)
        return 0;
    else
        return 1;
}

int valeur (Bit A){
    if (vide(&A))
        return 0;
    else
        return A.valeur;
}

ListeBit ajouter_queue (ListeBit A, int v){
    ListeBit newel, p;
    newel = (ListeBit) malloc(sizeof(Bit));
    newel->valeur = v;
    newel->suivant = NULL;
    if (vide(A)==0){
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

ListeBit reste (ListeBit A){
    return(A=A->suivant);
}



#endif