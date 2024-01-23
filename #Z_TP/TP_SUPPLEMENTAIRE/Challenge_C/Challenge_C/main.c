#include"func.h"

int main()
{
	int nbElem = 0, tmp = 0, bruh = 0;

	scanf("%d %d", &bruh, &nbElem);

	InfoTab Tableau = { 0, 0, NULL, 0, NULL, 1 };

	for (int i = bruh; i <= nbElem; i++)
	{
		Tableau.entier = i;

		Tableau.nbCase = nbCase(Tableau.entier);

		Tableau.tab = decompositionBin(Tableau.entier);

		Tableau.tabMiroir = inverseTab(Tableau);

		Tableau.entierMiroir = miroir(Tableau.entier);

		tmp = recompositionBin(Tableau.nbCase, Tableau.tabMiroir);

		if (tmp == Tableau.entierMiroir)
		{
			Tableau.nbElegant++;

			printf("gneu gneu je suis un nombre elegant : %d\n", Tableau.entier);
		}

//		afficheInfoTab(Tableau);

		freeTableau(Tableau);
		tmp = 0;
	}

	printf("nombre d'entier élégant : %d\n", Tableau.nbElegant);

	return EXIT_SUCCESS;
}