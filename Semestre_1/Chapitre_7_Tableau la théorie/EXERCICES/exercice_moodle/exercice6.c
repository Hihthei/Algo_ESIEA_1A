#include<stdlib.h>
#include<stdio.h>

int main() {

    int tab[10] = {0};
    for (int i = 0; i < 10; i++)
        tab[i] = i;
    int* p = &tab[0];

    printf("%p   %p\n", p, p+1);
    return 0;
}