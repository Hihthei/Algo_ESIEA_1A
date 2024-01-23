#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include"func.h"


int creerMenu (int mat[][10], int n, int pointsAliments[], int nbAlim, int maxPoints) {

    // for (int i = 0; i < n; i++)
    // {
    //     int somme = 0;
    //     for (int j = 0; j < nbAlim; j++)
    //     {
    //         mat[i][j] = pointsAliments[rand() % 10];
    //         if (mat[i][j] > 10) mat[i][j] %= 10;
    //         somme += mat[i][j];
    //     }
    //     printf("jours %d, somme 1/2 : %d\n\n", (i+1), somme);

    //     if (somme > maxPoints || somme < 0) {
    //         somme = 0;
    //         do
    //         {
    //             for (int j = 0; j < nbAlim; j++)
    //             {
    //                 int n = [rand() % 10];
    //                 if (mat[i][j] > 10) mat[i][j] %= 10;
                    
    //                 somme += mat[i][j];
    //             }
    //         } while (somme > maxPoints);
    //         printf("jours %d, somme 2/2 : %d\n\n", (i + 1), somme);
    //     }
    // }
    for (int i = 0; i < n; i++) {
        int somme = 0;
        while (somme < maxPoints) {
            int n = rand() % nbAlim;
            somme += pointsAliments[n];
            if(somme > maxPoints) {
                somme -= pointsAliments[n];
                break;
            }
            else mat[i][n] += 1;
        }
        printf("jours %d, somme :%d\n", i + 1, somme);
    }
    return 0;
}

int main() {
    srand(time(NULL));

    int pointsAliments[10] = {7,3,2,1,8,10,2,4,7,3};
    int nbAlim = 10, n = 7, maxPoints = 100;
    int mat[7][10];
    initMatr(mat, n);
    creerMenu (mat, n, pointsAliments, nbAlim, maxPoints);
    affMatrice(mat, 7, 10);


    // srand(time(NULL));
    // int tab[TAILLE_MATRICE_LONGUEUR];
    // int n = TAILLE_MATRICE_LONGUEUR, inf = INFERIEUR, sup = SUPERIEUR;
    // initTab(tab, n);
    // // affTab(tab, n);
    // fillRandomTab (tab, n, inf, sup);
    // affTab(tab, n);
    // printf("La moyenne de ce tableau est : %d\n\n", moyenneTab(tab, n));

    // int matrice[TAILLE_MATRICE_LARGEUR][TAILLE_MATRICE_LONGUEUR];
    // rdmMatr(matrice, TAILLE_MATRICE_LARGEUR, TAILLE_MATRICE_LONGUEUR, INFERIEUR, SUPERIEUR);
    // affMatrice(matrice, TAILLE_MATRICE_LARGEUR, TAILLE_MATRICE_LONGUEUR);
    // printf("La moyenne de cette matrice est : %d\n\n", moyenneMatr(matrice, TAILLE_MATRICE_LARGEUR, TAILLE_MATRICE_LONGUEUR));

    // int matr[TAILLE_MATRICE_LARGEUR][TAILLE_MATRICE_LONGUEUR];
    // initMatr(matr, TAILLE_MATRICE_LARGEUR);
    // fillMatr(matr, TAILLE_MATRICE_LARGEUR);
    // affMatrice(matr, TAILLE_MATRICE_LARGEUR, TAILLE_MATRICE_LONGUEUR);
    // printf("La moyenne de cette matrice est %d\n\n", moyenneMatr(matrice, TAILLE_MATRICE_LARGEUR, TAILLE_MATRICE_LONGUEUR));

    


    return 0;
}