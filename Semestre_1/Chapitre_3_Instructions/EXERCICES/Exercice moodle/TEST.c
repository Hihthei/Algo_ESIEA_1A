#include <stdio.h>

int main ()
{
    int vm, vd;
    scanf("%d", &vm);
    for (int i = 1; i++; i < 3)
    {
        scanf("%d", &vd);
        if (vm == vd)
        {
            printf("Bravo!\n");
            return 0;
        }
        else 
        {
            printf("Essaie encore.\n");
        }
    }
    printf("Dommage : c'était %d\n", vm);
    return 0;
}