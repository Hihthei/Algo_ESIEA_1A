#include<stdlib.h>
#include<stdio.h>

/*
Rédigez un programme permettant de calculer le rang n de la série harmonique.
Votre programme doit scanner l'entrée standard tant que le nombre saisi est invalide
et afficher le résultat sous forme d'un nombre flottant.
*/

int main()
{
    float n = -1.f, Un = 0.f;

    while ((n <= 0))
    {
        scanf("%f", &n);
//        printf("%f\n", n);
    }
    
    for (float i = 1; i <= n; i++)
    {
        Un = Un + (1.f / i);
    }

    printf("%f\n", Un);
    
    return 0.0;

}