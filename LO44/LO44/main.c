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
#include "population.h"

ListeBit initialiserIndiv (int taille, int prob){
    ListeBit A;
    if (taille==0)
        return (A =NULL);
    else{
        return (ajouter_queue(initialiserIndiv(taille-1, prob), random1(prob)));
    }
}

int conversionbinnum (ListeBit A, int i){ //Initialiser i à 0 pour utiliser
    
    if (A==NULL){
        return 0;
    }
    else{
        return ((valeur_tete(A))*(pow(2, i)) + conversionbinnum(reste(A), i+1));
    }
}

float qualite (ListeBit A){
    return (-pow( ( (conversionbinnum (A, 0) /pow(2, 3) ) *(2) -1), 2));
}

int main (){
    
    printf("Salut tout le monde !!!!!!!\n");
    printf("Top est trop fort !!!\n");

    ListeBit Test = NULL;
    
    Test = initialiserIndiv(3, 50);
    printlist(Test);
    printf("Qualite : %f\n", qualite(Test));
    
    printf("La valeur numerique de Z est %d", conversionbinnum(Test, 0));
}