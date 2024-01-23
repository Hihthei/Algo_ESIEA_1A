#include<stdio.h>
#include<stdlib.h>

/*
int JustePrix(int n, int a, int b)
{
	if ((b - a) == 1)
	{
		if (b == n)
			return b;
		if (a == n)
			return a;
	}
	int x = ((a + b) / 2);

	if (n < x)
	{
		printf("%d < n < %d\n", a, x);
		return JustePrix(n, a, x);
	}
	if (x < n)
	{
		printf("%d < n < %d\n", x, b);
		return JustePrix(n, x, b);
	}
}
*/

void DichotomieEtTrieRapide(int* tab, int pivot, int index)
{
	if (pivot == index)
	{
		return;
	}
	else if (pivot < index)
	{
		for (int i = index; i >= pivot; i--)
		{
			if (tab[i] < tab[pivot])
			{
				//échange des valeurs
				echangeValeur(tab, pivot, i);

				//échange des indexes
				echangeIndex(&pivot, &index, i);

				//on retourne la fonction
				DichotomieEtTrieRapide(tab, pivot, index);
				break;
			}
		}
	}
	else if (pivot > index)
	{
		for (int i = index; i <= pivot; i++)
		{
			printf("tab[i] = %d\ntab[pivot] = %d\npivot = %d     index = %d\n\n", tab[i], tab[pivot], pivot, index);
			if (tab[i] > tab[pivot])
			{
				//échange des valeurs
				echangeValeur(tab, pivot, i);

				//échange des indexes
				echangeIndex(&pivot, &index, i);

				//on retourne la fonction
				DichotomieEtTrieRapide(tab, pivot, index);
				break;
			}
		}
	}
}
void afficheTab(int* tab, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("[%d] ", tab[i]);
	}
	printf("\n");
}

void echangeValeurs(int* tab, int pivot, int index)
{
	int tmp = tab[pivot];
	tab[pivot] = tab[index];
	tab[index] = tmp;
	return;
}

void echangeIndexes(int* pivot, int* index, int i)
{
	int tmp = *pivot;
	*pivot = i;
	*index = tmp;
	return;
}

void partitionner(int* tab, int pivot, int index)
{
	if (pivot < index)
	{
		for (int i = index; i > pivot; i--)
		{
			if (tab[i] < tab[pivot])
			{
				printf("\n______________________\n");

				//échange des valeurs
				echangeValeurs(tab, pivot, i);

				//échange des indexes
				echangeIndexes(&pivot, &index, i);

				//affiche le tableau et les pivots
				afficheTab(tab, 6);
				printf("pivot = %d     index = %d\n", pivot, index);
				printf("______________________\n\n");

				//on retourne la fonction
				partitionner(tab, pivot, index);

				//on quitte la boucle de la fonction en question car il y a eu un changement de valeurs
				break;
			}
		}
	}
	else
	{
		for (int i = index; i < pivot; i++)
		{
			if (tab[i] > tab[pivot])
			{
				printf("\n______________________\n");

				//échange des valeurs
				echangeValeurs(tab, pivot, i);

				//échange des indexes
				echangeIndexes(&pivot, &index, i);

				//affiche le tableau et les pivots
				afficheTab(tab, 6);
				printf("pivot = %d     index = %d\n", pivot, index);
				printf("______________________\n\n");

				//on retourne la fonction
				partitionner(tab, pivot, index);

				//on quitte la boucle de la fonction en question car il y a eu un changement de valeurs
				break;
			}
		}
	}
}






int main()
{
	//printf("\nLa valeur recherchée est : %d", JustePrix(14297, 10000, 50000));
	int tab[6] = { 4, 1, 2, 5, 6, 3 };

	afficheTab(tab, 6);
	printf("\n\n");

	partitionner(tab, 0, 5);

	afficheTab(tab, 6);
	printf("\n\n");

	return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>

 //	partitionner()
 //[IN/OUT] int *T : pointeur sur le début du tableau
 //[IN]     int G  : indice de début de tableau
 //[IN]     int D  : indice de fin de tableau
 //La fonction partitionne le tableau autour de la valeur t[G] entre les indices G et D
 //La fonction retourne l'indice du pivot une fois le tableau partitionné.
 
int partitionner(int* T, int G, int D)
{
	int ech;
	while (G != D)
	{
		if (G < D)
		{
			if (T[G] > T[D])
			{
				ech = T[G];
				T[G] = T[D];
				T[D] = ech;
				ech = G;
				G = D;
				D = ech + 1;
			}
			if (T[G] <= T[D])
			{
				D--;
			}
		}
		else if (G > D)
		{
			if (T[G] < T[D])
			{
				ech = T[G];
				T[G] = T[D];
				T[D] = ech;
				ech = G;
				G = D;
				D = ech - 1;
			}
			if (T[G] >= T[D])
			{
				D++;
			}
		}
	}
	return G;
}

 //  triRapide()
 //[IN/OUT] int *T : pointeur sur le début du tableau
 //[IN]     int G  : indice de début de tableau
 //[IN]     int D  : indice de fin de tableau
 //La fonction trie le tableau entre les indices G et D
 //La fonction retourne 0 si tout s'est bien passé, -1 en cas d'erreur.
 
int triRapide(int* T, int G, int D)
{
	int indice = partitionner(T, G, D);

	if (indice > G) triRapide(T, G, indice - 1);
	if (D > indice) triRapide(T, indice + 1, D);
	return 0;
}

*/