#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main (void)
{
	int nbv, i, prob, result; 
	i=0;
	
	printf("\n\nRentrer le nombre de valeurs � g�n�rer:\n\n");
	scanf("%d", &nbv);
	
	printf("\n\nRentrer en pourcentage la probabilit� de 1 � g�n�rer:\n\n");
	scanf("%d", &prob);
	
	printf("\n\n");
	
	for (i=0; i <= (nbv); i++){
		result = random1(prob);
	}
	
	printf("\n\n");
	
}

int random1(int prob)
{
	int tirage;
	
	srand(time(NULL) + rand()); //Initialise al�atoirement la fonction rand()
	
	tirage = rand() % 100 + 1;  //Renvoi un entier entre 1 et 100
	
	if ( tirage <= prob ){
		printf("1 ");
		return 1;
	}
	else{
		printf("0 ");
		return 0;
	}
}

