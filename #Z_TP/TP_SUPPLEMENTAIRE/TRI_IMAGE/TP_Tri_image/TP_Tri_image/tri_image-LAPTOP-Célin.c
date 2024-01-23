#include <stdio.h>
#include <stdlib.h>

#include "libbmp.h"
#include "tri_image.h"

// Compare les pixels p1 et p2 selon un ordre lexicographique sur les composantes RGB
// Retourne -1 si p1<p2, 0 si p1=p2, 1 si p1>p2
// Exemple : compLexicoRGB ((23,104,236), (23,137,32)) retourne -1
int compLexicoRGB(Pixel* p1, Pixel* p2)
{
	if (p1->R < p2->R)
		return -1;
	else if (p1->R > p2->R)
		return 1;

	else {
		if (p1->G < p2->G)
			return -1;
		else if (p1->G > p2->G)
			return 1;

		else {
			if (p1->B < p2->B)
				return -1;
			else if (p1->B > p2->B)
				return 1;
			else return 0;
		}
	}
}

// Compare les pixels p1 et p2 selon la somme des composantes RGB
// Retourne -1 si p1<p2, 0 si p1=p2, 1 si p1>p2
// Exemple : compSommeRGB ((23,104,236), (23,137,32)) retourne 1
int compSommeRGB(Pixel* p1, Pixel* p2)
{
	short tmp = (short)(p1->R + p1->G + p1->B);
	short tmp2 = (short)(p2->R + p2->G + p2->B);
	if (tmp < tmp2)
		return -1;
	else if (tmp > tmp2)
		return 1;
	else return 0;
}

// Compare les pixels p1 et p2 selon un ordre lexicographique sur les composantes HSV
// Retourne -1 si p1<p2, 0 si p1=p2, 1 si p1>p2
int compLexicoHSV(Pixel* p1, Pixel* p2)
{
	if (p1->H < p2->H)
		return -1;
	else if (p1->H > p2->H)
		return 1;

	else {
		if (p1->S < p2->S)
			return -1;
		else if (p1->S > p2->S)
			return 1;

		else {
			if (p1->V < p2->V)
				return -1;
			else if (p1->V > p2->V)
				return 1;
			else return 0;
		}
	}
}

// Compare les pixels p1 et p2 selon un ordre lexicographique sur les composantes YCbCr
// Retourne -1 si p1<p2, 0 si p1=p2, 1 si p1>p2
int compLexicoYCbCr(Pixel* p1, Pixel* p2)
{
	if (p1->Y > p2->Y)
		return 1;
	else if (p1->Y < p2->Y)
		return -1;

	else
	{
		if (p1->Cb > p2->Cb)
			return 1;
		else if (p1->Cb < p2->Cb)
			return -1;

		else
		{
			if (p1->Cr > p2->Cr)
				return 1;
			else if (p1->Cr < p2->Cr)
				return -1;
		}
	}
	return 0;
}

// Trie l'image img a l'aide d'un tri a bulles en utilisant 
// la fonction compFunc pour comparer deux pixels
int triBulles(Image* img, pFunc compFunc)
{
	int a = 1;
	Pixel ech;
	while (a != 0)
	{
		a = 0;
		for (int i = 0; i < img->size - 1; i++)
		{
			if (compFunc(&img->pix[i], &img->pix[i + 1]) > 0)
			{
				ech = img->pix[i];
				img->pix[i] = img->pix[i + 1];
				img->pix[i + 1] = ech;
				a = 1;
			}
		}
	}
	return 0;
}

// Trie l'image img a l'aide d'un tri insertion en utilisant 
// la fonction compFunc pour comparer deux pixels
int triInsertion(Image* img, pFunc compFunc)
{
	Pixel ech;
	for (int i = 1; i < img->size; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (compFunc(&img->pix[j], &img->pix[j - 1]) < 0)
			{
				ech = img->pix[j];
				img->pix[j] = img->pix[j - 1];
				img->pix[j - 1] = ech;
			}
		}
	}
	return 0;
}

// Trie l'image img a l'aide d'un tri selection en utilisant 
// la fonction compFunc pour comparer deux pixels
int triSelection(Image* img, pFunc compFunc)
{
	Pixel ech;
	int min;
	for (int i = 0; i < img->size; i++)
	{
		min = i;
		for (int j = i; j < img->size; j++)
		{
			if (compFunc(&img->pix[min], &img->pix[j]) > 0)
			{
				min = j;
			}
		}
		ech = img->pix[min];
		img->pix[min] = img->pix[i];
		img->pix[i] = ech;
	}
	return 0;
}

// Partitionne l'image ig entre les pixels en position G et D,
// suivant la valeur du pixel en position pivot et en utilisant
// la fonction compFunc pour comparer deux pixels
// Retourne la position du pivot une fois le partitionnement effectue
int partitionner(Image* img, int G, int D, int pivot, pFunc compFunc)
{
	Pixel pixel1;
	int tmp;
	while (G != D)
	{
		if (G < D)
		{
			if (compFunc(&img->pix[G], &img->pix[D]) < 1)
				D--;
			else
			{
				pixel1 = img->pix[G];
				img->pix[G] = img->pix[D];
				img->pix[D] = pixel1;
				tmp = D;
				D = G;
				G = tmp;
				D++;
			}
		}
		else if (G > D)
		{
			if (compFunc(&img->pix[G], &img->pix[D]) > -1)
				D++;
			else
			{
				pixel1 = img->pix[G];
				img->pix[G] = img->pix[D];
				img->pix[D] = pixel1;
				tmp = D;
				D = G;
				G = tmp;
				D--;
			}
		}
	}
	return D;
}

// Trie les pixels de l'image img entre les positions G et D en utilisant
// la fonction compFunc pour comparer deux pixels
int triRapide(Image* img, int G, int D, pFunc compFunc)
{
	if (G == 0 && D == img->size - 1)
	{
		int ran = rand() % (img->size);
		Pixel ech;

		ech = img->pix[0];
		img->pix[0] = img->pix[ran];
		img->pix[ran] = ech;
	}


	int Pivot = partitionner(img, G, D, 0, compFunc);

	if (Pivot > G)
		triRapide(img, G, Pivot - 1, compFunc);

	if (Pivot < D)
		triRapide(img, Pivot + 1, D, compFunc);

	return 0;
}

// Trie les pixels de l'image img en utilisant
// la fonction compFunc pour comparer deux pixels
int quicksort(Image* img, pFunc compFunc)
{
	triRapide(img, 0, img->size - 1, compFunc);
	return 0;
}