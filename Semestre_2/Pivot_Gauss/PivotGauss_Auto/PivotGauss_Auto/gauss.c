#include "gauss.h"

/// @brief : Test si le pivot est résolu
/// @param : InfoMat Matrice - les informations de la matrice
/// @return : vrai si le pivot est résolu, faux sinon
bool gaussTest(InfoMat Matrice)
{
    int j;
    // Parcourir toutes les lignes de la matrice
    for (int i = 0; i < Matrice.ligne; i++)
    {
        //on recherche le premier élément de la ligne qui est nul
        j = 0;

        while ((j < Matrice.colonne) && (Matrice.mat[i][j] == 0))
        {
            j++;
            printf("%d\n", j);
        }

        //on passe à la boucle for suivante si toute la ligne a été vérifiée
        //Si tous les éléments de la ligne i sont nuls, on passte à la ligne suivante
        if (j == Matrice.colonne)
            continue;

        // Vérifier que la colonne du pivot est nul également
        for (int k = 0; k < Matrice.ligne; k++)
        {
            if (k == i)
                continue;

            if (Matrice.mat[k][j] != 0)
                return false;
        }

        // Vérifier que le pivot est bien à 1
        if (Matrice.mat[i][j] != 1)
            return false;
    }

    return true;
}


/*
    -- ALGORITHME DU PIVOT DE GAUSS --

    Entrée. Matrice de réels M[n][p]
    Sortie. Matrice de réels M échelonnée
    Entier Li ← 1
    Pour j allant de 1 à p faire
        Recherche de e: premier élément non nul de la colonne j à partir de Li
        Entier pivotVal ← e
        Entier pivotInd ← ligne(e)
        Si un pivot a été trouvé alors
            Échanger la ligne pivotInd avec la ligne Li
            Pour i allant de Li+1 à n
                faire Transvection(M, i, Li, -M[i][j]/M[Li][j])
            Fin Pour
            Li ← Li + 1
        Fin Si
    Fin Pour
*/


/// @brief : Résolution du pivot de gauss
/// @param : InfoMat Matrice - les informations de la matrice
/// @return : success
int gaussAuto(InfoMat Matrice)
{
    //On initialise les variables qu'on va utiliser ensuite
    int Li = 0, i = 0, j = 0, k = 0;

    //On cherche à parcourir la matrice colonne par colonne
    for (j = 0; j < Matrice.colonne; j++)
    {
        //i représente l'indice de la ligne de la matrice à laquelle on est
        //on cherche à trouver le pivot à la première ligne et ainsi de suite
        int Li = i;

        //on parcours la matrice à partir de Li
        //tant qu'on a pas trouver de pivot à la ligne Li, on parcour la ligne
        while (Li < Matrice.ligne && Matrice.mat[Li][j] == 0)
            Li++;

        //si on atteint la limite de la ligne, on change de colonne
        if (Li == Matrice.ligne)
            continue;

        else
        {
            //si on entre dans cette boucle, c'est qu'on a trouvé un pivot
            //on regarde si la ligne du pivot est différente à l'indice i

            /*
            Par exemple :
            i = 0, on recherche un pivot pour la première ligne de la matrice
            j = 0, on est à la première colonne de la matrice

            le premier pivot qu'on trouve est à Li = 3 (par exemple)

            donc on échange la ligne Li et i pour que la matrice soit échelonnée
            */

            if(i != Li)
                transposition(Matrice, i, Li);

            //On divise la ligne par elle même (ou on multiplie par l'inverse)

            /*
            Par exemple :
              (a b)    - L1 
            A=(c d)    - L2
            
            Si on divie L1 par elle même, on obtient :

              (1 b/a)  - L1
            A=(c d)    - L2
            */
            dilatation(Matrice, 1 / Matrice.mat[Li][j], Li);

            //Ensuite on réduit les lignes au dessus et en dessous du pivot pour qu'elle soit réduite
            for (k = 0; k < Matrice.ligne; k++)
            {
                //On fait bien attention à ce que la ligne qu'on réduit soit pas la ligne du pivot (parce que sinon elle disparait)
                if (k != Li)
                    transvection(Matrice, k, Li, -Matrice.mat[k][j]);
            }
            //on passe à la ligne suivante (pour chercher un pivot à la 2eme ligne par exemple)
            i++;
        }
    }

    return EXIT_SUCCESS;
}

/// @brief : échange de 2 lignes de la matrice
/// @param : InfoMat Matrice - les informations de la matrice
/// @param : int l1 - la ligne 1 à échanger
/// @param : int l2 - la ligne 2 à échanger
/// @return : Success
int transposition(InfoMat Matrice, int l1, int l2)
{
    if (l1 == l2)
    {
        printf("Vous devez entrer 2 lignes differentes\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < Matrice.colonne; i++)
    {
        double tmp = Matrice.mat[l1][i];
        Matrice.mat[l1][i] = Matrice.mat[l2][i];
        Matrice.mat[l2][i] = tmp;
    }
    return EXIT_SUCCESS;
}

/// @brief : multiplie une ligne de la matrice par un scalaire
/// @param : InfoMat Matrice - les informations de la matrice
/// @param : int lambda - un scalaire
/// @param : int l1 - la ligne à multiplier
/// @return : success
int dilatation(InfoMat Matrice, double lambda, int l1)
{
    if (lambda == 0)
    {
        printf("Vous ne pouvez pas multiplier par 0.\n");

        return EXIT_FAILURE;
    }

    //calcul
    for (int i = 0; i < Matrice.colonne; i++)
        Matrice.mat[l1][i] *= lambda;

    return EXIT_SUCCESS;
}

/// @brief : divise une ligne de la matrice par un scalaire
/// @param : InfoMat Matrice - les informations de la matrice
/// @param : int lambda - un scalaire
/// @param : int l1 - la ligne à diviser
/// @return : success
int division(InfoMat Matrice, double lambda, int l1)
{
    if (lambda == 0)
    {
        printf("Vous ne pouvez pas diviser par 0.\n");

        return EXIT_FAILURE;
    }
    //calcul
    for (int i = 0; i < Matrice.colonne; i++)
        Matrice.mat[l1][i] /= lambda;

    return EXIT_SUCCESS;
}

/// @brief : additionne 2 lignes de la matrice
/// @param : InfoMat Matrice - les informations de la matrice
/// @param : int l1 - la ligne à qui va aller l'addition
/// @param : int l2 - la ligne qui va s'additionner
/// @param : int lambda - un scalaire
/// @return : success
int transvection(InfoMat Matrice, int l1, int l2, double lambda)
{
    if (l1 == l2)
    {
        printf("Vous devez entrer 2 lignes différentes");
        return EXIT_FAILURE;
    }
    //calcul
    for (int i = 0; i < Matrice.colonne; i++)
        Matrice.mat[l1][i] += Matrice.mat[l2][i] * lambda;

    return EXIT_SUCCESS;
}

/// @brief : tri la matrice selon la première ligne
/// @param : InfoMat Matrice - les informations de la matrice
/// @return : success
int triMatrice(InfoMat Matrice)
{
    int i, tmp = 0, min;

    for (i = 0; i < Matrice.ligne - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < Matrice.colonne; j++)
        {
            if (Matrice.mat[j][0] < 0)
                dilatation(Matrice, -1, j);

            if (Matrice.mat[j][0] < Matrice.mat[min][0])
            {
                //on tri en fonction de la plus petite valeur de pivot possible, donc 0 exclus
                if (Matrice.mat[j][0] == 0)
                    continue;

                min = j;
            }
        }

        if (Matrice.mat[min][0] != Matrice.mat[i][0])
            transposition(Matrice, min, i);
    }
    return EXIT_SUCCESS;
}

/// @brief : le modulo avec 0 exclu
/// @param : int tmp - la valeur à diviser
/// @param : int modulo - le modulo
/// @return : le modulo de tmp par modulo
int modulo(int tmp, int modulo)
{
    if ((tmp % modulo) == 0)
        return modulo;

    return tmp % modulo;
}