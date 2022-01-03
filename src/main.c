#include "../include/liste.h"
#include "../include/arbre.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    Arbre A = creerArbreTresGrandNombre();
    affichageArbre(A);

    return 0;
}