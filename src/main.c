#include "../include/liste.h"
#include "../include/arbre.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    Arbre A = creerArbreTresGrandNombre();
    if(testArbreAvl(A) == 1)
        printf("Ceci est un AVL !\n");
    else
        printf("Ce n'est pas un AVL !\n");
    return 0;
}