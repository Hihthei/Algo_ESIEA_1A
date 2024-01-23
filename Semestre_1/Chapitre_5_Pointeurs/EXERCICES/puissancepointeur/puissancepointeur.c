#include"puissancepointeur.h"

void puissancePointeur(int* p_a, int n) {

    int result = 0;
    int a = *p_a;

    if (n == 0)
    {
        *p_a = 1;
        return;
    }
    
    if (n == 1)
    {
        return;
    }
    

    for (int i = 0; i < n-1; i++)
    {
            *p_a = *p_a * a;
    }

    return;    
}