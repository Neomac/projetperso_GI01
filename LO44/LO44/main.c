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


/* Cree et remplie une liste de bits 'A' de 'taille' valeurs (0 ou 1) selon la probabilite choisie (entre 0 et 100) */
/* Algorithme recursif */
ListeBit initialiserIndiv (int taille, int prob){
    ListeBit A;
    if (taille==0)					/* Cas trivial, taille sert a la fois a donner le nombre de bits de la liste et de compteur */
        return (A =NULL);		/* Une fois le compteur vide on indique la fin de la liste de bits */
    else{										/* Appel recursif, d'ou la necessite d'avoir un compteur dans les parametres de la fonction */
        return (ajouter_queue(initialiserIndiv(taille-1, prob), random1(prob)));	/* ajout aleatoire en bout de la liste d'un bit */
    }
}


/* Convertie les bits d'une liste en de bit en son entier correspondant dans la base decimale */
/* L'entier 'i' est un compteur indiquant la puissance correspondante du bit */
/* Algorithme recursif */
int conversionbinnum (ListeBit A, int i){ //Initialiser i a 0 pour utiliser
    
    if (A==NULL){		/* Cas trivial */
        return 0;		/* Une fois arrivee a la fin on retourne 0 car on fait une somme dans le cas general */
    }
    else{						/* Cas general */
        return ((valeur_tete(A))*(pow(2, i)) + conversionbinnum(reste(A), ++i));		/* Calcul de la valeur en decimale selon */
																																										/* la position du bit grace au compteur i */
    }
}


/* Calcule la qualite d'une liste de bits 'A' a partir de sa valeur en base decimale selon la fonction reelle f1 */
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
