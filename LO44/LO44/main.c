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
#include "foncpop.h"


int main ()
{
	printf("\n\nSalut tout le monde !!!!!!!\n");
	printf("Top est trop fort !!!\n\n");
	
	Population p;
	int i;
	
	//p=InitPopRecur(p, 20, 8, 50);
	p=InitPopIter(p, 20, 8, 50);
	
	i=0;
	while(i<=5 && VideP(p)==0){
		PrintList(p->Indiv);
		printf("   %.3f\n", p->qualite);
		p=ResteP(p);
	}
	
	/*ListeBit Test = NULL;
	
	Test = InitialiserIndivRecursif(3, 50);
	PrintList(Test);
	printf("Qualite : %f\n", QualiteI(Test));
	
	printf("La valeur numerique de Z est %d\n\n", conversionbinnum(Test, 0));*/
	
}
