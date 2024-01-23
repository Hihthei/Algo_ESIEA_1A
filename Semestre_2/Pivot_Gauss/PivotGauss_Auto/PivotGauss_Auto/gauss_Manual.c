#include "gauss_Manual.h"

/// @brief : interface utilisateur
/// @return : réponse utilisateur
int gaussManuel(InfoMat Matrice)
{
    //on clear la console pour que ce soit propre
    system("cls");

    //on affiche la matrice actuel
    afficheMat(Matrice);

    //on envoie les propositions
    printf( "- Transposition (echange de 2 lignes) : tapez 1\n"
            "- Dilatation (multiplication d'une ligne par un scalaire) : tapez 2\n"
            "- Transvection (addition de 2 lignes) : tapez 3\n"
            "- Division (division d'une ligne par un scalaire) : tapez 4\n"
            "- Tri matrice : tapez 5\n"
            "- Vous souhaitez quitter : tapez 6\n"
            "- Vous souhaitez recommancer : tapez 7\n\n");


    //on récupère la réponse et on la retourne
    printf("Entrez votre reponse : ");
    int tmp;
    scanf("%d", &tmp);

    return modulo(tmp, 7);
}

/// @brief : interface utilisateur
/// @return : success
int interfaceTransposition(InfoMat Matrice, int test)
{
    //on clear la console pour que ce soit propre
    system("cls");

    if (test > 0)
        printf("Veuillez rentrer une lignes corrects et differentes.\n\n");

    //on affiche la matrice actuel
    afficheMat(Matrice);

    //interface utilisateurs, quels lignes veulent-ils échanger
    int l1 = 0, l2 = 1;

    printf("Quels sont les lignes que vous voulez echanger ? (reponse attendu : \"l1 l2\")\n");
    scanf("%d %d", &l1, &l2);

    if (l1 == l2 || l1 <= 0 || l2 <= 0 || l1 > Matrice.ligne || l2 > Matrice.ligne)
    {
        return interfaceTransposition(Matrice, test+1);
        return EXIT_SUCCESS;
    }

    l1--;
    l2--;

    return transposition(Matrice, l1, l2);
}

/// @brief : interface utilisateur
/// @return : success
int interfaceDilatation(InfoMat Matrice, int test)
{
    //on clear la console pour que ce soit propre
    system("cls");

    //test de l'erreur
    if (test > 0)
        printf("Veuillez rentrer une ligne correct et un lambda different de 0.\n\n");

    //on affiche la matrice actuel
    afficheMat(Matrice);

    //interface utilisateurs, quelle ligne veulent-ils multiplier par quoi
    double lambda = 1;
    int l1 = 1;

    printf("Quelle est la ligne que vous voulez multiplier ? (reponse attendu : \"indice\")\n");
    scanf("%d", &l1);

    printf("\nPar combien voulez-vous multiplier cette ligne ? (reponse attendu : \"lambda\")\n");
    scanf("%lf", &lambda);

    if (l1 <= 0 || lambda == 0 || l1 > Matrice.ligne)
    {
        return interfaceDilatation(Matrice, test+1);
        return EXIT_SUCCESS;
    }

    //on réduit de 1 car en informatique un tableau commence à 0, alors qu'en maths il commente à 1
    l1--;

    return dilatation(Matrice, lambda, l1);
}

/// @brief : interface utilisateurs
/// @return : success
int interfaceDivision(InfoMat Matrice, int test)
{
    //on clear la console pour que ce soit propre
    system("cls");

    //test de l'erreur
    if (test > 0)
        printf("Veuillez rentrer une ligne correct et un lambda different de 0.\n\n");

    //on affiche la matrice actuel
    afficheMat(Matrice);

    //interface utilisateurs, quelles lignes veulent-ils diviser entres-elles
    double lambda = 1;
    int l1 = 1;

    printf("Quelles lignes voulez-vous diviser entres-elles ? (reponse attendu : \"ligne\")\n");
    printf("Votre reponse : ");
    scanf("%d", &l1);

    printf("\nPar combien souhaitez vous la diviser ? (reponse attendu : \"indice\")\n");
    printf("Votre reponse : ");
    scanf("%lf", &lambda);

    if(l1 <= 0 || lambda == 0 || l1 > Matrice.ligne)
    {
        return interfaceDivision(Matrice, test+1);
        return EXIT_SUCCESS;
    }

    l1--;

    return division(Matrice, lambda, l1);
}

int interfaceTransvection(InfoMat Matrice, int test)
{
    //on clear la console pour que ce soit propre
    system("cls");

    //test de l'erreur
    if (test > 0)
        printf("Veuillez rentrer des lignes corrects et differentes et un lambda different de 0.\n\n");

    //on affiche la matrice actuel
    afficheMat(Matrice);

    //interface utilisateurs, quelles lignes veulent-ils diviser entres-elles
    double lambda = 1;
    int l1 = 1, l2 = 2;

    printf("Quelles lignes voulez-vous additionner entres-elles ? (reponse attendu : \"ligne1 ligne2\")\n");
    printf("\tNote : c'est la ligne1 qui va recuperer l'addition (l1' = l1 + l2)\n");
    printf("Votre reponse : ");
    scanf("%d %d", &l1, &l2);

    printf("\nPar combien souhaitez vous la multiplier avant ? (par defaut 1) (reponse attendu : \"indice\")\n");
    printf("Votre reponse : ");
    scanf("%lf", &lambda);

    if (lambda == 0 || l1 == l2 || l1 <= 0 || l2 <= 0 || l1 > Matrice.ligne || l2 > Matrice.ligne)
    {
        return interfaceTransvection(Matrice, test+1);
        return EXIT_SUCCESS;
    }

    l1--;
    l2--;

    return transvection(Matrice, l1, l2, lambda);
}