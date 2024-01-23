#include "gauss.h"
#include "matrice.h"

/// @brief : Test si le pivot est résolu
/// @param : int n le nombre de colonne
/// @param : int m le nombre de ligne
/// @param : int** mat un pointeur vers la matrice
/// @return : vrai si le pivot est résolu, faux sinon
bool gaussTest(int n, int m, int** mat)
{
    int j;
    // Parcourir toutes les lignes de la matrice
    for (int i = 0; i < m; i++)
    {
        //on recherche le premier élément de la ligne qui est nul
        j = 0;

        while ((j < n) && (mat[i][j] == 0))
            j++;

        //on passe à la boucle for suivante si toute la ligne a été vérifiée
        // Si tous les éléments de la ligne i sont nuls, on passte à la ligne suivante
        if (j == n)
            continue;

        // Vérifier que la colonne du pivot est nul également
        for (int k = 0; k < m; k++)
        {
            if (k == i)
                continue;

            if (mat[k][j] != 0)
                return false;
        }

        // Vérifier que le pivot est bien à 1
        if (mat[i][j] != 1)
            return false;
    }

    return true;
}

/// @brief : Interface utilisateur
/// @param : int n le nombre de colonne
/// @param : int m le nombre de ligne
/// @param : int** mat un pointeur vers la matrice
/// @return : rien
int gaussManuel(int n, int m, int** mat)
{
    //on clear la console pour que ce soit propre
    system("cls");

    //on affiche la matrice actuel
    afficheMat(n, m, mat);

    //on envoie les propositions
    printf( "- Transposition : tapez 1\n"
            "- Dilatation : tapez 2\n"
            "- Transvection : tapez 3\n"
            "- Tri matrice : tapez 4\n"
            "- Vous souhaitez quitter ? Tapez 5\n\n");

    //on récupère la réponse et on la retourne
    printf("Entrez votre reponse : ");
    int tmp;
    scanf("%d", &tmp);

    return tmp;
}

/// @brief : interface utilisateurs + échange de 2 lignes de la matrice
/// @param : int n le nombre de colonne
/// @param : int indice la ligne à multiplier par -1
/// @param : int** mat un pointeur vers la matrice à initialiser
/// @return : rien
void transposition(int n, int m, int** mat)
{
    //on clear la console pour que ce soit propre
    system("cls");

    //on affiche la matrice actuel
    afficheMat(n, m, mat);

    //interface utilisateurs, quels lignes veulent-ils échanger
    int l1 = 0, l2 = 1;

    printf("Quels sont les lignes que vous voulez échanger ? (réponse attendu : \"l1 l2\")\n");
    scanf("%d %d", &l1, &l2);

    l1--;
    l2--;

    //échange des lignes
    echangeLigneMat(n, l1, l2, mat);

    return;
}

/// @brief : multriplie une ligne de la matrice par un lambda demandé
/// @param : int n le nombre de colonne
/// @param : int indice la ligne à multiplier par -1
/// @param : int** mat un pointeur vers la matrice à initialiser
/// @return : rien
void dilatation(int n, int m, int** mat)
{
    //on clear la console pour que ce soit propre
    system("cls");

    //on affiche la matrice actuel
    afficheMat(n, m, mat);

    //interface utilisateurs, quelle ligne veulent-ils multiplier par quoi
    int lambda = 1, indice = 1;

    printf("Quelle est la ligne que vous voulez multiplier ? (réponse attendu : \"indice\")\n");
    scanf("%d", &indice);
    printf("Par combien voulez-vous multiplier cette ligne ? (réponse attendu : \"lambda\")\n");
    scanf("%d", &lambda);

    //on réduit de 1 car en informatique un tableau commence à 0, alors qu'en maths il commente à 1
    indice--;
    lambda;

    //calcul
    for (int i = 0; i < m; i++)
    {
        mat[indice][i] *= lambda;
    }
    return;
}

/// @brief : interface utilisateurs + addition de 2 lignes entres-elles
/// @param : int n le nombre de colonne
/// @param : int indice la ligne à multiplier par -1
/// @param : int** mat un pointeur vers la matrice à initialiser
/// @return : rien
void transvection(int n, int m, int** mat)
{
    //on clear la console pour que ce soit propre
    system("cls");

    //on affiche la matrice actuel
    afficheMat(n, m, mat);

    //interface utilisateurs, quelles lignes veulent-ils additionner entres-elles
    int lambda = 1, l1 = 1, l2 = 1;
    char c = 'Y';

    printf("Quelles lignes voulez-vous additionner entres-elles ? (réponse attendu : \"ligneA ligneB\")\n");
    printf("Noter que la ligne A sera celle à laquelle vous ferez l'addition.\n");
    scanf("%d %d", &l1, &l2);

    //test de l'erreur
    if (l1 == l2)
    {
        printf( "Nous ne pouvons pas additioner une ligne à elle-même.\n"
                "Voulez vous retenter ? (réponse attendu : \"Y/N\")\n");
        scanf("%c", &c);

        if (c == 'Y')
            transvection(n, m, mat);

        return;
    }
    voidBuffer();

    printf("Voulez-vous multiplier la ligne B avant de l'ajouter à la ? (réponse attendu : \"Y/N\")\n");
    scanf("%c", &c);


    if (c == 'Y')
    {
        printf("Par combien voulez-vous multiplier cette ligne ? (réponse attendu : \"lambda\")\n");
        scanf("%d", &lambda);
    }
    voidBuffer();


    // /!\ getchar ne sert pas à ça normalement, on doit l'utiliser pour renvoyer le code ASCII d'un caractère /!\

    l1--;
    l2--;

    //calcul
    for (int i = 0; i < m; i++)
        mat[l1][i] += mat[l2][i] * lambda;

    return;
}

/// @brief : vide le buffer d'entrée
void voidBuffer()
{
    // Vider le buffer d'entrée
    while ((getchar()) != '\n');

    return;
}
/// @brief : echange 2 lignes de matrice entres elles
/// @param : int n le nombre de colonne (en contant le second membre)
/// @param : int l1 la ligne 1 à inverser
/// @param : int l2 la ligne 2 à inverser
/// @param : int** mat un pointeur vers la matrice à initialiser
/// @return : rien
void echangeLigneMat(int n, int l1, int l2, int** mat)
{
    if (l1 == l2)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int tmp = mat[l1][i];
        mat[l1][i] = mat[l2][i];
        mat[l2][i] = tmp;
    }
    return;
}

/// @brief : tri la matrice en mettant les lignes de pivot dans l'ordre croissant
/// @param : int l le nombre de ligne de la matrice
/// @param : int n le nombre de colonne (en contant le second membre)
/// @param : int** mat un pointeur vers la matrice à initialiser
/// @return : rien
void triMatrice(int l, int n, int** mat)
{
    int i, tmp = 0, min;

    for (i = 0; i < l - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < l; j++)
        {
            if (mat[j][0] < mat[min][0])
            {
                if (mat[j][0] == 0)
                    continue;
                //on tri en fonction de la plus petite valeur de pivot possible, donc 0 exclus
                min = j;
            }
        }


        if (mat[min][0] != mat[i][0])
        {
            echangeLigneMat(n, min, i, mat);
        }
    }
    return;
}

//sagemath; -> langage pour les maths