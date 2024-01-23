#include "matrice.h"
#include "gauss.h"

/// @brief : allou dynamiquement une matrice de taille l * n
/// @param : int l le nombre de ligne de la matrice
/// @param : int n le nombre de colonne (en contant le second membre)
/// @return : un pointeur sur la zone mémoire allouée
int** allocationDynamiqueMat(int l, int n)
{
    int** mat = (int**)calloc(l, sizeof(int*));
    if (mat == NULL)
    {
        printf("ERROR : allocation dynamique__allocationDynamique");
        return NULL;
    }
    for (int i = 0; i < l; i++) {
        mat[i] = (int*)calloc(n, sizeof(int));
        if (mat[i] == NULL) {
            printf("ERROR : allocation dynamique__allocationDynamique");
            return NULL;
        }
    }
    return mat;
}


/// @brief : initialise la matrice alloué dynamiquement à 0
/// @param : int l le nombre de ligne de la matrice
/// @param : int n le nombre de colonne (en contant le second membre)
/// @param : int** mat un pointeur vers la matrice à initialiser
/// @return : rien
void initialMat(int l, int n, int** mat)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = 0;
        }
    }
    return;
}



/// @brief : affiche la matrice
/// @param : int l le nombre de ligne de la matrice
/// @param : int n le nombre de colonne (en contant le second membre)
/// @param : int** mat un pointeur vers la matrice à initialiser
/// @return : rien
void afficheMat(int l, int n, int** mat)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("[%d] ", mat[i][j]);
        }
        printf("= 0\n");
    }
    printf("\n");
    return;
}



/// @brief : affiche la matrice
/// @param : int l le nombre de ligne de la matrice
/// @param : int n le nombre de colonne (en contant le second membre)
/// @param : int** mat un pointeur vers la matrice à initialiser
/// @param : FILE* fichier un pointeur vers le fichier qui contient la matrice
/// @return : rien
void remplirMat(int l, int n, int** mat, FILE* fichier)
{
    int error = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < n; j++)
        {
            error = fscanf(fichier, "%d", &mat[i][j]);
            if (error != 1)
            {
                printf("ERROR : lecture du fichier_remplirMat\n\n");
                return;
            }
        }
    }
    return;
}