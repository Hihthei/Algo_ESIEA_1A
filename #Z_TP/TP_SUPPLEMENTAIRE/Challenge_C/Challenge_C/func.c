#include"func.h"

int* allocTab(int nbCase)
{
    if (nbCase == 0)
    {
//        printf("ERROR : allocTab\n\n");
        return NULL;
    }

    int* tableau = NULL;
//    printf("ici_alloc : %d\n", nbCase);

    tableau = (int*)calloc((int)nbCase, sizeof(int));

    if (tableau == NULL)
    {
//        printf("ERROR : allocTab\n\n");
        return NULL;
    }

    return tableau;
}

int afficheTab(int nbCase, int* tab)
{
    if (nbCase == 0 || tab == NULL)
    {
//        printf("ERROR : afficheTab\n\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < nbCase; i++)
        printf("[%d] ", tab[i]);

    printf("\n\n");

    return EXIT_SUCCESS;
}

int miroir(int entier)
{
    int miroir = 0;

    while (entier > 0)
    {
        miroir = miroir * 10 + (entier % 10);
        entier /= 10;
    }

    return miroir;
}

int* inverseTab(InfoTab Tableau)
{
    int* tableau = allocTab(Tableau.nbCase);

    if (tableau == NULL)
        return NULL;

    int j = 0;
    for (int i = Tableau.nbCase - 1; i >= 0; i--)
    {
        tableau[j] = Tableau.tab[i];
        j++;
    }

    return tableau;
}

int powerRec(int n, int pow)
{
//    printf("ici_power : %d\n", pow);

    if (pow == 0)
        return 1;
    else if (n == 1)
        return 1;

    return n * powerRec(n, pow-1);
}

int nbCase(int n)
{
    int tmp = 0, cmpt = 0;

    while (n > tmp)
    {
        tmp += powerRec(2, cmpt);
        cmpt++;
    }
    return cmpt;
}

int* decompositionBin(int n)
{
    int cmpt = nbCase(n);

    int* tab = allocTab(cmpt);

    if (tab == NULL)
        return NULL;

    int i = cmpt -1;

    while ((n >= 1) && i >= 0)
    {
        if (n % 2 == 1)
        {
            tab[i] = 1;
            n--;
            n /= 2;
        }
        else if (n % 2 == 0)
        {
            tab[i] = 0;
            n /= 2;
        }
        i--;
    }

    return tab;
}

int recompositionBin(int nbCase, int* tab)
{
    if (nbCase == 1)
        return tab[0];

    int tmp = 0;

    int j = 0;
    for (int i = nbCase - 1; i >= 0; i--)
    {
        tmp += tab[i] * powerRec(2, j);
        j++;
    }

    return tmp;
}

int afficheInfoTab(InfoTab Tableau)
{
    printf(
        "_________________________________________\n\n"
        "Entier actuel : %d\n"
        "Tableau binaire de l'entier : ", Tableau.entier);

    afficheTab(Tableau.nbCase, Tableau.tab);

    printf(
        "Entier miroir : %d\n"
        "Tableau binaire de l'entier miroir : ", Tableau.entierMiroir);

    afficheTab(Tableau.nbCase, Tableau.tabMiroir);


    int tmp = recompositionBin(Tableau.nbCase, Tableau.tabMiroir);

    printf("Recomposition binaire du talbeau miroir : %d\n", tmp);

    return 0;
}


int freeTableau(InfoTab Tableau)
{
    if (Tableau.tab != NULL)
    {
        free(Tableau.tab);
        Tableau.tab = NULL;
    }


    if (Tableau.tabMiroir != NULL)
    {
        free(Tableau.tabMiroir);
        Tableau.tabMiroir = NULL;
    }

    return EXIT_SUCCESS;
}