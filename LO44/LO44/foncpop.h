#include "population.h"

/***********************************/
/*      Fonctions Population       */
/***********************************/

Population InitPopRecur(Population p, int TaillePop, int TailleIndiv, int prob)
{
	if(TaillePop == 0){
		return p=NULL;
	}
	else{
	return (ajouter_queue_pop(InitPopRecur( p, --TaillePop, TailleIndiv, prob), InitialiserIndivRecursif( TailleIndiv, prob)));
	}
}

Population InitPopIter(Population p, int TaillePop, int TailleIndiv, int prob)
{
	int i, j;
	p=NULL;
	for(i=0; i<= TaillePop; ++i){
		p=ajouter_queue_pop(p, InitialiserIndivRecursif( TailleIndiv, prob));
	}
	return p;
}

