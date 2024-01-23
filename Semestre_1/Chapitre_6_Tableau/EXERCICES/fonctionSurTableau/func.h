#ifndef _FUNC_H_
#define _FUNC_H_
#define TAILLE_MATRICE_LONGUEUR 10
#define TAILLE_MATRICE_LARGEUR 4
#define INFERIEUR 0
#define SUPERIEUR 10

int sommeTab(int tableau[], int nbDeCase);
void affTab(int tableau[], int nbDeCase);
void initTab(int tableau[], int nbDeCase);
void fillRandomTab (int tab[], int n, int inf, int sup);
int moyenneTab(int tableau[], int n);
void remplTab(int tableau[], int n);

void rdmMatr(int matrice[][TAILLE_MATRICE_LONGUEUR], int largeur, int longueur, int inf, int sup);
void affMatrice(int matrice[][TAILLE_MATRICE_LONGUEUR], int largeur, int longueur);
int sommeMatr(int matrice[][TAILLE_MATRICE_LONGUEUR], int largeur, int longueur);
int moyenneMatr(int matrice[][TAILLE_MATRICE_LONGUEUR], int largeur, int longueur);
void fillMatr(int matrice[][TAILLE_MATRICE_LONGUEUR], int largeur);
void initMatr(int matrice[][TAILLE_MATRICE_LONGUEUR], int largeur);

#endif