#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "notes.h"

void afficheEtudiant(Etudiant etu)
{
	printf("Nom :          %s\n", etu.nom);
	printf("Prenom:        %s\n", etu.prenom);
	printf("Notes de bloc: %2.2f, %2.2f, %2.2f\n", etu.notes[0], etu.notes[1], etu.notes[2]);
	printf("Moyenne:       %2.2f\n", etu.moy);
	printf("Credits:       %d\n", etu.credits);
}

void afficheEtudiantCompact(Etudiant etu)
{
	printf("%10s, %18s, %02.2f, %02.2f, %02.2f, %02.2f, %2d\n", 
		etu.nom, etu.prenom, etu.notes[0], etu.notes[1], etu.notes[2], etu.moy, etu.credits);
}

Etudiant *lireFichier (char *path, int *p_size)
{
	Etudiant *tab = NULL;
	FILE *pfile = NULL;
	char c=0;
	int count = 0;
	int i;

	if (!p_size)
	{
		printf("Argument NULL dans la fonction lireFichier\n");
		return NULL;
	}

	pfile = fopen(path, "r");
	if (!pfile)
	{
		printf("Impossible d'ouvrir le fichier %s\n", path);
		return NULL;
	}

	// Recuperation du nombre d'étudiants
	do
	{ 
		c = fgetc(pfile);
		if (c == '\n')
			count++;
	} while (c != EOF);
	rewind(pfile);
	count--;

	// Allocation du tableau d'etudiants
	tab = (Etudiant*)calloc(count, sizeof(Etudiant));

	// Lecture de la première ligne
	do
	{
		c = fgetc(pfile);
	}while ((c != EOF) && (c != '\n'));

	// Lecture complete du fichier de notes et calcul des moyennes
	for (i = 0; i <= count; i++)
	{
		fscanf(pfile, "%s %s %f %f %f\n", 
			tab[i].nom, tab[i].prenom, tab[i].notes, tab[i].notes+1, tab[i].notes+2);
		tab[i].moy = (tab[i].notes[0] * 12.f + tab[i].notes[1] * 10.f + tab[i].notes[2] * 8.f) / 30.f;
		tab[i].credits += (tab[i].notes[0] >= 10 ? 12 : 0);
		tab[i].credits += (tab[i].notes[1] >= 10 ? 10 : 0);
		tab[i].credits += (tab[i].notes[2] >= 10 ? 8 : 0);
	}

	*p_size = count;
	return tab;
}

int triInsertion (void *tab, int type_size, int length, int (*f_comp)(void*, void*))
{

	int i, j;
	void *tmp = calloc(1, type_size);
	for (i = 1; i < length; i++)
	{
		memcpy(tmp, (char*)tab + i*type_size, type_size);
		j = i;
		while (j > 0 && f_comp((char*)tab + (j-1)*type_size, tmp) > 0)
		{
			memcpy((char*)tab + j*type_size, (char*)tab + (j - 1)*type_size, type_size);
			j--;
		}
		memcpy((char*)tab + j*type_size, tmp, type_size);
	}
	return 0;
}

int compareTailleNom (Etudiant *etu1, Etudiant *etu2)
{
	int size1, size2;
	size1 = strlen(etu1->nom);
	size2 = strlen(etu2->nom);
	if (size1 < size2)
		return -1;
	if (size1> size2)
		return 1;
	return 0;
}

int compareTailleNomDec(Etudiant *etu1, Etudiant *etu2)
{
	int size1, size2;
	size1 = strlen(etu1->nom);
	size2 = strlen(etu2->nom);
	if (size1 < size2)
		return 1;
	if (size1> size2)
		return -1;
	return 0;
}

int compareMoyenne(Etudiant *etu1, Etudiant *etu2)
{
	float a = etu1->moy;
	float b = etu2->moy;
	if (a < b)
		return -1;
	if (a > b)
		return 1;
	return 0;
}

int compareBMI(Etudiant *etu1, Etudiant *etu2)
{
	float a = etu1->notes[BMI];
	float b = etu2->notes[BMI];
	if (a < b)
		return -1;
	if (a > b)
		return 1;
	return 0;
}

int compareBFH(Etudiant *etu1, Etudiant *etu2)
{
	float a = etu1->notes[BFH];
	float b = etu2->notes[BFH];
	if (a < b)
		return -1;
	if (a > b)
		return 1;
	return 0;
}

int compareBPE(Etudiant *etu1, Etudiant *etu2)
{
	float a = etu1->notes[BPE];
	float b = etu2->notes[BPE];
	if (a < b)
		return -1;
	if (a > b)
		return 1;
	return 0;
}

int compareCredits(Etudiant *etu1, Etudiant *etu2)
{
	int a = etu1->credits;
	int b = etu2->credits;
	if (a < b)
		return -1;
	if (a > b)
		return 1;
	return 0;
}

void pause (void)
{
	system("pause");
}

int main (int argc, char **argv)
{
	Etudiant *tab = NULL;
	int size = 0;
	int i;
	int (*f_comp)();  // Creation du pointeur sur fonction generique

	if (argc < 2)
	{
		printf("Usage: prog.exe <fichier CSV>\n");
		return EXIT_FAILURE;
	}
	tab = lireFichier(argv[1], &size); 
	printf("Liste non triée : %d étudiants\n", size);
	for (i = 0; i < size; i++)
		afficheEtudiantCompact(tab[i]);
	printf("\n----------------------------\n");

    f_comp = compareMoyenne;
	triInsertion(tab, sizeof(Etudiant), size, f_comp);
	printf("Les 10 qui redoublent:\n");
	for (i = 0; i < 5; i++)
		printf("%s ", tab[i].nom);
	printf("\n");
	for (; i < 10; i++)
		printf("%s ", tab[i].nom);
	printf("\n----------------------------\n");

    f_comp = compareCredits;
	triInsertion(tab, sizeof(Etudiant), size, f_comp);
	printf("Les 3 qui vont économiser de l'argent:\n");
	for (i = size; i>size-3; i--)
		printf("%s ", tab[i].nom);
	printf("\n----------------------------\n");

    f_comp = compareBFH;
	triInsertion(tab, sizeof(Etudiant), size, f_comp);
	f_comp = compareTailleNomDec;
	triInsertion(tab, sizeof(Etudiant), size, f_comp);
	printf("Les 2 qui de passeront plus jamais au tableau :\n");
	for (i = 0; i < 2; i++)
		afficheEtudiantCompact(tab[i]);
	printf("\n");
	return 0;
}
