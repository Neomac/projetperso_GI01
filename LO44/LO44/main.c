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
#include "individu.h"
#include "population.h"


int main (){
    
    printf("\n\nSalut tout le monde !!!!!!!\n");
    printf("Top est trop fort !!!\n");

    ListeBit Test = NULL;
    
    Test = InitialiserIndiv(3, 50);
    PrintList(Test);
    printf("Qualite : %f\n", QualiteI(Test));
    
    printf("La valeur numerique de Z est %d\n\n", conversionbinnum(Test, 0));
		
}
