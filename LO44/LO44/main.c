//
//  main.c
//  LO44
//
//  Created by Antoine Galluet on 12/12/12.
//  Copyright (c) 2012 Antoine Galluet. All rights reserved.
//

#include <stdio.h>
#include <ListeBit.h>

int main (){
    
    printf("Salut tout le monde !!!\n");
    int i, Z;
    ListeBit Indiv = NULL;
    for (i=1; i<11; i++){
        Indiv = ajouter_queue(Indiv,1);
    }
    Z=compt(Indiv);
    printf(Z);
    
}



int compt(ListeBit A){
    int n = 0;
    if (A->valeur==0){
        return(0);
    }
    else if (A->valeur==1){
        return(1);
    }
    else{
        if (A->valeur%2==1){
            return(2^(n+1)+ compt((reste(A))));
            n++;
        }
        else{
            return(compt(reste(A)));
        }
    }
}