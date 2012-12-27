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
	p=CreerP();
	for(i=0; i< TaillePop; ++i){
		p=ajouter_queue_pop(p, InitialiserIndivRecursif( TailleIndiv, prob));
	}
	return p;
}

int RandomN(int max)
{
	srand(time(NULL) + rand());	//Initialise aléatoirement la fonction rand()
	return (rand() % max+1);	//Tire aleatoirement un entier entre 1 et max
}

ListeBit PickIP(Population p, int TaillePop)
{
	int i, n=RandomN(TaillePop);
	i=1;
	while (i<n){
		p=ResteP(p);
		++i;
	}
	return (p->Indiv);
}

void QualiteP(Population P)
{
	Population p=P;
	
	while (VideP(p)==0){
		p->qualite=QualiteI(p->Indiv);
		p=ResteP(p);
	}
}

Population CroiserP(Population p1, int TaillePop, int pCroise)
{
	int j, i=1;
	Population p2=CreerP(), tamp1=CreerP(), tamp2=CreerP();
	while (i<=TaillePop){
		p2=ajouter_queue_pop (p2, PickIP(p1, TaillePop));
		p2=ajouter_queue_pop (p2, PickIP(p1, TaillePop));
		tamp1=p2;
		tamp2=p2;
		tamp1=Avant_Dernier_Pop(p2);
		tamp2=Dernier_Pop(p2);
		CroiseI(tamp1->Indiv, tamp2->Indiv, pCroise);
		++i;
		++i;
	}
	QualiteP(p2);
	return p2;
}

void RecopierP(Population p2, Population p1, int nbindiv)
{
	if (nbindiv==0){
	}
	else{
		p2=ajouter_queue_pop(p2, p1->Indiv); 
		RecopierP(p2, ResteP(p1), --nbindiv);
	}
}

Population SelectP(Population p, int tSelect, int TaillePop)
{
	Population tamp=p, p2=p;
	
	int i=1;
	while (i<tSelect){
		tamp=ResteP(tamp);
		++i;
	}
	tamp->suivant=NULL;
	RecopierP(tamp, p, (TaillePop-tSelect));
	return p;
}


// Premiere version de CroiserP, a conserver comme reference pour resoudre le probleme de
// croisement avec soi-meme
/*Population CroiserP(Population p1, int TaillePop, int pCroise)
{
	int i=1;
	Population p2=CreerP(), tampon=CreerP();
	ListeBit l1=CreerI(), l2=CreerI();
	
	while (i<=(TaillePop/2)){
		l1=PickIP(p1, TaillePop);
		PrintListQualite(l1);printf("\n");
		l2=PickIP(p1, TaillePop);
		while(l1==l2){
			l2=PickIP(p1, TaillePop);
		}
		PrintListQualite(l2);printf("\n");
		CroiseI(l1, l2, pCroise);
		printf("->");PrintListQualite(l1);printf("\n");
		printf("->");PrintListQualite(l2);printf("\n");printf("\n");
		p2=ajouter_queue_pop (p2, l1);
		p2=ajouter_queue_pop (p2, l2);
		++i;
	}
	return p2;
}*/
