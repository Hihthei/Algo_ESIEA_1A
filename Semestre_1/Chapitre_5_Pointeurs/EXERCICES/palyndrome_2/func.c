#include <stdio.h>
#include <math.h>

int Miror(int N);
int NbDigit(int N);
int Palindromize(int N);
int puissance(int a, int b);

int main() {
    printf("Le miroir de %d est : %d\n", 1337, Miror(1337));
    printf("Le nombre de digit de %d est : %d\n", 1337, NbDigit(1337));
    printf("Le palyndrome de %d est : %d\n", 1337, Palindromize(1337));
    return 0;
}

int puissance(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int valeur = a;
    for (int i = 0; i < b -1; i++) a = a * valeur;
    return a;
}

int Miror(int N)
{
    int reverse = 0;
    int finish = 0;
    
    int n = NbDigit(N);

    for (int i = 1; i < n+1; i++)
    {
        reverse = (puissance(10, n-(i)) * (N % puissance(10, i))) / puissance(10, i-1);
        finish += reverse;
        N -= (N % puissance(10,i));
        if (i == n) N = finish;
    }
    return N;
}

int NbDigit(int N)
{
    int i = 1;
    int j = 0;
    while (j == 0)
    {
        if (N < puissance(10, i)) j = i;
        i++;
    }
    return j;
}

int Palindromize(int N)
{
    int reverse = Miror(N);

    N *= puissance(10, NbDigit(N)+1);
    int compteur;
    for (int i = 0; i < NbDigit(reverse); i++)
    {
        int tmp = (puissance(10, NbDigit(reverse)-(i)) * (reverse % puissance(10, i))) / puissance(10, i-1);
        printf("tmp = %d\n", tmp);
        reverse -= reverse % puissance(10, compteur);
        printf("reverse = %d\n", reverse);
        N += (tmp * puissance(10,compteur));
        compteur++;
    }
    return N;
}

