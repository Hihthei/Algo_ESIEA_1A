#include<stdio.h>

int main()
{
	/**

	CHAPITRE 1 - VARIABLES EN C
	Ce chapitre couvre les notions de base concernant les variables en C. Il traite des différents types de variables, de leur utilité et de leur utilisation, ainsi que des différentes façons d'afficher leurs valeurs à l'aide de printf().
	*/
	/*

	SECTION 1 : TYPES DE VARIABLES
	Il existe plusieurs types de variables en C, chacun d'eux ayant une plage de valeurs différente et occupant une quantité de mémoire différente.
	*/
	// Type entier signé
	// Permet de stocker des entiers signés allant de -2^(n-1) à 2^(n-1)-1 (avec n bits)
	// Exemple : -32768 à 32767 sur 16 bits
	signed int x = 10;

	// Type entier non signé
	// Permet de stocker des entiers non signés allant de 0 à 2^n-1 (avec n bits)
	// Exemple : 0 à 65535 sur 16 bits
	unsigned int y = 100;

	// Type caractère
	// Permet de stocker un caractère ASCII
	char c = 'a';

	// Type flottant
	// Permet de stocker un nombre décimal à virgule flottante (simple précision)
	float f = 3.14;

	// Type double
	// Permet de stocker un nombre décimal à virgule flottante (double précision)
	double d = 3.14159265359;

	/*

	SECTION 2 : AFFICHAGE DE VARIABLES
	Pour afficher la valeur d'une variable en C, on utilise la fonction printf().
	Elle permet d'afficher du texte et des variables dans un format spécifié.
	*/
	// %d : affichage d'un entier signé
	printf("x = %d\n", x);

	// %u : affichage d'un entier non signé
	printf("y = %u\n", y);

	// %c : affichage d'un caractère
	printf("c = %c\n", c);

	// %f : affichage d'un flottant
	printf("f = %f\n", f);

	// %lf : affichage d'un double
	printf("d = %lf\n", d);

	// Pour afficher plusieurs variables, on peut utiliser plusieurs spécificateurs de format, séparés par des virgules.
	printf("x = %d, y = %u, c = %c, f = %f, d = %lf\n", x, y, c, f, d);

	// On peut également préciser la largeur et la précision de l'affichage pour les variables flottantes.
	printf("f = %.2f\n", f); // Affiche f avec deux chiffres après la virgule.

	// Il existe également d'autres spécificateurs de format pour afficher des variables en hexadécimal, en octal, etc.
	// %x : affichage d'un entier signé en hexadécimal
	printf("x en hexa : %x\n", x);

	// %o : affichage d'un entier signé en octal
	printf("x en octal : %o\n", x);

	// Pour plus de détails sur les spécificateurs de format, se référer à la documentation de printf().
}