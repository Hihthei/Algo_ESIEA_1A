#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

#include "gauss.h"

//INITIALISATION_DE_MATRICE
int** allocationDynamiqueMat(int n, int l);
void initialMat(int n, int l, int** mat);
void afficheMat(int n, int l, int** mat);
void remplirMat(int n, int l, int** mat, FILE* fichier);