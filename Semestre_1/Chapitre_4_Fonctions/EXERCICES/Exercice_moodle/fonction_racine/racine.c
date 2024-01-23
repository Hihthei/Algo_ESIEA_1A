#include<stdlib.h>
#include<stdio.h>

float racine(float Un);

int main() {
    float a = 0.0;
    scanf("%f", &a);
    printf("%.2f\n", racine(a));
    return 0;
}

float racine(float Un) {
    float a = Un;
    float UnPls = 0.0;
    for (int i = 0; i < 50; i++)
    {
        UnPls = (Un + a/Un)/2.0;
        Un = UnPls;
    }
    return Un;    
}