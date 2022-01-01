#include "../include/arbre.h"
#include <stdlib.h>
#include <stdio.h>

int estVideArbre(Arbre A)
{
    if(A == NULL)
        return 1;
    else
        return 0;
}

Liste racine(Arbre A)
{
    return A->nombre;
}

Arbre creerNoeud(Liste valeur, Arbre A)
{
    if(estVideArbre(A))
    {
        Arbre cpA = malloc(sizeof(Arbre));
        cpA->nombre = valeur;
        cpA->gauche = NULL;
        cpA->droit = NULL;
        return cpA;
    }
    else
    {
        if(plusGrandOuEgalQue(valeur, racine(A)) == 1)
        {
            A->droit = creerNoeud(valeur, A->droit);
            return A;
        }
        else
        {
            A->gauche = creerNoeud(valeur, A->gauche);
            return A;
        }
    }
}

/*void affichageArbre(Arbre A)
{
    if(estVideArbre(A) == 0)
    {
        afficherNombreTresGrand(racine(A));
        affichageArbre(A->gauche);
        affichageArbre(A->droit);
    }
}*/

void affichageArbre(Arbre A)
{
    a(A, 0);
}

void a(Arbre A, int i)
{
    if(estVideArbre(A) == 0)
    {
        printf("hauteur %d : ", i);
        afficherNombreTresGrand(racine(A));
        i++;
        a(A->gauche, i);
        a(A->droit, i);
    }
}

Arbre creerArbreTresGrandNombre()
{
    int choix = 1;
    Arbre A = creerNoeud(creerNombreTresGrand(), NULL);
    printf("Continuer ? (1 pour oui, 0 pour non) ");
    scanf("%d", &choix);

    while(choix == 1)
    {
        printf("=====Nouveau Noeud=====\n");
        A = creerNoeud(creerNombreTresGrand(), A);
        printf("Continuer ? (1 pour oui, 0 pour non) ");
        scanf("%d", &choix);
    }

    return A;
}

int hauteur(Arbre A)
{
    if(estVideArbre(A) == 1)
        return -1;
    else
    {
        int hauteurGauche = 1+hauteur(A->gauche);
        int hauteurDroit = 1+hauteur(A->droit);

        printf("Je ne suis pas une erreur : %d %d\n", hauteurGauche, hauteurDroit);

        if(hauteurGauche >= hauteurDroit)
            return hauteurGauche;
        else
            return hauteurDroit;
    }
}

int testArbreAvl(Arbre A)
{
    if(estVideArbre(A) == 1)
        return 1;
    else
    {
        int hg = hauteur(A->gauche);
        int hd = hauteur(A->droit);
        if()
    }
}