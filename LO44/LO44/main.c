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
	
	int LongIndiv, pCroise, taillePop, tSelect, nGen, cGen;
	
	printf("\n\n**********************************************************\n");
	printf("\n\n Projet d'algorithmique et programmation\n");
	printf("\nLO44-Automne 2012\n");
	printf("\n\n**********************************************************\n\n");
	
	printf("\nVeuillez rentrer le nombre de bits de chaque individus:\n");
	scanf("%d", &LongIndiv);
	
	printf("\n\nVeuillez rentrer la probabilite que ces bits soient des 1:\n");
	scanf("%d", &pCroise);
	
	printf("\n\nVeuillez rentrer la taille de la population:\n(entre 20 et 200 individus)\n");
	scanf("%d", &taillePop);
	
	printf("\n\nVeuillez rentrer le taux de selection a chaque generation en pourcentage:\n(entre 10%% et 90%%)\n");
	scanf("%d", &tSelect);
	tSelect=(taillePop*tSelect)/100;
	
	printf("\n\nVeuillez rentrer le nombre de generations\n");
	scanf("%d", &nGen);
	
	Population p=CreerP();
	
	p=InitPopIter(p, taillePop, LongIndiv, pCroise);
	/*Parametres: population, nombre d'individus, longueur individus et probabilite d'avoir des 1*/
	printf("\nPopulation initiale:\n\n");
	PrintPopQualite(p);
	printf("\n");	
	
	for (cGen=1; cGen<=nGen; ++cGen){
		p=CroiserP(p, taillePop, pCroise);
		/* Parametres: population, nombre individus et probabilite de croiser les bits */
		
		/* Il manque encore l'etape de tri */
		
		p=SelectP(p, tSelect, taillePop);
		/* Parametres: population, taux de selection, nombre individus */
	}
	
	printf("\nPopulation finale:\n\n");
	PrintPopQualite(p);
	printf("\n\n");
	
	printf("Meilleur individu de la population: \n");
	PrintListQualite(p->Indiv);
	printf("\n\n");
	
	
	/*ListeBit Test = NULL;
	
	Test = InitialiserIndivRecursif(3, 50);
	PrintList(Test);
	printf("Qualite : %f\n", QualiteI(Test));
	
	printf("La valeur numerique de Z est %d\n\n", conversionbinnum(Test, 0));*/
	
}
