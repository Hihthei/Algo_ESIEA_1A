#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* allocationDynamiqueTab(int n);
char** allocationDynamiqueMat(int n, int l);
int nbCaractere(char* tab);
void remplirTableau(int n, char* tab, FILE* fichier);
void remplirMatrice(int n, int l, char* tab, char** mat);
//int compareDeuxTab(char* tab, char** mat);
void afficheTab(int n, char* tab);
void afficheMat(int n, int l, char** mat);


int main() {
    //OUVERTURE DU FICHIER TEST
    FILE* fichier = NULL;

    fichier = fopen("feur.txt", "r");
    
    //TEST POUR VOIR SI L'OUVERTURE A REUSSI
    if (fichier == NULL)
    {
        return 1;
    }

    int n = 0, nb_carac = 0, space = 0, j = 0, i = 0, l = 0, tmp = 0, powd = 1;

    char c = 0;

    //COMPTEUR DE CARACTERE SANS LES ESPACES
    while (c != EOF)
    {
        c = fgetc(fichier);

        //VERIFICATION DU CARACTERE NUL
        if (c == EOF)
        {
            break;
        }
        if (c != ' ') {
            nb_carac++;
        }
        else if (c == ' ') {
            space++;
        }
    }
    int nb_tot = nb_carac + space;

    //RETOUR AU DEBUT DU FICHIER
    rewind(fichier);

    printf("compteur : %d\nespace : %d\n", nb_carac, space);

    
    //PARTIE TABLEAU_1
    char* tab = allocationDynamiqueTab(nb_carac);

    remplirTableau(nb_carac, tab, fichier);

    fclose(fichier);

    afficheTab(nb_carac, tab);

    /*
    
    //PARTIE MATRICE
    char** mat = allocationDynamiqueMat(n, l);

    remplirMatrice(n, l, tab, mat);

    afficheMat(n, l, mat);

    */
    free(tab);
    //free(mat);
    
    return 0;
}

char* allocationDynamiqueTab(int n)
{
    char* tab = calloc(n * 100, sizeof(char));
    if (tab == NULL) {
        printf("Error");
        return NULL;
    }

    return tab;
}

char** allocationDynamiqueMat(int n, int l)
{
    char** mat = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        mat[i] = (char*)malloc(l * sizeof(char));
    }

    if (mat == NULL) {
        printf("Error");
        return NULL;
    }

    return mat;
}

int nbCaractere(char* tab)
{
    for (int i = 0; i < (strlen(tab)-1); i++)
    {
        if (tab[i] == ' ') {
            
        }
    }
}

void remplirTableau(int n, char* tab, FILE* fichier)
{
    char c = 0;
    int p = -1, tmp = atoi(fgetc(fichier));
    int i = 0, j = 0;
    while (c != '\n')
    {
        c = fgetc(fichier);
        if (c == "\n") {
            break;
        }
        tmp *= 10;
        tmp += atoi(c);
        i++;
    }

    tab[0] = tmp;
    for (i; i < n; i++)
    {
        c = fgetc(fichier);

        if ((c > 47) && (c < 72)) {
            if (tab[i - 1] == ' ') {
                tmp *= 10;
                tmp += atoi(c);
            }
            tmp = atoi(c);
        }
        {

        }
        if (c == EOF)
        {
            break;
        }
        tab[i] = c;
    }
    return;
}

void remplirMatrice(int n, int l, char* tab, char** mat)
{
    int tmp = 0;
    int i = 0;
    for (int j = 0; j < l + 1; j++)
    {
        tmp = j + (i * l);
        if (tab[tmp] == '\n') {
            i++;
            j = 0;
        }
        if ((tab[tmp] != ' ') && (tab[tmp] != '\n'))
        {
            mat[i][j] = tab[tmp];
        }
    }
}

//int compareDeuxTab(char* tab, char** mat);

void afficheTab(int n, char* tab)
{
    int i;
    for (i = 0; i < n+1; i++) {
        printf("[%c] ", tab[i]);

    }
    printf("\nnombre de cases : %d\n", i);
    return;
}

void afficheMat(int n, int l, char** mat)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (mat[i][j] != ' ') {
                printf("[%c] ", mat[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    return;
}