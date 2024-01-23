#include<stdio.h>
#include<stdlib.h>

int maximum(int a, int b)
{
    int max;
    max = a < b ?  b : a ;
    return max;
}

int main()
{
    printf("%d\n", maximum(2,3));
    return 0;
}