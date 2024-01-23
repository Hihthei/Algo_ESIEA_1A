#include<stdio.h>
#include<stdlib.h>

void ecritureBinaire(int n, int* tab, int taille)
{
	taille--;

	int tmp = n;
	while (taille >= 0)
	{
		tab[taille] = tmp % 2;
		tmp /= 2;
		taille--;
	}
	return;
}

void viderTableau(int* tab)
{

}

int main()
{
	int tab[25];

	int n = 0, nombre = 0;

	scanf_s("%d", &nombre);

	//int* ptr = (int*)calloc(nombre, sizeof(int));

	ecritureBinaire(nombre, tab, 25);

	for (int i = 0; i < 25; i++)
		printf("%d ", tab[i]);

	printf("\n");


	//free(ptr);
	return 0;
}