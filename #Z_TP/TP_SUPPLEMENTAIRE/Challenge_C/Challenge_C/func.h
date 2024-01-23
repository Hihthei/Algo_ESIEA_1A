#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct InfoTab_s
{
	//entier 1
	int entier;
	int nbCase;
	int* tab;

	//entier miroir
	int entierMiroir;
	int* tabMiroir;

	//nombres élégants
	int nbElegant;

} InfoTab;

int* allocTab(int nbCase);
int afficheTab(int nbCase, int* tab);
int miroir(int entier);
int* inverseTab(InfoTab Tableau);
int powerRec(int n, int pow);
int nbCase(int n);
int* decompositionBin(int n);
int recompositionBin(int nbCase, int* tab);
int afficheInfoTab(InfoTab Tableau);
int freeTableau(InfoTab Tableau);