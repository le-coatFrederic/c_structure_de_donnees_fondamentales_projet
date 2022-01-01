#ifndef __ARBRE__H__
#define __ARBRE__H__

#include "liste.h"

typedef struct Noeud
{
    Liste nombre;
    struct Noeud *gauche;
    struct Noeud *droit;
}*Arbre;

int estVideArbre(Arbre A);
Liste racine(Arbre A);
Arbre creerNoeud(Liste valeur, Arbre A);
void affichageArbre(Arbre A);
void a(Arbre A, int i);
Arbre creerArbreTresGrandNombre();
int hauteur(Arbre A);
int testArbreAvl(Arbre A);

#endif