#include<stdio.h>
#include<stdlib.h>

int addition(int a, int b)
{
    int add = a + b;
    
    return add;
}

int main()
{
    int add = addition(2,3);
    printf("%d\n", add);
    return 0;
}