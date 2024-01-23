#include<stdio.h>
#include<stdlib.h>

/*
Rédigez un programme complet permettant de récupérer une série d'entiers positifs 
et d'afficher l'entier le plus grand et le plus petit de la série. La fin de la série
est repérée par la saisie d'un entier négatif.

Il est interdit d'utiliser cinq variables ou plus et vous ne devez pas non plus utiliser de tableau
*/

int main()
{
    int min = 0, max = 0, a = 0;

    scanf("%d", &a);

    if (a < 0)
    {   
        printf("max = %d et min = %d\n", max, min);
        return 0;
    }
    else { min = max = a; }

    do
    {

        scanf("%d", &a);

        // printf("max = %d et min = %d et a = %d\n", max, min, a);

        if (a < 0)
        {   
            printf("max = %d et min = %d\n", max, min);
            break;
        }

        if (a < min) { min = a; }

        if (a > max) { max = a; }

    } while (a >= 0);

    return 0;

}