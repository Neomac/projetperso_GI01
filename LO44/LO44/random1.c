#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*void main (void)
{
	int nbv, i, prob, result; 
	i=0;
	
	printf("\n\nRentrer le nombre de valeurs a generer:\n\n");
	scanf("%d", &nbv);
	
	printf("\n\nRentrer en pourcentage la probabilité de 1 a generer:\n\n");
	scanf("%d", &prob);
	
	printf("\n\n");
	
	for (i=0; i <= (nbv); i++){
		result = random1(prob);
		printf("%d ", result);
	}
	
	printf("\n\n");
	
}*/

int random1(int prob)

// prob est un entier compris entre 0 et 100
// Le sous-programme retournera aleatoirement 1 selon la probabilité choisie, sinon il retournera 0

{
	srand(time(NULL) + rand()); //Initialise aléatoirement la fonction rand()
	
	if ( (rand() % 100 + 1) <= prob ){ 	//Tire aleatoirement un entier entre 1 et 100 et le compare a prob
		return 1;													//Si c'est inferieure il renvoie 1
	}
	else{
		return 0;													//Sinon il renvoie 0
	}
}

