#ifndef _coureur_h
#define _coureur_h

struct coureur {
	char nom[20];
	char prenom[20];
	int dossard;
	char equipe[30];
	int temps;
};

struct coureur* Creer_Coureur(void);
struct coureur* Creer_Coureur_Auto(char*, char*, int, char*, int);
void Ajouter_Temps(struct coureur*);
void Afficher_Coureur(struct coureur*);



#endif
