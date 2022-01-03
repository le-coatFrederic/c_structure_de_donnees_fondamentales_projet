#ifndef __LISTE__H__
#define __LISTE__H__

typedef struct Cellule
{
    int chiffre;
    struct Cellule *suivant;
}*Liste;

int tete(Liste lst);
Liste queue(Liste lst);
int estVideListe(Liste lst);
Liste creerListe(int valeur, Liste lst);
Liste creerNombreTresGrand();
void afficherNombreTresGrand(Liste lst);
Liste formatageTresGrandNombre(Liste lst);
Liste compareDeuxNombreTresGrand(Liste lst1, Liste lst2);
int plusGrandQue(Liste lst1, Liste lst2);
int plusPetitQue(Liste lst1, Liste lst2);
int Egal(Liste lst1, Liste lst2);

#endif