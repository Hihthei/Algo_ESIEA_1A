#include "matrice.h"
#include"gauss.h"

int main()
{
	FILE* fichier = NULL;
	fichier = fopen("Matrice_pivot.txt", "r");

	int nb_ligne = 0, nb_pivot = 0;
	const int SECOND_MEMBRE = 1;

	if (fichier != NULL)
	{
		int nb_ele_lu = fscanf(fichier, "%d %d", &nb_ligne, &nb_pivot);
		if (nb_ele_lu != 2)
		{
			printf("ERROR : lecture du fichier_main - l.17");
			return EXIT_FAILURE;
		}

		if ((nb_ligne > 0) && (nb_pivot > 0))
		{
			int** mat = allocationDynamiqueMat(nb_ligne, nb_pivot);
			if (mat == NULL)
			{
				printf("ERROR : allocation dynamique - l.26");
				return EXIT_FAILURE;
			}

			initialMat(nb_ligne, nb_pivot, mat);
			remplirMat(nb_ligne, nb_pivot, mat, fichier);

			while (gaussTest(nb_ligne, nb_pivot, mat) == false)
			{
				int n = (int)gaussManuel(nb_ligne, nb_pivot, mat);

				switch (n)
				{
				case 5:
					break;
				case 1:
					transposition(nb_ligne, nb_pivot, mat);
					continue;
				case 2:
					dilatation(nb_ligne, nb_pivot, mat);
					continue;
				case 3:
					transvection(nb_ligne, nb_pivot, mat);
					continue;
				case 4:
					triMatrice(nb_ligne, nb_pivot, mat);
					continue;
				default:
					continue;
				}
				break;
			}
			//on sort de la boucle car la matrice est échelonnée et réduite, ou qu'on a quitté la boucle
			if (gaussTest(nb_ligne, nb_pivot, mat))
			{
				//on affiche la matrice triée
				afficheMat(nb_ligne, nb_pivot, mat);
				printf("felicitations, la matrice est échelonnee et reduite !\n");
			}


			//on libère la mémoire
			free(mat);
		}
		//on ferme le fichier
		fclose(fichier);
	}
	return 0;
}