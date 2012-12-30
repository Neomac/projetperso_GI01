#include "population.h"

/***********************************/
/*      Fonctions Population       */
/***********************************/

/* Cree et remplie une liste d'individus */
/* p: population a remplir; TaillePop: nombre d'individus souhaites dans la population; */
/* LongIndiv: nombre de bits de chaque individu; prob: probabilite d'avoir des bits de valeur egale a 1 */
/* Algorithme recursif */
Population InitPopRecur(Population p, int TaillePop, int LongIndiv, int prob)
{
	if(TaillePop == 0){	/* TaillePop sert egalement de compteur pour savoir combien d'individus il reste a ajouter */
		return p=NULL;		/* Une fois tous les individus ajoutes on marque la fin de la liste */
	}
	else{	/* Sinon on ajoute en fin de liste un individu cree aleatoirement */
	return (ajouter_queue_pop(InitPopRecur( p, --TaillePop, LongIndiv, prob), InitialiserIndivRecursif(LongIndiv, prob), LongIndiv));
	}
}

/* Cree et remplie une liste d'individus */
/* p: population a remplir; TaillePop: nombre d'individus souhaites dans la population; */
/* LongIndiv: nombre de bits de chaque individu; prob: probabilite d'avoir des bits de valeur egale a 1 */
/* Algorithme iteratif */
Population InitPopIter(Population p, int TaillePop, int LongIndiv, int prob)
{
	int i, j;
	p=CreerP();
	for(i=0; i< TaillePop; ++i){ /* TaillePop sert egalement de compteur pour savoir combien d'individus il reste a ajouter */
		/* On ajoute en fin de liste un individu cree aleatoirement */
		p=ajouter_queue_pop(p, InitialiserIndivRecursif( LongIndiv, prob), LongIndiv);
	}
	return p;
}

/* Renvoie un entier choisie aleatoirement entre 1 et l'entier max */
int RandomN(int max)
{
	srand(time(NULL) + rand());	//Initialise aléatoirement la fonction rand()
	return (rand() % max+1);	//Tire aleatoirement un entier entre 1 et max
}

/* Choisie aleatoirement et renvoie un individu d'une population */
ListeBit PickIP(Population p, int TaillePop)
{
	int i, n=RandomN(TaillePop); /* On initialise aleatoirement un entier compris entre 1 le nombre d'individus */
	i=1;
	while (i<n){ /* On parcourt la liste jusqu'a etre a l'individu dont la position dans la liste correspond a 'n' */
		p=ResteP(p);
		++i;
	}
	return (p->Indiv); /* On retourne cet individu */
}

/* Calcule les qualites de tous les individus d'une population */
void QualiteP(Population P, int LongIndiv)
{
	Population p=P;
	
	while (VideP(p)==0){ /* On parcourt la liste et calcul la qualite de chaque individu au fur et a mesure */
		p->qualite=QualiteI(p->Indiv, LongIndiv);
		p=ResteP(p);
	}
}

/* Recopie et croisment d'individus d'une population 'p1' pour creer une nouvelle population p2 */
Population CroiserP(Population p1, int TaillePop, int pCroise, int LongIndiv)
{
	int i=1;
	
	/* Initialisation de la population cible 'p2' et des 2 populations tampons 'tamp1' et 'tamp2' */
	Population p2=CreerP(), tamp1=CreerP(), tamp2=CreerP();
	
	/* Boucle choisissant 2 individus de 'p1', les recopiant dans 'p2' et les croisants */
	while (i<=TaillePop){
		
		/* Choix aleatoire de 2 individus de 'p1' et leur recopie a la fin 'p2' */
		p2=ajouter_queue_pop (p2, PickIP(p1, TaillePop), LongIndiv);
		p2=ajouter_queue_pop (p2, PickIP(p1, TaillePop), LongIndiv);
		
		/* Parcourt de p2 avec 'tamp1' et 'tamp2' pour recuperer les 2 individus ajoutes */
		tamp1=p2;
		tamp2=p2;
		tamp1=Avant_Dernier_Pop(p2);
		tamp2=Dernier_Pop(p2);
		
		/* Croisement des 2 individus ajoutes */
		CroiseI(tamp1->Indiv, tamp2->Indiv, pCroise);
		
		/* Double incrementation car on rajoute 2 individus a chaque boucle et non pas une seul*/
		++i;
		++i;
	}
	
	/* Recalcul des qualites des individus de 'p2' car elles sont initialement calculees lorsque les individus */
	/* sont ajoutes a 'p2', or les croiser apres modifie leur qualite */
	QualiteP(p2, LongIndiv);
	
	/* Renvoie de 'p2' */
	return p2;
}

/* Recopie un nombre 'nbindiv' d'individus de la liste d'individus 'p1' dans a la fin de celle 'p2' */
/* Algorithme recursif */
void RecopierP(Population p2, Population p1, int nbindiv, int LongIndiv)
{
	if (nbindiv==0){ /* Il n'y a plus d'individus a recopier, le sous-programme s'arrete */
	}
	else{
		p2=ajouter_queue_pop(p2, p1->Indiv, LongIndiv);	/* Recopie de l'individu de tete de 'p1' a la fin de 'p2'*/
		RecopierP(p2, ResteP(p1), --nbindiv, LongIndiv);	/* Appel recursif de la sous-fonction avec l'individu suivant de 'p1' et 1 individu de moins a recopier */
	}
}

/* Tronque et recopie en fin de liste les 'tSelect' premiers individus d'une liste d'individus de taille 'TaillePop'*/
Population SelectP(Population p, int tSelect, int taillePop, int LongIndiv)
{
	tSelect=(taillePop*tSelect)/100; /* Passage de tSelect d'un pourcentage a un entier relatif a taillePop */
	
	Population tamp=p; /* Initialisation d'un pointeur de parcourt */
	int i=1;
	
	/* Parcourt des 'tSelect' premiers individus de la liste */
	while (i<tSelect){
		tamp=ResteP(tamp);
		++i;
	}
	tamp->suivant=NULL; /* Troncature de la liste */
	
	/* Recopie des 'tSelect' premiers individus autant de fois que necessaire pour remplir la population */
	for(i=1; i<(taillePop/tSelect); ++i){
		RecopierP(tamp, p, tSelect, LongIndiv);
	}
	
	/* Dernier appel a la fonction RecopierP au cas ou 'tSelect' ne soit pas un multiple de 'TaillePop' */
	/* et ainsi finir de remplir p*/
	RecopierP(tamp, p, (taillePop-i*tSelect), LongIndiv);
	
	/* Renvoie de la liste */
	return p;
}

