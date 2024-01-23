#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>


struct InfoMat_s
{
	double ligne;
	double colonne;
	double** mat;
	FILE* fichier;

}; typedef struct InfoMat_s InfoMat;


//INTERFACE UTILISATEUR
int interfaceUtilisateur(InfoMat Matrice, int test);

//INITIALISATION_DE_MATRICE
double** allocMat(double ligne, double colonne);
InfoMat infoMatrice(char* str);
InfoMat restart(InfoMat Matrice);

//UTILISATION_DE_MATRICE
int afficheMat(InfoMat Matrice);
int remplirMat(InfoMat Matrice);

//BOUCLE UTILISATEUR
int gaussManualAplly(InfoMat Matrice);

//LIBERATION_DE_MATRICE
int freeMatrice(InfoMat Matrice);