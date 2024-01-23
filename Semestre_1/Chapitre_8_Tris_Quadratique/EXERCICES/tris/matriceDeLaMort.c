#include <stdio.h>
#include<time.h>

#define longueur 1000
#define largeur 2000

int main(){

    srand(time(NULL));
    
    int matrice[largeur][longueur] = {0};
    int somme = 0;

    for (int i = 0; i < largeur; i++)
    {
        for (int j = 0; j < longueur; j++)
        {
            matrice[i][j] = (rand() % (9 - 1 + 1)) + 1;

            printf("[%d] ", matrice[i][j]);
            somme += matrice[i][j];
        }
        // printf("\n");
    }
    printf("\n\nLa somme de cette matrice est de : %d\n", somme);
    return 0;
}