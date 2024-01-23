#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

int** allocMat(int nbRows, int nbCols)
{
	assert(nbRows > 0 && nbCols > 0); //assert vérifie que les conditions sont bonne et met un point d'arrêt si les condiitons ne sont pas respectés.
	
	int** mat = (int**)calloc(nbRows, sizeof(int*));
	if (mat != NULL)
	{
		for (int i = 0; i < nbRows; i++)
		{
			mat[i] = (int*)calloc(nbCols, sizeof(int));
			if (mat[i] == NULL)
			{
				for (int j = 0; j < i; j++)
				{
					free(mat[j]);
				}
				free(mat);
				return NULL;
			}
		}
	}
	else 
		return NULL;
	return mat;
}

void freeMat(int** mat, int nbRows)
{
	if (mat == NULL)
		return;
	for (int i = 0; i < nbRows; i++)
	{
		free(mat[i]);
	}
	free(mat);
}