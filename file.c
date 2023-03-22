#include "file.h" 


void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
    ptrF->Queue = -1;
    ptrF->Tete = -1;
}

int  retirer(T_File *ptrF,T_Elt *ptrE) //si pas vide, en tete de file
{
    if (fileVide(ptrF)){
        printf("\nPile vide");
        return 0;
    }
    if (ptrF->Queue == ptrF->Tete){
        affecterElt(ptrE, &(ptrF->Elts[ptrF->Queue]));
        initFile(ptrF);
    }
    else if (ptrF->Tete == MAX - 1){
        ptrF->Tete = 0;
        affecterElt(ptrE, &(ptrF->Elts[MAX - 1]));
    }
    else{
        ptrF->Tete = ptrF->Tete + 1;
        affecterElt(ptrE, &(ptrF->Elts[ptrF->Tete - 1]));
    }
    return 1;
}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
    if (filePleine(ptrF)){
        printf("\nPile pleine");
        return 0;
    }
    if (fileVide(ptrF)){
        ptrF->Tete = 0;
        ptrF->Queue = 0;
        affecterElt(&(ptrF->Elts[ptrF->Queue]), ptrE);
    }
    else if (ptrF->Queue == MAX - 1){
        affecterElt(&(ptrF->Queue), 0);
        affecterElt(&(ptrF->Elts[ptrF->Queue]), ptrE);
    }
    else{
        ptrF->Queue = ptrF->Queue + 1;
        affecterElt(&(ptrF->Elts[ptrF->Queue]), ptrE);
    }
    return 1;
} 

int fileVide(const  T_File *ptrF) // qd Tete == 0 
{
    return (ptrF->Queue == -1 && ptrF->Tete == -1);
}

int filePleine(const  T_File *ptrF) // qd MAX elts dans la file 
{
    int queue = ptrF->Queue;
    int tete = ptrF->Tete;
    if (queue > tete)
        return (queue - tete + 1 == MAX);
    else if (tete > queue)
        return (tete - queue == 1);
    else
        return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
    return ptrF->Elts[ptrF->Tete];
}

void afficherFile(T_File *ptrF)
{
    int queue = ptrF->Queue;
    int tete = ptrF->Tete;
    if (fileVide(ptrF))
        printf("\nFile vide\n");
    else if (queue > tete){
        int longueur = queue - tete + 1;
        for (int i = 0; i < longueur; i++)
            afficherElt(&(ptrF->Elts[i]));
    }
    else if (queue < tete){
        for (int i = tete; i < MAX; i++)
            afficherElt(&(ptrF->Elts[i]));
        for (int i = 0; i < queue; i++)
            afficherElt(&(ptrF->Elts[i]));
    }
    else {
        afficherElt(&(ptrF->Elts[queue]));
    }
    printf("\n");
}






