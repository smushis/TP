#include <stdio.h>
#include <stdlib.h>
#include "coureur.h"
#include <string.h>

struct coureur* Creer_Coureur(void)
{
	struct coureur* runner = malloc(sizeof(struct coureur));

	printf("Quel est le nom du coureur ?");
	scanf("%s",runner->nom);

	printf("Quel est le prenom du coureur ?");
	scanf("%s",runner->prenom);

	printf("Quel est le dossard du coureur ?");
	scanf("%d",&(runner->dossard));

	printf("Quel est l'equipe du coureur ?");
	scanf("%s",runner->equipe);

	printf("Quel est le temps cumule du coureur ? (en s)");
	scanf("%d",&(runner->temps));

	return runner;
}

struct coureur* Creer_Coureur_Auto(char* nom, char* prenom, int dossard, char* equipe,int temps)
{
	struct coureur* runner = malloc(sizeof(struct coureur));
	strcpy(runner->nom,nom);
	strcpy(runner->prenom,prenom);
	strcpy(runner->equipe, equipe);
	runner->dossard = dossard;
	runner->temps = temps;
	return runner;
}

void Ajouter_Temps(struct coureur* runner)
{
	int tmp = 0;
	printf("Quel est le temps de l'etape d'aujourd'hui du coureur? (en s)");
	scanf("%d",&tmp);
	runner->temps = (runner->temps)+tmp; 

}

void Afficher_Coureur(struct coureur* runner)
{
	int h,m,s,r = 0;
	h = runner->temps/3600;
	r = runner->temps%3600;
	m = r/60;
	s = r%60;


	printf("Nom: %s\n",runner->nom);
	printf("Prenom: %s",runner->prenom);
	printf("Dossard: %d\n",runner->dossard);
	printf("Equipe: %s",runner->equipe);
	printf("Temps: %d Heures, %d Minutes et %d Secondes\n\n",h,m,s);
}
