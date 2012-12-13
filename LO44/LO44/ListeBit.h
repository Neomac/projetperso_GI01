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

ListeBit ajouter_queue (ListeBit A, int v){
    ListeBit T = A;
    while (T->suivant!=NULL){
        T=T->suivant;
    }
    ListeBit new = (ListeBit) malloc (sizeof (Bit));
    new -> valeur = v;
    new -> suivant = NULL;
    return(T->suivant = new);
}

ListeBit reste (ListeBit A){
    return(A=A->suivant);
}


#endif