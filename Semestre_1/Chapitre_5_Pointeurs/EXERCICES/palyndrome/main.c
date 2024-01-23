#include<stdlib.h>
#include<stdio.h>
#include"echangeChaine.h"

int main(int argc, char **argv) {

    char nombre[1001];

    printf("Quelle est votre nombre de départ ?\nnombre de départ = ");
    scanf("%s", nombre);
    
    int n = strlen(nombre) - 1;
    char chaine[n];

    return 0;
}