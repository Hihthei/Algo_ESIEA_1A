#include"gauss_Manual.h"

int main()
{
	InfoMat Matrice = { 0, 0, NULL };

	//on rempli toutes les infos importantes (allocation de la matrice, et remplissage)
	Matrice = infoMatrice("Matrice_pivot.txt");

	if (Matrice.ligne == 0 || Matrice.colonne == 0 || Matrice.mat == NULL)
	{
		printf("ERROR : matrice non valide, main.c - l.13\n");

		//on libère la mémoire
		freeMatrice(Matrice);

		return EXIT_FAILURE;
	}

	int tmp = interfaceUtilisateur(Matrice, 0);

	if (tmp == 1)
	{
		//on fait le calcul de gauss manuel
		gaussManualAplly(Matrice);
	}
	else
	{
		//on fait le calcul de gauss automatique
		gaussAuto(Matrice);
	}

	system("cls");

	printf("Vous etes sorti de la boucle\n\n");

	//on affiche la matrice
	afficheMat(Matrice);

	//on libère la mémoire
	freeMatrice(Matrice);

	return EXIT_SUCCESS;
}