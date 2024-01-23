#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int nbvoyelle(char *str);
int inverseCasse (char *str);


//_________________________//


int main() {
    int res = nbvoyelle("ibijau");

    int tmp = inverseCasse("ibijau et un espace");
    // printf("\n");

    return printf("voyelle : %d\n", res);    
}


//_________________________//


int nbvoyelle(char *str) {
    if (str == NULL) return -1;

    int compte = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y')
            compte++;
    }
    return compte;
}

int inverseCasse (char *str) {
    if (str == NULL) return -1;
    int a = strlen(str);
    printf("nombre de char : %d\n", a);
    for (int i = 0; i < strlen(str); i++)
    {
        if(str[i] == 32);
        else str[i] = str[i] - 32;
        printf("%c", str[i]);
    }
    return a;
}