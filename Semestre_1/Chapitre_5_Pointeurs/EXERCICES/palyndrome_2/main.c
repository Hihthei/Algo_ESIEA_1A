#include<stdlib.h>
#include<stdio.h>
#include"echangeChaine.h"

int main() {

    long nombre = 0, reverse = 0;
    long* pnombre = &nombre;
    long* preverse = &reverse;

    printf("Quelle est votre nombre de départ ?\nnombre de départ = ");
    scanf("%ld", &nombre);
    reverse = nombre;

    long n = 0;
    long* p_n = &n;
    long compteur = 0;
    long a = 0, b = 1;

    while (a != b) {

        reverse = nombre;
        test(pnombre, p_n);
        echangeChaine(preverse, *p_n);
        n = 0;
        
        printf("nombre = %ld, reverse = %ld\n%ld/...\n", *pnombre, *preverse, compteur);
        if(*pnombre == *preverse) {
            printf("Felicitations ! Vous avez trouvez un palyndrome !\n");
            printf("Il a fallu %ld essais pour trouver %ld !!\n\n", compteur, *pnombre);

            a = b;
        }
        else {
            *pnombre += *preverse;
            printf("nombre = %ld, reverse = %ld\n%ld/...\n\n", *pnombre, *preverse, compteur);
        }
        compteur++;
        if (compteur > 15)
        {
            printf("Error 404\n");
            printf("Votre nombre demande trop de calcul et prends donc trop de temps.\n");
            printf("Une erreur a ete detectee dans le code, veuillez attendre la fin des travaux.\n");
            printf("Vous pouvez egalement tester un nombre different.\n\n");
            return 0;
        }
        
    }
    return 0;
}