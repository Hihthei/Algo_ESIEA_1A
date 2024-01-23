#include"echangeChaine.h"
#include<stdio.h>

int puissance(long a, long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long valeur = a;
    for (int i = 0; i < b -1; i++) a = a * valeur;
    return a;
}

void echangeChaine(long* preverse, long n) {

    long reverse = 0;
    long finish = 0;

    for (int i = 1; i < n+1; i++)
    {
        reverse = (puissance(10, n-(i)) * (*preverse % puissance(10, i))) / puissance(10, i-1);
        // printf("reverse = %d\n", reverse);
        finish += reverse;
        // printf("finish = %d\n", finish);
        *preverse -= (*preverse % puissance(10,i));
        // printf("preverse = %d\n", *preverse);
        if (i == n) *preverse = finish;
        // printf("%d/%d...\n\n", i, n);
    }
    return;
}

void test(long* pnombre, long* p_n) {
    long i = 1;
    while (*p_n == 0)
    {
        if (*pnombre < puissance(10, i)) *p_n = i;
        i++;
    }
    return;
}