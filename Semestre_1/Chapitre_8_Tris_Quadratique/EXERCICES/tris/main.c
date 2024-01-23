#include<stdio.h>

void remplirEtapes(int tab[], int N);
void triABulle(int tab[], int N);
void triSelectif(int tab[], int N);
void triInsertion(int tab[], int N);

#define longeur 6

int main() {
    
    
    int tab[longeur] = {6, 2, 4, 5, 1, 3};

    for (int i = 0; i < longeur; i++)
        printf("[%d] ", tab[i]);
    
    printf("\n\n\n");

    triABulle(tab, longeur);

    /*  
    bien penser qu'un tableau peut déjà avoir des cases triées /!\
    vérifier si il y a besoin de trier une case /!\
    */

    printf("\n\n\n");
    for (int i = 0; i < longeur; i++)
        printf("[%d] ", tab[i]);

    printf("\n");
    
    return 0;
}

void remplirEtapes(int tab[], int N) {
    for (int i = 0; i < N; i++)printf("[%d] ", tab[i]);
    printf("\n");
    return;
}

void triABulle(int tab[], int N) {
    int action = 1;
    while (action != 0)
    {
        action = 0;
        for(int i = 0; i < N-1; i++) {
            if (tab[i] > tab[i+1])
            {
                int tmp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = tmp;
                action++;
                remplirEtapes(tab, N);
            }
        }
    }
    return;
}

void triSelectif(int tab[], int N) {

    int min = 0;

    for (int i = 0; i < N-1; i++)
    {
        min = i;
        for (int j = i+1; j < N; j++) {
            if (tab[j] < tab[min])
                min = j;
        }

        if((tab[min] != tab[i]) && (tab[min] < tab[i])) {
            int tmp = tab[min];
            tab[min] = tab[i];
            tab[i] = tmp;
            remplirEtapes(tab, N);
        }
    }
    return;
}

void triInsertion(int tab[], int N) {
    int i, j, tmp;
    for (i = 1; i < N; i++) {
        if(tab[i - 1] > tab[i]) {
            tmp = tab[i];
            j = i - 1;
            while (j >= 0 && tab[j] > tmp) {
                tab[j + 1] = tab[j];
                j--;
            }
            tab[j + 1] = tmp;
            remplirEtapes(tab, N);
        }
    }
    return;
}