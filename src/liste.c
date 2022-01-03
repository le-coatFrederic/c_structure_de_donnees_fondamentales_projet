#include "../include/liste.h"
#include <stdlib.h>
#include <stdio.h>

int tete(Liste lst)
{
    if(!estVideListe(lst)) 
        return lst->chiffre;
    else 
        exit(EXIT_FAILURE);
}

Liste queue(Liste lst)
{
    if(!estVideListe(lst)) 
        return lst->suivant;
    else 
        exit(EXIT_FAILURE);
}

int estVideListe(Liste lst)
{
    if(lst == NULL) 
        return 1;
    else 
        return 0;
}

Liste creerListe(int valeur, Liste lst)
{
    Liste nouvelleCellule = malloc(sizeof(Liste));
    nouvelleCellule->chiffre = valeur;
    nouvelleCellule->suivant = lst;
    return nouvelleCellule;
}

Liste creerNombreTresGrand()
{
    int running = 1;
    int choix;
    Liste lst , cpLst, cpLst2;
    printf("Quel chiffre ajouter au nombre ? "); // le faire une première fois pour tout initialiser
    scanf("%d", &choix);
    if(choix < 0) return NULL;    
    
    else 
    {
        lst = creerListe(choix, NULL);
        cpLst = lst;
    }
    while(running)
    {
        printf("Quel chiffre ajouter au nombre ? ");
        scanf("%d", &choix);
        if(choix < 0) running = 0;
        else
        {
            cpLst->suivant = creerListe(choix, NULL);
            cpLst = queue(cpLst);
        }
    }
    return formatageTresGrandNombre(lst);
}

void afficherNombreTresGrand(Liste lst)
{
    while(!estVideListe(lst))
    {
        printf("%d", tete(lst));
        lst = queue(lst);
    }
}

Liste formatageTresGrandNombre(Liste lst)
{
    Liste cpLst = lst;
    while(!estVideListe(cpLst))
    {
        if(tete(cpLst) > 9)
        {
            cpLst->suivant = creerListe(tete(cpLst) % 10, queue(cpLst));
            cpLst->chiffre = (tete(cpLst) - (tete(cpLst) % 10)) / 10; 
        }
        else
            cpLst = queue(cpLst);
    }
    return lst;
}

Liste compareDeuxNombreTresGrand(Liste lst1, Liste lst2)
{
    int max = 0;

    Liste cpLst1 = lst1;
    Liste cpLst2 = lst2;

    while(tete(cpLst1) == 0)
        cpLst1 = queue(cpLst1);
    while(tete(cpLst2) == 0)
        cpLst2 = queue(cpLst2);

    while(!estVideListe(cpLst1) && !estVideListe(cpLst2))
    {
        if(max == 0 && tete(cpLst1) != tete(cpLst2))
        {
            if(tete(cpLst1) > tete(cpLst2))
                max = 1;
            else if(tete(cpLst1) < tete(cpLst2))
                max = 2;
        }
        cpLst1 = queue(cpLst1);
        cpLst2 = queue(cpLst2);
    }

    if(estVideListe(cpLst1) && estVideListe(cpLst2))
    {
        if(max == 1 || max == 0)
            return lst1;
        else 
            return lst2;
    }
    else
    {
        if(estVideListe(cpLst1))
            return lst2;
        else
            return lst1;
    }
}

int plusGrandQue(Liste lst1, Liste lst2)
{
    int max = 0;

    while(tete(lst1) == 0)
        lst1 = queue(lst1);
    while(tete(lst2) == 0)
        lst2 = queue(lst2);

    while(!estVideListe(lst1) && !estVideListe(lst2))
    {
        if(max == 0 && tete(lst1) != tete(lst2))
        {
            if(tete(lst1) > tete(lst2))
                max = 1;
            else if(tete(lst1) < tete(lst2))
                max = 2;
        }
        lst1 = queue(lst1);
        lst2 = queue(lst2);
    }

    if(estVideListe(lst1) && estVideListe(lst2))
    {
        if(max == 1)
            return 1;
        else 
            return 0;
    }
    else
    {
        if(estVideListe(lst1))
            return 0;
        else
            return 1;
    }
}

int plusPetitQue(Liste lst1, Liste lst2)
{
    int max = 0;

    while(tete(lst1) == 0)
        lst1 = queue(lst1);
    while(tete(lst2) == 0)
        lst2 = queue(lst2);

    while(!estVideListe(lst1) && !estVideListe(lst2))
    {
        if(max == 0 && tete(lst1) != tete(lst2))
        {
            if(tete(lst1) < tete(lst2))
                max = 1;
            else if(tete(lst1) > tete(lst2))
                max = 2;
        }
        lst1 = queue(lst1);
        lst2 = queue(lst2);
    }

    if(estVideListe(lst1) && estVideListe(lst2))
    {
        if(max == 1)
            return 1;
        else 
            return 0;
    }
    else
    {
        if(estVideListe(lst1))
            return 1;
        else
            return 0;
    }
}

int Egal(Liste lst1, Liste lst2)
{
    while(tete(lst1) == 0)
        lst1 = queue(lst1);
    while(tete(lst2) == 0)
        lst2 = queue(lst2);

    while(!estVideListe(lst1) && !estVideListe(lst2))
    {
        lst1 = queue(lst1);
        lst2 = queue(lst2);
    }

    if(estVideListe(lst1) && estVideListe(lst2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}