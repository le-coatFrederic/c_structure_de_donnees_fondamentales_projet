#include "../include/liste.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    Liste p = creerNombreTresGrand();
    Liste p2 = creerNombreTresGrand();

    printf("Premier nombre : ");
    afficherNombreTresGrand(p);
    printf("Deuxieme nombre : ");
    afficherNombreTresGrand(p2);

    Liste pGrande = compareDeuxNombreTresGrand(p, p2);
    printf("Le nombre le plus grand est : ");
    afficherNombreTresGrand(pGrande);

    return 0;
}