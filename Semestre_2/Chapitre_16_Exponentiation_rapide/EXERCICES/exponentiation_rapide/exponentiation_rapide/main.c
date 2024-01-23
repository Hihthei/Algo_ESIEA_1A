#include<stdio.h>
#include<stdlib.h>


int nbDigits(unsigned int n)
{
    int N = 0;

    while (n > 0)
    {
        N++;
        n /= 10;
    }

    return N;
}

int power(unsigned int n, unsigned int pow) {
    int result = 1;
    for (unsigned int i = 0; i < pow; i++) {
        result *= n;
    }
    return result;
}

int powerRec(int n, int pow)
{
    //    printf("ici_power : %d\n", pow);
    printf("et ici aussi\n");

    if (pow == 0)
        return 1;
    else if (n == 1)
        return 1;

    return n * powerRec(n, pow - 1);
}

int mirrorRightLeft(unsigned int n)
{
    int mirror = 0;

    while (n > 0)
    {
        mirror = mirror * 10 + (n % 10);
        n /= 10;
        printf("mirror = %d\n", mirror);
    }

    return mirror;
}

int mirrorLeftRight(unsigned int n) {
    int nbDgts = nbDigits(n);
    int mirror = 0;
    for (int i = nbDgts - 1; i >= 0; i--) {
        int digit = n / powerRec(10, i);
        n %= powerRec(10, i);
        mirror += digit * powerRec(10, nbDgts - i - 1);
        printf("mirror = %d\n", mirror);
    }
    return mirror;
}

int mirrorLeftRightRecur(unsigned int n, int nbDigits, int i)
{
    if (n == 0) {
        return 0;
    }
    else {
        int digit = n / powerRec(10, nbDigits - 1);
        n %= powerRec(10, nbDigits - 1);
        return digit * powerRec(10, i) + mirrorLeftRightRecur(n, nbDigits - 1, i + 1);
    }
}

unsigned int expoNaiveIter(unsigned int g, unsigned int e, unsigned int n)
{
    unsigned int result = 1;

    for (unsigned int i = 0; i < e; i++)
        result = (result * g) % n;

    return result;
}

unsigned int expoPuiss2(unsigned int g, unsigned int e, unsigned int n)
{
    while (e != 1)
    {
        g = (g * g) % n;
        e /= 2;
    }
    return g;
}

unsigned int* decomposeExpo(unsigned int n)
{
    int compt = 0;

    while (n != 1)
    {
        n /= 2;
        compt++;
    }

    printf("compteur = %d\n", compt);

    unsigned int* tab = calloc(compt, sizeof(unsigned int));

    if (tab != NULL)
        return tab;

    return NULL;
}


int nbCase(int n)
{
    printf("je suis bien passé par là\n");
    int tmp = 0, cmpt = 0;

    while (n > tmp)
    {
        tmp += powerRec(2, cmpt);
        cmpt++;
    }
    return cmpt;
}

int initializeTab(int n, char* tab)
{
    for (int i = 0; i < n; i++)
        tab[i] = 0;

    return 0;
}

int decompoBinaire(int n, char tab[32])
{
    int i = 0, tmp = nbCase(n);

    initializeTab(32, tab);

    while ((n >= 1) && i < 32)
    {
        if (n % 2 == 1)
        {
            tab[i] = 1;
            n--;
            n /= 2;
        }
        else if (n % 2 == 0)
        {
            tab[i] = 0;
            n /= 2;
        }
        i++;
    }

    return tmp;
}

unsigned int expoTabulaire(unsigned short g, unsigned int e, unsigned short n)
{
    return;

}

int main()
{
/*
    int mirror = MirorLeftRight(12);

    int mirror = 0;
    mirror = MirorLeftRightRecur(4512, 4, 0);

    printf("mirror = %d\n", mirror);

    printf("%u\n", ExpoNaiveIter(1337, 73, 4242));

    printf("%u", ExpoPuiss2(3, 4, 100));
*/ 
    //_____________________________
/*
    int* tab = decomposeExpo(22);

    if (tab != NULL)
        printf("success !\n");

    free(tab);
*/
    //_____________________________
/*
    char T[32];

    initializeTab(32, T);

    printf("%d\n", decompoBinaire(10, T));

    for (int i = 31; i >= 0; i--)
        printf("%d", T[i]);
*/
    //_____________________________

    printf("%d\n", expoTabulaire(3, 4, 100));


    return 0;
}