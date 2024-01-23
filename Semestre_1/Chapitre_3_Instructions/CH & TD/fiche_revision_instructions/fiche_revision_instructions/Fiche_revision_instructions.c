/**

    • Les Instructions en langage C

    1ère partie : Les grandes notions et leur utilité

    Les instructions sont des éléments fondamentaux du langage C qui permettent d'effectuer des actions ou des traitements sur des variables ou des données.
    Les instructions peuvent être regroupées en blocs ou en fonctions pour des raisons de lisibilité, de modularité et de réutilisabilité du code.
    
    
    • 2ème partie : Les différentes instructions

    L'instruction d'affectation permet d'assigner une valeur à une variable : variable = valeur;
    Les instructions de contrôle de flux permettent de modifier le déroulement du programme en fonction de conditions : if, else, switch, while, do - while, for, break, continue, return.
    L'instruction de déclaration permet de créer une nouvelle variable : type nom_variable;
    L'instruction de définition permet de créer une nouvelle variable et de lui assigner une valeur : type nom_variable = valeur;
    L'instruction d'incrémentation permet d'ajouter 1 à une variable : variable++;
    L'instruction de décrémentation permet de soustraire 1 à une variable : variable--;
**/


/*  • 3ème partie : Exemples d'utilisations dans un code concret, commenté et précis */

#include <stdio.h>

int main() {
    /* Déclaration et affectation de variables */
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

    /* Instructions de contrôle de flux */
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

/* Dans cet exemple, nous avons utilisé différentes instructions pour déclarer et affecter des variables,
afficher des valeurs, modifier des variables, contrôler le flux d'exécution et effectuer des boucles.
Les instructions ont permis de réaliser des traitements sur les variables et de modifier le déroulement
du programme en fonction de conditions. */