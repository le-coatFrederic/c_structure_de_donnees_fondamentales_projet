#include "../include/arbre.h"
#include <stdlib.h>
#include <stdio.h>

int estVideArbre(Arbre A) //fonction de base qui test si le noeud est vide
{
    if(A == NULL)
        return 1;
    else
        return 0;
}

Liste racine(Arbre A) //fonction de base des arbres qui renvoie la racine d'un noeud
{
    return A->nombre;
}

Arbre creerNoeud(Liste valeur) //fonction de base d'un arbre qui creer un noeud en lui allouant la mémoire nécessaire
{
    Arbre A = malloc(sizeof(Arbre)); //allocation de la mémoire
    A->nombre = valeur;
    A->gauche = NULL; //on vient de creer le noeud donc il n'a pas d'enfants
    A->droit = NULL;
    return A;
}

Arbre creerArbreTresGrandNombre() //fonction qui va demander à l'utilisateur d'entrer des nombre et qui va les implémenter dans l'abre
{
    int running = 1; //variable qui permettra de savoir si on continue à insérer des nombres dans l'arbre
    Liste valeur = creerNombreTresGrand(); 
    
    if(estVideListe(valeur) == 1) return NULL; //si on a pas entre de nombre alors on renvoi un pointeur NULL
    Arbre A = creerNoeud(valeur); //on creer un premier noeud

    while(running)
    {
        printf("=====Nouveau Noeud=====\n");
        valeur = creerNombreTresGrand();

        if(estVideListe(valeur) == 0) A = insertionNombreDansAvl(valeur, A); //insertion dans l'avl d'un nouveau nombre
        else running = 0;
    }

    return A;
}

int hauteur(Arbre A) //fonction récursive qui renvoie la hauteur d'un noeud
{
    if(estVideArbre(A) == 1)
        return -1; //quand le noeud est vide (donc enfant d'une feuille) on renvoie -1 
    else
    {
        int hauteurGauche = 1+hauteur(A->gauche); //recursivité non terminale (elle remonte en incrémentant le retour)
        int hauteurDroit = 1+hauteur(A->droit);

        if(hauteurGauche >= hauteurDroit) //retourne la hauteur la plus elevee
            return hauteurGauche;
        else
            return hauteurDroit;
    }
}

int testArbreAvl(Arbre A) //fonction qui permet de tester si un arbre est un AVL ou non (retourne 1 si oui sinon 0)
{
    if(estVideArbre(A))
        return 1;
    else
    {
        int diff = hauteur(A->gauche) - hauteur(A->droit);
        if(diff < -1 || diff > 1)
            return 0;
        else
        {
            int tg = testArbreAvl(A->gauche);
            int td = testArbreAvl(A->droit);
            if(tg == 0 || td == 0)
                return 0;
            else
                return 1;
        }
    }
}

Arbre rotationGauche(Arbre A) //fonction de rotation gauche qui est utile pour les avl
{   
    if(estVideArbre(A) == 0)
    {
        Arbre cpAGauche = A->droit;
        A->droit = cpAGauche->gauche;
        cpAGauche->gauche = A;
        return cpAGauche;
    }
    return NULL;    
}

Arbre rotationDroite(Arbre A) //fonction de rotation droite qui a la même fonction que la précédente mais inversée
{
    if(estVideArbre(A) == 0)
    {
        Arbre cpADroit = A->gauche;
        A->gauche = cpADroit->droit;
        cpADroit->droit = A;
        return cpADroit;
    }
    return NULL;
}

void affichageArbre(Arbre A) //fonction qui permet d'appeler la fonction récursive affiche en lui attribuant une valeur de base (permet de ne pas se tromper de valeur)
{
    affiche(A, 0);
}

void affiche(Arbre A, int i) //fonction qui affiche l'arbre
{
    if(estVideArbre(A) == 0)
    {
        for(int x = 0 ; x < i ; x++)
            printf("---");

        afficherNombreTresGrand(A->nombre);
        printf("\n");
        affiche(A->gauche, i+1);
        affiche(A->droit, i+1);
    }
}

int equilibre(Arbre A) //fonction qui donne l'equilibre d'un noeud (0 = hauteur similaire a gauche et a droite, -x = plus lourd a droite, x plus lourd a gauche)
{
    if(estVideArbre(A) == 1)
        return 0;
    return hauteur(A->gauche) - hauteur(A->droit);
}

Arbre insertionNombreDansAvl(Liste val, Arbre A) //fonction récursive qui va insérer un nombre dans un avl en s'assurant que ses règles soient bien respectées
{
    if(estVideArbre(A) == 1)
        return creerNoeud(val);
    else
        if(plusGrandQue(val, racine(A)) == 1)
            A->droit = insertionNombreDansAvl(val, A->droit);
        else
            A->gauche = insertionNombreDansAvl(val, A->gauche);

        //tests pour la rotation avec les 4 cas possibles
        int eq = equilibre(A);
        if(eq > 1 && plusPetitQue(val, A->gauche->nombre)) //rotation droite
            return rotationDroite(A);

        if(eq < -1 && plusGrandQue(val, A->droit->nombre)) //rotation gauche
            return rotationGauche(A);

        if(eq > 1 && plusGrandQue(val, A->gauche->nombre)) //rotation gauche droite
        {
            A->gauche = rotationGauche(A->gauche);
            return rotationDroite(A);
        }

        if(eq > 1 && plusGrandQue(val, A->droit->nombre)) //rotation gauche droite
        {
            A->droit = rotationDroite(A->droit);
            return rotationGauche(A);
        }

        return A;
}       