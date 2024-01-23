#include<stdio.h>

int main()
{
	//TITRE DU CHAPITRE : Les Tableaux en Langage C

/*
	Sommaire :

	� Introduction aux Tableaux

		1.1 D�finition d'un tableau en C
		1.2 D�claration et initialisation des tableaux
		1.3 Les diff�rents types de tableaux en C

	� Manipulation de Tableaux

		2.1 Acc�s aux �l�ments d'un tableau
		2.2 Parcours des �l�ments d'un tableau
		2.3 Affectation d'�l�ments � partir de scanf

	//___________________________________________________________________________________________________________________________________


	1. Introduction aux Tableaux :

		1.1 D�finition d'un tableau en C :
		Les tableaux en langage C sont des structures de donn�es permettant de stocker et de manipuler des
		collections d'�l�ments de m�me type. Les donn�es sont rassembl�es et donc plus faciles d'acc�s.

		1.2 D�claration et initialisation des tableaux :
*/
	//les crochets permettent de cr�er un tableau, la valeur d�signe le nombre de case.
//	int tab[10];

	//pour initialiser un tableau proprement, on le remplie de 0 au d�but. On ne peut le faire qu'� la d�claration de variable, et on fait comme �a :
	int tab[10] = { 0 };
	//{ 0 }, on remplie le tableau de 0. /!\, { 1 } ne va pas le remplir de 1... Oui c'est pas intuitif
/*
		1.3 Les diff�rents types de tableaux en C :
		On peut avoir des tableaux de nombre entier (int), � virgule (float), de caract�re (char) -> �a devient donc une cha�ne de caract�re
		de nombre � virgule mais avec plus de chiffre apr�s la virgule (double), .... Environ tous les types de variable que l'on souhaite.
*/
//	int tab[10] = { 0 };
	float tab2[10] = { 0.0f };
	double tab3[10] = { 0.0f };
	char tab1[11] = ""; //ATTENTION, dans une cha�ne de caract�re on affecte toujours une case de plus que ce dont on a besoin

	
/*
	2. Manipulation de Tableaux :

		2.1 Acc�s aux �l�ments d'un tableau :
		Les �l�ments d'un tableau sont accessibles � l'aide de leurs indices, un tableau de 10 cases aura donc... 10 possibilit�s.
*/

	tab[4] = 1; //� la case d'indice 4 du tableau, j'affecte la valeur 1
	tab[1] = tab[4] + tab[6]; //je r�cup�re la valeur stock� dans tab[4] et dans tab[6] et je l'additionne.
	//ATTENTION : un tableau se conte � partir de 0. Donc un tableau de 4 cases aura les indices :
	//tab[0] - tab[1] - tab[2] - tab[3]
	//tab[4] est donc.... La 5�me case du tableau !
	//Il y a bel et bien 4 cases dans le tableau, et la derni�re case est donc la case n-1, n �tant la taille du tableau.

	//Pour les cha�nes de caract�re (char tab1[11]), on manipule des caract�res. Donc des lettres :

	tab1[0] = "weshhhh"; //on affect � tab1[0], mais la cha�ne va se mettre sur tout le long du tableau.
	//On vera plus tard avec les pointeurs une autre fa�on de stocker les variables d'un tableau.

/*

		2.2 Parcours des �l�ments d'un tableau avec des boucles :
		Les boucles peuvent �tre utilis�es pour parcourir tous les �l�ments d'un tableau, effectuant ainsi des op�rations sur chacun d'eux.		

*/

	for (int i = 0; i < 10; i++) //i va prendre les valeurs de 0 � 9 (car < 10, et non <= 10)
	{
		tab[i] = 1; //� chaque passage de boucle je vais affect� une valeur diff�rente � la case.
	}

	
/*
	2.3 Affectation d'�l�ments � partir de scanf :
	On peut �videmment affecter des valeurs � partir de scanf. Pour l'instant, on va dire que le tableau marche comme une variable normal.
	On verra avec le chapitre des pointeurs que, non le tableau n'est pas comme une variable normal.

	je peux donc tr�s bien faire :
*/

	scanf("%d %d", &tab[1], &tab[4]);

/*
	et �a marchera tr�s bien


	Conclusion :
		Les tableaux en langage C sont des structures de donn�es polyvalentes et essentielles.Comprendre leur d�claration,
		leur manipulation et leur utilisation avec des fonctions est fondamental pour tout programmeur en C.En ma�trisant les tableaux,
		les programmeurs peuvent r�soudre une vari�t� de probl�mes informatiques de mani�re efficace et structur�e.

		Voici une fiche de r�vision sur les tableaux en langage C, respectant le squelette que vous avez fourni.
		Cette fiche couvre les principaux concepts li�s aux tableaux, de leur d�claration � leur utilisation avec des fonctions,
		en passant par les tableaux multidimensionnels et dynamiques.Les exemples pratiques illustrent l'application des concepts
		dans des sc�narios r�els. N'h�sitez pas � ajuster ou � ajouter des d�tails selon vos besoins sp�cifiques.
*/
	return 0;
}