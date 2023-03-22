// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)

#include "pile.h"
#include "file.h"

#define passerAuPremierFils(adrP, E) empiler(adrP, E)
#define remonterAuPere(adrP, element) depiler(adrP, element)
#define passerAuFrereSuivant(adrP, adrE) depiler(adrP, adrE), empiler(adrP, 1 + (*adrE))
#define naPlusDeFrere(adrP, TailleChaine) sommet(adrP) == TailleChaine
#define noeudTerminal(adrP, TailleChaine) hauteur(adrP) == TailleChaine
#define rechercheTerminee(adrP) pilevide(adrP)

void testPile(T_Pile *pile);
void testFile(T_File *file);
int menu_pile();
int menu_file();
int pileValide(T_Pile *adrP);
void permut(T_Pile *pile, char *chaine);
//void echec(T_Pile *pile, int taille);
//int pileValideEchec(T_Pile *adrP);



int menu()
{

	int choix;
	printf("\n\n\n SDA1 TP9");
	printf("\n\n\n 1 : tester mon fichier pile.c");
	printf("\n 2 : tester mon fichier file.c");
	printf("\n 3 : afficher et compter les permutations d'une chaine");
	printf("\n 4 : afficher et compter les solutions pour un échiquier ");
	printf("\n 0 :  QUITTER  ");
	printf("\n votre choix ?  ");
	scanf("%d", &choix);
	return choix;
}

int main()
{
	T_File mafile;
	T_Pile mapile;
	initFile(&mafile);
	initPile(&mapile);
	int chx;
	// int taille;
	// char chaine[20];

	do
	{
		chx = menu();
		switch (chx)
		{
		case 1:
			// testez toutes vos fonctions par un jeu de test de votre choix
			testPile(&mapile); // TP9 partie 1 : à ecrire
			break;
		case 2:				   // testez toutes vos fonctions par un jeu de test de votre choix
			testFile(&mafile); // TP9 partie 1 : à ecrire
			break;
		case 3:
			char chaine[MAX];
			printf("\nTapez la chaine : ");
			scanf("%s", chaine);	 // une chaine de longueur <=MAX
			permut(&mapile, chaine); // TP9 partie 2: ecrire permut
			break;
		case 4:
			//int taille;
			//printf("\nTapez la taille : ");
			//scanf("%d",&taille);//taille echiquier <=MAX
			//echec(&mapile,taille); //TP9 partie 3: ecrire echiquier
			break;
		}
	} while (chx != 0);

	printf("\nau plaisir de vous revoir ...\n");
	return 0;
}

int menu_pile()
{

	int choix;
	printf("\n\n\n 1 : initialiser/réinitialiser la pile");
	printf("\n 2 : ajouter un élément à la pile");
	printf("\n 3 : retirer un élément à la pile et l'afficher");
	printf("\n 4 : afficher la hauteur et le sommet de la pile");
	printf("\n 5 : Afficher la pile");
	printf("\n 0 :  QUITTER  ");
	printf("\n votre choix ?  ");
	scanf("%d", &choix);
	return choix;
}

int menu_file()
{

	int choix;
	printf("\n\n\n 1 : initialiser/réinitialiser la file");
	printf("\n 2 : ajouter un élément à la file");
	printf("\n 3 : retirer un élément à la file et l'afficher");
	printf("\n 4 : Afficher la file");
	printf("\n 0 :  QUITTER  ");
	printf("\n votre choix ?  ");
	scanf("%d", &choix);
	return choix;
}

void testPile(T_Pile *pile)
{
	int ch;

	do
	{
		T_Elt element;
		ch = menu_pile();
		switch (ch)
		{
		case 1:
			initPile(pile);
			break;
		case 2: // testez toutes vos fonctions par un jeu de test de votre choix
			printf("\nQuel element voulez-vous ajouter ? ");
			saisirElt(&element);
			empiler(pile, element);
			break;
		case 3:
			int flag = depiler(pile, &element);
			if (flag)
				afficherElt(&element);
			else
				printf("\nPile vide\n");
			break;
		case 4:
			if (pilevide(pile))
			{
				printf("\nPile vide\n");
				break;
			}
			printf("\nHauteur = \n%d   \nSommet =  ",hauteur(pile));
			T_Elt sm = sommet(pile);
			afficherElt(&sm);
			break;
		case 5:
			afficherPile(pile);
		}
	} while (ch != 0);

	printf("\nFin du test de pile\n");
}

void testFile(T_File *file)
{
	int ch;

	do
	{
		T_Elt element;
		ch = menu_file();
		switch (ch)
		{
		case 1:
			initFile(file);
			break;
		case 2: // testez toutes vos fonctions par un jeu de test de votre choix
			printf("\nQuel element voulez-vous ajouter ? ");
			saisirElt(&element);
			ajouter(file, &element);
			break;
		case 3:
			int flag = retirer(file, &element);
			if (flag)
				afficherElt(&element);
			else
				printf("\nFile vide\n");
			break;
		case 4:
			afficherFile(file);
		}
	} while (ch != 0);

	printf("\nFin du test de file\n");
}

int pileValide(T_Pile *adrP)
{
	int longueur = hauteur(adrP);
	for (int i = 0; i < longueur; i++)
	{
		for (int j = i + 1; j < longueur; j++)
		{
			if (adrP->Elts[i] == adrP->Elts[j])
				return 0;
		}
	}
	return (longueur != 0);
}

void permut(T_Pile *pile, char *chaine)
{
	int longueur = strlen(chaine);
	int e = 0;
	initPile(pile);
	int flag = 0;
	e++;
	printf("\n");
	passerAuPremierFils(pile, 1);
	while (!rechercheTerminee(pile))
	{
		while (pileValide(pile))
		{
			if (noeudTerminal(pile, longueur))
			{
				for (int i = 0; i <= longueur - 1; i++){
					printf("%c", chaine[pile->Elts[i]-1]);
				}
				flag ++;
				printf("\n");
				break;
			}
			else
			{
				passerAuPremierFils(pile, 1);
			}
		}
		while (!rechercheTerminee(pile) && naPlusDeFrere(pile, longueur))
		{
			remonterAuPere(pile, &e);
		}
		if (!rechercheTerminee(pile))
		{
			passerAuFrereSuivant(pile, &e);
			e++;
		}
	}
	printf("\nIl y a %d permutations.\n", flag);
}

/*
void echec(T_Pile *pile, int taille){
	initPile(pile);
	int longueur = taille;
	int e = 0;
	int niv = 0;
	e++;
	int tab[taille];
	passerAuPremierFils(pile, 1);
	tab[niv] = 1; 
	while (!(niv == 4 && pileValideEchec(pile)))
	{
		while (pileValideEchec(pile))
		{
			if (noeudTerminal(pile, longueur))
			{
				break;
			}
			else{
				passerAuPremierFils(pile, 1);
				niv++;
				e ++;
			}
		}
		while (!(niv == 4 && pileValideEchec(pile)) && naPlusDeFrere(pile, longueur))
		{
			remonterAuPere(pile, &e);
			niv--;
			tab[niv] = 1; 
		}
		if (!(niv == 4 && pileValideEchec(pile)))
		{
			passerAuFrereSuivant(pile, &e);
			tab[niv] = tab[niv] + 1;
			e++;
		}
	}
	printf("\n");
	for (int i = 0; i < taille; i++)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
}


int pileValideEchec(T_Pile *adrP)
{
	int longueur = hauteur(adrP);
	for (int i = 0; i < longueur; i++)
	{
		for (int j = i + 1; j < longueur; j++)
		{
			if (adrP->Elts[i] == adrP->Elts[j]
				|| adrP->Elts[i] == adrP->Elts[j] + 1
				|| adrP->Elts[i] == adrP->Elts[j] - 1)
				return 0;
		}

	}
	return (longueur != 0);
}
*/