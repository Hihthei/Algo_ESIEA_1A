#include"func.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

int sommeTab(int tableau[], int nbDeCase) {

    int result = 0;
    for (int i = 0; i < nbDeCase; i++) result += tableau[i];
    return result;
}

void affTab(int tableau[], int nbDeCase) {
    for (int i = 0; i < nbDeCase; i++) printf("[%d] ", tableau[i]);
    printf("\n");
    return;
}

void initTab(int tableau[], int nbDeCase) {
    for (int i = 0; i < nbDeCase; i++) tableau[i] = 0;
    return;
}

void fillRandomTab(int tab[], int n, int inf, int sup) {
    for (int i = 0; i < n; i++) {
        tab[i] = (rand() % (sup - inf +1)) + inf;
    }
    return;
}

void rdmMatr(int matrice[][TAILLE_MATRICE_LONGUEUR], int largeur, int longueur, int inf, int sup) {
    for (int i = 0; i < largeur; i++) 
    {
        for (int j = 0; j < longueur; j++)
            matrice[i][j] = (rand() % (sup - inf +1)) + inf;
    }

    return;
}

int moyenneTab(int tableau[], int n) {
    int moyenne = sommeTab(tableau, n) / n;
    return moyenne;
}

void remplTab(int tableau[], int n) {
    for (int i = 0; i < n; i++) scanf("%d", &tableau[i]);
    return;
}

void affMatrice(int matrice[][TAILLE_MATRICE_LONGUEUR], int largeur, int longueur) {
    // int lrg = 0, lng = 0;
    // while(lrg != largeur && lng != longueur) {
    //     for (int i = 0; i < longueur; i++) {
    //         lng = i;
    //         printf("[%d] ", matrice[lrg][lng]);
    //     }
    //     lrg++;
    //     lng = 0;
    // }
    // return;
    for (int i = 0; i < largeur; i++) 
    {
        for (int j = 0; j < longueur; j++)
            printf("[%d] ", matrice[i][j]);
        
        printf("\n");
    }
    return;
}

int sommeMatr(int matrice[][TAILLE_MATRICE_LONGUEUR], int largeur, int longueur) {
    int result = 0;
    for (int i = 0; i < largeur; i++) 
    {
        for (int j = 0; j < longueur; j++)
            result += matrice[i][j];
    }
    return result;
}

int moyenneMatr(int matrice[][TAILLE_MATRICE_LONGUEUR], int largeur, int longueur) {
    int moyenne = sommeMatr(matrice, largeur, longueur) / (largeur * longueur);
    return moyenne;
}

void initMatr(int matrice[][TAILLE_MATRICE_LONGUEUR], int largeur) {
    for (int i = 0; i < largeur; i++) 
    {
        for (int j = 0; j < 10; j++)
            matrice[i][j] = 0;
    }
    return;
}

void fillMatr(int matrice[][TAILLE_MATRICE_LONGUEUR], int largeur) {
    int tmp = 0;
    for(int i = 0; i < largeur; i++) {
        for(int j = 0; j < 10; j++) {
            matrice[i][j] = tmp + 1;
            tmp++;
        }
    }
    return;
}