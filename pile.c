#include "pile.h"



void initPile( T_Pile * P)
{
    int zero = 0;
    affecterElt(&P->nbElts, &zero);

}


int pilepleine(const  T_Pile *P)
{
    return (P->nbElts == MAX);
}



int pilevide(const  T_Pile *P)
{
    return (P->nbElts == 0);
}



int empiler( T_Pile *P, T_Elt e) //renvoie 0 si pile pleine, sinon 1
{
    if (pilepleine(P))
        return 0;
    affecterElt(&(P->Elts[P->nbElts]) , &e);
    P->nbElts = P->nbElts + 1;
    return 1;
}



int depiler( T_Pile *P, T_Elt *pelt)  //renvoie 0 si pile vide, sinon 1
{
    if (pilevide(P))
        return 0;
    P->nbElts = P->nbElts - 1;
    affecterElt(pelt ,&(P->Elts[P->nbElts]));       
    return 1;
}



T_Elt sommet(const  T_Pile *P)
{
    if (pilevide(P))
        return -1;
    return P->Elts[P->nbElts - 1];
}



int hauteur(const  T_Pile *P)
{
return P->nbElts;
}


void afficherPile(  T_Pile *P)
{
    if (pilevide(P))
        printf("\nPile vide\n");
    for (int i = P->nbElts - 1; i >= 0; i--)
        afficherElt(&(P->Elts[i]));
    printf("\n");
}








