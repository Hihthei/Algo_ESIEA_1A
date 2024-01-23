/*
Développez un programme complet permettant de jouer au jeu "Je pense à".
Votre programme doit dans un premier temps récupérer la valeur mystère qui 
est un chiffre entre 1 et 5. Le programme doit ensuite scanner un nombre tant
que le nombre entré n'est pas le bon que trois tentatives ont été réalisées.
Si le chiffre mystère est trouvé sur une tentative, le programme doit afficher "Bravo!",
sinon le programme affiche "Essaie encore.". Si le nombre n'est pas trouvé
sur la dernière tentative, le programme doit afficher "Dommage : c'était "
suivi du nombre mystère
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int valeur, recherche;

    scanf("%d", &valeur);

    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &recherche);

        if (recherche == valeur)
        {
            printf("Bravo!\n");
            break;
        }
        else if ((recherche != valeur) && (i < 2))
        {
            printf("Essaie encore.\n");
        }

        else if (i == 2)
        {
            if (recherche == valeur)
            {
                printf("Bravo!\n");
                break;
            }
            else if ((recherche != valeur))
            {
                printf("Dommage : c'était %d\n", valeur);
                break;
            }
        }
    }

    return 0;
    
}