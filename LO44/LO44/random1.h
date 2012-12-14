#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*void main (void)
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
		printf("%d ", result);
	}
	
	printf("\n\n");
	
}*/

int random1(int prob)

// prob est un entier compris entre 0 et 100
// Le sous-programme retournera al�atoirement 1 selon la probabilit� choisie, sinon il retournera 0

{
	srand(time(NULL) + rand()); //Initialise al�atoirement la fonction rand()
	
	if ( (rand() % 100 + 1) <= prob ){ 	//Tire al�atoirement un entier entre 1 et 100 et le compare � prob
		return 1;													//Si c'est inf�rieure il renvoie 1
	}
	else{
		return 0;													//Sinon il renvoie 0
	}
}
