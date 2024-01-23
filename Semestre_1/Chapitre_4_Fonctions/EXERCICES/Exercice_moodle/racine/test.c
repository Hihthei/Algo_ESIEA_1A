#include<stdio.h>

float racineAuto(float A, float c, float s) {
    float un = c, un_1;
    do {
        un_1 = un;
        un = 1.0 / 2.0 * (un + A / un);
    } while (fabs(un - un_1) > s); // On continue tant que la différence entre un et un+1 est supérieure au seuil s
    return un;
}

int main() {
    float A, c, s;

    printf("Entrez la valeur de A : ");
    scanf("%f", &A);
    printf("Entrez la valeur de c : ");
    scanf("%f", &c);
    printf("Entrez la valeur de s : ");
    scanf("%f", &s);

    int n;
    printf("Entrez le nombre d'itérations de la méthode : ");
    scanf("%d", &n);

    printf("La racine carrée de %f est approximée à %f au rang %d\n", A, racine(A, c, n), n);
    printf("La racine carrée de %f est approximée à %f avec un seuil de tolérance de %f\n", A, racineAuto(A, c, s), s);

    return 0;
}