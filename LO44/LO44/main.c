//
//  main.c
//  LO44
//
//  Created by Antoine Galluet on 12/12/12.
//  Copyright (c) 2012 Antoine Galluet. All rights reserved.
//

#include <stdio.h>
#include </Users/HP-Touchpad/projetperso_GI01/LO44/LO44/listebit.h>
#include <math.h>
#include </Users/HP-Touchpad/projetperso_GI01/LO44/LO44/random1.h>

int compt(ListeBit A, int i){
    if (vide(A)==0){
        return 0;
    }
    else{
        return (A->valeur)*2^(i) + compt(reste(A), i+1);
    }
}

int main (){
    
    printf("Salut tout le monde !!!\n");
    printf("Top est trop fort !!!\n");
    int i, Z;
    ListeBit Indiv = NULL;
    for (i=1; i<2; i++){
        Indiv = ajouter_queue(Indiv,1);
    }
    Z=compt(Indiv, 0);
    printf("Z est %d", Z);
}




