#ifndef __ARBRE__H__
#define __ARBRE__H__

#include "liste.h"

typedef struct Noeud //structure d'un noeud
{
    Liste nombre;
    struct Noeud *gauche;
    struct Noeud *droit;
}*Arbre;

int estVideArbre(Arbre A);
Liste racine(Arbre A);
Arbre creerNoeud(Liste valeur);
void affichageArbre(Arbre A);
void affiche(Arbre A, int i);
Arbre creerArbreTresGrandNombre();
int hauteur(Arbre A);
int testArbreAvl(Arbre A);
Arbre rotationGauche(Arbre A);
Arbre rotationDroite(Arbre A);
Arbre doubleRotationDroiteGauche(Arbre A);
Arbre doubleRotationGaucheDroite(Arbre A);
Arbre insertionNombreDansAvl(Liste val, Arbre A);

#endif