#include<stdio.h>

int main()
{
	/**

	CHAPITRE 1 - VARIABLES EN C
	Ce chapitre couvre les notions de base concernant les variables en C. Il traite des diff�rents types de variables, de leur utilit� et de leur utilisation, ainsi que des diff�rentes fa�ons d'afficher leurs valeurs � l'aide de printf().
	*/
	/*

	SECTION 1 : TYPES DE VARIABLES
	Il existe plusieurs types de variables en C, chacun d'eux ayant une plage de valeurs diff�rente et occupant une quantit� de m�moire diff�rente.
	*/
	// Type entier sign�
	// Permet de stocker des entiers sign�s allant de -2^(n-1) � 2^(n-1)-1 (avec n bits)
	// Exemple : -32768 � 32767 sur 16 bits
	signed int x = 10;

	// Type entier non sign�
	// Permet de stocker des entiers non sign�s allant de 0 � 2^n-1 (avec n bits)
	// Exemple : 0 � 65535 sur 16 bits
	unsigned int y = 100;

	// Type caract�re
	// Permet de stocker un caract�re ASCII
	char c = 'a';

	// Type flottant
	// Permet de stocker un nombre d�cimal � virgule flottante (simple pr�cision)
	float f = 3.14;

	// Type double
	// Permet de stocker un nombre d�cimal � virgule flottante (double pr�cision)
	double d = 3.14159265359;

	/*

	SECTION 2 : AFFICHAGE DE VARIABLES
	Pour afficher la valeur d'une variable en C, on utilise la fonction printf().
	Elle permet d'afficher du texte et des variables dans un format sp�cifi�.
	*/
	// %d : affichage d'un entier sign�
	printf("x = %d\n", x);

	// %u : affichage d'un entier non sign�
	printf("y = %u\n", y);

	// %c : affichage d'un caract�re
	printf("c = %c\n", c);

	// %f : affichage d'un flottant
	printf("f = %f\n", f);

	// %lf : affichage d'un double
	printf("d = %lf\n", d);

	// Pour afficher plusieurs variables, on peut utiliser plusieurs sp�cificateurs de format, s�par�s par des virgules.
	printf("x = %d, y = %u, c = %c, f = %f, d = %lf\n", x, y, c, f, d);

	// On peut �galement pr�ciser la largeur et la pr�cision de l'affichage pour les variables flottantes.
	printf("f = %.2f\n", f); // Affiche f avec deux chiffres apr�s la virgule.

	// Il existe �galement d'autres sp�cificateurs de format pour afficher des variables en hexad�cimal, en octal, etc.
	// %x : affichage d'un entier sign� en hexad�cimal
	printf("x en hexa : %x\n", x);

	// %o : affichage d'un entier sign� en octal
	printf("x en octal : %o\n", x);

	// Pour plus de d�tails sur les sp�cificateurs de format, se r�f�rer � la documentation de printf().
}