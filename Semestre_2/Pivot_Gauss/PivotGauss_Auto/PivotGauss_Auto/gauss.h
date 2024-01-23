#pragma once

#include "matrice.h"

//CALCUL_SUR_PIVOT
bool gaussTest(InfoMat Matrice);

int gaussAuto(InfoMat Matrice);

int transposition(InfoMat Matrice, int l1, int l2);
int dilatation(InfoMat Matrice, double lambda, int indice);
int division(InfoMat Matrice, double lambda, int indice);
int transvection(InfoMat Matrice, int l1, int l2, double lambda);

int triMatrice(InfoMat Matrice);
int modulo(int tmp, int modulo);