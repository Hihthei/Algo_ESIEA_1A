#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main()
{
    int a, b;

    scanf("int a=%d, b=%d;", &a, &b);

    /*
    
    scanf("%d %d", &a, &b);
    printf("a = %d , b = %d \n", a, b);

    printf("Donnez la valeur de n :");
    scanf("%d", &n);

    // rotation circulaire
    for(i = 0 ; i < n ; i++)
    {
        tmp = a;
        printf(" tmp = %d", tmp);

        a = b;
        printf(" a = %d", a);

        b = tmp;
        printf("b = %d \n", b);

    }

    */



    // échange de a et de b sans tmp (addition)
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a = %d, b = %d\n", a, b);


/*

    // échange de a et de b sans tmp (XOR)
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("a = %d, b = %d, c = %d\n", a, b, c);
*/

    return 0;
}