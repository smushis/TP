#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coureur.h"
#include "liste.h"

int Initialiser(struct liste* liste1)
{
	liste1->premier=NULL;
	liste1->dernier=NULL;
	return 0;
}

int Vide(struct liste* liste1)
{
	return (liste1->premier==NULL);
}

int Enfiler(struct liste* liste1, struct coureur* runner)
{
	struct cellule* aux;

	if (Vide(liste1))
	{
		liste1->dernier=(struct cellule *)malloc(sizeof(struct cellule));
		liste1->dernier->runner = runner;
		liste1->dernier->suivant = NULL;
		liste1->courant = liste1->dernier;
		liste1->premier=liste1->dernier;
	}
	else
	{
		aux=liste1->dernier;
		liste1->dernier=(struct cellule *)malloc(sizeof(struct cellule));
		liste1->dernier->runner = runner;
		liste1->dernier->suivant = NULL;
		aux->suivant = liste1->dernier;
		liste1->courant = liste1->dernier;
	}
	return 0;
}

int Aller_Debut(struct liste* liste1)
{
	int res;
	if(Vide(liste1))
	{
		res = -1;
	}
	else {
		liste1->courant = liste1->premier; 
		res = 0;
	}
	return res;
}

int Fin(struct liste* liste1)
{
	int res;
	if(Vide(liste1))
	{
		res = -1;
	}
	else {
		if(liste1->courant == liste1->dernier)
		{
			res = 0;
		}
		else res = -1;
	}
	return res;
}

int Avancer(struct liste* liste1)
{
	int res;
	if(Vide(liste1))
	{
	res = -1;
	}
	else {
		liste1->courant = liste1->courant->suivant;
		res = 0;
	}
	return res;	

}

int Coureur_Courant(struct liste* liste1, struct coureur* runner)
{
	int res;
	if(Vide(liste1))
	{
	res = -1;
	}
	else {
		runner=liste1->courant->runner;
		res = 0;
	}
	return res;	
	
}

int Effacer(struct liste* liste1, struct coureur* runner)
{
	int res;
	struct cellule* aux;
	struct cellule* previous;
	if(Vide(liste1))
	{
	res = -1;
	}
	else 
	{
		previous = liste1->premier;
		if(previous->runner == runner)
		{
			liste1->courant = previous->suivant;
			free(previous);
			res = 0;
			return res;
		}
		aux = previous->suivant;
		while(aux !=NULL)
		{
			if(aux->runner == runner)
			{
				previous->suivant = aux->suivant;
				liste1->courant = aux->suivant;
				free(aux);
				res = 0;
				return res;
			}
			else
			{
				previous = aux;
				aux = aux->suivant;
			}
		}
	}
	return res;	
	
}

void Afficher_Liste(struct liste* liste1)
{
	int nb = 0;
	int n = nb_elements(liste1);
	struct cellule* aux = liste1->premier;
	while(nb<n)
	{
		Afficher_Coureur(aux->runner);
		aux = aux->suivant;
		nb++;
	}
}

int nb_elements(struct liste* liste1)
{
	struct cellule* aux = liste1->premier;
	int nb = 0;
	if(!Vide(liste1))
	{
		do{
			nb++;
			aux = aux->suivant;
		}while(aux != NULL);
	}
	return nb;
}

void Trie(struct liste* liste1)
{
	int j,i =0;
	int n = nb_elements(liste1); 
	struct cellule* ptr1; 
	liste1->courant = liste1->premier;
	for(i=0;i<n-1;i++)
	{
		ptr1 = liste1->courant->suivant;
		for(j=1;j<n-i;j++)
		{
			if(liste1->courant->runner->temps > ptr1->runner->temps)
			{
				swapi(liste1->courant,ptr1);
			}
			ptr1 = ptr1->suivant;
		}
		liste1->courant = liste1->courant->suivant;
	}
}

void swapi(struct cellule* a,struct cellule* b)
{
	char nom [20];
	char prenom [20];
	int dossard;
	char equipe[30];
	int temps;

	temps = a->runner->temps;
	strcpy(nom,a->runner->nom);
	strcpy(prenom,a->runner->prenom);
	strcpy(equipe,a->runner->equipe);
	dossard = a->runner->dossard;

	a->runner->temps = b->runner->temps;
	strcpy(a->runner->nom,b->runner->nom);
	strcpy(a->runner->prenom,b->runner->prenom);
	strcpy(a->runner->equipe,b->runner->equipe);
	a->runner->dossard = b->runner->dossard;

	b->runner->temps = temps;
	strcpy(b->runner->nom,nom);
	strcpy(b->runner->prenom,prenom);
	strcpy(b->runner->equipe,equipe);
	b->runner->dossard = dossard;

}






