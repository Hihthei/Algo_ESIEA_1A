#include<stdio.h>

float racine(float A, float c, int n)
{
    float u[100];
    u[0] = c;

    if(n > 100)
        n = 100;
    int i;
    for (i = 0; i < n-1; i++)
    {
        u[i + 1] = 0.5 * (u[i] + (A / u[i]));
    }
    
    float tmp = u[i];
    return tmp;
}

float racineAuto(float A, float c, float s)
{
    float cplus;

    while ((A / c) != 1)
    {
        cplus = 0.5 * (c + (A / c));
        c = cplus;
    }

    return c;
}

int main()
{
    float A, c, s;
    scanf("%f %f %f", &A, &c, &s);
    float test;
    return printf("%f\n", test = racineAuto(A, c, s));
}