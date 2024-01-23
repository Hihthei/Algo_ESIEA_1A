#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./fonctions.h"


int main(int argc, char **argv)
{
    if (argc < 4)
    {
        printf("Pas assez d'information\n");
        return EXIT_FAILURE;
    }
    
    float a = atof(argv[1]), b = atof(argv[2]), c = atof(argv[3]);

    float truc = delta(a, b, c);
    printf("delta = %f\n", truc);

    if (truc < 0)
    {
        printf("Pas de solution\n");
        return EXIT_FAILURE;
    }
    else if (truc == 0) printf("la racine est : %f\n", -1 * b / 2 * a);

    else if (truc > 0)
    {
        float x1 = racine1(a, b, c);
        float x2 = racine2(a, b, c);

        if (x1 < x2) printf("x1 = %.6f et x2= %.6f\n", x1, x2);
        else printf("x1 = %.6f et x2= %.6f\n", x2, x1);
    }

    return 0;
}