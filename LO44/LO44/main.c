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

int conversionbinnum (ListeBit A, int i){
    if (A==NULL){
        return 0;
    }
    else{
        return ((A->valeur)*(2^(i)) + conversionbinnum(reste(A), i+1));
    }
}

int main (){
    
    printf("Salut tout le monde !!!!!!!\n");
    printf("Top est trop fort !!!\n");
    
    
    int i=0;
    ListeBit Indiv = NULL;
    ListeBit Test = NULL;
    Test = ajouter_queue(Test, 1);
    Test = ajouter_queue(Test, 0);
    Test = ajouter_queue(Test, 1);
    Test = ajouter_queue(Test, 1);
    printlist(Test);
    
    while (i<4) {
        Indiv = ajouter_queue(Indiv,1);
        Indiv = ajouter_queue(Indiv,0);
        i++;
    }
    printlist(Indiv);
    printf("Z est %d", conversionbinnum(Indiv, 0));
}




