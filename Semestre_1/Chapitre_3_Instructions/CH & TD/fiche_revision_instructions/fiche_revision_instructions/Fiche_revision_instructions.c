/**

    � Les Instructions en langage C

    1�re partie : Les grandes notions et leur utilit�

    Les instructions sont des �l�ments fondamentaux du langage C qui permettent d'effectuer des actions ou des traitements sur des variables ou des donn�es.
    Les instructions peuvent �tre regroup�es en blocs ou en fonctions pour des raisons de lisibilit�, de modularit� et de r�utilisabilit� du code.
    
    
    � 2�me partie : Les diff�rentes instructions

    L'instruction d'affectation permet d'assigner une valeur � une variable : variable = valeur;
    Les instructions de contr�le de flux permettent de modifier le d�roulement du programme en fonction de conditions : if, else, switch, while, do - while, for, break, continue, return.
    L'instruction de d�claration permet de cr�er une nouvelle variable : type nom_variable;
    L'instruction de d�finition permet de cr�er une nouvelle variable et de lui assigner une valeur : type nom_variable = valeur;
    L'instruction d'incr�mentation permet d'ajouter 1 � une variable : variable++;
    L'instruction de d�cr�mentation permet de soustraire 1 � une variable : variable--;
**/


/*  � 3�me partie : Exemples d'utilisations dans un code concret, comment� et pr�cis */

#include <stdio.h>

int main() {
    /* D�claration et affectation de variables */
    int a = 10;
    int b = 5;

    /* Affichage de variables */
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    /* Affectation de variables */
    a = 20;
    b = a + 5;

    /* Affichage de variables */
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    /* Instructions de contr�le de flux */
    if (a > b) {
        printf("a est plus grand que b\n");
    }
    else {
        printf("b est plus grand que a\n");
    }

    /* Boucle while */
    int i = 0;
    while (i < 5) {
        printf("i = %d\n", i);
        i++;
    }

    /* Boucle for */
    for (int j = 0; j < 5; j++) {
        printf("j = %d\n", j);
    }

    return 0;
}

/* Dans cet exemple, nous avons utilis� diff�rentes instructions pour d�clarer et affecter des variables,
afficher des valeurs, modifier des variables, contr�ler le flux d'ex�cution et effectuer des boucles.
Les instructions ont permis de r�aliser des traitements sur les variables et de modifier le d�roulement
du programme en fonction de conditions. */