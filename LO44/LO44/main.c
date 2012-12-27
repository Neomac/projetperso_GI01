//
//  main.c
//  LO44
//
//  Created by Antoine Galluet on 12/12/12.
//  Copyright (c) 2012 Antoine Galluet. All rights reserved.
//


#include "individu.h"
#include "population.h"
#include "foncpop.h"


int main ()
{
	printf("\n\nSalut tout le monde !!!!!!!\n");
	printf("Top est trop fort !!!\n\n");
	
	
	Population p1=CreerP(), p2=CreerP();
	int i;
	
	p1=InitPopIter(p1, 6, 4, 50);
	/*Parametres: population, nombre d'individus, longueur individus et probabilite d'avoir des 1*/
	printf("\nPopulation 1:\n");
	PrintPopQualite(p1);
	printf("\n");
	
	p2=CroiserP(p1, 6, 50);printf("\n");
	/*Parametres: population, longueur individus et probabilite de croiser les bits*/
	printf("Population 2: croisement de p1\n");
	PrintPopQualite(p2);
	printf("\n");
	
	p2=SelectP(p2, 4, 6);
	/*Parametres: population, nombre d'individus, longueur individus*/
	printf("Population 2: selection des 4 premiers individus\n");
	PrintPopQualite(p2);
	printf("\n");
	
	
	/*ListeBit Test = NULL;
	
	Test = InitialiserIndivRecursif(3, 50);
	PrintList(Test);
	printf("Qualite : %f\n", QualiteI(Test));
	
	printf("La valeur numerique de Z est %d\n\n", conversionbinnum(Test, 0));*/
	
}
