#include<stdio.h>

/*
Développez un programme complet prenant entrée deux entiers 
a et b et affichant le résultat de ab. On assure que b≥0.
La librairie math.h est interdite.
*/

int main()
{

    int n = 0, b = 0;

    scanf("%d", &n);
    b = n;
    int x = n;

    if (b == 0)
    {
        printf("1");
        return 0;
    }
    else
    {
        for (int i = 1; i < b; i++)
        { n = n * i; }

        printf("%d\n", n);
    }
    
    return 0;

}