#include "../include/liste.h"
#include <stdlib.h>
#include <stdio.h>

int tete(Liste lst)
{
    if(!estVide(lst)) 
        return lst->chiffre;
    else 
        exit(EXIT_FAILURE);
}

Liste queue(Liste lst)
{
    if(!estVide(lst)) 
        return lst->suivant;
    else 
        exit(EXIT_FAILURE);
}

int estVide(Liste lst)
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
    if(choix < 0) running = 0;
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
    while(!estVide(lst))
    {
        printf("%d ", tete(lst));
        lst = queue(lst);
    }
    printf("\n");
}

Liste formatageTresGrandNombre(Liste lst)
{
    Liste cpLst = lst;
    while(!estVide(cpLst))
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

    while(tete(lst1) == 0)
        lst1 = queue(lst1);
    while(tete(lst2) == 0)
        lst2 = queue(lst2);

    while(!estVide(lst1) || !estVide(lst2))
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
    if(estVide(lst1) && !estVide(lst2))
        return cpLst2;
    else if(!estVide(lst1) && estVide(lst2))
        return cpLst1;
    else
    {
        if(max == 1 || max == 0)
            return cpLst1;
        else 
            return cpLst2;
    }
}
