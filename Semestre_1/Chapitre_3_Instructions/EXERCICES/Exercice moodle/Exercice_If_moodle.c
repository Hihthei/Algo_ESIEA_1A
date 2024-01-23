#include<stdlib.h>
#include<stdio.h>

int main()
{
    float prix, monnaie, rendu;

    scanf("%f %f\n", &prix, &monnaie);

    rendu = monnaie - prix;

    rendu < 0 ? printf("ESCROC\n") : printf("%f\n", rendu);

    return 0;
    
}