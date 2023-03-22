// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)

#include "pile.h"
#include "file.h"

void testPile(T_Pile *pile);
void testFile(T_File *file);
int menu_pile();
int menu_file();



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
			testPile(&mapile); //TP9 partie 1 : à ecrire
			break;
		case 2: // testez toutes vos fonctions par un jeu de test de votre choix
			testFile(&mafile); //TP9 partie 1 : à ecrire
			break;
		case 3:
			// scanf("%s",chaine); //une chaine de longueur <=MAX
			// permut(&mapile,chaine); //TP9 partie 2: ecrire permut
			break;
		case 4:
			// scanf("%d",&taille);//taille echiquier <=MAX
			// echiquier(&mapile,taille); //TP9 partie 3: ecrire echiquier
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
			if (pilevide(pile)){
				printf("\nPile vide\n");
				break;
			}
			printf("\nHauteur = \n%d   \nSommet =  ", hauteur(pile));
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
