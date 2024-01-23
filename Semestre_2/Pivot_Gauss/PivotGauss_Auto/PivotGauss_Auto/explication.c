#include "gauss.h"

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

/*

Structure utilisée :

struct InfoMat_s
{
    double ligne;
    double colonne;
    double** mat;
    FILE* fichier;

}; typedef struct InfoMat_s InfoMat;

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

            if (i != Li)
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