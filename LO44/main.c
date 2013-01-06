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
#include "qualite.c"

int main ()
{
	printf("\n\n**********************************************************\n");
	printf("\n\n          Projet d'algorithmique et programmation\n");
	printf("\n                  LO44-Automne 2012\n");
	printf("\n\n**********************************************************\n\n");



	/* Saisie des parametres du programme */

	int LongIndiv, pCroise, taillePop, tSelect, nGen, cGen;


	printf("\nVeuillez choisir le nombre de bits de chaque individus: 8, 16 ou 32?\n");
	scanf("%d", &LongIndiv);
	while (LongIndiv!=8 && LongIndiv!=16 &&LongIndiv!=32){
		printf("\nErreur de Saisie!\n\nVeuillez choisir le nombre de bits de chaque individus: 8, 16 ou 32?\n");
		scanf("%d", &LongIndiv);
	}

	printf("\n\nVeuillez rentrer la probabilite que ces bits soient des 1:\n");
	scanf("%d", &pCroise);
	while (pCroise<0 || pCroise>100){
		printf("\nErreur de Saisie!\n\nVeuillez rentrer la probabilite que ces bits soient des 1:\n");
		scanf("%d", &pCroise);
	}

	printf("\n\nVeuillez rentrer la taille de la population:\n(entre 20 et 200 individus)\n");
	scanf("%d", &taillePop);
	while (taillePop<20 || taillePop>200){
		printf("\nErreur de Saisie!\n\nVeuillez rentrer la taille de la population:\n(entre 20 et 200 individus)\n");
		scanf("%d", &taillePop);
	}

	printf("\n\nVeuillez rentrer le taux de selection a chaque generation en pourcentage:\n(entre 10%% et 90%%)\n");
	scanf("%d", &tSelect);
	while (tSelect<10 || tSelect>90){
		printf("\nErreur de Saisie!\n\nVeuillez rentrer le taux de selection a chaque generation en pourcentage:\n(entre 10%% et 90%%)\n");
		scanf("%d", &tSelect);
	}

	printf("\n\nVeuillez rentrer le nombre de generations:\n(entre 20 et 200 générations)\n");
	scanf("%d", &nGen);
		while (nGen<20 || nGen>200){
		printf("\nErreur de Saisie!\n\nVeuillez rentrer le nombre de generations:\n(entre 20 et 200 générations)\n");
		scanf("%d", &nGen);
	}


	/* Initialisation de la population */

	Population p=CreerP();

	p=InitPopIter(p, taillePop, LongIndiv, pCroise);
	/*Parametres: population, nombre d'individus, longueur individus et probabilite d'avoir des 1*/
	printf("\nPopulation initiale:\n\n");
	PrintPopQualite(p, LongIndiv);
	printf("\n");


	/* Croisement, tri et selection de la population nGen fois */

	for (cGen=1; cGen<=nGen; ++cGen){
		p=CroiserP(p, taillePop, pCroise, LongIndiv);
		/* Parametres: population, nombre individus et probabilite de croiser les bits */

		p=QuicksortP(p, LongIndiv);
		/* Parametres: population, nombre individus */

		p=SelectP(p, tSelect, taillePop, LongIndiv);
		/* Parametres: population, taux de selection, nombre individus */

	}


	/* Population finale et meilleur individu de la population */

	printf("\nPopulation finale:\n\n");
	PrintPopQualite(p, LongIndiv);
	printf("\n\n");

	printf("Meilleur individu de la population: \n");
	PrintListQualite(p->Indiv, LongIndiv);
	printf("\n\n");


}
