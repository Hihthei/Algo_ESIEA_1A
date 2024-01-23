#include<stdio.h>
#include<stdlib.h>

unsigned int divEucRec(unsigned int a, unsigned int b)
{
    if(a < b)
        return a;
    
    return divEucRec(a -b, b);
}

int pair(int n)
{
	if(n == 1)
        return 0;
    else if(n == 0)
        return 1;

    return pair(n - 2);
}

int impair(int n)
{
	if(n == 1)
        return 1;
    else if(n == 0)
        return 0;

    return impair(n - 2);
}

    
int main()
{
    printf ("%d %d\n", pair(7), impair(7));
}