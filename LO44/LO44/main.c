//
//  main.c
//  LO44
//
//  Created by Antoine Galluet on 12/12/12.
//  Copyright (c) 2012 Antoine Galluet. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "listebit.h"
#include "random1.h"

int conversionbinnum(ListeBit A, int i){
    if (vide(A)==1){
        return 0;
    }
    else{
        return (A->valeur)*2^(i) + conversionbinnum(reste(A), i+1);
    }
}

int main (){
    
    printf("Salut tout le monde !!!\n");
    printf("Top est trop fort !!!\n");
    
    
    int i, Z;
    ListeBit Indiv = NULL;
    
    for (i=0; i<4; i++){
        Indiv = ajouter_queue(Indiv,1);
    }
    
    Z=conversionbinnum(Indiv, 0);
    printlist(Indiv);
    printf("Z est %d", Z);
}




