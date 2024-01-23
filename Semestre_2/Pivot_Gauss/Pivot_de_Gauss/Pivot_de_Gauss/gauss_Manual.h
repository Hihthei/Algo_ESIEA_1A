#pragma once

#include "matrice.h"

//CALCUL_SUR_PIVOT
bool gaussTest(int n, int m, int** mat);

//INTERFACE UTILISATEUR
int gaussManuel(int n, int m, int** mat);
void transposition(int n, int indice, int** mat);
void dilatation(int n, int m, int** mat);
void transvection(int n, int m, int** mat);

void voidBuffer();

void echangeLigneMat(int n, int l1, int l2, int** mat);
void triMatrice(int n, int l, int** mat);