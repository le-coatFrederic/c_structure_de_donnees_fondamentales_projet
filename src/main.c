#include "../include/liste.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    Liste p = creerNombreTresGrand();
    afficherNombreTresGrand(p);

    Liste p2 = creerNombreTresGrand();
    afficherNombreTresGrand(p2);

    printf("Le nombre le plus grand est : ");
    afficherNombreTresGrand(compareDeuxNombreTresGrand(p, p2));

    return 0;
}