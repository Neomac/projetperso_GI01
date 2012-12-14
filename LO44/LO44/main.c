//
//  main.c
//  LO44
//
//  Created by Antoine Galluet on 12/12/12.
//  Copyright (c) 2012 Antoine Galluet. All rights reserved.
//

#include <stdio.h>
#include </Users/HP-Touchpad/projetperso_GI01/LO44/LO44/listebit.h>
#include </Users/HP-Touchpad/projetperso_GI01/LO44/LO44/random1.c>

int main (){
    
    printf("Salut tout le monde !!!\n");
    printf("Top est trop fort !!!\n");
    int i, Z;
    ListeBit Indiv = NULL;
    for (i=1; i<11; i++){
        Indiv = ajouter_queue(Indiv,1);
    }
    Z=compt(Indiv);
    printf(Z);
    random1(20);
    
}



int compt(ListeBit A; int i){
    if (vide(A)==0)
}