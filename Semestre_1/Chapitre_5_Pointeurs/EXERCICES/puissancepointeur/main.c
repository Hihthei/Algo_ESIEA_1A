#include<stdlib.h>
#include<stdio.h>
#include"puissancepointeur.h"

int main(int argc, char **argv)
{
    int a = atof(argv[1]);
    int* p_a = &a;

    puissancePointeur(p_a, atof(argv[2]));

    printf("%d\n", *p_a);    

    return 0;
}