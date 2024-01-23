#include<stdlib.h>
#include<stdio.h>

int Palyndromize(int N);
int Miror(int N);
int NbDigit(int N);

int main() {
    int N = 0;
    scanf("%d", &N);
    return printf("%d\n%d\n%d\n", N, Miror(N), Palyndromize(N));
}

int Miror(int N)
{
    int miroir = 0;

    while (N > 0)
    {
        miroir = miroir * 10 + (N % 10);
        N /= 10;
    }

    return miroir;
}

int NbDigit(int N)
{
    int n = 0;

    while (N > 0)
    {
        n++;
        N /= 10;
    }

    return n;
}

int Palyndromize(int N)
{
    int n = NbDigit(N);
    int tmp = N - (N % 10);
    for (int i = 0; i < n-1; i++)
    {
        N *= 10;
    }
    printf("tmp = %d\n", tmp);
    N += Miror(tmp);
    return N;
}