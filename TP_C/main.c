#include <stdio.h>
#include <stdlib.h>
#include "coureur.h"
#include "liste.h"
#include <string.h>
#include <time.h>

int main()
{
	struct liste L;
	FILE * fiche; 
	int nb_etapes;
	int nb_equipe;
	char str_nb_etapes[3];
	char str_nb_equipe[3];
	int i,j;
	char equipe[30];
	char donnees [60];

	char str_dossard[3];
	char str_nom[20];
	char str_prenom[20];
	char* pch;
	int dossard = 0;

	int k;
	int temps_rdm =0;
	int rdm = 0;
	struct coureur* runner;
	/*struct coureur* runner1;
	struct coureur* runner2;
	struct coureur* runner3;
	struct coureur* runner4;

	runner1 = Creer_Coureur();
	Ajouter_Temps(runner1);
	Afficher_Coureur(runner1);

	runner2 = Creer_Coureur();
	Ajouter_Temps(runner2);
	Afficher_Coureur(runner2);

	runner3 = Creer_Coureur();
	Ajouter_Temps(runner3);
	Afficher_Coureur(runner3);

	runner4 = Creer_Coureur();
	Ajouter_Temps(runner4);
	Afficher_Coureur(runner4);*/

	srand(time(NULL));

	Initialiser(&L);
	fiche = fopen("liste_coureur","r");

	fgets(str_nb_etapes,5,fiche);
	nb_etapes = atoi(str_nb_etapes);

	fgets(str_nb_equipe,5,fiche);
	nb_equipe = atoi(str_nb_equipe);

	printf("nb equipe : %d\n",nb_equipe);
	printf("nb etapes : %d\n",nb_etapes);

	for(i=0;i<nb_equipe;i++)
	{
		fgets(equipe,30,fiche);
		for(j=0;j<5;j++)
		{
			temps_rdm =0;
			fgets(donnees,61,fiche);
			pch = strtok(donnees,",");
			strcpy(str_dossard,pch);
			dossard = atoi(str_dossard);

			pch = strtok(NULL,",");
			strcpy(str_nom,pch);

			pch = strtok(NULL,",");
			strcpy(str_prenom,pch);

			for(k=0;k<nb_etapes;k++)
			{
				temps_rdm += rand() % 3000+10800;
			}
			runner = Creer_Coureur_Auto(str_nom,str_prenom,dossard,equipe,temps_rdm);
			Enfiler(&L,runner);
			
		}
	}
	fclose(fiche);

	L.courant = L.premier;
	for(i=0;i<5*22;i++)
	{
		rdm = rand() % 10;
		if(rdm ==5)
		{
			printf("Le coureur %s est dope\n",L.courant->runner->nom);
			Effacer(&L,L.courant->runner);
		}
		L.courant = L.courant->suivant;
	}
	Trie(&L);
	//Afficher_Liste(&L);



	/*Enfiler(&L,runner1);
	Enfiler(&L,runner2);
	Enfiler(&L,runner3);
	Enfiler(&L,runner4);*/

	//Effacer(&L,runner2);
	//Trie(&L);
	//Afficher_Liste(&L);
	/*Aller_Debut(&L);	
	Afficher_Coureur(L.courant->runner);

	Avancer(&L);
	Afficher_Coureur(L.courant->runner);

	if(Fin(&L) ==0)
	{
		printf("Fin\n");
	}*/
	return 0;
}
