#ifndef _liste_h
#define _liste_h

#include "coureur.h"

struct cellule{
	struct coureur * runner;
	struct cellule * suivant;

};
	

struct liste{
	struct cellule * premier;
	struct cellule * dernier;
	struct cellule * courant;
	
};

int Initialiser(struct liste*);
int Enfiler(struct liste*, struct coureur*);
int Aller_Debut(struct liste*);
int Fin(struct liste* );
int Avancer(struct liste*);
int Coureur_Courant(struct liste*, struct coureur*);
int Effacer(struct liste*, struct coureur*);
void Afficher_Liste(struct liste*);
int nb_elements(struct liste*);
void Trie(struct liste*);
void swapi(struct cellule*, struct cellule*);


#endif
