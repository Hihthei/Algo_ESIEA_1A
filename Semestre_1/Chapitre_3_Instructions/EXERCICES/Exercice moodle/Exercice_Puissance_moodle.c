#include<stdio.h>

/*
Développez un programme complet prenant entrée deux entiers 
a et b et affichant le résultat de ab. On assure que b≥0.
La librairie math.h est interdite.
*/

int main()
{

    int a = 0, b = 0;

    scanf("%d %d", &a, &b);
    int x = a;

    if (b == 0)
    {
        printf("1");
        return 0;
    }
    else
    {
        for (int i = 1; i < b; i++)
        { a = a * x; }

        printf("%d\n", a);
    }
    
    

    return 0;

}