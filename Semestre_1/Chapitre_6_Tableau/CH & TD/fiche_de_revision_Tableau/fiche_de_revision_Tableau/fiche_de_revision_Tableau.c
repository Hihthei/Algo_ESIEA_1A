#include<stdio.h>

int main()
{
	//TITRE DU CHAPITRE : Les Tableaux en Langage C

/*
	Sommaire :

	• Introduction aux Tableaux

		1.1 Définition d'un tableau en C
		1.2 Déclaration et initialisation des tableaux
		1.3 Les différents types de tableaux en C

	• Manipulation de Tableaux

		2.1 Accès aux éléments d'un tableau
		2.2 Parcours des éléments d'un tableau
		2.3 Affectation d'éléments à partir de scanf

	//___________________________________________________________________________________________________________________________________


	1. Introduction aux Tableaux :

		1.1 Définition d'un tableau en C :
		Les tableaux en langage C sont des structures de données permettant de stocker et de manipuler des
		collections d'éléments de même type. Les données sont rassemblées et donc plus faciles d'accès.

		1.2 Déclaration et initialisation des tableaux :
*/
	//les crochets permettent de créer un tableau, la valeur désigne le nombre de case.
//	int tab[10];

	//pour initialiser un tableau proprement, on le remplie de 0 au début. On ne peut le faire qu'à la déclaration de variable, et on fait comme ça :
	int tab[10] = { 0 };
	//{ 0 }, on remplie le tableau de 0. /!\, { 1 } ne va pas le remplir de 1... Oui c'est pas intuitif
/*
		1.3 Les différents types de tableaux en C :
		On peut avoir des tableaux de nombre entier (int), à virgule (float), de caractère (char) -> ça devient donc une chaîne de caractère
		de nombre à virgule mais avec plus de chiffre après la virgule (double), .... Environ tous les types de variable que l'on souhaite.
*/
//	int tab[10] = { 0 };
	float tab2[10] = { 0.0f };
	double tab3[10] = { 0.0f };
	char tab1[11] = ""; //ATTENTION, dans une chaîne de caractère on affecte toujours une case de plus que ce dont on a besoin

	
/*
	2. Manipulation de Tableaux :

		2.1 Accès aux éléments d'un tableau :
		Les éléments d'un tableau sont accessibles à l'aide de leurs indices, un tableau de 10 cases aura donc... 10 possibilités.
*/

	tab[4] = 1; //à la case d'indice 4 du tableau, j'affecte la valeur 1
	tab[1] = tab[4] + tab[6]; //je récupère la valeur stocké dans tab[4] et dans tab[6] et je l'additionne.
	//ATTENTION : un tableau se conte à partir de 0. Donc un tableau de 4 cases aura les indices :
	//tab[0] - tab[1] - tab[2] - tab[3]
	//tab[4] est donc.... La 5ème case du tableau !
	//Il y a bel et bien 4 cases dans le tableau, et la dernière case est donc la case n-1, n étant la taille du tableau.

	//Pour les chaînes de caractère (char tab1[11]), on manipule des caractères. Donc des lettres :

	tab1[0] = "weshhhh"; //on affect à tab1[0], mais la chaîne va se mettre sur tout le long du tableau.
	//On vera plus tard avec les pointeurs une autre façon de stocker les variables d'un tableau.

/*

		2.2 Parcours des éléments d'un tableau avec des boucles :
		Les boucles peuvent être utilisées pour parcourir tous les éléments d'un tableau, effectuant ainsi des opérations sur chacun d'eux.		

*/

	for (int i = 0; i < 10; i++) //i va prendre les valeurs de 0 à 9 (car < 10, et non <= 10)
	{
		tab[i] = 1; //à chaque passage de boucle je vais affecté une valeur différente à la case.
	}

	
/*
	2.3 Affectation d'éléments à partir de scanf :
	On peut évidemment affecter des valeurs à partir de scanf. Pour l'instant, on va dire que le tableau marche comme une variable normal.
	On verra avec le chapitre des pointeurs que, non le tableau n'est pas comme une variable normal.

	je peux donc très bien faire :
*/

	scanf("%d %d", &tab[1], &tab[4]);

/*
	et ça marchera très bien


	Conclusion :
		Les tableaux en langage C sont des structures de données polyvalentes et essentielles.Comprendre leur déclaration,
		leur manipulation et leur utilisation avec des fonctions est fondamental pour tout programmeur en C.En maîtrisant les tableaux,
		les programmeurs peuvent résoudre une variété de problèmes informatiques de manière efficace et structurée.

		Voici une fiche de révision sur les tableaux en langage C, respectant le squelette que vous avez fourni.
		Cette fiche couvre les principaux concepts liés aux tableaux, de leur déclaration à leur utilisation avec des fonctions,
		en passant par les tableaux multidimensionnels et dynamiques.Les exemples pratiques illustrent l'application des concepts
		dans des scénarios réels. N'hésitez pas à ajuster ou à ajouter des détails selon vos besoins spécifiques.
*/
	return 0;
}